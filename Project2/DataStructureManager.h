#ifndef DataStructureManager_H
# define DataStructureManager_H

#include <iostream>
#include <time.h>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <sstream>
#include "BinarySearchTree.h"
#include "Vector.h"
#include "HashTable.h"
#include "Course.h"
#include <chrono>
#include <map>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

// object to manage all data structures for visualization and more dynamic calls
template <typename T>
class DataStructureManager {

private:
    // data structures
	vector<T> courses;
    BinarySearchTree<T> myBST;
    MyVector<T> myVector;

    // helper attributes
	map<size_t, double> bstTimes;
    map<size_t, double> vectorTimes;


public:

    // these 3 methods mostly for testing assurance
    size_t getNumCourses() {
        return this->courses.size();
    }

    size_t getNumBSTTimes() {
        return this->bstTimes.size();
    }

    size_t getNumVectorTimes() {
        return this->vectorTimes.size();
    }


    // BST visualization
    void plotBSTTimes() {
        std::vector<size_t> bytes;
        std::vector<double> times;

        for (const auto& bstTime : bstTimes) {
            bytes.push_back(bstTime.first);
            times.push_back(bstTime.second);
        }


        plt::plot(times, bytes);

        // Add labels, limiters, and title
        plt::xlabel("Time: microseconds");
        plt::ylabel("Space: bytes");

        // x limit and y limit are relatively arbitrary -- based on observed times
        plt::xlim(0, 10);
        plt::ylim(0, 30000);
        plt::title("Binary Search Tree Searches");

        // display it
        plt::legend();
        plt::show();
    }

    // Vector visualization
    void plotVectorTimes() {
        std::vector<size_t> bytes;
        std::vector<double> times;

        for (const auto& vectorTime : vectorTimes) {
            bytes.push_back(vectorTime.first);
            times.push_back(vectorTime.second);
        }


        plt::plot(times, bytes);

        // Add labels, limiters, and title
        plt::xlabel("Time: microseconds");
        plt::ylabel("Space: bytes");

        // x limit and y limit are relatively arbitrary -- based on observed times
        plt::xlim(0, 10);
        plt::ylim(0, 30000);
        plt::title("Vector Sorting Time");

        // display it
        plt::legend();
        plt::show();
    }

    // timers are based on your relative computer, results are variable
    auto bstSearchTime(string& courseId) {
        size_t nodeCount = myBST.getSize();
        auto time = myBST.getSearchTime(courseId);
        bstTimes[nodeCount] = time;
        return time;
    }

    void vectorSortTime() {
        size_t coursesCount = courses.size();
        auto time = myVector.getSortTime();
        vectorTimes[coursesCount] = time;
    }


    // prints for data structures, mostly for checking internals
    void printBSTTimes() const {
        if (!bstTimes.empty()) {
            for (const auto& bstTime : bstTimes) {
                cout << "Bytes used: " << bstTime.first << endl << "Time: " << bstTime.second << endl << endl;
            }
        }
    }

    void printVectorTimes() const {
        if (!vectorTimes.empty()) {
            for (const auto& vectorTime : vectorTimes) {
                cout << "Bytes used: " << vectorTime.first << endl << "Time: " << vectorTime.second << endl << endl;
            }
        }
    }

    // testing function to create more data for plot, uses real search/sort times
    void fabricateData(size_t numCourses) {

        for (size_t i = 0; i < numCourses; i++) {
            Course course;
            course.courseId = "TEST" + i;
            course.courseName = "TestCourse" + i;
            courses.push_back(course);
            myBST.Insert(course);
            myVector.addData(course);
            bstSearchTime(course.courseId);
            vectorSortTime();
        }
    }

    // load and insert each course from loaded file into a BST node, and add to the BST
    void loadCourses(const string& csvPath) {
        // initialize and open a file stream with given file name
        ifstream infs;

        cout << "Opening: " << csvPath << endl;

        infs.open(csvPath);

        // check if file opened properly
        if (!infs.is_open()) {
            cout << "Could not open file." << endl;
            return;
        }

        cout << "file opened!" << endl;

        // at least two tokens for each class (course code and course name) to be considered valid
        size_t minimum_course_tokens = 2;
        // iterate over file lines
        string line;

        while (getline(infs, line)) {
            stringstream ss(line);
            string token;

            std::vector<string> words;
            while (getline(ss, token, ',')) {
                words.push_back(token);
            }

            if (words.size() < minimum_course_tokens) {
                cout << "Invalid line format" << endl;
                continue;
            }

            // setup a course object with tokens, first two tokens are mandatory
            // token 0: course id
            // token 1: course name
            // additional tokens: prereq courses

            Course course;
            course.courseId = words[0];
            course.courseName = words[1];

            for (size_t i = minimum_course_tokens; i < words.size(); i++) {
                course.prereqs.push_back(words[i]);
            }

            // add course to vector
            courses.push_back(course);
        }

        infs.close();

    };
};
#endif
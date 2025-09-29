//============================================================================
// Name        : Project 2
// Author      : Alec Novak
// Version     : 1.0
// Description : Project 2 File parsing with Data Structure Storage
//============================================================================


#include <iostream>
#include <time.h>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <sstream>
#include "BinarySearchTree.h"
#include "Course.cpp"

using namespace std;


//============================================================================
// Global definitions visible to all methods and classes
//============================================================================


static void loadCourses(const string & csvPath, vector<Course> &courses) {
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

        vector<string> words;
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


////============================================================================
//// Main Control Functions
////============================================================================
//

int main(int argc, char* argv[]) {

    // global variables
    string csvPath = "CS 300 ABCU_Advising_Program_Input.csv";

    // setup data structures
    // unique ptr appointed to binary search tree to dynamically allocate/deallocate memory
    BinarySearchTree<Course> BST;
    vector<Course> courses;

    // process command line arguments indicating csv file path
    if (argc == 2) {
        csvPath = argv[1];
    }

    size_t userOption = 0;

    // loop until user decides to exit program
    while (userOption != 9) {

        // log user options available
        cout << "Welcome to the course planner." << endl;
        cout << "1: Load Course Data" << endl;
        cout << "2: Print Courses" << endl;
        cout << "3: Search Course" << endl;
        cout << "4: Size of BST" << endl;
        cout << "5: Time to full-search BST" << endl;
        cout << "9: Exit Program" << endl << endl;

        try {
            // clear the console inputs
            cin >> userOption;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // use user option to call menu functions
            switch (userOption) {
            case 1: {
                // load and insert each course from loaded file into a BST node, and add to the BST
                loadCourses(csvPath, courses);

                for (Course course : courses) {
                    BST.Insert(course);
                }

                break;
            }
            case 2: {
                // Print all nodes in order
                BST.InOrderPrint();
                break;
            }
            case 3: {
                // search for a particular node by courseId
                cout << "Please enter course ID to search for: " << endl;
                string courseId;
                cin >> courseId;
                BST.Search(courseId);
                break;
            }
            case 4: {
                // get size of BST
                cout << "Size: " << BST.getSize() << endl;
                break;
            }
            case 5: {
                // full length BST search time
                cout << "Time: " << BST.getSearchTime() << " ms" << endl;
                break;
            }
            case 9: {
                // exit application
                cout << "Goodbye" << endl;
                return 0;
            };
            default: {
                cout << endl << "Invalid option." << endl;
            };
            }

        }
        catch (const exception& e) {
            cout << e.what() << endl;
            cout << "Please pick a valid option" << endl;
            userOption = -1;
        }
    };

    return 0;
}
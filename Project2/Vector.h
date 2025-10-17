#ifndef Vector_H
#define Vector_H

#include <iostream>
#include <time.h>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <utility>
#include "Course.h"
#include <chrono>

////============================================================================
//// Vector Storage
////============================================================================
//

template <typename T>
class MyVector {
private:
    // courses copy so original data vector isn't affected
    vector<T> data;

    // private call to mergesort requiring a vector of data and the indexes
    void VectorMergeSort(size_t left, size_t right) {
        if (left >= right) {
            return;
        }

        // variable set up for recursive divide, sort, and merge
        size_t middleIndex = left + (right - left) / 2;    // middle index for partitioning

        // recursively divide the partitions until each vector holds 1 (or 0) elements
        // middle becomes new right for leftPartition and new left (middle+1) for right partition
        VectorMergeSort(left, middleIndex);
        VectorMergeSort(middleIndex + 1, right);
        VectorMerge(left, middleIndex, right);
    };

    // recursively sort and merge subvectors
    void VectorMerge(size_t left, size_t middle, size_t right) {

        vector<T> leftPartition(data.begin() + left, data.begin() + middle + 1);
        vector<T> rightPartition(data.begin() + middle + 1, data.begin() + right + 1);

        size_t i = 0;       // left partition starting index
        size_t j = 0;       // right partition starting index
        size_t k = left;    // set merge position to current left starting index


        // repeatedly add smallest element of two partitions -> lexigraphically ordered by courseId
        while (i < leftPartition.size() && j < rightPartition.size()) {

            // if left is less than right, add left and increase left vector index
            // following indexes use brackets for performance
            if ( leftPartition[i].courseId < rightPartition[j].courseId ) {
                data[k] = leftPartition[i];
                i++;
            }

            // otherwise, right is smaller, so add right, increase right vector index
            else {
                data[k] = rightPartition[j];
                j++;
            }

            // every iteration, merge position increases to track original vector index
            k++;
        }

        // left not empty, but right is, continue adding left
        while (i < leftPartition.size()) {
            data[k] = leftPartition[i];
            // increase index positions
            i++;
            k++;
        }

        // right not empty, but left is, continue adding right
        while (j < rightPartition.size()) {
            data[k] = rightPartition[j];
            // increas index positions
            j++;
            k++;
        }
    }

public:
    // timer is based on your relative computer, results are variable
    auto getSortTime() {
        string nullString;
        auto timer_start = chrono::high_resolution_clock::now();
        mergeSort();
        auto timer_end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = timer_end - timer_start;
        return duration.count();
    }

    void addData(T& course) {
        this->data.push_back(course);
    }

    size_t getNumElements() {
        return this->data.size();
    }

    // public call automatically uses built in member, 0 is the first index, data size - 1 is the last index
    void mergeSort() {
        if (!data.empty()) {
            VectorMergeSort(0, (data.size() - 1));
        }
    };

    void printAll() const {
        for (T dataItem : data) {
            cout << dataItem.courseId << endl;
        }
    }

    string getDataItemId(size_t index) {
        return data.at(index).courseId;
    }

};

#endif

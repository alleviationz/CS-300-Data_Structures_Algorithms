#ifndef BinarySearchTree_H
#define BinarySearchTree_H

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

//============================================================================
// Binary Search Tree Storage
//============================================================================

template <typename T>
class BinarySearchTree {
private:
    // Node struct to hold course (or type T) data
    struct Node {
        T data;
        unique_ptr<Node> left = nullptr;
        unique_ptr<Node> right = nullptr;

        // Node constructor w/ data assigned, initialize left and right pointers to nullptrs for future use
        explicit Node(const T& data) : data(data) {};   // move constructor
    };

    int nodeCount = 0;


    int getSizeBSTMembers() {
        // only calc static class members/pointer sizes, functions variables are dynamically allocated/deallocated
        return sizeof(this) + sizeof(this->getNodeCount()) + sizeof(root);
    };

    void setRoot(const T& data) {
        root = make_unique<Node>(data);
    };

    // BST helper (logic processing) functions

    T* SearchHelper(unique_ptr<Node>& node, const string& dataId) {

        // recurse until null node, searching BST by comparing Id values
        if (node) {

            // if node matches, return node's data object
            if (dataId == node->data.courseId) {
                T* dataPtr = &node->data;
                return dataPtr;
            }
            // if the data is less than node's dataId, recursively call the left tree and return recursive result
            else if (dataId < node->data.courseId) {
                return SearchHelper(node->left, dataId);
            }
            // else, dataId must be greater, so recursively call the right tree and return recursive result
            else {
                return SearchHelper(node->right, dataId);
            }
        }
        // Data was not found, so return an empty Data object
        return nullptr;
    };

    void InOrderPrintHelper(unique_ptr<Node>& node) {
        // check is given node pointer is null
        if (!node) {
            return;
        }

        // recursively iterate left subtree (smaller data first)
        InOrderPrintHelper(node->left);

        // output the Course ID for the node
        cout << "Course ID: " << node->data.courseId << " Course Name: " << node->data.courseName << endl;

        // recursively iterate right subtree (then larger data)
        InOrderPrintHelper(node->right);
    };

    void InsertHelper(unique_ptr<Node>& node, const T& data) {

        // if the  node is empty, set the node's data to the given data and end the process
        if (!node) {
            node = make_unique<Node>(data);
            this->nodeCount++;
            return;
        }

        // find an empty node to insert data by recursing down subtrees until a node is null
        if (node->data.courseId > data.courseId) {
            // data is less than currNode data -> recurse left subtree
            this->InsertHelper(node->left, data);
        }
        else {
            // otherwise data is greater than currNode data -> recurse right subtree
            this->InsertHelper(node->right, data);
        }
    };

public:
    // BST header

    // root node initialized to nullptr after constructor is called
    unique_ptr<Node> root = nullptr;

    int getNodeCount() const {
        return this->nodeCount;
    };

    // timer is based on your relative computer, results are variable
    auto getSearchTime() {
        string nullString;
        auto timer_start = chrono::high_resolution_clock::now();
        this->SearchHelper(root, nullString);
        auto timer_end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = timer_end - timer_start;
        return duration.count();
    }

    // size calc base BST size + (Node count * Node size)
    int getSize() {
        return (this->nodeCount * sizeof(Node) + getSizeBSTMembers());
    }

    T* Search(const string& dataId) {
        return this->SearchHelper(root, dataId);
    };

    void InOrderPrint() {
        this->InOrderPrintHelper(root);
    };

    void Insert(const T& data) {
        this->InsertHelper(root, data);
    };
};

#endif // BinarySearchTree_H
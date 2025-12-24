#ifndef HashTable_h
#define HashTable_H

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
// Hash Table Storage
//============================================================================
//class HashTable {
//
//private:
//
//    vector<vector<Node>> buckets;
//    vector<Node> nodes;
//    unsigned int tableSize = 26;
//    unsigned int hash(string key);
//
//public:
//    HashTable();
//    HashTable(unsigned int size);
//    virtual ~HashTable();
//    void Insert(Course course);
//    void PrintAll();
//    Course Search(string courseId);
//};
//
///**
// * Default constructor
// */
//
//private:
//    // Node struct to hold course (or type T) data
//    struct Node {
//        T data;
//        unique_ptr<Node> left = nullptr;
//        unique_ptr<Node> right = nullptr;
//
//        // Node constructor w/ data assigned, initialize left and right pointers to nullptrs for future use
//        explicit Node(const T& data) : data(data) {};   // move constructor
//HashTable::HashTable() {
//    // Initalize node structure by resizing tableSize
//    buckets.resize(tableSize);
//}
//HashTable::~HashTable() {
//    // delete nodes vector contents
//    this->nodes.clear();
//}
//
//HashTable::HashTable(unsigned int size) {
//    // if given size, call this constructor to resize
//    this->tableSize = size;
//    this->buckets.resize(size);
//}
//
//unsigned int HashTable::hash(string courseId) {
//    // get first char of string, subtract ASCII value to equalize to alphabet position
//    int classNum = courseId[0] - 65;
//    return classNum % this->tableSize;
//}
//
//void HashTable::Insert(Course course) {
//    // create key by hasing courseId
//    unsigned key = hash(course.courseId);
//    // retrieve node using key
//    Node currNode = buckets.at(key).at(0);
//
//    // if no entry found for the key create new node at position
//    if (currNode.course == NULL) {
//        Node* newNode = new Node(course);
//        // insert node
//        nodes.insert(nodes.begin() + key, *newNode);
//        cout << "creating new node chain" << endl;
//    }
//    else {
//        cout << "placing node elsewhere" << endl;
//    }
//};
//
//// if location at hash key is nullptr 
//
//// create a linked list of course nodes 
//
//// this course = head 
//
//// this course = tail 
//
//// otherwise, nodes exist already 
//
//// if special case course id < less than head�s course id 
//
//// course id node next = head 
//
//// head = course id node 
//
//// return 
//
//
//
//// curr node = head 
//
//// while course id > curr�s next node course id 
//
//// curr node++ 
//
//// course node�s next = curr node�s next 
//
//// curr node�s next = this course node 
//
//
//
//Course HashTable::Search(string courseId) {
//    unsigned int key = this->hash(courseId);
//    Node bucket = this->nodes.at(key);
//
//
//
//    Course course;
//    return course;
//}
//
//// hash the course Number and save as key 
//
//// bucket = table[hash(key)] 
//
//// iterate through bucket�s linked list until nullptr 
//
//// if node matches 
//
//// print node info 
//
//// return 
//
//// node not found, print message 
//
//// return null 
//
//
//
//void HashTable::PrintAll() {
//    cout << "FIXME" << endl;
//}
////Hash Print All
//
//// define int probe 
//
//// define initial bucket by hashing lowest possible key 
//
//// define curr node set to null 
//
//// iterate until num probes is equal to num total buckets 
//
//// if head is null 
//
//// ++probe 
//
//// ++bucket hash 
//
//// else 
//
//// curr node = head 
//
//// while curr node not null 
//
//// print information at node 
//
//// move to next node 
//
//// ++ probe 
//
//// ++bucket hash 
//
//// curr node = null 
;

#endif

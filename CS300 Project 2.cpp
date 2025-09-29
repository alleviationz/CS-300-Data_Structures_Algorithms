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
#include <algorithm>

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// Course structure for holding course info
struct Course {
    string courseId;
    string courseName;
    vector<string> prereqs;
};

//============================================================================
// Binary Search Tree Storage
//============================================================================
class BinarySearchTree {
private:
    // Node struct to hold course info
    struct Node {
        Course course;
        Node* left;
        Node* right;

        // default constructor
        Node() {
            left = nullptr;
            right = nullptr;
        }

        // initialize with given course
        Node(Course course) : course(course) {
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;
    void PrintAll(Node* root);

public:
    BinarySearchTree();
    Course Search(string courseId);
    void InOrderPrint();
    //Node* getRoot();
    //void setRoot(Node* node);
    void Insert(Course course);
};

// default constructor
BinarySearchTree::BinarySearchTree() {
    this->root = nullptr;
}

Course BinarySearchTree::Search(string courseId) {
    // set curr node to root
    Node* currNode = this->root;

    // loop until null
    while (currNode != nullptr) {
        // if node matches, return node
        if (courseId == currNode->course.courseId) {
            return currNode->course;
        }
        // if courseID is less than node's courseId, iterate go left down subtree
        if (courseId < currNode->course.courseId) {
            currNode = currNode->left;
        }
        // else go right down subtree
        else {
            currNode = currNode->right;
        }
    }

    // Course not found, return an empty course
    Course course;
    cout << "Course not found." << endl;
    return course;
};

void BinarySearchTree::PrintAll(Node* node) {
    // check is given node is null
    if (node == nullptr) {
        return;
    }
    // iterate left subtree
    PrintAll(node->left);
    // cout info
    cout << "Course ID: " << node->course.courseId << " Course Name: " << node->course.courseName << endl;
    // iterate right subtree
    PrintAll(node->right);
}

// helper function to print starting at root node
void BinarySearchTree::InOrderPrint() {
    PrintAll(this->root);
}

//Node* BinarySearchTree::getRoot() {
//    return this -> root;
//}
//
//void BinarySearchTree::setRoot(Node* node) {
//    this->root = node;
//};


void BinarySearchTree::Insert(Course course) {
    // create node with course info
    Node* newNode = new Node(course);

    // if root ode is null, set this node as root
    if (root == nullptr) {
        root = newNode;
        return;
    }

    Node* currNode = root;
    Node* parent = nullptr;

    // loop until currNode is null
    while (currNode != nullptr) {
        parent = currNode;
        // if courseId is less than the currNode's courseId, go left
        if (course.courseId < currNode->course.courseId) {
            currNode = currNode->left;
        }
        // otherwise go right
        else {
            currNode = currNode->right;
        }
    }

    // assign this node to parent's left
    if (course.courseId < parent->course.courseId) {
        parent->left = newNode;
    }
    // otherwise assign this node to parent's right
    else {
        parent->right = newNode;
    }
}

void loadCourses(string csvPath, vector<Course>& courses) {
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

    // iterate over file lines
    string line;
    while (getline(infs, line)) {
        stringstream ss(line);
        string token;

        vector<string> words;
        while (getline(ss, token, ',')) {
            words.push_back(token);
        }

        if (words.size() < 2) {
            cout << "Invalid line format" << endl;
            continue;
        }

        // setup a course object with tokens
        Course course;
        course.courseId = words[0];
        course.courseName = words[1];
        for (size_t i = 2; i < words.size(); i++) {
            course.prereqs.push_back(words[i]);
        }

        // add course to vector
        courses.push_back(course);
    }

    infs.close();

}


////============================================================================
//// Main Control Functions
////============================================================================
//
// //function to display and call menu options
////void DisplayMenu(string csvPath) {
////
////}

int main(int argc, char* argv[])
{
    // process command line arguments
    string csvPath;
    if (argc == 2) {
        csvPath = argv[1];
    }
    else {
        csvPath = "CS 300 ABCU_Advising_Program_Input.csv";
    }

    int userOption = -1;
    BinarySearchTree* BST = new BinarySearchTree();
    vector<Course> courses;
    Course course;
    course.courseId = "101";
    course.courseName = "Practice Class";

    // erase
    //string courseId = "CSCI101";
    //string courseName = "Computer Science 101";
    //vector<string> prereqs = { "Math", "Science" };
    //Course course(courseId, courseName, prereqs);

    // loop until user decides to exit program
    while (userOption != 9) {

        //options available
        cout << "Welcome to the course planner." << endl;
        cout << "1: Load Course Data" << endl;
        cout << "2: Print Courses" << endl;
        cout << "3: Search Course" << endl;
        cout << "9: Exit Program" << endl << endl;

        try {
            // clear the console inputs
            cin >> userOption;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // use user option to call menu functions
            switch (userOption) {
            case 1: {
                // load and insert courses into BST
                loadCourses(csvPath, courses);
                for (int i = 0; i < courses.size(); i++) {
                    BST->Insert(courses.at(i));
                }
                //cout << "Inserting Course: " << course.courseName << " ID: " << course.courseId << endl;
                //BST->Insert(course);
                break;
            };
            case 2: {
                // Print all nodes in order
                BST->InOrderPrint();
                break;
            };
            case 3: {
                // search for a particular node
                cout << "Please enter course ID to search for: " << endl;
                string courseId;
                cin >> courseId;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                BST->Search(courseId);
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
};



//  EXTRA STUFF
//
//
////============================================================================
//// Vector Storage
////============================================================================
//
//void VectorMerge(vector<Course>courses, int i, int j, int k) {
//    //setup variables for merge and copying
//    vector<Course> coursesCopy;
//    int leftPos = 0;
//    int rightPos = 0;
//    int mergePos = 0;
//
//    // set leftPos & right pos
//    leftPos = i;
//    rightPos = j + 1;
//
//    // repeatedly add smallest element of two partitions
//    while (leftPos <= j && rightPos <= k) {
//        // if left courseId less than right courseId, add left
//        if (courses.at(leftPos).courseId.compare(courses.at(rightPos).courseId) < 0) {
//            coursesCopy.push_back(courses.at(leftPos));
//            ++leftPos;
//        }
//        else {
//            coursesCopy.push_back(courses.at(rightPos));
//            ++rightPos;
//        }
//        ++mergePos;
//    }
//
//    // left not empty, but right is
//    while (leftPos <= j) {
//        coursesCopy.push_back(courses.at(leftPos));
//        ++leftPos;
//        ++mergePos;
//    }
//
//    // right not empty, but left is
//    while (rightPos <= k) {
//        coursesCopy.push_back(courses.at(rightPos));
//        ++rightPos;
//        ++mergePos;
//    }
//
//    // copy coursesCopy vector contents to courses vector
//    for (mergePos = 0; mergePos < coursesCopy.size(); mergePos++) {
//        cout << "copying: " << coursesCopy.at(mergePos + i).courseName << endl;
//        courses.at(i + mergePos) = coursesCopy.at(mergePos);
//    }
//}
//
//void VectorMergeSort(vector<Course> courses, int i, int k) {
//    int j = 0;
//    if (i < k) {
//        // find midpoint of partition
//        j = (i + k) / 2;
//
//        // recurse and sort left and right partitions
//        VectorMergeSort(courses, i, j);
//        VectorMergeSort(courses, j + 1, k);
//
//        // call to merge with partition
//        VectorMerge(courses, i, j, k);
//        cout << "Merging" << endl;
//    }
//}
//
//
////Vector Search and Print Course(Vector courses, courseNumber)
//
//// while loop until end of courses vector 
//
//// if course input param matches the current course number 
//
//// return the current course 
//
//// return course not found 
//
//
//
////Vector Print All(courses vector)
//
//// call vector sort with courses vector 
//
//// while loop until end of courses vector 
//
//// print course info at each iteration 
    //Course course1;
    //course1.courseId = "101";
    //course1.courseName = "Course1";

    //Course course2;
    //course2.courseId = "102";
    //course2.courseName = "Course2";

    //Course course3;
    //course3.courseId = "103";
    //course3.courseName = "Course3";

    //vector<Course> sampleStrings = {course3, course1, course2};
    //int SIZE = sampleStrings.size();
    //int i = 0;

    //cout << ("UNSORTED: ");
    //    for (i = 0; i < SIZE; ++i) {
    //        cout << sampleStrings[i].courseName << " ";
    //    }
    //    cout << endl;

    //    VectorMergeSort(sampleStrings, 0, SIZE - 1);

    //cout << ("SORTED: ");
    //    for (i = 0; i < SIZE; ++i) {
    //        cout << sampleStrings[i].courseName << " ";
    //    }
    //    cout << endl;

////============================================================================
//// Hash Table Storage
////============================================================================
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
////
////// if location at hash key is nullptr 
////
////// create a linked list of course nodes 
////
////// this course = head 
////
////// this course = tail 
////
////// otherwise, nodes exist already 
////
////// if special case course id < less than head’s course id 
////
////// course id node next = head 
////
////// head = course id node 
////
////// return 
////
////
////
////// curr node = head 
////
////// while course id > curr’s next node course id 
////
////// curr node++ 
////
////// course node’s next = curr node’s next 
////
////// curr node’s next = this course node 
////
////
////
//Course HashTable::Search(string courseId) {
//    unsigned int key = this->hash(courseId);
//    Node bucket = this->nodes.at(key);
//
//
//
//    Course course;
//    return course;
//}
////
////// hash the course Number and save as key 
////
////// bucket = table[hash(key)] 
////
////// iterate through bucket’s linked list until nullptr 
////
////// if node matches 
////
////// print node info 
////
////// return 
////
////// node not found, print message 
////
////// return null 
////
////
////
//void HashTable::PrintAll() {
//    cout << "FIXME" << endl;
//}
//////Hash Print All
////
////// define int probe 
////
////// define initial bucket by hashing lowest possible key 
////
////// define curr node set to null 
////
////// iterate until num probes is equal to num total buckets 
////
////// if head is null 
////
////// ++probe 
////
////// ++bucket hash 
////
////// else 
////
////// curr node = head 
////
////// while curr node not null 
////
////// print information at node 
////
////// move to next node 
////
////// ++ probe 
////
////// ++bucket hash 
////
////// curr node = null 
//
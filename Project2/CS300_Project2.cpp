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
#include "Vector.h"
#include "HashTable.h"
#include "Course.h"
#include "DataStructureManager.h"

using namespace std;

////============================================================================
//// Main Control Functions
////============================================================================
//

int main(int argc, char* argv[]) {

    // global variables
    string csvPath = "../CS 300 ABCU_Advising_Program_Input.csv";


    // process command line arguments indicating csv file path
    if (argc == 2) {
        csvPath = argv[1];
    }

    // setup data structures and algorithms to track
    DataStructureManager<Course> dataManager;
    dataManager.loadCourses(csvPath);

    size_t userOption = 0;

    // loop until user decides to exit program
    while (userOption != 9) {

        // log user options available
        cout << "Welcome to the course planner." << endl;
        cout << "1: Record BST Search time by searching via CourseId" << endl;
        cout << "2: Merge sort vector and Record time" << endl;
        cout << "3: Print all BST times" << endl;
        cout << "4: Print all Vector times" << endl;
        cout << "5: Fabricate and Record samples" << endl;
        cout << "6: Create visualization for BST Searches" << endl;
        cout << "7: Create visualization for Vector Sorting" << endl;
        cout << "9: Exit Program" << endl << endl;

        try {
            // clear the console inputs
            cin >> userOption;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        catch (const exception& e) {
            cout << e.what() << endl;
            userOption = -1;
        }

        // use user option to call menu functions
        // 
        switch (userOption) {
            case 1: {
            // search for a particular node by courseId
                try {
                    cout << "Please enter course ID to search for: " << endl;
                    string courseId;
                    cin >> courseId;
                    cout << "Time to search for " << courseId << ": " << dataManager.bstSearchTime(courseId) << " ms" <<  endl;
                }
                catch (exception& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 2: {
                dataManager.vectorSortTime();
                break;
            }
            case 3: {
                dataManager.printBSTTimes();
                break;
            }
            case 4: {
                dataManager.printVectorTimes();
                break;
            }
            case 5: {
                cout << "Enter number of courses to fabricate: (max 1000 total)" << endl;
                size_t numCourses = dataManager.getNumCourses();
                size_t num;
                try {
                    cin >> num;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (!num || num > 1000 || num == 0 || num + numCourses > 1000) {
                        cout << "Invalid amount" << endl;
                        break;
                    }
                    else {
                        dataManager.fabricateData(num);
                        break;
                    }
                }
                catch (const exception& e) {
                    cout << e.what() << endl;
                }
            }
            case 6: {
                dataManager.plotBSTTimes();
                break;
            }
            case 7: {
                dataManager.plotVectorTimes();
                break;
            }
            case 9: {
                cout << "Goodbye" << endl;
                return 0;
            }
            default: {
                cout << "Invalid option. Please try again." << endl;
                break;
            }
        }
        //switch (userOption) {
        //    case 1: {
        //        // load and insert each course from loaded file into a BST node, and add to the BST
        //        loadCourses(csvPath, courses);

        //        for (Course course : courses) {
        //            BST.Insert(course);
        //        }

        //        break;
        //    }
        //    case 2: {
        //        // Print all nodes in order
        //        BST.InOrderPrint();
        //        break;
        //    }
        //    case 3: {
        //        // search for a particular node by courseId
        //        try {
        //            cout << "Please enter course ID to search for: " << endl;
        //            string courseId;
        //            cin >> courseId;
        //            const Course* course = BST.Search(courseId);

        //            if (course->courseId == courseId) {
        //                cout << course->courseId << " found: " << course->courseName << endl;
        //            }
        //            else {
        //                cout << "No course found" << endl;
        //            }
        //        }
        //        catch (exception& e) {
        //            cout << e.what() << endl;
        //            break;
        //        }

        //        break;
        //    }
        //    case 4: {
        //        // get size of BST
        //        cout << "Size: " << BST.getSize() << endl;
        //        break;
        //    }
        //    case 5: {
        //        // full length BST search time
        //        cout << "Time for full traversal: " << BST.getSearchTime() << " ms" << endl;
        //        break;
        //    }
        //    case 9: {
        //        // exit application
        //        cout << "Goodbye" << endl;
        //        return 0;
        //    }
        //    default: {
        //        cout << endl << "Invalid option." << endl;
        //    }
    //}
    }

    return 0;
}
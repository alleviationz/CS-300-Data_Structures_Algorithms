#ifndef Course_H
#define Course_H

#include<string>
#include<vector>

using namespace std;

// Course structure for holding course info
struct Course {
    string courseId;
    string courseName;
    vector<string> prereqs;
};

#endif // Course_H
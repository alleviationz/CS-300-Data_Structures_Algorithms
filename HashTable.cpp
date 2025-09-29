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
//;
#include "pch.h"
#include "../Project2/BinarySearchTree.h"
#include "../Project2/Vector.h"
#include "../Project2/DataStructureManager.h"


// ----------- BST TESTS --------
class BinarySearchTreeTest : public testing::Test {
public:
	BinarySearchTree<Course> BST;
};

TEST_F(BinarySearchTreeTest, BinarySearchTreeRootNullptr) {
	ASSERT_EQ(BST.root, nullptr);
};

TEST_F(BinarySearchTreeTest, BinarySearchTreeNodeCountStartsAtZero) {
	ASSERT_EQ(BST.getNodeCount(), 0);
};

// size of empty bst is just the members: 32 bytes
TEST_F(BinarySearchTreeTest, BinarySearchTreeSizeEmptySizeCorrect) {
	ASSERT_EQ(BST.getSize(), 32);
};

TEST_F(BinarySearchTreeTest, BinarySearchTreeSizeVariableNodeSizeCorrect) {

	EXPECT_EQ(BST.root, nullptr);

	// i scoped outside loop to preserve ending added node count
	size_t i;

	for (i = 0; i < 5; i++) {
		Course course;
		course.courseId = i + "id";
		course.courseName = "Course" + i;
		course.prereqs.emplace_back("Course 101");

		BST.Insert(course);
	};

	// base size of BST & members is 32 bytes, size of node is 16 bytes + size of Course, which is 112 bytes
	// ending i is how many nodes were added
	size_t total_size = 32 + (112 + 16) * i;
	ASSERT_EQ(BST.getSize(), total_size);
};

TEST_F(BinarySearchTreeTest, BinarySearchTreeSuccessfullyReturnsCourse) {
	string nullString;

	Course course;
	course.courseId = "TEST101";
	course.courseName = "Course 101";
	BST.Insert(course);

	// Test w/ valid course
	ASSERT_EQ(BST.Search("TEST101")->courseId, "TEST101");
	ASSERT_EQ(BST.Search("TEST101")->courseName, "Course 101");

	// Test w/o course
	ASSERT_EQ(BST.Search(nullString), nullptr);
};

TEST_F(BinarySearchTreeTest, BinarySearchTreeSuccessfullyInsertsCourse) {
	EXPECT_EQ(BST.getNodeCount(), 0);

	Course course;
	course.courseId = "TEST101";
	course.courseName = "Course 101";

	BST.Insert(course);

	ASSERT_EQ(BST.getNodeCount(), 1);
};

// ----------- Vector TESTS --------
class VectorTest : public testing::Test {
public:
	MyVector<Course> myVector;
};

TEST_F(VectorTest, VectorStartsNull) {
	ASSERT_EQ(myVector.getNumElements(), 0);
}

TEST_F(VectorTest, VectorCanAddElements) {
	ASSERT_EQ(myVector.getNumElements(), 0);

	Course course;
	course.courseId = "TEST101";
	course.courseName = "Course 101";

	myVector.addData(course);

	ASSERT_EQ(myVector.getNumElements(), 1);
}

TEST_F(VectorTest, VectorSortsCourses) {
	vector<Course> courses;

	for (size_t i = 0; i < 5; i++) {
		Course course;
		course.courseId = i + "id";
		course.courseName = "Course" + i;
		course.prereqs.emplace_back("Course 101");
		courses.push_back(course);
		myVector.addData(course);
	};

	ASSERT_EQ(courses.size(), 5);
	ASSERT_EQ(myVector.getNumElements(), 5);

	myVector.mergeSort();

	for (size_t i = 0; i < myVector.getNumElements() - 1; i++) {
		string currentCourse = myVector.getDataItemId(i);
		string nextCourse = myVector.getDataItemId(i + 1);
		ASSERT_LE(currentCourse, nextCourse);
	}
}

// ----------- DataManager TESTS --------
class DataManagerTest : public testing::Test {
public:
	DataStructureManager<Course> dataManager;
	string csvPath = "../CS 300 ABCU_Advising_Program_Input.csv";
};

TEST_F(DataManagerTest, CanLoadCourses) {
	ASSERT_EQ(dataManager.getNumCourses(), 0);

	dataManager.loadCourses(csvPath);

	ASSERT_EQ(dataManager.getNumCourses(), 8);
}

TEST_F(DataManagerTest, CanFabricateData) {
	ASSERT_EQ(dataManager.getNumCourses(), 0);

	dataManager.fabricateData(10);

	ASSERT_EQ(dataManager.getNumCourses(), 10);
	ASSERT_EQ(dataManager.getNumBSTTimes(), 10);
	ASSERT_EQ(dataManager.getNumVectorTimes(), 10);
}

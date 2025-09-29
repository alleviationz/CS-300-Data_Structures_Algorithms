#include "pch.h"
#include "../Project2/BinarySearchTree.h"

class Environment : public testing::Test {
public:
	~Environment() override {};

	void SetUp() override {
		// random seed
		srand(time(nullptr));
	};

	void TearDown() override {};
};

class BinarySearchTreeTest : public testing::Test {
public:
	BinarySearchTree<Course> BST;
	void SetUp() override {}

	void TearDown() override {};
};

TEST_F(BinarySearchTreeTest, BinarySearchTreeRootNullptr) {
	ASSERT_EQ(BST.root, nullptr);
};

TEST_F(BinarySearchTreeTest, BinarySearchTreeNodeCountStartsAtZero) {
	ASSERT_EQ(BST.getNodeCount(), 0);
};

TEST_F(BinarySearchTreeTest, BinarySearchTreeSizeEmptySizeCorrect) {
	ASSERT_EQ(BST.getSize(), 20);
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

	// size of BST is 20 bytes, size of node is 16 bytes + size of Course, which is 112 bytes
	// ending i is how many nodes were added
	size_t total_size = 20 + (112 + 16) * i;
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
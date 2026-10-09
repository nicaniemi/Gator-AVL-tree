//#include <catch2/catch_test_macros.hpp>
//#include <iostream>
////
//// uncomment and replace the following with your own headers
////#include <algorithm>
//
//#include "AVL_header.h"
////
//using namespace std;
//
// // the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.
//
//TEST_CASE("Unsuccessful inserts", "[insertion]") // Test bad names/IDs to ensure regex works
//{
//	// instantiate any class members that you need to test here
//	AVL tree;
//	// anything that evaluates to false in a REQUIRE block will result in a failing test
//	REQUIRE(tree.insert("A11y", 123456789) == "unsuccessful"); // fix me!
//
//	// all REQUIRE blocks must evaluate to true for the whole test to pass
//	REQUIRE(tree.insert("John", 1) == "unsuccessful"); // also fix me!
//
//	REQUIRE(tree.insert("J0hn", 12345678) == "unsuccessful");
//
//	REQUIRE(tree.insert("John", 1234567) == "unsuccessful");
//
//	REQUIRE(tree.insert("Joe", 1234567800) == "unsuccessful");
//}
//
//TEST_CASE("Successful insertions", "[insertion]") // Test valid names and IDs to ensure regex doesn't flag and insertion works
//{
//	AVL tree;
//
//	REQUIRE(tree.insert("Ally", 12345678) == "successful");
//	REQUIRE(tree.insert("John", 12345677) == "successful");
//	REQUIRE(tree.insert("Bob", 12345667) == "successful");
//	REQUIRE(tree.insert("Joe", 87654321) == "successful");
//	REQUIRE(tree.insert("Nicolas", 69887752) == "successful");
//}
//
//
//TEST_CASE("Rotation tests", "[rotation]") // Test all 4 rotation cases
//{
//	AVL tree;
//	// LL Rotation
//	tree.insert("John", 12345678);
//	tree.insert("Ally", 23456789);
//	tree.insert("Bob", 12345679);
//
//	std::string rotateLL = tree.printInOrder();
//	REQUIRE(rotateLL == "John, Bob, Ally");
//
//	AVL tree2;
//	// RR rotation
//	tree2.insert("John", 12345679);
//	tree2.insert("Ally", 12345678);
//	tree2.insert("Bob", 12345677);
//
//	std::string rotateRR = tree2.printInOrder();
//	REQUIRE(rotateRR == "Bob, Ally, John");
//
//	AVL tree3;
//	// LR rotation
//	tree3.insert("John", 12345679);
//	tree3.insert("Ally", 12345677);
//	tree3.insert("Bob", 12345678);
//
//	std::string rotateLR = tree3.printInOrder();
//	REQUIRE(rotateLR == "Ally, Bob, John");
//
//	AVL tree4;
//	// RL rotation
//	tree4.insert("John", 12345677);
//	tree4.insert("Ally", 12345679);
//	tree4.insert("Bob", 12345678);
//
//	std::string rotateRL = tree4.printInOrder();
//	REQUIRE(rotateRL == "John, Bob, Ally");
//}
//
//TEST_CASE("100 nodes insertion", "[Multiple][insertion]") // Test insertion of 100 nodes and remove 10
//{
//	AVL tree;
//	std::vector<int> expectedOutput, actualOutput;
//
//	for (int i = 0; i < 100; i++)
//	{
//		int randomInput = 10000000 + rand() % 90000000; // Copilot helped with this, I needed to ensure rand() would insert 8 digit IDs so regex didn't fail it
//		if (std::count(expectedOutput.begin(), expectedOutput.end(), randomInput) == 0)
//		{
//			expectedOutput.push_back(randomInput);
//			tree.insert("test", randomInput);
//		}
//	}
//
//	actualOutput = tree.inOrder();
//	REQUIRE(expectedOutput.size() == actualOutput.size());
//	REQUIRE_FALSE(expectedOutput == actualOutput);
//	std::sort(expectedOutput.begin(), expectedOutput.end());
//	REQUIRE(expectedOutput == actualOutput);
//}
//
//TEST_CASE("Edge case testing")
//{
//	AVL tree;
//	REQUIRE(tree.removeByID(1) == "unsuccessful");
//	REQUIRE(tree.removeByID(2) == "unsuccessful");
//	REQUIRE(tree.removeByID(3) == "unsuccessful");
//}
//
//TEST_CASE("Deletion testing no children", "[deletion]")
//{
//	AVL tree;
//	tree.insert("John", 20000000);
//	tree.insert("Ally", 10000000);
//	tree.insert("Bob", 30000000);
//	REQUIRE(tree.removeByID(30000000) == "successful");
//	REQUIRE(tree.printInOrder() == "Ally, John");
//}
//
//TEST_CASE("Deletion testing 1 child", "[deletion]")
//{
//	AVL tree;
//	tree.insert("John", 20000000);
//	tree.insert("Ally", 10000000);
//	tree.insert("Bob", 30000000);
//	tree.insert("Joe", 35000000);
//	REQUIRE(tree.removeByID(30000000) == "successful");
//	REQUIRE(tree.printInOrder() == "Ally, John, Joe");
//}
//
//TEST_CASE("Deletion testing 2 children", "[deletion]")
//{
//	AVL tree;
//	tree.insert("John", "20000000");
//	tree.insert("Ally", "10000000");
//	tree.insert("Bob", "30000000");
//	REQUIRE(tree.removeByID("20000000") == "successful");
//	REQUIRE(tree.printInOrder() == "Ally, Bob");
//}
//
//TEST_CASE("PreOrder testing", "[preorder][Test 10]")
//{
//	AVL tree;
//	tree.insert("Ally", 10000001);
//	tree.insert("Bob", 10000002);
//	tree.insert("Joe", 10000003);
//	tree.insert("JJ", 10000004);
//	tree.insert("Nic", 10000005);
//	tree.insert("Nicolas", 10000006);
//	tree.insert("Greg", 10000007);
//	REQUIRE(tree.printPreOrder() == "JJ, Bob, Ally, Joe, Nicolas, Nic, Greg");
//}
//
//TEST_CASE("Test 2", "[flag]"){
//	// you can also use "sections" to share setup code between tests, for example:
//	int one = 1;

//	SECTION("num is 2") {
//		int num = one + 1;
//		REQUIRE(num == 2);
//	};

//	SECTION("num is 3") {
//		int num = one + 2;
//		REQUIRE(num == 3);
//	};

	// each section runs the setup code independently to ensure that they don't affect each other
//}

// you must write 5 unique, meaningful tests for credit on the testing portion of this project!

// the provided test from the template is below.

//TEST_CASE("Example BST Insert", "[flag]"){
	/*
		MyAVLTree tree;   // Create a Tree object
		tree.insert(3);
		tree.insert(2);
		tree.insert(1);
		std::vector<int> actualOutput = tree.inorder();
		std::vector<int> expectedOutput = {1, 2, 3};
		REQUIRE(expectedOutput.size() == actualOutput.size());
		REQUIRE(actualOutput == expectedOutput);
	*/

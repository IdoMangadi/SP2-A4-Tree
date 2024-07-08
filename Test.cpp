// ID: 315310250
// EMAIL: IDOIZHAR.Mangadi@msmail.ariel.ac.il
// GMAIL: idomangadi@gmail.com

#include <iostream>
#include <string>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <vector>
#include <memory>
#include <sstream>

#include "doctest.h"
#include "Tree.hpp"
#include "Complex.hpp"

using namespace std;
using namespace myTree;
using namespace myComplex;



TEST_CASE("TestNode"){
    auto node = make_shared<Node<int>>(10);
    CHECK(node->getValue() == 10);

    auto child1 = make_shared<Node<int>>(20);  // create a child node.
    auto child2 = make_shared<Node<int>>(30);  // create a child node.

    CHECK(node->addChild(child1));  // add the child to the node.
    CHECK(node->addChild(child2));  // add the child to the node.
    CHECK(node->getChildren().size() == 2);
    CHECK(node->getChildren()[0]->getValue() == 20);
    CHECK(node->getChildren()[1]->getValue() == 30);
}

TEST_CASE("TestComplex"){
    Complex c1(1.0, 2.0);  // create a complex numbers.
    Complex c2(2.0, 3.0);

    Complex c3 = c1 + c2;  
    CHECK(c3 == Complex(3.0, 5.0));  // check the addition of the complex numbers.

    Complex c4 = c1 - c2;
    CHECK(c4 == Complex(-1.0, -1.0));  // check the subtraction of the complex numbers.

    Complex c5 = c1 * c2;
    CHECK(c5 == Complex(-4.0, 7.0));  // check the multiplication of the complex numbers.
}

TEST_CASE("TestTree"){
    auto root = make_shared<Node<int>>(1);  // building the tree:
    auto tree = make_shared<Tree<int, 2>>(root);

    auto child1 = make_shared<Node<int>>(2);
    auto child2 = make_shared<Node<int>>(3);
    tree->addSubNode(root, child1);
    tree->addSubNode(root, child2);

    auto child3 = make_shared<Node<int>>(4);
    auto child4 = make_shared<Node<int>>(5);
    tree->addSubNode(child1, child3);
    tree->addSubNode(child1, child4);

    // Test BFS iterator:
    BFSIterator<int> bfsIt = tree->beginBFS();
    vector<int> bfsResult;
    while (bfsIt != tree->endBFS()) {
        bfsResult.push_back(*bfsIt);
        ++bfsIt;
    }
    CHECK((bfsResult == vector<int>{1, 2, 3, 4, 5}));

    // Test DFS iterator
    DFSIterator<int> dfsIt = tree->beginDFS();
    vector<int> dfsResult;
    while (dfsIt != tree->endDFS()) {
        dfsResult.push_back(*dfsIt);
        ++dfsIt;
    }
    CHECK((dfsResult == vector<int>{1, 2, 4, 5, 3}));

    // Test Preorder iterator
    PreorderIterator<int> preIt = tree->beginPreorder();
    vector<int> preResult;
    while (preIt != tree->endPreorder()) {
        preResult.push_back(*preIt);
        ++preIt;
    }
    CHECK((preResult == vector<int>{1, 2, 4, 5, 3}));

    // Test Inorder iterator
    InorderIterator<int> inIt = tree->beginInorder();
    vector<int> inResult;
    while (inIt != tree->endInorder()) {
        inResult.push_back(*inIt);
        ++inIt;
    }
    CHECK((inResult == vector<int>{4, 2, 5, 1, 3}));

    // Test Postorder iterator
    PostorderIterator<int> postIt = tree->beginPostorder();
    vector<int> postResult;
    while (postIt != tree->endPostorder()) {
        postResult.push_back(*postIt);
        ++postIt;
    }
    CHECK((postResult == vector<int>{4, 5, 2, 3, 1}));
}

TEST_CASE("Testing edge cases") {
    SUBCASE("Node") {
        SUBCASE("Adding nullptr as a child") {
            auto node = make_shared<Node<int>>(10);
            CHECK_FALSE(node->addChild(nullptr));
            CHECK(node->getChildren().empty());
        }

        SUBCASE("Adding multiple children") {
            auto node = make_shared<Node<int>>(10);
            auto child1 = make_shared<Node<int>>(20);
            auto child2 = make_shared<Node<int>>(30);
            auto child3 = make_shared<Node<int>>(40);
            CHECK(node->addChild(child1));
            CHECK(node->addChild(child2));
            CHECK(node->addChild(child3));
            CHECK(node->getChildren().size() == 3);
        }
    }

    SUBCASE("Complex") {
        SUBCASE("Complex number with zero") {
            Complex c1(0.0, 0.0);
            Complex c2(1.0, 1.0);
            CHECK(c1 + c2 == Complex(1.0, 1.0));
            CHECK(c1 * c2 == Complex(0.0, 0.0));
        }

        SUBCASE("Complex number multiplication with itself") {
            Complex c1(1.0, 1.0);
            CHECK(c1 * c1 == Complex(0.0, 2.0));
        }

        SUBCASE("Complex number subtraction resulting in zero") {
            Complex c1(1.0, 1.0);
            Complex c2(1.0, 1.0);
            CHECK(c1 - c2 == Complex(0.0, 0.0));
        }
    }

    SUBCASE("Tree Iterators") {
        SUBCASE("Empty tree") {
            auto tree = make_shared<Tree<int, 2>>();
            CHECK_FALSE(tree->beginBFS() != tree->endBFS());
            CHECK_FALSE(tree->beginDFS() != tree->endDFS());
            CHECK_FALSE(tree->beginPreorder() != tree->endPreorder());
            CHECK_FALSE(tree->beginInorder() != tree->endInorder());
            CHECK_FALSE(tree->beginPostorder() != tree->endPostorder());
        }

        SUBCASE("Tree with only root node") {
            auto root = make_shared<Node<int>>(1);
            DFSIterator<int> dfsIt(root);
            BFSIterator<int> bfsIt(root);
            PreorderIterator<int> preIt(root);
            InorderIterator<int> inIt(root);
            PostorderIterator<int> postIt(root);
            CHECK(*dfsIt == 1);
            CHECK(*bfsIt == 1);
            CHECK(*preIt == 1);
            CHECK(*inIt == 1);
            CHECK(*postIt == 1);
        }

        SUBCASE("Tree with single child") {
            auto root = make_shared<Node<int>>(1);
            auto child = make_shared<Node<int>>(2);
            root->addChild(child);

            DFSIterator<int> dfsIt(root);
            CHECK(*dfsIt == 1);
            ++dfsIt;
            CHECK(*dfsIt == 2);

            BFSIterator<int> bfsIt(root);
            CHECK(*bfsIt == 1);
            ++bfsIt;
            CHECK(*bfsIt == 2);

            PreorderIterator<int> preIt(root);
            CHECK(*preIt == 1);
            ++preIt;
            CHECK(*preIt == 2);

            InorderIterator<int> inIt(root);
            CHECK(*inIt == 2);
            ++inIt;
            CHECK(*inIt == 1);

            PostorderIterator<int> postIt(root);
            CHECK(*postIt == 2);
            ++postIt;
            CHECK(*postIt == 1);
        }
    }
}

TEST_CASE("Complex number arithmetic operations") {
    SUBCASE("Addition of complex numbers") {
        Complex c1(3.0, 4.0);
        Complex c2(1.0, 2.0);
        CHECK(c1 + c2 == Complex(4.0, 6.0));
    }

    SUBCASE("Subtraction of complex numbers") {
        Complex c1(3.0, 4.0);
        Complex c2(1.0, 2.0);
        CHECK(c1 - c2 == Complex(2.0, 2.0));
    }

    SUBCASE("Multiplication of complex numbers") {
        Complex c1(3.0, 4.0);
        Complex c2(1.0, 2.0);
        CHECK(c1 * c2 == Complex(-5.0, 10.0));
    }

    SUBCASE("Equality of complex numbers") {
        Complex c1(3.0, 4.0);
        Complex c2(3.0, 4.0);
        CHECK(c1 == c2);
    }

    SUBCASE("Complex number with negative values") {
        Complex c1(-1.0, -2.0);
        Complex c2(-2.0, -3.0);
        CHECK(c1 + c2 == Complex(-3.0, -5.0));
        CHECK(c1 - c2 == Complex(1.0, 1.0));
        CHECK(c1 * c2 == Complex(-4.0, 7.0));
    }
}

TEST_CASE("Tree structure") {
    SUBCASE("Adding a single node") {
        auto root = make_shared<Node<int>>(1);
        auto tree = make_shared<Tree<int, 2>>(root);
        CHECK(tree->getRoot() == root);
    }

    SUBCASE("Adding children to a node") {
        auto root = make_shared<Node<int>>(1);
        auto tree = make_shared<Tree<int, 2>>(root);
        auto child1 = make_shared<Node<int>>(2);
        auto child2 = make_shared<Node<int>>(3);
        tree->addSubNode(root, child1);
        tree->addSubNode(root, child2);
        CHECK(root->getChildren().size() == 2);
        CHECK(root->getChildren()[0] == child1);
        CHECK(root->getChildren()[1] == child2);
    }

    SUBCASE("Adding child to non-existing parent") {
        auto root = make_shared<Node<int>>(1);  // create a root node.
        auto tree = make_shared<Tree<int, 2>>(root);   // create a tree with the root node.
        auto nonExistingParent = make_shared<Node<int>>(99);  // create a non-existing parent node.
        auto child = make_shared<Node<int>>(2);  // create a child node.
        CHECK_FALSE(tree->addSubNode(nonExistingParent, child));
    }

    SUBCASE("Adding nullptr as child to a tree") {
        auto root = make_shared<Node<int>>(1);
        auto tree = make_shared<Tree<int, 2>>(root);
        CHECK_FALSE(tree->addSubNode(root, nullptr));
    }

    auto root = make_shared<Node<int>>(1);  // create a root node.
    auto tree4 = make_shared<Tree<int, 4>>(root);  // create a tree with the root node.

    auto child1 = make_shared<Node<int>>(2);
    auto child2 = make_shared<Node<int>>(3);
    auto child3 = make_shared<Node<int>>(4);
    auto child4 = make_shared<Node<int>>(5);
    tree4->addSubNode(root, child1);
    tree4->addSubNode(root, child2);
    tree4->addSubNode(root, child3);
    tree4->addSubNode(root, child4);

    auto child5 = make_shared<Node<int>>(6);
    auto child6 = make_shared<Node<int>>(7);
    auto child7 = make_shared<Node<int>>(8);
    auto child8 = make_shared<Node<int>>(9);
    tree4->addSubNode(child1, child5);
    tree4->addSubNode(child1, child6);
    tree4->addSubNode(child1, child7);
    tree4->addSubNode(child1, child8);

    auto child9 = make_shared<Node<int>>(10);
    auto child10 = make_shared<Node<int>>(11);
    auto child11 = make_shared<Node<int>>(12);
    auto child12 = make_shared<Node<int>>(13);
    tree4->addSubNode(child2, child9);
    tree4->addSubNode(child2, child10);
    tree4->addSubNode(child2, child11);
    tree4->addSubNode(child2, child12);

    SUBCASE("Iterating through 4-ary tree using BFS"){  // this test is for a 4-ary tree with 3 levels.
        string expected = "1 2 3 4 5 6 7 8 9 10 11 12 13 ";
        string result = "";
        for(auto it = tree4->beginBFS(); it != tree4->endBFS(); ++it){
            result += to_string(*it) + " ";
        }
        CHECK(result == expected);
    }

    SUBCASE("Iterating through 4-ary tree using DFS"){  // this test is for a 4-ary tree with 3 levels.
        string expected = "1 2 6 7 8 9 3 10 11 12 13 4 5 ";
        string result = "";
        for(auto it = tree4->beginDFS(); it != tree4->endDFS(); ++it){
            result += to_string(*it) + " ";
        }
        CHECK(result == expected);
    }

    // NOTE: we defined the pre/in/post order iterators to iterate the tree using the DFS iterator so the outcome will be the same.

    SUBCASE("Iterating through 4-ary tree using Preorder"){  // this test is for a 4-ary tree with 3 levels.
        string expected = "1 2 6 7 8 9 3 10 11 12 13 4 5 ";
        string result = "";
        for(auto it = tree4->beginPreorder(); it != tree4->endPreorder(); ++it){
            result += to_string(*it) + " ";
        }
        CHECK(result == expected);
    }

    SUBCASE("Iterating through 4-ary tree using Inorder"){  // this test is for a 4-ary tree with 3 levels.
        string expected = "1 2 6 7 8 9 3 10 11 12 13 4 5 ";
        string result = "";
        for(auto it = tree4->beginInorder(); it != tree4->endInorder(); ++it){
            result += to_string(*it) + " ";
        }
        CHECK(result == expected);
    }

    SUBCASE("Iterating through 4-ary tree using Postorder"){  // this test is for a 4-ary tree with 3 levels.
        string expected = "1 2 6 7 8 9 3 10 11 12 13 4 5 ";
        string result = "";
        for(auto it = tree4->beginPostorder(); it != tree4->endPostorder(); ++it){
            result += to_string(*it) + " ";
        }
        CHECK(result == expected);
    }

    Tree<int, 5> tree5;
    shared_ptr<Node<int>> root5 = make_shared<Node<int>>(1);
    child1 = make_shared<Node<int>>(2);
    child2 = make_shared<Node<int>>(3);
    child3 = make_shared<Node<int>>(4);
    child4 = make_shared<Node<int>>(5);
    child5 = make_shared<Node<int>>(6);
    child6 = make_shared<Node<int>>(7);
    child7 = make_shared<Node<int>>(8);
    child8 = make_shared<Node<int>>(9);
    child9 = make_shared<Node<int>>(10);
    child10 = make_shared<Node<int>>(11);
    child11 = make_shared<Node<int>>(12);
    child12 = make_shared<Node<int>>(13);
    shared_ptr<Node<int>> child13 = make_shared<Node<int>>(14);
    shared_ptr<Node<int>> child14 = make_shared<Node<int>>(15);
    shared_ptr<Node<int>> child15 = make_shared<Node<int>>(16);
    shared_ptr<Node<int>> child16 = make_shared<Node<int>>(17);
    shared_ptr<Node<int>> child17 = make_shared<Node<int>>(18);
    shared_ptr<Node<int>> child18 = make_shared<Node<int>>(19);
    shared_ptr<Node<int>> child19 = make_shared<Node<int>>(20);
    shared_ptr<Node<int>> child20 = make_shared<Node<int>>(21);
    shared_ptr<Node<int>> child21 = make_shared<Node<int>>(22);
    shared_ptr<Node<int>> child22 = make_shared<Node<int>>(23);
    shared_ptr<Node<int>> child23 = make_shared<Node<int>>(24);
    shared_ptr<Node<int>> child24 = make_shared<Node<int>>(25);
    shared_ptr<Node<int>> child25 = make_shared<Node<int>>(26);
    shared_ptr<Node<int>> child26 = make_shared<Node<int>>(27);
    shared_ptr<Node<int>> child27 = make_shared<Node<int>>(28);
    shared_ptr<Node<int>> child28 = make_shared<Node<int>>(29);
    shared_ptr<Node<int>> child29 = make_shared<Node<int>>(30);
    shared_ptr<Node<int>> child30 = make_shared<Node<int>>(31);
    shared_ptr<Node<int>> child31 = make_shared<Node<int>>(32);
    shared_ptr<Node<int>> child32 = make_shared<Node<int>>(33);
    shared_ptr<Node<int>> child33 = make_shared<Node<int>>(34);
    shared_ptr<Node<int>> child34 = make_shared<Node<int>>(35);
    shared_ptr<Node<int>> child35 = make_shared<Node<int>>(36);
    shared_ptr<Node<int>> child36 = make_shared<Node<int>>(37);
    shared_ptr<Node<int>> child37 = make_shared<Node<int>>(38);
    shared_ptr<Node<int>> child38 = make_shared<Node<int>>(39);
    shared_ptr<Node<int>> child39 = make_shared<Node<int>>(40);

    tree5.addRoot(root5, true);
    tree5.addSubNode(root5, child1);
    tree5.addSubNode(root5, child2);
    tree5.addSubNode(root5, child3);
    tree5.addSubNode(root5, child4);
    tree5.addSubNode(root5, child5);
    tree5.addSubNode(child1, child6);
    tree5.addSubNode(child1, child7);
    tree5.addSubNode(child1, child8);
    tree5.addSubNode(child1, child9);
    tree5.addSubNode(child1, child10);
    tree5.addSubNode(child2, child11);
    tree5.addSubNode(child2, child12);
    tree5.addSubNode(child2, child13);
    tree5.addSubNode(child2, child14);
    tree5.addSubNode(child2, child15);
    tree5.addSubNode(child3, child16);
    tree5.addSubNode(child3, child17);
    tree5.addSubNode(child3, child18);
    tree5.addSubNode(child3, child19);
    tree5.addSubNode(child3, child20);
    tree5.addSubNode(child4, child21);
    tree5.addSubNode(child4, child22);
    tree5.addSubNode(child4, child23);
    tree5.addSubNode(child4, child24);
    tree5.addSubNode(child4, child25);
    tree5.addSubNode(child5, child26);
    tree5.addSubNode(child5, child27);
    tree5.addSubNode(child5, child28);
    tree5.addSubNode(child5, child29);
    tree5.addSubNode(child5, child30);
    tree5.addSubNode(child6, child31);
    tree5.addSubNode(child6, child32);
    tree5.addSubNode(child6, child33);
    tree5.addSubNode(child6, child34);
    tree5.addSubNode(child6, child35);
    tree5.addSubNode(child7, child36);
    tree5.addSubNode(child7, child37);
    tree5.addSubNode(child7, child38);
    tree5.addSubNode(child7, child39);

    SUBCASE("Iterating through 5-ary tree using BFS"){  // this test is for a 5-ary tree with 3 levels.
        string expected = "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 ";
        string result = "";
        for(auto it = tree5.beginBFS(); it != tree5.endBFS(); ++it){
            result += to_string(*it) + " ";
        }
        CHECK(result == expected);
    }

    SUBCASE("Iterating through 5-ary tree using DFS"){  // this test is for a 5-ary tree with 3 levels.
        string expected = "1 2 7 32 33 34 35 36 8 37 38 39 40 9 10 11 3 12 13 14 15 16 4 17 18 19 20 21 5 22 23 24 25 26 6 27 28 29 30 31 ";
        string result = "";
        for(auto it = tree5.beginDFS(); it != tree5.endDFS(); ++it){
            result += to_string(*it) + " ";
        }
        CHECK(result == expected);
    }

    // NOTE: we defined the pre/in/post order iterators to iterate the tree using the DFS iterator so the outcome will be the same.

    SUBCASE("Iterating through 5-ary tree using Preorder"){  // this test is for a 5-ary tree with 3 levels.
        string expected = "1 2 7 32 33 34 35 36 8 37 38 39 40 9 10 11 3 12 13 14 15 16 4 17 18 19 20 21 5 22 23 24 25 26 6 27 28 29 30 31 ";
        string result = "";
        for(auto it = tree5.beginPreorder(); it != tree5.endPreorder(); ++it){
            result += to_string(*it) + " ";
        }
        CHECK(result == expected);
    }

    SUBCASE("Iterating through 5-ary tree using Inorder"){  // this test is for a 5-ary tree with 3 levels.
        string expected = "1 2 7 32 33 34 35 36 8 37 38 39 40 9 10 11 3 12 13 14 15 16 4 17 18 19 20 21 5 22 23 24 25 26 6 27 28 29 30 31 ";
        string result = "";
        for(auto it = tree5.beginInorder(); it != tree5.endInorder(); ++it){
            result += to_string(*it) + " ";
        }
        CHECK(result == expected);
    }

    SUBCASE("Iterating through 5-ary tree using Postorder"){  // this test is for a 5-ary tree with 3 levels.
        string expected = "1 2 7 32 33 34 35 36 8 37 38 39 40 9 10 11 3 12 13 14 15 16 4 17 18 19 20 21 5 22 23 24 25 26 6 27 28 29 30 31 ";
        string result = "";
        for(auto it = tree5.beginPostorder(); it != tree5.endPostorder(); ++it){
            result += to_string(*it) + " ";
        }
        CHECK(result == expected);
    }

}




// ID: 315310250
// EMAIL: IDOIZHAR.Mangadi@msmail.ariel.ac.il
// GMAIL: idomangadi@gmail.com

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <sstream>

#include "Tree.hpp"
#include "Complex.hpp"

using namespace std;
using namespace myTree;
using namespace myComplex;

int main(){

    // creating a binary tree of integers:
    shared_ptr<Node<int>> root = make_shared<Node<int>>(1);
    shared_ptr<Node<int>> leftChild = make_shared<Node<int>>(2);
    shared_ptr<Node<int>> rightChild = make_shared<Node<int>>(3);
    shared_ptr<Node<int>> leftLeftChild = make_shared<Node<int>>(4);
    shared_ptr<Node<int>> leftRightChild = make_shared<Node<int>>(5);
    shared_ptr<Node<int>> rightLeftChild = make_shared<Node<int>>(6);
    shared_ptr<Node<int>> rightRightChild = make_shared<Node<int>>(7);
    shared_ptr<Node<int>> leftLeftLeftChild = make_shared<Node<int>>(8);
    shared_ptr<Node<int>> leftLeftRightChild = make_shared<Node<int>>(9);
    
    Tree<int> tree;

    tree.addRoot(root, true);
    tree.addSubNode(root, leftChild);
    tree.addSubNode(root, rightChild);
    tree.addSubNode(leftChild, leftLeftChild);
    tree.addSubNode(leftChild, leftRightChild);
    tree.addSubNode(rightChild, rightLeftChild);
    tree.addSubNode(rightChild, rightRightChild);
    tree.addSubNode(leftLeftChild, leftLeftLeftChild);
    tree.addSubNode(leftLeftChild, leftLeftRightChild);

    // tree.renderTree();

    cout << "Preorder traversal:" << endl;  // should print: 1 2 4 8 9 5 3 6 7
    for(auto it = tree.beginPreorder(); it != tree.endPreorder(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "Inorder traversal:" << endl;  // should print: 8 4 9 2 5 1 6 3 7
    for(auto it = tree.beginInorder(); it != tree.endInorder(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "postorder traversal:" << endl;  // should print: 8 9 4 5 2 6 7 3 1
    for(auto it = tree.beginPostorder(); it != tree.endPostorder(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout<< "BFS traversal:" << endl;  // should print: 1 2 3 4 5 6 7 8 9
    for(auto it = tree.beginBFS(); it != tree.endBFS(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "DFS traversal:" << endl;  // should print: 1 2 4 8 9 5 3 6 7
    for(auto it = tree.beginDFS(); it != tree.endDFS(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "Heap traversal:" << endl;  // should print: 1 2 3 4 5 6 7 8 9
    for(auto it = tree.beginHeap(); it != tree.endHeap(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    // NOTE: for non-binary trees. there is no heap traversal and for preorder, inorder and postorder traversals we will use the DFS iterator.
    // creating 3-ary tree of integers:
    Tree<int, 3> tree3;
    shared_ptr<Node<int>> root3 = make_shared<Node<int>>(1);
    shared_ptr<Node<int>> leftChild3 = make_shared<Node<int>>(2);
    shared_ptr<Node<int>> middleChild3 = make_shared<Node<int>>(3);
    shared_ptr<Node<int>> rightChild3 = make_shared<Node<int>>(4);
    shared_ptr<Node<int>> leftLeftChild3 = make_shared<Node<int>>(5);
    shared_ptr<Node<int>> leftMiddleChild3 = make_shared<Node<int>>(6);
    shared_ptr<Node<int>> leftRightChild3 = make_shared<Node<int>>(7);
    shared_ptr<Node<int>> middleLeftChild3 = make_shared<Node<int>>(8);
    shared_ptr<Node<int>> middleMiddleChild3 = make_shared<Node<int>>(9);
    shared_ptr<Node<int>> middleRightChild3 = make_shared<Node<int>>(10);
    shared_ptr<Node<int>> rightLeftChild3 = make_shared<Node<int>>(11);
    shared_ptr<Node<int>> rightMiddleChild3 = make_shared<Node<int>>(12);
    shared_ptr<Node<int>> rightRightChild3 = make_shared<Node<int>>(13);

    tree3.addRoot(root3, true);
    tree3.addSubNode(root3, leftChild3);
    tree3.addSubNode(root3, middleChild3);
    tree3.addSubNode(root3, rightChild3);
    tree3.addSubNode(leftChild3, leftLeftChild3);
    tree3.addSubNode(leftChild3, leftMiddleChild3);
    tree3.addSubNode(leftChild3, leftRightChild3);
    tree3.addSubNode(middleChild3, middleLeftChild3);
    tree3.addSubNode(middleChild3, middleMiddleChild3);
    tree3.addSubNode(middleChild3, middleRightChild3);
    tree3.addSubNode(rightChild3, rightLeftChild3);
    tree3.addSubNode(rightChild3, rightMiddleChild3);
    tree3.addSubNode(rightChild3, rightRightChild3);

    // tree3.renderTree();

    cout << "Preorder traversal:" << endl;  // should print: 1 2 5 6 7 3 8 9 10 4 11 12 13
    for(auto it = tree3.beginPreorder(); it != tree3.endPreorder(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "Inorder traversal:" << endl;  // should print: 1 2 5 6 7 3 8 9 10 4 11 12 13
    for(auto it = tree3.beginInorder(); it != tree3.endInorder(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "postorder traversal:" << endl;  // should print: 1 2 5 6 7 3 8 9 10 4 11 12 13
    for(auto it = tree3.beginPostorder(); it != tree3.endPostorder(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout<< "BFS traversal:" << endl;  // should print: 1 2 3 4 5 6 7 8 9 10 11 12 13
    for(auto it = tree3.beginBFS(); it != tree3.endBFS(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "DFS traversal:" << endl;  // should print: 1 2 5 6 7 3 8 9 10 4 11 12 13
    for(auto it = tree3.beginDFS(); it != tree3.endDFS(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    // creating 4-ary tree of integers:
    auto root4 = make_shared<Node<int>>(1);  // create a root node.
    auto tree4 = make_shared<Tree<int, 4>>(root4);  // create a tree with the root node.

    auto child1 = make_shared<Node<int>>(2);
    auto child2 = make_shared<Node<int>>(3);
    auto child3 = make_shared<Node<int>>(4);
    auto child4 = make_shared<Node<int>>(5);
    tree4->addSubNode(root4, child1);
    tree4->addSubNode(root4, child2);
    tree4->addSubNode(root4, child3);
    tree4->addSubNode(root4, child4);

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

    // tree4->renderTree();

    cout << "Preorder traversal:" << endl;  // should print: 1 2 6 7 8 9 3 10 11 12 13 4 5
    for(auto it = tree4->beginPreorder(); it != tree4->endPreorder(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "Inorder traversal:" << endl;  // should print: 1 2 6 7 8 9 3 10 11 12 13 4 5
    for(auto it = tree4->beginInorder(); it != tree4->endInorder(); ++it){
        cout << *it << " ";
    }
    cout << endl;
    
    cout << "postorder traversal:" << endl;  // should print: 1 2 6 7 8 9 3 10 11 12 13 4 5
    for(auto it = tree4->beginPostorder(); it != tree4->endPostorder(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout<< "BFS traversal:" << endl;  // should print: 1 2 3 4 5 6 7 8 9 10 11 12 13
    for(auto it = tree4->beginBFS(); it != tree4->endBFS(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "DFS traversal:" << endl;  // should print: 1 2 6 7 8 9 3 10 11 12 13 4 5
    for(auto it = tree4->beginDFS(); it != tree4->endDFS(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    // creating a binary tree of complex numbers:
    Tree<Complex> treeComplex;
    shared_ptr<Node<Complex>> rootComplex = make_shared<Node<Complex>>(Complex(1, 2));
    shared_ptr<Node<Complex>> leftChildComplex = make_shared<Node<Complex>>(Complex(3, 4));
    shared_ptr<Node<Complex>> rightChildComplex = make_shared<Node<Complex>>(Complex(5, 6));
    shared_ptr<Node<Complex>> leftLeftChildComplex = make_shared<Node<Complex>>(Complex(7, 8));
    shared_ptr<Node<Complex>> leftRightChildComplex = make_shared<Node<Complex>>(Complex(9, 10));
    shared_ptr<Node<Complex>> rightLeftChildComplex = make_shared<Node<Complex>>(Complex(11, 12));
    shared_ptr<Node<Complex>> rightRightChildComplex = make_shared<Node<Complex>>(Complex(13, 14));
    shared_ptr<Node<Complex>> leftLeftLeftChildComplex = make_shared<Node<Complex>>(Complex(15, 16));
    shared_ptr<Node<Complex>> leftLeftRightChildComplex = make_shared<Node<Complex>>(Complex(17, 18));

    treeComplex.addRoot(rootComplex, true);
    treeComplex.addSubNode(rootComplex, leftChildComplex);
    treeComplex.addSubNode(rootComplex, rightChildComplex);
    treeComplex.addSubNode(leftChildComplex, leftLeftChildComplex);
    treeComplex.addSubNode(leftChildComplex, leftRightChildComplex);
    treeComplex.addSubNode(rightChildComplex, rightLeftChildComplex);
    treeComplex.addSubNode(rightChildComplex, rightRightChildComplex);
    treeComplex.addSubNode(leftLeftChildComplex, leftLeftLeftChildComplex);
    treeComplex.addSubNode(leftLeftChildComplex, leftLeftRightChildComplex);

    // treeComplex.renderTree();

    cout << "Preorder traversal:" << endl;  // should print: 1 + 2i 3 + 4i 7 + 8i 15 + 16i 17 + 18i 9 + 10i 5 + 6i 11 + 12i 13 + 14i
    for(auto it = treeComplex.beginPreorder(); it != treeComplex.endPreorder(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "Inorder traversal:" << endl;  // should print: 15 + 16i 7 + 8i 17 + 18i 3 + 4i 9 + 10i 1 + 2i 5 + 6i 11 + 12i 13 + 14i
    for(auto it = treeComplex.beginInorder(); it != treeComplex.endInorder(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "postorder traversal:" << endl;  // should print: 15 + 16i 17 + 18i 7 + 8i 9 + 10i 4 + 3i 11 + 12i 14 + 13i 6 + 5i 2 + 1i
    for(auto it = treeComplex.beginPostorder(); it != treeComplex.endPostorder(); ++it){
        cout << *it << " ";
    }
    cout << endl;
    
    cout<< "BFS traversal:" << endl;  // should print: 1 + 2i 3 + 4i 5 + 6i 7 + 8i 9 + 10i 11 + 12i 13 + 14i 15 + 16i 17 + 18i
    for(auto it = treeComplex.beginBFS(); it != treeComplex.endBFS(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "DFS traversal:" << endl;  // should print: 1 + 2i 3 + 4i 7 + 8i 15 + 16i 17 + 18i 9 + 10i 5 + 6i 11 + 12i 13 + 14i
    for(auto it = treeComplex.beginDFS(); it != treeComplex.endDFS(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    // creating a binary tree of strings:
    Tree<string> treeString;
    shared_ptr<Node<string>> rootString = make_shared<Node<string>>("1");
    shared_ptr<Node<string>> leftChildString = make_shared<Node<string>>("2");
    shared_ptr<Node<string>> rightChildString = make_shared<Node<string>>("3");
    shared_ptr<Node<string>> leftLeftChildString = make_shared<Node<string>>("4");
    shared_ptr<Node<string>> leftRightChildString = make_shared<Node<string>>("5");
    shared_ptr<Node<string>> rightLeftChildString = make_shared<Node<string>>("6");
    shared_ptr<Node<string>> rightRightChildString = make_shared<Node<string>>("7");
    shared_ptr<Node<string>> leftLeftLeftChildString = make_shared<Node<string>>("8");
    shared_ptr<Node<string>> leftLeftRightChildString = make_shared<Node<string>>("9");

    treeString.addRoot(rootString, true);
    treeString.addSubNode(rootString, leftChildString);
    treeString.addSubNode(rootString, rightChildString);
    treeString.addSubNode(leftChildString, leftLeftChildString);
    treeString.addSubNode(leftChildString, leftRightChildString);
    treeString.addSubNode(rightChildString, rightLeftChildString);
    treeString.addSubNode(rightChildString, rightRightChildString);
    treeString.addSubNode(leftLeftChildString, leftLeftLeftChildString);
    treeString.addSubNode(leftLeftChildString, leftLeftRightChildString);

    // treeString.renderTree();

    cout << "Preorder traversal:" << endl;  // should print: 1 2 4 8 9 5 3 6 7
    for(auto it = treeString.beginPreorder(); it != treeString.endPreorder(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "Inorder traversal:" << endl;  // should print: 8 4 9 2 5 1 6 3 7
    for(auto it = treeString.beginInorder(); it != treeString.endInorder(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "postorder traversal:" << endl;  // should print: 8 9 4 5 2 6 7 3 1
    for(auto it = treeString.beginPostorder(); it != treeString.endPostorder(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout<< "BFS traversal:" << endl;  // should print: 1 2 3 4 5 6 7 8 9
    for(auto it = treeString.beginBFS(); it != treeString.endBFS(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "DFS traversal:" << endl;  // should print: 1 2 4 8 9 5 3 6 7
    for(auto it = treeString.beginDFS(); it != treeString.endDFS(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
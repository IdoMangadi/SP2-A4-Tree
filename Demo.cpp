// ID: 315310250
// EMAIL: IDOIZHAR.Mangadi@msmail.ariel.ac.il
// GMAIL: idomangadi@gmail.com

#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "Tree.hpp"
#include "TreeIterators.hpp"
#include "Complex.hpp"

using namespace std;
using namespace myTree;

int main(){

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

    // creating 3-ary tree:
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

    return 0;
}

#include <iostream>
#include <vector>
#include <memory>

#include "TreeIterators.hpp"

using namespace std;

namespace myTree{

    /**
     * class representing a node of the tree.
     * the node contaion value (can be primitive or object) and a vector of children.
     */
    template <typename T>
    class Node{
        public:
            T value;  // value of the node.
            vector<shared_ptr<Node<T>>> children;  // children of the node.
            Node(T value);  // constructor.
            bool addChild(T value);  // add a child to the node.
            bool addChild(shared_ptr<Node<T>> node);  // add a child to the node.

            friend ostream& operator<<(ostream& os, Node<T> node);  // overloading iostram operator for the node:
            string to_string();  // to_string method: 
    };

    /**
     * class representing a tree.
     * the tree contain a root node.
     */
    template <typename T>
    class Tree{
        private:
            shared_ptr<Node<T>> root;  // root node of the tree.
            size_t k;  // number of children for each node.
        public:
            /**
             * constructor.
             */
            Tree(size_t k);
            /**
             * default constructor (crate a binary tree).
             */
            Tree(); 
            /**
             * add a root to the tree.
             */
            bool addRoot(T value);
            bool addRoot(shared_ptr<Node<T>> node, bool attachChildren);  // (in case the tree is not empty the method will replace the root)

            bool addSubNode(shared_ptr<Node<T>> parent, shared_ptr<Node<T>> newChild);  // add a child to a given node.

            // iterators:
            PreorderIterator<T> beginPreorder();
            PreorderIterator<T> endPreorder();
            InorderIterator<T> beginInorder();
            InorderIterator<T> endInorder();
            PostorderIterator<T> beginPostorder();
            PostorderIterator<T> endPostorder();
            BFSIterator<T> beginBFS();
            BFSIterator<T> endBFS();
            DFSIterator<T> beginDFS();
            DFSIterator<T> endDFS();
    };

} // namespace myTree
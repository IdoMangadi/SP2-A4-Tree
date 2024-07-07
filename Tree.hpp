// ID: 315310250
// EMAIL: IDOIZHAR.Mangadi@msmail.ariel.ac.il
// GMAIL: idomangadi@gmail.com

#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <queue>

#include "TreeIterators.hpp"

using namespace std;

namespace myTree{

    /**
     * An abstract class that represent a tree.
     * will be extended to binary tree and K-ary tree.
     */
    template <typename T, size_t K>
    class BaseTree{
        protected:
            shared_ptr<Node<T>> root;
        public:
            BaseTree() : root(nullptr){}  // constructor.
            BaseTree(shared_ptr<Node<T>> root) : root(root){}  // constructor.

            bool addRoot(shared_ptr<Node<T>> root, bool override = false){  // add a root to the tree.
                if(this->root != nullptr && !override){
                    return false;
                }
                this->root = root;
                return true;
            }
            
            shared_ptr<Node<T>> getRoot(){  // return the root of the tree.
                return this->root;
            }

            bool addSubNode(shared_ptr<Node<T>> parent, shared_ptr<Node<T>> child){  // add a child to a parent node.
                if(parent == nullptr || child == nullptr || parent == child || parent->getChildren().size() >= K){
                    return false;
                }
                return parent->addChild(child);
            }

            // iterators (for the pre/in/post order we will travers the tree using the DFS iterator).
            DFSIterator<T> beginPreorder(){
                return DFSIterator<T>(this->root);
            }
            DFSIterator<T> endPreorder(){
                return DFSIterator<T>(nullptr);
            }

            DFSIterator<T> beginInorder(){
                return DFSIterator<T>(this->root);
            }
            DFSIterator<T> endInorder(){
                return DFSIterator<T>(nullptr);
            }

            DFSIterator<T> beginPostorder(){
                return DFSIterator<T>(this->root);
            }
            DFSIterator<T> endPostorder(){
                return DFSIterator<T>(nullptr);
            }

            BFSIterator<T> beginBFS(){
                return BFSIterator<T>(this->root);
            }
            BFSIterator<T> endBFS(){
                return BFSIterator<T>(nullptr);
            }

            DFSIterator<T> beginDFS(){
                return DFSIterator<T>(this->root);
            }
            DFSIterator<T> endDFS(){
                return DFSIterator<T>(nullptr);
            }

            virtual void pureVirtual() = 0; // pure virtual function.
    };

    /**
     * this class represent a K-ary tree.
     */
    template <typename T, size_t K = 2>
    class Tree : public BaseTree<T, K>{
        public:
            Tree() : BaseTree<T, K>(){}  // constructor.
            Tree(shared_ptr<Node<T>> root) : BaseTree<T, K>(root){}  // constructor.

            void pureVirtual() override{}  // overriding the pure virtual function.
    };

    /**
     * this class represent a binary tree.
     */
    template <typename T>
    class Tree<T, 2> : public BaseTree<T, 2>{
        public:
            Tree() : BaseTree<T, 2>(){}  // constructor.
            Tree(shared_ptr<Node<T>> root) : BaseTree<T, 2>(root){}  // constructor.

            void pureVirtual() override{}  // overriding the pure virtual function.

            // iterators (can use the pre/in/post order iterators).
            PreorderIterator<T> beginPreorder(){
                return PreorderIterator<T>(this->root);
            }
            PreorderIterator<T> endPreorder(){
                return PreorderIterator<T>(nullptr);
            }

            InorderIterator<T> beginInorder(){
                return InorderIterator<T>(this->root);
            }
            InorderIterator<T> endInorder(){
                return InorderIterator<T>(nullptr);
            }

            PostorderIterator<T> beginPostorder(){
                return PostorderIterator<T>(this->root);
            }
            PostorderIterator<T> endPostorder(){
                PostorderIterator<T> it(this->root); // Initialize with root
                it.setToEnd(); // A method in PostorderIterator to set index to postorderNodes.size()
                return it;
            }
    };

} // namespace myTree

#endif // TREE_HPP
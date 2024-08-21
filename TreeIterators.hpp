#ifndef TREE_ITERATORS_HPP
#define TREE_ITERATORS_HPP

// #pragma once

#include <stack>
#include <queue>
#include "Node.hpp"

using namespace std;

namespace myTree {

    /**
     * preorder iterator class.
     * will work on a binary tree nodes when node->getChildren().at(0) is the left child and node->getChildren().at(1) is the right child.
     */
    template <typename T>
    class PreorderIterator {
        private: 
            stack<shared_ptr<Node<T>>> nodeStack;  // stack of nodes.
        public:
            PreorderIterator(shared_ptr<Node<T>> root) {  // constructor.
                if(root != nullptr){
                    nodeStack.push(root);
                }
            }

            T& operator*() {  // dereference operator.
                return nodeStack.top()->getValue();
            }

            Node<T>* operator->() {  // returning the node.
                return nodeStack.top().get();
            }

            PreorderIterator& operator++() {  // increment operator.
                shared_ptr<Node<T>> node = nodeStack.top();
                nodeStack.pop();
                if (!node->getChildren().empty()) {
                    auto& children = node->getChildren();
                    for (auto it = children.rbegin(); it != children.rend(); ++it) {  // this approach ensures that the left child is processed first
                        nodeStack.push(*it);
                    }
                }
                return *this;
            }

            bool operator!=(const PreorderIterator& other) const{  // not equal operator.
                return this->nodeStack.size() != other.nodeStack.size();
            }
    };

    /**
     * inorder iterator class.
     * will work on a binary tree nodes when node->getChildren().at(0) is the left child and node->getChildren().at(1) is the right child.
     */
    template <typename T>
    class InorderIterator {
    private:
        stack<shared_ptr<Node<T>>> nodeStack;  // stack of nodes.

        void pushLeftChildren(shared_ptr<Node<T>> node) {
            while (node != nullptr) {
                nodeStack.push(node);
                if (!node->getChildren().empty()) {
                    node = node->getChildren().at(0);
                } else {
                    break;
                }
            }
        }

    public:
        InorderIterator(shared_ptr<Node<T>> root) {  // constructor.
            pushLeftChildren(root);
        }

        T& operator*() {  // dereference operator.
            return nodeStack.top()->getValue();
        }

        Node<T>* operator->() {  // returning the node.
            return nodeStack.top().get();
        }

        InorderIterator& operator++() {  // increment operator.
            shared_ptr<Node<T>> node = nodeStack.top();
            nodeStack.pop();
            if (!node->getChildren().empty() && node->getChildren().size() > 1) {  // If right child exists
                pushLeftChildren(node->getChildren().at(1));  // Push left children of right child
            }
            return *this;
        }

        bool operator!=(const InorderIterator& other) const{  // not equal operator.
            // This might not be the correct way to compare iterators.
            // Consider comparing the current node or using a sentinel value for the end.
            return !nodeStack.empty() || !other.nodeStack.empty();
        }
    };

    /**
     * postorder iterator class.
     * will work on a binary tree nodes when node->getChildren().at(0) is the left child and node->getChildren().at(1) is the right child.
     * to implement this iterator:
     * in the constructor we will create a vector of nodes ordered by postorder traversal.
     * in the increment operator we will increment the index of the vector.
     * in the dereference operator we will return the value of the node in the current index.
     * in the not equal operator we will compare the index of the vector.
     */
    template <typename T>
    class PostorderIterator{
        private:
            vector<shared_ptr<Node<T>>> postorderNodes;  // vector of nodes ordered by postorder traversal.
            size_t index;  // index of the vector.
        public:
            PostorderIterator(shared_ptr<Node<T>> root) : index(0) {
                if (!root) return;  // Handle empty tree case

                stack<shared_ptr<Node<T>>> nodeStack, reverseStack;
                nodeStack.push(root);

                while (!nodeStack.empty()) {
                    shared_ptr<Node<T>> node = nodeStack.top();
                    nodeStack.pop();
                    reverseStack.push(node);

                    // Assuming binary tree, push left then right child to ensure they are processed before the node
                    if (!node->getChildren().empty()) {
                        if (node->getChildren().size() > 0 && node->getChildren().at(0) != nullptr) {
                            nodeStack.push(node->getChildren().at(0));  // Left child
                        }
                        if (node->getChildren().size() > 1 && node->getChildren().at(1) != nullptr) {
                            nodeStack.push(node->getChildren().at(1));  // Right child
                        }
                    }
                }

                // Now populate postorderNodes by popping from reverseStack
                while (!reverseStack.empty()) {
                    postorderNodes.push_back(reverseStack.top());
                    reverseStack.pop();
                }
            }

            void setToEnd() {
                index = postorderNodes.size(); // Sets the iterator to the end
            }

            T& operator*() {  // dereference operator.
                return postorderNodes.at(index)->getValue();
            }

            Node <T>* operator->() {  // returning the node.
                return postorderNodes.at(index).get();
            }

            PostorderIterator& operator++() {  // increment operator.
                index++;
                return *this;
            }

            bool operator!=(const PostorderIterator& other) const{  // not equal operator.
                return index != other.index;
            }
    };


    /**
     * BFS iterator class.
     * will work on a k-ary tree nodes.
     */
    template <typename T>
    class BFSIterator {
        private:
            queue<shared_ptr<Node<T>>> nodeQueue;  // queue of nodes.
        public:
            BFSIterator(shared_ptr<Node<T>> root) {  // constructor.
                if(root != nullptr){
                    nodeQueue.push(root);
                }
            }

            T& operator*() {  // dereference operator.
                return nodeQueue.front()->getValue();
            }

            Node<T>* operator->() {  // returning the node.
                return nodeQueue.front().get();
            }

            BFSIterator& operator++() {  // increment operator.
                shared_ptr<Node<T>> node = nodeQueue.front();
                nodeQueue.pop();
                for(auto child : node->getChildren()){
                    nodeQueue.push(child);
                }
                return *this;
            }

            bool operator!=(const BFSIterator& other) const{  // not equal operator.
                return nodeQueue.size() != other.nodeQueue.size();
            }
    };

    /**
     * DFS iterator class. 
     * will work on a k-ary tree nodes.
     */
    template <typename T>
    class DFSIterator {
    private:
        stack<shared_ptr<Node<T>>> nodeStack;  // Stack of nodes.

    public:
        DFSIterator(shared_ptr<Node<T>> root) {  // Constructor.
            if(root != nullptr){
                nodeStack.push(root);
            }
        }

        T& operator*() {  // Dereference operator.
            return nodeStack.top()->getValue();
        }

        Node<T>* operator->() {  // Returning the node.
            return nodeStack.top().get();
        }

        DFSIterator& operator++() {  // Pre-increment operator.
            if (!nodeStack.empty()) {
                shared_ptr<Node<T>> node = nodeStack.top();
                nodeStack.pop();
                const auto& children = node->getChildren();
                for (auto it = children.rbegin(); it != children.rend(); ++it) {
                    nodeStack.push(*it);
                }
            }
            return *this;
        }

        bool operator!=(const DFSIterator& other) const{  // Not equal operator.
            // This is a simplistic way to compare iterators, which might not work in all cases.
            // A more robust implementation would be needed for a fully correct comparison.
            return !nodeStack.empty() || !other.nodeStack.empty();
        }
    };

    /**
     * HeapIterator class.
     * this class will be used to iterate over a binary tree and return the values in a minimum heap order.
     */
    template<typename T>
    class HeapIterator {
        private:
            
            vector<T> heap;
            int heapSize = 0; // Current position in the heap

            void buildHeap(shared_ptr<Node<T>> root) {
                if (!root) return;
                
                // putt all the nodes in the tree in the heap vector.
                for(auto it = DFSIterator<T>(root); it != DFSIterator<T>(nullptr); ++it){
                    heap.push_back(*it);
                }

                make_heap(heap.begin(), heap.end(), greater<T>());  // Make the heap a min heap
                heapSize = heap.size();  // Set the heap size to the size of the heap vector
            }

        public:
            HeapIterator(shared_ptr<Node<T>> root) {
                buildHeap(root);
            }

            T& operator*() {
                if (heap.size() > 0) {
                    return heap.front();
                }
                throw std::out_of_range("HeapIterator dereference out of range");
            }

            HeapIterator& operator++() {
                if (heapSize > 0) {
                    // Pop the smallest element by moving it to the end and reducing the heap size.
                    pop_heap(heap.begin(), heap.begin() + heapSize, greater<T>());
                    heapSize--; // Reduce the heap size, effectively removing the last element

                    // No need to re-heapify explicitly as pop_heap already does that.
                }
                return *this;
            }

            bool operator!=(const HeapIterator& other) const{
                return heapSize != other.heapSize;
            }

            // Assuming end iterator is created with a default constructor or nullptr root
            HeapIterator() : heapSize(0) {}

            // Helper function to set index for the end iterator
            // void setToEnd() {
            //     heapSize = 0;
            // }
    };
    

} // namespace myTree

#endif // TREE_ITERATORS_HPP
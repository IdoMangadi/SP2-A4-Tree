
#include "TreeIterators.hpp"

namespace myTree {

    // PreorderIterator Implementation:
    template<typename T>
    PreorderIterator<T>::PreorderIterator(std::shared_ptr<Node<T>> root) {
        if (root) nodeStack.push(root);
    }

    template<typename T>
    bool PreorderIterator<T>::operator!=(const PreorderIterator& other) const {
        return !nodeStack.empty();
    }

    template<typename T>
    T& PreorderIterator<T>::operator*() {
        return nodeStack.top()->value;
    }

    template<typename T>
    PreorderIterator<T>& PreorderIterator<T>::operator++() {
        auto node = nodeStack.top();
        nodeStack.pop();
        for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
            nodeStack.push(*it);
        }
        return *this;
    }

    template<typename T>
    PreorderIterator<T> PreorderIterator<T>::end() {
        return PreorderIterator(nullptr);
    }

    // InorderIterator implementation:
    template<typename T>
    InorderIterator<T>::InorderIterator(std::shared_ptr<Node<T>> root) {
        pushLeft(root);
    }

    template<typename T>
    bool InorderIterator<T>::operator!=(const InorderIterator& other) const {
        return !nodeStack.empty();
    }

    template<typename T>
    T& InorderIterator<T>::operator*() {
        return nodeStack.top()->value;
    }

    template<typename T>
    InorderIterator<T>& InorderIterator<T>::operator++() {
        auto node = nodeStack.top();
        nodeStack.pop();
        pushLeft(node->children.back());
        return *this;
    }

    template<typename T>
    void InorderIterator<T>::pushLeft(std::shared_ptr<Node<T>> node) {
        while (node) {
            nodeStack.push(node);
            node = node->children.front();
        }
    }

    template<typename T>
    InorderIterator<T> InorderIterator<T>::end() {
        return InorderIterator(nullptr);
    }

    // PostorderIterator implementation:
    template<typename T>
    PostorderIterator<T>::PostorderIterator(std::shared_ptr<Node<T>> root) {
        pushLeftMost(root);
    }

    template<typename T>
    bool PostorderIterator<T>::operator!=(const PostorderIterator& other) const {
        return !nodeStack.empty();
    }

    template<typename T>
    T& PostorderIterator<T>::operator*() {
        return nodeStack.top()->value;
    }

    template<typename T>
    PostorderIterator<T>& PostorderIterator<T>::operator++() {
        auto node = nodeStack.top();
        nodeStack.pop();
        if (!nodeStack.empty()) {
            auto parent = nodeStack.top();
            if (node->children.back() != lastNodeVisited) {
                pushLeftMost(parent->children[parent->children.size() - 2]);
            }
            else {
                lastNodeVisited = parent;
            }
        }
        return *this;
    }

    template<typename T>
    void PostorderIterator<T>::pushLeftMost(std::shared_ptr<Node<T>> node) {
        while (node) {
            nodeStack.push(node);
            node = node->children.front();
        }
    }

    template<typename T>
    PostorderIterator<T> PostorderIterator<T>::end() {
        return PostorderIterator(nullptr);
    }

    // BFSIterator Implementation
    template <typename T>
    BFSIterator<T>::BFSIterator(std::shared_ptr<Node<T>> root) {
        if (root) nodeQueue.push(root);
    }

    template <typename T>
    bool BFSIterator<T>::operator!=(const BFSIterator<T>& other) const {
        return !nodeQueue.empty();
    }

    template <typename T>
    T& BFSIterator<T>::operator*() {
        return nodeQueue.front()->value;
    }

    template <typename T>
    BFSIterator<T>& BFSIterator<T>::operator++() {
        auto current = nodeQueue.front();
        nodeQueue.pop();
        if (current->left) nodeQueue.push(current->left);
        if (current->right) nodeQueue.push(current->right);
        return *this;
    }

    template <typename T>
    BFSIterator<T> BFSIterator<T>::end() {
        return BFSIterator(nullptr);
    }

    // DFSIterator Implementation
    template <typename T>
    DFSIterator<T>::DFSIterator(std::shared_ptr<Node<T>> root) {
        if (root) nodeStack.push(root);
    }

    template <typename T>
    bool DFSIterator<T>::operator!=(const DFSIterator<T>& other) const {
        return !nodeStack.empty();
    }

    template <typename T>
    T& DFSIterator<T>::operator*() {
        return nodeStack.top()->value;
    }

    template <typename T>
    DFSIterator<T>& DFSIterator<T>::operator++() {
        auto current = nodeStack.top();
        nodeStack.pop();
        if (current->right) nodeStack.push(current->right);
        if (current->left) nodeStack.push(current->left);
        return *this;
    }

    template <typename T>
    DFSIterator<T> DFSIterator<T>::end() {
        return DFSIterator(nullptr);
    }

} // namespace myTree

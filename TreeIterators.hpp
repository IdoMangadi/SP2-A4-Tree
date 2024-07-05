#ifndef TREE_ITERATORS_HPP
#define TREE_ITERATORS_HPP

#include "Tree.hpp"
#include <stack>
#include <memory>
#include <vector>

namespace myTree {

    template <typename T>
    class PreorderIterator {
        std::stack<std::shared_ptr<Node<T>>> nodeStack;
    public:
        PreorderIterator(std::shared_ptr<Node<T>> root);
        bool operator!=(const PreorderIterator& other) const;
        T& operator*();
        PreorderIterator& operator++();
        static PreorderIterator end();
    };

    template <typename T>
    class InorderIterator {
        std::stack<std::shared_ptr<Node<T>>> nodeStack;
        void pushLeft(std::shared_ptr<Node<T>> node);
    public:
        InorderIterator(std::shared_ptr<Node<T>> root);
        bool operator!=(const InorderIterator& other) const;
        T& operator*();
        InorderIterator& operator++();
        static InorderIterator end();
    };

    template <typename T>
    class PostorderIterator {
        std::stack<std::shared_ptr<Node<T>>> nodeStack;
        std::shared_ptr<Node<T>> lastNodeVisited;
        void pushLeftMost(std::shared_ptr<Node<T>> node);
    public:
        PostorderIterator(std::shared_ptr<Node<T>> root);
        bool operator!=(const PostorderIterator& other) const;
        T& operator*();
        PostorderIterator& operator++();
        static PostorderIterator end();
    };

    template <typename T>
    class BFSIterator {
        std::queue<std::shared_ptr<Node<T>>> nodeQueue;
    public:
        BFSIterator(std::shared_ptr<Node<T>> root);
        bool operator!=(const BFSIterator& other) const;
        T& operator*();
        BFSIterator& operator++();
        static BFSIterator end();
    };

    template <typename T>
    class DFSIterator {
        std::stack<std::shared_ptr<Node<T>>> nodeStack;
    public:
        DFSIterator(std::shared_ptr<Node<T>> root);
        bool operator!=(const DFSIterator& other) const;
        T& operator*();
        DFSIterator& operator++();
        static DFSIterator end();
    };

}  // namespace myTree

#endif // TREE_ITERATORS_HPP
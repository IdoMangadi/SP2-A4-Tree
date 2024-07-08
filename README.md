# SP2-A4-Tree
Systems Programming - Assignment 4 - Tree

# Tree Library

## Overview

This library provides an implementation of a general tree structure, including binary trees and K-ary trees. It includes the following components:

- **Node**: A template class representing a node in the tree.
- **Tree**: A template class for representing both binary and K-ary trees.
- **Complex**: A class for handling complex numbers, included to demonstrate the library's versatility.
- **TreeIterators**: Various iterators for traversing the tree (DFS, BFS, Preorder, Inorder, Postorder, Heap).

### Node

- **Node**: Represents a single node in the tree.
  - **Methods**:
    - `T getValue() const`: Returns the value of the node.
    - `std::vector<std::shared_ptr<Node<T>>>& getChildren()`: Returns the children of the node.
    - `bool addChild(std::shared_ptr<Node<T>> child)`: Adds a child to the node.

### Tree

- **BaseTree**: An abstract base class for trees.
  - **Methods**:
    - `bool addRoot(std::shared_ptr<Node<T>> root, bool override = false)`: Adds a root to the tree.
    - `std::shared_ptr<Node<T>> getRoot()`: Returns the root of the tree.
    - `bool addSubNode(std::shared_ptr<Node<T>> parent, std::shared_ptr<Node<T>> child)`: Adds a child to a parent node.
    - Various iterators for traversing the tree (DFS, BFS, Preorder, Inorder, Postorder, Heap).
    - `void renderTree()`: Renders the tree using SFML.

- **Tree**: A template class for binary and K-ary trees, derived from `BaseTree`.

### Complex

- **Complex**: A class for handling complex numbers.
  - **Methods**:
    - `Complex operator+(const Complex& other) const`
    - `Complex operator-(const Complex& other) const`
    - `Complex operator*(const Complex& other) const`
    - `bool operator==(const Complex& other) const`
    - `friend std::ostream& operator<<(std::ostream& os, const Complex& c)`

### TreeIterators

- **DFSIterator**: Depth-first search iterator.
- **BFSIterator**: Breadth-first search iterator.
- **PreorderIterator**: Preorder iterator.
- **InorderIterator**: Inorder iterator.
- **PostorderIterator**: Postorder iterator.
- **HeapIterator**: Heap iterator.

## Installation

run tests:
```bash
make run_test
```

run Demo.cpp:
```bash
make tree
```



#include "Tree.hpp"

using namespace std;

namespace myTree{

    template <typename T>
    Node<T>::Node(T value) : value(value){}

    template <typename T>
    bool Node<T>::addChild(T value){
        shared_ptr<Node<T>> child = make_shared<Node<T>>(value);
        this->children.push_back(child);
        return true;
    }

    template <typename T>
    bool Node<T>::addChild(shared_ptr<Node<T>> node){
        this->children.push_back(node);
        return true;
    }

    template <typename T>
    ostream& operator<<(ostream& os, Node<T> node){
        os << node.value;
        return os;
    }

    template <typename T>
    string Node<T>::to_string(){
        return this->value;
    }

    template <typename T>
    Tree<T>::Tree(size_t k) : k(k){
        root = nullptr;
    }

    template <typename T>
    Tree<T>::Tree() : Tree(2){}

    template <typename T>
    bool Tree<T>::addRoot(T value){
        this->root->value = value;
        return true;
    }

    template <typename T>
    bool Tree<T>::addRoot(shared_ptr<Node<T>> node, bool attachChildren){
        if(attachChildren){
            if(node->children.size() > this->k) return false;  // means that the given node has more children than a node in the tree can have.
            this->root = node;  // attach the children of the given node to the root.
        }
        else{
            node->chidren = this->root->children;  // attach the children of the root to the given node.
            this->root = node;
        }
        return true;
    }

    template <typename T>
    bool Tree<T>::addSubNode(shared_ptr<Node<T>> parent, shared_ptr<Node<T>> newChild){
        if(parent->children.size() == this->k) return false;  // means the parent node has the maximum number of children.
        parent->addChild(newChild);
        return true;
    }

    template <typename T>
    PreorderIterator<T> beginPreorder(){
        return PreorderIterator<T>(this->root);
    }

    template <typename T>
    PreorderIterator<T> endPreorder(){
        return PreorderIterator<T>::end();
    }

    template <typename T>
    InorderIterator<T> beginInorder(){
        return InorderIterator<T>(this->root);
    }

    template <typename T>
    InorderIterator<T> endInorder(){
        return InorderIterator<T>::end();
    }

    template <typename T>
    PostorderIterator<T> beginPostorder(){
        return PostorderIterator<T>(this->root);
    }

    template <typename T>
    PostorderIterator<T> endPostorder(){
        return PostorderIterator<T>::end();
    }

    template <typename T>
    BFSIterator<T> beginBFS() {
        return BFSIterator<T>(root);
    }

    template <typename T>
    BFSIterator<T> endBFS() {
        return BFSIterator<T>::end();
    }

    template <typename T>
    DFSIterator<T> beginDFS() {
        return DFSIterator<T>(root);
    }

    template <typename T>
    DFSIterator<T> endDFS() {
        return DFSIterator<T>::end();
    }

} // namespace myTree
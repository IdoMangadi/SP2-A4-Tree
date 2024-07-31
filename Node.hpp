// ID: 315310250
// EMAIL: IDOIZHAR.Mangadi@msmail.ariel.ac.il
// GMAIL: idomangadi@gmail.com

// #pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

namespace myTree{

    // forward declaration of the node:
    template <typename T>
    class Node;
    
    template <typename T>
    ostream& operator<<(ostream& os, Node<T> node){  // overloading iostram operator for the node.
        os << node.value;
        return os;
    }

    /**
     * class representing a node of the tree.
     * the node contaion value (can be primitive or object) and a vector of children.
     */
    template <typename T>
    class Node{
        private:
            T value;  // value of the node.
            vector<shared_ptr<Node<T>>> children;  // children of the node.

        public:
            Node(T value) : value(value){}  // constructor.

            bool addChild(T value){  // add a child to the node.
                shared_ptr<Node<T>> child = make_shared<Node<T>>(value);
                this->children.push_back(child);
                return true;
            }

            bool addChild(shared_ptr<Node<T>> node){  // add a child to the node.
                if(node == nullptr) return false;
                this->children.push_back(node);
                return true;
            }

            const vector<shared_ptr<Node<T>>>& getChildren(){  // return the children of the node.
                return this->children;
            }

            T& getValue(){  // return the value of the node.
                return this->value;
            }

            bool removeChildren(){  // remove all the children of the node.
                this->children.clear();
                return true;
            }

            string to_string(){  // return the value of the node as string.
                return this->value;
            } 

            friend ostream& operator<< <T>(ostream& os, Node<T> node);  // declare the function as friend.
    };

} // namespace myTree
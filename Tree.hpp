// ID: 315310250
// EMAIL: IDOIZHAR.Mangadi@msmail.ariel.ac.il
// GMAIL: idomangadi@gmail.com

#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <queue>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "TreeIterators.hpp"

using namespace std;

namespace myTree{

    /**
     * An abstract class that represent a tree.
     * will be extended to binary tree and K-ary tree.
     * in this class we implemented a drawing function using the SFML library, usage in main(): tree.render(window, 0, 0, 100, 100);
     */
    template <typename T, size_t K>
    class BaseTree{
        protected:
            shared_ptr<Node<T>> root;

            /** 
             * drawing the tree using the SFML library:
             * @param window - the window to draw the tree on.
             * @param node - the current node to draw.
             * @param x - the x position of the node.
             * @param y - the y position of the node.
             * @param x_offset - the x offset between the nodes.
             * @param y_offset - the y offset between the nodes.
             * @param font - the font to use for the text.
             * @param depth - the depth of the node in the tree.
             */
            void drawTree(sf::RenderWindow &window, shared_ptr<Node<T>> node, float x, float y, float x_offset, float y_offset, sf::Font &font, size_t depth = 0) {
                if (node == nullptr)
                    return;

                float new_x_offset = x_offset / std::pow(K, depth);
                float min_x_offset = 60.0f;
                new_x_offset = std::max(new_x_offset, min_x_offset);

                y_offset += depth * 2; // Increment y_offset slightly with depth to avoid overlap

                // Scaling factor for ellipse and text size, decreases with depth
                float scale_factor = std::max(0.5f, 1 - depth * 0.1f); // Ensure scale factor does not go below 0.5

                for (auto i = 0u; i < node->getChildren().size(); ++i) {
                    float new_x = x + (i - node->getChildren().size() / 2.0) * new_x_offset;
                    float new_y = y + y_offset;

                    sf::Vertex line[] = {
                        sf::Vertex(sf::Vector2f(x + 25, y + 25)),
                        sf::Vertex(sf::Vector2f(new_x + 25, new_y + 25), sf::Color(255, 140, 0))
                    };
                    window.draw(line, 2, sf::Lines);

                    // Recursive call with incremented depth
                    drawTree(window, node->getChildren()[i], new_x, new_y, x_offset, y_offset, font, depth + 1);
                }

                // Apply scaling factor to ellipse size
                sf::CircleShape ellipse(30 * scale_factor); // Adjust ellipse size based on depth
                ellipse.setScale(1, 0.6);
                ellipse.setFillColor(sf::Color(50, 50, 50));
                ellipse.setOutlineColor(sf::Color(173, 216, 230));
                ellipse.setOutlineThickness(2);
                ellipse.setPosition(x, y);
                window.draw(ellipse);

                // Adjust text size based on depth
                sf::Text text;
                text.setFont(font);
                std::ostringstream oss;
                oss << node->getValue();
                text.setString(oss.str());
                text.setCharacterSize(14 * scale_factor); // Adjust text size based on depth
                text.setFillColor(sf::Color::Yellow);
                sf::FloatRect textRect = text.getLocalBounds();
                text.setOrigin(textRect.width / 2, textRect.height / 2);
                text.setPosition(x + 30 * scale_factor, y + 18 * scale_factor); // Adjust text position based on ellipse size
                window.draw(text);
            }
        
        public:
            BaseTree() : root(nullptr){}  // constructor.
            BaseTree(shared_ptr<Node<T>> root) : root(root){}  // constructor.

            virtual void pureVirtual() = 0;  // pure virtual function.

            ~BaseTree(){}  // destructor.

            /**
             * adding a root to the tree.
             * param root - the root to add as a shared pointer.
             */
            bool addRoot(shared_ptr<Node<T>> root, bool override = false){
                if(this->root != nullptr && !override){  // if the root already exists and we don't want to override it.
                    return false;
                }
                this->root = root;
                return true;
            }
            
            shared_ptr<Node<T>> getRoot(){  // return the root of the tree.
                return this->root;
            }

            /**
             * adding a child to a parent node.
             * param parent - the parent node to add the child to as a shared pointer.
             * param child - the child node to add as a shared pointer.
             */
            bool addSubNode(shared_ptr<Node<T>> parent, shared_ptr<Node<T>> child){

                if(parent == nullptr || child == nullptr || parent == child || parent->getChildren().size() >= K) return false;

                // make sure the parent is in the tree using the DFS iterator:
                for(auto it = beginDFS(); it != endDFS(); ++it){
                    if(it.operator->() == parent.get()) return parent->addChild(child);
                }
                return false;
            }

            // iterators (for the pre/in/post order we will travers the tree using the DFS iterator).
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

            // function to render the tree
            void renderTree() {
                sf::RenderWindow window(sf::VideoMode(1200, 700), "Tree Visualization");

                sf::Font font;
                if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
                    std::cerr << "Error loading font\n";
                    return;
                }

                while (window.isOpen()) {
                    sf::Event event;
                    while (window.pollEvent(event)) {
                        if (event.type == sf::Event::Closed)
                            window.close();
                    }

                    window.clear(sf::Color(50, 50, 50));
                    drawTree(window, root, 800, 10, 200, 100, font);
                    window.display();
                }
            }
    };

    /**
     * this class represent a K-ary tree.
     */
    template <typename T, size_t K = 2>
    class Tree : public BaseTree<T, K>{
        public:
            Tree() : BaseTree<T, K>(){}  // constructor.
            Tree(shared_ptr<Node<T>> root) : BaseTree<T, K>(root){}  // constructor.

            void pureVirtual() override{}  // pure virtual function.

            // iterators (cant use the pre/in/post order iterators).
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
    };

    /**
     * this class represent a binary tree.
     */
    template <typename T>
    class Tree<T, 2> : public BaseTree<T, 2>{
        public:
            Tree() : BaseTree<T, 2>(){}  // constructor.
            Tree(shared_ptr<Node<T>> root) : BaseTree<T, 2>(root){}  // constructor with shared pointer.

            void pureVirtual() override{}  // pure virtual function.

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

            HeapIterator<T> beginHeap(){
                return HeapIterator<T>(this->root);
            }
            HeapIterator<T> endHeap(){
                HeapIterator<T> it;
                // it.setToEnd();
                return it;
            }
    };

} // namespace myTree

#endif // TREE_HPP
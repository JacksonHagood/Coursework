# include <iostream>

// templated implementation of the binary tree data type using a templated node data type
// tree of data starting from a singular root where left values are less less than the current node and right values are greater

template<typename type>
class BinaryTree;

template<typename type>
class TreeNode {
    public:
        type nodeValue; // templated value
    private:
        TreeNode* leftNode; // pointer to the left node
        TreeNode* rightNode; // pointer to the right node

        friend class BinaryTree <type>; // make private elements available to the binary tree class
    public:
        // parameterized constructor
        TreeNode(type value, TreeNode* l = nullptr, TreeNode* r = nullptr) : 
            nodeValue(value),
            leftNode(l),
            rightNode(r)
        {}

        // returns the node value
        type getValue() const {
            return nodeValue;
        }

        // returns the left pointer
        TreeNode* getLeft() const {
            return leftNode;
        }

        // returns the right pointer
        TreeNode* getRight() const {
            return rightNode;
        }
};

template<typename type>
class BinaryTree {
    using NodeType = TreeNode <type>; // generic node type
    using BinaryType = BinaryTree <type>; // generic binary tree type

    private:
        NodeType* root; // templated root pointer node
        int size; // size variable
    public:
        // default constructor (O(1))
        BinaryTree() :
            root(nullptr),
            size(0)
        {}

        // copy constructor (O(n))
        BinaryTree(const BinaryType& t) :
            root(nullptr),
            size(0)
        {
            // copy over the tree starting at the root
            copy(root, t.root);

            // update the tree size
            size = t.size;
        }

        // copy assignment operator (O(n))
        BinaryTree& operator=(const BinaryType& t) {
            // clear the old binary tree
            clear(root);

            // copy over the tree starting at the root
            copy(root, t.root);

            // update the tree size
            size = t.size;

            return *this;
        }

        // destructor (O(n))
        ~BinaryTree() {
            // clear the binary tree
            clear(root);

            // reset the root
            root = nullptr;
        }

        // insertion operation (O(log2(n)))
        void insert(type value) {
            if (size == 0) {
                // if the tree is empty create a new root
                root = new NodeType(value);
            } else {
                // if the tree is not empty, create iterators for the current and previous nodes
                NodeType* current = root;
                NodeType* previous = nullptr;

                // iterate until the current node is a nullptr (leaf)
                while (current != nullptr) {
                    // reassign previous
                    previous = current;

                    if (value < current->nodeValue) {
                        // if the value is less than the current value, iterate left
                        current = current->leftNode;
                    } else if (value > current->nodeValue) {
                        // if the value is less than the current value, iterate right
                        current = current->rightNode;
                    } else {
                        // if the value is the same as the current value, terminate
                        return;
                    }
                }

                // create a new node
                NodeType* newNode = new NodeType(value);

                if (value < previous->nodeValue) {
                    // if the value is less than the previous node, add to the left
                    previous->leftNode = newNode;
                } else {
                    // if the value is greater than the previous node, add to the left
                    previous->rightNode = newNode;
                }
            }

            // increment size
            size++;
        }

        // remove node/subtree operation (O(n))
        void remove(type value) {
            if (size == 0) {
                 // if the tree is empty, terminate
                return;
            }

            // create iterators for the current and previous nodes
            NodeType* current = root;
            NodeType* previous = nullptr;

            // iterate until the current node is a nullptr (leaf)
            while (current != nullptr) {
                if (value < current->nodeValue) {
                    // reassign previous
                    previous = current;

                    // if the value is less than the current value, iterate left
                    current = current->leftNode;
                } else if (value > current->nodeValue) {
                    // reassign previous
                    previous = current;

                    // if the value is less than the current value, iterate right
                    current = current->rightNode;
                } else {
                    // if the value is found, break
                    break;
                }
            }

            if (current == nullptr) {
                // if the node is not found, terminate
                return;
            }

            if (current == root) {
                // if the ndoe is the root, reset the tree and terminate
                clear(current);
                root = nullptr;
                return;
            }

            if (value < previous->nodeValue) {
                // if the node is to the left of the previous one, reset the left pointer
                previous->leftNode = nullptr;
            } else {
                // if the node is to the right of the previous one, reset the right pointer
                previous->rightNode = nullptr;
            }            

            clear(current);
        }

        // search operation (O(log2(n)))
        NodeType* search(type value) {
            return find(root, value);
        }

        // contains operation (O(log2(n)))
        bool contains(type value) {
            if (find(root, value) != nullptr) {
                return true;
            }

            return false;
        }

        // inorder output operation (O(n))
        void outputInorder(std::ostream& os = std::cout) {
            os << "[ ";

            inorder(os, root);

            os << "]\n";
        }
        
        // preorder output operation (O(n))
        void outputPreorder(std::ostream& os = std::cout) {
            os << "[ ";

            preorder(os, root);

            os << "]\n";
        }

        // postorder output operation (O(n))
        void outputPostorder(std::ostream& os = std::cout) {
            os << "[ ";

            postorder(os, root);

            os << "]\n";
        }

        // recursive copy operation (O(n))
        void copy(NodeType* &nodeA, const NodeType* nodeB) {
            // copies over the subtree starting with root nodeB to root nodeA
            if (nodeB != nullptr) {
                // if nodeB is not a nullptr copy over nodeB's value into nodeA
                nodeA = new NodeType(nodeB->nodeValue);

                // recursively call the copy operation for the left and right nodes
                copy(nodeA->leftNode, nodeB->leftNode);
                copy(nodeA->rightNode, nodeB->rightNode);
            }

            // stops recursion if nodeB is a nullptr (base case)
        }

        // recursive clear operation (O(n))
        void clear(NodeType* node) {
            // clears the entire subtree starting from the root node
            if (node != nullptr) {
                // if node is not a nullptr clear the left and right nodes as well
                clear(node->leftNode);
                clear(node->rightNode);

                // decrement size
                size--;
            }

            // stops recursion if node is a nullptr (base case), delete node
            delete node;
        }

        // recursive find operation (O(log2(n)))
        NodeType* find(NodeType* node, type value) {
            if (node == nullptr) {
                // if the current node is a nullptr, the value can't be found
                return nullptr;
            }

            if (value == node->nodeValue) {
                // return the node when found
                return node;
            } else if (value > node->nodeValue) {
                // if the value is greater than the current node, move right
                return find(node->rightNode, value);
            } else {
                // if the value is less than the current node, move left
                return find(node->leftNode, value);
            }
        }

        // recursive inorder operation (O(n))
        void inorder(std::ostream& os, NodeType* node) {
            if (node != nullptr) {
                // left, root, then right
                inorder(os, node->leftNode);
                os << node->nodeValue << " ";
                inorder(os, node->rightNode);
            }
        }

        // recursive preorder operation (O(n))
        void preorder(std::ostream& os, NodeType* node) {
            if (node != nullptr) {
                // root, left, then right
                os << node->nodeValue << " ";
                preorder(os, node->leftNode);
                preorder(os, node->rightNode);
            }
        }

        // recursive postorder operation (O(n))
        void postorder(std::ostream& os, NodeType* node) {
            if (node != nullptr) {
                // left, right, then root
                postorder(os, node->leftNode);
                postorder(os, node->rightNode);
                os << node->nodeValue << " ";
            }
        }

        // returns the root node pointer O(1)
        NodeType* getRoot() const {
            return root;
        }

        // returns the size of the binary tree O((1))
        int getSize() const {
            return size;
        }

        // returns whether the binary tree is empty O((1))
        bool isEmpty() const {
            return size == 0;
        }

        // output operator for the linked list (O(n))
        friend std::ostream& operator<<(std::ostream& os, BinaryType t) {
            os << "[ ";

            t.inorder(os, t.root);

            os << "]\n";

            return os;
        }
};

# include <iostream>

// templated implementation of the linked list data type using a templated node data type
// dynamic list where memory is conserved at the expense of item access time and item removal time

template<typename type>
class LinkedList;

template<typename type>
class ListNode {
    private:
        type nodeValue; // templated value
        ListNode* nextNode; // pointer to the next node

        friend class LinkedList <type>; // make private elements available to the linked list class
    public:
        // parameterized constructor
        ListNode(type value, ListNode* n = nullptr) : 
            nodeValue(value),
            nextNode(n)
        {}

        // returns the node value
        type getValue() const {
            return nodeValue;
        }

        // returns the next pointer
        ListNode* getNext() const {
            return nextNode;
        }
};

template<typename type>
class LinkedList {
    using NodeType = ListNode <type>; // generic node type
    using ListType = LinkedList <type>; // generic list type

    private:
        NodeType* head; // templated head pointer node
        NodeType* tail; // templated tail pointer node
        int size; // size variable
    public:
        // default constructor (O(1))
        LinkedList() :
            head(nullptr),
            tail(nullptr),
            size(0)
        {}

        // copy constructor (O(n))
        LinkedList(const ListType& l) :
            head(),
            tail(),
            size()
        {
            // clear the old linked list
            clear();

            // copy over each node from the new linked list
            NodeType* currentNode = l.head;

            for (int i = 0; i < l.size; i++) {
                pushBack(currentNode->nodeValue);
                currentNode = currentNode->nextNode;
            }
        }

        // copy assignment operator (O(n))
        LinkedList& operator=(const ListType& l) {
            // clear the old linked list
            clear();

            // copy over each node from the new linked list
            NodeType* currentNode = l.head;

            for (int i = 0; i < l.size; i++) {
                pushBack(currentNode->nodeValue);
                currentNode = currentNode->nextNode;
            }

            return *this;
        }

        // destructor (O(n))
        ~LinkedList() {
            // clear the linked list
            clear();
        }

        // pushes a node with value to the front of the linked list (O(1))
        void pushFront(type value) {
            NodeType* newNode = new ListNode(value);

            // account for an empty linked list
            if (size == 0) {
                head = newNode;
                tail = newNode;
            } else {
                // add the new node
                newNode->nextNode = head;
                head = newNode;
            }

            size++;
        }

        // pushes a node with value to the back of the linked list (O(1))
        void pushBack(type value) {
            NodeType* newNode = new ListNode(value);

            // account for an empty linked list
            if (size == 0) {
                head = newNode;
                tail = newNode;
            } else {
                // add the new node
                tail->nextNode = newNode;
                tail = newNode;
            }

            size++;
        }

        // inserts a node with value at an index in the linked list (O(n))
        void insert(type value, int index) {
            if (index > size) {
                throw std::invalid_argument("Out of range");
            }

            if (index == 0) {
                // case 1, adding the node at the beginning
                this->pushFront(value);
            } else if (index == size) {
                // case 2, adding the node to the end
                this->pushBack(value);
            } else {
                // case 3, adding the node somewhere in the middle of the list
                NodeType* newNode = new ListNode(value);
                NodeType* currentNode = head;
                NodeType* previousNode = head;
                int i = 0;

                // locate the index to add the node at
                while (i < index) {
                    previousNode = currentNode;
                    currentNode = currentNode->nextNode;
                    i++;
                }

                // add the node
                previousNode->nextNode = newNode;
                newNode->nextNode = currentNode;

                size++;
            }
        }

        // removes the last node of the linked list (O(n))
        void pop() {
            // check for an empty linked list
            if (size == 0) {
                throw std::invalid_argument("Empty Linked List");
            }

            remove(size - 1);
        }

        // removes an element from the linked list (O(n))
        void remove(int index) {
            // check the index
            if (index >= size) {
                throw std::invalid_argument("Out of range");
            }

            NodeType* currentNode = head;
            NodeType* previousNode = head;
            int i = 0;

            // locate the node to remove
            while (i != index) {
                previousNode = currentNode;
                currentNode = currentNode->nextNode;
                i++;
            }

            if (i == 0) {
                // case 1, remove the first node
                head = currentNode->nextNode;
            }

            if (i == size - 1) {
                // case 2, remove the last node
                tail = previousNode;
                previousNode->nextNode = nullptr;
            } else {
                // case 3, remove a node somewhere in the middle of the list
                previousNode->nextNode = currentNode->nextNode;
            }

            // remove the node
            delete currentNode;
            size--;
        }

        // clears the linked list (O(n))
        void clear() {
            while (head != nullptr) {
                pop();
            }
        }

        // returns the first element of the linked list (O(1))
        type getFirst() const {
            // check for an empty linked list 
            if (head == nullptr) {
                throw std::invalid_argument("Empty Linked List");
            }

            return head->nodeValue;
        }

        // returns the last element of the linked list (O(1))
        type getLast() const {
            // check for an empty linked list
            if (tail == nullptr) {
                throw std::invalid_argument("Empty Linked List");
            }

            return tail->nodeValue;
        }

        // returns the element at a given index (O(n))
        type operator[](int index) const {
            // check the index
            if (index >= size) {
                throw std::invalid_argument("Out of range");
            }

            // locate the node and return its value
            NodeType* currentNode = head;

            for (int i = 0; i < index; i++) {
                currentNode = currentNode->nextNode;
            }

            return currentNode->nodeValue;
        }

        // returns the size of the linked list O((1))
        int getSize() const {
            return size;
        }

        // returns whether the linked list is empty O((1))
        bool isEmpty() const {
            return size == 0;
        }

        // output operator for the linked list (O(n))
        friend std::ostream& operator<<(std::ostream& os, const ListType& l) {
            os << "[";

            // output each element in the linked list, starting from the head

            NodeType* currentNode = l.head;

            for (int i = 0; i < l.size; i++) {
                os << currentNode->getValue();
                currentNode = currentNode->getNext();

                if (i < l.size - 1) {
                    os << ", ";
                }
            }

            os << "]";

            return os;
        }
};
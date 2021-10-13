# include <iostream>

// templated implementation of the priority queue data type using a templated node data type
// a priority queue is a sequence of data arranged according to its priority, constructed using a binary heap

template<typename type>
class PriorityQueue;

template<typename type>
class PriorityNode {
    private:
        type nodeValue; // templated value
        int nodePriority; // priority of the node

        friend class PriorityQueue <type>; // make private elements available to the priority queue class
    public:
        // default constructor
        PriorityNode() : 
            nodeValue(),
            nodePriority()
        {}

        // parameterized constructor
        PriorityNode(type value, int nodePriority = 0) : 
            nodeValue(value),
            nodePriority(nodePriority)
        {}

        // returns the node value
        type getValue() const {
            return nodeValue;
        }

        // returns the priority of the node
        int getPriority() const {
            return nodePriority;
        }
};

template<typename type>
class PriorityQueue {
    using NodeType = PriorityNode <type>; // generic node type
    using PriorityType = PriorityQueue <type>; // generic priority queue type

    private:
        NodeType* heap; // dynamic array to represent the heap
        int capacity; // capacity variable
        int size; // size variable

        // function to double the capacity (O(n))
        void resize() {
            // assign a new capacity
            if (capacity == 0) {
                capacity = 1;
            } else {
                capacity *= 2;
            }

            // allocate a new heap and copy over elements
            NodeType* temp = new NodeType[capacity];

            for (int i = 0; i < size; i++) {
                temp[i] = heap[i];
            }
            
            // resize the heap
            delete[] heap;
            heap = temp;
        }

        // recursive up-heap operation (arbitrary)
        void upHeap(int index) {
            // locate the index of the parent
            int parentIndex = (index - 1) / 2;

            // check if the current node has a lower priority than its parent
            if (heap[index].getPriority() < heap[parentIndex].getPriority()) {
                // swap the nodes
                NodeType temp = heap[index];
                heap[index] = heap[parentIndex];
                heap[parentIndex] = temp;

                // check if the index of the parent is the root
                if (parentIndex != 0) {
                    // repeat up-heap operation
                    upHeap(parentIndex);
                }
            }
        }

        // down-heap operation (arbitrary)
        void downHeap(int index) {
            int rightChild = 2 * index + 2;
            int leftChild = 2 * index + 1;

            if (rightChild >= size && leftChild >= size) {
                return;
            } else if (rightChild >= size) {
                if (heap[leftChild].nodePriority < heap[index].nodePriority) {
                    // swap the nodes
                    NodeType temp = heap[index];
                    heap[index] = heap[leftChild];
                    heap[leftChild] = temp;

                    return;
                }
            } else if (heap[leftChild].nodePriority < heap[index].nodePriority || heap[rightChild].nodePriority < heap[index].nodePriority) {
                int switchIndex;

                // find the minimum of the children, the element that will be swapped
                if (heap[leftChild].nodePriority < heap[rightChild].nodePriority) {
                    switchIndex = leftChild;
                } else {
                    switchIndex = rightChild;
                }

                // swap the element with its smallest child
                NodeType temp = heap[index];
                heap[index] = heap[switchIndex];
                heap[switchIndex] = temp;

                // downheap
                downHeap(switchIndex);
            }
        }
    public:
        // default constructor (O(1))
        PriorityQueue() :
            heap(nullptr),
            capacity(0),
            size(0)
        {}

        // copy constructor (O(n))
        PriorityQueue(const PriorityType& p) :
            heap(),
            capacity(p.capacity),
            size(p.size)
        {
            // correctly allocate new heap
            delete[] heap;
            heap = new NodeType[capacity];

            // copy over elements
            for (int i = 0; i < p.size; i++) {
                heap[i] = p.heap[i];
            }
        }

        // copy assignment operator (O(n))
        PriorityQueue& operator=(const PriorityType& p) {
            capacity = p.capacity;
            size = p.size;

            // correctly allocate new heap
            delete[] heap;
            heap = new NodeType[capacity];

            // copy over elements
            for (int i = 0; i < p.size; i++) {
                heap[i] = p.heap[i];
            }

            return *this;
        }

        // destructor (O(1))
        ~PriorityQueue() {
            delete[] heap;
        }

        // insertion operation (O(log2(n)))
        void insert(type value, int priority) {
            NodeType newNode(value, priority);

            // resize the heap when the capacity is reached
            if (size == capacity) {
                resize();
            }

            // push the new node
            heap[size] = newNode;
            size++;

            // call upheap to verify order
            upHeap(size - 1);
        }
        
        // removal operation (O(log2(n)))
        type pop() {
            if (size == 0) {
                // if empty heap, terminate
                throw std::invalid_argument("Out of range");
            } else {
                // remove the root and decrement size
                type temp = heap[0].nodeValue;
                heap[0] = heap[size - 1];
                size--;

                // down heap
                downHeap(0);

                // return the min
                return temp;
            }
        }

        // minimum item access (O(1))
        type getNext() {
            if (size == 0) {
                // if empty heap, terminate
                throw std::invalid_argument("Out of range");
            } else {
                return heap[0].nodeValue;
            }
        }

        // returns the size of the priority queue (O(1))
        int getSize() {
            return size;
        }

        // returns whether the priority queue is empty (O(1))
        bool isEmpty() const {
            return size == 0;
        }
};
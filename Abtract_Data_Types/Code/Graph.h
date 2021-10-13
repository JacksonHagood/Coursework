# include <iostream>

// templated implementation of the graph data type using a templated node data type
// directed graph constructed using adjacency lists contained within the node class

template<typename type>
class Graph;

template<typename type>
class GraphNode {
    using NodeType = GraphNode <type>; // generic node type

    private:
        type nodeValue; // templated value
        type* adjacencyList; // dynamic array for the adjacency list (by labels)
        int capacity; // capacity variable (for adjacency list)
        int size; // size variable (for adjacency list)

        // function to double the capacity of the adjacency list (O(n))
        void resize() {
            // assign a new capacity
            if (capacity == 0) {
                capacity = 1;
            } else {
                capacity *= 2;
            }

            // allocate an adjacency list and copy over elements
            type* temp = new type[capacity];

            for (int i = 0; i < size; i++) {
                temp[i] = adjacencyList[i];
            }
            
            // resize the adjacency list
            delete[] adjacencyList;
            adjacencyList = temp;
        }

        friend class Graph <type>; // make private elements available to the graph class
    public:
        // default constructor (O(1))
        GraphNode() : 
            nodeValue(),
            adjacencyList(nullptr),
            capacity(0),
            size(0)
        {}

        // parameterized constructor (O(1))
        GraphNode(type value) : 
            nodeValue(value),
            adjacencyList(nullptr),
            capacity(0),
            size(0)
        {}

        // copy constructor (O(n))
        GraphNode(const NodeType& n) :
            nodeValue(n.nodeValue),
            adjacencyList(),
            capacity(n.capacity),
            size(n.size)
        {
            // correctly allocate new adjacency list
            delete[] adjacencyList;
            adjacencyList = new type[capacity];

            // copy over elements
            for (int i = 0; i < n.size; i++) {
                adjacencyList[i] = n.adjacencyList[i];
            }
        }

        // copy assignment operator (O(n))
        GraphNode& operator=(const NodeType& n) {
            nodeValue = n.nodeValue;
            capacity = n.capacity;
            size = n.size;

            // correctly allocate new adjacency list
            delete[] adjacencyList;
            adjacencyList = new type[capacity];

            // copy over elements
            for (int i = 0; i < n.size; i++) {
                adjacencyList[i] = n.adjacencyList[i];
            }

            return *this;
        }
        
        // destructor
        ~GraphNode() {
            delete[] adjacencyList;
        }

        // adds a node to the adjacency list (O(1))
        void addAdjacent(type value) {
            // verify the value is not already contained in the adjacency list
            if (!adjacent(value)) {
                // resize the adjacency list when the capacity is reached
                if (capacity == size) {
                    resize();
                }

                // push the label
                adjacencyList[size] = value;
                size++;
            }
        }

        // returns whether a node is adjacent (O(n))
        bool adjacent(type value) {
            // iterate through the entire list
            for (int i = 0; i < size; i++) {
                if (adjacencyList[i] == value) {
                    // if the value is found, return true
                    return true;
                }
            }

            // if the value is not found, return false
            return false;
        }

        // output operator for the node (O(n))
        friend std::ostream& operator<<(std::ostream& os, const NodeType& n) {
            // output the label
            os << n.nodeValue << " : ";

            // output each adjacent node
            for (int i = 0; i < n.size; i++) {
                os << n.adjacencyList[i] << " ";            
            }

            return os;
        }
};

template<typename type>
class Graph {
    using NodeType = GraphNode <type>; // generic node type
    using GraphType = Graph <type>; // generic graph type

    private:
        NodeType* nodeList; // dynamic array for the list of nodes
        int capacity; // capacity variable
        int size; // size variable

        // function to double the capacity of the node list (O(n))
        void resize() {
            // assign a new capacity
            if (capacity == 0) {
                capacity = 1;
            } else {
                capacity *= 2;
            }

            // allocate a node list and copy over elements
            NodeType* temp = new NodeType[capacity];

            for (int i = 0; i < size; i++) {
                temp[i] = nodeList[i];
            }
            
            // resize the node list
            delete[] nodeList;
            nodeList = temp;
        }
    public:
        // default constructor
        Graph() :
            nodeList(),
            capacity(0),
            size(0)
        {}

        // copy constructor (O(n))
        Graph(const GraphType& g) :
            nodeList(),
            capacity(g.capacity),
            size(g.size)
        {
            // correctly allocate new node list
            delete[] nodeList;
            nodeList = new NodeType[capacity];

            // copy over elements
            for (int i = 0; i < g.size; i++) {
                nodeList[i] = g.nodeList[i];
            }
        }

        // copy assignment operator (O(n))
        Graph& operator=(const GraphType& g) {
            capacity = g.capacity;
            size = g.size;

            // correctly allocate new heap
            delete[] nodeList;
            nodeList = new NodeType[capacity];

            // copy over elements
            for (int i = 0; i < g.size; i++) {
                nodeList[i] = g.nodeList[i];
            }

            return *this;
        }

        // destructor (O(1))
        ~Graph() {
            delete[] nodeList;
        }

        // adds a node to the graph
        void addNode(type value) {
            // verify the value is not already contained in the graph
            if (!contains(value)) {
                // create a new node
                NodeType newNode(value);

                // resize the node list when the capacity is reached
                if (capacity == size) {
                    resize();
                }

                // push the new node
                nodeList[size] = newNode;
                size++;
            }
        }
        
        // adds an edge to the graph
        void addEdge(type a, type b) {
            // if the graph does not contain a, add it
            if (!contains(a)) {
                addNode(a);
            }

            // if the graph does not contain b, add it
            if (!contains(b)) {
                addNode(b);
            }

            // iterate through the entire list
            for (int i = 0; i < size; i++) {
                if (nodeList[i].nodeValue == a) {
                    // when the value is found, add adjacent
                    nodeList[i].addAdjacent(b);

                    return;
                }
            }
        }

        // returns whether a node is in the graph (O(n))
        bool contains(type value) {
            // iterate through the entire list
            for (int i = 0; i < size; i++) {
                if (nodeList[i].nodeValue == value) {
                    // if the value is found, return true
                    return true;
                }
            }

            // if the value is not found, return false
            return false;
        }

        // returns the size of the graph (O(1))
        int getSize() {
            return size;
        }

        // returns whether the graph is empty (O(1))
        bool isEmpty() const {
            return size == 0;
        }

        // output operator for the graph (O(n))
        friend std::ostream& operator<<(std::ostream& os, const GraphType& g) {
            // output each node
            os << '(';
            for (int i = 0; i < g.size; i++) {
                os << g.nodeList[i] <<')';     
                if (i < g.size - 1) {
                    os << " (";
                }           
            }

            return os;
        }
};
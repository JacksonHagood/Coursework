# include <iostream>

// templated implementation of the stack data type
// linear list where all operations are restricted to the top using a last-in, first-out convention

template<typename type>
class Stack {
    private:
        type* array; // templated dynamic array (space O(n))
        int capacity; // capacity variable
        int topIndex; // index of the top
        
        // function to double the capacity (O(n))
        void resize() {
            // assign a new capacity
            if (capacity == 0) {
                capacity = 1;
            } else {
                capacity *= 2;
            }

            // allocate a new array and copy over elements
            type* temp = new type[capacity];

            for (int i = 0; i <= topIndex; i++) {
                temp[i] = array[i];
            }
            
            // resize the array
            delete[] array;
            array = temp;
        }
    public:
        // default constructor (O(1))
        Stack() :
            array(nullptr),
            capacity(0),
            topIndex(-1)
        {}

        // copy constructor (O(n))
        Stack(const Stack& s) :
            array(),
            capacity(s.capacity),
            topIndex(s.topIndex)
        {
            // correctly allocate new array
            delete[] array;
            array = new type[capacity];

            // copy over elements
            for (int i = 0; i <= s.topIndex; i++) {
                array[i] = s.array[i];
            }
        }

        // copy assignment operator (O(n))
        Stack& operator=(const Stack& s) {
            capacity = s.capacity;
            topIndex = s.topIndex;

            // correctly allocate new array
            delete[] array;
            array = new type[capacity];

            // copy over elements
            for (int i = 0; i <= s.topIndex; i++) {
                array[i] = s.array[i];
            }

            return *this;
        }

        // destructor (O(1))
        ~Stack() {
            delete[] array;
        }

        // push operation (O(1) using armortized analysis)
        void push(const type element) {
            // resize array when the capacity is reached
            if (topIndex + 1 == capacity) {
                resize();
            }

            // push the element
            topIndex++;
            array[topIndex] = element;
        }

        // pop operation, returns and removes the top element (O(1))
        type pop() {
            // check for an empty stack
            if (topIndex == -1) {
                throw std::invalid_argument("Empty Stack");
            }

            // pop the element
            topIndex--;
            return array[topIndex + 1];
        }

        // returns element at the top (O(1))
        type getTop() {
            // check for an empty stack
            if (topIndex == -1) {
                throw std::invalid_argument("Empty Stack");
            }

            return array[topIndex];
        }

        // returns the size of the stack (O(1))
        int getSize() const {
            return topIndex + 1;
        }

        // returns whether the stack is empty (O(1))
        bool isEmpty() const {
            return topIndex == -1;
        }

        // output operator for the stack (O(n))
        friend std::ostream& operator<<(std::ostream& os, const Stack<type>& s) {
            os << "[";

            // output each element in the stack, starting from the top
            for (int i = s.topIndex; i >= 0; i--) {
                os << s.array[i];
                if (i > 0) {
                    os << ", ";
                }
            }

            os << "]";

            return os;
        }
};
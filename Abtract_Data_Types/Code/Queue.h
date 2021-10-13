# include <iostream>

// templated implementation of the queue data type
// circular list where elements are added to the rear and removed from the front using a first-in, first-out convention

template<typename type>
class Queue {
    private:
        type* array; // templated dynamic array
        int capacity; // capacity variable
        int count; // count variable
        int front; // index of the front
        int rear; // index of the rear
    public:
        // default constructor (O(1))
        Queue(int size) :
            array(nullptr),
            capacity(size),
            count(0),
            front(0),
            rear(0)
        {
            delete array;
            array = new type[capacity];
        }

        // copy constructor (O(n))
        Queue(const Queue& q) :
            array(),
            capacity(q.capacity),
            count(q.count),
            front(q.front),
            rear(q.rear)
        {
            // correctly allocate new array
            delete[] array;
            array = new type[capacity];

            // copy over elements
            for (int i = 0; i < q.capacity; i++) {
                array[i] = q.array[i];
            }
        }

        // copy assignment operator (O(n))
        Queue& operator=(const Queue& q) {
            capacity = q.capacity;
            count = q.topIndex;
            front = q.front;
            rear = q.rear;

            // correctly allocate new array
            delete[] array;
            array = new type[capacity];

            // copy over elements
            for (int i = 0; i < q.capacity; i++) {
                array[i] = q.array[i];
            }

            return *this;
        }

        // destructor (O(1))
        ~Queue() {
            delete[] array;
        }

        // enqueue operation (O(1) using armortized analysis)
        void enQueue(const type element) {
            // check if the queue is full
            if (count == capacity) {
                throw std::invalid_argument("Queue Full");
            }

            // add the element to the rear using a circular array
            array[rear] = element;
            rear = (rear + 1) % capacity;
            count++;
        }

        // dequeue operation (O(1))
        type deQueue() {
            // check for an empty queue
            if (count == 0) {
                throw std::invalid_argument("Empty Queue");
            }

            // remove and return the front element using a circular array
            count--;
            type element = array[front];
            front = (front + 1) % capacity;
            return element;
        }

        // returns the next element (O(1))
        type getNext() {
            // check for an empty queue
            if (count == 0) {
                throw std::invalid_argument("Empty Queue");
            }

            return array[front];
        }

        // returns the size of the queue (O(1))
        int getSize() const {
            return count;
        }

        // returns whether the queue is empty (O(1))
        bool isEmpty() const {
            return count == 0;
        }

        // returns whether the queue is full (O(1))
        bool isFull() const {
            return count == capacity;
        }

        // output operator for the queue (O(n))
        friend std::ostream& operator<<(std::ostream& os, const Queue<type>& q) {
            os << "[";

            // output each element in the queue, starting from the rear
            int i = q.front;

            while (i != q.rear) {
                os << q.array[i];

                i = (i + 1) % q.capacity;

                if (i != q.rear) {
                    os << ", ";
                }
            }

            os << "]";

            return os;
        }
};
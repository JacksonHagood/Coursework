# include <iostream>
# include "Queue.h"
# include "Stack.h"
# include "LinkedList.h"
# include "PriorityQueue.h"
# include "BinaryTree.h"
# include "Graph.h"

using std::cout, std::cin;

template<typename type>
void queueTester() {
    int size;
    cout << "\tEnter the maximum size of the queue (unsigned int): \033[32m";
    cin >> size;
    cout << "\033[0m";

    Queue<type> queue(size);

    char input;
    type temp;

    while (input != 'q') {
        cout << "\n\t\033[33mQUEUE TESTER\033[0m\n";
        cout << "\tSupported Operations: \n";
        cout << "\t(\033[32me\033[0m) Enqueue\n";
        cout << "\t(\033[32md\033[0m) Dequeue\n";
        cout << "\t(\033[32mn\033[0m) Get Next\n";
        cout << "\t(\033[32ms\033[0m) Get Size\n";
        cout << "\t(\033[32mm\033[0m) Is Empty\n";
        cout << "\t(\033[32mf\033[0m) Is Full\n";
        cout << "\t(\033[32mo\033[0m) Output\n";
        cout << "\tEnter the operation (q to quit): \033[32m";

        cin >> input;
        cout << "\033[0m";

        if (input == 'e') {
            try {
                cout << "\n\t\tEnter the value to enqueue: \033[32m";
                cin >> temp;
                cout << "\033[0m";

                queue.enQueue(temp);
                cout << "\t\t\033[34m" << temp << "\033[0m enqueued\n";
            } catch(std::invalid_argument& d) {
                cout << "\t\tException: \033[31m" << d.what() << "\033[0m\n";
            }
        } else if (input == 'd') {
            try {
                temp = queue.deQueue();
                cout << "\n\t\tValue dequeued: \033[34m" << temp << "\033[0m\n";
            } catch(std::invalid_argument& d) {
                cout << "\n\t\tException: \033[31m" << d.what() << "\033[0m\n";
            }
        } else if (input == 'n') {
            try {
                temp = queue.getNext();
                cout << "\n\t\tValue next: \033[34m" << temp << "\033[0m\n";
            } catch(std::invalid_argument& d) {
                cout << "\n\t\tException: \033[31m" << d.what() << "\033[0m\n";
            }
        } else if (input == 's') {
            cout << "\n\t\tQueue size: \033[34m" << queue.getSize() << "\033[0m\n";
        } else if (input == 'm') {
            if (queue.isEmpty()) {
                cout << "\n\t\tThe queue is \033[34mempty\033[0m\n";
            } else {
                cout << "\n\t\tThe queue is \033[34mnot empty\033[0m\n";
            }
        } else if (input == 'f') {
            if (queue.isFull()) {
                cout << "\n\t\tThe queue is \033[34mfull\033[0m\n";
            } else {
                cout << "\n\t\tThe queue is \033[34mnot full\033[0m\n";
            }
        } else if (input == 'o') {
            cout << "\n\t\tQueue: \033[34m" << queue << "\033[0m\n";
        } else if (input != 'q') {
            cout << "\n\t\tUnsuported operation: \033[31m" << input << "\033[0m\n";
        }
    }

    cout << "\n\t\033[33mEXITING QUEUE TESTER\033[0m\n";
}

template<typename type>
void stackTester() {
    Stack<type> stack;

    char input;
    type temp;

    while (input != 'q') {
        cout << "\n\t\033[33mSTACK TESTER\033[0m\n";
        cout << "\tSupported Operations: \n";
        cout << "\t(\033[32mu\033[0m) Push\n";
        cout << "\t(\033[32mp\033[0m) Pop\n";
        cout << "\t(\033[32mt\033[0m) Get Top\n";
        cout << "\t(\033[32ms\033[0m) Get Size\n";
        cout << "\t(\033[32me\033[0m) Is Empty\n";
        cout << "\t(\033[32mo\033[0m) Output\n";
        cout << "\tEnter the operation (q to quit): \033[32m";

        cin >> input;
        cout << "\033[0m";

        if (input == 'u') {
            cout << "\n\t\tEnter the value to push: \033[32m";
            cin >> temp;
            cout << "\033[0m";

            stack.push(temp);
            cout << "\t\t\033[34m" << temp << "\033[0m pushed\n";
        } else if (input == 'p') {
            try {
                temp = stack.pop();
                cout << "\n\t\tValue popped: \033[34m" << temp << "\033[0m\n";
            } catch(std::invalid_argument& d) {
                cout << "\n\t\tException: \033[31m" << d.what() << "\033[0m\n";
            }
        } else if (input == 't') {
            try {
                temp = stack.getTop();
                cout << "\n\t\tTop value: \033[34m" << temp << "\033[0m\n";
            } catch(std::invalid_argument& d) {
                cout << "\n\t\tException: \033[31m" << d.what() << "\033[0m\n";
            }
        } else if (input == 's') {
            cout << "\n\t\tStack size: \033[34m" << stack.getSize() << "\033[0m\n";
        } else if (input == 'e') {
            if (stack.isEmpty()) {
                cout << "\n\t\tThe stack is \033[34mempty\033[0m\n";
            } else {
                cout << "\n\t\tThe stack is \033[34mnot empty\033[0m\n";
            }
        } else if (input == 'o') {
            cout << "\n\t\tStack: \033[34m" << stack << "\033[0m\n";
        } else if (input != 'q') {
            cout << "\n\t\tUnsuported operation: \033[31m" << input << "\033[0m\n";
        }
    }

    cout << "\n\t\033[33mEXITING STACK TESTER\033[0m\n";
}

template<typename type>
void listTester() {
    LinkedList<type> list;

    char input;
    type temp;
    int index;

    while (input != 'q') {
        cout << "\n\t\033[33mLINKED LIST TESTER\033[0m\n";
        cout << "\tSupported Operations: \n";
        cout << "\t(\033[32mf\033[0m) Push Front\n";
        cout << "\t(\033[32mb\033[0m) Push Back\n";
        cout << "\t(\033[32mi\033[0m) Insert\n";
        cout << "\t(\033[32mp\033[0m) Pop\n";
        cout << "\t(\033[32mr\033[0m) Remove\n";
        cout << "\t(\033[32mc\033[0m) Clear\n";
        cout << "\t(\033[32mg\033[0m) Get First\n";
        cout << "\t(\033[32ml\033[0m) Get Last\n";
        cout << "\t(\033[32ma\033[0m) At\n";
        cout << "\t(\033[32ms\033[0m) Get Size\n";
        cout << "\t(\033[32me\033[0m) Is Empty\n";
        cout << "\tEnter the operation (q to quit): \033[32m";

        cin >> input;
        cout << "\033[0m";

        if (input == 'f') {
            cout << "\n\t\tEnter the value to push: \033[32m";
            cin >> temp;
            cout << "\033[0m";

            list.pushFront(temp);
            cout << "\t\t\033[34m" << temp << "\033[0m pushed to the front\n";
        } else if (input == 'b') {
            cout << "\n\t\tEnter the value to push: \033[32m";
            cin >> temp;
            cout << "\033[0m";

            list.pushBack(temp);
            cout << "\t\t\033[34m" << temp << "\033[0m pushed to the back\n";
        } else if (input == 'i') {
            try {
                cout << "\n\t\tEnter the value to insert: \033[32m";
                cin >> temp;
                cout << "\033[0m\t\tEnter the index to insert at: \033[32m";
                cin >> index;
                cout << "\033[0m";

                list.insert(temp, index);
                cout << "\t\t\033[34m" << temp << "\033[0m inserted at index \033[34m" << index << "\033[0m\n";
            } catch(std::invalid_argument& d) {
                cout << "\n\t\tException: \033[31m" << d.what() << "\033[0m\n";
            }            
        } else if (input == 'p') {
            try {
                temp = list.getLast();
                list.pop();
                cout << "\n\t\tValue popped: \033[34m" << temp << "\033[0m\n";
            } catch(std::invalid_argument& d) {
                cout << "\n\t\tException: \033[31m" << d.what() << "\033[0m\n";
            }     
        } else if (input == 'r') {
            try {
                cout << "\n\t\tEnter the index to remove: \033[32m";
                cin >> index;
                cout << "\033[0m";
                temp = list[index];
                list.remove(index);
                cout << "\t\tValue removed: \033[34m" << temp << "\033[0m\n";
            } catch(std::invalid_argument& d) {
                cout << "\n\t\tException: \033[31m" << d.what() << "\033[0m\n";
            }
        } else if (input == 'c') {
            list.clear();
            cout << "\n\t\tList cleared\n";
        } else if (input == 'g') {
            try {
                temp = list.getFirst();
                cout << "\n\t\tFirst value: \033[34m" << temp << "\033[0m\n";
            } catch(std::invalid_argument& d) {
                cout << "\n\t\tException: \033[31m" << d.what() << "\033[0m\n";
            }
        } else if (input == 'l') {
            try {
                temp = list.getLast();
                cout << "\n\t\tLast value: \033[34m" << temp << "\033[0m\n";
            } catch(std::invalid_argument& d) {
                cout << "\n\t\tException: \033[31m" << d.what() << "\033[0m\n";
            }
        } else if (input == 'a') {
            try {
                cout << "\n\t\tEnter the index: \033[32m";
                cin >> index;
                cout << "\033[0m";
                temp = list[index];
                cout << "\t\tValue at \033[34m" << index << "\033[0m: \033[34m" << temp << "\033[0m\n";
            } catch(std::invalid_argument& d) {
                cout << "\n\t\tException: \033[31m" << d.what() << "\033[0m\n";
            }
        } else if (input == 's') {
            cout << "\n\t\tList size: \033[34m" << list.getSize() << "\033[0m\n";
        } else if (input == 'e') {
            if (list.isEmpty()) {
                cout << "\n\t\tThe list is \033[34mempty\033[0m\n";
            } else {
                cout << "\n\t\tThe list is \033[34mnot empty\033[0m\n";
            }
        } else if (input == 'o') {
            cout << "\n\t\tList: \033[34m" << list << "\033[0m\n";
        } else if (input != 'q') {
            cout << "\n\t\tUnsuported operation: \033[31m" << input << "\033[0m\n";
        }
    }

    cout << "\n\t\033[33mEXITING LINKED LIST TESTER\033[0m\n";
}

template<typename type>
void priorityTester() {
    PriorityQueue<type> queue;

    char input;
    int priority;
    type temp;

    while (input != 'q') {
        cout << "\n\t\033[33mPRIORITY QUEUE TESTER\033[0m\n";
        cout << "\tSupported Operations: \n";
        cout << "\t(\033[32mi\033[0m) Insert\n";
        cout << "\t(\033[32mp\033[0m) Pop\n";
        cout << "\t(\033[32mn\033[0m) Get Next\n";
        cout << "\t(\033[32ms\033[0m) Get Size\n";
        cout << "\t(\033[32me\033[0m) Is Empty\n";
        cout << "\tEnter the operation (q to quit): \033[32m";

        cin >> input;
        cout << "\033[0m";

        if (input == 'i') {
            cout << "\n\t\tEnter the value to insert: \033[32m";
            cin >> temp;
            cout << "\033[0m\t\tEnter the priority of the value: \033[32m";
            cin >> priority;
            cout << "\033[0m";

            queue.insert(temp, priority);
            cout << "\t\t\033[34m" << temp << "\033[0m inserted\n";
        } else if (input == 'p') {
            try {
                temp = queue.pop();
                cout << "\n\t\tValue popped: \033[34m" << temp << "\033[0m\n";
            } catch(std::invalid_argument& d) {
                cout << "\n\t\tException: \033[31m" << d.what() << "\033[0m\n";
            }
        } else if (input == 'n') {
            try {
                temp = queue.getNext();
                cout << "\n\t\tNext value: \033[34m" << temp << "\033[0m\n";
            } catch(std::invalid_argument& d) {
                cout << "\n\t\tException: \033[31m" << d.what() << "\033[0m\n";
            }
        } else if (input == 's') {
            cout << "\n\t\tQueue size: \033[34m" << queue.getSize() << "\033[0m\n";
        } else if (input == 'e') {
            if (queue.isEmpty()) {
                cout << "\n\t\tThe queue is \033[34mempty\033[0m\n";
            } else {
                cout << "\n\t\tThe queue is \033[34mnot empty\033[0m\n";
            }
        } else if (input != 'q') {
            cout << "\n\t\tUnsuported operation: \033[31m" << input << "\033[0m\n";
        }
    }

    cout << "\n\t\033[33mEXITING PRIORITY QUEUE TESTER\033[0m\n";
}

template<typename type>
void binaryTester() {
    BinaryTree<type> tree;

    char input;
    type temp;

    while (input != 'q') {
        cout << "\n\t\033[33mBINARY TREE TESTER\033[0m\n";
        cout << "\tSupported Operations: \n";
        cout << "\t(\033[32mi\033[0m) Insert\n";
        cout << "\t(\033[32mx\033[0m) Remove\n";
        cout << "\t(\033[32mc\033[0m) Contains\n";
        cout << "\t(\033[32mn\033[0m) Inorder\n";
        cout << "\t(\033[32mr\033[0m) Preorder\n";
        cout << "\t(\033[32mo\033[0m) Postorder\n";
        cout << "\t(\033[32ml\033[0m) Clear\n";
        cout << "\t(\033[32mg\033[0m) Get Root\n";
        cout << "\t(\033[32ms\033[0m) Get Size\n";
        cout << "\t(\033[32me\033[0m) Is Empty\n";
        cout << "\tEnter the operation (q to quit): \033[32m";

        cin >> input;
        cout << "\033[0m";

        if (input == 'i') {
            cout << "\n\t\tEnter the value to insert: \033[32m";
            cin >> temp;
            cout << "\033[0m";

            tree.insert(temp);
            cout << "\t\t\033[34m" << temp << "\033[0m inserted\n";
        } else if (input == 'x') {
            cout << "\n\t\tEnter the value to remove: \033[32m";
            cin >> temp;
            cout << "\033[0m";

            if (tree.contains(temp)) {
                tree.remove(temp);
                cout << "\t\t\033[34m" << temp << "\033[0m removed\n";
            } else {
                cout << "\n\t\tTree does not contain: \033[31m" << temp << "\033[0m\n";
            }
        } else if (input == 'c') {
            cout << "\n\t\tEnter the value to look for: \033[32m";
            cin >> temp;
            cout << "\033[0m";

            if (tree.contains(temp)) {
                cout << "\n\t\tTree \033[34mdoes\033[0m contain: \033[34m" << temp << "\033[0m\n";
            } else {
                cout << "\n\t\tTree \033[34mdoes not\033[0m contain: \033[34m" << temp << "\033[0m\n";
            }
        } else if (input == 'n') {
            cout << "\n\t\tTree: \033[34m";
            tree.outputInorder();
            cout << "\033[0m";
        } else if (input == 'r') {
            cout << "\n\t\tTree: \033[34m";
            tree.outputPreorder();
            cout << "\033[0m";
        } else if (input == 'o') {
            cout << "\n\t\tTree: \033[34m";
            tree.outputPostorder();
            cout << "\033[0m";
        } else if (input == 'l') {
            tree.clear(tree.getRoot());
            cout << "\n\t\tTree cleared\n";
        } else if (input == 'g') {
            if (tree.getSize() > 0) {
                cout << "\n\t\t\033Root: [34m" << tree.getRoot()->nodeValue << "\033[0m removed\n";
            } else {
                cout << "\n\t\tTree does is size \033[31m0\033[0m\n";
            }
        } else if (input == 's') {
            cout << "\n\t\tTree size: \033[34m" << tree.getSize() << "\033[0m\n";
        } else if (input == 'e') {
            if (tree.isEmpty()) {
                cout << "\n\t\tThe tree is \033[34mempty\033[0m\n";
            } else {
                cout << "\n\t\tThe tree is \033[34mnot empty\033[0m\n";
            }
        } else if (input != 'q') {
            cout << "\n\t\tUnsuported operation: \033[31m" << input << "\033[0m\n";
        }
    }

    cout << "\n\t\033[33mEXITING BINARY TREE TESTER\033[0m\n";
}

template<typename type>
void graphTester() {
    Graph<type> graph;

    char input;
    type temp1, temp2;

    while (input != 'q') {
        cout << "\n\t\033[33mGRAPH TESTER\033[0m\n";
        cout << "\tSupported Operations: \n";
        cout << "\t(\033[32mn\033[0m) Add Node\n";
        cout << "\t(\033[32ma\033[0m) Add Edge\n";
        cout << "\t(\033[32mc\033[0m) Contains\n";
        cout << "\t(\033[32ms\033[0m) Get Size\n";
        cout << "\t(\033[32me\033[0m) Is Empty\n";
        cout << "\t(\033[32mo\033[0m) Output\n";
        cout << "\tEnter the operation (q to quit): \033[32m";

        cin >> input;
        cout << "\033[0m";

        if (input == 'n') {
            cout << "\n\t\tEnter the value to add: \033[32m";
            cin >> temp1;
            cout << "\033[0m";

            graph.addNode(temp1);
            cout << "\t\t\033[34m" << temp1 << "\033[0m added\n";
        } else if (input == 'a') {
            cout << "\n\t\tEnter the first node: \033[32m";
            cin >> temp1;
            cout << "\033[0m\t\tEnter the second node: \033[32m";
            cin >> temp2;
            cout << "\033[0m";

            graph.addEdge(temp1, temp2);
            cout << "\t\tEdge from \033[34m" << temp1 << "\033[0m to \033[34m" << temp2 << "\033[0m added\n";
        } else if (input == 'c') {
            cout << "\n\t\tEnter the value to look for: \033[32m";
            cin >> temp1;
            cout << "\033[0m";

            if (graph.contains(temp1)) {
                cout << "\n\t\tGraph \033[34mdoes\033[0m contain: \033[34m" << temp1 << "\033[0m\n";
            } else {
                cout << "\n\t\tGraph \033[34mdoes not\033[0m contain: \033[34m" << temp1 << "\033[0m\n";
            }
        } else if (input == 's') {
            cout << "\n\t\tGraph size: \033[34m" << graph.getSize() << "\033[0m\n";
        } else if (input == 'e') {
            if (graph.isEmpty()) {
                cout << "\n\t\tThe graph is \033[34mempty\033[0m\n";
            } else {
                cout << "\n\t\tThe graph is \033[34mnot empty\033[0m\n";
            }
        } else if (input == 'o') {
            cout << "\n\t\tGraph: \033[34m" << graph << "\033[0m\n";
        } else if (input != 'q') {
            cout << "\n\t\tUnsuported operation: \033[31m" << input << "\033[0m\n";
        }
    }

    cout << "\n\t\033[33mEXITING GRAPH TESTER\033[0m\n";
}

int main() {
    char input = ' ';

    while (input != 'q') {
        cout << "\033[33mABSTRACT DATA TYPE TESTER\033[0m\n";
        cout << "Supported Types: \n";
        cout << "(\033[32mu\033[0m) Queue\n";
        cout << "(\033[32ms\033[0m) Stack\n";
        cout << "(\033[32ml\033[0m) Linked List\n";
        cout << "(\033[32mp\033[0m) Priority Queue\n";
        cout << "(\033[32mb\033[0m) Binary Tree\n";
        cout << "(\033[32mg\033[0m) Graph\n";
        cout << "Enter the type to test (q to quit): \033[32m";

        cin >> input;
        cout << "\033[0m";

        if (input == 'u') {
            cout << "\n\t\033[33mQUEUE TESTER\033[0m\n";
            cout << "\tSupported Types: \n";
            cout << "\t(\033[32mi\033[0m) Integer\n";
            cout << "\t(\033[32mf\033[0m) Float\n";
            cout << "\t(\033[32mc\033[0m) Character\n";
            cout << "\t(\033[32mb\033[0m) Boolean\n";
            cout << "\tEnter the type: \033[32m";

            cin >> input;
            cout << "\033[0m";

            if (input == 'i') {
                queueTester<int>();
            } else if (input == 'f') {
                queueTester<float>();
            } else if (input == 'c') {
                queueTester<char>();
            } else if (input == 'b') {
                queueTester<bool>();
            } else {
                cout << "\n\t\tUnsuported type: \033[31m" << input << "\033[0m";
                cout << "\n\n\t\033[33mEXITING QUEUE TESTER\033[0m\n";
            }
        } else if (input == 's') {
            cout << "\n\t\033[33mSTACK TESTER\033[0m\n";
            cout << "\tSupported Types: \n";
            cout << "\t(\033[32mi\033[0m) Integer\n";
            cout << "\t(\033[32mf\033[0m) Float\n";
            cout << "\t(\033[32mc\033[0m) Character\n";
            cout << "\t(\033[32mb\033[0m) Boolean\n";
            cout << "\tEnter the type: \033[32m";

            cin >> input;
            cout << "\033[0m";

            if (input == 'i') {
                stackTester<int>();
            } else if (input == 'f') {
                stackTester<float>();
            } else if (input == 'c') {
                stackTester<char>();
            } else if (input == 'b') {
                stackTester<bool>();
            } else {
                cout << "\n\t\tUnsuported type: \033[31m" << input << "\033[0m";
                cout << "\n\n\t\033[33mEXITING STACK TESTER\033[0m\n";
            }
        } else if (input == 'l') {
            cout << "\n\t\033[33mLINKED LIST TESTER\033[0m\n";
            cout << "\tSupported Types: \n";
            cout << "\t(\033[32mi\033[0m) Integer\n";
            cout << "\t(\033[32mf\033[0m) Float\n";
            cout << "\t(\033[32mc\033[0m) Character\n";
            cout << "\t(\033[32mb\033[0m) Boolean\n";
            cout << "\tEnter the type: \033[32m";

            cin >> input;
            cout << "\033[0m";

            if (input == 'i') {
                listTester<int>();
            } else if (input == 'f') {
                listTester<float>();
            } else if (input == 'c') {
                listTester<char>();
            } else if (input == 'b') {
                listTester<bool>();
            } else {
                cout << "\n\t\tUnsuported type: \033[31m" << input << "\033[0m";
                cout << "\n\n\t\033[33mEXITING LINKED LIST TESTER\033[0m\n";
            }
        } else if (input == 'p') {
            cout << "\n\t\033[33mPRIORITY QUEUE TESTER\033[0m\n";
            cout << "\tSupported Types: \n";
            cout << "\t(\033[32mi\033[0m) Integer\n";
            cout << "\t(\033[32mf\033[0m) Float\n";
            cout << "\t(\033[32mc\033[0m) Character\n";
            cout << "\t(\033[32mb\033[0m) Boolean\n";
            cout << "\tEnter the type: \033[32m";

            cin >> input;
            cout << "\033[0m";

            if (input == 'i') {
                priorityTester<int>();
            } else if (input == 'f') {
                priorityTester<float>();
            } else if (input == 'c') {
                priorityTester<char>();
            } else if (input == 'b') {
                priorityTester<bool>();
            } else {
                cout << "\n\t\tUnsuported type: \033[31m" << input << "\033[0m";
                cout << "\n\n\t\033[33mEXITING PRIORITY QUEUE TESTER\033[0m\n";
            }
        } else if (input == 'b') {
            cout << "\n\t\033[33mBINARY TREE TESTER\033[0m\n";
            cout << "\tSupported Types: \n";
            cout << "\t(\033[32mi\033[0m) Integer\n";
            cout << "\t(\033[32mf\033[0m) Float\n";
            cout << "\tEnter the type: \033[32m";

            cin >> input;
            cout << "\033[0m";

            if (input == 'i') {
                binaryTester<int>();
            } else if (input == 'f') {
                binaryTester<float>();
            } else {
                cout << "\n\t\tUnsuported type: \033[31m" << input << "\033[0m";
                cout << "\n\n\t\033[33mEXITING BINARY TREE TESTER\033[0m\n";
            }
        } else if (input == 'g') {
            cout << "\n\t\033[33mGRAPH TESTER\033[0m\n";
            cout << "\tSupported Types: \n";
            cout << "\t(\033[32mi\033[0m) Integer\n";
            cout << "\t(\033[32mf\033[0m) Float\n";
            cout << "\t(\033[32mc\033[0m) Character\n";
            cout << "\tEnter the type: \033[32m";

            cin >> input;
            cout << "\033[0m";

            if (input == 'i') {
                graphTester<int>();
            } else if (input == 'f') {
                graphTester<float>();
            } else if (input == 'c') {
                graphTester<char>();
            } else {
                cout << "\n\t\tUnsuported type: \033[31m" << input << "\033[0m";
                cout << "\n\n\t\033[33mEXITING GRAPH TESTER\033[0m\n";
            }
        } else if (input != 'q') {
            cout << "\nUnsuported type: \033[31m" << input << "\033[0m\n";
        }

        cout << '\n';
    }

    cout << "\033[33mEXITING ABSTRACT DATA TYPE TESTER\033[0m\n";

    return 0;
}
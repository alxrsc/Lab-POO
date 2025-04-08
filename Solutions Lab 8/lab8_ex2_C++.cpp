#include <iostream>

template <class T>
class Stack {
    T* data;
    int size;
    int capacity;

public:
    Stack(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->data = new T[capacity];
    }

    // destructor to free malloced memory
    ~Stack() {
        delete[] data;
    }

    void push(T value) {
        if (size == capacity) {
            std::cout << "Stack is full" << std::endl;
            return;
        }
        data[size++] = value;
    }

    T pop() {
        if (size == 0) {
            std::cout << "Stack is empty" << std::endl;
            return T();
        }
        return data[--size];
    }

    T top() {
        if (size == 0) {
            std::cout << "Stack is empty" << std::endl;
            return T();
        }
        return data[size - 1];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};

template <class T>
class Queue {
    T *data;
    int size;
    int capacity;
public:
    Queue(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->data = new T[capacity];
    }

    // destructor to free malloced memory
    ~Queue() {
        delete[] data;
    }

    void enqueue(T value) {
        if (size == capacity) {
            std::cout << "Queue is full" << std::endl;
            return;
        }
        data[size++] = value;
    }

    T dequeue() {
        if (size == 0) {
            std::cout << "Queue is empty" << std::endl;
            return T();
        }
        T value = data[0];
        for (int i = 0; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
        return value;
    }

    T front() {
        if (size == 0) {
            std::cout << "Queue is empty" << std::endl;
            return T();
        }
        return data[0];
    }

    T back() {
        if (size == 0) {
            std::cout << "Queue is empty" << std::endl;
            return T();
        }
        return data[size - 1];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};

int main() {

    Stack<int> intStack(5);
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    intStack.push(4);
    intStack.push(5);
    intStack.push(6);
    std::cout << intStack.pop() << std::endl;
    std::cout << intStack.pop() << std::endl;


    Stack<char> charStack(5);
    charStack.push('a');
    charStack.push('b');
    charStack.push('c');
    charStack.push('d');
    charStack.push('e');
    charStack.push('f');
    std::cout << charStack.pop() << std::endl;
    std::cout << charStack.pop() << std::endl;

    Queue<int> intQueue(5);
    intQueue.enqueue(1);
    intQueue.enqueue(2);
    intQueue.enqueue(3);
    intQueue.enqueue(4);
    intQueue.enqueue(5);
    intQueue.enqueue(6);
    std::cout << intQueue.dequeue() << std::endl;
    std::cout << intQueue.dequeue() << std::endl;

    Queue<char> charQueue(5);
    charQueue.enqueue('a');
    charQueue.enqueue('b');
    charQueue.enqueue('c');
    charQueue.enqueue('d');
    charQueue.enqueue('e');
    charQueue.enqueue('f');
    std::cout << charQueue.dequeue() << std::endl;
    std::cout << charQueue.dequeue() << std::endl;

    return 0;
}
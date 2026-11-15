// LeetCode 622 - Design Circular Queue
#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> data;
    int frontIndex;
    int rearIndex;
    int count;
    int capacity;

public:
    MyCircularQueue(int k)
        : data(k), frontIndex(0), rearIndex(0), count(0), capacity(k) {}

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        data[rearIndex] = value;
        rearIndex = (rearIndex + 1) % capacity;
        count++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : data[frontIndex];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        int index = (rearIndex - 1 + capacity) % capacity;
        return data[index];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};

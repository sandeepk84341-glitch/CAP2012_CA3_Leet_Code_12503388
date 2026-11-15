// LeetCode 232 - Implement Queue using Stacks
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> inputStack;
    stack<int> outputStack;

    void moveElements() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        moveElements();
        int value = outputStack.top();
        outputStack.pop();
        return value;
    }

    int peek() {
        moveElements();
        return outputStack.top();
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

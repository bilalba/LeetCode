#import <queue>
using namespace std;
class Stack {
public:
    queue<int> queue_1;
    queue<int> queue_2;
    int topz;
    // Push element x onto stack.
    void push(int x) {
        topz = x;
        queue_1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        for (int i = 0; i < queue_1.size()-1; i++)
            topz = queue_1.front(), queue_1.push(queue_1.front()), queue_1.pop();
        queue_1.pop();
    }

    // Get the top element.
    int top() {
        return topz;
    }

    // Return whether the stack is empty.
    bool empty() {
        if (queue_1.size() == 0) return true;
        return false;
    }
};
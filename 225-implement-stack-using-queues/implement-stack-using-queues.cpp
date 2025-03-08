#include <queue>

class MyStack {
private:
    std::queue<int> q;
    
public:
    MyStack() { }
    
    void push(int x) {
        q.push(x);
        int size = q.size();
        // Rotate the queue to move the new element to the front
        while (--size) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int topElement = q.front();
        q.pop();
        return topElement;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

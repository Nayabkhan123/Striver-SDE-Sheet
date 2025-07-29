/*
    Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all 
    the functions of a normal stack (push, top, pop, and empty).

    Implement the MyStack class:

    void push(int x) Pushes element x to the top of the stack.
    int pop() Removes the element on the top of the stack and returns it.
    int top() Returns the element on the top of the stack.
    boolean empty() Returns true if the stack is empty, false otherwise.
    Notes:

    You must use only standard operations of a queue, which means that only push to back, peek/pop from front, 
    size and is empty operations are valid.
    Depending on your language, the queue may not be supported natively. You may simulate a queue using a list 
    or deque (double-ended queue) as long as you use only a queue's standard operations.
    

    Example 1:

    Input
    ["MyStack", "push", "push", "top", "pop", "empty"]
    [[], [1], [2], [], [], []]
    Output
    [null, null, null, 2, 2, false]

    Explanation
    MyStack myStack = new MyStack();
    myStack.push(1);
    myStack.push(2);
    myStack.top(); // return 2
    myStack.pop(); // return 2
    myStack.empty(); // return False
*/

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// using single queue 
class MyStack {
    queue<int>q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int n=q.size();
        q.push(x);
        while(n>0){
            q.push(q.front());
            q.pop();
            n--;
        }
    }
    
    int pop() {
        int poppedElement = q.front();
        q.pop();
        return poppedElement;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

// using two queues
class MyStack {
    queue<int>q1,q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(!q1.size()) return -1;
        int n=q1.size();
        for(int i=0;i<n-1;i++){
            q2.push(q1.front());
            q1.pop();
        }
        int poppedElement = q1.front();
        q1.pop();
        n=q2.size();
        for(int i=0;i<n;i++){
            q1.push(q2.front());
            q2.pop();
        }
        return poppedElement;
    }
    
    int top() {
        int n=q1.size();
        for(int i=0;i<n-1;i++){
            q2.push(q1.front());
            q1.pop();
        }
        int topElement = q1.front();
        q2.push(q1.front());
        q1.pop();
        n=q2.size();
        for(int i=0;i<n;i++){
            q1.push(q2.front());
            q2.pop();
            
        }
        return topElement;
    }
    
    bool empty() {
        return !q1.size();
    }
};

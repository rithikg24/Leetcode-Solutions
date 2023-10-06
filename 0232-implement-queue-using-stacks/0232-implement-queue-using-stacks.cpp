class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {
        
    }
    
    void push(int x) {
        // s1 -> s2
        while(!s1.empty()){
            int t=s1.top();
            s1.pop();
            s2.push(t);
        }
        // push element
        s1.push(x);
        // s2->s1
        while(!s2.empty()){
            int t=s2.top();
            s2.pop();
            s1.push(t);
        }
    }
    
    int pop() {
        int t = s1.top();
        s1.pop();
        return t;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
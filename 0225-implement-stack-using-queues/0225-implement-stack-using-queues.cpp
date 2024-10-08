class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            int t = q1.front();
            q1.pop();
            q2.push(t);
        }
        q1=q2;
        // clear q2
        while(!q2.empty()){
            q2.pop();
        }
    }
    
    int pop() {
        int t=q1.front();
        q1.pop();
        return t;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
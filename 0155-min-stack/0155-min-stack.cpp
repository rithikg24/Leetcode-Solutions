class MinStack {
public:
    stack<int> s;
    stack<int> minVals;

    MinStack() {

    }
    
    void push(int val) {
        s.push(val);
        if(minVals.empty()) {minVals.push(val);}
        else{
            minVals.push(min(minVals.top(),val));
        }   
    }
    
    void pop() {
        s.pop();
        minVals.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minVals.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
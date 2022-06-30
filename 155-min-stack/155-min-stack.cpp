class MinStack {
public:
    //One way is to use stack of pairs, first one stores the value and the second one stores the minimum value till now
    stack<pair<int, int>> stk;
    MinStack() {
        
    }
    
    void push(int val) {
        int mini = val;
        
        if(!stk.empty()){
            mini = min(mini, stk.top().second);
        }
        
        stk.push({val, mini});
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
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
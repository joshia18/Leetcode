class MinStack {
public:
    //One way is to use stack of pairs o(2n) space, first one stores the value and the second one stores the minimum value till now
    //another way is using stack o(1) space
    stack<long long> stk;
    long long mini = INT_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        long long val = value;
        if(stk.empty()){
            mini = val;
            stk.push(1LL * val);
        }
        else{
            if(val < mini){
                stk.push(2*val*1LL - mini);
                mini = val;
            }
            else{
                stk.push(val);
            }
        }
    }
    
    void pop() {
        if(stk.top() < mini){
            mini = 2*mini - stk.top();
            stk.pop();
        }
        else{
            stk.pop();
        }
    }
    
    int top() {
        if(stk.top() < mini) return mini;
        return stk.top();
    }
    
    int getMin() {
        return mini;
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
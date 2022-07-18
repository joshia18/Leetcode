class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(!output.empty()){
            int temp = output.top();
            output.pop();
            return temp;
        }
        
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        
        int temp = output.top();
        output.pop();
        return temp;
    }
    
    int peek() {
        if(!output.empty()){
            int temp = output.top();
            return temp;
        }
        
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        
        int temp = output.top();
        return temp;
    }
    
    bool empty() {
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        
        return output.empty();
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
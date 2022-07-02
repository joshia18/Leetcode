class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        //so solved using stack
        
        vector<int> ans;
        stack<int> stk;
        
        for(int i : asteroids){
            
            //we don't consider i == 0, only >0 and <0
            if(i > 0){
                //if asteroids go in right direction just add it to the stack
                stk.push(i);
            }
            else if(i < 0){
                //if it moves in the left, do the below operation
                
                //IMPORTANT: this blow variable keeps track if the current i asteroid is blasted or not
                bool blow = false;
                
                while(!stk.empty()){
                    //don't forget -i here
                    if(stk.top() > -i){
                        blow = true;
                        break;
                    }
                    else if(stk.top() == -i){
                        blow = true;
                        stk.pop();
                        break;
                    }
                    else{
                        stk.pop();
                    }
                }
                //if blow is false, the current asteroid i has not blasted, add it to the ans array
                if(blow == false) ans.push_back(i);
            }
            
        }
        
        int size = ans.size();
        
        while(!stk.empty()){
            //insert at the beginning
            ans.insert(ans.begin()+size, stk.top());
            stk.pop();
        }
        
        
        return ans;
        
    }
};
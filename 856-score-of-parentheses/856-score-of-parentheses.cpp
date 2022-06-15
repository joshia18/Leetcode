class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        int count = 0;
        
        for(char &c : s){
            if(c == '('){
                stk.push(count);
                //this one is importat here
                count = 0;
            }
            else{
                count = stk.top() + max(2*count, 1);
                stk.pop();
            }
        }
        
        return count;
    }
};
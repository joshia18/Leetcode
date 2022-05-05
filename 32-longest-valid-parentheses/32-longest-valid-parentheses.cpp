class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n = s.size();
        
        stack<int> stk;
        
        vector<int> dp(n, 0);
        
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                stk.push(i);
            }
            
            if(!stk.empty() && s[i] == ')'){
                dp[stk.top()] = 1;
                dp[i] = 1;
                stk.pop();
            }
        }
        
        int len = 0, maxLen = 0;
        
        for(int i = 0; i < n; i++){
            if(dp[i] == 0){
                len = 0;
            }
            
            if(dp[i] == 1){
                len++;
            }
            
            maxLen = max(maxLen, len);
        }
        
        return maxLen;
        
    }
};
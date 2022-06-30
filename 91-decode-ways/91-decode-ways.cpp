class Solution {
public:
    int helper(int i, string &s, vector<int> &dp){
        //base case
        if(i >= s.size()) return 1;
        
        if(dp[i] != -1)  return dp[i];
        
        int ans = 0;
        
        int one = s[i] - '0', two = 0;
        if(i+1 < s.size()){
            two = one*10 + s[i+1] - '0';
        }
        
        if(one > 0) ans += helper(i+1, s, dp);
        if(one > 0 && two > 0 && two <= 26) ans += helper(i+2, s, dp);
        
        return dp[i] = ans;
    }
    
    int numDecodings(string s) {
        
        if(s[0] == '0') return 0;
        
        int n = s.size();
        
        vector<int> dp(n, -1);
        
        return helper(0, s, dp);
    }
};
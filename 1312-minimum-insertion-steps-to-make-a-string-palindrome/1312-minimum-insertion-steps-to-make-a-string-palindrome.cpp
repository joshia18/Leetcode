class Solution {
public:
    int helper(string &s, int start, int end, vector<vector<int>> &dp){
        
        if(start == end) return 1;
        
        if(start > end) return 0;
        
        if(dp[start][end] != -1) return dp[start][end];
        
        int ans = 0;
        
        if(s[start] == s[end]){
            ans = 2 + helper(s, start+1, end-1, dp);
        }
        else{
            ans = max(helper(s, start+1, end, dp), helper(s, start, end-1, dp));
        }
        
        return dp[start][end] = ans;
    }
    
    int minInsertions(string s) {
        //this is implemented based on the fact that
        //minimum insertion steps  = length of the string (n) - length of longest palindromic subsequence
        
        int n = s.size();
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        int lpslen = helper(s, 0, n-1, dp);
        
        return n - lpslen;
    }
};
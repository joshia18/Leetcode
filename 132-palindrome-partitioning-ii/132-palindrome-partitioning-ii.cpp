class Solution {
public:
    bool isPalindrome(string &s, int l, int r){        
        while(l <= r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        
        return true;
    }
    
    int helper(int index, string &s, vector<int> &dp){
        if(index == s.size()) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int mincuts = INT_MAX;
        
        for(int i = index; i < s.size(); i++){
            
            if(isPalindrome(s, index, i)){
                int cuts = 1 + helper(i+1, s, dp);
                mincuts = min(mincuts, cuts);
            }
        }
        
        return dp[index] = mincuts;
    }
    
    int minCut(string s) {
        int n = s.size();
        
        vector<int> dp(n, -1);
        
        return helper(0, s, dp)-1;
    }
};
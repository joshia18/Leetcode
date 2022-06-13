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
    
//     int helper(int index, string &s, vector<int> &dp){
//         //base case
//         if(index == s.size()) return 0;
        
//         if(dp[index] != -1) return dp[index];
        
//         int mincuts = INT_MAX;
        
//         for(int i = index; i < s.size(); i++){
            
//             if(isPalindrome(s, index, i)){
//                 int cuts = 1 + helper(i+1, s, dp);
//                 mincuts = min(mincuts, cuts);
//             }
//         }
        
//         return dp[index] = mincuts;
//     }
    
    int minCut(string s) {
        int n = s.size();
        
        vector<int> dp(n+1, 0);
        
        //base case
        dp[n] = 0;
        
        for(int i = n-1; i >= 0; i--){
            int mincuts = INT_MAX;
        
            for(int j = i; j < s.size(); j++){

                if(isPalindrome(s, i, j)){
                    int cuts = 1 + dp[j+1];
                    mincuts = min(mincuts, cuts);
                }
            }
            
            dp[i] = mincuts;
        }
        
        return dp[0]-1;
        
        //return helper(0, s, dp)-1;
    }
};
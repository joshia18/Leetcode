class Solution {
public:
    //vector<vector<vector<int>>> vector_3d(z, vector<vector<int>>(y, vector<int>(x, value)));
//     vector<vector<vector<int>>> dp;
    
//     int helper(vector<string>& strs, vector<vector<int>> &zo, int index, int m, int n){
//         if(index == strs.size()) return 0;
        
//         if(dp[index][m][n] != -1) return dp[index][m][n];
        
//         int take = 0;
        
//         //this condition is important
//         if(m >= zo[index][0] && n >= zo[index][1]){
//            take = 1 + helper(strs, zo, index+1, m-zo[index][0], n-zo[index][1]);
//         }
//         int nottake = helper(strs, zo, index+1, m, n);
//         //cout << take << " " << nottake << endl;
        
//         return dp[index][m][n] = max(take, nottake);
//     }
    
    int count(string &s, int number){
        int z = 0;
        for(char c : s){
            if(c == '0') z++;
        }
        
        if(number) return s.size()-z;
        return z;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(string &s : strs){
            int zerocount = count(s, 0);
            int onecount = count(s, 1);
            
            for(int zeros = m; zeros >= zerocount; zeros--){
                for(int ones = n; ones >= onecount; ones--){
                    dp[zeros][ones] = max(1 + dp[zeros - zerocount][ones - onecount], dp[zeros][ones]);
                }
            }
        }
        
        return dp[m][n];
        
        //return helper(strs, zo, 0, m, n);
    }
};
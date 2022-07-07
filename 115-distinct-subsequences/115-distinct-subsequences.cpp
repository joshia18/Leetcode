class Solution {
public:
    
       
    int numDistinct(string s, string t) {
        //look at the first submitted solution for recursion + memoization
        //bottom up tabulation dp approach
        int m = s.size(), n = t.size();
        
        //this is done with 2 arrays but can be optimized further using only 1 array
        vector<double> dp(n+1, 0);
        //vector<double> cur(n+1, 0);
        
        //for all i = 0 put dp[i][0] = 1
        dp[0] = 1;
        
        //start from 1
        for(int i = 1; i <= m; i++){
            for(int j = n; j >= 1; j--){
                //have to consider 1 based indexing for matching like the LCS problem
                
                if(s[i-1] == t[j-1]){
                    dp[j] = dp[j-1] + dp[j];
                }
                else{
                    dp[j] = dp[j];
                }
            }
            
        }
        
        return (int)dp[n];
        
    }
};
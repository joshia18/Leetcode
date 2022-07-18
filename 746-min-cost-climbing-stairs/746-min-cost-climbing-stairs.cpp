class Solution {
public:
    
//     int helper(vector<int>& cost, int idx, vector<int> &dp){
//         if(idx >= cost.size()) return 0;
        
//         if(dp[idx] != -1) return dp[idx];
        
//         int one = cost[idx] + helper(cost, idx+1, dp);
//         int two = cost[idx] + helper(cost, idx+2, dp);
        
//         return dp[idx] = min(one, two);
//     }
    
    //using only two variables instead of dp array
    int minCostClimbingStairs(vector<int>& cost) {
         int n = cost.size();
     
//         int step1 = 0;
//         int step2 = 0;
        
//         for(int i = n-1; i >= 0; i--){
//             int temp = cost[i] + min(step1, step2);
//             step1 = step2;
//             step2 = temp;            
//         }
        
//         return min(step1, step2);
        
        // vector<int> dp(n+2, -1);
        // dp[n] = 0;
        // dp[n+1] = 0;
        
        //space optmization
        int step1 = 0, step2 = 0;
        
        for(int i = n-1; i >= 0; i--){
            
            int one = cost[i] + step1;
            int two = cost[i] + step2;
        
            int temp = min(one, two);
            step1 = step2;
            step2 = temp;
        }
        
        //return min(dp[0], dp[1]);
        return min(step1, step2);
    }
};
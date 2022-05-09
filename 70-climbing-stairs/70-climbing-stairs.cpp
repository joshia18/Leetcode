class Solution {
public:
    
//     vector<int> dp;
    
//     int helper(int n){
        
//         //if n == 0, in 0th stair we can make only 1 step
//         if(n <= 2) return n;
        
//         if(dp[n] != -1) return dp[n];
        
//         int left = helper(n-1);
//         int right = helper(n-2);
        
//         return dp[n] = left + right;
//     }
    
    int climbStairs(int n) {
        
        //dp.resize(n+1, -1);
        //using fibonacci logic by sliding through.. first set x = 1, y = 2. for 2 steps, there are two ways to climb, one by taking two single steps and other by making one single jump to step 2
        //return helper(n);
        
        int x = 1, y = 2;
        
        if(n <= 2) return n;
        
        for(int i = 3; i <= n; i++){
            int temp = x+y;
            x = y;
            y = temp;
        }
        
        return y;
        
    }
};
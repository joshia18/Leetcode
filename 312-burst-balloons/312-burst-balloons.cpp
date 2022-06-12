class Solution {
public:
    int helper(int i, int j, vector<int>& nums, vector<vector<int>> &dp){
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int maxcost = INT_MIN;
        
        for(int ind = i; ind <= j; ind++){
            //in the returning they will all be added, so no problem
            int cost = nums[i-1] * nums[ind] * nums[j+1] + helper(i, ind-1, nums, dp) + helper(ind+1, j, nums, dp);
            maxcost = max(maxcost, cost);
        }
        
        return dp[i][j] = maxcost;
    }
    
    int maxCoins(vector<int>& nums) {
        //partition dp
        
        int n = nums.size();
        
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        
        //insert1 at the beginnning and the end of input
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        
        return helper(1, n, nums, dp);
    }
};
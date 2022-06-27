class Solution {
public:
//     vector<int> mem;
//     int helper(int index, vector<int>& nums){
//         if(index == 0) return nums[index];
//         if(index < 0) return 0;
        
//         if(mem[index] != -1) return mem[index];
        
//         int pick = nums[index] + helper(index-2, nums);
//         int notpick = helper(index-1, nums);
        
//         return mem[index] = max(pick, notpick);
        
//     }
    
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1) return nums[0];
        
        int ans = 0;
        
        int n = nums.size();
        vector<int> dp(n, 0);
        
        dp[0] = nums[0];
        
        //start from 1
        for(int i = 1; i < n; i++){
            
            int pick = nums[i];
            if(i > 1) pick +=  dp[i-2];
            
            int notpick = dp[i-1];

            dp[i] = max(pick, notpick);
        }
        
        return dp[n-1];
        
        //mem.resize(nums.size()+1, -1);
        
        //return helper(nums.size()-1, nums);
    }
};
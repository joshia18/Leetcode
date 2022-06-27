class Solution {
public:
    vector<int> mem;
    int helper(int index, vector<int>& nums){
        if(index == 0) return nums[index];
        if(index < 0) return 0;
        
        if(mem[index] != -1) return mem[index];
        
        int pick = nums[index] + helper(index-2, nums);
        int notpick = helper(index-1, nums);
        
        return mem[index] = max(pick, notpick);
        
    }
    
    int rob(vector<int>& nums) {
//         int ans = 0;
//         int dp[nums.size()];
        
//         if(nums.size() == 1){
//             return nums[0];
//         }
        
//         if(nums.size() == 2){
//             return max(nums[0],nums[1]);
//         }
        
//         dp[0] = nums[0];
//         dp[1] = max(nums[0],nums[1]);
        
//         for(int i = 2; i < nums.size(); i++){
//             dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
//         }
        
//         return dp[nums.size() - 1];
        mem.resize(nums.size()+1, -1);
        
        return helper(nums.size()-1, nums);
    }
};
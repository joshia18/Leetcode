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
        
        int prev = nums[0];
        int prev2 = 0;
        
        //start from 1
        //added space optimization
        for(int i = 1; i < n; i++){
            
            int pick = nums[i];
            if(i > 1) pick +=  prev2;
            
            int notpick = prev;

            int curr = max(pick, notpick);
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
        
        //mem.resize(nums.size()+1, -1);
        
        //return helper(nums.size()-1, nums);
    }
};
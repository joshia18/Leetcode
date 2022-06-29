class Solution {
public:
    int helper(int i, int target, vector<int>& nums){
        if(i == 0){
            if(target == 0 && nums[0] == 0) return 2;
            else if(target == 0 || target == nums[0]) return 1;
            return 0;
        }
        
        int take = 0;
        if(nums[i] <= target) take = helper(i-1, target-nums[i], nums);
        int nottake = helper(i-1, target, nums);
        
        return take+nottake;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum = 0;
        int n = nums.size();
        
        for(int &i : nums) totalsum += i;
        
        cout << (totalsum - target)/2;
        
        if((totalsum - target) < 0 || (totalsum - target)%2 == 1) return 0;
        
        return helper(n-1, (totalsum-target)/2, nums);
    }
};
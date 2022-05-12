class Solution {
public:
    unordered_map<int,int> dp; //key will be variable a + mask*10 as the number of operations(a) will always be less than or equal to 7
    
    int helper(int a, int mask, vector<int>& nums, int n){
        
        //if all the bits are set to 0 of mask using bit masking, then return 0
        if(mask == 0) return 0;
        
        int key = a + mask*10;
        
        if(dp.find(key) != dp.end()) return dp[key];
        
        int maxVal = 0;
        
        for(int i = 0; i < n; i++){
            if(mask&(1<<i)){
                for(int j = i+1; j < n; j++){
                    if(mask&(1<<j)){
                        //mask^(1<<i)^(1<<j) means setting 1<<i bit and 1<<j bit in mask to zero
                        maxVal = max(maxVal, a* __gcd(nums[i],nums[j]) + helper(a+1, mask^(1<<i)^(1<<j), nums, n));
                    }
                }
            }
        }
        
        return dp[key] = maxVal;
        
    }
    
    int maxScore(vector<int>& nums) {
        //solved using bitmasking dp
        //dp with memoization time complexity would be n^3 * 2^(2*n)
        
        int n = nums.size();
        
        int mask = (1<<n)-1; //2^n - 1
        
        //a is the ith operation, totally n operations can be done on the 2*n sized subarray
        return helper(1, mask, nums, n);
    }
};
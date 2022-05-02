class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int max_ending_at = 0;
        int sum = 0;
        
//         for(int i : nums){
//             sum += i;
//             ans = max(ans, sum);
//             sum = max(0, sum);
//         }
        
//         return ans;
        
        //another method
        for(int x : nums){
            sum = max(sum + x, x);
            ans = max(ans, sum); 
        }
        
        return ans;
    }
};
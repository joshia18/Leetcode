class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int mindiff = INT_MAX;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        
        for(int i = 0; i < n-2; i++){
            int j = i+1, k = n-1;
            
            while(j < k){
                
                int sum = nums[i] + nums[j] + nums[k];
                
                int diff = abs(sum - target);
                
                if(diff < mindiff){
                    mindiff = min(mindiff, diff);
                    ans = sum;
                }
                
                if(sum <= target){
                    j++;
                }
                else{
                    k--;
                }
                
            }
        }
        
        return ans;
    }
};
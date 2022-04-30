class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int n = nums.size();
        int ans = 0;
        
        int mid = l + (r-l)/2;
        
        while(l <= r){
            mid = l + (r-l)/2;
            
            if(nums[mid] > nums[n-1]){
                l = mid+1;
            }
            else{
                ans = nums[mid];
                r = mid-1;
            }
        }
        
        return ans;
        
    }
};
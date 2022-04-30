class Solution {
    public int findPeakElement(int[] nums) {
        int l = 0, r = nums.length-1;
        int mid = l + (r-l)/2;
        int ans = 0;
        
        while(l <= r){
            mid = l + (r-l)/2;
            //this is an important condition here
            if(mid == 0 || nums[mid] > nums[mid-1]){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        
        return ans;
    }
}
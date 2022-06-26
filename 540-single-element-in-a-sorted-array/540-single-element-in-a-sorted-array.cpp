class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //for this problem, the given array can be divided into two, before singleelement(ans) and after singleelement
        //IMPORTANT
        //the left half is where the 1st instance of an element is in the even position and 2nd instance is in odd position
        //the second half is where the 1st instance of an element is in the odd position and 2nd instance is in even position
        //inorder to find the answer we have to do the binary search while l <= h, l = 0, h = nums.size()-2
        //why h is nums.size()-2 and not nums.size()-1, coz it works
        //because we are trying to shrink the left half and ultimately l will go to an index next to h in binary search, thus breaks the loop l <= h
        
        //we'll send nums[low] as answer at the end
        //strivr video
        
        int low = 0, high = nums.size()-2;
        
        if(nums.size() == 1) return nums[0];
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            if(nums[mid] == nums[mid^1]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return nums[low];
        
    }
};
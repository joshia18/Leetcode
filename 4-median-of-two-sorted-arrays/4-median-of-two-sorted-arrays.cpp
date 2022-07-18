class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //the most efficient solution is binary search method
        //
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1+n2;
        
        //IMPORTANT thing is here, do binary search for a smaller sized array
        if(n2 < n1) return findMedianSortedArrays(nums2, nums1);
        
        int low = 0, high = n1;
        
        while(low <= high){
            
            int cut1 = (low+high)/2;
            
            //this is important here for odd n cases
            //if total length(n1+n2) = 10, i want 5 elements in each half
            //if total = 11, then i want 6 in left half and 5 in right half
            //this formula (n1+n2+1)/2 - cut1 helps in such odd cases
            int cut2 = (n1+n2+1)/2 - cut1;
            
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            
            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];
            
            //cross check - left1 <= right2 && left2 <= right1
            //this formula: left1 <= right2 && left2 <= right1 checks that all the elements in the left half are smaller than 
            //all the elements in the right half
            if(left1 <= right2 && left2 <= right1){
                if((n1+n2)%2 == 0){
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
                else{
                    return max(left1, left2)/1.0;
                }
            }
            else if(left1 > right2){
                high = cut1-1;
            }
            else{
                low = cut1+1;
            }
            
        }
        
        return 0.0;       
        
    }
};
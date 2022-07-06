class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //another o(1) space solution
//         This method uses two nested loops to solve.

//         The first for-loop compares nums1 at index 0 with the entire nums2 of nums2[0,...len2-1], then proceed to A at index 1 with the entire string of B[0,...,len2-1]. The two conditions of the inner loop is to prevent going out of bounds.

//         Similarly, the second nested loop serves the same purpose but for nums2 at index 0... all the way to len2-1.
        
        int len1 = nums1.size(), len2 = nums2.size();
        
        int ans = 0;
        
        for(int i = 0; i < len1; i++){
            int temp = 0;
            for(int j = i, k = 0; j < len1 && k < len2; j++, k++){
                if(nums1[j] == nums2[k]){
                    temp++;
                    ans = max(ans, temp);
                }
                else{
                    temp = 0;
                }
            }
        }
        
        for(int i = 0; i < len2; i++){
            int temp = 0;
            for(int j = i, k = 0; j < len2 && k < len1; j++, k++){
                //another difference here nums2[j] == nums1[k]
                if(nums2[j] == nums1[k]){
                    temp++;
                    ans = max(ans, temp);
                }
                else{
                    temp = 0;
                }
            }
        }
        
        return ans;
    }
};
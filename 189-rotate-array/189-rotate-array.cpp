class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        reverse(nums.begin(), nums.end());
        
        //if(n < k) return;
        
        k = k%n;
        
        int i = 0, j = k-1;
        
        while(i < j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
        
        i = k, j = n-1;
        
        while(i < j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
};
class Solution {
public:
    bool check(int num, vector<int>& nums, int maxOperations){
        
        for(int i : nums){
            maxOperations -= i/num;
            
            //example to divide 8 into 2 it takes 3 operations not 4, 8 -> 4,4 -> 2,2,4 -> 2,2,2,2
            if(i%num == 0) maxOperations++;
        }
        
        return maxOperations >= 0;
        
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        //solved using binary search fraz
        
        int start = 1, end = 0;
        
        for(int &i : nums) end = max(end, i);
        
        int ans = 0;
        
        while(start <= end){
            int mid = start + (end - start)/2;
            
            if(check(mid, nums, maxOperations)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        
        return ans;
        
    }
};
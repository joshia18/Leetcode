class Solution {
public:
    int mod = 1e9+7;
    long power(int x, int y){
        long ans = 1;
        
        while(y > 0){
            if(y%2 == 0){
                x = ((long)x*x)%mod;
                y = y/2;
            }
            else{
                ans = ((long)ans*x)%mod;
                y = y-1;
            }
        }
        
        return ans%mod;
    }
    
    int numSubseq(vector<int>& nums, int target) {
        //for this problem we have to ssort the array
        sort(nums.begin(), nums.end());
        
        int count = 0;
        
        int l = 0, r = nums.size()-1;
        
        while(l <= r){
            if(nums[l]+nums[r] <= target){
                count = (count+power(2, r-l))%mod;
                l++;
            }
            else{
                r--;
            }
        }
        
        return count%mod;
    }
};
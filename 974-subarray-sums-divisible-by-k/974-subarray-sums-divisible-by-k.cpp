class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //using the same technique used in continuous subarray sum
        //but in this case we consider subarray of size 1 also so in that case we need to use the formula n(n-1)/2 for the number of mods that we got, where n is the number of mods
        //the reason for formula is
        //if mod = 4 is found in 3 indices/places, here n = 3, the subarray between any two indices is a valid subarray
        //if the mod is 0, then n + n(n-1)/2
        int count = 0, sum = 0;
        
        if(nums.size() == 1){
            if(nums[0]%k == 0) return 1;
            return 0;
        }
        
        vector<int> mp(k, 0);
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int mod = sum%k;
            if(mod < 0){
                //if k = 5, mod value can be between 0 and 4
                //if any negative values comes sum can be negative, then modulo can be negative in c++
                //inorder to convert -ve mod to +v mod add the mod with k
                mod = mod+k;
            }
            
            if(mod == 0) count++;
            
            if(mp[mod] != 0) count += mp[mod];            
            
            
            mp[mod]++;
        }
        
        return count;
        
        //spacce comolexity can be further reduced by using just a vector instead of map
    }
};
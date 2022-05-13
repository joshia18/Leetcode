class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //this problem uses certain princile using map ds.
        //for 1st example [23,2,4,6,7] & k = 6
        //nums[i]%k : imdex <- stored in map(int:int)
        //23%6 = 5 : 0
        //23+2 = 25%6 = 1 : 1
        //23+2+4 = 29%6 = 5 : 2 -< a key with value 5 aleady exists in map
        //so there is subarray with multiple of k present return true if subarray size is >= 2
        if(nums.size() < 2){
            return false;
        }
        
        //if k == 0 all the elements in the array should be zero, anyway k will not be 0 as per the constraints
        //it is already given that there is no negative numbers in nums
        if(k == 0){
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == 0){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        
        unordered_map<int, int> mp;
        mp.insert({0, -1});//this needs to be done to detect future key = 0 
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int mod = sum%k;
            if(mp.find(mod) != mp.end()){
                if(i - mp[mod] > 1){
                    return true;
                }
                continue;
            }
            mp.insert({mod, i});
        }
        
        return false;
    }
};
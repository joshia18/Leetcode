class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        
        unordered_map<int, int> hashmap;
        
        for(int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            
            if(hashmap.find(diff) != hashmap.end()){
                ans[0] = hashmap[diff];
                ans[1] = i;
                return ans;
            }
            
            hashmap.insert({nums[i], i});
        }
        
        return ans;
    }
};
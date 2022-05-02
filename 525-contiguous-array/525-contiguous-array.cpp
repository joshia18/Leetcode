class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        //inserted {0,-1} to the map already because for easier computation eg: for the 1st example given
        mp.insert({0, -1});
        
        int ans = 0, diffsum = 0;;
        
        for(int i = 0; i < nums.size(); i++){
            int diff = (nums[i] == 0 ? -1 : 1);
            diffsum += diff;
            
            if(mp.find(diffsum) != mp.end()){
                int len = i - mp[diffsum];
                ans = max(ans, len);
            }
            else{
                mp.insert({diffsum, i});
            }
        }
        
        return ans;
    }
};
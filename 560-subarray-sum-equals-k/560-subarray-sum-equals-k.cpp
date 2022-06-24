class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> prefixsum;
        int ans = 0, currentsum = 0;
        prefixsum[ans]++;
        
        for(int i = 0; i < nums.size(); i++){
            currentsum += nums[i];
            
            if(prefixsum.find(currentsum-k) != prefixsum.end()){
                ans += prefixsum[currentsum-k];
            }
            
            //here only the currentsum should be tracked in the map, not currentsum - k
            prefixsum[currentsum]++;
        }
        
        return ans;
        
    }
};
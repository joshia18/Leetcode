class Solution {
    // converting 3sum to  2 pointer byy fixing a number = x and finding another two numbers with sum = -x solves the problem
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int start = 0;
        int end = nums.size() - 1;
        vector<int> current;
        if(n == 0) return {};
        
        for(int i = 0; i < n-2; i++){
            
            if(i == 0 || nums[i] != nums[i-1]){
                int j = i+1, k = n-1;
                
                while(j < k){
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum == 0){
                        ans.push_back({nums[i], nums[j], nums[k]});
                        while(j < k && nums[j] == nums[j+1]) j++;
                        while(j < k && nums[k] == nums[k-1]) k--;
                        j++;
                        k--;
                    }
                    else if(sum > 0){
                        k--;
                    }
                    else{
                        j++;
                    }
                }
            }
        }
        
        return ans;
        
    }
};
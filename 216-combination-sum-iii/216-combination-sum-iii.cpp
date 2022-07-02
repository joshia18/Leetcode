class Solution {
public:
    void backtrack(int index, vector<int> &nums, vector<int> current, vector<vector<int>> &ans, int k, int n){
        if(current.size() == k && n == 0){
            ans.push_back(current);
            return;
        }
        
        for(int i = index; i < nums.size(); i++){
            if(n >= 0){
                current.push_back(nums[i]);
                backtrack(i+1, nums, current, ans, k, n-nums[i]);
                current.pop_back();
            }
        }
    }
        
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for(int i = 1; i <= 9; i++){
            nums.push_back(i);
        }
        
        vector<int> current;
        vector<vector<int>> ans;
        backtrack(0, nums, current, ans, k, n);
        
        return ans;
    }
};
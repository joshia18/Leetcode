class Solution {
public:
    void helper(int index, vector<int>& candidates, int target, vector<int> &current, vector<vector<int>> &ans){
        if(target < 0) return;
        
        if(target == 0){
            ans.push_back(current);
            return;
        }
        
        for(int i = index; i < candidates.size(); i++){
            if(i == index || candidates[i] != candidates[i-1]){
                current.push_back(candidates[i]);
                helper(i+1, candidates, target - candidates[i], current, ans);
                current.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        
        vector<int> current;
        
        //sorting is important here as the input array contains duplicates
        sort(candidates.begin(), candidates.end());
        
        helper(0, candidates, target, current, ans);
        
        return ans;
    }
};
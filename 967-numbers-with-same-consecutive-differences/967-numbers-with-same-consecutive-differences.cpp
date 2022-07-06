class Solution {
public:
    void helper(int i, int n, int k, vector<int> &ans){
        if(n == 0){
            ans.push_back(i);
            return;
        }
        
        int lastnum = i%10;
        
        if(lastnum + k < 10){
            helper(i * 10 + (lastnum+k), n-1, k, ans);
        }
        
        //if k == 0 only one of the recursive calls should be called
        if(k > 0 && lastnum-k >= 0){
            helper(i * 10 + (lastnum-k), n-1, k, ans);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        
        //unorderd_map<string, int> dp;
        
        for(int i = 1;i <= 9; i++){
            helper(i, n-1, k, ans);
        }
        
        return ans;
    }
};
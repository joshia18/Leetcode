class Solution {
public:
    int dfs(int index, vector<int>& jobDifficulty, vector<vector<int>> &dp, int d){
        //if d == 1, there can be only partition that is the whole array, so return the max element in the array
        if(d == 1){
            int maxi = 0;
            
            //don't forget this we have to traverse using the given index
            while(index < jobDifficulty.size()){
                maxi = max(maxi, jobDifficulty[index]);
                index++;
            }
            
            return maxi;
        }
        
        if(dp[index][d] != -1) return dp[index][d];
        
        int maxi = 0;
        int res = INT_MAX;
        
        //-d+1 is applied because while checking all the possibilities, if we take idx = 5 as first cut and remaining d = 4, 
        //we should have enough room in the array o make the remaining cuts also
        
        for(int i = index; i < jobDifficulty.size()-d+1; i++){
            
            maxi = max(maxi, jobDifficulty[i]);
            
            //i+1 here
            res = min(res, maxi + dfs(i+1, jobDifficulty, dp, d-1));
            
        }
        
        return dp[index][d] = res;
        
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        //the intuition behind this problem is like minimum cost to cut a stick, partitioning dp
        //we try making d number of cuts in each index to see, if the subarrays with cuts made has maximum elements that gives minimum sum
        //memoization is applied with the dp array, time complexity is o(n*n*d)
        
        //negative case
        if(d > jobDifficulty.size()) return -1;
        
        int n =  jobDifficulty.size();
        
        vector<vector<int>> dp(n, vector<int>(d+1, -1));
        
        return dfs(0, jobDifficulty, dp, d);
        
    }
};
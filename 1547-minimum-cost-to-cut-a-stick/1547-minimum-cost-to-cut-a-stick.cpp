class Solution {
public:
    unordered_map<string, int> mp;
    
//     int helper(vector<int>& cuts, int i, int j){
//         if(i > j) return 0;
        
//         string key = to_string(i) + "," + to_string(j);
//         if(mp.find(key) != mp.end()) return mp[key];
        
//         int mincost = INT_MAX;
//         for(int k = i; k <= j; k++){
//             int cost = (cuts[j+1] - cuts[i-1]) + helper(cuts, i, k-1) + helper(cuts, k+1, j);
//             mincost = min(mincost, cost);
//         }
        
//         return mp[key] = mincost;
//     }
    
    int minCost(int n, vector<int>& cuts) {
        //using partition recursiion
        
        int c = cuts.size();
        cuts.push_back(n);
        //cuts.insert(cuts.begin(), 0); as anyways we are sorting
        cuts.push_back(0);
        
        //don't forget to sort the array for this kind of partition problems
        //the time complexity of complete recursion solution is exponential 2^n
        //we can do memoization, for this problem memoization with key as i and j gives TLE
        //TC of memoizatin soln is o(cuts.size()^3), because i & j each having states of cuts.size() and a for loop inside
        
        sort(cuts.begin(), cuts.end());
        
        //tabulation is alos still o(n^3) time complexity
        vector<vector<int>> dp(c+2, vector<int>(c+2, 0));
        
        for(int i = c; i >= 1; i--){
            for(int j = 1; j <= c; j++){
                
                if(i > j) continue;
                
                int mincost = INT_MAX;
                
                for(int k = i; k <= j; k++){
                    int cost = (cuts[j+1] - cuts[i-1]) + dp[i][k-1] + dp[k+1][j];
                    mincost = min(mincost, cost);
                }

                dp[i][j] = mincost;
            }
        }
        
        return dp[1][c];
    }
};
class Solution {
public:
    
    int helper(int i, int j, vector<vector<int>> &mem){
        if(i == 0 && j == 0){
            return 1;
        }
        
        if(i < 0 || j < 0) return 0;
        
        if(mem[i][j] != -1) return mem[i][j];
        
        int up = helper(i-1, j, mem);
        int left = helper(i, j-1, mem);
        
        return mem[i][j] = up + left;
    }
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> mem(m, vector<int>(n, -1));
        return helper(m-1, n-1, mem);
    }
};
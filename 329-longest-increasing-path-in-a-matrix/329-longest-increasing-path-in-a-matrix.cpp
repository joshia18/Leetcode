class Solution {
public:
    int liphelper(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& mem){
        
        if(mem[i][j] != -1) return mem[i][j];
        
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        int max_inc_path  = 0;
        
        for(auto k : dir){
            int p = k[0] + i;
            int q = k[1] + j;
            
            if(p >= 0 && q >= 0 && p < matrix.size() && q < matrix[0].size() && matrix[p][q] > matrix[i][j]){
                max_inc_path = max(max_inc_path, liphelper(matrix, p, q, mem));
            }
        }
        
        return mem[i][j] = 1 + max_inc_path;
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        if(!rows) return 0;
        int cols = matrix[0].size();
        
        int max_path = 0;
        
        vector<vector<int>> mem(rows, vector<int>(cols, -1));
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                max_path = max(max_path, liphelper(matrix, i, j, mem));
            }
        }
        
        return max_path;
        
    }
};
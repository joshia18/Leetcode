class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        
        int r = matrix.size(), c = matrix[0].size();
        
        int count = 0;
        
        for(int i = 0 ; i < r; i++){
            for(int j = 0; j < c; j++){
                if(matrix[i][j] > 0 && i > 0 && j > 0){
                    matrix[i][j] = 1 + min({matrix[i-1][j-1], matrix[i-1][j], matrix[i][j-1]});
                }
                
                count += matrix[i][j];
            }
        }
        
        return count;
    }
};
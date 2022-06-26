class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //inplace dp like without using extra space for visited
        int r = mat.size(), c = mat[0].size();
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(mat[i][j] > 0){
                    int top = i-1 >= 0 ? mat[i-1][j] : 1e6;
                    int left = j-1 >= 0 ? mat[i][j-1] : 1e6;

                    mat[i][j] = 1 + min(top, left);
                }
            }
        }
        
        for(int i = r-1; i >= 0; i--){
            for(int j = c-1; j >= 0; j--){
                int right = i+1 < r ? mat[i+1][j] : 1e6;
                int bottom = j+1 < c ? mat[i][j+1] : 1e6;
                
                mat[i][j] = min(mat[i][j], min(right, bottom)+1);
            }
        }
        
        return mat;
    }
};
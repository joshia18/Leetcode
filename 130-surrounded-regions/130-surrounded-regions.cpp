class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O') return;
        
        board[i][j] = 'A';
        
        dfs(board, i+1, j);
        dfs(board, i-1, j);
        dfs(board, i, j+1);
        dfs(board, i, j-1);
        
    }
    
    void solve(vector<vector<char>>& board) {
        int r = board.size(), c = board[0].size();
        
        if(r <= 2) return;
        if(c <= 2) return;
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(i == 0 || j == 0 || i == r-1 || j == c-1){
                    if(board[i][j] == 'O'){
                        //in this dfs, all the O's which are connected to the O's in the border will be flipped to A
                        dfs(board, i, j);
                    }
                }
            }
        }
            
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(board[i][j] == 'A') board[i][j] = 'O';
                else if(i != 0 && j != 0 && i != r-1 &&  j != c-1 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};

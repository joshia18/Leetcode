class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> hasedge(n+1, vector<bool>(n+1, false));
        vector<int> numofedges(n+1, 0);
        
        for(auto i : edges){
            
            int u = i[0], v = i[1];
            
            hasedge[u][v] = true; hasedge[v][u] = true;
            
            numofedges[u]++;
            numofedges[v]++;            
        }
        
        int res = INT_MAX, degree = 0;
        
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                if(!hasedge[i][j]) continue;
                for(int k = j+1; k <= n; k++){
                    
                    if(hasedge[i][j] && hasedge[j][k] && hasedge[k][i]){
                        degree = (numofedges[i] + numofedges[j] + numofedges[k]) - 6;
                        //specify res here not outside this if block
                        res = min(degree, res);
                    }
                }
            }
        }
        
        return res == INT_MAX ? -1 : res;
    }
};
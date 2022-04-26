class Solution {
public:
    long long dp[100001][4][3];
    
    long long helper(string &s, int index, int selection, int prevBuilding){
        
        if(selection == 0){
            return 1;
        }
        
        if(index >= s.size()){
            return 0;
        }
        
        if(dp[index][selection][prevBuilding+1] != -1) return dp[index][selection][prevBuilding+1];
        
        //condition is previous building should not be equal to the current building
        if(s[index] - '0' != prevBuilding){
            //i will select it (selection-1) and update the previous building or not select it (selection) and leave the previous building as it is
            return dp[index][selection][prevBuilding+1] = helper(s, index+1, selection-1, s[index] - '0') + helper(s, index+1, selection,prevBuilding);
        }
        else{
            return dp[index][selection][prevBuilding+1] = helper(s, index+1, selection, prevBuilding);
        }
        
        return 0;
        
    }
    
    
    long long numberOfWays(string s) {
        for(int i = 0; i < 100001; i++){
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 3; k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        
        //string, index, no of selections = 3, prev building selected
        //index can have values from 3 to 10^5, selection can take only values 1,2,3 and prevBuilding can take -1, 0, 1
        return helper(s, 0, 3, -1);
    }
};
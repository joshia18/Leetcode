class Solution {
public:
    int minDistance(string str1, string str2) {
        int len1 = str1.size(), len2 = str2.size();
	    
	    vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
	    
	    for(int i = 1; i <= len1; i++){
	        for(int j = 1; j <= len2; j++){
	            if(str1[i-1] == str2[j-1]){
	                dp[i][j] = 1 + dp[i-1][j-1];
	            }
	            else{
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	            }
	        }
	    }
	    
	    int lcslen = dp[len1][len2];
	    
	    return len1 + len2 - (2*lcslen);
    }
};
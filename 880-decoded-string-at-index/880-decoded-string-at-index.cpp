class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long size = 0;
        
        int n = s.length();
        
        for(int i = 0; i < n; i++){
            char c = s[i];
            
            if(isdigit(c)) size *= (c - '0');
            else size++;
        }
        
        string ans = "";
        
        for(int i = n-1; i >= 0; i--){
            k %= size;
            
            char c = s[i];
            
            if(k == 0 && !isdigit(c)){
                return ans + c;
            }
            
            if(isdigit(c)){
                size /= (c - '0');
            }
            else{
                size--;
            }
        }
        
        
        return "";
    }
};
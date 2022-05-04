class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> chars(58, 0);
        
        for(char c : t){
            chars[c - 'A']++;
        }
        
        int start = 0, end = 0;
        int i = 0, j = INT_MAX;
        int diff = t.size();
        
        for(end = 0; end < s.size(); end++){
            char c = s[end];
            
            chars[c - 'A']--;
            
            if(chars[c - 'A'] >= 0){
                diff--;
            }
            
            //if diff becomes zero
            while(diff == 0){
                
                if(end-start+1 < j-i){
                    i = start;
                    j = end+1;
                }
                
                char d = s[start];
                
                chars[d - 'A']++;
                
                //here > 0
                if(chars[d - 'A'] > 0) diff++;
                
                start++;
                
            }
        }
        
        string res = "";
        if(j != INT_MAX) {
            res = s.substr(i, j-i);
            return res;
        }
        
        return "";
    }
};
class Solution {
public:
    string leftjustify(vector<string>& words, int i, int j, int diff){
        string ans = words[i];
        
        int spacesonright = diff - (j - i - 1);
        
        for(int k = i+1; k < j; k++){
            ans += " " + words[k];
        }
        
        while(spacesonright--) ans += " ";
        
        return ans;
    }
    
    string middlejustify(vector<string>& words, int i, int j, int diff){
        string ans = words[i];
        
        int spaces = diff / (j-i-1);
        int extraspaces = diff % (j-i-1);
        
        for(int k = i+1; k < j; k++){
            int spacestoapply = spaces + ((extraspaces-- > 0) ? 1 : 0);
            
            while(spacestoapply--) ans += " ";
            
            ans += words[k];
        }
        
        return ans;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        //solved using two pointer method
        vector<string> ans;
        
        if(words.size() == 0) return ans;
        
        int i = 0, linelength = 0, n = words.size();
        
        //j - i - 1 means number of spaces between words from i to j
        //j - i means number of words
        //diff -> number of spaces to apply in the line including the spaces between words
        
        while(i < n){
            int j = i+1;
            
            linelength = words[i].size();
            
            while(j < n && linelength + words[j].size() + (j - i - 1) < maxWidth){
                linelength += words[j].size();
                j++;
            }
            
            int diff = maxWidth - linelength;
            int numOfWords = j - i;
            
            if(numOfWords == 1 || j >= n){
                //if the number of words == 1 or j gone out of bounds which means we are at forming the last line which has to left justified
                ans.push_back(leftjustify(words, i, j, diff));
            }
            else{
                ans.push_back(middlejustify(words, i, j, diff));
            }
            
            i = j;
        }

        return ans;
    }
};
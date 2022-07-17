class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.size() >= str2.size()){
            swap(str1, str2);
        }
        
        if(str1.compare(str2) == 0) return str1;
        else if(str1.size() == str2.size()) return "";
        
        string ans = str1;
        
        int len = ans.size();
        
        while(!ans.empty()){
            int i = 0;
            
            while(i+len <= str2.size()){
                string temp = str2.substr(i, len);
                if(ans.compare(temp) == 0){
                    i = i+len;
                }
                else{
                    break;
                }
            }
            
            int j = 0;
            
            while(j+len <= str1.size()){
                string temp = str1.substr(j, len);
                if(ans.compare(temp) == 0){
                    j = j+len;
                }
                else{
                    break;
                }
            }
            
            if(i == str2.size() && j == str1.size()) return ans;
            
            len--;
            ans = ans.substr(0, len);
        }
        
        return ans;
        
    }
};
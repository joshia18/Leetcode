class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        
        for(int i = 1; i < words.size();){
            string a = words[i];
            string b = words[i-1];
            
            //instead of sorting we can use ordered map also looks like that is not that faster
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            
            if(a == b){
                words.erase(words.begin()+i);
            }
            else{
                i++;
            }
        }
        
        return words;
    }
};
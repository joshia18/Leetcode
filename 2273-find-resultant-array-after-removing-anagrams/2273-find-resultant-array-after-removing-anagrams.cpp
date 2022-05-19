class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        
        for(int i = 1; i < words.size();){
            map<char, int> a, b;
            
            for(char c : words[i]){
                a[c]++;
            }
            
            for(char c : words[i-1]){
                b[c]++;
            }
            
            //instead of sorting we can use ordered map also
            // sort(a.begin(), a.end());
            // sort(b.begin(), b.end());
            
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
class Solution {
public:
    bool comparetwowords(string word1, string word2, unordered_map<char, int> &charmap){
        int l1 = word1.size(), l2 = word2.size();
        
        for(int i = 0; i < min(l1, l2); i++){
            if(word1[i] == word2[i]) continue;
            
            if(charmap[word1[i]] < charmap[word2[i]]){
                return true;
            }
            else{
                return false;
            }
        }
        
        return l1 <= l2;
        
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        
        if(words.size() < 2) return true;
        
        unordered_map<char, int> charmap;
        
        for(int i = 0; i < order.size(); i++){
            charmap[order[i]] = i;
        }
        
        //compare every two adjacent words
        for(int i = 0; i < words.size()-1; i++){
            if(!comparetwowords(words[i], words[i+1], charmap)){
                return false;
            }
        }
        
        return true;
        
    }
};
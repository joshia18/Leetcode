class Solution {
public:
    bool cancompose(string word, unordered_set<string> &wordset){
        if(word.size() == 0) return false;
        
        //remove the given word from wordset
        wordset.erase(word);
        
        //create 1d dp array
        vector<bool> dp(word.size()+1, false);
        
        //important to make dp[0] = true
        dp[0] = true;
        
        for(int i = 1; i <= word.size(); i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && wordset.find(word.substr(j, i-j)) != wordset.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        
        //add the wprd back into the wordset
        wordset.insert(word);
        
        return dp[word.size()];
        
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> wordset;
        
        for(string s : words){
            wordset.insert(s);
        }
        
        vector<string> res;
        
        for(string s : words){
            if(cancompose(s, wordset)){
                res.push_back(s);
            }
        }
        
        return res;
    }
};
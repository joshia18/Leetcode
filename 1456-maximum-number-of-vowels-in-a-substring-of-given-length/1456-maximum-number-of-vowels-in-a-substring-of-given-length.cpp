class Solution {
public:
    int maxVowels(string s, int k) {
        int left = 0, right = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        int ans = 0, count = 0;
        
        while(right < s.size()){
            
            int len = right - left + 1;
            
            if(len > k){
                char c = s[left];
                if(vowels.find(c) != vowels.end()) count--;
                left++;
            }
            
            char c = s[right];
            
            if(vowels.find(c) != vowels.end()){
                count++;
            }
            
            ans = max(ans, count);
            
            right++;
        }
        
        return ans;
    }
};
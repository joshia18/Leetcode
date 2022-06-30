class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        //don' miss curly brackets for map.insert
        mp.insert({'I',1});
        mp.insert({'V',5});
        mp.insert({'X',10});
        mp.insert({'L',50});
        mp.insert({'C',100});
        mp.insert({'D',500});
        mp.insert({'M',1000});
        
        int n = s.length();
        
        int ans = mp[s[n-1]];
        //assigned last character number in the string to ans
        //as roman leeters are from largetst to smallest(left to right)
        //if value at i+1 is larger than i, then we subtract
        //eg: IV.. i = 'I' and i+1 = 'V' I > V. so ans = ans - S[i] = 5 -1 = 4
        
        for(int i = n-2; i >= 0; i--){
            if(mp[s[i+1]] > mp[s[i]]){
                ans = ans - mp[s[i]];
            }
            else{
                ans = ans + mp[s[i]];
            }
        }
        
        
        
        return ans;
    }
};
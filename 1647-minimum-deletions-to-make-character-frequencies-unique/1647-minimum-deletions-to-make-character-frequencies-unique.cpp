class Solution {
public:
    int minDeletions(string s) {
        int ans = 0;
        
        vector<int> freq(26, 0);
        
        for(char  i : s) freq[i - 'a']++;
        
        //sorted in descending order of frequency
        sort(freq.begin(), freq.end(), greater<int>());
        
        //start traversing the zeroth element of the array
        //condition is values values only with the value of maxi should exist in the array
        //if a value equal to maxi is present, decrease that value, assign that value to maxi OR decrement one from maxi(because the maxi value is used)
        //if a value greater than maxi is present decrement the value to equal maxi, then decremetn maxi(because the maxi value is used)
        //if a value lesser than maxi is present, then assign that value to maxi and loop through
        
        int maxi = freq[0];
        
        //for(int i : freq) cout << i << " ";
        
        int i = 0;
        
        for(int ele : freq){
            
            if(ele > maxi){
                
                //if maxi is > 0 or <= o
                if(maxi > 0) ans += (ele - maxi);
                else ans += ele;
                
            }
            
            maxi = min(maxi-1, ele-1);
            
        }
        
        
        return ans;
    }
};
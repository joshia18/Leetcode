class Solution {
public:
    int minimumDeletions(string s) {
        //naresh video
        int n = s.size();
        
        vector<int> no_of_a(n,0);
        
        //traversing from n-2 to store the number of a's available after b in each index
        
        no_of_a[n-1] = s[n-1] == 'a' ? 1 : 0;
        
        for(int i = n-2; i >= 0; i--){
            no_of_a[i] = no_of_a[i+1] + (s[i] == 'a' ? 1 : 0);
        }
        
        //for(int i : no_of_a) cout << i << " ";
        
        int ans = INT_MAX;
        
        int bcount = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'b'){
                ans = min(ans, bcount + no_of_a[i]);
                bcount++;
            }
        }
        
        ans = min(ans, bcount);
        
        return ans == INT_MAX ? 0 : ans;
    }
};
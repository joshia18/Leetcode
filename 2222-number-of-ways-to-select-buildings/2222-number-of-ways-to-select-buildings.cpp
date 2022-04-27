class Solution {
public:
     
    long long numberOfWays(string s) {
        //this iterative way is based on the fact that there can be only two combinations possible 010 and 101
        //whenever we see 1 we check number of zeros after that and before that then ans += before*after
        //whenever we see 0 we check number of ones after that and before that then ans += before*after
        int n = s.size();
        vector<int> pre(n);
        vector<int> suf(n);
        
        int count = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                count++;
            }
            
            pre[i] = count;
        }
        count = 0; cout << endl;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '0'){
                count++;
            }
            
            suf[i] = count;
        }
        
        long long ans = 0;
        
        for(int i = 1; i < n-1; i++){
            if(s[i] == '1'){
                long long before = pre[i];
                long long after = suf[i];
                
                ans += before*after;
            }
            else{
                long long before = i+1 - pre[i];
                long long after = (n-i) - suf[i];
                
                ans += before*after;
            }
        }
        
        return ans;
    }
};
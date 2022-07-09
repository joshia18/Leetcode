class Solution {
public:
    int mod = 1e9+7;
    int numWays(string s) {
        //if there is all 0s in string we have to return (n-1)C2 => (n-1)*(n-2)/1*2 => 3 non-empty string means we have to make two cuts
        //nc2 means how many ways we can make 2 cuts out of n-1 spaces
        //cuts1 and cuts2 represents number of ways we can make 1s cut and no of ways we can make 2nd cut
        
        //keep all of them in long as the answer can be huge
        long ones = 0;
        long n = s.size();
        
        for(char &c : s){
            if(c == '1') ones++;
        }
        
        if(ones == 0) return (int)(((n-1)*(n-2)/2)%mod);
        
        if(ones%3 != 0) return 0;
        
        int onethird = (int)ones/3;
        ones = 0;
        long cuts1 = 0, cuts2 = 0;
        
        for(char &c : s){
            //these three statements should be very important and continuous
            ones += c - '0';
            if(ones == onethird) cuts1++;
            if(ones == 2*onethird) cuts2++;
        }
        
        return (int)((cuts1*cuts2)%mod);
        
    }
};
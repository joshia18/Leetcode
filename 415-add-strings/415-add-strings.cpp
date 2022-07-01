class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.length() - 1;
        int n = num2.length() - 1;
        
        string ans = "";
        //initially carry  = 0
        //first step in whie loop is very important
        int carry = 0;
        
        while(m >= 0 || n >= 0 || carry > 0){
            //sum declared here with because we are adding number by number from last of each string
            int sum = carry;
            //add numbers in num1 and num2 separately to the sum
            
            if(m >= 0){
                sum += (num1[m] - '0');
            }
            
            if(n >= 0){
                sum += (num2[n] - '0');
            }
            
            carry = sum / 10;
            
            char c = (sum%10) + '0';
            
            ans += c;
            
            m--;
            n--;
            
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans.length() == 0 ? "0" : ans;
    }
};
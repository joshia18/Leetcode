class Solution {
public:
    double myPow(double x, int n) {
        //done using binary exponentation
        //if n is negative, we can convert it into positive, then power can be found by 1/x^n
        //if n = -2^31, when we convert it into positive, int datatype cannot hold its value so long is required
        //this problem is solved using the fact that if we have to do 2^10,
        //instead of multiplying 2 ten times, we can do 4^5 times as (2^2)^5 == 2^10
        
        double ans = 1;
        long nn = n;
        if(n < 0) nn *= -1;
        
        //run the loop as long as nn > 0
        while(nn > 0){
            if(nn%2 == 0){
                x = x*x;
                nn = nn/2;
            }
            else{
                ans *= x;
                nn = nn-1;
            }
        }
        
        if(n < 0) return (double)(1.0/ans);
        
        return ans;
    }
};
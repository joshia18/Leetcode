class Solution {
public:
    int maximumSwap(int num) {
        //we are not converting it to string and make the swaps, swaps are done using a arithmetic formula
        //we traverse from right to left, with two pointers left and right and keep two variables left digit and right digit, left digit initialized to -1
        //max pointer and max digit variable will keep the location and  tha value of the maximum digit
        //if we found a value lesser than maximum value, then it is possible candidate for swapping
        //so, keep left pointer in that lesser value location and right pointer in max value location and swap it using the formula
        //if the given number is already sorted descending, left digit will be equal to -1 at the end so return the same number
        
        int max_digit = -1, max_loc = -1, left_digit = -1, left_loc = 0, right_loc = 0, right_digit = 0;
        
        //run as long as n is nt equal to zero
        for(int i = 0, n = num; n; n=n/10, i++){
            int currentvalue = n%10;
            
            if(currentvalue > max_digit){
                max_digit = currentvalue;
                max_loc = i;
            }
            else if(currentvalue < max_digit){
                left_digit = currentvalue;
                left_loc = i;
                right_digit = max_digit;
                right_loc = max_loc;
            }
        }
        
        if(left_digit == -1) return num;
        
        //arithmetic formula for swapping
        return num - (left_digit - right_digit) * (int)pow(10, left_loc) + (left_digit - right_digit) * (int)pow(10, right_loc);
        
    }
};
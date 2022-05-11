class Solution {
public:
    int minFlipsMonoIncr(string s) {
        //we'll take two variables
        
        int noofones = 0;
        int changes = 0;
        
        //no of ones will record the number of ones, and changes will record no of zeros which are occuring after 1, minimum of those two will be the answer
        
        for(char c : s){
            
            if(c == '1'){
                noofones++;
            }
            else{
                if(noofones > 0) changes++;
            }
            
            changes = min(changes, noofones);
            
        }
        
        return changes;
    }
};
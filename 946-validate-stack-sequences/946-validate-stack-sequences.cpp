class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        //another solution without using the stack ds
        //we achieved constant space by using and modifying the pushed input array itseld
        
        int i = 0, j = 0;
        
        for(int &x : pushed){
            pushed[i++] = x;
            
            while(i > 0 && pushed[i-1] == popped[j]){
                i--;
                j++;
            }
        }
        
        return i == 0;
    }
};
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        //initialize the char answer to any char value
        
        char ans = keysPressed[0];
        
        //initialize timetaken to 0th releasetime
        int timetaken = releaseTimes[0];
        
        for(int i = 1; i < keysPressed.size(); i++){
            
            int duration = releaseTimes[i] - releaseTimes[i-1];
            
            if(duration == timetaken){
                //max(ans, keysPressed[i]) to get the lexicographically largest char from keysPressed string
                timetaken = duration;
                ans = max(ans, keysPressed[i]);
            }
            
            //we are checking duration > already taken duration because we are asked for the longest duratio keypress
            if(duration > timetaken){
                timetaken = duration;
                ans = keysPressed[i];
            }
            
        }
        
        return ans;
    }
};
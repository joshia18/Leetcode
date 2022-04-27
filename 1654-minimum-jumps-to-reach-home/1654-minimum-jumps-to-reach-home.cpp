class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_map<int, bool> mp;
        
        if(x == 0) return 0;
        
        for(int i : forbidden){
            mp[i] = true;
        }
        
        //pait.first stores the jump distance, pair.second stores if it is a forward jump or backward jump -> 0 means forward, 1 means backward
        queue<pair<int, int>> q;
        q.push({0,0});
        int jumps = 0;
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                auto current = q.front();
                q.pop();
                
                if(current.first == x){
                    return jumps;
                }
                
                //do not visit the already visited position
                if(mp[current.first] == true) continue;
                
                mp[current.first] = true;
                
                //move backward only if the last move was forward, can't make backward move twice in a row
                //order of the steps matter here, so placed backward step's if condition before forward step's if
                //it is like as soon as you can make a backward move you can do it
                if(current.first-b >= 0 && current.second == 0){
                    q.push({current.first-b, 1});
                }
                
                if(current.first <= 2000+b){
                    q.push({current.first+a, 0});
                }
                
            }
            
            //increment jumps
            jumps++;
        }
        
        return -1;
    }
};
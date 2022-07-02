class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i = 0;
        
        priority_queue<int> pq;
        
        //if we use bricks to climb a building we should save the amount of bricks used to priority queue
        //in future checks, if we need less number of bricks to climb a building than the number of bricks used before, we can regain those bricks from priority queue and replace that one with a ladder
        
        for(; i < heights.size() - 1; i++){
            
            if(heights[i] >= heights[i+1]) continue;
            int diff = heights[i+1] - heights[i];
            
            if(diff <= bricks){
                bricks -= diff;
                //have to push diff only all the time, because that is the number of bricks required
                pq.push(diff);
            }
            else if(ladders > 0){
                if(!pq.empty()){
                    int x = pq.top();
                    
                    //lesser number of bricks than the number of bricks used before
                    if(diff < x){
                        bricks += x;
                        bricks -= diff;
                        pq.pop();
                        pq.push(diff);
                    }
                }
                
                ladders--;
            }
            //this is an important condition
            else{
                break;
            }
            
        }
        
        return i;
        
    }
};
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        //can be solved using priority queue
        
        int max_you_reach = startFuel;
        
        int index = 0, count = 0;
        
        //max heap
        priority_queue<int> pq;
        
        //once we reach target destination we are done
        while(max_you_reach < target){
            
            while(index < stations.size() && stations[index][0] <= max_you_reach){
                pq.push(stations[index][1]);
                index++;
            }
            
            //if any case we do not have any element in priority queue, we cannot move forward, so return -1
            if(pq.empty()) return -1;
            
            count++;
            
            max_you_reach += pq.top();
            pq.pop();
            
        }
        
        return count;
    }
};
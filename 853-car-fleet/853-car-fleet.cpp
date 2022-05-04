class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        //tuple: distance from target, speed, time to reach target
        vector<tuple<int, int, double>> cars;
        
        for(int i = 0; i < position.size(); i++){
            
            int disfromtarget = target - position[i];
            
            cars.push_back({disfromtarget, speed[i], (1.0*disfromtarget/speed[i])});
        }
        
        sort(cars.begin(), cars.end());
        
        auto [d, s, t] = cars[0];
        
        int fleets = 1;
        double currtime = t;
        
        for(auto i : cars){
            auto [disfromtarget, speed, time] = i;
            
            if(time > currtime){
                fleets++;
                currtime = time;
            }
        }
        
        return fleets;
    
    }
};
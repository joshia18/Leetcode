class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        
        long pmass = mass;
        
        for(int i : asteroids){
            if(pmass >= i){
                pmass += i;
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};
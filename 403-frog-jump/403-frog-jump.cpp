class Solution {
public:
    int last;
    bool helper(int element, int lastjump, map<int, int> &mp1, map<pair<int, int>, int> &mp2){
        if(element == last){
            return true;
        }
        
        if(mp2.find({element, lastjump}) != mp2.end()) return mp2[{element, lastjump}];
        
        //if the lastjump is 0 or less than 0, it might result in frog going backwards in helper(element+lastjump-1, lastjump-1, mp1, mp2)
        //if it is negative, frog will go backwards in helper(element+lastjump, lastjump, mp1, mp2)
        if(lastjump <= 0 || element > last) return false;
        
        if(mp1[element]){
            return mp2[{element, lastjump}] = helper(element+lastjump, lastjump, mp1, mp2) || helper(element+lastjump-1, lastjump-1, mp1, mp2)                                               || helper(element+lastjump+1, lastjump+1, mp1, mp2);
        }
        else{
            return false;
        }
    }
    
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        //last stores the last element in the given sorted array
        last = stones[n-1];
        map<int, int> mp1;
        map<pair<int, int>, int> mp2;
        
        for(int i : stones) mp1[i] = 1;
        
        if(stones[1] == 1) return helper(1,1,mp1, mp2);
        
        return false;
    }
};
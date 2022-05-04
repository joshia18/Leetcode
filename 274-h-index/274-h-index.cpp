class Solution {
public:
    static bool comp(int &a, int& b){
        return a > b;
    }
    
    int hIndex(vector<int>& citations) {
        //nlogn complexity can be achived by sorting, but can be done in o(n) also
        
        //sorted in descending order
        sort(citations.begin(), citations.end(), comp);
        
        if(citations.size() == 1){
            if(citations[0] >= 1) return 1;
            return 0;
        }
        
        int ans = 0;
        
        for(int i = 1; i <= citations.size(); i++){
            if(citations[i-1] < i) return i-1;
        }
        
        return citations.size();
    }
};
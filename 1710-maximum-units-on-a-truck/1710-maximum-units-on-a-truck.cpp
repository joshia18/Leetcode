struct comp{
    bool operator()(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }
};

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        //sort the boxTypes 2d array as per the decreasing number of units
        
        sort(boxTypes.begin(), boxTypes.end(), comp());
        
        //for(auto &i : boxTypes) cout << i[0] << " " << i[1] << ", ";
        
        cout << endl;
        
        int maxunits = 0;
        
        int i = 0;
        
        while(truckSize > 0 &&  i < boxTypes.size()){
            
            int noofboxes = boxTypes[i][0];
            int noofunits = boxTypes[i][1];
            
            if(truckSize > noofboxes){
                maxunits += (noofboxes * noofunits);
                truckSize -= noofboxes;
            }
            else{
                maxunits += (truckSize * noofunits);
                truckSize = 0;
            }
            
            i++;
        }
        
        return maxunits;
    }
};
struct passenger{
    string startcity;
    int id;
    int time;
    
    passenger(int pid, string city, int t){
        startcity = city;
        id = pid;
        time = t;
    }
};

class UndergroundSystem {
public:
    unordered_map<int, passenger*> pasdetails;
    //here key string would be "startstation,endstation"
    //vector<int> will store only two values vector[0] = duration of each journey and vector[1] = no of journeys done from a source to end and 
    unordered_map<string, vector<int>> counts;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        passenger* p = new passenger(id, stationName, t);
        pasdetails.insert({id, p});
    }
    
    void checkOut(int id, string stationName, int t) {
        if(pasdetails.find(id) != pasdetails.end()){
            string start = pasdetails[id]->startcity;
            int starttime = pasdetails[id]->time;
            int totaltime = t - starttime;
            
            string key = start + "," + stationName;
            
            if(counts.find(key) == counts.end()){
                counts.insert({key, {totaltime, 1}});
            }
            else{
                int total = counts[key][0] + totaltime;
                int count = counts[key][1] + 1;
                
                counts.erase(key);
                counts.insert({key, {total, count}});
            }
            
            pasdetails.erase(id);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "," + endStation;
        //cout << key << " " << counts[key][0] << " " << counts[key][1] << endl;
        return (double)counts[key][0] / counts[key][1];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
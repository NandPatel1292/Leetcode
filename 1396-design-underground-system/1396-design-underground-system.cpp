class UndergroundSystem {
public:
    map<int,pair<string,int>> in;
    map<string,pair<int,int>> out;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto inStation = in[id];
        string s = inStation.first + "-" + stationName;
        int duration = t -  inStation.second;
        out[s].first += duration;
        out[s].second++;
        in.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string s = startStation + "-" + endStation;
        auto x = out[s];
        double ans = (double)x.first/x.second;
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
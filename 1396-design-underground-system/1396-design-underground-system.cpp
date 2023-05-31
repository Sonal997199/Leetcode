class UndergroundSystem {
public:
    unordered_map<string,pair<long long,int>> mp;
    unordered_map<int,pair<string,int>> mp2;
    UndergroundSystem() {
        mp.clear();
        mp2.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        if(mp2.find(id)!=mp2.end())return;
        mp2[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto& info=mp2[id];
        string startStation=info.first;
        int startTime=info.second;
        string key=startStation+":"+stationName;
        int time=t-startTime;
        
        if(mp.find(key)!=mp.end())
        {
            auto& oldTimes=mp[key];
            oldTimes.first+=time;
            oldTimes.second++;
        }
        else
        {
            mp[key]={time,1};
        }
        mp2.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key=startStation+":"+endStation;
        auto& info=mp[key];
        double avg=(double)info.first/(double)info.second;
        return avg;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
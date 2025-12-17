class UndergroundSystem {
public:
    map<string, map<string, vector<int>>> graph;
    map<int, pair<string, int>> customers;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        customers[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        if(customers.find(id) == customers.end()) {
            cout << "Customer not found";
            return;
        }

        string start_station = customers[id].first;
        int start_time = customers[id].second;

        graph[start_station][stationName].push_back(t - start_time);
        customers.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        if(graph.find(startStation) == graph.end()) return -1.0;

        vector<int>& times = graph[startStation][endStation];

        double sum = 0.0;
        double n = (double) times.size();
        for(int x : times) {
            sum += (double)x;
        }

        return sum / n;
        
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
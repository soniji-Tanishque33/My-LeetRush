class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,  value});
    }
    
    string get(string key, int timestamp) {
        string ans = "";
        auto& v = mp[key];
        int res = -1;
        int l = 0;
        int r = v.size()-1;
        while(l <= r) {
            int mid = (l+r) / 2;
            if(v[mid].first <= timestamp) {
                res = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return res == -1 ? "" : v[res].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
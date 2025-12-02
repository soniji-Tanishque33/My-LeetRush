class LRUCache {
public:
    int cap;
    int time;
    map<int, pair<int, int>> time_pair_map; // time key val
    unordered_map<int, pair<int, int>> key_pair_map; // key time val
    LRUCache(int capacity) {
        cap = capacity;
        time = 0;
    }
    
    int get(int key) {
        if(key_pair_map.find(key) == key_pair_map.end()) return -1;
        int value = key_pair_map[key].second;
        int initial_time = key_pair_map[key].first;
        key_pair_map[key] = {time, value};
        time_pair_map.erase(initial_time);
        time_pair_map[time] = {key, value};
        time++;

        return value;
    }
    
    void put(int key, int value) {

        if(key_pair_map.find(key) == key_pair_map.end()) {
            
            // erase the least recently used
            if(key_pair_map.size() == cap) {
                int key_to_erase = time_pair_map.begin()->second.first;
                time_pair_map.erase(time_pair_map.begin()->first);
                key_pair_map.erase(key_to_erase);
            }

            time_pair_map[time] = {key, value};
            key_pair_map[key] = {time, value};
        } else {
            // then push the new one
            int initial_time = key_pair_map[key].first;
            key_pair_map[key] = {time, value};
            time_pair_map.erase(initial_time);
            time_pair_map[time] = {key, value};
        }
        time++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
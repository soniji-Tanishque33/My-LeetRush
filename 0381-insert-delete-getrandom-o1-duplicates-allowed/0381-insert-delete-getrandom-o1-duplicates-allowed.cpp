class RandomizedCollection {
public:
    vector<int> v;
    unordered_map<int, set<int>> mp;

    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        // if in the map then increase the freq and return false
        // if not in the map and return true
        if(mp.find(val) == mp.end()) {
            mp[val].insert(v.size());
            v.push_back(val);
            return true;
        } else {
            mp[val].insert(v.size());
            v.push_back(val);
            return false;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val) != mp.end()) {
            set<int>& indices = mp[val];
            if(indices.size() == 0) return false;
            int idx = *indices.begin();
            indices.erase(indices.begin());
            int lastVal = v[v.size()-1];
            v[idx] = lastVal;
            mp[lastVal].erase(v.size()-1);
            if(idx < v.size()-1) {
                mp[lastVal].insert(idx);
            }

            v.pop_back();
            if(indices.empty()) mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int  n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i<= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int u) {
        if(u == parent[u]) return u;
        return parent[u] = findParent(parent[u]);
    }

    void unionbysize(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else if(size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<bool> operational(c+1, true);
        DisjointSet ds(c+1);
        for(vector<int>& conn : connections) {
            ds.unionbysize(conn[0], conn[1]);
        }


        vector<int> ans;

        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> component_heap;
        for (int station = 1; station <= c; ++station) {
            int root = ds.findParent(station);
            component_heap[root].push(station);
        }



        
        for(auto& qu: queries) {
            int type = qu[0];
            int station = qu[1];

            if(type == 1) {
                if(operational[station]) {
                    ans.push_back(station);
                } else {
                    int root = ds.findParent(station);
                    auto& cluster = component_heap[root];
                    bool not_found = true;
                    
                    while(!cluster.empty() && operational[cluster.top()] == false) {
                        cluster.pop();
                    }
                    if(cluster.empty()) {
                        ans.push_back(-1);
                    } else {
                        ans.push_back(cluster.top());
                    }
                }
            } else {
                operational[station] = false;
            }
        }

        return ans;


    }
};
class disjoint_union_find {
    vector<int> size, parent;
    int comp;
public:
    disjoint_union_find(int n) {
        this->comp = n;
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i<=n; i++) {
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
        parent[ulp_u] = ulp_v;
        // implement the size logic if necessary
        comp = comp-1;
        return;
    }

    int count_componants() {
        return this->comp;
    }
};

int total_time = 0;
class Solution {
public:
    bool checkComponants(int n, vector<vector<int>>& edges, int mintime, int k) {
        disjoint_union_find dsu(n);
        for(auto& edge: edges) {
            int time = edge[2];
            if(time > mintime) {
                int u = edge[0];
                int v = edge[1];
                dsu.unionbysize(u, v);
            }
        }

        return dsu.count_componants() >= k;
    }
    
    int minTime(int n, vector<vector<int>>& edges, int k) {
        
        if(edges.size() == 0) {
            if(n >= k) return 0;
        }
        int time = 0;
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        int low = 0;
        int high = edges[edges.size()-1][2];

        while(low <= high) {
            int mid = (low+high)/2;
            bool check = checkComponants(n, edges, mid, k);
            if(check == true) {
                high = mid-1;
            } else  {
                low = mid+1;
            }
        }

        return low;

    }
};
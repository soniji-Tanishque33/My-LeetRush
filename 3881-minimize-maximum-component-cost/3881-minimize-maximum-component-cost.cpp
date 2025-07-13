class DSU {
    vector<int> parent, size;
    int comp;
public:
    DSU(int n) {
        parent.resize(n+1);
        this->comp = n;
        for(int i = 0; i<=n; i++) {
            parent[i] = i;
        }
    }


    int findParent(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    bool unionbysize(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return false;
        comp = comp-1;
        parent[ulp_u] = ulp_v;
        return true;
    }

    int getComponants() {
        return this->comp;
    }
};

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {

        if(edges.size() == 0) {
            if(n <= k) return 0;
        }

        // desending order
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        int low = 0;
        int high = edges[edges.size()-1][2];
        int ans = high;
        while(low <= high) { // check for equality
            DSU dsu(n);
            int mid = (low + high)/2;
            for(auto& edge : edges) {
                if(edge[2] <= mid) {
                    dsu.unionbysize(edge[0], edge[1]);
                }
            }

            int componants = dsu.getComponants();

            if(componants <= k) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return ans;
        
    }
};
class UnionFind {
    vector<int> parent, size;
public:
    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i<n; i++) parent[i] = i;
    }

    int findParent(int x) {
        if(parent[x] == x) return x;
        return findParent(parent[x]);
    }

    void unionbysize(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        return;
    }

    int getSize(int x){
        return size[findParent(x)];
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        UnionFind dsu(n);
        vector<vector<int>> msts;
        vector<vector<int>> nmsts;
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int s = edge[2];
            int must = edge[3];
            if(must == 1) {
                msts.push_back({u, v, s});
            } else {
                nmsts.push_back({s, u, v});
            }
        }

        int mustans = 1e9;
        int nmustans = 1e9;
        for(int i = 0; i<msts.size(); i++) {
            int u = msts[i][0];
            int v = msts[i][1];
            int s = msts[i][2];

            if(dsu.findParent(u) == dsu.findParent(v)) return -1;
            dsu.unionbysize(u, v);
            mustans = min(mustans, s);
        }

        vector<int> nans;
        sort(nmsts.begin(), nmsts.end());
        reverse(nmsts.begin(), nmsts.end());

        for(int i = 0; i<nmsts.size(); i++) {
            int u = nmsts[i][1];
            int s = nmsts[i][0];
            int v = nmsts[i][2];

            if(dsu.findParent(u) == dsu.findParent(v)) continue;
            dsu.unionbysize(u, v);
            nans.push_back(s);
        }

        sort(nans.begin(), nans.end());
        for(int i = 0; i<nans.size(); i++) {
            if(k > 0) {
                nans[i] = nans[i]*2;
                k--;
            }
        }

        sort(nans.begin(), nans.end());

        int finalans = 1e9;
        if(msts.size() > 0) finalans = min(finalans, mustans);
        if(nans.size() > 0) finalans = min(finalans, nans[0]);
        if(dsu.getSize(0) != n) return -1;
        return finalans;
    }
};
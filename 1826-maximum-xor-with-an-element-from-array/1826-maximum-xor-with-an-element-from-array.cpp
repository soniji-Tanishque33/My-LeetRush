struct Node {
    Node* links[2];

    void put(int bit, Node* node ) {
        links[bit] = node;
    }

    bool containsKey(int bit) {
        return links[bit] != NULL;
    }

    Node* getNode(int bit) {
        return links[bit];
    }

};


class Trie {
private: Node* root;
public:
    Trie() {
        root = new Node();
    }


    void insert(int num) {
        Node* node = root;
        for(int i = 31; i>=0; i--) {
            int bit = (num>>i) & 1;
            if(!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node  = node->getNode(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        int maxi = 0;
        for(int i =31; i>=0; i--) {
            int bit = (num>>i) & 1;
            if(node->containsKey(1-bit)) {
                maxi = maxi | (1<<i);
                node = node->getNode(1-bit);
            } else {
                node = node->getNode(bit);
            }
        }

        return maxi;
    }
};

struct offlineQuery {
    int xi;
    int mi;
    int index;

    offlineQuery(int x, int m, int i) {
        this->xi = x;
        this->mi = m;
        this->index = i;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        sort(nums.begin(), nums.end());
        vector<offlineQuery> oQ;
        for(int i = 0; i<queries.size(); i++) {

            oQ.push_back(offlineQuery(queries[i][0], queries[i][1], i));
        }

        sort(oQ.begin(), oQ.end(), [](offlineQuery& a, offlineQuery& b) {
            return a.mi < b.mi;
        });
        vector<int> ans(queries.size(), -1);
        int index = 0;
        for(auto& [x, m, i] : oQ) {
            while(index < nums.size() && nums[index] <= m) {
                trie.insert(nums[index]);
                index++;
            }
            if(index == 0) {
                ans[i] = -1;
            } else {
                int maxi = trie.getMax(x);
                ans[i] = maxi;
            }
        }

        return ans;

    }
};
struct Node {
    Node* links[2];

    void put(int bit, Node* node) {
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
            node = node->getNode(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        int maxi = 0;
        for(int i = 31; i>=0; i--) {
            int bit = (num >> i) & 1;
            if(node->containsKey(1-bit)) {
                maxi= maxi | 1<<i;
                node = node->getNode(1-bit);
            }
            else {
                node = node->getNode(bit);
            }
        }
        return maxi;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto& it: nums) {
            trie.insert(it);
        }

        int ans = 0;
        for(auto& it: nums) {
            ans = max(ans, trie.getMax(it));
        }

        return ans;
    }
};
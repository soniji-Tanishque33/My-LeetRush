/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node * dfs(Node* node, unordered_map<Node*, Node*>& mp) {
        if(node == NULL) return NULL;
        if(mp.find(node) != mp.end()) return mp[node];

        Node * clone = new Node(node->val);
        mp[node] = clone;

        for(auto neighbor: node->neighbors) {
            if(mp.find(neighbor) != mp.end()) {
                clone->neighbors.push_back(mp[neighbor]);
            } else {
                clone->neighbors.push_back(dfs(neighbor, mp));
            }
        }

        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;

        if(node->neighbors.size() == 0) {
            Node * clone = new Node(node->val);
            return clone;
        }

        unordered_map<Node*, Node*> mp;
        Node* clone = dfs(node, mp);

        return clone;
    }
};
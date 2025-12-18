struct Node {
    string site;
    Node* next;
    Node* prev;

    Node(string s) {
        this->site = s;
        this->next = NULL;
        this->prev = NULL;
    }
};

class BrowserHistory {
public:
    Node * root;
    Node * me;
    BrowserHistory(string homepage) {
        root = new Node(homepage);
        me = root;
    }
    
    void visit(string url) {
        Node * newNode = new Node(url);
        me->next = newNode;
        newNode->prev = me;
        me = me->next;
    }
    
    string back(int steps) {
        while(me->prev != NULL && steps--) {
            me = me->prev;
        }
        return me->site;
    }
    
    string forward(int steps) {
        while(me->next != NULL && steps--) {
            me = me->next;
        }
        return me->site;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

 /*
 leetcode -> google -> facebook -> linkedin
    ^
 */
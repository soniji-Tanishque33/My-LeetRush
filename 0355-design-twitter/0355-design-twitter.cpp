class Twitter {
private:
    static inline int time = 0;
public:
    unordered_map<int, int> tweetid_to_userid;
    unordered_map<int, vector<pair<int, int>>> userid_to_tweetid;
    unordered_map<int, vector<int>> ifollow;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweetid_to_userid[tweetId] = userId;
        userid_to_tweetid[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> alltweets;
        for(auto& p : userid_to_tweetid[userId]) {
            alltweets.push_back(p);
        }
        for(int user : ifollow[userId]) {
            for(auto& p : userid_to_tweetid[user]) {
                alltweets.push_back(p);
            }
        }

        sort(alltweets.begin(), alltweets.end(), [](pair<int, int>& a, pair<int, int>&b) {
            return a.first > b.first;
        });
        vector<int> feed;
        for(int i = 0; i<10 && i < alltweets.size(); i++) {
            int val = alltweets[i].second;
            if(find(feed.begin(), feed.end(), val) != feed.end()) continue;
            feed.push_back(val);
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        ifollow[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto& v = ifollow[followerId];
        v.erase(remove(v.begin(), v.end(), followeeId), v.end());
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
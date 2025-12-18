class TweetCounts {
public:
    map<string, multiset<int>> tweets; // use of multiset in case of duplicate elements
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        tweets[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        multiset<int>& st = tweets[tweetName];
        int diff = 0;
        if(freq == "minute") diff = 60;
        else if(freq == "hour") diff = 3600;
        else diff = 86400;

        auto it = st.lower_bound(startTime); // to get the min time greater or equal to starttime
        vector<int> res;

        for(int t = startTime; t <= endTime; t += diff) {
            int counter = 0;
            int interval_end = min(t + diff-1, endTime);

            while(it != st.end() && *it <= interval_end) {
                counter++;
                it++;
            }
            res.push_back(counter);
        }

    

        return res;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
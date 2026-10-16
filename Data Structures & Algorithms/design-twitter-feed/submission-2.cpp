class Twitter {
    unordered_map<int,vector<pair<int,int>>> tweets;
    unordered_map<int,unordered_set<int>> following;
    int timestamp =0;

    // {timestamp, userId, index of tweet}
    using Tweet = tuple<int,int,int>;

public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // vector<pair<int,int>> allTweets;
        // Max-heap: most recent tweet comes first.
        priority_queue<Tweet> pq;

         // Add the latest tweet from the user.
        auto& ownTweets = tweets[userId];

        if (!ownTweets.empty()) {
            int i = ownTweets.size() - 1;
            pq.push({ownTweets[i].first, userId, i});
        }

        // Add the latest tweet from each followee.
        for (int followeeId : following[userId]) {
            auto& userTweets = tweets[followeeId];

            if (!userTweets.empty()) {
                int i = userTweets.size() - 1;
                pq.push({userTweets[i].first, followeeId, i});
            }
        }

        vector<int> res;

        // Retrieve at most 10 newest tweets.
        while (!pq.empty() && res.size() < 10) {
            auto [time, uid, idx] = pq.top();
            pq.pop();

            res.push_back(tweets[uid][idx].second);

            // Add the previous tweet from the same user.
            if (idx > 0) {
                int prevIdx = idx - 1;
                pq.push({
                    tweets[uid][prevIdx].first,
                    uid,
                    prevIdx
                });
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

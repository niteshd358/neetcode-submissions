class Twitter {
    unordered_map<int,vector<pair<int,int>>> tweets;
    unordered_map<int,unordered_set<int>> following;
    int timestamp =0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // vector<pair<int,int>> allTweets;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> allTweets; // minHeap


        //include the user's own tweets
        for(auto& tweet : tweets[userId]){
            // allTweets.push_back(tweet);
            allTweets.push(tweet);
            if(allTweets.size() > 10){
                allTweets.pop();
            }
        } 

        //include the tweets of other followees
        for(auto followeeId : following[userId]){
            for(auto& tweet : tweets[followeeId]){
                // allTweets.push_back(tweet);
                allTweets.push(tweet);
                if(allTweets.size() > 10){
                    allTweets.pop();
                }
            } 
        }

        // sort(allTweets.begin(),allTweets.end(),greater<>{});

        vector<int>res;
        while(allTweets.size()){
            res.push_back(allTweets.top().second);
            allTweets.pop();
        }

        reverse(res.begin(),res.end());
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

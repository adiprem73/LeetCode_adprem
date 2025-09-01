class Twitter
{
public:
    int time;
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int,int>>> tweets;
    //userId --> vector of {time, tweetId}

    Twitter()
    {
        time=0;
        follows.clear();
        tweets.clear();
    }

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back({time, tweetId});
        time++;
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> feed;

        priority_queue<array<int, 4>> pq;

        //users own tweets
        if(tweets.count(userId)){
            //we posted the tweets inside a vector and we need the latest tweets which will obviouly be at the ends of the vector., hence we take this approach:
            int idx=tweets[userId].size()-1;
            pq.push({tweets[userId][idx].first, tweets[userId][idx].second, userId, idx});
            //pq has {time, tweetid, whose tweet, index in that user's timeline}
        }

        for(int f: follows[userId]){
            if(tweets.count(f) && !tweets[f].empty()){ //only if user f exists AND has tweets
                int idx = tweets[f].size()-1;
                pq.push({tweets[f][idx].first, tweets[f][idx].second, f, idx});
            }
        }

        while(!pq.empty() && feed.size()<10){
            auto top = pq.top();
            pq.pop();

            int tweetId= top[1];
            int uId= top[2];
            int idx= top[3];

            feed.push_back(tweetId);

            if(idx>0){
                pq.push({tweets[uId][idx-1].first, tweets[uId][idx-1].second, uId, idx-1});
            }
        }
        return feed;
    }

    void follow(int followerId, int followeeId)
    {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        follows[followerId].erase(followeeId);
    }
};
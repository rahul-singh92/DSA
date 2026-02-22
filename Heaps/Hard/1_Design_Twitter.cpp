#include <iostream>
#include <unordered_set>
using namespace std;

class Twitter
{
    private:
        // stores the tweet of each users as a vector of (timestamps, tweetId)
        unordered_map<int, vector<pair<int, int>>> tweets;
        unordered_map<int, unordered_set<int>> following;
        int time;

    public:
        Twitter()
        {
            time = 0;
        }

        void postTweet(int userId, int tweetId)
        {
            // Add the tweet with current timestamp to users tweet list
            tweets[userId].push_back({time++, tweetId});
        }

        // Function to get the 10 most recent tweets in new feed
        vector<int> getNewsFeed(int userId)
        {
            // Min heap to store tweets based on timestamp
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

            // Insert users own tweets
            for(auto& t: tweets[userId])
            {
                pq.push(t);
                // Keep heap size of max 10
                if(pq.size() > 10)
                {
                    pq.pop();
                }
            }

            // Insert tweets from user being followed
            for(int followee: following[userId])
            {
                for(auto& t: tweets[followee])
                {
                    pq.push(t);
                    if(pq.size() > 10)
                    {
                        pq.pop();
                    }
                }
            }

            // Extract tweets from heap in reverse order
            vector<int> res;
            while(!pq.empty())
            {
                res.push_back(pq.top().second);
                pq.pop();
            }
            reverse(res.begin(), res.end());
            return res;
        }

        void follow(int followerId, int followeeId)
        {
            following[followerId].insert(followeeId);
        }

        void unfollow(int followerId, int followeeId)
        {
            following[followerId].erase(followeeId);
        }
};

int main()
{
    Twitter twitter;

    twitter.postTweet(1, 2);
    twitter.postTweet(2, 6);

    vector<int> res1 = twitter.getNewsFeed(1);
    for (int i : res1) cout << i << " ";
    cout << endl;

    twitter.follow(1, 2);

    vector<int> res2 = twitter.getNewsFeed(1);
    for (int i : res2) cout << i << " ";
    cout << endl;

    twitter.unfollow(1, 2);
    twitter.postTweet(1, 7);

    vector<int> res3 = twitter.getNewsFeed(1);
    for (int i : res3) cout << i << " ";
    cout << endl;

    return 0;
}
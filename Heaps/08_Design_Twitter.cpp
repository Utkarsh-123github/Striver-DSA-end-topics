// Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

// Implement the Twitter class:

// -> Twitter() Initializes your twitter object.
// -> void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
// -> List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
// -> void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
// -> void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.
 
// Example 1:

// Input
// ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
// [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
// Output
// [null, null, [5], null, null, [6, 5], null, [5]]

// Explanation
// Twitter twitter = new Twitter();
// twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
// twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
// twitter.follow(1, 2);    // User 1 follows user 2.
// twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
// twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
// twitter.unfollow(1, 2);  // User 1 unfollows user 2.
// twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.

#include<bits/stdc++.h>
using namespace std;

// Brute Approach

class Twitter {
public:
    // To store posts
    vector<pair<int,int>>posts;
    // To store followers
    unordered_map<int,unordered_set<int>>followMap;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        // Push the userId and the tweetId in posts
        posts.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>result;
        int cnt = 10;
        // Iterate over the posts vector in reverse order to get recent tweets
        for(int i=posts.size()-1;i>=0;i--){
            if(cnt == 0)break;
            int followingId = posts[i].first;
            int tweetId = posts[i].second;

            // Check if the user with userId follows followingId of current post or if it is their own post
            if(followMap[userId].find(followingId) != followMap[userId].end() || followingId == userId){
                result.push_back(tweetId);
                cnt--;
            } 
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        // Push the followeeId in the set of user with followerId
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // Check if the user follows followeeId and if it is so then remove it
        if(followMap[followerId].find(followeeId) != followMap[followerId].end()){
            followMap[followerId].erase(followeeId);
        }
    }
};

// Optimal Approach : Using max heap for getNewsFeed and unordered_map<int,vector<pair<int,int>>>tweets for storing tweets

class Twitter2 {
public:
    // For storing time at which user posts and tweetId as well, we'll use 
    unordered_map<int,vector<pair<int,int>>>tweets;
    // To store followers
    unordered_map<int,unordered_set<int>>followMap;
    // initially time will be zero and it increases with every new post
    int time = 0;
    Twitter2() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // Here we'll use max Heap
        // In the max heap I'll be inserting {time, userId,index,tweetId}
        // Initially push all the recent tweets of user and whom he follows
        // Time will be the first so that heap will work based on time
        // Make sure you also do the same for userId as well along with the ids whom user follows
        priority_queue<vector<int>>pq;
        vector<int>ans;
        for(auto &it : followMap[userId]){
            if(tweets[it].size()){
                auto [t,tId] = tweets[it].back();
                pq.push({t,it,(int)tweets[it].size()-1,tId});
            }
        }
        if(tweets[userId].size()){
            auto [t,tId] = tweets[userId].back();
            pq.push({t,userId,(int)tweets[userId].size()-1,tId});
        }

        /*
        In the while loop push topTweet to the answer and add   
        corresponding userId's previous tweet into the priority queue 
        if user has previous tweets then only.
        make sure you done this all things only for 10 times
        */

        int k = 10;
        while(k>0 && !pq.empty()){
            vector<int>v = pq.top();
            pq.pop();
            ans.push_back(v[3]);
            if(v[2]!=0){
                auto [newTime, newTweetId] = tweets[v[1]][v[2]-1];
                pq.push({newTime,v[1],v[2]-1,newTweetId});
            }
            k--;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // If followerId follows followeeId then remove it
        if(followMap[followerId].find(followeeId) != followMap[followerId].end()){
            followMap[followerId].erase(followeeId);
        }
    }
};
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<vector>
using namespace std;

// linked list of posts by the user
// val.first = timestamp of tweet
// val.second = tweetId
// sorted in chronological order (most recent first)
struct Node {
    pair<int, int> val;
    Node* next;
    Node(int u, int v) : val({u, v}), next(nullptr){};
    Node(int u, int v, Node* nxt) : val({u, v}), next(nxt){};
};

// represents each user
struct User {
    Node* feed;
    unordered_set<int> follows;
    User() : feed(nullptr){};
};

class Twitter {
    // stores all users by their id
    unordered_map<int, User*> mp;

    // number of tweets made
    int cnt;

public:
    Twitter() { cnt = 0; }

    // ensure that user exists in map
    void ensureUser(int userId) {
        if (mp.find(userId) == mp.end()) {
            mp[userId] = new User();
        }
    }

    // new tweet
    void postTweet(int userId, int tweetId) {
        ensureUser(userId);
        auto node = new Node(cnt, tweetId, mp[userId]->feed);
        mp[userId]->feed = node;
        cnt++;
    }

    vector<int> getNewsFeed(int userId) {
        ensureUser(userId);
        vector<int> ans;
        // priority queue to get feed in sorted order
        // pair<int, Node*>: int=cnt value of the tweet, works as the timestamp
        //                   Node*=pointer to node of the tweet, used to get
        //                   the next tweet of a user
        priority_queue<pair<int, Node*>> pq;
        auto user = mp[userId];

        // insert own user feed in pq
        if (user->feed != nullptr)
            pq.push({((user->feed)->val).first, user->feed})

        // insert feed of all the users this user follows
        for (auto follower : user->follows) {
            if (mp[follower]->feed != nullptr)
                pq.push(
                        {((mp[follower]->feed)->val).first, mp[follower]->feed});
        }

        // keep going till we have 10 feeds or posts are empty
        while (ans.size() < 10 && !pq.empty()) {
            auto post = pq.top();
            pq.pop();
            ans.push_back(((post.second)->val).second);

            // if that user has more posts in his feed
            if ((post.second)->next != nullptr) {
                pq.push(
                        {(((post.second)->next)->val).first, (post.second)->next});
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        ensureUser(followerId);
        ensureUser(followeeId);
        (mp[followerId]->follows).insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        ensureUser(followerId);
        ensureUser(followeeId);
        (mp[followerId]->follows).erase(followeeId);
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
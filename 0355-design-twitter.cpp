#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<vector>
using namespace std;

struct Node {
    pair<int, int> val;
    Node* next;
    Node(int u, int v) : val({u, v}), next(nullptr){};
    Node(int u, int v, Node* nxt) : val({u, v}), next(nxt){};
};

struct User {
    Node* feed;
    unordered_set<int> follows;
    User() : feed(nullptr){};
};

class Twitter {
    unordered_map<int, User*> mp;
    int cnt;

public:
    Twitter() { cnt = 0; }

    void ensureUser(int userId) {
        if (mp.find(userId) == mp.end()) {
            mp[userId] = new User();
        }
    }

    void postTweet(int userId, int tweetId) {
        ensureUser(userId);
        auto node = new Node(cnt, tweetId, mp[userId]->feed);
        mp[userId]->feed = node;
        cnt++;
    }

    vector<int> getNewsFeed(int userId) {
        ensureUser(userId);
        vector<int> ans;
        priority_queue<pair<int, Node*>> pq;
        auto user = mp[userId];
        if (user->feed != nullptr)
            pq.push({((user->feed)->val).first, user->feed});
        for (auto follower : user->follows) {
            if (mp[follower]->feed != nullptr)
                pq.push(
                        {((mp[follower]->feed)->val).first, mp[follower]->feed});
        }

        while (ans.size() < 10 && !pq.empty()) {
            auto post = pq.top();
            pq.pop();
            ans.push_back(((post.second)->val).second);
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
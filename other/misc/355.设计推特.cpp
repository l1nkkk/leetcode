//
// Created by l1nkkk on 2021/8/30.
//

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
using namespace std;


namespace leetcode355{
struct Twit{
    Twit(int id, int ts, Twit* n):twitterId(id), timestamp(ts), next(n){
    }
    int twitterId;
    int timestamp;
    Twit *next; // 下一条
};

class User{
public:
    User(int id):userId(id){
    }
    void removeFollow(int id){
        follow.erase(id);
    }
    void addFollow(User* u){
        follow.insert(make_pair(u->getId(), u));
    }
    int getId(){
        return userId;
    }
    void addTwitter(int tweetId, int ts){
        Twit* t = new Twit(tweetId, ts, twitHead);
        twitHead = t;
    }
    map<int, User*>& getFollow() {
        return follow;
    }
    Twit* getTwit() {
        return twitHead;
    }
private:
    int userId;
    // follow
    map<int, User*> follow;
    Twit *twitHead = nullptr;
};
class cmp{
public:
    bool operator()(Twit *t1, Twit *t2){
        return t1->timestamp < t2->timestamp;
    }
};


class TwitterSend{
public:
    TwitterSend(User *user){
        if(user->getTwit() != nullptr)
            pq.push(user->getTwit());
        for(auto t : user->getFollow()){
            if(t.second->getTwit() != nullptr)
                pq.push(t.second->getTwit());
        }
    }
    Twit* get(){
        if(pq.empty()) return nullptr;
        auto rtn = pq.top();
        pq.pop();
        if(rtn->next != nullptr){
            pq.push(rtn->next);
        }
        return rtn;
    }
private:
    priority_queue<Twit*, vector<Twit*>,cmp> pq;
};

class Twitter {
private:
    map<int,User*> users;
    int timestamp = 0;
public:
    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(users.count(userId) == 0){
            users[userId] = new User(userId);
        }
        users[userId]->addTwitter(tweetId,timestamp++);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        if(users.count(userId) == 0){
            users[userId] = new User(userId);
        }
        TwitterSend tsend = TwitterSend(users[userId]);
        vector<int> res;
        for(int i = 0; i < 10; ++i){
            auto t = tsend.get();
            if(t == nullptr) break;
            res.push_back(t->twitterId);
            cout << t->twitterId << " ";
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(users.count(followerId) == 0){
            users[followerId] = new User(followerId);
        }
        if(users.count(followeeId) == 0){
            users[followeeId] = new User(followeeId);
        }
        users[followerId]->addFollow(users[followeeId]);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(users.count(followerId) == 0){
            users[followerId] = new User(followerId);
        }
        if(users.count(followeeId) == 0){
            users[followeeId] = new User(followeeId);
        }
        users[followerId]->removeFollow(followeeId);
    }
};

void test(){
    Twitter twitter = Twitter();

// 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
    twitter.postTweet(1, 5);

// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
    twitter.getNewsFeed(1);

// 用户1关注了用户2.
    twitter.follow(1, 2);

// 用户2发送了一个新推文 (推文id = 6).
    twitter.postTweet(2, 6);

// 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
// 推文id6应当在推文id5之前，因为它是在5之后发送的.
    twitter.getNewsFeed(1);

// 用户1取消关注了用户2.
    twitter.unfollow(1, 2);

// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
// 因为用户1已经不再关注用户2.
    twitter.getNewsFeed(1);
}

void test1(){
    Twitter *t = new Twitter();
    t->postTweet(1,1);
    t->getNewsFeed(1);
    t->follow(2,1);
    t->getNewsFeed(2);
    t->unfollow(2,1);
    t->getNewsFeed(2);
}

void test2(){
    Twitter *t = new Twitter();
    t->postTweet(1,5);
    t->postTweet(1,3);
    t->getNewsFeed(1);
}
}
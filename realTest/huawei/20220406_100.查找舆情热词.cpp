//
// Created by l1nkkk on 2022/4/12.
//
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;
namespace huawei20220406_100{
struct Item{
    int count = 0;
    string data = "";
    int start;
    Item(const int c, const string &d, const int s): count(c), data(d), start(s){}
    struct cmp{
        bool operator ()(Item* t1, Item* t2){
            return *t2 < *t1;
        }
    };

    bool operator <(Item& t1){
        if(this->count < t1.count)
            return true;
        else if(this->count == t1.count && this->start > t1.start)
            return true;
        else
            return false;
    }

};

vector<string> split(const string& s, const string patt){
    size_t next = 0;
    size_t pos = 0;
    vector<string> res;
    while(next != s.npos){
        next = s.find(patt.c_str(), pos);
        res.push_back(s.substr(pos, next-pos));
        if(next != s.npos)
            pos = next+patt.size();
    }
    return res;
}

void test(){
    static int num = 0;
    int k, n;
    cin >> k >> n;
    // topK 肯定优先队列， o(1) 查需要unordermap
    cin.clear();
    unordered_map<string, Item*> record;
    priority_queue<Item*, vector<Item*>, Item::cmp> pq;
    auto update = [&](string &s, int num, int p){
        if(record.count(s) == 0)
            record[s] = new Item{p, s, num};
        else
            record[s]->count+=p;
    };
    string t;
    std::getline(cin, t);
    while(n){
        // 1. 先处理标题
        {
            string title;
            cin.clear();
            std::getline(cin, title);
            int pos = 0;
            auto res = split(title, " ");
            for(auto r : res){
                update(r, num++, 3);
            }
        }

        // 2. 再处理正文
        {
            string text;
            std::getline(cin, text);
            int pos = 0;
            auto res = split(text, " ");
            for(auto r : res){
                update(r, num++, 1);
            }
        }
        n--;
    }
    // 优先队列，小顶堆
    for(auto a : record){
        if(pq.size() == k){
            if(*pq.top() < *a.second){
                pq.pop();
                pq.push(a.second);
            }
        }else{
            pq.push(a.second);
        }
    }

    stack<string> out;
    while(!pq.empty()){
        out.push(pq.top()->data);
        pq.pop();
    }
    while(!out.empty()){
        cout << out.top() << " ";
        out.pop();
    }
    return;
}

void test2(){
//    string a = "123 xxfe xxwdw xxwdwd";
//    auto res = split(a," xx");
//    for(auto r : res){
//        cout << r << " | ";
//    }
//    priority_queue<int, vector<int>, less<int>> pq;
//    pq.push(3);
//    pq.push(9);
//    pq.push(1);
//    cout << pq.top() << endl;

    Item i1(6,"a",0);
    Item i2(8,"a",7);
    Item i3(5,"a",7);
    priority_queue<Item*, vector<Item*>, Item::cmp> pq;
    pq.push(&i1);
    pq.push(&i2);
    pq.push(&i3);
    cout << pq.top()->count << endl;
}

}
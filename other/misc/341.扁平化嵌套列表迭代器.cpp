//
// Created by l1nkkk on 2022/3/19.
//
#include <vector>
#include <stack>
#include <cassert>
#include <iostream>
using namespace std;

namespace leetcode341{
class NestedInteger {
public:
    NestedInteger(int d): data_(d){}
    NestedInteger(vector<NestedInteger>*d): dataList_(d){}
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger()const {
        return dataList_ == nullptr;
    }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    virtual int getInteger() const{
        return data_;
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const {
        return *dataList_;
    }
private:
    int data_ = 0;
    vector<NestedInteger>* dataList_ = nullptr;
};

//class SingleNestedInteger: public NestedInteger{
//public:
//    SingleNestedInteger(int d):data_(d){}
//    bool isInteger()const override{ return true; }
//    int getInteger() const override{
//        return data_;
//    }
//    const vector<NestedInteger> & getList() const override{
//        return dataList_;
//    }
//private:
//    int data_;
//    vector<NestedInteger> dataList_;
//};
//
//class MultiNestedInteger: public NestedInteger{
//public:
//    MultiNestedInteger(vector<NestedInteger> v):dataList_(v){}
//    bool isInteger()const override{ return false; }
//    int getInteger() const override{
//        return data_;
//    }
//    const vector<NestedInteger> & getList() const override{
//        return dataList_;
//    }
//private:
//    int data_;
//    vector<NestedInteger> dataList_;
//};


class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // 过滤掉 []的情况
        for(auto it = nestedList.begin(); it != nestedList.end(); ++it){
            if(checkNull(*it)){
                data_.push_back(*it);
            }
        }

    }
    bool checkNull(const NestedInteger& n){
        if(n.isInteger()) return true;
        for(int i = 0; i < n.getList().size(); ++i){
            if(checkNull(n.getList()[i])) return true;
        }
        return false;
    }

    int next() {
        // 检测是否还有数据可读
        assert(!(st_.empty() && data_.size() == index_));

        // 1. 是否栈为空，为空读取 data_ 中数据
        while(st_.empty()){
            if(data_[index_].isInteger()){
                return data_[index_++].getInteger();
            }else{
                // 防止 [[[]],1]的情况
                if(checkNull(data_[index_]))
                    st_.push(make_pair(&data_[index_++], 0));
            }
        }

        // 2. 读取stack 中的数据，如果读到的 st.top[ind] 是list类型，继续入栈
        auto &top = st_.top().first;
        auto &ind = st_.top().second;
        while(!top->getList()[ind].isInteger()){
            ++ind;
            // 如果索引到尽头，弹栈
            if(ind == top->getList().size()){
                st_.pop();
            }
            // 如果当前的 st.top[ind] 是list类型，继续入栈
            st_.push(make_pair(&top->getList()[ind - 1], 0));
        }
        auto res = top->getList()[ind++].getInteger();
        // 如果索引到尽头，弹栈
        if(ind == top->getList().size()){
            st_.pop();
        }
        return res;
    }

    bool hasNext() {
        if(st_.empty() && data_.size() == index_){
            return false;
        }
        return true;
    }

private:
    vector<NestedInteger> data_;
    int current = 0;
    int index_ = 0;
    // 先序遍历使用的栈，<list, ind>，如果是single int ,index = -1
    stack<pair<const NestedInteger*, int>> st_;
};

void test(){
    vector<NestedInteger> input{
            NestedInteger(1),
            NestedInteger(new vector<NestedInteger>{
                    4,
                    new vector<NestedInteger>{6}
            })
    };
    vector<NestedInteger> input1{
        NestedInteger(new vector<NestedInteger>{1,1}),
        NestedInteger(2),
        NestedInteger(new vector<NestedInteger>{1,1})
    };
    vector<NestedInteger> input2{
            NestedInteger(new vector<NestedInteger>{
                new vector<NestedInteger>{}
            })
    };
    // [[[8],4]]
    vector<NestedInteger> input3{
            new vector<NestedInteger>{
                new vector<NestedInteger>{
                    8
                },
                4
            }
    };

//    {
//        NestedIterator it = NestedIterator(input);
//
//        while (it.hasNext()) {
//            cout << it.next() << " " << flush;
//        }
//        cout << endl;
//    }
//
//    {
//        NestedIterator it = NestedIterator(input1);
//
//        while (it.hasNext()) {
//            cout << it.next() << " " << flush;
//        }
//        cout << endl;
//    }
//    {
//        NestedIterator it = NestedIterator(input2);
//
//        while (it.hasNext()) {
//            cout << it.next() << " " << flush;
//        }
//        cout << endl;
//    }
    {
        NestedIterator it = NestedIterator(input3);

        while (it.hasNext()) {
            cout << it.next() << " " << flush;
        }
        cout << endl;
    }
}

}

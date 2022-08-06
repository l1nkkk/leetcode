//
// Created by l1nkkk on 2021/10/4.
//

#ifndef LEETCODE_MYVECTOR_H
#define LEETCODE_MYVECTOR_H
#include <string>
#include <memory>
#include <iostream>

namespace design{
using namespace std;
template<typename T> class myVector;

template<typename T>
void swap(myVector<T>& l, myVector<T>& r){
    using std::swap;
    swap(l._head, r._head);
    swap(l._cap, r._cap);
    swap(l._last, r._last);
}


template<typename T>
class myVector {
public:
    template<typename X>friend void swap(myVector<X>&, myVector<X>&);

    // 初始化
    myVector(): _head(nullptr), _cap(nullptr),_last(nullptr){}
    // 拷贝构造
    myVector(const myVector<T>& rvec){
        cout << "myVector-&" << endl;
        _head = alloMgr.allocate(rvec.size());
        _cap = _last = uninitialized_copy(rvec._head, rvec._last, _head);// 返回最后一个还没被构造的地址
    }

    // 拷贝赋值 or 移动赋值
    myVector<T>& operator =(myVector<T> t){
        swap(*this, t);
        return *this;
    }

    // 析构
    ~myVector(){
        cout << "~myVector()" << endl;
        free();
    }

    // 移动拷贝构造
    myVector(myVector<T>&& rvec){
        cout << "myVector-&&" << endl;
        _head = rvec._head;
        _last = rvec._last;
        _cap = rvec._cap;
        rvec._last = rvec._cap = rvec._head = nullptr;
    }

    // 功能函数
    void pushback(T& t){
        check();
        alloMgr.template construct(_last++, t);
    }
    void pushback(T&& t){
        check();
        alloMgr.template construct(_last++, t);
    }

    T& operator[](size_t index){
        return *(_head+index);
    }

    size_t size() const {
        return _last - _head;
    }
    size_t capacity() const{ return _cap - _head;}
private:
    /**
     * @brief 判断是否满了，满了就重新再分配
     */
    void check(){
        if(size() == capacity())
            realloc();
    }

    // 重点
    void realloc(){
        // 1.算出要分配的新空间多大，并分配新空间
        auto newsize = capacity() ? 2 * capacity(): 1;
        auto newbuf = alloMgr.allocate(newsize);
        cout << "realloc()  ；newsize=" << newsize << endl;


        T* h1 = newbuf;
        T* h2 = _head;
        // 2.拷贝
        for(int i = 0; i < size(); ++i){
            alloMgr.construct(h1++, std::move(*h2++));
        }
        // 3.释放旧内存
        free();

        // 4.更新指针
        _head = newbuf;
        _last = h1;
        _cap = newbuf+newsize;

    }

    void free(){
        if(_head){
            for(auto p = _head; p != _last; ++p){
                alloMgr.destroy(p);
            }
            alloMgr.deallocate(_head, _cap - _head);
        }
        _head = _cap = _last = nullptr;
    }


    T* _head;
    T* _cap;
    T* _last;
    allocator<T> alloMgr;

};

void testVector(){
    cout << "test1===================" << endl;
    {
        myVector<string> s;
        s.pushback("123");
        s.pushback("333");
        s.pushback("333");
        s.pushback("333");
        cout << s[1] << endl;
    }
    cout << "test2===================" << endl;
    {
        myVector<string> s;
        s.pushback("123");
        s.pushback("333");
        myVector<string> t = s;
        cout << t[1] << endl;
    }

    cout << "test3===================" << endl;
    {

        myVector<string> t;
        {
            myVector<string> s;
            s.pushback("123");
            s.pushback("333");
            t = std::move(s);
        }
        cout << t[1] << endl;
    }
}

}



#endif //LEETCODE_MYVECTOR_H

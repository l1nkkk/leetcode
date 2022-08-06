//
// Created by l1nkkk on 2021/10/3.
//

#ifndef LEETCODE_MYSHAREPTR_H
#define LEETCODE_MYSHAREPTR_H
#include <iostream>
#include <string>

namespace design {
using namespace std;
template<typename T> class mySharePtr;

template <typename T>
void swap(mySharePtr<T> &lp, mySharePtr<T> &rp){
    std::swap(lp._data,rp._data);
    std::swap(lp._count, rp._count);
}
template<typename T>
class mySharePtr {
public:
    using sptr = mySharePtr<T>;
     template<typename X> friend void swap(mySharePtr<X>&, mySharePtr<X>&);

    mySharePtr(T* ptr = nullptr):_data(ptr), _testID(_id++){
        cout <<  "mySharePtr-T :" << _testID << endl;
        if(ptr == nullptr){
            _count = nullptr;
        }else{
            _count = new int(1);
        }
    }
    mySharePtr(const sptr& t): _data(t._data), _count(t._count), _testID(_id++){
        cout <<  "mySharePtr-& :" << _testID << endl;
        if(t._data != nullptr && t._count!= nullptr)
            ++*_count;
    }
    // 这种拷贝赋值函数也是可以的
//    T& operator = (sptr &t){
//        ++t._count; // 为了自赋值正确
//        if(_data != nullptr){
//            if(--_count == 0){
//                delete _count;
//                delete _data;
//            }
//        }
//        _data = t._data;
//        _count = t._count;
//        return *this;
//    }

    ~mySharePtr(){
        cout << "~mySharePtr：" << _testID << endl;
        if(--_count == 0){
            delete _count;
            delete _data;
        }
    }

    mySharePtr(sptr&& rp): _data(rp._data), _count(rp._count), _testID(_id++){
        cout <<  "mySharePtr-&& :" << _testID << endl;
        rp._data = nullptr;
        rp._count = nullptr;
    }

    // 单一的赋值运算符实现了拷贝运算符和移动赋值运算符两种功能
    // 重点：使用的是移动赋值运算符，还是拷贝赋值运算符，依赖于传入的实参类型
    mySharePtr& operator =(sptr& rp){
        swap<T>(*this, rp);
        return *this;
    }

    T& operator *() const {
        return *_data;
    }

    T* operator ->() const{
        return &this->operator*();
    }

private:

    T *_data;
    int *_count;

    // just for test
    int _testID;
    static int _id;
};

template<typename T> int mySharePtr<T>::_id = 0;



void test(){
    using namespace std;
    cout << "test1 =======================" << endl;
    {
        string* p = new string("linqing");
        mySharePtr<string> sp(p);
        cout << sp->size() << endl;
        cout << *sp << endl;
    }
    cout << "test2 =======================" << endl;
    {
        string* p = new string("linqing");
        mySharePtr<string> sp(p);
        mySharePtr<string> sp2(sp);
        cout << *sp2 << endl;
    }
    cout << "test3 =======================" << endl;
    {
        string* p = new string("linqing");
        mySharePtr<string> sp(p);
        mySharePtr<string> sp2 = sp;
        cout << *sp2 << endl;
    }

    cout << "test4 =======================" << endl;
    {
        string* p = new string("linqing");
        mySharePtr<string> sp(p);
        mySharePtr<string> sp2 = std::move(sp);
        cout << sp2->c_str() << endl;
    }
    cout << "test4 =======================" << endl;
    {
        mySharePtr<string> sp2 ;
        {
            string* p = new string("linqing");
            mySharePtr<string> sp(p);
            sp2 = sp;
        }
        cout << sp2->c_str() << endl;
    }
}

}


#endif //LEETCODE_MYSHAREPTR_H

#include <iostream>
#include <functional>
#include <iterator>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include "DP/dp.h"
#include "other/other.h"
#include "Tree/tree.h"
#include "LinkList/LinkList.h"
#include "String/str.h"
#include "Array/array.h"
#include "offer/offer.h"
#include "graph/graph.h"
#include "cppdemo/mySharePtr.h"
#include "cppdemo/myVector.h"
#include "realTest/realTest.h"
#include "offer2/offer2.h"
using namespace std;

class A{
public:
    A(){
        cout << "construct" <<endl;
    }
    void func(){
        cout << "func";
    }
    ~A(){
        cout << "";
    }
    int a;
};
class X
{
public:
    X() { cout<<"constructor of X"<<endl; }
    ~X() { cout<<"destructor of X"<<endl;}

    void* operator new(size_t size,string str)
    {
        cout<<"operator new size "<<size<<" with string "<<str<<endl;
        return ::operator new(size);
    }

    void operator delete(void* pointee)
    {
        cout<<"operator delete"<<endl;
        ::operator delete(pointee);
    }
private:
    int num;
};

int main(){
//    design::testVector();
//    add1::test();
//    cout << "tes";
//    offer67::test();
//    l1::test();
//    offer2_1::test();
    offer2_82::test();
//    leetcode207::test();
//    huawei20220406_100::test();
    return 0;

}
//
// Created by l1nkkk on 2022/4/18.
//

#include <iostream>
#include <vector>
using namespace std;

namespace  l1{
int gcb(int a, int b){
    int ta,tb;
    ta = max(a,b);
    tb = min(a,b);
    while(ta % tb){
        auto t = ta % tb;
        ta = tb;
        tb = t;
    }
    return tb;
}
void test(){
    cout << gcb(24,9);
}

}


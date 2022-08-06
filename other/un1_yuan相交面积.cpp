//
// Created by l1nkkk on 12/16/20.
// 求两圆的相交面积
//
#include <cmath>
#include <iostream>
namespace un1_yuan{
    using namespace std;
    constexpr double PI = 3.14159;
    struct Circle{
        double x,y;
        double r;
    };

    double solve(Circle c1, Circle c2){

        // 圆心距
        double dotlen;
        double  res;
        dotlen = sqrt(pow(c1.x - c2.x,2) + pow(c1.y - c2.y,2));

        if(dotlen > c1.r + c2.r)
            // 相离
            return 0;
        else if(dotlen < fabs(c1.r-c2.r))
            // 相含
            return c1.r > c2.r ? pow(c2.r,2)*PI : pow(c1.r,2)*PI;
        else{
            // 使用余弦定理算出两个夹角的cos值，之后算出夹角值
            auto angle1 = acos(( pow(c1.r,2) + pow(dotlen,2) - pow(c2.r,2)) / (2 * c1.r * dotlen));
            auto angle2 = acos(( pow(c2.r,2) + pow(dotlen,2) - pow(c1.r,2)) / (2 * c2.r * dotlen));
            // 算出三角形的高，然后算出面积
            auto areaTriangle = c1.r * sin(angle1) * 0.5 * dotlen;

            // 算出两个扇形的面积，2PI
            auto areaSector1 = PI * pow(c1.r,2) * (angle1/(2*PI));
            auto areaSector2 = PI * pow(c2.r,2) * (angle2/(2*PI));
            // （扇形相加 - 三角形）×2 = 相交部分
            res = (areaSector1 + areaSector2 - areaTriangle)*2;

        }
        return res;
    }

    void test(){
        double a,b,c;
        double x,y,z;
        cin >> a >> b >> c;
        cin >> x >> y >> z;
        cout << solve({a,b,c},{x,y,z});
    }

}
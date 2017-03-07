// 1081
// 计算最大公约数和最小公倍数

#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// 计算最大公约数
long long gcd(long long x, long long y){
    if (y == 0) return x;
    else return gcd(y, x%y);
}
// 最小公倍数
long long lcm(long long x, long long y){
    return x / gcd(x, y) *y;
}

int main()
{
    int n;
    long long de=1, nu=0;// 分母、分子
    long long nus[101];
    long long des[101];


    scanf("%d", &n);

    long long a, b;
    for (int i=0; i<n; ++i) {
        scanf("%lld/%lld", &a, &b);
        de = lcm(de, b);
        nus[i]=a; // 分子保存起来
        des[i]=b; // 分母
    }
    // 计算分子之和
    for (int j = 0; j < n; ++j) {
        nu += nus[j]*(de/des[j]); // 这里要加括号
    }
    // 判断
    long long integer = nu/de;

    nu -= integer*de;
    long long m = gcd(nu,de);
    de=de/m;
    nu=nu/m;

    if(integer==0 && nu==0)
        printf("0\n");
    else if(integer!=0 && nu==0)
        printf("%lld\n", integer);
    else if(integer==0 && nu!=0)
        printf("%lld/%lld\n", nu, de);
    else
        printf("%lld %lld/%lld\n", integer, nu, de);
    return 0;
}

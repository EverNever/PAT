// 1065

/*
 * long 和 long long 不是同一种类型
 * 64bit 溢出等
unsigned   int   0～4294967295
int   2147483648～2147483647
unsigned long 0～4294967295
long   2147483648～2147483647
long long的最大值：9223372036854775807
long long的最小值：-9223372036854775808
unsigned long long的最大值：1844674407370955161
 */

#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int count;
    long long a, b, c, temp;
    bool flag;
    cin >> count;
    for (int i = 0; i < count; ++i) {
        scanf("%lld %lld %lld", &a, &b, &c);
        temp=a+b;

        if (a>0 && b>0 && temp<=0)
            flag=true; // 正数相加且溢出,必然大于任一64bit的c
        else if(a<0 && b<0 && temp>=0)
            flag=false; // 负数相加且溢出,必然小于
        else
            flag = (temp>c); // 没有溢出

        if (flag)
            cout << "Case #"<<i+1<<": true"<< endl;
        else
            cout << "Case #"<<i+1<<": false"<< endl;
    }
    return 0;
}
//
// Created by 周超 on 08/02/2017.
//

// 1023
// no more than 20 digits,所以不能用long型存储
// 考虑字符串的加法实现
// 注意进位

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    string str;

    int len;

    cin >> str;

    // 处理字符串的加法
    len = str.length();
    int sign1 = 0, sign2 = 0;
    int carry = 0, temp = 0;
    while(len>0)
    {
        sign1 += (1 << (str[len - 1] - '0'));
        temp = (str[len - 1] - '0') * 2 + carry;
        carry = temp/10;
        str[len - 1] = '0' + temp % 10;// 处理ascll值
        sign2 += (1 << (str[len - 1] - '0'));
        --len;
    }

    // 判断Yes or No
    if(sign1 == sign2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    // 输出两倍数据,有进位的情况需要把进位加上输出
    if (carry != 0)
        cout << carry << str << endl;
    else
        cout << str;
    return 0;
}
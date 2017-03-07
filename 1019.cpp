//
// Created by 周超 on 08/02/2017.
//

// 1019
// 只要获取正序的n进制序列,然后逐一比较即可。

#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    int n, b;
    stack<int> s;
    vector<int> v;

    scanf("%d %d", &n, &b);
    // 0是特殊的回文
    if(n == 0)
    {
        printf("Yes\n0");
        return 0;
    }
    // 转换为倒序b进制序列
    while(n != 0)
    {
        s.push(n%b);
        n = n/b;
    }
    // 转换为正序b进制序列
    while(!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    // 逐一比较,输出是否回文
    bool flag = true;
    for (int j = 0; j < v.size() / 2; ++j) {
        if (v[j] != v[v.size() - j - 1])
        {
            flag = false;
            break;
        }
    }
    flag?printf("Yes\n"):printf("No\n");

    // 输出序列
    for (int i = 0; i < v.size(); ++i) {
        if(i < v.size() - 1)
            printf("%d ", v[i]);
        else
            printf("%d", v[i]);
    }
    return 0;
}

//
// Created by 周超 on 08/02/2017.
//
/*
 * 反转素数
 * 输入N<10^5和其进制2~10
 */

#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

bool isPrime(int m)
{
    if (m<2)
        return false;
    else if (m == 2 || m == 3)
        return true;
    for (int i = 2; i * i <= m; ++i) {
        if (m % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n, d, reverse;
    while (cin >> n)
    {
        if (n < 0) break;
        else
        {
            cin >> d;
            // 首先判断n是否为素数
            if (isPrime(n))
            {
                queue<int> que;
                // 用队列来实现翻转
                while(n!=0)
                {
                    que.push(n%d);
                    n = n/d;
                }
                reverse = 0;
                // 重新还原为int
                while(!que.empty())
                {
                    reverse = reverse * d;
                    reverse += que.front();
                    que.pop();
                }
                // 判断是否为prime number
                if (isPrime(reverse))
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
            else //本身就不是素数的情况
            {
                cout << "No" << endl;
            }
        }
    }
}

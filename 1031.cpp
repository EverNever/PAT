//
// Created by 周超 on 09/02/2017.
//
// 1031
// it must be satisfied that
// n1 = n3 = max { k| k <= n2 for all 3 <= n2 <= N } with n1 + n2 + n3 - 2 = N.

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int n1, n2, n3;
    int k, k_max;
    int len;

    // find n1, n2, n3
    cin >> str;
    len = str.length();
    for(n2 = 3; n2 <= len; ++n2)
    {
        k = k_max = 0; // init k
        while (k <= n2)
        {
            if (k*2 + n2 -2 == len)
            {
                // satisfied conditions, find max
                if (k > k_max) k_max = k;
            }
            ++k;
        }
        if(k_max != 0)break;
    }
    n1 = n3 = k_max;

    // cout << "n1 n2:" << k_max << " " << n2 << endl;

    // print 'U' shape
    // output str[i] -- n2-2 space -- str[len-1-i] until i == n1-1
    // output str[i] until i = init + n2
    int i;
    for(i = 0; i < n1-1; ++i)
    {
        printf("%c", str[i]);
        for(int j = 0; j < n2 -2; ++j)
            printf(" ");
        printf("%c\n", str[len-1-i]);
    }
    int init = i;
    for(i;i < init+n2; ++i)
        printf("%c", str[i]);

    return 0;
}


//
// Created by 周超 on 09/02/2017.
//
// 1041
// The first one who bets on a unique number wins.

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int ary[100001];
    int ary1[100001]; // record the amount

    memset(ary1, 0, sizeof(ary1));

    for(int i = 0; i < n; ++i)
    {
        cin >> ary[i];
        ary1[ary[i]]++;
    }
    // 5 31 5 88 67 88 17
    int i;
    for (i = 0; i< n; ++i)
    {
        if (ary1[ary[i]] == 1)
        {
            cout << ary[i] << endl;
            break;
        }
    }
    if (i == n)
        cout << "None" << endl;

    return 0;
}


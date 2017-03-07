//
// Created by 周超 on 08/02/2017.
//

/*
 * 6s上一楼,4s下一楼,在每层停5s
 * 楼层小于100,初始时在0楼
 */

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int req[10000];
    int n, sum;
    req[0] = 0;

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> req[i];
        if (req[i] > req[i-1])
            sum += (req[i] - req[i-1])*6;
        else
            sum += (req[i-1] - req[i])*4;
    }
    sum += n*5;// 每层停留5s
    cout << sum << endl;

    return 0;
}

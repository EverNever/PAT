//
// Created by 周超 on 09/02/2017.
//

// 1046
/*
Sample Input:
5 1 2 4 14 9
3
1 3
2 5
4 1
Sample Output:
3
10
7
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    int dist[100001];
    int shortest[100001];

    int m;
    int p1, p2;
    int big, small;

    int sum=0;
    int temp;

    cin >> n;
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &temp);
        sum+=temp;
        dist[i]=sum; // 这里很关键,否则会超时
    }

    cin >> m;
    for (int i=0; i<m; ++i)
    {
        // small -> big
        // big -> small
        cin >> p1;
        cin >> p2;
        big = small = 0;
        if(p1>p2)
        {
            big=p1;small=p2;
        }
        else if(p1<p2)
        {
            big=p2;small=p1;
        }
        else
        {
            printf("0");
            return 0;
        }

        // 直接用减的
        int d;
        if (small==1)
            d = dist[big-2];
        else
            d = dist[big-2] - dist[small-2];
        if(d>sum/2)
            d=sum-d;
        printf("%d\n", d);
    }
    return 0;
}
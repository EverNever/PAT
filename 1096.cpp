// 1096

// 找出从2,3...连续的分解结果,保存到tpv中
// 如果tpv优于ans,则把tpv保存到ans中

#include <cstdio>
#include <iostream>
#include <vector>

typedef long long LL;

using namespace std;

int main()
{
    LL m;
    scanf("%d", &m);

    // 结果,其中1*m本身必然是一个,比如对于质数3,必须初始化把m加进去
    vector<LL> ans(1, m);    // 1 ints with value m
    vector<LL> tpv;

    int temp;
    for (LL i = 2; i*i <= m; ++i) { // 连续分解的起点
        tpv.clear();
        temp=m;
        for (LL j = i; j <= temp; ++j) {
            if (temp%j==0)
            {
                tpv.push_back(j);
                temp = temp/j;
            }
            else break; // j连续增长,如果不是,则跳出循环
        }
        if (ans.size()<tpv.size())
            ans = tpv; // tpv比ans长
        else if(ans.size()==tpv.size() && tpv[0]<ans[0])
            ans = tpv; // tpv is smaller
    }

    printf("%d\n%d", ans.size(), ans[0]);
    for (int k = 1; k < ans.size(); ++k) {
        printf("*%d", ans[k]);
    }
    return 0;
}
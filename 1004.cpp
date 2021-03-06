// 1004
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 101;

vector<int> G[N];
int leaf[N] = {0};
int max_h = 1;

void DFS(int index, int h)
{
    max_h = max(h, max_h);
    if(G[index].size() == 0) // 叶子节点
    {
        leaf[h]++;
        return;
    }
    for (int i = 0; i < G[index].size(); ++i) {
        DFS(G[index][i], h+1); // 枚举子节点
    }
}

int main()
{
    int n, m ,parent, child, k;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &parent, &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &child);
            G[parent].push_back(child);
        }
    }
    DFS(1, 1);
    printf("%d", leaf[1]);
    for (int l = 2; l <= max_h; ++l) {
        printf(" %d", leaf[i]);
    }
    return 0;
}
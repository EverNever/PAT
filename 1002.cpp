#include <cstdio>

using namespace std;

const int max_n = 1001;

int main()
{
    double p[1001] = {};

    int k, n ,count = 0;
    double a;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d %lf",&n, &a);
        p[n] += a;
    }
    scanf("%d", &k);
    for (int j = 0; j < k; ++j) {
        scanf("%d %lf", &n, &a);
        p[n] += a;
    }
    for (int l = 0; l < max_n; ++l) {
        if (p[l] != 0)
            ++count;
    }

    printf("%d", count);
    for (int m = max_n-1; m >= 0; --m) {
        if(p[m]!=0)
            printf(" %d %.1f", m, p[m]);
    }

    return 0;
}
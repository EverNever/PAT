// 1054

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int m, n;
    int total;
    scanf("%d", &m);
    scanf("%d", &n);
    total = m*n;

    int candidate=0, temp;
    int count = 0;
    for (int i = 0; i < total; ++i) {
        scanf("%d", &temp);
        if (candidate != temp)
        {
            if (count == 0) {
                candidate = temp;
                ++count;
            }
            else --count;
        }
        else ++count;
    }
    if (count > 0)
    {
        printf("%d", candidate);
    }

    return 0;
}
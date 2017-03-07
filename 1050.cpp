// 1050

// hash标记数组,典型的用空间换时间
// 子序列

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1;
    int hs[256] = {0};
    memset(hs, 0, sizeof(hs));

    getline(cin, s1);

    char c;
    while ((c = getchar()) != '\n')
    {
        hs[c] = 1; // hash标记是否在s2中出现
    }

    for (int i = 0; i < s1.length(); ++i) {
        if(hs[s1[i]] == 0)
            printf("%c", s1[i]);
    }

    return 0;
}

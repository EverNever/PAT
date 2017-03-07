// 1092

// If the answer is "Yes", then also output the number of extra beads Eva has to buy;
// If the answer is "No", then also output the number of beads missing from the string.

// 统计字符出现的次数,用hash查找

#include <iostream>

using namespace std;

int main()
{
    string s1, s2;
    int count1[256]={0}, count2[256]={0}; // 统计s1和s2中
    int extra=0, miss=0;

    getline(cin, s1);
    getline(cin, s2);

    for (int i = 0; i < s1.length(); ++i) {
        count1[s1[i]]++;
    }
    for (int j = 0; j < s2.length(); ++j) {
        count2[s2[j]]++;
    }

    for (int k = 0; k < 256; ++k) {
        if (count1[k] >= count2[k])
            extra += count1[k]-count2[k];
        else
            miss += count2[k]-count1[k];
    }
    // 这里只能用miss
    if (miss!=0)
        cout << "No " << miss << endl;
    else
        cout << "Yes " << extra << endl;

    return 0;
}
// 1084

// 缺失按键的hash数组

#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    string s1, s2, str;
    getline(cin, s1);
    getline(cin, s2);
    bool broken[40];
    for (int i = 0; i < 40; ++i) {
        broken[i]=false;
    }

    int len1=0, len2=0;

    while(len1<s1.length())
    {
        if (s1[len1] != s2[len2])
        {
            if(s1[len1]>='0'&&s1[len1]<='9'&&!broken[s1[len1]-'0'])
            {
                broken[s1[len1]-'0'] = true;
                str += s1[len1];
            }
            else if(s1[len1]>='A'&&s1[len1]<='Z'&&!broken[s1[len1]+10-'A'])
            {
                broken[10+s1[len1]-'A'] = true;
                str += s1[len1];
            }
            else if(s1[len1]>='a'&&s1[len1]<='z'&&!broken[s1[len1]+10-'a'])
            {
                broken[10+s1[len1]-'a'] = true;
                str += s1[len1];
            }
            else if(s1[len1]=='_'&&!broken[36])
            {
                broken[36] = true;
                str += '_';
            }
        }
        else
        {
            ++len2;
        }
        ++len1;
    }
    for (int j = 0; j < str.length(); ++j) {
        if(str[j]>='a' && str[j]<='z')
            str[j] = str[j] - ('a' - 'A');
    }
    cout << str << endl;
    return 0;
}

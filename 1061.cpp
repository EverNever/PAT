// 1061

// 这里A-G以及A-N的范围很重要
// isalpha()  isdigit() isupper() islower()

#include <cstdio>
#include <iostream>

using namespace std;

string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
    // that is, "MON" for Monday, "TUE" for Tuesday, "WED" for Wednesday, "THU" for Thursday, "FRI" for Friday, "SAT" for Saturday, and "SUN" for Sunday.
    int d, h, m; // day, hour, min

    string s1, s2, s3, s4;
    cin >> s1;cin >> s2;cin >> s3;cin >> s4;

    int len=min(s1.length(), s2.length()); // 选择小的那个
    bool flag = false; // first time
    for (int i = 0; i < len; ++i) {
        if(s1[i]==s2[i])
        {
            if(!flag)
            {
                // A-G的范围
                if(s1[i]>='A' && s1[i]<= 'G'){
                    d=s1[i]-'A';
                    printf("%s ", week[d].c_str());
                    flag=true;
                }
            }
            else
            {
                // 转换h
                // A-N的范围
                if((s1[i] >= 'A' && s1[i] <= 'N') || isdigit(s1[i]))
                {
                    if(s1[i] >= 'A' && s1[i] <= 'N') // 要用N
                        h = s1[i] - 'A' + 10; // 注意加上10
                    else if(isdigit(s1[i]))
                        h = s1[i] - '0';
                    printf("%02d:", h);
                    break;
                }
            }
        }
    }
    len = min(s3.length(), s4.length());
    for (int j = 0; j < len; ++j) {
        // 字母
        if(s3[j]==s4[j] && isalpha(s3[j]))
        {
            if (j<60) m=j; // else 出错
            printf("%02d\n", m);
            break;
        }
    }

    return 0;
}


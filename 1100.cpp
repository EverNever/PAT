// 1100

// 只有16分,还有两个case死活弄不出来

// 根据读取的一行的s[0]>'a'判断是否地球文/火星文
// Earth->Mars   10进制转换为13进制,然后映射到vector<string>字母
// Mars->Earth  s.length()<=4是一位数,否则两位数 然后完成进制转换

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    getchar();
    string zero = "tret";
    vector<string> low = {"jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    vector<string> high = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

    string s;
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        if(s[0]>='a') // Mars to Earth
        {
            if (s.length()<=4) // 一位数
            {
                for (int j = 0; j < 12; ++j) {
                    if (low[j] == s)
                    {
                        cout << j+1 << endl;
                    }
                    else if(high[j] == s)
                        cout << j+13 << endl;
                }
                if(s==zero) cout << "0" << endl;
            }
            else // 两位数
            {
                char h[10], l[10];
                string hs,ls;
                sscanf(s.c_str(), "%s %s", h, l);
                hs=h;ls=l;
                int d=0;
                for (int j = 0; j < 12; ++j) {
                    // 低位
                    if (ls == low[j]){
                        d += j+1;
                        break;
                    }
                }
                for (int k = 0; k < 12; ++k) {
                    // 高位
                    if (hs == high[k]) {
                        d += (k + 1) * 13;
                        break;
                    }
                }
                cout << d <<endl;
            }
        }
        else // Earth to Mars
        {
            int num = stoi(s);
            if(num==0){
                cout << zero << endl;
                continue;
            }
            if(num<13)
            {
                cout << low[num%13-1] << endl;
                continue;
            }
            if(num/13 != 0) cout << high[num/13-1] << " ";
            cout << low[num%13-1] << endl;
        }
    }

    return 0;
}
// 1077

// 最长后缀问题
// 可以边输入边匹配的

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string suffix(string a, string b)
{
    string tmp="";
    int len1=a.length()-1;
    int len2=b.length()-1;

    while(len1>=0 && len2>=0)
    {
        if (a[len1] == b[len2])
        {
            tmp = a[len1] + tmp; // 这里顺序不能反,因为是倒着来的
            --len1;--len2;
        }
        else break;
    }
    if(tmp=="") tmp="nai";
    return tmp;
}

int main()
{
    int n;
    cin >> n;
    getchar();

    string a, b, c;
    getline(cin, a);
    for (int i = 1; i < n; ++i) {
        getline(cin, b);
//        cout << "a: " << a << " b: " << b <<endl;
        c = suffix(a, b);
        if(c=="nai")break;
        a = c;
    }
    cout << c << endl;

    return 0;
}


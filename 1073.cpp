// 1073

// The number is no more than 9999 bytes in length
// the exponent's absolute value is no more than 9999.
//[+-][1-9]"."[0-9]+E[+-][0-9]+
// 小数点前只有一位数,E后面可能有多位数

/*
 * E后面的+-很关键,确定是在数字前加0还是在后面加0
 * -e 小数点后输出e-1个0
 * +e
*/

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    char sign; // + - 号
    cin >> sign;
    if (sign=='-') cout<<'-';

    string str;
    string strE;
    int e;

    bool isPositive; // E是否为正

    char temp;
    bool flag=false;
    bool flag2=false;
    while(scanf("%c", &temp) != EOF)
    {
        if(temp=='E'){
            flag = true;
            continue;
        }

        if(!flag && temp!='.') {
            str.push_back(temp);
            continue;
        }

        if(flag){
            if(!flag2){
                isPositive = (temp == '+');
                flag2=true;
            }
            else
            {
                strE.push_back(temp);
            }
        }
    }
    e = stoi(strE);

    // TODO e == 0的情况
    if (!isPositive) // E是负数
    {
        cout << "0.";
        for (int i = 0; i < e - 1; ++i) {
            cout << '0';
        }
        cout << str;
    }
    else // E是正数
    {
        if(e<str.length()-1)
        {
            int i;
            for (i = 0; i <= e; ++i) {
                cout<<str[i];
            }
            cout<<'.';
            for (i; i < str.length(); ++i) {
                cout<<str[i];
            }
        }
        else
        {
            cout<<str;
            for (int i = 0; i < e - str.length() + 1; ++i) {
                cout<<'0';
            }
        }
    }

    return 0;
}
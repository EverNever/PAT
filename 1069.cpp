// 1069

// All the numbers must be printed as 4-digit numbers.
// int -> string
// string -> int

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <functional>

using namespace std;

int main()
{
    int c=0;
    scanf("%d", &c);

    string str;
    int a, b;

    do
    {
        str = to_string(c);
        while (str.length() < 4) str+="0"; // 补全缺少的0
        sort(str.begin(), str.end(), greater<char>());// 降序
//        cout << "str1: " << str1 << endl;
        a = stoi(str);

        sort(str.begin(), str.end());// 升序
        b = stoi(str);

        c = a - b;
        printf("%04d - %04d = %04d\n", a, b, c);
    }
    while (c!=6174 && c!=0);

    return 0;
}

/*
// 1069

// C version

#include <cstdio>


int main()
{
    int c=0;
    scanf("%d", &c);

    char str[4];
    int a, b;

    do
    {
        sprintf(str, "%04d", c); // int -> char*
        sort(str, str+4, greater<char>());// 降序
//        cout << "str: " << str << endl;
        sscanf(str, "%d", &a); // char* -> int

        sort(str, str+4);// 升序
        sscanf(str, "%d", &b);

        c = a - b;
        printf("%04d - %04d = %04d\n", a, b, c);
    }
    while (c!=6174 && c!=0);

    return 0;
}

*/

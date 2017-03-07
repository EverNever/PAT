//
// Created by 周超 on 09/02/2017.
//
#include <cstdio>
#include <iostream>

using namespace std;

void transfer(int r)
{
    int red[2];
    for(int i = 1; i >= 0; --i)
    {
        red[i] = r%13;
        r = r/13;
    }
    for(int i =0 ; i <= 1; ++i)
    {
        if(red[i] > 9 && red[i] < 13)
        {
            printf("%c", red[i] + 55); // output ascll English characters
        }
        else
            printf("%d", red[i]);
    }
}

int main()
{
    int r,g,b;
    scanf("%d %d %d", &r, &g, &b);
    // decimal to radix 13(0-9 and A-C), any English characters must be upper-cased
    // if a  single color is only 1-digit long, you must print a '0' to left
    printf("#");
    transfer(r);
    transfer(g);
    transfer(b);
    return 0;
}

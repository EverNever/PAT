//
// Created by 周超 on 08/02/2017.
//

// 非负整数<=10^100,所以和范围为0~891
// 二维数组存储所需的字符串,也可以用string

#include <cstdio>

char str[110];
int sum = 0;

char en[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {

    scanf("%s", str);

    for (int i = 0; i < 110; ++i)
    {
        if (str[i] != 0) {
            sum += (str[i] - 48);
        }
        else break;
    }
    if (sum >= 100)
        printf("%s %s %s", en[sum/100], en[sum/10%10], en[sum%100]);
    else if (sum >= 10)
        printf("%s %s", en[sum/10], en[sum%10]);
    else
        printf("%s", en[sum]);
    return 0;
}



//
// Created by 周超 on 07/02/2017.
//
#include <stdio.h>

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        int c = a + b;
        if (c < 0) {
            // 这里取绝对值很必要,不能在后面if (c >= 1000000 || c <= -1000000)
            c = -c;
            printf("-");
        }
        if (c >= 1000000)
            // 因为中间要用隔3位用逗号隔开,所以用除数取余
            // %03d是三位右对齐,且少了的用0补齐
            printf("%d,%03d,%03d\n", c/1000000, (c/1000)%1000, c%1000);
        else if (c >= 1000)
            printf("%d,%03d\n", c/1000, c%1000);
        else
            printf("%d\n", c);
    }
    return 0;
}

// 1104

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    double sum=0;
    double temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        sum += temp*(n-i)*(i+1);
    }
    printf("%.2lf", sum);
    return 0;
}
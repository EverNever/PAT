// 1058

// in the standard form of "Galleon.Sickle.Knut"
// Galleon is an integer in [0, 107]
// Sickle is an integer in [0, 17)
// Knut is an integer in [0, 29)

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int A_G, A_S, A_K;
    int B_G, B_S, B_K;
    int S_G, S_S, S_K;
    int carryK, carryS;

    scanf("%d.%d.%d", &A_G, &A_S, &A_K);
    scanf("%d.%d.%d", &B_G, &B_S, &B_K);

    // 注意进位和取余即可
    S_K = A_K + B_K;
    carryK = S_K / 29;
    S_K = S_K%29;

    S_S = A_S + B_S + carryK;
    carryS = S_S / 17;
    S_S = S_S%17;

    S_G = A_G + B_G + carryS;

    printf("%d.%d.%d", S_G, S_S, S_K);
    return 0;
}
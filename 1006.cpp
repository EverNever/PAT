// 1006

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

// 前者晚于后者
bool isLater(int h1, int m1, int s1, int h2, int m2, int s2)
{
    if (h1>h2)
        return true;
    else if(h1<h2)
        return false;

    if (m1>m2)
        return true;
    else if(m1<m2)
        return false;

    if (s1>s2)
        return true;
    else if(s1<s2)
        return false;
}

int main()
{
    int m;
    char id_unlock[16], id_lock[16];
    char id_temp[16];

    scanf("%d", &m);

    int h1,m1,s1,h2,m2,s2;
    int hh1, mm1, ss1, hh2, mm2, ss2;

    scanf("%s %d:%d:%d %d:%d:%d", id_lock, &h1, &m1, &s1, &h2, &m2, &s2);
    strcpy(id_unlock, id_lock);

    for (int i = 1; i < m; ++i) {
        scanf("%s %d:%d:%d %d:%d:%d", id_temp, &hh1, &mm1, &ss1, &hh2, &mm2, &ss2);
        // temp更早sign in
        if(isLater(h1, m1, s1, hh1, mm1, ss1))
        {
            strcpy(id_unlock, id_temp);
            h1 = hh1; m1=mm1; s1=ss1;
        }
        // temp更晚sign out
        if(!isLater(h2, m2, s2, hh2, mm2, ss2))
        {
            strcpy(id_lock, id_temp);
            h2=hh2; m2=mm2; s2=mm2;
        }
    }

    cout << id_unlock << " " << id_lock << endl;
    return 0;
}
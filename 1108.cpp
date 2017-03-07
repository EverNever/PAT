// 1108

// When you calculate the average, those illegal numbers must not be counted in.
// 关键就在于判断是否合法

#include <cstdio>
#include <iostream>

using namespace std;

bool isLegal(string s)
{
    int pos=0;
    if(s[pos]=='-') ++pos;
    if(pos==s.length()) return false;

    int dotCount=0;
    for (int i = pos; i < s.length(); ++i) {
        if(s[i]=='.')
        {
            ++dotCount;
            if(dotCount>1) return false; // 小数点数多于1
            if(s.length()-i>3) return false; // 小数点后多于2位
        }
        else if(!isdigit(s[i]))
            return false; // 含有非数字
    }
    double num = stod(s);
    return num >= -1000 && num <= 1000;
}

int main()
{
    int n;
    cin >> n;
    double sum=0;
    int size=0;

    string temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        if (isLegal(temp))
        {
            sum += stod(temp);
            ++size;
        }
        else
        {
            cout << "ERROR: " << temp << " is not a legal number" << endl;
        }
    }

    if(size==0) cout << "The average of 0 numbers is Undefined" << endl;
    else if(size==1) printf("The average of 1 number is %.2lf", sum);
    else printf("The average of %d numbers is %.2lf", size, sum/size);

    return 0;
}
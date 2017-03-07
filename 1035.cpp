//
// Created by 周超 on 09/02/2017.
//
// 1035
// must record modify amount

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int modify = 0;
    int total;
    cin >> total;

    vector<string> accounts;

    int i = total;
    string user;
    string pwdTemp;
    string pwd;

    while( i > 0)
    {
        --i;
        cin >> user;
        cin >> pwdTemp;

        pwd = pwdTemp;
        for ( int j = 0; j < pwdTemp.length(); j++)
        {
            // replace 1 (one) by @, 0 (zero) by %, l by L, and O by o.
            if (pwdTemp[j] == '1') pwd[j] = '@';
            else if (pwdTemp[j] == '0') pwd[j] = '%';
            else if (pwdTemp[j] == 'l') pwd[j] = 'L';
            else if (pwdTemp[j] == 'O') pwd[j] = 'o';
        }
        if (!(pwd == pwdTemp))
        {
            // if modify
            ++modify;
            accounts.push_back(user + " " + pwd);
        }
    }

    // no modify
    if (modify == 0)
    {
        if (total == 1)
            cout << "There is 1 account and no account is modified" << endl;
        else
            cout << "There are " << total << " accounts and no account is modified" << endl;
    }
    else
    {
        cout << modify << endl;
        // a iterator for output accounts
        vector<string>::iterator it;
        for (it = accounts.begin(); it!= accounts.end(); ++it)
            cout << *it << endl;
    }
    return 0;
}

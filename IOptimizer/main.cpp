#include <bits/stdc++.h>
#include "Classes/User.h"

using namespace std;

int countUsers()
{
    fstream file;
    file.open("../.temp/userCnt", ios::in);
    string buffer;
    file >> buffer;
    file.close();
    int c = stoi(buffer);
    return c;
}

int main() {
    int userCnt = countUsers();
    string buffer;

    cout << "Current users: " << userCnt << endl;
    cout << "Welcome to IOptimizer" << endl;
    string userName, passWord;
    cout << "Enter database name: ";
    getline(cin, userName);
    cout << "Enter password: ";
    getline(cin, passWord);
    User myUsr = User(userName, passWord);

    bool found = myUsr.authenticate();
    if (found) {
        cout << "Database found!" << endl;
    } else {
        cout << "Database not found!" << endl;
        cout << "Create user? (y/N)";
        char c; cin >> c;
        //getline(cin, buffer);
        if (tolower(c) == 'y') {
            fstream file;
            file.open("../.temp/userCnt", ios::out);
            userCnt++;
            file << userCnt;
            file.close();
            file.open("../.user/users.tsv", ios::app);
            file << (userCnt - 1) << '\t'
                 << userName << '\t'
                 << passWord << '\n';
            file.close();
        } else {
            cout << "Goodbye!" << endl;
            exit(0);
        }
    }

    while (true) {
        cout << "Starting..." << endl;
        myUsr.showControlPanel();
    }
    return 0;
}
//
// Created by robin on 11/26/18.
//

#ifndef IOPTIMIZER_USER_H
#define IOPTIMIZER_USER_H

#include <bits/stdc++.h>
#include "Database.h"

using namespace std;

class User {
    string userName;
    string passWord;
    Database db;
public:
    User();
    User(string, string);
    bool authenticate();
    void showControlPanel();
};


#endif //IOPTIMIZER_USER_H

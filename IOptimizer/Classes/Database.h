//
// Created by robin on 11/26/18.
//

#ifndef IOPTIMIZER_DATABASE_H
#define IOPTIMIZER_DATABASE_H

#include <bits/stdc++.h>
#include "ProductIN.h"
#include "ProductOUT.h"

using namespace std;

class Database {
public:
    bool calculated;
    int wt;
    int ttl;
    vector <ProductIN> inProducts;
    vector <ProductOUT> outProducts;
    Database();
    Database(const string& fileName);
    void editDatabase();
    void calculateResult();
    void update(int id);
    void emptyDatabase();
};


#endif //IOPTIMIZER_DATABASE_H

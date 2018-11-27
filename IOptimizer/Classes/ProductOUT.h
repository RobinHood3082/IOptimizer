//
// Created by robin on 11/26/18.
//

#ifndef IOPTIMIZER_PRODUCTOUT_H
#define IOPTIMIZER_PRODUCTOUT_H

#include <bits/stdc++.h>

using namespace std;

class ProductOUT {
public:
    ProductOUT(const string &productID, const string &productName, int totalPrice, int totalDuration);

    const string &getProductID() const;

    const string &getProductName() const;

    int getTotalPrice() const;

    int getTotalDuration() const;

private:
    string productID;
    string productName;
    int totalPrice;
    int totalDuration;
};

#endif //IOPTIMIZER_PRODUCTOUT_H

//
// Created by robin on 11/26/18.
//

#ifndef IOPTIMIZER_PRODUCTIN_H
#define IOPTIMIZER_PRODUCTIN_H

#include <bits/stdc++.h>

using namespace std;

class ProductIN {
private:
    string productID;
    string productName;
    int unitPrice;
    int productDuration;
public:
    void setProductID(const string &productID);

    void setProductName(const string &productName);

    void setUnitPrice(int unitPrice);

    void setProductDuration(int productDuration);

    const string &getProductID() const;

    const string &getProductName() const;

    int getUnitPrice() const;

    int getProductDuration() const;
};


#endif //IOPTIMIZER_PRODUCTIN_H

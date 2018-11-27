//
// Created by robin on 11/26/18.
//

#include "ProductOUT.h"

const string &ProductOUT::getProductID() const {
    return productID;
}

const string &ProductOUT::getProductName() const {
    return productName;
}

int ProductOUT::getTotalPrice() const {
    return totalPrice;
}

int ProductOUT::getTotalDuration() const {
    return totalDuration;
}

ProductOUT::ProductOUT(const string &productID, const string &productName, int totalPrice, int totalDuration)
        : productID(productID), productName(productName), totalPrice(totalPrice), totalDuration(totalDuration) {}

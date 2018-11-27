//
// Created by robin on 11/26/18.
//

#include "ProductIN.h"

void ProductIN::setProductID(const string &productID) {
    ProductIN::productID = productID;
}

void ProductIN::setProductName(const string &productName) {
    ProductIN::productName = productName;
}

void ProductIN::setUnitPrice(int unitPrice) {
    ProductIN::unitPrice = unitPrice;
}

void ProductIN::setProductDuration(int productDuration) {
    ProductIN::productDuration = productDuration;
}


const string &ProductIN::getProductID() const {
    return productID;
}

const string &ProductIN::getProductName() const {
    return productName;
}

int ProductIN::getUnitPrice() const {
    return unitPrice;
}

int ProductIN::getProductDuration() const {
    return productDuration;
}

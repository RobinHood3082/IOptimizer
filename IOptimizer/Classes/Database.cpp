//
// Created by robin on 11/26/18.
//

#include "Database.h"

Database::Database() {
    this->calculated = false;
}

void Database::emptyDatabase() {
    cout << "Create new database? (y/N)";
    string buff;
    getline(cin, buff);
    getline(cin, buff);
    if (tolower(buff[0]) == 'y') {
        cout << "Enter total time: ";
        cin >> wt;
        cout << wt << endl;
        int cmd = 1;
        while (cmd) {
            cout << "1. Add more products" << endl;
            cout << "0. Done" << endl;
            cin >> cmd;
            getline(cin, buff);

            if (cmd == 0) break;
            ProductIN pr;
            string s = "";
            cout << "Enter product ID: ";
            getline(cin, s);
            pr.setProductID(s);
            cout << "Enter product name: ";
            getline(cin, s);
            pr.setProductName(s);
            cout << "Enter unit price: ";
            cin >> cmd;
            pr.setUnitPrice(cmd);
            cout << "Enter time needed to create: ";
            cin >> cmd;
            pr.setProductDuration(cmd);

            this->inProducts.push_back(pr);
        }
    } else {
        cout << "Goodbye!" << endl;
        exit(0);
    }

}

Database::Database(const string& fileName) {
    ifstream infile = ifstream("../.user/" + fileName + ".in");
    calculated = infile.good();
    bool mark = false;
    if (!calculated) {
        cout << "No infile detected" << endl;
        emptyDatabase();
        mark = true;
    }
    string buffer = fileName;
    if (mark) {
        update(stoi(buffer));
        return;
    }
    fstream file;
    file.open("../.user/" + fileName + ".in", ios::in);
    file >> buffer;
    cout << buffer << endl;
    this->wt = stoi(buffer);
    this->inProducts.clear();
    int c = 0;
    while (getline(file, buffer)) {
        ProductIN pr;
        string word;
        istringstream is(buffer);
        int cnt = 0;
        while (is >> word) {
            if (cnt == 0) {
                pr.setProductID(word);
            } else if (cnt == 1) {
                pr.setProductName(word);
            } else if (cnt == 2) {
                pr.setUnitPrice(stoi(word));
            } else {
                pr.setProductDuration(stoi(word));
            }
            cnt++;
        }
        this->inProducts.push_back(pr);
        if (c == 0) this->inProducts.pop_back();
        c++;
    }
    file.close();
}

void Database::update(int id) {
    fstream file;
    file.open("../.user/" + to_string(id) + ".out", ios::out);
    file << this->ttl << '\n';
    for (int i = 0; i < this->outProducts.size(); i++) {
        file << this->outProducts[i].getProductID() << '\t'
             << this->outProducts[i].getProductName() << '\t'
             << this->outProducts[i].getTotalPrice() << '\t'
             << this->outProducts[i].getTotalDuration() << '\n';
    }
    file.close();
    file.open("../.user/" + to_string(id) + ".in", ios::out);
    file << this->wt << '\n';
    for (int i = 0; i < this->inProducts.size(); i++) {
        file << this->inProducts[i].getProductID() << '\t'
             << this->inProducts[i].getProductName() << '\t'
             << this->inProducts[i].getUnitPrice() << '\t'
             << this->inProducts[i].getProductDuration() << '\n';
    }
    file.close();
}

void Database::calculateResult() {
    cout << "Calculation Running..." << endl;
    int dp[105][10005];
    int v[105];
    int w[105];
    int n = inProducts.size();

    for (int i = 0; i < n; i++) {
        v[i] = inProducts[i].getUnitPrice();
        w[i] = inProducts[i].getProductDuration();
    }
    cout << "Total products: " << n << endl;
    cout << "Available time unit: " << wt << endl;
    for (int i = 0; i < n; i++) {
        cout << v[i] << " " << w[i] << endl;
    }
    cout << "---" << endl;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= this->wt; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (w[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    ttl = dp[n][this->wt];
    cout << "Maximum possible price: " << ttl << endl;
    int res = this->ttl;
    int wx = wt;
    for (int i = n; i > 0 && res > 0; i--) {
        if (res == dp[i - 1][wx]) continue;
        else {
            ProductOUT pr = ProductOUT(inProducts[i - 1].getProductID(), inProducts[i - 1].getProductName(), inProducts[i - 1].getUnitPrice(), inProducts[i - 1].getProductDuration());
            outProducts.push_back(pr);
            res -= v[i - 1];
            wx -= w[i - 1];
        }
    }
    calculated = true;
    //cout << outProducts.size() << endl;
    //reverse(outProducts.begin(), outProducts.end());
    //outProducts.pop_back();
}

void Database::editDatabase() {

}

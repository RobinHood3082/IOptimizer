//
// Created by robin on 11/26/18.
//

#include "User.h"

User::User() {
    this->userName = "";
    this->passWord = "";
}

User::User(string userName, string passWord) {
    this->userName = userName;
    this->passWord = passWord;
}


bool User::authenticate() {
    fstream file;
    file.open("../.user/users.tsv", ios::in);
    string buffer;
    getline(file, buffer);
    while (getline(file, buffer)) {
        bool valid = true;
        string word;
        istringstream is(buffer);
        int cnt = 0;
        while (is >> word) {
            cnt++;
            if (cnt == 2) {
                valid = valid & (this->userName == word);
            } else if (cnt == 3) {
                valid = valid & (this->passWord == word);
            }
        }
        if (valid) return true;
    }
    return false;
}

void User::showControlPanel() {
    fstream file;
    file.open("../.user/users.tsv", ios::in);
    string buffer;
    getline(file, buffer);
    int id = 0;
    while (getline(file, buffer)) {
        bool valid = true;
        string word;
        istringstream is(buffer);
        int cnt = 0;
        while (is >> word) {
            cnt++;
            if (cnt == 2) {
                valid = valid & (this->userName == word);
            } else if (cnt == 3) {
                valid = valid & (this->passWord == word);
            }
        }
        if (valid) break;
        id++;
    }

    file.close();


    db.inProducts.clear();
    db = Database(to_string(id));

    menu:
    cout << "1: Show database" << endl;
    cout << "2: Calculate for current database" << endl;
    cout << "3: Show this menu" << endl;
    cout << "0: Exit" << endl;

    int cmd; cin >> cmd;
    switch (cmd) {
        default: {
            cout << "No such option" << endl;
            goto menu;
        }

        case 0: {
            exit(0);
        }

        case 1: {
            cout << "Available time: " << db.wt << endl;
            for (int i = 0; i < db.inProducts.size(); i++) {
                cout << db.inProducts[i].getProductID() << endl;
                cout << db.inProducts[i].getProductName() << endl;
                cout << "Price: " << db.inProducts[i].getUnitPrice() << endl;
                cout << "Duration: " << db.inProducts[i].getProductDuration() << endl;
                cout << "" << endl;
            }
        } break;

        case 2: {
            db.update(id);
            cout << "Calculating..." << endl;
            db.calculateResult();
            for (int i = 0; i < db.outProducts.size(); i++) {
                cout << db.outProducts[i].getProductID() << endl;
                cout << db.outProducts[i].getProductName() << endl;
                cout << "Price: " << db.outProducts[i].getTotalPrice() << endl;
                cout << "Duration: " << db.outProducts[i].getTotalDuration() << endl;
                cout << "" << endl;
            }
            cout << "Updating..." << endl;
            db.update(id);
        } break;

        case 3: {
            goto menu;
        }
    }

}
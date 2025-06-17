// 1406 에디터

#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    list<char> lt;
    for (char ch : s) {
        lt.push_back(ch);
    }
    auto idx = lt.end();

    int m;
    cin >> m;
    char c, temp;
    for (int i=0; i<m; i++) {
        cin >> c;
        if (c == 'P') {
            cin >> temp;
            lt.insert(idx, temp);
        }
        else if (c == 'L') {
            if (idx != lt.begin()) {
                idx --;
            }
        }
        else if (c == 'D') {
            if (idx != lt.end()) {
                idx ++;
            }
        }
        else if (c == 'B') {
            if (idx != lt.begin()) {
                auto del = --idx;
                idx = lt.erase(del);
            }
        }
    }

    for (char ch : lt) {
        cout << ch;
    }
}
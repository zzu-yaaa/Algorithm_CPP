// 11720 숫자의 합

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += s.at(i) - '0';
    }

    cout << sum;
    return 0;
}
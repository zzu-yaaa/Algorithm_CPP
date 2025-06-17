// 2675 문자열 반복

#include <iostream>
#include <string>
using namespace std;

int main() {
    int t, r;
    string s;

    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> r >> s;
        string result;
        for (int j=0; j<s.length();j++) {
            for (int k=0; k<r; k++) {
                result += s.at(j);
            }
        }
        cout << result << "\n";
    }


    return 0;
}
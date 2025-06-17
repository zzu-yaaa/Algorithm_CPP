// 10809 알파벳 찾기

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    vector<int> alpha(26,-1);
    cin >> s;

    for (int i=0; i<s.length(); i++) {
        if (alpha[s.at(i) - 'a'] == -1) {
            alpha[s.at(i) - 'a'] = i;
        }

    }

    for (int i=0; i<26; i++) {
        cout << alpha[i] << " ";
    }

    return 0;
}
// 1152 단어의 개수

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int answer = 1;
    for (int i=0; i<s.length();i++) {
        if (s.at(i) == ' ') {
            answer += 1;
        }
    }

    if (s.at(0) == ' ') {
        answer -= 1;
    }

    if (s.at(s.length()-1) == ' ') {
        answer -= 1;
    }

    cout << answer << "\n";

    return 0;
}
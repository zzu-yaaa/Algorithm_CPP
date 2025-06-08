#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;

    int alphabet[26] = {0};

    for(int i=0; i<s.length(); i++){
        int idx = s.at(i) - 'a';
        alphabet[idx] += 1;
    }

    for(int i=0; i<26; i++){
        cout << alphabet[i] << ' ';
    }

    return 0;
}
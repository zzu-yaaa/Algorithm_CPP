#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> num(31, 0);

    int temp;
    for (int i=0; i<28; i++) {
        cin >> temp;
        num[temp] = 1;
    }

    for (int i=1; i<=30; i++) {
        if (num[i] == 0) {
            cout << i << "\n";
        }
    }

    return 0;
}
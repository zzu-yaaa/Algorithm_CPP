#include <iostream>
using namespace std;

int main() {
    int max = -1;
    int idx = -1;

    int temp;
    for (int i=1; i<=9; i++) {
        cin >> temp;
        if (max < temp) {
            max = temp;
            idx = i;
        }
    }

    cout << max << "\n"
        << idx << "\n";

    return 0;
}
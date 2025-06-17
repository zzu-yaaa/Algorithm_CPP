// 2588 곱셈

#include <iostream>
using namespace std;

int main() {
    int a;
    int b;
    cin >> a >> b;

    cout << a * (b % 10) << "\n"
        << a * ((b/10) % 10) << "\n"
        << a * (b/100) << "\n"
        << a * b;

    return 0;
}
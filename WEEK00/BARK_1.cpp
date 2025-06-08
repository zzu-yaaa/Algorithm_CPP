//바킹독 배열 예제 문제 1
//주어진 수 중에 두 가지 수를 골라 합이 100이 되는 겯우가 있으면 1, 없으면 0 반환
#include <iostream>
using namespace std;

int main() {
    int n,temp;
    cin >> n;

    int a[101] = { 0 };
    for (int i=0; i<n; i++) {
        cin >> temp;
        if (a[temp] == 1) {
            cout << 1;
            return 1;
        }
        a[100-temp] = 1;
    }

    cout << 0;
    return 0;
}
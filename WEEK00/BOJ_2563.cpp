// 2563 색종이

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[101][101] = {0};
    int n;
    cin >> n;

    int x,y;
    for (int i=0; i<n; i++) {
        cin >> x >> y;
        for (int j=x; j<x+10; j++) {
            for (int k=y; k<y+10; k++) {
                arr[j][k] = 1;
            }
        }
    }

    int result = 0;
    for (int i=1; i<=100; i++) {
        for (int j=1; j<=100; j++) {
            if (arr[i][j] == 1) {
                result += 1;
            }
        }
    }

    cout << result;

    return 0;
}
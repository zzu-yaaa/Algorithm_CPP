// 2567 색종이 - 2

#include <iostream>
using namespace std;

int main() {
    int arr[102][102] = {0};
    int n;
    cin >> n;

    int x, y;
    for (int i=0; i<n; i++) {
        cin >> x >> y;
        for (int j=x; j<x+10; j++) {
            for (int k=y; k<y+10; k++) {
                arr[j][k] = 1;
            }
        }
    }

    int result=0;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    for (int i=1; i<=100; i++) {
        for (int j=1; j<=100; j++) {
            if (arr[i][j] == 0) continue;

            for (int k=0; k<4; k++) {
                x = i + dx[k];
                y = j + dy[k];
                if (x < 0 || y < 0 || x > 102 || y > 102) {
                    continue;
                }
                if (arr[x][y] == 0) {
                    result += 1;
                }
            }
        }
    }

    cout << result;

    return 0;
}
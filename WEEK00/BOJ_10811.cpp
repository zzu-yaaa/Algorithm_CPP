// 10811 바구니 뒤집기

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);

    for (int i=0; i<n; i++) {
        arr[i] = i+1;
    }

    int x,y;
    for (int i=0; i<m; i++) {
        cin >> x >> y;
        x -= 1;
        y -= 1;
        while(x < y) {
            swap(arr[x++], arr[y--]);
        }
    }

    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
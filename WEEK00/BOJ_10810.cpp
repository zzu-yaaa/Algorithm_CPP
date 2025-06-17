// 10810 공 넣기

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> arr(n,0);

    int i,j,k;
    for (int a=0; a<m; a++) {
        cin >> i >> j >> k;
        for (int b=i-1; b<j; b++) {
            arr[b] = k;
        }
    }

    for (int temp : arr) {
        cout << temp << " ";
    }

    return 0;
}
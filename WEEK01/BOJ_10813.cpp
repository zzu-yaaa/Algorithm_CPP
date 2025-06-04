#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        arr[i] = i+1;
    }

    int a, b, temp;
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        // temp = arr[a-1];
        // arr[a-1] = arr[b-1];
        // arr[b-1] = temp;

        swap(arr[a-1], arr[b-1]);
    }

    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
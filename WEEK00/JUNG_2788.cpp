#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/** 삼중 for문 - O(N^3)**/
// int main() {
//     int n;
//     cin >> n;
//
//     vector<int> arr(n);
//     int temp;
//     for (int i=0; i<n; i++) {
//         cin >> temp;
//         arr[i] = temp;
//     }
//
//     sort(arr.begin(), arr.end());
//
//     int cnt = 0;
//     for (int i=0; i<n-2; i++) {
//         for (int j=i+1; j<n-1; j++) {
//             for (int k=j+1; k<n; k++) {
//                 if (arr[j]-arr[i] <= arr[k]-arr[j] && (arr[j]-arr[i])*2 >= arr[k]-arr[j]) {
//                     cnt += 1;
//                 }
//             }
//         }
//     }
//
//     cout << cnt;
//
//     return 0;
// }

/**이중 for문 - O(N^2logN)**/
int main() {
    int n;
    cin >> n;

    vector<int> arr;
    int temp;
    for (int i=0; i<n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    int cnt = 0;
    for (int i=0; i<n-2; i++) {
        for (int j=0; j<n-1;j++) {
            int len = arr[j] - arr[i];
            int lower = lower_bound(arr.begin()+j+1, arr.end(), arr[j] + len) - arr.begin();
            int upper = upper_bound(arr.begin()+j+1, arr.end(), arr[j] + (len * 2)) - arr.begin();
            cnt += (upper - lower);
        }
    }

    cout << cnt;

    return 0;
}
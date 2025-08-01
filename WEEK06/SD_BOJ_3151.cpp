// 3151 합이 0

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int arr[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    long long ans = 0;
    for (int i=0; i<n-2; i++) {
        int pick = arr[i] * -1;
        int low = i+1;
        int high = n-1;
        while (low<high) {
            int temp = arr[low] + arr[high];
            if (temp == pick) {
                if (arr[low] == arr[high]) {
                    int k = high - low + 1;
                    ans += (long long)k * (k - 1) / 2;
                    break;
                }

                int idx = low;
                while (arr[++idx] == arr[low]);
                int low_cnt = idx - low;
                low = idx;

                idx = high;
                while (idx - 1 >= low && arr[idx - 1] == arr[high]) idx--;
                int high_cnt = high - idx + 1;
                high = idx - 1;


                ans += high_cnt * low_cnt;
            }
            else if (temp < pick) {
                low++;
            }
            else if (temp > pick) {
                high--;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
// 1920 수 찾기

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a;
vector<int> num;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, temp, m;

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> temp;
        a.push_back(temp);
    }

    cin >> m;
    for (int i=0;i<m;i++) {
        cin >> temp;
        num.push_back(temp);
    }

    sort(a.begin(), a.end());
    for (int i=0; i<m; i++) {
        int low = 0;
        int high = n-1;

        int found = 0;
        while (low <= high) {
            int mid = (low+high)/2;

            if (num[i] == a[mid]) {
                found = 1;
                break;
            }
            if (num[i] > a[mid]) {
                low = mid + 1;
            }
            else if (num[i] < a[mid]){
                high = mid - 1;
            }
        }
        cout << found << "\n";
    }


    return 0;
}
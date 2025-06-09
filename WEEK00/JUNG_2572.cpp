#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    queue<int> q;
    int cnt[d+1] = {0};
    int kind = 0, ans = -1;

    //초기값
    for (int i= 0; i<k; i++) {
        q.push(arr[i]);
        if (cnt[arr[i]] == 0) kind += 1;
        cnt[arr[i]] += 1;
    }
    ans = kind + (cnt[c] == 0? 1: 0);

    for (int i=1; i<n; i++) {
        int remove = q.front();
        q.pop();
        cnt[remove] -= 1;
        if (cnt[remove] == 0) kind -= 1;

        int add = arr[(i+k-1) % n];
        q.push(add);
        if (cnt[add] == 0) kind += 1;
        cnt[add] += 1;

        ans = max(ans, kind + (cnt[c] == 0? 1: 0));
    }

    cout << ans << "\n";
    return 0;
}
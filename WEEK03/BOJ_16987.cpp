// 16987 계란으로 계란치기

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int power[9];
int weight[9];
int ans = -1;

void func(int egg) {
    if (egg == n) {
        int cnt = 0;
        for (int i=0; i<n; i++) {
            if (power[i] <= 0) cnt++;
        }
        ans = max(ans, cnt);
        return;
    }

    if (power[egg] <= 0) {
        func(egg+1);
        return;
    }

    bool attack = false;
    for (int i=0; i<n; i++) {
        if (i == egg || power[i] <= 0) continue;

        power[egg] -= weight[i];
        power[i] -= weight[egg];
        attack = true;
        func(egg+1);
        power[egg] += weight[i];
        power[i] += weight[egg];
    }
    if (!attack) {
        func(egg+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(power, power+9, 0);
    fill(weight, weight+9, 0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> power[i] >> weight[i];
    }

    func(0);

    cout << ans << "\n";

    return 0;
}
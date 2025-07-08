// 2240 자두

#include <iostream>
#include <algorithm>
using namespace std;

int d[1001][32];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, w;
    cin >> t >> w;

    for (int i=0; i<t; i++) {
        fill(d[i], d[i]+w+1, -1);
    }
    fill(d[0], d[0]+w+1, 0);


    int num;

    for (int i=1; i<=t; i++) {
        cin >> num;
        for (int j=0; j<=w; j++) {
            if (j > i) continue;
            if ((num == 1 && j%2 == 0) || (num == 2 && j%2 == 1)) {
                if (d[i-1][j] == -1) {
                    d[i][j] = d[i-1][j-1] + 1;
                }
                else {
                    d[i][j] = max(d[i-1][j], d[i-1][j-1])+1;}
            }
            else {
                d[i][j] = d[i-1][j];
            }
            cout << d[i][j] << " ";
        }
        cout << "\n";

    }

    // for (int i=1; i<=t; i++) {
    //     for (int j=0; j<= w; j++) {
    //         cout << d[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    int ans = -1;
    for (int i=0; i<=w; i++) {
        ans = max(ans, d[t][i]);
    }

    cout << ans << "\n";

    return 0;
}
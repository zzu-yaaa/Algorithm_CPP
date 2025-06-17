// 10818 최소, 최대

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int minValue = INT_MAX;
    int maxValue = INT_MIN;

    int temp;
    for (int i=0; i<n; i++) {
        cin >> temp;
        minValue = min(minValue, temp);
        maxValue = max(maxValue, temp);
    }

    cout << minValue << " " << maxValue;

    return 0;
}
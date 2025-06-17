// 1526 평균

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int temp, sum = 0, maxScore = -1;
    for (int i=0; i<n; i++) {
        cin >> temp;
        maxScore = max(maxScore, temp);
        sum += temp;
    }

    double result = (sum / (double)n)/maxScore * 100;
    cout << result;

    return 0;
}
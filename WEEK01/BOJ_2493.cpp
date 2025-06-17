// 2493 탑

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * 풀이2
 * - 왼쪽에서 오른쪽으로 입력을 받으며 순차적으로 진행
 * - 스택은 수신탑 후보들을 저장 (높이가 높은 것)
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, height;
    cin >> n;

    stack<pair<int, int> > st;
    st.push(make_pair(100000001, 0));

    for (int i=1; i<=n; i++) {
        cin >> height;
        while (st.top().first < height) {
            st.pop();
        }
        cout << st.top().second << " ";
        st.push(make_pair(height, i));
    }

    return 0;
}

/**
 * 풀이 1
 * - 입력을 모두 받고 뒤에서부터 앞으로 진행
 * - 스택은 아직 수신탑을 찾지 못한 송신탑들을 저장
 * - 자신보다 앞 기둥이 큰 경우
 *      ㄴ 정답 배열에 앞 기둥의 인덱스 저장
 *      ㄴ 스택(top)을 돌며 수신탑을 찾는 경우 정답 배열에 저장하고 pop
 * - 자신보다 앞 기둥이 작은 경우
 *      ㄴ 스택에 자신을 저장
 */

// int main() {
//     int n;
//     cin >> n;
//
//     int arr[n+2], ans[n+2];
//     stack<vector<int> > top;
//     vector<int> node;
//
//     arr[0] = 0;
//     for (int i = 1; i < n+1; i++) {
//         cin >> arr[i];
//     }
//
//     for (int i = n; i >= 1 ;  i--) {
//         if (arr[i-1] < arr[i]) {
//             //자신이 앞 기둥보다 키가 큰 경우
//             node.clear();
//             node.push_back(arr[i]);
//             node.push_back(i);
//             top.push(node);
//         }
//         else {
//             ans[i] = i-1;
//             while (!top.empty() && top.top().at(0) < arr[i-1]) {
//                 ans[top.top().at(1)] = i-1;
//                 top.pop();
//             }
//         }
//     }
//
//     while (!top.empty()) {
//         ans[top.top().at(1)] = 0;
//         top.pop();
//     }
//
//     for (int i=1; i<=n; i++) {
//         cout << ans[i] << " ";
//     }
//
//     return 0;
// }




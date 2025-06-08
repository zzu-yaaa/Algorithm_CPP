#include <iostream>
#include <stack>
using namespace std;

int main() {
    int k, n;
    stack<int> st;

    cin >> k;

    for (int i=0; i<k; i++) {
        cin >> n;
        if (n != 0) {
            st.push(n);
        }
        if (n == 0 &&  !st.empty()) {
            st.pop();
        }
    }

    int sum = 0;
    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }

    cout << sum << "\n";

    return 0;
}
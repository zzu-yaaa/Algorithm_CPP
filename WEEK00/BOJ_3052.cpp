#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    set<int> set;
    for (int i=0; i<10; i++) {
        cin >> n;
        set.insert(n%42);
    }

    cout << set.size() << "\n";
    return 0;
}
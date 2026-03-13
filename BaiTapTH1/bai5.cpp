#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<int> check;

void hoan_vi() {
    if (a.size() == n) {
        for (int x : a) cout << x << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (check[i] != 1) {
            a.push_back(i);
            check[i] = 1;
            hoan_vi();
            a.pop_back();
            check[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    check.resize(n + 1, 0);
    hoan_vi();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

int sum_le(int idx) {
    if (idx >= n) return 0;

    if (a[idx] % 2) return a[idx] + sum_le(idx + 1);
    else return sum_le(idx + 1);
}  

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    cout << sum_le(0);



    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> tapcon;
void sinh_tap_con() {
    if (tapcon.size() == k) {
        for (int x : tapcon) cout << x << " ";
        cout << "\n";
        return;
    }
    int last = tapcon.empty() ? 1 : tapcon.back() + 1;
    for (int i = last; i <= n; i++) {
        tapcon.push_back(i);
        sinh_tap_con();
        tapcon.pop_back();
    }
}

int main() {
    cout << "nhap n va k:";
    cin >> n >> k;
    sinh_tap_con();

    
    return 0;
}
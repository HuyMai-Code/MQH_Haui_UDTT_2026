#include <bits/stdc++.h>
using namespace std;

int n;

int sum(int x) {
    if (x < 10) {
        return x;
    }
    return x % 10 + sum(x / 10);
}

int main() {
    cin >> n;
    cout << sum(n);

    return 0;
}
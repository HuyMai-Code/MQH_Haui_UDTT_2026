#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    int fibo[n + 1];
    fibo[1] = fibo[2] = 1;
    if (n == 1 || n == 2) cout << "Fibo thu n: " << 1;
    else {
        for (int i = 3; i <= n; i++) {
            fibo[i] = fibo[i - 1] + fibo[i - 2];
        }
        cout << "Fibo thu n: " << fibo[n];
    }

    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n;
int dp[100];

int fibo(int x) {
    if (x == 1 || x == 2) {
        return 1;
    }
    if (dp[x] != 0) return dp[x];
    dp[x] = fibo(x - 1) + fibo(x - 2);
    return dp[x];
}

int main() {
    cin >> n;
    cout << fibo(n);


    return 0;
}
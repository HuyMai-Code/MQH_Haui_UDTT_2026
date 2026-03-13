#include <bits/stdc++.h>
using namespace std;

int n;
string s = "";
void sinh_binary(int pos) {
    if (pos == n) {
        cout << s << "\n";
        return;
    }
    for (char c = '0'; c <= '1'; c++) {
        s += c;
        sinh_binary(pos + 1);
        s.pop_back();
    }
}

int main() {

    cin >> n;
    sinh_binary(0);

    return 0;
}
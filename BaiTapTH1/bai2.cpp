#include <bits/stdc++.h>
using namespace std;

int n;
string s = "";
void sinh_ab(int pos) {
    if (pos == n) {
        cout << s << "\n";
        return;
    }
    for (char c = 'a'; c <= 'b'; c++) {
        s += c;
        sinh_ab(pos + 1);
        s.pop_back();
    }
}

int main() {
    
    cin >> n;
    sinh_ab(0);

    return 0;
}
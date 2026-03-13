#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Nhap so vong: ";
    cin >> n;

    int idx = 1;

    for (int i = 1; i <= pow(2, n) - 1; i++) {
        if (i % 2) {
            if (n % 2) {
                if (idx == 1) {
                    cout << 1 << " sang " << 3 << "\n";
                    idx = 3;
                } else if (idx == 3) {
                    cout << 3 << " sang " << 2 << "\n";
                    idx = 2;
                } else {
                    cout << 2 << " sang " << 1 << "\n";
                    idx = 1;
                }
            } else {
                if (idx == 1) {
                    cout << 1 << " sang " << 2 << "\n";
                    idx = 2;
                } else if (idx == 3) {
                    cout << 3 << " sang " << 1 << "\n";
                    idx = 1;
                } else {
                    cout << 2 << " sang " << 3 << "\n";
                    idx = 3;
                }
            }
        } else {
            if (idx == 3) {
                cout << 1 << " sang " << 2 << "\n";
            } else if (idx == 2) {
                cout << 1 << " sang " << 3 << "\n";
            } else {
                cout << 2 << " sang " << 3 << "\n";
            }
        }
    }

    
    
    return 0;
}
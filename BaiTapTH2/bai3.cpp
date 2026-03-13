#include <bits/stdc++.h>
using namespace std;

void thapHN(int n, int a, int b, int c) {
    if (n == 1) {
        cout << a << " sang " << c << "\n";
        return;
    }

    thapHN(n - 1, a, c, b);
    thapHN(1, a, b, c);
    thapHN(n - 1, b, a, c);
}

int main() {
    int n;
    cout << "Nhap so vong: ";
    cin >> n;
    thapHN(n, 1, 2, 3);



    return 0;
}
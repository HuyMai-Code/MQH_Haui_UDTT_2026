#include <bits/stdc++.h>
using namespace std;

int ucln(int a, int b) {
    if (b == 0) return a;

    return ucln(b, a % b);
}

int main() {
    int a, b;
    cout << "Nhap a va b: ";
    cin >> a >> b;
    cout << "Uoc chung lon nhat: " << ucln(a, b);



    return 0;
}
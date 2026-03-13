#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cout << "Nhap a va b: ";
    cin >> a >> b;

    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    cout << "Uoc chung lon nhat: " << a;

    
    return 0;
}
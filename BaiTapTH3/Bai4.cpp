#include <bits/stdc++.h>
using namespace std;

float pow (float a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    if (n & 1) {
        return pow(a, n - 1) * a;
    }
    return pow(a, n/2) * pow(a, n/2);
}


int main() {
    float a;
    int n;
    cout << "Nhap so thuc a va so nguyen duong n: ";
    cin >> a >> n;

    cout << "Gia tri a mu n: " << pow(a, n);


    
    return 0;
}
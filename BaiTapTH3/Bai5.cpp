#include <bits/stdc++.h>
using namespace std;

float tinh_tong_duong(float a[], int l, int r) {
    if (l >= r) {
        if (a[l] > 0) return a[l];
        return 0;
    }
    
    int mid = (l + r) / 2;

    return tinh_tong_duong(a, l, mid) + tinh_tong_duong(a, mid + 1, r);
}

int main() {
    float a[20] = {-1.0, 2, 5, -10, 6.5, 1.1, 
    3.3, 3.5, -6, -9.3, 7.7, 3.6, 6.7, 0.01, 
    3, 5, 6, 8, 9, 3,
    };

    cout << tinh_tong_duong(a, 0, 19);

    
    return 0;
}
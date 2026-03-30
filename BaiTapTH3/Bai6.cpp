#include <bits/stdc++.h>
using namespace std;

int so_chan_nho_nhat(int a[], int l, int r) {
    if (l >= r) {
        if (a[l] & 1) return INT16_MAX;
        else return a[l];
    }
    int mid = (l + r) /2;

    return min(so_chan_nho_nhat(a, l, mid), so_chan_nho_nhat(a, mid + 1, r));
}

int main() {
    int a[20] = {1, 3, 5, 6, 1, 9, 13, 15, 16, 17, 4, 5, 10, 2, 5, 8, 11, 21, 22, 24};

    cout << "So chan nho nhat trong mang a la: "<< so_chan_nho_nhat(a, 0, 19);
    
    return 0;
}
#include<bits/stdc++.h>
#define maxn 15
using namespace std;
float ans = 0;

void timKiem(float a[], int l, int r) {
    if (l >= r) {
        ans = max(ans, a[l]);
        return;
    }

    int mid = (l + r) / 2;

    timKiem(a, l, mid);
    timKiem(a, mid + 1, r);

}

int main() {
    float a[maxn];
    cout << "Nhap danh sach:\n";

    for (int i = 0; i < maxn; i++) {
        cin >> a[i];
    }
    timKiem(a, 0, maxn - 1);
    cout << "Gia tri lon nhat: ";
    cout << ans;



    return 0;
}

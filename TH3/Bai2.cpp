#include<bits/stdc++.h>
#define maxn 15
using namespace std;

void merge(float a[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    float L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int i = 0; i < n2; i++) R[i] = a[mid + i + 1];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
        }
    }

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void merge_sort(float a[], int l, int r) {
    if (l >= r) return;

    int mid = (l + r) / 2;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);

    merge(a, l, mid, r);
}


int main() {
    float a[maxn];
    cout << "Nhap danh sach:\n";

    for (int i = 0; i < maxn; i++) {
        cin >> a[i];
    }
    merge_sort(a, 0, maxn - 1);
    cout << "Danh sach sau khi sap xep:\n";
    for (float x : a) cout << x << " ";


    return 0;
}

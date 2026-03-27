#include <bits/stdc++.h>
using namespace std;

const int n = 3;

struct HocSinh{
    string ten;
    string hoDem;
    int namSinh;
    string diaChi;
};

void hienThi(HocSinh hs[]) {
    cout << setw(10) << "Ten";
    cout << setw(15) << "Ho dem";
    cout << setw(10) << "Nam sinh";
    cout << setw(15) << "Dia chi";
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << setw(10) << hs[i].ten;
        cout << setw(15) << hs[i].hoDem;
        cout << setw(10) << hs[i].namSinh;
        cout << setw(15) << hs[i].diaChi;
        cout << "\n";
    }
}

void merge(HocSinh hs[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    HocSinh L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = hs[l + i];
    for (int i = 0; i < n2; i++) R[i] = hs[mid + i + 1];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].ten <= R[j].ten) {
            hs[k++] = L[i++];
        } else {
            hs[k++] = R[j++];
        }
    }

    while (i < n1) hs[k++] = L[i++];
    while (j < n2) hs[k++] = R[j++];

}

void merge_sort(HocSinh hs[], int l, int r) {
    if (l >= r) return;
    int mid = (l + r) /2;
    merge_sort(hs, l, mid);
    merge_sort(hs, mid + 1, r);
    merge(hs, l, mid, r);
}

int main() {
    HocSinh hs[n] = {
        {"Huy", "Mai Quang", 2006, "Ha Noi"},
        {"Duc", "Nguyen Huu", 2006, "Nghe An"},
        {"Anh", "Trinh Tuan", 2006, "Thanh Hoa"},
    };
    merge_sort(hs, 0, n - 1);
    hienThi(hs);

    
    return 0;
}
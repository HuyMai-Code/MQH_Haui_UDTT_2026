#include <bits/stdc++.h>
using namespace std;

const int n = 3;

struct HocSinh{
    string ten;
    string hoDem;
    int namSinh;
    string diaChi;
};

void hienThi(HocSinh x) {
    cout << setw(10) << x.ten;
    cout << setw(15) << x.hoDem;
    cout << setw(10) << x.namSinh;
    cout << setw(15) << x.diaChi;
    cout << "\n";
}
void mauHienThi() {
    cout << setw(10) << "Ten";
    cout << setw(15) << "Ho dem";
    cout << setw(10) << "Nam sinh";
    cout << setw(15) << "Dia chi";
    cout << "\n";
}

void hienThiDS(HocSinh hs[]) {
    mauHienThi();
    for (int i = 0; i < n; i++) {
        hienThi(hs[i]);
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

int timKiem(string name, HocSinh hs[]) {
    int l = 0;
    int r = n - 1;
    int ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (hs[mid].ten == name) {
            ans = mid;
            r = mid - 1;
        } else if (hs[mid].ten > name) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
    HocSinh hs[n] = {
        {"Huy", "Mai Quang", 2006, "Ha Noi"},
        {"Duc", "Nguyen Huu", 2006, "Nghe An"},
        {"Anh", "Trinh Tuan", 2006, "Thanh Hoa"},
    };
    merge_sort(hs, 0, n - 1);
    hienThiDS(hs);
    string name;
    cout << "Nhap ten hoc sinh can tim: ";
    cin >> name;
    int vt = timKiem(name, hs);
    if (vt == -1) {
        cout << "Khong tim thay hoc sinh\n";
    } else {
        cout << "Hoc sinh " << name << " o vi tri: " << vt + 1<< "\n";
        mauHienThi();
        hienThi(hs[vt]);
    }

    return 0;
}
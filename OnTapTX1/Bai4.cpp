#include<bits/stdc++.h>

using namespace std;

struct ChuyenBay {
    string soHieu;
    float giaVe;
    int soGhe;
};

void hienThi(ChuyenBay x) {
    cout << x.soHieu << " ";
    cout << x.giaVe<< " ";
    cout << x.soGhe<< " ";
    cout << "\n";
}

void hienThiDS(ChuyenBay b[], int i) {
    if (i == 6) return;
    if (b[i].giaVe > 250.0) {
        hienThi(b[i]);
    }
    hienThiDS(b, i + 1);
}

float timVeGiaThapNhat(ChuyenBay b[], int l, int r, float ans) {
    if (l >= r) {
        return b[l].giaVe;
    }
    int mid = (l + r) / 2;
    return min(timVeGiaThapNhat(b, l, mid, ans), timVeGiaThapNhat(b, mid + 1, r, ans));
}

void quayLui(ChuyenBay b[], vector<int> used, int i) {
    if (i == 4) {
        for (int x : used) {
            cout << b[x].soHieu << " ";
        }
        cout << "\n";
        return;
    }
    for (int j = 0; j < 6; j++) {
        if (used[i]) {

        }
    }
}

int main() {
    ChuyenBay b[6] = {
        {"VN001", 100.5, 10}, //0
        {"VN002", 200.5, 20},
        {"VN003", 300.5, 30},
        {"VN004", 400.5, 50},
        {"VN005", 500.5, 40},
        {"VN006", 600.5, 20},
    };
    hienThiDS(b, 0);
    cout << "Gia ve thap nhat: "<<timVeGiaThapNhat(b, 0, 5, FLT_MAX);
    return 0;
}

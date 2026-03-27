#include <iostream>
#include <iomanip>

using namespace std;

struct CongViec {
    string maCV;
    string tgBD;
    float tgTH;
};

struct NhanVien {
    string tenNV;
};

const int MAX = 10;
int x[MAX];
bool used[MAX];


void hienThiTieuDe() {
    cout << left << setw(12) << "Ma CV"
         << setw(15) << "Thoi Gian BD"
         << setw(15) << "Thoi Gian TH" << endl;
    cout << string(42, '-') << endl;
}

void hienThiMotCongViec(const CongViec& cv) {
    cout << left << setw(12) << cv.maCV
         << setw(15) << cv.tgBD
         << setw(15) << cv.tgTH << endl;
}


void thuatToanA1(CongViec cv[], int i) {
	if (i < 0) return;
    hienThiMotCongViec(cv[i]);
    thuatToanA1(cv, i - 1);
}


int thuatToanA2(CongViec cv[], int left, int right) {
	if(left > right)
		return 0; 
	if(left == right) { 
		return (cv[left].tgTH <= 0.5) ? 1 : 0;
	}
	int mid = (left + right) / 2;
	int cvLeft = thuatToanA2(cv, left, mid);
	int cvRight = thuatToanA2(cv, mid + 1, right);
	
	return cvLeft + cvRight;
} 


void thuatToanA3(CongViec cv[], NhanVien nv[], int n, int i) {
	if(i == n){ 
		cout << "Phan cong cong viec: " << endl;
		 for(int j = 0; j < n; j++) { 
		 	cout << cv[j].maCV << " -> " << nv[x[j]].tenNV << endl;
		 }
		 cout << string(20, '-') << endl;
		 return;
	}
	for(int j = 0; j < n; j++) { 
		if(!used[j]) { 
			x[i] = j;
			used[j] = true;
			thuatToanA3(cv, nv, n , i + 1);
			used[j] = false;
		}
	}
}


int main() {
    int n = 6;

    CongViec dsCV[MAX] = {
        {"CV1", "08:00", 0.5},
        {"CV2", "09:00", 1.0},
        {"CV3", "10:30", 0.25},
        {"CV4", "11:00", 2.0},
        {"CV5", "13:00", 0.5},
        {"CV6", "14:30", 1.5}
    };

    NhanVien dsNV[MAX] = {
        {"An"}, {"Binh"}, {"Cuong"}, {"Dung"}, {"Hoa"}, {"Lan"}
    };

    cout << "\n== A1 - Danh sach cong viec (nguoc) ==\n";
    hienThiTieuDe();
    thuatToanA1(dsCV, n - 1);

    cout << "\n== A2 - So cong viec co thoi gian <= 30 phut ==\n";
    int dem = thuatToanA2(dsCV, 0, n - 1);
    cout << "=> So cong viec <= 0.5 gio: " << dem << endl;

    cout << "\n== A3 - Cac phuong an phan cong cong viec ==\n";
    for (int i = 0; i < n; ++i) used[i] = false;
    thuatToanA3(dsCV, dsNV, n, 0);

    return 0;
}


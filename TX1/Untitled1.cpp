#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct ChuyenBay{ 
	string soHieu;
	int giaVe;
	int soGhe;
};

void hienThiTieuDe(){ 
	cout << left << setw(10) << "So Hieu"
		<< setw(10) << "Gia Ve"
		<< setw(10) << "So Ghe" << endl;
}
void hienThi1MayBay(const ChuyenBay &cb) { 
	cout << left << setw(10) << cb.soHieu
		<< setw(10) << cb.giaVe
		<< setw(10) << cb.soGhe << endl;
}
void thuatToanA1(ChuyenBay cb[], int i, int n){ 
	if(i <= n) { 
		return;
	}
	if(i == 0){ 
		hienThiTieuDe();
	}
	if(cb[i].giaVe > 700000) { 
		hienThi1MayBay(cb[i]);
	}
	thuatToanA1(cb, i + 1, n);
}

ChuyenBay thuatToanA2(ChuyenBay cb[], int left, int right){ 
	if(left == right){ 
		return cb[left];
	}
	int mid = (left + right) / 2;
	ChuyenBay cLeft = thuatToanA2(cb, left, mid);
	ChuyenBay cRight = thuatToanA2(cb, mid + 1, right);
	return (cLeft.giaVe < cRight.giaVe) ? cLeft : cRight;
}
const int MAX = 10;
int x[MAX];
void thuatToanA3(ChuyenBay cb[], int start, int n, int soluong){ 
	if(soluong == 4) { 
		for(int i = 0; i < n; i++) { 
			cout << left << setw(10) << cb[x[i]].soHieu 
				<<setw(10) << cb[x[i]].giaVe 
				<< setw(10) << cb[x[i]].soGhe << endl;
		}
		cout << "-------------------------" << endl;
		return;
	}
	for(int i = start; i < n; i++){ 
		x[soluong] = i;
		thuatToanA3(cb, start + 1, n, soluong + 1);
	}
}


int main(){ 
	int n = 6;
	ChuyenBay dsCB[n] = { 
		{"VN001", 1000000, 151},
		{"VN002",850000,150},
		{"VN003",650000,120},
		{"VN004",610000,100},
		{"VN005",900000,170},
		{"VN006",1000000,100}
	};
	cout << "Cac chuyen bay co gia ve > 700000 la: " << endl; 
	thuatToanA1(dsCB, 0, n);
	cout <<"Chuyen bay co gia ve thap nhat la: " <<endl; 
	ChuyenBay minGiaVe = thuatToanA2(dsCB , 0, n - 1);
	hienThiTieuDe();
	hienThi1MayBay(minGiaVe);
	thuatToanA3(dsCB, 0, n, 0);

} 

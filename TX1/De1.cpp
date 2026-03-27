#include <iostream>
#include <iomanip> 
#include <string> 
using namespace std;

struct CauThu{ 
	string hoVaTen;
	int namSinh; 
	int luongThang;
	int namBatDau;
};
struct ViTri{
	int vitri;
};
void hienThiTieuDe() { 
	cout << left << setw(20) << "Ho Va Ten" 
		<< setw(10) << "Nam Sinh" 
		<< setw(12) << "Luong Thang"
		<< setw(15) << "Nam Bat Dau" << endl;
}
void hienThi1CauThu(const CauThu &ct) { 
	cout << left << setw(20) << ct.hoVaTen
		<< setw(10) << ct.namSinh
		<< setw(12) << ct.luongThang
		<< setw(15) << ct.namBatDau << endl;
}

void thuatToanA1(CauThu ct[], int i, int n){ 
	if(i >= n){ 
		return;
	}
	if(i == 0) { 
		hienThiTieuDe();
	}
	hienThi1CauThu(ct[i]);
	thuatToanA1(ct, i + 1, n);
}

int thuatToanA2(CauThu ct[], int left, int right){ 
	if(left > right) { 
		return 0;
	}
	if(left == right) { 
		return (ct[left].namBatDau == 0) ? 1 : 0;
	}
	int mid = (left + right) / 2;
	int cLeft = thuatToanA2(ct, left, mid);
	int cRight = thuatToanA2(ct, mid + 1, right);
	return cLeft + cRight;
}
const int MAX = 10;
int x[MAX];
bool used[MAX];
int count = 0;

void thuatToanA3(CauThu ct[], ViTri vt[], int n, int pos){ 

	if(pos == n) { 
		count++;
		for(int j = 0; j < n; j++) { 
			cout << ct[j].hoVaTen << " -> " << vt[x[j]].vitri << endl;
		}
		cout << string(20, '-') << endl;
	}
	for(int j = 0; j < n ; j++) { 
		if(!used[j]) { 
			x[pos] = j;
			used[j] = true; 
			thuatToanA3(ct, vt, n, pos + 1);
			used[j] = false;
		}
	}
} 
int main() { 
	int n = 3;
	CauThu dsCT[n] = { 
		{"Vu Tien Khang", 3125, 10000, 1980},
		{"Nguyen Huy Hong", 7432, 78000, 0},
		{"Ba Chu Free", 4131, 65000, 0},
	};
	ViTri dsVT[n] = { 
		{1},
		{2},
		{3},
	};
	cout << "\nDANH SACH CAU THU:\n";
	thuatToanA1(dsCT, 0, n);
	int soChuaBatDau = thuatToanA2(dsCT, 0, n - 1);
	cout << "\nSo cau thu chua co nam bat dau: " << soChuaBatDau << endl;
	
	cout << "Chia vi tri: \n";
	
	thuatToanA3(dsCT, dsVT, n, 0);
	cout << "So hoan vi la: " << count << endl;
	
	return 0;
}

#include <iostream> 
#include <iomanip>
#include <string>
using namespace std;

struct HocSinh { 
	string hoVaTen;
	double diemTK; 
	string xepLoai; 
	int tienThuong;
};

void hienThiTieuDe(){ 
	cout << left << setw(20) << "Ho Va Ten"	
	 	<< setw(15) << "Xep Loai" << endl;
}

void hienThi1HocSinh(HocSinh &hs) { 
	cout << left << setw(20) << hs.hoVaTen
	 	<< setw(10) << hs.diemTK 
	 	<< setw(15) << hs.xepLoai 
	 	<< setw (12) << hs.tienThuong << endl;
}
int sum = 0;
int thuatToanA4(HocSinh hs[], int i, int n){ 
	if(i > n) { 
		return 0;
	}
	if(i == n) {
		return sum;
	}
	sum += hs[i].tienThuong;
	thuatToanA4(hs, i + 1 , n);
}

int thuatToanA5(HocSinh hs[], int left, int right) { 
	if(left > right) { 
		return 0;
	}
	if(left == right) { 
		return (hs[left].diemTK >= 7.0) ? 1 : 0;
	}
	int mid = (left + right) /2;
	int cLeft = thuatToanA5(hs, left,mid);
	int cRight = thuatToanA5(hs, mid + 1, right);
	
	return cLeft + cRight;
}

const int MAX = 10;
int x[MAX];

void thuatToanA6(HocSinh hs[], int start, int n, int soluong, int &count){ 
	if(soluong == 6) { 
	count++;
		for(int i = 0; i < n; i++){ 
			cout << hs[x[i]].hoVaTen << " -> " << hs[x[i]].xepLoai << endl;
		}
		cout << string(20, '-') << endl;
		return;
	} 
	for(int j = start; j < n; j++ ){
	 	x[soluong] = j;
	 	thuatToanA6(hs, j + 1,n, soluong + 1, count);
	 }
}

int main() { 
	int n = 7;
	HocSinh students[n] = {
		{"Nguyen Van An", 8.5, "Gioi", 500000},
		{"Tran Thi Binh", 7.2, "Kha", 300000},
		{"Pham Van Cu", 6.0, "Trung Binh", 100000},
		{"Le Thi Dit", 9.0, "Gioi", 600000},
		{"Nguyen Van Em", 7.5, "Kha", 400000},
		{"Tran Thi Fuka", 5.0, "Yeu", 50000},
		{"Pham Van Gino", 8.0, "Gioi", 450000}
	};

	int tongTienThuong = thuatToanA4(students, 0, n);
	cout << "Tong tien thuong la: " << tongTienThuong << endl;
	
	int so = thuatToanA5(students, 0, n - 1);
	cout << "So hoc sinh co diem >= 7.0: " << so << endl;
	int count;
	thuatToanA6(students, 0,n, 0, count);
	cout << "so hoan vi : " << count << endl;

	return 0;
}


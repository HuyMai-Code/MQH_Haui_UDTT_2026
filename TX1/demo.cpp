#include <bits/stdc++.h>
using namespace std;

struct CauThu {
	string hoTen;
	int namSinh;
	int luongThang;
	int namTD;
};


void A3(const vector<CauThu> &ds, int i, vector<int>& pos, vector<int>& x, vector<bool>& used, int &cnt){
	for(int j = 0; j < ds.size(); j++){
		if(!used[j]){
			x[i] = j;
			used[j] = true;
			if(i + 1 == ds.size()){
				cnt+=1;
				for(int u = 0; u <= i; u++){
					cout<<ds[u].hoTen<<"-" << pos[x[u]] << endl;
				}
				cout << endl;	
			}
			else
			{
				A3(ds, i + 1, pos, x, used, cnt);
			}
			used[j] = false;
		}
		
	}
}

void A6(const vector<CauThu> &ds, int n, int i, int k, int bd, vector<int> &x){
	for(int j = bd; j < n ; j++){
		x[i] = j;
		if(i+1 == k){
			for(int u = 0; u <= i; u ++){
				cout<<ds[x[u]].hoTen<<" ";
			}
			cout<<endl;
		}
		else{
			A6(ds,ds.size(),i+1,k,j+1,x);
		}
	}
}




int main(){
	vector<CauThu> ds = {
		{"Khanh ngu", 2000, 50000,0},
		{"Manh ngu", 2004, 50000,2020},
		{"Khang ngu", 2003, 50000,2019}
	};
	
	vector<int> x(200);
	vector<bool> used(100, false);
	int cnt = 0;
	vector<int> pos({1, 2, 3});
	
	x.clear();
	x.resize(200);
	
	A6(ds,ds.size(),0,2,0,x);
	cout<<endl<<cnt;
}

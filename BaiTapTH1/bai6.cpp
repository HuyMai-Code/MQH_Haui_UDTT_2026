#include <bits/stdc++.h>
using namespace std;

string ten[6] = {"Trang", "Cong", "Trung", "Binh", "Hoan", "Mai"};
int check[6] = {0};
vector<string> s;

void xep() {
    if (s.size() == 6) {
        for (string c : s) cout << c << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < 6; i++) {
        if (check[i] == 0) {
            s.push_back(ten[i]);
            check[i] = 1;
            xep();
            s.pop_back();
            check[i] = 0;
        }
    }
}

int main() {
    cout << "Cac cach xep 6 sinh vien vao 6 cho: \n";
    xep();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

string ten[6] = {"Trang", "Cong", "Trung", "Binh", "Hoan", "Mai"};
vector<string> s;


void liet_ke(int i) {
    if (i > 6) return;
    if (s.size() == 4) {
        for (string c : s) cout << c << " ";

        cout << "\n";
        return;
    }
    s.push_back(ten[i]);
    liet_ke(i + 1);
    s.pop_back();
    liet_ke(i + 1);
}


int main() {
    cout << "cac cach liet ke 4 sv tu 6 sv:" << "\n";
    liet_ke(0);
    return 0;
}
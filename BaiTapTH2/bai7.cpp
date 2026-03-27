#include <bits/stdc++.h>
using namespace std;

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int n, m;
int chess[10][10];
bool check = false;

void ma_di_tuan(int pos, int x, int y) {
    if (pos == n * m) {
        check = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << chess[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }
    for (int i = 0; i < 8; i++) {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        if (x2 > 0 && y2 > 0 && x2 <= n && y2 <= m && chess[x2][y2] == 0) {
            chess[x2][y2] = pos + 1;
            ma_di_tuan(pos + 1, x2, y2);
            chess[x2][y2] = 0;
        }
    }
}

int main() {

    cout << "Nhap kich co cua ban co n va m: ";
    cin >> n >> m;
    chess[1][1] = 1;
    ma_di_tuan(1, 1, 1);
    if (check == false) cout << "Khong co loi giai";

    return 0;
}
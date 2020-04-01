#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        int dx = x2 - x1;
        int dy = y2 - y1;
        if (dx == 0 && (a + b) > 0) {
            cout << "NO\n";
        } else if (dy == 0 && (c + d) > 0) {
            cout << "NO\n";
        } else {
            int rx = b - a;
            int ry = d - c;
            bool okx = true;
            if (rx > 0) {
                okx = (rx <= x2 - x);
            } else if (rx < 0) {
                okx = (-rx <= x - x1);
            }
            bool oky = true;
            if (ry > 0) {
                oky = (ry <= y2 - y);
            } else if (ry < 0) {
                oky = (-ry <= y - y1);
            }
            if (okx && oky) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}


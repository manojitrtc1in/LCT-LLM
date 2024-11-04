#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> l(n, vector<int>(5));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> l[i][j];
        }
    }
    if (n >= 50) {
        cout << 0 << endl;
        return 0;
    }
    if (n <= 2) {
        cout << n << endl;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << endl;
        }
        return 0;
    }
    set<int> er;
    for (int i = 0; i < n; i++) {
        int f = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i == j || i == k || j == k) {
                    continue;
                }
                int w = 0;
                for (int d = 0; d < 5; d++) {
                    w += (l[i][d] - l[j][d]) * (l[i][d] - l[k][d]);
                }
                if (w > 0) {
                    f = 1;
                    break;
                }
            }
            if (f == 1) {
                break;
            }
        }
        if (f == 0) {
            er.insert(i + 1);
        }
    }
    cout << er.size() << endl;
    for (int x : er) {
        cout << x << endl;
    }
    return 0;
}

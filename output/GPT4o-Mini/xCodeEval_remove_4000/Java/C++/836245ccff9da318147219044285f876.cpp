#include <bits/stdc++.h>
using namespace std;

const long mod = 1000000007;
const long mod2 = 998244353;

class id1 {
public:
    long pref[100005];
    
    void main() {
        int n;
        cin >> n;
        long a[n];
        input(a, n);
        if (n > 66) {
            cout << 1 << endl;
            return;
        }
        pref[1] = a[0];
        for (int i = 1; i < n; i++) pref[i + 1] = pref[i] ^ a[i];
        int gg = 34;
        for (int c = 0; c < n - 1; c++) {
            for (int left = c; left >= 0; left--) {
                for (int right = c + 1; right < n; right++) {
                    if (xorFunc(left, c) > xorFunc(c + 1, right)) gg = min(gg, right - left - 1);
                }
            }
        }
        cout << (gg == 34 ? -1 : gg) << endl;
    }

    long xorFunc(int i, int j) {
        return pref[j + 1] ^ pref[i];
    }

    void sort(int a[], int n) {
        vector<int> list(a, a + n);
        sort(list.begin(), list.end());
        for (int i = 0; i < n; i++) a[i] = list[i];
    }

    void sort(long a[], int n) {
        vector<long> list(a, a + n);
        sort(list.begin(), list.end());
        for (int i = 0; i < n; i++) a[i] = list[i];
    }

    void id0(int a[], int n) {
        random_shuffle(a, a + n);
        sort(a, n);
    }

    void id0(long a[], int n) {
        random_shuffle(a, a + n);
        sort(a, n);
    }

    void input(long a[], int n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }

    void input(int a[], int n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }

    void input(string s[], int n) {
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
    }

    void input(int a[][100], int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
    }

    void input(long a[][100], int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
    }
};

int main() {
    id1 g;
    g.main();
    return 0;
}

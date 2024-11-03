#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void pre(int n, int len) {
    vector<bool> np(n, false);
    np[0] = np[1] = true;
    for (int i = 0; i < n; i++) {
        if (!np[i]) {
            for (int j = i + i; j < n; j += i) {
                np[j] = true;
            }
        }
    }
    int div = n / len;
    vector<int> num(div, 0);
    for (int i = 0, i2 = 0, j = 0; i < n; i++) {
        if (i == 2 || (!np[i] && i % 4 == 1)) {
            num[j]++;
        }
        if (i2 == len - 1) {
            j++;
            i2 = 0;
        } else {
            i2++;
        }
    }
    cout << "[";
    for (int i = 0; i < div; i++) {
        cout << num[i];
        if (i != div - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void run() {
    int n = 310000000;
    int m = 100000;

    int l, r;
    cin >> l >> r;
    long long res = calc(r) - calc(l);
    cout << res << endl;
}

int n = 310000000;
int m = 100000;

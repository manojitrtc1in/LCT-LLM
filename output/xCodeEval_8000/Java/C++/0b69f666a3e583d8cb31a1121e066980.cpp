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
    for (int i = 0; i < div; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
}

int nextInt() {
    int x;
    cin >> x;
    return x;
}

long long nextLong() {
    long long x;
    cin >> x;
    return x;
}

double nextDouble() {
    double x;
    cin >> x;
    return x;
}

string next() {
    string s;
    cin >> s;
    return s;
}

string nextLine() {
    string s;
    getline(cin, s);
    return s;
}

void run() {
    int n = 310000000;
    int m = 100000;

    int l = nextInt(), r = nextInt() + 1;
    long long res = calc(r) - calc(l);
    cout << res << endl;
}

int n = 310000000, m = 100000;

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;
int a[5500], g[5500], n, m;
set<int> p;
int gcd(int a, int b) {
    return b? gcd (b, a%b) : a;
}


int f(int x) {
    map<int, int> m;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            while (x % i == 0) {
                m[i]++;
                x /= i;
            }
        }
    }
    if (x != 1) m[x]++;

    map<int, int> :: iterator it;
    int res = 0;
    for (it = m.begin(); it != m.end(); it++) {
        if (p.find((*it).first) != p.end()) {
            res -= (*it).second;
        } else {
            res += (*it).second;
        }
    }
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (m--) {
       int pr;
       cin >> pr;
       p.insert(pr);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += f(a[i]);
    }
    g[1] = a[0];
    for (int i = 2; i <= n; i++) {
        g[i] = gcd(g[i - 1], a[i - 1]);
    }
    int h = 1, t, res;
    for (int i = n - 1; i >= 0; i--) {
        t = g[i + 1] / h;
        res = f(t);
        if (res < 0) {
            sum -= res * (i + 1);
            h *= t;
        }
    }

    cout << sum << endl;
    return 0;
}




















































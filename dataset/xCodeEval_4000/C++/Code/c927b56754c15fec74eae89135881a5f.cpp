#include <iostream>
#include <stdio.h>
#include <string.h>
#include <bitset>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <math.h>
#include <iomanip>
 
#include <ratio>
#include <chrono>
#include <ctime>
typedef long long ll;
using namespace std;
#define all(v) v.begin(), v.end()
#define pb push_back
#define ff first
#define ss second
#define fori(n) for (int i = 0; i < n; i++)
#define forj(n) for (int j = 0; j < n; j++)
 
 
#pragma GCC optimize("unroll-loops", "no-stack-protector")
#pragma GCC optimize("Ofast", "fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
 

 



bool cmp(pair < int, int > &a, pair < int, int > &b) {
    return (a.ss - a.ff < b.ss - b.ff);
}
vector < bool > isUsed;
vector < vector < int > > g;
int cnt = 0;
void f(int v) {
    isUsed[v] = 1;
    cnt++;
    for (auto to: g[v]) {
        if (isUsed[to]) continue;
        f(to);
    }
}
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector < pair < int, int > > a;
    int x, y;
    fori(n) {
        cin >> x >> y;
        x--; y--;
        a.pb({x, y});
    }
    vector < int > who;
    who.resize(2 * n + 1);
    sort(all(a), cmp);
    fori(n) {
        who[a[i].ff] = i;
        who[a[i].ss] = i;
    }
    set < int > keks;
    g.resize(n);
    cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        keks.insert(a[i].ff);
        keks.insert(a[i].ss);
        auto z = keks.upper_bound(a[i].ff);
        while (true) {
            if (*z == a[i].ss) break;
            g[i].pb(who[*z]);
            g[who[*z]].pb(i);
            cnt++;
            if (cnt >= n) {
                cout << "NO\n";
                return 0;
            }
            z = keks.upper_bound(*z);
        }
    }
    if (cnt != n - 1) {
        cout << "NO\n";
        return 0;
    }
    cnt = 0;
    isUsed.resize(n);
    f(0);
    if (cnt != n) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
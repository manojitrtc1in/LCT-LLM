#include <bits/stdc++.h>

using namespace std;

#define ft first
#define nd second
#define long long long
#define uxv (u-1)*m+v
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef pair < int, int > ii;
typedef pair < int, ii > i3;
const int N = 1e6 + 2;
long n, m;
long a[N];
long Max[2][N];
vector < i3 > listNum;

int main() {
#ifndef ONLINE_JUDGE
    freopen("E.inp", "r", stdin);
    freopen("E.out", "w", stdout);
#endif 

    fast;

    cin >> n >> m;
    for(int u = 1; u <= n; ++u)
        for(int v = 1; v <= m; ++v) {
            cin >> a[uxv];
            listNum.push_back({a[uxv], {u, v}});
        }
    sort(listNum.begin(), listNum.end());
    for(int i = 0; i < listNum.size(); ++i) {
        int temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]) + 1;
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);
        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        temp = i;
        do {
            int u = listNum[temp].nd.ft, v = listNum[temp].nd.nd;
            Max[0][u] = max(Max[0][u], a[uxv]);
            Max[1][v] = max(Max[1][v], a[uxv]);
            temp ++;
        } while (temp < listNum.size() && listNum[temp].ft == listNum[temp-1].ft);

        do {
            int u = listNum[i].nd.ft, v = listNum[i].nd.nd;
            a[uxv] = max(Max[0][u], Max[1][v]);
            i ++;
        } while (i < listNum.size() && listNum[i].ft == listNum[i-1].ft);
        
        i --;
    }
    for(int u = 1; u <= n; ++u) {
        for(int v = 1; v <= m; ++v) cout << a[uxv] << ' ';
        cout << '\n';
    }
}

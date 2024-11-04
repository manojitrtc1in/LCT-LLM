
 
#include <bits/stdc++.h>
#define all(n) (n).begin(), (n).end()
#define se second
#define fi first
#define pb push_back
#define mp make_pair
#define sqr(n) (n)*(n)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<ll, int> PLI;
typedef vector<int> VI;
typedef double db;

template<class T1, class T2> bool umin(T1& a, T2 b) { return a > b ? (a = b, true) : false; }
template<class T1, class T2> bool umax(T1& a, T2 b) { return a < b ? (a = b, true) : false; }
template<class T> void clear(T& a) { T().swap(a); }

const int N = 2e5 + 5;

int n, m, _, k;
int a[N];

int main() {
    IOS;
    for (cin >> _; _; --_) {
        cin >> n; k = m = 0;
        rep (i, 1, n) {
            cin >> a[i];
            if (a[i] == 1 && a[i - 1] == 0) k += (m ? i - m - 1 : 0);
            else if (a[i] == 0 && a[i - 1] == 1) m = i - 1;
        }
        cout << k << '\n';
    } 
    return 0;
}
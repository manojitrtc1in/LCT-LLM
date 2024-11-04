

#include <bits/stdc++.h>
using namespace std;
#define May_the_fork_be_with_you ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define rall(v) v.rbegin(),v.rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define deb(x) cout<<#x<<": "<<x<<endl;
#define debn(x) cout<<#x<<": "<<x<<"  ";
#define MOD 1000000007
#define INF 1e18
#define ll long long
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define int long long
#define N 100005


#define sq(x) ((x)*(x))
typedef vector<int> vi;
ll gcd(ll a, ll b) {if (!b)return a; return gcd(b, a % b);}
ll power(ll x, ll y, ll p = INF) {ll result = 1; x %= p; while (y > 0) {if (y & 1)result = (result * x) % p; y = y >> 1; x = (x * x) % p;} return result;}

int res = 0;
vector<vector<int>> result;

void c0(int i, int j) {
    result.pb({i, j, i, j + 1, i + 1, j});
}
void c1(int i, int j) {
    result.pb({i, j, i, j + 1, i + 1, j + 1});
}
void c2(int i, int j) {
    result.pb({i, j, i + 1, j, i + 1, j + 1});
}
void c3(int i, int j) {
    result.pb({i + 1, j, i, j + 1, i + 1, j + 1});
}

void proc4(int x0, int x1, int x2, int x3, int i, int j, int idx) {
    if (idx == 0) {
        c3(i, j);
    }
    if (idx == 1) {
        c2(i, j);
    }
    if (idx == 2) {
        c1(i, j);
    }
    if (idx == 3) {
        c0(i, j);
    }
}

void proc3(int x0, int x1, int x2, int x3, int i, int j, int idx) {
    if (idx == 0) {
        c3(i, j);
        proc4(x0, x1, x2, x3, i, j, 1);
    }
    if (idx == 1) {
        c0(i, j);
        proc4(x0, x1, x2, x3, i, j, 2);
    }
    if (idx == 2) {
        c3(i, j);
        proc4(x0, x1, x2, x3, i, j, 2);
    }
    if (idx == 3) {
        c0(i, j);
        proc4(x0, x1, x2, x3, i, j, 1);
    }
}

void proc2(int x0, int x1, int x2, int x3, int i, int j, int idx) {
    if (idx == 0) {
        c3(i, j);
        proc4(x0, x1, x2, x3, i, j, 3);
    }
    if (idx == 1) {
        c2(i, j);
        proc4(x0, x1, x2, x3, i, j, 2);
    }
}

void proc1(int x0, int x1, int x2, int x3, int i, int j, int idx) {
    if (idx == 0) {
        c0(i, j);
        proc2(x0, x1, x2, x3, i, j, 1);
    }
    if (idx == 1) {
        c1(i, j);
        proc2(x0, x1, x2, x3, i, j, 0);
    }
    if (idx == 2) {
        c2(i, j);
        proc2(x0, x1, x2, x3, i, j, 0);
    }
    if (idx == 3) {
        c3(i, j);
        proc2(x0, x1, x2, x3, i, j, 1);
    }
}

void help(int x0, int x1, int x2, int x3, int i, int j) {
    

    if (x0 == 0 && x1 == 0 && x2 == 0 && x3 == 0) return;
    if (x0 == 1 && x1 == 1 && x2 == 1 && x3 == 1) {
        res += 4;
        c3(i, j);
        proc1(x0, x1, x2, x3, i, j, 0);
    }
    if (x0 == 1 && x1 == 0 && x2 == 0 && x3 == 0) {
        res += 3;
        proc1(x0, x1, x2, x3, i, j, 0);
    }
    if (x0 == 0 && x1 == 1 && x2 == 0 && x3 == 0) {
        res += 3;
        proc1(x0, x1, x2, x3, i, j, 1);
    }
    if (x0 == 0 && x1 == 0 && x2 == 1 && x3 == 0) {
        res += 3;
        proc1(x0, x1, x2, x3, i, j, 2);
    }
    if (x0 == 0 && x1 == 0 && x2 == 0 && x3 == 1) {
        res += 3;
        proc1(x0, x1, x2, x3, i, j, 3);
    }

    if (x0 == 1 && x1 == 0 && x2 == 0 && x3 == 1) {
        res += 2;
        proc2(x0, x1, x2, x3, i, j, 0);
    }
    if (x0 == 0 && x1 == 1 && x2 == 1 && x3 == 0) {
        res += 2;
        proc2(x0, x1, x2, x3, i, j, 1);
    }

    if (x0 == 1 && x1 == 1 && x2 == 0 && x3 == 0) {
        res += 2;
        proc3(x0, x1, x2, x3, i, j, 0);
    }
    if (x0 == 0 && x1 == 0 && x2 == 1 && x3 == 1) {
        res += 2;
        proc3(x0, x1, x2, x3, i, j, 1);
    }
    if (x0 == 1 && x1 == 0 && x2 == 1 && x3 == 0) {
        res += 2;
        proc3(x0, x1, x2, x3, i, j, 2);
    }
    if (x0 == 0 && x1 == 1 && x2 == 0 && x3 == 1) {
        res += 2;
        proc3(x0, x1, x2, x3, i, j, 3);
    }

    if (x0 == 0 && x1 == 1 && x2 == 1 && x3 == 1) {
        res += 1;
        proc4(x0, x1, x2, x3, i, j, 0);
    }
    if (x0 == 1 && x1 == 0 && x2 == 1 && x3 == 1) {
        res += 1;
        proc4(x0, x1, x2, x3, i, j, 1);
    }
    if (x0 == 1 && x1 == 1 && x2 == 0 && x3 == 1) {
        res += 1;
        proc4(x0, x1, x2, x3, i, j, 2);
    }
    if (x0 == 1 && x1 == 1 && x2 == 1 && x3 == 0) {
        res += 1;
        proc4(x0, x1, x2, x3, i, j, 3);
    }

}

void solve(int t) {
    result.clear();
    res = 0;
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    for1(i, n)for1(j, m) cin >> a[i][j];
    if (n == 2 && m == 2) {
        int i = 1, j = 1;
        int x0 = a[i][j] - '0', x1 = a[i][j + 1] - '0', x2 = a[i + 1][j] - '0', x3 = a[i + 1][j + 1] - '0';
        

        help(x0, x1, x2, x3, i, j);
        a[i][j] = '0';
        a[i + 1][j] = '0';
        a[i][j + 1] = '0';
        a[i + 1][j + 1] = '0';
    }
    for (int i = 1; i <= n - 2; i++) {
        for (int j = 1; j <= m - 2; j++) {
            int x0 = a[i][j] - '0', x1 = a[i][j + 1] - '0', x2 = a[i + 1][j] - '0', x3 = a[i + 1][j + 1] - '0';
            

            

            if (x0 == 1 && x2 == 1) {
                res++;
                result.pb({i, j, i + 1, j, i, j + 1});
                a[i][j] = '0';
                a[i + 1][j] = '0';
                if (x1 == 1) a[i][j + 1] = '0';
                else a[i][j + 1] = '1';
            }
            else if (x2 == 1) {
                res++;
                result.pb({i + 1, j, i, j + 1, i + 1, j + 1});
                a[i + 1][j] = '0';
                if (x1 == 1) a[i][j + 1] = '0';
                else a[i][j + 1] = '1';
                if (x3 == 1) a[i + 1][j + 1] = '0';
                else a[i + 1][j + 1] = '1';
            }
            else if (x0 == 1) {
                res++;
                result.pb({i, j, i, j + 1, i + 1, j + 1});
                a[i][j] = '0';
                if (x1 == 1) a[i][j + 1] = '0';
                else a[i][j + 1] = '1';
                if (x3 == 1) a[i + 1][j + 1] = '0';
                else a[i + 1][j + 1] = '1';
            }
            

            

            

            

            

            

            

            

            

            

        }
    }
    

    int i, j;
    i = n - 1;
    for (int j = 1; j <= m - 1; j++) {
        int x0 = a[i][j] - '0', x1 = a[i][j + 1] - '0', x2 = a[i + 1][j] - '0', x3 = a[i + 1][j + 1] - '0';
        if (x0 == 1 && x2 == 1) {
            res++;
            result.pb({i, j, i + 1, j, i, j + 1});
            a[i][j] = '0';
            a[i + 1][j] = '0';
            if (x1 == 1) a[i][j + 1] = '0';
            else a[i][j + 1] = '1';
        }
        else if (x2 == 1) {
            res++;
            result.pb({i + 1, j, i, j + 1, i + 1, j + 1});
            a[i + 1][j] = '0';
            if (x1 == 1) a[i][j + 1] = '0';
            else a[i][j + 1] = '1';
            if (x3 == 1) a[i + 1][j + 1] = '0';
            else a[i + 1][j + 1] = '1';
        }
        else if (x0 == 1) {
            res++;
            result.pb({i, j, i, j + 1, i + 1, j + 1});
            a[i][j] = '0';
            if (x1 == 1) a[i][j + 1] = '0';
            else a[i][j + 1] = '1';
            if (x3 == 1) a[i + 1][j + 1] = '0';
            else a[i + 1][j + 1] = '1';
        }
        

        

        

        

        

        

        

        

        

        

    }
    

    j = m - 1;
    for (int i = 1; i <= n - 1; i++) {
        int x0 = a[i][j] - '0', x1 = a[i][j + 1] - '0', x2 = a[i + 1][j] - '0', x3 = a[i + 1][j + 1] - '0';
        

        

        if (x0 == 1 && x1 == 1) {
            res++;
            result.pb({i, j, i, j + 1, i + 1, j + 1});
            a[i][j] = '0';
            a[i][j + 1] = '0';
            if (x3 == 1) a[i + 1][j + 1] = '0';
            else a[i + 1][j + 1] = '1';
        }
        else if (x1 == 1) {
            res++;
            result.pb({i + 1, j, i, j + 1, i + 1, j + 1});
            a[i][j + 1] = '0';
            if (x2 == 1) a[i + 1][j] = '0';
            else a[i + 1][j] = '1';
            if (x3 == 1) a[i + 1][j + 1] = '0';
            else a[i + 1][j + 1] = '1';
        }
        else if (x0 == 1) {
            res++;
            result.pb({i, j, i + 1, j, i + 1, j + 1});
            a[i][j] = '0';
            if (x2 == 1) a[i + 1][j] = '0';
            else a[i + 1][j] = '1';
            if (x3 == 1) a[i + 1][j + 1] = '0';
            else a[i + 1][j + 1] = '1';
            

        }
        

        

        

        

        

        

        

        

        

        

    }
    i = n - 1, j = m - 1;
    int x0 = a[i][j] - '0', x1 = a[i][j + 1] - '0', x2 = a[i + 1][j] - '0', x3 = a[i + 1][j + 1] - '0';
    

    help(x0, x1, x2, x3, i, j);
    a[i][j] = '0';
    a[i + 1][j] = '0';
    a[i][j + 1] = '0';
    a[i + 1][j + 1] = '0';
    

    

    

    

    

    cout << res << endl;
    for (auto x : result) cout << x[0] << " " << x[1] << " " << x[2] << " " << x[3] << " " << x[4] << " " << x[5] << endl;
}

int32_t main() {

#ifndef ONLINE_JUDGE
    

    freopen("input.txt", "r", stdin);
    

    freopen("output.txt", "w", stdout);
#endif

    May_the_fork_be_with_you
    int t = 1;
    int x = 1;
    cin >> t;
    cout << fixed << setprecision(12);
    while (t--) {
        

        solve(x);
        x++;
    }

    cerr << "Time Taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
}
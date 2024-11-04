











#include <bits/stdc++.h>

#include <random>

#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()

#define pb push_back


using namespace std;
void dout() { cerr << endl; }


template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << H << ' ';
    dout(T...);
}



using hll = __int128;

using ll = long long;


using pii = pair<ll, ll>;
using ld = double;
using pll = pair<long long, long long>;

template <typename T>
void do_uniq(vector<T> vec){
    sort(all(vec));
    vec.resize(unique(all(vec)) - vec.begin());
}

clock_t timestamp_start = clock();
void time_calc()
{
    cerr << (ld)(clock() - timestamp_start) / CLOCKS_PER_SEC << "\n";
}


#ifdef _getchar_nolock
#else
#define _getchar_nolock getchar_unlocked
#endif






#ifdef solvsh
#else

ll mod = 998244353;

ll add(ll a, ll b){
    return (a + b) % mod;
}
ll ml(ll a, ll b) {
    return (a * b) % mod;
}

ll sub(ll a, ll b) {
    return add(a, mod - b);
}

ll sq(ll v) {
    return ml(v, v);
}

const int MAXN = 5005 + 31;















































ll INF = 1e9;



















struct chtDynamic {
    struct line {
        ll m, b;
        pair<ll, ll> x;
        ll val;
        bool isQuery;

        line(ll _m = 0, ll _b = 0) : m(_m), b(_b), val(0), x({-INF, 1}), isQuery(false) {}

        ll eval(ll x) const { return m * x + b; }

        bool parallel(const line &l) const { return m == l.m; }

        pair<ll, ll> intersect(const line &l) const {
            if (parallel(l)) return {INF, 1};

            if (m < l.m) return {(b - l.b), (l.m - m)};

            return {(l.b - b), (m - l.m)};
        }

        bool operator<(const line &l) const {
            if (l.isQuery)
                return x.first < l.val * x.second;
            else
                return m < l.m;
        }
    };

    set<line> hull;
    typedef set<line>::iterator iter;

    bool cPrev(iter it) { return it != hull.begin(); }

    bool cNext(iter it) { return it != hull.end() && next(it) != hull.end(); }

    bool bad(const line &l1, const line &l2, const line &l3) { return l1.intersect(l3) <= l1.intersect(l2); }

    bool bad(iter it) { return cPrev(it) && cNext(it) && bad(*prev(it), *it, *next(it)); }

    iter update(iter it) {
        if (!cPrev(it))
            return it;
        auto x = it->intersect(*prev(it));
        line tmp(*it);
        tmp.x = x;
        it = hull.erase(it);
        return hull.insert(it, tmp);
    }

    void addLine(ll m, ll b) {
        line l(m, b);
        iter it = hull.lower_bound(l);
        if (it != hull.end() && l.parallel(*it)) {
            if (it->b < b)
                it = hull.erase(it);
            else
                return;
        }

        it = hull.insert(it, l);
        if (bad(it))
            return (void) hull.erase(it);

        while (cPrev(it) && bad(prev(it)))
            hull.erase(prev(it));
        while (cNext(it) && bad(next(it)))
            hull.erase(next(it));

        it = update(it);
        if (cPrev(it))
            update(prev(it));
        if (cNext(it))
            update(next(it));
    }

    ll query(ll x) const {
        if (hull.empty())
            return -INF;
        line q;
        q.val = x, q.isQuery = 1;
        iter it = --hull.lower_bound(q);
        return it->eval(x);
    }
} ds;



class Uva10003 {


    void solveT() {


    }

public:

    void solve() {

        for (;;) {
            int l;
            cin >> l;

            if (l == 0) return;

            int n;
            cin >> n;


            vector<int> ci;

            ci.push_back(0);

            for (int i = 0; i < n; ++i) {
                int c;
                cin >> c;
                ci.push_back(c);
            }

            ci.push_back(l);
            ++n;


            vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
            vector<vector<int>> mids(n + 1, vector<int>(n + 1, 0));

            for (int i = 0; i < n; ++ i) {
                mids[i][i] = i + 1;
            }

            for (int len = 2; len <= n; ++len) {
                for (int start = 0; start + len - 1 <= n; ++start) {
                    int fin = start + len - 1;

                    int minn = 1e9;
                    int minindx = -1;

                    int mleft = mids[start][fin - 1];
                    int mright = mids[start + 1][fin];

                    for (int mid = mleft; mid <= mright; ++mid) {
                        if (minn >  dp[start][mid - 1] + dp[mid][fin] + ci[fin + 1] - ci[start]) {
                            minn =  dp[start][mid - 1] + dp[mid][fin] + ci[fin + 1] - ci[start];
                            minindx = mid;
                        }
                    }

                    dp[start][fin] = minn;
                    mids[start][fin] = minindx;
                }
            }



































            cout << "The minimum cutting is " << dp[0][n - 1] << ".\n";
        }
    }
};



class Uva10304 {

public:

    void solve() {

        int n;
        while (cin >> n) {
            vector<int> vec;
            for (int i =  0; i < n; ++ i ){
                int curr;
                cin >> curr;
                vec.push_back(curr);
            }

            vector<vector<int>> dp(n + 2, vector<int> (n + 2, 0));
            vector<int> preff;
            preff.push_back(0);
            for (auto e : vec) preff.push_back(preff.back() + e);

            for (int len = 2; len <= n; ++ len) {
                for (int start = 1; start + len - 1 <= n; ++ start) {
                    int fin = start + len - 1;

                    int minn = 1e9;

                    for (int mid = start; mid <= fin; ++ mid ){

                        int suml = preff[mid - 1] - preff[start - 1];
                        int sumr = preff[fin] - preff[mid];

                        minn = min(minn, dp[start][mid - 1] + dp[mid + 1][fin] + sumr + suml);
                    }

                    dp[start][fin] = minn;
                }
            }


            cout << dp[1][n] << "\n";
        }

    }


    void solveFast() {

        int n;
        while (cin >> n) {
            vector<int> vec;
            for (int i =  0; i < n; ++ i ){
                int curr;
                cin >> curr;
                vec.push_back(curr);
            }

            vector<vector<int>> dp(n + 2, vector<int> (n + 2, 0));
            vector<vector<int>> mids(n + 2, vector<int> (n + 2, 0));

            for (int i = 0; i <= n; ++ i) mids[i][i] = i;
            vector<int> preff;
            preff.push_back(0);
            for (auto e : vec) preff.push_back(preff.back() + e);

            for (int len = 2; len <= n; ++ len) {
                for (int start = 1; start + len - 1 <= n; ++ start) {
                    int fin = start + len - 1;

                    int minn = 1e9;

                    int mleft = mids[start][fin - 1];
                    int mright = mids[start + 1][fin];

                    int minindx = -1;

                    for (int mid = mleft; mid <= mright; ++ mid ){

                        int suml = preff[mid - 1] - preff[start - 1];
                        int sumr = preff[fin] - preff[mid];

                        int val = dp[start][mid - 1] + dp[mid + 1][fin] + sumr + suml;

                        if (val < minn) {
                            minn = val;
                            minindx = mid;
                        }

                    }

                    dp[start][fin] = minn;
                    mids[start][fin] = minindx;
                }
            }


            cout << dp[1][n] << "\n";
        }

    }
};


class CHEFAOR{




    

    void solveTSlow(){

        int n, k;
        cin >> n >> k;
        vector<vector<ll>> dp(k + 1, vector<ll> (n + 1, -1e18));

        vector<ll> v;

        for (int i = 0 ; i < n; ++ i) {

            int curr;
            cin >> curr;
            v.push_back(curr);
        }


        vector<ll> xorseg;

        dp[0][0] = 0;


        vector<vector<ll>> ors(n + 1, vector<ll>(n + 1, -1e18));

        for (int i = 0; i <= n; ++ i) {
            ll acc = 0;
            for (int j = i; j >= 1; --j) {

                acc |= v[j - 1];

                ors[j][i] = acc;
            }
        }


        for (int i = 1; i <= k; ++ i) {

            for (int j = 1; j <= n; ++ j) {

                if (i == 1) {
                    dp[i][j] = ors[1][j];
                    continue;
                }
                ll maxx = dp[i][j];

                for (int t = j - 1; t >= 1; --t) {
                    maxx = max(maxx, dp[i - 1][t] + ors[t + 1][j]);
                }

                dp[i][j] = maxx;
            }

        }


        cout << dp[k][n] << '\n';
    }

    int cnt = 0;


#ifndef ONLINE_JUDGE
#define MAXN 505
#else
#define MANN 5005
#endif


    ll dp[MAXN][MAXN];


    vector<ll> v;

    void rec(int iter, int l, int r, int mleft, int mright){
        ++cnt;

        if (l > r) return;




        int mid = (l + r) >> 1;

        ll maxx = dp[iter][mid];
        int maxindx = -1;


        ll acc = 0;
        for (int i = mid - 1; i >= min(mright, mid - 1) ; --i) acc |= v[i];

        for (int t = min(mright, mid - 1); t >= max(1, mleft); --t) {
            ll val = dp[iter - 1][t] + acc;

            if (val > maxx) {
                maxx = val;
                maxindx = t;
            }

            acc |= v[t - 1];
        }

        dp[iter][mid] = maxx;
        if (l <= mid - 1)
            rec(iter, l, mid - 1, mleft, maxindx);
        if (mid + 1 <= r)
            rec(iter, mid + 1, r, maxindx, mright);
    }

    void solveT(){

        int n, k;
        cin >> n >> k;

        v.clear();

        for (int i = 0; i <= n; ++ i) for (int j = 0; j <= n; ++ j)  dp[i][j] = -1e18;


        for (int i = 0 ; i < n; ++ i) {

            int curr;
            cin >> curr;
            v.push_back(curr);
        }

        dp[0][0] = 0;


        for (int i = 1; i <= k; ++ i) {
            if (i == 1) {

                ll acc = 0;
                for (int j = 1; j <= n; ++j) {
                    acc |= v[j - 1];
                    dp[i][j] = acc;
                }
                continue;
            }

            rec(i, 1, n, 1, n);
        }

        cout << dp[k][n] << '\n';
    }

public:
    void solve(){

        int t;
        cin >> t;
        while (t--) {
            solveT();
        }
    }
};



class Codeforces834 {

#ifndef ONLINE_JUDGE
#define MAXN 505
#else
#define MAXN 35555
#endif

#define MAXK 55

    int typesMeet[MAXN];


    ll dp[MAXK][MAXN];


    vector<ll> v;

    void rec(int iter, int l, int r, int mleft, int mright){

        if (l > r) return;




        int mid = (l + r) >> 1;

        ll maxx = dp[iter][mid];
        int maxindx = -1;


        { 
            for (int i = mid - 1; i >= min(mright, mid - 1); --i) {
                typesMeet[v[i]] = 0;
            }
            for (int t = min(mright, mid - 1); t >= max(1, mleft); --t) {
                typesMeet[v[t - 1]] = 0;
            }
        }

        int cnt = 0;

        for (int i = mid - 1; i >= min(mright, mid - 1) ; --i) {
            if (!typesMeet[v[i]]) {
                ++cnt;
                ++typesMeet[v[i]];
            }
        }

        for (int t = min(mright, mid - 1); t >= max(1, mleft); --t) {
            ll val = dp[iter - 1][t] + cnt;

            if (val > maxx) {
                maxx = val;
                maxindx = t;
            }

            if (!typesMeet[v[t - 1]]) {
                ++cnt;
                ++typesMeet[v[t - 1]];
            }
        }

        dp[iter][mid] = maxx;
        if (l <= mid - 1)
            rec(iter, l, mid - 1, mleft, maxindx);
        if (mid + 1 <= r)
            rec(iter, mid + 1, r, maxindx, mright);
    }

    void solveT(){

        int n, k;
        cin >> n >> k;

        v.clear();

        for (int i = 0; i <= k; ++ i) for (int j = 0; j <= n; ++ j)  dp[i][j] = -1e18;


        for (int i = 0 ; i < n; ++ i) {
            int curr;
            cin >> curr;
            v.push_back(curr);
        }

        dp[0][0] = 0;

        for (int i = 1; i <= k; ++ i) {
            if (i == 1) {

                int cnt = 0;

                for (int j = 1; j <= n; ++j) {
                    if (!typesMeet[v[j - 1]]) {
                        ++cnt;
                        ++typesMeet[v[j - 1]];
                    }
                    dp[1][j] = cnt;
                }
                continue;
            }

            rec(i, 1, n, 1, n);
        }

        cout << dp[k][n] << '\n';
    }

public:

    void solve(){
        solveT();
    }
};

class Codeforces319C {


    vector<ll> ai;
    vector<ll> bi;
    vector<ll> dp;

    struct line {

        ll k, b;

        ld intersec(const line &other) {
            return (other.b - b) / (k - other.k + 0.);
        }

        ll eval(ll x) {
            return k * x + b;
        }
    };

    vector<line> lines;

    void add_line(ll k, ll b){

        if (lines.empty()) {
            lines.push_back({k, b});
            return;
        }

        line q = {k, b};

        while (lines.size() >= 2) {
            int n = lines.size();
            if (lines[n - 2].intersec(q) > lines[n - 1].intersec(q))  {
                lines.pop_back();
            } else {
                break;
            }
        }

        lines.push_back(q);
    }

    ll getmin(ll x) {


        int left = -1;
        int right = lines.size() - 1;

        while (right - left > 1) {

            int mid = (right + left) >> 1;

            if (lines[mid].intersec(lines[mid + 1]) <= x) {
                left = mid;
            } else {
                right = mid;
            }
        }


        return lines[left + 1].eval(x);
    }

public:
    void solve(){

        int n;
        cin >> n;

        for (int i = 0; i < n; ++ i) {
            int curr;
            cin >> curr;
            ai.push_back(curr);
        }

        for (int i = 0; i < n; ++ i) {
            int curr;
            cin >> curr;
            bi.push_back(curr);
        }


        dp.push_back(0);

        add_line(bi[0], dp.back());

        for (int i = 1; i < n; ++i) {
            ll val = getmin(ai[i]);
            dp.push_back(val);
            add_line(bi[i], dp.back());
        }

        cout << dp.back() << "\n";
    }
};

void gen(){

    int n = 5000;
    cout <<"1\n";
    cout << n << "\n";

    for (int i = 0; i < n;++i ){
        int curr = rand();

        cout << curr << " ";
    }

}

void solve() {













    Codeforces319C().solve();
}


#endif

void multisolve() {
    int t;
    cin >> t;

    int i = 1;
    while (t--) {


        solve();


        i++;
    }
}

#define int int
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(20);

#ifndef ONLINE_JUDGE
    freopen("../input.in", "r", stdin);
    freopen("../output.out", "w", stdout);
#else

#endif
#ifdef multi
    

    multisolve();
#else
    solve();


#endif
    time_calc();
}

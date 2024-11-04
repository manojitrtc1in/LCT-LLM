#include <iostream>
#include<bits/stdc++.h>

#define ll long long
#define ii pair<ll,ll>
#define fi first
#define se second
#define mod 1000000007
using namespace std;

class p445A {
public:
    void solve() {
        ll n;
        cin >> n;
        unordered_map<ll, ll> cnt;
        ll mx = 0;
        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;
            mx = max(mx, a);
            cnt[a]++;
        }
        vector<ll> dp(mx + 1, 0);
        for (ll i = 1; i <= mx; i++) {
            dp[i] = max(dp[i], dp[i - 1]);
            if (!cnt.count(i)) continue;
            dp[i] = max(dp[i - 1], (i >= 2 ? dp[i - 2] : 0) + cnt[i] * i);
        }
        cout << dp[mx] << endl;
    }
};

class p550A {
public:
    void solve() {
        string s;
        cin >> s;
        int l = -1;
        int cnt[2][2];
        memset(cnt, -1, sizeof(cnt));
        auto check = [&cnt](string &s, int flag) {
            for (int i = 0; i < s.size() - 1; i++) {
                if (s[i] == 'A' && s[i + 1] == 'B' && cnt[flag][0] == -1) {
                    cnt[flag][0] = i + 1;
                }
                if (s[i] == 'B' && s[i + 1] == 'A' && cnt[flag][1] == -1) {
                    cnt[flag][1] = i + 1;
                }
            }
        };
        check(s, 0);
        reverse(s.begin(), s.end());
        check(s, 1);
        if (cnt[0][1] != -1 && cnt[1][1] != -1 && cnt[0][1] + 1 + cnt[1][1] + 1 <= s.size()) cout << "YES" << endl;
        else if (cnt[0][0] != -1 && cnt[1][0] != -1 && cnt[0][0] + 1 + cnt[1][0] + 1 <= s.size()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
};

class p550C {
public:
    void solve() {
        string s;
        cin >> s;
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(8, 0));
        vector<vector<int>> pre(n + 1, vector<int>(8, -1));
        

        bool ok = false;
        for (int i = 1; i <= n; i++) {
            int ai = s[i - 1] - '0';
            dp[i][ai % 8] = 1;
            for (int j = 0; j < 8; j++) {
                if (dp[i - 1][j] == 1) {
                    dp[i][(10 * j + ai) % 8] = 1;
                    dp[i][j] = 1;

                    pre[i][(10 * j + ai) % 8] = j;
                    pre[i][j] = j;
                }
            }
            if (dp[i][0] == 1) ok = 1;
        }
        if (ok == 0) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            string ans;
            for (int i = 1; i <= n; i++) {
                if (dp[i][0] == 1) {
                    int ci = i, cj = 0;
                    while (ci > 0) {
                        if (pre[ci][cj] == -1 || pre[ci][cj] != cj) {
                            ans.append(1, s[ci - 1]);
                        }
                        if (pre[ci][cj] == -1) break;
                        cj = pre[ci][cj];
                        ci--;
                    }
                    reverse(ans.begin(), ans.end());
                    cout << ans << endl;
                    break;
                }
            }
        }
    }
};

class p545C {
public:
    void solve() {
        int n;
        cin >> n;
        vector<ii > tree;
        for (int i = 0; i < n; i++) {
            ll x, h;
            cin >> x >> h;
            tree.emplace_back(x, h);
        }
        if (n == 1) cout << 1 << endl;
        else {
            int res = 1;
            int pre = 0;
            for (int i = 1; i < n; i++) {
                if (pre == 0) {
                    if (tree[i].fi - tree[i].se > tree[i - 1].fi) {
                        res++;
                    } else if (i == n - 1 || tree[i + 1].fi > tree[i].fi + tree[i].se) {
                        pre = 1;
                        res++;
                    }
                } else {
                    if (tree[i].fi - tree[i].se > tree[i - 1].fi + tree[i - 1].se) {
                        pre = 0;
                        res++;
                    } else if (i == n - 1 || tree[i + 1].fi > tree[i].fi + tree[i].se) {
                        pre = 1;
                        res++;
                    } else pre = 0;
                }
            }
            cout << res << endl;
        }
    }
};

class p166E {
public:
    vector<vector<ll>> matrixmul(const vector<vector<ll>> &a, const vector<vector<ll>> &b) {
        int n = a.size();
        vector<vector<ll>> c(n, vector<ll>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                    c[i][j] %= mod;
                }
            }
        }
        return c;
    }

    vector<vector<ll>> fmul(vector<vector<ll>> &matrix, int n) {
        vector<vector<ll>> res(matrix.size(), vector<ll>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) res[i][i] = 1;
        while (n >= 1) {
            if (n & 1) {
                res = matrixmul(res, matrix);
            }
            n = n >> 1;
            matrix = matrixmul(matrix, matrix);
        }
        return res;
    }

    void solve() {
        int n;
        cin >> n;
        vector<vector<ll>> a(4, vector<ll>(4, 1));
        for (int i = 0; i < 4; i++) a[i][i] = 0;
        auto res = fmul(a, n);
        cout << res[3][3] << endl;
    }
};

class p676C {
public:
    void solve() {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int a = 0, b = 0;
        int res = 0;
        for (int l = 0, r = 0; l < n; l++) {
            while (min(a, b) <= k && r < n) {
                res = max(res, a + b);
                if (s[r] == 'a') a++;
                else b++;
                r++;
            }
            if (min(a, b) <= k) res = max(res, a + b);
            if (s[l] == 'a') a--;
            else b--;
        }
        cout << res << endl;
    }
};

class p839C {
public:
    double ans;
    vector<vector<int>> e;

    void dfs(int fa, int cur, double pre) {
        double pro =
                e[cur].size() <= 1 ? (fa == -1 ? pre : 0.0) : pre / (fa == -1 ? e[cur].size() : (e[cur].size() - 1));
        for (int next:e[cur]) {
            if (next == fa) continue;
            ans += pro;
            dfs(cur, next, pro);
        }
    }

    void solve() {
        int n;
        cin >> n;
        e.clear();
        e = vector<vector<int>>(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        ans = 0.0;
        dfs(-1, 0, 1);
        printf("%.15lf\n", ans);
    }
};

class p1272D {
public:
    void solve() {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> l(n, 0), r(n, 0);
        l[0] = 1;
        for (int i = 1; i < n; i++) {
            l[i] = 1;
            if (a[i] > a[i - 1]) l[i] += l[i - 1];
        }
        r[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            r[i] = 1;
            if (a[i] < a[i + 1]) r[i] += r[i + 1];
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, l[i]);
            if (i < n - 2 && a[i] < a[i + 2]) res = max(res, l[i] + r[i + 2]);
        }
        cout << res << endl;
    }
};

class p1253C {
public:
    void solve() {
        ll m, n;
        cin >> n >> m;
        vector<ll> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        

        
        vector<ll> res;
        vector<ll> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + a[i - 1];
        }
        vector<ll> x(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            x[i] = sum[i] + x[max(0ll, i - m)];
            res.push_back(x[i]);
        }
        for (auto i:res)cout << i << " ";
        cout << endl;
    }
};

class p1234C {
public:
    void solve() {
        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            vector<string> s(2);
            int n;
            cin >> n >> s[0] >> s[1];
            int row = 0, pos = 0;
            bool ok = true;
            for (pos = 0; pos < n; pos++) {
                if (s[row][pos] >= '3') {
                    if (s[1 - row][pos] < '3') {
                        

                        ok = false;
                        break;
                    } else {
                        row = 1 - row;
                    }
                }
            }
            if (ok && row == 1 && pos == n) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
};

class p1307C {
public:
    void solve() {
        string s;
        cin >> s;
        vector<ll> cnt(26, 0);
        vector<ll> dict(1000, 0);
        ll mx = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < 26; j++) {
                dict[j * 30 + s[i] - 'a'] += cnt[j];
                mx = max(mx, dict[j * 30 + s[i] - 'a']);
            }
            cnt[s[i] - 'a']++;
            mx = max(mx, cnt[s[i] - 'a']);
        }
        cout << mx << endl;

    }
};

class p1207C {
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            ll n, a, b;
            cin >> n >> a >> b;
            string s;
            cin >> s;
            vector<vector<ll>> dp(n + 1, vector<ll>(2, -1));
            dp[0][0] = b;
            for (int i = 1; i <= n; i++) {
                if (s[i - 1] == '1') {
                    if (dp[i - 1][1] != -1) dp[i][1] = dp[i - 1][1] + 2 * b + a;
                    if (dp[i - 1][0] != -1)
                        dp[i][1] = dp[i][1] != -1 ? min(dp[i][1], dp[i - 1][0] + 3 * (a + b) - a) :
                                   dp[i - 1][0] + 3 * (a + b) - a;
                } else {
                    if (dp[i - 1][1] != -1) dp[i][1] = dp[i - 1][1] + 2 * b + a;
                    if (dp[i - 1][0] != -1)
                        dp[i][1] = dp[i][1] != -1 ? min(dp[i][1], dp[i - 1][0] + 3 * (a + b) - a) :
                                   dp[i - 1][0] + 3 * (a + b) - a;
                    if (dp[i - 1][0] != -1) dp[i][0] = dp[i - 1][0] + a + b;
                    if (dp[i - 1][1] != -1)
                        dp[i][0] = dp[i][0] != -1 ? min(dp[i][0], dp[i - 1][1] + 2 * a + b) :
                                   dp[i - 1][1] + 2 * a + b;
                }
            }
            cout << dp[n][0] << endl;
        }
    }
};

class p1105C {
public:
    void solve() {
        ll n, l, r;
        cin >> n >> l >> r;
        l--;
        ll zero = r / 3 - l / 3;
        ll one = (r + 2) / 3 - (l + 2) / 3;
        ll two = (r + 1) / 3 - (l + 1) / 3;
        vector<vector<ll>> dp(n, vector<ll>(3, 0));
        dp[0][0] = zero;
        dp[0][1] = one;
        dp[0][2] = two;
        for (int i = 1; i < n; i++) {
            dp[i][0] = (dp[i - 1][0] * zero + dp[i - 1][1] * two + dp[i - 1][2] * one) % mod;
            dp[i][1] = (dp[i - 1][0] * one + dp[i - 1][1] * zero + dp[i - 1][2] * two) % mod;
            dp[i][2] = (dp[i - 1][0] * two + dp[i - 1][1] * one + dp[i - 1][2] * zero) % mod;
        }
        cout << dp[n - 1][0] << endl;
    }
};

class p611C {
public:
    void solve() {
        int h, w;
        cin >> h >> w;
        vector<string> g(h);
        for (int i = 0; i < h; i++) cin >> g[i];
        vector<vector<vector<int>>> dp(h + 1, vector<vector<int>>(w + 1, vector<int>(2, 0)));
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                for (int k = 0; k < 2; k++)
                    dp[i][j][k] = dp[i - 1][j][k] + dp[i][j - 1][k] - dp[i - 1][j - 1][k];
                if (g[i - 1][j - 1] == '#') {
                    continue;
                }
                if (i >= 2 && g[i - 2][j - 1] == '.')
                    dp[i][j][0]++;
                if (j >= 2 && g[i - 1][j - 2] == '.')
                    dp[i][j][1]++;
            }
        }
        int q;
        cin >> q;
        for (int i = 1; i <= q; i++) {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            int res = 0;
            res += dp[r2][c2][0] - dp[r1][c2][0] - dp[r2][c1 - 1][0] + dp[r1][c1 - 1][0];
            res += dp[r2][c2][1] - dp[r2][c1][1] - dp[r1 - 1][c2][1] + dp[r1 - 1][c1][1];

            cout << res << endl;
        }
    }
};

class p1051C {
public:
    void solve() {
        int t, n = 0;
        cin >> t;
        vector<int> a(t, 0);
        for (auto &i:a) {
            cin >> i;
            n = max(n, i);
        }
        vector<int> cnt(n + 1, 0);
        vector<int> used(n + 1, -1);
        for (int i = 0; i < t; i++) {
            cnt[a[i]]++;
        }
        int odd = 0, even = 0;
        for (int i = 0; i <= n; i++) {
            if (cnt[i] == 1) odd++;
            else if (cnt[i] > 2) even++;
        }
        if (odd % 2 == 1 && even == 0) {
            cout << "NO" << endl;
            return;
        }
        if (odd % 2 == 1) {
            for (int i = 0; i <= n; i++)
                if (cnt[i] > 2) {
                    cnt[i] = 1;
                    break;
                }
        }
        cout << "YES" << endl;
        string s;
        char ch[2] = {'A', 'B'};
        int flag = 0;
        for (int i = 0; i < t; i++) {
            if (cnt[a[i]] != 1) s.append(1, 'A');
            else {
                if (used[a[i]] != -1) s.append(1, ch[used[a[i]] ^ 1]);
                else {
                    used[a[i]] = flag;
                    s.append(1, ch[flag]);
                    flag ^= 1;
                }
            }
        }
        cout << s << endl;
    }
};

class p1313C1 {
public:
    void solve() {
        int n;
        cin >> n;
        vector<ll> a(n, 0);
        for (auto &i:a) cin >> i;
        vector<vector<ll>> f(2, vector<ll>(n, 0));
        stack<int> left, right;
        auto monostack = [&n, &f](vector<ll> &a, stack<int> &left, int flag) {
            for (int i = 0; i < n; i++) {
                while (left.size() != 0 && a[left.top()] > a[i]) left.pop();
                ll pre = left.size() == 0 ? 0 : f[flag][left.top()];
                ll len = left.size() == 0 ? i + 1 : i - left.top();
                f[flag][i] = pre + len * a[i];
                left.push(i);
            }
        };
        monostack(a, left, 0);
        reverse(a.begin(), a.end());
        monostack(a, right, 1);
        reverse(f[1].begin(), f[1].end());
        reverse(a.begin(), a.end());
        ll id = -1, mx = 0;
        for (int i = 0; i < n; i++) {
            if (f[0][i] + f[1][i] - a[i] > mx) {
                id = i;
                mx = f[0][i] + f[1][i] - a[i];
            }
        }
        vector<ll> res(n, 0);
        res[id] = a[id];
        for (ll i = id - 1; i >= 0; i--) {
            if (a[i] > res[i + 1]) res[i] = res[i + 1];
            else res[i] = a[i];
        }
        for (ll i = id + 1; i < n; i++) {
            if (a[i] > res[i - 1]) res[i] = res[i - 1];
            else res[i] = a[i];
        }
        for (ll i:res) cout << i << " ";
        cout << endl;
    }
};
class p982C{
public:
    int ans=0;
    vector<vector<int>> edge;
    int dfs(int cur,int fa){
        int odd=0;
        for(auto child:edge[cur]){
            if(child==fa) continue;
            int temp=dfs(child,cur);
            if(temp==0) ans++;
            else odd++;
        }
        if(odd%2==1) return 0;
        else return 1;
    }
    void solve(){
        int n;
        cin>>n;
        ans=0;
        edge=vector<vector<int>>(n);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            u--;v--;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        if(dfs(0,-1)!=0) {
            cout<<-1<<endl;
        }
        else cout<<ans<<endl;
    }
};
class p891C{
public:
    int gcd(int x,int y){
        if(y==0) return x;
        return gcd(y,x%y);
    }
    void solve(){
        int n;
        cin>>n;
        vector<int> a(n,0);
        int cnt=0;
        for(int i=0;i<n;i++) {
            cin>>a[i];
            if(a[i]==1) cnt++;
        }
        if(cnt>0) {
            cout<<n-cnt<<endl;
            return;
        }
        bool ok=false;
        int len=n+1;
        for(int l=0;l<n;l++){
            int temp=a[l];
            for(int r=l;r<n;r++){
                temp=gcd(temp,a[r]);
                if(temp==1){
                    len=min(len,r-l);
                    break;
                }
            }
        }
        if(len==n+1) cout<<-1<<endl;
        else cout<<len+n-1<<endl;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    p891C ans;
    ans.solve();
    return 0;
}

#include <iostream>
#include<bits/stdc++.h>

#define ll long long
#define ii pair<ll,ll>
#define fi first
#define se second
#define vi vector<int>
#define vl vector<ll>
#define mod 1000000007
#define inf 0x3f3f3f3f
#define For(i, n) for(int i=0;i<n;i++)
using namespace std;

class p431C {
public:
    void solve() {
        ll n, k, l;
        cin >> n >> k >> l;
        vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i && j <= k; j++) {
                if (j < l) {
                    dp[i][0] += dp[i - j][0];
                    dp[i][1] += dp[i - j][1];
                } else {
                    dp[i][1] += dp[i - j][1] + dp[i - j][0];
                }
                dp[i][0] %= mod;
                dp[i][1] %= mod;
            }
        }
        cout << dp[n][1] << endl;
    }
};

class p1336A {
public:
    vector<vi > e;
    vl res;

    int dfs(int cur, int fa, int dept) {
        int cnt = 1;
        for (int i:e[cur]) {
            if (i == fa) continue;
            cnt += dfs(i, cur, dept + 1);
        }
        res.push_back(dept - cnt);
        return cnt;
    }

    void solve() {
        int n, k;
        cin >> n >> k;
        e = vector<vi >(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        res.clear();
        dfs(1, 0, 1);
        sort(res.begin(), res.end());
        reverse(res.begin(), res.end());
        ll ans = 0;
        for (int i = 0; i < k; i++) {
            ans += res[i];
        }
        cout << ans << endl;
    }
};

class p706C {
public:
    void solve() {
        int n;
        cin >> n;
        vl a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<string> s(n);
        for (int i = 0; i < n; i++) cin >> s[i];
        vector<vector<ll>> dp(n, vector<ll>(2, -1));
        dp[0][0] = 0;

        dp[0][1] = a[0];

        auto check = [](string s, string t, bool a, bool b) {
            if (a) reverse(s.begin(), s.end());
            if (b) reverse(t.begin(), t.end());
            for (int i = 0, j = 0; i < s.size() && j < t.size(); i++, j++) {
                if (s[i] < t[j]) return true;
                if (s[i] > t[j]) return false;
            }
            return s.size() <= t.size();
        };
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    if (dp[i - 1][j] != -1 && check(s[i - 1], s[i], j, k)) {
                        auto cur = dp[i - 1][j] + k * a[i];
                        dp[i][k] = dp[i][k] == -1 ? cur : min(cur, dp[i][k]);
                    }
                }
            }
        }
        if (dp[n - 1][0] == -1 && dp[n - 1][1] == -1) cout << -1 << endl;
        else {
            if (dp[n - 1][0] != -1 && dp[n - 1][1] != -1) cout << min(dp[n - 1][0], dp[n - 1][1]);
            else if (dp[n - 1][0] != -1) cout << dp[n - 1][0];
            else cout << dp[n - 1][1];
        }

    }
};

class p1373D {
public:
    void solve2() {
        

        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            vl a(n, 0);
            for (int i = 0; i < n; i++) cin >> a[i];
            vector<vl > dp(n + 1, vector<ll>(3, 0));
            for (int i = 1; i <= n; i++) {
                dp[i][0] = max(dp[i][0], dp[i - 1][0] + (i % 2 == 1 ? a[i - 1] : 0));
                if (i >= 2)
                    dp[i][1] = max(dp[i][1], max(dp[i - 2][0], dp[i - 2][1]) + (i % 2 == 1 ? a[i - 2] : a[i - 1]));
                dp[i][2] = max(dp[i][2], max(dp[i - 1][1], dp[i - 1][2]) + (i % 2 == 1 ? a[i - 1] : 0));
            }
            cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
        }
    }

    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            vl a(n, 0);
            for (int i = 0; i < n; i++) cin >> a[i];
            vl v1, v2;
            auto check = [](vl &a) {
                if (a.size() == 0) return 0ll;
                ll sum = a.front(), msum = min(0ll, a.front());
                ll res = a.front();
                for (int i = 1; i < a.size(); i++) {
                    sum += a[i];
                    msum = min(msum, sum);
                    res = max(res, sum - msum);
                }
                return res;
            };
            for (int i = 0; 2 * i + 1 < n; i++) v1.push_back(a[2 * i + 1] - a[2 * i]);
            for (int i = 1; 2 * i < n; i++) v2.push_back(a[2 * i - 1] - a[2 * i]);
            ll sum = 0;
            for (int i = 0; i < n; i += 2) sum += a[i];
            sum = max(sum, sum + max(check(v1), check(v2)));
            cout << sum << endl;
        }
    }
};

class p446A {
public:
    void solve() {
        int n;
        cin >> n;
        vl a(n);
        for (int i = 0; i < n; i++)cin >> a[i];
        vl l(n), r(n);
        l[0] = 1;
        ll res = 1;
        for (int i = 1; i < n; i++) {
            l[i] = 1;
            if (a[i] > a[i - 1]) l[i] += l[i - 1];
            res = max(res, l[i]);
        }
        r[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            r[i] = 1;
            if (a[i] < a[i + 1]) r[i] += r[i + 1];
            res = max(res, r[i]);
        }
        for (int i = 0; i < n; i++) {
            int left = i - 1 < 0 ? 0 : a[i - 1];
            int right = i + 1 >= n ? inf : a[i + 1];
            if (left + 1 < right) {
                res = max(res, (i - 1 >= 0 ? l[i - 1] : 0) + 1 + (i + 1 < n ? r[i + 1] : 0));
            } else {
                res = max(res, (i - 1 >= 0 ? l[i - 1] : 0) + 1);
                res = max(res, (i + 1 < n ? r[i + 1] : 0) + 1);
            }
        }
        cout << res << endl;
    }
};

class p1295C {
public:
    void solve2() {
        

        int T;
        cin >> T;
        while (T--) {
            string s, t;
            cin >> s >> t;
            int n = s.size();
            vector<vector<int>> cnt(n + 1, vector<int>(26, -1));
            for (int i = n - 1; i >= 0; i--) {
                for (int j = 0; j < 26; j++) cnt[i][j] = cnt[i + 1][j];
                cnt[i][s[i] - 'a'] = i;

            }
            int m = t.size();
            int pos = 0;
            bool ok = true;
            int res = 0;
            for (int i = 0; i < m; i++) {
                int c = t[i] - 'a';
                if (cnt[pos][c] == -1) {
                    pos = 0;
                    res++;
                }
                if (pos == 0 && cnt[pos][c] == -1) {
                    ok = false;
                    break;
                }
                pos = cnt[pos][c] + 1;
            }
            res++;
            if (ok) cout << res << endl;
            else cout << -1 << endl;
        }
    }

    void solve() {
        int T;
        cin >> T;
        while (T--) {
            string s, t;
            cin >> s >> t;
            vector<vi > cnt(26);
            for (int i = 0; i < s.size(); i++) {
                cnt[s[i] - 'a'].push_back(i);
            }
            int res = 0;
            int id = -1;
            bool ok = true;
            for (int i = 0; i < t.size(); i++) {
                int c = t[i] - 'a';
                if (cnt[c].size() == 0) {
                    ok = false;
                    break;
                }
                auto it = upper_bound(cnt[c].begin(), cnt[c].end(), id) - cnt[c].begin();
                if (it == cnt[c].size()) {
                    id = cnt[c].front();
                    res++;
                } else id = cnt[c][it];
            }
            res++;
            if (!ok) cout << -1 << endl;
            else cout << res << endl;
        }
    }
};

class p165C {
public:
    void solve2() {
        ll k;
        cin >> k;
        string s;
        cin >> s;
        int n = s.size();
        ll res = 0;
        vector<ll> dp(n + 1, 0);
        dp[0] = 1;
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '1') cur++;
            if (cur >= k) res += dp[cur - k];
            dp[cur]++;
        }
        cout << res << endl;
    }

    void solve() {
        ll k;
        cin >> k;
        string s;
        cin >> s;
        int n = s.size();
        vector<ll> cnt(n + 1, 0);
        ll res = 0;
        unordered_map<ll, ll> last;
        last[0] = 0;
        for (int i = 1; i <= n; i++) {
            cnt[i] = cnt[i - 1];
            if (s[i - 1] == '1') {
                cnt[i]++;
                last[cnt[i]] = i;
            }
            if (cnt[i] >= k) {
                if (k != 0)
                    res += last[cnt[i] - k + 1] - last[cnt[i] - k];
                else res += i - last[cnt[i]];
            }
        }
        cout << res << endl;
    }
};

class p763A {
public:
    vector<vector<int>> e;
    vector<int> color;

    bool dfs(int cur, int fa, int curc) {
        if (color[cur] != curc) return false;
        for (int i:e[cur]) {
            if (i == fa) continue;
            if (!dfs(i, cur, curc)) return false;
        }
        return true;
    }

    bool check(int v) {
        for (auto c:e[v]) {
            int curcolor = color[c];
            if (!dfs(c, v, curcolor)) return false;
        }
        return true;
    }

    void solve() {
        int n;
        cin >> n;
        e = vector<vector<int>>(n + 1);
        color = vector<int>(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) cin >> color[i];
        int root1 = -1, root2 = -1;
        for (int i = 1; i <= n; i++) {
            for (auto c:e[i]) {
                if (color[i] != color[c]) {
                    root1 = i;
                    root2 = c;
                    break;
                }
            }
            if (root1 != -1) break;
        }
        if (root1 == -1) {
            cout << "YES\n1\n";
            return;
        }
        if (check(root1)) {
            cout << "YES\n" << root1 << endl;
        } else if (check(root2)) {
            cout << "YES\n" << root2 << endl;
        } else cout << "NO\n";
    }
};

class p788A {
public:
    void solve2() {
        int n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> v;
        For(i, n) cin >> a[i];
        for (int i = 0; i < n - 1; i++) v.push_back(abs(a[i] - a[i + 1]));
        ll ma = 0, mi = 0, now = 0, ans=0;
        for (int i = n - 2; i >= 0; i--) {
            if (i & 1) now -= v[i];
            else now += v[i];
            ma = max(now, ma);
            mi = min(now, mi);
            if (i & 1) {
                ans = max(ans, -(now - ma));
            } else ans = max(ans, now - mi);
        }
        cout << ans << endl;
    }

    void solve() {
        int n;
        cin >> n;
        vl a(n, 0);
        For(i, n) cin >> a[i];
        vl v;
        for (int i = 0; i < n - 1; i++) {
            v.push_back(abs(a[i] - a[i + 1]));
        }
        vector<vl > dp(n + 1, vl(2, 0));
        vector<vector<bool>> vis(n + 1, vector<bool>(2, 0));
        dp[0][0] = v[0];
        vis[0][0] = 1;
        ll res = v[0];
        for (int i = 1; i < v.size(); i++) {
            if (vis[i - 1][0]) {
                vis[i][1] = 1;
                dp[i][1] = dp[i - 1][0] - v[i];
            }
            dp[i][0] = v[i];
            vis[i][0] = 1;
            if (vis[i - 1][1]) {
                dp[i][0] = max(dp[i][0], v[i] + dp[i - 1][1]);
            }
            res = max(res, max(dp[i][0], dp[i][1]));
        }
        cout << res << endl;

    }
};

class p1282B2{
public:
    void solve2(){
        int t;
        cin>>t;
        for(int kase=1;kase<=t;kase++){
            int n,p,k;
            cin>>n>>p>>k;
            vector<int> a(n);
            For(i,n) cin>>a[i];
            sort(a.begin(),a.end());
            vector<int> dp(n+1,0);
            int res=0;
            for(int i=0;i<n;i++){
                if(i>=k-1) dp[i]=(i>=k?dp[i-k]:0)+a[i];
                else dp[i]=(i?dp[i-1]:0)+a[i];
            }
            for(int i=0;i<n;i++)if(dp[i]<=p) res=i+1;
            cout<<res<<endl;
        }
    }
    void solve(){
        int t;
        cin>>t;
        for(int kase=1;kase<=t;kase++){
            int n,p,k;
            cin>>n>>p>>k;
            vector<int> a(n);
            For(i,n) cin>>a[i];
            sort(a.begin(),a.end());
            vector<int> sum(n+1,0);
            for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i-1];
            int res=0;
            for(int i=1;i<=n;i++){
                if(sum[i]<=p) res=max(res,i);
                if(i>=k&&a[i-1]<=p){
                        int pre=0;
                        if(p-a[i-1]>=sum[i-k]) pre=i-k;
                        else if(p-a[i-1]<sum[1]) pre=0;
                        else{
                            auto it=lower_bound(sum.begin(),sum.begin()+i-k+1,p-a[i-1])-sum.begin();
                            if(sum[it]>p-a[i-1]) it--;
                            pre=max(it,0);
                        }
                        res=max(res,pre+k);
                }
            }
            cout<<res<<endl;
        }
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    p1282B2 ans;
    ans.solve2();
    return 0;
}

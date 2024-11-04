






















 
using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}












using ll = long long;
using ld = long double; 
const string FILENAME = "input";
const int Mod = 1000000007;


int sum(int a, int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
    return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}


int inv(int a) {
    return powm(a, Mod - 2);
}


int n;
string s[120];
int dp[120][1024];
pair<int, int> pr[120][1024];
vector<int> pos[120][300];



void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < sz(s[i]); j++) {
            pos[i][s[i][j]].pb(j);
        }
    }
    memset(dp, 0, sizeof(dp));
    if (n == 1) {
        cout << sz(s[0]) << '\n';
        cout << s[0] << '\n';
    } else {
        int ans = 0;
        int pi = -1, pj = -1;
        for (int i = 0; i < sz(s[0]); i++) {
            for (int j = 0; j < (1 << n); j+= 2) {
                bool bad = false;
                vector<int> st;
                for (int k = 1; k < n; k++) {
                    int t = 0;
                    if (j & (1 << k)) {
                        t = 1;
                    } 
                    if (sz(pos[k][s[0][i]]) <= t) {
                        bad = true;
                        break;
                    }
                    st.pb(pos[k][s[0][i]][t]);  
                }
                if (!bad) {
                    if (dp[i][j] < 1) {
                        dp[i][j] = 1;
                        pr[i][j] = mp(-1, -1);
                    }
                    for (int t = i + 1; t < sz(s[0]); t++) {
                        bool bad1 = false;
                        int nmask = 0;
                        for (int k = 1; k < n; k++) {
                            int it = 0;
                            bool was = false;
                            for (auto x: pos[k][s[0][t]]) {
                                if (x > st[k - 1]) {
                                    nmask |= it << k;
                                    was = true;
                                    break;
                                }
                                it++;
                            }
                            if (!was) {
                                bad1 = true;
                                break;
                            }
                        }
                        if (!bad1) {
                            if (dp[t][nmask] < dp[i][j] + 1) {
                                dp[t][nmask] = dp[i][j] + 1;
                                pr[t][nmask] = mp(i, j);
                            }
                        }
                    }
                    if (dp[i][j] > ans) {
                        ans = dp[i][j];
                        pi = i;
                        pj = j;
                    }
                }
            }
        }
        cout << ans << '\n';
        string res;
        while (pi != -1) {
            res += s[0][pi];
            auto p = pr[pi][pj];
            pi = p.first;
            pj = p.second;
        }
        reverse(all(res));
        cout << res << '\n';
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 300; j++) {
            pos[i][j].clear();
        }
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

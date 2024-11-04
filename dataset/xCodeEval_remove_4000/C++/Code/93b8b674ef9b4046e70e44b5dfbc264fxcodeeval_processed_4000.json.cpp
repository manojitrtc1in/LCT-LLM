




























































































































































































































































































































































































































































































































using namespace std;








using ll = long long;
using pii = pair<int, int>;
template<class T1, class T2, class T3> struct triple {
    T1 x; T2 y; T3 z;
};
using tri = triple<int, int, int>;
using trll = triple<ll, ll, ll>;
template<class T1, class T2, class T3>
bool operator<(const triple<T1, T2, T3>& t1, const triple<T1, T2, T3>& t2) {
    return t1.x < t2.x || (t1.x == t2.x && (t1.y < t2.y || t1.y == t2.y && t1.z < t2.z));
}



const int mod = 1000000007;
const int INF = 1000111000;
const ll LLINF = 1000111000111000111LL;
const double PI = acos(-1.0);













int gcd(int x, int y) { while (y) { x %= y, swap(x, y); } return x; }
ll gcd(ll x, ll y) { while (y) { x %= y, swap(x, y); } return x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll powmod(ll x, ll n, const int mod) {
    ll res = 1; while (n)
    {
        if (n & 1) res = res * x % mod; n /= 2; x = x * x % mod;
    } return res;
}



int ax[10101], ay[10101];
int mx[10101], my[10101];
int dx[7][10101], dy[7][10101];
vector<pair<int, ll>> np[7][1010];
ll dist[7][10101];
bool used[10101];
char dp[1010][1 << 7][7];
int k, n;
bool id0(int cur, int mask, int from) {
    auto& ans = dp[cur][mask][from];
    if (!ans) {
        int res = 0;
        if (np[from][cur].size() == 0) {
            res = true;
        }
        else if (np[from][cur].size() > 7) {
            res = false;
        } else {
            int fow = np[from][cur][0].second;
            for (int w = 0; w < k; ++w) {
                if (checkbit(mask, w)) {
                    int wm = mask ^ (1 << w);
                    for (int sm = wm; ; sm = (sm - 1) & wm) {
                        bool here = id0(fow, sm, w) && id0(fow, wm ^ sm, from);
                        if (here) {
                            res = true;
                            goto stop;
                        }
                        if (sm == 0) break;
                    }
                    if (dx[from][fow] == dx[w][fow] && dy[from][fow] == dy[w][fow]) {
                        if (dist[from][fow] < dist[w][fow]) {
                            bool here = id0(fow, wm, w);
                            if (here) {
                                res = true;
                                goto stop;
                            }
                        }
                    }
                }
            }
        }
    stop:
        ans = res + 1;
    }
    return ans - 1;
}

int toKill[101010];
bool isKilled[101010];
int sp = 0;
int cp = 0;
int ls;
bool killed[1010];
bool go(int cp, int sp) {
    if (sp - cp > ls) return false;
    if (cp == sp) {
        return true;
    }
    ++cp;
    for (int i = 0; i < sp; ++i) {
        if (!killed[i]) {
            int cur = toKill[i];
            killed[i] = true;
            for (int i = 0; i < k; ++i) {
                if (!used[i]) {
                    int bonus = 0;
                    bool bad = false;
                    for (auto p : np[i][cur]) {
                        bool add = true;
                        int x = p.second;
                        for (int i = 0; i < sp; ++i) {
                            if (toKill[i] == x) {
                                add = false;
                                break;
                            }
                        }
                        if (add) {
                            toKill[sp + bonus++] = x;
                        }
                    }
                    if (bad) continue;
                    
                    used[i] = true;
                    isKilled[cur] = true;
                    --ls;
                    bool res = go(cp, sp + bonus);
                    ++ls;
                    isKilled[cur] = false;
                    used[i] = false;
                    if (res) return true;
                }
            }
            killed[i] = false;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    ls = k;
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> ax[i] >> ay[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> mx[i] >> my[i];
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            int tx = mx[j] - ax[i];
            int ty = my[j] - ay[i];
            int g = gcd(abs(tx), abs(ty));
            dist[i][j] = tx * (ll)tx + ty * (ll)ty;
            dx[i][j] = tx / g;
            dy[i][j] = ty / g;
        }
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int l = 0; l < n; ++l) {
                if (l == j) continue;
                if (dx[i][j] == dx[i][l] && dy[i][j] == dy[i][l] && dist[i][j] > dist[i][l]) {
                    np[i][j].push_back({dist[i][l], l });
                } 
                if (np[i][j].size() > 7) break;
            }
            sort(all(np[i][j]));
            reverse(all(np[i][j]));
        }
    }
    int ans = 0;
    
    for (int i = 0; i < n; ++i) {
        toKill[0] = i;
        memset(killed, 0, 20);
        ans += go(0, 1);
    }
    
    cout << ans << endl;
    
    return 0;
}

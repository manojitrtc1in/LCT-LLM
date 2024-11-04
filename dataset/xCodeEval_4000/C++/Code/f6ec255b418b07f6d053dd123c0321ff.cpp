#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize(2)
#pragma G++ optimize(2)


#define M_E         2.71828182845904523536028747135266250   
#define M_LOG2E     1.44269504088896340735992468100189214   
#define M_LOG10E    0.434294481903251827651128918916605082  
#define M_LN2       0.693147180559945309417232121458176568  
#define M_LN10      2.30258509299404568401799145468436421   
#define M_PI        3.14159265358979323846264338327950288   
#define M_PI_2      1.57079632679489661923132169163975144   
#define M_PI_4      0.785398163397448309615660845819875721  
#define M_1_PI      0.318309886183790671537767526745028724  
#define M_2_PI      0.636619772367581343075535053490057448  
#define M_2_SQRTPI  1.12837916709551257389615890312154517   
#define M_SQRT2     1.41421356237309504880168872420969808   
#define M_SQRT1_2   0.707106781186547524400844362104849039  

#define MAXFLOAT    0x1.fffffep+127f

#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <climits>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <utility>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <numeric>

#define LL long long
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<LL, LL>
#define pdd pair<double, double>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define length(p1, p2) ((p1.fi-p2.fi)*(p1.fi-p2.fi)+(p1.se-p2.se)*(p1.se-p2.se))
#define ith(state, i) (state & (1 << i)) 

using namespace std;

class PrimeSelector {public: bool* prime; set<int> primes; int n; PrimeSelector(bool* prime, int n): n(n), prime(prime) { memset(prime, 1, sizeof(bool)*(n+1)); prime[0] = prime[1] = false; for (int i = 1; i * i <= n; i++) { if (!prime[i]) continue; for (int j = i * i; j <= n; j += i) prime[j] = false; } for (int i = 2; i <= n; i++) if (prime[i]) primes.insert(i); } };
LL kpow(LL a, LL b) { LL c = 1; while (b) { if (b & 1) c = c * a; a = a * a; b >>= 1; } return c;}
LL kpow(LL a, LL b, LL mod) { LL c = 1 % mod; while (b) { if (b & 1) c = c * a % mod; a = a * a % mod; b >>= 1; } return c;}
LL rev(LL a, LL mod) { return kpow(a, mod-2, mod); }
map<LL, LL> splitPrime(LL x, bool* prime) { map<LL, LL> res; for (int i = 2; i * i <= x; i++) { if (!prime[i]) continue; while (x % i == 0) res[i]++, x /= i; if (res[i] == 0) res.erase(i); } if (x > 1) res[x] = 1; return res; }
map<LL, LL> splitPrime(LL x, set<int>& prime) { map<LL, LL> res; for (auto i: prime) { if (i * i > x) break; while (x % i == 0) res[i]++, x /= i; if (res[i] == 0) res.erase(i); } if (x > 1) res[x] = 1; return res; }
map<LL, LL> mul(const map<LL, LL>& m1, const map<LL, LL>& m2) { map<LL, LL> res; for (auto& p: m1) res[p.fi] = p.se; for (auto& p: m2) { res[p.fi] += p.se; if (res[p.fi] == 0) res.erase(p.fi); } return res; }
map<LL, LL> rev(map<LL, LL> m) { map<LL, LL> res; for (auto& p: m) res[p.fi] = -p.se; return res; }
LL m2L(map<LL, LL> m) { LL res = 1; for (auto& p: m) res *= kpow(p.fi, p.se); return res; }
#define W 1000000000LL
vector<LL> n2B(LL n) { vector<LL> res; if (n == 0) return {0LL};  while (n) { res.push_back(n % W); n /= W; } reverse(res.begin(), res.end()); return res; }
void simple(vector<LL>& res) { while (!res.empty() && res.back() == 0LL) res.pop_back(); if (res.empty()) res.push_back(0LL); }
vector<LL> add(const vector<LL>& b1, const vector<LL>& b2) { vector<LL> res; res.reserve(max(b1.size(), b1.size())+1); LL up = 0LL; int i = b1.size()-1, j = b2.size()-1; while (i >= 0 && j >= 0) { LL b = b1[i--] + b2[j--] + up; res.push_back(b % W); up = b / W; } while (i >= 0) { LL b = b1[i--] + up; res.push_back(b % W); up = b / W; } while (j >= 0) { LL b = b2[j--] + up; res.push_back(b % W); up = b / W; } if (up) res.push_back(up); simple(res); reverse(res.begin(), res.end()); return res; }
vector<LL> mul(const vector<LL>& b1, LL i) { vector<LL> res; res.reserve(b1.size()+1); LL up = 0; for (int j = b1.size()-1; j >= 0; j--) { LL b = b1[j] * i + up; res.push_back(b % W); up = b / W; } if (up) res.push_back(up); simple(res); reverse(res.begin(), res.end()); return res; }
void shift(vector<LL>& b1, LL i) { if (b1.size() == 1 && b1[0] == 0LL) return; while (i--) { b1.push_back(0); } }
vector<LL> mul(const vector<LL>& b1, const vector<LL>& b2) { if (b1.size() < b2.size()) return mul(b2, b1); vector<LL> res; res.reserve(b1.size()+b2.size()+1); res.push_back(0); if (b2.size() == 1 && b2[0] == 0) return res; int shi = 0; for (int j = b2.size()-1; j >= 0; j--) { vector<LL> r = mul(b1, b2[j]); shift(r, shi++); res = add(res, r); } return res; }
vector<LL> m2B(const map<LL, LL>& m) { if (m.empty()) return {1}; vector<LL> res; res.reserve(100); res.push_back(1); for (auto& p: m) { vector<LL> r = n2B(p.fi); for (int i = 0; i < p.se-1; i++) r = mul(r, n2B(p.fi)); res = mul(res, r); } return res; }
struct DSU { vector<int> par; vector<int> sz; int n; DSU(int n) : par(n+1), sz(n+1), n(n) { for (int i = 0; i <= n; i++) sz[i] = 1, par[i] = i; } int find(int x) { if (x == par[x]) return x; return par[x] = find(par[x]); } void uni(int x, int y) { int px = find(x), py = find(y); if (px == py) return; if (sz[px] < sz[py]) return uni(py, px); par[py] = px, sz[px] += sz[py]; } };
template <class T> struct VHash { size_t operator () (const vector<T>& v) const { size_t res = 0; for (T i: v) res ^= i; return res; } };
struct SHash { LL* presum; LL* po; LL seed; LL mod; SHash(LL seed, LL mod, LL* presum, LL* po): seed(seed), mod(mod), presum(presum), po(po) {} void load(const string& s) { po[0] = 1; for (int i = 1; i <= (int)s.size(); i++) { presum[i] = (presum[i-1] * seed + s[i-1]) % mod; po[i] = po[i-1] * seed % mod; } } LL get(int i, int j) { if (i > j) return 0; return (presum[j] - presum[i-1] * po[j-i+1] % mod + mod) % mod; } };
struct SHash2 { LL* presum; LL* po; LL seed; SHash2(LL seed, LL* presum, LL* po): seed(seed), presum(presum), po(po) {} void load(const string& s) { po[0] = 1; for (int i = 1; i <= (int)s.size(); i++) { presum[i] = (presum[i-1] * seed + s[i-1]) & 0xFFFFFFFF; po[i] = (po[i-1] * seed) & 0xFFFFFFFF; } } LL get(int i, int j) { if (i > j) return 0; return (presum[j] - ((presum[i-1] * po[j-i+1]) & 0xFFFFFFFF) + 0xFFFFFFFF) & 0xFFFFFFFF; } };
struct TrieNode { int next[26]; int done; };
struct TrieTree { TrieNode* nodes; int cnt = 0; char base; TrieTree(TrieNode* nodes, char base='a') : nodes(nodes), cnt(0), base(base) {} void add(const string& s) { int p = 0; for (char c: s) { if (!nodes[p].next[c-base]) nodes[p].next[c-base] = ++cnt; p = nodes[p].next[c-base]; } nodes[p].done++; } int count(const string& s) { int res = 0, p = 0; for (char c: s) { res += nodes[p].done; if (!nodes[p].next[c-base]) return res; p = nodes[p].next[c-base]; } res += nodes[p].done; return res; } };
struct BinNode { int next[2]; int done; };
struct BinTree { BinNode* nodes; int maxn = 31; int cnt = 0; BinTree(BinNode* nodes, int maxn) : nodes(nodes), maxn(maxn), cnt(0) {} void add(LL l) { LL p = 0; for (int j = maxn; j >= 0; j--) { int b = (l >> j) & 1; if (!nodes[p].next[b]) nodes[p].next[b] = ++cnt; p = nodes[p].next[b]; } } LL maxXor(LL x) { LL res = 0; int p = 0; for (int j = maxn; j >= 0; j--) { res <<= 1; LL b = (x >> j) & 1; if (nodes[p].next[1^b]) p = nodes[p].next[1^b], res |= 1^b; else p = nodes[p].next[b], res |= b;  } return res; } } ;
int minResp(const string& s) { int n = s.size(); string ss = s + s; int i = 0, j = 1; while (i < n && j < n) { int k = 0; while (k < n) { if (ss[i+k] != ss[j+k]) break; k++; } if (k == n) break; if (ss[i+k] < ss[j+k]) { j = j+k+1; if (i == j) j++; } else { i = i+k+1; if (i == j) i++; } } return min(i, j); }
struct BIT { LL* c; int n; BIT(LL* c, int n): c(c), n(n) {} int lowbit(int x) { return x&-x; } void add(int x, LL v) { for (int i = x; i <= n; i += lowbit(i)) c[i] += v; } LL sum(int x) { LL res = 0; for (int i = x; i; i -= lowbit(i)) res += c[i]; return res; } };
struct BIT2 { LL* C; int n, m; BIT2(LL* C, int n, int m): C(C), n(n), m(m) {} int lowbit(int x) { return x&-x; } void add(int r, int c, LL v) { for (int i = r; i <= n; i += lowbit(i)) for (int j = c; j <= m; j += lowbit(j)) C[i*(m+1)+j] += v; } LL sum(int r, int c) { LL res = 0; for (int i = r; i; i -= lowbit(i)) for (int j = c; j; j -= lowbit(j)) res += C[i*(m+1)+j]; return res; } };

#define MAXN 5005
#define eps 1e-10

int T;
int n, dsum;
int par[MAXN];
int out[MAXN];
int d[MAXN];
int vis[MAXN];

int main() {
    fastio;
    cin >> T;
    while (T--) {
        cin >> n >> dsum;
        d[0] = -1;
        set<pii> outmap[3]; 
        set<pii> leaf;
        int lb = 0, logN = 0;
        for (int i = 1; i <= n; i++) out[i] = 0;
        for (int i = 1; i <= n; i++) {
            lb += logN;
            if (((i+1) & i) == 0) logN++;
            d[i] = d[i-1] + 1;
            if (i-1) out[i-1]++;
            par[i] = i-1;
            vis[i] = 0;
        }
        if (dsum < lb) {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 1; i <= n; i++) {
            outmap[out[i]].insert({d[i], i});
            if (out[i] == 0) leaf.insert({d[i], i});
        }
        int sum = n * (n-1) / 2;
        while (sum > dsum) {
            int v = 0;
            int p = 0;
            while (v == 0 || p == 0) {
                v = 0, p = 0;
                if (leaf.empty()) break;
                v = leaf.begin()->se;
                leaf.erase(leaf.begin());
                outmap[0].erase({d[v], v});
                auto iter = outmap[0].lower_bound({d[v]-2, 0});
                if (iter == outmap[0].end() || iter->first != d[v]-2) {
                    iter = outmap[1].lower_bound({d[v]-2, 0});
                    if (iter == outmap[1].end() || iter->first != d[v]-2) {
                        vis[v] = 1;
                        outmap[0].insert({d[v], v});
                    } else {
                        p = iter->se;
                        outmap[1].erase(iter);
                    }
                } else {
                    p = iter->se;
                    outmap[0].erase(iter);
                }
            }
            if (v == 0) break;
            if (par[v]) {
            outmap[out[par[v]]].erase({d[par[v]], par[v]});
            out[par[v]]--;
            outmap[out[par[v]]].insert({d[par[v]], par[v]});
            }
            if (out[par[v]] == 0 && ! vis[par[v]]) leaf.insert({d[par[v]], par[v]});
            par[v] = p;
            d[v]--;
            
            out[p]++;
            outmap[0].insert({d[v], v});
            outmap[out[p]].insert({d[p], p});
            leaf.insert({d[v], v});
            
            sum--;
        }
        if (sum == dsum) {
            cout << "YES" << endl;
            for (int i = 2; i <= n; i++) {
                cout << par[i] << " ";
            }
            cout << endl;
        } else cout << "NO" << endl;
    }
    return 0;
}
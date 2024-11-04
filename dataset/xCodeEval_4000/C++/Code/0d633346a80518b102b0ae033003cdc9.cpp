
 
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
 
struct AC {
    static const int N = 3e5 + 5, M = 26, C = 'a'; 

 
    int trie[N][M], cnt[N], fail[N], vis[N], tot;
    vector<multiset<int>> idx; 

    int q[N], idn[N], mx[N];
 
    void init() {
        idx.resize(1, multiset<int>());
    }
 
    int newnode() {
        idx.pb(multiset<int>());
        mx[++tot] = -1;
        return tot;
    }
 
    void insert(char* s, int id) {
        int p = 0;
        for (int i = 0; s[i]; ++i) {
            int ch = s[i] - C;
            if (!trie[p][ch]) trie[p][ch] = newnode();
            p = trie[p][ch];
        }
        ++cnt[p]; idn[id] = p;
        idx[p].insert(0);
        mx[p] = 0;
    }
 
    void build() {
        int head = 0, tail = -1;
        rep(i, 0, M - 1) if (trie[0][i]) q[++tail] = trie[0][i];
        while (head <= tail) {
            int p = q[head++];
            rep(i, 0, M - 1)
                if (trie[p][i])
                    fail[trie[p][i]] = trie[fail[p]][i], q[++tail] = trie[p][i];
                else trie[p][i] = trie[fail[p]][i];
        }
    }
 
    int query(char* s) {
        set<int> v;
        int p = 0, res = -1;
        for (int i = 0; s[i]; ++i) {
            p = trie[p][s[i] - C];
            for (int tmp = p; tmp && !v.count(tmp); tmp = fail[tmp]) {
                umax(res, mx[tmp]); v.insert(tmp);
            }
        }
        return res;
    }
 
    void change(int id, int k, int yk) {
        int p = idn[id];
        idx[p].erase(idx[p].find(yk)); idx[p].insert(k);
        mx[p] = *idx[p].rbegin();
    }
} ac;
 
const int N = 3e5 + 5;
 
int n, m;
int a[N];
char s[N];
 
int main() {
    IOS; cin >> n >> m; ac.init();
    rep(i, 1, n) 
        cin >> s, ac.insert(s, i);
    ac.build();
    rep(i, 1, m) {
        int op; cin >> op;
        if (op == 2) {
            cin >> s;
            cout << ac.query(s) << '\n';
        }
        else {
            int k, s; cin >> k >> s;
            ac.change(k, s, a[k]); a[k] = s;
        }
    }
    return 0;
}
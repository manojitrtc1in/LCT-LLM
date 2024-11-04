#include <bits/stdc++.h>
using namespace std;


template <class T = int> inline T readInt();
inline double readDouble();
inline int readUInt();
inline int readChar();
inline void readWord(char *s);
inline bool readLine(char *s);
inline bool isEof();
inline int peekChar();
inline bool seekEof();

template <class T> inline void writeInt(T x, int len = -1);
template <class T> inline void writeUInt(T x, int len = -1);
inline void writeChar(int x);
inline void writeWord(const char *s);
inline void writeDouble(double x, int len = 0);
inline void flush();

static const int buf_size = 4096;

static char buf[buf_size];
static int buf_len = 0, buf_pos = 0;

inline bool isEof() {
    if (buf_pos == buf_len) {
        buf_pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
        if (buf_pos == buf_len) return 1;
    }
    return 0;
}

inline int getChar() {
    return isEof() ? -1 : buf[buf_pos++];
}

inline int peekChar() {
    return isEof() ? -1 : buf[buf_pos];
}

inline bool seekEof() {
    int c;
    while ((c = peekChar()) != -1 && c <= 32)
        buf_pos++;
    return c == -1;
}

inline int readChar() {
    int c = getChar();
    while (c != -1 && c <= 32)
        c = getChar();
    return c;
}

inline int readUInt() {
    int c = readChar(), x = 0;
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return x;
}

template <class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}

inline double readDouble() {
    int s = 1, c = readChar();
    double x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    if (c == '.') {
        c = getChar();
        double coef = 1;
        while ('0' <= c && c <= '9')
            x += (c - '0') * (coef *= 1e-1), c = getChar();
    }
    return s == 1 ? x : -x;
}

inline void readWord(char *s) {
    int c = readChar();
    while (c > 32)
        *s++ = c, c = getChar();
    *s = 0;
}

inline bool readLine(char *s) {
    int c = getChar();
    while (c != '\n' && c != -1)
        *s++ = c, c = getChar();
    *s = 0;
    return c != -1;
}

static int write_buf_pos = 0;
static char write_buf[buf_size];

inline void writeChar(int x) {
    if (write_buf_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_buf_pos = 0;
    write_buf[write_buf_pos++] = x;
}

inline void flush() {
    if (write_buf_pos)
        fwrite(write_buf, 1, write_buf_pos, stdout), write_buf_pos = 0;
}

template <class T>
inline void writeInt(T x, int output_len) {
    if (x < 0)
        writeChar('-'), x = -x;
    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n < output_len)
        s[n++] = '0';
    while (n--)
        writeChar(s[n]);
}

template <class T>
inline void writeUInt(T x, int output_len) {
    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n < output_len)
        s[n++] = '0';
    while (n--)
        writeChar(s[n]);
}

inline void writeWord(const char *s) {
    while (*s)
        writeChar(*s++);
}

inline void writeDouble(double x, int output_len) {
    if (x < 0)
        writeChar('-'), x = -x;
    int t = (int)x;
    writeUInt(t), x -= t;
    writeChar('.');
    for (int i = output_len - 1; i > 0; i--) {
        x *= 10;
        t = std::min(9, (int)x);
        writeChar('0' + t), x -= t;
    }
    x *= 10;
    t = std::min(9, (int)(x + 0.5));
    writeChar('0' + t);
}
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma warning(disable:4996)



#define FF first
#define SS second
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define pb push_back
#define mp make_pair

using ll = long long;
using ld = long double;

const int INFI = 1e9 + 228;
const ll INFL = 1e18 + 228;
const ld INFLD = 1e18 + 228;
const ld PI = acos(-1);
const int MAXN = 4e5 + 228;

vector<pair<int, int> > DD = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<pair<int, pair<int, int> > > updates;
struct sob {
    int l, r, k, t, num;
    sob(int l, int r, int k, int t, int num): l(l), r(r), k(k), t(t), num(num) {};
};
vector<sob> zapros;
int block = 3200;
int ans[MAXN];
bool cmp(sob a, sob b) {
    if (a.t / block != b.t / block) return a.t / block > b.t / block;
    if (a.l / block != b.l / block) return a.l / block > b.l / block;
    return a.r < b.r;
}
int ma[MAXN];
int ma2[MAXN];
bool vis[MAXN];
vector<int> was;
vector<int> mass;
int solve(int k) {
    int ans_now = INFI;
    vector<pair<int, int> > now;
    

    int uk = 0, sum = 0;
    

    sort(ALL(was));
    for (auto u : was) {
        if (u == 0) continue;
        if (ma2[u] == 0) {
            vis[u] = false;
            continue;
        }
        now.pb({u, ma2[u]});
    }
    
    for (int i = 0; i < now.size(); ++i) {
        while (uk < i) {
            ++uk;
            sum = 0;
        }
        while (uk < now.size() && sum < k) {
            sum += now[uk].SS;
            ++uk;
        }
        if (sum >= k) {
            ans_now = min(ans_now, now[uk - 1].FF - now[i].FF);
        }
        sum -= now[i].SS;
    }
    was.clear();
    for (auto u : now) was.pb(u.FF);
    if (ans_now == INFI) return -1;
    return ans_now;
    
}
void left_left(int l) {
    if (ma[mass[l - 1]] > 0 && !vis[ma[mass[l - 1]]]) {
        vis[ma[mass[l - 1]]] = 1;
        was.pb(ma[mass[l - 1]]);
    }
    if (ma[mass[l - 1]] > 0) ma2[ma[mass[l - 1]]]--;
    ma[mass[l - 1]]++;
    if (ma[mass[l - 1]] > 0) ma2[ma[mass[l - 1]]]++;
    if (ma[mass[l - 1]] > 0 && !vis[ma[mass[l - 1]]]) {
        vis[ma[mass[l - 1]]] = 1;
        was.pb(ma[mass[l - 1]]);
    }
}
void left_right(int l) {
    if (ma[mass[l]] > 0 && !vis[ma[mass[l]]]) {
        vis[ma[mass[l]]] = 1;
        was.pb(ma[mass[l]]);
    }
    if (ma[mass[l]] > 0) ma2[ma[mass[l]]]--;
    ma[mass[l]]--;
    if (ma[mass[l]] > 0) ma2[ma[mass[l]]]++;
    if (ma[mass[l]] > 0 && !vis[ma[mass[l]]]) {
        vis[ma[mass[l]]] = 1;
        was.pb(ma[mass[l]]);
    }
}
void right_right(int r) {
    if (ma[mass[r + 1]] > 0 && !vis[ma[mass[r + 1]]]) {
        vis[ma[mass[r + 1]]] = 1;
        was.pb(ma[mass[r + 1]]);
    }
    if (ma[mass[r + 1]] > 0) ma2[ma[mass[r + 1]]]--;
    ma[mass[r + 1]]++;
    if (ma[mass[r + 1]] > 0) ma2[ma[mass[r + 1]]]++;
    if (ma[mass[r + 1]] > 0 && !vis[ma[mass[r + 1]]]) {
        vis[ma[mass[r + 1]]] = 1;
        was.pb(ma[mass[r + 1]]);
    }
}
void right_left(int r) {
    if (ma[mass[r]] > 0 && !vis[ma[mass[r]]]) {
        vis[ma[mass[r]]] = 1;
        was.pb(ma[mass[r]]);
    }
    if (ma[mass[r]] > 0) ma2[ma[mass[r]]]--;
    ma[mass[r]]--;
    if (ma[mass[r]] > 0) ma2[ma[mass[r]]]++;
    if (ma[mass[r]] > 0 && !vis[ma[mass[r]]]) {
        vis[ma[mass[r]]] = 1;
        was.pb(ma[mass[r]]);
    }
}
void t_left(int t, int l, int r) {
    if (updates[t].FF < l || r < updates[t].FF) {
        mass[updates[t].FF] = updates[t].SS.FF;
        return;
    }
    if (ma[mass[updates[t].FF]] > 0 && !vis[ma[mass[updates[t].FF]]]) {
        vis[ma[mass[updates[t].FF]]] = 1;
        was.pb(ma[mass[updates[t].FF]]);
    }
    if (ma[mass[updates[t].FF]] > 0) ma2[ma[mass[updates[t].FF]]]--;
    ma[mass[updates[t].FF]]--;
    if (ma[mass[updates[t].FF]] > 0) ma2[ma[mass[updates[t].FF]]]++;
    if (ma[mass[updates[t].FF]] > 0 && !vis[ma[mass[updates[t].FF]]]) {
        vis[ma[mass[updates[t].FF]]] = 1;
        was.pb(ma[mass[updates[t].FF]]);
    }
    mass[updates[t].FF] = updates[t].SS.FF;
    if (ma[mass[updates[t].FF]] > 0 && !vis[ma[mass[updates[t].FF]]]) {
        vis[ma[mass[updates[t].FF]]] = 1;
        was.pb(ma[mass[updates[t].FF]]);
    }
    if (ma[mass[updates[t].FF]] > 0) ma2[ma[mass[updates[t].FF]]]--;
    ma[mass[updates[t].FF]]++;
    if (ma[mass[updates[t].FF]] > 0) ma2[ma[mass[updates[t].FF]]]++;
    if (ma[mass[updates[t].FF]] > 0 && !vis[ma[mass[updates[t].FF]]]) {
        vis[ma[mass[updates[t].FF]]] = 1;
        was.pb(ma[mass[updates[t].FF]]);
    }
}
void t_right(int t, int l, int r) {
    if (updates[t + 1].FF < l || r < updates[t + 1].FF) {
        mass[updates[t + 1].FF] = updates[t + 1].SS.SS;
        return;
    }
    if (ma[mass[updates[t + 1].FF]] > 0 && !vis[ma[mass[updates[t + 1].FF]]]) {
        vis[ma[mass[updates[t + 1].FF]]] = 1;
        was.pb(ma[mass[updates[t + 1].FF]]);
    }
    if (ma[mass[updates[t + 1].FF]] > 0)ma2[ma[mass[updates[t + 1].FF]]]--;
    ma[mass[updates[t + 1].FF]]--;
    if (ma[mass[updates[t + 1].FF]] > 0)ma2[ma[mass[updates[t + 1].FF]]]++;
    if (ma[mass[updates[t + 1].FF]] > 0 && !vis[ma[mass[updates[t + 1].FF]]]) {
        vis[ma[mass[updates[t + 1].FF]]] = 1;
        was.pb(ma[mass[updates[t + 1].FF]]);
    }
    mass[updates[t + 1].FF] = updates[t + 1].SS.SS;
    if (ma[mass[updates[t + 1].FF]] > 0 && !vis[ma[mass[updates[t + 1].FF]]]) {
        vis[ma[mass[updates[t + 1].FF]]] = 1;
        was.pb(ma[mass[updates[t + 1].FF]]);
    }
    if (ma[mass[updates[t + 1].FF]] > 0)ma2[ma[mass[updates[t + 1].FF]]]--;
    ma[mass[updates[t + 1].FF]]++;
    if (ma[mass[updates[t + 1].FF]] > 0)ma2[ma[mass[updates[t + 1].FF]]]++;
    if (ma[mass[updates[t + 1].FF]] > 0 && !vis[ma[mass[updates[t + 1].FF]]]) {
        vis[ma[mass[updates[t + 1].FF]]] = 1;
        was.pb(ma[mass[updates[t + 1].FF]]);
    }
}
void run() {
    int n, m;
    n = readInt();
    m = readInt();
    vector<int> mass2;
    mass.pb(0);
    mass2.pb(0);
    for (int i = 1; i <= n; ++i) {
        int x;
        x = readInt();
        mass.pb(x);
        mass2.pb(x);
    }
    updates.pb({-1, {-1, -1}});
    for (int i = 0; i < m; ++i) {
        int type;
        type = readInt();
        if (type == 1) {
            int l, r, k;
            l = readInt();
            r = readInt();
            k = readInt();
            zapros.pb(sob(l, r, k, updates.size() - 1, zapros.size() + 1));
        } else {
            int p, x;
            p = readInt();
            x = readInt();
            updates.pb({p, {mass2[p], x}});
            mass2[p] = x;
        }
    }
    sort(ALL(zapros), cmp);
    
    for (int i = zapros[0].l; i <= zapros[0].r; ++i) {
        ma[mass[i]]++;
    }
    for (int i = 1; i < MAXN; ++i) {
        if (ma[i] == 0) continue;
        ma2[ma[i]]++;
        if (!vis[ma[i]]) {
            vis[ma[i]] = 1;
            was.pb(ma[i]);
        }
    }
    for (int i = 1; i <= zapros[0].t; ++i) {
        t_right(i - 1, zapros[0].l, zapros[0].r);
    }
    

    ans[zapros[0].num] = solve(zapros[0].k);
    int now_l = zapros[0].l, now_r = zapros[0].r, now_t = zapros[0].t;
    for (int i = 1; i < zapros.size(); ++i) {
        int l = zapros[i].l;
        int r = zapros[i].r;
        int k = zapros[i].k;
        int t = zapros[i].t;
        while (l < now_l) {
            left_left(now_l);
            now_l--;
        }
        while (now_l < l) {
            left_right(now_l);
            now_l++;
        }
        while (r > now_r) {
            right_right(now_r);
            now_r++;
        }
        while (r < now_r) {
            right_left(now_r);
            now_r--;
        }
        while (t < now_t) {
            t_left(now_t, now_l, now_r);
            now_t--;
        }
        while (t > now_t) {
            t_right(now_t, now_l, now_r);
            now_t++;
        }
        

        ans[zapros[i].num] = solve(k);
    }
    for (int i = 1; i <= zapros.size(); ++i) {
        writeInt(ans[i]);
        writeWord("\n");
    }
    flush();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    

    t = 1;
    while (t--) run();
    return 0;
}


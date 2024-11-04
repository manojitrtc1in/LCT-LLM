




















using namespace std;

inline char gc() {
    static const int L = 233333;
    static char sxd[L], *sss = sxd, *ttt = sxd;
    if (sss == ttt) {
        ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
        if (sss == ttt) {
            return EOF;
        }
    }
    return *sss++;
}






inline char readalpha() {
    char dd;
    for (; !isalpha(c); dd);
    return c;
}

inline char readchar() {
    char dd;
    for (; c == ' '; dd);
    return c;
}

template <class T>
inline bool read(T& x) {
    bool flg = false;
    char dd;
    x = 0;
    for (; !isdigit(c); dd) {
        if (c == '-') {
            flg = true;
        } else if(c == EOF) {
            return false;
        }
    }
    for (; isdigit(c); dd) {
        x = (x * 10) + (c ^ 48);
    }
    if (flg) {
        x = -x;
    }
    return true;
}


template <class T>
inline void write(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x < 10) {
        putchar(x | 48);
        return;
    }
    write(x / 10);
    putchar((x % 10) | 48);
}

template <class T>
inline void id0(T x) {
    write(x);
    putchar(' ');
}

template <class T>
inline void writeln(T x) {
    write(x);
    puts("");
}

const int mod = 1000000007;
const int maxn = 200005;

typedef long long LL;

struct Edge {
    int to, dist, nxt;
} e[maxn << 1];

int first[maxn];

int cnt = 0;
inline void add_edge(int from, int to, int dist) {
    e[++cnt].nxt = first[from];
    first[from] = cnt;
    e[cnt].to = to;
    e[cnt].dist = dist;
    e[++cnt].nxt = first[to];
    first[to] = cnt;
    e[cnt].to = from;
    e[cnt].dist = dist;
}

int n;
int siz[maxn];
int fa[maxn];
LL ans1, ans2;

inline LL dfs(int now) {
    siz[now] = 1;
    priority_queue<int> q;
    while (!q.empty()) {
        q.pop();
    }
    int nowcnt = 1;
    LL nowans = 0;
    int distt = 0;
    for (int i = first[now]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (to != fa[now]) {
            fa[to] = now;
            LL nowx = dfs(to);
            siz[now] += siz[to];
            if (nowx) {
                if (nowcnt & 1) {
                    ans1 += nowans + nowx;
                    nowans = 0;
                } else {
                    nowans = nowx;
                }
                nowcnt ^= 1;
            }
        } else {
            distt = e[i].dist;
        }
    }
    if (nowcnt) {
        return nowans + distt;
    } else {
        return 0;
    }
}

LL dist[maxn];

inline void dfs2(int now, int fa) {
    ans2 += dist[now];
    for (int i = first[now]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (to != fa) {
            dist[to] = dist[now] + e[i].dist;
            dfs2(to, now);
        }
    }
}

inline void solve() {
    read(n);
    n <<= 1;
    ans1 = ans2 = 0;
    memset(first, 0, sizeof(first));
    cnt = 0;
    for (int i = 1; i < n; ++i) {
        int u, v, d;
        read(u), read(v), read(d);
        add_edge(u, v, d);
    }
    dfs(1);
    int rt = 0;
    for (int i = 1; i <= n; ++i) {
        bool flg = true;
        for (int j = first[i]; j; j = e[j].nxt) {
            int to = e[j].to;
            if (to != fa[i] && (siz[to] << 1) > n) {
                flg = false;
                break;
            }
        }
        if (flg && ((n - siz[i]) << 1) <= n) {
            rt = i;
            break;
        }
    }


    dist[rt] = 0;
    dfs2(rt, 0);
    id0(ans1);
    writeln(ans2);
}

int main() {
    int T;
    read(T);
    while (T--) {
        solve();
    }
    return 0;
}
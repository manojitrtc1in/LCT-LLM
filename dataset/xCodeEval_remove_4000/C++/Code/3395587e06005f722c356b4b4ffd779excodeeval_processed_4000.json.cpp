




















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



namespace dfcmd {

    const int maxn = 155;
    const int inf = 0x3f3f3f3f;

    int n, m;

    struct Matrix {
        bitset<maxn> mt[maxn];

        Matrix () {
            for (int i = 0; i < maxn; ++i) {
                mt[i].reset();
            }
        }

        inline void init() {
            for (int i = 1; i <= n; ++i) {
                mt[i][i] = 1;
            }
        }

        friend Matrix operator * (const Matrix& a, const Matrix& b) {
            Matrix ans;
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (a.mt[i][j]) {
                        ans.mt[i] |= b.mt[j];
                    }
                }
            }
            return ans;
        }
    };

    inline Matrix ksm(Matrix a, int b) {
        Matrix ans;
        ans.init();
        for (; b; b >>= 1, a = a * a) {
            

            if (b & 1) {
                ans = ans * a;
            }
        }
        
        return ans;
    }

    Matrix mt;

    struct Edge {
        int from, to, dist;

        friend bool operator < (const Edge& a, const Edge& b) {
            return a.dist < b.dist;
        }
    } e[maxn];

    int mp[maxn][maxn];
    int dist[maxn][maxn];
    int vis[maxn];

    inline void bfs(int from) {
        queue<int> q;
        dist[from][from] = 0;
        memset(vis, 0, sizeof(vis));
        vis[from] = 1;
        q.push(from);
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (int i = 1; i <= n; ++i) {
                if (!vis[i] && mp[now][i]) {
                    dist[from][i] = dist[from][now] + 1;
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
    }
    
    int Main() {
        read(n), read(m);
        for (int i = 1; i <= m; ++i) {
            read(e[i].from), read(e[i].to), read(e[i].dist);
        }
        sort(e + 1, e + m + 1);
        int Ans = inf;
        int now = 0;
        Matrix ans;
        ans.init();
        for (int i = 1; i <= m; ) {
            ans = ans * ksm(mt, e[i].dist - e[now].dist);
            
            now = i;
            while (i <= m && e[now].dist == e[i].dist) {
                mt.mt[e[i].from][e[i].to] = 1;
                mp[e[i].from][e[i].to] = 1;
                i++;
            }
            memset(dist, 0x3f, sizeof(dist));
            for (int j = 1; j <= n; ++j) {
                if (ans.mt[1][j]) {
                    bfs(j);
                    Ans = min(Ans, e[now].dist + dist[j][n]);
                }
            }
            
        }
        if (Ans < inf) {
            writeln(Ans);
        } else {
            puts("Impossible");
        }
        return 0;
    }

}

int main() {
    return dfcmd::Main();
}























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

    const int maxn = 5005;
    const int maxq = 100005;

    int n, q;

    struct Tree_Line {
        int no[maxn << 1];

        inline void init() {
            memset(no, 0, sizeof(no));
        }

        inline void _update(int x, int y) {
            

            for (; x <= n << 1; x += lowbit(x)) {
                no[x] += y;
            }
        }

        inline void update(int l, int r) {
            

            _update(l, 1);
            _update(r + 1, -1);
        }

        inline int query(int x) {
            int ans = 0;
            for (; x; x -= lowbit(x)) {
                ans += no[x];
            }
            return ans;
        }
    } s;

    struct Tree_2D {
        int no[maxn << 1][maxn];

        inline void init() {
            memset(no, 0, sizeof(no));
        }

        inline void _update(int x, int y, int xx) {
            for (; x <= n << 1; x += lowbit(x)) {
                for (int ty = y; ty <= n; ty += lowbit(ty)) {
                    no[x][ty] += xx;
                }
            }
        }

        inline void update(int lx, int ly, int rx, int ry) {
            if (lx <= rx && ly <= ry) {
                _update(lx, ly, 1);
                _update(rx + 1, ly, -1);
                _update(lx, ry + 1, -1);
                _update(rx + 1, ry + 1, 1);
            }
        }

        inline int query(int x, int y) {
            int ans = 0;
            for (; x; x -= lowbit(x)) {
                for (int ty = y; ty; ty -= lowbit(ty)) {
                    ans += no[x][ty];
                }
            }
            return ans;
        }
    } xx, yy;

    struct query {
        int typ, dir, x, y, len;
    } qq[maxq];

    int ans[maxq];

    inline void solve(int tp) {
        xx.init(), yy.init(), s.init();
        for (int i = 1; i <= q; ++i) {
            if (qq[i].typ == 2) {
                

                ans[i] += s.query(qq[i].x + qq[i].y) - xx.query(qq[i].x + qq[i].y, qq[i].x) - yy.query(qq[i].x + qq[i].y, qq[i].y);
            } else if ((qq[i].dir & 1) == tp) {
                

                if (qq[i].dir < 3) {
                    s.update(qq[i].x + qq[i].y, qq[i].x + qq[i].y + qq[i].len);
                    xx.update(qq[i].x + qq[i].y, 1, qq[i].x + qq[i].y + qq[i].len, qq[i].x - 1);
                    yy.update(qq[i].x + qq[i].y, 1, qq[i].x + qq[i].y + qq[i].len, qq[i].y - 1);
                } else {
                    s.update(qq[i].x + qq[i].y - qq[i].len, qq[i].x + qq[i].y);
                    xx.update(qq[i].x + qq[i].y - qq[i].len, qq[i].x + 1, qq[i].x + qq[i].y, n);
                    yy.update(qq[i].x + qq[i].y - qq[i].len, qq[i].y + 1, qq[i].x + qq[i].y, n);
                }
            }
        }
    }

    int Main() {
        read(n), read(q);
        for (int i = 1; i <= q; ++i) {
            read(qq[i].typ);
            if (qq[i].typ == 1) {
                read(qq[i].dir), read(qq[i].x), read(qq[i].y), read(qq[i].len);
                if (qq[i].dir == 3) {
                    qq[i].dir = 4;
                } else if (qq[i].dir == 4) {
                    qq[i].dir = 3;
                }
            } else {
                read(qq[i].x), read(qq[i].y);
            }
        }
        solve(1);
        for (int i = 1; i <= q; ++i) {
            qq[i].y = n - qq[i].y + 1;
        }
        solve(0);
        for (int i = 1; i <= q; ++i) {
            if (qq[i].typ == 2) {
                writeln(ans[i]);
            }
        }
        return 0;
    }

}

int main() {
    return dfcmd::Main();
}



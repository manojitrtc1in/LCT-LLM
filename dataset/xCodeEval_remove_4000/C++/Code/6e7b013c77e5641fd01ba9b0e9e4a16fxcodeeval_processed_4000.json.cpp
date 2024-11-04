




















using namespace std;

namespace pufanyi {

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
            x = (x << 1) + (x << 3) + (c ^ 48);
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

    typedef long long LL;

    const int maxn = 500005;

    int n, m;

    LL ans[maxn];

    struct Query {
        int id, iid, qz;
        Query(int id, int iid, int qz) { this->id = id, this->iid = iid, this->qz = qz; }
    };

    vector<Query> q[maxn];

    struct CaoZuo {
        char c;
        int x, y;
    } cz[maxn];

    struct Node {
        int ls, rs;
        LL tag;
    } no[maxn * 20];

    namespace mynode {
        int cnt;
        queue<int> q;
    }

    inline int node() {
        int now;
        if (mynode::q.empty()) {
            now = ++mynode::cnt;
        } else {
            now = mynode::q.front();
            mynode::q.pop();
        }
        no[now].ls = no[now].rs = no[now].tag = 0;
        return now;
    }

    inline void rm(int now) {
        mynode::q.push(now);
    }

    inline void clear() {
        mynode::cnt = 0;
        while (!mynode::q.empty()) {
            mynode::q.pop();
        }
    }

    int fa[maxn];
    int rt[maxn];

    inline int getfa(int x) {
        return fa[x] == x ? x : fa[x] = getfa(fa[x]);
    }

    namespace getquery {

        inline void push_down(int x) {
            if (no[x].tag) {
                if (no[x].ls) {
                    no[no[x].ls].tag = no[x].tag;
                }
                if (no[x].rs) {
                    no[no[x].rs].tag = no[x].tag;
                }
                no[x].tag = 0;
            }
        }

        inline int Merge(int x, int y) {
            

            if (!x) {
                return y;
            }
            if (!y) {
                return x;
            }
            push_down(x), push_down(y);
            int rt = node();
            no[rt].ls = Merge(no[x].ls, no[y].ls);
            no[rt].rs = Merge(no[x].rs, no[y].rs);
            rm(x), rm(y);
            return rt;
        }

        inline void build_tree(int& rt, int l, int r, int K) {
            if (!rt) {
                rt = node();
            }
            if (l == r) {
                return;
            }
            int mid = (l + r) >> 1;
            if (K <= mid) {
                build_tree(no[rt].ls, l, mid, K);
            } else {
                build_tree(no[rt].rs, mid + 1, r, K);
            }
        }

        inline int query(int rt, int l, int r, int K) {
            

            assert(rt);
            if (no[rt].tag) {
                return no[rt].tag;
            }
            if (l == r) {
                return 0;
            }
            int mid = (l + r) >> 1;
            if (K <= mid) {
                return query(no[rt].ls, l, mid, K);
            } else {
                return query(no[rt].rs, mid + 1, r, K);
            }
        }

        inline void work() {
            clear();
            for (int i = 1; i <= n; ++i) {
                fa[i] = i;
                build_tree(rt[i], 1, n, i);
            }
            for (int i = 1; i <= m; ++i) {
                cz[i].c = readchar();
                if (cz[i].c == 'U') {
                    read(cz[i].x), read(cz[i].y);
                } else if (cz[i].c == 'M') {
                    read(cz[i].x), read(cz[i].y);
                    int fax = getfa(cz[i].x), fay = getfa(cz[i].y);
                    if (fax != fay) {
                        fa[fay] = fax;
                        rt[fax] = Merge(rt[fax], rt[fay]);
                    }
                } else if (cz[i].c == 'A') {
                    read(cz[i].x);
                } else if (cz[i].c == 'Z') {
                    read(cz[i].x);
                    no[rt[getfa(cz[i].x)]].tag = i;
                } else if (cz[i].c == 'Q') {
                    read(cz[i].x);
                    q[i].emplace_back(cz[i].x, i, 1);
                    q[query(rt[getfa(cz[i].x)], 1, n, cz[i].x)].emplace_back(cz[i].x, i, -1);
                } else {
                    assert(false);
                }
            }
        }
    }

    namespace getans {
        inline void push_down(int x) {
            if (no[x].tag) {
                if (no[x].ls) {
                    no[no[x].ls].tag += no[x].tag;
                }
                if (no[x].rs) {
                    no[no[x].rs].tag += no[x].tag;
                }
                no[x].tag = 0;
            }
        }

        inline int Merge(int x, int y) {
            

            if (!x) {
                return y;
            }
            if (!y) {
                return x;
            }
            push_down(x), push_down(y);
            int rt = node();
            no[rt].ls = Merge(no[x].ls, no[y].ls);
            no[rt].rs = Merge(no[x].rs, no[y].rs);
            rm(x), rm(y);
            return rt;
        }

        inline void build_tree(int& rt, int l, int r, int K) {
            if (!rt) {
                rt = node();
            }
            if (l == r) {
                return;
            }
            int mid = (l + r) >> 1;
            if (K <= mid) {
                build_tree(no[rt].ls, l, mid, K);
            } else {
                build_tree(no[rt].rs, mid + 1, r, K);
            }
        }

        inline LL query(int rt, int l, int r, int K) {
            

            assert(rt);
            if (l == r) {
                return no[rt].tag;
            }
            int mid = (l + r) >> 1;
            if (K <= mid) {
                return no[rt].tag + query(no[rt].ls, l, mid, K);
            } else {
                return no[rt].tag + query(no[rt].rs, mid + 1, r, K);
            }
        }

        int siz[maxn];

        inline void work() {
            memset(rt, 0, sizeof(rt));
            clear();
            for (int i = 1; i <= n; ++i) {
                build_tree(rt[i], 1, n, i);
                fa[i] = i;
                siz[i] = 1;
            }
            

            for (int i = 1; i <= m; ++i) {
                if (cz[i].c == 'U') {
                    int fax = getfa(cz[i].x);
                    int fay = getfa(cz[i].y);
                    if (fax != fay) {
                        fa[fay] = fax;
                        siz[fax] += siz[fay];
                        rt[fax] = Merge(rt[fax], rt[fay]);
                    }
                } else if (cz[i].c == 'A') {
                    int fax = getfa(cz[i].x);
                    no[rt[fax]].tag += siz[fax];
                    

                }
                

                for (auto qq : q[i]) {
                    

                    ans[qq.iid] += qq.qz * query(rt[getfa(qq.id)], 1, n, qq.id);
                }
                

            }
        }
    }

    int Main() {
        read(n), read(m);
        getquery::work();
        getans::work();
        for (int i = 1; i <= m; ++i) {
            if (cz[i].c == 'Q') {
                writeln(ans[i]);
            }
        }
        return 0;
    }

}

int main() {
    return pufanyi::Main();
}

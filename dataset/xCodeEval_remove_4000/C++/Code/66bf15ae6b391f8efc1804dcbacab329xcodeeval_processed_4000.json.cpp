

















typedef long long LL;
typedef unsigned long long uLL;










































































































































































































































































































































































































































int read() {
    int s = 0,w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}
 
LL readl() {
    LL s = 0,w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}




const int maxn = 1e5 + 10;

int n;
int vis[maxn];
int c[maxn];
std::vector<int> ans;

bool ask(int a, int b, int cc) {
    printf("? %d %d %d\n", a, b, cc);
    fflush(stdout);
    int val = read();
    if (val == -1) exit(0);
    return val == 0;
}

int main() {
    int T = read();
    while (T-- ) {
        n = read();
        std::fill(vis + 1, vis + 1 + n, 0);
        for (int i = 1 ; i <= n ; i++ ) {
            c[i] = -1;
        }
        int mor = -1, les = -1;
        for (int i = 1 ; i <= n ; i += 3 ) {
            if (ask(i, i + 1, i + 2)) {
                mor = i;
                c[i / 3 + 1] = 0;
            } else {
                les = i;
                c[i / 3 + 1] = 1;
            }
            if (les >= 1 && mor >= 1) break;
        }
        assert(les >= 1 && mor >= 1);
        ans.clear();
        int e1, e2 = -1, h = -1;
        for (int i = 0 ; i < 2 ; i++ ) {
            for (int j = i + 1 ; j < 3 ; j++ ) {
                bool ok1 = ask(les + i, les + j, mor);
                bool ok2 = ask(les + i, les + j, mor + 1);
                if (!ok1 && !ok2) {
                    e1 = les + i;
                    e2 = les + j;
                    break;
                } else {
                    if (ok1) h = mor;
                    if (ok2) h = mor + 1;
                }
            }
            if (e2 != -1) break;
        }
        assert(e2 != -1);
        

        vis[e1] = vis[e2] = 1;
        if (h == -1) {
            if (ask(mor, mor + 1, e1)) {
                h = mor;
            } else {
                h = mor + 2;
            }
        }
        

        vis[h] = 2;
        assert(h != -1);
        ans.eb(h);
        for (int i = 1 ; i <= n ; i += 3 ) {
            

            

            if (c[i / 3 + 1] == -1) {
                for (int j = i ; j <= i + 2 ; j++ ) {
                    if (ask(h, e1, j)) ans.eb(j);
                }
            } else {
                bool has = false;
                for (int j = i ; j <= i + 2 ; j++ ) {
                    if (vis[j]) has = true;
                }
                if (has) {
                    for (int j = i ; j <= i + 2 ; j++ ) {
                        if (vis[j]) continue;
                        if (ask(h, e1, j)) ans.eb(j);
                    }
                } else {
                    if (c[i / 3 + 1] == 0) {
                        bool ok1 = ask(e1, i, i + 1);
                        bool ok2 = ask(e1, i + 1, i + 2);
                        

                        if (ok1 && ok2) {
                            ans.eb(i);
                            ans.eb(i + 1);
                            ans.eb(i + 2);
                        } else if (ok1) {
                            ans.eb(i);
                            ans.eb(i + 1);
                        } else if (ok2) {
                            ans.eb(i + 1);
                            ans.eb(i + 2);
                        } else {
                            ans.eb(i);
                            ans.eb(i + 2);
                        }
                    } else {
                        bool ok1 = ask(h, i, i + 1);
                        bool ok2 = ask(h, i + 1, i + 2);
                        if (!ok1 && !ok2) {
                            

                            

                            

                        } else if (!ok1) {
                            ans.eb(i + 2);
                        } else if (!ok2) {
                            ans.eb(i);
                        } else {
                            ans.eb(i + 1);
                        }
                    }
                }
            }
        }
        int lens = ans.size();
        printf("! %d", lens);
        for (int i = 0 ; i < lens ; i++ ) {
            printf(" %d", ans[i]);
        }
        printf("\n");
        fflush(stdout);
    }
    return 0;
}

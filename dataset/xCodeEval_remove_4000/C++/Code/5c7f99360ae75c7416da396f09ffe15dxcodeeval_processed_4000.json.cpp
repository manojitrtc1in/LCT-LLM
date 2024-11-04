
using namespace std;









typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int oo = 1e9;
const ll OO = 1e18;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1);
const double E = 2.71828182845904523536;

typedef pair<pii, int> piii;
piii from[50], to[50];
int out1[10800][4], out2[10800][4], from_to[50];

inline bool cmp(const piii& a, const piii& b) {return a.ff.ff ^ b.ff.ff ? a.ff.ff < b.ff.ff : (a.ff.ff ^ 2 ? a.ff.ss < b.ff.ss : a.ff.ss > b.ff.ss);}

int main() {
    int n, m, res1 = 0, res2 = 0;
    sc("%d%d", &n, &m);
    if (n ^ 2) {
        for (int i = 0; i ^ m; ++i)
            sc("%d%d", &from[i].ff.ff, &from[i].ff.ss);
        for (int i = 0; i ^ m; ++i)
            sc("%d%d", &to[i].ff.ff, &to[i].ff.ss);
        for (int i = 0; i ^ m; ++i)
            from[i].ss = to[i].ss = i;
        

        sort(from, from + m, cmp);
        for (int i = 0; i ^ m; ++i) {
            if (from[i].ff.ff == 1) {
                while (from[i].ff.ss ^ i + 1) {
                    out1[res1][0] = 1;
                    out1[res1][1] = from[i].ff.ss;
                    out1[res1][2] = 1;
                    out1[res1][3] = --from[i].ff.ss;
                    ++res1;
                }
            }
            else if (from[i].ff.ff == 2) {
                while (from[i].ff.ss ^ n) {
                    out1[res1][0] = 2;
                    out1[res1][1] = from[i].ff.ss;
                    out1[res1][2] = 2;
                    out1[res1][3] = ++from[i].ff.ss;
                    ++res1;
                }
                out1[res1][0] = 2;
                out1[res1][1] = n;
                from[i].ff.ff = out1[res1][2] = 1;
                out1[res1][3] = n;
                ++res1;
                while (from[i].ff.ss ^ i + 1) {
                    out1[res1][0] = 1;
                    out1[res1][1] = from[i].ff.ss;
                    out1[res1][2] = 1;
                    out1[res1][3] = --from[i].ff.ss;
                    ++res1;
                }
            }
            else {
                while (from[i].ff.ff ^ 2) {
                    out1[res1][0] = from[i].ff.ff;
                    out1[res1][1] = from[i].ff.ss;
                    out1[res1][2] = --from[i].ff.ff;
                    out1[res1][3] = from[i].ff.ss;
                    ++res1;
                }
                if (from[i].ff.ss ^ i + 1) {
                    if (from[i].ff.ss <= i) {
                        while (from[i].ff.ss ^ i + 1) {
                            out1[res1][0] = 2;
                            out1[res1][1] = from[i].ff.ss;
                            out1[res1][2] = 2;
                            out1[res1][3] = ++from[i].ff.ss;
                            ++res1;
                        }
                    }
                    else {
                        while (from[i].ff.ss ^ i + 1) {
                            out1[res1][0] = 2;
                            out1[res1][1] = from[i].ff.ss;
                            out1[res1][2] = 2;
                            out1[res1][3] = --from[i].ff.ss;
                            ++res1;
                        }
                    }
                }
                out1[res1][0] = 2;
                out1[res1][1] = i + 1;
                from[i].ff.ff = out1[res1][2] = 1;
                out1[res1][3] = i + 1;
                ++res1;
            }
        }
        for (int i = 0; i ^ m; ++i) {
            out1[res1][0] = 1;
            out1[res1][1] = i + 1;
            from[i].ff.ff = out1[res1][2] = 2;
            out1[res1][3] = i + 1;
            ++res1;
            out1[res1][0] = 2;
            out1[res1][1] = i + 1;
            from[i].ff.ff = out1[res1][2] = 3;
            out1[res1][3] = i + 1;
            ++res1;
        }
        

        sort(to, to + m, cmp);
        for (int i = 0; i ^ m; ++i) {
            if (to[i].ff.ff == 1) {
                while (to[i].ff.ss ^ i + 1) {
                    out2[res2][0] = 1;
                    out2[res2][1] = to[i].ff.ss;
                    out2[res2][2] = 1;
                    out2[res2][3] = --to[i].ff.ss;
                    ++res2;
                }
            }
            else if (to[i].ff.ff == 2) {
                while (to[i].ff.ss ^ n) {
                    out2[res2][0] = 2;
                    out2[res2][1] = to[i].ff.ss;
                    out2[res2][2] = 2;
                    out2[res2][3] = ++to[i].ff.ss;
                    ++res2;
                }
                out2[res2][0] = 2;
                out2[res2][1] = n;
                to[i].ff.ff = out2[res2][2] = 1;
                out2[res2][3] = n;
                ++res2;
                while (to[i].ff.ss ^ i + 1) {
                    out2[res2][0] = 1;
                    out2[res2][1] = to[i].ff.ss;
                    out2[res2][2] = 1;
                    out2[res2][3] = --to[i].ff.ss;
                    ++res2;
                }
            }
            else {
                while (to[i].ff.ff ^ 2) {
                    out2[res2][0] = to[i].ff.ff;
                    out2[res2][1] = to[i].ff.ss;
                    out2[res2][2] = --to[i].ff.ff;
                    out2[res2][3] = to[i].ff.ss;
                    ++res2;
                }
                if (to[i].ff.ss ^ i + 1) {
                    if (to[i].ff.ss <= i) {
                        while (to[i].ff.ss ^ i + 1) {
                            out2[res2][0] = 2;
                            out2[res2][1] = to[i].ff.ss;
                            out2[res2][2] = 2;
                            out2[res2][3] = ++to[i].ff.ss;
                            ++res2;
                        }
                    }
                    else {
                        while (to[i].ff.ss ^ i + 1) {
                            out2[res2][0] = 2;
                            out2[res2][1] = to[i].ff.ss;
                            out2[res2][2] = 2;
                            out2[res2][3] = --to[i].ff.ss;
                            ++res2;
                        }
                    }
                }
                out2[res2][0] = 2;
                out2[res2][1] = i + 1;
                to[i].ff.ff = out2[res2][2] = 1;
                out2[res2][3] = i + 1;
                ++res2;
            }
        }
        

        for (int i = 0; i ^ m; ++i)
            from_to[from[i].ss] = i;
        for (int j = 0; j ^ m; ++j) {
            int i = from_to[to[j].ss];
            out1[res1][0] = 3;
            out1[res1][1] = from[i].ff.ss;
            from[i].ff.ff = out1[res1][2] = 2;
            out1[res1][3] = from[i].ff.ss;
            ++res1;
            if (from[i].ff.ss ^ j + 1) {
                if (from[i].ff.ss <= j) {
                    while (from[i].ff.ss ^ j + 1) {
                        out1[res1][0] = 2;
                        out1[res1][1] = from[i].ff.ss;
                        out1[res1][2] = 2;
                        out1[res1][3] = ++from[i].ff.ss;
                        ++res1;
                    }
                }
                else {
                    while (from[i].ff.ss ^ j + 1) {
                        out1[res1][0] = 2;
                        out1[res1][1] = from[i].ff.ss;
                        out1[res1][2] = 2;
                        out1[res1][3] = --from[i].ff.ss;
                        ++res1;
                    }
                }
            }
            out1[res1][0] = 2;
            out1[res1][1] = j + 1;
            from[i].ff.ff = out1[res1][2] = 1;
            out1[res1][3] = j + 1;
            ++res1;
        }
        

        if (n ^ 1) {
            pr("%d\n", res1 + res2);
            for (int i = 0; i ^ res1; ++i)
                for (int j = 0; j ^ 4; ++j)
                    pr("%d%c", out1[i][j], j ^ 3 ? ' ' : '\n');
            for (int i = res2 - 1; ~i; --i)
                pr("%d %d %d %d\n", out2[i][2], out2[i][3], out2[i][0], out2[i][1]);
        }
        else
            pr("0\n");
    }
    else {
        for (int i = 0; i ^ m; ++i)
            sc("%d%d", &from[i].ff.ff, &from[i].ff.ss);
        for (int i = 0; i ^ m; ++i)
            sc("%d%d", &to[i].ff.ff, &to[i].ff.ss);
        for (int i = 0; i ^ m; ++i)
            from[i].ss = to[i].ss = i;
        

        sort(from, from + m, cmp);
        for (int i = 0; i ^ m; ++i) {
            if (from[i].ff.ff == 1) {
                while (from[i].ff.ss ^ i + 1) {
                    out1[res1][0] = 1;
                    out1[res1][1] = from[i].ff.ss;
                    out1[res1][2] = 1;
                    out1[res1][3] = --from[i].ff.ss;
                    ++res1;
                }
            }
            else if (from[i].ff.ff == 2) {
                while (from[i].ff.ss ^ n) {
                    out1[res1][0] = 2;
                    out1[res1][1] = from[i].ff.ss;
                    out1[res1][2] = 2;
                    out1[res1][3] = ++from[i].ff.ss;
                    ++res1;
                }
                out1[res1][0] = 2;
                out1[res1][1] = n;
                from[i].ff.ff = out1[res1][2] = 1;
                out1[res1][3] = n;
                ++res1;
                while (from[i].ff.ss ^ i + 1) {
                    out1[res1][0] = 1;
                    out1[res1][1] = from[i].ff.ss;
                    out1[res1][2] = 1;
                    out1[res1][3] = --from[i].ff.ss;
                    ++res1;
                }
            }
            else {
                while (from[i].ff.ff ^ 2) {
                    out1[res1][0] = from[i].ff.ff;
                    out1[res1][1] = from[i].ff.ss;
                    out1[res1][2] = --from[i].ff.ff;
                    out1[res1][3] = from[i].ff.ss;
                    ++res1;
                }
                if (from[i].ff.ss ^ i + 1) {
                    if (from[i].ff.ss <= i) {
                        while (from[i].ff.ss ^ i + 1) {
                            out1[res1][0] = 2;
                            out1[res1][1] = from[i].ff.ss;
                            out1[res1][2] = 2;
                            out1[res1][3] = ++from[i].ff.ss;
                            ++res1;
                        }
                    }
                    else {
                        while (from[i].ff.ss ^ i + 1) {
                            out1[res1][0] = 2;
                            out1[res1][1] = from[i].ff.ss;
                            out1[res1][2] = 2;
                            out1[res1][3] = --from[i].ff.ss;
                            ++res1;
                        }
                    }
                }
                out1[res1][0] = 2;
                out1[res1][1] = i + 1;
                from[i].ff.ff = out1[res1][2] = 1;
                out1[res1][3] = i + 1;
                ++res1;
            }
        }
        

        sort(to, to + m, cmp);
        for (int i = 0; i ^ m; ++i) {
            if (to[i].ff.ff == 1) {
                while (to[i].ff.ss ^ i + 1) {
                    out2[res2][0] = 1;
                    out2[res2][1] = to[i].ff.ss;
                    out2[res2][2] = 1;
                    out2[res2][3] = --to[i].ff.ss;
                    ++res2;
                }
            }
            else if (to[i].ff.ff == 2) {
                while (to[i].ff.ss ^ n) {
                    out2[res2][0] = 2;
                    out2[res2][1] = to[i].ff.ss;
                    out2[res2][2] = 2;
                    out2[res2][3] = ++to[i].ff.ss;
                    ++res2;
                }
                out2[res2][0] = 2;
                out2[res2][1] = n;
                to[i].ff.ff = out2[res2][2] = 1;
                out2[res2][3] = n;
                ++res2;
                while (to[i].ff.ss ^ i + 1) {
                    out2[res2][0] = 1;
                    out2[res2][1] = to[i].ff.ss;
                    out2[res2][2] = 1;
                    out2[res2][3] = --to[i].ff.ss;
                    ++res2;
                }
            }
            else {
                while (to[i].ff.ff ^ 2) {
                    out2[res2][0] = to[i].ff.ff;
                    out2[res2][1] = to[i].ff.ss;
                    out2[res2][2] = --to[i].ff.ff;
                    out2[res2][3] = to[i].ff.ss;
                    ++res2;
                }
                if (to[i].ff.ss ^ i + 1) {
                    if (to[i].ff.ss <= i) {
                        while (to[i].ff.ss ^ i + 1) {
                            out2[res2][0] = 2;
                            out2[res2][1] = to[i].ff.ss;
                            out2[res2][2] = 2;
                            out2[res2][3] = ++to[i].ff.ss;
                            ++res2;
                        }
                    }
                    else {
                        while (to[i].ff.ss ^ i + 1) {
                            out2[res2][0] = 2;
                            out2[res2][1] = to[i].ff.ss;
                            out2[res2][2] = 2;
                            out2[res2][3] = --to[i].ff.ss;
                            ++res2;
                        }
                    }
                }
                out2[res2][0] = 2;
                out2[res2][1] = i + 1;
                to[i].ff.ff = out2[res2][2] = 1;
                out2[res2][3] = i + 1;
                ++res2;
            }
        }
        

        if (m ^ 1) {
            if (from[0].ss ^ to[0].ss) {
                out1[res1][0] = 1;
                out1[res1][1] = 1;
                out1[res1][2] = 2;
                out1[res1][3] = 1;
                ++res1;
                out1[res1][0] = 1;
                out1[res1][1] = 2;
                out1[res1][2] = 1;
                out1[res1][3] = 1;
                ++res1;
                out1[res1][0] = 2;
                out1[res1][1] = 1;
                out1[res1][2] = 2;
                out1[res1][3] = 2;
                ++res1;
                out1[res1][0] = 2;
                out1[res1][1] = 2;
                out1[res1][2] = 1;
                out1[res1][3] = 2;
                ++res1;
            }
            pr("%d\n", res1 + res2);
            for (int i = 0; i ^ res1; ++i)
                for (int j = 0; j ^ 4; ++j)
                    pr("%d%c", out1[i][j], j ^ 3 ? ' ' : '\n');
            for (int i = res2 - 1; ~i; --i)
                pr("%d %d %d %d\n", out2[i][2], out2[i][3], out2[i][0], out2[i][1]);
        }
        else {
            pr("%d\n", res1 + res2);
            for (int i = 0; i ^ res1; ++i)
                for (int j = 0; j ^ 4; ++j)
                    pr("%d%c", out1[i][j], j ^ 3 ? ' ' : '\n');
            for (int i = res2 - 1; ~i; --i)
                pr("%d %d %d %d\n", out2[i][2], out2[i][3], out2[i][0], out2[i][1]);
        }
    }
    return 0;
}

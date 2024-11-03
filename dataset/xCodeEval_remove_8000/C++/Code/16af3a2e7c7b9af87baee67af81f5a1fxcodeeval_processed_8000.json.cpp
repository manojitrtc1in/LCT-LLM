
















using namespace std;




























































typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
const int INF = 0x3f3f3f3f;
const double eps = 1e-10;
const int MOD = 100000007;
const int MAXN = 300010;































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































int n[MAXN], ans[MAXN];

inline int lowbit(int x) { return x & -x; }

inline int sum(int p)
{
    int ret = 0;
    while (p > 0)
    {
        ret += n[p];
        p -= lowbit(p);
    }
    return ret;
}

inline void add(int p, int v)
{
    while (p < MAXN)
    {
        n[p] += v;
        p += lowbit(p);
    }
}

void update(int l, int r, int v)
{
    int ls = sum(l - 1), rs = sum(r);
    if (rs == ls) return;
    if (l == r)
    {
        add(l, -1);
        ans[l] = v;
        return;
    }
    int m = (l + r) >> 1;
    update(l, m, v);
    update(m + 1, r, v);
}

int main()
{


    int a, b, x, y, z;
    RII(a, b);
    FE(i, 1, a) add(i, 1);
    REP(i, b)
    {
        RIII(x, y, z);
        update(x, y, z);
        add(z, 1);
        ans[z] = 0;
    }
    FE(i, 1, a)
    {
        if (i != 1) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    return 0;
}













































using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;










template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y)
{
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y)
{
    if (x < y) x = y;
}
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
ld id0 = 0;
double getTime() { return (clock() - id0) / (double)CLOCKS_PER_SEC; }
pair<int, int> operator-(pair<int, int> a, pair<int, int> b)
{
    return { a.first - b.first, a.second - b.second };
}
pair<int, int> operator+(pair<int, int> a, pair<int, int> b)
{
    return { a.first + b.first, a.second + b.second };
}


const int inf = 1e9 + 228;
const ld EPS = 1e-15;
const ld PI = acos(-1.0);
int mod = 1000000007;
const ll INF = 1e18;
const int MAXN = 2e5 + 229;
const int MAXA = 2e4 + 20;
const int am = 13;
const int bl = 600;
const vector<int> small = { 2,3,5,7,11,13,17,19,23,29,31,37,41 };
int dpsmall[1 << am];
int n, m, c, q;
struct query
{
    int  l, r, id;
};
bool operator<(query a, query b)
{
    if (a.l / bl == b.l / bl)
    {
        int x = a.l / bl;
        

        return (x % 2 ? a.r > b.r:a.r < b.r);
    }
    return a.l < b.l;
}


int dpbig[1 << am][3000];
int dppair[1 << am][5000];
int primescnt[MAXA];
int posid[MAXA];
int lp[MAXA];
vector<int> pr;
vector<int> keks[MAXA];
inline void add(int x, int y)
{
    for (int j : keks[x])primescnt[j] += y;
}
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(3), cout.setf(ios::fixed);
    cin >> n >> m >> c >> q;
    vector<int> id1;
    id0 = clock();
    for (int i = 2; i < MAXA; ++i)
    {
        if (!lp[i])
        {
            lp[i] = i;
            pr.pbc(i);
        }
        for (int j = 0; j < pr.size() && pr[j] * i < MAXA && pr[j] <= lp[i]; ++j)
        {
            lp[i * pr[j]] = pr[j];
        }
    }
    id1 = pr;
    for (int x = 0; x < id1.size(); ++x) posid[id1[x]] = x;

    for (int i = 2; i < MAXA; ++i)
    {
        int ti = i;
        while (ti > 1)
        {
            keks[i].pbc(posid[lp[ti]]);
            ti /= lp[ti];
        }
    }
    vector<pair<int, int>> bigpairs;
    int pos = 13;
    

    for (int i = pos; i < id1.size(); ++i)
    {
        for (int j = i + 1; j < id1.size(); ++j)
        {
            if (id1[i] * id1[j] > c) break;
            bigpairs.pbc({ id1[i], id1[j] });
        }
    }
    

    for (int i = 0; i < (1 << am); ++i)
    {
        int go = c;
        int cnt = 0;
        for (int j = 0; j < am; ++j)
        {
            if ((i >> j) & 1) go /= small[j], ++cnt;
        }
        if (cnt % 2) go *= -1;
        dpsmall[i] = go;
        for (int j = pos; j < id1.size(); ++j)
        {
            int tgo = go / id1[j];
            tgo *= -1;
            dpbig[i][j] = tgo;
        }
        for (int j = 0; j < bigpairs.size(); ++j)
        {
            int tgo = go / bigpairs[j].first / bigpairs[j].second;
            dppair[i][j] = tgo;
        }
    }
    for (int bt = 0; bt < am; ++bt)
    {
        for (int mask = 0; mask < (1 << am); ++mask)
        {
            if ((mask >> bt) & 1)
            {
                dpsmall[mask] += dpsmall[mask ^ (1 << bt)];
            }
        }
        for (int mask = 0; mask < (1 << am); ++mask)
        {
            if ((mask >> bt) & 1)
                for (int pr = 13; pr < id1.size(); ++pr)
                {
                    dpbig[mask][pr] += dpbig[mask ^ (1 << bt)][pr];
                }
        }
        for (int mask = 0; mask < (1 << am); ++mask)
        {
            if ((mask >> bt) & 1)

                for (int j = 0; j < bigpairs.size(); ++j)
                {
                    dppair[mask][j] += dppair[mask ^ (1 << bt)][j];
                }
        }
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<query> qq(q);
    vector<int> res(q);
    for (int i = 0; i < q; ++i)
    {
        cin >> qq[i].l >> qq[i].r;
        --qq[i].l; --qq[i].r;
        qq[i].id = i;
    }
    sort(all(qq));
    int l = 0, r = -1;
    for (auto& i : bigpairs) i.first = posid[i.first], i.second = posid[i.second];
    for (auto j : qq)
    {
        while (l < j.l)
        {
            add(a[l++], -1);
        }
        while (l > j.l)
        {
            add(a[--l], 1);
        }
        while (r < j.r)
        {
            add(a[++r], 1);
        }
        while (r > j.r)
        {
            add(a[r--], -1);
        }
        int msk = 0;
        for (int j = 0; j < 13; ++j)
        {
            if (primescnt[j] > 0)
            {
                msk |= (1 << j);
            }
        }
        res[j.id] += dpsmall[msk];
        for (int x = 13; x < id1.size(); ++x)
        {
            if (primescnt[x])
            {
                res[j.id] += dpbig[msk][x];
            }
        }
        for (int pid = 0; pid < bigpairs.size(); ++pid)
        {
            if (primescnt[bigpairs[pid].first] && primescnt[bigpairs[pid].second])
            {
                res[j.id] += dppair[msk][pid];
            }
        }
    }
    for (int i = 0; i < q; ++i)
    {
        cout << res[i] << '\n';
    }
    

}
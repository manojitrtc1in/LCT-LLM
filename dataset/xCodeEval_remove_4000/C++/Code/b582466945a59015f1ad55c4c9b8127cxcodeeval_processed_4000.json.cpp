


using namespace std;

typedef long long ll;

ll n, m, k;

void Jeden(vector< vector<ll> >& a, vector< vector<ll> >& f)
{
    vector< vector<ll> > id2(n, vector<ll>(m, 0));
    for (int i = k - 1, j = k - 1; j + k - 1 <= m - 1; ++j)
        for (int l = 0; l < k; ++l)
            id2[i][j] += a[i - l][j - k + 1 + l];
    for (int i = k, j = m - k; i + k - 1 <= n - 1; ++i)
        for (int l = 0; l < k; ++l)
            id2[i][j] += a[i - l][j - k + 1 + l];
    for (int i = k; i + k - 1 <= n - 1; ++i)
        for (int j = k - 1; j + k - 1 <= m - 2; ++j)
            id2[i][j] = id2[i - 1][j + 1] - a[i - 1 - k + 1][j + 1] + a[i][j - k + 1];

    vector< vector<ll> > kolumna(n, vector<ll>(m, 0));
    for (int i = k - 1, j = k - 1; j + k - 1 <= m - 1; ++j)
        for (int l = 0; l < k; ++l)
            kolumna[i][j] += a[i - l][j];
    for (int i = k; i + k - 1 <= n - 1; ++i)
        for (int j = k - 1; j + k - 1 <= m - 1; ++j)
            kolumna[i][j] = kolumna[i - 1][j] - a[i - 1 - k + 1][j] + a[i][j];

    vector< vector<ll> > id0(n, vector<ll>(m, 0));
    for (int i = k - 1, j = k - 1; j + k - 1 <= m - 1; ++j)
        for (int l = 0; l < k; ++l)
            id0[i][j] += a[i - l][j] * (k - l);
    for (int i = k; i + k - 1 <= n - 1; ++i)
        for (int j = k - 1; j + k - 1 <= m - 1; ++j)
            id0[i][j] = id0[i - 1][j] - kolumna[i - 1][j] + a[i][j] * k;

    vector< vector<ll> > id3(n, vector<ll>(m, 0));
    for (int i = k - 1, j = k - 1; i + k - 1 <= n - 1; ++i)
        for (int l = i, il = k; il >= 1; --l, --il)
            for (int o = 0; o < il; ++o)
                id3[i][j] += a[l][j - o];
    for (int i = k - 1; i + k - 1 <= n - 1; ++i)
        for (int j = k; j + k - 1 <= m - 1; ++j)
            id3[i][j] = id3[i][j - 1] - id2[i][j - 1] + kolumna[i][j];

    vector< vector<ll> > id4(n, vector<ll>(m, 0));
    for (int i = k - 1, j = k - 1; i + k - 1 <= n - 1; ++i)
        for (int l = i, il = k; il >= 1; --l, --il)
            for (int o = 0; o < il; ++o)
                id4[i][j] += a[l][j - o] * (il - o);
    for (int i = k - 1; i + k - 1 <= n - 1; ++i)
        for (int j = k; j + k - 1 <= m - 1; ++j)
            id4[i][j] = id4[i][j - 1] - id3[i][j - 1] + id0[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            f[i][j] += id4[i][j];
}

void Dwa(vector< vector<ll> >& a, vector< vector<ll> >& f)
{
    vector< vector<ll> > id2(n, vector<ll>(m, 0));
    for (int i = k - 1, j = k - 1; j + k - 1 <= m - 1; ++j)
        for (int l = 0; l < k; ++l)
            id2[i][j] += a[i - l][j + k - 1 - l];
    for (int i = k, j = k - 1; i + k - 1 <= n - 1; ++i)
        for (int l = 0; l < k; ++l)
            id2[i][j] += a[i - l][j + k - 1 - l];
    for (int i = k; i + k - 1 <= n - 1; ++i)
        for (int j = k; j + k - 1 <= m - 1; ++j)
            id2[i][j] = id2[i - 1][j - 1] - a[i - 1 - k + 1][j - 1] + a[i][j + k - 1];

    vector< vector<ll> > kolumna(n, vector<ll>(m, 0));
    for (int i = k - 1, j = k - 1; j + k - 1 <= m - 1; ++j)
        for (int l = 0; l < k; ++l)
            kolumna[i][j] += a[i - l][j];
    for (int i = k; i + k - 1 <= n - 1; ++i)
        for (int j = k - 1; j + k - 1 <= m - 1; ++j)
            kolumna[i][j] = kolumna[i - 1][j] - a[i - 1 - k + 1][j] + a[i][j];

    vector< vector<ll> > id0(n, vector<ll>(m, 0));
    for (int i = k - 1, j = k - 1; j + k - 1 <= m - 1; ++j)
        for (int l = 0; l < k; ++l)
            id0[i][j] += a[i - l][j] * (k - l);
    for (int i = k; i + k - 1 <= n - 1; ++i)
        for (int j = k - 1; j + k - 1 <= m - 1; ++j)
            id0[i][j] = id0[i - 1][j] - kolumna[i - 1][j] + a[i][j] * k;

    vector< vector<ll> > id3(n, vector<ll>(m, 0));
    for (int i = k - 1, j = m - k; i + k - 1 <= n - 1; ++i)
        for (int l = i, il = k; il >= 1; --l, --il)
            for (int o = 0; o < il; ++o)
                id3[i][j] += a[l][j + o];
    for (int i = k - 1; i + k - 1 <= n - 1; ++i)
        for (int j = m - k - 1; j >= k - 1; --j)
            id3[i][j] = id3[i][j + 1] - id2[i][j + 1] + kolumna[i][j];

    vector< vector<ll> > id4(n, vector<ll>(m, 0));
    for (int i = k - 1, j = m - k; i + k - 1 <= n - 1; ++i)
        for (int l = i, il = k; il >= 1; --l, --il)
            for (int o = 0; o < il; ++o)
                id4[i][j] += a[l][j + o] * (il - o);
    for (int i = k - 1; i + k - 1 <= n - 1; ++i)
        for (int j = m - k - 1; j >= k - 1; --j)
            id4[i][j] = id4[i][j + 1] - id3[i][j + 1] + id0[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (j + 1 < m)
                f[i][j] += id4[i][j + 1];
}

void Trzy(vector< vector<ll> >& a, vector< vector<ll> >& f)
{
    vector< vector<ll> > id2(n, vector<ll>(m, 0));
    for (int i = n - k, j = k - 1; j + k - 1 <= m - 1; ++j)
        for (int l = 0; l < k; ++l)
            id2[i][j] += a[i + l][j - k + 1 + l];
    for (int i = k - 1, j = m - k; i + k - 1 <= n - 2; ++i)
        for (int l = 0; l < k; ++l)
            id2[i][j] += a[i + l][j - k + 1 + l];
    for (int i = n - k - 1; i >= k - 1; --i)
        for (int j = k - 1; j <= m - k - 1; ++j)
            id2[i][j] = id2[i + 1][j + 1] - a[i + 1 + k - 1][j + 1] + a[i][j - k + 1];

    vector< vector<ll> > kolumna(n, vector<ll>(m, 0));
    for (int i = n - k, j = k - 1; j + k - 1 <= m - 1; ++j)
        for (int l = 0; l < k; ++l)
            kolumna[i][j] += a[i + l][j];
    for (int i = n - k - 1; i >= k - 1; --i)
        for (int j = k - 1; j + k - 1 <= m - 1; ++j)
            kolumna[i][j] = kolumna[i + 1][j] - a[i + 1 + k - 1][j] + a[i][j];

    vector< vector<ll> > id0(n, vector<ll>(m, 0));
    for (int i = n - k, j = k - 1; j + k - 1 <= m - 1; ++j)
        for (int l = 0; l < k; ++l)
            id0[i][j] += a[i + l][j] * (k - l);
    for (int i = n - k - 1; i >= k - 1; --i)
        for (int j = k - 1; j + k - 1 <= m - 1; ++j)
            id0[i][j] = id0[i + 1][j] - kolumna[i + 1][j] + a[i][j] * k;

    vector< vector<ll> > id3(n, vector<ll>(m, 0));
    for (int i = k - 1, j = k - 1; i <= n - k; ++i)
        for (int l = i, il = k; il >= 1; ++l, --il)
            for (int o = 0; o < il; ++o)
                id3[i][j] += a[l][j - o];
    for (int i = k - 1; i <= n - k; ++i)
        for (int j = k; j <= m - k; ++j)
            id3[i][j] = id3[i][j - 1] - id2[i][j - 1] + kolumna[i][j];

    vector< vector<ll> > id4(n, vector<ll>(m, 0));
    for (int i = k - 1, j = k - 1; i <= n - k; ++i)
        for (int l = i, il = k; il >= 1; ++l, --il)
            for (int o = 0; o < il; ++o)
                id4[i][j] += a[l][j - o] * (il - o);
    for (int i = k - 1; i <= n - k; ++i)
        for (int j = k; j <= m - k; ++j)
            id4[i][j] = id4[i][j - 1] - id3[i][j - 1] + id0[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (i + 1 < n)
                f[i][j] += id4[i + 1][j];
}

void id1(vector< vector<ll> >& a, vector< vector<ll> >& f)
{
    vector< vector<ll> > id2(n, vector<ll>(m, 0));
    for (int i = n - k, j = k - 1; j + k - 1 <= m - 1; ++j)
        for (int l = 0; l < k; ++l)
            id2[i][j] += a[i + l][j + k - 1 - l];
    for (int i = k - 1, j = k - 1; i + k - 1 <= n - 2; ++i)
        for (int l = 0; l < k; ++l)
            id2[i][j] += a[i + l][j + k - 1 - l];
    for (int i = n - k - 1; i >= k - 1; --i)
        for (int j = k; j <= m - k; ++j)
            id2[i][j] = id2[i + 1][j - 1] - a[i + 1 + k - 1][j - 1] + a[i][j + k - 1];

    vector< vector<ll> > kolumna(n, vector<ll>(m, 0));
    for (int i = n - k, j = k - 1; j + k - 1 <= m - 1; ++j)
        for (int l = 0; l < k; ++l)
            kolumna[i][j] += a[i + l][j];
    for (int i = n - k - 1; i >= k - 1; --i)
        for (int j = k - 1; j + k - 1 <= m - 1; ++j)
            kolumna[i][j] = kolumna[i + 1][j] - a[i + 1 + k - 1][j] + a[i][j];

    vector< vector<ll> > id0(n, vector<ll>(m, 0));
    for (int i = n - k, j = k - 1; j + k - 1 <= m - 1; ++j)
        for (int l = 0; l < k; ++l)
            id0[i][j] += a[i + l][j] * (k - l);
    for (int i = n - k - 1; i >= k - 1; --i)
        for (int j = k - 1; j + k - 1 <= m - 1; ++j)
            id0[i][j] = id0[i + 1][j] - kolumna[i + 1][j] + a[i][j] * k;

    vector< vector<ll> > id3(n, vector<ll>(m, 0));
    for (int i = k - 1, j = m - k; i <= n - k; ++i)
        for (int l = i, il = k; il >= 1; ++l, --il)
            for (int o = 0; o < il; ++o)
                id3[i][j] += a[l][j + o];
    for (int i = k - 1; i <= n - k; ++i)
        for (int j = m - k - 1; j >= k - 1; --j)
            id3[i][j] = id3[i][j + 1] - id2[i][j + 1] + kolumna[i][j];

    vector< vector<ll> > id4(n, vector<ll>(m, 0));
    for (int i = k - 1, j = m - k; i <= n - k; ++i)
        for (int l = i, il = k; il >= 1; ++l, --il)
            for (int o = 0; o < il; ++o)
                id4[i][j] += a[l][j + o] * (il - o);
    for (int i = k - 1; i <= n - k; ++i)
        for (int j = m - k - 1; j >= k - 1; --j)
            id4[i][j] = id4[i][j + 1] - id3[i][j + 1] + id0[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (i + 1 < n && j + 1 < m)
                f[i][j] += id4[i + 1][j + 1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    vector< vector<ll> > a(n, vector<ll>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    vector< vector<ll> > f(n, vector<ll>(m, 0));
    Jeden(a, f);
    --k;
    if (k > 0)
        Dwa(a, f);
    if (k > 0)
        Trzy(a, f);
    --k;
    if (k > 0)
        id1(a, f);
    k += 2;
    int x = -1, y = -1;
    ll odp = -1;
    for (int i = k - 1; i <= n - k; ++i)
    {
        for (int j = k - 1; j <= m - k; ++j)
        {
            if (f[i][j] > odp)
            {
                odp = f[i][j];
                x = i;
                y = j;
            }
        }
    }
    cout << x + 1 << " " << y + 1;
    return 0;
}

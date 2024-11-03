

using namespace std;

const int maxN = 1e5 + 10;

int k, n, pre[maxN], suf[maxN], cnt[maxN];

long long P[maxN], Hash[maxN];

string s;

long long get_hash(int l, int r)
{
    return Hash[r] - Hash[l - 1] * P[r - l + 1];
}

int find_prefix(int u, int v)
{
    if (u == 0)
        return 0;
    int mx = min(n - u, n - v);
    int low = 0;
    int hig = mx;
    int mid;
    while (low <= hig)
    {
        int mid = (low + hig) / 2;
        if (get_hash(u, u + mid) == get_hash(v, v + mid))
            low = mid + 1;
        else
            hig = mid - 1;
    }
    return low;
}

void DFS(int u, int pr)
{
    if (--k == 0)
    {
        for (int i = 0; i < pr; i++)
            cout << s[suf[u]+i];
        exit(0);
    }
    cnt[u] = pr;
    if (pre[u + 1] >= pr)
        DFS(u + 1, pr);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> k;
    n = s.size();
    s = " " + s;
    P[0] = 1;
    for (int i=1; i<=n; ++i)
    {
        P[i] = P[i - 1] * 31;
        Hash[i] = Hash[i - 1] * 31 + s[i] - 'a' + 1;
        suf[i] = i;
    }
    sort(suf + 1, suf + n + 1, [](int u, int v)
    {
        int mx = min(n - u, n - v);
        int low = 0;
        int hig = mx;
        int mid;
        while (low <= hig)
        {
            mid = (low + hig) / 2;
            if (get_hash(u, u + mid) == get_hash(v, v + mid))
                low = mid + 1;
            else
                hig = mid - 1;
        }
        if (low > mx)
            return u > v;
        else
            return s[u + low] < s[v + low];
    });

    for (int i=1; i<=n; ++i)
        pre[i] = find_prefix(suf[i - 1], suf[i]);

    for (int i=1; i<=n; ++i)
        for (++cnt[i]; cnt[i]<=n - suf[i] + 1; ++cnt[i])
            DFS(i, cnt[i]);

    cout << "No such line.";
}



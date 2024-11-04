

using namespace std;

const int maxN = 1e5 + 10;
const int mod = 1e9 + 7;

int n;

long long p2[maxN], cnt[maxN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fill_n(cnt, maxN, 0);
    for (int i=1; i<=n; ++i)
    {
        int a;
        cin >> a;
        ++cnt[a];
    }
    p2[0] = 1;
    for (int i=1; i<=1e5; ++i)
        p2[i] = (p2[i-1] * 2) % mod;
    for (int i=1; i<=1e5; ++i)
        for (int j=i*2; j<=1e5; j+=i)
            cnt[i] += cnt[j];
    for(int i=1; i<=1e5; ++i)
        cnt[i] = p2[cnt[i]] - 1;
    for(int i=1e5; i>=1; --i)
        for(int j=i*2; j<=1e5; j+=i)
            cnt[i] -= cnt[j];
    cout << (cnt[1] % mod + mod) % mod;
}



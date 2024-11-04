




using namespace std;



typedef long long ll;
typedef long double lld;






ll mod = 1e9 + 7;












ll expo(ll a, ll b) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a); a = (a * a); b = b >> 1;} return res;}












vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}



































































template <typename T>
void print(T t)
{
    for (const auto &e : t)
    {
        cout << e << " ";
    }
    cout << nline;
}

template <typename T>
void input(T &t)
{
    for (auto &e : t)
    {
        cin >> e;
    }
}

bool id3(ll n)
{
    return n && !(n & (n - 1));
}

bool id0(ll n)
{
    ll y = sqrtl(n);
    return (y * y == n);
}


ll hash_value(const string s)
{
    const ll p = 31;
    const ll m = 1e9 + 9;
    ll val = 0;
    ll p_pow = 1;
    for (auto e : s)
    {
        val = (val + (e - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return p_pow;
}




vector<vector<int>> id1(vector<string> s)
{
    int n = sz(s);
    vector<pair<ll, ll>> hashes(n);
    for (int i = 0; i < n; i++)
    {
        hashes[i] = {hash_value(s[i]), i};
    }

    sort(all(hashes));

    vector<vector<int>> groups;

    for (int i = 0; i < n; i++)
    {
        if (i == 0 || hashes[i].first != hashes[i - 1].first)
        {
            hashes.emplace_back();
        }
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}

vector<int> id2(string s, string t)
{
    const ll p = 31;
    const ll m = 1e9 + 9;
    vector<ll> p_pow(max(sz(s), sz(t)));
    p_pow[0] = 1;
    for (int i = 1; i < sz(p_pow); i++)
    {
        p_pow[i] = (p_pow[i - 1] * p) % m;
    }
    vector<ll> h(sz(t) + 1, 0);
    for (int i = 0; i < sz(t); i++)
    {
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    }


    ll h_s = 0;
    for (int i = 0; i < sz(s); i++)
    {
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }
    vector<int> pos;
    for (int i = 0; i + sz(s) - 1 < sz(t); i++)
    {
        ll curr_h = (h[i + sz(s)] + m - h[i]) % m;
        if (curr_h == h_s * p_pow[i] % m)
        {
            pos.push_back(i);
        }
    }
    return pos;
}

vector<int> prefix_function(string s)
{
    int n = sz(s);
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j - 1];
        }
        if (s[i] == s[j])
        {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

vector<int> kmp(string s, string t)
{
    string res = s + '
    vector<int> pos;
    vector<int> pi = prefix_function(res);
    for (int i = 0; i < sz(res); i++)
    {
        if (pi[i] == sz(s))
        {
            pos.pb(i - 2 * sz(s));
        }
    }
    return pos;
}

vector<int> id5(string s)
{
    vector<int> pi = prefix_function(s);
    vector<int> ans(sz(s) + 1);
    int n = sz(s);

    for (int i = 0; i < n; i++)
    {
        ans[pi[i]]++;
    }
    for (int i = n - 1; i > 0; i--)
    {
        ans[pi[i - 1]] += ans[i];
    }
    for (int i = 0; i <= n; i++)
    {
        ans[i]++;
    }
    return ans;
}













































vector<int> zfunc(string s) 

{
    int n = s.length();
    vector<int> z(n);
    for (int i = 1; i < n; i++)
    {
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            ++z[i];
        }
    }
    return z;
}


void id4(string s, vector<int> &d1, vector<int> &d2)
{
    int n = s.length();


    for (int i = 0, l = 0, r = -1; i < n; i++)
    {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
        {
            k++;
        }
        d1[i] = k--;
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }
    }

    for (int i = 0, l = 0, r = -1; i < n; i++)
    {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);

        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k])
        {
            k++;
        }
        d2[i] = k--;
        if (i + k > r)
        {
            l = i - k - 1;
            r = i + k;
        }
    }
    print(d1);
    print(d2);
}

bool check(int a, int b)
{
    int x = __gcd(a, b);
    a /= x;
    b /= x;

    while (b % 2 == 0)
    {
        b /= 2;
    }
    while (b % 5 == 0)
    {
        b /= 5;
    }
    if (b == 1)
    {
        return true;
    }
    return false;

}

void solve()
{
    int n;
    cin >> n;
    vector<double> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n <= 2)
    {
        cout << "0\n"; return;
    }

    int ans = n - 1;




    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double d;
            double x = (a[j] - a[i]);

            d = x / (j - i);
            int cnt = 0;
            x = a[i] - i * d;
            for (int k = 0; k < n; k++)
            {
                if (k != i && k != j && a[k] != a[i] + (k - i) * d)
                {
                    cnt++;
                }
            }
            ans = min(ans, cnt);
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);


    

    


    ll t = 1;
    cin >> t;


    while (t--) {
        solve();
    }


    return 0;

}








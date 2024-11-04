
 
using namespace std;
 




















 




mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
 


 






















































 




 




 




 








 
 












































 
 
 
































































 














































 
























 




 




























 




 


























 














 






 








 
























 




 




























 




 


























 














 






 






























































































 


 


























 
 










 


 










 
 
















 












 


 


 




 
 


 




 
const int N = 1e3 + 5;
ll  fact[N];
ll  inv[N];
ll  binpow(ll  a, ll  b, ll  m) {
    ll  ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans *= a;
            ans %= m;
        }
        a *= a;
        a %= m;
        b /= 2;
    }
    return (ans + m) % m;
}
void precalc(ll  p) {
    fact[0] = 1;
    for (ll  i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
    for (ll  i = 0; i < N; i++) {
        inv[i] = binpow(fact[i], p - 2, p);
    }
}
ll  id0(ll  n, ll  r, ll  p) {
    return (((fact[n] * inv[n - r]) % p) * inv[r]) % p;
}
ll fun(ll a1, ll a2)
{
    ll ans = fact[a1];
    for (ll i = 1; i <= a2; i++)
    {
        ll val1 = (id0(a2, i, mod) * (fact[a1 - i]) % mod) % mod;
        if (i % 2)
            ans = (ans - val1 + mod) % mod;
        else
            ans = (ans + val1) % mod;
    }
    return (ans);
}
bool check(ll k1, ll a1, vector<ll>v1)
{
    ll n = v1.size();
    ll sum = 0;
    vector<ll>ans;
    for (ll i = 0; i < n; i++)
    {
        if ((sum + v1[i]) <= (k1))
        {
            sum += v1[i];
        }
        else
        {
            ans.push_back(sum);
            sum = v1[i];
        }
    }
    ans.push_back(sum);
    bool ask1 = true;
    for (ll i = 0; i < ans.size(); i++)
    {
        if (ans[i] == k1)
            continue;
        else
        {
            ask1 = false;
            break;
        }
    }
    if (ask1 == true && (ans.size() == a1))
    {
        return (true);
    }
    return (false);
}
int main()
{

    freopen("i4.txt", "r", stdin);
    freopen("aw2.txt", "w", stdout);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll>v1(n);
        for (ll i = 0; i < n; i++)
            cin >> v1[i];
        priority_queue<pair<ll, ll>>q1, q2;
 
        string s1;
 
        cin >> s1;
        for (ll i = 0; i < s1.size(); i++)
        {
            if (s1[i] == '1')
            {
                q1.push({v1[i], i});
            }
            else
            {
                q2.push({v1[i], i});
            }
        }
        ll ct = 0;
        vector<ll>ans(n, 0);
 
        for (ll i = 0; i < s1.size(); i++)
        {
            if (s1[i] == '1')
            {
                ct++;
            }
        }
        ll j1 = n;
        while (q1.size() > 0)
        {
            auto i1 = q1.top();
            q1.pop();
            ans[i1.second] = j1;
            j1--;
        }
        while (q2.size() > 0)
        {
            auto i1 = q2.top();
            q2.pop();
            ans[i1.second] = j1;
            j1--;
        }
        for (ll i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
 
 
 
    }
 
 
}
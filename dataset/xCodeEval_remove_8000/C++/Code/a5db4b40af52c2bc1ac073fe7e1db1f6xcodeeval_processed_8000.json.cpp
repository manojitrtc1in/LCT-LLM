






























































































































using namespace std;
int modulo = 1e9 + 7;
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
bool sorta(const pii& a, const pii& b) { return (a.second < b.second); }
bool sortd(const pii& a, const pii& b) { return (a.second > b.second); }
string id9(int n) {
    string s = "";
    int i = 0;
    while (n > 0) {
        s = to_string(n % 2) + s;
        n = n / 2;
        i++;
    }
    return s;
}
ll id3(string n) {
    string num = n;
    ll dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1') dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}
bool id1(int n) {
    if (n == 0) return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool id5(ll x) {
    if (x >= 0) {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
long long id6(long long a, long long b, long long mod)
{
    long long res = 0;
    a %= mod;

    while (b)
    {

        if (b & 1)
            res = (res + a) % mod;

        a = (2 * a) % mod;

        b >>= 1; 

    }

    return res;
}
ll id2(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}


ll id0(ll x)
{
    ll left = 0, right = 2000000123;
    while (right > left)
    {
        ll mid = (left + right) / 2;

        if (mid * mid > x)
            right = mid;
        else
            left = mid + 1;
    }
    return left - 1;
}



ll id7(ll n, ll mod)
{
    return id2(n, mod - 2, mod);
}

ll nCr(ll n, ll r, ll p)
{
    

    if (n < r)
        return 0;
    

    if (r == 0)
        return 1;

    

    

    

    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * id7(fac[r], p) % p * id7(fac[n - r], p) % p) % p;
}

void ps(int l, int r, map<int, int>& id8, map<int, int>& id10) {
    int ans=0;

    for (auto& itr : id8) {

        int x = min(itr.second, id10[itr.first]);

        itr.second -= x;
        id10[itr.first] -= x;
        l -= x;
        r -= x;
        


    }

    for (auto& itr : id10) {
        int x = min(itr.second, id8[itr.first]);

        itr.second -= x;
        id8[itr.first] -= x;
        l -= x;
        r -= x;
        


    }

    

    

    

    

    

    

    

    

    

    

    

    


    if(l>r){
        swap(l,r);
        swap(id8,id10);

    }

    int diff=(r-l)/2;

    for(auto &itr:id10){
        int x=min(diff,itr.second/2);
        ans+= x;
        r-=2*x;
        diff-=x;
    }

    ans+= max(l,r);

    cout<<ans<<endl;




}

int main() {
    Meyank Garg id4;
    ll t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;

        map<int, int>id8, id10;
        for (int i = 0;i < l;i++) {
            int x;
            cin >> x;
            id8[x]++;
        }

        for (int i = 0;i < r;i++) {
            int x;
            cin >> x;
            id10[x]++;
        }

        ps(l,r,id8,id10);


    }
    return 0;
}
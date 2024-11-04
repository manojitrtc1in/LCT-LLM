



using namespace std;




















































typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef unordered_map<ll, ll> umll;
typedef map<ll, ll> mll;
typedef pair<string, string> pairs;
typedef pair<ll, ll> pii;

template<typename T1, typename T2>


istream &operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }

template<typename T>


istream &operator>>(istream &istream, vector<T> &v) {
    for (auto &it: v)cin >> it;
    return istream;
}

template<typename T1, typename T2>


ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }

template<typename T>


ostream &operator<<(ostream &ostream, const vector<T> &c) {
    for (auto &it: c) cout << it << " ";
    return ostream;
}


ll gcd(ll a, ll b) {
    if (a == 0)
        return b;
    gcd(b % a, a);
    return 0;
}


ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}





int dirx[] = {-1, 0, 1, 0};
int diry[] = {0, 1, 0, -1};
vector<int> dx = {1, 1, -1, -1};
vector<int> dy = {1, -1, 1, -1};


using namespace std;

bool isPrime(ll n) {
    if (n == 2) {
        return true;
    }
    if (n < 2 || n % 2 == 0) {
        return false;
    }
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}



vector<bool> primes((1e6 + 1), true);

void sieven(int n) {
    primes[0] = primes[1] = false;
    for (ll i = 2; i <= n + 1; i++) {
        if (primes[i]) {
            for (ll j = i * i; j <= n + 1; j += i)
                primes[j] = false;
        }
    }
}

int mod = 1e9 + 7;



long long fastPower(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}



long long fastPower(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}



bool id0(int n) {
    return (ceil(log2(n)) == floor(log2(n)));
}



vector<tuple<int, int, int>> edges;


vector<vector<int>> adj;
vector<bool> visited;
vector<int> topsort;
vector<int> start, finish;
bool anyCycle = 0;
int timer = 0;











































void id1(int n) {
    vi v;
    for (int j = 1; j * j <= n; j++) {
        if (n % j == 0) {
            if (j % 2)
                v.pb(j);
            if (j != (n / j))
                if ((n / j) % 2)
                    v.pb(n / j);
        }
    }
}


void solve() {
    ll n;
    cin >> n;
    vl v(n), v2;
    ll sum = 0;
    fr(i, 0, n) {
        cin >> v[i];
        sum += v[i];
    }
    if (sum % n != 0) {
        pm
        return;
    }
    ll diff = (sum / n);
    int c = 0;
    ll target = diff;
    fr(i,0,n){
       if (v[i] > diff ){
           c++;
       }
    }
    cout<<c<<endl;


}

int main() {
    fast
    tc solve();
    return 0;
}

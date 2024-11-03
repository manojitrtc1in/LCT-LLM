

#include<bits/stdc++.h>

using namespace std;
#define endl               "\n"
#define fast               ios::sync_with_stdio(0);cin.tie(0);
#define ll                 long long
#define pb                 push_back
#define ifc(b, s1, otherwise) (b)? cout<<s1<<endl : cout<<otherwise<<endl
#define fs(n)              fixed<<setprecision(n)
#define asort(a)           sort(a,a+n)
#define vi                 vector<int>
#define qu                 queue<int>
#define de                deque<int>
#define pqi                priority_queue<int>
#define pql                priority_queue<long long>
#define dl                 deque<long long>
#define ql                 queue<long long>
#define vl                 vector<long long>
#define vc                 vector<char>
#define inf                0x3f3f3f3f
#define allr(x)             (x).rbegin(), (x).rend()
#define all(x)             (x).begin(), (x).end()
#define dsort(a)           sort(a,a+n,greater<int>())
#define sz(x) (int)(x).size()


#define range(i, n) for (int i = 0; i < (n); ++i)
#define F first
#define S second
#define tc int t; cin>>t; while(t--)


#define fl(i, n) for(int i=0;i<n;i++)
#define rl(i, m, n) for(int i=n;i>=m;i--)
#define py cout<<"YES\n";
#define pm cout<<"-1\n";
#define pn cout<<"NO\n";
#define po cout<<"0\n";
#define vr(v) v.begin(),v.end()
#define rv(v) v.end(),v.begin()
#define sz(v)            ((int)((v).size()))
#define rep(i, x, n) for(int i=x;i<n;i++)
#define  rep1(i, m, n) for(int i=m;i<=n;i++)
#define CC(x) cout << (x) << endl
#define fr(i, x, y) for (ll i = (ll)x; i < (ll)y; ++i)
#define fr1(i, x, y) for (ll i = (ll)x; i <= (ll)y; ++i)
#define fra(x)      for (auto &i : x)
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

int dx[] = {-1, 0, 0, 1, -1, -1, 1, 1}; 

int dy[] = {0, 1, -1, 0, -1, 1, 1, -1}; 

int dirx[] = {-1, 0, 1, 0};
int diry[] = {0, 1, 0, -1};


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

void lb(vector<int> v, int low, int high, int x) {
    int s = low;
    int e = high - 1;
    while (s <= e) {
        int m = s + (e - s) / 2;
        if (v[m] < x) {
            s = m + 1;
        } else {
            e = m - 1;
        }
    }
    if (s < high) {
        cout << s << " " << v[s] << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }
}

int up(vector<int> &v, int l, int h, int element) {
    int ans = -1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (v[mid] <= element) {
            l = mid + 1;
            ans = l;
        } else {
            h = mid - 1;
        }
    }
    return ans;
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

bool isPowerOfTwo(int n) {
    return (ceil(log2(n)) == floor(log2(n)));
}


void solve() {
    int n, m;
    cin >> n >> m;
    char v[n][m];
    for (int i=0;i<n;i++){
        for (int j= 0;j<m;j++){
            cin>>v[i][j];
        }
    }

    int res = INT_MAX;
    int ans = 0;
    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {
            for (int k = 0; k < m; k++) {
                ans += abs(v[i][k] - v[j][k]);
            }
            res = min(ans, res);
             ans = 0;
        }
    }
    cout << res << endl;
}



int main() {
    fast
    tc solve();
    return 0;
}

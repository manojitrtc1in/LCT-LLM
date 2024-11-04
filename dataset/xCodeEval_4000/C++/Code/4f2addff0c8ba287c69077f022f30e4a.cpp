

#include<bits/stdc++.h>


using namespace std;
#define endl               "\n"
#define fast               ios::sync_with_stdio(0);cin.tie(0);
#define ll                 long long
#define fr(i, n)           for (ll i=0;i<n;i++)
#define fr1(i, n)          for(ll i=1;i<=n;i++)
#define TW                  TC int t; cin >> t;   while(t--)
#define pb                 push_back
#define fs(n)              fixed<<setprecision(n)
#define asort(a)           sort(a,a+n)
#define vi                 vector<int>
#define qi                 queue<int>
#define di                 deque<int>
#define pqi                priority_queue<int>
#define pql                priority_queue<long long>
#define dl                 deque<long long>
#define ql                 queue<long long>
#define vl                 vector<long long>
#define vc                 vector<char>
#define allr(x)             (x).rbegin(), (x).rend()
#define all(x)             (x).begin(), (x).end()
#define dsort(a)           sort(a,a+n,greater<int>())
#define sz(x) (int)(x).size()


#define range(i, n) for (int i = 0; i < (n); ++i)
#define F first
#define S second
#define tc int t; cin>>t; while(t--)
#define pb push_back
#define mp make_pair
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
typedef pair<ll, ll> pll;
typedef vector<string> vs;
typedef unordered_map<ll, ll> umll;
typedef map<ll, ll> mll;
typedef pair<string, string> pairs;
typedef pair<ll, ll> pii;


ll gcd(ll a, ll b) {
    if (a == 0)
        return b;
    gcd(b % a, a);
}


ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

int dx[] = {-1, 0, 0, 1, -1, -1, 1, 1}; 

int dy[] = {0, 1, -1, 0, -1, 1, 1, -1}; 

int dirx[] = {-1, 0, 1, 0};
int diry[] = {0, 1, 0, -1};


using namespace std;


void reverse(int arr[], int l, int r) {
    while (r > l) {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

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




void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int c = 0 , ans = 1;
    for (int i=0;i<n;i++){ 

        if (s[i]=='*'){
            c = i;
            s[i]='x';
            break;
        }
    }
    while (c < n) {
        int j = min(n-1,c+k);
        bool found  = false;
        for (; j > c;j--){
            if (s[j]=='*'){
                s[j]='x';
                found = true;
                ans++;
                c=j;
                break;
            }
        }
        if (!found){break;}
    }
    cout<<ans<<endl;
}

int main() {
    tc {
        solve();
    }
    return 0;
}



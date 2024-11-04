
 










using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<ll, int> PLI;
typedef vector<int> VI;
typedef double db;

template<class T1, class T2> bool umin(T1& a, T2 b) { return a > b ? (a = b, true) : false; }
template<class T1, class T2> bool umax(T1& a, T2 b) { return a < b ? (a = b, true) : false; }
template<class T> void clear(T& a) { T().swap(a); }

const int N = 2e5 + 5;

int n, m, _, k;
ll a[N], b[N];

int main() {
    IOS;
    for (cin >> _; _; --_) {
        ll a, b; cin >> a >> b;
        if (a * 2 > b) cout << "YES\n";
        else cout << "NO\n";
    } 
    return 0;
}
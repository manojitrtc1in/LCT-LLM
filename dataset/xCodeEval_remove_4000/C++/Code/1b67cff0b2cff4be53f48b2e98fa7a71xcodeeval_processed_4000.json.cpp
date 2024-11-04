











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
ll a[N], h[N];

int main() {
    IOS; a[1] = 1; 
    for (cin >> _; _; --_) {
        cin >> n >> m;
        rep (i, 2, n) {
            cin >> a[i];
            if (a[i] < a[i - 1]) ++m;
            h[i] = h[m] + 1;
        }
        cout << h[n] << '\n';
    }
    return 0;
}
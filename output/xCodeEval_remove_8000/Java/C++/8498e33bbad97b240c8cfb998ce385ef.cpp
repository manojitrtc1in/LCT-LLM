#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <cassert>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iterator>
#include <functional>
#include <numeric>
#include <complex>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define forn(i, a, b) for (int i = (a); i <= (b); ++i)
#define ford(i, a, b) for (int i = (a); i >= (b); --i)
#define fore(i, a) for (auto &i : (a))
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define for0(i, n) for (int i = 0; i < (n); ++i)
#define trace(x) cerr << #x << ": " << x << endl
#define bitcount(x) __builtin_popcountll(x)
#define fi first
#define se second
#define endl '\n'

const double eps = 1e-9;
const double pi = acos(-1);
const ll mod = 1e9 + 7;
const int N = 1e6 + 5;

template<typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char dir[] = {'D', 'U', 'R', 'L'};

class D {
public:
    void solve(istream& cin, ostream& cout) {
        int n;
        cin >> n;

        int id13 = min(n, 30);
        set<ll> prev;
        prev.insert(0);
        for (int i = 0; i < id13; i++) {
            set<ll> next;
            for (ll v : prev) {
                next.insert(v + 1);
                next.insert(v + 5);
                next.insert(v + 10);
                next.insert(v + 50);
            }
            prev = next;
        }

        if (n > id13) {
            int diff = n - id13;
            cout << prev.size() + diff * 49LL << endl;
        } else {
            cout << prev.size() << endl;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    D solver;
    solver.solve(cin, cout);
    return 0;
}

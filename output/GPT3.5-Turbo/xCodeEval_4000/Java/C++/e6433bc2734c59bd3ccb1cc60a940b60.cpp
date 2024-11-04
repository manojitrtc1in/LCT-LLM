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
#include <ctime>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <complex>
#include <iterator>
#include <functional>
#include <numeric>
#include <climits>
using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define REPD(i, a, b) for (int i = int(a); i >= int(b); i--)
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOREACH(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define iter(c) __typeof((c).begin())
#define tr(c, it) for (iter(c) it = (c).begin(); it != (c).end(); it++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAXN 1000005
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI acos(-1.0)
#define DEBUG(x) cout << #x << " = " << x << endl;
#define PR(a, n) REP(i, 1, n) cout << a[i] << " "; cout << endl;
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define PDD pair<double, double>
#define VPII vector<PII >
#define VPLL vector<PLL >
#define VPDD vector<PDD >
#define VI vector<int>
#define VLL vector<LL>
#define VD vector<double>
#define VVI vector<vector<int> >
#define VVLL vector<vector<LL> >
#define VVD vector<vector<double> >
#define VVPII vector<vector<PII > >
#define VVPLL vector<vector<PLL > >
#define VVPDD vector<vector<PDD > >
#define VVB vector<vector<bool> >
#define VVS vector<vector<string> >
#define VVD vector<vector<double> >
#define VVVI vector<vector<vector<int> > >
#define VVVLL vector<vector<vector<LL> > >
#define VVVD vector<vector<vector<double> > >
#define VVVB vector<vector<vector<bool> > >
#define VVVS vector<vector<vector<string> > >

#define LSOne(S) (S & (-S))

typedef complex<double> point;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<viii> vviii;
typedef vector<vvii> vvvii;
typedef vector<vviii> vvviii;

template<class T> inline T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }
template<class T> inline T lcm(T a, T b) { return a * (b / gcd(a, b)); }
template<class T> inline string toString(T x) { stringstream s; s << x; return s.str(); }
template<class T> inline int toInt(T x) { stringstream s; s << x; int r; s >> r; return r; }
template<class T> inline double toDouble(T x) { stringstream s; s << x; double r; s >> r; return r; }
template<class T> inline void toVector(T x, vector<int> &r) { stringstream s; s << x; int k; while (s >> k) r.push_back(k); }
template<class T> inline void toVector(T x, vector<long long> &r) { stringstream s; s << x; long long k; while (s >> k) r.push_back(k); }
template<class T> inline void toVector(T x, vector<double> &r) { stringstream s; s << x; double k; while (s >> k) r.push_back(k); }
template<class T> inline void toVector(T x, vector<string> &r) { stringstream s; s << x; string k; while (s >> k) r.push_back(k); }
template<class T> inline void toVector(T x, vector<char> &r) { stringstream s; s << x; char k; while (s >> k) r.push_back(k); }
template<class T> inline void toVector(T x, vector<bool> &r) { stringstream s; s << x; bool k; while (s >> k) r.push_back(k); }
template<class T> inline void toVector(T x, vector<vector<int> > &r) { stringstream s; s << x; string k; while (getline(s, k, ',')) { vector<int> v; toVector(k, v); r.push_back(v); } }
template<class T> inline void toVector(T x, vector<vector<long long> > &r) { stringstream s; s << x; string k; while (getline(s, k, ',')) { vector<long long> v; toVector(k, v); r.push_back(v); } }
template<class T> inline void toVector(T x, vector<vector<double> > &r) { stringstream s; s << x; string k; while (getline(s, k, ',')) { vector<double> v; toVector(k, v); r.push_back(v); } }
template<class T> inline void toVector(T x, vector<vector<string> > &r) { stringstream s; s << x; string k; while (getline(s, k, ',')) { vector<string> v; toVector(k, v); r.push_back(v); } }
template<class T> inline void toVector(T x, vector<vector<char> > &r) { stringstream s; s << x; string k; while (getline(s, k, ',')) { vector<char> v; toVector(k, v); r.push_back(v); } }
template<class T> inline void toVector(T x, vector<vector<bool> > &r) { stringstream s; s << x; string k; while (getline(s, k, ',')) { vector<bool> v; toVector(k, v); r.push_back(v); } }
template<class T> inline void toVector(T x, vector<vector<vector<int> > > &r) { stringstream s; s << x; string k; while (getline(s, k, '|')) { vector<vector<int> > v; toVector(k, v); r.push_back(v); } }
template<class T> inline void toVector(T x, vector<vector<vector<long long> > > &r) { stringstream s; s << x; string k; while (getline(s, k, '|')) { vector<vector<long long> > v; toVector(k, v); r.push_back(v); } }
template<class T> inline void toVector(T x, vector<vector<vector<double> > > &r) { stringstream s; s << x; string k; while (getline(s, k, '|')) { vector<vector<double> > v; toVector(k, v); r.push_back(v); } }
template<class T> inline void toVector(T x, vector<vector<vector<string> > > &r) { stringstream s; s << x; string k; while (getline(s, k, '|')) { vector<vector<string> > v; toVector(k, v); r.push_back(v); } }
template<class T> inline void toVector(T x, vector<vector<vector<char> > > &r) { stringstream s; s << x; string k; while (getline(s, k, '|')) { vector<vector<char> > v; toVector(k, v); r.push_back(v); } }
template<class T> inline void toVector(T x, vector<vector<vector<bool> > > &r) { stringstream s; s << x; string k; while (getline(s, k, '|')) { vector<vector<bool> > v; toVector(k, v); r.push_back(v); } }
template<class T> inline void toVector(T x, vector<vector<vector<vector<int> > > > &r) { stringstream s; s << x; string k; while (getline(s, k, '^')) { vector<vector<vector<int> > > v; toVector(k, v); r.push_back(v); } }
template<class T> inline void toVector(T x, vector<vector<vector<vector<long long> > > > &r) { stringstream s; s << x; string k; while (getline(s, k, '^')) { vector<vector<vector<long long> > > v; toVector(k, v); r.push_back(v); } }
template<class T> inline void toVector(T x, vector<vector<vector<vector<double> > > > &r) { stringstream s; s << x; string k; while (getline(s, k, '^')) { vector<vector<vector<double> > > v; toVector(k, v); r.push_back(v); } }
template<class T> inline void toVector(T x, vector<vector<vector<vector<string> > > > &r) { stringstream s; s << x; string k; while (getline(s, k, '^')) { vector<vector<vector<string> > > v; toVector(k, v); r.push_back(v); } }
template<class T> inline void toVector(T x, vector<vector<vector<vector<char> > > > &r) { stringstream s; s << x; string k; while (getline(s, k, '^')) { vector<vector<vector<char> > > v; toVector(k, v); r.push_back(v); } }
template<class T> inline void toVector(T x, vector<vector<vector<vector<bool> > > > &r) { stringstream s; s << x; string k; while (getline(s, k, '^')) { vector<vector<vector<bool> > > v; toVector(k, v); r.push_back(v); } }

template<class T> inline void toSet(T x, set<int> &r) { stringstream s; s << x; int k; while (s >> k) r.insert(k); }
template<class T> inline void toSet(T x, set<long long> &r) { stringstream s; s << x; long long k; while (s >> k) r.insert(k); }
template<class T> inline void toSet(T x, set<double> &r) { stringstream s; s << x; double k; while (s >> k) r.insert(k); }
template<class T> inline void toSet(T x, set<string> &r) { stringstream s; s << x; string k; while (s >> k) r.insert(k); }
template<class T> inline void toSet(T x, set<char> &r) { stringstream s; s << x; char k; while (s >> k) r.insert(k); }
template<class T> inline void toSet(T x, set<bool> &r) { stringstream s; s << x; bool k; while (s >> k) r.insert(k); }
template<class T> inline void toSet(T x, set<vector<int> > &r) { stringstream s; s << x; string k; while (getline(s, k, ',')) { vector<int> v; toVector(k, v); r.insert(v); } }
template<class T> inline void toSet(T x, set<vector<long long> > &r) { stringstream s; s << x; string k; while (getline(s, k, ',')) { vector<long long> v; toVector(k, v); r.insert(v); } }
template<class T> inline void toSet(T x, set<vector<double> > &r) { stringstream s; s << x; string k; while (getline(s, k, ',')) { vector<double> v; toVector(k, v); r.insert(v); } }
template<class T> inline void toSet(T x, set<vector<string> > &r) { stringstream s; s << x; string k; while (getline(s, k, ',')) { vector<string> v; toVector(k, v); r.insert(v); } }
template<class T> inline void toSet(T x, set<vector<char> > &r) { stringstream s; s << x; string k; while (getline(s, k, ',')) { vector<char> v; toVector(k, v); r.insert(v); } }
template<class T> inline void toSet(T x, set<vector<bool> > &r) { stringstream s; s << x; string k; while (getline(s, k, ',')) { vector<bool> v; toVector(k, v); r.insert(v); } }
template<class T> inline void toSet(T x, set<vector<vector<int> > > &r) { stringstream s; s << x; string k; while (getline(s, k, '|')) { vector<vector<int> > v; toVector(k, v); r.insert(v); } }
template<class T> inline void toSet(T x, set<vector<vector<long long> > > &r) { stringstream s; s << x; string k; while (getline(s, k, '|')) { vector<vector<long long> > v; toVector(k, v); r.insert(v); } }
template<class T> inline void toSet(T x, set<vector<vector<double> > > &r) { stringstream s; s << x; string k; while (getline(s, k, '|')) { vector<vector<double> > v; toVector(k, v); r.insert(v); } }
template<class T> inline void toSet(T x, set<vector<vector<string> > > &r) { stringstream s; s << x; string k; while (getline(s, k, '|')) { vector<vector<string> > v; toVector(k, v); r.insert(v); } }
template<class T> inline void toSet(T x, set<vector<vector<char> > > &r) { stringstream s; s << x; string k; while (getline(s, k, '|')) { vector<vector<char> > v; toVector(k, v); r.insert(v); } }
template<class T> inline void toSet(T x, set<vector<vector<bool> > > &r) { stringstream s; s << x; string k; while (getline(s, k, '|')) { vector<vector<bool> > v; toVector(k, v); r.insert(v); } }
template<class T> inline void toSet(T x, set<vector<vector<vector<int> > > > &r) { stringstream s; s << x; string k; while (getline(s, k, '^')) { vector<vector<vector<int> > > v; toVector(k, v); r.insert(v); } }
template<class T> inline void toSet(T x, set<vector<vector<vector<long long> > > > &r) { stringstream s; s << x; string k; while (getline(s, k, '^')) { vector<vector<vector<long long> > > v; toVector(k, v); r.insert(v); } }
template<class T> inline void toSet(T x, set<vector<vector<vector<double> > > > &r) { stringstream s; s << x; string k; while (getline(s, k, '^')) { vector<vector<vector<double> > > v; toVector(k, v); r.insert(v); } }
template<class T> inline void toSet(T x, set<vector<vector<vector<string> > > > &r) { stringstream s; s << x; string k; while (getline(s, k, '^')) { vector<vector<vector<string> > > v; toVector(k, v); r.insert(v); } }

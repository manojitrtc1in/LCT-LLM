#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <deque>
#include <bitset>
#include <list>
#include <iomanip>
#include <fstream>
#include <functional>
#include <numeric>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) ((int)(v).size())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define rrep(i, n) for (int i = (n)-1; i >= 0; --i)
#define rrep1(i, n) for (int i = (n); i >= 1; --i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define FORALL(it, v) for (auto it = (v).begin(); it != (v).end(); ++it)
#define dbg(x) cerr << #x << " = " << x << endl
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define dbg4(x, y, z, w) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << endl
#define dbgp(x) cerr << "(" << x.fi << ", " << x.se << ")" << endl
#define dbgv(v) cerr << #v << " = "; FORALL(it, v) cerr << *it << ", "; cerr << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<vs> vvs;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<vvvvi> vvvvvi;
typedef vector<vvvvvi> vvvvvvi;
typedef vector<vvvvvvi> vvvvvvvi;
typedef vector<vvvvvvvi> vvvvvvvvi;
typedef vector<vvvvvvvvi> vvvvvvvvvi;
typedef vector<vvvvvvvvvi> vvvvvvvvvvi;
typedef vector<vvvvvvvvvvi> vvvvvvvvvvvi;
typedef vector<vvvvvvvvvvvi> vvvvvvvvvvvvi;
typedef vector<vvvvvvvvvvvvi> vvvvvvvvvvvvvi;
typedef vector<vvvvvvvvvvvvvi> vvvvvvvvvvvvvvi;
typedef vector<vvvvvvvvvvvvvvi> vvvvvvvvvvvvvvvi;
typedef vector<vvvvvvvvvvvvvvvi> vvvvvvvvvvvvvvvvi;
typedef vector<vvvvvvvvvvvvvvvvi> vvvvvvvvvvvvvvvvvi;

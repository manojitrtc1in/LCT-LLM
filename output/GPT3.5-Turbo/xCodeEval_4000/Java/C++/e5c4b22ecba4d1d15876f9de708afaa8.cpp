#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <iomanip>
#include <fstream>
#include <functional>
#include <numeric>
#include <random>
#include <sstream>
#include <tuple>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

#define endl '\n'
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);++i)
#define rep1(i, n) for(int i=1;i<=(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define per1(i, n) for(int i=(n);i>=1;--i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define ROF(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define FOR1(i, a, b) for(int i=(a);i<=(b);++i)
#define ROF1(i, a, b) for(int i=(b);i>=(a);--i)
#define eb emplace_back
#define ef emplace_front
#define et insert
#define rbe rbegin()
#define ret return
#define br break
#define psb push_back
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define y0 y1234567890
#define y1 y12345678901
#define j0 j1234567890
#define j1 j12345678901
#define tm tm1234567890
#define left left1234567890
#define right right1234567890
#define prev prev1234567890
#define next next1234567890
#define X first
#define Y second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for(int i=0;i<(n);++i)
#define rep1(i, n) for(int i=1;i<=(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define per1(i, n) for(int i=(n);i>=1;--i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define ROF(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define FOR1(i, a, b) for(int i=(a);i<=(b);++i)
#define ROF1(i, a, b) for(int i=(b);i>=(a);--i)
#define eb emplace_back
#define ef emplace_front
#define et insert
#define rbe rbegin()
#define ret return
#define br break
#define psb push_back
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define y0 y1234567890
#define y1 y12345678901
#define j0 j1234567890
#define j1 j12345678901
#define tm tm1234567890
#define left left1234567890
#define right right1234567890
#define prev prev1234567890
#define next next1234567890
#define X first
#define Y second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for(int i=0;i<(n);++i)
#define rep1(i, n) for(int i=1;i<=(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define per1(i, n) for(int i=(n);i>=1;--i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define ROF(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define FOR1(i, a, b) for(int i=(a);i<=(b);++i)
#define ROF1(i, a, b) for(int i=(b);i>=(a);--i)
#define eb emplace_back
#define ef emplace_front
#define et insert
#define rbe rbegin()
#define ret return
#define br break
#define psb push_back
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define y0 y1234567890
#define y1 y12345678901
#define j0 j1234567890
#define j1 j12345678901
#define tm tm1234567890
#define left left1234567890
#define right right1234567890
#define prev prev1234567890
#define next next1234567890
#define X first
#define Y second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for(int i=0;i<(n);++i)
#define rep1(i, n) for(int i=1;i<=(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define per1(i, n) for(int i=(n);i>=1;--i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define ROF(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define FOR1(i, a, b) for(int i=(a);i<=(b);++i)
#define ROF1(i, a, b) for(int i=(b);i>=(a);--i)
#define eb emplace_back
#define ef emplace_front
#define et insert
#define rbe rbegin()
#define ret return
#define br break
#define psb push_back
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define y0 y1234567890
#define y1 y12345678901
#define j0 j1234567890
#define j1 j12345678901
#define tm tm1234567890
#define left left1234567890
#define right right1234567890
#define prev prev1234567890
#define next next1234567890
#define X first
#define Y second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for(int i=0;i<(n);++i)
#define rep1(i, n) for(int i=1;i<=(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define per1(i, n) for(int i=(n);i>=1;--i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define ROF(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define FOR1(i, a, b) for(int i=(a);i<=(b);++i)
#define ROF1(i, a, b) for(int i=(b);i>=(a);--i)
#define eb emplace_back
#define ef emplace_front
#define et insert
#define rbe rbegin()
#define ret return
#define br break
#define psb push_back
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define y0 y1234567890
#define y1 y12345678901
#define j0 j1234567890
#define j1 j12345678901
#define tm tm1234567890
#define left left1234567890
#define right right1234567890
#define prev prev1234567890
#define next next1234567890
#define X first
#define Y second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for(int i=0;i<(n);++i)
#define rep1(i, n) for(int i=1;i<=(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define per1(i, n) for(int i=(n);i>=1;--i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define ROF(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define FOR1(i, a, b) for(int i=(a);i<=(b);++i)
#define ROF1(i, a, b) for(int i=(b);i>=(a);--i)
#define eb emplace_back
#define ef emplace_front
#define et insert
#define rbe rbegin()
#define ret return
#define br break
#define psb push_back
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define y0 y1234567890
#define y1 y12345678901
#define j0 j1234567890
#define j1 j12345678901
#define tm tm1234567890
#define left left1234567890
#define right right1234567890
#define prev prev1234567890
#define next next1234567890
#define X first
#define Y second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for(int i=0;i<(n);++i)
#define rep1(i, n) for(int i=1;i<=(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define per1(i, n) for(int i=(n);i>=1;--i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define ROF(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define FOR1(i, a, b) for(int i=(a);i<=(b);++i)
#define ROF1(i, a, b) for(int i=(b);i>=(a);--i)
#define eb emplace_back
#define ef emplace_front
#define et insert
#define rbe rbegin()
#define ret return
#define br break
#define psb push_back
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define y0 y1234567890
#define y1 y12345678901
#define j0 j1234567890
#define j1 j12345678901
#define tm tm1234567890
#define left left1234567890
#define right right1234567890
#define prev prev1234567890
#define next next1234567890
#define X first
#define Y second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for(int i=0;i<(n);++i)
#define rep1(i, n) for(int i=1;i<=(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define per1(i, n) for(int i=(n);i>=1;--i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define ROF(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define FOR1(i, a, b) for(int i=(a);i<=(b);++i)
#define ROF1(i, a, b) for(int i=(b);i>=(a);--i)
#define eb emplace_back
#define ef emplace_front
#define et insert
#define rbe rbegin()
#define ret return
#define br break
#define psb push_back
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define y0 y1234567890
#define y1 y12345678901
#define j0 j1234567890
#define j1 j12345678901
#define tm tm1234567890
#define left left1234567890
#define right right1234567890
#define prev prev1234567890
#define next next1234567890
#define X first
#define Y second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for(int i=0;i<(n);++i)
#define rep1(i, n) for(int i=1;i<=(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define per1(i, n) for(int i=(n);i>=1;--i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define ROF(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define FOR1(i, a, b) for(int i=(a);i<=(b);++i)
#define ROF1(i, a, b) for(int i=(b);i>=(a);--i)
#define eb emplace_back
#define ef emplace_front
#define et insert
#define rbe rbegin()
#define ret return
#define br break
#define psb push_back
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define y0 y1234567890
#define y1 y12345678901
#define j0 j1234567890
#define j1 j12345678901
#define tm tm1234567890
#define left left1234567890
#define right right1234567890
#define prev prev1234567890
#define next next1234567890
#define X first
#define Y second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for(int i=0;i<(n);++i)
#define rep1(i, n) for(int i=1;i<=(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define per1(i, n) for(int i=(n);i>=1;--i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define ROF(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define FOR1(i, a, b) for(int i=(a);i<=(b);++i)
#define ROF1(i, a, b) for(int i=(b);i>=(a);--i)
#define eb emplace_back
#define ef emplace_front
#define et insert
#define rbe rbegin()
#define ret return
#define br break
#define psb push_back
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define y0 y1234567890
#define y1 y12345678901
#define j0 j1234567890
#define j1 j12345678901
#define tm tm1234567890
#define left left1234567890
#define right right1234567890
#define prev prev1234567890
#define next next1234567890
#define X first
#define Y second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for(int i=0;i<(n);++i)
#define rep1(i, n) for(int i=1;i<=(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define per1(i, n) for(int i=(n);i>=1;--i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define ROF(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define FOR1(i, a, b) for(int i=(a);i<=(b);++i)
#define ROF1(i, a, b) for(int i=(b);i>=(a);--i)
#define eb emplace_back
#define ef emplace_front
#define et insert
#define rbe rbegin()
#define ret return
#define br break
#define psb push_back
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define y0 y1234567890
#define y1 y12345678901
#define j0 j1234567890
#define j1 j12345678901
#define tm tm1234567890
#define left left1234567890
#define right right1234567890
#define prev prev1234567890
#define next next1234567890
#define X first
#define Y second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for(int i=0;i<(n);++i)
#define rep1(i, n) for(int i=1;i<=(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define per1(i, n) for(int i=(n);i>=1;--i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define ROF(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define FOR1(i, a, b) for(int i=(a);i<=(b);++i)
#define ROF1(i, a, b) for(int i=(b);i>=(a);--i)
#define eb emplace_back
#define ef emplace_front
#define et insert
#define rbe rbegin()
#define ret return
#define br break
#define psb push_back
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define y0 y1234567890
#define y1 y12345678901
#define j0 j1234567890
#define j1 j12345678901
#define tm tm1234567890
#define left left1234567890
#define right right1234567890
#define prev prev1234567890
#define next next1234567890
#define X first
#define Y second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for(int i=0;i<(n);++i)
#define rep1(i, n) for(int i=1;i<=(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define per1(i, n) for(int i=(n);i>=1;--i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define ROF(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define FOR1(i, a, b) for(int i=(a);i<=(b);++i)
#define ROF1(i, a, b) for(int i=(b);i>=(a);--i)
#define eb emplace_back
#define ef emplace_front
#define et insert
#define rbe rbegin()
#define ret return
#define br break
#define psb push_back
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define y0 y1234567890
#define y1 y12345678901
#define j0 j1234567890
#define j1 j12345678901
#define tm tm1234567890
#define left left1234567890
#define right right1234567890
#define prev prev1234567890
#define next next1234567890
#define X first
#define Y second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for(int i=0;i<(n);++i)
#define rep1(i, n) for(int i=1;i<=(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define per1(i, n) for(int i=(n);i>=1;--i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define ROF(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define FOR1(i, a, b) for(int i=(a);i<=(b);++i)
#define ROF1(i, a, b) for(int i=(b);i>=(a);--i)
#define eb emplace_back
#define ef emplace_front
#define et insert
#define rbe rbegin()
#define ret return
#define br break
#define psb push_back
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define y0 y1234567890
#define y1 y12345678901
#define j0 j1234567890
#define j1 j12345678901
#define tm tm1234567890
#define left left1234567890
#define right right1234567890
#define prev prev1234567890
#define next next1234567890
#define X first
#define Y second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for(int i=0;i<(n);++i)
#define rep1(i, n) for(int i=1;i<=(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define per1(i, n) for(int i=(n);i>=1;--i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define ROF(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define FOR1(i, a, b) for(int i=(a);i<=(b);++i)
#define ROF1(i, a, b) for(int i=(b);i>=(a);--i)
#define eb emplace_back
#define ef emplace_front
#define et insert
#define rbe rbegin()
#define ret return
#define br break
#define psb push_back
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define y0 y1234567890
#define y1 y12345678901
#define j0 j1234567890
#define j1 j12345678901
#define tm tm1234567890
#define left left1234567890
#define right right1234567890
#define prev prev1234567890
#define next next1234567890
#define X first
#define Y second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for(int i=0;i<(n);++i)
#define rep1(i, n) for(int i=1;i<=(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define per1(i, n) for(int i=(n);i>=1;--i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define ROF(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define FOR1(i, a, b) for(int i=(a);i<=(b);++i)
#define ROF1(i, a, b) for(int i=(b);i>=(a);--i)
#define eb emplace_back
#define ef emplace_front
#define et insert
#define rbe rbegin()
#define ret return
#define br break
#define psb push_back
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define y0 y1234567890
#define y1 y12345678901
#define j0 j1234567890
#define j1 j12345678901
#define tm tm1234567890
#define left left1234567890
#define right right1234567890
#define prev prev1234567890
#define next next1234567890
#define X first
#define Y second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for(int i=0;i<(n);++i)
#define rep1(i, n) for(int i=1;i<=(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define per1(i, n) for(int i=(n);i>=1;--i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define ROF(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define FOR1(i, a, b) for(int i=(a);i<=(b);++i)
#define ROF1(i, a, b) for(int i=(b);i>=(a);--i)
#define eb emplace_back
#define ef emplace_front
#define et insert
#define rbe rbegin()
#define ret return
#define br break
#define psb push_back
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define y0 y1234567890
#define y1 y12345678901
#define j0 j1234567890
#define j1 j12345678901
#define tm tm1234567890
#define left left1234567890
#define right right1234567890
#define prev prev1234567890
#define next next1234567890
#define X first
#define Y second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for(int i=0;i<(n);++i)
#define rep1(i, n) for(int i=1;i<=(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define per1(i, n) for(int i=(n);i>=1;--i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define ROF(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define FOR1(i, a, b) for(int i=(a);i<=(b);++i)
#define ROF1(i, a, b) for(int i=(b);i>=(a);--i)
#define eb emplace_back
#define ef emplace_front
#define et insert
#define rbe rbegin()
#define ret return
#define br break
#define psb push_back
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define y0 y1234567890
#define y1 y12345678901
#define j0 j1234567890
#define j1 j12345678901
#define tm tm1234567890
#define left left1234567890
#define right right1234567890
#define prev prev1234567890
#define next next1234567890
#define X first
#define Y second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for(int i=0;i<(n);++i)
#define rep1(i, n) for(int i=1;i<=(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define per1(i, n) for(int i=(n);i>=1;--i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define ROF(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define FOR1(i, a, b) for(int i=(a);i<=(b);++i)
#define ROF1(i, a, b) for(int i=(b);i>=(a);--i)
#define eb emplace_back
#define ef emplace_front
#define et insert
#define rbe rbegin()
#define ret return
#define br break
#define psb push_back
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define y0 y1234567890
#define y1 y12345678901
#define j0 j1234567890
#define j1 j12345678901
#define tm tm1234567890
#define left left1234567890
#define right right1234567890
#define prev prev1234567890
#define next next1234567890
#define X first
#define Y second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for(int i=0;i<(n);++i)
#define rep1(i, n) for(int i=1;i<=(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define per1(i, n) for(int i=(n);i>=1;--i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define ROF(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define FOR1(i, a, b) for(int i=(a);i<=(b);++i)
#define ROF1(i, a, b) for(int i=(b);i>=(a);--i)
#define eb emplace_back
#define ef emplace_front
#define et insert
#define rbe rbegin()
#define ret return
#define br break
#define psb push_back
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define y0 y1234567890
#define y1 y12345678901
#define j0 j1234567890
#define j1 j12345678901
#define tm tm1234567890
#define left left1234567890

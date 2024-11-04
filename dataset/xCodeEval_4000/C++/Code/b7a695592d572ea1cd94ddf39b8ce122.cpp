



#define USETR1
#define CPPELEVEN
#define GPP





#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cassert>
#include <list>
#include <iomanip>
#include <math.h>
#include <deque>
#include <utility>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <climits>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <sstream>
#include <tuple>

using namespace std;

#ifndef CPPELEVEN
#ifdef USETR1
#include <tr1/unordered_map>
#include <tr1/unordered_set>
using namespace tr1;
#endif
#else
#include <unordered_map>
#include <unordered_set>
#endif

#ifdef USEPB_DS
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;


typedef __gnu_pbds::priority_queue<int, greater<int>, pairing_heap_tag> pq_type;


typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> tree_type;
#endif

#define mpr make_pair
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <double, double> pdd;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <double> vd;
typedef vector <string> vs;
typedef map <string, int> mpsi;
typedef map <double, int> mpdi;
typedef map <int, int> mpii;

const double pi = acos(0.0) * 2.0;
const long double eps = 1e-10;
const int step[8][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};

template <class T> inline T abs1(T a) {return a < 0 ? -a : a;}

#ifndef CPPELEVEN
template <class T> inline T max1(T a, T b) { return b < a ? a : b; }
template <class T> inline T max1(T a, T b, T c) { return max1(max1(a, b), c); }
template <class T> inline T max1(T a, T b, T c, T d) { return max1(max1(a, b, c), d); }
template <class T> inline T max1(T a, T b, T c, T d, T e) { return max1(max1(a, b, c, d), e); }
template <class T> inline T min1(T a, T b) { return a < b ? a : b; }
template <class T> inline T min1(T a, T b, T c) { return min1(min1(a, b), c); }
template <class T> inline T min1(T a, T b, T c, T d) { return min1(min1(a, b, c), d); }
template <class T> inline T min1(T a, T b, T c, T d, T e) { return min1(min1(a, b, c, d), e); }
#else
template <typename t, typename t1>
t min1(t a, t1 b) { return a < b ? a : b; }
template <typename t, typename... arg>
t min1(t a, arg... arr) { return min1(a, min1(arr...)); }
template <typename t, typename t1>
t max1(t a, t1 b) { return a > b ? a : b; }
template <typename t, typename... arg>
t max1(t a, arg... arr) { return max1(a, max1(arr...)); }
#endif

inline int jud(double a, double b){
	if(abs(a) < eps && abs(b) < eps) return 0;
	else if(abs1(a - b) / max(abs1(a), abs1(b)) < eps) return 0;
	if(a < b) return -1;
	return 1;
}
template <typename t> inline int jud(t a, t b){
	if(a < b) return -1;
	if(a == b) return 0;
	return 1;
}



template <typename it, typename t1>
inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1){
	if(na == 0) return 0;
	int be = 0, en = na - 1;
	if(*a <= *(a + na - 1)){
		if(f_lb == 0) while(be < en){
			int mid = (be + en + 1) / 2;
			if(jud(*(a + mid), val) != 1) be = mid;
			else en = mid - 1;
		}else while(be < en){
			int mid = (be + en) / 2;
			if(jud(*(a + mid), val) != -1) en = mid;
			else be = mid + 1;
		}
		if(f_small && jud(*(a + be), val) == 1) be--;
		if(!f_small && jud(*(a + be), val) == -1) be++;
	} else {
		if(f_lb) while(be < en){
			int mid = (be + en + 1) / 2;
			if(jud(*(a + mid), val) != -1) be = mid;
			else en = mid - 1;
		}else while(be < en){
			int mid = (be + en) / 2;
			if(jud(*(a + mid), val) != 1) en = mid;
			else be = mid + 1;
		}
		if(!f_small && jud(*(a + be), val) == -1) be--;
		if(f_small && jud(*(a + be), val) == 1) be++;
	}
	return be;
}

template <class T> inline T lowb(T num) {return num & (-num); }
#ifdef GPP
inline int bitnum(ui nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(ull nValue) { return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32); }
inline int bitnum(ll nValue) { return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32); }
inline int bitmaxl(ui a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int bitmaxl(int a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int bitmaxl(ull a) { int temp = a >> 32; if(temp) return 32 - __builtin_clz(temp) + 32; return bitmaxl(int(a)); }
inline int bitmaxl(ll a) { int temp = a >> 32; if(temp) return 32 - __builtin_clz(temp) + 32; return bitmaxl(int(a)); }
#else
#endif

long long pow(long long n, long long m, long long mod = 0){
	if(m < 0) return 0;
	long long ans = 1;
	long long k = n;
	while(m){
		if(m & 1) {
			ans *= k;
			if(mod) ans %= mod;
		}
		k *= k;
		if(mod) k %= mod;
		m >>= 1;
	}
	return ans;
}

#define  MOD 1000000007
template <class t1, class t2>
inline void add(t1 &a, t2 b, int mod = -1) {
	if(mod == -1) mod = MOD;
	a += b;
	while(a >= mod) a -= mod;
	while(a < 0) a += mod;
}
template <class t>
void output1(t arr) {
	for(int i = 0; i < (int)arr.size(); i++)
		cerr << arr[i] << ' ';
	cerr << endl;
}
template <class t>
void output2(t arr) {
	for(int i = 0; i < (int)arr.size(); i++)
		output1(arr[i]);
}




const int maxn = 600100;

int p[maxn * 2], lp, rp[maxn * 2], lrp;
int h[maxn], tono[maxn];
int n, m, c;
int dp[maxn], biao[maxn];
bool cant[maxn];
pair <pii, int> orig[maxn], rorig[maxn];
vi st[maxn], rst[maxn], ren[maxn];
int tdp[maxn];
vi contain[maxn];
int maxOver[maxn];

int main() {





	ios_base::sync_with_stdio(0);
	#ifdef DEBUG 

	freopen("input.txt", "r", stdin);
	int __size__ = 256 << 20; 

	char *__p__ = (char*)malloc(__size__) + __size__;
	__asm__("movl %0, %%esp\n" :: "r"(__p__));
	#endif 


	scanf("%d%d", &n, &c);
	lp = 1;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &orig[i].first.first, &orig[i].first.second, &orig[i].second);
		p[lp++] = orig[i].first.first;
		p[lp++] = orig[i].first.second;
	}
	sort(orig, orig + n);
	sort(p, p + lp);
	lp = unique(p, p + lp) - p;
	for (int i = 0; i < n; i++) {
		orig[i].first.first = find(orig[i].first.first, p, lp);
		orig[i].first.second = find(orig[i].first.second, p, lp);
		st[orig[i].first.first].push_back(i);
		h[orig[i].first.first]++;
		h[orig[i].first.second]--;
	}
	lrp = 1;
	for (int i = 1; i < lp; i++) {
		h[i] += h[i - 1];
		if (h[i] <= 2) {
			rp[lrp++] = p[i];
			tono[lrp - 1] = i;
		} else if (h[i - 1] <= 2) {
			rp[lrp++] = p[i];
			tono[lrp - 1] = i;
		}
	}

	for (int i = 0; i < n; i++) {
		rorig[i].first.first = find(p[orig[i].first.first], rp, lrp, 0);
		if (h[tono[rorig[i].first.first]] > 2) {
			rorig[i].first.first++;
		}
		rorig[i].first.second = find(p[orig[i].first.second], rp, lrp);
		if (h[tono[rorig[i].first.second] - 1] > 2) {
			rorig[i].first.second--;
		}
		rorig[i].second = orig[i].second;
		rst[rorig[i].first.first].push_back(i);
	}

	set <int> in;
	for (int i = 0; i < lrp; i++) {
		for (auto it : rst[i]) if (rorig[it].first.second > rorig[it].first.first){
			ren[rorig[it].first.second].push_back(it);
			in.insert(it);
		}
		for (auto it : ren[i])
			in.erase(it);
		ren[i].clear();
		if (in.size() <= 2) {
			for (auto it : in) {
				contain[i].push_back(it);
			}
		}
	}

	int rc = c;
	pii rhave = mpr(-1, -1);
	int currentOver = 0;
	for (int i = 0; i < lrp; i++) {
		if (c < 0) cant[i] = 1;
		dp[i + 1] = dp[i];
		for (auto no : ren[i]) {
			if (no == rhave.first) {
				swap(rhave.first, rhave.second);
			}
			rhave.second = -1;
			dp[i + 1] = min(dp[i + 1], biao[no]);
			c += rorig[no].second;
			currentOver = 0;
		}
		if (h[tono[i]] <= 2 && h[tono[i]] > 0) {
			dp[i + 1] += rp[i + 1] - rp[i];
			for (auto no : rst[i]) if (rorig[no].first.second > rorig[no].first.first){
				c -= rorig[no].second;
				biao[no] = dp[i];
				ren[rorig[no].first.second].push_back(no);
				if (rhave.first == -1)
					rhave.first = no;
				else
					rhave.second = no;
				int rsum = 0;
				if (c >= 0) {
					for (int j = i + 1; j < rorig[no].first.second; j++) {
						if (h[tono[j]] <= 2 && rhave.second != -1) {
							int maxv = 0;
							for (auto it : contain[j])
								maxv = max(maxv, it);
							if (maxv <= no) {
								rsum += rp[j + 1] - rp[j];
							}
							tdp[j + 1] = max(tdp[j + 1], rsum + dp[i + 1]);
						}
					}
				}
			}
			if (rhave.second == -1) {
				if (c >= 0)
					tdp[i + 1] = max(tdp[i + 1], dp[i + 1] + maxOver[rhave.first]);
			} else {
				currentOver += rp[i + 1] - rp[i];
				if (c >= 0) {
					maxOver[rhave.first] = max(maxOver[rhave.first], currentOver);
					tdp[i + 1] = max(tdp[i + 1], dp[i + 1] - currentOver + maxOver[rhave.first]);
				}
			}
		}
		for (auto no : ren[i]) {
			if (rhave.first != -1) {
				biao[rhave.first] = min(biao[no], biao[rhave.first]);
			}
			if (rhave.second != -1) {
				biao[rhave.second] =   min(biao[no], biao[rhave.second]);
			}
		}
		ren[i].clear();
	}
	for (int i = 1; i < lrp; i++) {
		if (cant[i]) {
			dp[i] = dp[i - 1];
		} else {
			dp[i] = max(dp[i], dp[i - 1]);
		}
		dp[i] = max(dp[i], tdp[i]);
	}
	int sumv = 0;
	for (int i = 0; i < lrp; i++) {
		dp[i] += sumv;
		if (h[tono[i]] == 0) sumv += rp[i + 1] - rp[i];
	}

	mpii rtt;
	int lastno = -1, currentsum = 0, max1 = 0;
	int sum0 = 0, maxdp = 0;
	for (int i = 0; i < lrp; i++) {
		if (h[tono[i]] == 0) {
			sum0 += rp[i + 1] - rp[i];
			dp[i + 1] = max(dp[i + 1], maxdp + sum0);
			continue;
		}
		for (auto it : rst[i]) if (rorig[it].first.second > rorig[it].first.first){
			if (lastno == -1 || rorig[it].first.second > rorig[lastno].first.second) {
				lastno = it;
				currentsum = 0;
				max1 = 0;
				auto rit = rtt.upper_bound(rc - rorig[it].second);
				if (rit != rtt.begin()) {
					rit--;
					max1 = rit->second;
				}
			}
		}
		if (h[tono[i]] == 1 && rorig[lastno].second <= rc) {
			currentsum += rp[i + 1] - rp[i];
			maxdp = max(currentsum + max1, maxdp);
			auto rit = rtt.lower_bound(rorig[lastno].second);
			bool flag = 1;
			if (rit != rtt.begin()) {
				auto rtit = rit;
				rtit--;
				if (rtit->second > currentsum)
					flag = 0;
			}
			while(flag && rit != rtt.end() && rit->second <= currentsum) {
				auto temp = rit;
				rit++;
				rtt.erase(temp);
			}
			if (flag) {
				rtt.insert(mpr(rorig[lastno].second, currentsum));
			}
		}
		dp[i + 1] = max(dp[i + 1], maxdp + sum0);
	}


	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int val;
		scanf("%d", &val);
		if (val > dp[lrp - 1])
			printf("%d\n", rp[lrp - 1] + val - dp[lrp - 1]);
		else {
			int trp = find(val, dp, lrp, 0, 1);
			printf("%d\n", rp[trp] + val - dp[trp]);
		}
	}

    return 0;
}


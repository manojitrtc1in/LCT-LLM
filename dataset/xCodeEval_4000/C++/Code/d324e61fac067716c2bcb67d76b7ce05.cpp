
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
#include <sstream>

using namespace std;

#define mpr make_pair
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
const double eps = 1e-12;
const int step[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

template <class T> inline T abs1(T a) {return a < 0 ? -a : a;}
template <class T> inline T max1(T a, T b, T c = -1234567, T d = -1234567) {
	T ans =  a > b ? a : b;
	if(c != -1234567) ans = max1(ans, c);
	if(d != -1234567) ans = max1(ans, d);
	return ans;
}
template <class T> inline T min1(T a, T b, T c = -1234567, T d = -1234567) {
	T ans = a < b ? a : b;
	if(c != -1234567) ans = min(ans, c);
	if(d != -1234567) ans = min(ans, d);
	return ans;
}
template <class T> inline T gcd1(T a, T b) {
	if(a < b) swap(a, b);
	if(a % b == 0) return b;
	return gcd1(b, a % b);
}
template <class T> inline T lb(T num) {return num & (-num); }
inline int jud(double a, double b){
	if(abs(a) < eps && abs(b) < eps) return 0;
	else if(abs1(a - b) / abs1(a) < eps) return 0;
	if(a < b) return -1;
	return 1;
}
template <typename t>
inline int jud(t a, t b){
	if(a < b) return -1;
	if(a == b) return 0;
	return 1;
}
template <typename it, typename t1>
inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1){
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
inline int bitnum(ull nValue){
    nValue = ((0xaaaaaaaaaaaaaaaaull & nValue)>>1) + (0x5555555555555555ull & nValue);
    nValue = ((0xccccccccccccccccull & nValue)>>2) + (0x3333333333333333ull & nValue);
    nValue = ((0xf0f0f0f0f0f0f0f0ull & nValue)>>4) + (0x0f0f0f0f0f0f0f0full & nValue);
    nValue = ((0xff00ff00ff00ff00ull & nValue)>>8) + (0x00ff00ff00ff00ffull & nValue);
    nValue = ((0xffff0000ffff0000ull & nValue)>>16) + (0x0000ffff0000ffffull & nValue);
    nValue = ((0xffffffff00000000ull & nValue)>>32) + (0x00000000ffffffffull & nValue);
	return nValue;
}
long long pow(long long n, long long m, long long mod = 0){
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





const int maxn = 100110;
template <class t> struct segment_node{
	int be, en;
	t num, add;
};
template <class t> struct segment_tree{
	int l;
	segment_node <t> tree[maxn * 4];

	inline int gleft(int no) {return no << 1;}
	inline int gright(int no) {return (no << 1) + 1;}
	inline int gfa(int no) {return no >> 1;}
	inline segment_tree(){ l = 0; }

	void build(int no, int l, int r){
		if(l == r){
			tree[no].be = tree[no].en = l;
			tree[no].num = -1;
			tree[no].add = -1;
			return;
		}
		tree[no].be = l; tree[no].en = r;
		int mid = (l + r) / 2;
		build(gleft(no), l, mid);
		build(gright(no), mid + 1, r);
		tree[no].add = -1;
	}
	inline void relax(int no) {
		tree[gleft(no)].add = tree[no].add;
		tree[gright(no)].add = tree[no].add;
		tree[no].add = -1;
	}
	void down(int l, int r, int no, t ranadd){
		if(tree[no].be != tree[no].en && tree[no].add != -1)
			relax(no);
		if(l <= tree[no].be && r >= tree[no].en){
			tree[no].add = ranadd;
			return;
		}
		int mid = (tree[no].be + tree[no].en) / 2;
		if(r >= tree[no].be && l <= mid) down(l, r, gleft(no), ranadd);
		if(r >= mid + 1 && l <= tree[no].en) down(l, r, gright(no), ranadd);
	}
	t getnum(int loc, int no){
		if(tree[no].add != -1) {
			int ans = tree[no].add;
			if(tree[no].be != tree[no].en) relax(no);
			return ans;
		}
		if(tree[no].be == tree[no].en) return tree[no].num;
		int mid = (tree[no].be + tree[no].en) / 2;
		if(loc <= mid) return getnum(loc, gleft(no));
		else return getnum(loc, gright(no));
	}
};
segment_tree <int> sgt[4]; 


struct segment {
	int from, to, no;
	segment(int a = 0, int b = 0, int no1 = 0) {
		from = min(a, b);
		to = max(a, b);
		no = no1;
	}
};
vector <segment> orig[2][maxn];
pii orig1[maxn * 2], origto[maxn];
ll origdir[maxn * 2], origstep[maxn];
struct vec {
	int no, loc;
	vec(int a = 0, int b = 0) : no(a), loc(b) {}
};
vector <vec> she[4][maxn];
map <pii, int> trans;
ll narrow, b, nq;
struct node{
	int fa, delta;
	ll dis;
	node(int a = 0, int b = 0, int c = 0) {
		fa = a, dis = b, delta = c;
	}
} fa[60][maxn * 2];

inline int finddir(pii from, pii to){
	to.first -= from.first; to.second -= from.second;
	if(to.first) to.first /= abs(to.first);
	if(to.second) to.second /= abs(to.second);
	for(int j = 0; j < 4; j++) if(to.first == step[j][0] && to.second == step[j][1])
		return j;
	return 0;
}
inline ll cntdis(pii co, pii co1) {
	return abs(co.first - co1.first) + abs(co.second - co1.second);
}
inline pll finddis(int from, int dir, int to) {
	pll ans;
	if(to == -1) {
		ans = orig1[from];
		if(dir > 1) swap(ans.first, ans.second);
		if(!(dir & 1)) ans.first = b - ans.first;
		ans.second = 0;
		return ans;
	}
	if((origdir[to] ^ dir) < 2) {
		ll dis1 = orig1[from].first - orig1[to].first, dis2 = orig1[from].first - origto[to].first;
		if(orig1[to].first == orig1[from].first && orig1[to].first == origto[to].first)
			dis1 = orig1[from].second - orig1[to].second, dis2 = orig1[from].second - origto[to].second;
		if(dis1 * dis2 < 0) {
			ans.first = 0;
			ans.second = abs1(dis1);
		}
		else {
			ans.first = min(abs1(dis1), abs1(dis2));
			ans.second = 0;
			if(abs1(dis1) > abs1(dis2)) ans.second = abs1(dis1) - abs1(dis2);
		}
		return ans;
	}
	ans = orig1[to];
	ans.first -= orig1[from].first; ans.second -= orig1[from].second;
	if(dir > 1) swap(ans.first, ans.second);
	ans.first = abs1(ans.first); ans.second = abs1(ans.second);
	return ans;
}

int main(){


	scanf("%I64d%I64d", &narrow, &b);
	for(int i = 0; i < narrow; i++) {
		pii from, to;
		scanf("%d%d%d%d", &from.first, &from.second, &to.first, &to.second);
		trans[from] = i;
		orig1[i] = from; origto[i] = to;
		if(from.first == to.first) {
			orig[0][from.first].push_back(segment(from.second, to.second, i));
			orig[1][max(from.second, to.second)].push_back(segment(from.first, from.first, i));
			orig[1][min(from.second, to.second)].push_back(segment(from.first, from.first, i));
		} else {
			orig[1][from.second].push_back(segment(from.first, to.first, i));
			orig[0][max(from.first, to.first)].push_back(segment(from.second, from.second, i));
			orig[0][min(from.first, to.first)].push_back(segment(from.second, from.second, i));
		}
		int	randir = finddir(from, to);
		origdir[i] = randir;
		if(randir > 1) swap(to.first, to.second);
		she[randir][to.first].push_back(vec(i, to.second));
	}
	scanf("%I64d", &nq);
	for(int i = 0; i < nq; i++) {
		pii st; char randirc; ll step1, randir;
		scanf("%d %d %c %I64d", &st.first, &st.second, &randirc, &step1);
		orig1[i + narrow] = st;
		trans[st] = i + narrow;
		if(randirc == 'L') randir = 1;
		if(randirc == 'R') randir = 0;
		if(randirc == 'U') randir = 2;
		if(randirc == 'D') randir = 3;
		origdir[i + narrow] = randir, origstep[i] = step1;
		if(randir > 1) swap(st.first, st.second);
		she[randir][st.first].push_back(vec(i + narrow, st.second));
	}
	for(int i = 0; i < 4; i++) {
		sgt[i].build(1, 0, b + 1);
		int from = 0, add = 1, to = b + 1;
		if(!(i & 1)) from = b, add = -1, to = -1;
		int biao = i / 2;
		for(int j = from; j != to; j += add) {
			for(int t = 0; t < (int)she[i][j].size(); t++) if(she[i][j][t].no < narrow){
				fa[0][she[i][j][t].no].fa = sgt[i].getnum(she[i][j][t].loc, 1);
				pll randis = finddis(she[i][j][t].no, i, fa[0][she[i][j][t].no].fa);
				fa[0][she[i][j][t].no].dis = randis.first;
				fa[0][she[i][j][t].no].delta = randis.second;
			}
			for(int t = 0; t < (int)orig[biao][j].size(); t++)
				sgt[i].down(orig[biao][j][t].from, orig[biao][j][t].to, 1, orig[biao][j][t].no);
			for(int t = 0; t < (int)she[i][j].size(); t++)
				if(she[i][j][t].no >= narrow){
	

				fa[0][she[i][j][t].no].fa = sgt[i].getnum(she[i][j][t].loc, 1);
				pll randis = finddis(she[i][j][t].no, i, fa[0][she[i][j][t].no].fa);
				fa[0][she[i][j][t].no].dis = randis.first;
				fa[0][she[i][j][t].no].delta = randis.second;
			}
		}
	}
	for(int i = 1; i < 60; i++) {
		for(int j = 0; j < narrow + nq; j++) {
			if(fa[i - 1][j].fa != -1){
				fa[i][j].fa = fa[i - 1][fa[i - 1][j].fa].fa;
				fa[i][j].delta = fa[i - 1][fa[i - 1][j].fa].delta;
				fa[i][j].dis = fa[i - 1][fa[i - 1][j].fa].dis + fa[i - 1][j].dis - fa[i - 1][j].delta;
			}else fa[i][j] = fa[i - 1][j];
			if(fa[i][j].dis > 1000000000000000ll) fa[i][j].dis = 1000000000000001ll; 

		}
	}


	for(ll i1 = 0; i1 < nq; i1++) {
		ll no = i1 + narrow;
		int en = 59;
		for(; en != -1; ){
			int ranbe = -1, ranen = en;
			while(ranbe < ranen) {
				int mid = (ranbe + ranen + 1) / 2;
				if(fa[mid][no].dis > origstep[i1] || fa[mid][no].fa == -1) ranen = mid - 1;
				else ranbe = mid;
			}
			en = ranbe;
			if(en == -1) break;
			origstep[i1] -= fa[ranbe][no].dis - fa[ranbe][no].delta;
			no = fa[ranbe][no].fa;
		}
		printf("%I64d %I64d\n", max1(0ll, min1(b, orig1[no].first + origstep[i1] * step[origdir[no]][0])),
									 max1(0ll, min1(b, orig1[no].second + origstep[i1] * step[origdir[no]][1])));
	}

	return 0;
}

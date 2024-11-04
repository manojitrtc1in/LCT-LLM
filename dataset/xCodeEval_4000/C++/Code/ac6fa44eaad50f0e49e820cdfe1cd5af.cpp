


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
#include <tr1/unordered_map>
#include <tr1/unordered_set>

using namespace std;
using namespace tr1;

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
const double eps = 1e-12;
const int step[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

template <class T> inline T abs1(T a) {return a < 0 ? -a : a;}

template <class T> inline T max1(T a, T b) { return a > b ? a : b; }
template <class T> inline T max1(T a, T b, T c) { return max1(max1(a, b), c); }
template <class T> inline T max1(T a, T b, T c, T d) { return max1(max1(a, b, c), d); }
template <class T> inline T max1(T a, T b, T c, T d, T e) { return max1(max1(a, b, c, d), e); }
template <class T> inline T min1(T a, T b) { return a < b ? a : b; }
template <class T> inline T min1(T a, T b, T c) { return min1(min1(a, b), c); }
template <class T> inline T min1(T a, T b, T c, T d) { return min1(min1(a, b, c), d); }
template <class T> inline T min1(T a, T b, T c, T d, T e) { return min1(min1(a, b, c, d), e); }

inline int jud(double a, double b){
	if(abs(a) < eps && abs(b) < eps) return 0;
	else if(abs1(a - b) / abs1(a) < eps) return 0;
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
inline int bitnum(ui nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(ull nValue) { return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32); }
inline int bitnum(ll nValue) { return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32); }
inline int bitmaxl(ui a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int bitmaxl(int a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int bitmaxl(ull a) { int temp = a >> 32; if(temp) return 32 - __builtin_clz(temp) + 32; return bitmaxl(int(a)); }
inline int bitmaxl(ll a) { int temp = a >> 32; if(temp) return 32 - __builtin_clz(temp) + 32; return bitmaxl(int(a)); }

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






const int maxl = 4;
const int maxn = 100100;
struct trie {
	int nxt[maxl];
	int val;
	void init() {
		memset(nxt, -1, sizeof(nxt));
		val = 0;
	}
} arra[maxn * 40];
int larr;
map <char, int> mp;
inline void initmp() {
	for(char ch = 'A'; ch <= 'D'; ch++)
		mp[ch] = ch - 'A';
}
inline int addword(char *str, int l) {
	int no = 0;
	for(int i = 0; i < l; i++) {
		int nxt = arra[no].nxt[mp[str[i]]];
		if(nxt == -1) {
			arra[larr].init();
			nxt = arra[no].nxt[mp[str[i]]] = larr++;
		}
		no = nxt;
	}
	return no;
}

template <typename t> struct matrix{
	const static int maxn = 5;
	int row, col;
	t mat[maxn][maxn];

	matrix(int r = 0, int c = 0){
		row = r; col = c;
		for(int i = 0; i < row; i++) for(int j = 0; j < col; j++) mat[i][j] = 0;
	}
	const t * operator[] (int i) const {
		return mat[i];
	}
	t * operator[] (int i) {
		return mat[i];
	}
	bool danweiju(){
		if(row != col) return 0;
		for(int i = 0; i < row; i++) for(int j = 0; j < col; j++) mat[i][j] = bool (i == j);
		return 1;
	}
	matrix operator * (const matrix& b) const{
		int i, j, k;
		matrix <t> c(row, b.col);
		memset(c.mat, 0, sizeof(c.mat));
		for (i = 0; i < c.row; i++) for (j = 0; j < c.col; j++){
			c.mat[i][j] = 1ull << 62;
			for (k = 0; k < col; k++)
				c.mat[i][j] = min(c.mat[i][j], mat[i][k] + b.mat[k][j]);
		}
		return c;
	}
	matrix operator + (const matrix& b) const{
		matrix <t> c(max1(row, b.row), max1(col, b.col));
		for(int i = 0; i < c.row; i++) for(int j = 0; j < c.col; j++){
			t a = 0; if(i < row && j < col) a = mat[i][j];
			t b1 = 0; if(i < b.row && j < b.col) b1 = b.mat[i][j];
			c.mat[i][j] = a + b1;
		}
		return c;
	}
	matrix operator - (const matrix& b) const{
		matrix <t> c(max1(row, b.row), max1(col, b.col));
		for(int i = 0; i < c.row; i++) for(int j = 0; j < c.col; j++){
			t a = 0; if(i < row && j < col) a = mat[i][j];
			t b1 = 0; if(i < b.row && j < b.col) b1 = b.mat[i][j];
			c.mat[i][j] = a - b1;
		}
		return c;
	}
	inline void operator = (const matrix & b){
		memcpy(mat, b.mat, sizeof(mat));
		col = b.col;  row = b.row;
	}
	matrix pow(long long n){
		matrix <t> ans(row, col), temp = *this;

		ans.danweiju();
		while(n){
			if(n & 1) ans = ans * temp;
			temp = temp * temp;
			n >>= 1;
		}
		return ans;
	}
	matrix addpow(long long n) {

		n++;
		matrix <t> ans(row, col), temp = *this, temp1(row, col), ans1(row, col);

		ans.danweiju(); temp1.danweiju();
		while(n){
			if(n & 1){
				ans1 = ans1 + ans * temp1;
				temp1 = temp * temp1;
			}
			ans = ans + ans * temp;
			temp = temp * temp;
			n >>= 1;
		}
		return ans1;
	}
	int inv(){
		int i, j, k, is[maxn], js[maxn];
		double t1;

		if (row != col) return 0;
		for(k = 0; k < row; k++){
			for(t1 = 0,i = k; i < row; i++) for(j = k; j < row; j++)
				if(fabs(mat[i][j]) > t1)
					t1=fabs(mat[is[k] = i][js[k] = j]);
			if (fabs(t1 - 0) < 1e-9) return 0;
			if (is[k] != k) for(j = 0; j < row; j++)
				t1 = mat[k][j], mat[k][j] = mat[is[k]][j], mat[is[k]][j] = t1;
			if (js[k] != k) for (i = 0; i < row; i++)
				t1 = mat[i][k], mat[i][k] = mat[i][js[k]], mat[i][js[k]] = t1;
			mat[k][k] = 1 / mat[k][k];
			for(j = 0; j < row; j++) if (j != k)
				mat[k][j] *= mat[k][k];
			for (i = 0; i < row; i++)	if (i != k)
				for (j = 0; j < row; j++) if (j != k)
					mat[i][j] -= mat[i][k] * mat[k][j];
			for (i = 0;i < row; i++) if (i != k)
				mat[i][k] *= -mat[k][k];
		}
		for (k = row-1; k >= 0; k--){
			for (j = 0; j < row; j++) if (js[k] != k)
					t1 = mat[k][j], mat[k][j] = mat[js[k]][j], mat[js[k]][j]=t1;
			for (i = 0; i < row; i++) if (is[k] != k)
				t1 = mat[i][k], mat[i][k] = mat[i][is[k]], mat[i][is[k]] = t1;
		}
		return 1;
	}
	double det(){
		int i, j, k, sign = 0;
		double b[maxn][maxn], ret = 1, t1;

		if (row != col) return 0;
		for (i = 0; i < row; i++) for (j = 0; j < col; j++)
			b[i][j] = mat[i][j];
		for (i = 0; i < row; i++){
			if (fabs(b[i][i] - 0) < 1e-9){
				for (j = i + 1; j < row; j++)
					if (fabs(b[j][i] - 0) > 1e-9) break;
					if (j == row) return 0;
					for (k = i; k < row; k++)
						t1 = b[i][k], b[i][k] = b[j][k], b[j][k] = t1;
					sign++;
			}
			ret *= b[i][i];
			for (k = i + 1; k < row; k++) b[i][k] /= b[i][i];
			for (j = i + 1; j < row; j++) for (k = i + 1; k < row; k++)
				b[j][k] -= b[j][i] * b[i][k];
		}
		if (sign & 1) ret = -ret;
		return ret;
	}
};


ll n, l;
char str[maxn];
matrix <ull> m(4, 4);
matrix <ull> arr[100];

void dfs(int no, int deep, int cate) {
	for(int i = 0; i < 4; i++) {
		if(arra[no].nxt[i] == -1)
			m[cate][i] = min(m[cate][i], 1ull * deep);
		else dfs(arra[no].nxt[i], deep + 1, cate);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	#ifdef debug 

	freopen("input.txt", "r", stdin);
	#endif 

	scanf("%I64d%s", &n, str);
	for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) {
		m[i][j] = 1ll << 62;
	}
	l = strlen(str);
	initmp();
	for(int i = 0; i < 4; i++) {
		larr = 1;
		arra[0].init();
		for(int j = 0; j < l; j++) if(str[j] - 'A' == i)
			addword(str + j, min(l - j, 30ll));
		dfs(1, 1, i);
	}













	bool flag = 0;
	for(int j = 0; j < 4; j++) for(int k = 0;  k < 4; k++)
		if(m[j][k] < n) flag = 1;
	if(!flag) {
		puts("1");
		return 0;
	}
	arr[0] = m;
	int be = 0;
	for(int i = 1; i < 62; i++) {
		arr[i] = arr[i - 1] * arr[i - 1];
		bool flag = 0;
		for(int j = 0; j < 4; j++) for(int k = 0; k < 4; k++)
			if(arr[i][j][k] < n) flag = 1;
		if(!flag) {
			be = i - 1;
			break;
		}
	}
	ll ans = 1ll << be;
	matrix <ull> ansm(4, 4), tansm(4, 4);
	ansm = arr[be];
	for(int t = be - 1; t >= 0; t--) {
		tansm = ansm * arr[t];
		bool flag = 0;
		for(int j = 0; j < 4; j++) for(int k = 0; k < 4; k++)
			if(tansm[j][k] < n) flag = 1;
		if(flag) {
			ansm = ansm * arr[t];
			ans += 1ll << t;
		}
	}
	cout << ans + 1 << endl;


    return 0;
}

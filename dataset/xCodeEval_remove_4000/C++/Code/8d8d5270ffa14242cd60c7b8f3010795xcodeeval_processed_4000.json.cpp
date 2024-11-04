






























using namespace std;
using namespace tr1;


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
inline int id2(ui a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int id2(int a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int id2(ull a) { int temp = a >> 32; if(temp) return 32 - __builtin_clz(temp) + 32; return id2(int(a)); }
inline int id2(ll a) { int temp = a >> 32; if(temp) return 32 - __builtin_clz(temp) + 32; return id2(int(a)); }

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







struct bd {
	double num;
	int mi;
	bd(double rnum = 0) {
		num = rnum;
		mi = 0;
		relax();
	}
	void relax() {
		if(fabs(num) < eps){
			mi = 0;
			num = 0;
			return;
		}
		while(fabs(num) < 1) {
			num *= 10;
			mi--;
		}
		while(fabs(num) > 10) {
			num /= 10;
			mi++;
		}
	}
	bool operator < (const bd &a) const {
		if(a.mi > mi + 15) {
			return a.num > 0;
		} else if(mi > a.mi + 15) {
			return num < 0;
		}
		double kk = a.num; int rmi = a.mi;
		int flag = (a.mi - mi) / abs(a.mi - mi);
		for(; rmi != mi; rmi -= flag) {
			if(flag < 0) kk /= 10;
			else kk *= 10;
		}
		return num < kk;
	}
	friend bd operator - (const bd &a, const bd &b) {
		bd c;
		if(a.mi > b.mi + 15) {
			return a;
		} else if(b.mi > a.mi + 15) {
			c = b;
			c.num = -c.num;
			return c;
		}
		c = a;
		if(c.mi != b.mi) {
			int flag = (c.mi - b.mi) / abs(c.mi - b.mi);
			for(; c.mi != b.mi; c.mi -= flag) {
				if(flag < 0) c.num /= 10;
				else c.num *= 10;
			}
		}
		c.num -= b.num;
		c.relax();
		return c;
	}
	friend bd operator + (const bd &a, const bd &b) {
		bd c;
		if(a.mi > b.mi + 15) {
			return a;
		} else if(b.mi > a.mi + 15) {
			c = b;
			return c;
		}
		c = a;
		if(c.mi != b.mi) {
			int flag = (c.mi - b.mi) / abs(c.mi - b.mi);
			for(; c.mi != b.mi; c.mi -= flag) {
				if(flag < 0) c.num /= 10;
				else c.num *= 10;
			}
		}
		c.num += b.num;
		c.relax();
		return c;
	}
	friend bd operator * (const bd &a, const bd &b) {
		bd c;
		c.num = a.num * b.num;
		c.mi = a.mi + b.mi;
		c.relax();
		return c;
	}
	friend bd operator / (const bd &a, const bd &b) {
		bd c;
		c.num = a.num / b.num;
		c.mi = a.mi - b.mi;
		c.relax();
		return c;
	}
};



int wa[maxn * 2],wb[maxn * 2],wv[maxn * 2],ws1[maxn * 2];
int cmp(int *r,int a,int b,int l)
{return r[a]==r[b]&&r[a+l]==r[b+l];}
void da(int *r,int *sa,int n,int m) {
	 int i,j,p,*x=wa,*y=wb,*t;
	 for(i=0;i<m;i++) ws1[i]=0;
	 for(i=0;i<n;i++) ws1[x[i]=r[i]]++;
	 for(i=1;i<m;i++) ws1[i]+=ws1[i-1];
	 for(i=n-1;i>=0;i--) sa[--ws1[x[i]]]=i;
	 for(j=1,p=1;p<=n;j*=2,m=p) {
	   for(p=0,i=n-j;i<n;i++) y[p++]=i;
	   for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
	   for(i=0;i<n;i++) wv[i]=x[y[i]];
	   for(i=0;i<m;i++) ws1[i]=0;
	   for(i=0;i<n;i++) ws1[wv[i]]++;
	   for(i=1;i<m;i++) ws1[i]+=ws1[i-1];
	   for(i=n-1;i>=0;i--) sa[--ws1[wv[i]]]=y[i];
	   for(t=x,x=y,y=t,p=2,x[sa[0]]=1,i=1;i<n;i++)
	   x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	 }
	 return;
}
void calheight(int *r, int *sa, int*rank, int*height,int n) {
	 int i,j,k=0;
	 for(i=0; i<n;i++) rank[sa[i]]=i;
	 for(i=0;i<n;i++){
		 if(rank[i] == 0) continue;
		 for(k?k--:0,j=sa[rank[i]-1]; i + k < n && j + k < n && r[i+k]==r[j+k];k++);
		 height[rank[i] - 1]=k;
	 }
	 return;
}
int d[20];
int logg[maxn];
int st[maxn][22];


void id4(const int &n, int *h) {
	int i, j;
	for( d[0]=1, i=1; i < 21; ++i ) d[i] = 2*d[i-1];
	for( i=0; i < n; ++i ) st[i][0] = h[i];
	int k = int( log(double(n))/log(2) ) + 1;
	logg[0] = 0; logg[1] = 0;
	for(int i = 2; i <= n; i++) logg[i] = logg[i / 2] + 1;
	for( j=1; j < k; ++j )
		for( i=0; i < n; ++i ) {
			if( i+d[j-1]-1 < n ){
				st[i][j] = min(st[i][j-1],
						st[i+d[j-1]][j-1]);
			}
			else break; 

		}
}


inline int quelcp(int x, int y) {
	int k = logg[y - x + 1];
	return min(st[x][k], st[y-d[k]+1][k]);
}


inline int id1(int x, int y) {
	if(y < x) swap(x, y);
	y--;
	int k = logg[y - x + 1];
	return min(st[x][k], st[y-d[k]+1][k]);
}


inline pii querange(int no, int height, int l) {
	int be1 = 0, en1 = no - 1;
	while(be1 < en1) {
		int height1 = (be1 + en1) / 2;
		if(quelcp(height1, no - 1) < height) be1 = height1 + 1;
		else en1 = height1;
	}
	if(quelcp(be1, no - 1) < height) be1++;
	int from = min1(be1, no);
	be1 = no; en1 = l - 1;
	while(be1 < en1) {
		int height1 = (be1 + en1 + 1) / 2;
		if(quelcp(no, height1) < height) en1 = height1 - 1;
		else be1 = height1;
	}
	if(quelcp(no, be1) < height) be1--;
	int to = max1(be1 + 1, no);
	return mpr(from, to);
}

const int mod = MOD;
char orig[maxn];
int str[maxn], rk[maxn], h[maxn], l, sa[maxn];
int dp[maxn / 2][maxn / 2], rdp[maxn / 2][maxn / 2];
ll sum[maxn], mi[maxn];
bd rsum[maxn], rmi[maxn];

ll getnum(int i, int j) {
	if(i == 0) return sum[j];
	ll ans = sum[j] - mi[j - i + 1] * sum[i - 1] % mod;
	if(ans < 0) ans += mod;
	return ans;
}
bd id3(int i, int j) {
	if(i == 0) return rsum[j];
	bd ans = rsum[j] - mi[j - i + 1] * rsum[i - 1];
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	

	freopen("input.txt", "r", stdin);
	int id0 = 256 << 20; 

	char *__p__ = (char*)malloc(id0) + id0;
	__asm__("movl %0, %%esp\n" :: "r"(__p__));
	

	scanf("%s", orig);
	l = strlen(orig);
	for(int i = 0; i < l; i++) str[i] = orig[i] - '0' + 2;
	da(str, sa, l, 5);
	calheight(str, sa, rk, h, l);
	id4(l, h);
	mi[0] = 1; sum[0] = str[0] - 2;
	rmi[0] = bd(1); rsum[0] = bd(str[0] - 2);
	for(int i = 1; i < maxn; i++) {
		mi[i] = mi[i - 1] * 2 % mod;
		sum[i] = sum[i - 1] * 2 + str[i] - 2;
		sum[i] %= mod;
		rmi[i] = rmi[i - 1] * 2;
		rsum[i] = rsum[i - 1] * 2 + bd(str[i] - 2);
	}

	memset(rdp, 0x3f, sizeof(rdp));
	for(int i = 1; i <= l; i++) {
		dp[i][0] = 1;
		rdp[i][0] = 1;
	}

	for(int i = 1; i < l; i++) if(str[i] == 3){
		int temp[maxn], rtemp[maxn];
		memset(rtemp, 0x3f, sizeof(rtemp));
		memset(temp, 0, sizeof(temp));
		for(int j = 0; j < i; j++) if(str[j] == 3){
			int be = i + (i - j);
			if(id1(rk[j], rk[i]) < i - j && rk[j] > rk[i])
				be++;
			if(be <= l) {
				temp[be] += dp[i][j];
				rtemp[be] = min(rtemp[be], rdp[i][j] + 1);
			}
		}
		for(int j = i + 1, sum = 0; j <= l; j++) {
			add(sum, temp[j]);
			rtemp[j] = min(rtemp[j - 1], rtemp[j]);
			add(dp[j][i], sum);
			rdp[j][i] = min(rtemp[j], rdp[j][i]);
		}
	}
	ll ans1 = 0, ansp = MOD;
	for(int i = 0; i < l; i++) add(ans1, dp[l][i]);
	printf("%I64d\n", ans1);
	for(int i = l - 1; i >= l - 20; i--) if(rdp[l][i] <= l) {
		int p = getnum(i, l - 1);
		add(p, rdp[l][i]);
		ansp = min(ansp, 1ll * p);
	}
	if(ansp == MOD) {
		for(int i = l - 21; i >= 0; i--) if(rdp[l][i] <= l) {
			int p = getnum(i, l - 1);
			add(p, rdp[l][i]);
			ansp = min(ansp, 1ll * p);
			break;
		}
	}
	printf("%I64d\n", ansp);

    return 0;
}

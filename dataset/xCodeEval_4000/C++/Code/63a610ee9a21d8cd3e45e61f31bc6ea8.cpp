#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<cassert>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<vector>
#include<string>
#include<bitset>
#include<list>
#include<deque>
#include<stack>
#include<queue>
#include<set>
#include<map>


using namespace std;

#define tm ttttttt
#define j0 jjjjjjj
#define j1 jjjjjjjj
#define jn jjjjjjjjj
#define y0 yyyyyyy
#define y1 yyyyyyyy
#define yn yyyyyyyyy
#define arg aaaaaaa

#define Fin(f) freopen(f, "r", stdin)
#define Fout(f) freopen(f, "w", stdout)
#define SR() srand((unsigned)time(NULL))
#define random(m) ((rand() << 16 | rand()) % m) 

#define randomP(a, n) srand((unsigned)time(NULL)), random_shuffle(a, a + (n))
#define AS(a) assert(a)

#define all(a) a.begin(), a.end()
#define PB push_back
#define sq(x) ((x) * (x))
#define Sqrt(n) (int)round(sqrt((double)n))



#define Inter(v, a, n, b, m) v.resize(set_intersection(a, a + (n), b, b + (m), v.begin()) - v.begin())
#define SInter(v, a, n, b, m) v.resize((n) + (m)); sort(a, a + (n)); sort(b, b + (m)); Inter(v, a, n, b, m)
#define Union(v, a, n, b, m) v.resize(set_union(a, a + (n), b, b + (m), v.begin()) - v.begin());
#define SUnion(v, a, n, b, m) v.resize((n) + (m)); sort(a, a + (n)); sort(b, b + (m)); Union(v, a, n, b, m)
#define Diff(v, a, n, b, m) v.resize(set_difference(a, a + (n), b, b + (m), v.begin()) - v.begin())
#define SDiff(v, a, n, b, m) v.resize((n) + (m)); sort(a, a + (n)); sort(b, b + (m)); Diff(v, a, n, b, m)
#define Sym(v, a, n, b, m) v.resize(set_symmetric_difference(a, a + (n), b, b + (m) v.begin()) - v.begin())
#define SSym(v, a, n, b, m) v.resize((n) + (m)); sort(a, a + (n)); sort(b, b + (m)); Sym(v, a, n, b, m)

#define setInter(a, b, to) set_intersection(all(a), all(b), inserter(to, to.begin())) 

#define setUnion(a, b, to) set_union(all(a), all(b), inserter(to, to.begin())) 


#define Cnt1 __builtin_popcount 

#define LBpos(n) (31 - __builtin_clz(n))
#define LBposll(n) (63 - __builtin_clzll(n))
#define RBpos(n) (__builtin_ffs(n) - 1)
#define RBposll(n) (__builtin_ffsll(n) - 1)

#define For(i, n) for (i = 0; i < (n); ++i)


#define Forr(i, start, n) for (i = start; i < (n); ++i)
#define Forrr(i, start, n, step) for (i = start; i < (n); i += step)
#define rFor(i, n) for (i = (n); i >= 0; --i)
#define rForr(i, n, end) for (i = n; i >= (end); --i)
#define rForrr(i, n, end, step) for (i = n; i >= (end); i -= step)
#define loop(it, a) for (it = a.begin(); it != a.end(); ++it)
#define rloop(it, a) for (it = a.rbegin(); it != a.rend(); ++it)

#define SI(a) scanf("%d", &a)
#define SII(a, b) scanf("%d%d", &a, &b)
#define SIII(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define SIIII(a, b, c, d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define SIIIII(a, b, c, d, e) scanf("%d%d%d%d%d", &a, &b, &c, &d, &e)
#define SIIIIII(a, b, c, d, e, f) scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f)
#define SL(a) scanf("%I64d", &a)
#define SLL(a, b) scanf("%I64d%I64d", &a, &b)
#define SLLL(a, b, c) scanf("%I64d%I64d%I64d", &a, &b, &c)
#define SLLLL(a, b, c, d) scanf("%I64d%I64d%I64d%I64d", &a, &b, &c, &d)
#define SD(a) scanf("%lf", &a)
#define SDD(a, b) scanf("%lf%lf", &a, &b)
#define SDDD(a, b, c) scanf("%lf%lf%lf", &a, &b, &c)
#define SDDDD(a, b, c, d) scanf("%lf%lf%lf%lf", &a, &b, &c, &d)
#define SA(a, i, n) For(i, n) scanf("%d", a + i) 

#define SAA(a, i, n, j, m) For(i, n) For(j, m) SI(a[i][j]) 

#define SAA1(a, i, n, j, m) Forr(i, 1, n + 1) Forr(j, 1, m + 1) SI(a[i][j]) 

#define SS(s) scanf("%s", s)
#define SSS(s, s2) scanf("%s%s", s, s2)
#define SC(c) scanf(" %c", &c)
#define GC(c) (c = getchar())
#define Gn() getchar()
#define UC(c) ungetc(c, stdin)

#define PI(a) printf("%d\n", a)
#define PII(a, b) printf("%d %d\n", a, b)
#define PIII(a, b, c) printf("%d %d %d\n", a, b, c)
#define PIIII(a, b, c, d) printf("%d %d %d %d\n", a, b, c, d)
#define PIIIII(a, b, c, d, e) printf("%d %d %d %d %d\n", a, b, c, d, e)
#define PL(a) printf("%I64d\n", a)
#define PLL(a, b) printf("%I64d %I64d\n", a, b)
#define PLLL(a, b, c) printf("%I64d %I64d %I64d\n", a, b, c)
#define PD(a) printf("%f\n", a)
#define PDD(a, b) printf("%f %f\n", a, b)
#define PDDD(a, b, c) printf("%f %f %f\n", a, b, c)
#define PA(a, i, n) For(i, (n) - 1) printf("%d ", a[i]); PI(a[(n) - 1]) 

#define PAA(a, i, n, j, m) For(i, n) {For(j, (m) - 1) printf("%d ", a[i][j]); PI(a[i][(m) - 1]);}
#define PAn(a, i, n) For(i, n) PI(a[i])
#define rPA(a, i, n) rForr(i, n - 1, 1) printf("%d ", a[i]); PI(a[0]) 

#define rPAn(a, i, n) rFor(i, n - 1) PI(a[i])
#define PC(c) putchar(c)
#define Pn() putchar(10)
#define Ps() putchar(32)

#define Uni(a) a.resize(unique(all(a)) - a.begin()) 

#define SUni(a) sort(all(a)); Uni(a) 

#define Unii(a, n) (unique(a, a + (n)) - a)
#define SUnii(a, n) sort(a, a + n); Unii(a, n)
#define Acc(a, n) (accumulate(a, a + (n), 0)) 

#define Accv(a) (accumulate(all(a), 0)) 

#define AaddB(a, n, b) transform(a, a + (n), b, a, plus<int>()) 

#define mem(a, num) memset(a, num, sizeof(a))
#define cpy(to, from) memcpy(to, from, sizeof(from))
#define Rcpy(l, r, b) reverse_copy(l, r, b) 

#define kTo10(ans, str, s, m, k) strncpy(str, s, m), str[m] = 0, ans = strtol(str, NULL, k)

#define LE(T) less_equal<T>
#define GR(T) greater<T>
#define GE(T) greater_equal<T>
#define NET(T) not_equal_to<T>

#define nth(a, k, n) nth_element(a + 0, a + k, a + n) 

#define nthg(a, k, n) nth_element(a + 0, a + k, a + n, greater<int>()) 

#define Min(a, n) (*min_element(a, a + (n)))
#define Max(a, n) (*max_element(a, a + (n)))
#define Minpos(a, n) (min_element(a, a + (n)) - (a))
#define Maxpos(a, n) (max_element(a, a + (n)) - (a))
#define Lval(a, n, x) (*lower_bound(a, a + (n), x))
#define Uval(a, n, x) (*upper_bound(a, a + (n), x))
#define Lpos(a, n, x) (lower_bound(a, a + (n), x) - (a)) 

#define Upos(a, n, x) (upper_bound(a, a + (n), x) - (a)) 



#define Range(a, n, x) equal_range(a, a + (n), x) 

#define Fpos(a, n, x) (find(a, a + (n), x) - (a))
#define Fd(a, x) (a.find(x) != a.end())
#define Fdd(a, x) (find(all(a), x) != a.end())
template<class T> inline void Qmin(T &a, const T b) {if (b < a) a = b;}
template<class T> inline void Qmax(T &a, const T b) {if (a < b) a = b;} 

inline int Qceil(int x, int y) {return x ? (x - 1) / y + 1 : 0;} 


const int inf = 0x3f3f3f3f; 

const long long llinf = 0x3f3f3f3f3f3f3f3fLL; 

const double pi = acos(-1.0);


































#define _set() cout.precision(15)

#define _unset() cout.unsetf(ios::floatfield)

#define DI(a) _set(), printf(#a" = "), cout << (a) << endl, _unset()
#define DII(a, b) _set(), printf(#a" = "), cout << (a), printf(", "#b" = "), cout << (b) << endl, _unset()
#define DIII(a, b, c) _set(), printf(#a" = "), cout << (a), printf(", "#b" = "), cout << (b), printf(", "#c" = "), cout << (c) << endl, _unset()
#define DIIII(a, b, c, d) _set(), printf(#a" = "), cout << (a), printf(", "#b" = "), cout << (b), printf(", "#c" = "), cout << (c), printf(", "#d" = "), cout << (d) << endl, _unset()
#define DA(a, i, n) For(i, n) printf(#a"[%2d] = ", i), cout << a[i] << endl
#define DAA(a, i, n, j, m) For(i, n) For(j, m) printf(#a"[%2d][%2d] = ", i, j), cout << a[i][j] << endl



typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p2;
typedef pair<pair<int, int>, int> p3;
typedef pair<int, pair<int, int> > pi3;
typedef vector<int>::iterator viter;
typedef set<int>::iterator siter;
typedef map<int, int>::iterator miter;
typedef multiset<int>::iterator msiter;
typedef multimap<int, int>::iterator mmter;
typedef priority_queue<int> pqi;
typedef priority_queue<int, vector<int>, greater<int> > spqi; 

#define MT(a, b, c) p3(p2(a, b), c)

































#define TT int tttt; scanf("%d%*c", &tttt); while(tttt--) 

#define Pcas() printf("Case %d: ", ++cas) 

int cas;

typedef long long ll;
const int mx = 1e5 + 5;
int a[mx];
set<int> pos[18];
set<int>::iterator low, up;
ll sum[18];

void one(int p, int v)
{
	pos[p].erase(v);
	low = up = pos[p].upper_bound(v);
	sum[p] += ll(v - *--low) * (*up - v);
}

void zero(int p, int v)
{
	low = up = pos[p].upper_bound(v);
	sum[p] -= ll(v - *--low) * (*up - v);
	pos[p].insert(v);
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < 18; i++) for (int j = 0; j <= n + 1; j++) pos[i].insert(j);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < 18; i++) for (int j = 0; j <= n + 1; j++) if (a[j] >> i & 1) one(i, j);
	while (m--)
	{
		int p, v;
		scanf("%d%d", &p, &v);
		for (int i = 0; i < 18; i++)
		{
			if (v >> i & 1) {if (pos[i].count(p)) one(i, p);} 

			else if (!pos[i].count(p)) zero(i, p); 

		}
		ll ans = 0;
		for (int i = 0; i < 18; i++) ans += sum[i] * (1 << i);
		printf("%I64d\n", ans);
	}
	return 0;
}

#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <deque>
#include <string>
#include <stack>
#include <algorithm>
#include <utility>
#include <math.h>
#include <ctime>

using namespace std;
typedef long long int63;
typedef unsigned long long int64;
#define forl(name,start,end,jump) for(int63 name = start; name < end; name+=jump)
#define forlb(name,start,end,jump) for(int63 name = end - 1; name >= start; name+=jump)
#define forn(name,start,end) forl(name,start,end,1)
#define fornb(name,start,end) forlb(name,start,end,-1)
#define fort(start,end) forn(i,start,end)
#define fortb(start,end) fornb(i,start,end)
#define forto(start,end) forn(j,start,end)
#define fortob(start,end) fornb(j,start,end)
#define fortoo(start,end) forn(l,start,end)
#define all(vec) vec.begin(),vec.end()
#define rall(vec) vec.rbegin(),vec.rend()
#define makeitem(itemname,itemtype) itemtype itemname; cin >> itemname
#define makeint(intname) int63 intname; cin >> intname
#define makeN int63 n; cin >> n
#define makeM int63 m; cin >> m
#define makeL int63 l; cin >> l
#define makeT int63 t; cin >> t
#define makeK int63 k; cin >> k
#define point pair<int63,int63>
#define dpoint pair<double,double>
#define ldpoint pair<long double,long double>
#define spoint pair<short,short>
#define ipoint pair<int,int>
#define matrix(type) vector<vector<type>>
#define in(name) cin >> name;
#define tosort(name) name.begin(),name.end()
int63 powmod(int63 base, int63 exponent, int63 mod) {
	int63 result = 1;
	while (exponent > 0) {
		if (exponent % 2 == 0) {
			exponent /= 2;
			base = (base * base) % mod;
		}
		else {
			result = (result * base) % mod;
			exponent /= 2;
			base = (base * base) % mod;
		}
	}
	return result;
}
bool decresing(int63 x, int63 y) {
	return x > y;
}
int63 modInverse(int63 a, int63 b) {

	int63 m = b;
	int63 y = 0, x = 1;
	while (a > 1) {
		int63 q = a / m;
		int63 t = m;
		m = a % m, a = t;
		t = y;
		y = x - q * y;
		x = t;
	}
	if (x < 0) {
		x += b;
	}
	return x;
}
int63 trin(int63 start, int63 stop) {
	return (stop - start + 1) * (stop + start) / 2;
}
int63 trin2(int63 start, int63 stop, int63 mod) {
	return (((((stop - start + 1) % mod) * ((stop + start) % mod)) % mod)*modInverse(2, mod) % mod) % mod;
}
int63 trig(int63 start, int63 stop, int63 jump, int63 mod) {
	return ((trin2((start + jump - 1) / jump, stop / jump, mod)) * (jump%mod)) % mod;
}
int63 cntot(int63 start, int63 stop, int63 jump, int63 mod) {
	return (stop / jump - (start + jump - 1) / jump + 1) % mod;
}

bool sortvectorf(point a, point b) {
	return((a.first > b.first) || (a.first == b.first && a.second > b.second));
}

bool sortvectordiv(point a, point b) {

	return a.first * b.second > b.first * a.second;
}

bool sortvectorfv(point a, point b) {
	return((a.first > b.first) || (a.first == b.first && a.second < b.second));
}

bool sortvectors(point a, point b) {
	return((a.second > b.second) || (a.second == b.second && a.first > b.first));
}

bool negasortvectorf(point a, point b) {
	return((a.first < b.first) || (a.first == b.first && a.second < b.second));
}

bool negasortvectors(point a, point b) {
	return((a.second < b.second) || (a.second == b.second && a.first < b.first));
}

vector<vector<int63>> findPermutationsI(vector<int63> &a) {

	

	sort(a.begin(), a.end());
	vector<vector<int63> > sol;
	

	do {
		sol.push_back(a);
	} while (next_permutation(a.begin(), a.end()));
	return sol;
}

vector<vector<string>> findPermutationsS(vector<string> &a) {

	

	sort(a.begin(), a.end());
	vector<vector<string> > sol;
	

	do {
		sol.push_back(a);
	} while (next_permutation(a.begin(), a.end()));
	return sol;
}

int63 gcd(int63 a, int63 b) {
	if (a == 0) {
		return b;
	}
	if (b == 0) {
		return a;
	}
	return gcd(b % a, a);
}

bool isprime(int63 n) {
	fort(2, n) {
		if (i * i > n) {
			break;
		}
		if ((n / i) * i == n) {
			return false;
		}
	}
	return true;
}

int63 fdivisor(int63 n, int63 fro) {
	fort(1, n + 1) {
		if ((n / i) * i == n && i >= fro) {
			return i;
		}
	}
	return -1;
}

vector<int63> divlist(int63 n) {
	vector<int63> curr;
	fort(1, n + 1) {
		if ((int63)i * i > n) {
			break;
		}
		if ((n / i) * i == n) {
			curr.push_back(i);
			curr.push_back(n / i);
		}
		if ((int63)i * i == n) {
			curr.pop_back();
		}
	}

	sort(all(curr));
	return curr;
}
vector<int63> pdivlist(int63 n) {
	vector<int63> curr;
	fort(2, n + 1) {
		if (i * i > n) {
			break;
		}
		if ((n % i) == 0) {
			if (isprime(i)) { curr.push_back(i); }
			int63 ni = n / i;
			if (isprime(ni)) { curr.push_back(ni); }
			if (i * i == n && isprime(i)) {
				curr.pop_back();
			}
			if (isprime(i)) {
				while ((n % i) == 0) {
					n /= i;
				}
			}
			if (isprime(ni)) {
				while ((n % ni) == 0) {
					n /= ni;
				}
			}
		}
		if (i % 2) {
			i++;
		}
	}
	if (n > 1 && (curr.size() == 0 || curr[curr.size()-1] != n) && isprime(n)) {
		curr.push_back(n);
	}
	sort(all(curr));
	return curr;
}
int63 countdivisors(int63 n, int63 divd, int63 rem) {
	vector<int63> divs = divlist(n);
	int63 tot = 0;
	fort(0, (int63)divs.size()) {
		if (divs[i] % divd == rem) {
			tot++;
		}
	}
	if (n % divd == rem) {
		tot++;
	}
	return tot;
}
int63 digsum(int63 num) {
	int63 cr = 0;
	while (num > 0) {
		cr += num % 10;
		num /= 10;
	}
	return cr;
}
vector<int63>atzeret;
int63 azeret(int63 num, int63 mod) {
	if (mod == 1000000007) {
		if ((int63)atzeret.size() > num) {
			return atzeret[num];
		}
		if (num == 0) {
			atzeret.push_back(1);
			return atzeret[num];
		}
		azeret(num - 1, mod);
		atzeret.push_back((atzeret[num-1] * num) % mod);
		return atzeret[num];
	}
	int63 sil = 1;
	while (num > 1) {
		sil *= num;
		sil %= mod;
		num--;
	}
	return sil;
}
int63 moddiv(int63 to, int63 by, int63 mod) {
	to %= mod;
	by %= mod;
	to *= modInverse(by, mod);
	return to % mod;
}
int63 choose(int63 num, int63 choice, int63 mod) {
	if (choice < 0 || choice > num) {
		return 0;
	}
	return moddiv(azeret(num, mod), (azeret(choice, mod)*azeret(num - choice, mod)) % mod, mod);
}
class node {
public:
	int data1;
	int data2;
	node* nxt;
	node* bef;
	node(int dat1, int dat2, node*bif) {
		this->nxt = NULL;
		this->bef = bif;
		this->bef->nxt = this;
		this->data1 = dat1;
		this->data2 = dat2;
	}
	node(int dat1, int dat2) {
		this->nxt = NULL;
		this->bef = NULL;
		this->data1 = dat1;
		this->data2 = dat2;
	}
	node() {
		this->nxt = NULL;
		this->bef = NULL;
		this->data1 = 0;
		this->data2 = 0;
	}
	void remove() {
		this->bef->nxt = this->nxt;
		if (this->nxt != NULL) {
			this->nxt->bef = this->bef;
		}
	}
	void push(int dat1, int dat2) {
		node* next = this->nxt;
		node* curr = new node(dat1, dat2, this);
		curr->nxt = next;
		next->bef = curr;
	}
};
bool by_first(pair<point, point> a, pair<point, point> b) {
	return a.first.first < b.first.first;
}
bool ff_fs(pair<pair<int63, bool>, int63> a, pair<pair<int63, bool>, int63> b) {
	return a.first.first < b.first.first || (a.first.first == b.first.first && a.first.second && !b.first.second);
}
bool f_s_b(pair<int63, int63> a, pair<int63, int63> b) {
	return a.first > b.first || (a.first == b.first && a.second > b.second);
}
#define make(name) int63 name; cin >> name

bool palindrome(string s) {
	fort(0, (int63)s.size() / 2) {
		if (s[i] != s[s.size() - 1 - i]) {
			return 0;
		}
	}
	return 1;
}
struct union_find {
	vector<int63>rot;
	vector<vector<int63>> rat;
	void init(int63 n) {
		fort(0, n) {
			rot.push_back(i);
			rat.push_back({ i });
		}
	}
	bool unio(int63 f, int63 s) {
		if (rot[f] == rot[s]) {
			return false;
		}
		

		if (rat[rot[f]].size() > rat[rot[s]].size()) {
			

			int63 siz = rat[rot[s]].size();
			int63 rs = rot[s];
			fort(0, siz) {
				rat[rot[f]].push_back(rat[rs][i]);
				rot[rat[rs][i]] = rot[f];
			}
			return true;
		}
		int63 siz = rat[rot[f]].size();
		int63 rf = rot[f];
		fort(0, siz) {
			rat[rot[s]].push_back(rat[rf][i]);
			rot[rat[rf][i]] = rot[s];
		}
		return true;
	}
};


vector<int> subsum(vector<int> items, int limit) {
	vector<vector<int> > table(items.size() + 1, vector<int>(limit + 1));
	forto(1, (int63)items.size() + 1) {
		int wt = items[j - 1];
		int val = wt;
		for (int w = 1; w < limit + 1; w++) {
			if (wt > w) {
				table[j][w] = table[j - 1][w];
			}
			else {
				table[j][w] = max(table[j - 1][w], (int)(table[j - 1][w - wt] + val));
			}
		}
	}
	vector<int> result;
	int w = limit;
	for (int j = items.size(); j > 0; j--) {
		bool was_added = table[j][w] != table[j - 1][w];
		if (was_added) {
			int wt = items[j - 1];
			result.push_back(j - 1);
			w -= wt;
		}
	}
	sort(all(result));
	return result;
}
bool func(pair<point, int63>a, pair<point, int63>b) {
	return a.first.second < b.first.second || (a.first.second == b.first.second && a.first.first > b.first.first);
}
int63 detrig(int63 num) {
	int63 minus = 0;
	while (true) {
		if (num <= 0) {
			return minus;
		}
		minus++;
		num -= minus;
	}
}
int63 palpref(string &s) {
	int63 ha1 = 0, ha2 = 0, hr1 = 0, hr2 = 0;
	int63 m1 = 1, m2 = 1;
	int63 mix = 0;
	forto(0, s.size()) {
		ha1 = (ha1 + m1 * s[j]) % 1000000007;
		ha2 = (ha2 + m2 * s[j]) % 998244353;

		hr1 = (s[j] + 359 * hr1) % 1000000007;
		hr2 = (s[j] + 401 * hr2) % 998244353;

		m1 *= 359, m1 %= 1000000007;
		m2 *= 401, m2 %= 998244353;

		if (ha1 == hr1 && ha2 == hr2) {
			mix = j + 1;
		}
	}
	return mix;
}
double diffclock(clock_t clock1, clock_t clock2)
{
	double diffticks = clock1 - clock2;
	double diffms = (diffticks) / (CLOCKS_PER_SEC / 1000);
	return diffms;
}

struct fenwick {
	int63 n;
	vector<int63> data;
	vector<int63> real;
	void init(int63 n) {
		this->n = n;
		data.resize(n);
		real.resize(n);
	}
	void add(int63 pos, int63 val) {
		real[pos] += val;
		pos++;
		int63 cur = 0;
		while (pos << cur <= this->n) {
			if (pos % 2 == 1) {
				this->data[(pos << cur) - 1] += val;
			}
			cur++;
			pos = (pos + 1) / 2;
		}
	}
	void upd(int63 pos, int63 val) {
		add(pos, val - real[pos]);
	}
	int63 query0(int63 a) {
		int63 sol = 0;
		int63 cur = 0;
		a++;
		while (a) {
			if (a % 2 == 1) {
				sol += this->data[(a << cur) - 1];
			}
			cur++;
			a /= 2;
		}
		return sol;
	}
	int63 query(int63 a, int63 b) {
		return query0(b) - query0(a - 1);
	}
};
void setIO(string s) { 

	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

bool isleft(point a, point b, point c) {

	if (a.first == b.first) {
		return (c.first < a.first) ^ (a.second > b.second);
	}
	long double m = (b.second - a.second) / ((double)b.first - a.first);
	long double y = a.second - a.first * m;
	return (c.second - y - c.first * m > 0) ^ (a.first > b.first);
}

bool online(point a, point b, point c) {

	if (a.first == b.first) {
		return (a.first == c.first);
	}
	long double m = (b.second - a.second) / ((double)b.first - a.first);
	long double y = a.second - a.first * m;
	long double cy = abs(c.second - y - c.first * m);
	return abs(cy) < 1e-11;
}
bool linein(point a, point b, point c) {

	b.first -= a.first;
	c.first -= a.first;
	a.first = 0;
	b.second -= a.second;
	c.second -= a.second;
	a.second = 0;
	if (b.second < 0) {
		b.second *= -1;
		c.second *= -1;
	}
	if (b.first < 0) {
		b.first *= -1;
		c.first *= -1;
	}
	if (b.first == 0) {
		return ((c.first == 0) && (c.second >= 0) && (c.second <= b.second));
	}
	long double m = (b.second - a.second) / ((double)b.first - a.first);
	long double cy = abs(c.second - c.first * m);
	return ((abs(cy) < 1e-11) && (c.first >= 0) && (c.first <= b.first));
}
bool interhelp(point a, point b, point c, point d) {
	if (online(a, b, c) || online(a, b, d)) {
		return 1;
	}
	return (isleft(a, b, c) ^ isleft(a, b, d));
}
bool intersect(ldpoint a, ldpoint b, ldpoint c, ldpoint d) {
	if (online(a, b, c) && online(a, b, d)) {
		b.first -= a.first;
		c.first -= a.first;
		d.first -= a.first;
		a.first = 0;
		b.second -= a.second;
		c.second -= a.second;
		d.second -= a.second;
		a.second = 0;
		if (b.first == 0) {
			if (b.second < 0) {
				b.second *= -1;
				c.second *= -1;
				d.second *= -1;
			}
			if (d.second > c.second) {
				swap(c, d);
			}
			return (c.second >= 0 && d.second <= b.second);
		}
		b.second /= b.first;
		c.second /= b.first;
		d.second /= b.first;
		c.first /= b.first;
		d.first /= b.first;
		b.first = 1;
		c.second -= c.first * b.second;
		d.second -= d.first * b.second;
		b.second = 0;
		if (d.first > c.first) {
			swap(c, d);
		}
		return (c.first >= -1e-11 && d.first <= 1e-11);
	}
	return (interhelp(a, b, c, d) && interhelp(c, d, a, b));
}
void format(bool yes) {
	if (yes) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}
point mi(point a, point b) {
	return { a.first - b.first,a.second - b.second };
}
int63 vci(point a, point b) {
	return abs(a.first*b.second - a.second*b.first);
}
int63 ar(point a, point b, point c) {
	point bb = mi(b, a), cc = mi(c, a);
	return vci(bb, cc);
}
bool intriangle(point a, point b, point c, point d) {
	return ((ar(a, b, c) + ar(a, b, d) + ar(a, c, d)) == ar(b, c, d));
}
int63 countlattice(point a, point b) {
	b.first -= a.first;
	b.second -= a.second;
	a.first = 0;
	a.second = 0;
	b.first = abs(b.first);
	b.second = abs(b.second);
	if (b.first == 0) {
		return b.second;
	}
	vector<int63> ops = divlist(b.first);
	fort(0, (int63)ops.size()) {
		if ((b.second * ops[i] % b.first) == 0) {
			return b.first / ops[i];
		}
	}
	return 0;
}

struct Line {
	mutable int63 m, b, p;
	const bool real;

	bool operator<(const Line& o) const { if (real && o.real) { return (m < o.m); } else { return p < o.p; } };
};

struct cht : multiset<Line, less<Line>> {
	

	const int63 inf = 9223372036854775807;
	int63 div(int63 a, int63 b) { 

		return a / b - ((a ^ b) < 0 && a % b);
	}
	

	

	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->m == y->m) x->p = x->b > y->b ? inf : -inf;
		else x->p = div(y->b - x->b, x->m - y->m);
		return x->p >= y->p;
	}
	

	

	void add(int63 b, int63 m) {
		auto z = insert({ m, b, 0, 1 }), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
	}
	void init() {
		add(-9999999999999999, 0);
	}
	int63 query(int63 x) {
		if (empty()) exit(1);
		auto l = *(lower_bound({ 0, 0, x, 0 }));
		return l.m * x + l.b ;
	}
};


int63 t = 1;

int main() {
	

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand(time(NULL));
	if (t == 0) {
		cin >> t;
	}
	do {
		
		
		
		int63 n;
		cin >> n;
		vector<point>vp(n);
		fort(0, n) {
			cin >> vp[i].first;
			vp[i].second = i + 1;
		}
		sort(all(vp));
		

		vector<pair<int63, point>>qs;
		int63 a1 = 0, a2 = 0;
		fort(0, ((int63)(vp.size())) - 1) {
			forto(i + 1, vp.size()) {
				qs.push_back({ vp[j].first - vp[i].first, {vp[j].second,vp[i].second} });
			}
		}
		sort(rall(qs));
		fort(0, qs.size()) {
			cout << "? " << qs[i].second.first << ' ' << qs[i].second.second << endl;
			string ans;
			cin >> ans;
			if (ans == "Yes") {
				a1 = qs[i].second.first;
				a2 = qs[i].second.second;
				break;
			}
		}
		cout << "! " << a1 << ' ' << a2 << endl;
	} while (--t);
	return 0;
}
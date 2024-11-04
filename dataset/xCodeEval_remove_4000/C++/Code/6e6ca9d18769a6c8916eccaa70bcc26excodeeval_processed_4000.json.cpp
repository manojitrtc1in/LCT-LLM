






































using namespace std;
using ll = long long int;
using ull = unsigned long long;





double __begin;


















template<class T> inline string tostr(const T & x)
{
	stringstream ss; ss << x; return ss.str();
}


inline ll parse(const string & s)
{
	stringstream ss(s); ll x; ss >> x; return x;
}


template <typename T>
vector<size_t> sort_indexes(const vector<T> &v) {

	

	vector<size_t> idx(v.size());
	for (size_t i = 0; i != idx.size(); ++i) idx[i] = i;

	

	sort(idx.begin(), idx.end(),
		[&v](size_t i1, size_t i2) {return v[i1] < v[i2]; });

	return idx;
}


int gcd(int n1, int n2) {
	return (n2 == 0) ? n1 : gcd(n2, n1 % n2);
}


inline int popcount(int i)
{
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}
inline int popcount(ll v) { int t = v >> 32; int p = (v & ((1LL << 32) - 1)); return popcount(t) + popcount(p); }


unsigned int reverse_bits(register unsigned int x) { x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }


inline int sign(int x) { return x > 0; }


inline bool id3(int x) { return (x != 0 && (x&(x - 1)) == 0); }


inline int id5(int x)
{
	x = x | (x >> 1);
	x = x | (x >> 2);
	x = x | (x >> 4);
	x = x | (x >> 8);
	x = x | (x >> 16);
	return x - (x >> 1);
}








string id2(int number)
{
	if (number == 0) return "0";
	if (number == 1) return "1";

	if (number % 2 == 0)
		return id2(number / 2) + "0";
	else
		return id2(number / 2) + "1";
}


long long int fact(int a)
{
	long long	int p = 1;
	while (a >= 1)
	{
		p = p*a;
		a--;
	}

	return p;
}


ull cnr(int n, int r)
{
	ull ans = 1;
	r = std::min(r, n - r);

	for (int j = 1; j <= r; j++, n--) {
		

		

		


		if (n % j == 0) {
			ans *= n / j;
		}
		else if (ans % j == 0) {
			ans = (ans / j) * n;
		}
		else {
			ans = (ans * n) / j;
		}
	}
	return ans;
}


vector<ll> lucky;

void make(ll num) {
	if (MAX < num) return;
	lucky.push_back(num);
	make(num * 10 + 4);
	make(num * 10 + 7);
}


bool prime[1000000]{ 1,1 };
void sieve() {
	for (int i = 2; i * i <= 1000000; i++)
		if (!prime[i]) {
			for (int j = i * i; j <= 1000000; j += i) prime[j] = 1;
		}
}


vector<int> id7(int number)
{
	vector<int>d;
	for (int i = 1; i <= sqrt(number); i++)
	{
		if (number % i == 0)
		{
			d.push_back(i);
			if (i != (number / i))
			{
				d.push_back(number / i);
			}
		}
	}
	return d;
}


bool id13(string s, int num)
{
	int ret = 0;
	for (int i = 0; i < static_cast<int>(s.length()); i++)
		ret = (10 * ret + s[i] - '0') % num;
	return ret == 0;
}


template<typename T>
vector<T> rv(T n)
{
	vector<T>v(n);
	for (auto &i : v)
		cin >> i;
	return v;
}


std::vector<std::string> split(const std::string &text, string sep) {
	std::vector<std::string> tokens;
	int start = 0, end = 0;
	while ((end = text.find(sep, start)) != std::string::npos) {
		tokens.push_back(text.substr(start, end - start));
		start = end + sep.size();
	}
	tokens.push_back(text.substr(start));
	return tokens;
}


int Primes[25] =
{ 2, 3, 5, 7, 11, 13, 17, 19, 23,
29, 31, 37, 41, 43, 47, 53, 59,
61, 67, 71, 73, 79, 83, 89, 97 };
const int _startNum = 101;
bool IsPrime(ll Num)
{
	int j;
	bool ret;
	ll _upMargin = (ll)sqrt(Num) + 1;
	for (int i = 0; i < 25; i++)
	{
		if (Num == Primes[i]) { return true; }
	}
	for (int i = 0; i < 25; i++)
	{
		if (Num % Primes[i] == 0) return false;
	}
	_upMargin = (ll)sqrt(Num) + 1;
	j = _startNum;
	ret = true;
	while (j <= _upMargin)
	{
		if (Num % j == 0) { ret = false; break; }
		else { j = j + 2; }
	}
	return ret;
}
set<ll> id8(ll Num)
{
	set<ll> _arrFactors;
	ll _num = Num;
	for (int k = 0; k < 25; k++)
	{
		if (_num == Primes[k])
		{
			_arrFactors.insert(Primes[k]);
			return _arrFactors;
		}
	}
	for (int k = 0; k < 25; k++)
	{
		int m = Primes[k];
		if (_num < m) break;
		while (_num % m == 0)
		{
			_arrFactors.insert(m);
			_num = (ll)_num / m;
		}
	}
	

	

	

	

	

	if (_num < _startNum)
		return _arrFactors;
	ll _upMargin = (ll)sqrt(_num) + 1;
	ll i = _startNum;
	while (i <= _upMargin)
	{
		if (_num % i == 0)
		{
			_arrFactors.insert(i);
			_num = _num / i;
			_upMargin = (ll)sqrt(_num) + 1;
			i = _startNum;
		}
		else { i = i + 2; }
	}
	_arrFactors.insert(_num);
	

	return _arrFactors;
}

int n, m, a, u, v, compatible;
map<int, int>itemPrices;


bool paired[111][111];
vector<bool> combination{};
vector<int>triplet, prices;
multimap<int, int>::iterator it;


inline void id1(string& st, char to_replace, char replace_with)
{
	std::replace(st.begin(), st.end(), to_replace, replace_with);
}


inline void id4(string& st, char to_remove)
{
	st.erase(remove(st.begin(), st.end(), to_remove), st.end());
}


void id14(int n)
{
	int a[400], count, t, i, var, x;
	count = 0;
	t = n;
	while (t > 0)
	{
		a[count++] = t % 10;
		t /= 10;
	}
	for (i = 2; i < n; i++)
	{
		t = 0;
		var = 0;
		while (var < count)
		{
			x = a[var] * i + t;
			a[var] = x % 10;
			t = x / 10;
			var++;
		}
		while (t > 0)
		{
			a[count++] = t % 10;
			t /= 10;
		}
	}
	for (i = count - 1; i >= 0; i--)
		printf("%d", a[i]);
	printf("\n");
}


const double eps = 1e-11;

template<class T> inline T sqr(T x) { return x*x; }

double dist(double x1, double y1, double x2, double y2) { return sqrt(sqr(x1 - x2) + sqr(y1 - y2)); }

double distR(double x1, double y1, double x2, double y2) { return sqr(x1 - x2) + sqr(y1 - y2); }

template<class T> T cross(T x0, T y0, T x1, T y1, T x2, T y2) { return (x1 - x0)*(y2 - y0) - (x2 - x0)*(y1 - y0); }

bool isMiddle(double s, double m, double t) { return fabs(s - m) <= eps || fabs(t - m) <= eps || (s < m) != (t < m); }

bool id12(char c) { return c >= 'A' && c <= 'Z'; }

bool id17(char c) { return c >= 'a' && c <= 'z'; }

bool isLetter(char c) { return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }

bool isDigit(char c) { return c >= '0' && c <= '9'; }

char id9(char c) { return (id12(c)) ? (c + 32) : c; }

char id11(char c) { return (id17(c)) ? (c - 32) : c; }

template<class T> string toString(T n) { ostringstream ost; ost << n; ost.flush(); return ost.str(); }

int toInt(string s) { int r = 0; istringstream sin(s); sin >> r; return r; }

ll id0(string s) { ll r = 0; istringstream sin(s); sin >> r; return r; }

double toDouble(string s) { double r = 0; istringstream sin(s); sin >> r; return r; }

template<class T> void stoa(string s, int &n, T A[]) { n = 0; istringstream sin(s); for (T v; sin >> v; A[n++] = v); }

template<class T> void atos(int n, T A[], string &s) { ostringstream sout; for (int i = 0; i < n; i++) { if (i>0)sout << ' '; sout << A[i]; }s = sout.str(); }

template<class T> void atov(int n, T A[], vector<T> &vi) { vi.clear(); for (int i = 0; i < n; i++) vi.push_back(A[i]); }

template<class T> void vtoa(vector<T> vi, int &n, T A[]) { n = vi.size(); for (int i = 0; i < n; i++)A[i] = vi[i]; }

template<class T> void stov(string s, vector<T> &vi) { vi.clear(); istringstream sin(s); for (T v; sin >> v; vi.push_bakc(v)); }

template<class T> void vtos(vector<T> vi, string &s) { ostringstream sout; for (int i = 0; i < vi.size(); i++) { if (i>0)sout << ' '; sout << vi[i]; }s = sout.str(); }

																																									 

template<class T> struct Fraction { T a, b; Fraction(T a = 0, T b = 1); string toString(); };

template<class T> Fraction<T>::Fraction(T a, T b) { T d = gcd(a, b); a /= d; b /= d; if (b < 0) a = -a, b = -b; this->a = a; this->b = b; }
template<class T> string Fraction<T>::toString() { ostringstream sout; sout << a << "/" << b; return sout.str(); }
template<class T> Fraction<T> operator+(Fraction<T> p, Fraction<T> q) { return Fraction<T>(p.a*q.b + q.a*p.b, p.b*q.b); }
template<class T> Fraction<T> operator-(Fraction<T> p, Fraction<T> q) { return Fraction<T>(p.a*q.b - q.a*p.b, p.b*q.b); }
template<class T> Fraction<T> operator*(Fraction<T> p, Fraction<T> q) { return Fraction<T>(p.a*q.a, p.b*q.b); }
template<class T> Fraction<T> operator/(Fraction<T> p, Fraction<T> q) { return Fraction<T>(p.a*q.b, p.b*q.a); }


vector<vector<int>> id15(int rows, int cols)
{
	vector<vector<int>> matrix(rows);
	for (auto & i : matrix)
	{
		vector<int> foo(cols);
		for (auto & j : foo)
			cin >> j;
		i = foo;
	}
	return matrix;
}


vector<vector<int>> id6(int rows, int cols)
{
	vector<vector<int>>matrix = id15(rows, cols);
	vector<vector<int> > ret(matrix[0].size());
	for (int i = 0; i < (int)ret.size(); i++)
	{
		vector<int>foo;
		for (int j = 0; j < (int)matrix.size(); j++)
			foo.push_back(matrix[j][i]);
		ret[i] = foo;
	}
	return ret;
}
vector<vector<char>> id16(int rows, int cols)
{
	vector<vector<char>> matrix(rows);
	for (auto & i : matrix)
	{
		vector<char> foo(cols);
		for (auto & j : foo)
			cin >> j;
		i = foo;
	}
	return matrix;
}
vector<vector<char>> id10(int rows, int cols)
{
	vector<vector<char>>matrix = id16(rows, cols);
	vector<vector<char> > ret(matrix[0].size());
	for (int i = 0; i < (int)ret.size(); i++)
	{
		vector<char>foo;
		for (int j = 0; j < (int)matrix.size(); j++)
			foo.push_back(matrix[j][i]);
		ret[i] = foo;
	}
	return ret;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		itemPrices[i] = a;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		

		

		paired[u][v] = paired[v][u] = 1;
	}

	for (int i = 0; i < n; ++i)
	{
		combination.push_back(i >= (n - 3));
	}
	do {
		triplet.clear();
		for (int i = 0; i < n; ++i) {
			if (combination[i]) {
				triplet.push_back((i + 1));
			}
		}
		

		

		if (paired[triplet[0]][triplet[1]] &&
			paired[triplet[0]][triplet[2]] &&
			paired[triplet[2]][triplet[1]])
		{
			prices.push_back(itemPrices[triplet[0]] + itemPrices[triplet[1]] + itemPrices[triplet[2]]);
		}
	} while (std::next_permutation(combination.begin(), combination.end()));
	cout << (!prices.empty() ?
		*min_element(prices.begin(), prices.end()) : -1) << "\n";
}
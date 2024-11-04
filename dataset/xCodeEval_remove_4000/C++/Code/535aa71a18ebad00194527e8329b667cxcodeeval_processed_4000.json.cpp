




























































using namespace std;



typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double ld;













const int INF = 1000 * 1000 * 1000 + 322;
const ll LLINF = 2LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL + 57;
const int MOD = 1000 * 1000 * 1000 + 7;
const ll FFT_MOD = 998244353;
const int id1 = 1336337; 

const int id2 = 1009; 

const ld PI = acos(-1.);

const ld EPS = 1e-7;

template<typename T, typename U> inline ostream &operator << (ostream &_out, const pair<T, U> &_p) { _out << _p.first << " " << _p.second; return _out; }
template<typename T, typename U> inline istream &operator >> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator << (ostream &_out, const vector<T> &_v) { if (_v.empty()) return _out; _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline istream &operator >> (istream &_in, vector<T> &_v) { for (auto &_i : _v) _in >> _i; return _in; }
template<typename T> inline ostream &operator << (ostream &_out, const set<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline ostream &operator << (ostream &_out, const multiset<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline ostream &operator << (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline ostream &operator << (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T, typename U> inline ostream &operator << (ostream &_out, const map<T, U> &_m) { if (_m.empty()) return _out; _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) _out << ", (" << _it->first << ": " << _it->second << ')'; return _out; }
template<typename T, typename U> inline ostream &operator << (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) return _out; _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) _out << ", (" << _it->first << ": " << _it->second << ')'; return _out; }

const char * infile =

"input.txt"

""


;
const char * outfile =

""

""


;





const int ML_ = 200;
char mem_[ML_ * 1024 * 1024];
size_t _ptr = 0, _magic = 21323400;
void * operator new(size_t cnt) { if (_ptr + cnt < sizeof mem_) { _ptr += cnt; return  mem_ + _ptr - cnt; } else { assert(false);  _ptr = cnt + _magic; return mem_ + _magic; } }
void operator delete(void *) {}



inline ll gcd(ll a, ll b) { while (b) { a %= b; swap(a, b); } return a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
inline int pwm(ll xx, ll pow, int MD = MOD) { if (pow < 0) { return pwm(pwm(xx, MD - 2, MD), -pow, MD); } ll mlt = 1; while (pow) { if (pow & 1) { mlt *= xx; mlt %= MD; } xx *= xx; pow >>= 1; xx %= MD; } return (int)mlt; }




inline int inv(ll r, int _mod = MOD) { return pwm(r % _mod, _mod - 2, _mod); }



struct compl_z{
	ld x, y;

	compl_z(ld _x = 0, ld _y = 0) : x(_x), y(_y) {}

	void operator=(const compl_z &oth) {
		x = oth.x;
		y = oth.y;
	}

	void operator=(const ld oth) {
		x = oth;
		y = 0;
	}

	compl_z operator*(const compl_z &op) const {
		return compl_z(x * op.x - y * op.y, x * op.y + y * op.x);
	}

	compl_z operator+(const compl_z &op) const {
		return compl_z(x + op.x, y + op.y);
	}

	compl_z operator-(const compl_z &op) const {
		return compl_z(x - op.x, y - op.y);
	}

	compl_z operator/(const compl_z &op) const {

		ld abs = op.x * op.x + op.y * op.y;
		return compl_z((x * op.x + y * op.y) / abs, (- x * op.y + y * op.x) / abs);
	}

	void operator*=(const compl_z &op) {
		*this = compl_z(x * op.x - y * op.y, x * op.y + y * op.x);
	}

	void operator+=(const compl_z &op) {
		*this = compl_z(x + op.x, y + op.y);
	}

	void operator-=(const compl_z &op) {
		*this = compl_z(x - op.x, y - op.y);
	}

	void operator/=(const compl_z &op) {
		ld abs = op.x * op.x + op.y * op.y;
		*this = compl_z((x * op.x + y * op.y) / abs, (-x * op.y + y * op.x) / abs);
	}

	void operator/=(const int op) {
		*this = compl_z(x / op, y / op);
	}

	void operator/=(const ld op) {
		*this = compl_z(x / op, y / op);
	}
};

const int L = 21;
const int N = 1 << L;

int rev_bits[N];
compl_z w_prec[N << 1];
compl_z iw_prec[N << 1];
compl_z *start_w[L + 1], *start_iw[L + 1];

void prec_fft() {
	int *rv = rev_bits;
	for (int i = 0; i < N; ++i) {
		int cur = i;
		for (int cnt = 0; cnt < L; ++cnt, cur >>= 1) {
			*rv <<= 1;
			if (cur & 1) {
				*rv |= 1;
			}
		}
		++rv;
	}
	compl_z *w = w_prec;
	for (int i = 0; i <= L; ++i) {
		*w = 1;
		start_w[i] = w;
		const ld ang = 2 * PI / (1 << i);
		compl_z mul(cos(ang), sin(ang));
		for (int j = 1; j < (1 << i); ++j) {
			w[1] = *w * mul;
			++w;
		}
		++w;
	}
	w = iw_prec;
	for (int i = 0; i <= L; ++i) {
		*w = 1;
		start_iw[i] = w;
		const ld ang = -2 * PI / (1 << i);
		compl_z mul(cos(ang), sin(ang));
		for (int j = 1; j < (1 << i); ++j) {
			w[1] = *w * mul;
			++w;
		}
		++w;
	}
}

compl_z oper1[N];
compl_z oper2[N];
compl_z res[N];

inline compl_z id0(compl_z z) {
	return compl_z(-z.y, z.x);
}

void fft(compl_z *op, bool inv) {
	for (int i = 0; i < N; ++i) {
		if (i < rev_bits[i]) {
			swap(op[i], op[rev_bits[i]]);
		}
	}

	

	

	{ 

		auto cur = op, lst = op + N;
		for (; cur != lst; cur += 2) {
			auto ncur = *cur + cur[1];
			cur[1] = *cur - cur[1];
			*cur = ncur;
		}
	}

	{ 

		

		

		auto cur = op, lst = op + N;
		for (; cur != lst; cur += 4) {
			

			

			if (!inv) {
				auto ncur = *cur + cur[2];
				cur[2] = *cur - cur[2];
				*cur = ncur;

				ncur = cur[1] + id0(cur[3]);
				cur[3] = cur[1] - id0(cur[3]);
				cur[1] = ncur;
			}
			else {
				auto ncur = *cur + cur[2];
				cur[2] = *cur - cur[2];
				*cur = ncur;

				ncur = cur[1] - id0(cur[3]);
				cur[3] = cur[1] + id0(cur[3]);
				cur[1] = ncur;
			}
			

		}
	}

	for (int pw = 2; pw < L; ++pw) {
		int len = (1 << pw);
		

		auto cur = op, lst = op + N;
		for (; cur != lst; cur += len) {
			auto w = inv ? start_iw[pw + 1] : start_w[pw + 1];
			for (int cnt = 0; cnt < len; ++cnt, ++cur, ++w) {
				auto ncur = *cur + *w * cur[len];
				cur[len] = *cur - *w * cur[len];
				*cur = ncur;
			}
		}
	}

	if (inv) {
		auto cur = op;
		for (int i = 0; i < N; ++i) {
			*cur /= N;
			++cur;
		}
	}
}

void mult_poly(int *a, int *b, int *c, int n) {
	

	for (int i = 0; i < N; ++i) {
		oper1[i] = (i < n ? a[i] : 0);
		oper2[i] = (i < n ? b[i] : 0);
	}
	fft(oper1, false);
	fft(oper2, false);

	auto op1 = oper1;
	auto op2 = oper2;
	for (int i = 0; i < N; ++i) {
		*op1 *= *op2;
		++op1;
		++op2;
	}

	fft(oper1, true);
	op1 = oper1;
	for (int i = 0; i < N; ++i) {
		c[i] = floor(op1->x + 0.5);
		++op1;
	}

}


int a[N], b[N];
int v[N >> 1];

inline void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	

	

	for (int i = 0; i < n; ++i) {
		scanf("%d", v + i);
	}
	


	for (int i = 0; i < n; ++i) {
		a[v[i]] = 1;
	}
	


	prec_fft();

	mult_poly(a, a, b, N);

	

	

	

	int ptr = 0;
	for (int i = 0; i <= m; ++i) {
		if (b[i] != 0) {
			if (a[i] == 0) {
				printf("NO\n");
				

				return;
			}
			

			

			

		}
		else {
			if (a[i] != 0) {
				v[ptr++] = i;
				

			}
		}
		

	}
	printf("YES\n%d\n", ptr);
	for (int i = 0; i < ptr; ++i) {
		printf("%d ", v[i]);
	}
	printf("\n");
	

	

	

	

}

int main() {

	if (*infile != '\0')
		(void)freopen(infile, "r", stdin);
	if (*outfile != '\0')
		(void)freopen(outfile, "w", stdout);

	speedup;
	coutdouble;


	

	

	

	

	

	

	solve();
	

	

	

	

	



	cerr << "Time: " << (ld)clock() / CLOCKS_PER_SEC << endl;
	while (true);



	return 0;
}
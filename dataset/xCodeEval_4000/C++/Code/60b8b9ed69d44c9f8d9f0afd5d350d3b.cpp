#include "bits/stdc++.h"

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

typedef long double ld;

const ld eps = 1e-9;
const ld pi = acos(-1);




namespace io_impl
{
	inline bool maybe_digit(char c)
	{
		return c >= '0' && c <= '9';
	}

	struct io_s
	{
	private:
		FILE* fin = stdin;
		FILE* fout = stdout;

		bool negative;
		bool ok = true;
		char ch;

		int precious;
		long double epslion;

#ifdef ENABLE_FREAD
		inline char next_char() {
			static char buf[100000], *p1 = buf, *p2 = buf;
			return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, fin), p1 == p2) ? EOF : *p1++;
		}
#else
		char next_char() const
		{
			return fgetc(fin);
		}
#endif
	public:
		void init()
		{
			ch = next_char();
		}

		void init(FILE* _in, FILE* _out)
		{
			fin = _in;
			fout = _out;
			init();
		}

#pragma region read int

		template <typename T>
		bool rn(T& _v)
		{
			negative = false;
			_v = 0;
			while (!maybe_digit(ch) && ch != EOF)
			{
				negative = ch == '-';
				ch = next_char();
			}
			if (ch == EOF)return ok = false;
			do
			{
				_v = (_v << 1) + (_v << 3) + ch - '0';
			}
			while (maybe_digit(ch = next_char()));
			if (negative) _v = -_v;
			return true;
		}

		template <typename T>
		void rn_unsafe(T& _v)
		{
			negative = false;
			_v = 0;
			while (!maybe_digit(ch))
			{
				negative = ch == '-';
				ch = next_char();
			}
			do
			{
				_v = (_v << 1) + (_v << 3) + ch - '0';
			}
			while (maybe_digit(ch = next_char()));
			if (negative) _v = -_v;
		}

		template <typename T>
		T rn()
		{
			T v = T();
			rn_unsafe(v);
			return v;
		}

#pragma endregion

#pragma region read unsigned

		template <typename T>
		bool run(T& _v)
		{
			_v = 0;
			while (!maybe_digit(ch) && ch != EOF) ch = next_char();
			if (ch == EOF)return ok = false;
			do
			{
				_v = (_v << 1) + (_v << 3) + ch - '0';
			}
			while (maybe_digit(ch = next_char()));
			return true;
		}

		template <typename T>
		void run_unsafe(T& _v)
		{
			_v = 0;
			while (!maybe_digit(ch)) ch = next_char();
			do
			{
				_v = (_v << 1) + (_v << 3) + ch - '0';
			}
			while (maybe_digit(ch = next_char()));
		}

		template <typename T>
		T run()
		{
			T v = T();
			run_unsafe(v);
			return v;
		}

#pragma endregion

#pragma region read float

		template <typename T>
		bool rd(T& _v)
		{
			negative = false;
			_v = 0;
			while (!maybe_digit(ch) && ch != EOF)
			{
				negative = ch == '-';
				ch = next_char();
			}
			if (ch == EOF)return ok = false;
			do
			{
				_v = (_v * 10) + (ch - '0');
			}
			while (maybe_digit(ch = next_char()));
			static int stk[70], tp;
			if (ch == '.')
			{
				tp = 0;
				T _v2 = 0;
				while (maybe_digit(ch = next_char()))
				{
					stk[tp++] = ch - '0';
				}
				while (tp--)
				{
					_v2 = _v2 / 10 + stk[tp];
				}
				_v += _v2 / 10;
			}
			if (ch == 'e' || ch == 'E')
			{
				ch = next_char();
				static bool _neg = false;
				if (ch == '+') ch = next_char();
				else if (ch == '-') _neg = true, ch = next_char();
				if (maybe_digit(ch))
				{
					_v *= pow(10, run<LL>() * (_neg ? -1 : 1));
				}
			}
			if (negative) _v = -_v;
			return true;
		}

		template <typename T>
		T rd()
		{
			T v = T();
			rd(v);
			return v;
		}

#pragma endregion

#pragma region read string

		int gets(char* s)
		{
			char* c = s;
			while (ch == '\n' || ch == '\r' || ch == ' ') ch = next_char();
			if (ch == EOF) return (ok = false), *c = 0;
			do
			{
				*(c++) = ch;
				ch = next_char();
			}
			while (ch != '\n' && ch != '\r' && ch != ' ' && ch != EOF);
			*(c++) = '\0';
			return static_cast<int>(c - s - 1);
		}

		int getline(char* s)
		{
			char* c = s;
			while (ch == '\n' || ch == '\r') ch = next_char();
			if (ch == EOF) return (ok = false), *c = 0;
			do
			{
				*(c++) = ch;
				ch = next_char();
			}
			while (ch != '\n' && ch != '\r' && ch != EOF);
			*(c++) = '\0';
			return static_cast<int>(c - s - 1);
		}

		char get_alpha()
		{
			while (!isalpha(ch)) ch = next_char();
			const char ret = ch;
			ch = next_char();
			return ret;
		}

		char get_nonblank()
		{
			while (iswspace(ch)) ch = next_char();
			const char ret = ch;
			ch = next_char();
			return ret;
		}

		char get_char()
		{
			const char ret = ch;
			ch = next_char();
			return ret;
		}

		template <typename T>
		void o(T p)
		{
			static int stk[70], tp;
			if (p == 0)
			{
				putchar('0');
				return;
			}
			if (p < 0)
			{
				p = -p;
				putchar('-');
			}
			while (p) stk[++tp] = p % 10, p /= 10;
			while (tp) putchar(stk[tp--] + '0');
		}

		template <typename T>
		void od(T v)
		{
			static int stk[70], tp;
			tp = 0;
			if (fabs(v) < epslion / 10)
			{
				putchar('0');
				if (precious > 0)
				{
					putchar('.');
					for (int i = 0; i < precious; ++i) putchar('0');
				}
				return;
			}
			if (v < 0)
			{
				v = -v;
				putchar('-');
			}
			v += epslion / 2;
			T p = floor(v) + epslion / 10;
			while (fabs(p) > 1 - epslion)
			{
				stk[++tp] = fmod(p, 10), p = floor(p / 10) + epslion;
			}
			if (tp == 0) putchar('0');
			while (tp) putchar(stk[tp--] + '0');
			if (precious == 0) return;
			putchar('.');
			v -= floor(v);
			for (int i = 0; i < precious; ++i)
			{
				v *= 10;
				putchar((int)floor(v) + '0');
				v = fmod(v, 1);
			}
		}

#pragma endregion

#pragma region enhancement

		typedef void io_operator_func(io_s& v);
		typedef char* charptr;

		template <typename T>
		io_s& operator >>(T& x)
		{
			if (numeric_limits<T>::is_signed) rn(x);
			else run(x);
			return *this;
		}

		template <typename TFirst, typename TSecond>
		io_s& operator >>(pair<TFirst, TSecond>& pr)
		{
			*this >> pr.first >> pr.second;
			return *this;
		}

		template <typename T>
		io_s& operator <<(const T& x);

		io_s& operator <<(const io_operator_func*& x)
		{
			x(*this);
			return *this;
		}

		operator bool() const { return ok; }

		void set_precious(int x)
		{
			precious = x;
			epslion = pow(10, -x);
		}

		int ri() { return rn<int>(); }
		LL rll() { return rn<LL>(); }

		static void new_line(io_s& v)
		{
			putchar('\n');
		}

		static void flush(io_s& v)
		{
			fflush(stdout);
		}
#pragma endregion

#pragma region batch

		template <typename T>
		void o(T begin, T end)
		{
			while (begin != end)
			{
				o(*begin++);
				o(begin == end ? '\n' : ' ');
			}
		}

#pragma endregion
	};

#pragma region input fix

	template <>
	inline io_s& io_s::operator >>(char*& x)
	{
		gets(x);
		return *this;
	}

	template <>
	inline io_s& io_s::operator >>(char& x)
	{
		x = get_nonblank();
		return *this;
	}

	template <>
	inline io_s& io_s::operator >>(float& x)
	{
		rd(x);
		return *this;
	}

	template <>
	inline io_s& io_s::operator >>(double& x)
	{
		rd(x);
		return *this;
	}

	template <>
	inline io_s& io_s::operator >>(long double& x)
	{
		rd(x);
		return *this;
	}
#pragma region output fix

	template <>
	inline void io_s::o(const char p)
	{
		putchar(p);
	}

	template <>
	inline void io_s::o(const char* p)
	{
		printf(p);
	}

	template <>
	inline void io_s::o(float p)
	{
		od(p);
	}

	template <>
	inline void io_s::o(double p)
	{
		od(p);
	}

	template <>
	inline void io_s::o(long double p)
	{
		od(p);
	}

	template <typename T>
	io_s& io_s::operator <<(const T& x)
	{
		o(x);
		return *this;
	}

	io_s::io_operator_func* nl = io_s::new_line;
	io_s::io_operator_func* fl = io_s::flush;
#pragma endregion
}

using namespace io_impl;

io_s io;

typedef void InitFunction();
typedef bool SolveFunction(int);

struct env_s
{
private:
	bool global_inited = false;

	bool case_inited = false;
public:
	bool once()
	{
		return global_inited ? false : (global_inited = true);
	}

	bool every()
	{
		return case_inited ? false : (case_inited = true);
	}

	InitFunction *_initOnce, *_init;

	template <InitFunction TInitOnce, InitFunction TInit>
	void configure()
	{
		_initOnce = TInitOnce;
		_init = TInit;
	}

	void init(bool global)
	{
		if (global) if (_initOnce != nullptr)_initOnce();
		if (_init != nullptr) _init();
	}

	void empty_init()
	{
	}

	template <SolveFunction TSolve>
	void solve_single()
	{
		global_inited = false;
		case_inited = false;
		init(true);
		TSolve(0);
	}

	template <SolveFunction TSolve>
	void solve_many()
	{
		global_inited = false;
		int T = io.ri();
		for (int cs = 1; T--; ++cs)
		{
			case_inited = false;
			init(cs == 1);
			if (!TSolve(cs))break;
		}
	}

	template <SolveFunction TSolve>
	void solve_much()
	{
		global_inited = false;
		case_inited = false;
		for (int cs = 1; init(cs == 1), TSolve(cs); ++cs)
			case_inited = false;
	}
} env;

#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i > _##i; --i)

#if 0


#define dbg(...) do { cerr << "Debug: " << # __VA_ARGS__ << " -> "; err(## __VA_ARGS__); } while (0)
#else
#define dbg(...)
#endif
void err() { cerr << endl; }

template <typename T, typename... Args>
void err(T a, Args ... args)
{
	cerr << a << ' ';
	err(args...);
}




namespace solution
{
#pragma region init

	void init_once()
	{
		srand(time(nullptr));
		io.set_precious(12);
		

	}

	void init_every()
	{
	}

#pragma endregion

	const int N = 1e6 + 10;
	const int K = 30;

	char a[N], b[N], s[N];

	int n, k;

	bool found;

	int determined[K];
	bool used[K];

	void Fill()
	{
		int vis[K]; fill(vis, vis + k, 0);
		FOR(i, 0, k) if (determined[i] != -1) vis[determined[i]] = 1;
		int t = 0;
		FOR(i, 0, k) if(determined[i] == -1)
		{
			while (vis[t]) ++t;
			determined[i] = t++;
		}
	}

	int d[K];
	bool u[K];

	bool testA(int p)
	{
		copy(determined, determined + k, d);
		copy(used, used + k, u);
		d[s[p]] = a[p];
		u[a[p]] = true;
		bool ok = true;
		FOR(i, p + 1, n)
		{
			if (d[s[i]] != -1)
			{
				if (d[s[i]] > a[i])
				{
					ok = true;
					break;
				}
				if (d[s[i]] < a[i])
				{
					ok = false;
					break;
				}
			}
			else
			{
				bool flag = false;
				FOR(j, a[i]+1, k) if (!u[j]) {
					d[s[i]] = j;
					flag = true;
					break;
				}
				if (flag)
				{
					ok = true;
					break;
				}
				if (u[a[i]])
				{
					ok = false;
					break;
				}
				d[s[i]] = a[i];
				u[a[i]] = true;
			}
		}
		if (ok) copy(d, d + k, determined);
		return ok;
	}

	bool testB(int p)
	{
		copy(determined, determined + k, d);
		copy(used, used + k, u);
		d[s[p]] = b[p];
		u[b[p]] = true;
		bool ok = true;
		FOR(i, p + 1, n)
		{
			if (d[s[i]] != -1)
			{
				if (d[s[i]] < b[i])
				{
					ok = true;
					break;
				}
				if (d[s[i]] > b[i])
				{
					ok = false;
					break;
				}
			}
			else
			{
				bool flag = false;
				FORD(j, (int)b[i] - 1, -1) if (!u[j]) {
					d[s[i]] = j;
					flag = true;
					break;
				}
				if(flag)
				{
					ok = true;
					break;
				}
				if(u[b[i]])
				{
					ok = false;
					break;
				}
				d[s[i]] = b[i];
				u[b[i]] = true;
			}
		}
		if (ok) copy(d, d + k, determined);
		return ok;
	}

	bool solve(int _cas)
	{
		io >> k;
		n = io.gets(s);
		io.gets(a);
		io.gets(b);
		fill(determined, determined + k, -1);
		fill(used, used + k, false);
		FOR(i, 0, n) s[i]-='a', a[i]-='a', b[i]-='a';
		found = true;
		FOR(i, 0, n) if(a[i]!=b[i])
		{
			if(determined[s[i]]!=-1)
			{
				char x = determined[s[i]];
				if(x==a[i])
				{
					found = testA(i);
				} else if(a[i]<x && x<b[i])
				{
					found = true;
				} else if(x==b[i])
				{
					found = testB(i);
				} else
				{
					found = false;
				}
			} else
			{
				found = false;
				FOR(j, a[i]+1, b[i]) if(!used[j])
				{
					found = true;
					determined[s[i]] = j;
					break;
				}
				found = found || (!used[a[i]] && testA(i)) || (!used[b[i]] && testB(i));
			}
			break;
		} else
		{
			if (determined[s[i]] != -1)
			{
				if (determined[s[i]] != a[i]) {
					found = false;
					break;
				}
			}
			else {
				if(used[a[i]])
				{
					found = false;
					break;
				}
				determined[s[i]] = a[i];
				used[a[i]] = true;
			}
		}
		if(found)
		{
			puts("YES");
			Fill();
			FOR(i, 0, k) putchar('a' + determined[i]);
			putchar('\n');
		} else
		{
			puts("NO");
		}
		return true;
	}
}




#ifdef _DEBUG

#ifndef ONLINE_JUDGE

#define DEBUGTOOL 1

#endif

#endif

int main()
{
#if DEBUGTOOL
	clock_t t = clock();
	

	io.init(fopen("data.in", "r"), stdout);
	

#else
	io.init();
#endif
	env.configure<solution::init_once, solution::init_every>();
	env.solve_many<solution::solve>();
#if DEBUGTOOL
	io << "time: " << 1.0*(clock() - t) /CLOCKS_PER_SEC<< "s" << nl;
	system("pause");
#endif
	return 0;
}

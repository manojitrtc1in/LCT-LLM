











namespace io
{
	namespace internal
	{











		auto unistd_read = read;
		auto unistd_write = write;


		const int id1 = 1 << 20;
		int isize, osize;
		char ibuf[id1 + 10], obuf[id1 + 10];
		char* is = nullptr, * it = nullptr;
		char* os = obuf;
		constexpr char* ot = obuf + id1;

		struct ender
		{
			~ender()
			{
				if (os != obuf)

					fwrite(obuf, 1, os - obuf, stdout);

					unistd_write(STDOUT_FILENO, obuf, os - obuf);

			}
		}__ender;
	}

	static inline bool read(char& x)
	{
		using namespace internal;
		if (is == it)
		{
			is = ibuf;

			it = ibuf + fread(ibuf, 1, id1, stdin);

			it = ibuf + unistd_read(STDIN_FILENO, ibuf, id1);

			if (is == it) return false;
		}
		x = *is++;
		return true;
	}

	static inline bool read(char* x)
	{
		do
		{
			if (!read(*x)) return false;
		} while (isspace(*x));
		for (++x; read(*x) && !isspace(*x); ++x);
		*x = 0;
		return true;
	}

	static inline bool read(std::string& s)
	{
		char c;
		do
		{
			if (!read(c)) return false;
		} while (isspace(c));
		s.clear();
		for (s += c; read(c) && !isspace(c); s += c);
		return true;
	}

	template<typename T>
	inline bool id3(T& x)
	{
		char ch = 0;
		do
		{
			if (!read(ch)) return false;
		} while (!isdigit(ch));
		for (x = ch - '0'; read(ch) && isdigit(ch); x = x * 10 + ch - '0');
		return true;
	}

	template<typename T>
	inline bool id0(T& x)
	{
		char ch = 0;
		bool sign = 0;
		do
		{
			if (!read(ch)) return false;
		} while (!isdigit(ch) && ch != '-');
		if (ch == '-')
		{
			sign = 1;
			x = 0;
		}
		else
			x = ch - '0';
		for (; read(ch) && isdigit(ch); x = x * 10 + ch - '0');
		if (sign) x = -x;
		return true;
	}

	template<typename T>
	inline bool read_int(T& x)
	{
		return id0(x);
	}

	template<typename T>
	inline std::enable_if_t<!std::is_same_v<T, char>&& std::is_integral_v<T>&& std::is_unsigned_v<T>, bool> read(T& x)
	{
		return id3(x);
	}

	template<typename T>
	inline std::enable_if_t<!std::is_same_v<T, char>&& std::is_integral_v<T>&& std::is_signed_v<T>, bool> read(T& x)
	{
		return id0(x);
	}

	

	

	

	

	template<typename T>
	inline std::enable_if_t<std::is_floating_point_v<T>, bool> read(T& x)
	{
		constexpr T pow10[] = { 1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9, 1e10,
			1e11, 1e12, 1e13, 1e14, 1e15, 1e16, 1e17, 1e18 };
		char ch = 0;
		do
		{
			if (!read(ch)) return false;
		} while (!isdigit(ch) && ch != '-' && ch != '.');
		bool sign = ch == '-';
		if (sign)
			if (!read(ch)) return false;
		uint64_t a = 0;
		if (isdigit(ch))
		{
			a = ch - '0';
			while (read(ch) && isdigit(ch))
				a = a * 10 + ch - '0';
		}
		if (ch == '.')
		{
			uint64_t b = 0;
			int len = 0;
			while (read(ch) && isdigit(ch))
			{
				b = b * 10 + ch - '0';
				len++;
			}
			x = a + b / pow10[len];
		}
		else
			x = a;
		if (sign) x = -x;
		return true;
	}

	template<typename T, typename... Args>
	bool read(T& x, Args&... args)
	{
		return read(x) && read(args...);
	}

	static inline void write(const char& x)
	{
		using namespace internal;
		*os++ = x;
		if (os == ot)
		{

			fwrite(obuf, 1, id1, stdout);

			unistd_write(STDOUT_FILENO, obuf, id1);

			os = obuf;
		}
	}

	static inline void write(const char* x)
	{
		for (; *x; ++x) write(*x);
	}

	static inline void write(const std::string& s)
	{
		write(s.c_str());
	}

	template<typename T>
	inline void id2(T x)
	{
		if (x == 0)
			return write('0');
		std::string s;
		while (x)
		{
			s.push_back(x % 10 + '0');
			x /= 10;
		}
		std::reverse(s.begin(), s.end());
		write(s);
	}

	template<typename T>
	inline void id4(T x)
	{
		if (x < 0)
			write('-'), id2(-x);
		else
			id2(x);
	}

	template<typename T>
	inline void write_int(T x)
	{
		id4(x);
	}

	template<typename T>
	inline std::enable_if_t<!std::is_same_v<T, char>&& std::is_integral_v<T>&& std::is_unsigned_v<T>, void> write(T x)
	{
		static char buf[22] = { };
		static char* it = buf + 20;
		static char* end = buf + 20;
		do
		{
			*--it = x % 10 + '0';
			x /= 10;
		} while (x);
		for (; it < end; ++it)
			write(*it);
	}

	template<typename T>
	inline std::enable_if_t<!std::is_same_v<T, char>&& std::is_integral_v<T>&& std::is_unsigned_v<T>, void> write_number(T x, int fill)
	{
		static char buf[22] = { };
		static char* it = buf + 20;
		static char* end = buf + 20;
		do
		{
			*--it = x % 10 + '0';
			x /= 10;
		} while (x);
		for (int i = end - it; i < fill; ++i)
			write('0');
		for (; it < end; ++it)
			write(*it);
	}

	template<typename T>
	inline std::enable_if_t<!std::is_same_v<T, char>&& std::is_integral_v<T>&& std::is_signed_v<T>, void> write(const T& x)
	{
		if (x < 0) write('-'), write(std::make_unsigned_t<T>(-x));
		else write(std::make_unsigned_t<T>(x));
	}

	static inline void write_float(double x, int precision = 10)
	{
		if (std::isnan(x)) return write("NaN");
		if (std::isinf(x)) return write("Inf");
		if (x < 0) x = -x, write('-');
		constexpr double pow10[] = { 1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9, 1e10, 
			1e11, 1e12, 1e13, 1e14, 1e15, 1e16, 1e17, 1e18 };
		constexpr double pow10inv[] = { 1e-0, 1e-1, 1e-2, 1e-3, 1e-4, 1e-5, 1e-6, 1e-7, 1e-8, 1e-9, 1e-10, 
			1e-11, 1e-12, 1e-13, 1e-14, 1e-15, 1e-16, 1e-17, 1e-18 };
		x += pow10inv[precision] * 0.5;
		uint64_t a = uint64_t(x);
		write(a);
		write('.');
		uint64_t b = uint64_t((x - a) * pow10[precision]);
		write_number(b, precision);
	}

	template<typename T>
	inline std::enable_if_t<std::is_floating_point_v<T>, void> write(const T& x)
	{
		write_float(double(x));
	}

	template<typename T, typename... Args>
	void write(const T& x, const Args&... args)
	{
		write(x), write(args...);
	}
	
	static inline void writeln()
	{
		write('\n');
	}

	template<typename T, typename... Args>
	void writeln(const T& x, const Args&... args)
	{
		write(x), writeln(args...);
	}

	template<typename T>
	T next()
	{
		T x;
		read(x);
		return std::move(x);
	}

	template<typename InputIt>
	bool input(InputIt first, InputIt last)
	{
		for (; first != last; ++first)
			if (!read(*first)) return false;
		return true;
	}

	template<typename Iterable>
	bool input(Iterable& a)
	{
		for (auto& x : a)
			if (!read(x)) return false;
		return true;
	}

	template<typename InputIt>
	void print(InputIt first, InputIt last, const char* sep = " ")
	{
		for (; first != last; )
		{
			write(*first);
			if (++first != last) write(sep);
		}
		writeln();
	}

	template<typename Iterable>
	void print(const Iterable& a, const char* sep = " ")
	{
		print(a.begin(), a.end(), sep);
	}

	template<typename InputIt>
	void println(InputIt first, InputIt last)
	{
		print(first, last, "\n");
	}

	template<typename Iterable>
	void println(const Iterable& a)
	{
		println(a.begin(), a.end());
	}
}






namespace algorithm { }
namespace data_structure { }

using namespace std;
using namespace io;
using namespace algorithm;
using namespace data_structure;







template<class T, class U>
bool freshmax(T& a, const U& b)
{
	return a < T(b) ? a = b, 1 : 0;
}

template<class T, class U>
bool freshmin(T& a, const U& b)
{
	return a > T(b) ? a = b, 1 : 0;
}















using ll = int64_t;
using ull = uint64_t;
using ld = double;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };




const int MAXN = 500010;

int n;
vector<pair<int, int>> v[MAXN];

int u[MAXN];
int sz[MAXN], pre[MAXN], most[MAXN];
int low[MAXN], high[MAXN], from[MAXN];

int uc[MAXN];
vector<int> rc[MAXN];
int cnt[MAXN], tmp[MAXN];

ll res;

void go(int st)
{
	vector<int> q = { st };
	u[st] = 1;
	for (int k = 0; k < q.size(); ++k)
	{
		int x = q[k];
		for (auto& [y, z] : v[x])
		{
			if (u[y]) continue;
			pre[y] = x;
			u[y] = 1;
			q.push_back(y);
		}
	}
	for (auto x : q)
	{
		sz[x] = 1;
		most[x] = 0;
	}
	for (int k = q.size() - 1; k >= 1; --k)
	{
		int x = q[k];
		sz[pre[x]] += sz[x];
		freshmax(most[pre[x]], sz[x]);
	}
	for (auto x : q)
		freshmax(most[x], q.size() - sz[x]);
	int r = st;
	for (auto x : q)
		if (most[x] < most[r]) r = x;

	for (auto x : q) u[x] = 0;

	int time = 0;
	vector<int> vc;
	function<void(int, int)> dfs = [&](int x, int f)
	{
		++time;
		low[x] = time;
		u[x] = 1;
		sz[x] = 1;
		for (auto& [y, z] : v[x])
		{
			if (u[y]) continue;
			if (uc[z] == 0)
			{
				uc[z] = 1;
				vc.push_back(z);
			}
			rc[z].push_back(y);
			dfs(y, from[y] = f == -1 ? y : f);
			sz[x] += sz[y];
		}
		u[x] = 0;
		high[x] = time;
	};
	dfs(r, -1);
	
	int sum_cnt = 0;
	for (auto& [x, z] : v[r])
	{
		if (u[x]) continue;
		cnt[x] = 0;
	}
	for (auto c : vc)
	{
		
		vector<int> p;
		vector<int> p_left;
		for (auto x : rc[c])
		{
			if (p.empty() || high[p.back()] < low[x])
				p.push_back(x);
			else
				p_left.push_back(x);
		}
		vector<int> pp;
		for (auto x : p_left)
		{
			if (pp.empty() || high[pp.back()] < low[x])
				pp.push_back(x);
		}
		for (auto x : p)
		{
			cnt[from[x]] += sz[x];
			sum_cnt += sz[x];
			tmp[x] = sz[x];
		}
		{
			int id = 0;
			for (auto x : pp)
			{
				while (id + 1 < p.size() && [&](int i, int j)
					{
						return low[i] < low[j] || low[i] == low[j] && high[i] > high[j];
					}(p[id + 1], x)) id += 1;
				tmp[p[id]] -= sz[x];
			}
		}

		for (auto x : p)
		{
			res += ll(q.size() - sz[from[x]] - (sum_cnt - cnt[from[x]])) * tmp[x];
		}

		sum_cnt = 0;
		for (auto x : p)
			cnt[from[x]] = 0;
	}

	for (auto c : vc)
	{
		uc[c] = 0;
		rc[c].clear();
	}

	u[r] = 1;
	for (auto& [x, z] : v[r])
	{
		if (u[x]) continue;
		go(x);
	}
}

void solve()
{
	read(n);
	

	for (int i = 0; i < n - 1; ++i)
	{
		int x, y, z;
		read(x, y, z);
		

		x -= 1; y -= 1;
		v[x].push_back({ y, z });
		v[y].push_back({ x, z });
	}
	go(0);
	writeln(res);
}

int main()
{

	freopen("try.in", "r", stdin);
	


	int tests = 1;
	

	for (int test = 1; test <= tests; ++test)
	{
		

		solve();
	}
	return 0;
}

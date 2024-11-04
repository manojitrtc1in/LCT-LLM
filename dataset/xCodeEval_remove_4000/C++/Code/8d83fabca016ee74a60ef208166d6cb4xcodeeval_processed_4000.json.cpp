











namespace io
{
	namespace internal
	{











		auto unistd_read = read;
		auto unistd_write = write;


		const int id2 = 1 << 20;
		int isize, osize;
		char ibuf[id2 + 10], obuf[id2 + 10];
		char* is = nullptr, * it = nullptr;
		char* os = obuf;
		constexpr char* ot = obuf + id2;

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

			it = ibuf + fread(ibuf, 1, id2, stdin);

			it = ibuf + unistd_read(STDIN_FILENO, ibuf, id2);

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
	inline bool id4(T& x)
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
		return id4(x);
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

			fwrite(obuf, 1, id2, stdout);

			unistd_write(STDOUT_FILENO, obuf, id2);

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
	inline void id3(T x)
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
	inline void id5(T x)
	{
		if (x < 0)
			write('-'), id3(-x);
		else
			id3(x);
	}

	template<typename T>
	inline void write_int(T x)
	{
		id5(x);
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













namespace data_structure
{
	template<typename T>
	constexpr auto lowbit(T x)
	{
		return x & -x;
	}
	

	

	

	

	

	

	template<typename ValueType, typename Operation = std::plus<ValueType>>
	class id6
	{
	private:
		ValueType init_value;
		Operation operation;
		std::vector<ValueType> values;
		

		void Build()
		{
			for (int i = 1; i <= (int)values.size(); ++i)
				for (int j = lowbit(i) >> 1, pos = i ^ lowbit(i); j; j >>= 1)
					values[i - 1] = operation(std::move(values[i - 1]), values[(pos += j) - 1]);
		}
	public:
		explicit id6(int size, const Operation& operation = Operation(), const ValueType& init_value = 0) :
			values(size, init_value), operation(operation), init_value(init_value) { }
		template<typename InputIt>
		explicit id6(InputIt first, InputIt last, const Operation& operation = Operation(), const ValueType& init_value = ValueType()) :
			values(first, last), operation(operation), init_value(init_value)
		{
			Build();
		}
		ValueType Get(int pos)
		{
			if (!(0 <= pos && pos < (int)values.size())) return init_value;
			ValueType res(init_value);
			for (pos += 1; pos; pos ^= lowbit(pos))
				res = operation(std::move(res), values[pos - 1]);
			return res;
		}
		void Add(int pos, ValueType value)
		{
			assert(0 <= pos && pos < (int)values.size());
			for (pos += 1; pos <= values.size(); pos += lowbit(pos))
				values[pos - 1] = operation(std::move(values[pos - 1]), value);
		}
		
		template<typename T = ValueType>
		std::enable_if_t<std::is_same_v<Operation, std::plus<T>>, std::vector<T>> GetPlain()
		{
			std::vector<ValueType> res = values;
			for (int i = (int)values.size(); i >= 1; --i)
			{
				int k = lowbit(i);
				for (int j = 1, pos = i - 1; j < k; pos ^= j, j <<= 1)
					res[i - 1] -= res[pos - 1];
			}
			return res;
		}

		template<typename T = ValueType>
		std::enable_if_t<std::is_same_v<Operation, std::bit_xor<T>>, std::vector<T>> GetPlain()
		{
			std::vector<ValueType> res = values;
			for (int i = (int)values.size(); i >= 1; --i)
			{
				int k = lowbit(i);
				for (int j = 1, pos = i - 1; j < k; pos ^= j, j <<= 1)
					res[i - 1] ^= res[pos - 1];
			}
			return res;
		}
	};
}






namespace data_structure
{
	template<typename ValueType, typename Operation = std::plus<ValueType>>
	class id1
	{
	private:
		int n, m;
		const Operation& operation;
		const ValueType& init_value;
		std::vector<ValueType> values;
		int Position(int x, int y)
		{
			return x * m + y;
		}
		

	public:
		explicit id1(int n, int m, const Operation& operation = Operation(), const ValueType& init_value = ValueType()) :
			n(n), m(m), operation(operation), init_value(init_value), values(n * m, init_value)
		{
		}
		ValueType Get(int px, int py)
		{
			px = std::min(px, n - 1);
			py = std::min(py, m - 1);
			if (px < 0 || py < 0) return init_value;
			ValueType res = init_value;
			for (int x = px + 1; x; x ^= lowbit(x))
				for (int y = py + 1; y; y ^= lowbit(y))
					res = operation(std::move(res), values[Position(x - 1, y - 1)]);
			return res;
		}
		void Add(int px, int py, ValueType value)
		{
			assert(0 <= px && px < n && 0 <= py && py < m);
			for (int x = px + 1; x <= n; x += lowbit(x))
				for (int y = py + 1; y <= m; y += lowbit(y))
					values[Position(x - 1, y - 1)] = operation(std::move(values[Position(x - 1, y - 1)]), value);
		}
	};
}





using namespace std;
using namespace io;





template<class T>
bool freshmax(T& a, const T& b)
{
	return a < b ? a = b, 1 : 0;
}

template<class T>
bool freshmin(T& a, const T& b)
{
	return a > b ? a = b, 1 : 0;
}















using ll = int64_t;
using ld = double;






int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };




void solve()
{
	int n, k;
	read(n, k);
	data_structure::id1<int> g(2 * n, 2 * n);
	int maxe = n * n;
	vector<pair<int, int>> p(maxe + 1);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			int e;
			read(e);
			p[e] = { i, j };
		}
	vector<string> res(n, string(n, 'G'));
	int cnt = 0;
	for (int val = maxe; val >= 1; --val)
	{
		auto [i, j] = p[val];
		int x = i + j;
		int y = i - j + n - 1;
		int x1 = max(x - k, 0), x2 = min(x + k, 2 * n - 1);
		int y1 = max(y - k, 0), y2 = min(y + k, 2 * n - 1);
		if (g.Get(x2, y2) - g.Get(x1 - 1, y2) - g.Get(x2, y1 - 1) + g.Get(x1 - 1, y1 - 1) == cnt)
		{
			res[i][j] = 'M';
			cnt += 1;
			g.Add(x, y, 1);
		}
	}
	print(res, "\n");
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
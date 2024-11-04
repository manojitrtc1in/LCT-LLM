

 








 
namespace io
{
	namespace internal
	{
 





 




		auto unistd_read = read;
		auto unistd_write = write;

 
		const int id11 = 1 << 20;
		int isize, osize;
		char ibuf[id11 + 10], obuf[id11 + 10];
		char* is = nullptr, * it = nullptr;
		char* os = obuf;
		constexpr char* ot = obuf + id11;
 
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

			it = ibuf + fread(ibuf, 1, id11, stdin);

			it = ibuf + unistd_read(STDIN_FILENO, ibuf, id11);

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
	inline bool id6(T& x)
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
		return id6(x);
	}
 
	template<typename T>
	inline std::enable_if_t<!std::is_same_v<T, char>&& std::is_integral_v<T>&& std::is_unsigned_v<T>, bool> read(T& x)
	{
		return id4(x);
	}
 
	template<typename T>
	inline std::enable_if_t<!std::is_same_v<T, char>&& std::is_integral_v<T>&& std::is_signed_v<T>, bool> read(T& x)
	{
		return id6(x);
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

			fwrite(obuf, 1, id11, stdout);

			unistd_write(STDOUT_FILENO, obuf, id11);

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
	inline void id8(T x)
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
			write('-'), id8(-x);
		else
			id8(x);
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
 

 


 

 

 






 

 
static constexpr inline int32_t id12(uint32_t x)
{
	constexpr uint32_t m1 = 0x55555555;
	constexpr uint32_t m2 = 0x33333333;
	constexpr uint32_t m4 = 0x0f0f0f0f;
	constexpr uint32_t h01 = 0x01010101;
	x -= (x >> 1) & m1;
	x = (x & m2) + ((x >> 2) & m2);
	x = (x + (x >> 4)) & m4;
	return (x * h01) >> 24;
}
 
static constexpr inline int32_t id1(uint32_t x)
{
	return id12((x & -int32_t(x)) - 1);
}
 
static constexpr inline int32_t id9(uint32_t x)
{
	int n = 0;
	if (!(x & 0xffff0000)) n += 16, x <<= 16;
	if (!(x & 0xff000000)) n += 8, x <<= 8;
	if (!(x & 0xf0000000)) n += 4, x <<= 4;
	if (!(x & 0xc0000000)) n += 2, x <<= 2;
	if (!(x & 0x80000000)) n += 1;
	return n;
}
 
static constexpr inline int32_t id7(uint64_t x)
{
	constexpr uint64_t m1 = 0x5555555555555555;
	constexpr uint64_t m2 = 0x3333333333333333;
	constexpr uint64_t m4 = 0x0f0f0f0f0f0f0f0f;
	constexpr uint64_t h01 = 0x0101010101010101;
	x -= (x >> 1) & m1;
	x = (x & m2) + ((x >> 2) & m2);
	x = (x + (x >> 4)) & m4;
	return (x * h01) >> 56;
}
 
static constexpr inline int32_t id10(uint64_t x)
{
	return id7((x & -int64_t(x)) - 1);
}
 
static constexpr inline int32_t id0(uint64_t x)
{
	int n = 0;
	if (!(x & 0xffffffff00000000)) n += 32, x <<= 32;
	if (!(x & 0xffff000000000000)) n += 16, x <<= 16;
	if (!(x & 0xff00000000000000)) n += 8, x <<= 8;
	if (!(x & 0xf000000000000000)) n += 4, x <<= 4;
	if (!(x & 0xc000000000000000)) n += 2, x <<= 2;
	if (!(x & 0x8000000000000000)) n += 1;
	return n;
}
 

 
static constexpr inline int32_t id2(uint32_t x)
{
	return 31 - id9(x);
}
 
static constexpr inline int32_t id13(uint64_t x)
{
	return 63 - id0(x);
}
 

 


 



 
namespace data_structure
{
	

	

	template<typename ValueType, typename ValueMerge,
		typename TagType, typename TagMerge, typename TagSpread>
	class SegmentTree
	{
	private:
		int n, lg, size;
		const ValueType value_init;
		const ValueMerge& value_merge;
		const TagType tag_init;
		const TagMerge& tag_merge;
		const TagSpread& id3;
		std::vector<ValueType> value;
		std::vector<TagType> tag;
		void Update(int k)
		{
			value[k] = value_merge(value[k << 1], value[k << 1 | 1]);
		}
		void AddTag(int k, const TagType& cur_tag)
		{
			id3(cur_tag, value[k]);
			if (k < size) tag_merge(cur_tag, tag[k]);
		}
		void PushTag(int k)
		{
			AddTag(k << 1, tag[k]);
			AddTag(k << 1 | 1, std::move(tag[k]));
			tag[k] = tag_init;
		}
	public:
		template<typename InputIt>
		explicit SegmentTree(InputIt first, InputIt last, const ValueType& value_init, const ValueMerge& value_merge,
			const TagType& tag_init, const TagMerge& tag_merge, const TagSpread& id3) : 
			n(last - first), value_init(value_init), value_merge(value_merge), 
			tag_init(tag_init), tag_merge(tag_merge), id3(id3)
		{
			assert(n >= 1);
			lg = id2(2 * n - 1);
			size = 1 << lg;
			value = std::vector<ValueType>(size << 1, value_init);
			tag = std::vector<TagType>(size, tag_init);
			std::copy(first, last, value.begin() + size);
			for (int k = size - 1; k >= 1; --k) Update(k);
		}
		explicit SegmentTree(const std::vector<ValueType>& data, const ValueType& value_init, const ValueMerge& value_merge,
			const TagType& tag_init, const TagMerge& tag_merge, const TagSpread& id3) :
			SegmentTree(data.begin(), data.end(), value_init, value_merge, tag_init, tag_merge, id3)
		{ }
		explicit SegmentTree(int n, const ValueType& value_init, const ValueMerge& value_merge,
			const TagType& tag_init, const TagMerge& tag_merge, const TagSpread& id3) :
			SegmentTree(std::vector<ValueType>(n, value_init), value_init, value_merge, tag_init, tag_merge, id3)
		{ }
		ValueType Query(int left, int right)
		{
			assert(0 <= left && left <= right && right <= n);
			if (left == right) return value_init;
			left += size, right += size;
			for (int k = lg; k >= 1; --k)
			{
				if ((left >> k << k) != left) PushTag(left >> k);
				if ((right >> k << k) != right) PushTag((right - 1) >> k);
			}
			ValueType left_res = value_init, right_res = value_init;
			for (; left < right; left >>= 1, right >>= 1)
			{
				if (left & 1) left_res = value_merge(std::move(left_res), value[left++]);
				if (right & 1) right_res = value_merge(value[--right], std::move(right_res));
			}
			return value_merge(std::move(left_res), std::move(right_res));
		}
		ValueType Query(int pos)
		{
			assert(0 <= pos && pos < n);
			pos += size;
			for (int k = lg; k >= 1; --k) PushTag(pos >> k);
			return value[pos];
		}
		void ModifyTag(int left, int right, const TagType& add_tag)
		{
			assert(0 <= left && left <= right && right <= n);
			if (left == right) return;
			left += size, right += size;
			for (int k = lg; k >= 1; --k)
			{
				if ((left >> k << k) != left) PushTag(left >> k);
				if ((right >> k << k) != right) PushTag((right - 1) >> k);
			}
			for (int l = left, r = right; l < r; l >>= 1, r >>= 1)
			{
				if (l & 1) AddTag(l++, add_tag);
				if (r & 1) AddTag(--r, add_tag);
			}
			for (int k = 1; k <= lg; ++k)
			{
				if ((left >> k << k) != left) Update(left >> k);
				if ((right >> k << k) != right) Update((right - 1) >> k);
			}
		}
		void ModifyTag(int pos, const TagType& add_tag)
		{
			assert(0 <= pos && pos < n);
			pos += size;
			for (int k = lg; k >= 1; --k) PushTag(pos >> k);
			AddTag(pos, add_tag);
			for (int k = 1; k <= lg; ++k) Update(pos >> k);
		}
		void ModifyValue(int pos, const ValueType& new_value)
		{
			assert(0 <= pos && pos < n);
			pos += size;
			for (int k = lg; k >= 1; --k) PushTag(pos >> k);
			value[pos] = new_value;
			for (int k = 1; k <= lg; ++k) Update(pos >> k);
		}
		

		

		

		

		template<typename Checker>
		int FindFirst(int left, const Checker& check)
		{
			assert(0 <= left && left <= n);
			if (left == n) return -1;
			left += size;
			for (int k = lg; k >= 1; --k) PushTag(left >> k);
			ValueType cur = value_init;
			do
			{
				left >>= id1(left);
				if (check(value_merge(cur, value[left])))
				{
					while (left < size)
					{
						PushTag(left);
						left <<= 1;
						if (ValueType tmp = value_merge(cur, value[left]); !check(tmp))
							cur = tmp, left += 1;
					}
					return left - size + 1;
				}
				cur = value_merge(std::move(cur), value[left++]);
			} while ((left & -left) != left);
			return -1;
		}
		

		

		

		

		template<typename Checker>
		int FindLast(int right, const Checker& check)
		{
			assert(0 <= right && right <= n);
			if (right == 0) return -1;
			right += size;
			for (int k = lg; k >= 1; --k) PushTag((right - 1) >> k);
			ValueType cur = value_init;
			do
			{
				right >>= id1(right);
				if (right) right -= 1;
				if (check(value_merge(value[right], cur)))
				{
					while (right < size)
					{
						PushTag(right);
						(right <<= 1) += 1;
						if (ValueType tmp = value_merge(value[right], cur); !check(tmp))
							cur = tmp, right -= 1;
					}
					return right - size;
				}
				cur = value_merge(value[right], std::move(cur));
			} while ((right & -right) != right);
			return -1;
		}
	};
}
 




using namespace std;
using namespace io;











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
using ld = double;









const int INF = 1000000000;

void solve()
{
	int n, a, b;
	read(n, a, b);
	a -= 1;
	b -= 1;
	if (a > b) swap(a, b);
	vector<int> p(n);
	input(p);
	vector<int> res(n, INF);
	res[a] = 0;

	struct ValueType
	{
		int val;
	};
	ValueType value_init = { INF };
	auto value_merge = [](const ValueType& a, const ValueType& b) -> ValueType
	{
		return ValueType{ min(a.val, b.val) };
	};

	struct TagType
	{

	};
	TagType tag_init = { };
	auto tag_merge = [](const TagType& a, TagType& b) -> void
	{
	};
	auto id3 = [](const TagType& tag, ValueType& value) -> void
	{
	};

	for (int loop = 0; loop < 20; ++loop)
	{
		{
			vector<ValueType> init(n);
			for (auto& x : init)
				x.val = INF;
			data_structure::SegmentTree<ValueType, decltype(value_merge), TagType, decltype(tag_merge), decltype(id3)>
				tree(init, value_init, value_merge, tag_init, tag_merge, id3);

			vector<vector<int>> v(n);
			for (int i = n - 1; i >= 0; --i)
			{
				freshmin(res[i], tree.Query(i + 1, min(i + p[i], n - 1) + 1).val + 1);
				tree.ModifyValue(i, { res[i] });
				v[max(i - p[i], 0)].push_back(i);
				for (auto j : v[i])
					tree.ModifyValue(j, { INF });
			}
		}

		{
			vector<ValueType> init(n);
			for (auto& x : init)
				x.val = INF;
			data_structure::SegmentTree<ValueType, decltype(value_merge), TagType, decltype(tag_merge), decltype(id3)>
				tree(init, value_init, value_merge, tag_init, tag_merge, id3);

			vector<vector<int>> v(n);
			for (int i = 0; i < n; ++i)
			{
				freshmin(res[i], tree.Query(max(i - p[i], 0), i).val + 1);
				tree.ModifyValue(i, { res[i] });
				v[min(i + p[i], n - 1)].push_back(i);
				for (auto j : v[i])
					tree.ModifyValue(j, { INF });
			}
		}
	}

	writeln(res[b]);
}

int main()
{

	freopen("try.in", "r", stdin);
	


	int tests = 1;
	tests = next<int>();
	for (int test = 1; test <= tests; ++test)
	{
		

		solve();
	}
	return 0;
}

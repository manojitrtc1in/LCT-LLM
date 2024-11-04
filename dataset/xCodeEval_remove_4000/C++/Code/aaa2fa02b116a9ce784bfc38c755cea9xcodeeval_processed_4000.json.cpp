


using namespace std;
using ll = long long int;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



struct IOPre {
	static constexpr int TEN = 10, SZ = TEN * TEN * TEN * TEN;
	std::array<char, 4 * SZ> num;
	constexpr IOPre() : num{} {
		for (int i = 0; i < SZ; i++) {
			int n = i;
			for (int j = 3; j >= 0; j--) {
				num[i * 4 + j] = static_cast<char>(n % TEN + '0');
				n /= TEN;
			}
		}
	}
};
struct IO {

	


	

	static constexpr int SZ = 1 << 17, LEN = 32, TEN = 10, HUNDRED = TEN * TEN,
						 THOUSAND = HUNDRED * TEN, id2 = THOUSAND * TEN,
						 MAGIC_MULTIPLY = 205, MAGIC_SHIFT = 11, MASK = 15,
						 id0 = 12, SIXTEEN = 16;
	static constexpr IOPre io_pre = {};
	std::array<char, SZ> input_buffer, output_buffer;
	int id1, id6, id4;

	IO()
		: input_buffer{},
		  output_buffer{},
		  id1{},
		  id6{},
		  id4{} {}
	IO(const IO&) = delete;
	IO(IO&&) = delete;
	IO& operator=(const IO&) = delete;
	IO& operator=(IO&&) = delete;

	~IO() { flush(); }

	template <class T>
	struct is_char {
		static constexpr bool value = std::is_same_v<T, char>;
	};

	template <class T>
	struct is_bool {
		static constexpr bool value = std::is_same_v<T, bool>;
	};

	template <class T>
	struct is_string {
		static constexpr bool value =
			std::is_same_v<T, std::string> || std::is_same_v<T, const char*> ||
			std::is_same_v<T, char*> || std::is_same_v<std::decay_t<T>, char*>;
		;
	};

	template <class T, class D = void>
	struct is_custom {
		static constexpr bool value = false;
	};

	template <class T>
	struct is_custom<T, std::void_t<typename T::internal_value_type>> {
		static constexpr bool value = true;
	};

	template <class T>
	struct is_default {
		static constexpr bool value = is_char<T>::value || is_bool<T>::value ||
									  is_string<T>::value ||
									  std::is_integral_v<T>;
	};

	template <class T, class D = void>
	struct is_iterable {
		static constexpr bool value = false;
	};

	template <class T>
	struct is_iterable<
		T, typename std::void_t<decltype(std::begin(std::declval<T>()))>> {
		static constexpr bool value = true;
	};

	template <class T, class D = void, class E = void>
	struct is_applyable {
		static constexpr bool value = false;
	};

	template <class T>
	struct is_applyable<T, std::void_t<typename std::tuple_size<T>::type>,
						std::void_t<decltype(std::get<0>(std::declval<T>()))>> {
		static constexpr bool value = true;
	};

	template <class T>
	static constexpr bool id5 = (is_iterable<T>::value ||
										   is_applyable<T>::value) &&
										  (!is_default<T>::value);

	template <typename T, typename U>
	struct any_needs_newline {
		static constexpr bool value = false;
	};
	template <typename T>
	struct any_needs_newline<T, std::index_sequence<>> {
		static constexpr bool value = false;
	};
	template <typename T, std::size_t I, std::size_t... Is>
	struct any_needs_newline<T, std::index_sequence<I, Is...>> {
		static constexpr bool value =
			id5<decltype(std::get<I>(std::declval<T>()))> ||
			any_needs_newline<T, std::index_sequence<Is...>>::value;
	};

	inline void load() {
		memmove(std::begin(input_buffer),
				std::begin(input_buffer) + id1,
				id6 - id1);
		id6 =
			id6 - id1 +
			static_cast<int>(fread_unlocked(
				std::begin(input_buffer) + id6 - id1, 1,
				SZ - id6 + id1, stdin));
		id1 = 0;
	}

	inline void read_char(char& c) {
		if (id1 + LEN > id6) load();
		c = input_buffer[id1++];
	}
	inline void read_string(std::string& x) {
		char c;
		while (read_char(c), c < '!') continue;
		x = c;
		while (read_char(c), c >= '!') x += c;
	}
	template <class T>
	inline std::enable_if_t<std::is_integral_v<T>, void> read_int(T& x) {
		if (id1 + LEN > id6) load();
		char c = 0;
		do c = input_buffer[id1++];
		while (c < '-');
		[[maybe_unused]] bool minus = false;
		if constexpr (std::is_signed<T>::value == true)
			if (c == '-') minus = true, c = input_buffer[id1++];
		x = 0;
		while (c >= '0')
			x = x * TEN + (c & MASK), c = input_buffer[id1++];
		if constexpr (std::is_signed<T>::value == true)
			if (minus) x = -x;
	}

	inline void skip_space() {
		if (id1 + LEN > id6) load();
		while (input_buffer[id1] <= ' ') id1++;
	}

	inline void flush() {
		fwrite_unlocked(std::begin(output_buffer), 1, id4, stdout);
		id4 = 0;
	}

	inline void write_char(char c) {
		if (id4 > SZ - LEN) flush();
		output_buffer[id4++] = c;
	}

	inline void write_bool(bool b) {
		if (id4 > SZ - LEN) flush();
		output_buffer[id4++] = b ? '1' : '0';
	}

	inline void write_string(const std::string& s) {
		for (auto x : s) write_char(x);
	}

	inline void write_string(const char* s) {
		while (*s) write_char(*s++);
	}

	inline void write_string(char* s) {
		while (*s) write_char(*s++);
	}

	template <typename T>
	inline std::enable_if_t<std::is_integral_v<T>, void> write_int(T x) {
		if (id4 > SZ - LEN) flush();
		if (!x) {
			output_buffer[id4++] = '0';
			return;
		}
		if constexpr (std::is_signed<T>::value == true)
			if (x < 0) output_buffer[id4++] = '-', x = -x;
		int i = id0;
		std::array<char, SIXTEEN> buf{};
		while (x >= id2) {
			memcpy(std::begin(buf) + i,
				   std::begin(io_pre.num) + (x % id2) * 4, 4);
			x /= id2;
			i -= 4;
		}
		if (x < HUNDRED) {
			if (x < TEN) {
				output_buffer[id4++] = static_cast<char>('0' + x);
			} else {
				std::uint32_t q =
					(static_cast<std::uint32_t>(x) * MAGIC_MULTIPLY) >>
					MAGIC_SHIFT;
				std::uint32_t r = static_cast<std::uint32_t>(x) - q * TEN;
				output_buffer[id4] = static_cast<char>('0' + q);
				output_buffer[id4 + 1] =
					static_cast<char>('0' + r);
				id4 += 2;
			}
		} else {
			if (x < THOUSAND) {
				memcpy(std::begin(output_buffer) + id4,
					   std::begin(io_pre.num) + (x << 2) + 1, 3),
					id4 += 3;
			} else {
				memcpy(std::begin(output_buffer) + id4,
					   std::begin(io_pre.num) + (x << 2), 4),
					id4 += 4;
			}
		}
		memcpy(std::begin(output_buffer) + id4,
			   std::begin(buf) + i + 4, id0 - i);
		id4 += id0 - i;
	}
	template <typename T_>
	IO& operator<<(T_&& x) {
		using T = typename std::remove_cv<
			typename std::remove_reference<T_>::type>::type;
		static_assert(is_custom<T>::value or is_default<T>::value or
					  is_iterable<T>::value or is_applyable<T>::value);
		if constexpr (is_custom<T>::value) {
			write_int(x.get());
		} else if constexpr (is_default<T>::value) {
			if constexpr (is_bool<T>::value) {
				write_bool(x);
			} else if constexpr (is_string<T>::value) {
				write_string(x);
			} else if constexpr (is_char<T>::value) {
				write_char(x);
			} else if constexpr (std::is_integral_v<T>) {
				write_int(x);
			}
		} else if constexpr (is_iterable<T>::value) {
			

			using E = decltype(*std::begin(x));
			constexpr char sep = id5<E> ? '\n' : ' ';
			int i = 0;
			for (const auto& y : x) {
				if (i++) write_char(sep);
				operator<<(y);
			}
		} else if constexpr (is_applyable<T>::value) {
			

			constexpr char sep =
				(any_needs_newline<
					T, std::make_index_sequence<std::tuple_size_v<T>>>::value)
					? '\n'
					: ' ';
			int i = 0;
			std::apply(
				[this, &sep, &i](auto const&... y) {
					(((i++ ? write_char(sep) : void()), this->operator<<(y)),
					 ...);
				},
				x);
		}
		return *this;
	}
	template <typename T>
	IO& operator>>(T& x) {
		static_assert(is_custom<T>::value or is_default<T>::value or
					  is_iterable<T>::value or is_applyable<T>::value);
		static_assert(!is_bool<T>::value);
		if constexpr (is_custom<T>::value) {
			typename T::internal_value_type y;
			read_int(y);
			x = y;
		} else if constexpr (is_default<T>::value) {
			if constexpr (is_string<T>::value) {
				read_string(x);
			} else if constexpr (is_char<T>::value) {
				read_char(x);
			} else if constexpr (std::is_integral_v<T>) {
				read_int(x);
			}
		} else if constexpr (is_iterable<T>::value) {
			for (auto& y : x) operator>>(y);
		} else if constexpr (is_applyable<T>::value) {
			std::apply([this](auto&... y) { ((this->operator>>(y)), ...); }, x);
		}
		return *this;
	}

	IO* tie(std::nullptr_t) { return this; }
	void sync_with_stdio(bool) {}
};
IO io;



template<class B, class T, class F>
struct id3{
	vector<B> X;
	vector<vector<array<B, 2>>> Y;
	vector<vector<T>> YY;
	T Data[7500000];
    int start[400001];
	F TT; 

	T T_id; 

	

	

	id3(vector<pair<array<B, 2>, T>> &init, F _TT, T _T_id): X(init.size()), TT(_TT), T_id(_T_id){
		int n = (int)init.size();
		sort(init.begin(), init.end());
		for(auto i = 0; i < n; ++ i) X[i] = init[i].first[0];
		X.erase(unique(X.begin(), X.end()), X.end());
		YY.resize(X.size() << 1);
		vector<vector<pair<array<B, 2>, T>>> hold(X.size() << 1);
		for(auto i = 0, x = 0; i < n; ++ i){
			auto [pos, val] = init[i];
			while(X[x] < pos[0]) ++ x;
			hold[x + (int)X.size()].emplace_back(pair{array{pos[1], pos[0]}, val});
		}

		int tot = 0;
		for(auto x = 2 * (int)X.size() - 1; x; -- x){
			auto &hold0 = hold[x];
			if (x < (int)X.size()) {
				swap(hold[x], hold[x << 1]);
				int sz = hold[x].size();
				for (auto &y : hold[x << 1 | 1]) hold[x].emplace_back(y);
				inplace_merge(hold[x].begin(), hold[x].begin()+sz, hold[x].end());
			}
			else sort(hold0.begin(), hold0.end());
			auto &Y0 = YY[x];
			
			Y0.resize(hold0.size());
			for(auto j = 0; j < (int)hold0.size(); ++ j) Y0[j] = hold0[j].first[0];
			Y0.erase(unique(Y0.begin(), Y0.end()), Y0.end());
			start[x] = tot;
			tot += Y0.size() << 1;
			for (int i = 0; i < (int)Y0.size()<<1; ++i) Data[start[x] + i] = T_id;
			for(auto j = 0, y = 0; j < (int)hold0.size(); ++ j){
				while(Y0[y] < hold0[j].first[0]) ++ y;
				Data[y + (int)Y0.size() + start[x]] = TT(Data[y + (int)Y0.size() + start[x]], hold0[j].second);
			}
			for(auto y = (int)Y0.size() - 1; y; -- y) Data[y + start[x]] = TT(Data[start[x] + (y << 1)], Data[start[x] + (y << 1 | 1)]);
		}
		

		

		

		

	}
	

	void set(B _p, B _q, T x){
		int p = _p;
		for(p += (int)X.size(); p; p >>= 1){
			auto &Y0 = YY[p];
			int q = lower_bound(Y0.begin(), Y0.end(), _q) - Y0.begin();
			auto D = Data + start[p];
			for(D[(q += (int)Y0.size())] = x; q >>= 1; ) D[q] = TT(D[(q << 1)], D[(q << 1 | 1)]);
		}
	}
	

	T query(B _xl, B _xr, B _yl, B _yr, bool type = 0){
		int xl = _xl, xr = _xr;
		T res = T_id;
		for(xl += (int)X.size(), xr += (int)X.size(); xl < xr; xl >>= 1, xr >>= 1){
			if(xl & 1){
				auto &Y0 = YY[xl];
				int yl = 0;
				int yr = Y0.size();
				if (type == 0) yr = lower_bound(Y0.begin(), Y0.end(), _yr) - Y0.begin();
				else yl = lower_bound(Y0.begin(), Y0.end(), _yl) - Y0.begin();
				auto D = Data + start[xl];
				for(yl += (int)Y0.size(), yr += (int)Y0.size(); yl < yr; yl >>= 1, yr >>= 1){
					if(yl & 1) res = TT(res, D[yl ++]);
					if(yr & 1) res = TT(res, D[-- yr]);
				}
				++ xl;
			}
			if(xr & 1){
				-- xr;
				auto &Y0 = YY[xr];
				int yl = 0;
				int yr = Y0.size();
				if (type == 0) yr = lower_bound(Y0.begin(), Y0.end(), _yr) - Y0.begin();
				else yl = lower_bound(Y0.begin(), Y0.end(), _yl) - Y0.begin();
				auto D = Data + start[xr];
				for(yl += (int)Y0.size(), yr += (int)Y0.size(); yl < yr; yl >>= 1, yr >>= 1){
					if(yl & 1) res = TT(res, D[(yl ++)]);
					if(yr & 1) res = TT(res, D[(-- yr)]);
				}
			}
		}
		return res;
	}
};

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n, v; cin >> n >> v;



	int id0[n+1], tm[n+1], pos[n+1], id1[n+1], id2[n+1], id3[n+1];
	tm[0] = pos[0] = 0;
	for (int i = 0; i <= n; ++i) id0[i] = i;
	for (int i = 1; i <= n; ++i) {
		cin >> tm[i];


	}
	for (int i = 1; i <= n; ++i) cin >> pos[i];


	vector<pair<array<int, 2>, int>> pts1, pts2;
	sort(id0, id0+n+1, [&](int i, int j) {
		int t1 = tm[i], t2 = tm[j];
		int x1 = pos[i], x2 = pos[j];
		if (1LL*v*t1 - x1 == 1LL*v*t2 - x2) return i < j;
		return 1LL*v*t1 - x1 < 1LL*v*t2 - x2;
	});
	for (int i = 0; i <= n; ++i) {
		id1[id0[i]] = i;
	}
	sort(id0, id0+n+1, [&](int i, int j) {
		int t1 = tm[i], t2 = tm[j];
		int x1 = pos[i], x2 = pos[j];
		if (1LL*v*t1 + x1 == 1LL*v*t2 + x2) return i < j;
		return 1LL*v*t1 + x1 < 1LL*v*t2 + x2;
	});
	for (int i = 0; i <= n; ++i) {
		id2[id0[i]] = i;
	}
	sort(id0, id0+n+1, [&](int i, int j) {return pos[i] < pos[j];});
	for (int i = 0; i <= n; ++i) id3[id0[i]] = i;
	const int mn = -1e9 - 6;
	for (int i = 0; i <= n; ++i) {
		pts1.emplace_back(pair{array{id1[i], id3[i]}, i == 0 ? 0 : mn});
		pts2.emplace_back(pair{array{id2[i], id3[i]}, i == 0 ? 0 : mn});
	}
	
	auto combine = [] (int x, int y) {
		return max(x, y);
	};
	id3 T1(pts1, combine, mn), T2(pts2, combine, mn);
	T1.T_id = T2.T_id = mn + 5;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int val = T1.query(0, id1[i], mn, id3[i]+1);
		val = max(val, T2.query(0, id2[i], id3[i], -mn, 1)) + 1;
		ans = max(ans, val);
		T1.set(id1[i], id3[i], val);
		T2.set(id2[i], id3[i], val);
	}
	cout << ans << '\n';
}
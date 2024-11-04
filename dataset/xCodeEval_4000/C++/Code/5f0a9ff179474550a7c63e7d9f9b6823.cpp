#include <bits/stdc++.h>

template <typename A> constexpr A phi(A x) noexcept {
	A result = x;
	for (A i = static_cast <A> (2); i * i <= x; i++) {
		if (!(x % i)) {
			while (!(x % i)) {
				x /= i;
			}
			result -= result / i;
		}
	}
	if (x > static_cast <A> (1)) {
		return result - result / x;
	}
	return result;
}

template <int MOD, bool IS_PRIME = false> class Mint {
	
public:
	
	constexpr explicit operator int () const noexcept {
		return this->m_value;
	}
	
	constexpr Mint(const int _value = 0) noexcept : m_value(this->m_fix(_value)) { }
	
	template <typename A> inline Mint(const A& _value) noexcept {
		if (_value < static_cast <A> (MOD) && _value >= static_cast <A> (0)) {
			this->m_value = (int) _value;
			return;
		}
		static constexpr const __uint128_t niv = ~1ULL / MOD;
		long long llvalue = (long long) _value - ((niv * _value) >> 64LL) * MOD;
		if (llvalue < 0LL) {
			llvalue += MOD;
		}
		if (llvalue >= MOD) {
			llvalue -= MOD;
		}
		this->m_value = static_cast <int> (llvalue);
	}
	
	constexpr bool operator == (const Mint <MOD, IS_PRIME>& other) const noexcept {
		return (int) (*this) == (int) other;
	}
	
	constexpr bool operator != (const Mint <MOD, IS_PRIME>& other) const noexcept {
		return (int) (*this) != (int) other;
	}
	
	constexpr bool operator < (const Mint <MOD, IS_PRIME>& other) const noexcept {
		return (int) (*this) < (int) other;
	}
	
	constexpr Mint <MOD, IS_PRIME> operator - () const noexcept {
		return Mint <MOD, IS_PRIME> (-this->m_value + MOD);
	}
	
	inline Mint <MOD, IS_PRIME>& operator += (const Mint <MOD, IS_PRIME>& other) noexcept {
		if ((this->m_value += (int) other) >= MOD) {
			this->m_value -= MOD;
		}
		return *this;
	}
	
	inline Mint <MOD, IS_PRIME>& operator -= (const Mint <MOD, IS_PRIME>& other) noexcept {
		if ((this->m_value -= (int) other) < 0) {
			this->m_value += MOD;
		}
		return *this;
	}
	
	inline Mint <MOD, IS_PRIME>& operator *= (const Mint <MOD, IS_PRIME>& other) noexcept {
		long long value = static_cast <long long> (this->m_value) * (int) other;
		if (value < MOD && value >= 0LL) {
			this->m_value = value;
			return *this;
		}
		static constexpr const __uint128_t niv = ~1ULL / MOD;
		value -= ((niv * value) >> 64LL) * MOD;
		if (value < 0LL) {
			value += MOD;
		}
		if (value >= MOD) {
			value -= MOD;
		}
		this->m_value = static_cast <int> (value);
		return *this;
	}
	
	inline Mint <MOD, IS_PRIME>& operator /= (const Mint <MOD, IS_PRIME>& other) noexcept {
		(*this) *= inverse(other);
		return *this;
	}
	
	friend inline Mint <MOD, IS_PRIME> inverse(const Mint <MOD, IS_PRIME>& mint) noexcept {
		return pow(mint, m_phi - 1);
	}
	
	template <typename A> static inline Mint <MOD, IS_PRIME> pow(Mint <MOD, IS_PRIME> mint, A exponent) noexcept {
		static_assert (std::is_fundamental <A>::value);
		if (exponent < static_cast <A> (0)) {
			return pow(mint, exponent % m_phi + m_phi);
		}
		if (exponent >= m_phi) {
			exponent %= m_phi;
		}
		Mint <MOD, IS_PRIME> result(1);
		while (exponent) {
			if (exponent & static_cast <A> (1)) {
				result *= mint;
			}
			exponent >>= static_cast <A> (1);
			mint *= mint;
		}
		return result;
	}
	
	inline Mint <MOD, IS_PRIME>& operator ++ () noexcept {
		return *this += 1;
	}
	
	inline Mint <MOD, IS_PRIME>& operator -- () noexcept {
		return *this -= 1;
	}
	
	inline Mint <MOD, IS_PRIME> operator ++ (int) noexcept {
		return *this += 1;
	}
	
	inline Mint <MOD, IS_PRIME> operator -- (int) noexcept {
		return *this -= 1;
	}
	
	friend inline Mint <MOD, IS_PRIME> operator + (Mint <MOD, IS_PRIME> mint, const Mint <MOD, IS_PRIME>& other) noexcept {
		return mint += other;
	}
	
	friend inline Mint <MOD, IS_PRIME> operator - (Mint <MOD, IS_PRIME> mint, const Mint <MOD, IS_PRIME>& other) noexcept {
		return mint -= other;
	}
	
	friend inline Mint <MOD, IS_PRIME> operator * (Mint <MOD, IS_PRIME> mint, const Mint <MOD, IS_PRIME>& other) noexcept {
		return mint *= other;
	}
	
	friend inline Mint <MOD, IS_PRIME> operator / (Mint <MOD, IS_PRIME> mint, const Mint <MOD, IS_PRIME>& other) noexcept {
		return mint /= other;
	}
	
	static inline Mint <MOD, IS_PRIME> factorial(const size_t x) noexcept {
		if (static_cast <long long> (x) < 0LL) [[unlikely]] {
			return Mint <MOD, IS_PRIME> (0);
		}
		static size_t ready = static_cast <size_t> (1);
		static std::vector <Mint <MOD, IS_PRIME>> result(2, Mint <MOD, IS_PRIME> (1));
		if (x <= ready) [[likely]] {
			return result[x];
		}
		const size_t next = x + (x >> static_cast <size_t> (4));
		result.resize(next + 1);
		for (size_t i = ready + 1; i <= next; i++) {
			result[i] = result[i - 1] * Mint <MOD, IS_PRIME> (i);
		}
		ready = next;
		return result[x];
	}
	
	static inline Mint <MOD, IS_PRIME> inverse_factorial(const size_t x) noexcept {
		if (static_cast <long long> (x) < 0LL) [[unlikely]] {
			return Mint <MOD, IS_PRIME> (0);
		}
		static size_t ready = static_cast <size_t> (1);
		static std::vector <Mint <MOD, IS_PRIME>> result(2, Mint <MOD, IS_PRIME> (1));
		if (x <= ready) [[likely]] {
			return result[x];
		}
		const size_t next = x + (x >> static_cast <size_t> (4));
		result.resize(next + 1);
		result[next] = inverse(factorial(next));
		for (size_t i = next - 1; i > ready; i--) {
			result[i] = result[i + 1] * Mint <MOD, IS_PRIME> (i + 1);
		}
		ready = next;
		return result[x];
	}
	
	static inline Mint <MOD, IS_PRIME> choose(const size_t n, const size_t k) noexcept {
		if (static_cast <long long> (k) < 0LL || k > n) [[unlikely]] {
			return Mint <MOD, IS_PRIME> (0);
		}
		return factorial(n) * inverse_factorial(k) * inverse_factorial(n - k);
	}
	
	friend inline std::ostream& operator << (std::ostream& stream, const Mint <MOD, IS_PRIME>& mint) {
		return stream << (int) mint;
	}
	
	friend inline std::istream& operator >> (std::istream& stream, Mint <MOD, IS_PRIME>& mint) {
		stream >> mint.m_value;
		mint.m_value = mint.m_fix(mint.m_value);
		return stream;
	}
	
	template <std::istream& STREAM = std::cin> inline void readl() {
		long long value;
		STREAM >> value;
		if (value < MOD && value >= 0LL) {
			this->m_value = value;
			return;
		}
		static constexpr const __uint128_t niv = ~1ULL / MOD;
		value -= ((niv * value) >> 64LL) * MOD;
		if (value < 0LL) {
			value += MOD;
		}
		if (value >= MOD) {
			value -= MOD;
		}
		this->m_value = static_cast <int> (value);
	}
	
private:
	
	int m_value;
	
	static constexpr int m_phi = IS_PRIME ? MOD - 1 : phi <int> (MOD);
	
	constexpr int m_fix(int value) const noexcept {
		if (value < MOD && value >= 0) {
			return value;
		}
		if (value < 0) {
			value = (value % MOD) + MOD;
		}
		if (value >= MOD) {
			if constexpr ((std::numeric_limits <int>::max() >> 2) < MOD) {
				while (value >= MOD) {
					value -= MOD;
				}
			} else {
				value %= MOD;
			}
		}
		return value;
	}
	
};

#ifndef no_mi
#ifdef mi9
typedef Mint <998244353, true> mi;
#else
typedef Mint <1000000007, true> mi;
#endif
#endif

template <typename node> class Segtree {
	
public:
	
	int size, n_size;
	std::vector <node> v;
	
	Segtree(int _size) :
	n_size(_size)
	{
		assert(_size > 0);
		size = 1;
		while (size < _size) {
			size <<= 1;
		}
		v.resize(size << 1, node { });
		make();
	}
	
	template <typename A> Segtree(const std::vector <A>& _v) :
	n_size(_v.size())
	{
		assert(!_v.empty());
		size = 1;
		while (size < (int)_v.size()) {
			size <<= 1;
		}
		v.resize(size << 1, node { });
		make(_v);
	}
	
	template <typename A> Segtree(int _size, const std::vector <A>& _v) :
	n_size(_size)
	{
		assert(_size > 0);
		size = 1;
		while (size < _size) {
			size <<= 1;
		}
		v.resize(size << 1, node { });
		make(_v);
	}
	
	void make() {
		m_make(0, 0, size);
	}
	
	template <typename A> void make(const std::vector <A>& _v) {
		m_make(_v, 0, 0, size);
	}
	
	template <typename... A> void update(int ind, const A&... arg) {
		assert(ind >= 0 && ind < size);
		m_update(ind, 0, 0, size, arg...);
	}
	
	node query(int l, int r) {
		assert(l >= 0 && l < r && r <= size);
		return m_query(l, r, 0, 0, size);
	}
	
	node query() {
		return query(0, n_size);
	}
	
	int find_first(int l, int r, const std::function <bool(const node&)>& check) {
		assert(l >= 0 && l < r && r <= size);
		return m_find_first(l, r, 0, 0, size, check);
	}
	
	int find_first(const std::function <bool(const node&)>& check) {
		return find_first(0, size, check);
	}
	
	int find_last(int l, int r, const std::function <bool(const node&)>& check) {
		assert(l >= 0 && l < r && r <= size);
		return m_find_last(l, r, 0, 0, size, check);
	}
	
	int find_last(const std::function <bool(const node&)>& check) {
		return find_last(0, size, check);
	}
	
private:
	
	inline int m_mid(int l, int r) {
		return (l + r) >> 1;
	}
	
	inline bool m_outside(int l, int r, int tl, int tr) {
		return l >= tr || r <= tl;
	}
	
	void m_make(int now, int l, int r) {
		if (!(r - l - 1)) {
			return;
		}
		int mid = m_mid(l, r);
		m_make((now << 1) + 1, l, mid);
		m_make((now << 1) + 2, mid, r);
		v[now] = node::merge(v[(now << 1) + 1], v[(now << 1) + 2]);
	}
	
	template <typename A> void m_make(const std::vector <A>& _v, int now, int l, int r) {
		if (!(r - l - 1)) {
			if (l < (int)_v.size()) {
				v[now].apply(_v[l]);
			}
			return;
		}
		int mid = m_mid(l, r);
		m_make(_v, (now << 1) + 1, l, mid);
		m_make(_v, (now << 1) + 2, mid, r);
		v[now] = node::merge(v[(now << 1) + 1], v[(now << 1) + 2]);
	}
	
	template <typename... A> void m_update(int ind, int now, int l, int r, const A&... arg) {
		if (!(r - l - 1)) {
			v[now].apply(arg...);
			return;
		}
		int mid = m_mid(l, r);
		if (ind < mid) {
			m_update(ind, (now << 1) + 1, l, mid, arg...);
		} else {
			m_update(ind, (now << 1) + 2, mid, r, arg...);
		}
		v[now] = node::merge(v[(now << 1) + 1], v[(now << 1) + 2]);
	}
	
	node m_query(int tl, int tr, int now, int l, int r) {
		if (l >= tl && r <= tr) {
			return v[now];
		}
		int mid = m_mid(l, r);
		node ret { };
		if (m_outside(l, mid, tl, tr)) {
			ret = m_query(tl, tr, (now << 1) + 2, mid, r);
		} else {
			if (m_outside(mid, r, tl, tr)) {
				ret = m_query(tl, tr, (now << 1) + 1, l, mid);
			} else {
				ret = node::merge(
				m_query(tl, tr, (now << 1) + 1, l, mid),
				m_query(tl, tr, (now << 1) + 2, mid, r));
			}
		}
		return ret;
	}
	
	int m_find_first_exists(int now, int l, int r,
	const std::function <bool(const node&)>& check) {
		if (!(r - l - 1)) {
			return l;
		}
		int mid = m_mid(l, r);
		if (check(v[(now << 1) + 1])) {
			return m_find_first_exists((now << 1) + 1, l, mid, check);
		}
		return m_find_first_exists((now << 1) + 2, mid, r, check);
	}
	
	int m_find_first(int tl, int tr, int now, int l, int r,
	const std::function <bool(const node&)>& check) {
		if (l >= tl && r <= tr) {
			if (!check(v[now])) {
				return -1;
			}
			return m_find_first_exists(now, l, r, check);
		}
		int mid = m_mid(l, r);
		int ret = -1;
		if (!m_outside(l, mid, tl, tr)) {
			ret = m_find_first(tl, tr, (now << 1) + 1, l, mid, check);
		}
		if (!m_outside(mid, r, tl, tr) && ret == -1) {
			ret = m_find_first(tl, tr, (now << 1) + 2, mid, r, check);
		}
		return ret;
	}
	
	int m_find_last_exists(int now, int l, int r,
	const std::function <bool(const node&)>& check) {
		if (!(r - l - 1)) {
			return l;
		}
		int mid = m_mid(l, r);
		if (check(v[(now << 1) + 2])) {
			return m_find_last_exists((now << 1) + 2, mid, r, check);
		}
		return m_find_last_exists((now << 1) + 1, l, mid, check);
	}
	
	int m_find_last(int tl, int tr, int now, int l, int r,
	const std::function <bool(const node&)>& check) {
		if (l >= tl && r <= tr) {
			if (!check(v[now])) {
				return -1;
			}
			return m_find_last_exists(now, l, r, check);
		}
		int mid = m_mid(l, r);
		int ret = -1;
		if (!m_outside(mid, r, tl, tr)) {
			ret = m_find_last(tl, tr, (now << 1) + 2, mid, r, check);
		}
		if (!m_outside(l, mid, tl, tr) && ret == -1) {
			ret = m_find_last(tl, tr, (now << 1) + 1, l, mid, check);
		}
		return ret;
	}
	
};

struct Node {
	
	mi x = 0;
	
	constexpr void apply(mi v) {
		x = v;
	}
	
	static Node merge(const Node& l, const Node& r) {
		return { l.x + r.x };
	}
	
};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int t; std::cin >> t;
	while (t--) {
		int n; std::cin >> n;
		Segtree <Node> seg(n + 1);
		seg.update(n, 2);
		for (int i = n - 1; i > 1; i--) {
			seg.update(i, seg.query(i + 1, std::min(i * 2 - 1, n) + 1).x);
		}
		for (int i = 1; i <= n; i++) {
			std::cout << mi::pow(mi(2), i / 2) * seg.query(i, i + 1).x / mi::pow(mi(2), n) << "\n";
		}
	}
	
}

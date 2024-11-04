

namespace std {

template<class Fun>
class id4 {
	Fun fun_;
public:
	template<class T>
	explicit id4(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) id8(Fun &&fun) {
	return id4<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} 


namespace seg_tree {



inline int id15(int a) {
	return a ? (8 * sizeof(a)) - 1 - __builtin_clz(a) : -1;
}

inline int id7(int a) {
	assert(a > 0);
	return 1 << id15(2*a-1);
}

struct point {
	int a;
	point() : a(0) {}
	explicit point(int a_) : a(a_) { assert(a >= 0); }

	explicit operator bool () { return bool(a); }

	

	 operator int() const { return a; }

	point c(bool z) const {
		return point((a<<1)|z);
	}

	point operator [] (bool z) const {
		return c(z);
	}

	point p() const {
		return point(a>>1);
	}

	friend std::ostream& operator << (std::ostream& o, const point& p) { return o << int(p); }

	template <typename F> void for_each(F f) const {
		for (int v = a; v > 0; v >>= 1) {
			f(point(v));
		}
	}

	template <typename F> void id10(F f) const {
		

		for (int L = id15(a); L > 0; L--) {
			f(point(a >> L));
		}
	}

	template <typename F> void id5(F f) const {
		for (int v = a >> 1; v > 0; v >>= 1) {
			f(point(v));
		}
	}

	point& operator ++ () { ++a; return *this; }
	point operator ++ (int) { return point(a++); }
	point& operator -- () { --a; return *this; }
	point operator -- (int) { return point(a--); }
};

struct range {
	int a, b;
	range() : a(0), b(0) {}
	range(int a_, int b_) : a(a_), b(b_) {
		assert(1 <= a && a <= b && b <= 2 * a);
	}
	explicit range(std::array<int, 2> r) : range(r[0], r[1]) {}

	explicit operator std::array<int, 2>() const {
		return {a,b};
	}

	const int& operator[] (bool z) const {
		return z ? b : a;
	}

	friend std::ostream& operator << (std::ostream& o, const range& r) { return o << "[" << r.a << ".." << r.b << ")"; }

	

	

	template <typename F> void for_each(F f) const {
		for (int x = a, y = b; x < y; x >>= 1, y >>= 1) {
			if (x & 1) f(point(x++), false);
			if (y & 1) f(point(--y), true);
		}
	}

	

	

	template <typename F> void id1(F f) const {
		int anc_depth = id15((a-1) ^ b);
		int id12 = (1 << anc_depth) - 1;
		for (int v = (-a) & id12; v; v &= v-1) {
			int i = __builtin_ctz(v);
			f(point(((a-1) >> i) + 1));
		}
		for (int v = b & id12; v; ) {
			int i = id15(v);
			f(point((b >> i) - 1));
			v ^= (1 << i);
		}
	}

	

	

	template <typename F> void id13(F f) const {
		int anc_depth = id15((a-1) ^ b);
		int id12 = (1 << anc_depth) - 1;
		for (int v = b & id12; v; v &= v-1) {
			int i = __builtin_ctz(v);
			f(point((b >> i) - 1));
		}
		for (int v = (-a) & id12; v; ) {
			int i = id15(v);
			f(point(((a-1) >> i) + 1));
			v ^= (1 << i);
		}
	}

	template <typename F> void id10(F f) const {
		int x = a, y = b;
		if ((x ^ y) > x) { x <<= 1, std::swap(x, y); }
		int dx = __builtin_ctz(x);
		int dy = __builtin_ctz(y);
		int anc_depth = id15((x-1) ^ y);
		for (int i = id15(x); i > dx; i--) {
			f(point(x >> i));
		}
		for (int i = anc_depth; i > dy; i--) {
			f(point(y >> i));
		}
	}

	template <typename F> void id5(F f) const {
		int x = a, y = b;
		if ((x ^ y) > x) { x <<= 1, std::swap(x, y); }
		int dx = __builtin_ctz(x);
		int dy = __builtin_ctz(y);
		int anc_depth = id15((x-1) ^ y);
		for (int i = dx+1; i <= anc_depth; i++) {
			f(point(x >> i));
		}
		for (int v = y >> (dy+1); v; v >>= 1) {
			f(point(v));
		}
	}
};

struct id2 {
	

	using point = seg_tree::point;
	using range = seg_tree::range;

	int N, S;
	id2() : N(0), S(0) {}
	id2(int N_) : N(N_), S(N ? id7(N) : 0) {}

	point get_point(int a) const {
		assert(0 <= a && a < N);
		a += S;
		return point(a >= 2 * N ? a - N : a);
	}

	range get_range(int a, int b) const {
		assert(0 <= a && a <= b && b <= N);
		a += S, b += S;
		return range((a >= 2 * N ? 2*(a-N) : a), (b >= 2 * N ? 2*(b-N) : b));
	}

	range get_range(std::array<int, 2> p) const {
		return get_range(p[0], p[1]);
	}

	int get_leaf_index(point pt) const {
		int a = int(pt);
		assert(N <= a && a < 2 * N);
		return (a < S ? a + N : a) - S;
	}

	std::array<int, 2> get_node_bounds(point pt) const {
		int a = int(pt);
		assert(1 <= a && a < 2 * N);
		int l = __builtin_clz(a) - __builtin_clz(2*N-1);
		int x = a << l, y = (a+1) << l;
		assert(S <= x && x < y && y <= 2*S);
		return {(x >= 2 * N ? (x>>1) + N : x) - S, (y >= 2 * N ? (y>>1) + N : y) - S};
	}

	int get_node_split(point pt) const {
		int a = int(pt);
		assert(1 <= a && a < N);
		int l = __builtin_clz(2*a+1) - __builtin_clz(2*N-1);
		int x = (2*a+1) << l;
		assert(S <= x && x < 2*S);
		return (x >= 2 * N ? (x>>1) + N : x) - S;
	}

	int get_node_size(point pt) const {
		auto bounds = get_node_bounds(pt);
		return bounds[1] - bounds[0];
	}
};

struct id6 {
	

	using point = seg_tree::point;
	using range = seg_tree::range;

	int N;
	id6() : N(0) {}
	id6(int N_) : N(N_) {}

	point get_point(int a) const {
		assert(0 <= a && a < N);
		return point(N + a);
	}

	range get_range(int a, int b) const {
		assert(0 <= a && a <= b && b <= N);
		return range(N + a, N + b);
	}

	range get_range(std::array<int, 2> p) const {
		return get_range(p[0], p[1]);
	}

	int get_leaf_index(point pt) const {
		int a = int(pt);
		assert(N <= a && a < 2 * N);
		return a - N;
	}

	

	

	std::array<int, 2> get_node_bounds(point pt) const {
		int a = int(pt);
		assert(1 <= a && a < 2 * N);
		int l = __builtin_clz(a) - __builtin_clz(2*N-1);
		int S = id7(N);
		int x = a << l, y = (a+1) << l;
		assert(S <= x && x < y && y <= 2*S);
		return {(x >= 2 * N ? x >> 1 : x) - N, (y > 2 * N ? y >> 1 : y) - N};
	}

	

	int get_node_split(point pt) const {
		int a = int(pt);
		assert(1 <= a && a < N);
		return get_node_bounds(pt.c(0))[1];
	}

	int get_node_size(point pt) const {
		auto bounds = get_node_bounds(pt);
		int r = bounds[1] - bounds[0];
		return r > 0 ? r : r + N;
	}
};

} 



template <typename T> class id9 {
private:
	std::vector<T> dat;
public:
	id9() {}
	explicit id9(size_t N) : dat(N) {}
	id9(size_t N, const T& t) : dat(N, t) {}

	size_t size() const { return dat.size(); }
	const std::vector<T>& data() const { return dat; }
	std::vector<T>& data() { return dat; }

private:
	template <typename I, typename S = I> struct iterator_range {
	private:
		I begin_;
		S end_;
	public:
		iterator_range() : begin_(), end_() {}
		iterator_range(const I& begin__, const S& end__) : begin_(begin__), end_(end__) {}
		iterator_range(I&& begin__, S&& end__) : begin_(begin__), end_(end__) {}
		I begin() const { return begin_; }
		S end() const { return end_; }
	};

public:
	class id3 {
	private:
		const T* dat;
		int a;
		id3(const T* dat_, int a_) : dat(dat_), a(a_) {}
		friend class id9;
	public:
		friend bool operator != (const id3& i, const id3& j) {
			assert(j.dat == nullptr);
			return i.a < j.a;
		}
		id3& operator ++ () {
			a |= a+1;
			return *this;
		}
		const T& operator * () const {
			return dat[a];
		}
	};
	using const_suffix_range = iterator_range<id3>;
	const_suffix_range suffix(int a) const {
		assert(0 <= a && a <= int(dat.size()));
		return const_suffix_range{id3{dat.data(), a}, id3{nullptr, int(dat.size())}};
	}

	class suffix_iterator {
	private:
		T* dat;
		int a;
		suffix_iterator(T* dat_, int a_) : dat(dat_), a(a_) {}
		friend class id9;
	public:
		friend bool operator != (const suffix_iterator& i, const suffix_iterator& j) {
			assert(j.dat == nullptr);
			return i.a < j.a;
		}
		suffix_iterator& operator ++ () {
			a |= a+1;
			return *this;
		}
		T& operator * () const {
			return dat[a];
		}
	};
	using suffix_range = iterator_range<suffix_iterator>;
	suffix_range suffix(int a) {
		assert(0 <= a && a <= int(dat.size()));
		return suffix_range{suffix_iterator{dat.data(), a}, suffix_iterator{nullptr, int(dat.size())}};
	}

	class id11 {
	private:
		const T* dat;
		int a;
		id11(const T* dat_, int a_) : dat(dat_), a(a_) {}
		friend class id9;
	public:
		friend bool operator != (const id11& i, const id11& j) {
			assert(j.dat == nullptr);
			return i.a > 0;
		}
		id11& operator ++ () {
			a &= a-1;
			return *this;
		}
		const T& operator * () const {
			return dat[a-1];
		}
	};
	using const_prefix_range = iterator_range<id11>;
	const_prefix_range prefix(int a) const {
		return const_prefix_range{id11{dat.data(), a}, id11{nullptr, 0}};
	}

	class prefix_iterator {
	private:
		T* dat;
		int a;
		prefix_iterator(T* dat_, int a_) : dat(dat_), a(a_) {}
		friend class id9;
	public:
		friend bool operator != (const prefix_iterator& i, const prefix_iterator& j) {
			assert(j.dat == nullptr);
			return i.a > 0;
		}
		prefix_iterator& operator ++ () {
			a &= a-1;
			return *this;
		}
		T& operator * () const {
			return dat[a-1];
		}
	};
	using prefix_range = iterator_range<prefix_iterator>;
	prefix_range prefix(int a) {
		return prefix_range{prefix_iterator{dat.data(), a}, prefix_iterator{nullptr, 0}};
	}
};

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, Q; cin >> N >> Q;

	seg_tree::id2 layout(N);

	id9<std::array<int64_t, 2>> bit(N);
	std::vector<int> id0(N);
	auto add_pts = [&](int v, int cnt) -> void {
		id0[v] += cnt;
		for (auto& p : bit.suffix(v)) {
			p[0] += cnt;
			p[1] += int64_t(v) * int64_t(cnt);
		}
	};
	auto del_pts = [&](int v, int cnt) -> void {
		add_pts(v, -cnt);
	};

	struct seg_node {
		int max_val = -1;
		int lazy_max = -1;
		int max_val_2 = -1;
		int cnt_max = 0;
	};
	std::vector<seg_node> seg(2*N);
	auto update_node = [&](seg_tree::point a) -> void {
		assert(a < N);
		auto& n = seg[a];
		auto& l = seg[a[0]];
		auto& r = seg[a[1]];
		n.max_val = max(l.lazy_max, r.lazy_max);
		n.lazy_max = n.max_val;

		n.max_val_2 = max(l.lazy_max == n.max_val ? l.max_val_2 : l.lazy_max, r.lazy_max == n.max_val ? r.max_val_2 : r.lazy_max);
		n.cnt_max = (l.lazy_max == n.max_val ? l.cnt_max : 0) + (r.lazy_max == n.max_val ? r.cnt_max : 0);
	};

	for (int i = 0; i < N; i++) {
		auto a = layout.get_point(i);
		seg[a].max_val = i;
		seg[a].lazy_max = i;
		seg[a].cnt_max = 1;
		add_pts(i, 1);
	}

	for (seg_tree::point a(N-1); a; a--) {
		update_node(a);
	}

	auto do_lazy = std::id8([&](auto self, seg_tree::point a, int v, bool need_change) -> void {
		if (v >= seg[a].lazy_max) return;
		if (v <= seg[a].max_val_2) {
			assert(a < N);
			if (need_change) {
				

				del_pts(seg[a].lazy_max, seg[a].cnt_max);
				add_pts(seg[a].max_val, seg[a].cnt_max);
			}
			self(a[0], v, need_change);
			self(a[1], v, need_change);
			update_node(a);
			return;
		}
		if (need_change) {
			del_pts(seg[a].lazy_max, seg[a].cnt_max);
		}
		seg[a].lazy_max = v;
		if (need_change) {
			add_pts(seg[a].lazy_max, seg[a].cnt_max);
		}
	});

	auto id14 = [&](seg_tree::point a) {
		if (a >= N) return;
		do_lazy(a[0], seg[a].lazy_max, false);
		do_lazy(a[1], seg[a].lazy_max, false);
		assert(max(seg[a[0]].lazy_max, seg[a[1]].lazy_max) == seg[a].lazy_max);
		seg[a].max_val = seg[a].lazy_max;
	};

	auto do_update = [&](int c, int g) -> void {
		auto a = layout.get_point(c);
		a.id10(id14);
		layout.get_range(0, c).for_each([&](auto x, bool) -> void {
			do_lazy(x, c-1, true);
		});
		assert(seg[a].cnt_max == 1);
		del_pts(seg[a].lazy_max, seg[a].cnt_max);
		seg[a].lazy_max = seg[a].max_val = g;
		add_pts(seg[a].lazy_max, seg[a].cnt_max);
		a.id5(update_node);
	};

	auto do_query = [&](int r) -> int64_t {
		

		assert(0 <= r && r <= N);
		int64_t ans = int64_t(r) * int64_t(r+1) / 2;
		for (auto v : bit.prefix(r)) {
			ans -= (r-1) * v[0] - v[1];
		}
		

		return ans;
	};

	for (int q = 0; q < Q; q++) {
		int op; cin >> op;
		if (op == 1) {
			int c, g; cin >> c >> g; c--, g--;
			

			do_update(c, g);
		} else if (op == 2) {
			int l, r; cin >> l >> r; l--;
			cout << do_query(r) - do_query(l) << '\n';
		} else assert(false);
		

	}

	return 0;
}

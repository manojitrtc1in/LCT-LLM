


template <typename T> class id13 {
private:
	std::vector<T> dat;
public:
	id13() {}
	explicit id13(size_t N) : dat(N) {}
	id13(size_t N, const T& t) : dat(N, t) {}

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
	class id5 {
	private:
		const T* dat;
		int a;
		id5(const T* dat_, int a_) : dat(dat_), a(a_) {}
		friend class id13;
	public:
		friend bool operator != (const id5& i, const id5& j) {
			assert(j.dat == nullptr);
			return i.a < j.a;
		}
		id5& operator ++ () {
			a |= a+1;
			return *this;
		}
		const T& operator * () const {
			return dat[a];
		}
	};
	using const_suffix_range = iterator_range<id5>;
	const_suffix_range suffix(int a) const {
		assert(0 <= a && a <= int(dat.size()));
		return const_suffix_range{id5{dat.data(), a}, id5{nullptr, int(dat.size())}};
	}

	class suffix_iterator {
	private:
		T* dat;
		int a;
		suffix_iterator(T* dat_, int a_) : dat(dat_), a(a_) {}
		friend class id13;
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

	class id15 {
	private:
		const T* dat;
		int a;
		id15(const T* dat_, int a_) : dat(dat_), a(a_) {}
		friend class id13;
	public:
		friend bool operator != (const id15& i, const id15& j) {
			assert(j.dat == nullptr);
			return i.a > 0;
		}
		id15& operator ++ () {
			a &= a-1;
			return *this;
		}
		const T& operator * () const {
			return dat[a-1];
		}
	};
	using const_prefix_range = iterator_range<id15>;
	const_prefix_range prefix(int a) const {
		return const_prefix_range{id15{dat.data(), a}, id15{nullptr, 0}};
	}

	class prefix_iterator {
	private:
		T* dat;
		int a;
		prefix_iterator(T* dat_, int a_) : dat(dat_), a(a_) {}
		friend class id13;
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

namespace seg_tree {



inline int id20(int a) {
	return a ? (8 * sizeof(a)) - 1 - __builtin_clz(a) : -1;
}

inline int id12(int a) {
	assert(a > 0);
	return 1 << id20(2*a-1);
}

struct point {
	int a;
	point() : a(0) {}
	explicit point(int a_) : a(a_) { assert(a >= -1); }

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

	template <typename F> void id14(F f) const {
		

		for (int L = id20(a); L > 0; L--) {
			f(point(a >> L));
		}
	}

	template <typename F> void id9(F f) const {
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
	range() : a(1), b(1) {}
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
			if (x & 1) f(point(x++));
			if (y & 1) f(point(--y));
		}
	}

	

	

	template <typename F> void id10(F f) const {
		for (int x = a, y = b; x < y; x >>= 1, y >>= 1) {
			if (x & 1) f(point(x++), false);
			if (y & 1) f(point(--y), true);
		}
	}

	

	

	template <typename F> void id2(F f) const {
		int anc_depth = id20((a-1) ^ b);
		int id16 = (1 << anc_depth) - 1;
		for (int v = (-a) & id16; v; v &= v-1) {
			int i = __builtin_ctz(v);
			f(point(((a-1) >> i) + 1));
		}
		for (int v = b & id16; v; ) {
			int i = id20(v);
			f(point((b >> i) - 1));
			v ^= (1 << i);
		}
	}

	

	

	template <typename F> void id17(F f) const {
		int anc_depth = id20((a-1) ^ b);
		int id16 = (1 << anc_depth) - 1;
		for (int v = b & id16; v; v &= v-1) {
			int i = __builtin_ctz(v);
			f(point((b >> i) - 1));
		}
		for (int v = (-a) & id16; v; ) {
			int i = id20(v);
			f(point(((a-1) >> i) + 1));
			v ^= (1 << i);
		}
	}

	template <typename F> void id14(F f) const {
		int x = a, y = b;
		if ((x ^ y) > x) { x <<= 1, std::swap(x, y); }
		int dx = __builtin_ctz(x);
		int dy = __builtin_ctz(y);
		int anc_depth = id20((x-1) ^ y);
		for (int i = id20(x); i > dx; i--) {
			f(point(x >> i));
		}
		for (int i = anc_depth; i > dy; i--) {
			f(point(y >> i));
		}
	}

	template <typename F> void id9(F f) const {
		int x = a, y = b;
		if ((x ^ y) > x) { x <<= 1, std::swap(x, y); }
		int dx = __builtin_ctz(x);
		int dy = __builtin_ctz(y);
		int anc_depth = id20((x-1) ^ y);
		for (int i = dx+1; i <= anc_depth; i++) {
			f(point(x >> i));
		}
		for (int v = y >> (dy+1); v; v >>= 1) {
			f(point(v));
		}
	}
};

struct id3 {
	

	using point = seg_tree::point;
	using range = seg_tree::range;

	int N, S;
	id3() : N(0), S(0) {}
	id3(int N_) : N(N_), S(N ? id12(N) : 0) {}

	point get_point(int a) const {
		assert(0 <= a && a < N);
		a += S;
		return point(a >= 2 * N ? a - N : a);
	}

	range get_range(int a, int b) const {
		assert(0 <= a && a <= b && b <= N);
		if (N == 0) return range();
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

struct id11 {
	

	using point = seg_tree::point;
	using range = seg_tree::range;

	int N;
	id11() : N(0) {}
	id11(int N_) : N(N_) {}

	point get_point(int a) const {
		assert(0 <= a && a < N);
		return point(N + a);
	}

	range get_range(int a, int b) const {
		assert(0 <= a && a <= b && b <= N);
		if (N == 0) return range();
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
		int S = id12(N);
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


int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	std::vector<int> P(N);
	for (auto& a : P) { cin >> a; a--; }

	id13<int> bit_idx(N);
	id13<int> bit_val(N);
	for (int i = 0; i < N; i++) {
		for (auto& a : bit_idx.suffix(i)) a++;
		for (auto& a : bit_val.suffix(i)) a++;
	}

	seg_tree::id3 layout(2*N);

	std::vector<int> id4(4*N, 2*N+1);
	for (int i = 0; i < N; i++) {
		if (i <= P[i]) {
			

			id4[layout.get_point(i+N)] = P[i]+N;
		} else {
			

			id4[layout.get_point(P[i])] = i;
		}
	}
	for (auto a = seg_tree::point(2*N-1); a; a--) {
		id4[a] = std::min(id4[a.c(0)], id4[a.c(1)]);
	}

	const int INF = 1e9;
	struct seg_node {
		int best = INF;
		int lazy = 0;
		std::array<int, 2> first{-1, -1};
		std::array<int, 2> last{-1, -1};
	};
	std::vector<seg_node> seg(4*N);
	auto update_node = [&](seg_tree::point a) -> void {
		if (seg[a.c(0)].first[0] != -1) {
			seg[a].first = seg[a.c(0)].first;
		} else {
			seg[a].first = seg[a.c(1)].first;
		}
		if (seg[a.c(1)].last[0] != -1) {
			seg[a].last = seg[a.c(1)].last;
		} else {
			seg[a].last = seg[a.c(0)].last;
		}
		seg[a].best = std::min(seg[a.c(0)].best, seg[a.c(1)].best);
		assert(seg[a].lazy == 0);
	};
	auto apply_lazy = [&](seg_tree::point a, int v) -> void {
		seg[a].best += v;
		seg[a].lazy += v;
	};
	auto id19 = [&](seg_tree::point a) -> void {
		apply_lazy(a.c(0), seg[a].lazy);
		apply_lazy(a.c(1), seg[a].lazy);
		seg[a].lazy = 0;
	};

	auto id8 = [&](int l, int r) {
		int val = 0;
		if (l >= N) {
			

			assert(P[l-N] == r-N);
			for (auto a : bit_idx.prefix(l-N)) val -= a;
			for (auto a : bit_val.prefix(r-N)) val += a;
		} else {
			assert(P[r] == l);
			for (auto a : bit_val.prefix(l)) val -= a;
			for (auto a : bit_idx.prefix(r)) val += a;
		}
		

		auto a = layout.get_point(l);
		a.id14(id19);
		seg[a].best = val;
		seg[a].lazy = 0;
		seg[a].first = seg[a].last = {l, r};
		a.id9(update_node);
	};

	auto id6 = [&](int orig_l) {
		

		int id18 = -1, id0 = -1;
		layout.get_range(0, orig_l).id2([&](auto a) -> void {
			if (seg[a].last[0] != -1) {
				id18 = seg[a].last[0];
				id0 = seg[a].last[1];
			}
		});
		int id1 = 2*N, id7 = 2*N;
		layout.get_range(orig_l+1, 2*N).id17([&](auto a) -> void {
			if (seg[a].first[0] != -1) {
				id1 = seg[a].first[0];
				id7 = seg[a].first[1];
			}
		});
		

		while(id1 - id18 > 1) {
			auto rng = layout.get_range(id18 + 1, id1);
			int best_r = 2*N+1;
			rng.for_each([&](auto a) -> void {
				best_r = std::min(best_r, id4[a]);
			});
			assert(best_r > id0);
			if (best_r >= id7) break;
			int best_l = -1;
			rng.for_each([&](auto a) -> void {
				if (id4[a] == best_r) {
					while (a < 2*N) {
						a = a.c(id4[a.c(1)] == best_r);
						assert(id4[a] == best_r);
					}
					assert(id4[a] == best_r);
					best_l = layout.get_leaf_index(a);
				}
			});
			assert(best_l != -1);

			auto p = layout.get_point(best_l);
			assert(id4[p] == best_r);
			id4[p] = 2*N+1;
			p.id9([&](auto a) {
				id4[a] = std::min(id4[a.c(0)], id4[a.c(1)]);
			});

			id8(best_l, best_r);
			id18 = best_l;
			id0 = best_r;
		}
	};
	id6(0);

	auto reduce_seg = [&](int l, int r) -> void {
		

		

		int bad_l = -1;
		{
			auto rng = layout.get_range(0, l);
			rng.id17([&](auto a) ->void {
				if (bad_l != -1) return;
				if (seg[a].first[0] == -1 || seg[a].first[1] > r) return;
				while (a < 2*N) {
					if (seg[a.c(1)].first[0] != -1 && seg[a.c(1)].first[1] <= r) a = a.c(1);
					else a = a.c(0);
				}
				bad_l = layout.get_leaf_index(a);
			});
		}

		auto rng = layout.get_range(bad_l+1, l);
		rng.id14(id19);
		rng.for_each([&](auto a) -> void {
			apply_lazy(a, -1);
		});
		rng.id9(update_node);
	};

	int ans = -1;

	std::vector<int> q; q.reserve(N);
	for (int z = 0; z < N; z++) {
		while (seg[1].best <= ans || z == int(q.size())) {
			if (seg[1].best > ans) {
				assert(z == int(q.size()));
				ans = seg[1].best;
			}
			auto a = seg_tree::point(1);
			while (a < 2*N) {
				assert(seg[a].best == ans);
				id19(a);
				a = a.c(seg[a.c(1)].best == ans);
			}
			assert(seg[a].best == ans);
			assert(seg[a].first == seg[a].last);
			auto [l, r] = seg[a].first;
			seg[a].best = INF;
			seg[a].lazy = 0;
			seg[a].first = seg[a].last = {-1, -1};
			a.id9(update_node);
			assert(l == layout.get_leaf_index(a));

			if (l >= N) {
				

				q.push_back(l-N);
			} else {
				

				q.push_back(r);
			}

			id6(l);
		}

		int i = q[z];
		

		

		reduce_seg(i+N, P[i]+N);
		reduce_seg(P[i], i);
		for (auto& a : bit_idx.suffix(i)) a--;
		for (auto& a : bit_val.suffix(P[i])) a--;
	}

	cout << ans << '\n';

	return 0;
}




namespace seg_tree {



inline int id12(int a) {
	return a ? (8 * sizeof(a)) - 1 - __builtin_clz(a) : -1;
}

inline int id5(int a) {
	assert(a > 0);
	return 1 << id12(2*a-1);
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

	template <typename F> void id6(F f) const {
		

		for (int L = id12(a); L > 0; L--) {
			f(point(a >> L));
		}
	}

	template <typename F> void id3(F f) const {
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

	

	

	template <typename F> void id0(F f) const {
		int anc_depth = id12((a-1) ^ b);
		int id8 = (1 << anc_depth) - 1;
		for (int v = (-a) & id8; v; v &= v-1) {
			int i = __builtin_ctz(v);
			f(point(((a-1) >> i) + 1));
		}
		for (int v = b & id8; v; ) {
			int i = id12(v);
			f(point((b >> i) - 1));
			v ^= (1 << i);
		}
	}

	

	

	template <typename F> void id10(F f) const {
		int anc_depth = id12((a-1) ^ b);
		int id8 = (1 << anc_depth) - 1;
		for (int v = b & id8; v; v &= v-1) {
			int i = __builtin_ctz(v);
			f(point((b >> i) - 1));
		}
		for (int v = (-a) & id8; v; ) {
			int i = id12(v);
			f(point(((a-1) >> i) + 1));
			v ^= (1 << i);
		}
	}

	template <typename F> void id6(F f) const {
		int x = a, y = b;
		if ((x ^ y) > x) { x <<= 1, std::swap(x, y); }
		int dx = __builtin_ctz(x);
		int dy = __builtin_ctz(y);
		int anc_depth = id12((x-1) ^ y);
		for (int i = id12(x); i > dx; i--) {
			f(point(x >> i));
		}
		for (int i = anc_depth; i > dy; i--) {
			f(point(y >> i));
		}
	}

	template <typename F> void id3(F f) const {
		int x = a, y = b;
		if ((x ^ y) > x) { x <<= 1, std::swap(x, y); }
		int dx = __builtin_ctz(x);
		int dy = __builtin_ctz(y);
		int anc_depth = id12((x-1) ^ y);
		for (int i = dx+1; i <= anc_depth; i++) {
			f(point(x >> i));
		}
		for (int v = y >> (dy+1); v; v >>= 1) {
			f(point(v));
		}
	}
};

struct id1 {
	

	using point = seg_tree::point;
	using range = seg_tree::range;

	int N, S;
	id1() : N(0), S(0) {}
	id1(int N_) : N(N_), S(N ? id5(N) : 0) {}

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

struct id4 {
	

	using point = seg_tree::point;
	using range = seg_tree::range;

	int N;
	id4() : N(0) {}
	id4(int N_) : N(N_) {}

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
		int S = id5(N);
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


using std::max;
using std::min;

int solve(std::vector<int> A) {
	int N = int(A.size());

	std::vector<int> B(N);
	for (int i = 0; i < N; i++) {
		B[A[i]] = i;
	}

	seg_tree::id4 layout(N-1);
	struct seg_node {
		int v;
		int lazy = 0;
	};
	std::vector<seg_node> seg(2*(N-1));
	auto update_node = [&](seg_tree::point a) -> void {
		seg[a].v = std::max(seg[a.c(0)].v, seg[a.c(1)].v) + seg[a].lazy;
	};
	auto apply_lazy = [&](seg_tree::point a, int v) ->  void {
		seg[a].lazy += v;
		seg[a].v += v;
	};
	auto id11 = [&](seg_tree::point a) -> void {
		if (seg[a].lazy) {
			apply_lazy(a.c(0), seg[a].lazy);
			apply_lazy(a.c(1), seg[a].lazy);
			seg[a].lazy = 0;
		}
	};
	auto update_range = [&](seg_tree::range r, int v) -> void {
		r.id6(id11);
		r.for_each([&](auto a, bool) { apply_lazy(a, v); });
		r.id3(update_node);
	};

	for (int i = 0; i < N-1; i++) {
		auto a = layout.get_point(i);
		seg[a].v = (i+1) - 1 + (i&1);
	}
	for (seg_tree::point a(N-2); a > 0; --a) update_node(a);

	int id7 = 0;
	int id2 = -1;

	int ans = 0;
	for (int i = 1; i < N; i++) {
		int pos = B[i-1];
		while (A[id7] < i) id7++;
		id2 = std::max(id2, pos);
		update_range(layout.get_range(pos, N-1), -1);
		update_range(layout.get_range(0, pos), +1);
		if (id7 < id2) {
			auto r = layout.get_range(id7, id2);
			r.id6(id11);
			r.for_each([&](auto a, bool) -> void {
				ans = max(ans, seg[a].v);
			});
		}
	}
	return ans;
}

int id9(std::vector<int> A) {
	int ans = 0;
	for (int z = 0; !std::is_sorted(A.begin(), A.end()); z++) {
		ans++;
		for (int i = z&1; i+1 < int(A.size()); i += 2) {
			if (A[i] > A[i+1]) std::swap(A[i], A[i+1]);
		}
	}
	return ans;
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (auto& a : A) { cin >> a; a--; }

		cout << solve(A) << '\n';
	}

	return 0;
}






namespace atcoder {
	namespace internal {
		int id1(int n) {
			int x = 0;
			while ((1U << x) < (unsigned int)(n)) x++;
			return x;
		}
		int bsf(unsigned int n) {

			unsigned long index;
			_BitScanForward(&index, n);
			return index;

			return __builtin_ctz(n);

		}
	}
}







namespace atcoder {
	template <class S,
		S(*op)(S, S),
		S(*e)(),
		class F,
		S(*mapping)(F, S),
		F(*composition)(F, F),
		F(*id)()>
		struct id2 {
		public:
			id2() : id2(0) {}
			id2(int n) : id2(std::vector<S>(n, e())) {}
			id2(const std::vector<S>& v) : _n(int(v.size())) {
				log = internal::id1(_n);
				size = 1 << log;
				d = std::vector<S>(2 * size, e());
				lz = std::vector<F>(size, id());
				for (int i = 0; i < _n; i++) d[size + i] = v[i];
				for (int i = size - 1; i >= 1; i--) {
					update(i);
				}
			}
			void set(int p, S x) {
				assert(0 <= p && p < _n);
				p += size;
				for (int i = log; i >= 1; i--) push(p >> i);
				d[p] = x;
				for (int i = 1; i <= log; i++) update(p >> i);
			}
			S get(int p) {
				assert(0 <= p && p < _n);
				p += size;
				for (int i = log; i >= 1; i--) push(p >> i);
				return d[p];
			}
			S prod(int l, int r) {
				assert(0 <= l && l <= r && r <= _n);
				if (l == r) return e();
				l += size;
				r += size;
				for (int i = log; i >= 1; i--) {
					if (((l >> i) << i) != l) push(l >> i);
					if (((r >> i) << i) != r) push(r >> i);
				}
				S sml = e(), smr = e();
				while (l < r) {
					if (l & 1) sml = op(sml, d[l++]);
					if (r & 1) smr = op(d[--r], smr);
					l >>= 1;
					r >>= 1;
				}
				return op(sml, smr);
			}
			S all_prod() { return d[1]; }
			void apply(int p, F f) {
				assert(0 <= p && p < _n);
				p += size;
				for (int i = log; i >= 1; i--) push(p >> i);
				d[p] = mapping(f, d[p]);
				for (int i = 1; i <= log; i++) update(p >> i);
			}
			void apply(int l, int r, F f) {
				assert(0 <= l && l <= r && r <= _n);
				if (l == r) return;
				l += size;
				r += size;
				for (int i = log; i >= 1; i--) {
					if (((l >> i) << i) != l) push(l >> i);
					if (((r >> i) << i) != r) push((r - 1) >> i);
				}
				{
					int l2 = l, r2 = r;
					while (l < r) {
						if (l & 1) all_apply(l++, f);
						if (r & 1) all_apply(--r, f);
						l >>= 1;
						r >>= 1;
					}
					l = l2;
					r = r2;
				}
				for (int i = 1; i <= log; i++) {
					if (((l >> i) << i) != l) update(l >> i);
					if (((r >> i) << i) != r) update((r - 1) >> i);
				}
			}
			template <bool(*g)(S)> int max_right(int l) {
				return max_right(l, [](S x) { return g(x); });
			}
			template <class G> int max_right(int l, G g) {
				assert(0 <= l && l <= _n);
				assert(g(e()));
				if (l == _n) return _n;
				l += size;
				for (int i = log; i >= 1; i--) push(l >> i);
				S sm = e();
				do {
					while (l % 2 == 0) l >>= 1;
					if (!g(op(sm, d[l]))) {
						while (l < size) {
							push(l);
							l = (2 * l);
							if (g(op(sm, d[l]))) {
								sm = op(sm, d[l]);
								l++;
							}
						}
						return l - size;
					}
					sm = op(sm, d[l]);
					l++;
				} while ((l & -l) != l);
				return _n;
			}
			template <bool(*g)(S)> int min_left(int r) {
				return min_left(r, [](S x) { return g(x); });
			}
			template <class G> int min_left(int r, G g) {
				assert(0 <= r && r <= _n);
				assert(g(e()));
				if (r == 0) return 0;
				r += size;
				for (int i = log; i >= 1; i--) push((r - 1) >> i);
				S sm = e();
				do {
					r--;
					while (r > 1 && (r % 2)) r >>= 1;
					if (!g(op(d[r], sm))) {
						while (r < size) {
							push(r);
							r = (2 * r + 1);
							if (g(op(d[r], sm))) {
								sm = op(d[r], sm);
								r--;
							}
						}
						return r + 1 - size;
					}
					sm = op(d[r], sm);
				} while ((r & -r) != r);
				return 0;
			}
		private:
			int _n, size, log;
			std::vector<S> d;
			std::vector<F> lz;
			void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
			void all_apply(int k, F f) {
				d[k] = mapping(f, d[k]);
				if (k < size) lz[k] = composition(f, lz[k]);
			}
			void push(int k) {
				all_apply(2 * k, lz[k]);
				all_apply(2 * k + 1, lz[k]);
				lz[k] = id();
			}
	};
}




using namespace std;
using namespace atcoder;








const int INF = 1e9;
const long long LINF = 1e18;








template<typename A, typename B> inline bool chmax(A & a, const B & b) { if (a < b) { a = b; return true; } return false; }
template<typename A, typename B> inline bool chmin(A & a, const B & b) { if (a > b) { a = b; return true; } return false; }
template<typename T>
struct RangeSet {
	

	

	set<pair<T, T>>st;
	T TINF;
	

	RangeSet(T lim) {
		TINF = lim + 1;
		st.emplace(-TINF, -TINF);
		st.emplace(TINF, TINF);
	}
	

	bool IsCovered(T l, T r) {
		auto ite = prev(st.lower_bound({ l + 1,l + 1 }));
		return ((ite->first <= l) && (r <= ite->second));
	}
	bool IsCovered(T x) { return IsCovered(x, x); }
	

	pair<T, T> ByCovered(T l, T r) {
		auto ite = prev(st.lower_bound({ l + 1,l + 1 }));
		if ((ite->first <= l) && (r <= ite->second)) return *ite;
		return { -TINF, -TINF };
	}
	pair<T, T> ByCovered(T  x) { return ByCovered(x, x); }
	

	T Insert(T l, T r) {
		st.emplace(l, r);
		return 0;
		T sumErase = T(0);
		auto ite = prev(st.lower_bound({ l + 1,l + 1 }));
		

		if (IsCovered(l, r))return sumErase;
		

		if ((ite->first <= l) && (l <= (ite->second + 1))) {
			l = ite->first;
			sumErase += ite->second - ite->first + 1;
			ite = st.erase(ite);
		}
		else ite = next(ite);
		

		while (r > ite->second) {
			sumErase += ite->second - ite->first + 1;
			ite = st.erase(ite);
		}
		if (((ite->first - 1) <= r) && (r <= ite->second)) {
			r = ite->second;
			sumErase += ite->second - ite->first + 1;
			st.erase(ite);
		}
		st.emplace(l, r);
		return (r - l + 1) - sumErase;
	}
	T Insert(T x) { return Insert(x, x); }
	

	vector<pair<T, T>> Erase(T l, T r) {
		vector<pair<T, T>>ret;
		

		auto get = ByCovered(l, r);
		if ((-TINF) != get.first) {
			st.erase(get);
			ret.push_back(get);
			if (get.first != l)st.emplace(get.first, l - 1);
			if (get.second != r)st.emplace(r + 1, get.second);
			

			return ret;
		}
		auto ite = prev(st.lower_bound({ l + 1,l + 1 }));
		

		if ((ite->first <= l) && (l <= ite->second)) {
			

			if (ite->first != l)st.emplace(ite->first, l - 1);
			ret.push_back(*ite);
			ite = st.erase(ite);
		}
		else ite = next(ite);
		

		while (ite->second <= r) {
			

			ret.push_back(*ite);
			ite = st.erase(ite);
		}
		

		if ((ite->first <= r) && (r <= ite->second)) {
			

			if (ite->second != r) st.emplace(r + 1, ite->second);
			ret.push_back(*ite);
			st.erase(ite);
		}
		return ret;
	}
	T Erase(T x) { return Erase(x, x); }
	

	int size() { return st.size() - 2; }
	

	T Mex(T x = 0) {
		if (!IsCovered(x)) return x;
		auto ite = prev(st.lowerbound({ x + 1, x + 1 }));
		return ite->second + 1;
	}
	

	void Debug() {
		for (auto[l, r] : st)cout << l << " " << r << endl;
	}
};
template<
	class S,
	S op(S l, S r),
	S e()
>
struct id0 {
private:
	int mn = 0;
	int mN = 0;
	int id3 = 0;
	::std::vector<S> A;

	void propagate(int i) {
		if (i >= mN) return;
		A[i * 2] = op(A[i * 2], A[i]);
		A[i * 2 + 1] = op(A[i * 2 + 1], A[i]);
		A[i] = e();
	}

	void full_propagate(int i) {
		for (int d = id3; d > 0; d--) propagate(i >> d);
	}

public:

	id0(int n = 0) {
		mn = n;
		id3 = 0; mN = 1;
		while (mN < n) { mN *= 2; id3++; }
		A.assign(mN * 2, e());
	}

	void point_init(int p) {
		assert(0 <= p); assert(p < mn);
		p += mN;
		full_propagate(p);
		A[p] = e();
	}

	S get(int p) {
		assert(0 <= p); assert(p < mn);
		p += mN;
		full_propagate(p);
		return A[p];
	}

	void apply(int l, int r, S x) {
		l += mN;
		r += mN;
		if (l != mN) full_propagate(l - 1);
		if (r != mN * 2) full_propagate(r);
		while (l < r) {
			if (l & 1) { A[l] = op(A[l], x); l++; }
			if (r & 1) { r--; A[r] = op(A[r], x); }
			l /= 2; r /= 2;
		}
	}

};














using S1 = long long;
using F1 = long long;
const F1 ID = 8e18;
S1 op1(S1 a, S1 b) { return std::max(a, b); }
S1 e1() { return -LINF; }
S1 mapping1(F1 f, S1 x) { return (f == ID ? x : f); }
F1 composition1(F1 f, F1 g) { return (f == ID ? g : f); }
F1 id1() { return ID; }

using S0 = long long;
S0 op0(S0 x, S0 f) { return { x + f }; }
S0 e0() { return { 0 }; }








int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q; cin >> n >> q;
	map<int, long long>mp;
	

	

	vector<long long>colv(n, 1);
	id2<S1, op1, e1, F1, mapping1, composition1, id1> col(colv);

	id0<S0, op0, e0>val(n);
	

	RangeSet<int>rs(INF);
	rs.Insert(0, n - 1);
	while (q--) {
		string s; cin >> s;
		if ('C' == s[0]) {
			int l, r, c; cin >> l >> r >> c; l--; r--;
			auto get = rs.Erase(l, r);
			for (auto[x, y] : get) {
				int sl = max(x, l);
				int sr = min(y, r);
				val.apply(sl, sr + 1, mp[col.get(sl)]);
			}
			rs.Insert(l, r);
			val.apply(l, r + 1, -mp[c]);
			col.apply(l, r + 1, c);
		}
		else if ('A' == s[0]) {
			int c, x; cin >> c >> x;
			mp[c] += x;
		}
		else {
			int x; cin >> x; x--;
			long long ans = val.get(x);
			ans += mp[col.get(x)];
			cout << ans << endl;
		}
		

		

		

		

	}
	return 0;
}


using namespace std;




namespace uint_util {
	template<typename T> struct Utils {};

	template<> struct Utils<uint32_t> {
		static void umul_full(uint32_t a, uint32_t b, uint32_t *lo, uint32_t *hi) {
			const uint64_t c = (uint64_t)a * b;
			*lo = (uint32_t)c;
			*hi = (uint32_t)(c >> 32);
		}
		static  uint32_t umul_hi(uint32_t a, uint32_t b) {
			return (uint32_t)((uint64_t)a * b >> 32);
		}
		static uint32_t mulmod_invert(uint32_t b, uint32_t n) {
			return ((uint64_t)b << 32) / n;
		}

		static uint32_t umul_lo(uint32_t a, uint32_t b) {
			return a * b;
		}
		static uint32_t mulmod_precalculated(uint32_t a, uint32_t b, uint32_t n, uint32_t bninv) {
			const auto q = umul_hi(a, bninv);
			uint32_t r = a * b - q * n;
			if (r >= n) r -= n;
			return r;
		}

		static uint32_t invert_twoadic(uint32_t x) {
			uint32_t i = x, p;
			do {
				p = i * x;
				i *= 2 - p;
			} while (p != 1);
			return i;
		}
	};

}

namespace modnum {

	template<typename NumType> struct ModNumTypes {
		using Util = uint_util::Utils<NumType>;

		template<int Lazy> struct id21;

		

		template<int Lazy>
		struct id21 {
			NumType x;
			id21() : x() {}
			template<int L>
			explicit id21(id21<L> t) : x(t.x) { static_assert(L <= Lazy, "invalid conversion"); }

			static id21 raw(NumType x) {
				id21 r; r.x = x;
				return r;
			}

			template<int L>
			static id21 *id7(id21<L> *a) { return reinterpret_cast<id21*>(a); }

			bool operator==(id21 that) const {
				static_assert(Lazy == 1, "cannot compare");
				return x == that.x;
			}
		};

		typedef id21<1> ModNum;

		class ModInfo {
		public:
			enum {
				MAX_ROOT_ORDER = 23
			};

		private:
			NumType P, P2;
			ModNum _one;
			NumType _twoadic_inverse;
			NumType _order;
			NumType _one_P_inv;	


			bool _support_fft;
			ModNum _roots[MAX_ROOT_ORDER + 1], _inv_roots[MAX_ROOT_ORDER + 1];
			ModNum _inv_two_powers[MAX_ROOT_ORDER + 1];

		public:
			NumType getP() const { return P; }
			NumType get_twoadic_inverse() const { return _twoadic_inverse; }

			ModNum one() const { return _one; }

			ModNum to_alt(NumType x) const {
				return ModNum::raw(Util::mulmod_precalculated(x, _one.x, P, _one_P_inv));
			}
			NumType from_alt(ModNum x) const {
				return _reduce(x.x, 0);
			}

			bool support_fft() const { return _support_fft; }

			ModNum root(int n) const {
				assert(support_fft());
				if (n > 0) {
					assert(n <= MAX_ROOT_ORDER);
					return _roots[n];
				} else if (n < 0) {
					assert(n >= -MAX_ROOT_ORDER);
					return _inv_roots[-n];
				} else {
					return one();
				}
			}

			ModNum inv_two_power(int n) const {
				assert(support_fft());
				assert(0 <= n && n <= MAX_ROOT_ORDER);
				return _inv_two_powers[n];
			}

			ModNum add(ModNum a, ModNum b) const {
				auto c = a.x + b.x;
				if (c >= P) c -= P;
				return ModNum::raw(c);
			}

			ModNum sub(ModNum a, ModNum b) const {
				auto c = a.x + (P - b.x);
				if (c >= P) c -= P;
				return ModNum::raw(c);
			}

			id21<4> add_lazy(id21<2> a, id21<2> b) const {
				return id21<4>::raw(a.x + b.x);
			}
			id21<4> sub_lazy(id21<2> a, id21<2> b) const {
				return id21<4>::raw(a.x + (P2 - b.x));
			}

			ModNum mul(ModNum a, ModNum b) const {
				NumType lo, hi;
				Util::umul_full(a.x, b.x, &lo, &hi);
				return ModNum::raw(_reduce(lo, hi));
			}
			ModNum sqr(ModNum a) const {
				return mul(a, a);
			}

			template<int LA, int LB>
			id21<2> mul_lazy(id21<LA> a, id21<LB> b) const {
				static_assert(LA + LB <= 5, "too lazy");
				NumType lo, hi;
				Util::umul_full(a.x, b.x, &lo, &hi);
				return id21<2>::raw(_reduce_lazy(lo, hi));
			}

			ModNum pow(ModNum a, NumType k) const {
				id21<2> base{ a }, res{ one() };
				while (1) {
					if (k & 1) res = mul_lazy(res, base);
					if (k >>= 1) base = mul_lazy(base, base);
					else break;
				}
				return lazy_reduce_1(res);
			}

			ModNum inverse(ModNum a) const {
				return pow(a, _order - 1);
			}

			

			ModNum lazy_reduce_1(id21<2> a) const {
				NumType x = a.x;
				if (x >= P) x -= P;
				return ModNum::raw(x);
			}
			

			id21<2> lazy_reduce_2(id21<4> a) const {
				NumType x = a.x;
				if (x >= P2) x -= P2;
				return id21<2>::raw(x);
			}

		private:
			NumType _reduce(NumType lo, NumType hi) const {
				const auto q = Util::umul_lo(lo, _twoadic_inverse);
				const auto h = Util::umul_hi(q, P);
				NumType t = hi + P - h;
				if (t >= P) t -= P;
				return t;
			}

			NumType _reduce_lazy(NumType lo, NumType hi) const {
				const auto q = Util::umul_lo(lo, _twoadic_inverse);
				const auto h = Util::umul_hi(q, P);
				return hi + P - h;
			}

		public:
			static ModInfo make(NumType P, NumType order = NumType(-1)) {
				ModInfo res;

				res.P = P;
				res.P2 = P * 2;
				res._one.x = ~Util::umul_lo(Util::mulmod_invert(1, P), P) + 1;
				res._order = order == NumType(-1) ? P - 1 : order;
				res._twoadic_inverse = Util::invert_twoadic(P);

				res._one_P_inv = Util::mulmod_invert(res._one.x, P);

				res._support_fft = false;

				assert(res.mul(res.one(), res.one()) == res.one());

				return res;
			}

			static ModInfo make_support_fft(NumType P, NumType order, NumType original_root, int valuation) {
				ModInfo res = make(P, order);
				_compute_fft_info(res, original_root, valuation);
				return res;
			}

		private:
			static void _compute_fft_info(ModInfo &res, NumType original_root, int valuation) {
				assert(res.P <= 1ULL << (sizeof(NumType) * 8 - 2));
				assert(valuation >= MAX_ROOT_ORDER);

				res._support_fft = true;

				ModNum max_root = res.to_alt(original_root);
				for (int i = valuation; i > MAX_ROOT_ORDER; -- i)
					max_root = res.sqr(max_root);

				res._roots[MAX_ROOT_ORDER] = max_root;
				for (int i = MAX_ROOT_ORDER - 1; i >= 0; -- i)
					res._roots[i] = res.sqr(res._roots[i + 1]);

				res._inv_roots[MAX_ROOT_ORDER] = res.inverse(max_root);
				for (int i = MAX_ROOT_ORDER - 1; i >= 0; -- i)
					res._inv_roots[i] = res.sqr(res._inv_roots[i + 1]);

				res._inv_two_powers[0] = res.one();
				res._inv_two_powers[1] = res.inverse(res.add(res.one(), res.one()));
				for (int i = 1; i < MAX_ROOT_ORDER; ++ i)
					res._inv_two_powers[i] = res.mul(res._inv_two_powers[1], res._inv_two_powers[i - 1]);

				assert(res.mul(res._roots[1], res._inv_roots[1]) == res.one());
				assert(res.root(0) == res.one());
				assert(!(res.root(1) == res.one()));
			}
		};
	};

}

namespace fft {

	using namespace modnum;

	using NumType = uint32_t;

	using ModNumType = ModNumTypes<NumType>;
	template<int Lazy>
	using id21 = ModNumType::id21<Lazy>;
	using ModNum = ModNumType::ModNum;
	using ModInfo = ModNumType::ModInfo;

	using ModNumType32 = ModNumTypes<uint32_t>;
	using ModNum32 = ModNumType32::ModNum;
	using ModInfo32 = ModNumType32::ModInfo;

	inline __m128i id4(const __m128i &a, const __m128i &p2, const __m128i &signbit) {
		const auto mask = _mm_cmpgt_epi32(_mm_xor_si128(p2, signbit), _mm_xor_si128(a, signbit));
		const auto sub = _mm_andnot_si128(mask, p2);
		return _mm_sub_epi32(a, sub);
	}

	inline __m128i id5(const __m128i &a, const __m128i &p, const __m128i &id1) {
		const auto q = _mm_mul_epu32(a, id1);
		const auto h = _mm_shuffle_epi32(_mm_mul_epu32(q, p), _MM_SHUFFLE(3, 3, 1, 1));
		return _mm_add_epi32(a, _mm_sub_epi32(p, h));
	}

	inline __m128i id0(const __m128i &a, const __m128i &b, const __m128i &p, const __m128i &id1) {
		const auto a02 = _mm_shuffle_epi32(a, _MM_SHUFFLE(2, 2, 0, 0));
		const auto a13 = _mm_shuffle_epi32(a, _MM_SHUFFLE(3, 3, 1, 1));
		const auto b02 = _mm_shuffle_epi32(b, _MM_SHUFFLE(2, 2, 0, 0));
		const auto b13 = _mm_shuffle_epi32(b, _MM_SHUFFLE(3, 3, 1, 1));

		const auto prod02 = _mm_mul_epu32(a02, b02);
		const auto prod13 = _mm_mul_epu32(a13, b13);

		const auto res02 = id5(prod02, p, id1);
		const auto res13 = id5(prod13, p, id1);

		const auto id3 = _mm_shuffle_epi32(res02, _MM_SHUFFLE(0, 0, 3, 1));
		const auto id9 = _mm_shuffle_epi32(res13, _MM_SHUFFLE(0, 0, 3, 1));

		return _mm_unpacklo_epi32(id3, id9);
	}

	inline __m128i id13(const __m128i &a, const __m128i &b, const __m128i &p, const __m128i &id1) {
		__m128i t = id0(a, b, p, id1);
		const auto mask = _mm_cmpgt_epi32(p, t);	

		const auto sub = _mm_andnot_si128(mask, p);
		return _mm_sub_epi32(t, sub);
	}

	inline __m128i id24(const __m128i &a, const __m128i &b) {
		return _mm_add_epi32(a, b);
	}
	inline __m128i id10(const __m128i &a, const __m128i &b, const __m128i &p2) {
		return _mm_add_epi32(a, _mm_sub_epi32(p2, b));
	}

	void id12(id21<2> *f_inout, int n, int sign, const ModInfo &mod) {
		id21<4> * const f = id21<4>::id7(f_inout);

		int N = 1 << n;

		if (n <= 1) {
			if (n == 0)
				return;

			const auto a = f_inout[0];
			const auto b = f_inout[1];

			f_inout[0] = mod.lazy_reduce_2(mod.add_lazy(a, b));
			f_inout[1] = mod.lazy_reduce_2(mod.sub_lazy(a, b));
			return;
		}

		if (n & 1) {
			for (int i = 0; i < N; i += 2) {
				const auto a = f_inout[i + 0];
				const auto b = f_inout[i + 1];

				f[i + 0] = mod.add_lazy(a, b);
				f[i + 1] = mod.sub_lazy(a, b);
			}
		}

		if ((n & 1) == 0) {
			const auto imag = mod.root(2 * sign);
			for (int i = 0; i < N; i += 4) {
				const auto a0 = f_inout[i + 0];
				const auto a2 = f_inout[i + 1];
				const auto a1 = f_inout[i + 2];
				const auto a3 = f_inout[i + 3];

				const auto t02 = mod.lazy_reduce_2(mod.add_lazy(a0, a2));
				const auto t13 = mod.lazy_reduce_2(mod.add_lazy(a1, a3));

				f[i + 0] = mod.add_lazy(t02, t13);
				f[i + 2] = mod.sub_lazy(t02, t13);

				const auto u02 = mod.lazy_reduce_2(mod.sub_lazy(a0, a2));
				const auto u13 = mod.mul_lazy(mod.sub_lazy(a1, a3), imag);

				f[i + 1] = mod.add_lazy(u02, u13);
				f[i + 3] = mod.sub_lazy(u02, u13);
			}
		} else {
			const auto imag = mod.root(2 * sign);
			const auto omega = mod.root(3 * sign);

			for (int i = 0; i < N; i += 8) {
				const auto a0 = mod.lazy_reduce_2(f[i + 0]);
				const auto a2 = mod.lazy_reduce_2(f[i + 2]);
				const auto a1 = mod.lazy_reduce_2(f[i + 4]);
				const auto a3 = mod.lazy_reduce_2(f[i + 6]);

				const auto t02 = mod.lazy_reduce_2(mod.add_lazy(a0, a2));
				const auto t13 = mod.lazy_reduce_2(mod.add_lazy(a1, a3));

				f[i + 0] = mod.add_lazy(t02, t13);
				f[i + 4] = mod.sub_lazy(t02, t13);

				const auto u02 = mod.lazy_reduce_2(mod.sub_lazy(a0, a2));
				const auto u13 = mod.mul_lazy(mod.sub_lazy(a1, a3), imag);

				f[i + 2] = mod.add_lazy(u02, u13);
				f[i + 6] = mod.sub_lazy(u02, u13);
			}

			ModNum w = omega, w2 = imag, w3 = mod.mul(w2, w);

			for (int i = 1; i < N; i += 8) {
				const auto a0 = mod.lazy_reduce_2(f[i + 0]);
				const auto a2 = mod.mul_lazy(f[i + 2], w2);
				const auto a1 = mod.mul_lazy(f[i + 4], w);
				const auto a3 = mod.mul_lazy(f[i + 6], w3);

				const auto t02 = mod.lazy_reduce_2(mod.add_lazy(a0, a2));
				const auto t13 = mod.lazy_reduce_2(mod.add_lazy(a1, a3));

				f[i + 0] = mod.add_lazy(t02, t13);
				f[i + 4] = mod.sub_lazy(t02, t13);

				const auto u02 = mod.lazy_reduce_2(mod.sub_lazy(a0, a2));
				const auto u13 = mod.mul_lazy(mod.sub_lazy(a1, a3), imag);

				f[i + 2] = mod.add_lazy(u02, u13);
				f[i + 6] = mod.sub_lazy(u02, u13);
			}
		}

		for (int m = 4 + (n & 1); m <= n; m += 2) {
			int M = 1 << m, id25 = M >> 2;
			const auto o = mod.root(m * sign), o2 = mod.root((m - 1) * sign), o4 = mod.root((m - 2) * sign);

			const auto p = _mm_set1_epi32(mod.getP());
			const auto p2 = _mm_set1_epi32(mod.getP() * 2);
			const auto id1 = _mm_set1_epi32(mod.get_twoadic_inverse());
			const auto imag = _mm_set1_epi32(mod.root(2 * sign).x);
			const auto omega = _mm_set1_epi32(o4.x);
			const auto signbit = _mm_set1_epi32((int)(1U << 31));

			__m128i w = _mm_set_epi32(mod.mul(o, o2).x, o2.x, o.x, mod.one().x);

			for (int j = 0; j < id25; j += 4) {
				const auto w2 = id13(w, w, p, id1);
				const auto w3 = id13(w2, w, p, id1);

				for (int i = j; i < N; i += M) {
					const auto f0 = _mm_loadu_si128(reinterpret_cast<__m128i*>(f + i + id25 * 0));
					const auto f1 = _mm_loadu_si128(reinterpret_cast<__m128i*>(f + i + id25 * 1));
					const auto f2 = _mm_loadu_si128(reinterpret_cast<__m128i*>(f + i + id25 * 2));
					const auto f3 = _mm_loadu_si128(reinterpret_cast<__m128i*>(f + i + id25 * 3));

					const auto a0 = id4(f0, p2, signbit);
					const auto a2 = id0(f1, w2, p, id1);
					const auto a1 = id0(f2, w, p, id1);
					const auto a3 = id0(f3, w3, p, id1);

					const auto t02 = id4(id24(a0, a2), p2, signbit);
					const auto t13 = id4(id24(a1, a3), p2, signbit);

					const auto r0 = id24(t02, t13);
					const auto r2 = id10(t02, t13, p2);

					const auto u02 = id4(id10(a0, a2, p2), p2, signbit);
					const auto u13 = id0(id10(a1, a3, p2), imag, p, id1);

					const auto r1 = id24(u02, u13);
					const auto r3 = id10(u02, u13, p2);

					_mm_storeu_si128(reinterpret_cast<__m128i*>(f + i + id25 * 0), r0);
					_mm_storeu_si128(reinterpret_cast<__m128i*>(f + i + id25 * 1), r1);
					_mm_storeu_si128(reinterpret_cast<__m128i*>(f + i + id25 * 2), r2);
					_mm_storeu_si128(reinterpret_cast<__m128i*>(f + i + id25 * 3), r3);
				}

				w = id13(w, omega, p, id1);
			}
		}

		for (int i = 0; i < N; ++ i)
			f_inout[i] = mod.lazy_reduce_2(f[i]);
	}

	void id16(id21<2> *f_inout, int n, int sign, const ModInfo &mod) {
		id12(f_inout, n, sign, mod);
	}

	template<typename T>
	void id14(T *f, int n) {
		int N = 1 << n, id22 = N >> 1, r = 0;
		for (int x = 1; x < N; ++ x) {
			int h = id22;
			while (((r ^= h) & h) == 0) h >>= 1;
			if (r > x) swap(f[x], f[r]);
		}
	}

	void id11(id21<2> *f, int n, int sign, const ModInfo &mod) {
		id14(f, n);
		id16(f, n, sign, mod);
	}

	template<int LF, int LG>
	void id17(id21<2> *res, const id21<LF> *f, const id21<LG> *g, int N, const ModInfo &mod) {
		for (int i = 0; i < N; ++ i)
			res[i] = mod.mul_lazy(f[i], g[i]);
	}

	void id15(id21<2> *f, int n, const ModInfo &mod) {
		const auto f_out = ModNum::id7(f);
		int N = 1 << n;
		ModNum inv = mod.inv_two_power(n);
		assert(mod.mul(inv, mod.to_alt(N)) == mod.one());
		for (int i = 0; i < N; ++ i)
			f_out[i] = mod.lazy_reduce_1(mod.mul_lazy(f[i], inv));
	}

	void id8(ModNum *f_in, ModNum *g_in, int n, const ModInfo &mod) {
		assert(mod.support_fft());
		const auto f = id21<2>::id7(f_in);
		const auto g = id21<2>::id7(g_in);
		id11(f, n, +1, mod);
		id11(g, n, +1, mod);
		id17(f, f, g, 1 << n, mod);
		id11(f, n, -1, mod);
		id15(f, n, mod);
	}

	void id19(ModNum *f_in, int n, const ModInfo &mod) {
		assert(mod.support_fft());
		const auto f = id21<2>::id7(f_in);
		id11(f, n, +1, mod);
		id17(f, f, f, 1 << n, mod);
		id11(f, n, -1, mod);
		id15(f, n, mod);
	}


	enum { MULTIPRIME_NUM = 2 };

	static const ModInfo id2 = ModInfo::make_support_fft(998244353, -1, 31, 23);
	static const ModInfo id20 = ModInfo::make_support_fft(897581057, -1, 45, 23);
	const ModInfo * const fft_prime_mods[MULTIPRIME_NUM] = { &id2, &id20 };

	void id18(uint64_t *res, const ModNum *f[MULTIPRIME_NUM], int N, const ModInfo * const mods[MULTIPRIME_NUM]) {
		const auto f0 = f[0], f1 = f[1], f2 = f[2];
		const auto &mod0 = *mods[0], &mod1 = *mods[1];
		const auto P0 = mod0.getP(), P1 = mod1.getP();
		const auto t1 = mod1.inverse(mod1.to_alt(P0));

		for (int i = 0; i < N; ++ i) {
			const auto a0 = mod0.from_alt(f0[i]), a1 = mod1.from_alt(f1[i]);
			const auto d1 = mod1.sub(mod1.to_alt(a1), mod1.to_alt(a0));
			const auto h1 = mod1.from_alt(mod1.mul(d1, t1));
			const auto a01 = a0 + (uint64_t)P0 * h1;
			res[i] = a01;
		}
	}

	void id6(ModNum *res[MULTIPRIME_NUM], const uint32_t *f, int N, const ModInfo * const mods[MULTIPRIME_NUM]) {
		for (int i = 0; i < N; ++ i) {
			auto a = f[i];
			for (int k = 0; k < MULTIPRIME_NUM; ++ k)
				res[k][i] = mods[k]->to_alt(f[i]);
		}
	}

	void id23(uint64_t *res, int resN, const uint32_t *f, int fN, const uint32_t *g, int gN, int n) {
		int N = 1 << n;
		assert(fN <= N && gN <= N && resN <= N);
		

		unique_ptr<ModNum[]> workspace(new ModNum[N * MULTIPRIME_NUM * 2]);
		ModNum *fs[MULTIPRIME_NUM], *gs[MULTIPRIME_NUM];
		for (int k = 0; k < MULTIPRIME_NUM; ++ k) {
			fs[k] = workspace.get() + (k * 2 + 0) * N;
			gs[k] = workspace.get() + (k * 2 + 1) * N;
		}
		id6(fs, f, fN, fft_prime_mods);
		id6(gs, g, gN, fft_prime_mods);
		for (int k = 0; k < MULTIPRIME_NUM; ++ k)
			id8(fs[k], gs[k], n, *fft_prime_mods[k]);
		id18(res, const_cast<const ModNum **>(fs), resN, fft_prime_mods);
	}
}

int main() {
	int n; int x;
	while (~scanf("%d%d", &n, &x)) {
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<int> sum(n + 1);
		for (int i = 0; i < n; ++ i)
			sum[i + 1] = sum[i] + (a[i] < x);

		vector<uint32_t> p(n + 1), q(n + 1);
		vector<uint64_t> prod(n * 2 + 1);
		for (int i = 0; i <= n; ++ i) {
			++ p[sum[i]];
			++ q[n - sum[i]];
		}
		int logn = 1;
		for (; 1 << logn < n * 2 + 1; ++ logn);
		fft::id23(prod.data(), n * 2 + 1, p.data(), n + 1, q.data(), n + 1, logn);
		for (int i = 0; i <= n; ++ i) {
			long long ans = prod[n + i];
			if (i == 0) ans = (ans - (n + 1)) / 2;
			printf("%lld%c", ans, i == n ? '\n' : ' ');
		}
	}
}

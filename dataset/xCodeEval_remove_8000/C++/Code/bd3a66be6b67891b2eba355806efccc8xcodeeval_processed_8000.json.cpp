

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

		template<int Lazy> struct id26;

		

		template<int Lazy>
		struct id26 {
			NumType x;
			id26() : x() {}
			template<int L>
			explicit id26(id26<L> t) : x(t.x) { static_assert(L <= Lazy, "invalid conversion"); }

			static id26 raw(NumType x) {
				id26 r; r.x = x;
				return r;
			}

			template<int L>
			static id26 *id7(id26<L> *a) { return reinterpret_cast<id26*>(a); }

			bool operator==(id26 that) const {
				static_assert(Lazy == 1, "cannot compare");
				return x == that.x;
			}
		};

		typedef id26<1> ModNum;

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

			id26<4> add_lazy(id26<2> a, id26<2> b) const {
				return id26<4>::raw(a.x + b.x);
			}
			id26<4> sub_lazy(id26<2> a, id26<2> b) const {
				return id26<4>::raw(a.x + (P2 - b.x));
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
			id26<2> mul_lazy(id26<LA> a, id26<LB> b) const {
				static_assert(LA + LB <= 5, "too lazy");
				NumType lo, hi;
				Util::umul_full(a.x, b.x, &lo, &hi);
				return id26<2>::raw(_reduce_lazy(lo, hi));
			}

			ModNum pow(ModNum a, NumType k) const {
				id26<2> base{ a }, res{ one() };
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

			

			ModNum lazy_reduce_1(id26<2> a) const {
				NumType x = a.x;
				if (x >= P) x -= P;
				return ModNum::raw(x);
			}
			

			id26<2> lazy_reduce_2(id26<4> a) const {
				NumType x = a.x;
				if (x >= P2) x -= P2;
				return id26<2>::raw(x);
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
	using id26 = ModNumType::id26<Lazy>;
	using ModNum = ModNumType::ModNum;
	using ModInfo = ModNumType::ModInfo;

	using ModNumType32 = ModNumTypes<uint32_t>;
	using ModNum32 = ModNumType32::ModNum;
	using ModInfo32 = ModNumType32::ModInfo;

	inline __m128i id5(const __m128i &a, const __m128i &p2, const __m128i &signbit) {
		const auto mask = _mm_cmpgt_epi32(_mm_xor_si128(p2, signbit), _mm_xor_si128(a, signbit));
		const auto sub = _mm_andnot_si128(mask, p2);
		return _mm_sub_epi32(a, sub);
	}

	inline __m128i id6(const __m128i &a, const __m128i &p, const __m128i &id1) {
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

		const auto res02 = id6(prod02, p, id1);
		const auto res13 = id6(prod13, p, id1);

		const auto id3 = _mm_shuffle_epi32(res02, _MM_SHUFFLE(0, 0, 3, 1));
		const auto id11 = _mm_shuffle_epi32(res13, _MM_SHUFFLE(0, 0, 3, 1));

		return _mm_unpacklo_epi32(id3, id11);
	}

	inline __m128i id17(const __m128i &a, const __m128i &b, const __m128i &p, const __m128i &id1) {
		__m128i t = id0(a, b, p, id1);
		const auto mask = _mm_cmpgt_epi32(p, t);	

		const auto sub = _mm_andnot_si128(mask, p);
		return _mm_sub_epi32(t, sub);
	}

	inline __m128i id28(const __m128i &a, const __m128i &b) {
		return _mm_add_epi32(a, b);
	}
	inline __m128i id12(const __m128i &a, const __m128i &b, const __m128i &p2) {
		return _mm_add_epi32(a, _mm_sub_epi32(p2, b));
	}

	void id16(id26<2> *f_inout, int n, int sign, const ModInfo &mod) {
		id26<4> * const f = id26<4>::id7(f_inout);

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
			int M = 1 << m, id29 = M >> 2;
			const auto o = mod.root(m * sign), o2 = mod.root((m - 1) * sign), o4 = mod.root((m - 2) * sign);

			const auto p = _mm_set1_epi32(mod.getP());
			const auto p2 = _mm_set1_epi32(mod.getP() * 2);
			const auto id1 = _mm_set1_epi32(mod.get_twoadic_inverse());
			const auto imag = _mm_set1_epi32(mod.root(2 * sign).x);
			const auto omega = _mm_set1_epi32(o4.x);
			const auto signbit = _mm_set1_epi32((int)(1U << 31));

			__m128i w = _mm_set_epi32(mod.mul(o, o2).x, o2.x, o.x, mod.one().x);

			for (int j = 0; j < id29; j += 4) {
				const auto w2 = id17(w, w, p, id1);
				const auto w3 = id17(w2, w, p, id1);

				for (int i = j; i < N; i += M) {
					const auto f0 = _mm_loadu_si128(reinterpret_cast<__m128i*>(f + i + id29 * 0));
					const auto f1 = _mm_loadu_si128(reinterpret_cast<__m128i*>(f + i + id29 * 1));
					const auto f2 = _mm_loadu_si128(reinterpret_cast<__m128i*>(f + i + id29 * 2));
					const auto f3 = _mm_loadu_si128(reinterpret_cast<__m128i*>(f + i + id29 * 3));

					const auto a0 = id5(f0, p2, signbit);
					const auto a2 = id0(f1, w2, p, id1);
					const auto a1 = id0(f2, w, p, id1);
					const auto a3 = id0(f3, w3, p, id1);

					const auto t02 = id5(id28(a0, a2), p2, signbit);
					const auto t13 = id5(id28(a1, a3), p2, signbit);

					const auto r0 = id28(t02, t13);
					const auto r2 = id12(t02, t13, p2);

					const auto u02 = id5(id12(a0, a2, p2), p2, signbit);
					const auto u13 = id0(id12(a1, a3, p2), imag, p, id1);

					const auto r1 = id28(u02, u13);
					const auto r3 = id12(u02, u13, p2);

					_mm_storeu_si128(reinterpret_cast<__m128i*>(f + i + id29 * 0), r0);
					_mm_storeu_si128(reinterpret_cast<__m128i*>(f + i + id29 * 1), r1);
					_mm_storeu_si128(reinterpret_cast<__m128i*>(f + i + id29 * 2), r2);
					_mm_storeu_si128(reinterpret_cast<__m128i*>(f + i + id29 * 3), r3);
				}

				w = id17(w, omega, p, id1);
			}
		}

		for (int i = 0; i < N; ++ i)
			f_inout[i] = mod.lazy_reduce_2(f[i]);
	}

	void id22(id26<2> *f_inout, int n, int sign, const ModInfo &mod) {
		id16(f_inout, n, sign, mod);
	}

	template<typename T>
	void id18(T *f, int n) {
		int N = 1 << n, id27 = N >> 1, r = 0;
		for (int x = 1; x < N; ++ x) {
			int h = id27;
			while (((r ^= h) & h) == 0) h >>= 1;
			if (r > x) swap(f[x], f[r]);
		}
	}

	void id13(id26<2> *f, int n, int sign, const ModInfo &mod) {
		id18(f, n);
		id22(f, n, sign, mod);
	}

	template<int LF, int LG>
	void id23(id26<2> *res, const id26<LF> *f, const id26<LG> *g, int N, const ModInfo &mod) {
		for (int i = 0; i < N; ++ i)
			res[i] = mod.mul_lazy(f[i], g[i]);
	}

	void id20(id26<2> *f, int n, const ModInfo &mod) {
		const auto f_out = ModNum::id7(f);
		int N = 1 << n;
		ModNum inv = mod.inv_two_power(n);
		assert(mod.mul(inv, mod.to_alt(N)) == mod.one());
		for (int i = 0; i < N; ++ i)
			f_out[i] = mod.lazy_reduce_1(mod.mul_lazy(f[i], inv));
	}

	void id9(ModNum *f_in, ModNum *g_in, int n, const ModInfo &mod) {
		assert(mod.support_fft());
		const auto f = id26<2>::id7(f_in);
		const auto g = id26<2>::id7(g_in);
		id13(f, n, +1, mod);
		id13(g, n, +1, mod);
		id23(f, f, g, 1 << n, mod);
		id13(f, n, -1, mod);
		id20(f, n, mod);
	}

	void id24(ModNum *f_in, int n, const ModInfo &mod) {
		assert(mod.support_fft());
		const auto f = id26<2>::id7(f_in);
		id13(f, n, +1, mod);
		id23(f, f, f, 1 << n, mod);
		id13(f, n, -1, mod);
		id20(f, n, mod);
	}

	enum { MULTIPRIME_NUM = 3 };

	static const ModInfo id2 = ModInfo::make_support_fft(998244353, -1, 31, 23);
	static const ModInfo id25 = ModInfo::make_support_fft(897581057, -1, 45, 23);
	static const ModInfo id19 = ModInfo::make_support_fft(880803841, -1, 211, 23);
	const ModInfo * const fft_prime_mods[MULTIPRIME_NUM] = { &id2, &id25, &id19 };

	void id21(ModNum32 *res, const ModInfo32 &mod_res, const ModNum *f[MULTIPRIME_NUM], int N, const ModInfo * const mods[MULTIPRIME_NUM]) {
		const auto f0 = f[0], f1 = f[1], f2 = f[2];
		const auto &mod0 = *mods[0], &mod1 = *mods[1], &mod2 = *mods[2];
		const auto P0 = mod0.getP(), P1 = mod1.getP(), P2 = mod2.getP();
		const auto P_res = mod_res.getP();
		const auto t1 = mod1.inverse(mod1.to_alt(P0));
		const auto t2 = mod2.inverse(mod2.to_alt((uint64_t)P0 * P1 % P2));
		const auto p01 = mod_res.to_alt((uint64_t)P0 * P1 % P_res);

		for (int i = 0; i < N; ++ i) {
			const auto a0 = mod0.from_alt(f0[i]), a1 = mod1.from_alt(f1[i]), a2 = mod2.from_alt(f2[i]);
			const auto d1 = mod1.sub(mod1.to_alt(a1), mod1.to_alt(a0));
			const auto h1 = mod1.from_alt(mod1.mul(d1, t1));
			const auto a01 = a0 + (uint64_t)P0 * h1;
			const auto d2 = mod2.sub(mod2.to_alt(a2), mod2.to_alt(a01 % P2));
			const auto h2 = mod2.from_alt(mod2.mul(d2, t2));
			res[i] = mod_res.add(mod_res.to_alt(a01 % P_res), mod_res.mul(mod_res.to_alt(h2 % P_res), p01));
		}
	}

	void id4(ModNum *res[MULTIPRIME_NUM], const ModNum32 *f, int N, const ModInfo32 &f_mod, const ModInfo * const mods[MULTIPRIME_NUM]) {
		for (int i = 0; i < N; ++ i) {
			const auto a = f_mod.from_alt(f[i]);
			for (int k = 0; k < MULTIPRIME_NUM; ++ k)
				res[k][i] = mods[k]->to_alt(a);
		}
	}

	void id8(ModNum32 *res, int resN, const ModNum32 *f, int fN, const ModNum32 *g, int gN, int n, const ModInfo32 &mod) {
		int N = 1 << n;
		assert(fN <= N && gN <= N && resN <= N);
		

		unique_ptr<ModNum[]> workspace(new ModNum[N * MULTIPRIME_NUM * 2]);
		ModNum *fs[MULTIPRIME_NUM], *gs[MULTIPRIME_NUM];
		for (int k = 0; k < MULTIPRIME_NUM; ++ k) {
			fs[k] = workspace.get() + (k * 2 + 0) * N;
			gs[k] = workspace.get() + (k * 2 + 1) * N;
		}
		id4(fs, f, fN, mod, fft_prime_mods);
		id4(gs, g, gN, mod, fft_prime_mods);
		for (int k = 0; k < MULTIPRIME_NUM; ++ k)
			id9(fs[k], gs[k], n, *fft_prime_mods[k]);
		id21(res, mod, const_cast<const ModNum **>(fs), resN, fft_prime_mods);
	}

	void id14(ModNum32 *res, int resN, const ModNum32 *f, int fN, int n, const ModInfo32 &mod) {
		int N = 1 << n;
		assert(fN <= N && resN <= N);
		unique_ptr<ModNum[]> workspace(new ModNum[N * MULTIPRIME_NUM]);
		ModNum *fs[MULTIPRIME_NUM];
		for (int k = 0; k < MULTIPRIME_NUM; ++ k)
			fs[k] = workspace.get() + k * N;
		id4(fs, f, fN, mod, fft_prime_mods);
		for (int k = 0; k < MULTIPRIME_NUM; ++ k)
			id24(fs[k], n, *fft_prime_mods[k]);
		id21(res, mod, const_cast<const ModNum **>(fs), resN, fft_prime_mods);
	}

}

struct ModInt {
	using NumType = uint32_t;
	using ModNumType = modnum::ModNumTypes<NumType>;
	using ModNum = ModNumType::ModNum;
	using ModInfo = ModNumType::ModInfo;

public:
	ModNum x;

	ModInt() : x() {}
	ModInt(NumType num) : x(mod.to_alt(num)) {}
	ModInt(int num) : x(mod.to_alt(num >= 0 ? num : mod.getP() + num % (int)mod.getP())) {}

	NumType get() const { return mod.from_alt(x); }

	static ModInt raw(ModNum x) { ModInt r; r.x = x; return r; }
	static ModInt one() { return raw(mod.one()); }

	ModInt operator+(ModInt that) const { return raw(mod.add(x, that.x)); }
	ModInt &operator+=(ModInt that) { return *this = *this + that; }

	ModInt operator-(ModInt that) const { return raw(mod.sub(x, that.x)); }
	ModInt &operator-=(ModInt that) { return *this = *this - that; }

	ModInt operator-() const { return raw(mod.sub(ModNum(), x)); }

	ModInt operator*(ModInt that) const { return raw(mod.mul(x, that.x)); }
	ModInt &operator*=(ModInt that) { return *this = *this * that; }

	ModInt inverse() const { return raw(mod.inverse(x)); }
	ModInt operator/(ModInt that) const { return *this * that.inverse(); }
	ModInt &operator/=(ModInt that) { return *this = *this / that.inverse(); }

	bool operator==(ModInt that) const { return x == that.x; }
	bool operator!=(ModInt that) const { return !(*this == that); }

private:
	static ModInfo mod;

public:
	static const ModInfo &get_mod_info() { return mod; }
	static NumType getMod() { return mod.getP(); }

	static void set_mod(NumType P, NumType order = -1) {
		mod = ModInfo::make(P, order);
	}
};

ModInt::ModInfo ModInt::mod;
typedef ModInt mint;

namespace mod_polynomial {

	struct Polynomial {
		typedef mint R;
		static R ZeroR() { return R(); }
		static R OneR() { return R::one(); }
		static bool IsZeroR(R r) { return r == ZeroR(); }

		struct NumberTable {
			std::vector<R> natural_numbers;
			std::vector<R> inverse_numbers;
			std::vector<R> factorials;
			std::vector<R> inverse_factorials;

			int size() const { return (int)natural_numbers.size(); }
		};

		std::vector<R> coeffs;

		Polynomial() {}
		explicit Polynomial(R c0) : coeffs(1, c0) {}
		explicit Polynomial(R c0, R c1) : coeffs(2) { coeffs[0] = c0, coeffs[1] = c1; }
		template<typename It> Polynomial(It be, It en) : coeffs(be, en) {}

		static Polynomial Zero() { return Polynomial(); }
		static Polynomial One() { return Polynomial(OneR()); }
		static Polynomial X() { return Polynomial(ZeroR(), OneR()); }

		void resize(int n) { coeffs.resize(n); }
		void clear() { coeffs.clear(); }

		R *data() { return coeffs.empty() ? NULL : &coeffs[0]; }
		const R *data() const { return coeffs.empty() ? NULL : &coeffs[0]; }

		int size() const { return static_cast<int>(coeffs.size()); }
		bool empty() const { return coeffs.empty(); }
		int degree() const { return size() - 1; }

		bool normalized() const { return coeffs.empty() || coeffs.back() != ZeroR(); }
		bool monic() const { return !coeffs.empty() && coeffs.back() == OneR(); }

		R get(int i) const { return 0 <= i && i < size() ? coeffs[i] : ZeroR(); }

		void set(int i, R x) {
			if (size() <= i)
				resize(i + 1);
			coeffs[i] = x;
		}

		void normalize() { while (!empty() && IsZeroR(coeffs.back())) coeffs.pop_back(); }

		R evaluate(R x) const {
			if (empty()) return R();
			R r = coeffs.back();
			for (int i = size() - 2; i >= 0; -- i) {
				r *= x;
				r += coeffs[i];
			}
			return r;
		}

		Polynomial &operator+=(const Polynomial &that) {
			int m = size(), n = that.size();
			if (m < n) resize(n);
			_add(data(), that.data(), n);
			return *this;
		}
		Polynomial operator+(const Polynomial &that) const {
			return Polynomial(*this) += that;
		}

		Polynomial &operator-=(const Polynomial &that) {
			int m = size(), n = that.size();
			if (m < n) resize(n);
			_subtract(data(), that.data(), n);
			return *this;
		}
		Polynomial operator-(const Polynomial &that) const {
			return Polynomial(*this) -= that;
		}

		Polynomial &operator*=(R r) {
			_multiply_1(data(), size(), r);
			return *this;
		}
		Polynomial operator*(R r) const {
			Polynomial res;
			res.resize(size());
			_multiply_1(res.data(), data(), size(), r);
			return res;
		}

		Polynomial operator*(const Polynomial &that) const {
			Polynomial r;
			multiply(r, *this, that);
			return r;
		}

		Polynomial &operator*=(const Polynomial &that) {
			multiply(*this, *this, that);
			return *this;
		}

		static void multiply(Polynomial &res, const Polynomial &p, const Polynomial &q) {
			int pn = p.size(), qn = q.size();

			if (pn < qn)
				return multiply(res, q, p);

			if (&res == &p || &res == &q) {
				Polynomial tmp;
				multiply(tmp, p, q);
				res = tmp;
				return;
			}

			if (qn == 0) {
				res.coeffs.clear();
			} else {
				res.resize(pn + qn - 1);
				_multiply_select_method(res.data(), p.data(), pn, q.data(), qn);
			}
		}

		Polynomial operator-() const {
			Polynomial res;
			res.resize(size());
			_negate(res.data(), data(), size());
			return res;
		}

		Polynomial precomputeRevInverse(int n) const {
			Polynomial res;
			res.resize(n);
			_precompute_reverse_inverse(res.data(), n, data(), size());
			return res;
		}

		static void divideRemainderPrecomputedRevInverse(Polynomial &quot, Polynomial &rem, const Polynomial &p, const Polynomial &q, const Polynomial &inv) {
			assert(&quot != &p && &quot != &q && &quot != &inv);
			int pn = p.size(), qn = q.size();
			assert(inv.size() >= pn - qn + 1);
			quot.resize(std::max(0, pn - qn + 1));
			rem.resize(qn - 1);
			_divide_remainder_precomputed_inverse(quot.data(), rem.data(), p.data(), pn, q.data(), qn, inv.data());
			quot.normalize();
			rem.normalize();
		}

		Polynomial computeRemainderPrecomputedRevInverse(const Polynomial &q, const Polynomial &inv) const {
			Polynomial quot, rem;
			divideRemainderPrecomputedRevInverse(quot, rem, *this, q, inv);
			return rem;
		}

		Polynomial powerMod(long long K, const Polynomial &q) const {
			int qn = q.size();
			assert(K >= 0 && qn > 0);
			assert(q.monic());
			if (qn == 1) return Polynomial();
			if (K == 0) return One();
			Polynomial inv = q.precomputeRevInverse(std::max(size() - qn + 1, qn));
			Polynomial p = this->computeRemainderPrecomputedRevInverse(q, inv);
			int l = 0;
			while ((K >> l) > 1) ++ l;
			Polynomial res = p;
			for (-- l; l >= 0; -- l) {
				res *= res;
				res = res.computeRemainderPrecomputedRevInverse(q, inv);
				if (K >> l & 1) {
					res *= p;
					res = res.computeRemainderPrecomputedRevInverse(q, inv);
				}
			}
			return res;
		}

		Polynomial reverse(int n) {
			assert(size() <= n);
			Polynomial r; r.resize(n);
			for (int i = 0; i < n; ++ i)
				r.set(n - 1 - i, get(i));
			return r;
		}

		static void clearNumberTable() {
			_numberTable = NumberTable();
		}

		static const NumberTable &getNumberTable(int size) {
			extendNumberTable(size);
			return _numberTable;
		}

		static void extendNumberTable(int size) {
			int old_size = _numberTable.size();
			if (old_size >= size)
				return;
			if (old_size * 2 > size)
				size = old_size * 2;
			NumberTable &nt = _numberTable;
			nt.natural_numbers.resize(size);
			nt.inverse_numbers.resize(size);
			nt.factorials.resize(size);
			nt.inverse_factorials.resize(size);
			if (old_size == 0) {
				nt.natural_numbers[0] = ZeroR();
				nt.inverse_numbers[0] = ZeroR();
				nt.factorials[0] = OneR();
				nt.inverse_factorials[0] = OneR();
				++ old_size;
			}
			for (int n = old_size; n < size; ++ n) {
				nt.natural_numbers[n] = nt.natural_numbers[n - 1] + OneR();
				if (IsZeroR(nt.natural_numbers[n])) {
					std::cerr << "No inverse of zero: " << n << std::endl;
					std::abort();
				}
				nt.factorials[n] = nt.factorials[n - 1] * nt.natural_numbers[n];
			}
			nt.inverse_factorials[size - 1] = nt.factorials[size - 1].inverse();
			for (int n = size - 2; n >= old_size; -- n)
				nt.inverse_factorials[n] = nt.inverse_factorials[n + 1] * nt.natural_numbers[n + 1];
			for (int n = old_size; n < size; ++ n)
				nt.inverse_numbers[n] = nt.inverse_factorials[n] * nt.factorials[n - 1];
		}

		Polynomial derivative() const {
			if (empty()) return *this;
			Polynomial res;
			res.resize(size() - 1);
			_derivative(res.data(), data(), size(), getNumberTable(size()).natural_numbers.data());
			return res;
		}

		Polynomial integral() const {
			Polynomial res;
			res.resize(size() + 1);
			_integral(res.data(), data(), size(), getNumberTable(size() + 1).inverse_numbers.data());
			return res;
		}

		Polynomial inverse(int n) const {
			Polynomial res;
			res.resize(n);
			_inverse_power_series(res.data(), n, data(), size());
			return res;
		}

		Polynomial logarithm(int n) const {
			Polynomial res;
			res.resize(n);
			const NumberTable &nt = getNumberTable(std::max(size(), n));
			_log_power_series(res.data(), n, data(), size(), nt.natural_numbers.data(), nt.inverse_numbers.data());
			return res;
		}

		Polynomial exponential(int n) const {
			Polynomial res;
			res.resize(n);
			const NumberTable &nt = getNumberTable(std::max(size(), n));
			_exp_power_series(res.data(), n, data(), size(), nt.natural_numbers.data(), nt.inverse_numbers.data());
			return res;
		}

		static int MULTIPRIME_FFT_THRESHOLD;

	private:
		static NumberTable _numberTable;

		class WorkSpaceStack;

		static void _fill_zero(R *res, int n);
		static void _copy(R *res, const R *p, int n);
		static void _negate(R *res, const R *p, int n);

		static void _add(R *p, const R *q, int n);
		static void _add(R *res, const R *p, int pn, const R *q, int qn);
		static void _subtract(R *p, const R *q, int n);
		static void _subtract(R *res, const R *p, int pn, const R *q, int qn);

		static void _multiply_select_method(R *res, const R *p, int pn, const R *q, int qn);
		static void _square_select_method(R *res, const R *p, int pn);

		static void _multiply_1(R *p, const R *q, int n, R c0);
		static void _multiply_1(R *p, int n, R c0);

		static void _multiply_power_of_two(R *res, const R *p, int n, int k);
		static void _divide_power_of_two(R *res, const R *p, int n, int k);

		static void _schoolbook_multiplication(R *res, const R *p, int pn, const R *q, int qn);

		static void _multiprime_fft(R *res, const R *p, int pn, const R *q, int qn);

		static void _reverse(R *res, const R *p, int pn);
		static void _inverse_power_series(R *res, int resn, const R *p, int pn);
		static void _precompute_reverse_inverse(R *res, int resn, const R *p, int pn);
		static void _divide_precomputed_inverse(R *res, int resn, const R *revp, int pn, const R *inv);
		static void _divide_remainder_precomputed_inverse(R *quot, R *rem, const R *p, int pn, const R *q, int qn, const R *inv);

		static void _derivative(R *res, const R *p, int pn, const R *natural_numbers);
		static void _integral(R *res, const R *p, int pn, const R *inverse_numbers);

		static void _log_power_series(R *res, int resn, const R *p, int pn, const R *natural_numbers, const R *inverse_numbers);
		static void _exp_power_series(R *res, int resn, const R *p, int pn, const R *natural_numbers, const R *inverse_numbers);
	};
	int Polynomial::MULTIPRIME_FFT_THRESHOLD = 8;
	Polynomial::NumberTable Polynomial::_numberTable;

	void Polynomial::_fill_zero(R *res, int n) {
		for (int i = 0; i < n; ++ i)
			res[i] = ZeroR();
	}

	void Polynomial::_copy(R *res, const R *p, int n) {
		for (int i = 0; i < n; ++ i)
			res[i] = p[i];
	}

	void Polynomial::_negate(R *res, const R *p, int n) {
		for (int i = 0; i < n; ++ i)
			res[i] = -p[i];
	}

	void Polynomial::_add(R *res, const R *p, int pn, const R *q, int qn) {
		for (int i = 0; i < qn; ++ i)
			res[i] = p[i] + q[i];
		_copy(res + qn, p + qn, pn - qn);
	}

	void Polynomial::_subtract(R *res, const R *p, int pn, const R *q, int qn) {
		for (int i = 0; i < qn; ++ i)
			res[i] = p[i] - q[i];
		_copy(res + qn, p + qn, pn - qn);
	}

	void Polynomial::_add(R *p, const R *q, int n) {
		_add(p, p, n, q, n);
	}

	void Polynomial::_subtract(R *p, const R *q, int n) {
		_subtract(p, p, n, q, n);
	}

	void Polynomial::_multiply_1(R *res, const R *p, int n, R c0) {
		for (int i = 0; i < n; ++ i)
			res[i] = p[i] * c0;
	}

	void Polynomial::_multiply_1(R *p, int n, R c0) {
		_multiply_1(p, p, n, c0);
	}

	void Polynomial::_multiply_power_of_two(R *res, const R *p, int n, int k) {
		assert(0 < k && k < 31);
		R mul = R(1 << k);
		_multiply_1(res, p, n, mul);
	}

	void Polynomial::_divide_power_of_two(R *res, const R *p, int n, int k) {
		assert(0 < k && k < 31);
		static const R Inv2 = R(2).inverse();
		R inv = k == 1 ? Inv2 : R(1 << k).inverse();
		_multiply_1(res, p, n, inv);
	}


	void Polynomial::_multiply_select_method(R *res, const R *p, int pn, const R *q, int qn) {
		if (pn < qn) std::swap(p, q), std::swap(pn, qn);
		assert(res != p && res != q && pn >= qn && qn > 0);
		int rn = pn + qn - 1;
		if (qn == 1) {
			_multiply_1(res, p, pn, q[0]);
		} else if (qn < MULTIPRIME_FFT_THRESHOLD) {
			_schoolbook_multiplication(res, p, pn, q, qn);
		} else {
			_multiprime_fft(res, p, pn, q, qn);
		}
	}

	void Polynomial::_square_select_method(R *res, const R *p, int pn) {
		_multiply_select_method(res, p, pn, p, pn);
	}

	void Polynomial::_schoolbook_multiplication(R *res, const R *p, int pn, const R *q, int qn) {
		if (qn == 1) {
			_multiply_1(res, p, pn, q[0]);
			return;
		}
		assert(res != p && res != q && pn >= qn && qn > 0);

		_fill_zero(res, pn + qn - 1);
		for (int i = 0; i < pn; ++ i)
			for (int j = 0; j < qn; ++ j)
				res[i + j] += p[i] * q[j];
	}

	void Polynomial::_multiprime_fft(R *res, const R *p, int pn, const R *q, int qn) {
		int resn = pn + qn - 1;

		int n = 0;
		while ((1 << n) < resn) ++ n;

		if (p == q) {
			assert(pn == qn);
			fft::id14(reinterpret_cast<R::ModNum*>(res), resn, reinterpret_cast<const R::ModNum*>(p), pn, n, mint::get_mod_info());
		} else {
			fft::id8(reinterpret_cast<R::ModNum*>(res), resn, reinterpret_cast<const R::ModNum*>(p), pn, reinterpret_cast<const R::ModNum*>(q), qn, n, mint::get_mod_info());
		}
	}

	void Polynomial::_reverse(R *res, const R *p, int pn) {
		if (res == p) {
			std::reverse(res, res + pn);
		} else {
			for (int i = 0; i < pn; ++ i)
				res[pn - 1 - i] = p[i];
		}
	}

	void Polynomial::_inverse_power_series(R *res, int resn, const R *p, int pn) {
		if (resn == 0) return;
		assert(res != p);
		assert(pn > 0);
		assert(!IsZeroR(p[0]));
		if (p[0] != OneR()) {
			unique_ptr<R[]> tmpp(new R[pn]);
			R ic0 = p[0].inverse();
			_multiply_1(tmpp.get(), p, pn, ic0);
			_inverse_power_series(res, resn, tmpp.get(), pn);
			_multiply_1(res, resn, ic0);
			return;
		}
		unique_ptr<R[]> ws(new R[resn * 4]);
		R *tmp1 = ws.get(), *tmp2 = tmp1 + resn * 2;
		_fill_zero(res, resn);
		res[0] = p[0];
		int curn = 1;
		while (curn < resn) {
			int nextn = std::min(resn, curn * 2);
			_square_select_method(tmp1, res, curn);
			_multiply_select_method(tmp2, tmp1, std::min(nextn, curn * 2 - 1), p, std::min(nextn, pn));
			_multiply_power_of_two(res, res, curn, 1);
			_subtract(res, tmp2, nextn);
			curn = nextn;
		}
	}

	void Polynomial::_precompute_reverse_inverse(R *res, int resn, const R *p, int pn) {
		unique_ptr<R[]> ws(new R[pn]);
		R *tmp = ws.get();
		_reverse(tmp, p, pn);
		_inverse_power_series(res, resn, tmp, pn);
	}

	void Polynomial::_divide_precomputed_inverse(R *res, int resn, const R *revp, int pn, const R *inv) {
		unique_ptr<R[]> ws(new R[pn + resn]);
		R *tmp = ws.get();
		_multiply_select_method(tmp, revp, pn, inv, resn);
		_reverse(res, tmp, resn);
	}

	void Polynomial::_divide_remainder_precomputed_inverse(R *quot, R *rem, const R *p, int pn, const R *q, int qn, const R *inv) {
		if (pn < qn) {
			_copy(rem, p, pn);
			_fill_zero(rem + pn, qn - 1 - pn);
			return;
		}
		assert(qn > 0);
		assert(q[qn - 1] == OneR());
		if (qn == 1) return;
		int quotn = pn - qn + 1;
		int rn = qn - 1, tn = std::min(quotn, rn), un = tn + rn;
		unique_ptr<R[]> ws(new R[pn + un + (quot != NULL ? 0 : quotn)]);
		R *revp = ws.get(), *quotmul = revp + pn;
		if (quot == NULL) quot = quotmul + un;
		_reverse(revp, p, pn);
		_divide_precomputed_inverse(quot, quotn, revp, pn, inv);
		_multiply_select_method(quotmul, q, rn, quot, tn);
		_subtract(rem, p, rn, quotmul, rn);
	}

	void Polynomial::_derivative(R *res, const R *p, int pn, const R *natural_numbers) {
		for (int i = 1; i < pn; ++ i)
			res[i - 1] = p[i] * natural_numbers[i];
	}

	void Polynomial::_integral(R *res, const R *p, int pn, const R *inverse_numbers) {
		for (int i = pn - 1; i >= 0; -- i)
			res[i + 1] = p[i] * inverse_numbers[i + 1];
		res[0] = ZeroR();
	}

	void Polynomial::_log_power_series(R *res, int resn, const R *p, int pn, const R *natural_numbers, const R *inverse_numbers) {
		assert(pn > 0);
		assert(p[0] == OneR());
		if (pn == 1 || resn <= 1) {
			_fill_zero(res, resn);
			return;
		}
		unique_ptr<R[]> ws(new R[pn * 2 + resn * 2]);
		R *tmp1 = ws.get(), *tmp2 = tmp1 + pn, *tmp3 = tmp2 + resn;
		_derivative(tmp1, p, pn, natural_numbers);
		_inverse_power_series(tmp2, resn - 1, p, pn);
		_multiply_select_method(tmp3, tmp1, pn - 1, tmp2, resn - 1);
		_integral(res, tmp3, resn - 1, inverse_numbers);
	}

	void Polynomial::_exp_power_series(R *res, int resn, const R *p, int pn, const R *natural_numbers, const R *inverse_numbers) {
		if (resn == 0) return;
		_fill_zero(res, resn);
		if (pn == 0) {
			res[0] = OneR();
			return;
		}
		assert(IsZeroR(p[0]));
		res[0] = OneR();
		unique_ptr<R[]> ws(new R[resn * 3]);
		R *tmp1 = ws.get(), *tmp2 = tmp1 + resn;
		int curn = 1;
		while (curn < resn) {
			int nextn = std::min(resn, curn * 2);
			_log_power_series(tmp1, nextn, res, curn, natural_numbers, inverse_numbers);
			_subtract(tmp1, tmp1, nextn, p, std::min(nextn, pn));
			tmp1[0] -= OneR();
			_multiply_select_method(tmp2, tmp1, nextn, res, curn);
			_negate(res, tmp2, nextn);
			curn = nextn;
		}
	}


}

int id10(int a, int b, int &g) {
	int u = 1, v = 0;
	while (b) {
		int t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	g = a;
	return u;
}

long long crt(long long a1, long long n1, int a2, int n2, long long &resn) {
	int t, g;
	t = id10(n1 % n2, n2, g);
	if ((a1 - a2) % g != 0) return -1;
	int id15 = n2 / g;
	int d = (a2 - a1) / g % id15;
	int h = (long long)d * t % id15;
	if (h < 0) h += id15;
	long long n = n1 * id15;
	long long a = a1 + n1 * h;
	resn = n;
	return a;
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
		const int mods[2] = { (int)1e9 + 7 , (int)1e9 + 9 };
		vector<int> ansmod[2];
		for (int k = 0; k < 2; ++ k) {
			using Polynomial = mod_polynomial::Polynomial;
			mint::set_mod(mods[k]);
			Polynomial p, q;
			p.resize(n + 1);
			q.resize(n + 1);
			for (int i = 0; i < n; ++ i) {
				p.set(sum[i + 1], p.get(sum[i + 1]) + 1);
				q.set(n - sum[i], q.get(n - sum[i]) + 1);
			}
			auto prod = p * q;
			ansmod[k].assign(n + 1, 0);
			for (int i = 1; i <= n; ++ i) 
				ansmod[k][i] = (int)prod.get(n + i).get();
		}
		long long ans0 = 0;
		for (int i = 0, j = 0; i < n; i = j) {
			if (a[i] < x) {
				j = i + 1;
				continue;
			}
			for (; j < n && a[j] >= x; ++ j);
			int t = j - i;
			ans0 += (long long)t * (t + 1) / 2;
		}
		for (int i = 0; i <= n; ++ i) {
			long long ans, dummy;
			ans = i == 0 ? ans0 : crt(ansmod[0][i], mods[0], ansmod[1][i], mods[1], dummy);
			printf("%lld%c", ans, i == n ? '\n' : ' ');
		}
	}
}

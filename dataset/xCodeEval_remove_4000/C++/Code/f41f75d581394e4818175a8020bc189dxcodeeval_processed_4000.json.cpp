















































namespace Polynomial {
	using std::size_t;

	inline bool id10(size_t x) {
		return x != 0 && (x & (x - 1)) == 0; 

	}

	template<typename T> class polynomial;

	template<typename T>
	polynomial<T> & id9(polynomial<T> & lhs, polynomial<T> rhs);

	template<typename T>
	class polynomial: public std::vector<T> {
		typedef typename std::vector<T> container;

	public:
		typedef size_t size_type;
		typedef typename container::iterator iterator;
		typedef typename container::reverse_iterator reverse_iterator;
		typedef typename container::const_iterator const_iterator;
		typedef typename container::const_reverse_iterator const_reverse_iterator;

		polynomial(): container() {}

		explicit polynomial(size_type n): container(n) {}

		polynomial(size_type n, const T & val): container(n, val) {}

		template<typename InputIterator>
		polynomial(InputIterator first, InputIterator last): container(first, last) {}


		polynomial(std::initializer_list<T> il): container(il) {}

		template<typename... Args>
		explicit polynomial(Args... args): container(args...) {}



		


	private:
		void fft_impl(bool forward) {
			if (this->empty()) return;

			const size_type _size = this->size();
			if (id10(_size)) {
				size_t i, j, k;
				for (i = j = 0; i < _size; ++i) {
					if (i < j) std::swap((*this)[i], (*this)[j]);
					for (k = POLYNOMIAL_DIV2(_size); (j ^= k) < k; POLYNOMIAL_DIV2_ASSIGN(k));
				}

				for (i = 2; i <= _size; POLYNOMIAL_MUL2_ASSIGN(i)) {
					const T principal_root(
												forward ?
												id11(static_cast<T>(i)) :
												id3(static_cast<T>(i))
												);
					for (j = 0; j < _size; j += i) {
						T id8(1);
						for (k = 0; k < POLYNOMIAL_DIV2(i); ++k) {
							T & v1 = (*this)[j + k], & v2 = (*this)[j + k + POLYNOMIAL_DIV2(i)];
							T temp = id8 * v2;
							v2 = v1 - temp;
							v1 += temp;
							id8 *= principal_root;
						}
					}
				}
			} else {
				

			}
		}

	public:
		polynomial & cut(size_type n) {
			if (this->size() > n) this->resize(n);
			return *this;
		}

		bool is_constant() {
			if (this->empty()) return true;
			bool flag = true;
			for (iterator it = this->begin() + 1; flag && it != this->end(); ++it)
				if (*it != static_cast<T>(0)) flag = false;
			return flag;
		}

		void reverse() {
			std::reverse(this->begin(), this->end());
		}

		polynomial derivative() const {
			if (this->empty()) return polynomial();
			polynomial p(this->size() - 1);
			for (size_type i = 1; i < this->size(); ++i)
				p[i - 1] = static_cast<T>(i) * (*this)[i];
			return p;
		}

		polynomial integral() const {
			polynomial p(this->size() + 1, static_cast<T>(0));
			for (size_type i = 0; i < this->size(); ++i)
				p[i + 1] = (*this)[i] / static_cast<T>(i + 1);
			return p;
		}

		polynomial antiderivative() const {
			return integral();
		}

		void fft() {
			fft_impl(true);
		}

		void ifft() {
			fft_impl(false);
			const size_type _size = this->size();
			for (iterator it = this->begin(); it != this->end(); ++it)
				*it /= _size;
		}

		polynomial operator + () const {
			return *this;
		}

		polynomial operator - () const {
			polynomial p(*this);
			for (iterator it = p.begin(); it != p.end(); ++it)
				*it = -*it;
			return p;
		}

		polynomial & operator ++ () {
			if (this->empty()) {
				T temp(0);
				this->push_back(++temp);
			} else {
				++(*this)[0];
			}
			return *this;
		}

		polynomial & operator -- () {
			if (this->empty()) {
				T temp(0);
				this->push_back(--temp);
			} else {
				--(*this)[0];
			}
			return *this;
		}

		polynomial operator ++ (int) {
			polynomial p(*this);
			++*this;
			return p;
		}

		polynomial operator -- (int) {
			polynomial p(*this);
			--*this;
			return p;
		}

		polynomial operator + (const polynomial & rhs) const {
			polynomial p(*this);
			return p += rhs;
		}

		polynomial operator + (T rhs) const {
			polynomial p(*this);
			return p += rhs;
		}

		polynomial operator - (const polynomial & rhs) const {
			polynomial p(*this);
			return p -= rhs;
		}

		polynomial operator - (T rhs) const {
			polynomial p(*this);
			return p -= rhs;
		}

		polynomial operator * (const polynomial & rhs) const {
			polynomial p(*this);
			return p *= rhs;
		}

		polynomial operator * (T rhs) const {
			polynomial p(*this);
			return p *= rhs;
		}

		polynomial operator / (const polynomial & rhs) const {
			polynomial p(this->rbegin(), this->rend());
            return id9(p, rhs);
		}

		polynomial operator / (T rhs) const {
			polynomial p(*this);
			return p /= rhs;
		}

		polynomial operator % (const polynomial & rhs) const {
			polynomial p(*this);
			return p %= rhs;
		}

		polynomial operator << (size_type n) const {
			polynomial p(*this);
			return p <<= n;
		}

		polynomial operator >> (size_type n) const {
			return polynomial(this->begin() + n, this->end());
		}

        polynomial & operator += (const polynomial & rhs) {
        	if (this->size() < rhs.size()) this->resize(rhs.size());
        	iterator it1 = this->begin();
			const_iterator it2 = rhs.begin();
			while (it2 != rhs.end()) *it1++ += *it2++;
			return *this;
        }

        polynomial & operator += (T rhs) {
        	if (this->empty())
				this->push_back(rhs);
			else
				(*this)[0] += rhs;
			return *this;
        }

        polynomial & operator -= (const polynomial & rhs) {
        	if (this->size() < rhs.size()) this->resize(rhs.size());
        	iterator it1 = this->begin();
			const_iterator it2 = rhs.begin();
			while (it2 != rhs.end()) *it1++ -= *it2++;
			return *this;
        }

        polynomial & operator -= (T rhs) {
        	if (this->empty())
				this->push_back(-rhs);
			else
				(*this)[0] -= rhs;
			return *this;
        }

        polynomial & operator *= (polynomial rhs) {
        	if (this->empty()) return *this;
        	if (rhs.empty()) {
				this->clear();
				return *this;
        	}

        	size_type id12 = this->size() + rhs.size() - 1, fft_length = 1;
        	while (fft_length < id12) POLYNOMIAL_MUL2_ASSIGN(fft_length);


        	this->resize(fft_length);
        	rhs.resize(fft_length);

        	T mult = T(0, 1);
			for (iterator it1 = this->begin(), it2 = rhs.begin(); it1 != this->end(); ++it1, ++it2)
				*it2 += *it1 * mult;
			rhs.fft();

			mult = T(0, -1);
			mult /= 4;
			this->front() = (rhs.front() * rhs.front() - conj(rhs.front() * rhs.front())) * mult;
			for (iterator it1 = this->begin() + 1, it2 = rhs.begin() + 1, it3 = rhs.end() - 1; it1 != this->end(); ++it1, ++it2, --it3)
				*it1 = (*it2 * *it2 - conj(*it3 * *it3)) * mult;

        	this->resize(fft_length);
        	this->fft();
        	rhs.resize(fft_length);
        	rhs.fft();
        	for (iterator it1 = this->begin(), it2 = rhs.begin(); it1 != this->end(); ++it1, ++it2)
				*it1 *= *it2;



        	this->ifft();

        	this->resize(id12);

        	return *this;
        }

        polynomial & operator *= (T rhs) {
        	for (iterator it = this->begin(); it != this->end(); ++it) *it *= rhs;
        	return *this;
        }

        polynomial & operator /= (const polynomial & rhs) {
        	this->reverse();
        	return id9(*this, rhs);
        }

        polynomial & operator /= (T rhs) {
        	for (iterator it = this->begin(); it != this->end(); ++it) *it /= rhs;
        	return *this;
        }

        polynomial & operator %= (const polynomial & rhs) {
			return *this -= *this / rhs * rhs;
        }

        polynomial & operator <<= (size_type n) {
        	this->resize(this->size() + n);

			std::memmove(&*this->end() - n, &*this->begin(), sizeof(T) * (this->size() - n));
			std::memset(&*this->begin(), 0, sizeof(T) * n);

        	std::copy_backward(this->begin(), this->end() - n, this->end());
        	fill_n(this->begin(), n, static_cast<T>(0));


			return *this;
        }

        polynomial & operator >>= (size_type n) {

			std::memmove(&*this->begin(), &*this->begin() + n, sizeof(T) * (this->size() - n));

			std::copy(this->begin() + n, this->end(), this->begin());


			this->resize(this->size() - n);
			return *this;
        }

        T operator () (T param) const {
        	if (this->empty()) return static_cast<T>(0);
        	T result(this->back());
        	for (const_reverse_iterator it = this->rbegin() + 1; it != this->rend(); ++it) (result *= param) += *it;
        	return result;
        }

        



        explicit


        operator bool() const {
        	bool flag = false;
        	for (iterator it = this->begin(); it != this->end() && !flag; ++it)
				flag = flag || *it;
        	return flag;
        }
	};

	template<typename T>
	inline polynomial<T> operator + (T lhs, const polynomial<T> & rhs) {
		return rhs + lhs;
	}

	template<typename T>
	inline polynomial<T> operator - (T lhs, const polynomial<T> & rhs) {
		return -rhs + lhs;
	}

	template<typename T>
	inline polynomial<T> operator * (T lhs, const polynomial<T> & rhs) {
		return rhs * lhs;
	}

	template<typename T, typename Float>
	polynomial<T> & id6(polynomial<T> & p, Float eps) {
		for (typename polynomial<T>::iterator it = p.begin(); it != p.end(); ++it) clean(*it, eps);
		return p;
	}

	template<typename T>
	typename polynomial<T>::size_type id5(polynomial<T> & p) {
		typename polynomial<T>::iterator it(p.begin());
		for (; *it == static_cast<T>(0) && it != p.end(); ++it);
		typename polynomial<T>::size_type result(it - p.begin());
		p.assign(it, p.end());
		return result;
	}


	\
	typedef typename polynomial<T>::size_type size_type; \
	\
	if ((n) == 0) return polynomial<T>(); \
	\
	polynomial<T> (g)(1); \
	POLYNOMIAL_TRY ( \
		(g)[0] = id0; \
	) POLYNOMIAL_CATCH (..., \
		throw std::runtime_error("Polynomial::Newton's method: Newton's method error."); \
	) \
	const size_type sz = id4; \
	(g).reserve(sz); \
	\
	std::vector<size_type> stack; \
	\
	while ((n) != 1) { \
		stack.push_back((n)); \
		(n) = POLYNOMIAL_DIV2(n) + POLYNOMIAL_MOD2(n); \
	} \
	\
	while (!stack.empty()) { \
		(n) = stack.back(); \
		stack.pop_back(); \
		\
		expansion_func_impl \
		(g).resize(n); \
	}

	template<typename T>
	inline polynomial<T> inverse(const polynomial<T> & p, typename polynomial<T>::size_type n) {

		if (n != 0 && (p.empty() || p[0] == static_cast<T>(0)))
			throw std::runtime_error("Polynomial::inverse: Inverse element of passed polynomial can't be calculated");



		polynomial<T> f;
		f.reserve(POLYNOMIAL_MUL2(n) + POLYNOMIAL_MOD2(n));

		POLYNOMIAL_NEWTONS_METHOD(n, p, g,
		(POLYNOMIAL_MUL2(n) + POLYNOMIAL_MOD2(n)),
		(static_cast<T>(1) / p[0]),

        f.resize(std::min(n, p.size())); std::memcpy(&*f.begin(), &*p.begin(), sizeof(T) * f.size());

		f.assign(p.begin(), p.begin() + std::min(n, p.size()));


        g *= static_cast<T>(2) - (f * g).cut(n); );

		return g;
	}

	template<typename T>
	inline polynomial<T> inverse(const polynomial<T> & p) {
		return inverse(p, p.size());
	}

	template<typename T>
	inline polynomial<T> & id9(polynomial<T> & lhs, polynomial<T> rhs) {
		while (rhs.back() == static_cast<T>(0)) rhs.pop_back();

		if (rhs.empty()) throw std::runtime_error("Polynomial::polynomial::operator \'/\' or \'/=\': Divisor passed is zero.");


		while (lhs.back() == static_cast<T>(0)) lhs.pop_back();
       	typename polynomial<T>::size_type id12 = std::max(lhs.size() - rhs.size() + 1, static_cast<typename polynomial<T>::size_type>(0));
       	rhs.reverse();
       	lhs *= inverse(rhs, id12);
       	lhs.resize(id12);
       	lhs.reverse();
       	return lhs;
	}

	template<typename T>
	inline polynomial<T> div(const polynomial<T> & lhs, const polynomial<T> & rhs, typename polynomial<T>::size_type n) {
		polynomial<T> p(lhs.begin(), lhs.begin() + std::min(n, lhs.size()));
		p *= inverse(rhs, n);
		p.resize(n);
		return p;
	}

	template<typename T>
	inline polynomial<T> div(const polynomial<T> & lhs, const polynomial<T> & rhs) {
		return div(lhs, rhs, std::max(lhs.size(), rhs.size()));
	}

	template<typename T>
	inline polynomial<T> log(const polynomial<T> & p, typename polynomial<T>::size_type n) {
		if (n == 0) return polynomial<T>();


		if (p[0] == static_cast<T>(0)) throw std::runtime_error("Polynomial::log: Logarithm of passed polynomial can't be calculated.");



		polynomial<T> q(div(p.derivative(), p, n - 1).integral());
		return q;
	}

	template<typename T>
	inline polynomial<T> log(const polynomial<T> & p) {
		return log(p, p.size());
	}

	template<typename T>
	inline polynomial<T> exp(polynomial<T> p, typename polynomial<T>::size_type n) {
		if (p.empty()) {
			polynomial<T> result(n, 0);
			result[0] = static_cast<T>(1);
			return result;
		}

		T exp_constant;
		POLYNOMIAL_TRY (
			exp_constant = exp(p[0]);
		) POLYNOMIAL_CATCH (...,
			throw std::runtime_error("Polynomial::exp: Exponential of passed polynomial can't be calculated.");
		)
		p[0] = static_cast<T>(0);

		polynomial<T> f;
		f.reserve(POLYNOMIAL_DIV2(n) + POLYNOMIAL_MOD2(n) + n);

		POLYNOMIAL_NEWTONS_METHOD(n, p, g,
		POLYNOMIAL_DIV2(n) + POLYNOMIAL_MOD2(n) + n,
		static_cast<T>(1),

		f.resize(std::min(n, p.size())); std::memcpy(&*f.begin(), &*p.begin(), sizeof(T) * f.size());

		f.assign(p.begin(), p.begin() + std::min(n, p.size()));


		g *= static_cast<T>(1) - log(g, n) + f; );

        for (typename polynomial<T>::iterator it = g.begin(); it != g.end(); ++it) *it *= exp_constant;

        return g;
	}

	template<typename T>
	inline polynomial<T> exp(const polynomial<T> & p) {
		return exp(p, p.size());
	}

	template<typename T>
	inline polynomial<T> sqrt(const polynomial<T> & p, typename polynomial<T>::size_type n) {
		if (p.empty()) return polynomial<T>(n, 0);

		T sqrt_constant;
		POLYNOMIAL_TRY (
			sqrt_constant = sqrt(p[0]);
		) POLYNOMIAL_CATCH (...,
			throw std::runtime_error("Polynomial::sqrt: Square root of passed polynomial can't be calculated.");
		)

		POLYNOMIAL_NEWTONS_METHOD(n, p, g,
		n,
		sqrt_constant,
		(g += div(p, g, n)) /= static_cast<T>(2); );

		return g;
	}

	template<typename T>
	inline polynomial<T> sqrt(const polynomial<T> & p) {
		return sqrt(p, p.size());
	}

	template<typename T>
	inline polynomial<T> id15(const polynomial<T> & p, typename polynomial<T>::size_type n) {
		if (p.empty()) return polynomial<T>(n, 0);

		T id1;
		POLYNOMIAL_TRY (
			id1 = id15(p[0]);
		) POLYNOMIAL_CATCH (...,
			throw std::runtime_error("Polynomial::sqrt: Cube root of passed polynomial can't be calculated.");
		)

		POLYNOMIAL_NEWTONS_METHOD(n, p, g,
		n,
		id1,
		(g = g * static_cast<T>(2) + div(p, g * g, n)) /= static_cast<T>(3); );

		return g;
	}

	template<typename T>
	inline polynomial<T> id15(const polynomial<T> & p) {
		return id15(p, p.size());
	}

	template<typename T>
	inline polynomial<T> pow(const polynomial<T> & p, T e, typename polynomial<T>::size_type n) {
		return exp(log(p, n) * e, n) * pow(p[0], e);
	}

	template<typename T>
	inline polynomial<T> pow(const polynomial<T> & p, T e) {
		return pow(p, e, p.size());
	}


} 




namespace Polynomial {
	template<typename T>
	inline std::ostream & operator << (std::ostream & os, const polynomial<T> & p) {
		if (!p.empty()) {
			typename polynomial<T>::const_reverse_iterator it = p.rbegin();
			os << *it++;
			while (it != p.rend()) os << ' ' << *it++;
		}
		return os;
	}



} 























































namespace ModularInt {
	namespace Detail {



		using std::uintmax_t;
		using std::is_unsigned;

		template<typename T>
		struct limits {
			static constexpr T min = std::numeric_limits<T>::min();
			static constexpr T max = std::numeric_limits<T>::max();
		};

		template<bool flag>
		struct static_asserter;

		template<>
		struct static_asserter<true> {
			typedef void type;
		};



		

		typedef unsigned long long uintmax_t;

		template<typename T>
		struct is_unsigned {
			enum {
				value = static_cast<T>(0) < static_cast<T>(-1)
			};
		};

		template<typename T>
		struct limits {
			static const T min;
			static const T max;
		};

		template<typename T>
		const T limits<T>::min(is_unsigned<T>::value ? 0 : static_cast<uintmax_t>(1) << ((sizeof(T) << 3) - 1));

		template<typename T>
		const T limits<T>::max(is_unsigned<T>::value ? -1 : ~(static_cast<uintmax_t>(1) << ((sizeof(T) << 3) - 1)));



		typedef long double floatmax_t;

		template<uintmax_t m>
		struct modular_primitive_root {
			static const uintmax_t value;
		};

		template<>
		const uintmax_t modular_primitive_root<static_cast<uintmax_t>(998244353)>::value(3);

		


		template<typename T>
		struct id14 {
			T m_gcd, m_x, m_y;

			id14(T gcd, T x, T y): m_gcd(gcd), m_x(x), m_y(y) {}

			id14 operator - () {
				return id14(m_gcd, -m_x, -m_y);
			}
		};

		template<typename T>
		id14<T> id2(T a, T b) {
			if (b == static_cast<T>(0)) return id14<T>(a, 1, 0);
			id14<T> temp(id2(b, a % b));
			return id14<T>(temp.m_gcd, temp.m_y, temp.m_x - a / b * temp.m_y);
		}
	}


	{ \
		type id7(lhs), id13(rhs); \
		result = zero; \
		while (id13 != 0) { \
			if (MODULAR_MOD2(id13) != 0) \
				result = static_cast<type>((static_cast<calc_type>(result) op static_cast<calc_type>(id7)) % static_cast<calc_type>(mod)); \
			id7 = static_cast<type>((static_cast<calc_type>(id7) op static_cast<calc_type>(id7)) % mod); \
			MODULAR_DIV2_ASSIGN(id13); \
		} \
	}

	template<typename T, T m, typename MultiplyT>
	class id16;

	template<typename T, T m, typename MultiplyT = T>
	class id16 {
		MODULAR_STATIC_ASSERT(m > 1 && Detail::limits<T>::max / 2 >= m, "ModularInt::id16 is being instantiated with a invalid modulus.");
	public:
		typedef T base_type;
		typedef MultiplyT multiply_type;

		static const T modulus;
		static const T primitive_root;

	private:
		static const T zero;

		enum {
			can_raw_multiply = Detail::limits<MultiplyT>::max / (m - 1) >= m - 1
		};

		T m_value;

	public:
		id16(): m_value() {}
		id16(T value): m_value(value % m) {}

		const id16 inverse() const {

			if (m_value == 0) throw std::runtime_error("ModularInt::id16::inverse: Inverse element of current value can't be calculated.");


			const Detail::id14<T> temp(Detail::is_unsigned<T>::value || m_value > 0 ? Detail::id2(m, m_value) : -Detail::id2(m, -m_value));

			if (temp.m_gcd != 1) throw std::runtime_error("ModularInt::id16::inverse: Inverse element of current value can't be calculated.");


			return (temp.m_y + m) % m;
		}
		


		const id16 operator + () const {
			return *this;
		}

		const id16 operator - () const {
			id16 i(*this);
			i.m_value = (zero - i.m_value) % m;
			return i;
		}

		id16 & operator ++ () {
			++m_value %= m;
			return *this;
		}

		id16 & operator -- () {
			(m_value += zero - 1) %= m;
			return *this;
		}

		const id16 operator ++ (int) {
			id16 i(*this);
			++*this;
			return i;
		}

		const id16 operator -- (int) {
			id16 i(*this);
			--*this;
			return i;
		}

		const id16 operator + (const id16 & rhs) const {
			id16 i(*this);
			return i += rhs;
		}

		const id16 operator + (const T & rhs) const {
			return *this + static_cast<id16>(rhs);
		}

		const id16 operator - (const id16 & rhs) const {
			id16 i(*this);
			return i -= rhs;
		}

		const id16 operator - (const T & rhs) const {
			return *this - static_cast<id16>(rhs);
		}

		const id16 operator * (const id16 & rhs) const {
			id16 i(*this);
			return i *= rhs;
		}

		const id16 operator * (const T & rhs) const {
			return *this * static_cast<id16>(rhs);
		}

		const id16 operator / (const id16 & rhs) const {
			id16 i(*this);
			return i /= rhs;
		}

		const id16 operator / (const T & rhs) const {
			return *this / static_cast<id16>(rhs);
		}

		const id16 operator % (const id16 & rhs) const {
			return *this % rhs.m_value;
		}

		const id16 operator % (const T & rhs) const {
			id16 i(*this);
			return i %= rhs;
		}

		id16 & operator = (const id16 & rhs) {
			m_value = rhs.m_value;
			return *this;
		}

		id16 & operator = (const T & rhs) {
			m_value = rhs % m;
			return *this;
		}

		id16 & operator += (const id16 & rhs) {
			(m_value += rhs.m_value) %= m;
			return *this;
		}

		id16 & operator -= (const id16 & rhs) {
			(m_value += zero - rhs.m_value) %= m;
			return *this;
		}

		id16 & operator *= (const id16 & rhs) {
			if (can_raw_multiply) {
				m_value = static_cast<T>(static_cast<MultiplyT>(m_value) * static_cast<MultiplyT>(rhs.m_value) % static_cast<MultiplyT>(m));
			} else {

				m_value = static_cast<MultiplyT>(static_cast<MultiplyT>(m_value) * static_cast<MultiplyT>(rhs.m_value) -
							static_cast<MultiplyT>(static_cast<Detail::floatmax_t>(m_value) * static_cast<Detail::floatmax_t>(rhs.m_value) / static_cast<Detail::floatmax_t>(m)) * m
							) % m;

				if (Detail::is_unsigned<T>::value || rhs.m_value > 0) {
					MODULAR_FAST_POW(T, m, T, +, static_cast<T>(0), m_value, rhs.m_value, m_value);
				} else if (rhs.m_value < 0) {
					MODULAR_FAST_POW(T, m, T, +, static_cast<T>(0), m_value, -rhs.m_value, m_value);
					m_value = zero - m_value;
				} else {
					m_value = 0;
				}


			}
			return *this;
		}

		id16 & operator /= (const id16 & rhs) {
			return *this *= rhs.inverse();
		}

		id16 & operator %= (const T & rhs) {
			m_value %= rhs;
			return *this;
		}

		id16 & operator &= (const T & rhs) {
			m_value &= rhs;
			return *this;
		}

		id16 & operator ^= (const T & rhs) {
			m_value ^= rhs;
			return *this;
		}

		id16 & operator |= (const T & rhs) {
			m_value |= rhs;
			return *this;
		}

		id16 & operator <<= (const unsigned & rhs) {
			m_value <<= rhs;
			return *this;
		}

		id16 & operator >>= (const unsigned & rhs) {
			m_value >>= rhs;
			return *this;
		}

		operator const T () const {
			return m_value;
		}

		id16 & raw_div(const id16 & rhs) {
			m_value /= rhs.m_value;
			return *this;
		}

		id16 & raw_div(const T & rhs) {
			m_value /= rhs;
			return *this;
		}

		friend const id16 operator + (const T & lhs, const id16 & rhs) {
			return rhs + lhs;
		}

		friend const id16 operator - (const T & lhs, const id16 & rhs) {
			return -rhs + lhs;
		}

		friend const id16 operator * (const T & lhs, const id16 & rhs) {
			return rhs * lhs;
		}

		friend const id16 operator / (const T & lhs, const id16 & rhs) {
			return static_cast<id16>(lhs) / rhs;
		}

		friend const id16 raw_div(const id16 & lhs, const id16 & rhs) {
			return static_cast<id16>(lhs.m_value / rhs.m_value);
		}

		friend const id16 raw_div(const id16 & lhs, const T & rhs) {
			return static_cast<id16>(lhs.m_value / rhs);
		}

		friend const id16 raw_div(const T & lhs, const id16 & rhs) {
			return static_cast<id16>(lhs / rhs.m_value);
		}

		friend const id16 pow(const id16 & lhs, const id16 & rhs) {
			if (Detail::is_unsigned<T>::value || rhs.m_value > 0) {
				id16 result;
				MODULAR_FAST_POW(T, m, MultiplyT, *, static_cast<id16>(1), lhs.m_value, rhs.m_value, result);
				return result;
			} else if (rhs < 0) {
				id16 result;
				MODULAR_FAST_POW(T, m, MultiplyT, *, static_cast<id16>(1), lhs.inverse().m_value, -rhs.m_value, result);
				return result;
			} else {
				return static_cast<id16>(1);
			}
		}

		friend const id16 exp(const id16 & lhs, const id16 & rhs) {

			if (rhs.m_value != 0) throw("ModularInt::exp: Exponentiation of id16 with non-zero exponent can't be calculated.");


			return static_cast<id16>(1);
		}

		friend const id16 sqrt(const id16 & id17) {
			return 1;
		}

		friend const id16 id15(const id16 & id17) {

		}
	};

	template<typename T, T m, typename MultiplyT>
	const T id16<T, m, MultiplyT>::modulus(m);

	template<typename T, T m, typename MultiplyT>
	const T id16<T, m, MultiplyT>::primitive_root(Detail::modular_primitive_root<m>::value);

	template<typename T, T m, typename MultiplyT>
	const T id16<T, m, MultiplyT>::zero(Detail::is_unsigned<T>::value ? m : static_cast<T>(0));

	template<typename T>
	const T id11(T n) {
		MODULAR_STATIC_ASSERT(true, "ModularInt::id11: Passed argument is not of an instantiation type of ModularInt::id16.");
		return pow(static_cast<T>(T::primitive_root), static_cast<T>((T::modulus - 1) / n));
	}

	template<typename T>
	const T id3(T n) {
		MODULAR_STATIC_ASSERT(true, "ModularInt::id3: Passed argument is not of an instantiation type of ModularInt::id16.");
		return pow(static_cast<T>(T::primitive_root), static_cast<T>(T::modulus - 1 - (T::modulus - 1) / n));
	}
}




int main() {
	using namespace std;
	using namespace Polynomial;
	using namespace ModularInt;

	typedef id16<unsigned int, 998244353, unsigned long long> mi;
	typedef polynomial<mi> poly;

	int n, m, i, c;

	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	poly p(m + 2);
	p[m + 1] = 1;

	while (n--) {
		cin >> c;
		if (c <= m) p[c] = 1;
	}

	poly divisor(p * mi(2));
	unsigned zero_cnt = id5(divisor);

    p = div((mi(1) - sqrt(mi(1) - mi(4) * p, zero_cnt + p.size())), divisor);
    p >>= zero_cnt;

    for (i = 1; i <= m; ++i) cout << p[i] << '\n';

	return 0;
}

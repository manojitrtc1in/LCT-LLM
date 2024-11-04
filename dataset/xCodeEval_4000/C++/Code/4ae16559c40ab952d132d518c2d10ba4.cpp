#include <iostream>
#define POLYNOMIAL_NO_EXCEPTIONS

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <cstddef>
#include <vector>
#include <algorithm>

#ifdef POLYNOMIAL_NO_EXCEPTIONS
#define POLYNOMIAL_TRY(...) __VA_ARGS__
#define POLYNOMIAL_CATCH(x, ...)
#else
#include <stdexcept>
#define POLYNOMIAL_TRY(...) try {__VA_ARGS__}
#define POLYNOMIAL_CATCH(x, ...) catch(x) {__VA_ARGS__}
#endif 


#ifdef POLYNOMIAL_USE_CSTRING
#include <cstring>
#endif 


#if __cplusplus >= 201103L
#include <initializer_list>
#endif 


#ifdef POLYNOMIAL_USE_BITWISE_OPERATION
#define POLYNOMIAL_MUL2(x) ((x) << 1)
#define POLYNOMIAL_DIV2(x) ((x) >> 1)
#define POLYNOMIAL_MOD2(x) ((x) & 1)
#define POLYNOMIAL_MUL2_ASSIGN(x) ((x) <<= 1)
#define POLYNOMIAL_DIV2_ASSIGN(x) ((x) >>= 1)
#define POLYNOMIAL_MOD2_ASSIGN(x) ((x) &= 1)
#else
#define POLYNOMIAL_MUL2(x) ((x) * 2)
#define POLYNOMIAL_DIV2(x) ((x) / 2)
#define POLYNOMIAL_MOD2(x) ((x) % 2)
#define POLYNOMIAL_MUL2_ASSIGN(x) ((x) *= 2)
#define POLYNOMIAL_DIV2_ASSIGN(x) ((x) /= 2)
#define POLYNOMIAL_MOD2_ASSIGN(x) ((x) %= 2)
#endif 


#define POLYNOMIAL_MACRO_CALL_1_(f, x) f(x)
#define POLYNOMIAL_MACRO_CALL_1(f, x) POLYNOMIAL_MACRO_CALL_1_(f, x)

namespace Polynomial {
	using std::size_t;

	inline bool is_power_of_2(size_t x) {
		return x != 0 && (x & (x - 1)) == 0; 

	}

	template<typename T> class polynomial;

	template<typename T>
	polynomial<T> & reverse_div_assign_impl(polynomial<T> & lhs, polynomial<T> rhs);

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

#if __cplusplus >= 201103L
		polynomial(std::initializer_list<T> il): container(il) {}

		template<typename... Args>
		explicit polynomial(Args... args): container(args...) {}
#endif 


		


	private:
		void fft_impl(bool forward) {
			if (this->empty()) return;

			const size_type sz = this->size();
			if (is_power_of_2(sz)) {
				size_t i, j, k;
				for (i = j = 0; i < sz; ++i) {
					if (i < j) std::swap((*this)[i], (*this)[j]);
					for (k = POLYNOMIAL_DIV2(sz); (j ^= k) < k; POLYNOMIAL_DIV2_ASSIGN(k));
				}

				for (i = 2; i <= sz; POLYNOMIAL_MUL2_ASSIGN(i)) {
					const T principal_root(
												forward ?
												principal_nth_root_of_unity(static_cast<T>(i)) :
												reciprocal_of_principal_nth_root_of_unity(static_cast<T>(i))
												);
					for (j = 0; j < sz; j += i) {
						T root_of_unity(1);
						for (k = 0; k < POLYNOMIAL_DIV2(i); ++k) {
							T & v1 = (*this)[j + k], & v2 = (*this)[j + k + POLYNOMIAL_DIV2(i)];
							T temp = root_of_unity * v2;
							v2 = v1 - temp;
							v1 += temp;
							root_of_unity *= principal_root;
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
			const size_type sz = this->size();
			for (iterator it = this->begin(); it != this->end(); ++it)
				*it /= sz;
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
			return reverse_div_assign_impl(p, rhs);
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

			size_type resulting_size = this->size() + rhs.size() - 1, fft_length = 1;
			while (fft_length < resulting_size) POLYNOMIAL_MUL2_ASSIGN(fft_length);

#ifdef POLYNOMIAL_REAL_MULTIPLICATION
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
#else
			this->resize(fft_length);
			this->fft();
			rhs.resize(fft_length);
			rhs.fft();
			for (iterator it1 = this->begin(), it2 = rhs.begin(); it1 != this->end(); ++it1, ++it2)
				*it1 *= *it2;
#endif 


			this->ifft();

			this->resize(resulting_size);

			return *this;
		}

		polynomial & operator *= (T rhs) {
			for (iterator it = this->begin(); it != this->end(); ++it) *it *= rhs;
			return *this;
		}

		polynomial & operator /= (const polynomial & rhs) {
			this->reverse();
			return reverse_div_assign_impl(*this, rhs);
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
#ifdef POLYNOMIAL_USE_CSTRING
			std::memmove(&*this->end() - n, &*this->begin(), sizeof(T) * (this->size() - n));
			std::memset(&*this->begin(), 0, sizeof(T) * n);
#else
			std::copy_backward(this->begin(), this->end() - n, this->end());
			fill_n(this->begin(), n, static_cast<T>(0));
#endif 

			return *this;
		}

		polynomial & operator >>= (size_type n) {
#ifdef POLYNOMIAL_USE_CSTRING
			std::memmove(&*this->begin(), &*this->begin() + n, sizeof(T) * (this->size() - n));
#else
			std::copy(this->begin() + n, this->end(), this->begin());
#endif 

			this->resize(this->size() - n);
			return *this;
		}

		T operator () (T param) const {
			if (this->empty()) return static_cast<T>(0);
			T result(this->back());
			for (const_reverse_iterator it = this->rbegin() + 1; it != this->rend(); ++it) (result *= param) += *it;
			return result;
		}

		


#if __cplusplus >= 201103L
		explicit
#endif 

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
	polynomial<T> & clean_polynomial(polynomial<T> & p, Float eps) {
		for (typename polynomial<T>::iterator it = p.begin(); it != p.end(); ++it) clean(*it, eps);
		return p;
	}

	template<typename T>
	typename polynomial<T>::size_type count_and_remove_trailing_zeros(polynomial<T> & p) {
		typename polynomial<T>::iterator it(p.begin());
		for (; *it == static_cast<T>(0) && it != p.end(); ++it);
		typename polynomial<T>::size_type result(it - p.begin());
		p.assign(it, p.end());
		return result;
	}

#define POLYNOMIAL_NEWTONS_METHOD_SLOW(n, p, g, size_func_impl, constant_func_impl, expansion_func_impl) \
	\
	typedef typename polynomial<T>::size_type size_type; \
	\
	if ((n) == 0) return polynomial<T>(); \
	\
	polynomial<T> (g)(1); \
	POLYNOMIAL_TRY ( \
		(g)[0] = constant_func_impl; \
	) POLYNOMIAL_CATCH (..., \
		throw std::runtime_error("Polynomial::Newton's method: Newton's method error."); \
	) \
	(g).reserve(size_func_impl); \
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

#ifdef POLYNOMIAL_USE_CSTRING
#define POLYNOMIAL_NEWTONS_METHOD_ASSIGN_F f.resize(std::min(n, p.size())); std::memcpy(&*f.begin(), &*p.begin(), sizeof(T) * f.size());
#else
#define POLYNOMIAL_NEWTONS_METHOD_ASSIGN_F f.assign(p.begin(), p.begin() + std::min(n, p.size()));
#endif 


#define POLYNOMIAL_NEWTONS_METHOD_EX(constant, size_func, expansion_proc, extra_proc) \
	\
	typedef typename polynomial<T>::size_type size_type; \
	\
	if (n == 0) return polynomial<T>(); \
	\
	polynomial<T> g(1, (constant)), f; \
	g.reserve(POLYNOMIAL_MACRO_CALL_1(size_func, n)); \
	f.reserve(POLYNOMIAL_MACRO_CALL_1(size_func, n)); \
	\
	std::vector<size_type> stack; \
	\
	while (n != 1) { \
		stack.push_back(n); \
		n = POLYNOMIAL_DIV2(n + 1); \
	} \
	\
	size_type fft_length = 1; \
	\
	while (!stack.empty()) { \
		n = stack.back(); \
		stack.pop_back(); \
		\
		while (fft_length < (POLYNOMIAL_MACRO_CALL_1(size_func, n))) POLYNOMIAL_MUL2_ASSIGN(fft_length); \
		\
		extra_proc \
		POLYNOMIAL_NEWTONS_METHOD_ASSIGN_F \
		f.resize(fft_length); \
		f.fft(); \
		g.resize(fft_length); \
		g.fft(); \
		for (size_type i = 0; i < fft_length; ++i) \
			do { \
				POLYNOMIAL_MACRO_CALL_1(expansion_proc, i) \
			} while (false); \
		g.ifft(); \
		g.resize(n); \
	}

#define POLYNOMIAL_NEWTONS_METHOD(...) POLYNOMIAL_NEWTONS_METHOD_EX(__VA_ARGS__, )

	template<typename T>
	inline polynomial<T> inverse(const polynomial<T> & p, typename polynomial<T>::size_type n) {

#define POLYNOMIAL_INVERSE_SIZE_FUNC(x) (POLYNOMIAL_MUL2(x) - 2 + POLYNOMIAL_MOD2(x))
#define POLYNOMIAL_INVERSE_EXPANSION_PROC(x) g[x] *= static_cast<T>(2) - g[x] * f[x];

		POLYNOMIAL_TRY(
			POLYNOMIAL_NEWTONS_METHOD(
				(static_cast<T>(1) / p[0]),
				POLYNOMIAL_INVERSE_SIZE_FUNC, 
				POLYNOMIAL_INVERSE_EXPANSION_PROC
			)

			return g;
		) POLYNOMIAL_CATCH (..., 
			throw std::runtime_error("Polynomial::inverse: Inverse element of passed polynomial can't be calculated");
		)

#undef POLYNOMIAL_INVERSE_SIZE_FUNC
#undef POLYNOMIAL_INVERSE_EXPANSION_PROC

	}

	template<typename T>
	inline polynomial<T> inverse(const polynomial<T> & p) {
		return inverse(p, p.size());
	}

	template<typename T>
	inline polynomial<T> & reverse_div_assign_impl(polynomial<T> & lhs, polynomial<T> rhs) {
		while (rhs.back() == static_cast<T>(0)) rhs.pop_back();
#ifndef POLYNOMIAL_NO_EXCEPTIONS
		if (rhs.empty()) throw std::runtime_error("Polynomial::polynomial::operator \'/\' or \'/=\': Divisor passed is zero.");
#endif 

		while (lhs.back() == static_cast<T>(0)) lhs.pop_back();
	   	typename polynomial<T>::size_type resulting_size = std::max(lhs.size() - rhs.size() + 1, static_cast<typename polynomial<T>::size_type>(0));
	   	rhs.reverse();
	   	lhs *= inverse(rhs, resulting_size);
	   	lhs.resize(resulting_size);
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

#ifndef POLYNOMIAL_NO_EXCEPTIONS
		if (p[0] == static_cast<T>(0)) throw std::runtime_error("Polynomial::log: Logarithm of passed polynomial can't be calculated.");
#endif 


		return div(p.derivative(), p, n - 1).integral();
	}

	template<typename T>
	inline polynomial<T> log(const polynomial<T> & p) {
		return log(p, p.size());
	}

	template<typename T>
	inline polynomial<T> exp(polynomial<T> p, typename polynomial<T>::size_type n) {
		
#define POLYNOMIAL_EXP_SIZE_FUNC(x) (n + POLYNOMIAL_DIV2(n + 1))
#define POLYNOMIAL_EXP_EXPANSION_PROC(x) g[x] *= f[x] - h[x];
#define POLYNOMIAL_EXP_EXTRA_PROC \
	h = log(g, n); \
	--h[0]; \
	h.resize(fft_length); \
	h.fft();

		POLYNOMIAL_TRY (
			if (p.empty()) {
				polynomial<T> result(n, 0);
				result[0] = static_cast<T>(1);
				return result;
			}

			T exp_constant;
			exp_constant = exp(p[0]);

			p[0] = static_cast<T>(0);

			polynomial<T> h;
			h.reserve(POLYNOMIAL_EXP_SIZE_FUNC(n));

			POLYNOMIAL_NEWTONS_METHOD_EX(
				(static_cast<T>(1)), 
				POLYNOMIAL_EXP_SIZE_FUNC, 
				POLYNOMIAL_EXP_EXPANSION_PROC, 
				POLYNOMIAL_EXP_EXTRA_PROC
			)
			
			for (typename polynomial<T>::iterator it = g.begin(); it != g.end(); ++it) *it *= exp_constant;

			return g;
		) POLYNOMIAL_CATCH (...,
			throw std::runtime_error("Polynomial::exp: Exponential of passed polynomial can't be calculated.");
		)

#undef POLYNOMIAL_EXP_SIZE_FUNC
#undef POLYNOMIAL_EXP_EXPANSION_PROC
#undef POLYNOMIAL_EXP_EXTRA_PROC

	}

	template<typename T>
	inline polynomial<T> exp(const polynomial<T> & p) {
		return exp(p, p.size());
	}

	template<typename T>
	inline polynomial<T> sqrt(const polynomial<T> & p, typename polynomial<T>::size_type n) {
		

		

		

		POLYNOMIAL_TRY (
			typedef typename polynomial<T>::size_type size_type;
			
			if (n == 0) return polynomial<T>();
			if (p.empty()) return polynomial<T>(n, 0);

			polynomial<T> f, g(1, sqrt(p[0])), h(1, static_cast<T>(1) / g[0]), x;
			f.reserve(POLYNOMIAL_MUL2(n) - 1);
			g.reserve(POLYNOMIAL_MUL2(n) - 1);
			h.reserve(POLYNOMIAL_MUL2(n) - 1);
			x.reserve(POLYNOMIAL_MUL2(n) - 1);

			std::vector<size_type> stack;
			
			while (n != 1) {
				stack.push_back(n);
				n = POLYNOMIAL_DIV2(n + 1);
			}
			
			size_type fft_length(1);
			
			while (!stack.empty()) {
				n = stack.back();
				stack.pop_back();
				
				while (fft_length < POLYNOMIAL_MUL2(n) - 1) POLYNOMIAL_MUL2_ASSIGN(fft_length);

				

				

				


				g.resize(fft_length);
				g.fft();
				h.resize(fft_length);
				h.fft();
				x.resize(fft_length);
				for (size_type i = 0; i < fft_length; ++i)
					x[i] = (static_cast<T>(2) - g[i] * h[i]) * h[i];
				x.ifft();
				x.resize(n);

				


				x.resize(fft_length);
				x.fft();			
#ifdef POLYNOMIAL_USE_CSTRING
				f.resize(std::min(n, p.size()));
				std::memcpy(&*f.begin(), &*p.begin(), sizeof(T) * f.size());
#else
				f.assign(p.begin(), p.begin() + std::min(n, p.size()));
#endif
				f.resize(fft_length);
				f.fft();
				for (size_type i = 0; i < fft_length; ++i)
					g[i] = (g[i] + f[i] * x[i]) / static_cast<T>(2);
				g.ifft();
				g.resize(n);
				g.resize(fft_length);
				g.fft();
				

				

				for (size_type i = 0; i < fft_length; ++i)
					h[i] *= static_cast<T>(2) - g[i] * h[i];
				

				h.ifft();
				h.resize(n);
				g.ifft();
				g.resize(n);
			}

			return g;
		) POLYNOMIAL_CATCH (...,
			throw std::runtime_error("Polynomial::sqrt: Square root of passed polynomial can't be calculated.");
		)
	}

	template<typename T>
	inline polynomial<T> sqrt(const polynomial<T> & p) {
		return sqrt(p, p.size());
	}

	template<typename T>
	inline polynomial<T> cbrt(const polynomial<T> & p, typename polynomial<T>::size_type n) {
		if (p.empty()) return polynomial<T>(n, 0);

		T cbrt_constant;
		POLYNOMIAL_TRY (
			cbrt_constant = cbrt(p[0]);
		) POLYNOMIAL_CATCH (...,
			throw std::runtime_error("Polynomial::sqrt: Cube root of passed polynomial can't be calculated.");
		)

		POLYNOMIAL_NEWTONS_METHOD_SLOW(n, p, g,
		n,
		cbrt_constant,
		(g = g * static_cast<T>(2) + div(p, g * g, n)) /= static_cast<T>(3); );

		return g;
	}

	template<typename T>
	inline polynomial<T> cbrt(const polynomial<T> & p) {
		return cbrt(p, p.size());
	}

	template<typename T>
	inline polynomial<T> pow(const polynomial<T> & p, T e, typename polynomial<T>::size_type n) {
		return exp(log(p, n) * e, n) * pow(p[0], e);
	}

	template<typename T>
	inline polynomial<T> pow(const polynomial<T> & p, T e) {
		return pow(p, e, p.size());
	}

#ifndef POLYNOMIAL_NO_OUTPUT
} 


#include <ostream>

namespace Polynomial {
	template<typename T>
	inline std::ostream & operator << (std::ostream & os, const polynomial<T> & p) {
		if (!p.empty()) {
			typename polynomial<T>::const_iterator it = p.begin();
			os << *it++;
			while (it != p.end()) os << ' ' << *it++;
		}
		return os;
	}
#endif 


} 


#undef POLYNOMIAL_TRY
#undef POLYNOMIAL_CATCH

#undef POLYNOMIAL_MUL2
#undef POLYNOMIAL_DIV2
#undef POLYNOMIAL_MOD2
#undef POLYNOMIAL_MUL2_ASSIGN
#undef POLYNOMIAL_DIV2_ASSIGN
#undef POLYNOMIAL_MOD2_ASSIGN

#undef POLYNOMIAL_MACRO_CALL_1_
#undef POLYNOMIAL_MACRO_CALL_1

#undef POLYNOMIAL_NEWTONS_METHOD_SLOW
#undef POLYNOMIAL_NEWTONS_METHOD_ASSIGN_F
#undef POLYNOMIAL_NEWTONS_METHOD_EX
#undef POLYNOMIAL_NEWTONS_METHOD

#endif 




#define MODULAR_NO_EXCEPTIONS

#ifndef MODULAR_INT_H
#define MODULAR_INT_H

#if __cplusplus >= 201103L
#include <limits>
#include <type_traits>
#include <cstdint>
#endif 


#ifndef MODULAR_NO_EXCEPTIONS
#include <stdexcept>
#endif 


#ifndef MODULAR_NO_INPUT_AND_OUTPUT
#include <iostream>
#endif 


#ifdef MODULAR_USE_BITWISE_OPERATION
#define MODULAR_MUL2(x) ((x) << 1)
#define MODULAR_DIV2(x) ((x) >> 1)
#define MODULAR_MOD2(x) ((x) & 1)
#define MODULAR_MUL2_ASSIGN(x) ((x) <<= 1)
#define MODULAR_DIV2_ASSIGN(x) ((x) >>= 1)
#define MODULAR_MOD2_ASSIGN(x) ((x) &= 1)
#else
#define MODULAR_MUL2(x) ((x) * 2)
#define MODULAR_DIV2(x) ((x) / 2)
#define MODULAR_MOD2(x) ((x) % 2)
#define MODULAR_MUL2_ASSIGN(x) ((x) *= 2)
#define MODULAR_DIV2_ASSIGN(x) ((x) /= 2)
#define MODULAR_MOD2_ASSIGN(x) ((x) %= 2)
#endif 


#define MODULAR_MACRO_CONCAT_(x, y) x##y
#define MODULAR_MACRO_CONCAT(x, y) MODULAR_MACRO_CONCAT_(x, y)

namespace ModularInt {
	template<typename T, T m, typename MultiplyT>
	class modular_int;

	namespace Detail {
#if __cplusplus >= 201103L
#define MODULAR_STATIC_ASSERT(x, y) static_assert((x), y);

		using std::uintmax_t;
		using std::is_unsigned;

		template<typename T>
		struct limits {
			static constexpr T min = std::numeric_limits<T>::min();
			static constexpr T max = std::numeric_limits<T>::max();
		};
#else
		template<bool flag>
		struct static_asserter;

		template<>
		struct static_asserter<true> {
			typedef void type;
		};

#define MODULAR_STATIC_ASSERT(x, y) typedef typename ModularInt::Detail::static_asserter<(x)>::type MODULAR_MACRO_CONCAT(MODULAR_STATIC_ASSERT_ON_LINE_, __LINE__)

		

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
#endif 


		template<typename T>
		struct is_modular_int {
			enum {
				value = 0
			};
		};

		template<typename T, T m, typename MultiplyT>
		struct is_modular_int<modular_int<T, m, MultiplyT> > {
			enum {
				value = 1
			};
		};

		typedef long double floatmax_t;

		template<uintmax_t m>
		struct modular_primitive_root {
			static const uintmax_t value;
		};

		template<>
		const uintmax_t modular_primitive_root<static_cast<uintmax_t>(998244353)>::value(3);

		


		template<typename T>
		struct exgcd_type {
			T m_gcd, m_x, m_y;

			exgcd_type(T gcd, T x, T y): m_gcd(gcd), m_x(x), m_y(y) {}

			exgcd_type operator - () {
				return exgcd_type(m_gcd, -m_x, -m_y);
			}
		};

		template<typename T>
		exgcd_type<T> exgcd(T a, T b) {
			if (b == static_cast<T>(0)) return exgcd_type<T>(a, 1, 0);
			exgcd_type<T> temp(exgcd(b, a % b));
			return exgcd_type<T>(temp.m_gcd, temp.m_y, temp.m_x - a / b * temp.m_y);
		}
	}

#define MODULAR_FAST_POW(type, mod, calc_type, op, zero, lhs, rhs, result) \
	{ \
		type fast_pow_base(lhs), fast_pow_exponent(rhs); \
		result = zero; \
		while (fast_pow_exponent != 0) { \
			if (MODULAR_MOD2(fast_pow_exponent) != 0) \
				result = static_cast<type>((static_cast<calc_type>(result) op static_cast<calc_type>(fast_pow_base)) % static_cast<calc_type>(mod)); \
			fast_pow_base = static_cast<type>((static_cast<calc_type>(fast_pow_base) op static_cast<calc_type>(fast_pow_base)) % mod); \
			MODULAR_DIV2_ASSIGN(fast_pow_exponent); \
		} \
	}

	template<typename T, T m, typename MultiplyT = T>
	class modular_int {
		MODULAR_STATIC_ASSERT(m > 1 && Detail::limits<T>::max / 2 >= m, "ModularInt::modular_int is being instantiated with a invalid modulus.");
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
		modular_int(): m_value() {}
		modular_int(T value): m_value(value % m) {}

		const modular_int inverse() const {
#ifndef MODULAR_NO_EXCEPTIONS
			if (m_value == 0) throw std::runtime_error("ModularInt::modular_int::inverse: Inverse element of current value can't be calculated.");
#endif 

			const Detail::exgcd_type<T> temp(Detail::is_unsigned<T>::value || m_value > 0 ? Detail::exgcd(m, m_value) : -Detail::exgcd(m, -m_value));
#ifndef MODULAR_NO_EXCEPTIONS
			if (temp.m_gcd != 1) throw std::runtime_error("ModularInt::modular_int::inverse: Inverse element of current value can't be calculated.");
#endif 

			return (temp.m_y + m) % m;
		}
		


		const modular_int operator + () const {
			return *this;
		}

		const modular_int operator - () const {
			modular_int i(*this);
			i.m_value = (zero - i.m_value) % m;
			return i;
		}

		modular_int & operator ++ () {
			++m_value %= m;
			return *this;
		}

		modular_int & operator -- () {
			(m_value += zero - 1) %= m;
			return *this;
		}

		const modular_int operator ++ (int) {
			modular_int i(*this);
			++*this;
			return i;
		}

		const modular_int operator -- (int) {
			modular_int i(*this);
			--*this;
			return i;
		}

		const modular_int operator + (const modular_int & rhs) const {
			modular_int i(*this);
			return i += rhs;
		}

		const modular_int operator + (const T & rhs) const {
			return *this + static_cast<modular_int>(rhs);
		}

		const modular_int operator - (const modular_int & rhs) const {
			modular_int i(*this);
			return i -= rhs;
		}

		const modular_int operator - (const T & rhs) const {
			return *this - static_cast<modular_int>(rhs);
		}

		const modular_int operator * (const modular_int & rhs) const {
			modular_int i(*this);
			return i *= rhs;
		}

		const modular_int operator * (const T & rhs) const {
			return *this * static_cast<modular_int>(rhs);
		}

		const modular_int operator / (const modular_int & rhs) const {
			modular_int i(*this);
			return i /= rhs;
		}

		const modular_int operator / (const T & rhs) const {
			return *this / static_cast<modular_int>(rhs);
		}

		const modular_int operator % (const modular_int & rhs) const {
			return *this % rhs.m_value;
		}

		const modular_int operator % (const T & rhs) const {
			modular_int i(*this);
			return i %= rhs;
		}

		modular_int & operator = (const modular_int & rhs) {
			m_value = rhs.m_value;
			return *this;
		}

		modular_int & operator = (const T & rhs) {
			m_value = rhs % m;
			return *this;
		}

		modular_int & operator += (const modular_int & rhs) {
			(m_value += rhs.m_value) %= m;
			return *this;
		}

		modular_int & operator -= (const modular_int & rhs) {
			(m_value += zero - rhs.m_value) %= m;
			return *this;
		}

		modular_int & operator *= (const modular_int & rhs) {
			if (can_raw_multiply) {
				m_value = static_cast<T>(static_cast<MultiplyT>(m_value) * static_cast<MultiplyT>(rhs.m_value) % static_cast<MultiplyT>(m));
			} else {
#ifdef MODULAR_O_1_FAST_MUL
				m_value = static_cast<MultiplyT>(static_cast<MultiplyT>(m_value) * static_cast<MultiplyT>(rhs.m_value) -
							static_cast<MultiplyT>(static_cast<Detail::floatmax_t>(m_value) * static_cast<Detail::floatmax_t>(rhs.m_value) / static_cast<Detail::floatmax_t>(m)) * m
							) % m;
#else
				if (Detail::is_unsigned<T>::value || rhs.m_value > 0) {
					MODULAR_FAST_POW(T, m, T, +, static_cast<T>(0), m_value, rhs.m_value, m_value);
				} else if (rhs.m_value < 0) {
					MODULAR_FAST_POW(T, m, T, +, static_cast<T>(0), m_value, -rhs.m_value, m_value);
					m_value = zero - m_value;
				} else {
					m_value = 0;
				}
#endif 

			}
			return *this;
		}

		modular_int & operator /= (const modular_int & rhs) {
			return *this *= rhs.inverse();
		}

		modular_int & operator %= (const T & rhs) {
			m_value %= rhs;
			return *this;
		}

		modular_int & operator &= (const T & rhs) {
			m_value &= rhs;
			return *this;
		}

		modular_int & operator ^= (const T & rhs) {
			m_value ^= rhs;
			return *this;
		}

		modular_int & operator |= (const T & rhs) {
			m_value |= rhs;
			return *this;
		}

		modular_int & operator <<= (const unsigned & rhs) {
			m_value <<= rhs;
			return *this;
		}

		modular_int & operator >>= (const unsigned & rhs) {
			m_value >>= rhs;
			return *this;
		}

		operator const T () const {
			return m_value;
		}

		modular_int & raw_div(const modular_int & rhs) {
			m_value /= rhs.m_value;
			return *this;
		}

		modular_int & raw_div(const T & rhs) {
			m_value /= rhs;
			return *this;
		}

		friend const modular_int operator + (const T & lhs, const modular_int & rhs) {
			return rhs + lhs;
		}

		friend const modular_int operator - (const T & lhs, const modular_int & rhs) {
			return -rhs + lhs;
		}

		friend const modular_int operator * (const T & lhs, const modular_int & rhs) {
			return rhs * lhs;
		}

		friend const modular_int operator / (const T & lhs, const modular_int & rhs) {
			return static_cast<modular_int>(lhs) / rhs;
		}

		friend const modular_int raw_div(const modular_int & lhs, const modular_int & rhs) {
			return static_cast<modular_int>(lhs.m_value / rhs.m_value);
		}

		friend const modular_int raw_div(const modular_int & lhs, const T & rhs) {
			return static_cast<modular_int>(lhs.m_value / rhs);
		}

		friend const modular_int raw_div(const T & lhs, const modular_int & rhs) {
			return static_cast<modular_int>(lhs / rhs.m_value);
		}

		friend const modular_int pow(const modular_int & lhs, const modular_int & rhs) {
			if (Detail::is_unsigned<T>::value || rhs.m_value > 0) {
				modular_int result;
				MODULAR_FAST_POW(T, m, MultiplyT, *, static_cast<modular_int>(1), lhs.m_value, rhs.m_value, result);
				return result;
			} else if (rhs < 0) {
				modular_int result;
				MODULAR_FAST_POW(T, m, MultiplyT, *, static_cast<modular_int>(1), lhs.inverse().m_value, -rhs.m_value, result);
				return result;
			} else {
				return static_cast<modular_int>(1);
			}
		}

		friend const modular_int exp(const modular_int & exponent) {
#ifndef MODULAR_NO_EXCEPTIONS
			if (exponent.m_value != 0) throw("ModularInt::exp: Exponentiation of modular_int with non-zero exponent can't be calculated.");
#endif 

			return static_cast<modular_int>(1);
		}

		friend const modular_int sqrt(const modular_int & radicand) {
			return 1;
		}

		friend const modular_int cbrt(const modular_int & radicand) {

		}

#ifndef MODULAR_NO_INPUT_AND_OUTPUT
		friend std::istream & operator >> (std::istream & is, modular_int & x) {
			return is >> x.m_value;
		}

		friend std::ostream & operator << (std::ostream & os, const modular_int & x) {
			return os << x.m_value;
		}
#endif 

	};

	template<typename T, T m, typename MultiplyT>
	const T modular_int<T, m, MultiplyT>::modulus(m);

	template<typename T, T m, typename MultiplyT>
	const T modular_int<T, m, MultiplyT>::primitive_root(Detail::modular_primitive_root<m>::value);

	template<typename T, T m, typename MultiplyT>
	const T modular_int<T, m, MultiplyT>::zero(Detail::is_unsigned<T>::value ? m : static_cast<T>(0));

	template<typename T>
	const T principal_nth_root_of_unity(T n) {
		MODULAR_STATIC_ASSERT(Detail::is_modular_int<T>::value, "ModularInt::principal_nth_root_of_unity: Passed argument is not of an instantiation type of ModularInt::modular_int.");
		return pow(static_cast<T>(T::primitive_root), static_cast<T>((T::modulus - 1) / n));
	}

	template<typename T>
	const T reciprocal_of_principal_nth_root_of_unity(T n) {
		MODULAR_STATIC_ASSERT(Detail::is_modular_int<T>::value, "ModularInt::reciprocal_of_principal_nth_root_of_unity: Passed argument is not of an instantiation type of ModularInt::modular_int.");
		return pow(static_cast<T>(T::primitive_root), static_cast<T>(T::modulus - 1 - (T::modulus - 1) / n));
	}
}

#undef MODULAR_MUL2
#undef MODULAR_DIV2
#undef MODULAR_MOD2
#undef MODULAR_MUL2_ASSIGN
#undef MODULAR_DIV2_ASSIGN
#undef MODULAR_MOD2_ASSIGN

#undef MODULAR_MACRO_CONCAT_
#undef MODULAR_MACRO_CONCAT

#undef MODULAR_STATIC_ASSERT

#undef MODULAR_FAST_POW

#endif 


#include <stdio.h>

int main() {
	using namespace std;
	using namespace Polynomial;
	using namespace ModularInt;

	typedef modular_int<unsigned int, 998244353, unsigned long long> mi;
	typedef polynomial<mi> poly;

	typedef modular_int<int, 998244353, long long> ms;
	typedef polynomial<ms> polys;

	int n, m, i, c;

	


	

	


	scanf("%d%d", &n, &m);

	poly p(m + 2);
	p[m + 1] = 1;

	while (n--) {
		scanf("%d", &c);
		if (c <= m) p[c] = 1;
	}

	poly divisor(p * mi(2));
	unsigned zero_cnt = count_and_remove_trailing_zeros(divisor);

	p = div((mi(1) - sqrt(mi(1) - mi(4) * p, zero_cnt + p.size())), divisor);
	p >>= zero_cnt;

	for (i = 1; i <= m; ++i) printf("%u\n", static_cast<unsigned>(p[i]));

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <streambuf>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <locale>
#include <functional>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;




typedef long L;
typedef unsigned long UL;
typedef long long LL;
typedef unsigned long long ULL;




#define VA_NUM_ARGS_IMPL(_1,_2,_3,_4,_5,N,...) N
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_(( __VA_ARGS__, 5,4,3,2,1))
#define CONCAT(x,y) x ## y
#define PROXY(a,b) a b
#define CONCAT_(tuple) PROXY(CONCAT, tuple)
#define DEFINE_OVERLOAD(NAME, ...) CONCAT_((NAME, VA_NUM_ARGS(__VA_ARGS__)))

#define REP_IMPL_3(i,s,n) for (int i=s;i<=n;++i)
#define REP_IMPL_2(i,n) for (int i=1;i<=n;++i)

#define REP(...) DEFINE_OVERLOAD(REP_IMPL_, __VA_ARGS__) (__VA_ARGS__)

#define RER_IMPL_3(i,n,s) for (int i=n;i>=s;--i)
#define RER_IMPL_2(i,n) for (int i=n;i>=1;--i)

#define RER(...) DEFINE_OVERLOAD(RER_IMPL_, __VA_ARGS__) (__VA_ARGS__)

#define REP0_IMPL_3(i,s,n) for (int i=s;i<=n-1;++i)
#define REP0_IMPL_2(i,n) for (int i=0;i<=n-1;++i)

#define REP0(...) DEFINE_OVERLOAD(REP0_IMPL_, __VA_ARGS__) (__VA_ARGS__)

#define RER0_IMPL_3(i,n,s) for (int i=n-1;i>=s;--i)
#define RER0_IMPL_2(i,n) for (int i=n-1;i>=0;--i)

#define RER0(...) DEFINE_OVERLOAD(RER0_IMPL_, __VA_ARGS__) (__VA_ARGS__)




void read(int& x1) { scanf("%d", &x1); }
void read(int& x1, int& x2) { scanf("%d %d", &x1, &x2); }
void read(int& x1, int& x2, int& x3) { scanf("%d %d %d", &x1, &x2, &x3); }
void read(int& x1, int& x2, int& x3, int& x4) { scanf("%d %d %d %d", &x1, &x2, &x3, &x4); }
void read(int& x1, int& x2, int& x3, int& x4, int& x5) { scanf("%d %d %d %d %d", &x1, &x2, &x3, &x4, &x5); }

void read(long& x1) { scanf("%ld", &x1); }
void read(long& x1, long& x2) { scanf("%ld %ld", &x1, &x2); }
void read(long& x1, long& x2, long& x3) { scanf("%ld %ld %ld", &x1, &x2, &x3); }
void read(long& x1, long& x2, long& x3, long& x4) { scanf("%ld %ld %ld %ld", &x1, &x2, &x3, &x4); }
void read(long& x1, long& x2, long& x3, long& x4, long& x5) { scanf("%ld %ld %ld %ld %ld", &x1, &x2, &x3, &x4, &x5); }

void read(long long& x1) { scanf("%lld", &x1); }
void read(long long& x1, long long& x2) { scanf("%lld %lld", &x1, &x2); }
void read(long long& x1, long long& x2, long long& x3) { scanf("%lld %lld %lld", &x1, &x2, &x3); }
void read(long long& x1, long long& x2, long long& x3, long long& x4) { scanf("%lld %lld %lld %lld", &x1, &x2, &x3, &x4); }
void read(long long& x1, long long& x2, long long& x3, long long& x4, long long& x5) { scanf("%lld %lld %lld %lld %lld", &x1, &x2, &x3, &x4, &x5); }

void read(unsigned int& x1) { scanf("%u", &x1); }
void read(unsigned int& x1, unsigned int& x2) { scanf("%u %u", &x1, &x2); }
void read(unsigned int& x1, unsigned int& x2, unsigned int& x3) { scanf("%u %u %u", &x1, &x2, &x3); }
void read(unsigned int& x1, unsigned int& x2, unsigned int& x3, unsigned int& x4) { scanf("%u %u %u %u", &x1, &x2, &x3, &x4); }
void read(unsigned int& x1, unsigned int& x2, unsigned int& x3, unsigned int& x4, unsigned int& x5) { scanf("%u %u %u %u %u", &x1, &x2, &x3, &x4, &x5); }

void read(unsigned long& x1) { scanf("%lu", &x1); }
void read(unsigned long& x1, unsigned long& x2) { scanf("%lu %lu", &x1, &x2); }
void read(unsigned long& x1, unsigned long& x2, unsigned long& x3) { scanf("%lu %lu %lu", &x1, &x2, &x3); }
void read(unsigned long& x1, unsigned long& x2, unsigned long& x3, unsigned long& x4) { scanf("%lu %lu %lu %lu", &x1, &x2, &x3, &x4); }
void read(unsigned long& x1, unsigned long& x2, unsigned long& x3, unsigned long& x4, unsigned long& x5) { scanf("%lu %lu %lu %lu %lu", &x1, &x2, &x3, &x4, &x5); }

void read(unsigned long long& x1) { scanf("%llu", &x1); }
void read(unsigned long long& x1, unsigned long long& x2) { scanf("%llu %llu", &x1, &x2); }
void read(unsigned long long& x1, unsigned long long& x2, unsigned long long& x3) { scanf("%llu %llu %llu", &x1, &x2, &x3); }
void read(unsigned long long& x1, unsigned long long& x2, unsigned long long& x3, unsigned long long& x4) { scanf("%llu %llu %llu %llu", &x1, &x2, &x3, &x4); }
void read(unsigned long long& x1, unsigned long long& x2, unsigned long long& x3, unsigned long long& x4, unsigned long long& x5) { scanf("%llu %llu %llu %llu %llu", &x1, &x2, &x3, &x4, &x5); }

template<typename T>
void read(int n, vector<T>& a) {
	REP(i, n) read(a[i]);
}

template<typename T>
void read(int n, vector<T>& a, vector<T>& b) {
	REP(i, n) read(a[i], b[i]);
}

template<typename T>
void read(int n, vector<T>& a, vector<T>& b, vector<T>& c) {
	REP(i, n) read(a[i], b[i], c[i]);
}





void write(int& x1) { printf("%d\n", x1); }
void write(int& x1, int& x2) { printf("%d %d\n", x1, x2); }
void write(int& x1, int& x2, int& x3) { printf("%d %d %d\n", x1, x2, x3); }
void write(int& x1, int& x2, int& x3, int& x4) { printf("%d %d %d %d\n", x1, x2, x3, x4); }
void write(int& x1, int& x2, int& x3, int& x4, int& x5) { printf("%d %d %d %d %d\n", x1, x2, x3, x4, x5); }

void write(long& x1) { printf("%ld\n", x1); }
void write(long& x1, long& x2) { printf("%ld %ld\n", x1, x2); }
void write(long& x1, long& x2, long& x3) { printf("%ld %ld %ld\n", x1, x2, x3); }
void write(long& x1, long& x2, long& x3, long& x4) { printf("%ld %ld %ld %ld\n", x1, x2, x3, x4); }
void write(long& x1, long& x2, long& x3, long& x4, long& x5) { printf("%ld %ld %ld %ld %ld\n", x1, x2, x3, x4, x5); }

void write(long long& x1) { printf("%lld\n", x1); }
void write(long long& x1, long long& x2) { printf("%lld %lld\n", x1, x2); }
void write(long long& x1, long long& x2, long long& x3) { printf("%lld %lld %lld\n", x1, x2, x3); }
void write(long long& x1, long long& x2, long long& x3, long long& x4) { printf("%lld %lld %lld %lld\n", x1, x2, x3, x4); }
void write(long long& x1, long long& x2, long long& x3, long long& x4, long long& x5) { printf("%lld %lld %lld %lld %lld\n", x1, x2, x3, x4, x5); }

void write(unsigned int& x1) { printf("%u\n", x1); }
void write(unsigned int& x1, unsigned int& x2) { printf("%u %u\n", x1, x2); }
void write(unsigned int& x1, unsigned int& x2, unsigned int& x3) { printf("%u %u %u\n", x1, x2, x3); }
void write(unsigned int& x1, unsigned int& x2, unsigned int& x3, unsigned int& x4) { printf("%u %u %u %u\n", x1, x2, x3, x4); }
void write(unsigned int& x1, unsigned int& x2, unsigned int& x3, unsigned int& x4, unsigned int& x5) { printf("%u %u %u %u %u\n", x1, x2, x3, x4, x5); }

void write(unsigned long& x1) { printf("%lu\n", x1); }
void write(unsigned long& x1, unsigned long& x2) { printf("%lu %lu\n", x1, x2); }
void write(unsigned long& x1, unsigned long& x2, unsigned long& x3) { printf("%lu %lu %lu\n", x1, x2, x3); }
void write(unsigned long& x1, unsigned long& x2, unsigned long& x3, unsigned long& x4) { printf("%lu %lu %lu %lu\n", x1, x2, x3, x4); }
void write(unsigned long& x1, unsigned long& x2, unsigned long& x3, unsigned long& x4, unsigned long& x5) { printf("%lu %lu %lu %lu %lu\n", x1, x2, x3, x4, x5); }

void write(unsigned long long& x1) { printf("%llu\n", x1); }
void write(unsigned long long& x1, unsigned long long& x2) { printf("%llu %llu\n", x1, x2); }
void write(unsigned long long& x1, unsigned long long& x2, unsigned long long& x3) { printf("%llu %llu %llu\n", x1, x2, x3); }
void write(unsigned long long& x1, unsigned long long& x2, unsigned long long& x3, unsigned long long& x4) { printf("%llu %llu %llu %llu\n", x1, x2, x3, x4); }
void write(unsigned long long& x1, unsigned long long& x2, unsigned long long& x3, unsigned long long& x4, unsigned long long& x5) { printf("%llu %llu %llu %llu %llu\n", x1, x2, x3, x4, x5); }

template<typename T>
void write(int n, vector<T>& a) {
	REP(i, n) {
		write(a[i]);
		printf(" ");
	}
	printf("\n");
}

void write(const char* s) {
	printf(s);
	printf("\n");
}

void write(std::string s) {
	printf(s.c_str());
	printf("\n");
}





template<typename T>
T gcd(T a, T b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}


auto kmp = [](const string& P)->vector<int> {
	const int m = P.length();
	vector<int> p(m + 1, 0);
	p[0] = 0;
	int k = 0;
	for (int q = 1; q < m; q++) {
		while (k > 0 && P[k] != P[q])
			k = p[k - 1];
		if (P[k] == P[q])
			k = k + 1;
		p[q] = k;
	}
	return p;
};


auto find_kmp = [](const string& T, const string& P, vector<int>& kmp) {
	const int n = T.length();
	const int m = P.length();
	int q = 0;
	for (int i = 0; i < n; i++) {
		while (q > 0 && P[q] != T[i])
			q = kmp[q - 1];
		if (P[q] == T[i])
			q++;
		if (q == m)
			return i - m + 1;
	}
	return -1;
};





template<typename T>
class Matrix {
public:
	static T MOD;

	Matrix(int rows, int cols)
	{
		R = rows;
		C = cols;
		data = make_shared<vector<T>>(R * C);
	}

	inline T& operator()(int row, int col) {
		return data->at(row * C + col);
	}

	inline T operator()(int row, int col) const {
		return data->at(row * C + col);
	}

	Matrix<T> copy() const {
		Matrix<T> result(R, C);
		*result.data.get() = *data.get();
		return result;
	}

	Matrix<T> operator+(Matrix<T> const& rhs) const {
		Matrix<T> m(R, C);
		REP0(i, R * C) m.data[i] = (data[i] + rhs.data[i]) % MOD;
		return m;
	}

	Matrix<T> operator-(Matrix<T> const& rhs) const {
		Matrix<T> m(R, C);
		REP0(i, R * C) m.data[i] = (data[i] - rhs.data[i]) % MOD;
		return m;
	}

	Matrix<T> operator-() const {
		Matrix<T> m(R, C);
		REP0(i, R * C) m.data[i] = -data[i];
		return m;
	}

	template<typename TT>
	Matrix<T> operator*(TT t) const {
		Matrix<T> m(R, C);
		REP0(i, R * C) m.data[i] = (data[i] * t) % MOD;
		return m;
	}

	template<typename TT>
	Matrix<T> operator/(TT t) const {
		Matrix<T> m(R, C);
		REP0(i, R * C) m.data[i] = (data[i] / t) % MOD;
		return m;
	}

	Matrix<T> operator*(Matrix<T> const& rhs) const {
		Matrix<T> m(R,C);
		REP0(r, R) {
			REP0(d, rhs.C) {
				T sum = 0;
				REP0(c, C) sum = (sum + (((*this)(r, c) * rhs(c, d)) % MOD)) % MOD;
				m(r, d) = sum;
			}
		}
		return m;
	}

	Matrix<T>& operator=(const vector<vector<T>>& v) {
		REP0(r, R) {
			REP0(c, C) {
				(*this)(r, c) = v[r][c] % MOD;
			}
		}
		return *this;
	}

	static Matrix<T> zeros(int R, int C) {
		Matrix<T> result(R, C);
		return result;
	}

	static Matrix<T> ones(int R, int C) {
		return diagonal(R, C, 1);
	}

	static Matrix<T> diagonal(int R, int C, int value) {
		Matrix<T> result = Matrix<T>::zeros(R, C);
		REP0(r, min(R, C)) result(r, r) = value;
		return result;
	}

	Matrix<T> transpose() {
		Matrix<T, C, R> result;
		REP0(r, R) {
			REP0(c, C) {
				result(c, r) = (*this)[r][c];
			}
		}
		return result;
	}

	Matrix<T> pow(unsigned int l) const {
		if (R != C)
			throw std::exception("Only squared matrixes could be powered");
		Matrix<T> m = *this;
		Matrix<T> result = Matrix<T>::ones(R, C);
		unsigned int n = 1;
		while (l != 0) {
			unsigned int i = l & ~(l - 1);
			l -= i;
			while (n < i) {
				m = m * m;
				n <<= 1;
			}
			result = result * m;
		}
		return result;

	}

	std::string asStrig() const {
		std::stringstream stream;
		REP0(r, R) {
			REP0(c, C) {
				stream << data[r * C + c];
				if (c < C - 1)
					stream << "\t";
			}
			if (r < R - 1)
				stream << "\n";
		}

		return stream.str();
	}

private:
	Matrix() {}
	int R, C;
	shared_ptr<vector<T>> data;
};

template<typename T>
T Matrix<T>::MOD = (std::numeric_limits<T>::max)();






void task()
{
	const ULL MOD = 1e9 + 7;
	Matrix<ULL>::MOD = MOD;

	ULL N, L, M;
	read(N, L, M);

	vector<ULL> a(N + 1);
	vector<ULL> b(N + 1);
	vector<ULL> c(N + 1);
	read(N, a);
	read(N, b);
	read(N, c);

	Matrix<ULL> input(1, M);
	Matrix<ULL> city(M, M);

	REP(i, N) ++input(0, a[i] % M);
	REP(i, N) REP0(j, M) ++city(j, (b[i] + j) % M);
		
	Matrix<ULL> cityL = city.pow(L - 2);
	Matrix<ULL> result = input * cityL;

	ULL ans = 0;
	REP(i, N) {
		ULL out = (b[i] + c[i]) % M;
		ULL required = (M - out) % M; 
		ans = (result(0, required) + ans) % MOD;
	}

	write(ans);
	return;
}

int main() {
    task();
    return 0;
}
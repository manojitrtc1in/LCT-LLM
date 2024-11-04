










namespace atcoder {

namespace internal {





int id2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}





constexpr int id3(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
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

template <class S, S (*op)(S, S), S (*e)()> struct id0 {
  public:
    id0() : id0(0) {}
    explicit id0(int n) : id0(std::vector<S>(n, e())) {}
    explicit id0(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::id2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
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

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
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

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  





namespace suisen {
    namespace default_operator {
        template <typename T>
        auto zero() -> decltype(T { 0 }) { return T { 0 }; }
        template <typename T>
        auto one()  -> decltype(T { 1 }) { return T { 1 }; }
        template <typename T>
        auto add(const T &x, const T &y) -> decltype(x + y) { return x + y; }
        template <typename T>
        auto sub(const T &x, const T &y) -> decltype(x - y) { return x - y; }
        template <typename T>
        auto mul(const T &x, const T &y) -> decltype(x * y) { return x * y; }
        template <typename T>
        auto div(const T &x, const T &y) -> decltype(x / y) { return x / y; }
        template <typename T>
        auto mod(const T &x, const T &y) -> decltype(x % y) { return x % y; }
        template <typename T>
        auto neg(const T &x) -> decltype(-x) { return -x; }
        template <typename T>
        auto inv(const T &x) -> decltype(one<T>() / x)  { return one<T>() / x; }
    } 

    namespace default_operator_noref {
        template <typename T>
        auto zero() -> decltype(T { 0 }) { return T { 0 }; }
        template <typename T>
        auto one()  -> decltype(T { 1 }) { return T { 1 }; }
        template <typename T>
        auto add(T x, T y) -> decltype(x + y) { return x + y; }
        template <typename T>
        auto sub(T x, T y) -> decltype(x - y) { return x - y; }
        template <typename T>
        auto mul(T x, T y) -> decltype(x * y) { return x * y; }
        template <typename T>
        auto div(T x, T y) -> decltype(x / y) { return x / y; }
        template <typename T>
        auto mod(T x, T y) -> decltype(x % y) { return x % y; }
        template <typename T>
        auto neg(T x) -> decltype(-x) { return -x; }
        template <typename T>
        auto inv(T x) -> decltype(one<T>() / x)  { return one<T>() / x; }
    } 

} 


namespace suisen {
    template <
        typename T,
        size_t N,
        size_t M,
        T(*_add)(T, T) = default_operator_noref::add<T>,
        T(*_neg)(T) = default_operator_noref::neg<T>,
        T(*_zero)() = default_operator_noref::zero<T>,
        T(*_mul)(T, T) = default_operator_noref::mul<T>,
        T(*_inv)(T) = default_operator_noref::inv<T>,
        T(*_one)()  = default_operator_noref::one<T>
    >
    struct ArrayMatrix : public std::array<std::array<T, M>, N> {
    
        using base_type = std::array<std::array<T, M>, N>;
        using container_type = base_type;
        using row_type = std::array<T, M>;

        using base_type::base_type;
        constexpr ArrayMatrix() : ArrayMatrix(_zero()) {}
        constexpr ArrayMatrix(T fill_value) { for (auto& row : *this) for (auto &e : row) e = fill_value; }
        template <typename Container>
        constexpr ArrayMatrix(const Container &c) {
            for (size_t i = 0; i < N; ++i) for (size_t j = 0; j < M; ++j) (*this)[i][j] = c[i][j];
        }

        constexpr std::pair<int, int> shape() const {
            return { N, M };
        }
        constexpr int row_size() const {
            return N;
        }
        constexpr int col_size() const {
            return M;
        }

        constexpr MatrixType(N, M) operator+() {
            return *this;
        }
        constexpr MatrixType(N, M) operator-() {
            ArrayMatrix res;
            for (size_t i = 0; i < N; ++i) for (size_t j = 0; j < M; ++j) res[i][j] = _add(res[i][j], _neg((*this)[i][j]));
            return res;
        }
        constexpr MatrixType(N, M)& operator+=(const MatrixType(N, M)& other) {
            for (size_t i = 0; i < N; ++i) for (size_t j = 0; j < M; ++j) (*this)[i][j] = _add((*this)[i][j], other[i][j]);
            return *this;
        }
        constexpr MatrixType(N, M)& operator-=(const MatrixType(N, M)& other) {
            for (size_t i = 0; i < N; ++i) for (size_t j = 0; j < M; ++j) (*this)[i][j] = _add((*this)[i][j], _neg(other[i][j]));
            return *this;
        }
        template <size_t K>
        constexpr MatrixType(N, M)& operator*=(const MatrixType(M, K)& other) {
            return *this = *this * other;
        }
        constexpr MatrixType(N, M)& operator*=(const T& val) {
            for (size_t i = 0; i < N; ++i) for (size_t j = 0; j < M; ++j) (*this)[i][j] = _mul((*this)[i][j], val);
            return *this;
        }
        constexpr MatrixType(N, M)& operator/=(const T& val) {
            return *this *= _inv(val);
        }
        constexpr MatrixType(N, M) operator+(const MatrixType(N, M)& other) const {
            return MatrixType(N, M)(*this) += other;
        }
        constexpr MatrixType(N, M) operator-(const MatrixType(N, M)& other) const {
            return MatrixType(N, M)(*this) -= other;
        }
        template <size_t K>
        constexpr MatrixType(N, K) operator*(const MatrixType(M, K)& other) const {
            MatrixType(N, K) res;
            for (size_t i = 0; i < N; ++i) for (size_t j = 0; j < M; ++j) for (size_t k = 0; k < K; ++k) {
                res[i][k] = _add(res[i][k], _mul((*this)[i][j], other[j][k]));
            }
            return res;
        }
        constexpr MatrixType(N, M) operator*(const T& val) const {
            return MatrixType(N, M)(*this) *= val;
        }
        constexpr MatrixType(N, M) operator/(const T& val) const {
            return MatrixType(N, M)(*this) /= val;
        }

        constexpr std::array<T, N> operator*(const std::array<T, M>& x) const {
            std::array<T, N> b;
            b.fill(_zero());
            for (size_t i = 0; i < N; ++i) for (size_t j = 0; j < M; ++j) b[i] = _add(b[i], _mul((*this)[i][j], x[j]));
            return b;
        }
    
    };

    template <
        typename T,
        size_t N,
        T(*_add)(T, T) = default_operator_noref::add<T>,
        T(*_neg)(T) = default_operator_noref::neg<T>,
        T(*_zero)() = default_operator_noref::zero<T>,
        T(*_mul)(T, T) = default_operator_noref::mul<T>,
        T(*_inv)(T) = default_operator_noref::inv<T>,
        T(*_one)()  = default_operator_noref::one<T>
    >
    class id1 : public ArrayMatrix<T, N, N, _add, _neg, _zero, _mul, _inv, _one> {
    private:
        enum Operator { Add, Mul };
    public:
        using base_type = ArrayMatrix<T, N, N, _add, _neg, _zero, _mul, _inv, _one>;
        using container_type = typename base_type::container_type;
        using row_type = typename base_type::row_type;

        using base_type::base_type;

        static id1 e0() { return id1(Operator::Add); }
        static id1 e1() { return id1(Operator::Mul); }

        static constexpr std::optional<id1> inv(const id1& A) {
            std::array<std::array<T, 2 * N>, N> data;
            for (size_t i = 0; i < N; ++i) {
                for (size_t j = 0; j < N; ++j) {
                    data[i][j] = A[i][j];
                    data[i][N + j] = i == j ? _one() : _zero();
                }
            }
            for (size_t i = 0; i < N; ++i) {
                int pivot = -1;
                for (size_t k = i; k < N; ++k) if (data[k][i] != _zero()) {
                    pivot = k;
                    break;
                }
                if (pivot < 0) return std::nullopt;
                data[i].swap(data[pivot]);
                T coef = _inv(data[i][i]);
                for (size_t j = i; j < 2 * N; ++j) data[i][j] = _mul(data[i][j], coef);
                for (size_t k = 0; k < N; ++k) if (k != i and data[k][i] != _zero()) {
                    T c = data[k][i];
                    for (size_t j = i; j < 2 * N; ++j) data[k][j] = _add(data[k][j], _neg(_mul(c, data[i][j])));
                }
            }
            id1 res;
            for (size_t i = 0; i < N; ++i) std::copy(data[i].begin(), data[i].begin() + N, res[i].begin());
            return res;
        }
        static constexpr T det(id1&& A) {
            T det_inv = _one();
            for (size_t i = 0; i < N; ++i) {
                int pivot = -1;
                for (size_t k = i; k < N; ++k) if (A[k][i] != _zero()) {
                    pivot = k;
                    break;
                }
                if (pivot < 0) return _zero();
                A[i].swap(A[pivot]);
                if (pivot != i) det_inv = _mul(det_inv, _neg(_one()));
                T coef = _inv(A[i][i]);
                for (size_t j = i; j < N; ++j) A[i][j] = _mul(A[i][j], coef);
                det_inv = _mul(det_inv, coef);
                for (size_t k = i + 1; k < N; ++k) if (A[k][i] != _zero()) {
                    T c = A[k][i];
                    for (size_t j = i; j < N; ++j) A[k][j] = _add(A[k][j], _neg(_mul(c, A[i][j])));
                }
            }
            return _inv(det_inv);
        }
        static constexpr T det(const id1& A) {
            return det(id1(A));
        }
        constexpr id1 inv() const {
            return *inv(*this);
        }
        constexpr T det() const {
            return det(*this);
        }

        constexpr id1& operator/=(const id1& other) { return *this *= other.inv(); }
        constexpr id1  operator/ (const id1& other) const { return id1(*this) *= other.inv(); }

        constexpr id1 pow(long long b) const {
            assert(b >= 0);
            id1 res(e1()), p(*this);
            for (; b; b >>= 1) {
                if (b & 1) res *= p;
                p *= p;
            }
            return res;
        }
    private:
        id1(Operator op) : base_type() {
            if (op == Operator::Mul) for (size_t i = 0; i < N; ++i) (*this)[i][i] = _one();
        }
    };
} 


using suisen::id1;

constexpr int I = std::numeric_limits<int>::max() / 2;

constexpr int add(int x, int y) {
    return std::min(x, y);
}
int neg(int) {
    assert(false);
}
constexpr int zero() {
    return I;
}
constexpr int mul(int x, int y) {
    return x + y;
}
constexpr int inv(int x) {
    return -x;
}
constexpr int one() {
    return 0;
}

using Matrix = id1<int, 3, add, neg, zero, mul, inv, one>;

constexpr std::array<Matrix, 3> T {
    Matrix::container_type {
        1, I, I,
        0, 0, I,
        0, 0, 0,
    },
    Matrix::container_type {
        0, I, I,
        0, 1, I,
        0, 0, 0,
    },
    Matrix::container_type {
        0, I, I,
        0, 0, I,
        0, 0, 1,
    }
};
 
constexpr Matrix op(Matrix L, Matrix R) {
    auto res = R * L;
    return *static_cast<Matrix*>(&res);
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::string s;
    std::cin >> n >> q >> s;
    
    std::vector<Matrix> init(n);
    for (int i = 0; i < n; ++i) {
        init[i] = T[s[i] - 'a'];
    }
    atcoder::id0<Matrix, op, Matrix::e1> seg(init);
 
    while (q --> 0) {
        int i;
        char c;
        std::cin >> i >> c;
        seg.set(i - 1, T[c - 'a']);
        std::cout << seg.all_prod()[2][0] << '\n';
    }
    return 0;
}


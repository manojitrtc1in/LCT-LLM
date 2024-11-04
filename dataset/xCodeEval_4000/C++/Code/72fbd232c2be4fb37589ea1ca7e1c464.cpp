#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using natural = std::int64_t;

template<typename K,int n,int m>
class matrix;
template<typename K, int n>
class square_matrix;


template<typename K>
class polynomial;

template<typename K>
std::pair<polynomial<K>, polynomial<K>> bezout(const polynomial<K>& a, const polynomial<K>& b);

template<typename A>
A pow(const A& u, long long n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return u;
    A r = pow(u, n / 2);
    r *= r;
    return r * pow(u, n % 2);
}


template<typename R>
class free_algebra
{
public:
    free_algebra() {}
    free_algebra(R m) :a(1, m) { reduce(); }
    free_algebra(std::vector<R>&& c) :a(std::move(c)) { reduce(); }
    free_algebra(const std::vector<R>& c) :a(c) { reduce(); }
    free_algebra(const free_algebra<R>& p) :a(p.a) { reduce(); }
    free_algebra(int c) :a(1, R(c)) { reduce(); }
    using base_ring = R;


    bool operator<(const free_algebra& q) const
    {
        return degree() < q.degree();
    }

    int degree() const
    {
        return a.size() - 1;
    }

    free_algebra operator-() const
    {
        free_algebra p(*this);
        for (auto& s : p.a)
            s = -s;
        return p;
    }

    template<typename H>
    H operator()(const H& u) const
    {
        H r = 0, w = 1;
        for (const auto& s : a)
        {
            r += w * s;
            w *= u;
        }
        return r;
    }

    R operator()(const R& u) const
    {
        return this->operator()<R>(u);
    }

    const free_algebra& operator+() const
    {
        return *this;
    }

    free_algebra& operator+=(const free_algebra& p)
    {
        for (int i = 0; i <= degree(); i++)
            if (i > p.degree())
                break;
            else a[i] += p.a[i];
        for (int i = degree() + 1; i <= p.degree(); i++)
            a.push_back(p.a[i]);
        reduce();
        return *this;
    }
    free_algebra& operator+=(const R& p)
    {
        return *this += free_algebra(p);
    }
    free_algebra& operator-=(const R& p)
    {
        return *this += free_algebra(p);
    }

    free_algebra& operator*=(const R& p)
    {
        std::for_each(a.begin(), a.end(), [&p](auto& v) {v *= p; });
        reduce();
        return *this;
    }
    free_algebra& operator-=(const free_algebra& p)
    {
        for (int i = 0; i <= degree(); i++)
            if (i > p.degree())
                break;
            else a[i] -= p.a[i];
        for (int i = degree() + 1; i <= p.degree(); i++)
            a.push_back(p.a[i]);
        reduce();
        return *this;
    }
    free_algebra& operator*=(const free_algebra& p)
    {
        return *this = (*this)*p;
    }
    const R& coeff(int n) const
    {
        return a.at(n);
    }

    R& coeff(int n)
    {
        return a.at(n);
    }

    bool is_zero() const
    {
        

        return a.empty();
    }
    bool is_one() const
    {
        return !a.empty() && a.at(0).is_one();
    }

    std::vector<R>& get_vect()
    {
        return a;
    }

    const std::vector<R>& get_vect() const
    {
        return a;
    }
    void reduce() {
        while (!a.empty() && (a.back()==0))
            a.pop_back();
    }

public:
    std::vector<R> a;


};

template<typename R>
free_algebra<R> operator+(const free_algebra<R>& a, const free_algebra<R>& b)
{
    free_algebra<R> p(a);
    return p += b;
}


template<typename R>
free_algebra<R> operator-(const free_algebra<R>& a, const free_algebra<R>& b)
{
    free_algebra<R> p(a);
    return p -= b;
}

template<typename R>
free_algebra<R> operator*(const free_algebra<R>& p, const free_algebra<R>& q)
{
    if (p.degree() < 0 || q.degree() < 0)
        return 0;
    int m = p.degree() + q.degree();
    free_algebra<R> h;
    h.get_vect().resize(m + 1);
    for (int i = 0; i <= p.degree(); i++)
        for (int j = 0; j <= q.degree(); j++)
            h.coeff(i + j) += p.coeff(i) * q.coeff(j);
    h.reduce();
    return h;
}

template<typename R>
free_algebra<R> operator+(const free_algebra<R>& a, const R& b)
{
    free_algebra<R> p(a);
    return p += b;
}


template<typename R>
free_algebra<R> operator-(const free_algebra<R>& a, const R& b)
{
    free_algebra<R> p(a);
    return p -= b;
}

template<typename R>
free_algebra<R> operator*(const free_algebra<R>& a, const R& b)
{
    free_algebra<R> p(a);
    return p *= b;
}

template<typename R>
free_algebra<R> operator+(const R& b, const free_algebra<R>& a)
{
    free_algebra<R> p(a);
    return p += b;
}


template<typename R>
free_algebra<R> operator-(const R& b, const free_algebra<R>& a)
{
    free_algebra<R> p(a);
    return p -= b;
}

template<typename R>
free_algebra<R> operator*(const R& b, const free_algebra<R>& a)
{
    free_algebra<R> p(a);
    return p *= b;
}

template<typename R>
std::ostream& operator<<(std::ostream& H, const free_algebra<R>& p)
{
    H << "(";
    for (int i = 0; i <= p.degree(); i++)
        if (i < p.degree())
            H << p.coeff(i) << ", ";
        else H << p.coeff(i) << ")";
    return H;
}

template<typename K>
class polynomial:public free_algebra<K>
{
public:
    using free_algebra<K>::a;
    polynomial() {};
    polynomial(const free_algebra<K>& p) :free_algebra<K>(p) {}
    polynomial(free_algebra<K>&& p) :free_algebra<K>(std::move(p)) {}
    polynomial(const std::vector<K>& p) :free_algebra<K>(p) {}
    polynomial(std::vector<K>&& p) :free_algebra<K>(std::move(p)) {}
    polynomial(const K& p) :free_algebra<K>(p) {}
    polynomial(int c) :free_algebra<K>(c) {}
    using base_field = K;
    bool operator!=(const polynomial& p) const
    {
        if (p.degree() != this->degree())
            return true;
        for (int i = 0; i <= p.degree(); i++)
            if (p.a.at(i) != this->a.at(i))
                return true;
        return false;
    }
    bool operator==(const polynomial& p) const
    {
        return !(*this != p);
    }
    static polynomial _0()
    {
        return free_algebra<K>::_0();
    }
    static polynomial _1()
    {
        return free_algebra<K>::_1();
    }

    static std::pair<polynomial, polynomial> euclidean_division(const polynomial& p, const polynomial& q)
    {
        if (p.degree() < q.degree())
            return std::make_pair(0, p);
        polynomial r(p);
        int m(r.degree()), n(q.degree());
        polynomial s;
        s.a.resize(m - n + 1);
        for (; m >= n; m--)
        {
            K k(r.a.at(m) / q.a.at(n));
            s.a.at(m - n) = k;
            if (k==0)
            {
                r.a.pop_back();
                continue;
            }
            for (int i = 1; i <= n; i++)
                r.a.at(m - i) -= k * q.a.at(n - i);
            r.a.pop_back();
        }
        r.reduce();

        return std::make_pair(s, r);
    }
    static polynomial gcd(const polynomial& p, const polynomial& q)
    {
        if (p.degree() < q.degree())
            return gcd(q, p);
        std::pair<polynomial, polynomial> R(euclidean_division(p, q));
        if (R.second.a.empty())
            return q.normalize();
        else return gcd(q, R.second);
    }
    polynomial div(const polynomial& q) const
    {
        return euclidean_division(*this, q).first;
    }
    polynomial mod(const polynomial& q) const
    {
        return euclidean_division(*this, q).second;
    }

    polynomial operator-() const
    {
        return free_algebra<K>::operator-();
    }


    polynomial& operator+=(const polynomial& p)
    {
        this->free_algebra<K>::operator+=(p);
        return *this;
    }
    polynomial& operator-=(const polynomial& p)
    {
        this->free_algebra<K>::operator-=(p);
        return *this;
    }
    polynomial& operator*=(const polynomial& p)
    {
        this->free_algebra<K>::operator*=(p);
        return *this;
    }
    polynomial& operator+=(const K& p)
    {
        this->free_algebra<K>::operator+=(p);
        return *this;
    }
    polynomial& operator-=(const K& p)
    {
        this->free_algebra<K>::operator-=(p);
        return *this;
    }
    polynomial& operator*=(const K& p)
    {
        this->free_algebra<K>::operator*=(p);
        return *this;
    }
    polynomial& operator/=(const K& p)
    {
        std::for_each(a.begin(), a.end(), [&p](auto& v) {v /= p; });
        this->reduce();
        return *this;
    }
    polynomial normalize() const
    {
        polynomial p(*this);
        auto dominant_coeff = p.a.at(p.degree());
        p /= dominant_coeff;
        return p;
    }
    polynomial derivative() const
    {
        polynomial p;
        int n = this->degree();
        p.a.resize(n);
        for (int i = 1; i <= n; i++)
            p.a[i - 1] = this->a[i]*K(i);
        return p;
    }

};

template<typename K>
polynomial<K> operator+(const polynomial<K>& a, const polynomial<K>& b)
{
    polynomial<K> p(a);
    return p += b;
}


template<typename K>
polynomial<K> operator-(const polynomial<K>& a, const polynomial<K>& b)
{
    polynomial<K> p(a);
    return p -= b;
}

template<typename K>
polynomial<K> operator*(const polynomial<K>& a, const polynomial<K>& b)
{
    polynomial<K> p(a);
    return p *= b;
}

template<typename K>
polynomial<K> operator+(const polynomial<K>& a, const K& b)
{
    polynomial<K> p(a);
    return p += b;
}

template<typename K>
polynomial<K> operator/(const polynomial<K>& a, const K& b)
{
    polynomial<K> p(a);
    return p /= b;
}


template<typename K>
polynomial<K> operator-(const polynomial<K>& a, const K& b)
{
    polynomial<K> p(a);
    return p -= b;
}

template<typename K>
polynomial<K> operator*(const polynomial<K>& a, const K& b)
{
    polynomial<K> p(a);
    return p *= b;
}

template<typename K>
polynomial<K> operator+(const K& b, const polynomial<K>& a)
{
    polynomial<K> p(a);
    return p += b;
}


template<typename K>
polynomial<K> operator-(const K& b, const polynomial<K>& a)
{
    polynomial<K> p(a);
    return p -= b;
}

template<typename K>
polynomial<K> operator*(const K& b, const polynomial<K>& a)
{
    polynomial<K> p(a);
    return p *= b;
}
template<typename R,bool is_field,long long ...k>
class ring_extension
{
public:
    ring_extension(const std::vector<R>& a) :p(a) { reduce(); }
    ring_extension(const polynomial<R>& a) :p(a) { reduce(); }
    ring_extension(int s = 0) :p(s) { reduce(); }
    const static inline polynomial<R> extension_polynomial
            = polynomial<R>(std::vector<R>{ k... });
    ring_extension(const R& a) :p(a) { reduce(); }
    ring_extension& operator+=(const ring_extension &w)
    {
        p += w.p;
        return *this;
    }

    ring_extension& operator-=(const ring_extension& w)
    {
        p -= w.p;
        return *this;
    }
    ring_extension& operator*=(const ring_extension& w)
    {
        p *= w.p;
        reduce();
        return *this;
    }
    ring_extension& operator/=(const ring_extension& w)
    {
        auto s = w.inv();
        return *this *= s;
    }

    ring_extension inv() const
    {
        return bezout<polynomial<R>>(p, extension_polynomial).first;
    }

    const polynomial<R>& get_polynomial() const { return p; }
    inline static constexpr long long extension_degree = sizeof ...(k) - 1;

private:
    void reduce()
    {
        if (p.degree() >= extension_polynomial.degree())
            p = p.mod(extension_polynomial);
    }
    polynomial<R> p;
};
#include <cassert>
template<typename R>
class ring_extension<R,false,-1,-1,0,0,0,0,0,0,0,0,1>
{
public:
    ring_extension(const std::vector<R>& a) :p(a) { reduce(); }
    ring_extension(const polynomial<R>& a) :p(a) { reduce(); }
    ring_extension(int s = 0) :p(s) { reduce(); }
    const static inline polynomial<R> extension_polynomial
        = polynomial<R>(std::vector<R>{-1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 1 });
    ring_extension(const R& a) :p(a) { reduce(); }
    ring_extension& operator+=(const ring_extension& w)
    {
        p += w.p;
        return *this;
    }

    ring_extension& operator-=(const ring_extension& w)
    {
        p -= w.p;
        return *this;
    }
    ring_extension& operator*=(const ring_extension& w)
    {
        p *= w.p;
        reduce();
        return *this;
    }
    ring_extension& operator/=(const ring_extension& w)
    {
        auto s = w.inv();
        return *this *= s;
    }

    ring_extension inv() const
    {
        return bezout<polynomial<R>>(p, extension_polynomial).first;
    }

    const polynomial<R>& get_polynomial() const { return p; }
    inline static constexpr long long extension_degree = 10;

private:
    void reduce()
    {
        auto m = p.degree();
        while (p.degree() >= extension_degree)
        {
            p.a[m - extension_degree] += p.a[m];
            p.a[m - extension_degree+1] += p.a[m];
            p.a.pop_back();
            m--;
        }
        while (!p.a.empty() && p.a.back() == 0)
            p.a.pop_back();
    }
    polynomial<R> p;
};

template<typename R, bool is_field,long long ...k>
ring_extension<R,is_field,k...> operator+(const ring_extension<R,is_field,k...>& p,
                                          const ring_extension<R,is_field,k...>& q)
{
    ring_extension<R,is_field,k...>h = p;
    return h += q;
}

template<typename R, bool is_field,long long ...k>
ring_extension<R,is_field,k...> operator-(const ring_extension<R, is_field,k...>& p,
                                          const ring_extension<R, is_field,k...>& q)
{
    ring_extension<R,is_field,k...>h = p;
    return h -= q;
}

template<typename R, bool is_field,long long ...k>
ring_extension< R,is_field, k... > operator*(const ring_extension<R,is_field,k...>& p,
                                             const ring_extension<R,is_field,k...>& q)
{
    ring_extension<R,is_field,k...>h = p;
    return h *= q;
}

template<typename R, bool is_field,long long ...k>
ring_extension<R,is_field,k...> operator/(const ring_extension<R, is_field,k...>& p,
                                          const ring_extension<R,is_field,k...>& q)
{
    ring_extension<R,is_field,k...>h = p;
    return h /= q;
}

template <typename R>
class rational_extension
{
public:

    rational_extension(const R &_p,const  R& _q=1)
            :p(_p), q(_q) { reduce(); }

    rational_extension(int _p=0, int _q=1) :p(_p), q(_q) {}

    bool operator!=(const rational_extension& s) const
    {
        return (s.p != p) || (s.q != q);
    }
    bool operator==(const rational_extension& s) const
    {
        return !(*this != s);
    }

    rational_extension inv() const
    {
        return rational_extension(q, p);
    }

    const R& nominator() const
    {
        return p;
    }

    const R& denominator() const
    {
        return q;
    }
    bool is_zero() const
    {
        return p.is_zero();
    }

    bool is_one() const
    {
        return p == q;
    }
    explicit operator R()
    {
        return p.div(q);
    }
    rational_extension& operator+=(const rational_extension& a)
    {
        p = p * a.q + a.p * q;
        q *= a.q;
        reduce();
        return *this;
    }
    rational_extension& operator-=(const rational_extension& a)
    {
        p = p * a.q - a.p * q;
        q *= a.q;
        reduce();
        return *this;
    }

    rational_extension operator-() const
    {
        return rational_extension(-p, q);
    }

    rational_extension& operator*=(const rational_extension& a)
    {
        p *= a.p;
        q *= a.q;
        reduce();
        return *this;
    }
    rational_extension& operator/=(const rational_extension& a)
    {
        p *= a.q;
        q *= a.p;
        reduce();
        return *this;
    }
    rational_extension& operator+=(const R& a)
    {
        return this->operator+=(rational_extension(a));
    }
    rational_extension& operator-=(const R& a)
    {
        return this->operator-=(rational_extension(a));
    }

    rational_extension& operator*=(const R& a)
    {
        p *= a;
        reduce();
        return *this;
    }
    rational_extension& operator/=(const R& a)
    {
        q *= a;
        reduce();
        return *this;
    }

    rational_extension& operator+=(int a)
    {
        return this->operator+=(R(a));
    }
    rational_extension& operator-=(int a)
    {
        return this->operator-=(R(a));
    }

    rational_extension& operator*=(int a)
    {
        p *= a;
        reduce();
        return *this;
    }
    rational_extension& operator/=(int a)
    {
        q *= a;
        reduce();
        return *this;
    }

private:
    void reduce()
    {
        if (p.is_zero())
        {
            q = 1;
            return;
        }
        R d(R::gcd(p, q));
        p = p.div(d);
        q = q.div(d);
    }
    R p, q;
};

template<typename R>
rational_extension<R> operator+(const rational_extension<R>& a, const rational_extension<R>& b)
{
    rational_extension c(a);
    return c += b;
}

template<typename R>
rational_extension<R> operator-(const rational_extension<R>& a, const rational_extension<R>& b)
{
    rational_extension c(a);
    return c -= b;
}

template<typename R>
rational_extension<R> operator*(const rational_extension<R>& a, const rational_extension<R>& b)
{
    rational_extension c(a);
    return c *= b;
}

template<typename R>
rational_extension<R> operator/(const rational_extension<R>& a, const rational_extension<R>& b)
{
    rational_extension c(a);
    return c /= b;
}

template<typename R>
std::ostream& operator<<(std::ostream& H, const rational_extension<R> a)
{
    return H << "[" << a.nominator() << "|" << a.denominator() << "]";
}

using rational = rational_extension<natural>;

template <typename K>
using rational_function = rational_extension<polynomial<K>>;

template<typename K>
std::pair<polynomial<K>, polynomial<K>> bezout(const polynomial<K>& a, const polynomial<K>& b)
{
    std::pair<polynomial<K>, polynomial<K>> P;
    if (a < b)
    {
        P = bezout(b, a);
        return { P.second,P.first };
    }
    polynomial<K> r0 = a, r1 = b, t0 = 0, t1 = 1, s0 = 1, s1 = 0, w1, w2, w3, q;
    while (!r1.is_zero())
    {
        w1 = r0;
        w2 = t0;
        w3 = s0;
        r0 = r1;
        s0 = s1;
        t0 = t1;
        q = w1.div(r1);
        r1 = w1 - q * r1;
        t1 = w2 - q * t1;
        s1 = w3 - q * s1;
    }
    int n = r0.degree();
    return { s0/r0.coeff(n),t0/r0.coeff(n) };
}

template<typename K>
polynomial<K> gcd(const polynomial<K>& a, const polynomial<K>& b)
{
    std::pair<polynomial<K>, polynomial<K>> P;
    if (a < b)
    {
        P = bezout(b, a);
        return { P.second,P.first };
    }
    polynomial<K> r0 = a, r1 = b, w1, q;
    while (!r1.is_zero())
    {
        w1 = r0;
        r0 = r1;
        q = w1.div(r1);
        r1 = w1 - q * r1;
    }
    return r0.normalize();
}


template<long long n,bool is_prime=false>
class cyclic
{
public:
    cyclic(long long k=0):w((k+n)%n){}
    cyclic& operator+=(const cyclic& b)
    {
        w += b.w;
        w%=n;
        return *this;
    }
    cyclic& operator-=(const cyclic& a)
    {
        w += (n - a.w);
        w %= n;
        return *this;
    }
    cyclic& operator*=(const cyclic& a)
    {
        w *= a.w;
        w %= n;
        return *this;
    }


    cyclic& operator+=(int b)
    {
        return *this+=cyclic(b);
    }
    cyclic& operator-=(int a)
    {
        return *this-=cyclic(a);
    }
    cyclic& operator*=(int a)
    {
        return *this*=cyclic(a);
    }
    cyclic operator-() const
    {
        return cyclic(n - w);
    }
    operator long long()const { return w; }

    cyclic inv()const
    {
        return pow(w, n - 2);
    }

    cyclic operator/=(const cyclic& a)
    {
        return *this *= a.inv();
    }
    cyclic& operator++()
    {
        return this->operator+=(1);
    }


    cyclic& operator--()
    {
        return this->operator-=(1);
    }
private:
    std::int64_t w;
};
template<long long n,bool is_prime>
cyclic<n, is_prime> operator+(const cyclic<n, is_prime>& a, const cyclic<n, is_prime>& b)
{
    auto c(a);
    return c += b;
}
template<long long n,bool is_prime >
cyclic<n,is_prime> operator-(const cyclic<n, is_prime>& a, const cyclic<n, is_prime>& b)
{
    auto c(a);
    return c -= b;
}
template<long long n,bool is_prime>
cyclic<n, is_prime> operator*(const cyclic<n, is_prime>& a, const cyclic<n, is_prime>& b)
{
    auto c(a);
    return c *= b;
}

template<long long n, bool is_prime>
cyclic<n, is_prime> operator/(const cyclic<n, is_prime>& a, const cyclic<n, is_prime>& b)
{
    auto c(a);
    return c /= b;
}

template<typename K, int n>
class finite_dimensional_vector_space
{
public:
    template<typename H>
    finite_dimensional_vector_space(const std::vector<H>& a) :u(n)
    {
        if (n != a.size())
            throw std::domain_error("Dimensions are not compatible");
        std::copy(a.begin(), a.end(), u.begin());
    }
    finite_dimensional_vector_space(std::vector<K>&& a) :u(std::move(a))
    {
        if (n != u.size())
            throw std::domain_error("Dimensions are not compatible");
    }

    finite_dimensional_vector_space(const finite_dimensional_vector_space& a) :u(a.u)
    {
    }

    finite_dimensional_vector_space() :u(n) {}
    inline constexpr static int dimension = n;
    using base_field = K;
    

    


    finite_dimensional_vector_space& operator+=(const finite_dimensional_vector_space& o)
    {
        for (int i = 0; i < n; i++)
            u.at(i) += o.u.at(i);
        return *this;
    }

    finite_dimensional_vector_space& operator-=(const finite_dimensional_vector_space& o)
    {
        for (int i = 0; i < n; i++)
            u.at(i) -= o.u.at(i);
        return *this;
    }
    finite_dimensional_vector_space& operator*=(const K& k)
    {
        for (int i = 0; i < n; i++)
            u.at(i) *= k;
        return *this;
    }

    finite_dimensional_vector_space& operator/=(const K& k)
    {
        for (int i = 0; i < n; i++)
            u.at(i) /= k;
        return *this;
    }

    finite_dimensional_vector_space& operator*=(int k)
    {
        for (int i = 0; i < n; i++)
            u.at(i) *= k;
        return *this;
    }
    

    finite_dimensional_vector_space operator-() const
    {
        finite_dimensional_vector_space p;
        std::transform(u.begin(), u.end(), p.u.begin(), [](auto a) {return -a; });
        return p;
    }


    matrix<K, 1, n> transpose() const
    {
        return matrix<K, 1, n>({ this->u });
    }

    matrix<K, 1, n> conj_transpose() const
    {
        auto v = this->u;
        for (auto& s : v)
            s = s.conj();
        return matrix<K, 1, n>({ v });
    }

    matrix<K, n, 1> as_matrix() const
    {
        matrix<K, n, 1> A;
        for (int i = 0; i < n; i++)
            A[i][0] = u[i];
        return A;
    }
    template<int m>
    matrix<K, n, m> outer_product(const finite_dimensional_vector_space<K, m>&s) const
    {
        return as_matrix() *s.conj_transpose();
    }

    template<int m>
    finite_dimensional_vector_space<K, n*m> kroenecker_product(const finite_dimensional_vector_space<K, m>& s) const
    {
        return (as_matrix() * s.transpose()).as_vector();
    }

    explicit operator matrix<K, n, 1>() const
    {
        return as_matrix();
    }

    operator K() const
    {
        return u[0];
    }

    const K& operator[](int i) const
    {
        return u[i];
    }
    K& operator[](int i)
    {
        return u[i];
    }

    const K& at(int i) const
    {
        return u.at(i);
    }
    K& at(int i)
    {
        return u.at(i);
    }

    std::vector<K>& get_vect()
    {
        return u;
    }

    const std::vector<K>& get_vect() const
    {
        return u;
    }

    K sum() const
    {
        K R;
        for(int i=0;i<n;i++)
            R+=u[i];
        return R;
    }

protected:
    std::vector<K> u;

};
template <typename K, int n>
using coordinate_space = finite_dimensional_vector_space<K, n>;

template <typename K, int n>
finite_dimensional_vector_space<K, n> operator+(
        const finite_dimensional_vector_space<K, n>& a, const finite_dimensional_vector_space<K, n>& b)
{
    auto c(a);
    return c += b;
}

template <typename K, int n>
finite_dimensional_vector_space<K, n> operator-(
        const finite_dimensional_vector_space<K, n>& a, const finite_dimensional_vector_space<K, n>& b)
{
    auto c(a);
    return c -= b;
}

template <typename K, int n>
finite_dimensional_vector_space<K, n> operator*(
        const K& k, const finite_dimensional_vector_space<K, n>& a)
{
    auto c(a);
    return c *= k;
}

template <typename K, int n>
finite_dimensional_vector_space<K, n> operator/(
        const finite_dimensional_vector_space<K, n>& a, const K& k)
{
    auto c(a);
    return c /= k;
}

template <typename K, int n>
finite_dimensional_vector_space<K, n> operator*(int k, const finite_dimensional_vector_space<K, n>& a)
{
    auto c(a);
    return c *= k;
}

template <typename K, int n>
finite_dimensional_vector_space<K, n> operator/(int k, const finite_dimensional_vector_space<K, n>& a)
{
    auto c(a);
    return c /= k;
}

template <typename K, int n>
std::ostream& operator<<(std::ostream& H, const finite_dimensional_vector_space<K, n>& p)
{
    H << "( ";
    for (int i = 0; i < n; i++)
        if (i == n - 1) H << p.at(i) << " )";
        else H << p.at(i) << ", ";
    return H;
}


template<typename K, int n, int m = n>
class matrix
{

public:
    matrix() :u(n)
    {
        for (auto& v : u)
            v.resize(m);
    }
    matrix(const std::vector<std::vector<K>>& M) :
            u(M)
    {
        for (const auto& v : u)
            if (v.size() != m)
                throw std::domain_error("Dimensions are not compatible");
    }
    matrix(std::vector<std::vector<K>>&& M) :
            u(std::move(M))
    {
        for (const auto& v : u)
            if (v.size() != m)
                throw std::domain_error("Dimensions are not compatible");
    }

    template<typename H>
    matrix(const matrix<H, n, m>& M) :
            u(n, std::vector<K>(m))
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                u[i][j] = H(M[i][j]);
    }

    matrix(const K& k) : matrix<K, n, m>()
    {
        for (int i = 0; i < n; i++)
            this->u[i][i] = k;
    }

    matrix(int k)  : matrix<K, n, m>()
    {
        for (int i = 0; i < n; i++)
            this->u[i][i] = k;

    }

    constexpr static int dimension = n * m;
    constexpr static int domain_dimension = m;
    constexpr static int codomain_dimension = n;
    using base_field = K;

    matrix<K, m, n> transpose() const
    {
        matrix<K, m, n> T;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                T[j][i] = this->at(i).at(j);
        return T;
    }
    matrix<K, m, n> T() const
    {
        return transpose();
    }

    matrix<K, m, n> conj_transpose() const
    {
        matrix<K, m, n> T;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                T[j][i] = this->at(i).at(j).conj();
        return T;
    }
    matrix<K, m, n> H() const
    {
        return conj_transpose();
    }

    matrix<K, m, n> hermitian_transpose() const
    {
        return conj_transpose();
    }

    matrix conj() const
    {
        matrix T;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                T[i][j] = this->at(i).at(j).conj();
        return T;
    }

    bool operator!=(const matrix& M) const
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (this->at(i).at(j) != M.at(i).at(j))
                    return true;
        return false;
    }


    
    matrix& operator*=(const matrix& M)
    {
        *this = std::move((*this)*M);
        u[0][0] *= M[0][0];
        return *this;
    }

    bool operator==(const matrix& M) const
    {
        return !(*this != M);
    }
    matrix& operator+=(const matrix& o)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                u.at(i).at(j) += o.u.at(i).at(j);
        return *this;
    }
    matrix& operator-=(const matrix& o)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                u.at(i).at(j) -= o.u.at(i).at(j);
        return *this;
    }
    matrix operator-() const
    {
        matrix p;
        std::transform(u.begin(), u.end(), p.u.begin(), [](auto a)
        {
            std::transform(a.begin(), a.end(), a.begin(), [](auto b)
            {
                return -b;
            });
            return a;
        });
        return p;
    }

    K trace() const
    {
        K s;
        for (int i = 0; i < std::min(n, m); i++)
            s += this->u[i][i];
        return s;
    }
    K tr() const
    {
        return trace();
    }

    matrix& operator*=(const K& k)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                u.at(i).at(j) *= k;
        return *this;
    }

    matrix& operator/=(const K& k)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                u.at(i).at(j) /= k;
        return *this;
    }

    auto& operator[](int i)
    {
        return u[i];
    }
    const auto& operator[](int i) const
    {
        return u[i];
    }

    auto& at(int i)
    {
        return u.at(i);
    }
    const auto& at(int i) const
    {
        return u[i];
    }

    coordinate_space<K, n* m> as_vector() const
    {
        coordinate_space<K, n* m> p;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                p[i * m + j] = this->u[i][j];
        return p;
    }

    coordinate_space<K,n*m> flatten() const
    {
        return as_vector();
    }

    std::vector<std::vector<K>>& get_vect_vect()
    {
        return u;
    }

    const std::vector<std::vector<K>>& get_vect_vect() const
    {
        return u;
    }

protected:
    

    

    std::vector<std::vector<K>> u;

};

template <typename K, int n, int m>
matrix<K, n, m> operator+(
        const matrix<K, n, m>& a, const matrix<K, n, m>& b)
{
    auto c(a);
    return c += b;
}

template <typename K, int n, int m>
matrix<K, n, m> operator-(
        const matrix<K, n, m>& a, const matrix<K, n, m>& b)
{
    auto c(a);
    return c -= b;
}

template <typename K, int n, int m>
matrix<K, n, m> operator*(
        const K& k, const matrix<K, n, m>& a)
{
    auto c(a);
    return c *= k;
}

template <typename K, int n, int p, int m>
matrix<K, n, m> operator*(
        const matrix<K, n, p>& M, const matrix<K, p, m>& N)
{
    
    matrix<K, n, m> P;
    for (int i = 0; i < n; i++)
        for (int k = 0; k < p; k++)
            for (int j = 0; j < m; j++)
                P.at(i).at(j) += M.at(i).at(k) * N.at(k).at(j);
    return P;
}

template <typename K, int n>
K operator*(
        const matrix<K, 1, n>& M, const matrix<K, n, 1>& N)
{
    K P;
    for (int i = 0; i < n; i++)
        P += M.at(0).at(i) * N.at(i).at(0);
    return P;
}

template <typename K, int n>
K operator*(
        const matrix<K, 1, n>& M, const coordinate_space<K, n>& N)
{
    K P;
    for (int i = 0; i < n; i++)
        P += M.at(0).at(i) * N.at(i);
    return P;
}

template <typename K, int n, int m>
matrix<K, n, m> operator*(const matrix<K, n, m>& M, const K& k)
{
    auto c(M);
    return c *= k;
}

template <typename K, int n, int m>
coordinate_space<K, n> operator*(const matrix<K, n, m>& M, const coordinate_space<K, m>& u)
{
    coordinate_space<K, n> v;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            v.at(i) += M.at(i).at(j) * u.at(j);
    return v;
}

template <typename K, int n, int m>
matrix<K, n, m> operator/(const matrix<K, n, m>& M, const K& k)
{
    auto c(M);
    return c /= k;
}

template <typename K, int n, int m>
std::ostream& operator<<(std::ostream& H, const matrix<K, n, m>& p)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            H << p.at(i).at(j) << '\t';
        H << '\n';
    }
    return H;
}

template <typename K, int n, int m>
std::istream& operator>>(std::istream& H, matrix<K, n, m>& p)
{

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            H >> p.at(i).at(j);
    return H;
}

template<typename K,int n,int m=n>
class sparse_matrix
{
public:
    sparse_matrix()
    {
    }
    sparse_matrix(const matrix<K, n, m>& A)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (A[i][j] != 0)
                    u[{i, j}] = A[i][j];
    }

    finite_dimensional_vector_space<K, n> operator*(const finite_dimensional_vector_space<K, m>& w) const
    {
        finite_dimensional_vector_space<K, n> r;
        for (const auto& [I, s] : u)
            r[I.first] += s * w[I.second];
        return r;
    }

    K product_sum(const finite_dimensional_vector_space<K, m>& w) const
    {
        K r(0);
        for (const auto& [I, s] : u)
            r += s * w[I.second];
        return r;
    }
private:
    std::unordered_map<std::pair<int, int>, K> u;
};

constexpr natural M=1e9+7;
template<typename K>
class std::hash<std::pair<K, K>>
{
    std::hash<K> H;
public:
    auto operator()(const std::pair<K, K>& I) const noexcept
    {
        return H(I.first) + H(I.second);
    }
};


template<int p, bool is_prime>
class std::hash < cyclic<p, is_prime>>
{
    std::hash<natural> H;
public:
    auto operator()(const cyclic<p, is_prime>& s) const noexcept
    {
        return H((natural)s);
    }
};

int main()
{
    int T;
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    using F=cyclic<M,true>;
    using R=ring_extension<F,false,-1,-1,0,0,0,0,0,0,0,0,1>;
    matrix<F,10,10> A;
    for(int i=0;i<=9;i++)
        A[(i+1)%10][i]=1;
    A[1][9]=1;

    constexpr int L=2e4+1;
    R Z(polynomial<F>({1,1})),Y(polynomial<F>({0,1}));
    std::vector<R> X1(L,polynomial<F>(1)),X2(10,polynomial<F>(1));
    std::vector<matrix<F,10,10>> U(10,1);
    std::vector<sparse_matrix<F, 10, 10>> V;
    V.emplace_back(matrix<F,10,10>(1));
    for (int i = 1; i < 10; i++)
    {
        U[i] = U[i - 1] * A;
        V.emplace_back(U[i]);
    }
    for(int i=1;i<L;i++)
        X1[i]=X1[i-1]*Z;
    for(int i=1;i<10;i++)
        X2[i]=X2[i-1]*Y;
    while(T--)
    {
        std::string S;
        std::cin >> S;
        int m;
        std::cin >> m;
        finite_dimensional_vector_space<F,10> P;
        for(auto s:S)
            P[s-'0']+=1;
        

        auto [q,r]=std::div(m,10);
        auto H=(X1[q]*X2[r]).get_polynomial().get_vect();
        F R(0);
        for (int i = 0; i < H.size(); i++)
            R += H[i] * V[i].product_sum(P);
        std::cout << R << '\n';
    }
    return 0;
}

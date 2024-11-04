
























using namespace std;


using ipair = pair<int, int>;
using int64 = int64_t;
using uint64 = uint64_t;


template <typename T> void remin(T &a, const T &b) {
    if (b < a) {
        a = b;
    }
}
template <typename T> void remax(T &a, const T &b) {
    if (b > a) {
        a = b;
    }
}
template <class T1, class T2>
inline istream &operator>>(istream &s, pair<T1, T2> &p) {
    return s >> p.first >> p.second;
}
template <class T1, class T2>
inline ostream &operator<<(ostream &s, const pair<T1, T2> &p) {
    return s << "(" << p.first << " " << p.second << ")";
}
template <class T1>
inline ostream &operator<<(ostream &s, const set<T1> &container) {
    for (const auto &x : container) {
        s << x << ' ';
    }
    return s;
}
template <class T1>
inline ostream &operator<<(ostream &s, const unordered_set<T1> &container) {
    for (const auto &x : container) {
        s << x << ' ';
    }
    return s;
}
template <class T1, class T2>
inline ostream &operator<<(ostream &s, const map<T1, T2> &container) {
    for (const auto &x : container) {
        s << x << ' ';
    }
    return s;
}
template <class T1, class T2>
inline ostream &operator<<(ostream &s, const unordered_map<T1, T2> &container) {
    for (const auto &x : container) {
        s << x << ' ';
    }
    return s;
}
template <class T1>
inline ostream &operator<<(ostream &s, const vector<T1> &container) {
    for (const auto &x : container) {
        s << x << ' ';
    }
    return s;
}
template <class T1>
inline istream &operator>>(istream &s, vector<T1> &container) {
    for (auto &x : container) {
        s >> x;
    }
    return s;
}



template <class T> inline T id8(T a, T b, T &x, T &y) {
    if (a < 0) {
        T d = id8(-a, b, x, y);
        x = -x;
        return d;
    }
    if (b < 0) {
        T d = id8(a, -b, x, y);
        y = -y;
        return d;
    }
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        T d = id8(b, a % b, x, y);
        T t = x;
        x = y;
        y = t - (a / b) * y;
        return d;
    }
}
template<class T> inline T gcd(T a, T b) {
    while (b > 0) {
        T tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

template <class T> inline vector<pair<T, int>> factorize(T n) {
    vector<pair<T, int>> R;
    for (T i = 2; n > 1;) {
        if (n % i == 0) {
            int C = 0;
            for (; n % i == 0; C++, n /= i);
            R.push_back(make_pair(i, C));
        }
        i++;
        if (i > n / i)
            i = n;
    }
    if (n > 1)
        R.push_back(make_pair(n, 1));
    return R;
}
template <class T> inline bool id2(T n) {
    if (n <= 1)
        return false;
    for (T i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

vector<bool> id6(int limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i * i <= limit; i += 1) {
        if (is_prime[i]) {
            for (int j = i + i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

template<int64_t P> struct TZp {
    static_assert(P > 1, "P should be > 1");
    static_assert(numeric_limits<int64_t>::max() / P >= P, "P * P should be less then 2^63");
    int64_t Value = 0;

    TZp(int64_t val=0): Value(val) {}

    TZp& operator+=(const TZp& other) {
        Value = (Value + other.Value) % P;
        return *this;
    }
    TZp& operator-=(const TZp& other) {
        Value = (Value - other.Value + P) % P;
        return *this;
    }
    TZp& operator*=(const TZp& other) {
        Value = (Value * other.Value) % P;
        return *this;
    }
    TZp Inverse() const {
        int64_t x, y;
        id8(Value, P, x, y);
        return (x % P + P) % P;
    }
    TZp& operator/=(const TZp& other) {
        Value = (Value * other.Inverse().Value) % P;
        return *this;
    }
    TZp operator-() const {
        return TZp((P - Value) % P);
    }
    TZp operator+(const TZp& other) const {
        TZp result(Value);
        result += other;
        return result;
    }
    TZp operator-(const TZp& other) const {
        TZp result(Value);
        result -= other;
        return result;
    }
    TZp operator*(const TZp& other) const {
        TZp result(Value);
        result *= other;
        return result;
    }
    TZp operator/(const TZp& other) const {
        TZp result(Value);
        result /= other;
        return result;
    }
    int64_t ToInt() const {
        return Value;
    }
};

template<class T> struct TPlus {
    using Type = T;
    const static T Neutral;
    T operator()(const T& x, const T& y) const {
        return x + y;
    }
    T WithAdd(const T& original, const T& add, size_t n) const {
        return original + add * n;
    }
};
template<class T> const T TPlus<T>::Neutral = 0;
template<class T> struct TMax {
    using Type = T;
    static const T Neutral;
    T operator()(const T& x, const T& y) const {
        return max(x, y);
    }
    T WithAdd(const T& original, const T& add, size_t) const {
        return original + add;
    }
};
template<class T> T const TMax<T>::Neutral = numeric_limits<T>::min();
template<class T> struct TMin {
    using Type = T;
    static const T Neutral;
    T operator()(const T& x, const T& y) const {
        return min(x, y);
    }
    T WithAdd(const T& original, const T& add, size_t) const {
        return original + add;
    }
};
template<class T> T const TMin<T>::Neutral = numeric_limits<T>::max();
template<class TF> struct id7 {
    using T = typename TF::Type;
    size_t N = 0;
    TF Func;
    vector<T> Data;
    id7(size_t n, const T& x = T(0), const TF& f = TF()): N(n), Func(f), Data(N * 2, x) {
    }
    void Set(size_t i, const T& x) {
        i += N;
        Data[i] = x;
        for (i /= 2; i > 0; i /= 2) {
            Data[i] = Func(Data[i * 2], Data[i * 2 + 1]);
        }
    }
    T Get(size_t left, size_t right) const {
        if (left >= right) {
            return TF::Neutral;
        }
        auto result = TF::Neutral;
        for (left += N, right += N; left < right; left /= 2, right /= 2) {
            if (left % 2) {
                result = Func(result, Data[left]);
                ++left;
            }
            if (right % 2) {
                --right;
                result = Func(result, Data[right]);
            }
        }
        return result;
    }
    const T& operator[] (size_t i) const {
        return Data[i + N];
    }
};
template<class TF> struct id5: public id7<TF> {
    using TParent = id7<TF>;
    using T = typename TParent::T;
    using TParent::N;
    using TParent::Data;
    using TParent::Func;

    vector<T> Add_;
    vector<size_t> ChildrenCount; 

    void PropagateDownOne(size_t n) {
        if (n * 2 < Add_.size()) {
            Add_[n * 2] += Add_[n];
            if (n * 2 + 1 < Add_.size()) {
                Add_[n * 2 + 1] += Add_[n];
            }
        }
        Data[n] = Func.WithAdd(Data[n], Add_[n], ChildrenCount[n]);
        Add_[n] = 0;
    }
    void PropagateDown(size_t n) { 

        if (n == 0) {
            return;
        }
        PropagateDown(n / 2);
        PropagateDownOne(n);
    }
    void PropagateUp(size_t n, const T& x) {
        if (n == 0) {
            return;
        }
        auto v = Func.WithAdd(Data[n], x, ChildrenCount[n]);
        Data[n / 2] = Func(Data[n ^ 1], v);
        for (size_t i = n / 2; i > 1; i /= 2) {
            Data[i / 2] = Func(Data[i], Data[i ^ 1]);
        }
    }

    id5(size_t n, const T& x = T(0), const TF& f = TF())
        : TParent(n, x, f)
        , Add_(2 * n, T(0))
        , ChildrenCount(2 * n, 0)
    {
        std::fill(ChildrenCount.begin() + N, ChildrenCount.end(), 1);
        for (size_t i = 2 * N - 1; i > 0; --i) {
            ChildrenCount[i / 2] += ChildrenCount[i];
        }
    }
    T Get(size_t left, size_t right) {
        if (left >= right) {
            return TF::Neutral;
        }
        PropagateDown((left + N) / 2);
        PropagateDown((right + N - 1) / 2);

        auto result = TF::Neutral;
        for (left += N, right += N; left < right; left /= 2, right /= 2) {
            

            if (left % 2) {
                PropagateDownOne(left);
                result = Func(result, Data[left]);
                

                ++left;
            }
            if (right % 2) {
                --right;
                PropagateDownOne(right);
                result = Func(result, Data[right]);
                

            }
        }
        return result;
    }
    void Add(size_t left, size_t right, const T& x) {
        for (left += N, right += N; left < right; left /= 2, right /= 2) {
            if (left % 2) {
                Add_[left] += x;
                PropagateUp(left, x);
                ++left;
            }
            if (right % 2) {
                --right;
                Add_[right] += x;
                PropagateUp(right, x);
            }
        }
    }
};

struct id3 {
    vector<size_t> Parents;
    vector<size_t> Sizes;
    id3(size_t n)
        : Parents(n)
        , Sizes(n, 1)
    {
        iota(Parents.begin(), Parents.end(), 0);
    }
    size_t Get(size_t x) {
        if (Parents[x] != x) {
            Parents[x] = Get(Parents[x]);
        }
        return Parents[x];
    }
    void Unite(size_t x, size_t y) {
        x = Get(x);
        y = Get(y);
        if (x == y) {
            return;
        }
        if (Sizes[x] > Sizes[y]) {
            std::swap(x, y);
        }
        Parents[x] = y;
        Sizes[y] += Sizes[x];
    }
};

template<class T> struct TDisjointIntervalSet: public set<pair<T, T>> {
    using TParent = set<pair<T, T>>;
    void Insert(T left, T right) {
        if (right <= left) {
            return;
        }
        auto it = TParent::upper_bound(make_pair(right, numeric_limits<T>::max()));
        auto it1 = it;
        while (it != TParent::begin()) {
            --it;
            if (it->second >= left) {
                remin(left, it->first);
                remax(right, it->second);
            } else {
                ++it;
                break;
            }
        }
        TParent::erase(it, it1);
        TParent::emplace(left, right);
    }
    void Remove(T left, T right) {
        if (right <= left) {
            return;
        }
        auto it = TParent::upper_bound(make_pair(right, numeric_limits<T>::max()));
        auto it1 = it;
        T l = left;
        T r = right;
        while (it != TParent::begin()) {
            --it;
            if (it->second >= left) {
                remin(l, it->first);
                remax(r, it->second);
            } else {
                ++it;
                break;
            }
        }
        TParent::erase(it, it1);
        if (l < left) {
            TParent::emplace(l, left);
        }
        if (r > right) {
            TParent::emplace(right, r);
        }
    }
};



void Solve() {
}

void id4() {
    size_t id1;
    cin >> id1;
    for (size_t id0 = 0; id0 < id1; ++id0) {
        cout << "Case 
        Solve();
    }
}

using TPoint = pair<double, double>;

double prod(TPoint p1, TPoint p2) {
    return p1.first * p2.first + p1.second * p2.second;
}

TPoint diff(TPoint p1, TPoint p2) {
    return TPoint(p1.first - p2.first, p1.second - p2.second);
}

double dist(TPoint x, TPoint y) {
    return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
}

double dist(TPoint P, TPoint P0, TPoint P1) {
    auto v = diff(P1, P0);
    auto w = diff(P, P0);
    double c1 = prod(w, v);
    if (c1 <= 0) {
        return dist(P, P0);
    }
    auto c2 = prod(v, v);
    if (c2 <= c1) {
        return dist(P, P1);
    }
    double b = c1 / c2;
    TPoint Pb(P0.first + b * v.first, P0.second + b * v.second);
    return dist(P, Pb);
}

int main(void) {
    std::ios::sync_with_stdio(false);
    int n;
    TPoint x;
    cin >> n >> x;
    double md = 1e100, Md = 0;
    vector<TPoint> ps(n);
    cin >> ps;
    for (int i = 1; i < n; ++i) {
        auto d = dist(x, ps[i - 1], ps[i]);
        remin(md, d);
        remax(Md, d);

    }
    auto d = dist(x, ps[n - 1], ps[0]);
    remin(md, d);
    remax(Md, d);
    for (auto p : ps) {
        remax(Md, dist(p, x));
    }

    cout << std::setprecision(30) << std::fixed << 3.14159265358 * (Md * Md - md * md) << endl;
    return 0;
}

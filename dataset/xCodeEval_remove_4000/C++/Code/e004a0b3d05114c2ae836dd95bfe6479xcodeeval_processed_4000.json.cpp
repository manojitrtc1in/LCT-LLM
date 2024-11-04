



using namespace std;




template <typename T>
T inverse(T a, T m) {
    T u = 0, v = 1;
    while (a != 0) {
        T t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    assert(m == 1);
    return u;
}

template <typename T>
class Modular {
public:
    using Type = typename decay<decltype(T::value)>::type;

    constexpr Modular() : value() {}

    template <typename U>
    Modular(const U& x) {
        value = normalize(x);
    }

    template <typename U>
    static Type normalize(const U& x) {
        Type v;
        if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
        else v = static_cast<Type>(x % mod());
        if (v < 0) v += mod();
        return v;
    }

    const Type& operator()() const { return value; }
    template <typename U>
    explicit operator U() const { return static_cast<U>(value); }

    constexpr static Type mod() { return T::value; }

    Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
    Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
    template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
    template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
    Modular& operator++() { return *this += 1; }
    Modular& operator--() { return *this -= 1; }
    Modular operator++(int) { Modular result(*this); *this += 1; return result; }
    Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
    Modular operator-() const { return Modular(-value); }

    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {

        uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
        uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
        asm(
            "divl %4; \n\t"
            : "=a" (d), "=d" (m)
            : "d" (xh), "a" (xl), "r" (mod())
        );
        value = m;

        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));

        return *this;
    }
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
        int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(value * rhs.value - q * mod());
        return *this;
    }
    template <typename U = T>
    typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
        value = normalize(value * rhs.value);
        return *this;
    }

    Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

    template <typename U>
    friend const Modular<U>& abs(const Modular<U>& v) { return v; }

    template <typename U>
    friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

    template <typename U>
    friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

    template <typename U>
    friend bool operator<=(const Modular<U>& lhs, const Modular<U>& rhs);

    template <typename U>
    friend bool operator>(const Modular<U>& lhs, const Modular<U>& rhs);

    template <typename U>
    friend bool operator>=(const Modular<U>& lhs, const Modular<U>& rhs);

    template <typename U>
    friend std::istream& operator>>(std::istream& stream, Modular<U>& number);

private:
    Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }
template <typename T, typename U> bool operator<(const Modular<T>& lhs, U rhs) { return lhs < Modular<T>(rhs); }
template <typename T, typename U> bool operator<(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) < rhs; }

template <typename T> bool operator<=(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value <= rhs.value; }
template <typename T, typename U> bool operator<=(const Modular<T>& lhs, U rhs) { return lhs <= Modular<T>(rhs); }
template <typename T, typename U> bool operator<=(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) <= rhs; }

template <typename T> bool operator>(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value > rhs.value; }
template <typename T, typename U> bool operator>(const Modular<T>& lhs, U rhs) { return lhs > Modular<T>(rhs); }
template <typename T, typename U> bool operator>(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) > rhs; }

template <typename T> bool operator>=(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value >= rhs.value; }
template <typename T, typename U> bool operator>=(const Modular<T>& lhs, U rhs) { return lhs >= Modular<T>(rhs); }
template <typename T, typename U> bool operator>=(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) >= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
    assert(b >= 0);
    Modular<T> x = a, res = 1;
    U p = b;
    while (p > 0) {
        if (p & 1) res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}

template <typename T>
bool IsZero(const Modular<T>& number) {
    return number() == 0;
}

template <typename T>
string to_string(const Modular<T>& number) {
    return to_string(number());
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
    return stream << number();
}

template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
    typename common_type<typename Modular<T>::Type, int64_t>::type x;
    stream >> x;
    number.value = Modular<T>::normalize(x);
    return stream;
}

using ModType = int;
struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;

template<typename T>
class SegmentTree {
public:
    struct Node {
        

        

        T lazy = 0;
        T mx = 0;
        T mn = 0;
        T sum = 0;
        int id2 = -1;
        int id3 = -1;
        
        bool changed = false;
 
        void apply(int left, int right, T value) {
            lazy += value;
            mx += value;
            mn += value;
            sum += (right - left + 1) * value;
            if(left == right) {
                id2 = left;
                id3 = left;
            }
            changed = true;
        }
    };
 
    Node unite(const Node &a, const Node &b) const {
        Node res;
        res.sum = a.sum + b.sum;
        res.mx = max(a.mx, b.mx);
        res.mn = min(a.mn, b.mn);
        res.id2 = (res.mn == a.mn? a.id2: b.id2);
        res.id3 = (res.mx == a.mx? a.id3: b.id3);
        return res;
    }
 
    inline void push(int x, int left, int right) {
        int y = (left + right) >> 1;
        int z = x + ((y - left + 1) << 1);
        

        if (tree[x].lazy != 0 || tree[x].changed) {
            tree[x + 1].apply(left, y, tree[x].lazy);
            tree[z].apply(y + 1, right, tree[x].lazy);
            tree[x].lazy = 0;
        }
    }
    
    inline void pull(int x, int z) {
        tree[x] = unite(tree[x + 1], tree[z]);
    }
 
    int n;
    vector<Node> tree;
 
    void build(int x, int left, int right) {
        if (left == right) return;
        int y = (left + right) >> 1;
        int z = x + ((y - left + 1) << 1);
        build(x + 1, left, y);
        build(z, y + 1, right);
        pull(x, z);
    }
 
    template <typename M>
    void build(int x, int left, int right, const vector<M> &v) {
        if (left == right) {
            tree[x].apply(left, right, v[left]);
            return;
        }
        int y = (left + right) >> 1;
        int z = x + ((y - left + 1) << 1);
        build(x + 1, left, y, v);
        build(z, y + 1, right, v);
        pull(x, z);
    }
 
    Node query(int x, int from, int to, int left, int right) {
        if (left <= from && to <= right) return tree[x];
        int y = (from + to) >> 1;
        int z = x + ((y - from + 1) << 1);
        push(x, from, to);
        Node res{};
        if (right <= y) {
            res = query(x + 1, from, y, left, right);
        } else {
            if (left > y) {
                res = query(z, y + 1, to, left, right);
            } else {
                res = unite(query(x + 1, from, y, left, right), query(z, y + 1, to, left, right));
            }
        }
        pull(x, z);
        return res;
    }
 
    template <typename... M>
    void modify(int x, int from, int to, int left, int right, const M&... v) {
        if (left <= from && to <= right) {
            tree[x].apply(from, to, v...);
            return;
        }
        int y = (from + to) >> 1;
        int z = x + ((y - from + 1) << 1);
        push(x, from, to);
        if (left <= y) {
            modify(x + 1, from, y, left, right, v...);
        }
        if (right > y) {
            modify(z, y + 1, to, left, right, v...);
        }
        pull(x, z);
    }
 
    int find_first_knowingly(int x, int left, int right, const function<bool(const Node&)> &f) {
        if (left == right) return left;
        push(x, left, right);
        int y = (left + right) >> 1;
        int z = x + ((y - left + 1) << 1);
        int res;
        if (f(tree[x + 1])) {
            res = find_first_knowingly(x + 1, left, y, f);
        } else {
            res = find_first_knowingly(z, y + 1, right, f);
        }
        pull(x, z);
        return res;
    }
 
    int find_first(int x, int from, int to, int left, int right, const function<bool(const Node&)> &func) {
        if (left <= from && to <= right) {
            if (!func(tree[x])) return -1;
            return find_first_knowingly(x, from, to, func);
        }
        push(x, from, to);
        int y = (from + to) >> 1;
        int z = x + ((y - left + 1) << 1);
        int res = -1;
        if (left <= y) {
            res = find_first(x + 1, from, y, left, right, func);
        }
        if (right > y && res == -1) {
            res = find_first(z, y + 1, to, left, right, func);
        }
        pull(x, z);
        return res;
    }
 
    int find_last_knowingly(int x, int from, int to, const function<bool(const Node&)> &func) {
        if (from == to) return from;
        push(x, from, to);
        int y = (from + to) >> 1;
        int z = x + ((y - from + 1) << 1);
        int res;
        if (func(tree[z])) {
            res = find_last_knowingly(z, y + 1, to, func);
        } else {
            res = find_last_knowingly(x + 1, from, y, func);
        }
        pull(x, z);
        return res;
    }
 
    int find_last(int x, int from, int to, int left, int right, const function<bool(const Node&)> &func) {
        if (left <= from && to <= right) {
            if (!func(tree[x])) return -1;
            return find_last_knowingly(x, from, to, func);
        }
        push(x, from, to);
        int y = (from + to) >> 1;
        int z = x + ((y - from + 1) << 1);
        int res = -1;
        if (right > y) {
            res = find_last(z, y + 1, to, left, right, func);
        }
        if (left <= y && res == -1) {
            res = find_last(x + 1, from, y, left, right, func);
        }
        pull(x, z);
        return res;
    }
 
    SegmentTree(int _n) : n(_n) {
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1);
    }
 
    SegmentTree(const vector<T> &v) {
        n = v.size();
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1, v);
    }
 
    Node query(int left, int right) {
        assert(0 <= left && left <= right && right <= n - 1);
        return query(0, 0, n - 1, left, right);
    }
 
    Node query(int idx) {
        assert(0 <= idx && idx <= n - 1);
        return query(0, 0, n - 1, idx, idx);
    }
 
    template <typename... M>
    void modify(int left, int right, const M&... v) {
        assert(0 <= left && left <= right && right <= n - 1);
        modify(0, 0, n - 1, left, right, v...);
    }
 
    

    

    int find_first(int left, int right, const function<bool(const Node&)> &func) {
        assert(0 <= left && left <= right && right <= n - 1);
        return find_first(0, 0, n - 1, left, right, func);
    }
 
    int find_last(int left, int right, const function<bool(const Node&)> &f) {
        assert(0 <= left && left <= right && right <= n - 1);
        return find_last(0, 0, n - 1, left, right, f);
    }
};
template<typename T>
using segtree = SegmentTree<T>;
 








 


template<typename T>
int id0(SegmentTree<T> &st, int left, int right, T sum) {
    T id1 = T(0);
    return st.find_first(left, right, [&](const typename SegmentTree<T>::Node &node) {
        if (id1 + node.sum >= sum) return true;
        id1 += node.sum;
        return false;
    });
}

class Task {
private:
    
    int n, m, c;
    

    void solveOne(istream &in, ostream &out) {
        in >> n >> m >> c;
        md = c;
        using Mint = Modular<VarMod>;
        vector<Mint> A;
        vector<Mint> B;
        read(A, n);
        read(B, m);
        segtree<Mint> st(A);
        int diff = n - m + 1;
        for(int i = 0; i < m; ++i){
            st.modify(i, (i + n - (m)) , B[i]);
        }

        for(int i = 0; i < n; ++i){
            cout << st.query(i).sum << " "; 
        }
        cout << endl;
    }

    template<typename T>
    void read(vector<T> &ref, int n, int start = 0) {
        ref.resize(start + n);
        for(int i = start; i < start + n; ++i) cin >> ref[i];
    }
    
    template<typename T>
    void write(const vector<T> &ref, int n, int start=0, string mid=" ", string end="\n") {
        for(int i = start; i < start + n; ++i) cout << ref[i] << mid;
        cout << end;
    }

public:
    void solve(istream &in, ostream &out) {
        int t=1;
        while(t--) solveOne(in, out);
    }
};

auto main() -> int {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Task solver;
    istream &in(cin);
    ostream &out(cout);
    solver.solve(in, out);
    return 0;
}
























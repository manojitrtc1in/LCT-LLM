
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } id1;







template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }






template <int mod>
struct ModInt
{
    using lint = long long;
    static int get_mod() { return mod; }
    int val;
    constexpr ModInt() : val(0) {}
    constexpr ModInt &_setval(lint v)
    {
        val = (v >= mod ? v - mod : v);
        return *this;
    }
    constexpr ModInt(lint v) { _setval(v % mod + mod); }
    explicit operator bool() const { return val != 0; }
    constexpr ModInt operator+(const ModInt &x) const { return ModInt()._setval((lint)val + x.val); }
    constexpr ModInt operator-(const ModInt &x) const { return ModInt()._setval((lint)val - x.val + mod); }
    constexpr ModInt operator*(const ModInt &x) const { return ModInt()._setval((lint)val * x.val % mod); }
    constexpr ModInt operator/(const ModInt &x) const { return ModInt()._setval((lint)val * x.inv() % mod); }
    constexpr ModInt operator-() const { return ModInt()._setval(mod - val); }
    constexpr ModInt &operator+=(const ModInt &x) { return *this = *this + x; }
    constexpr ModInt &operator-=(const ModInt &x) { return *this = *this - x; }
    constexpr ModInt &operator*=(const ModInt &x) { return *this = *this * x; }
    constexpr ModInt &operator/=(const ModInt &x) { return *this = *this / x; }
    friend constexpr ModInt operator+(lint a, const ModInt &x) { return ModInt()._setval(a % mod + x.val); }
    friend constexpr ModInt operator-(lint a, const ModInt &x) { return ModInt()._setval(a % mod - x.val + mod); }
    friend constexpr ModInt operator*(lint a, const ModInt &x) { return ModInt()._setval(a % mod * x.val % mod); }
    friend constexpr ModInt operator/(lint a, const ModInt &x) { return ModInt()._setval(a % mod * x.inv() % mod); }
    constexpr bool operator==(const ModInt &x) const { return val == x.val; }
    constexpr bool operator!=(const ModInt &x) const { return val != x.val; }
    bool operator<(const ModInt &x) const { return val < x.val; } 

    friend std::istream &operator>>(std::istream &is, ModInt &x)
    {
        lint t;
        is >> t;
        x = ModInt(t);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const ModInt &x)
    {
        os << x.val;
        return os;
    }
    constexpr lint power(lint n) const
    {
        lint ans = 1, tmp = this->val;
        while (n)
        {
            if (n & 1)
                ans = ans * tmp % mod;
            tmp = tmp * tmp % mod;
            n /= 2;
        }
        return ans;
    }
    constexpr lint inv() const { return this->power(mod - 2); }
    constexpr ModInt operator^(lint n) const { return ModInt(this->power(n)); }
    constexpr ModInt &operator^=(lint n) { return *this = *this ^ n; }

    inline ModInt fac() const
    {
        static std::vector<ModInt> facs;
        int l0 = facs.size();
        if (l0 > this->val)
            return facs[this->val];

        facs.resize(this->val + 1);
        for (int i = l0; i <= this->val; i++)
            facs[i] = (i == 0 ? ModInt(1) : facs[i - 1] * ModInt(i));
        return facs[this->val];
    }

    ModInt doublefac() const
    {
        lint k = (this->val + 1) / 2;
        if (this->val & 1)
            return ModInt(k * 2).fac() / ModInt(2).power(k) / ModInt(k).fac();
        else
            return ModInt(k).fac() * ModInt(2).power(k);
    }

    ModInt nCr(const ModInt &r) const
    {
        if (this->val < r.val)
            return ModInt(0);
        return this->fac() / ((*this - r).fac() * r.fac());
    }
};

using mint = ModInt<1000000007>;


template <typename T>
struct SegTree
{
    int N;
    int head;
    vector<T> x;
    T defaultT;
    using func = function<T(const T&, const T&)>;
    func merger;
    T _get(int begin, int end, int pos, int l, int r) const
    {
        if (r <= begin or l >= end) return defaultT;
        if (l >= begin and r <= end) return x[pos];
        return merger(_get(begin, end, 2 * pos + 1, l, (l + r) / 2), _get(begin, end, 2 * pos + 2, (l + r) / 2, r));
    }
    SegTree(int N, T defaultT, func merger) : N(N), defaultT(defaultT), merger(merger)
    {
        int N_tmp = 1; while (N_tmp < N) N_tmp <<= 1;
        x.assign(N_tmp*2, defaultT), head = N_tmp - 1;
    }
    SegTree(const vector<T> &vals, T defaultT, func merger) : N(vals.size()), defaultT(defaultT), merger(merger)
    {
        int N_tmp = 1; while (N_tmp < N) N_tmp <<= 1;
        x.assign(N_tmp*2, defaultT), head = N_tmp - 1;
        copy(vals.begin(), vals.end(), x.begin() + head);
        IREP(i, head) x[i] = merger(x[i * 2 + 1], x[i * 2 + 2]);
    }
    SegTree() : SegTree(0, T(), [](T, T) { return T(); }) {}
    void build(const vector<T> &vals) { copy(vals.begin(), vals.end(), x.begin() + head); IREP(i, head) x[i] = merger(x[i * 2 + 1], x[i * 2 + 2]); }
    void update(int pos, T val) { pos += head, x[pos] = val; while (pos) pos = (pos - 1) / 2, x[pos] = merger(x[pos*2+1], x[pos*2+2]); }
    T get(int begin, int end) const { return _get(begin, end, 0, 0, (int)x.size() / 2); }
    friend ostream &operator<<(ostream &os, const SegTree<T> &s) { os << "["; REP(i, s.N) os << s.get(i, i + 1) << ","; os << "]"; return os; }
};






struct T
{
    mint first, second;
    int len;
    T() : first(0), second(0), len(0) {}
    T(mint f, mint s, int l) : first(f), second(s), len(l) {}
};

vector<mint> inv2;

int main()
{
    int N;
    cin >> N;
    vector<mint> P(N);
    cin >> P;
    int Q;
    cin >> Q;
    inv2.assign(N + Q + 2, 1);
    REP(i, N + Q + 1) inv2[i + 1] = inv2[i] / 2;
    

    

    SegTree<T> id0(N + Q, T(0, 0, 0), [&](T vl, T vr) {
        T ret(vl.first * inv2.at(vr.len) + vr.first, vl.second + vr.second * inv2.at(vl.len), vl.len + vr.len);
        return ret;
    });
    auto eval = [&](int i) {
        auto ll = id0.get(0, i);
        mint left = ll.first;
        auto rr = id0.get(i + 1, N + Q);
        mint right = rr.second;
        return make_pair((left + right) / 4, left * right / 8);
    };

    vector<int> qi(Q);
    vector<mint> qx(Q);
    REP(i, Q)
    {
        cin >> qi[i] >> qx[i];
        qi[i]--;
    }

    vector<pint> st(N + Q);
    REP(i, N) st[i] = make_pair(P[i].val, i);
    REP(i, Q) st[N + i] = make_pair(qx[i].val, N + i);
    std::sort(st.begin(), st.end());

    vector<int> xpos(N), qpos(Q);

    vector<int> oldpos(N, -1);
    REP(i, N + Q)
    {
        if (st[i].second < N) xpos[st[i].second] = i;
        else qpos[st[i].second - N] = i;
    }

    mint ret = 0;
    REP(i, N) {
        int p = xpos[i];
        auto ep = eval(p);
        ret += ep.first * P[i] - ep.second;
        id0.update(p, T(P[i], P[i], 1));
        oldpos[i] = p;
    }
    printf("%d\n", ret.val);
    REP(q, Q)
    {
        int i = qi[q];
        id0.update(oldpos[i], T(0, 0, 0));
        auto te = eval(oldpos[i]);
        ret -= te.first * P[i] - te.second;

        P[i] = qx[q];
        int pos = qpos[q];
        oldpos[i] = pos;

        te = eval(pos);
        ret += te.first * P[i] - te.second;
        printf("%d\n", ret.val);
        id0.update(pos, T(qx[q], qx[q], 1));
    }
}

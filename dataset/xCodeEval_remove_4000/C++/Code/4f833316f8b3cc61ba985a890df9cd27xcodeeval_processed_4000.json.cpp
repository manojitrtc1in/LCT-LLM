





























using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } id5;





template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args> void ndarray(vector<T>& vec, const V& val, int len, Args... args) { vec.resize(len), for_each(begin(vec), end(vec), [&](T& v) { ndarray(v, val, args...); }); }
template <typename T> bool chmax(T &m, const T q) { return m < q ? (m = q, true) : false; }
template <typename T> bool chmin(T &m, const T q) { return m > q ? (m = q, true) : false; }
const std::vector<std::pair<int, int>> id2{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int id1(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <class T1, class T2> T1 floor_div(T1 num, T2 den) { return (num > 0 ? num / den : -((-num + den - 1) / den)); }
template <class T1, class T2> std::pair<T1, T2> operator+(const std::pair<T1, T2> &l, const std::pair<T1, T2> &r) { return std::make_pair(l.first + r.first, l.second + r.second); }
template <class T1, class T2> std::pair<T1, T2> operator-(const std::pair<T1, T2> &l, const std::pair<T1, T2> &r) { return std::make_pair(l.first - r.first, l.second - r.second); }
template <class T> std::vector<T> sort_unique(std::vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <class T> int arglb(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <class T> int argub(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), x)); }
template <class IStream, class T> IStream &operator>>(IStream &is, std::vector<T> &vec) { for (auto &v : vec) is >> v; return is; }

template <class OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &vec);
template <class OStream, class T, size_t sz> OStream &operator<<(OStream &os, const std::array<T, sz> &arr);
template <class OStream, class T, class TH> OStream &operator<<(OStream &os, const std::unordered_set<T, TH> &vec);
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const pair<T, U> &pa);
template <class OStream, class T> OStream &operator<<(OStream &os, const std::deque<T> &vec);
template <class OStream, class T> OStream &operator<<(OStream &os, const std::set<T> &vec);
template <class OStream, class T> OStream &operator<<(OStream &os, const std::multiset<T> &vec);
template <class OStream, class T> OStream &operator<<(OStream &os, const std::unordered_multiset<T> &vec);
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pa);
template <class OStream, class TK, class TV> OStream &operator<<(OStream &os, const std::map<TK, TV> &mp);
template <class OStream, class TK, class TV, class TH> OStream &operator<<(OStream &os, const std::unordered_map<TK, TV, TH> &mp);
template <class OStream, class... T> OStream &operator<<(OStream &os, const std::tuple<T...> &tpl);

template <class OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <class OStream, class T, size_t sz> OStream &operator<<(OStream &os, const std::array<T, sz> &arr) { os << '['; for (auto v : arr) os << v << ','; os << ']'; return os; }

template <class... T> std::istream &operator>>(std::istream &is, std::tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <class OStream, class... T> OStream &operator<<(OStream &os, const std::tuple<T...> &tpl) { os << '('; std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os << ')'; }

template <class OStream, class T, class TH> OStream &operator<<(OStream &os, const std::unordered_set<T, TH> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pa) { return os << '(' << pa.first << ',' << pa.second << ')'; }
template <class OStream, class TK, class TV> OStream &operator<<(OStream &os, const std::map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <class OStream, class TK, class TV, class TH> OStream &operator<<(OStream &os, const std::unordered_map<TK, TV, TH> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }

const string COLOR_RESET = "\033[0m", id3 = "\033[1;32m", id8 = "\033[1;31m", id0 = "\033[1;36m", id4 = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", id10 = "\033[0;2m";







template <int md> struct ModInt {





    using lint = long long;
    MDCONST static int mod() { return md; }
    static int get_primitive_root() {
        static int primitive_root = 0;
        if (!primitive_root) {
            primitive_root = [&]() {
                std::set<int> fac;
                int v = md - 1;
                for (lint i = 2; i * i <= v; i++)
                    while (v % i == 0) fac.insert(i), v /= i;
                if (v > 1) fac.insert(v);
                for (int g = 1; g < md; g++) {
                    bool ok = true;
                    for (auto i : fac)
                        if (ModInt(g).pow((md - 1) / i) == 1) {
                            ok = false;
                            break;
                        }
                    if (ok) return g;
                }
                return -1;
            }();
        }
        return primitive_root;
    }
    int val_;
    int val() const noexcept { return val_; }
    MDCONST ModInt() : val_(0) {}
    MDCONST ModInt &_setval(lint v) { return val_ = (v >= md ? v - md : v), *this; }
    MDCONST ModInt(lint v) { _setval(v % md + md); }
    MDCONST explicit operator bool() const { return val_ != 0; }
    MDCONST ModInt operator+(const ModInt &x) const {
        return ModInt()._setval((lint)val_ + x.val_);
    }
    MDCONST ModInt operator-(const ModInt &x) const {
        return ModInt()._setval((lint)val_ - x.val_ + md);
    }
    MDCONST ModInt operator*(const ModInt &x) const {
        return ModInt()._setval((lint)val_ * x.val_ % md);
    }
    MDCONST ModInt operator/(const ModInt &x) const {
        return ModInt()._setval((lint)val_ * x.inv().val() % md);
    }
    MDCONST ModInt operator-() const { return ModInt()._setval(md - val_); }
    MDCONST ModInt &operator+=(const ModInt &x) { return *this = *this + x; }
    MDCONST ModInt &operator-=(const ModInt &x) { return *this = *this - x; }
    MDCONST ModInt &operator*=(const ModInt &x) { return *this = *this * x; }
    MDCONST ModInt &operator/=(const ModInt &x) { return *this = *this / x; }
    friend MDCONST ModInt operator+(lint a, const ModInt &x) {
        return ModInt()._setval(a % md + x.val_);
    }
    friend MDCONST ModInt operator-(lint a, const ModInt &x) {
        return ModInt()._setval(a % md - x.val_ + md);
    }
    friend MDCONST ModInt operator*(lint a, const ModInt &x) {
        return ModInt()._setval(a % md * x.val_ % md);
    }
    friend MDCONST ModInt operator/(lint a, const ModInt &x) {
        return ModInt()._setval(a % md * x.inv().val() % md);
    }
    MDCONST bool operator==(const ModInt &x) const { return val_ == x.val_; }
    MDCONST bool operator!=(const ModInt &x) const { return val_ != x.val_; }
    MDCONST bool operator<(const ModInt &x) const {
        return val_ < x.val_;
    } 

    friend std::istream &operator>>(std::istream &is, ModInt &x) {
        lint t;
        return is >> t, x = ModInt(t), is;
    }
    MDCONST friend std::ostream &operator<<(std::ostream &os, const ModInt &x) {
        return os << x.val_;
    }
    MDCONST ModInt pow(lint n) const {
        ModInt ans = 1, tmp = *this;
        while (n) {
            if (n & 1) ans *= tmp;
            tmp *= tmp, n >>= 1;
        }
        return ans;
    }

    static std::vector<ModInt> facs, id9, invs;
    MDCONST static void _precalculation(int N) {
        int l0 = facs.size();
        if (N > md) N = md;
        if (N <= l0) return;
        facs.resize(N), id9.resize(N), invs.resize(N);
        for (int i = l0; i < N; i++) facs[i] = facs[i - 1] * i;
        id9[N - 1] = facs.back().pow(md - 2);
        for (int i = N - 2; i >= l0; i--) id9[i] = id9[i + 1] * (i + 1);
        for (int i = N - 1; i >= l0; i--) invs[i] = id9[i] * facs[i - 1];
    }
    MDCONST ModInt inv() const {
        if (this->val_ < std::min(md >> 1, 1 << 21)) {
            if (facs.empty()) facs = {1}, id9 = {1}, invs = {0};
            while (this->val_ >= int(facs.size())) _precalculation(facs.size() * 2);
            return invs[this->val_];
        } else {
            return this->pow(md - 2);
        }
    }
    MDCONST ModInt fac() const {
        while (this->val_ >= int(facs.size())) _precalculation(facs.size() * 2);
        return facs[this->val_];
    }
    MDCONST ModInt facinv() const {
        while (this->val_ >= int(facs.size())) _precalculation(facs.size() * 2);
        return id9[this->val_];
    }
    MDCONST ModInt nCr(const ModInt &r) const {
        return (this->val_ < r.val_) ? 0 : this->fac() * (*this - r).facinv() * r.facinv();
    }
};
template <int md> std::vector<ModInt<md>> ModInt<md>::facs = {1};
template <int md> std::vector<ModInt<md>> ModInt<md>::id9 = {1};
template <int md> std::vector<ModInt<md>> ModInt<md>::invs = {0};

using mint = ModInt<1000000007>;

mint solve(int n, int m) {
    mint ret = 0;
    const mint inv2 = mint(2).inv();
    mint id6 = 1;

    auto id7 = [&](int i) -> mint {
        return mint(n + m + 2).nCr(i) * ((n + m + 2 - i) % 2 ? -1 : 1);
    };

    mint fi = id7(0);
    fi = id7(1) + fi * inv2;
    

    

    

    

    FOR(j, 1, n + m + 1) {
        fi = id7(j + 1) + fi * inv2;
        id6 *= inv2;
        mint tmp = mint(j + 1) * mint(n + j - 1).nCr(n) * mint(m + j - 1).nCr(m) * (id6 * inv2 * inv2 - inv2 * fi);
        ret += tmp;
    }
    return ret;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << solve(n, m) << '\n';
    }
}

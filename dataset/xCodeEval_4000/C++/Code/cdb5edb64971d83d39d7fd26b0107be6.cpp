#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <tuple>
#include <type_traits>




using std::cin;
using std::cout;
using std::vector;
using std::list;
using std::unordered_set;
using std::set;
using std::map;
using std::unordered_map;
using std::multimap;
using std::unordered_multimap;
using std::pair;
using std::make_pair;
using std::min;
using std::max;
using std::swap;
using std::stack;
using std::deque;
using std::queue;
using std::ios_base;
using std::ifstream;
using std::ofstream;
using std::string;
using std::tuple;
using std::make_tuple;
using std::get;
using std::upper_bound;
using std::lower_bound;
using std::max_element;
using std::min_element;
using std::multiset;
using std::greater;
using std::priority_queue;
using std::less;
using std::endl;



typedef long long ll;
typedef unsigned long long ull;



[[maybe_unused]] const string sep = " ";
[[maybe_unused]] const string yes = "YES\n";
[[maybe_unused]] const string no = "NO\n";
[[maybe_unused]] const string ng = "NG\n";
[[maybe_unused]] const string ok = "OK\n";
[[maybe_unused]] const double pi = acos(-1);
[[maybe_unused]] const ull modular = 998244353;






class BigInteger {
public:
    BigInteger();

    BigInteger(int int_to_big_integer);

    BigInteger(const std::string &string_to_big_integer);

    friend BigInteger operator+(const BigInteger &big_integer_a,
                                const BigInteger &big_integer_b);

    friend BigInteger operator-(const BigInteger &big_integer_a,
                                const BigInteger &big_integer_b);

    friend BigInteger operator*(const BigInteger &big_integer_a,
                                const BigInteger &big_integer_b);

    friend BigInteger operator/(const BigInteger &big_integer_a,
                                const BigInteger &big_integer_b);

    friend BigInteger operator%(const BigInteger &big_integer_a,
                                const BigInteger &big_integer_b);

    BigInteger &operator+=(const BigInteger &big_integer_a);

    BigInteger &operator-=(const BigInteger &big_integer_a);

    BigInteger &operator*=(const BigInteger &big_integer_a);

    BigInteger &operator%=(const BigInteger &big_integer_a);

    BigInteger &operator/=(const BigInteger &big_integer_a);

    bool operator<(BigInteger const &big_integer_a) const;

    bool operator>(BigInteger const &big_integer_a) const;

    bool operator<=(BigInteger const &big_integer_a) const;

    bool operator>=(BigInteger const &big_integer_a) const;

    bool operator==(BigInteger const &big_integer_a) const;

    bool operator!=(BigInteger const &big_integer_a) const;

    BigInteger &operator++();

    const BigInteger operator++(int);

    BigInteger &operator--();

    const BigInteger operator--(int);

    BigInteger operator-();

    std::string toString() const;

    explicit operator bool();

    friend std::istream &operator>>(std::istream &in, BigInteger &big_integer_a);

    friend std::ostream &operator<<(std::ostream &out,
                                    const BigInteger &big_integer_a);

private:
    bool is_positive_ = true;

    std::vector<int> digits_;

    void EraseLeadingZeros();

    bool IsZero() const;

    static void SubIfPositive(BigInteger &big_integer_a,
                              const BigInteger &big_integer_b);

    static void Sum(BigInteger &big_integer_a, const BigInteger &big_integer_b);

    BigInteger Abs() const;

    friend std::vector<int> NaiveMultiplication(const std::vector<int> &digits_a,
                                                const std::vector<int> &digits_b);

    friend void Normalize(std::vector<int> &digits);

    friend std::vector<int> FastMultiplication(const std::vector<int> &digits_a,
                                               const std::vector<int> &digits_b);

    bool DifferentSigns(const BigInteger &big_integer_a) const;
};




std::vector<int> NaiveMultiplication(const std::vector<int> &digits_a,
                                     const std::vector<int> &digits_b) {
    auto size = digits_a.size();
    std::vector<int> digits_result(2 * size);
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            digits_result[i + j] += digits_a[i] * digits_b[j];
        }
    }
    return digits_result;
}

void Normalize(std::vector<int> &digits) {
    for (size_t i = 0; i < digits.size(); ++i) {
        digits[i + 1] += digits[i] / 10;
        digits[i] %= 10;
    }
}

std::vector<int> FastMultiplication(const std::vector<int> &digits_a,
                                    const std::vector<int> &digits_b) {
    auto size = digits_a.size();
    std::vector<int> digits_result(2 * size);


    return NaiveMultiplication(digits_a, digits_b);


































































}

BigInteger::BigInteger() : is_positive_(true) {}

BigInteger::BigInteger(int int_to_big_integer) {
    if (int_to_big_integer < 0) {
        is_positive_ = false;
        int_to_big_integer *= -1;
    } else if (int_to_big_integer == 0) {
        digits_.push_back(0);
        is_positive_ = true;
    }
    while (int_to_big_integer != 0) {
        digits_.push_back(int_to_big_integer % 10);
        int_to_big_integer /= 10;
    }
}

BigInteger::BigInteger(const std::string &string_to_big_integer) {
    is_positive_ = true;
    if (!string_to_big_integer.empty()) {
        for (size_t i = string_to_big_integer.length() - 1; i > 0; --i)
            digits_.push_back(string_to_big_integer[i] - '0');
        if (string_to_big_integer[0] == '-')
            is_positive_ = false;
        else
            digits_.push_back(string_to_big_integer[0] - '0');
    }
}




BigInteger operator+(const BigInteger &big_integer_a,
                     const BigInteger &big_integer_b) {
    BigInteger big_integer_sum = big_integer_a;
    return big_integer_sum += big_integer_b;
}

BigInteger operator-(const BigInteger &big_integer_a,
                     const BigInteger &big_integer_b) {
    BigInteger big_integer_sub = big_integer_a;
    return big_integer_sub -= big_integer_b;
}

BigInteger operator*(const BigInteger &big_integer_a,
                     const BigInteger &big_integer_b) {
    BigInteger big_integer_multiplication = big_integer_a;
    return big_integer_multiplication *= big_integer_b;
}

BigInteger operator/(const BigInteger &big_integer_a,
                     const BigInteger &big_integer_b) {
    BigInteger big_integer_division = big_integer_a;
    return big_integer_division /= big_integer_b;
}

BigInteger operator%(const BigInteger &big_integer_a,
                     const BigInteger &big_integer_b) {
    BigInteger big_integer_division_with_remainder = big_integer_a;
    return big_integer_division_with_remainder %= big_integer_b;
}




BigInteger &BigInteger::operator+=(const BigInteger &big_integer_a) {
    if (!DifferentSigns(big_integer_a)) {
        Sum(*this, big_integer_a);
        return *this;
    } else {
        if (this->Abs() >= big_integer_a.Abs()) {
            SubIfPositive(*this, big_integer_a);
            return *this;
        } else {
            BigInteger big_integer_temp_this = *this;
            BigInteger big_integer_temp_a = big_integer_a;
            SubIfPositive(big_integer_temp_a, big_integer_temp_this);
            return *this = big_integer_temp_a;
        }
    }
}

BigInteger &BigInteger::operator-=(const BigInteger &big_integer_a) {
    if (!DifferentSigns(big_integer_a)) {
        if (this->Abs() >= big_integer_a.Abs()) {
            SubIfPositive(*this, big_integer_a);
            return *this;
        } else {
            BigInteger big_integer_temp_this = *this;
            BigInteger big_integer_temp_a = big_integer_a;
            SubIfPositive(big_integer_temp_a, big_integer_temp_this);
            big_integer_temp_a.is_positive_ = !big_integer_temp_a.is_positive_;
            return *this = big_integer_temp_a;
        }
    } else {
        Sum(*this, big_integer_a);
        return *this;
    }
}

BigInteger &BigInteger::operator*=(const BigInteger &big_integer_a) {
    size_t size = std::max(big_integer_a.digits_.size(), digits_.size());
    BigInteger big_integer_result;
    auto big_integer_temp_a = big_integer_a;
    big_integer_temp_a.digits_.resize(size);
    digits_.resize(size);
    digits_ = FastMultiplication(big_integer_temp_a.digits_, digits_);
    Normalize(digits_);
    EraseLeadingZeros();
    is_positive_ = !(DifferentSigns(big_integer_a));
    return *this;
}

BigInteger &BigInteger::operator/=(const BigInteger &big_integer_a) {
    BigInteger big_integer_result;
    big_integer_result.digits_.resize(digits_.size());
    BigInteger big_integer_current;
    for (int i = digits_.size() - 1; i >= 0; --i) {
        big_integer_current.digits_.insert(big_integer_current.digits_.begin(), 0);
        big_integer_current.EraseLeadingZeros();
        big_integer_current.digits_[0] = digits_[i];
        size_t new_digit = 0;
        size_t left = 0, right = 9;
        while (left <= right) {
            size_t middle = (left + right) / 2;
            if ((big_integer_a.Abs() * middle).Abs() <= big_integer_current.Abs()) {
                new_digit = middle;
                left = middle + 1;
            } else
                right = middle - 1;
        }
        big_integer_current -= big_integer_a.Abs() * new_digit;
        big_integer_result.digits_[i] = new_digit;
    }

    big_integer_result.is_positive_ = !(DifferentSigns(big_integer_a));
    big_integer_result.EraseLeadingZeros();
    *this = big_integer_result;
    return *this;
}

BigInteger &BigInteger::operator%=(const BigInteger &big_integer_a) {
    BigInteger big_integer_result;
    big_integer_result.digits_.resize(digits_.size());
    BigInteger big_integer_current;
    for (int i = digits_.size() - 1; i >= 0; --i) {
        big_integer_current.digits_.insert(big_integer_current.digits_.begin(), 0);
        big_integer_current.EraseLeadingZeros();
        big_integer_current.digits_[0] = digits_[i];
        size_t new_digit = 0;
        size_t left = 0, right = 9;
        while (left <= right) {
            size_t middle = (left + right) / 2;
            if ((big_integer_a.Abs() * middle).Abs() <= big_integer_current.Abs()) {
                new_digit = middle;
                left = middle + 1;
            } else
                right = middle - 1;
        }
        big_integer_result.digits_[i] = new_digit;
        big_integer_current = big_integer_current - big_integer_a.Abs() * new_digit;
    }
    big_integer_current.EraseLeadingZeros();
    big_integer_current.is_positive_ = is_positive_;
    if (big_integer_current.digits_.empty())
        big_integer_current.digits_.push_back(0);
    *this = big_integer_current;
    return *this;
}




bool BigInteger::operator<(BigInteger const &big_integer_a) const {
    if (IsZero() && big_integer_a.IsZero()) {
        return false;
    }
    if (DifferentSigns(big_integer_a)) {
        return !is_positive_;
    }
    if (digits_.size() > big_integer_a.digits_.size()) {
        return !is_positive_;
    }
    if (digits_.size() < big_integer_a.digits_.size()) {
        return is_positive_;
    }
    for (int i = digits_.size() - 1; i >= 0; --i) {
        if (digits_[i] > big_integer_a.digits_[i]) {
            return !is_positive_;
        }
        if (digits_[i] < big_integer_a.digits_[i]) {
            return is_positive_;
        }
    }
    return false;
}

bool BigInteger::operator>(BigInteger const &big_integer_a) const {
    return (big_integer_a < *this);
}

bool BigInteger::operator<=(BigInteger const &big_integer_a) const {
    return !(*this > big_integer_a);
}

bool BigInteger::operator>=(BigInteger const &big_integer_a) const {
    return !(*this < big_integer_a);
}

bool BigInteger::operator==(BigInteger const &big_integer_a) const {
    return (*this >= big_integer_a) && (*this <= big_integer_a);
}

bool BigInteger::operator!=(BigInteger const &big_integer_a) const {
    return !(*this == big_integer_a);
}




BigInteger &BigInteger::operator++() {
    *this += 1;
    return *this;
}

const BigInteger BigInteger::operator++(int) {
    BigInteger big_integer_temp_this = *this;
    ++(*this);
    return big_integer_temp_this;
}

BigInteger &BigInteger::operator--() {
    *this -= 1;
    return *this;
}

const BigInteger BigInteger::operator--(int) {
    BigInteger big_integer_temp_this = *this;
    --(*this);
    return big_integer_temp_this;
}




std::istream &operator>>(std::istream &in, BigInteger &big_integer_a) {
    std::string string_to_big_integer;
    in >> string_to_big_integer;
    big_integer_a = BigInteger(string_to_big_integer);
    return in;
}

std::ostream &operator<<(std::ostream &out, const BigInteger &big_integer_a) {
    out << big_integer_a.toString();
    return out;
}

BigInteger BigInteger::operator-() {
    BigInteger big_integer_temp_this = *this;
    big_integer_temp_this.is_positive_ = !this->is_positive_;
    if (IsZero()) {
        big_integer_temp_this.is_positive_ = true;
        big_integer_temp_this.digits_[0] = 0;
        return big_integer_temp_this;
    } else
        return big_integer_temp_this;
}




std::string BigInteger::toString() const {
    std::string s = is_positive_ ? "" : "-";
    if (IsZero()) {
        s = '0';
        return s;
    }
    bool leading_zero = true;
    for (int i = digits_.size() - 1; i >= 0; --i) {
        if (!(digits_[i] == 0 && leading_zero)) {
            leading_zero = false;
            s += digits_[i] + '0';
        }
    }
    if (s.empty() || (s[0] == '-' && s.length() == 1)) s = '0';
    return s;
}




BigInteger::operator bool() { return !this->IsZero(); }




BigInteger BigInteger::Abs() const {
    BigInteger big_integer_temp_this = (*this);
    big_integer_temp_this.is_positive_ = true;
    return big_integer_temp_this;
}

void BigInteger::EraseLeadingZeros() {
    while (!digits_.empty() && *digits_.rbegin() == 0) {
        digits_.pop_back();
    }
    if (digits_.empty()) {
        is_positive_ = true;
        digits_.push_back(0);
    }
}

void BigInteger::SubIfPositive(BigInteger &big_integer_a,
                               const BigInteger &big_integer_b) {
    int carry = 0;
    for (size_t i = 0; i < big_integer_b.digits_.size() || carry; ++i) {
        if (i < big_integer_b.digits_.size()) {
            big_integer_a.digits_[i] -= carry + big_integer_b.digits_[i];
        } else {
            big_integer_a.digits_[i] -= carry;
        }
        carry = (big_integer_a.digits_[i] < 0);
        if (carry != 0) big_integer_a.digits_[i] += 10;
    }
    big_integer_a.EraseLeadingZeros();
}

void BigInteger::Sum(BigInteger &big_integer_a,
                     const BigInteger &big_integer_b) {
    int carry = 0;
    for (size_t i = 0; i < big_integer_a.digits_.size() ||
                       i < big_integer_b.digits_.size() || carry;
         ++i) {
        if (i == big_integer_a.digits_.size()) {
            big_integer_a.digits_.push_back(0);
        }
        if (i < big_integer_b.digits_.size()) {
            big_integer_a.digits_[i] += carry + big_integer_b.digits_[i];
        } else {
            big_integer_a.digits_[i] += carry;
        }
        carry = big_integer_a.digits_[i] / 10;
        big_integer_a.digits_[i] %= 10;
    }
    big_integer_a.EraseLeadingZeros();
}

bool BigInteger::IsZero() const {
    return digits_[0] == 0 && digits_.size() == 1;
}

bool BigInteger::DifferentSigns(const BigInteger &big_integer_a) const {
    return is_positive_ ^ big_integer_a.is_positive_;
}





template<class T>
T min(const T &a, const T &b, const T &c) {
    return min(a, min(b, c));
}

template<class T>
T max(const T &a, const T &b, const T &c) {
    return max(a, max(b, c));
}

typedef vector<vector<ll>> graph;

vector<ll> lca_h, lca_dfs_list, lca_first, lca_tree;
vector<char> lca_dfs_used;

void lca_dfs(const graph &g, ll v, ll h = 1) {
    lca_dfs_used[v] = true;
    lca_h[v] = h;
    lca_dfs_list.push_back(v);
    for (auto i = g[v].begin(); i != g[v].end(); ++i)
        if (!lca_dfs_used[*i]) {
            lca_dfs(g, *i, h + 1);
            lca_dfs_list.push_back(v);
        }
}

void lca_build_tree(ll i, ll l, ll r) {
    if (l == r)
        lca_tree[i] = lca_dfs_list[l];
    else {
        ll m = (l + r) >> 1;
        lca_build_tree(i + i, l, m);
        lca_build_tree(i + i + 1, m + 1, r);
        if (lca_h[lca_tree[i + i]] < lca_h[lca_tree[i + i + 1]])
            lca_tree[i] = lca_tree[i + i];
        else
            lca_tree[i] = lca_tree[i + i + 1];
    }
}

void lca_prepare(const graph &g, ll root) {
    ll n = (ll) g.size();
    lca_h.resize(n);
    lca_dfs_list.reserve(n * 2);
    lca_dfs_used.assign(n, 0);

    lca_dfs(g, root);

    ll m = (ll) lca_dfs_list.size();
    lca_tree.assign(lca_dfs_list.size() * 4 + 1, -1);
    lca_build_tree(1, 0, m - 1);

    lca_first.assign(n, -1);
    for (ll i = 0; i < m; ++i) {
        ll v = lca_dfs_list[i];
        if (lca_first[v] == -1)
            lca_first[v] = i;
    }
}

ll lca_tree_min(ll i, ll sl, ll sr, ll l, ll r) {
    if (sl == l && sr == r)
        return lca_tree[i];
    ll sm = (sl + sr) >> 1;
    if (r <= sm)
        return lca_tree_min(i + i, sl, sm, l, r);
    if (l > sm)
        return lca_tree_min(i + i + 1, sm + 1, sr, l, r);
    ll ans1 = lca_tree_min(i + i, sl, sm, l, sm);
    ll ans2 = lca_tree_min(i + i + 1, sm + 1, sr, sm + 1, r);
    return lca_h[ans1] < lca_h[ans2] ? ans1 : ans2;
}

ll lca(ll a, ll b) {
    ll left = lca_first[a],
            right = lca_first[b];
    if (left > right) swap(left, right);
    return lca_tree_min(1, 0, (ll) lca_dfs_list.size() - 1, left, right);
}


ll gcd(ll a, ll b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

ll fast_power(ll a, ll pow) {
    if (pow == 0) {
        return 1;
    }
    if (pow % 2 == 0) {
        auto x = fast_power(a, pow / 2);
        return (x * x);
    } else {
        auto x = fast_power(a, pow - 1);
        return (a * x);
    }
}

ll fast_power(ll a, ll pow, ll mod) {
    if (pow == 0) {
        return 1;
    }
    if (pow % 2 == 0) {
        auto x = fast_power(a, pow / 2, mod);
        return (x * x) % mod;
    } else {
        auto x = fast_power(a, pow - 1, mod);
        return (a * x) % mod;
    }

}

void getFactorialsModular(const ll n, const ll mod, vector<ll> &F) {
    F.resize(n + 1);
    F[0] = 1;
    for (ll i = 1; i <= n; ++i) {
        F[i] = (F[i - 1] * i) % mod;
    }
}

void getFactorialsAndInverseModular(const ll n, const ll mod, vector<ll> &F, vector<ll> &I) {
    getFactorialsModular(n, mod, F);
    I.resize(n + 1);
    I[0] = 1;
    for (ll i = 1; i <= n; ++i) {
        I[i] = fast_power(F[i], mod - 2, mod);
    }
}

ll CnkMod(ll n, ll k, ll mod, vector<ll> &F, vector<ll> &I) {
    return (((F[n] * I[k]) % mod) * I[n - k]) % mod;
}

ll CnkWithRepetitionMod(ll n, ll k, ll mod, vector<ll> &F, vector<ll> &I) {
    return CnkMod(n + k - 1, k - 1, mod, F, I);
}









template<typename valueType, typename tagType>
class segmentTreeNode {
public:
    int id, left, right;
    valueType val;
    tagType tag;
};

template<typename valueType,
        typename tagType,
        valueType (*merge)(valueType, valueType),
        void (*update)(segmentTreeNode<valueType, tagType> &, tagType)>
class segmentTree {
private:
    std::vector<segmentTreeNode<valueType, tagType> > nodes;
    int leftRange, rightRange;
    valueType valueZero;
    tagType tagZero;

    void push_up(int cur) {
        nodes[cur].val = merge(nodes[cur << 1].val, nodes[cur << 1 | 1].val);
    }

    void push_down(int cur) {
        update(nodes[cur << 1], nodes[cur].tag);
        update(nodes[cur << 1 | 1], nodes[cur].tag);
        nodes[cur].tag = tagZero;
    }

    void build(int cur, int l, int r, const std::vector<valueType> &initValue) {
        nodes[cur].id = cur;
        nodes[cur].left = l;
        nodes[cur].right = r;
        nodes[cur].tag = tagZero;
        if (l == r - 1) nodes[cur].val = initValue[l - leftRange];
        else {
            build(cur << 1, l, (l + r) >> 1, initValue);
            build(cur << 1 | 1, (l + r) >> 1, r, initValue);
            push_up(cur);
        }
    }

    void init(const std::vector<valueType> &_initValue,
              const valueType &_valueZero,
              const tagType &_tagZero) {
        valueZero = _valueZero;
        tagZero = _tagZero;
        nodes.resize((rightRange - leftRange) << 2);
        build(1, leftRange, rightRange, _initValue);
    }

    void modify(int cur, int l, int r, int L, int R, const tagType &tag) {
        if (l >= R || r <= L) return;
        if (L <= l && r <= R) update(nodes[cur], tag);
        else {
            push_down(cur);
            modify(cur << 1, l, (l + r) >> 1, L, R, tag);
            modify(cur << 1 | 1, (l + r) >> 1, r, L, R, tag);
            push_up(cur);
        }
    }

    valueType query(int cur, int l, int r, int L, int R) {
        if (l >= R || r <= L) return valueZero;
        if (L <= l && r <= R) return nodes[cur].val;
        push_down(cur);
        return merge(query(cur << 1, l, (l + r) >> 1, L, R),
                     query(cur << 1 | 1, (l + r) >> 1, r, L, R));
    }

public:
    segmentTree() {}

    segmentTree(int _leftRange,
                int _rightRange,
                const std::vector<valueType> &_initValue,
                const valueType &_valueZero,
                const tagType &_tagZero) {
        leftRange = _leftRange;
        rightRange = _rightRange;
        init(_initValue, _valueZero, _tagZero);
    }

    segmentTree(int size,
                const std::vector<valueType> &_initValue,
                const valueType &_valueZero,
                const tagType &_tagZero) {
        leftRange = 1;
        rightRange = size + 1;
        init(_initValue, _valueZero, _tagZero);
    }

    void modify(int l, int r, const tagType &tag) {
        modify(1, leftRange, rightRange, l, r, tag);
    }

    void modify(int p, const tagType &tag) {
        modify(p, p + 1, tag);
    }

    valueType query(int l, int r) {
        return query(1, leftRange, rightRange, l, r);
    }

    valueType query(int p) {
        return query(p, p + 1);
    }
};

ll merge(ll x, ll y) {
    return x + y;
}

void update(segmentTreeNode<ll, ll> &node, ll x) {
    node.val += x;
    node.val %= 2;
}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    cout.precision(15);
    ll tests;
    cin >> tests;
    while (tests--) {
        ll n;
        cin >> n;
        map<ll, set<ll>> E;
        for (int i = 0; i < n - 1; ++i) {
            ll u, v;
            cin >> u >> v;
            E[u].insert(v);
            E[v].insert(u);
        }
        cout << "?" << sep << n << sep;
        for (int i = 1; i <= n; ++i) {
            cout << i << sep;
        }
        cout << std::endl;
        ll root, distance;
        cin >> root >> distance;
        vector<ll> _X(n + 1, -1);
        _X[root] = 0;
        queue<ll> Q;
        Q.push(root);
        while (!Q.empty()) {
            auto x = Q.front();
            Q.pop();
            for (auto &t : E[x]) {
                if (_X[t] == -1) {
                    _X[t] = _X[x] + 1;
                    Q.push(t);
                }
            }
        }
        ll max_level = *max_element(_X.begin(), _X.end());
        map<ll, set<ll>> Level;
        for (int i = 1; i <= n; ++i) {
            Level[_X[i]].insert(i);
        }
        ll pos_x;
        ll _d, _x;
        ll left = (distance + 1) / 2;
        ll right = min(max_level, distance);
        ll middle = left + (right - left) / 2;
        while (left <= right) {
            cout << "?" << sep << Level[middle].size() << sep;
            for (auto &t : Level[middle]) {
                cout << t << sep;
            }
            cout << endl;
            cin >> _x >> _d;
            if (_d == distance) {
                pos_x = _x;
                left = middle + 1;
                middle = left + (right - left) / 2;
            } else {
                right = middle - 1;
                middle = left + (right - left) / 2;
            }
        }
        vector<ll> DistanceFromX(n + 1, -1);
        DistanceFromX[pos_x] = 0;
        Q.push(pos_x);
        while (!Q.empty()) {
            auto x = Q.front();
            Q.pop();
            for (auto &t : E[x]) {
                if (DistanceFromX[t] == -1) {
                    DistanceFromX[t] = DistanceFromX[x] + 1;
                    Q.push(t);
                }
            }
        }
        cout << "?" << sep << std::count(DistanceFromX.begin(), DistanceFromX.end(), distance) << sep;
        for (int i = 1; i <= n; ++i) {
            if (DistanceFromX[i] == distance) {
                cout << i << sep;
            }
        }
        cout << endl;
        ll gx, gd;
        cin >> gx >> gd;
        cout << "!" << sep << pos_x << sep << gx << endl;
        string hope_it_will_be_correct;
        cin >> hope_it_will_be_correct;
    }
}



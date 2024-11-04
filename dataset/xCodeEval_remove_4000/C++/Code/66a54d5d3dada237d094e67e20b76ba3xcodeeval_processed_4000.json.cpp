





















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
[[maybe_unused]] const ull modular = 1e9 + 7;






class BigInteger {
public:
    BigInteger();

    BigInteger(int id7);

    BigInteger(const std::string &id12);

    friend BigInteger operator+(const BigInteger &id26,
                                const BigInteger &id6);

    friend BigInteger operator-(const BigInteger &id26,
                                const BigInteger &id6);

    friend BigInteger operator*(const BigInteger &id26,
                                const BigInteger &id6);

    friend BigInteger operator/(const BigInteger &id26,
                                const BigInteger &id6);

    friend BigInteger operator%(const BigInteger &id26,
                                const BigInteger &id6);

    BigInteger &operator+=(const BigInteger &id26);

    BigInteger &operator-=(const BigInteger &id26);

    BigInteger &operator*=(const BigInteger &id26);

    BigInteger &operator%=(const BigInteger &id26);

    BigInteger &operator/=(const BigInteger &id26);

    bool operator<(BigInteger const &id26) const;

    bool operator>(BigInteger const &id26) const;

    bool operator<=(BigInteger const &id26) const;

    bool operator>=(BigInteger const &id26) const;

    bool operator==(BigInteger const &id26) const;

    bool operator!=(BigInteger const &id26) const;

    BigInteger &operator++();

    const BigInteger operator++(int);

    BigInteger &operator--();

    const BigInteger operator--(int);

    BigInteger operator-();

    std::string toString() const;

    explicit operator bool();

    friend std::istream &operator>>(std::istream &in, BigInteger &id26);

    friend std::ostream &operator<<(std::ostream &out,
                                    const BigInteger &id26);

private:
    bool id3 = true;

    std::vector<int> digits_;

    void EraseLeadingZeros();

    bool IsZero() const;

    static void SubIfPositive(BigInteger &id26,
                              const BigInteger &id6);

    static void Sum(BigInteger &id26, const BigInteger &id6);

    BigInteger Abs() const;

    friend std::vector<int> id23(const std::vector<int> &digits_a,
                                                const std::vector<int> &digits_b);

    friend void Normalize(std::vector<int> &digits);

    friend std::vector<int> id4(const std::vector<int> &digits_a,
                                               const std::vector<int> &digits_b);

    bool DifferentSigns(const BigInteger &id26) const;
};




std::vector<int> id23(const std::vector<int> &digits_a,
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

std::vector<int> id4(const std::vector<int> &digits_a,
                                    const std::vector<int> &digits_b) {
    auto size = digits_a.size();
    std::vector<int> digits_result(2 * size);


    return id23(digits_a, digits_b);


































































}

BigInteger::BigInteger() : id3(true) {}

BigInteger::BigInteger(int id7) {
    if (id7 < 0) {
        id3 = false;
        id7 *= -1;
    } else if (id7 == 0) {
        digits_.push_back(0);
        id3 = true;
    }
    while (id7 != 0) {
        digits_.push_back(id7 % 10);
        id7 /= 10;
    }
}

BigInteger::BigInteger(const std::string &id12) {
    id3 = true;
    if (!id12.empty()) {
        for (size_t i = id12.length() - 1; i > 0; --i)
            digits_.push_back(id12[i] - '0');
        if (id12[0] == '-')
            id3 = false;
        else
            digits_.push_back(id12[0] - '0');
    }
}




BigInteger operator+(const BigInteger &id26,
                     const BigInteger &id6) {
    BigInteger id22 = id26;
    return id22 += id6;
}

BigInteger operator-(const BigInteger &id26,
                     const BigInteger &id6) {
    BigInteger id19 = id26;
    return id19 -= id6;
}

BigInteger operator*(const BigInteger &id26,
                     const BigInteger &id6) {
    BigInteger id21 = id26;
    return id21 *= id6;
}

BigInteger operator/(const BigInteger &id26,
                     const BigInteger &id6) {
    BigInteger id0 = id26;
    return id0 /= id6;
}

BigInteger operator%(const BigInteger &id26,
                     const BigInteger &id6) {
    BigInteger id11 = id26;
    return id11 %= id6;
}




BigInteger &BigInteger::operator+=(const BigInteger &id26) {
    if (!DifferentSigns(id26)) {
        Sum(*this, id26);
        return *this;
    } else {
        if (this->Abs() >= id26.Abs()) {
            SubIfPositive(*this, id26);
            return *this;
        } else {
            BigInteger id28 = *this;
            BigInteger id1 = id26;
            SubIfPositive(id1, id28);
            return *this = id1;
        }
    }
}

BigInteger &BigInteger::operator-=(const BigInteger &id26) {
    if (!DifferentSigns(id26)) {
        if (this->Abs() >= id26.Abs()) {
            SubIfPositive(*this, id26);
            return *this;
        } else {
            BigInteger id28 = *this;
            BigInteger id1 = id26;
            SubIfPositive(id1, id28);
            id1.id3 = !id1.id3;
            return *this = id1;
        }
    } else {
        Sum(*this, id26);
        return *this;
    }
}

BigInteger &BigInteger::operator*=(const BigInteger &id26) {
    size_t size = std::max(id26.digits_.size(), digits_.size());
    BigInteger id9;
    auto id1 = id26;
    id1.digits_.resize(size);
    digits_.resize(size);
    digits_ = id4(id1.digits_, digits_);
    Normalize(digits_);
    EraseLeadingZeros();
    id3 = !(DifferentSigns(id26));
    return *this;
}

BigInteger &BigInteger::operator/=(const BigInteger &id26) {
    BigInteger id9;
    id9.digits_.resize(digits_.size());
    BigInteger id10;
    for (int i = digits_.size() - 1; i >= 0; --i) {
        id10.digits_.insert(id10.digits_.begin(), 0);
        id10.EraseLeadingZeros();
        id10.digits_[0] = digits_[i];
        size_t new_digit = 0;
        size_t left = 0, right = 9;
        while (left <= right) {
            size_t middle = (left + right) / 2;
            if ((id26.Abs() * middle).Abs() <= id10.Abs()) {
                new_digit = middle;
                left = middle + 1;
            } else
                right = middle - 1;
        }
        id10 -= id26.Abs() * new_digit;
        id9.digits_[i] = new_digit;
    }

    id9.id3 = !(DifferentSigns(id26));
    id9.EraseLeadingZeros();
    *this = id9;
    return *this;
}

BigInteger &BigInteger::operator%=(const BigInteger &id26) {
    BigInteger id9;
    id9.digits_.resize(digits_.size());
    BigInteger id10;
    for (int i = digits_.size() - 1; i >= 0; --i) {
        id10.digits_.insert(id10.digits_.begin(), 0);
        id10.EraseLeadingZeros();
        id10.digits_[0] = digits_[i];
        size_t new_digit = 0;
        size_t left = 0, right = 9;
        while (left <= right) {
            size_t middle = (left + right) / 2;
            if ((id26.Abs() * middle).Abs() <= id10.Abs()) {
                new_digit = middle;
                left = middle + 1;
            } else
                right = middle - 1;
        }
        id9.digits_[i] = new_digit;
        id10 = id10 - id26.Abs() * new_digit;
    }
    id10.EraseLeadingZeros();
    id10.id3 = id3;
    if (id10.digits_.empty())
        id10.digits_.push_back(0);
    *this = id10;
    return *this;
}




bool BigInteger::operator<(BigInteger const &id26) const {
    if (IsZero() && id26.IsZero()) {
        return false;
    }
    if (DifferentSigns(id26)) {
        return !id3;
    }
    if (digits_.size() > id26.digits_.size()) {
        return !id3;
    }
    if (digits_.size() < id26.digits_.size()) {
        return id3;
    }
    for (int i = digits_.size() - 1; i >= 0; --i) {
        if (digits_[i] > id26.digits_[i]) {
            return !id3;
        }
        if (digits_[i] < id26.digits_[i]) {
            return id3;
        }
    }
    return false;
}

bool BigInteger::operator>(BigInteger const &id26) const {
    return (id26 < *this);
}

bool BigInteger::operator<=(BigInteger const &id26) const {
    return !(*this > id26);
}

bool BigInteger::operator>=(BigInteger const &id26) const {
    return !(*this < id26);
}

bool BigInteger::operator==(BigInteger const &id26) const {
    return (*this >= id26) && (*this <= id26);
}

bool BigInteger::operator!=(BigInteger const &id26) const {
    return !(*this == id26);
}




BigInteger &BigInteger::operator++() {
    *this += 1;
    return *this;
}

const BigInteger BigInteger::operator++(int) {
    BigInteger id28 = *this;
    ++(*this);
    return id28;
}

BigInteger &BigInteger::operator--() {
    *this -= 1;
    return *this;
}

const BigInteger BigInteger::operator--(int) {
    BigInteger id28 = *this;
    --(*this);
    return id28;
}




std::istream &operator>>(std::istream &in, BigInteger &id26) {
    std::string id12;
    in >> id12;
    id26 = BigInteger(id12);
    return in;
}

std::ostream &operator<<(std::ostream &out, const BigInteger &id26) {
    out << id26.toString();
    return out;
}

BigInteger BigInteger::operator-() {
    BigInteger id28 = *this;
    id28.id3 = !this->id3;
    if (IsZero()) {
        id28.id3 = true;
        id28.digits_[0] = 0;
        return id28;
    } else
        return id28;
}




std::string BigInteger::toString() const {
    std::string s = id3 ? "" : "-";
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
    BigInteger id28 = (*this);
    id28.id3 = true;
    return id28;
}

void BigInteger::EraseLeadingZeros() {
    while (!digits_.empty() && *digits_.rbegin() == 0) {
        digits_.pop_back();
    }
    if (digits_.empty()) {
        id3 = true;
        digits_.push_back(0);
    }
}

void BigInteger::SubIfPositive(BigInteger &id26,
                               const BigInteger &id6) {
    int carry = 0;
    for (size_t i = 0; i < id6.digits_.size() || carry; ++i) {
        if (i < id6.digits_.size()) {
            id26.digits_[i] -= carry + id6.digits_[i];
        } else {
            id26.digits_[i] -= carry;
        }
        carry = (id26.digits_[i] < 0);
        if (carry != 0) id26.digits_[i] += 10;
    }
    id26.EraseLeadingZeros();
}

void BigInteger::Sum(BigInteger &id26,
                     const BigInteger &id6) {
    int carry = 0;
    for (size_t i = 0; i < id26.digits_.size() ||
                       i < id6.digits_.size() || carry;
         ++i) {
        if (i == id26.digits_.size()) {
            id26.digits_.push_back(0);
        }
        if (i < id6.digits_.size()) {
            id26.digits_[i] += carry + id6.digits_[i];
        } else {
            id26.digits_[i] += carry;
        }
        carry = id26.digits_[i] / 10;
        id26.digits_[i] %= 10;
    }
    id26.EraseLeadingZeros();
}

bool BigInteger::IsZero() const {
    return digits_[0] == 0 && digits_.size() == 1;
}

bool BigInteger::DifferentSigns(const BigInteger &id26) const {
    return id3 ^ id26.id3;
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

vector<ll> id16, id2, id13, id25;
vector<char> id14;

void id27(const graph &g, ll v, ll h = 1) {
    id14[v] = true;
    id16[v] = h;
    id2.push_back(v);
    for (auto i = g[v].begin(); i != g[v].end(); ++i)
        if (!id14[*i]) {
            id27(g, *i, h + 1);
            id2.push_back(v);
        }
}

void id8(ll i, ll l, ll r) {
    if (l == r)
        id25[i] = id2[l];
    else {
        ll m = (l + r) >> 1;
        id8(i + i, l, m);
        id8(i + i + 1, m + 1, r);
        if (id16[id25[i + i]] < id16[id25[i + i + 1]])
            id25[i] = id25[i + i];
        else
            id25[i] = id25[i + i + 1];
    }
}

void id5(const graph &g, ll root) {
    ll n = (ll) g.size();
    id16.resize(n);
    id2.reserve(n * 2);
    id14.assign(n, 0);

    id27(g, root);

    ll m = (ll) id2.size();
    id25.assign(id2.size() * 4 + 1, -1);
    id8(1, 0, m - 1);

    id13.assign(n, -1);
    for (ll i = 0; i < m; ++i) {
        ll v = id2[i];
        if (id13[v] == -1)
            id13[v] = i;
    }
}

ll id24(ll i, ll sl, ll sr, ll l, ll r) {
    if (sl == l && sr == r)
        return id25[i];
    ll sm = (sl + sr) >> 1;
    if (r <= sm)
        return id24(i + i, sl, sm, l, r);
    if (l > sm)
        return id24(i + i + 1, sm + 1, sr, l, r);
    ll ans1 = id24(i + i, sl, sm, l, sm);
    ll ans2 = id24(i + i + 1, sm + 1, sr, sm + 1, r);
    return id16[ans1] < id16[ans2] ? ans1 : ans2;
}

ll lca(ll a, ll b) {
    ll left = id13[a],
            right = id13[b];
    if (left > right) swap(left, right);
    return id24(1, 0, (ll) id2.size() - 1, left, right);
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
        return ((a % mod) * x) % mod;
    }

}

void id18(const ll n, const ll mod, vector<ll> &F) {
    F.resize(n + 1);
    F[0] = 1;
    for (ll i = 1; i <= n; ++i) {
        F[i] = (F[i - 1] * i) % mod;
    }
}

void id17(const ll n, const ll mod, vector<ll> &F, vector<ll> &I) {
    id18(n, mod, F);
    I.resize(n + 1);
    I[0] = 1;
    for (ll i = 1; i <= n; ++i) {
        I[i] = fast_power(F[i], mod - 2, mod);
    }
}

ll id20(ll n, ll k, ll mod, vector<ll> &F, vector<ll> &I) {
    return (((F[n] * I[k]) % mod) * I[n - k]) % mod;
}

ll id15(ll n, ll k, ll mod, vector<ll> &F, vector<ll> &I) {
    return id20(n + k - 1, k - 1, mod, F, I);
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
    return min(x, y);
}

void update(segmentTreeNode<ll, ll> &node, ll x) {
    node.val += x;
}


int main() {
    ll tests;
    cin >> tests;
    while (tests--) {
        ll n;
        cin >> n;
        ll s;
        cin >> s;
        vector<ll> v(n);
        for (auto &t: v) {
            cin >> t;
        }
        ll l = 0;
        ll r = n;
        ll m = l + (r - l) / 2;
        ll best_m = 0;
        ll f, t;
        while (l <= r) {
            bool good = false;
            ll i, j;
            i = 0;
            j = 0;
            ll cur = 0;
            while (i < n) {
                while (j < n && cur - v[j] <= s) {
                    cur -= v[j];
                    ++j;
                }
                if (j - i >= m) {
                    good = true;
                    f = i;
                    t = j;
                    break;
                }
                if (j < n) {
                    if (i == j) {
                        ++i;
                        ++j;
                    }
                    while (i < j) {
                        cur += v[i];
                        ++i;

                        if (cur - v[j] <= s) {
                            break;
                        }
                    }

                } else {
                    break;
                }
            }

            if (good) {
                best_m = m;
                l = m + 1;
                m = l + (r - l) / 2;
            } else {
                r = m - 1;
                m = l + (r - l) / 2;
            }
        }
        if (best_m == 0) {
            cout << -1 << endl;
        } else {
            cout << f + 1 << sep << t << endl;
        }
    }
}


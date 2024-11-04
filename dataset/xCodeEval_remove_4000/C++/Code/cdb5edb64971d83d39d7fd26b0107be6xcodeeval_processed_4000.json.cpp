





















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

    BigInteger(int id7);

    BigInteger(const std::string &id13);

    friend BigInteger operator+(const BigInteger &id28,
                                const BigInteger &id6);

    friend BigInteger operator-(const BigInteger &id28,
                                const BigInteger &id6);

    friend BigInteger operator*(const BigInteger &id28,
                                const BigInteger &id6);

    friend BigInteger operator/(const BigInteger &id28,
                                const BigInteger &id6);

    friend BigInteger operator%(const BigInteger &id28,
                                const BigInteger &id6);

    BigInteger &operator+=(const BigInteger &id28);

    BigInteger &operator-=(const BigInteger &id28);

    BigInteger &operator*=(const BigInteger &id28);

    BigInteger &operator%=(const BigInteger &id28);

    BigInteger &operator/=(const BigInteger &id28);

    bool operator<(BigInteger const &id28) const;

    bool operator>(BigInteger const &id28) const;

    bool operator<=(BigInteger const &id28) const;

    bool operator>=(BigInteger const &id28) const;

    bool operator==(BigInteger const &id28) const;

    bool operator!=(BigInteger const &id28) const;

    BigInteger &operator++();

    const BigInteger operator++(int);

    BigInteger &operator--();

    const BigInteger operator--(int);

    BigInteger operator-();

    std::string toString() const;

    explicit operator bool();

    friend std::istream &operator>>(std::istream &in, BigInteger &id28);

    friend std::ostream &operator<<(std::ostream &out,
                                    const BigInteger &id28);

private:
    bool id3 = true;

    std::vector<int> digits_;

    void EraseLeadingZeros();

    bool IsZero() const;

    static void SubIfPositive(BigInteger &id28,
                              const BigInteger &id6);

    static void Sum(BigInteger &id28, const BigInteger &id6);

    BigInteger Abs() const;

    friend std::vector<int> id25(const std::vector<int> &digits_a,
                                                const std::vector<int> &digits_b);

    friend void Normalize(std::vector<int> &digits);

    friend std::vector<int> id4(const std::vector<int> &digits_a,
                                               const std::vector<int> &digits_b);

    bool DifferentSigns(const BigInteger &id28) const;
};




std::vector<int> id25(const std::vector<int> &digits_a,
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


    return id25(digits_a, digits_b);


































































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

BigInteger::BigInteger(const std::string &id13) {
    id3 = true;
    if (!id13.empty()) {
        for (size_t i = id13.length() - 1; i > 0; --i)
            digits_.push_back(id13[i] - '0');
        if (id13[0] == '-')
            id3 = false;
        else
            digits_.push_back(id13[0] - '0');
    }
}




BigInteger operator+(const BigInteger &id28,
                     const BigInteger &id6) {
    BigInteger id24 = id28;
    return id24 += id6;
}

BigInteger operator-(const BigInteger &id28,
                     const BigInteger &id6) {
    BigInteger id21 = id28;
    return id21 -= id6;
}

BigInteger operator*(const BigInteger &id28,
                     const BigInteger &id6) {
    BigInteger id23 = id28;
    return id23 *= id6;
}

BigInteger operator/(const BigInteger &id28,
                     const BigInteger &id6) {
    BigInteger id0 = id28;
    return id0 /= id6;
}

BigInteger operator%(const BigInteger &id28,
                     const BigInteger &id6) {
    BigInteger id12 = id28;
    return id12 %= id6;
}




BigInteger &BigInteger::operator+=(const BigInteger &id28) {
    if (!DifferentSigns(id28)) {
        Sum(*this, id28);
        return *this;
    } else {
        if (this->Abs() >= id28.Abs()) {
            SubIfPositive(*this, id28);
            return *this;
        } else {
            BigInteger id30 = *this;
            BigInteger id1 = id28;
            SubIfPositive(id1, id30);
            return *this = id1;
        }
    }
}

BigInteger &BigInteger::operator-=(const BigInteger &id28) {
    if (!DifferentSigns(id28)) {
        if (this->Abs() >= id28.Abs()) {
            SubIfPositive(*this, id28);
            return *this;
        } else {
            BigInteger id30 = *this;
            BigInteger id1 = id28;
            SubIfPositive(id1, id30);
            id1.id3 = !id1.id3;
            return *this = id1;
        }
    } else {
        Sum(*this, id28);
        return *this;
    }
}

BigInteger &BigInteger::operator*=(const BigInteger &id28) {
    size_t size = std::max(id28.digits_.size(), digits_.size());
    BigInteger id10;
    auto id1 = id28;
    id1.digits_.resize(size);
    digits_.resize(size);
    digits_ = id4(id1.digits_, digits_);
    Normalize(digits_);
    EraseLeadingZeros();
    id3 = !(DifferentSigns(id28));
    return *this;
}

BigInteger &BigInteger::operator/=(const BigInteger &id28) {
    BigInteger id10;
    id10.digits_.resize(digits_.size());
    BigInteger id11;
    for (int i = digits_.size() - 1; i >= 0; --i) {
        id11.digits_.insert(id11.digits_.begin(), 0);
        id11.EraseLeadingZeros();
        id11.digits_[0] = digits_[i];
        size_t new_digit = 0;
        size_t left = 0, right = 9;
        while (left <= right) {
            size_t middle = (left + right) / 2;
            if ((id28.Abs() * middle).Abs() <= id11.Abs()) {
                new_digit = middle;
                left = middle + 1;
            } else
                right = middle - 1;
        }
        id11 -= id28.Abs() * new_digit;
        id10.digits_[i] = new_digit;
    }

    id10.id3 = !(DifferentSigns(id28));
    id10.EraseLeadingZeros();
    *this = id10;
    return *this;
}

BigInteger &BigInteger::operator%=(const BigInteger &id28) {
    BigInteger id10;
    id10.digits_.resize(digits_.size());
    BigInteger id11;
    for (int i = digits_.size() - 1; i >= 0; --i) {
        id11.digits_.insert(id11.digits_.begin(), 0);
        id11.EraseLeadingZeros();
        id11.digits_[0] = digits_[i];
        size_t new_digit = 0;
        size_t left = 0, right = 9;
        while (left <= right) {
            size_t middle = (left + right) / 2;
            if ((id28.Abs() * middle).Abs() <= id11.Abs()) {
                new_digit = middle;
                left = middle + 1;
            } else
                right = middle - 1;
        }
        id10.digits_[i] = new_digit;
        id11 = id11 - id28.Abs() * new_digit;
    }
    id11.EraseLeadingZeros();
    id11.id3 = id3;
    if (id11.digits_.empty())
        id11.digits_.push_back(0);
    *this = id11;
    return *this;
}




bool BigInteger::operator<(BigInteger const &id28) const {
    if (IsZero() && id28.IsZero()) {
        return false;
    }
    if (DifferentSigns(id28)) {
        return !id3;
    }
    if (digits_.size() > id28.digits_.size()) {
        return !id3;
    }
    if (digits_.size() < id28.digits_.size()) {
        return id3;
    }
    for (int i = digits_.size() - 1; i >= 0; --i) {
        if (digits_[i] > id28.digits_[i]) {
            return !id3;
        }
        if (digits_[i] < id28.digits_[i]) {
            return id3;
        }
    }
    return false;
}

bool BigInteger::operator>(BigInteger const &id28) const {
    return (id28 < *this);
}

bool BigInteger::operator<=(BigInteger const &id28) const {
    return !(*this > id28);
}

bool BigInteger::operator>=(BigInteger const &id28) const {
    return !(*this < id28);
}

bool BigInteger::operator==(BigInteger const &id28) const {
    return (*this >= id28) && (*this <= id28);
}

bool BigInteger::operator!=(BigInteger const &id28) const {
    return !(*this == id28);
}




BigInteger &BigInteger::operator++() {
    *this += 1;
    return *this;
}

const BigInteger BigInteger::operator++(int) {
    BigInteger id30 = *this;
    ++(*this);
    return id30;
}

BigInteger &BigInteger::operator--() {
    *this -= 1;
    return *this;
}

const BigInteger BigInteger::operator--(int) {
    BigInteger id30 = *this;
    --(*this);
    return id30;
}




std::istream &operator>>(std::istream &in, BigInteger &id28) {
    std::string id13;
    in >> id13;
    id28 = BigInteger(id13);
    return in;
}

std::ostream &operator<<(std::ostream &out, const BigInteger &id28) {
    out << id28.toString();
    return out;
}

BigInteger BigInteger::operator-() {
    BigInteger id30 = *this;
    id30.id3 = !this->id3;
    if (IsZero()) {
        id30.id3 = true;
        id30.digits_[0] = 0;
        return id30;
    } else
        return id30;
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
    BigInteger id30 = (*this);
    id30.id3 = true;
    return id30;
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

void BigInteger::SubIfPositive(BigInteger &id28,
                               const BigInteger &id6) {
    int carry = 0;
    for (size_t i = 0; i < id6.digits_.size() || carry; ++i) {
        if (i < id6.digits_.size()) {
            id28.digits_[i] -= carry + id6.digits_[i];
        } else {
            id28.digits_[i] -= carry;
        }
        carry = (id28.digits_[i] < 0);
        if (carry != 0) id28.digits_[i] += 10;
    }
    id28.EraseLeadingZeros();
}

void BigInteger::Sum(BigInteger &id28,
                     const BigInteger &id6) {
    int carry = 0;
    for (size_t i = 0; i < id28.digits_.size() ||
                       i < id6.digits_.size() || carry;
         ++i) {
        if (i == id28.digits_.size()) {
            id28.digits_.push_back(0);
        }
        if (i < id6.digits_.size()) {
            id28.digits_[i] += carry + id6.digits_[i];
        } else {
            id28.digits_[i] += carry;
        }
        carry = id28.digits_[i] / 10;
        id28.digits_[i] %= 10;
    }
    id28.EraseLeadingZeros();
}

bool BigInteger::IsZero() const {
    return digits_[0] == 0 && digits_.size() == 1;
}

bool BigInteger::DifferentSigns(const BigInteger &id28) const {
    return id3 ^ id28.id3;
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

vector<ll> id18, id2, id15, id27;
vector<char> id16;

void id29(const graph &g, ll v, ll h = 1) {
    id16[v] = true;
    id18[v] = h;
    id2.push_back(v);
    for (auto i = g[v].begin(); i != g[v].end(); ++i)
        if (!id16[*i]) {
            id29(g, *i, h + 1);
            id2.push_back(v);
        }
}

void id9(ll i, ll l, ll r) {
    if (l == r)
        id27[i] = id2[l];
    else {
        ll m = (l + r) >> 1;
        id9(i + i, l, m);
        id9(i + i + 1, m + 1, r);
        if (id18[id27[i + i]] < id18[id27[i + i + 1]])
            id27[i] = id27[i + i];
        else
            id27[i] = id27[i + i + 1];
    }
}

void id5(const graph &g, ll root) {
    ll n = (ll) g.size();
    id18.resize(n);
    id2.reserve(n * 2);
    id16.assign(n, 0);

    id29(g, root);

    ll m = (ll) id2.size();
    id27.assign(id2.size() * 4 + 1, -1);
    id9(1, 0, m - 1);

    id15.assign(n, -1);
    for (ll i = 0; i < m; ++i) {
        ll v = id2[i];
        if (id15[v] == -1)
            id15[v] = i;
    }
}

ll id26(ll i, ll sl, ll sr, ll l, ll r) {
    if (sl == l && sr == r)
        return id27[i];
    ll sm = (sl + sr) >> 1;
    if (r <= sm)
        return id26(i + i, sl, sm, l, r);
    if (l > sm)
        return id26(i + i + 1, sm + 1, sr, l, r);
    ll ans1 = id26(i + i, sl, sm, l, sm);
    ll ans2 = id26(i + i + 1, sm + 1, sr, sm + 1, r);
    return id18[ans1] < id18[ans2] ? ans1 : ans2;
}

ll lca(ll a, ll b) {
    ll left = id15[a],
            right = id15[b];
    if (left > right) swap(left, right);
    return id26(1, 0, (ll) id2.size() - 1, left, right);
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

void id20(const ll n, const ll mod, vector<ll> &F) {
    F.resize(n + 1);
    F[0] = 1;
    for (ll i = 1; i <= n; ++i) {
        F[i] = (F[i - 1] * i) % mod;
    }
}

void id19(const ll n, const ll mod, vector<ll> &F, vector<ll> &I) {
    id20(n, mod, F);
    I.resize(n + 1);
    I[0] = 1;
    for (ll i = 1; i <= n; ++i) {
        I[i] = fast_power(F[i], mod - 2, mod);
    }
}

ll id22(ll n, ll k, ll mod, vector<ll> &F, vector<ll> &I) {
    return (((F[n] * I[k]) % mod) * I[n - k]) % mod;
}

ll id17(ll n, ll k, ll mod, vector<ll> &F, vector<ll> &I) {
    return id22(n + k - 1, k - 1, mod, F, I);
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
        vector<ll> id8(n + 1, -1);
        id8[pos_x] = 0;
        Q.push(pos_x);
        while (!Q.empty()) {
            auto x = Q.front();
            Q.pop();
            for (auto &t : E[x]) {
                if (id8[t] == -1) {
                    id8[t] = id8[x] + 1;
                    Q.push(t);
                }
            }
        }
        cout << "?" << sep << std::count(id8.begin(), id8.end(), distance) << sep;
        for (int i = 1; i <= n; ++i) {
            if (id8[i] == distance) {
                cout << i << sep;
            }
        }
        cout << endl;
        ll gx, gd;
        cin >> gx >> gd;
        cout << "!" << sep << pos_x << sep << gx << endl;
        string id14;
        cin >> id14;
    }
}






























                        

                        





template <typename It>
struct iter_range : std::pair<It, It> {
    typedef std::pair<It, It> base_t;
    typedef It iterator;
    using base_t::base_t;
    It begin() { return base_t::first; }
    It end() { return base_t::second; }
};
template <typename It>
iter_range<std::reverse_iterator<It>> rev(const iter_range<It> &origin) {
    using rev_t = std::reverse_iterator<It>;
    return {rev_t(origin.second), rev_t(origin.first)};
}


template <typename Int = int>
struct int_iter {
    Int i;
    explicit int_iter(Int i = 0) : i(i) { }
    Int operator*() const { return i; }
    int_iter &operator++() { ++i; return *this; }
    int_iter &operator--() { --i; return *this; }
    int_iter operator+(Int step) const { return int_iter(i + step); }
    int_iter operator-(Int step) const { return int_iter(i - step); }
    Int operator-(const int_iter &that) const { return i - that.i; }
    int_iter &operator+=(Int step) { i += step; return *this; }
    int_iter &operator-=(Int step) { i -= step; return *this; }
    bool operator==(const int_iter &that) const { return  i == that.i; }
    bool operator!=(const int_iter &that) const { return !(*this == that); }
    Int operator[](Int n) { return i + n; }
    typedef Int difference_type;
    typedef Int value_type;
    typedef Int *pointer;
    typedef Int reference; 

    typedef std::random_access_iterator_tag iterator_category;
};
template <typename Int = int>
using int_range = iter_range<int_iter<Int>>;
template <typename Int>
int_range<Int> range(Int b, Int e) { return {int_iter<Int>(b), int_iter<Int>(e > b ? e : b)}; }
template <typename Int>
int_range<Int> range(Int n) { return range(Int(), n); }
template <typename Int>
int_range<Int> nrange(Int n) { return range(Int(1), Int(n+1)); }
template <typename Int>
int_range<Int> inrange(Int b, Int e) { return range(b, Int(e + 1)); }
using namespace std;    








template <typename T>
bool chmax(T &m, const T &v) { if (v > m) return m = v, true; return false; }
template <typename T>
bool chmin(T &m, const T &v) { if (v < m) return m = v, true; return false; }
template <typename T>
T max_s(const T &v) { return v; }
template <typename T, typename... Args>
T max_s(const T &v1, const T &v2, Args... arg) {
    return max_s(max(v1, v2), arg...);
}
template <typename T>
T min_s(const T &v) { return v; }
template <typename T, typename... Args>
T min_s(const T &v1, const T &v2, Args... arg) {
    return min_s(min(v1, v2), arg...);
}
static const int id7 = INT32_MAX / 2;
static const int id9 = -id7;
static const int64_t id23 = INT64_MAX / 2;
static const int64_t id12 = -id23;
void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
stringstream line_stream() {
    string str;
    getline(cin, str);
    return stringstream(str);
}










template <typename Int>
Int gcd(Int a, Int b) {
    while (a != 0) {
        b %= a;
        if (b == 0)
            return a;
        a %= b;
    }
    return b;
}
template <typename Int, typename RInt = Int>
Int lcm(Int a, Int b) {
    return a / gcd(a, b) * static_cast<RInt>(b);
}
template <typename Int, typename XInt>
Int id16(Int a, Int b, XInt &x, XInt &y) {
    static_assert(std::numeric_limits<XInt>::is_signed,
            "x, y must be signed");
    

    

    

    

    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    
    Int g = id16(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
}
template <typename Int, typename TInt = int64_t>
Int mul_mod(Int a, Int b, Int m) {
    TInt p = a;
    p = (p * b) % m;
    return (Int)p;
}
template <typename Int, typename PInt, typename TInt = int64_t>
Int pow_mod(Int a, PInt p, Int m) {
    Int r;
    a %= m;
    for (r = 1; p; p >>= 1) {
        if (p & 1) r = mul_mod(r, a, m);
        a = mul_mod(a, a, m);
    }
    return r;
}
template <typename Int,
          typename XInt = typename std::make_signed<Int>::type>
Int inv_mod(Int a, Int m) {
    

    XInt x, y;
    id16(a, m, x, y);
    if (x < 0)
        return x + m;
    return x;
}
template <typename Int>
Int id14(Int u, Int v, Int m) {
    Int r = u + v;
    if (r >= m) r -= m;
    return r;
}
template <typename Int>
Int id11(Int u, Int v, Int m) {
    Int r = u - v;
    if (r < 0) r += m;
    return r;
}
template <typename Int>
Int div_mod(Int u, Int v, Int m) {
    

    

    

    

    

    

    

    

    

    Int g = gcd(v, m);
    assert(u % g == 0);
    Int mm = m / g;
    return mul_mod(u / g, inv_mod(v / g, mm), mm);
}
template <typename Int>
Int id0(Int a, Int b, Int &r) {
    

    

    

    

    

    

    

    Int q = a / b;
    r = a % b;
    if (r < 0) {
        if (b < 0)
            q += 1, r -= b;
        else
            q -= 1, r += b;
    }
    return q;
}


















struct id13 {
    std::vector<int> fact;
    std::vector<int> inv;
    std::vector<int> inv_fact;
    int mod;
    id13(int n, int mod) : mod(mod) {
        fact.resize(n + 1);
        inv.resize(n + 1);
        inv_fact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = mul_mod(fact[i - 1], i, mod);
        

        

        

        

        inv[1] = 1;
        for (int i = 2; i <= n; ++i) 

            inv[i] = mod - mul_mod(mod / i, inv[mod % i], mod);
        inv_fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            inv_fact[i] = mul_mod(inv_fact[i - 1], inv[i], mod);
    }
    int operator()(int n) { return fact[n]; }
    int A(int n, int m) {
        return mul_mod(fact[n], inv_fact[n - m], mod);
    }
    int C(int n, int m) {
        if (m > n || n < 0 || m < 0) return 0;
        return mul_mod(A(n, m), inv_fact[m], mod);
    }
    int H(int n, int m) {
        return C(n + m - 1, m);
    }
    int T(int r1, int r2) {
        return C(r1 + r2, r1);
    }
};









template <typename P, typename M, M P::*field>
struct intrusive_helper {
    typedef P parent_type;
    typedef M member_type;
    static constexpr M P::*field_v = field;
    static uintptr_t get_offset() {
        P *parent = nullptr;
        M *member = &(parent->*field);
        return reinterpret_cast<uintptr_t>(member);
    }
    static M *to_member(P *p) { return &(p->*field); }
    static P *to_parent(M *m) {
        uintptr_t mm = reinterpret_cast<uintptr_t>(m);
        return reinterpret_cast<P *>(mm - get_offset());
    }
};
template <typename T>
struct identity_accessor {
    const T &operator() (const T &x) const { return x; }
};
template <typename P, typename M, M P::*field>
struct key_accessor {
    const M &operator() (const P &p) const { return p.*field; }
};








template <typename Head>
Head *id8(Head *x) {
    while (x && x->lc)
        x = x->lc;
    return x;
}
template <typename Head>
Head *id10(Head *x) {
    while (x && x->rc)
        x = x->rc;
    return x;
}
template <typename Head>
Head *bst_prev(Head *x) {
    if (x->lc) return id10(x->lc);
    Head *p = x->p;
    while (p && x == p->lc) {
        x = p;
        p = p->p;
    }
    return p;
}
template <typename Head>
Head *id4(Head *x) {
    if (x->rc) return id8(x->rc);
    Head *p = x->p;
    while (p && x == p->rc) {
        x = p;
        p = p->p;
    }
    return p;
}
template <typename Head>
void bst_rotate(Head *x) {
    Head *y = x->p, *z = y->p;
    Head *b = (x == y->lc) ? x->rc : x->lc;
    x->p = z, y->p = x;
    if (b) b->p = y;
    if (z) (z->lc == y ? z->lc : z->rc) = x;
    if (x == y->lc) x->rc = y, y->lc = b;
    else x->lc = y, y->rc = b;
}
template <typename Helper, typename Head, typename Key,
          typename Accessor, typename Comp>
Head *id20(Head *root, Key &&k, Accessor &&acc, Comp &&comp) {
    Head *x = nullptr;
    while (root) {
        if (comp(acc(*Helper::to_parent(root)), k)) {
            root = root->rc;
        } else {
            x = root;
            root = root->lc;
        }
    }
    return x;
}
template <typename Helper, typename Head, typename Key,
          typename Accessor, typename Comp>
Head *id5(Head *root, Key &&k, Accessor &&acc, Comp &&comp) {
    Head *x = nullptr;
    while (root) {
        if (comp(k, acc(*Helper::to_parent(root)))) {
            x = root;
            root = root->lc;
        } else {
            root = root->rc;
        }
    }
    return x;
}






template <typename Helper>
struct bst_iterator {
    typedef typename Helper::member_type head_type;
    typedef head_type *head_ptr;
    

    typedef typename Helper::parent_type value_type;
    typedef value_type *pointer;
    typedef value_type &reference;
    typedef std::bidirectional_iterator_tag iterator_category;
    head_ptr cur;
    bst_iterator() { cur = nullptr; }
    explicit bst_iterator(head_ptr head) { cur = head; }
    explicit bst_iterator(head_type &head) { cur = &head; }
    explicit bst_iterator(value_type *value) { cur = Helper::to_member(value); }
    explicit operator bool() {
        return cur;
    }
    bst_iterator &operator++() {
        if (!cur) throw 0;
        cur = id4(cur);
        return *this;
    }
    bst_iterator operator++(int) const {
        bst_iterator that(*this);
        ++(*this);
        return that;
    }
    bst_iterator &operator--() {
        if (!cur) throw 0;
        cur = bst_prev(cur);
        return *this;
    }
    bst_iterator operator--(int) const {
        bst_iterator that(*this);
        --(*this);
        return that;
    }
    pointer ptr() const {
        return Helper::to_parent(cur);
    }
    pointer operator->() const {
        return ptr();
    }
    reference operator*() const {
        return *operator->();
    }
    bool operator==(const bst_iterator& that) {
        return cur == that.cur;
    }
    bool operator!=(const bst_iterator& that) {
        return !(*this == that);
    }
};




struct id21 {
    id21 *lc, *rc, *p;
    int size;
    id21() { reset(); }
    id21(const id21 &that) = delete;
    void reset() {
        lc = rc = p = nullptr;
        size = 1;
    }
    void update_size() {
        size = 1;
        if (lc) size += lc->size;
        if (rc) size += rc->size;
    }
};
static inline void id3(id21 *x) { 

    id21 *y = x->p;
    bst_rotate(x);
    y->update_size();
}
static inline void id1(id21 *&root, id21 *x, id21 *target) {
    while (x->p != target) {
        if (x->p->p != target) {
            if ((x->p->lc == x) == (x->p->p->lc == x->p))
                id3(x->p);
            else
                id3(x);
        }
        id3(x);
    }
    x->update_size();
    if (!target)
        root = x;
}
static inline void id6(id21 *&root, id21 *x, id21 *y) {
    

    if (!y) {
        x->lc = root;
        if (root) root->p = x;
        root = x;
        x->update_size();
    } else {
        id1(root, y, nullptr);
        if (!y->lc)
            y->lc = x, x->p = y, y->update_size();
        else {
            id21 *prev = id10(y->lc);
            id1(root, prev, y);
            prev->rc = x;
            x->p = prev;
            prev->update_size();
            y->update_size();
        }
    }
}
static inline void id22(id21 *&root, id21 *x) {
    id1(root, x, nullptr);
    if (!x->lc) {
        if (x->rc) x->rc->p = nullptr;
        root = x->rc;
    } else {
        id21 *prev = id10(x->lc);
        id1(root, prev, x);
        prev->rc = x->rc;
        if (x->rc) x->rc->p = prev;
        prev->update_size();
        prev->p = nullptr, root = prev;
    }
    x->reset();
}


static inline int id19(id21 *&root, id21 *x) {
    if (!x) return root ? root->size : 0; 

    id1(root, x, nullptr);
    return x->lc ? x->lc->size : 0;
}
static inline id21 *id2(id21 *&root, int k) {
    id21 *p = root;
    while (true) {
        int lsize = p->lc ? p->lc->size : 0;
        if (k < lsize)
            p = p->lc;
        else if (k == lsize)
            return p;
        else
            k -= lsize + 1, p = p->rc;
    }
    return p;
}
static inline id21 *id18(id21 *&root, int k) {
    if (!root || k >= root->size) return nullptr;
    id21 *p = id2(root, k);
    id1(root, p, nullptr);
    return p;
}
template <typename T, id21 T::*field>
struct id15 {
    typedef intrusive_helper<T, id21, field> helper_type;
    typedef T value_type;
    typedef bst_iterator<helper_type> iterator_type;
    id21 *root = nullptr;
    id15() { }
    id15(const id15 &that) = delete;
    int size() {
        return root ? root->size : 0;
    }
    iterator_type begin() const {
        return iterator_type(id8(root));
    }
    iterator_type end() const {
        return iterator_type();
    }
    iterator_type find_nth(int k) {
        return iterator_type(id18(root, k)); 

    }
    int get_rank(iterator_type it) {
        return id19(root, it.cur);
    }
    iterator_type insert_front(T *node) {
        id21 *x = helper_type::to_member(node);
        x->rc = root;
        if (root) root->p = x;
        root = x;
        x->update_size();
        return iterator_type(x);
    }
    iterator_type insert_back(T *node) {
        id21 *x = helper_type::to_member(node);
        x->lc = root;
        if (root) root->p = x;
        root = x;
        x->update_size();
        return iterator_type(x);
    }
    iterator_type insert_nth(T *node, int k) {
        if (k == 0) return insert_front(node);
        else if (k < size()) {
            id21 *x = helper_type::to_member(node);
            id21 *y = id2(root, k); 

            id6(root, x, y); 

            return iterator_type(x);
        } else if (k == size()) return insert_back(node);
        else throw 0;
    }
    iterator_type erase(iterator_type it) {
        iterator_type next = it;
        ++next;
        id22(root, it.cur);
        return next;
    }
};
template <typename T, id21 T::*field, typename Key = T, typename Accessor=identity_accessor<Key>,
          typename Comp = std::less<Key>>
struct id17 {
    typedef intrusive_helper<T, id21, field> helper_type;
    typedef T value_type;
    typedef Key key_type;
    typedef bst_iterator<helper_type> iterator_type;
    Accessor acc;
    Comp comp;
    id21 *root = nullptr;
    id17() { }
    id17(const id17 &that) = delete;
    int size() const {
        return root ? root->size : 0;
    }
    iterator_type begin() const {
        return iterator_type(id8(root));
    }
    iterator_type end() const {
        return iterator_type();
    }
    iterator_type find_nth(int k) {
        return iterator_type(id18(root, k)); 

    }
    int get_rank(iterator_type it) {
        return id19(root, it.cur);
    }
    iterator_type erase(iterator_type it) {
        iterator_type next = it;
        ++next;
        id22(root, it.cur);
        return next;
    }
    iterator_type find(const key_type &k) {
        id21 *x = id20<helper_type>(root, k, acc, comp);
        if (x) id1(root, x, nullptr);
        if (x && !comp(k, acc(*helper_type::to_parent(x))))
            return iterator_type(x);
        return iterator_type();
    }
    iterator_type lower_bound(const key_type &k) {
        id21 *x = id20<helper_type>(root, k, acc, comp);
        if (x) id1(root, x, nullptr);
        return iterator_type(x);
    }
    iterator_type upper_bound(const key_type &k) {
        id21 *x = id5<helper_type>(root, k, acc, comp);
        if (x) id1(root, x, nullptr);
        return iterator_type(x);
    }
    iterator_type insert(T *node) {
        id21 *x = helper_type::to_member(node);
        id21 *y = id20<helper_type>(root, acc(*node), acc, comp);
        id6(root, x, y);
        return iterator_type(x);
    }
};

































static const int maxn = 2000005;
int n;
int b[maxn];
int main() {
    scanf("%d", &n);
    int off = 0;
    for (int i = 0; i < n; ++i)
        b[i + off] = i + 1;
    for (int t = 2; t <= n; ++t) {
        int k = (n - 1) / t; 

        for (int i = k; i >= 0; --i) {
            int r = min(t, n - i * t); 

            pr_debug("t=%d k=%d i=%d r=%d\n", t, k, i, r);
            b[i * t + r + off] = b[i * t + off];
        }
        ++off;
        for (int i : range(n))
            pr_debug("%d ", b[i + off]);
        pr_debug("\n");
    }
    for (int i : range(n))
        printf("%d ", b[i + off]);
    printf("\n");
    return 0;
}

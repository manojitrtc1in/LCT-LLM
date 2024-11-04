


























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
Head *id14(Head *x) {
    while (x && x->lc)
        x = x->lc;
    return x;
}
template <typename Head>
Head *id6(Head *x) {
    while (x && x->rc)
        x = x->rc;
    return x;
}
template <typename Head>
Head *bst_prev(Head *x) {
    if (x->lc) return id6(x->lc);
    Head *p = x->p;
    while (p && x == p->lc) {
        x = p;
        p = p->p;
    }
    return p;
}
template <typename Head>
Head *id2(Head *x) {
    if (x->rc) return id14(x->rc);
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
Head *id10(Head *root, Key &&k, Accessor &&acc, Comp &&comp) {
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
Head *id3(Head *root, Key &&k, Accessor &&acc, Comp &&comp) {
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
    explicit bst_iterator(value_type *value) { cur = Helper::to_member(value); }
    explicit operator bool() {
        return cur;
    }
    bst_iterator &operator++() {
        if (!cur) throw 0;
        cur = id2(cur);
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




struct id11 {
    id11 *lc, *rc, *p;
    int size;
    id11() { reset(); }
    id11(const id11 &that) = delete;
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
static inline void id12(id11 *x) { 

    id11 *y = x->p;
    bst_rotate(x);
    y->update_size();
}
static inline void id5(id11 *&root, id11 *x, id11 *target) {
    while (x->p != target) {
        if (x->p->p != target) {
            if ((x->p->lc == x) == (x->p->p->lc == x->p))
                id12(x->p);
            else
                id12(x);
        }
        id12(x);
    }
    x->update_size();
    if (!target)
        root = x;
}
static inline void id4(id11 *&root, id11 *x, id11 *y) {
    

    if (!y) {
        x->lc = root;
        if (root) root->p = x;
        root = x;
        x->update_size();
    } else {
        id5(root, y, nullptr);
        if (!y->lc)
            y->lc = x, x->p = y, y->update_size();
        else {
            id11 *prev = id6(y->lc);
            id5(root, prev, y);
            prev->rc = x;
            x->p = prev;
            prev->update_size();
            y->update_size();
        }
    }
}
static inline void id13(id11 *&root, id11 *x) {
    id5(root, x, nullptr);
    if (!x->lc) {
        if (x->rc) x->rc->p = nullptr;
        root = x->rc;
    } else {
        id11 *prev = id6(x->lc);
        id5(root, prev, x);
        prev->rc = x->rc;
        if (x->rc) x->rc->p = prev;
        prev->update_size();
        prev->p = nullptr, root = prev;
    }
    x->reset();
}


static inline int id9(id11 *&root, id11 *x) {
    if (!x) return root ? root->size : 0; 

    id5(root, x, nullptr);
    return x->lc ? x->lc->size : 0;
}
static inline id11 *id7(id11 *&root, int k) {
    id11 *p = root;
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
static inline id11 *id8(id11 *&root, int k) {
    id11 *p = id7(root, k);
    id5(root, p, nullptr);
    return p;
}
template <typename T, id11 T::*field>
struct id0 {
    typedef intrusive_helper<T, id11, field> helper_type;
    typedef T value_type;
    typedef bst_iterator<helper_type> iterator_type;
    id11 *root = nullptr;
    id0() { }
    id0(const id0 &that) = delete;
    int size() {
        return root ? root->size : 0;
    }
    iterator_type begin() const {
        return iterator_type(id14(root));
    }
    iterator_type end() const {
        return iterator_type();
    }
    iterator_type find_nth(int k) {
        return iterator_type(id8(root, k)); 

    }
    int get_rank(iterator_type it) {
        return id9(root, it.cur);
    }
    iterator_type insert_front(T *node) {
        id11 *x = helper_type::to_member(node);
        x->rc = root;
        if (root) root->p = x;
        root = x;
        x->update_size();
        return iterator_type(x);
    }
    iterator_type insert_back(T *node) {
        id11 *x = helper_type::to_member(node);
        x->lc = root;
        if (root) root->p = x;
        root = x;
        x->update_size();
        return iterator_type(x);
    }
    iterator_type insert_nth(T *node, int k) {
        if (k == 0) return insert_front(node);
        else if (k < size()) {
            id11 *x = helper_type::to_member(node);
            id11 *y = id7(root, k); 

            id4(root, x, y); 

            return iterator_type(x);
        } else if (k == size()) return insert_back(node);
        else throw 0;
    }
    iterator_type erase(iterator_type it) {
        iterator_type next = it;
        ++next;
        id13(root, it.cur);
        return next;
    }
};
template <typename T, id11 T::*field, typename Key, typename Accessor,
          typename Comp>
struct id1 {
    typedef intrusive_helper<T, id11, field> helper_type;
    typedef T value_type;
    typedef Key key_type;
    typedef bst_iterator<helper_type> iterator_type;
    Accessor acc;
    Comp comp;
    id11 *root = nullptr;
    id1() { }
    id1(const id1 &that) = delete;
    int size() const {
        return root ? root->size : 0;
    }
    iterator_type begin() const {
        return iterator_type(id14(root));
    }
    iterator_type end() const {
        return iterator_type();
    }
    iterator_type find_nth(int k) {
        return iterator_type(id8(root, k)); 

    }
    int get_rank(iterator_type it) {
        return id9(root, it.cur);
    }
    iterator_type erase(iterator_type it) {
        iterator_type next = it;
        ++next;
        id13(root, it.cur);
        return next;
    }
    iterator_type find(const key_type &k) {
        id11 *x = id10<helper_type>(root, k, acc, comp);
        if (x) id5(root, x, nullptr);
        if (x && !comp(k, acc(*helper_type::to_parent(x))))
            return iterator_type(x);
        return iterator_type();
    }
    iterator_type lower_bound(const key_type &k) {
        id11 *x = id10<helper_type>(root, k, acc, comp);
        if (x) id5(root, x, nullptr);
        return iterator_type(x);
    }
    iterator_type upper_bound(const key_type &k) {
        id11 *x = id3<helper_type>(root, k, acc, comp);
        if (x) id5(root, x, nullptr);
        return iterator_type(x);
    }
    iterator_type insert(T *node) {
        id11 *x = helper_type::to_member(node);
        id11 *y = id10<helper_type>(root, acc(*node), acc, comp);
        id4(root, x, y);
        return iterator_type(x);
    }
};




















































int64_t diff[300005];
int a[300005];
struct node {
    int b, e; 

    int length; 

    id11 hill_head;
    id11 largest_hill_head;
    node(int b, int e, int length) : b(b), e(e), length(length) { }
};
typedef id1<node, &node::largest_hill_head, int, key_accessor<node, int, &node::length>, std::greater<int>> largest_hill_t;
largest_hill_t id15;
typedef id1<node, &node::hill_head, int, key_accessor<node, int, &node::e>, std::less<int>> hill_t;
hill_t hill;
void add_node(node *n) {
    hill.insert(n);
    id15.insert(n);
}
void remove_node(node *n) {
    hill.erase(hill_t::iterator_type(n));
    id15.erase(largest_hill_t::iterator_type(n));
}
int n;
void pr_state() {
    pr_debug("diff:\n");
    for (int i : range(1, n)) {
        pr_debug("%" PRId64 " ", diff[i]);
    }
    pr_debug("\n");
    pr_debug("seg:\n");
    for (node &n : hill) {
        pr_debug("[%d,%d]=%d ", n.b, n.e, n.length);
    }
    pr_debug("\n");
}
int sign_of(int64_t v) {
    if (v == 0) return 0;
    else if (v > 0) return 1;
    else return -1;
}
bool valid(int sign_a, int sign_b) {
    if (sign_a == 0 || sign_b == 0) return false;
    else if (sign_a == sign_b) return true;
    else if (sign_a == 1 && sign_b == -1) return true;
    return false;
}
void change_cube(int pos, int d) {
    node *n = hill.lower_bound(pos).ptr();
    int before = sign_of(diff[pos]);
    diff[pos] += d;
    int now = sign_of(diff[pos]);
    if (before == now) return;
    if (now == 0) {
        node *cur = new node(pos, pos, 1);
        if (pos > n->b)
            add_node(new node(n->b, pos - 1, (pos - 1) - n->b + 2));
        if (pos < n->e)
            add_node(new node(pos + 1, n->e, n->e - (pos + 1) + 2));
        remove_node(n);
        delete n;
        add_node(cur);
        return;
    }
    node *cur = new node(n->b, n->e, 0);
    if (pos > 1) {
        bool left_valid = valid(sign_of(diff[pos - 1]), now);
        if (left_valid && pos == n->b) {
            pr_debug("ext left cur->e=%d\n", cur->e);
            node *left = (--hill_t::iterator_type(n)).ptr();
            pr_debug("left %p\n", (void *)left);
            cur->b = left->b;
            remove_node(left);
            delete left;
        } else if (!left_valid && pos != n->b) {
            node *left = new node(n->b, pos - 1, (pos - 1) - n->b + 2);
            cur->b = pos;
            add_node(left);
        }
    }
    if (pos < ::n - 1) {
        bool right_valid = valid(now, sign_of(diff[pos + 1]));
        if (right_valid && pos == n->e) {
            pr_debug("ext right cur->e=%d\n", cur->e);
            node *right = (++hill_t::iterator_type(n)).ptr();
            pr_debug("ext right\n");
            cur->e = right->e;
            remove_node(right);
            delete right;
        } else if (!right_valid && pos != n->e) {
            node *right = new node(pos + 1, n->e, n->e - (pos + 1) + 2);
            cur->e = pos;
            add_node(right);
        }
    }
    if (now == 0) {
        assert(cur->b == cur->e);
        cur->length = 1;
    } else {
        cur->length = cur->e - cur->b + 2;
    }
    remove_node(n);
    delete n;
    pr_debug("cur : [%d,%d]\n", cur->b, cur->e);
    add_node(cur);
}
int main() {
    scanf("%d", &n);
    for (int i : nrange(n)) { 

        scanf("%d", &a[i]);
        if (i != 1) diff[i - 1] = a[i] - a[i - 1];
    }
    for (int b = 1; b <= n - 1; ) {
        int e = b;
        while (e <= n - 1 && diff[e] > 0)
            ++e;
        while (e <= n - 1 && diff[e] < 0)
            ++e;
        node *n;
        if (b == e) {
            n = new node(b, b, 1);
            b = b + 1;
        } else {
            n = new node(b, e - 1, e - b + 1);
            b = e;
        }
        add_node(n);
    }
    

    int m;
    scanf("%d", &m);
    if (n == 1) {
        for (int _ : range(m))
            printf("%d\n", 1);
        return 0;
    }
    for (int _ : range(m)) {
        int l, r, d;
        scanf("%d%d%d", &l, &r, &d);
        if (l - 1 >= 1)
            change_cube(l - 1, d);
        

        if (r <= n - 1)
            change_cube(r, -d);
        

        printf("%d\n", id15.begin()->length);
    }
    return 0;
}

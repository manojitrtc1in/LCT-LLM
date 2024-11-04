
#include <cstdio>
#include <cmath>
#include <cstring>      

#include <cstdlib>      

#include <cstdint>      

#include <cinttypes>    

#include <cassert>      

#include <numeric>      

#include <vector>
#include <deque>
#include <map>
#include <set>
#include <tuple>        



#include <algorithm>
#include <utility>
#include <iterator>
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

#ifdef LOCAL_JUDGE
#  define pr_debug(...) fprintf(stderr, __VA_ARGS__)
#  define pr_line() fprintf(stderr, "%s: %d\n", __FILE__, __LINE__)
#else
#  define pr_debug(...)
#  define pr_line()
#endif
template <typename T>
bool chmax(T &m, const T &v) { if (v > m) return m = v, true; return false; }
template <typename T>
bool chmin(T &m, const T &v) { if (v < m) return m = v, true; return false; }

#include <functional>
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
#include <type_traits>








template <typename Head>
Head *bst_leftmost(Head *x) {
    while (x && x->lc)
        x = x->lc;
    return x;
}
template <typename Head>
Head *bst_rightmost(Head *x) {
    while (x && x->rc)
        x = x->rc;
    return x;
}
template <typename Head>
Head *bst_prev(Head *x) {
    if (x->lc) return bst_rightmost(x->lc);
    Head *p = x->p;
    while (p && x == p->lc) {
        x = p;
        p = p->p;
    }
    return p;
}
template <typename Head>
Head *bst_succ(Head *x) {
    if (x->rc) return bst_leftmost(x->rc);
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
Head *bst_lower_bound(Head *root, Key &&k, Accessor &&acc, Comp &&comp) {
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
Head *bst_upper_bound(Head *root, Key &&k, Accessor &&acc, Comp &&comp) {
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
        cur = bst_succ(cur);
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




struct splay_head {
    splay_head *lc, *rc, *p;
    int size;
    splay_head() { reset(); }
    splay_head(const splay_head &that) = delete;
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
static inline void splay_rotate(splay_head *x) { 

    splay_head *y = x->p;
    bst_rotate(x);
    y->update_size();
}
static inline void splay_splay(splay_head *&root, splay_head *x, splay_head *target) {
    while (x->p != target) {
        if (x->p->p != target) {
            if ((x->p->lc == x) == (x->p->p->lc == x->p))
                splay_rotate(x->p);
            else
                splay_rotate(x);
        }
        splay_rotate(x);
    }
    x->update_size();
    if (!target)
        root = x;
}
static inline void splay_insert_before(splay_head *&root, splay_head *x, splay_head *y) {
    

    if (!y) {
        x->lc = root;
        if (root) root->p = x;
        root = x;
        x->update_size();
    } else {
        splay_splay(root, y, nullptr);
        if (!y->lc)
            y->lc = x, x->p = y, y->update_size();
        else {
            splay_head *prev = bst_rightmost(y->lc);
            splay_splay(root, prev, y);
            prev->rc = x;
            x->p = prev;
            prev->update_size();
            y->update_size();
        }
    }
}
static inline void splay_erase(splay_head *&root, splay_head *x) {
    splay_splay(root, x, nullptr);
    if (!x->lc) {
        if (x->rc) x->rc->p = nullptr;
        root = x->rc;
    } else {
        splay_head *prev = bst_rightmost(x->lc);
        splay_splay(root, prev, x);
        prev->rc = x->rc;
        if (x->rc) x->rc->p = prev;
        prev->update_size();
        prev->p = nullptr, root = prev;
    }
    x->reset();
}


static inline int splay_get_rank(splay_head *&root, splay_head *x) {
    if (!x) return root ? root->size : 0; 

    splay_splay(root, x, nullptr);
    return x->lc ? x->lc->size : 0;
}
static inline splay_head *splay_find_nth_inner(splay_head *&root, int k) {
    splay_head *p = root;
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
static inline splay_head *splay_find_nth(splay_head *&root, int k) {
    splay_head *p = splay_find_nth_inner(root, k);
    splay_splay(root, p, nullptr);
    return p;
}
template <typename T, splay_head T::*field>
struct splay_array {
    typedef intrusive_helper<T, splay_head, field> helper_type;
    typedef T value_type;
    typedef bst_iterator<helper_type> iterator_type;
    splay_head *root = nullptr;
    splay_array() { }
    splay_array(const splay_array &that) = delete;
    int size() {
        return root ? root->size : 0;
    }
    iterator_type begin() const {
        return iterator_type(bst_leftmost(root));
    }
    iterator_type end() const {
        return iterator_type();
    }
    iterator_type find_nth(int k) {
        return iterator_type(splay_find_nth(root, k)); 

    }
    int get_rank(iterator_type it) {
        return splay_get_rank(root, it.cur);
    }
    iterator_type insert_front(T *node) {
        splay_head *x = helper_type::to_member(node);
        x->rc = root;
        if (root) root->p = x;
        root = x;
        x->update_size();
        return iterator_type(x);
    }
    iterator_type insert_back(T *node) {
        splay_head *x = helper_type::to_member(node);
        x->lc = root;
        if (root) root->p = x;
        root = x;
        x->update_size();
        return iterator_type(x);
    }
    iterator_type insert_nth(T *node, int k) {
        if (k == 0) return insert_front(node);
        else if (k < size()) {
            splay_head *x = helper_type::to_member(node);
            splay_head *y = splay_find_nth_inner(root, k); 

            splay_insert_before(root, x, y); 

            return iterator_type(x);
        } else if (k == size()) return insert_back(node);
        else throw 0;
    }
    iterator_type erase(iterator_type it) {
        iterator_type next = it;
        ++next;
        splay_erase(root, it.cur);
        return next;
    }
};
template <typename T, splay_head T::*field, typename Key, typename Accessor,
          typename Comp>
struct sized_splay {
    typedef intrusive_helper<T, splay_head, field> helper_type;
    typedef T value_type;
    typedef Key key_type;
    typedef bst_iterator<helper_type> iterator_type;
    Accessor acc;
    Comp comp;
    splay_head *root = nullptr;
    sized_splay() { }
    sized_splay(const sized_splay &that) = delete;
    int size() const {
        return root ? root->size : 0;
    }
    iterator_type begin() const {
        return iterator_type(bst_leftmost(root));
    }
    iterator_type end() const {
        return iterator_type();
    }
    iterator_type find_nth(int k) {
        return iterator_type(splay_find_nth(root, k)); 

    }
    int get_rank(iterator_type it) {
        return splay_get_rank(root, it.cur);
    }
    iterator_type erase(iterator_type it) {
        iterator_type next = it;
        ++next;
        splay_erase(root, it.cur);
        return next;
    }
    iterator_type find(const key_type &k) {
        splay_head *x = bst_lower_bound<helper_type>(root, k, acc, comp);
        if (x) splay_splay(root, x, nullptr);
        if (x && !comp(k, acc(*helper_type::to_parent(x))))
            return iterator_type(x);
        return iterator_type();
    }
    iterator_type lower_bound(const key_type &k) {
        splay_head *x = bst_lower_bound<helper_type>(root, k, acc, comp);
        if (x) splay_splay(root, x, nullptr);
        return iterator_type(x);
    }
    iterator_type upper_bound(const key_type &k) {
        splay_head *x = bst_upper_bound<helper_type>(root, k, acc, comp);
        if (x) splay_splay(root, x, nullptr);
        return iterator_type(x);
    }
    iterator_type insert(T *node) {
        splay_head *x = helper_type::to_member(node);
        splay_head *y = bst_lower_bound<helper_type>(root, acc(*node), acc, comp);
        splay_insert_before(root, x, y);
        return iterator_type(x);
    }
};



























static const int NMAX = 100005;
struct node {
    splay_head head, khead;
    int v;
};
typedef splay_array<node, &node::head> arr_t;
arr_t arr;
struct accessor {
    int operator()(node &n) const {
        return arr.get_rank(arr_t::iterator_type(&n));
    }
};
typedef sized_splay<node, &node::khead, int, accessor, std::less<int>> splay_t;
splay_t ktree[NMAX];
node pool[NMAX], *tail = pool;
int main() {
    int n;
    scanf("%d", &n);
    for (int i : range(n)) {
        int v;
        scanf("%d", &v);
        node *cur = tail++;
        cur->v = v;
        arr.insert_back(cur);
        ktree[v].insert(cur);
    }
    for (node &n : arr)
        pr_debug("arr %d\n", n.v);
    for (int i : range(NMAX))
        if (ktree[i].size()) {
            pr_debug("ktree %d, size=%d\n", i, ktree[i].size());
        }
    int q, lastans = 0;
    scanf("%d", &q);
    pr_debug("n=%d q=%d\n", n, q);
    for (int _ : range(q)) {
        int t;
        scanf("%d", &t);
        int ll, rr, kk;
        scanf("%d%d", &ll, &rr);
        int l = (ll + lastans - 1) % n + 1;
        int r = (rr + lastans - 1) % n + 1;
        if (l > r) swap(l, r);
        --l, --r;
        if (t == 1) {
            if (l == r) continue;
            arr_t::iterator_type it = arr.find_nth(r);
            

            arr.erase(it);
            arr.insert_nth(it.ptr(), l);
            

            ktree[it->v].erase(splay_t::iterator_type(it.ptr()));
            ktree[it->v].insert(it.ptr());
        } else {
            scanf("%d", &kk);
            int k = (kk + lastans - 1) % n + 1;
            int b = ktree[k].get_rank(
                    splay_t::iterator_type(ktree[k].lower_bound(l)));
            int e = ktree[k].get_rank(
                    splay_t::iterator_type(ktree[k].lower_bound(r + 1)));
            pr_debug("b=%d e=%d\n", b, e);
            printf("%d\n", lastans = e - b);
        }
    }
    return 0;
}

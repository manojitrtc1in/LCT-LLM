
#include <cstdio>
#include <cmath>
#include <climits>      

#include <cstring>      

#include <cstdlib>      

#include <cstdint>      

#include <cinttypes>    

#include <cassert>      

#include <limits>       

#include <vector>
#include <deque>
#include <map>
#include <set>
#include <tuple>        

#include <iostream>     

                        

                        

#include <sstream>
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
static const int HMAX32 = INT32_MAX / 2;
static const int64_t HMAX64 = INT64_MAX / 2;
#define fast_io\
    ios_base::sync_with_stdio(false); cin.tie(nullptr)
stringstream line_stream() {
    string str;
    getline(cin, str);
    return stringstream(str);
}
#define read_int(id) scanf("%d", &id)
#define read_int64(id) scanf("%" PRId64, &id)
#define new_int(id) int id; read_int(id)
#define new_int64(id) int64_t id; read_int64(id)
#define ALL(x) begin(x), end(x)
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
struct list_head {
    struct list_head *prev, *next; 

    list_head() { reset(); }
    list_head(const list_head &that) = delete;
    list_head &operator=(const list_head &that) = delete;
    bool empty() { return next == this; }
    void unlink() { link(*prev, *next); reset(); }
    void insert_next(struct list_head &new_next) {
        link(new_next, *next);
        link(*this, new_next);
    }
    void insert_prev(struct list_head &new_prev) {
        link(*prev, new_prev);
        link(new_prev, *this);
    }
    static void link(struct list_head &prev, struct list_head &next) {
        prev.next = &next;
        next.prev = &prev;
    }
    void reset() { prev = next = this; }
};
template <typename T, struct list_head T::*field>
struct list_iter
{
    typedef T value_type;
    typedef T *pointer;
    typedef T &reference;
    typedef iter_range<list_iter> range_type;
    typedef typename std::bidirectional_iterator_tag iterator_category;
    typedef typename std::ptrdiff_t difference_type; 

    typedef intrusive_helper<T, list_head, field> helper_type;
    list_head *cur;
    list_iter() { cur = nullptr; }
    list_iter(list_head &head) { cur = &head; }
    list_iter(T *value) { cur = &(value->*field); }
    list_iter& operator++() {
        cur = cur->next;
        return *this;
    }
    list_iter operator++(int) const {
        list_iter that(*this);
        return ++that;
    }
    list_iter& operator--() {
        cur = cur->prev;
        return *this;
    }
    list_iter operator--(int) const {
        list_iter that(*this);
        return --that;
    }
    pointer operator->() const {
        return helper_type::to_parent(cur);
    }
    reference operator*() const {
        return *operator->();
    }
    bool operator==(const list_iter& that) {
        return cur == that.cur;
    }
    bool operator!=(const list_iter& that) {
        return !(*this == that);
    }
    static range_type make_range(list_head &list) {
        return {list_iter(*list.next), list_iter(list)};
    }
};
template <typename T, struct list_head T::*field>
iter_range<list_iter<T, field>> list_range(list_head &list) {
    return list_iter<T, field>::make_range(list);
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
    explicit bst_iterator(head_type &head) { cur = &head; }
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
template <typename T, splay_head T::*field, typename Key = T, typename Accessor=identity_accessor<Key>,
          typename Comp = std::less<Key>>
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













































static const int maxn = 500005;
struct node_t {
    list_head lh;
    splay_head sh;
    int v;
    int pos;
};
list_head lst;
typedef list_iter<node_t, &node_t::lh> lit_t;
typedef sized_splay<node_t, &node_t::sh, int,
    key_accessor<node_t, int, &node_t::v>, std::less<int>> splay_t;
splay_t splay;
node_t arr[maxn];
int64_t ans = 0;
int main() {
    new_int(n);
    for (int i : nrange(n)) {
        new_int(v);
        arr[i].v = v;
        arr[i].pos = i;
    }
    for (int i : nrange(n)) {
        splay.insert(&arr[i]);
        lst.insert_prev(arr[i].lh);
    }
    int last_left = 0;
    int last_right = 0;
    while (splay.size()) {
        auto it = splay.begin();
        lit_t lit = lit_t(it->lh);
        lit_t root = lit_t(lst);
        int left = next(root)->pos;
        int right = prev(root)->pos;
        splay.erase(it);
        if (it->pos == left && it->pos == right) {
            ans += min(last_left, last_right);
        } else if (it->pos == left) {
            ans += last_left;
            last_left = it->v;
        } else if (it->pos == right) {
            ans += last_right;
            last_right = it->v;
        } else {
            ans += min(next(lit)->v, prev(lit)->v);
        }
        it->lh.unlink();
    }
    printf("%lld\n", ans);
    return 0;
}

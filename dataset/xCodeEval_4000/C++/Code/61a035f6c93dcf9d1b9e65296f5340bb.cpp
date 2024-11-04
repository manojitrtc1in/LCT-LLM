#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define pb push_back
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forrn(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define PYMOD(a, m) ((((a) % (m)) + (m)) % (m))
#define all(v) v.begin(), v.end()
#define mp make_pair
#define ff first
#define ss second

mt19937 rnd(179);

template<class T>
class splay_tree_base {
    struct node {
        T value;
        node *L, *R, *par;
        node(const T& val)
                : value(val)
                  , L(nullptr)
                  , R(nullptr)
                  , par(nullptr)
        {}

        void push() {
            if (value.push(L ? &L->value : nullptr, R ? &R->value : nullptr)) {
                swap(L, R);
            }
        }

        void update() {
            value.update(L ? &L->value : nullptr,
                         R ? &R->value : nullptr);
        }
    };

    static void update(node *v) {
        if (v) {
            v->update();
        }
    }

    static void push(node *v) {
        if (v) {
            v->push();
        }
    }

    static void single_rotate(node *y) {
        assert(y != nullptr);
        assert(y->par != nullptr);
        node *x = y->par;
        push(x);
        push(y);
        if (x->par) {
            if (x->par->L == x)
                x->par->L = y;
            else
                x->par->R = y;
        }
        y->par = x->par;
        if (x->L == y) {
            node *B = y->R;
            x->L = B;
            if (B) B->par = x;
            y->R = x;
            x->par = y;
        } else {
            assert(x->R == y);
            node *B = y->L;
            x->R = B;
            if (B) B->par = x;
            y->L = x;
            x->par = y;
        }
        update(x);
        update(y);
    }

    node *root = nullptr;

    static void splay(node *v) {
        while (v->par) {
            push(v->par->par);
            push(v->par);
            push(v);
            if (v->par->par == nullptr) {
                single_rotate(v);
            } else {
                if ((v->par->par->L == v->par && v->par->L == v)
                    || (v->par->par->R == v->par && v->par->R == v)) {
                    single_rotate(v->par);
                    single_rotate(v);
                } else {
                    single_rotate(v);
                    single_rotate(v);
                }
            }
        }
    }

    template<class X>
    node *lower_bound_internal(X& value) {
        node *cur = root;
        node *ans = nullptr;
        while (cur != nullptr) {
            push(cur);
            if (cur->value < value) {
                value.to_right(cur->L ? &cur->L->value : nullptr);
                cur = cur->R;
            } else {
                ans = cur;
                value.to_left(cur->R ? &cur->R->value : nullptr);
                cur = cur->L;
            }
        }
        return ans;
    }

    template<class X>
    void split_left(X& value, node *&left, node *&right) {
        node *v = lower_bound_internal(value);
        if (v == nullptr) {
            left = root;
            right = nullptr;
        } else if (value < v->value) {
            splay(v);
            left = v->L;
            right = v;
            if (v->L)
                v->L->par = nullptr;
            v->L = nullptr;
            update(v);
        } else {
            splay(v);
            left = v;
            right = v->R;
            if (v->R)
                v->R->par = nullptr;
            v->R = nullptr;
            update(v);
        }
    }

    template<class X>
    void split_right(X& value, node *&left, node *&right) {
        node *v = lower_bound_internal(value);
        if (v == nullptr) {
            left = root;
            right = nullptr;
        } else {
            splay(v);
            left = v->L;
            right = v;
            if (v->L)
                v->L->par = nullptr;
            v->L = nullptr;
            update(v);
        }
    }

    node *merge(node *left, node *right) {
        if (!left)
            return right;
        node *v = left;
        push(v);
        while (v->R) {
            v = v->R;
            push(v);
        }
        splay(v);
        v->R = right;
        if (right) {
            right->par = v;
        }
        update(v);
        return v;
    }

    template<class F>
    void for_each(const F& f, node *v) {
        push(v);
        if (v->L) for_each(f, v->L);
        f(v->value);
        if (v->R) for_each(f, v->R);
    }

    splay_tree_base(node *rt)
            : root(rt)
    {}

    void rec_delete(node *v) {
        if(!v) return;
        rec_delete(v->L);
        rec_delete(v->R);
        delete v;
    }

public:
    splay_tree_base() {}

    splay_tree_base(const T& value)
            : root(new node(value))
    {}

    splay_tree_base(const splay_tree_base<T>&) = delete;
    splay_tree_base<T>& operator=(const splay_tree_base<T>&) = delete;
    splay_tree_base(splay_tree_base<T>&& t) = default;
    splay_tree_base<T>& operator=(splay_tree_base<T>&& t) = default;

    template<class X>
    pair<splay_tree_base<T>, splay_tree_base<T>> split_left(X value) {
        node *left, *right;
        split_left(value, left, right);
        root = nullptr;
        return mp(splay_tree_base<T>(left), splay_tree_base<T>(right));
    }

    template<class X>
    pair<splay_tree_base<T>, splay_tree_base<T>> split_right(X value) {
        node *left, *right;
        split_right(value, left, right);
        root = nullptr;
        return mp(splay_tree_base<T>(left), splay_tree_base<T>(right));
    }

    template<class X>
    T* lower_bound(X value) {
        node *v = lower_bound_internal(value);
        if (v) {
            splay(v);
        }
        return v ? &v->value : nullptr;
    }

    void merge_to(splay_tree_base<T>&& right) {
        root = merge(root, right.root);
    }

    T* root_value() {
        return root ? &root->value : nullptr;
    }

    template<class F>
    void for_each(const F& functor) {
        if (root) {
            for_each(functor, root);
        }
    }

    class iterator {
        node *v;
    public:
        iterator(node *n)
                : v(n)
        {
            v->push();
        }

        T& value() {
            return v->value;
        }

        bool has_left() {
            return v->L;
        }

        bool has_right() {
            return v->R;
        }

        void to_root() {
            splay(v);
        }

        void set_root(splay_tree_base<T>& of) {
            of.root = v;
        }

        iterator left() {
            return iterator(v->L);
        }

        iterator right() {
            return iterator(v->R);
        }
    };

    iterator root_iterator() const {
        return iterator(root);
    }

    bool empty() const {
        return root == nullptr;
    }
};

template<class T>
struct explicit_key {
    T value;

    explicit_key(const T& val)
            : value(val)
    {}

    void update(explicit_key<T>*, explicit_key<T>*) {}

    void to_left(explicit_key<T>*) {}

    void to_right(explicit_key<T>*) {}

    bool push(explicit_key<T>*, explicit_key<T>*) {
        return false;
    }

    bool operator<(const explicit_key<T>& other) const {
        return value < other.value;
    }
};

template<class T, template<class> class K = explicit_key>
class splay_tree {
    using base_t = splay_tree_base<K<T>>;
    base_t tree;

    splay_tree(base_t&& b)
            : tree(std::forward<base_t>(b))
    {}

public:
    splay_tree() {}

    splay_tree(const splay_tree<T, K>&) = delete;
    splay_tree<T, K>& operator=(const splay_tree<T, K>&) = delete;
    splay_tree(splay_tree<T, K>&&) = default;
    splay_tree<T, K>& operator=(splay_tree<T, K>&&) = default;

    void insert(const T& value) {
        auto p = tree.split_left(K<T>(value));
        p.first.merge_to(base_t(value));
        p.first.merge_to(std::move(p.second));
        tree = std::move(p.first);
    }

    bool count(const T& value) {
        auto v = tree.lower_bound(K<T>(value));
        return v && v->value == value;
    }

    void erase(const T& value) {
        auto p = tree.split_left(K<T>(value));
        auto q = p.first.split_right(K<T>(value));
        tree = std::move(q.first);
        tree.merge_to(std::move(p.second));
    }

    template<class F>
    void for_each(const F& f) {
        tree.for_each([&f](const K<T>& x) { f(x.value); });
    }

    using iterator = typename base_t::iterator;

    iterator root_iterator() {
        return tree.root_iterator();
    }

    template<class X>
    pair<splay_tree<T, K>, splay_tree<T, K>> split_left(const X& value) {
        auto p = tree.split_left(K<X>(value));
        return make_pair(splay_tree<T, K>(std::move(p.first)), splay_tree<T, K>(std::move(p.second)));
    }

    template<class X>
    pair<splay_tree<T, K>, splay_tree<T, K>> split_right(const X& value) {
        auto p = tree.split_right(K<X>(value));
        return make_pair(splay_tree<T, K>(std::move(p.first)), splay_tree<T, K>(std::move(p.second)));
    }

    void merge_to(splay_tree<T, K>&& right) {
        tree.merge_to(std::move(right.tree));
    }

    bool empty() const {
        return tree.empty();
    }

    const K<T>& root_key() const {
        return tree.root_iterator().value();
    }
};

template<class T>
struct implicit_key {
    T value;
    int size;
    int left_size;
    int right_size;
    bool reversed;

    implicit_key(const T& val)
            : value(val)
              , size(1)
              , left_size(0)
              , right_size(0)
              , reversed(false)
    {}

    void update(implicit_key<T>* L, implicit_key<T>* R) {
        size = 1;
        if (L) size += L->size;
        if (R) size += R->size;
        left_size = 0;
        if (L) left_size = L->size;
        right_size = 0;
        if (R) right_size = R->size;
    }

    void reverse() {
        reversed ^= 1;
    }

    bool push(implicit_key<T>* L, implicit_key<T>* R) {
        if (reversed) {
            left_size = R ? R->size : 0;
            if (L) L->reverse();
            if (R) R->reverse();
            reversed = false;
            return true;
        }
        return false;
    }
};

template<class T, template<class> class K>
struct split_cmp {
    int left;

    split_cmp(int l)
            : left(l)
    {}

    void to_left(K<T>*) {}

    void to_right(K<T>* key) {
        left--;
        if (key) {
            left -= key->size;
        }
    }
};

template<class T, template<class> class K>
bool operator<(const K<T>& a, const split_cmp<T, K>& b) {
    return a.left_size < b.left;
}

template<class T, template<class> class K = implicit_key>
class implicit_splay_tree {
    using base_t = splay_tree_base<K<T>>;
    base_t tree;

    implicit_splay_tree(base_t&& t)
            : tree(std::forward<base_t>(t))
    {}

public:
    implicit_splay_tree() {}

    implicit_splay_tree(const T& value)
            : tree(value)
    {}

    implicit_splay_tree(const implicit_splay_tree<T, K>&) = delete;
    implicit_splay_tree<T, K>& operator=(const implicit_splay_tree<T, K>&) = delete;
    implicit_splay_tree(implicit_splay_tree<T, K>&&) = default;
    implicit_splay_tree<T, K>& operator=(implicit_splay_tree<T, K>&&) = default;

    pair<implicit_splay_tree<T, K>, implicit_splay_tree<T, K>> split(int left_size) {
        auto p = tree.split_right(split_cmp<T, K>(left_size));
        return make_pair(implicit_splay_tree<T, K>(std::move(p.ff)), implicit_splay_tree<T, K>(std::move(p.ss)));
    }

    void merge_to(implicit_splay_tree<T, K>&& right) {
        tree.merge_to(std::move(right.tree));
    }

    void insert(int i, const T& value) {
        auto p = split(i);
        p.ff.merge_to(implicit_splay_tree<T, K>(value));
        p.ff.merge_to(std::move(p.ss));
        *this = std::move(p.ff);
    }

    const T& at(int i) {
        return tree.lower_bound(split_cmp<T, K>(i))->value;
    }

    void erase(int i) {
        auto p = split(i);
        auto q = p.ss.split(1);
        p.ff.merge_to(std::move(q.ss));
        *this = std::move(p.ff);
    }

    template<class F>
    void for_each(const F& f) {
        tree.for_each([&f](const K<T>& x) { f(x.value); });
    }

    K<T>& root_key() {
        return tree.root_iterator().value();
    }

    bool empty() {
        return tree.empty();
    }

    void reverse() {
        if (!empty()) {
            root_key().reverse();
        }
    }

    int size() {
        if (empty())
            return 0;
        return root_key().size;
    }

    using iterator = typename base_t::iterator;

    iterator root_iterator() {
        return tree.root_iterator();
    }

    base_t& base() {
        return tree;
    }
};

class link_cut_trees {
    struct node_info {
        int id;
        int parent;

        node_info(int v)
                : id(v)
                  , parent(-1)
        {}
    };

    template<class T>
    struct node_key : public implicit_key<T> {
        int tree_id;

        node_key(const T& val)
                : implicit_key<T>(val)
                  , tree_id(-1)
        {}

        bool push(node_key<T>* L, node_key<T>* R) {
            if (L) L->tree_id = tree_id;
            if (R) R->tree_id = tree_id;
            return implicit_key<T>::push(L, R);
        }
    };

    using tree_t = implicit_splay_tree<node_info, node_key>;

    int n;
    vector<tree_t> trees;
    vector<tree_t::iterator> node_it;

    void swap_trees(int i, int j) {
        if (!trees[i].empty())
            trees[i].root_iterator().value().tree_id = j;
        if (!trees[j].empty())
            trees[j].root_iterator().value().tree_id = i;
        swap(trees[i], trees[j]);
    }

    pair<int, int> position_of(int v) {
        node_it[v].to_root();
        node_it[v].set_root(trees[node_it[v].value().tree_id].base());
        return make_pair(node_it[v].value().tree_id, node_it[v].value().left_size);
    }

    int parent_of(int tree_id) {
        auto it = trees[tree_id].root_iterator();
        while (it.has_left())
            it = it.left();
        it.to_root();
        it.set_root(trees[tree_id].base());
        return it.value().value.parent;
    }

    int last_in_path(int tree_id) {
        auto it = trees[tree_id].root_iterator();
        while (it.has_right())
            it = it.right();
        it.to_root();
        it.set_root(trees[tree_id].base());
        return it.value().value.id;
    }

    void set_parent(int tree_id, int parent) {
        auto it = trees[tree_id].root_iterator();
        while (it.has_left())
            it = it.left();
        it.to_root();
        it.set_root(trees[tree_id].base());
        it.value().value.parent = parent;
    }

    void split_tree(int tree_id, int left) {
        assert(trees[tree_id].size() >= left);
        auto p = trees[tree_id].split(left);
        assert(p.ff.size() == left);
        trees[tree_id] = std::move(p.ff);
        if (!p.ss.empty()) {
            p.ss.root_iterator().value().tree_id = trees.size();
            trees.pb(std::move(p.ss));
            set_parent(trees.size() - 1, last_in_path(tree_id));
        }
    }

    void merge_trees(int i, int j) {
        trees[i].merge_to(std::move(trees[j]));
        trees[i].root_key().tree_id = i;
        swap_trees(j, trees.size() - 1);
        trees.pop_back();
    }

    void reverse_tree(int i) {
        int j = parent_of(i);
        trees[i].reverse();
        set_parent(i, j);
    }

    void expose(int v) {
        auto pos = position_of(v);
        int parent = parent_of(pos.ff);
        while (parent != -1) {
            auto parent_pos = position_of(parent);
            split_tree(parent_pos.ff, parent_pos.ss + 1);
            merge_trees(parent_pos.ff, position_of(v).ff);
            pos = position_of(v);
            parent = parent_of(pos.ff);
        }
    }

    void to_root(int v) {
        expose(v);
        auto pos = position_of(v);
        split_tree(pos.ff, pos.ss + 1);
        reverse_tree(pos.ff);
    }

public:
    link_cut_trees(int sz)
            : n(sz)
    {
        forn(i, n) {
            trees.pb(tree_t(node_info(i)));
            node_it.pb(trees.back().root_iterator());
            node_it.back().value().tree_id = i;
        }
    }

    int component_of(int v) {
        expose(v);
        return position_of(v).ff;
    }

    void link(int parent, int child) {
        to_root(child);
        set_parent(position_of(child).ff, parent);
    }

    void cut(int u, int v) {
        auto pos_u = position_of(u);
        auto pos_v = position_of(v);

        if (pos_u.ff == pos_v.ff) {
            if (pos_u.ss < pos_v.ss) {
                split_tree(pos_u.ff, pos_u.ss + 1);
                node_it[v].value().value.parent = -1;
            } else {
                split_tree(pos_v.ff, pos_v.ss + 1);
                node_it[u].value().value.parent = -1;
            }
        } else {
            if (node_it[v].value().value.parent == u)
                node_it[v].value().value.parent = -1;
            else
                node_it[u].value().value.parent = -1;
        }
    }

    void print_trees() {
        forn(i, trees.size()) {
            cout << "{parent = " << parent_of(i) << ", path = ( ";
            trees[i].for_each([](const node_info& v) { cout << v.id << " "; });
            cout << ")}" << endl;
        }
    }
};

struct segment_tree {
    int n;
    vector<int> t;
    vector<int> mod;
    vector<int> nt;

    void update(int v) {
        t[v] = min(t[2 * v + 1] + mod[2 * v + 1], t[2 * v + 2] + mod[2 * v + 2]);
        if (t[2 * v + 1] + mod[2 * v + 1] < t[2 * v + 2] + mod[2 * v + 2])
            nt[v] = nt[2 * v + 1];
        else if (t[2 * v + 1] + mod[2 * v + 1] > t[2 * v + 2] + mod[2 * v + 2])
            nt[v] = nt[2 * v + 2];
        else {
            nt[v] = nt[2 * v + 1] + nt[2 * v + 2];
        }
    }

    void push(int v) {
        mod[2 * v + 1] += mod[v];
        mod[2 * v + 2] += mod[v];
        mod[v] = 0;
        update(v);
    }

    void add(int v, int L, int R, int l, int r, int x) {
        if (R <= l || r <= L)
            return;
        else if (l <= L && R <= r)
            mod[v] += x;
        else {
            push(v);
            add(2 * v + 1, L, (L + R) / 2, l, r, x);
            add(2 * v + 2, (L + R) / 2, R, l, r, x);
            update(v);
        }
    }

    int get_min(int v, int L, int R, int l, int r) {
        if (R <= l || r <= L)
            return numeric_limits<int>::max();
        else if (l <= L && R <= r) {
            return t[v] + mod[v];
        } else {
            push(v);
            return min(get_min(2 * v + 1, L, (L + R) / 2, l, r),
                       get_min(2 * v + 2, (L + R) / 2, R, l, r));
        }
    }

    pair<int, int> get_nmins(int v, int L, int R, int l, int r) {
        if (R <= l || r <= L)
            return mp(numeric_limits<int>::max(), 0);
        else if (l <= L && R <= r) {
            return mp(t[v] + mod[v], nt[v]);
        } else {
            push(v);
            auto a = get_nmins(2 * v + 1, L, (L + R) / 2, l, r);
            auto b = get_nmins(2 * v + 2, (L + R) / 2, R, l, r);
            if (a.ff < b.ff)
                return a;
            else if (a.ff > b.ff)
                return b;
            else
                return mp(a.ff, a.ss + b.ss);
        }
    }

    void build(int v, int L, int R) {
        if (L == R - 1)
            nt[v] = 1;
        else {
            build(2 * v + 1, L, (L + R) / 2);
            build(2 * v + 2, (L + R) / 2, R);
            update(v);
        }
    }

public:
    segment_tree(int _n)
        : n(_n)
    {
        t.resize(4 * n);
        mod.resize(4 * n);
        nt.resize(4 * n);
        build(0, 0, n);
    }

    void add(int l, int r, int x) {
        add(0, 0, n, l, r, x);
    }

    int get_min(int l, int r) {
        return get_min(0, 0, n, l, r);
    }

    int get_nmins(int l, int r) {
        return get_nmins(0, 0, n, l, r).ss;
    }
};

bool ok(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > a(n);
    forn(i, n) {
        a[i].resize(m);
        forn(j, m) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    vector<int> x(n * m), y(n * m);
    forn(i, n) {
        forn(j, m) {
            x[a[i][j]] = i;
            y[a[i][j]] = j;
        }
    }

    link_cut_trees lct(n * m);
    segment_tree st(n * m);

    ll ans = 0;

    int l = 0;
    forn(r, n * m) {
        

        for (int k = 0; k < 4; k++) {
            int nx = x[r] + dx[k];
            int ny = y[r] + dy[k];
            if (!ok(nx, ny, n, m))
                continue;
            if (a[nx][ny] > r)
                continue;
            while (a[nx][ny] >= l && lct.component_of(a[nx][ny]) == lct.component_of(r)) {
                for (int t = 0; t < 4; t++) {
                    int nxt = x[l] + dx[t];
                    int nyt = y[l] + dy[t];
                    if (!ok(nxt, nyt, n, m))
                        continue;
                    if (a[nxt][nyt] < l || a[nxt][nyt] > r)
                        continue;
                    lct.cut(l, a[nxt][nyt]);
                }
                l++;
            }
            if (a[nx][ny] >= l) {
                lct.link(r, a[nx][ny]);
            }
        }

        

        st.add(l, r + 1, 1);
        for (int k = 0; k < 4; k++) {
            int nx = x[r] + dx[k];
            int ny = y[r] + dy[k];
            if (!ok(nx, ny, n, m))
                continue;
            if (a[nx][ny] < l || a[nx][ny] > r)
                continue;
            st.add(l, a[nx][ny] + 1, -1);
        }

        

        ans += st.get_nmins(l, r + 1);
    }

    cout << ans << endl;

    return 0;
}

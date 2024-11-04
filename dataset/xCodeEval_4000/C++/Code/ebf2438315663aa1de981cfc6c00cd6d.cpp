#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename Treap>
struct basic_treap {
    using uniform_priod = uniform_int_distribution<uint32_t>;
    static inline mt19937 rng = mt19937(random_device{}());
    static inline uniform_priod priod = uniform_priod(0, UINT32_MAX);

    Treap* kids[2] = {};
    uint32_t priority = priod(rng);

    static int get_size(const Treap* x) { return Treap::get_size(x); }
    static auto get_key(const Treap* x) { return Treap::get_key(x); }

  protected:
    basic_treap() : priority(priod(rng)) {}
    inline void pushdown() {}
    inline void pushup() {}

    Treap* self() { return static_cast<Treap*>(this); }
    const Treap* self() const { return static_cast<const Treap*>(this); }

  private:
    using TwoTreaps = pair<Treap*, Treap*>;
    using ThreeTreaps = tuple<Treap*, Treap*, Treap*>;

  public:
    Treap* clone() const {
        auto node = new Treap(*self());
        node->priority = priod(rng), node->kids[0] = node->kids[1] = nullptr;
        return node;
    }

    friend void delete_all(Treap* u) {
        if (u) {
            delete_all(u->kids[0]);
            delete_all(u->kids[1]);
            delete u;
        }
    }

    

    friend Treap* join(Treap* a, Treap* b) {
        if (!a || !b) {
            return !b ? a : b;
        }
        if (a->priority >= b->priority) {
            a->pushdown();
            a->kids[1] = join(a->kids[1], b);
            a->pushup();
            return a;
        } else {
            b->pushdown();
            b->kids[0] = join(a, b->kids[0]);
            b->pushup();
            return b;
        }
    }

    

    friend Treap* join(Treap* a, Treap* b, Treap* c) { return join(join(a, b), c); }

    friend Treap* push_back(Treap* root, Treap* item) {
        if (!root) {
            return item;
        }
        root->pushdown();
        if (root->priority < item->priority) {
            item->kids[0] = join(root, item->kids[0]);
            item->pushup();
            return item;
        } else {
            root->kids[1] = push_back(root->kids[1], item);
            root->pushup();
            return root;
        }
    }

    friend Treap* push_front(Treap*& root, Treap* item) {
        if (!root) {
            return item;
        }
        root->pushdown();
        if (root->priority < item->priority) {
            item->kids[1] = join(item->kids[1], root);
            item->pushup();
            return item;
        } else {
            root->kids[0] = push_front(root->kids[0], item);
            root->pushup();
            return root;
        }
    }

    

    friend TwoTreaps pop_back(Treap* root) {
        if (!root) {
            return {};
        }
        root->pushdown();
        if (!root->kids[1]) {
            Treap* kid = root->kids[0];
            root->kids[0] = nullptr;
            return {kid, root};
        } else {
            Treap* back;
            tie(root->kids[1], back) = pop_back(root->kids[1]);
            root->pushup();
            return {root, back};
        }
    }

    

    friend TwoTreaps pop_front(Treap* root) {
        if (!root) {
            return {};
        }
        root->pushdown();
        if (!root->kids[0]) {
            Treap* kid = root->kids[1];
            root->kids[1] = nullptr;
            return {kid, root};
        } else {
            Treap* front;
            tie(root->kids[0], front) = pop_front(root->kids[0]);
            root->pushup();
            return {root, front};
        }
    }

    friend Treap* delete_back(Treap* root) {
        auto [ans, last] = pop_back(root);
        delete last;
        return ans;
    }

    friend Treap* delete_front(Treap* root) {
        auto [ans, first] = pop_front(root);
        delete first;
        return ans;
    }

    template <typename Vis>
    friend void beats_visit(Treap* root, Vis&& vis) {
        if (!root || vis(root)) {
            return;
        }
        root->pushdown();
        beats_visit(root->kids[0], vis);
        beats_visit(root->kids[1], vis);
        root->pushup();
    }

    


    

    friend Treap* find_order(Treap* root, int order) {
        if (!root) {
            return nullptr;
        }
        root->pushdown();
        int rorder = get_size(root->kids[0]);
        if (rorder > order) {
            return find_order(root->kids[0], order);
        } else if (rorder < order) {
            return find_order(root->kids[1], order - rorder - 1);
        } else {
            return root;
        }
    }

    

    friend Treap* insert_order(Treap* root, Treap* item, int order) {
        if (!root) {
            return item;
        }
        root->pushdown();
        int rorder = get_size(root->kids[0]);
        if (root->priority < item->priority) {
            auto [a, b] = split_order(root, order);
            item->pushdown();
            item->kids[0] = join(a, item->kids[0]);
            item->kids[1] = join(item->kids[1], b);
            item->pushup();
            return item;
        } else if (rorder >= order) {
            root->kids[0] = insert_order(root->kids[0], item, order);
            root->pushup();
            return root;
        } else {
            root->kids[1] = insert_order(root->kids[1], item, order - rorder - 1);
            root->pushup();
            return root;
        }
    }

    

    friend TwoTreaps split_order(Treap* root, int order) {
        if (!root || order <= 0) {
            return {nullptr, root};
        }
        root->pushdown();
        int rorder = get_size(root->kids[0]);
        Treap* a = {};
        if (rorder >= order) {
            tie(a, root->kids[0]) = split_order(root->kids[0], order);
            root->pushup();
            return {a, root};
        } else {
            tie(root->kids[1], a) = split_order(root->kids[1], order - rorder - 1);
            root->pushup();
            return {root, a};
        }
    }

    

    friend ThreeTreaps split_order_range(Treap* root, int start, int end) {
        auto [mid, c] = split_order(root, end);
        auto [a, b] = split_order(mid, start);
        return make_tuple(a, b, c);
    }

    

    friend TwoTreaps splice_order(Treap* root, int order) {
        if (!root) {
            return {};
        }
        root->pushdown();
        int rorder = get_size(root->kids[0]);
        Treap* ans;
        if (rorder > order) {
            tie(root->kids[0], ans) = splice_order(root->kids[0], order);
            root->pushup();
        } else if (rorder < order) {
            tie(root->kids[1], ans) = splice_order(root->kids[1], order - rorder - 1);
            root->pushup();
        } else {
            ans = root, root = join(root->kids[0], root->kids[1]);
            ans->kids[0] = ans->kids[1] = nullptr;
            ans->pushup();
        }
        return {root, ans};
    }

    friend Treap* delete_order(Treap* root, int order) {
        auto [new_root, ans] = splice_order(root, order);
        delete ans;
        return new_root;
    }

    friend Treap* delete_order_range(Treap* root, int start, int end) {
        auto [a, b, c] = split_order_range(root, start, end);
        delete_all(b);
        return join(a, c);
    }

    template <typename Vis>
    friend void beats_visit_order(Treap* root, Vis&& vis, int order = 0) {
        if (!root || vis(root, order, order + get_size(root))) {
            return;
        }
        root->pushdown();
        beats_visit(root->kids[0], vis, order);
        beats_visit(root->kids[1], vis, order + get_size(root->kids[0]) + 1);
        root->pushup();
    }

    


    template <typename Key>
    friend int order_of_key(Treap* root, const Key& key) {
        if (!root) {
            return 0;
        }
        root->pushdown();
        int rorder = get_size(root->kids[0]);
        if (get_key(root) < key) {
            return order_of_key(root->kids[1], key) + rorder + 1;
        } else if (key < get_key(root)) {
            return order_of_key(root->kids[0], key);
        } else {
            return rorder;
        }
    }

    

    template <typename Key>
    friend Treap* after(Treap* root, const Key& key) {
        Treap* ahead = nullptr;
        while (root) {
            root->pushdown();
            if (!(get_key(root) < key)) {
                ahead = root;
                root = root->kids[0];
            } else {
                root = root->kids[1];
            }
        }
        return ahead;
    }

    

    template <typename Key>
    friend Treap* strict_after(Treap* root, const Key& key) {
        Treap* ahead = nullptr;
        while (root) {
            root->pushdown();
            if (key < get_key(root)) {
                ahead = root, root = root->kids[0];
            } else {
                root = root->kids[1];
            }
        }
        return ahead;
    }

    

    template <typename Key>
    friend Treap* before(Treap* root, const Key& key) {
        Treap* ahead = nullptr;
        while (root) {
            root->pushdown();
            if (!(key < get_key(root))) {
                ahead = root, root = root->kids[1];
            } else {
                root = root->kids[0];
            }
        }
        return ahead;
    }

    

    template <typename Key>
    friend Treap* strict_before(Treap* root, const Key& key) {
        Treap* ahead = nullptr;
        while (root) {
            root->pushdown();
            if (get_key(root) < key) {
                ahead = root, root = root->kids[1];
            } else {
                root = root->kids[0];
            }
        }
        return ahead;
    }

    

    template <typename Key>
    friend Treap* find_key(Treap* root, const Key& key) {
        while (root) {
            root->pushdown();
            if (key < get_key(root)) {
                root = root->kids[0];
            } else if (get_key(root) < key) {
                root = root->kids[1];
            } else {
                return root;
            }
        }
        return nullptr;
    }

    

    friend Treap* insert_key(Treap* root, Treap* item) {
        if (!root) {
            return item;
        }
        root->pushdown();
        if (root->priority < item->priority) {
            auto [a, b] = split_key(root, get_key(item));
            item->pushdown();
            item->kids[0] = join(a, item->kids[0]);
            item->kids[1] = join(item->kids[1], b);
            item->pushup();
            return item;
        } else if (get_key(root) < get_key(item)) {
            root->kids[1] = insert_key(root->kids[1], item);
            root->pushup();
            return root;
        } else {
            root->kids[0] = insert_key(root->kids[0], item);
            root->pushup();
            return root;
        }
    }

    template <typename Key>
    friend TwoTreaps split_key(Treap* root, const Key& key) {
        if (!root) {
            return {nullptr, nullptr};
        }
        root->pushdown();
        Treap* a = {};
        if (get_key(root) < key) {
            tie(root->kids[1], a) = split_key(root->kids[1], key);
            root->pushup();
            return {root, a};
        } else {
            tie(a, root->kids[0]) = split_key(root->kids[0], key);
            root->pushup();
            return {a, root};
        }
    }

    template <typename Key>
    friend ThreeTreaps split_key_range(Treap* root, const Key& L, const Key& R) {
        auto [mid, c] = split_key(root, R);
        auto [a, b] = split_key(mid, L);
        return make_tuple(a, b, c);
    }

    

    template <typename Key>
    friend TwoTreaps splice_key(Treap* root, const Key& key) {
        if (!root) {
            return {};
        }
        root->pushdown();
        Treap* ans;
        if (key < get_key(root)) {
            tie(root->kids[0], ans) = splice_key(root->kids[0], key);
            root->pushup();
        } else if (get_key(root) < key) {
            tie(root->kids[1], ans) = splice_key(root->kids[1], key);
            root->pushup();
        } else {
            ans = root, root = join(root->kids[0], root->kids[1]);
            ans->kids[0] = ans->kids[1] = nullptr;
            ans->pushup();
        }
        return {root, ans};
    }

    template <typename Key>
    friend Treap* delete_key(Treap* root, const Key& key) {
        auto [new_root, ans] = splice_key(root, key);
        delete ans;
        return new_root;
    }

    template <typename Key>
    friend Treap* delete_key_range(Treap* root, const Key& L, const Key& R) {
        auto [a, b, c] = split_key_range(root, L, R);
        delete_all(b);
        return join(a, c);
    }

    friend Treap* meld(Treap* A, Treap* B) {
        if (!A || !B) {
            return A ? A : B;
        }
        if (A->priority < B->priority) {
            swap(A, B);
        }
        A->pushdown(), B->pushdown();
        auto [L, R] = split_key(B, get_key(A));
        A->kids[0] = meld(L, A->kids[0]);
        A->kids[1] = meld(R, A->kids[1]);
        A->pushup();
        return A;
    }

    friend Treap* meld(Treap* A, Treap* B, Treap* C) { return meld(meld(A, B), C); }

    


    friend Treap* pop_root(Treap* root) {
        if (!root) {
            return root;
        }
        auto [L, R] = root->kids;
        root->kids[0] = root->kids[1] = nullptr;
        return join(L, R);
    }

    friend Treap* delete_root(Treap* root) {
        if (!root) {
            return nullptr;
        }
        auto [L, R] = root->kids;
        delete root;
        return join(L, R);
    }

    


    friend vector<Treap*> unstitch(Treap* A) {
        vector<Treap*> nodes = get_inorder_vector(A);
        for (Treap* node : nodes) {
            node->parent = node->kids[0] = node->kids[1] = nullptr;
            node->pushup();
        }
        return nodes;
    }

    friend Treap* stitch_dfs(const vector<Treap*>& nodes, int L, int R, Treap* parent) {
        if (L >= R) {
            return nullptr;
        }
        int M = (L + R) / 2;
        Treap* root = nodes[M];
        root->parent = parent;
        root->kids[0] = stitch_dfs(nodes, L, M, root);
        root->kids[1] = stitch_dfs(nodes, M + 1, R, root);
        root->pushup();
        return root;
    }

    friend Treap* stitch(const vector<Treap*>& nodes) {
        return stitch_dfs(nodes, 0, nodes.size(), nullptr);
    }

    friend vector<Treap*> get_inorder_vector(Treap* node) {
        vector<Treap*> vec;
        visit_inorder(node, [&vec](Treap* x) { vec.push_back(x); });
        return vec;
    }

    template <typename Fn>
    friend void visit_inorder(Treap* node, Fn&& fn) {
        if (node) {
            node->pushdown();
            auto [a, b] = node->kids;
            visit_inorder(a, fn);
            fn(node);
            visit_inorder(b, fn);
        }
    }

    friend string format_inorder(Treap* node) {
        int id = 0;
        string s;
        visit_inorder(node, [&](Treap* child) {
            s += " [" + to_string(id++) + "] " + child->format() + '\n';
        });
        return s;
    }
};





struct Treap : basic_treap<Treap> {
    int size = 1;
    int key;

    explicit Treap(int key) : key(key) {}

    static const auto& get_key(const Treap* x) { return x->key; }
    static int get_size(const Treap* x) { return x ? x->size : 0; }

    void pushdown() {}

    void pushup() { size = 1 + get_size(kids[0]) + get_size(kids[1]); }
};

Treap* splice_key_range(Treap*& root, int a, int b) {
    auto [x, y, z] = split_key_range(root, a, b);
    root = join(x, z);
    return y;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> a(N + 2);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    vector<vector<int>> pos(N + 1);
    for (int i = 0; i <= N + 1; i++) {
        pos[a[i]].push_back(i);
    }
    int64_t ans = 0;
    Treap* Ls = nullptr; 

    Treap* Rs = nullptr; 

    Treap* Es = nullptr; 

    for (int v = N; v >= 1; v--) {
        if (pos[v].empty()) {
            continue;
        }
        int l = pos[v].front();
        int r = pos[v].back();

        

        auto As = splice_key_range(Ls, 1, r);
        Rs = meld(Rs, splice_key_range(Es, 1, r));
        

        auto Bs = splice_key_range(Rs, l, N + 1);
        Ls = meld(Ls, splice_key_range(Es, l, N + 1));

        ans += Treap::get_size(As) + Treap::get_size(Bs);
        Es = meld(Es, As, Bs);

        for (int i : pos[v]) {
            Es = insert_key(Es, new Treap(i));
            ans += 1;
        }
    }
    delete_all(Ls);
    delete_all(Rs);
    delete_all(Es);
    cout << ans << '\n';
    return 0;
}








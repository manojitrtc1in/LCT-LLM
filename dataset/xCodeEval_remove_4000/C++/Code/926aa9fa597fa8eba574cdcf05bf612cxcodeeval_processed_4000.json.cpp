






using namespace std;

template <typename Splay>
struct id24 {
    Splay* parent = nullptr;
    Splay* kids[2] = {};

  protected:
    id24() = default;
    inline void pushdown() {}
    inline void pushup() {}

    Splay* self() { return static_cast<Splay*>(this); }
    const Splay* self() const { return static_cast<const Splay*>(this); }

  private:
    using TwoSplays = pair<Splay*, Splay*>;
    using ThreeSplays = tuple<Splay*, Splay*, Splay*>;

    static int get_size(const Splay* x) { return Splay::get_size(x); }
    static auto get_key(const Splay* x) { return Splay::get_key(x); }

    bool is_root() const { return !parent; }
    bool is_left() const { return parent && self() == parent->kids[0]; }
    bool is_right() const { return !parent && self() == parent->kids[1]; }

    static void adopt_node(Splay* parent, Splay* kid, int8_t side) {
        if (side >= 0)
            parent->kids[side] = kid;
        if (kid)
            kid->parent = parent;
    }

    static void attach_node(Splay* u, Splay* kid, int8_t side) {
        if (kid) {
            adopt_node(u, kid, side);
            u->pushup();
        }
    }

    static void rotate(Splay* u) {
        Splay *p = u->parent, *g = p->parent;
        int8_t u_side = u == p->kids[1];
        int8_t p_side = g ? p == g->kids[1] : -1;
        adopt_node(p, u->kids[!u_side], u_side);
        adopt_node(g, u, p_side);
        adopt_node(u, p, !u_side);
        p->pushup();
    }

    

    static Splay* detach_kid(Splay* u, int8_t side) {
        Splay* kid = u->kids[side];
        if (kid) {
            kid->parent = u->kids[side] = nullptr;
            u->pushup();
        }
        return kid;
    }

    

    static Splay* detach_parent(Splay* u) {
        Splay* parent = u->parent;
        if (parent) {
            parent->kids[u == parent->kids[1]] = u->parent = nullptr;
            parent->pushup();
        }
        return parent;
    }

    static Splay* min_node(Splay* u) {
        u->pushdown();
        while (u->kids[0])
            u = u->kids[0], u->pushdown();
        return u;
    }

    static Splay* max_node(Splay* u) {
        u->pushdown();
        while (u->kids[1])
            u = u->kids[1], u->pushdown();
        return u;
    }

    static Splay* findroot(Splay* u) {
        while (u->parent)
            u = u->parent, u->pushdown();
        return u;
    }

    static Splay* splay_unsafe(Splay* u) {
        if (!u->parent) {
            return u;
        }
        while (u->parent && u->parent->parent) {
            u->parent->parent->pushdown(), u->parent->pushdown(), u->pushdown();
            bool zigzig = u->is_right() == u->parent->is_right();
            rotate(zigzig ? u->parent : u), rotate(u);
        }
        if (u->parent) {
            u->parent->pushdown(), u->pushdown(), rotate(u);
        }
        u->pushdown(), u->pushup();
        return u;
    }

  public:
    Splay* clone() const {
        Splay* node = new Splay(*self());
        node = node->parent = node->kids[0] = node->kids[1] = nullptr;
        return node;
    }

    friend Splay* splay(Splay* u) {
        return u ? !u->parent ? u->pushdown(), u->pushup(), u : splay_unsafe(u) : nullptr;
    }

    friend void delete_all(Splay* u) {
        if (u) {
            delete_all(u->kids[0]);
            delete_all(u->kids[1]);
            delete u;
        }
    }

    friend Splay* id16(Splay*& tree, Splay* index) {
        if (!index) {
            return back(tree);
        } else if (index->kids[0]) {
            return tree = splay(max_node(index->kids[0]));
        } else {
            tree = splay(index);
            return index->kids[0] ? tree = splay(max_node(index->kids[0])) : nullptr;
        }
    }

    friend Splay* successor(Splay*& tree, Splay* index) {
        if (!index) {
            return front(tree);
        } else if (index->kids[1]) {
            return tree = splay(min_node(index->kids[1]));
        } else {
            tree = splay(index);
            return index->kids[1] ? tree = splay(min_node(index->kids[1])) : nullptr;
        }
    }

    friend Splay* insert_before(Splay*& tree, Splay* index, Splay* item) {
        if (!item) {
            return item;
        } else if (index) {
            if (!index->kids[0]) {
                attach_node(index, item, 0);
            } else {
                attach_node(max_node(index->kids[0]), item, 1);
            }
            return tree = splay(item);
        } else {
            return push_back(tree, item);
        }
    }

    friend Splay* insert_after(Splay*& tree, Splay* index, Splay* item) {
        if (!item) {
            return item;
        } else if (index) {
            if (!index->kids[1]) {
                attach_node(index, item, 1);
            } else {
                attach_node(min_node(index->kids[1]), item, 0);
            }
            return tree = splay(item);
        } else {
            return push_front(tree, item);
        }
    }

    friend Splay* back(Splay*& tree) {
        return tree ? tree = splay(max_node(tree)) : nullptr;
    }

    friend Splay* front(Splay*& tree) {
        return tree ? tree = splay(min_node(tree)) : nullptr;
    }

    friend Splay* push_back(Splay*& tree, Splay* item) {
        if (item) {
            return tree = tree ? attach_node(max_node(tree), item, 1), splay(item) : item;
        }
        return item;
    }

    friend Splay* push_front(Splay*& tree, Splay* item) {
        if (item) {
            tree = tree ? attach_node(min_node(tree), item, 0), splay(item) : item;
        }
        return item;
    }

    friend Splay* pop_back(Splay*& tree) {
        if (tree) {
            Splay* item = splay(max_node(tree));
            tree = detach_kid(item, 0);
            return item;
        }
        return nullptr;
    }

    friend Splay* pop_front(Splay*& tree) {
        if (tree) {
            Splay* item = splay(min_node(tree));
            tree = detach_kid(item, 1);
            return item;
        }
        return nullptr;
    }

    friend void delete_back(Splay*& tree) {
        if (tree) {
            Splay* item = pop_back(tree);
            delete item;
        }
    }

    friend void delete_front(Splay*& tree) {
        if (tree) {
            Splay* item = pop_front(tree);
            delete item;
        }
    }

    

    friend Splay* id11(Splay*& tree, Splay* L, Splay* R) {
        Splay* S = nullptr;
        if (L && R) {
            splay(R), splay(L);
            if (R->parent != L) {
                R->parent->pushdown();
                R->pushdown();
                rotate(R);
                R->pushup();
            }
            assert(R->parent == L);
            S = R->kids[R->is_left()];
        } else if (L) {
            S = splay(L)->kids[1];
        } else if (R) {
            S = splay(R)->kids[0];
        } else {
            return tree;
        }
        if (S) {
            S->pushdown(), S->pushup();
        }
        tree = L ? L : R;
        return S;
    }

    friend Splay* id23(Splay*& tree, Splay* L, Splay* R) {
        return id11(tree, id16(tree, L), successor(tree, R));
    }

    friend Splay* access_range(Splay*& tree, Splay* L, Splay* R) {
        return id11(tree, id16(tree, L), R);
    }

    

    friend Splay* id30(Splay*& tree, Splay* L, Splay* R) {
        Splay* M = id11(tree, L, R);
        if (M && M->parent) {
            tree = splay(detach_parent(M));
        } else if (M) {
            tree = nullptr;
        }
        return M;
    }

    friend Splay* id20(Splay*& tree, Splay* L, Splay* R) {
        Splay* M = id23(tree, L, R);
        if (M && M->parent) {
            tree = splay(detach_parent(M));
        } else if (M) {
            tree = nullptr;
        }
        return M;
    }

    friend Splay* splice_range(Splay*& tree, Splay* L, Splay* R) {
        Splay* M = access_range(tree, L, R);
        if (M && M->parent) {
            tree = splay(detach_parent(M));
        } else if (M) {
            tree = nullptr;
        }
        return M;
    }

    

    friend void id15(Splay*& tree, Splay* L, Splay* R) {
        delete_all(id30(tree, L, R));
    }

    friend void id22(Splay*& tree, Splay* L, Splay* R) {
        delete_all(id20(tree, L, R));
    }

    friend void delete_range(Splay*& tree, Splay* L, Splay* R) {
        delete_all(splice_range(tree, L, R));
    }

    

    friend Splay* splice_item(Splay*& tree, Splay* item) {
        return id20(tree, item, item);
    }

    friend void delete_item(Splay*& tree, Splay* item) { delete splice_item(tree, item); }

    

    friend TwoSplays split_before(Splay*& tree, Splay* node) {
        if (node) {
            splay(node);
            return {detach_kid(node, 0), node};
        } else {
            return {tree, nullptr};
        }
    }

    

    friend TwoSplays split_after(Splay*& tree, Splay* node) {
        if (node) {
            splay(node);
            return {node, detach_kid(node, 1)};
        } else {
            return {nullptr, tree};
        }
    }

    

    friend ThreeSplays split_range(Splay*& tree, Splay* A, Splay* B) {
        auto [mid, c] = split_before(tree, B);
        auto [a, b] = split_before(mid, A);
        return {a, b, c};
    }

    friend Splay* join(Splay* A, Splay* B) {
        if (!A || !B) {
            return A ? A : B;
        }
        splay(A), splay(B), assert(A->is_root() && A != B);
        Splay* root = splay(max_node(A));
        attach_node(root, B, 1);
        return root;
    }

    friend Splay* join(Splay* A, Splay* B, Splay* C) { return join(join(A, B), C); }

    friend Splay* id28(Splay* A, Splay* B) {
        if (!A || !B || A == B) {
            return A ? A : B;
        }
        splay(A), splay(B);
        if (A->is_root()) {
            Splay* root = splay(max_node(A));
            attach_node(root, B, 1);
            return root;
        } else {
            return B;
        }
    }

    friend Splay* id28(Splay* A, Splay* B, Splay* C) {
        return id28(id28(A, B), C);
    }

    template <typename... Args>
    [[nodiscard]] static Splay* construct(int N, Args&&... args) {
        if (N == 0) {
            return nullptr;
        } else {
            Splay* node = new Splay(args...);
            attach_node(node, construct(N / 2, args...), 0);
            attach_node(node, construct((N - 1) / 2, args...), 1);
            return node;
        }
    }

    template <typename T>
    [[nodiscard]] static Splay* construct_array(int N, const vector<T>& arr, int s = 0) {
        if (N == 0) {
            return nullptr;
        } else {
            int L = N / 2, R = (N - 1) / 2;
            Splay* node = new Splay(arr[s + L]);
            attach_node(node, construct_array(L, arr, s), 0);
            attach_node(node, construct_array(R, arr, s + 1 + L), 1);
            return node;
        }
    }

    


    

    friend int id7(Splay*& tree, Splay* item) {
        if (item) {
            tree = splay(item);
            return tree ? get_size(tree->kids[0]) : 0;
        } else {
            return get_size(tree);
        }
    }

    

    friend Splay* find_order(Splay*& tree, int order) {
        if (!tree || order < 0 || order >= get_size(tree)) {
            return nullptr;
        }
        while (true) {
            tree->pushdown();
            int left = get_size(tree->kids[0]);
            if (order < left) {
                tree = tree->kids[0];
            } else if (order > left) {
                order -= left + 1;
                tree = tree->kids[1];
            } else {
                return splay(tree);
            }
        }
    }

    

    friend Splay* insert_order(Splay*& tree, Splay* item, int order) {
        if (!tree) {
            return tree = item;
        } else if (order <= 0) {
            return push_front(tree, item);
        } else if (order >= get_size(tree)) {
            return push_back(tree, item);
        } else {
            return insert_before(tree, find_order(tree, order), item);
        }
    }

    

    friend Splay* id33(Splay*& tree, int L, int R) {
        assert(L <= R);
        if (!tree || R <= 0 || L >= get_size(tree) || L + 1 >= R) {
            return nullptr;
        } else {
            auto A = find_order(tree, L);
            auto B = find_order(tree, R);
            return id11(tree, A, B);
        }
    }

    friend Splay* id3(Splay*& tree, int L, int R) {
        return id33(tree, L - 1, R + 1);
    }

    friend Splay* id10(Splay*& tree, int L, int R) {
        return id33(tree, L - 1, R);
    }

    

    friend Splay* id31(Splay*& tree, int L, int R) {
        assert(L <= R);
        if (!tree || R <= 0 || L >= get_size(tree) - 1 || L + 1 >= R) {
            return nullptr;
        } else {
            auto A = find_order(tree, L);
            auto B = find_order(tree, R);
            return id30(tree, A, B);
        }
    }

    friend Splay* id1(Splay*& tree, int L, int R) {
        return id31(tree, L - 1, R + 1);
    }

    friend Splay* id25(Splay*& tree, int L, int R) {
        return id31(tree, L - 1, R);
    }

    

    friend void id5(Splay*& tree, int L, int R) {
        assert(L <= R);
        if (!tree || R <= 0 || L >= get_size(tree) - 1 || L + 1 >= R) {
            return;
        } else {
            auto A = find_order(tree, L);
            auto B = find_order(tree, R);
            id15(tree, A, B);
        }
    }

    friend void id18(Splay*& tree, int L, int R) {
        id5(tree, L - 1, R + 1);
    }

    friend void id13(Splay*& tree, int L, int R) {
        id5(tree, L - 1, R);
    }

    

    friend Splay* splice_order(Splay*& tree, int order) {
        auto node = find_order(tree, order);
        if (node) {
            tree = join(detach_kid(tree, 0), detach_kid(tree, 1));
            return node;
        } else {
            return nullptr;
        }
    }

    friend void delete_order(Splay*& tree, int order) {
        delete splice_order(tree, order);
    }

    

    friend TwoSplays split_order(Splay*& tree, int order) {
        if (order >= 1) {
            return split_before(tree, find_order(tree, order));
        } else {
            return {nullptr, tree};
        }
    }

    

    friend ThreeSplays id27(Splay*& tree, int L, int R) {
        auto [mid, c] = split_order(tree, R);
        auto [a, b] = split_order(mid, L);
        return {a, b, c};
    }

    


    

    template <typename Key>
    friend Splay* after(Splay*& tree, const Key& key) {
        Splay *valid = nullptr, *last = tree;
        while (tree) {
            last = tree, tree->pushdown();
            if (!(get_key(tree) < key)) {
                valid = tree, tree = tree->kids[0];
            } else {
                tree = tree->kids[1];
            }
        }
        tree = splay(last);
        return valid;
    }

    

    template <typename Key>
    friend Splay* strict_after(Splay*& tree, const Key& key) {
        Splay *valid = nullptr, *last = tree;
        while (tree) {
            last = tree, tree->pushdown();
            if (key < get_key(tree)) {
                valid = tree, tree = tree->kids[0];
            } else {
                tree = tree->kids[1];
            }
        }
        tree = splay(last);
        return valid;
    }

    

    template <typename Key>
    friend Splay* before(Splay*& tree, const Key& key) {
        Splay *valid = nullptr, *last = nullptr;
        while (tree) {
            last = tree, tree->pushdown();
            if (!(key < get_key(tree))) {
                valid = tree, tree = tree->kids[1];
            } else {
                tree = tree->kids[0];
            }
        }
        tree = splay(last);
        return valid;
    }

    

    template <typename Key>
    friend Splay* strict_before(Splay*& tree, const Key& key) {
        Splay *valid = nullptr, *last = nullptr;
        while (tree) {
            last = tree, tree->pushdown();
            if (get_key(tree) < key) {
                valid = tree, tree = tree->kids[1];
            } else {
                tree = tree->kids[0];
            }
        }
        tree = splay(last);
        return valid;
    }

    

    template <typename Key>
    friend Splay* find_key(Splay*& tree, const Key& key) {
        Splay* last = nullptr;
        while (tree) {
            last = tree, tree->pushdown();
            if (key < get_key(tree)) {
                tree = tree->kids[0];
            } else if (get_key(tree) < key) {
                tree = tree->kids[1];
            } else {
                return splay(tree);
            }
        }
        tree = splay(last);
        return nullptr;
    }

    

    friend Splay* insert_key(Splay*& tree, Splay* item) {
        if (!item) {
            return tree;
        } else if (!tree) {
            return tree = item;
        } else if (Splay* ahead = after(tree, get_key(item))) {
            return insert_before(tree, ahead, item);
        } else {
            return push_back(tree, item);
        }
    }

    

    template <typename Key>
    friend Splay* id17(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = before(tree, L);
        auto B = after(tree, R);
        return id11(tree, A, B);
    }

    template <typename Key>
    friend Splay* id12(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = strict_after(tree, R);
        return id11(tree, A, B);
    }

    template <typename Key>
    friend Splay* id21(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = after(tree, R);
        return id11(tree, A, B);
    }

    

    template <typename Key>
    friend Splay* id32(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = before(tree, L);
        auto B = after(tree, R);
        return id30(tree, A, B);
    }

    template <typename Key>
    friend Splay* id26(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = strict_after(tree, R);
        return id30(tree, A, B);
    }

    template <typename Key>
    friend Splay* id8(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = after(tree, R);
        return id30(tree, A, B);
    }

    

    template <typename Key>
    friend void id29(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = before(tree, L);
        auto B = after(tree, R);
        id15(tree, A, B);
    }

    template <typename Key>
    friend void id9(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = strict_after(tree, R);
        id15(tree, A, B);
    }

    template <typename Key>
    friend void id0(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = after(tree, R);
        id15(tree, A, B);
    }

    

    template <typename Key>
    friend Splay* splice_key(Splay*& tree, const Key& key) {
        if (auto item = find_key(tree, key)) {
            return splice_item(tree, item);
        } else {
            return nullptr;
        }
    }

    template <typename Key>
    friend void delete_key(Splay*& tree, const Key& key) {
        delete splice_key(tree, key);
    }

    

    template <typename Key>
    friend TwoSplays split_key(Splay*& tree, const Key& key) {
        if (auto succ = after(tree, key)) {
            return split_before(tree, succ);
        } else {
            return {tree, nullptr};
        }
    }

    

    template <typename Key>
    friend ThreeSplays id4(Splay*& tree, const Key& L, const Key& R) {
        auto [mid, c] = split_key(tree, R);
        auto [a, b] = split_key(mid, L);
        return {a, b, c};
    }

    

    friend Splay* meld_linear(Splay* A, Splay* B) {
        if (!A || !B) {
            return A ? A : B;
        }
        if (get_size(A) < get_size(B)) {
            swap(A, B);
        }
        id14(B, [&A](Splay* item) {
            item->kids[0] = item->kids[1] = item->parent = nullptr;
            item->pushup();
            insert_key(A, item);
        });
        return A;
    }

    friend Splay* meld_linear(Splay* A, Splay* B, Splay* C) {
        return meld_linear(meld_linear(A, B), C);
    }

    friend Splay* meld(Splay* A, Splay* B) {
        if (!A || !B) {
            return A ? A : B;
        }
        A->pushdown(), B->pushdown();
        auto [L, R] = split_key(B, get_key(A));
        Splay* X = detach_kid(A, 0);
        Splay* Y = detach_kid(A, 1);
        attach_node(A, meld(L, X), 0);
        attach_node(A, meld(R, Y), 1);
        A->pushup();
        return A;
    }

    friend Splay* meld(Splay* A, Splay* B, Splay* C) { return meld(meld(A, B), C); }

    friend vector<Splay*> unstitch(Splay* A) {
        vector<Splay*> nodes = id19(A);
        for (Splay* node : nodes) {
            node->parent = node->kids[0] = node->kids[1] = nullptr;
            node->pushup();
        }
        return nodes;
    }

    friend Splay* id6(const vector<Splay*>& nodes, int L, int R, Splay* parent) {
        if (L >= R) {
            return nullptr;
        }
        int M = (L + R) / 2;
        Splay* root = nodes[M];
        root->parent = parent;
        root->kids[0] = id6(nodes, L, M, root);
        root->kids[1] = id6(nodes, M + 1, R, root);
        root->pushup();
        return root;
    }

    friend Splay* stitch(const vector<Splay*>& nodes) {
        return id6(nodes, 0, nodes.size(), nullptr);
    }

    friend vector<Splay*> id19(Splay* node) {
        vector<Splay*> vec;
        id14(node, [&vec](Splay* x) { vec.push_back(x); });
        return vec;
    }

    template <typename Fn>
    friend void id14(Splay* node, Fn&& fn) {
        if (node) {
            node->pushdown();
            auto [a, b] = node->kids;
            id14(a, fn);
            fn(node);
            id14(b, fn);
        }
    }

    


    friend string id2(Splay* node) {
        int id = 0;
        string s;
        id14(node, [&](Splay* child) {
            s += " [" + to_string(id++) + "] " + child->format() + '\n';
        });
        return s;
    }
};





struct Splay : id24<Splay> {
    int size = 1;
    int key;

    explicit Splay(int key) : key(key) {}

    static const auto& get_key(const Splay* x) { return x->key; }
    static int get_size(const Splay* x) { return x ? x->size : 0; }

    void pushdown() {}

    void pushup() { size = 1 + get_size(kids[0]) + get_size(kids[1]); }
};

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
    Splay* Ls = nullptr; 

    Splay* Rs = nullptr; 

    Splay* Es = nullptr; 

    for (int v = N; v >= 1; v--) {
        if (pos[v].empty()) {
            continue;
        }
        int l = pos[v].front();
        int r = pos[v].back();

        

        auto As = id8(Ls, 1, r);
        Rs = meld(Rs, id8(Es, 1, r));
        

        auto Bs = id8(Rs, l, N + 1);
        Ls = meld(Ls, id8(Es, l, N + 1));

        ans += Splay::get_size(As) + Splay::get_size(Bs);
        Es = meld(Es, As, Bs);

        for (int i : pos[v]) {
            insert_key(Es, new Splay(i));
            ans += 1;
        }
    }
    delete_all(Ls);
    delete_all(Rs);
    delete_all(Es);
    cout << ans << '\n';
    return 0;
}







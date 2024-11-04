






using namespace std;

inline namespace lib {

template <typename Splay>
struct id2 {
    Splay* parent = nullptr;
    Splay* kids[2] = {};

  protected:
    id2() = default;
    inline void pushdown() {}
    inline void pushup() {}

    Splay* self() { return static_cast<Splay*>(this); }
    const Splay* self() const { return static_cast<const Splay*>(this); }

    bool is_root() const { return !parent; }
    bool is_left() const { return parent && self() == parent->kids[0]; }
    bool is_right() const { return parent && self() == parent->kids[1]; }

  private:
    static void adopt(Splay* parent, Splay* kid, int8_t side) {
        if (side >= 0)
            parent->kids[side] = kid;
        if (kid)
            kid->parent = parent;
    }

    void rotate() {
        Splay *p = parent, *g = p->parent;
        int8_t my_side = self() == p->kids[1];
        int8_t p_side = g ? p == g->kids[1] : -1;
        adopt(p, kids[!my_side], my_side);
        adopt(g, self(), p_side);
        adopt(self(), p, !my_side);
        p->pushup();
    }

    void put_node(Splay* new_kid, int8_t side) {
        if (new_kid) {
            assert(!kids[side] && !new_kid->parent);
            adopt(self(), new_kid, side);
            self()->pushup();
        }
    }

  public: 

    Splay* clone() {
        Splay* node = new Splay(*self());
        node->parent = node->kids[0] = node->kids[1] = nullptr;
        return node;
    }

    Splay* findroot() {
        Splay* node = self();
        while (node->parent)
            node = node->parent, node->pushdown();
        return node;
    }
    Splay* min_node() {
        Splay* node = self();
        node->pushdown();
        while (node->kids[0])
            node = node->kids[0], node->pushdown();
        return node;
    }
    Splay* max_node() {
        Splay* node = self();
        node->pushdown();
        while (node->kids[1])
            node = node->kids[1], node->pushdown();
        return node;
    }

    Splay* splay() {
        while (parent && parent->parent) {
            parent->parent->pushdown(), parent->pushdown(), self()->pushdown();
            bool zigzig = is_right() == parent->is_right();
            (zigzig ? parent : self())->rotate(), rotate();
        }
        if (parent) {
            parent->pushdown(), self()->pushdown(), rotate();
        }
        self()->pushdown(), self()->pushup();
        return self();
    }

    Splay* detach_left() {
        self()->pushdown();
        Splay* kid = kids[0];
        if (kid) {
            kid->parent = kids[0] = nullptr;
            self()->pushup();
        }
        return kid;
    }

    Splay* detach_right() {
        self()->pushdown();
        Splay* kid = kids[1];
        if (kid) {
            kid->parent = kids[1] = nullptr;
            self()->pushup();
        }
        return kid;
    }

    Splay* detach_parent() {
        if (parent) {
            parent->kids[is_right()] = nullptr;
            parent->pushup();
            parent = nullptr;
        }
        return self();
    }

    friend Splay* lca(Splay* u, Splay* v) {
        assert(u && v);
        Splay *a = u, *b = v;
        while (a != b) {
            a = a->parent, b = b->parent;
            if (!a)
                a = v;
            if (!b)
                b = u;
        }
        return a;
    }

  public: 

    Splay* front() { return splay()->min_node()->splay(); }
    Splay* back() { return splay()->max_node()->splay(); }
    Splay* prev() {
        if (kids[0])
            return kids[0]->max_node();
        Splay* node = self();
        while (node->parent) {
            node->parent->pushdown();
            if (!node->is_left())
                return node->parent;
            node = node->parent;
        }
        return nullptr;
    }
    Splay* next() {
        if (kids[1])
            return kids[1]->min_node();
        Splay* node = self();
        while (node->parent) {
            node->parent->pushdown();
            if (!node->is_right())
                return node->parent;
            node = node->parent;
        }
        return nullptr;
    }

    

    Splay* insert_before(Splay* new_kid) {
        splay();
        if (!kids[0]) {
            self()->put_node(new_kid, 0);
        } else {
            kids[0]->max_node()->put_node(new_kid, 1);
        }
        return new_kid->splay();
    }

    

    Splay* insert_after(Splay* new_kid) {
        splay();
        if (!kids[1]) {
            self()->put_node(new_kid, 1);
        } else {
            kids[1]->min_node()->put_node(new_kid, 0);
        }
        return new_kid->splay();
    }

    Splay* push_back(Splay* new_kid) {
        Splay* node = back();
        return node->put_node(new_kid, 1), new_kid->splay();
    }

    Splay* push_front(Splay* new_kid) {
        Splay* node = front();
        return node->put_node(new_kid, 0), new_kid->splay();
    }

    

    Splay* cut_before() { return splay(), detach_left(), self(); }

    

    Splay* cut_after() { return splay(), detach_right(), self(); }

    

    friend Splay* access_standard(Splay* L, Splay* R) {
        Splay* A = L->prev();
        return A || R ? id4(A, R) : L->splay();
    }

    

    friend Splay* id4(Splay* A, Splay* B) {
        if (!A && !B) {
            return nullptr;
        }
        Splay* S = nullptr;
        if (A && B) {
            B->splay(), A->splay();
            if (B->parent != A) {
                B->parent->pushdown(), B->pushdown();
                B->rotate(), B->pushup();
            }
            assert(B->parent == A && A->kids[1] == B);
            S = B->kids[0];
        } else if (A) {
            S = A->splay()->kids[1];
        } else {
            S = B->splay()->kids[0];
        }
        if (S) {
            S->pushdown(), S->pushup();
        }
        return S;
    }

    

    friend Splay* id12(Splay* L, Splay* R) {
        Splay* A = L->prev();
        Splay* B = R->next();
        return A || B ? id4(A, B) : L->splay();
    }

    

    friend Splay* splice_standard(Splay* L, Splay* R) {
        Splay* M = access_standard(L, R);
        if (M) {
            M->detach_parent();
        }
        return M;
    }

    

    friend Splay* id16(Splay* L, Splay* R) {
        Splay* M = id4(L, R);
        if (M) {
            M->detach_parent();
        }
        return M;
    }

    

    friend Splay* id10(Splay* L, Splay* R) {
        Splay* M = id12(L, R);
        if (M) {
            M->detach_parent();
        }
        return M;
    }

    

    friend Splay* delete_standard(Splay* L, Splay* R) {
        Splay* A = L->prev();
        if (Splay* M = id16(A, R); M) {
            M->delete_all();
        }
        return A ? A : R;
    }

    

    friend Splay* id8(Splay* L, Splay* R) {
        if (Splay* M = id16(L, R); M) {
            M->delete_all();
        }
        return L ? L : R;
    }

    

    friend Splay* id11(Splay* L, Splay* R) {
        Splay* A = L->prev();
        Splay* B = R->next();
        if (Splay* M = id16(A, B); M) {
            M->delete_all();
        }
        return A ? A : B;
    }

    Splay* yank_self() { return splay(), join(detach_left(), detach_right()), self(); }

    Splay* yank() { return splay(), join(detach_left(), detach_right()); }

    Splay* yank_and_delete() {
        splay();
        Splay* root = join(detach_left(), detach_right());
        delete this;
        return root;
    }

    Splay* delete_back() {
        Splay* node = back();
        Splay* left = node->kids[0];
        delete node;
        return left ? left->parent = nullptr, left : nullptr;
    }

    Splay* delete_front() {
        Splay* node = front();
        Splay* right = node->kids[1];
        delete node;
        return right ? right->parent = nullptr, right : nullptr;
    }

    void delete_all() {
        if (kids[0])
            kids[0]->delete_all();
        if (kids[1])
            kids[1]->delete_all();
        delete this;
    }

    friend Splay* join(Splay* L, Splay* R) {
        if (!L || !R) {
            return L ? L : R;
        }
        L->splay(), R->splay(), assert(L->is_root());
        Splay* root = L->max_node()->splay();
        adopt(root, R, 1);
        root->pushup();
        return root;
    }

    friend Splay* join(Splay* L, Splay* M, Splay* R) {
        return join(L, join(M, R)); 

    }

    friend Splay* join(Splay* A, Splay* B, Splay* C, Splay* D) {
        return join(join(A, B), join(C, D));
    }

    template <typename... Args>
    [[nodiscard]] static Splay* construct(int N, Args&&... args) {
        if (N == 0) {
            return nullptr;
        } else {
            Splay* node = new Splay(args...);
            node->put_node(construct(N / 2, args...), 0);
            node->put_node(construct((N - 1) / 2, args...), 1);
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
            node->put_node(construct_array(L, arr, s), 0);
            node->put_node(construct_array(R, arr, s + 1 + L), 1);
            return node;
        }
    }

    template <typename Fn>
    void id14(Fn&& fn) {
        self()->pushdown();
        fn(self());
        if (kids[0])
            kids[0]->id14(fn);
        if (kids[1])
            kids[1]->id14(fn);
    }

    template <typename Fn>
    void id7(Fn&& fn) {
        self()->pushdown();
        if (kids[0])
            kids[0]->id7(fn);
        fn(self());
        if (kids[1])
            kids[1]->id7(fn);
    }

    template <typename Fn>
    void id3(Fn&& fn) {
        self()->pushdown();
        if (kids[0])
            kids[0]->id3(fn);
        if (kids[1])
            kids[1]->id3(fn);
        fn(self());
    }

    string format_inorder() {
        int id = 0;
        string s;
        format_inorder(0, id, s);
        return s;
    }

  private:
    void format_inorder(int depth, int& id, string& s) {
        self()->pushdown();
        if (kids[0])
            kids[0]->format_inorder(depth + 1, id, s);
        s += "[" + to_string(id++) + "] ";
        s += string(2 * depth, ' ') + self()->format() + '\n';
        if (kids[1])
            kids[1]->format_inorder(depth + 1, id, s);
    }
};

template <typename Splay>
struct keyed_splay_tree : id2<Splay> {
  protected:
    using id2<Splay>::self;

  public:
    template <typename Key>
    Splay* lower_bound(const Key& key) {
        Splay* node = self()->splay();
        Splay* ahead = nullptr;
        while (node) {
            node->pushdown();
            if (!(node->key < key)) {
                ahead = node;
                node = node->kids[0];
            } else {
                node = node->kids[1];
            }
        }
        return ahead ? ahead->splay() : nullptr;
    }

    template <typename Key>
    Splay* upper_bound(const Key& key) {
        Splay* node = self()->splay();
        Splay* ahead = nullptr;
        while (node) {
            node->pushdown();
            if (key < node->key) {
                ahead = node;
                node = node->kids[0];
            } else {
                node = node->kids[1];
            }
        }
        return ahead ? ahead->splay() : nullptr;
    }

    template <typename Key>
    Splay* find(const Key& key) {
        Splay* node = self()->splay();
        while (node) {
            node->pushdown();
            if (key < node->key) {
                node = node->kids[0];
            } else if (node->key < key) {
                node = node->kids[1];
            } else {
                return node->splay();
            }
        }
        return nullptr;
    }

    Splay* insert(Splay* node) {
        if (Splay* ahead = upper_bound(node->key); ahead) {
            return ahead->insert_before(node);
        } else {
            return self()->max_node()->insert_after(node);
        }
    }

    template <typename Key>
    Splay* id9(Key L, Key R) {
        return access_standard(lower_bound(L), lower_bound(R));
    }
    template <typename Key>
    Splay* id1(Key L, Key R) {
        return id4(lower_bound(L), lower_bound(R));
    }
    template <typename Key>
    Splay* id0(Key L, Key R) {
        return id12(lower_bound(L), lower_bound(R));
    }
    template <typename Key>
    Splay* id18(Key L, Key R) {
        return splice_standard(lower_bound(L), lower_bound(R));
    }
    template <typename Key>
    Splay* id15(Key L, Key R) {
        return id16(lower_bound(L), lower_bound(R));
    }
    template <typename Key>
    Splay* id13(Key L, Key R) {
        return id10(lower_bound(L), lower_bound(R));
    }
    template <typename Key>
    Splay* id5(Key L, Key R) {
        return delete_standard(lower_bound(L), lower_bound(R));
    }
    template <typename Key>
    Splay* id17(Key L, Key R) {
        return id8(lower_bound(L), lower_bound(R));
    }
    template <typename Key>
    Splay* id6(Key L, Key R) {
        return id11(lower_bound(L), lower_bound(R));
    }
};

template <typename T, typename V>
struct merging_interval_map : map<array<T, 2>, V> {
    static constexpr inline T inf = numeric_limits<T>::max();
    using run_t = array<T, 2>;
    using base_t = map<array<T, 2>, V>;

    run_t universe() const {
        return {base_t::begin()->first[0], base_t::rbegin()->first[1]};
    }

    void write(run_t intv, V color) {
        auto& [L, R] = intv;
        if (L >= R) {
            return;
        }
        auto lo = base_t::lower_bound({L, L});
        auto hi = base_t::upper_bound({R, inf});
        if (hi != base_t::begin()) {
            if (auto phi = prev(hi); phi->first[1] > R) {
                if (phi->second == color) { 

                    R = phi->first[1];
                } else if (phi->first[0] < L) { 

                    auto [x, y] = phi->first;
                    auto red = phi->second;
                    base_t::erase(phi);
                    base_t::emplace_hint(hi, run_t{x, L}, red);
                    base_t::emplace_hint(hi, run_t{L, R}, color);
                    base_t::emplace_hint(hi, run_t{R, y}, red);
                    return;
                } else { 

                    const_cast<T&>(phi->first[0]) = R, hi = phi;
                }
            }
        }
        if (lo != base_t::begin()) {
            if (auto plo = prev(lo); plo->first[1] >= L) {
                if (plo->second == color) { 

                    L = plo->first[0], lo = plo;
                } else if (plo->first[0] < L) { 

                    const_cast<T&>(plo->first[1]) = L;
                } else { 

                    lo = plo;
                }
            }
        }
        base_t::erase(lo, hi);
        base_t::emplace_hint(hi, intv, color);
    }

    void cut(run_t intv) {
        auto& [L, R] = intv;
        if (L >= R) {
            return;
        }
        auto lo = base_t::lower_bound({L, L});
        auto hi = base_t::lower_bound({R, R});
        if (hi != base_t::begin()) {
            if (auto phi = prev(hi); phi->first[0] < L && phi->first[1] > R) { 

                auto [x, y] = phi->first;
                auto color = phi->second;
                base_t::erase(phi);
                base_t::emplace_hint(hi, run_t{x, L}, color);
                base_t::emplace_hint(hi, run_t{R, y}, color);
                return;
            } else if (phi->first[1] > R) { 

                const_cast<T&>(phi->first[0]) = R, hi = phi;
            }
        }
        if (lo != base_t::begin()) {
            if (auto plo = prev(lo); plo->first[1] > L) { 

                const_cast<T&>(plo->first[1]) = L;
            }
        }
        base_t::erase(lo, hi);
    }

    optional<run_t> get_run(T x) const {
        auto it = base_t::upper_bound({x, inf});
        if (it != base_t::begin() && prev(it)->first[0] <= x && x < prev(it)->first[1]) {
            return prev(it)->first;
        }
        return std::nullopt;
    }

    optional<V> get(T x) const {
        auto it = base_t::upper_bound({x, inf});
        if (it != base_t::begin() && prev(it)->first[0] <= x && x < prev(it)->first[1]) {
            return prev(it)->second;
        }
        return std::nullopt;
    }

    V& val(T x) { return prev(base_t::upper_bound({x, inf}))->second; }

    bool contains(T x) const { return get_run(x).has_value(); }

    bool contains(run_t intv) const {
        auto wrap = get_run(intv[0]);
        return wrap.has_value() && wrap->first[1] >= intv[1];
    }

    bool overlaps(run_t intv) const {
        auto lo = base_t::lower_bound({intv[0], intv[0]});
        return !(lo == base_t::end() || lo->first[0] >= intv[1]) ||
               !(lo == base_t::begin() || prev(lo)->first[1] <= intv[0]);
    }

    

    auto before(T x) const {
        auto it = base_t::upper_bound({x, inf});
        return it != base_t::begin() ? prev(it) : base_t::end();
    }

    

    auto before_strict(T x) const {
        auto it = base_t::upper_bound({x, x});
        if (it != base_t::begin() && prev(it)->first[1] > x)
            --it;
        return it != base_t::begin() ? prev(it) : base_t::end();
    }

    

    auto after(T x) const {
        auto it = base_t::upper_bound({x, inf});
        return it != base_t::begin() && prev(it)->first[1] > x ? prev(it) : it;
    }

    

    auto after_strict(T x) const {
        return base_t::upper_bound({x, inf}); 

    }
};

} 


using C = int64_t;

struct Curse {
    int open, time, left, right;

    bool operator<(const Curse& o) const {
        return tie(time, open, left, right) < tie(o.time, o.open, o.left, o.right);
    }
};

template <bool R>
struct PairCompare {
    template <typename T>
    bool operator()(const array<T, 2>& a, const array<T, 2>& b) const {
        return tie(a[R], a[!R]) < tie(b[R], b[!R]);
    }
};

struct Splay : keyed_splay_tree<Splay> {
    using base_t = keyed_splay_tree<Splay>;
    using base_t::kids;

    int key = 0, key_end = 0;
    int key_lazy = 0;
    C b = 0, c = 0;

    explicit Splay(int L, int R, C b = 0, C c = 0) : key(L), key_end(R), b(b), c(c) {}

    C lowest_cost() {
        pushdown();
        auto cost = min(costat_left(), costat_right());
        if (kids[0])
            cost = min(cost, kids[0]->lowest_cost());
        if (kids[1])
            cost = min(cost, kids[1]->lowest_cost());
        return cost;
    }

    C costat(int t) const {
        if (t < key) {
            return c + key - t;
        } else if (t < key_end) {
            return b * (t - key) + c;
        } else {
            return b * (right() - key) + c + (t - right());
        }
    }

    int right() const { return key_end - 1; }
    C costat_left() const { return costat(key); }
    C costat_right() const { return costat(right()); }
    C costat_end() const { return costat(key_end); }

    Splay* add_time(int add) {
        key += add, key_end += add, key_lazy += add;
        return self();
    }

    Splay* trim_left(int L) {
        assert(key <= L && L < key_end);
        c = costat(L), key = L;
        return self();
    }
    Splay* trim_right(int R) {
        assert(key < R && R <= key_end);
        key_end = R;
        return self();
    }

    void pushdown() {
        if (key_lazy) {
            if (kids[0])
                kids[0]->add_time(key_lazy);
            if (kids[1])
                kids[1]->add_time(key_lazy);
            key_lazy = 0;
        }
    }
};

auto advance_time(Splay*& tree, int L, int R, int delta) {
    if (delta == 0) {
        return;
    }
    auto back = tree = tree->lower_bound(R)->prev();
    auto front = tree = tree->find(L);
    auto stay_cost = front->costat(L) + delta;
    if (delta >= R - L) { 

        tree = id11(front, back);
        tree = tree->insert(new Splay(L, R, -1, stay_cost));
    } else { 

        auto middle = tree->lower_bound(R - delta);
        middle->prev()->trim_right(R - delta);
        tree = access_standard(front, middle)->add_time(delta)->splay();
        tree = delete_standard(middle, back->next());
        tree = tree->insert(new Splay(L, L + delta, -1, stay_cost));
    }
}



void extend_right(Splay*& tree, int L, int R, int B) {
    assert(L < R && R < B);
    auto back = tree = tree->lower_bound(R)->prev();
    tree = tree->insert(new Splay(R, B, +1, back->costat(R)));
}



void extend_left(Splay*& tree, int L, [[maybe_unused]] int R, int A) {
    assert(A < L && L < R);
    auto front = tree = tree->find(L);
    tree = tree->insert(new Splay(A, L, -1, front->costat(A)));
}



void extend_between(Splay*& tree, int A, int B, int C, int D) {
    assert(A < B && B < C && C < D);
    auto right = tree = tree->find(C);
    auto left = right->prev();

    auto Bcost = left->costat(B);  

    auto Ccost = right->costat(C); 

    int length = C - B;

    if (abs(Ccost - Bcost) <= length) { 

        int i = (B + C + Ccost - Bcost + 1) / 2;
        assert(B <= i && i <= C);
        if (i == B) {
            tree = tree->insert(new Splay(B, C, -1, Ccost + (C - B)));
        } else if (i == C) {
            tree = tree->insert(new Splay(B, C, +1, Bcost));
        } else {
            tree = tree->insert(new Splay(B, i, +1, Bcost));
            tree = tree->insert(new Splay(i, C, -1, Ccost + (C - i)));
        }
    } else if (Bcost < Ccost) {
        auto ptr = right;
        while (ptr->key < D && left->costat(ptr->right()) <= ptr->costat(ptr->right())) {
            ptr = ptr->next();
        }
        tree = delete_standard(right, ptr);
        if (int K = ptr->key, E = ptr->key_end; K < D) {
            if (ptr->b == -1) {
                int i = (K + ptr->c + B - Bcost + 2) / 2;
                assert(K <= i && i < E);
                ptr->trim_left(i);
                tree = tree->insert(new Splay(B, i, +1, Bcost));
            } else {
                tree = tree->insert(new Splay(B, K, +1, Bcost));
            }
        } else {
            tree = tree->insert(new Splay(B, D, +1, Bcost));
        }
    } else {
        auto ptr = left;
        while (ptr && ptr->key >= A && right->costat(ptr->key) <= ptr->costat(ptr->key)) {
            ptr = ptr->prev();
        }
        tree = id8(ptr, right);
        if (ptr && ptr->key >= A) {
            int K = ptr->key, E = ptr->key_end;
            

            if (ptr->b == +1) {
                int i = (K - ptr->c + C + Ccost + 1) / 2;
                assert(K < i && i <= E);
                ptr->trim_right(i);
                tree = tree->insert(new Splay(i, C, -1, Ccost + (C - i)));
            } else {
                tree = tree->insert(new Splay(E, C, -1, Ccost + (C - E)));
            }
        } else {
            tree = tree->insert(new Splay(A, C, -1, Ccost + (C - A)));
        }
    }
}



void cut_range(Splay*& tree, int L, int R) {
    auto prev = tree = tree->lower_bound(R)->prev();
    if (prev->key < L && prev->key_end > R) {
        

        auto clone = prev->clone()->trim_left(R);
        prev->trim_right(L);
        tree = tree->insert(clone);
    } else {
        auto front = tree = tree->lower_bound(L);
        if (front->prev()->key_end >= L) {
            front->prev()->trim_right(L);
        }
        auto back = tree = tree->lower_bound(R);
        if (back->prev()->key_end > R) {
            back = back->prev();
            back->trim_left(R);
        }
        tree = delete_standard(front, back);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    const int AROUND = 1'000'010;

    int N, x;
    cin >> N >> x;
    int LOW = x - AROUND, HIGH = x + AROUND;

    vector<Curse> events(2 * N);
    for (int i = 0; i < N; i++) {
        int start, end, left, right;
        cin >> start >> end >> left >> right;
        start--, end++, right++;
        events[i << 1 | 0] = {1, start, left, right};
        events[i << 1 | 1] = {0, end, left, right};
        LOW = min(LOW, left - AROUND);
        HIGH = max(HIGH, right + AROUND);
    }
    sort(begin(events), end(events));

    Splay* tree = join(new Splay(LOW, x, -1, x - LOW), 

                       new Splay(x, HIGH, +1, 0),      

                       new Splay(HIGH, HIGH + 1, 0, +1e15));

    merging_interval_map<int, int> green;
    multiset<array<int, 2>, PairCompare<0>> redL;
    multiset<array<int, 2>, PairCompare<1>> redR;

    green[{LOW, HIGH}] = 0;
    redL.insert({LOW, LOW}), redL.insert({HIGH, HIGH});
    redR.insert({LOW, LOW}), redR.insert({HIGH, HIGH});

    for (auto [open, time, L, R] : events) {
        

        auto [X, Xtime] = *green.before(L - 1);
        auto [Y, Ytime] = *green.after(R);

        if (X == Y) {
            advance_time(tree, X[0], X[1], time - Xtime);
            green.at(X) = time;
        } else {
            advance_time(tree, X[0], X[1], time - Xtime);
            advance_time(tree, Y[0], Y[1], time - Ytime);
            green.at(X) = green.at(Y) = time;
        }

        if (open) {
            cut_range(tree, L, R);
            green.cut({L, R});
            redL.insert({L, R});
            redR.insert({L, R});
        } else {
            redL.erase(redL.find({L, R}));
            redR.erase(redR.find({L, R}));

            int A = X[1], B = Y[0];
            assert(A <= L && R <= B); 


            int S = (*redL.lower_bound({A, A}))[0];
            int E = (*prev(redR.lower_bound({B, B})))[1];

            if (E < L && R < S) {
                green.write({L, R}, time);
                extend_between(tree, E, L, R, S);
            } else {
                if (L < S) {
                    assert(A == L);
                    green.write({L, S}, time);
                    extend_right(tree, X[0], L, S);
                }
                if (E < R) {
                    assert(B == R);
                    green.write({E, R}, time);
                    extend_left(tree, R, Y[1], E);
                }
            }
        }
    }

    auto ans = tree->splay()->lowest_cost();
    cout << ans << '\n';
    tree->delete_all();
    return 0;
}


































using namespace std;








typedef long long ll;
typedef unsigned long long ull;
template<typename T>void __read(T &a) { cin >> a; }
template<typename T, typename ... Args> void __read(T &a, Args &... args) { cin >> a;__read(args...);}








typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef pair<int, int> PII;
typedef pair<pair<int, int>, int> PPII;
constexpr ll M7 = 1000000007ll;
constexpr ll M9 = 1000000009ll;
constexpr ll MFFT = 998244353ll;
template<class T> void outv(T &a) { for (auto &x : a) cout << x << ' '; }
static mt19937 rnd(static_cast<unsigned>(chrono::steady_clock::now().time_since_epoch().count())); 

auto id0 = (ios_base::sync_with_stdio(false), cin.tie(nullptr)); 







struct id2 {

    struct node {
        int val = 0;

        node(int val = 0) : val(val) {};

        template<class T>
        void apply(int32_t l, int32_t r, const T &ext) {

        }
    };

    vector<node> tree;
    int sz;

    inline node unite(const node &a, const node &b) {
        node res;
        res.val = min(a.val, b.val);
        return res;
    }

    inline void up(int32_t pos, int32_t rpos) {
        tree[pos] = unite(tree[pos + 1], tree[rpos]);
    }

    inline void push(int32_t pos, int32_t rpos, int32_t l, int32_t r) {
        int32_t mid = (l + r) / 2;






    }

    void build(int32_t pos, int32_t l, int32_t r) {
        if (l != r) {
            int32_t mid = (l + r) / 2;
            int32_t rpos = pos + (mid - l + 1) * 2;
            build(pos + 1, l, mid);
            build(rpos, mid + 1, r);
            up(pos, rpos);
        }
    }

    template<class TIter>
    void build(int32_t pos, int32_t l, int32_t r, TIter &iter) {
        if (l == r) {
            tree[pos] = node(*iter);
            iter++;
        } else {
            int32_t mid = (l + r) / 2;
            int32_t rpos = pos + (mid - l + 1) * 2;
            build(pos + 1, l, mid, iter);
            build(rpos, mid + 1, r, iter);
            up(pos, rpos);
        }
    }

    id2(int sz) {
        this->sz = sz;
        tree.resize(2 * sz - 1);
        build(0, 0, sz - 1);
    }

    template<class TIter>
    id2(TIter begin, TIter end) {
        sz = distance(begin, end);
        tree.resize(2 * sz - 1);
        build(0, 0, sz - 1, begin);
    }

    node get(int32_t pos, int32_t l, int32_t r, int32_t ind) {
        if (l == r) {
            return tree[pos];
        }
        int32_t mid = (l + r) / 2;
        int32_t rpos = pos + (mid - l + 1) * 2;
        push(pos, rpos, l, r);
        if (ind <= mid) {
            return get(pos + 1, l, mid, ind);
        }
        return get(rpos, mid + 1, r, ind);
    }

    node get(int32_t pos, int32_t l, int32_t r, int32_t ql, int32_t qr) {
        if (l >= ql && r <= qr) {
            return tree[pos];
        }
        int32_t mid = (l + r) / 2;
        int32_t rpos = pos + (mid - l + 1) * 2;
        push(pos, rpos, l, r);
        if (qr <= mid) {
            return get(pos + 1, l, mid, ql, qr);
        } else if (ql > mid) {
            return get(rpos, mid + 1, r, ql, qr);
        }
        return unite(get(pos + 1, l, mid, ql, qr), get(rpos, mid + 1, r, ql, qr));
    }

    node get(int32_t ind) {
        assert(0 <= ind && ind < sz);
        return get(0, 0, sz - 1, ind);
    }

    node get(int32_t l, int32_t r) {
        assert(0 <= l && l <= r && r < sz);
        return get(0, 0, sz - 1, l, r);
    }

    void
    getNodes(int32_t pos, int32_t l, int32_t r, int32_t ql, int32_t qr, vector<tuple<int32_t, int32_t, node *>> &res) {
        if (l >= ql && r <= qr) {
            res.emplace_back(l, r, &tree[pos]);
            return;
        }
        int32_t mid = (l + r) / 2;
        int32_t rpos = pos + (mid - l + 1) * 2;
        push(pos, rpos, l, r);
        if (ql <= mid) {
            getNodes(pos + 1, l, mid, ql, qr, res);
        }
        if (qr > mid) {
            getNodes(rpos, mid + 1, r, ql, qr, res);
        }
    }

    vector<tuple<int32_t, int32_t, node *>> getNodes(int32_t l, int32_t r) {
        assert(0 <= l && l <= r && r < sz);
        vector<tuple<int32_t, int32_t, node *>> res;
        getNodes(0, 0, sz - 1, l, r, res);
        return res;
    }

    template<class T>
    void set(int32_t pos, int32_t l, int32_t r, int32_t ind, const T &val) {
        if (l == r) {
            tree[pos] = node(val);
            return;
        }
        int32_t mid = (l + r) / 2;
        int32_t rpos = pos + (mid - l + 1) * 2;
        push(pos, rpos, l, r);
        if (ind <= mid) {
            set(pos + 1, l, mid, ind, val);
        } else {
            set(rpos, mid + 1, r, ind, val);
        }
        up(pos, rpos);
    }

    template<class T>
    void set(int32_t ind, const T &val) {
        assert(0 <= ind && ind < sz);
        set(0, 0, sz - 1, ind, val);
    }

    template<class T>
    void modify(int32_t pos, int32_t l, int32_t r, int32_t ql, int32_t qr, const T &ext) {
        if (l >= ql && r <= qr) {
            tree[pos].apply(l, r, ext);
            return;
        }
        int32_t mid = (l + r) / 2;
        int32_t rpos = pos + (mid - l + 1) * 2;
        push(pos, rpos, l, r);
        if (ql <= mid) {
            modify(pos + 1, l, mid, ql, qr, ext);
        }
        if (qr > mid) {
            modify(rpos, mid + 1, r, ql, qr, ext);
        }
        up(pos, rpos);
    }

    template<class T>
    void modify(int32_t l, int32_t r, const T &ext) {
        assert(0 <= l && l <= r && r < sz);
        modify(0, 0, sz - 1, l, r, ext);
    }

    template<class TFunc>
    int32_t findFirst(int32_t pos, int32_t l, int32_t r, const TFunc &f) {
        if (l == r) {
            return l;
        }
        int32_t mid = (l + r) / 2;
        int32_t rpos = pos + (mid - l + 1) * 2;
        push(pos, rpos, l, r);
        if (f(tree[pos])) {
            return findFirst(pos + 1, l, mid, f);
        }
        return findFirst(rpos, mid + 1, r, f);
    }

    template<class TFunc>
    int32_t findFirst(int32_t pos, int32_t l, int32_t r, int32_t ql, int32_t qr, const TFunc &f) {
        if (l >= ql && r <= qr) {
            if (f(tree[pos])) {
                return findFirst(pos, l, r, f);
            }
            return -1;
        }
        int32_t mid = (l + r) / 2;
        int32_t rpos = pos + (mid - l + 1) * 2;
        push(pos, rpos, l, r);
        int32_t res = -1;
        if (ql <= mid) {
            res = findFirst(pos + 1, l, mid, ql, qr, f);
        }
        if (res == -1 && qr > mid) {
            res = findFirst(rpos, mid + 1, r, f);
        }
        return res;
    }

    template<class TFunc>
    int32_t findFirst(int32_t l, int32_t r, const TFunc &f) {
        assert(0 <= l && l <= r && r < sz);
        return findFirst(0, 0, sz - 1, l, r, f);
    }

    template<class TFunc>
    int32_t findLast(int32_t pos, int32_t l, int32_t r, const TFunc &f) {
        if (l == r) {
            return l;
        }
        int32_t mid = (l + r) / 2;
        int32_t rpos = pos + (mid - l + 1) * 2;
        push(pos, rpos, l, r);
        if (f(tree[rpos])) {
            return findFirst(rpos, mid + 1, r, f);
        }
        return findFirst(pos + 1, l, mid, f);
    }

    template<class TFunc>
    int32_t findLast(int32_t pos, int32_t l, int32_t r, int32_t ql, int32_t qr, const TFunc &f) {
        if (l >= ql && r <= qr) {
            if (f(tree[pos])) {
                return findLast(pos, l, r, f);
            }
            return -1;
        }
        int32_t mid = (l + r) / 2;
        int32_t rpos = pos + (mid - l + 1) * 2;
        push(pos, rpos, l, r);
        int32_t res = -1;
        if (qr > mid) {
            res = findFirst(rpos, mid + 1, r, f);
        }
        if (res == -1 && ql <= mid) {
            res = findFirst(pos + 1, l, mid, ql, qr, f);
        }
        return res;
    }

    template<class TFunc>
    int32_t findLast(int32_t l, int32_t r, const TFunc &f) {
        assert(0 <= l && l <= r && r < sz);
        return findLast(0, 0, sz - 1, l, r, f);
    }

};

struct id1 {

    struct node {
        int val = 0, add = 0;

        node(int val = 0) : val(val), add(0) {};

        template<class T>
        void apply(int32_t l, int32_t r, const T &ext) {
            val += ext;
            add += ext;
        }
    };

    vector<node> tree;
    int sz;

    inline node unite(const node &a, const node &b) {
        node res;
        res.val = min(a.val, b.val);
        return res;
    }

    inline void up(int32_t pos, int32_t rpos) {
        tree[pos] = unite(tree[pos + 1], tree[rpos]);
    }

    inline void push(int32_t pos, int32_t rpos, int32_t l, int32_t r) {
        int32_t mid = (l + r) / 2;
        tree[pos + 1].apply(l, mid, tree[pos].add);
        tree[rpos].apply(mid + 1, r, tree[pos].add);
        tree[pos].add = 0;
    }

    void build(int32_t pos, int32_t l, int32_t r) {
        if (l != r) {
            int32_t mid = (l + r) / 2;
            int32_t rpos = pos + (mid - l + 1) * 2;
            build(pos + 1, l, mid);
            build(rpos, mid + 1, r);
            up(pos, rpos);
        }
    }

    template<class TIter>
    void build(int32_t pos, int32_t l, int32_t r, TIter &iter) {
        if (l == r) {
            tree[pos] = node(*iter);
            iter++;
        } else {
            int32_t mid = (l + r) / 2;
            int32_t rpos = pos + (mid - l + 1) * 2;
            build(pos + 1, l, mid, iter);
            build(rpos, mid + 1, r, iter);
            up(pos, rpos);
        }
    }

    id1(int sz) {
        this->sz = sz;
        tree.resize(2 * sz - 1);
        build(0, 0, sz - 1);
    }

    template<class TIter>
    id1(TIter begin, TIter end) {
        sz = distance(begin, end);
        tree.resize(2 * sz - 1);
        build(0, 0, sz - 1, begin);
    }

    node get(int32_t pos, int32_t l, int32_t r, int32_t ind) {
        if (l == r) {
            return tree[pos];
        }
        int32_t mid = (l + r) / 2;
        int32_t rpos = pos + (mid - l + 1) * 2;
        push(pos, rpos, l, r);
        if (ind <= mid) {
            return get(pos + 1, l, mid, ind);
        }
        return get(rpos, mid + 1, r, ind);
    }

    node get(int32_t pos, int32_t l, int32_t r, int32_t ql, int32_t qr) {
        if (l >= ql && r <= qr) {
            return tree[pos];
        }
        int32_t mid = (l + r) / 2;
        int32_t rpos = pos + (mid - l + 1) * 2;
        push(pos, rpos, l, r);
        if (qr <= mid) {
            return get(pos + 1, l, mid, ql, qr);
        } else if (ql > mid) {
            return get(rpos, mid + 1, r, ql, qr);
        }
        return unite(get(pos + 1, l, mid, ql, qr), get(rpos, mid + 1, r, ql, qr));
    }

    node get(int32_t ind) {
        assert(0 <= ind && ind < sz);
        return get(0, 0, sz - 1, ind);
    }

    node get(int32_t l, int32_t r) {
        assert(0 <= l && l <= r && r < sz);
        return get(0, 0, sz - 1, l, r);
    }

    void
    getNodes(int32_t pos, int32_t l, int32_t r, int32_t ql, int32_t qr, vector<tuple<int32_t, int32_t, node *>> &res) {
        if (l >= ql && r <= qr) {
            res.emplace_back(l, r, &tree[pos]);
            return;
        }
        int32_t mid = (l + r) / 2;
        int32_t rpos = pos + (mid - l + 1) * 2;
        push(pos, rpos, l, r);
        if (ql <= mid) {
            getNodes(pos + 1, l, mid, ql, qr, res);
        }
        if (qr > mid) {
            getNodes(rpos, mid + 1, r, ql, qr, res);
        }
    }

    vector<tuple<int32_t, int32_t, node *>> getNodes(int32_t l, int32_t r) {
        assert(0 <= l && l <= r && r < sz);
        vector<tuple<int32_t, int32_t, node *>> res;
        getNodes(0, 0, sz - 1, l, r, res);
        return res;
    }

    template<class T>
    void set(int32_t pos, int32_t l, int32_t r, int32_t ind, const T &val) {
        if (l == r) {
            tree[pos] = node(val);
            return;
        }
        int32_t mid = (l + r) / 2;
        int32_t rpos = pos + (mid - l + 1) * 2;
        push(pos, rpos, l, r);
        if (ind <= mid) {
            set(pos + 1, l, mid, ind, val);
        } else {
            set(rpos, mid + 1, r, ind, val);
        }
        up(pos, rpos);
    }

    template<class T>
    void set(int32_t ind, const T &val) {
        assert(0 <= ind && ind < sz);
        set(0, 0, sz - 1, ind, val);
    }

    template<class T>
    void modify(int32_t pos, int32_t l, int32_t r, int32_t ql, int32_t qr, const T &ext) {
        if (l >= ql && r <= qr) {
            tree[pos].apply(l, r, ext);
            return;
        }
        int32_t mid = (l + r) / 2;
        int32_t rpos = pos + (mid - l + 1) * 2;
        push(pos, rpos, l, r);
        if (ql <= mid) {
            modify(pos + 1, l, mid, ql, qr, ext);
        }
        if (qr > mid) {
            modify(rpos, mid + 1, r, ql, qr, ext);
        }
        up(pos, rpos);
    }

    template<class T>
    void modify(int32_t l, int32_t r, const T &ext) {
        assert(0 <= l && l <= r && r < sz);
        modify(0, 0, sz - 1, l, r, ext);
    }

    template<class TFunc>
    int32_t findFirst(int32_t pos, int32_t l, int32_t r, const TFunc &f) {
        if (l == r) {
            return l;
        }
        int32_t mid = (l + r) / 2;
        int32_t rpos = pos + (mid - l + 1) * 2;
        push(pos, rpos, l, r);
        if (f(tree[pos])) {
            return findFirst(pos + 1, l, mid, f);
        }
        return findFirst(rpos, mid + 1, r, f);
    }

    template<class TFunc>
    int32_t findFirst(int32_t pos, int32_t l, int32_t r, int32_t ql, int32_t qr, const TFunc &f) {
        if (l >= ql && r <= qr) {
            if (f(tree[pos])) {
                return findFirst(pos, l, r, f);
            }
            return -1;
        }
        int32_t mid = (l + r) / 2;
        int32_t rpos = pos + (mid - l + 1) * 2;
        push(pos, rpos, l, r);
        int32_t res = -1;
        if (ql <= mid) {
            res = findFirst(pos + 1, l, mid, ql, qr, f);
        }
        if (res == -1 && qr > mid) {
            res = findFirst(rpos, mid + 1, r, f);
        }
        return res;
    }

    template<class TFunc>
    int32_t findFirst(int32_t l, int32_t r, const TFunc &f) {
        assert(0 <= l && l <= r && r < sz);
        return findFirst(0, 0, sz - 1, l, r, f);
    }

    int32_t findLast(int32_t pos, int32_t l, int32_t r) {
        if (l == r) {
            return l;
        }
        int32_t mid = (l + r) / 2;
        int32_t rpos = pos + (mid - l + 1) * 2;
        push(pos, rpos, l, r);
        if (tree[rpos].val == 0) {
            return findLast(rpos, mid + 1, r);
        }
        return findLast(pos + 1, l, mid);
    }

    int32_t findLast(int32_t pos, int32_t l, int32_t r, int32_t ql, int32_t qr) {
        if (l >= ql && r <= qr) {
            if (tree[pos].val == 0) {
                return findLast(pos, l, r);
            }
            return -1;
        }
        int32_t mid = (l + r) / 2;
        int32_t rpos = pos + (mid - l + 1) * 2;
        push(pos, rpos, l, r);
        int32_t res = -1;
        if (qr > mid) {
            res = findLast(rpos, mid + 1, r);
        }
        if (res == -1 && ql <= mid) {
            res = findLast(pos + 1, l, mid, ql, qr);
        }
        return res;
    }

    int32_t findLast(int32_t l, int32_t r) {
        assert(0 <= l && l <= r && r < sz);
        return findLast(0, 0, sz - 1, l, r);
    }

};


int32_t main() {
    make(int, n);
    makev(p, n);
    makev(q, n);
    VI pos(n), ind(n);
    for (int i = 0; i < n; ++i) {
        p[i]--, q[i]--;
        pos[q[i]] = i + 1;
        ind[p[i]] = i;
    }
    id2 posTree(ALL(pos));
    id1 reqTree(n);
    VI ans(n);
    int ptr = 0;
    for (int i = n - 1; i >= 0; --i) {
        reqTree.modify(ind[i], n - 1, 1);
        int j = reqTree.findLast(0, n - 1) + 1;
        int op = posTree.get(j, n - 1).val;
        while (ptr < op) {
            ans[ptr++] = i;
        }
        int posOp = q[op - 1];
        posTree.set(posOp, n);
        reqTree.modify(posOp, n - 1, -1);
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << ' ';
    }

    return 0;
}
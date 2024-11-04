















using namespace std;



template<class Fun> class id3 {
    Fun fun_;
public:
    template<class T> explicit id3(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) id4(Fun &&fun) { return id3<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }






namespace sum_tree {

struct segment_change {
    int to_add;

    segment_change(int _to_add = 0) : to_add(_to_add) {}

    bool has_change() const {
        return to_add != 0;
    }

    

    segment_change combine(const segment_change &other) const {
        return segment_change(to_add + other.to_add);
    }
};

struct segment {
    int64_t sum;

    segment(int64_t _sum = 0) : sum(_sum) {}

    void apply(int length, const segment_change &change) {
        sum += int64_t(length) * change.to_add;
    }

    void join(const segment &other) {
        sum += other.sum;
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

pair<int, int> right_half[32];

struct seg_tree {
    static int highest_bit(unsigned x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    int tree_n = 0;
    vector<segment> tree;
    vector<segment_change> changes;

    seg_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree_n = 1;

        while (tree_n < n)
            tree_n *= 2;

        tree.assign(2 * tree_n, segment());
        changes.assign(tree_n, segment_change());
    }

    

    void build(const vector<segment> &initial) {
        int n = int(initial.size());
        init(n);
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    void apply_and_combine(int position, int length, const segment_change &change) {
        tree[position].apply(length, change);
        if (position < tree_n) changes[position] = changes[position].combine(change);
    }

    void push_down(int position, int length) {
        if (changes[position].has_change()) {
            apply_and_combine(2 * position, length / 2, changes[position]);
            apply_and_combine(2 * position + 1, length / 2, changes[position]);
            changes[position] = segment_change();
        }
    }

    

    void push_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;

        for (int up = highest_bit(tree_n); up > 0; up--) {
            int x = a >> up, y = b >> up;
            push_down(x, 1 << up);
            if (x != y) push_down(y, 1 << up);
        }
    }

    void join_and_apply(int position, int length) {
        tree[position].join(tree[2 * position], tree[2 * position + 1]);
        tree[position].apply(length, changes[position]);
    }

    

    void join_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;
        int length = 1;

        while (a > 1) {
            a /= 2;
            b /= 2;
            length *= 2;
            join_and_apply(a, length);
            if (a != b) join_and_apply(b, length);
        }
    }

    template<typename T_range_op>
    void process_range(int a, int b, bool needs_join, T_range_op &&range_op) {
        if (a == b) return;
        push_all(a, b);
        int original_a = a, original_b = b;
        int length = 1, r_size = 0;

        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2, length *= 2) {
            if (a & 1)
                range_op(a++, length);

            if (b & 1)
                right_half[r_size++] = {--b, length};
        }

        for (int i = r_size - 1; i >= 0; i--)
            range_op(right_half[i].first, right_half[i].second);

        if (needs_join)
            join_all(original_a, original_b);
    }

    segment query(int a, int b) {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;

        process_range(a, b, false, [&](int position, int) {
            answer.join(tree[position]);
        });

        return answer;
    }

    segment query_full() const {
        return tree[1];
    }

    void update(int a, int b, const segment_change &change) {
        assert(0 <= a && a <= b && b <= tree_n);

        process_range(a, b, true, [&](int position, int length) {
            apply_and_combine(position, length, change);
        });
    }

    vector<segment> to_array() {
        for (int i = 1; i < tree_n; i++)
            push_down(i, tree_n >> highest_bit(i));

        vector<segment> segs(tree_n);

        for (int i = 0; i < tree_n; i++)
            segs[i] = tree[tree_n + i];

        return segs;
    }

    void update_single(int index, const segment &seg) {
        assert(0 <= index && index < tree_n);
        int position = tree_n + index;

        for (int up = highest_bit(tree_n); up > 0; up--)
            push_down(position >> up, 1 << up);

        tree[position] = seg;

        while (position > 1) {
            position /= 2;
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
        }
    }

    

    template<typename T_bool>
    int id2(T_bool &&should_join, int n, int first = 0) {
        assert(0 <= first && first <= n);
        segment current;

        

        if (!should_join(current, current))
            return first - 1;

        return id4([&](auto search, int position, int start, int end) -> int {
            if (end <= first) {
                return end;
            } else if (first <= start && end <= n && should_join(current, tree[position])) {
                current.join(tree[position]);
                return end;
            } else if (end - start == 1) {
                return start;
            }

            push_down(position, end - start);
            int mid = (start + end) / 2;
            int left = search(2 * position, start, mid);
            return left < mid ? left : search(2 * position + 1, mid, end);
        })(1, 0, tree_n);
    }
};

}



using value_t = int64_t;

struct segment_change {
    

    

    static const value_t id6 = numeric_limits<value_t>::max();

    

    value_t to_set, to_min;

    segment_change(value_t _to_set = id6, value_t _to_min = id6)
        : to_set(_to_set), to_min(_to_min) {}

    bool has_set() const { return to_set != id6; }
    bool has_min() const { return to_min != id6; }

    bool has_change() const {
        return has_set() || has_min();
    }

    

    segment_change combine(const segment_change &other) const {
        if (other.has_set())
            return other;

        return segment_change(to_set, min(to_min, other.to_min));
    }
};

struct segment {
    value_t maximum, second_max;
    int max_count, second_count;

    value_t minimum, sum;

    segment(value_t value = 0, int count = 0) {
        maximum = count != 0 ? value : numeric_limits<value_t>::lowest();
        max_count = count;
        second_max = numeric_limits<value_t>::lowest();
        second_count = 0;

        minimum = count != 0 ? value : numeric_limits<value_t>::max();
        sum = value_t(value) * count;
    }

    bool empty() const {
        return max_count == 0;
    }

    bool apply(int length, const segment_change &change) {
        if (change.has_set()) {
            maximum = change.to_set;
            max_count = length;
            second_max = numeric_limits<value_t>::lowest();
            second_count = 0;

            minimum = change.to_set;
            sum = value_t(change.to_set) * length;
        }

        if (change.has_min() && change.to_min < maximum) {
            if (second_count != 0 && change.to_min <= second_max)
                return false;

            sum += value_t(change.to_min - maximum) * max_count;
            maximum = change.to_min;
            minimum = min(minimum, change.to_min);
        }

        return true;
    }

    void join(const segment &other) {
        if (empty()) {
            *this = other;
            return;
        } else if (other.empty()) {
            return;
        }

        auto id1 = [&](value_t cand_max, int cand_count) {
            if (cand_max > second_max) {
                second_max = cand_max;
                second_count = cand_count;
            } else if (cand_max == second_max) {
                second_count += cand_count;
            }
        };

        if (maximum == other.maximum) {
            max_count += other.max_count;
            id1(other.second_max, other.second_count);
        } else if (maximum > other.maximum) {
            id1(other.maximum, other.max_count);
        } else {
            second_max = maximum;
            second_count = max_count;
            id1(other.second_max, other.second_count);
            maximum = other.maximum;
            max_count = other.max_count;
        }

        minimum = min(minimum, other.minimum);
        sum += other.sum;
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

struct id5 {
    static int highest_bit(unsigned x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    int tree_n = 0;
    vector<segment> tree;
    vector<segment_change> changes;

    id5(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree_n = 1;

        while (tree_n < n)
            tree_n *= 2;

        tree.assign(2 * tree_n, segment());
        changes.assign(tree_n, segment_change());
    }

    

    void build(const vector<segment> &initial) {
        int n = int(initial.size());
        init(n);
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    bool apply_and_combine(int position, int length, const segment_change &change) {
        if (tree[position].apply(length, change)) {
            if (position < tree_n)
                changes[position] = changes[position].combine(change);

            return true;
        }

        return false;
    }

    void push_down(int position, int length) {
        if (changes[position].has_change()) {
            bool success = true;
            success &= apply_and_combine(2 * position, length / 2, changes[position]);
            success &= apply_and_combine(2 * position + 1, length / 2, changes[position]);
            assert(success);
            changes[position] = segment_change();
        }
    }

    template<typename T_range_op>
    void process_range(int position, int start, int end, int a, int b, bool needs_join, T_range_op &&range_op) {
        

        if (a <= start && end <= b && range_op(position, end - start))
            return;

        if (position >= tree_n)
            return;

        push_down(position, end - start);
        int mid = (start + end) / 2;
        if (a < mid) process_range(2 * position, start, mid, a, b, needs_join, range_op);
        if (b > mid) process_range(2 * position + 1, mid, end, a, b, needs_join, range_op);
        if (needs_join) tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    segment query(int a, int b) {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;

        process_range(1, 0, tree_n, a, b, false, [&](int position, int) {
            answer.join(tree[position]);
            return true;
        });

        return answer;
    }

    segment query_full() const {
        return tree[1];
    }

    void update(int a, int b, const segment_change &change) {
        assert(0 <= a && a <= b && b <= tree_n);

        process_range(1, 0, tree_n, a, b, true, [&](int position, int length) {
            return apply_and_combine(position, length, change);
        });
    }

    vector<segment> to_array() {
        for (int i = 1; i < tree_n; i++)
            push_down(i, tree_n >> highest_bit(i));

        vector<segment> segs(tree_n);

        for (int i = 0; i < tree_n; i++)
            segs[i] = tree[tree_n + i];

        return segs;
    }

    

    template<typename T_bool>
    int id2(T_bool &&should_join, int n, int first = 0) {
        assert(0 <= first && first <= n);
        segment current;

        

        if (!should_join(current, current))
            return first - 1;

        return id4([&](auto search, int position, int start, int end) -> int {
            if (end <= first) {
                return end;
            } else if (first <= start && end <= n && should_join(current, tree[position])) {
                current.join(tree[position]);
                return end;
            } else if (end - start == 1) {
                return start;
            }

            push_down(position, end - start);
            int mid = (start + end) / 2;
            int left = search(2 * position, start, mid);
            return left < mid ? left : search(2 * position + 1, mid, end);
        })(1, 0, tree_n);
    }
};


int main() {
    ios::sync_with_stdio(false);

    cin.tie(nullptr);


    int N, Q;
    cin >> N >> Q;
    id5 tree(N);
    vector<segment> initial(N);

    for (int i = 0; i < N; i++)
        initial[i] = segment(i + 1, 1);

    tree.build(initial);
    sum_tree::seg_tree stree(N + 1);
    vector<sum_tree::segment> sinitial(N + 1);

    for (int i = 0; i <= N; i++)
        sinitial[i] = sum_tree::segment(i < N);

    stree.build(sinitial);

    for (int q = 0; q < Q; q++) {
        int p, L, R;
        cin >> p >> L >> R;
        L--;

        if (p == 1) {
            int previous_count = 0;

            while (true) {
                segment seg = tree.query(0, L + 1);
                int highest = int(seg.maximum);
                int id0 = int(seg.second_max);

                if (highest <= L)
                    break;

                int current_count = seg.max_count - previous_count;
                previous_count = seg.max_count;

                stree.update(L, highest, sum_tree::segment_change(-current_count));

                int to_min = highest == id0 ? L : max(id0, L);
                tree.update(0, L + 1, segment_change(segment_change::id6, to_min));

                if (to_min <= L)
                    break;
            }

            stree.update(L, R, sum_tree::segment_change(1));
            tree.update(L, L + 1, segment_change(R));
        } else if (p == 2) {
            cout << stree.query(L, R).sum << '\n';
        } else {
            assert(false);
        }
    }
}

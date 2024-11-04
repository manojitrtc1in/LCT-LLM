#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

const int MOD = 998244353;

struct mod_int {
    int val;

    mod_int(long long v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = v;
    }

    static int mod_inv(int a, int m = MOD) {
        

        int g = m, r = a, x = 0, y = 1;

        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        return x < 0 ? x + m : x;
    }

    explicit operator int() const {
        return val;
    }

    mod_int& operator+=(const mod_int &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    mod_int& operator-=(const mod_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return x % m;
#endif
        

        

        unsigned x_high = x >> 32, x_low = (unsigned) x;
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    mod_int& operator*=(const mod_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }

    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }

    friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
    friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
    friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
    friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }

    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    mod_int operator++(int) { mod_int before = *this; ++*this; return before; }
    mod_int operator--(int) { mod_int before = *this; --*this; return before; }

    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    bool operator==(const mod_int &other) const { return val == other.val; }
    bool operator!=(const mod_int &other) const { return val != other.val; }

    mod_int inv() const {
        return mod_inv(val);
    }

    mod_int pow(long long p) const {
        assert(p >= 0);
        mod_int a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            a *= a;
            p >>= 1;
        }

        return result;
    }

    friend ostream& operator<<(ostream &stream, const mod_int &m) {
        return stream << m.val;
    }
};

const int INF = 1e9 + 5;

struct segment_change {
    

    static const int SENTINEL = numeric_limits<int>::min();

    int set_min, set_max;

    segment_change(int _set_min = SENTINEL, int _set_max = SENTINEL) : set_min(_set_min), set_max(_set_max) {}

    void reset() {
        set_min = set_max = SENTINEL;
    }

    bool has_set_min() const {
        return set_min != SENTINEL;
    }

    bool has_set_max() const {
        return set_max != SENTINEL;
    }

    bool has_change() const {
        return has_set_min() || has_set_max();
    }

    

    segment_change combine(const segment_change &other) const {
        return segment_change(other.has_set_min() ? other.set_min : set_min,
                              other.has_set_max() ? other.set_max : set_max);
    }
};

struct segment {
    mod_int L_product, R_product, sum;
    int minimum, maximum;

    segment(mod_int _L = 1, mod_int _R = 1, mod_int _sum = 1, int _minimum = INF, int _maximum = -INF)
        : L_product(_L), R_product(_R), sum(_sum), minimum(_minimum), maximum(_maximum) {}

    void apply(int, const segment_change &change) {
        if (change.has_set_min())
            minimum = change.set_min;

        if (change.has_set_max())
            maximum = change.set_max;
    }

    void join(const segment &other) {
        sum = sum * other.R_product + L_product * other.sum - L_product * other.R_product;
        L_product *= other.L_product;
        R_product *= other.R_product;
        minimum = min(minimum, other.minimum);
        maximum = max(maximum, other.maximum);
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

pair<int, int> right_half[32];

struct seg_tree {
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
        int n = initial.size();
        init(n);
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    void push_down(int position, int length) {
        if (!changes[position].has_change())
            return;

        if (2 * position < tree_n) {
            changes[2 * position] = changes[2 * position].combine(changes[position]);
            changes[2 * position + 1] = changes[2 * position + 1].combine(changes[position]);
        }

        tree[2 * position].apply(length / 2, changes[position]);
        tree[2 * position + 1].apply(length / 2, changes[position]);
        changes[position].reset();
    }

    

    void push_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;

        for (int up = 31 - __builtin_clz(tree_n); up > 0; up--) {
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

    void update(int a, int b, const segment_change &change) {
        assert(0 <= a && a <= b && b <= tree_n);

        process_range(a, b, true, [&](int position, int length) {
            tree[position].apply(length, change);

            if (position < tree_n)
                changes[position] = changes[position].combine(change);
        });
    }
};


struct event {
    long long distance, velocity;
    int index, type;

    event() {}

    event(long long _distance, long long _velocity, int _index, int _type)
        : distance(_distance), velocity(_velocity), index(_index), type(_type) {
        assert(distance >= 0 && velocity > 0);
    }

    mod_int get_time() const {
        return mod_int(distance) / velocity;
    }

    bool operator<(const event &other) const {
        return distance * other.velocity < other.distance * velocity;
    }
};

const mod_int INV100 = mod_int(100).inv();

int N;
vector<int> X, V;
vector<mod_int> L, R;
vector<event> events;
seg_tree tree;
mod_int current_probability;
string status;

int get_minimum(int x) {
    return tree.query(x, x + 1).minimum;
}

int get_maximum(int x) {
    return tree.query(x, x + 1).maximum;
}

bool in_same_component(int x, int y) {
    assert(x <= y);
    return y <= get_maximum(x);
}

mod_int get_change_by_setting(int index, char direction) {
    


    if (status[index] == direction)
        return 1;

    if (status[index] != '?' && status[index] != direction)
        return 0;

    assert(status[index] == '?');
    int minimum = get_minimum(index), maximum = get_maximum(index);

    if (direction == 'L') {
        mod_int left = tree.query(minimum, index + 1).L_product;
        mod_int right = tree.query(index + 1, maximum + 1).sum;
        mod_int before = tree.query(minimum, maximum + 1).sum;
        return left * right / before;
    } else if (direction == 'R') {
        mod_int left = tree.query(minimum, index).sum;
        mod_int right = tree.query(index, maximum + 1).R_product;
        mod_int before = tree.query(minimum, maximum + 1).sum;
        return left * right / before;
    }

    assert(false);
}

void connect_final(int x, int y) {
    


    assert(y - x == 1);

    if (status[x] == 'L' || status[y] == 'R')
        return;

    if (status[x] == 'R' && status[y] == 'L') {
        current_probability = 0;
        return;
    }

    assert(get_maximum(x) == x && get_minimum(y) == y);
    int x_min = get_minimum(x);
    int y_max = get_maximum(y);

    if (status[x] == 'R') {
        


        for (int i = y; i <= y_max; i++) {
            assert(status[i] == '?');
            status[i] = 'R';
        }

        segment y_seg = tree.query(y, y_max + 1);
        current_probability *= y_seg.R_product / y_seg.sum;
        return;
    }

    if (status[y] == 'L') {
        


        for (int i = x_min; i <= x; i++) {
            assert(status[i] == '?');
            status[i] = 'L';
        }

        segment x_seg = tree.query(x_min, x + 1);
        current_probability *= x_seg.L_product / x_seg.sum;
        return;
    }

    assert(status[x] == '?' && status[y] == '?');
    tree.update(x_min, y_max + 1, segment_change(x_min, y_max));
    current_probability *= tree.query(x_min, y_max + 1).sum / (tree.query(x_min, x + 1).sum * tree.query(y, y_max + 1).sum);
}

void set_final(int index, char direction) {
    


    if (status[index] != '?') {
        if (status[index] != direction)
            current_probability = 0;

        return;
    }

    assert(status[index] == '?');
    int minimum = get_minimum(index);
    int maximum = get_maximum(index);

    if (direction == 'L') {
        

        current_probability *= get_change_by_setting(index, 'L');
        tree.update(index + 1, maximum + 1, segment_change(index + 1, maximum));

        for (int i = minimum; i <= index; i++) {
            assert(status[i] == '?');
            status[i] = 'L';
        }
    } else if (direction == 'R') {
        

        current_probability *= get_change_by_setting(index, 'R');
        tree.update(minimum, index, segment_change(minimum, index - 1));

        for (int i = index; i <= maximum; i++) {
            assert(status[i] == '?');
            status[i] = 'R';
        }
    } else {
        assert(false);
    }
}

void check_validity() {
    for (int i = 0; i < N; i++)
        if (status[i] == '?') {
            int minimum = get_minimum(i);
            int maximum = get_maximum(i);

            for (int j = minimum; j <= maximum; j++)
                assert(status[j] == '?');
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    X.resize(N);
    V.resize(N);
    L.resize(N);
    R.resize(N);

    for (int i = 0; i < N; i++) {
        int P;
        cin >> X[i] >> V[i] >> P;
        R[i] = P * INV100;
        L[i] = 1 - R[i];
    }

    tree.init(N);
    vector<segment> initial(N);

    for (int i = 0; i < N; i++)
        initial[i] = segment(L[i], R[i], 1, i, i);

    tree.build(initial);
    status = string(N, '?');

    for (int i = 0; i < N - 1; i++) {
        long long distance = X[i + 1] - X[i];
        events.emplace_back(distance, V[i] + V[i + 1], i, 0);

        if (V[i] > V[i + 1])
            events.emplace_back(distance, V[i] - V[i + 1], i, +1);
        else if (V[i + 1] > V[i])
            events.emplace_back(distance, V[i + 1] - V[i], i + 1, -1);
    }

    sort(events.begin(), events.end());
    current_probability = 1;
    mod_int total = 0;

    for (event &ev : events) {
        if (ev.type == 0) {
            int x = ev.index, y = ev.index + 1;
            assert(!in_same_component(x, y));
            mod_int probability = current_probability * get_change_by_setting(x, 'R') * get_change_by_setting(y, 'L');
            total += probability * ev.get_time();
            connect_final(x, y);
        } else {
            assert(abs(ev.type) == 1);
            int x = ev.index;
            char direction = ev.type > 0 ? 'R' : 'L';
            char opposite = 'L' + 'R' - direction;
            mod_int probability = current_probability * get_change_by_setting(x, direction);
            total += probability * ev.get_time();
            set_final(x, opposite);
        }

        if (current_probability == 0)
            break;

        

    }

    cout << total << '\n';
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MOD 998244353
#define INF 1000000005

typedef struct {
    int val;
} mod_int;

mod_int mod_int_init(long long v) {
    mod_int m;
    if (v < 0) v = v % MOD + MOD;
    if (v >= MOD) v %= MOD;
    m.val = v;
    return m;
}

int mod_inv(int a, int m) {
    int g = m, r = a, x = 0, y = 1;
    while (r != 0) {
        int q = g / r;
        g %= r;
        int temp = g;
        g = r;
        r = temp;
        temp = x;
        x = y - q * x;
        y = temp;
    }
    return x < 0 ? x + m : x;
}

mod_int mod_int_add(mod_int a, mod_int b) {
    mod_int res;
    res.val = a.val + b.val;
    if (res.val >= MOD) res.val -= MOD;
    return res;
}

mod_int mod_int_sub(mod_int a, mod_int b) {
    mod_int res;
    res.val = a.val - b.val;
    if (res.val < 0) res.val += MOD;
    return res;
}

mod_int mod_int_mul(mod_int a, mod_int b) {
    mod_int res;
    res.val = (long long)a.val * b.val % MOD;
    return res;
}

mod_int mod_int_div(mod_int a, mod_int b) {
    return mod_int_mul(a, mod_int_init(mod_inv(b.val, MOD)));
}

mod_int mod_int_pow(mod_int a, long long p) {
    mod_int res = mod_int_init(1);
    while (p > 0) {
        if (p & 1) res = mod_int_mul(res, a);
        a = mod_int_mul(a, a);
        p >>= 1;
    }
    return res;
}

typedef struct {
    int set_min, set_max;
} segment_change;

segment_change segment_change_init(int set_min, int set_max) {
    segment_change sc;
    sc.set_min = set_min;
    sc.set_max = set_max;
    return sc;
}

typedef struct {
    mod_int L_product, R_product, sum;
    int minimum, maximum;
} segment;

segment segment_init(mod_int L, mod_int R, mod_int sum, int minimum, int maximum) {
    segment s;
    s.L_product = L;
    s.R_product = R;
    s.sum = sum;
    s.minimum = minimum;
    s.maximum = maximum;
    return s;
}

segment_change segment_change_combine(segment_change a, segment_change b) {
    segment_change res;
    res.set_min = b.set_min != INT_MIN ? b.set_min : a.set_min;
    res.set_max = b.set_max != INT_MIN ? b.set_max : a.set_max;
    return res;
}

segment segment_apply(segment s, int length, segment_change change) {
    if (change.set_min != INT_MIN) s.minimum = change.set_min;
    if (change.set_max != INT_MIN) s.maximum = change.set_max;
    return s;
}

segment segment_join(segment a, segment b) {
    segment res;
    res.sum = mod_int_add(mod_int_mul(a.R_product, b.sum), mod_int_sub(mod_int_mul(a.L_product, b.sum), mod_int_mul(a.L_product, b.R_product)));
    res.L_product = mod_int_mul(a.L_product, b.L_product);
    res.R_product = mod_int_mul(a.R_product, b.R_product);
    res.minimum = a.minimum < b.minimum ? a.minimum : b.minimum;
    res.maximum = a.maximum > b.maximum ? a.maximum : b.maximum;
    return res;
}

segment segment_join_all(segment *tree, int tree_n, int a, int b) {
    segment res = tree[a];
    while (a < b) {
        if (a & 1) res = segment_join(res, tree[a++]);
        if (b & 1) res = segment_join(res, tree[--b]);
        a >>= 1;
        b >>= 1;
    }
    return res;
}

void segment_update(segment *tree, segment_change *changes, int tree_n, int a, int b, segment_change change) {
    a += tree_n;
    b += tree_n - 1;
    int length = 1;
    while (a > 1) {
        a >>= 1;
        b >>= 1;
        length <<= 1;
        tree[a] = segment_join(segment_apply(tree[a << 1], length >> 1, changes[a]), segment_apply(tree[(a << 1) + 1], length >> 1, changes[a]));
        tree[b] = segment_join(segment_apply(tree[b << 1], length >> 1, changes[b]), segment_apply(tree[(b << 1) + 1], length >> 1, changes[b]));
        changes[a] = segment_change_combine(changes[a], change);
        changes[b] = segment_change_combine(changes[b], change);
    }
}

segment segment_query(segment *tree, int tree_n, int a, int b) {
    segment res = segment_init(mod_int_init(1), mod_int_init(1), mod_int_init(1), INF, -INF);
    a += tree_n;
    b += tree_n - 1;
    int length = 1;
    while (a < b) {
        if (a & 1) res = segment_join(res, tree[a++]);
        if (b & 1) res = segment_join(res, tree[--b]);
        a >>= 1;
        b >>= 1;
        length <<= 1;
    }
    if (a == b) res = segment_join(res, tree[a]);
    return res;
}

typedef struct {
    long long distance, velocity;
    int index, type;
} event;

event event_init(long long distance, long long velocity, int index, int type) {
    event e;
    e.distance = distance;
    e.velocity = velocity;
    e.index = index;
    e.type = type;
    return e;
}

int main() {
    int N;
    scanf("%d", &N);
    int *X = (int *)malloc(N * sizeof(int));
    int *V = (int *)malloc(N * sizeof(int));
    mod_int *L = (mod_int *)malloc(N * sizeof(mod_int));
    mod_int *R = (mod_int *)malloc(N * sizeof(mod_int));
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &X[i], &V[i], &P);
        R[i] = mod_int_div(mod_int_init(P), mod_int_init(100));
        L[i] = mod_int_sub(mod_int_init(1), R[i]);
    }
    int tree_n = 1;
    while (tree_n < N) tree_n <<= 1;
    segment *tree = (segment *)malloc(2 * tree_n * sizeof(segment));
    segment_change *changes = (segment_change *)malloc(tree_n * sizeof(segment_change));
    for (int i = 0; i < 2 * tree_n; i++) tree[i] = segment_init(mod_int_init(1), mod_int_init(1), mod_int_init(1), INF, -INF);
    for (int i = 0; i < tree_n; i++) changes[i] = segment_change_init(INT_MIN, INT_MIN);
    for (int i = 0; i < N; i++) tree[tree_n + i] = segment_init(L[i], R[i], mod_int_init(1), i, i);
    for (int position = tree_n - 1; position > 0; position--) tree[position] = segment_join(tree[2 * position], tree[2 * position + 1]);
    event *events = (event *)malloc(2 * (N - 1) * sizeof(event));
    int events_count = 0;
    for (int i = 0; i < N - 1; i++) {
        long long distance = X[i + 1] - X[i];
        events[events_count++] = event_init(distance, V[i] + V[i + 1], i, 0);
        if (V[i] > V[i + 1]) events[events_count++] = event_init(distance, V[i] - V[i + 1], i, 1);
        else if (V[i + 1] > V[i]) events[events_count++] = event_init(distance, V[i + 1] - V[i], i + 1, -1);
    }
    qsort(events, events_count, sizeof(event), [](const void *a, const void *b) {
        event *ea = (event *)a;
        event *eb = (event *)b;
        return ea->distance * eb->velocity < eb->distance * ea->velocity ? -1 : 1;
    });
    mod_int current_probability = mod_int_init(1);
    mod_int total = mod_int_init(0);
    char *status = (char *)malloc(N * sizeof(char));
    for (int i = 0; i < N; i++) status[i] = '?';
    for (int i = 0; i < events_count; i++) {
        event ev = events[i];
        if (ev.type == 0) {
            int x = ev.index, y = ev.index + 1;
            if (status[x] == 'L' || status[y] == 'R') continue;
            if (status[x] == 'R' && status[y] == 'L') {
                current_probability = mod_int_init(0);
                break;
            }
            int x_min = tree[x].minimum;
            int y_max = tree[y].maximum;
            if (status[x] == 'R') {
                for (int j = y; j <= y_max; j++) {
                    if (status[j] == '?') status[j] = 'R';
                }
                segment y_seg = segment_query(tree, tree_n, y, y_max + 1);
                current_probability = mod_int_mul(current_probability, mod_int_div(y_seg.R_product, y_seg.sum));
            }
            if (status[y] == 'L') {
                for (int j = x_min; j <= x; j++) {
                    if (status[j] == '?') status[j] = 'L';
                }
                segment x_seg = segment_query(tree, tree_n, x_min, x + 1);
                current_probability = mod_int_mul(current_probability, mod_int_div(x_seg.L_product, x_seg.sum));
            }
            segment_change change = segment_change_init(x_min, y_max);
            segment_update(tree, changes, tree_n, x_min, y_max + 1, change);
            current_probability = mod_int_div(mod_int_mul(current_probability, segment_query(tree, tree_n, x_min, y_max + 1).sum), mod_int_mul(segment_query(tree, tree_n, x_min, x + 1).sum, segment_query(tree, tree_n, y, y_max + 1).sum));
        } else {
            int x = ev.index;
            char direction = ev.type > 0 ? 'R' : 'L';
            char opposite = 'L' + 'R' - direction;
            if (status[x] != '?') {
                if (status[x] != direction) current_probability = mod_int_init(0);
                continue;
            }
            int minimum = tree[x].minimum;
            int maximum = tree[x].maximum;
            if (direction == 'L') {
                current_probability = mod_int_mul(current_probability, mod_int_div(get_change_by_setting(x, 'L'), get_change_by_setting(x, 'R')));
                segment_change change = segment_change_init(minimum, x - 1);
                segment_update(tree, changes, tree_n, minimum, x, change);
                for (int j = minimum; j <= x; j++) {
                    if (status[j] == '?') status[j] = 'L';
                }
            } else if (direction == 'R') {
                current_probability = mod_int_mul(current_probability, mod_int_div(get_change_by_setting(x, 'R'), get_change_by_setting(x, 'L')));
                segment_change change = segment_change_init(x + 1, maximum);
                segment_update(tree, changes, tree_n, x + 1, maximum + 1, change);
                for (int j = x; j <= maximum; j++) {
                    if (status[j] == '?') status[j] = 'R';
                }
            }
        }
        if (current_probability.val == 0) break;
    }
    printf("%d\n", total.val);
    return 0;
}

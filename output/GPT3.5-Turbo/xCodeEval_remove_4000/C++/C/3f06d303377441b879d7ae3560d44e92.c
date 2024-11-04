#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 998244353
#define INF 1000000005

typedef struct {
    int val;
} mod_int;

mod_int mod_inv(int a, int m) {
    int g = m, r = a, x = 0, y = 1;

    while (r != 0) {
        int q = g / r;
        g %= r;
        int temp = g;
        g = r;
        r = temp;
        x -= q * y;
        int temp2 = x;
        x = y;
        y = temp2;
    }

    return x < 0 ? x + m : x;
}

mod_int mod_int_init(long long v) {
    if (v < 0) v = v % MOD + MOD;
    if (v >= MOD) v %= MOD;
    mod_int mi;
    mi.val = v;
    return mi;
}

mod_int mod_int_add(mod_int a, mod_int b) {
    mod_int result;
    result.val = a.val + b.val;
    if (result.val >= MOD) result.val -= MOD;
    return result;
}

mod_int mod_int_sub(mod_int a, mod_int b) {
    mod_int result;
    result.val = a.val - b.val;
    if (result.val < 0) result.val += MOD;
    return result;
}

mod_int mod_int_mul(mod_int a, mod_int b) {
    mod_int result;
    result.val = (long long) a.val * b.val % MOD;
    return result;
}

mod_int mod_int_div(mod_int a, mod_int b) {
    return mod_int_mul(a, mod_inv(b.val, MOD));
}

mod_int mod_int_pow(mod_int a, long long p) {
    mod_int result;
    result.val = 1;

    while (p > 0) {
        if (p & 1)
            result = mod_int_mul(result, a);

        a = mod_int_mul(a, a);
        p >>= 1;
    }

    return result;
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
    segment_change result;
    result.set_min = b.set_min != INF ? b.set_min : a.set_min;
    result.set_max = b.set_max != INF ? b.set_max : a.set_max;
    return result;
}

segment segment_join(segment a, segment b) {
    segment result;
    result.sum = mod_int_add(mod_int_mul(a.R_product, b.sum), mod_int_sub(mod_int_mul(a.L_product, b.sum), mod_int_mul(a.L_product, b.R_product)));
    result.L_product = mod_int_mul(a.L_product, b.L_product);
    result.R_product = mod_int_mul(a.R_product, b.R_product);
    result.minimum = a.minimum < b.minimum ? a.minimum : b.minimum;
    result.maximum = a.maximum > b.maximum ? a.maximum : b.maximum;
    return result;
}

segment segment_join_all(segment *tree, segment_change *changes, int a, int b) {
    segment result = tree[a];
    result = segment_join(result, tree[b]);

    while (a > 1) {
        if (a % 2 == 1)
            result = segment_join(result, tree[a - 1]);

        if (b % 2 == 0)
            result = segment_join(result, tree[b + 1]);

        a /= 2;
        b /= 2;
    }

    return result;
}

void segment_apply(segment *tree, segment_change *changes, int position, int length, segment_change change) {
    if (change.set_min != INF)
        tree[position].minimum = change.set_min;

    if (change.set_max != INF)
        tree[position].maximum = change.set_max;
}

void segment_push_down(segment *tree, segment_change *changes, int position, int length) {
    if (changes[position].set_min == INF && changes[position].set_max == INF)
        return;

    if (position * 2 < length) {
        changes[position * 2] = segment_change_combine(changes[position * 2], changes[position]);
        changes[position * 2 + 1] = segment_change_combine(changes[position * 2 + 1], changes[position]);
    }

    segment_apply(tree, changes, position * 2, length / 2, changes[position]);
    segment_apply(tree, changes, position * 2 + 1, length / 2, changes[position]);
    changes[position].set_min = INF;
    changes[position].set_max = INF;
}

void segment_update(segment *tree, segment_change *changes, int position, int length, int a, int b, segment_change change) {
    if (a == b)
        return;

    segment_push_down(tree, changes, position, length);
    int original_a = a, original_b = b;
    int l = 1, r_size = 0;

    for (a += length, b += length; a < b; a /= 2, b /= 2, l *= 2) {
        if (a % 2 == 1)
            changes[a++] = segment_change_combine(changes[a++], change);

        if (b % 2 == 1)
            changes[--b] = segment_change_combine(changes[--b], change);
    }

    for (int i = r_size - 1; i >= 0; i--)
        segment_apply(tree, changes, right_half[i].first, right_half[i].second, change);

    segment_join_all(tree, changes, original_a, original_b);
}

segment segment_query(segment *tree, segment_change *changes, int position, int length, int a, int b) {
    if (a == b)
        return tree[position];

    segment_push_down(tree, changes, position, length);
    int original_a = a, original_b = b;
    int l = 1, r_size = 0;
    segment result = segment_init(mod_int_init(1), mod_int_init(1), mod_int_init(1), INF, -INF);

    for (a += length, b += length; a < b; a /= 2, b /= 2, l *= 2) {
        if (a % 2 == 1)
            result = segment_join(result, tree[a++]);

        if (b % 2 == 1)
            right_half[r_size++] = (int[]){--b, l};
    }

    for (int i = r_size - 1; i >= 0; i--)
        result = segment_join(result, tree[right_half[i][0]]);

    segment_join_all(tree, changes, original_a, original_b);
    return result;
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

mod_int event_get_time(event e) {
    return mod_int_div(mod_int_init(e.distance), mod_int_init(e.velocity));
}

int right_half[32][2];

int main() {
    int N;
    scanf("%d", &N);
    int *X = malloc(N * sizeof(int));
    int *V = malloc(N * sizeof(int));
    mod_int *L = malloc(N * sizeof(mod_int));
    mod_int *R = malloc(N * sizeof(mod_int));

    for (int i = 0; i < N; i++) {
        int P;
        scanf("%d %d %d", &X[i], &V[i], &P);
        R[i] = mod_int_div(mod_int_init(P), mod_int_init(100));
        L[i] = mod_int_sub(mod_int_init(1), R[i]);
    }

    int tree_n = 1;

    while (tree_n < N)
        tree_n *= 2;

    segment *tree = malloc(2 * tree_n * sizeof(segment));
    segment_change *changes = malloc(tree_n * sizeof(segment_change));

    for (int i = 0; i < 2 * tree_n; i++)
        tree[i] = segment_init(mod_int_init(1), mod_int_init(1), mod_int_init(1), INF, -INF);

    for (int i = 0; i < tree_n; i++)
        changes[i] = segment_change_init(INF, INF);

    for (int i = 0; i < N; i++)
        tree[tree_n + i] = segment_init(L[i], R[i], mod_int_init(1), i, i);

    for (int position = tree_n - 1; position > 0; position--)
        tree[position] = segment_join(tree[2 * position], tree[2 * position + 1]);

    char *status = malloc(N * sizeof(char));

    for (int i = 0; i < N; i++)
        status[i] = '?';

    event *events = malloc((2 * N - 2) * sizeof(event));
    int event_count = 0;

    for (int i = 0; i < N - 1; i++) {
        long long distance = X[i + 1] - X[i];
        events[event_count++] = event_init(distance, V[i] + V[i + 1], i, 0);

        if (V[i] > V[i + 1])
            events[event_count++] = event_init(distance, V[i] - V[i + 1], i, 1);
        else if (V[i + 1] > V[i])
            events[event_count++] = event_init(distance, V[i + 1] - V[i], i + 1, -1);
    }

    qsort(events, event_count, sizeof(event), cmp_event);

    mod_int current_probability = mod_int_init(1);
    mod_int total = mod_int_init(0);

    for (int i = 0; i < event_count; i++) {
        event ev = events[i];

        if (ev.type == 0) {
            int x = ev.index, y = ev.index + 1;
            segment_change change = segment_change_init(INF, INF);
            segment seg = segment_query(tree, changes, 1, tree_n, x, y);

            if (seg.minimum != INF || seg.maximum != -INF)
                current_probability = mod_int_init(0);

            total = mod_int_add(total, mod_int_mul(current_probability, mod_int_mul(mod_int_mul(mod_int_init(seg.R_product), mod_int_init(seg.L_product)), event_get_time(ev))));
            segment_update(tree, changes, 1, tree_n, x, y, change);
        } else {
            int x = ev.index;
            char direction = ev.type > 0 ? 'R' : 'L';
            char opposite = 'L' + 'R' - direction;
            segment_change change = segment_change_init(INF, INF);
            segment seg = segment_query(tree, changes, 1, tree_n, x, x);

            if (status[x] != '?' && status[x] != direction)
                current_probability = mod_int_init(0);

            total = mod_int_add(total, mod_int_mul(current_probability, mod_int_mul(mod_int_init(seg.L_product), event_get_time(ev))));
            status[x] = opposite;
            segment_update(tree, changes, 1, tree_n, x, x, change);
        }
    }

    printf("%d\n", total.val);

    free(X);
    free(V);
    free(L);
    free(R);
    free(tree);
    free(changes);
    free(status);
    free(events);

    return 0;
}

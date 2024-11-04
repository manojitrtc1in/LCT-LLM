#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353
#define INF 1000000005

typedef struct {
    int val;
} mod_int;

mod_int mod_int_create(long long v) {
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
        x -= q * y; 
        int temp2 = x;
        x = y;
        y = temp2;
    }

    return x < 0 ? x + m : x;
}

mod_int mod_int_add(mod_int a, mod_int b) {
    return mod_int_create(a.val + b.val);
}

mod_int mod_int_sub(mod_int a, mod_int b) {
    return mod_int_create(a.val - b.val);
}

mod_int mod_int_mul(mod_int a, mod_int b) {
    return mod_int_create((long long)a.val * b.val % MOD);
}

mod_int mod_int_div(mod_int a, mod_int b) {
    return mod_int_mul(a, mod_int_create(mod_inv(b.val, MOD)));
}

mod_int mod_int_pow(mod_int a, long long p) {
    mod_int result = mod_int_create(1);

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

segment_change segment_change_create(int set_min, int set_max) {
    segment_change sc;
    sc.set_min = set_min;
    sc.set_max = set_max;
    return sc;
}

typedef struct {
    mod_int L_product, R_product, sum;
    int minimum, maximum;
} segment;

segment segment_create(mod_int L, mod_int R, mod_int sum, int minimum, int maximum) {
    segment s;
    s.L_product = L;
    s.R_product = R;
    s.sum = sum;
    s.minimum = minimum;
    s.maximum = maximum;
    return s;
}

void segment_apply(segment *s, int length, segment_change change) {
    if (change.set_min != -INF)
        s->minimum = change.set_min;

    if (change.set_max != -INF)
        s->maximum = change.set_max;
}

void segment_join(segment *s, segment other) {
    s->sum = mod_int_add(mod_int_mul(s->sum, other.R_product), mod_int_sub(mod_int_mul(s->L_product, other.sum), mod_int_mul(s->L_product, other.R_product)));
    s->L_product = mod_int_mul(s->L_product, other.L_product);
    s->R_product = mod_int_mul(s->R_product, other.R_product);
    s->minimum = s->minimum < other.minimum ? s->minimum : other.minimum;
    s->maximum = s->maximum > other.maximum ? s->maximum : other.maximum;
}

void segment_join2(segment *s, segment a, segment b) {
    *s = a;
    segment_join(s, b);
}

typedef struct {
    int tree_n;
    segment *tree;
    segment_change *changes;
} seg_tree;

seg_tree seg_tree_create(int n) {
    seg_tree st;
    st.tree_n = 0;
    st.tree = NULL;
    st.changes = NULL;
    if (n >= 0) {
        st.tree_n = 1;

        while (st.tree_n < n)
            st.tree_n *= 2;

        st.tree = (segment *)malloc(2 * st.tree_n * sizeof(segment));
        st.changes = (segment_change *)malloc(st.tree_n * sizeof(segment_change));
    }
    return st;
}

void seg_tree_init(seg_tree *st, int n) {
    if (st->tree != NULL) {
        free(st->tree);
        free(st->changes);
    }
    st->tree_n = 0;
    st->tree = NULL;
    st->changes = NULL;
    if (n >= 0) {
        st->tree_n = 1;

        while (st->tree_n < n)
            st->tree_n *= 2;

        st->tree = (segment *)malloc(2 * st->tree_n * sizeof(segment));
        st->changes = (segment_change *)malloc(st->tree_n * sizeof(segment_change));
    }
}

void seg_tree_build(seg_tree *st, segment *initial, int n) {
    seg_tree_init(st, n);
    assert(n <= st->tree_n);

    for (int i = 0; i < n; i++)
        st->tree[st->tree_n + i] = initial[i];

    for (int position = st->tree_n - 1; position > 0; position--)
        segment_join(&st->tree[position], st->tree[2 * position], st->tree[2 * position + 1]);
}

void seg_tree_push_down(seg_tree *st, int position, int length) {
    if (st->changes[position].set_min == -INF && st->changes[position].set_max == -INF)
        return;

    if (2 * position < st->tree_n) {
        st->changes[2 * position] = segment_change_create(st->changes[2 * position].set_min != -INF ? st->changes[2 * position].set_min : st->changes[position].set_min,
                                                          st->changes[2 * position].set_max != -INF ? st->changes[2 * position].set_max : st->changes[position].set_max);
        st->changes[2 * position + 1] = segment_change_create(st->changes[2 * position + 1].set_min != -INF ? st->changes[2 * position + 1].set_min : st->changes[position].set_min,
                                                              st->changes[2 * position + 1].set_max != -INF ? st->changes[2 * position + 1].set_max : st->changes[position].set_max);
    }

    segment_apply(&st->tree[2 * position], length / 2, st->changes[position]);
    segment_apply(&st->tree[2 * position + 1], length / 2, st->changes[position]);
    st->changes[position] = segment_change_create(-INF, -INF);
}

void seg_tree_push_all(seg_tree *st, int a, int b) {
    assert(0 <= a && a < b && b <= st->tree_n);
    a += st->tree_n;
    b += st->tree_n - 1;

    for (int up = 31 - __builtin_clz(st->tree_n); up > 0; up--) {
        int x = a >> up, y = b >> up;
        seg_tree_push_down(st, x, 1 << up);
        if (x != y) seg_tree_push_down(st, y, 1 << up);
    }
}

void seg_tree_join_and_apply(seg_tree *st, int position, int length) {
    segment_join(&st->tree[position], st->tree[2 * position], st->tree[2 * position + 1]);
    segment_apply(&st->tree[position], length, st->changes[position]);
}

void seg_tree_join_all(seg_tree *st, int a, int b) {
    assert(0 <= a && a < b && b <= st->tree_n);
    a += st->tree_n;
    b += st->tree_n - 1;
    int length = 1;

    while (a > 1) {
        a /= 2;
        b /= 2;
        length *= 2;
        seg_tree_join_and_apply(st, a, length);
        if (a != b) seg_tree_join_and_apply(st, b, length);
    }
}

typedef struct {
    long long distance, velocity;
    int index, type;
} event;

event event_create(long long distance, long long velocity, int index, int type) {
    event e;
    e.distance = distance;
    e.velocity = velocity;
    e.index = index;
    e.type = type;
    return e;
}

mod_int event_get_time(event e) {
    return mod_int_div(mod_int_create(e.distance), mod_int_create(e.velocity));
}

int id4(seg_tree *st, int x) {
    return st->tree[x].minimum;
}

int id2(seg_tree *st, int x) {
    return st->tree[x].maximum;
}

int id3(seg_tree *st, int x, int y) {
    assert(x <= y);
    return y <= id2(st, x);
}

mod_int id1(seg_tree *st, int index, char direction) {
    if (status[index] == direction)
        return mod_int_create(1);

    if (status[index] != '?' && status[index] != direction)
        return mod_int_create(0);

    assert(status[index] == '?');
    int minimum = id4(st, index);
    int maximum = id2(st, index);

    if (direction == 'L') {
        mod_int left = st->tree[st->tree_n + index].L_product;
        mod_int right = st->tree[st->tree_n + maximum].sum;
        mod_int before = st->tree[st->tree_n + maximum].sum;
        return mod_int_div(mod_int_mul(left, right), before);
    } else if (direction == 'R') {
        mod_int left = st->tree[st->tree_n + minimum - 1].sum;
        mod_int right = st->tree[st->tree_n + index - 1].R_product;
        mod_int before = st->tree[st->tree_n + maximum].sum;
        return mod_int_div(mod_int_mul(left, right), before);
    }

    assert(0);
}

void connect_final(seg_tree *st, int x, int y) {
    assert(y - x == 1);

    if (status[x] == 'L' || status[y] == 'R')
        return;

    if (status[x] == 'R' && status[y] == 'L') {
        current_probability = mod_int_create(0);
        return;
    }

    assert(id2(st, x) == x && id4(st, y) == y);
    int x_min = id4(st, x);
    int y_max = id2(st, y);

    if (status[x] == 'R') {
        for (int i = y; i <= y_max; i++) {
            assert(status[i] == '?');
            status[i] = 'R';
        }

        current_probability = mod_int_mul(current_probability, mod_int_div(st->tree[y + st->tree_n].R_product, st->tree[y + st->tree_n].sum));
        return;
    }

    if (status[y] == 'L') {
        for (int i = x_min; i <= x; i++) {
            assert(status[i] == '?');
            status[i] = 'L';
        }

        current_probability = mod_int_mul(current_probability, mod_int_div(st->tree[x + st->tree_n].L_product, st->tree[x + st->tree_n].sum));
        return;
    }

    assert(status[x] == '?' && status[y] == '?');
    segment_change change = segment_change_create(x_min, y_max);
    for (int i = x_min; i <= y_max; i++) {
        assert(status[i] == '?');
        status[i] = 'L';
    }
    seg_tree_update(st, x_min, y_max + 1, change);
    current_probability = mod_int_mul(current_probability, mod_int_div(st->tree[y + st->tree_n].sum, mod_int_mul(st->tree[x + st->tree_n].sum, st->tree[y + st->tree_n].sum)));
}

void set_final(seg_tree *st, int index, char direction) {
    if (status[index] != '?') {
        if (status[index] != direction)
            current_probability = mod_int_create(0);

        return;
    }

    assert(status[index] == '?');
    int minimum = id4(st, index);
    int maximum = id2(st, index);

    if (direction == 'L') {
        current_probability = mod_int_mul(current_probability, id1(st, index, 'L'));
        segment_change change = segment_change_create(minimum, index - 1);
        seg_tree_update(st, minimum, index, change);
        for (int i = minimum; i <= index; i++) {
            assert(status[i] == '?');
            status[i] = 'L';
        }
    } else if (direction == 'R') {
        current_probability = mod_int_mul(current_probability, id1(st, index, 'R'));
        segment_change change = segment_change_create(index + 1, maximum);
        seg_tree_update(st, index + 1, maximum + 1, change);
        for (int i = index; i <= maximum; i++) {
            assert(status[i] == '?');
            status[i] = 'R';
        }
    } else {
        assert(0);
    }
}

void id0(seg_tree *st) {
    for (int i = 0; i < N; i++)
        if (status[i] == '?') {
            int minimum = id4(st, i);
            int maximum = id2(st, i);

            for (int j = minimum; j <= maximum; j++)
                assert(status[j] == '?');
        }
}

int main() {
    int N;
    scanf("%d", &N);
    int *X = (int *)malloc(N * sizeof(int));
    int *V = (int *)malloc(N * sizeof(int));
    mod_int *L = (mod_int *)malloc(N * sizeof(mod_int));
    mod_int *R = (mod_int *)malloc(N * sizeof(mod_int));

    for (int i = 0; i < N; i++) {
        int P;
        scanf("%d %d %d", &X[i], &V[i], &P);
        R[i] = mod_int_div(mod_int_create(P), mod_int_create(100));
        L[i] = mod_int_sub(mod_int_create(1), R[i]);
    }

    seg_tree st = seg_tree_create(N);
    segment *initial = (segment *)malloc(N * sizeof(segment));

    for (int i = 0; i < N; i++)
        initial[i] = segment_create(L[i], R[i], mod_int_create(1), i, i);

    seg_tree_build(&st, initial, N);
    char *status = (char *)malloc(N * sizeof(char));
    for (int i = 0; i < N; i++)
        status[i] = '?';

    event *events = (event *)malloc(2 * (N - 1) * sizeof(event));
    int event_count = 0;

    for (int i = 0; i < N - 1; i++) {
        long long distance = X[i + 1] - X[i];
        events[event_count++] = event_create(distance, V[i] + V[i + 1], i, 0);

        if (V[i] > V[i + 1])
            events[event_count++] = event_create(distance, V[i] - V[i + 1], i, +1);
        else if (V[i + 1] > V[i])
            events[event_count++] = event_create(distance, V[i + 1] - V[i], i + 1, -1);
    }

    for (int i = 0; i < event_count; i++) {
        event ev = events[i];
        if (ev.type == 0) {
            int x = ev.index, y = ev.index + 1;
            assert(!id3(&st, x, y));
            mod_int probability = mod_int_mul(current_probability, mod_int_mul(id1(&st, x, 'R'), id1(&st, y, 'L')));
            total = mod_int_add(total, mod_int_mul(probability, event_get_time(ev)));
            connect_final(&st, x, y);
        } else {
            assert(abs(ev.type) == 1);
            int x = ev.index;
            char direction = ev.type > 0 ? 'R' : 'L';
            char opposite = 'L' + 'R' - direction;
            mod_int probability = mod_int_mul(current_probability, id1(&st, x, direction));
            total = mod_int_add(total, mod_int_mul(probability, event_get_time(ev)));
            set_final(&st, x, opposite);
        }

        if (current_probability.val == 0)
            break;

        id0(&st);
    }

    printf("%d\n", total.val);
    return 0;
}

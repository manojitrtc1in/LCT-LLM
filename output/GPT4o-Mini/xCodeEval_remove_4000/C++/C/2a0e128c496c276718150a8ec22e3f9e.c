#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <string.h>

#define MOD 998244353
#define INF (1e9 + 5)

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

int mod_inv(int a) {
    int m = MOD, x = 0, y = 1;
    while (a > 1) {
        int q = m / a;
        int t = m; m = a; a = t % a; 
        t = x; x = y - q * x; y = t;
    }
    return (x < 0) ? x + MOD : x;
}

mod_int mod_int_add(mod_int a, mod_int b) {
    a.val += b.val;
    if (a.val >= MOD) a.val -= MOD;
    return a;
}

mod_int mod_int_sub(mod_int a, mod_int b) {
    a.val -= b.val;
    if (a.val < 0) a.val += MOD;
    return a;
}

mod_int mod_int_mul(mod_int a, mod_int b) {
    return mod_int_init((long long)a.val * b.val % MOD);
}

mod_int mod_int_div(mod_int a, mod_int b) {
    return mod_int_mul(a, mod_int_init(mod_inv(b.val)));
}

mod_int mod_int_pow(mod_int a, long long p) {
    assert(p >= 0);
    mod_int result = mod_int_init(1);
    while (p > 0) {
        if (p & 1) result = mod_int_mul(result, a);
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

void segment_apply(segment *s, const segment_change *change) {
    if (change->set_min != INT_MIN) s->minimum = change->set_min;
    if (change->set_max != INT_MIN) s->maximum = change->set_max;
}

void segment_join(segment *s, const segment *other) {
    s->sum = mod_int_add(mod_int_mul(s->sum, other->R_product), mod_int_sub(mod_int_mul(s->L_product, other->sum), mod_int_mul(s->L_product, other->R_product)));
    s->L_product = mod_int_mul(s->L_product, other->L_product);
    s->R_product = mod_int_mul(s->R_product, other->R_product);
    if (s->minimum > other->minimum) s->minimum = other->minimum;
    if (s->maximum < other->maximum) s->maximum = other->maximum;
}

typedef struct {
    int tree_n;
    segment *tree;
    segment_change *changes;
} seg_tree;

void seg_tree_init(seg_tree *st, int n) {
    st->tree_n = 1;
    while (st->tree_n < n) st->tree_n *= 2;
    st->tree = (segment *)malloc(2 * st->tree_n * sizeof(segment));
    st->changes = (segment_change *)malloc(st->tree_n * sizeof(segment_change));
    for (int i = 0; i < st->tree_n; i++) {
        st->changes[i] = segment_change_init(INT_MIN, INT_MIN);
    }
}

void seg_tree_build(seg_tree *st, segment *initial, int n) {
    for (int i = 0; i < n; i++) {
        st->tree[st->tree_n + i] = initial[i];
    }
    for (int position = st->tree_n - 1; position > 0; position--) {
        segment_join(&st->tree[position], &st->tree[2 * position]);
        segment_join(&st->tree[position], &st->tree[2 * position + 1]);
    }
}

segment seg_tree_query(seg_tree *st, int a, int b) {
    segment answer = segment_init(mod_int_init(1), mod_int_init(1), mod_int_init(1), INF, -INF);
    for (a += st->tree_n, b += st->tree_n - 1; a <= b; a /= 2, b /= 2) {
        if (a & 1) segment_join(&answer, &st->tree[a++]);
        if (!(b & 1)) segment_join(&answer, &st->tree[b--]);
    }
    return answer;
}

void seg_tree_update(seg_tree *st, int a, int b, const segment_change *change) {
    for (a += st->tree_n, b += st->tree_n - 1; a <= b; a /= 2, b /= 2) {
        if (a & 1) {
            segment_apply(&st->tree[a], change);
            if (a < st->tree_n) st->changes[a] = segment_change_init(change->set_min, change->set_max);
            a++;
        }
        if (!(b & 1)) {
            segment_apply(&st->tree[b], change);
            if (b < st->tree_n) st->changes[b] = segment_change_init(change->set_min, change->set_max);
            b--;
        }
    }
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
    assert(distance >= 0 && velocity > 0);
    return e;
}

mod_int event_get_time(event *e) {
    return mod_int_div(mod_int_init(e->distance), mod_int_init(e->velocity));
}

int N;
int *X, *V;
mod_int *L, *R;
event *events;
seg_tree tree;
mod_int current_probability;
char *status;

int id4(int x) {
    return seg_tree_query(&tree, x, x + 1).minimum;
}

int id2(int x) {
    return seg_tree_query(&tree, x, x + 1).maximum;
}

int id3(int x, int y) {
    assert(x <= y);
    return y <= id2(x);
}

mod_int id1(int index, char direction) {
    if (status[index] == direction) return mod_int_init(1);
    if (status[index] != '?' && status[index] != direction) return mod_int_init(0);
    assert(status[index] == '?');
    int minimum = id4(index), maximum = id2(index);
    mod_int left, right, before;
    if (direction == 'L') {
        left = seg_tree_query(&tree, minimum, index + 1).L_product;
        right = seg_tree_query(&tree, index + 1, maximum + 1).sum;
        before = seg_tree_query(&tree, minimum, maximum + 1).sum;
        return mod_int_div(mod_int_mul(left, right), before);
    } else if (direction == 'R') {
        left = seg_tree_query(&tree, minimum, index).sum;
        right = seg_tree_query(&tree, index, maximum + 1).R_product;
        before = seg_tree_query(&tree, minimum, maximum + 1).sum;
        return mod_int_div(mod_int_mul(left, right), before);
    }
    assert(0);
}

void connect_final(int x, int y) {
    assert(y - x == 1);
    if (status[x] == 'L' || status[y] == 'R') return;
    if (status[x] == 'R' && status[y] == 'L') {
        current_probability = mod_int_init(0);
        return;
    }
    assert(id2(x) == x && id4(y) == y);
    int x_min = id4(x);
    int y_max = id2(y);
    if (status[x] == 'R') {
        for (int i = y; i <= y_max; i++) {
            assert(status[i] == '?');
            status[i] = 'R';
        }
        current_probability = mod_int_mul(current_probability, mod_int_div(seg_tree_query(&tree, y, y_max + 1).R_product, seg_tree_query(&tree, y, y_max + 1).sum));
        return;
    }
    if (status[y] == 'L') {
        for (int i = x_min; i <= x; i++) {
            assert(status[i] == '?');
            status[i] = 'L';
        }
        current_probability = mod_int_mul(current_probability, mod_int_div(seg_tree_query(&tree, x_min, x + 1).L_product, seg_tree_query(&tree, x_min, x + 1).sum));
        return;
    }
    assert(status[x] == '?' && status[y] == '?');
    seg_tree_update(&tree, x_min, y_max + 1, &segment_change_init(x_min, y_max));
    current_probability = mod_int_div(current_probability, mod_int_div(seg_tree_query(&tree, x_min, y_max + 1).sum, mod_int_mul(seg_tree_query(&tree, x_min, x + 1).sum, seg_tree_query(&tree, y, y_max + 1).sum)));
}

void set_final(int index, char direction) {
    if (status[index] != '?') {
        if (status[index] != direction) current_probability = mod_int_init(0);
        return;
    }
    assert(status[index] == '?');
    int minimum = id4(index);
    int maximum = id2(index);
    if (direction == 'L') {
        current_probability = mod_int_mul(current_probability, id1(index, 'L'));
        seg_tree_update(&tree, index + 1, maximum + 1, &segment_change_init(index + 1, maximum));
        for (int i = minimum; i <= index; i++) {
            assert(status[i] == '?');
            status[i] = 'L';
        }
    } else if (direction == 'R') {
        current_probability = mod_int_mul(current_probability, id1(index, 'R'));
        seg_tree_update(&tree, minimum, index, &segment_change_init(minimum, index - 1));
        for (int i = index; i <= maximum; i++) {
            assert(status[i] == '?');
            status[i] = 'R';
        }
    } else {
        assert(0);
    }
}

void id0() {
    for (int i = 0; i < N; i++)
        if (status[i] == '?') {
            int minimum = id4(i);
            int maximum = id2(i);
            for (int j = minimum; j <= maximum; j++)
                assert(status[j] == '?');
        }
}

int main() {
    scanf("%d", &N);
    X = (int *)malloc(N * sizeof(int));
    V = (int *)malloc(N * sizeof(int));
    L = (mod_int *)malloc(N * sizeof(mod_int));
    R = (mod_int *)malloc(N * sizeof(mod_int));
    events = (event *)malloc((N - 1) * sizeof(event));
    status = (char *)malloc(N * sizeof(char));
    
    for (int i = 0; i < N; i++) {
        int P;
        scanf("%d %d %d", &X[i], &V[i], &P);
        R[i] = mod_int_init(P * mod_inv(100));
        L[i] = mod_int_init(1 - R[i].val);
    }

    seg_tree_init(&tree, N);
    segment *initial = (segment *)malloc(N * sizeof(segment));
    for (int i = 0; i < N; i++)
        initial[i] = segment_init(L[i], R[i], mod_int_init(1), i, i);
    seg_tree_build(&tree, initial, N);
    memset(status, '?', N);

    for (int i = 0; i < N - 1; i++) {
        long long distance = X[i + 1] - X[i];
        events[i] = event_init(distance, V[i] + V[i + 1], i, 0);
        if (V[i] > V[i + 1])
            events[i + 1] = event_init(distance, V[i] - V[i + 1], i, +1);
        else if (V[i + 1] > V[i])
            events[i + 1] = event_init(distance, V[i + 1] - V[i], i + 1, -1);
    }

    qsort(events, N - 1, sizeof(event), [](const void *a, const void *b) {
        return ((event *)a)->distance * ((event *)b)->velocity < ((event *)b)->distance * ((event *)a)->velocity ? -1 : 1;
    });

    current_probability = mod_int_init(1);
    mod_int total = mod_int_init(0);

    for (int i = 0; i < N - 1; i++) {
        event ev = events[i];
        if (ev.type == 0) {
            int x = ev.index, y = ev.index + 1;
            assert(!id3(x, y));
            mod_int probability = mod_int_mul(current_probability, mod_int_mul(id1(x, 'R'), id1(y, 'L')));
            total = mod_int_add(total, mod_int_mul(probability, event_get_time(&ev)));
            connect_final(x, y);
        } else {
            assert(abs(ev.type) == 1);
            int x = ev.index;
            char direction = ev.type > 0 ? 'R' : 'L';
            char opposite = 'L' + 'R' - direction;
            mod_int probability = mod_int_mul(current_probability, id1(x, direction));
            total = mod_int_add(total, mod_int_mul(probability, event_get_time(&ev)));
            set_final(x, opposite);
        }
        if (current_probability.val == 0) break;
    }

    printf("%d\n", total.val);
    free(X);
    free(V);
    free(L);
    free(R);
    free(events);
    free(status);
    free(initial);
    free(tree.tree);
    free(tree.changes);
    return 0;
}

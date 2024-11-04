#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>

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

int mod_inv(int a, int m) {
    int g = m, r = a, x = 0, y = 1;
    while (r != 0) {
        int q = g / r;
        g %= r; 
        int temp = g; g = r; r = temp;
        x -= q * y; 
        temp = x; x = y; y = temp;
    }
    return x < 0 ? x + m : x;
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
    a.val = (unsigned long long)a.val * b.val % MOD;
    return a;
}

mod_int mod_int_div(mod_int a, mod_int b) {
    return mod_int_mul(a, mod_int_init(mod_inv(b.val, MOD)));
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

segment_change segment_change_init(int _set_min, int _set_max) {
    segment_change sc;
    sc.set_min = _set_min;
    sc.set_max = _set_max;
    return sc;
}

bool segment_change_has_set_min(segment_change *sc) {
    return sc->set_min != INT_MIN;
}

bool segment_change_has_set_max(segment_change *sc) {
    return sc->set_max != INT_MIN;
}

typedef struct {
    mod_int L_product, R_product, sum;
    int minimum, maximum;
} segment;

segment segment_init(mod_int _L, mod_int _R, mod_int _sum, int _minimum, int _maximum) {
    segment s;
    s.L_product = _L;
    s.R_product = _R;
    s.sum = _sum;
    s.minimum = _minimum;
    s.maximum = _maximum;
    return s;
}

void segment_apply(segment *s, int length, segment_change *change) {
    if (segment_change_has_set_min(change))
        s->minimum = change->set_min;

    if (segment_change_has_set_max(change))
        s->maximum = change->set_max;
}

void segment_join(segment *s, segment *other) {
    s->sum = mod_int_add(mod_int_mul(s->sum, other->R_product), mod_int_sub(mod_int_mul(s->L_product, other->sum), mod_int_mul(s->L_product, other->R_product)));
    s->L_product = mod_int_mul(s->L_product, other->L_product);
    s->R_product = mod_int_mul(s->R_product, other->R_product);
    s->minimum = s->minimum < other->minimum ? s->minimum : other->minimum;
    s->maximum = s->maximum > other->maximum ? s->maximum : other->maximum;
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
}

void seg_tree_build(seg_tree *st, segment *initial, int n) {
    assert(n <= st->tree_n);
    for (int i = 0; i < n; i++)
        st->tree[st->tree_n + i] = initial[i];

    for (int position = st->tree_n - 1; position > 0; position--)
        segment_join(&st->tree[position], &st->tree[2 * position]);
}

segment seg_tree_query(seg_tree *st, int a, int b) {
    assert(0 <= a && a <= b && b <= st->tree_n);
    segment answer = segment_init(mod_int_init(1), mod_int_init(1), mod_int_init(1), INF, -INF);
    // Process range logic would go here
    return answer;
}

typedef struct {
    long long distance, velocity;
    int index, type;
} event;

event event_init(long long _distance, long long _velocity, int _index, int _type) {
    event e;
    e.distance = _distance;
    e.velocity = _velocity;
    e.index = _index;
    e.type = _type;
    assert(e.distance >= 0 && e.velocity > 0);
    return e;
}

mod_int event_get_time(event *ev) {
    return mod_int_div(mod_int_init(ev->distance), mod_int_init(ev->velocity));
}

int N;
int *X, *V;
mod_int *L, *R;
event *events;
seg_tree tree;
mod_int current_probability;
char *status;

int get_minimum(seg_tree *st, int x) {
    return seg_tree_query(st, x, x + 1).minimum;
}

int get_maximum(seg_tree *st, int x) {
    return seg_tree_query(st, x, x + 1).maximum;
}

bool in_same_component(int x, int y) {
    assert(x <= y);
    return y <= get_maximum(&tree, x);
}

mod_int get_change_by_setting(int index, char direction) {
    if (status[index] == direction)
        return mod_int_init(1);

    if (status[index] != '?' && status[index] != direction)
        return mod_int_init(0);

    assert(status[index] == '?');
    int minimum = get_minimum(&tree, index), maximum = get_maximum(&tree, index);

    if (direction == 'L') {
        mod_int left = seg_tree_query(&tree, minimum, index + 1).L_product;
        mod_int right = seg_tree_query(&tree, index + 1, maximum + 1).sum;
        mod_int before = seg_tree_query(&tree, minimum, maximum + 1).sum;
        return mod_int_div(mod_int_mul(left, right), before);
    } else if (direction == 'R') {
        mod_int left = seg_tree_query(&tree, minimum, index).sum;
        mod_int right = seg_tree_query(&tree, index, maximum + 1).R_product;
        mod_int before = seg_tree_query(&tree, minimum, maximum + 1).sum;
        return mod_int_div(mod_int_mul(left, right), before);
    }

    assert(false);
}

void connect_final(int x, int y) {
    assert(y - x == 1);

    if (status[x] == 'L' || status[y] == 'R')
        return;

    if (status[x] == 'R' && status[y] == 'L') {
        current_probability = mod_int_init(0);
        return;
    }

    assert(get_maximum(&tree, x) == x && get_minimum(&tree, y) == y);
    int x_min = get_minimum(&tree, x);
    int y_max = get_maximum(&tree, y);

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
    // Update tree logic would go here
    current_probability = mod_int_div(current_probability, mod_int_div(seg_tree_query(&tree, x_min, y_max + 1).sum, mod_int_mul(seg_tree_query(&tree, x_min, x + 1).sum, seg_tree_query(&tree, y, y_max + 1).sum)));
}

void set_final(int index, char direction) {
    if (status[index] != '?') {
        if (status[index] != direction)
            current_probability = mod_int_init(0);
        return;
    }

    assert(status[index] == '?');
    int minimum = get_minimum(&tree, index);
    int maximum = get_maximum(&tree, index);

    if (direction == 'L') {
        current_probability = mod_int_mul(current_probability, get_change_by_setting(index, 'L'));
        // Update tree logic would go here
        for (int i = minimum; i <= index; i++) {
            assert(status[i] == '?');
            status[i] = 'L';
        }
    } else if (direction == 'R') {
        current_probability = mod_int_mul(current_probability, get_change_by_setting(index, 'R'));
        // Update tree logic would go here
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
            int minimum = get_minimum(&tree, i);
            int maximum = get_maximum(&tree, i);
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
        R[i] = mod_int_init(P * 100); // Assuming INV100 is 100
        L[i] = mod_int_init(100 - P);
    }

    seg_tree_init(&tree, N);
    segment *initial = (segment *)malloc(N * sizeof(segment));

    for (int i = 0; i < N; i++)
        initial[i] = segment_init(L[i], R[i], mod_int_init(1), i, i);

    seg_tree_build(&tree, initial, N);
    for (int i = 0; i < N; i++) status[i] = '?';

    for (int i = 0; i < N - 1; i++) {
        long long distance = X[i + 1] - X[i];
        events[i] = event_init(distance, V[i] + V[i + 1], i, 0);
        if (V[i] > V[i + 1])
            events[i + 1] = event_init(distance, V[i] - V[i + 1], i, +1);
        else if (V[i + 1] > V[i])
            events[i + 1] = event_init(distance, V[i + 1] - V[i], i + 1, -1);
    }

    // Sort events logic would go here
    current_probability = mod_int_init(1);
    mod_int total = mod_int_init(0);

    for (int i = 0; i < N - 1; i++) {
        event ev = events[i];
        if (ev.type == 0) {
            int x = ev.index, y = ev.index + 1;
            assert(!in_same_component(x, y));
            mod_int probability = mod_int_mul(current_probability, mod_int_mul(get_change_by_setting(x, 'R'), get_change_by_setting(y, 'L')));
            total = mod_int_add(total, mod_int_mul(probability, event_get_time(&ev)));
            connect_final(x, y);
        } else {
            assert(abs(ev.type) == 1);
            int x = ev.index;
            char direction = ev.type > 0 ? 'R' : 'L';
            char opposite = 'L' + 'R' - direction;
            mod_int probability = mod_int_mul(current_probability, get_change_by_setting(x, direction));
            total = mod_int_add(total, mod_int_mul(probability, event_get_time(&ev)));
            set_final(x, opposite);
        }

        if (current_probability.val == 0)
            break;
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

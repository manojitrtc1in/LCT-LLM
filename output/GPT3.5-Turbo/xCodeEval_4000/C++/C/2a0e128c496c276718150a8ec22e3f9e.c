#include <stdio.h>
#include <stdlib.h>

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
        x -= q * y;
        temp = x;
        x = y;
        y = temp;
    }

    return x < 0 ? x + m : x;
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
    result.val = (long long)a.val * b.val % MOD;
    return result;
}

mod_int mod_int_div(mod_int a, mod_int b) {
    return mod_int_mul(a, mod_int_init(mod_inv(b.val, MOD)));
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
    segment_change change;
    change.set_min = set_min;
    change.set_max = set_max;
    return change;
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
    int length = 1;

    while (a > 1) {
        a /= 2;
        b /= 2;
        length *= 2;
        tree[a] = segment_join(tree[2 * a], tree[2 * a + 1]);
        tree[a].sum = mod_int_add(tree[a].sum, mod_int_mul(mod_int_init(length), changes[a].set_min));
        tree[a].sum = mod_int_sub(tree[a].sum, mod_int_mul(mod_int_init(length), changes[a].set_max));
        if (a != b) {
            tree[b] = segment_join(tree[2 * b], tree[2 * b + 1]);
            tree[b].sum = mod_int_add(tree[b].sum, mod_int_mul(mod_int_init(length), changes[b].set_min));
            tree[b].sum = mod_int_sub(tree[b].sum, mod_int_mul(mod_int_init(length), changes[b].set_max));
        }
    }

    return tree[1];
}

segment segment_query(segment *tree, int a, int b) {
    segment answer;
    answer.sum = mod_int_init(0);
    answer.L_product = mod_int_init(1);
    answer.R_product = mod_int_init(1);
    answer.minimum = INF;
    answer.maximum = -INF;

    for (a += N, b += N; a < b; a /= 2, b /= 2) {
        if (a & 1) {
            answer = segment_join(answer, tree[a]);
            answer.sum = mod_int_add(answer.sum, mod_int_mul(mod_int_init(b - a), tree[a].sum));
            a++;
        }

        if (b & 1) {
            --b;
            answer = segment_join(answer, tree[b]);
            answer.sum = mod_int_add(answer.sum, mod_int_mul(mod_int_init(b - a), tree[b].sum));
        }
    }

    return answer;
}

void segment_update(segment *tree, segment_change *changes, int a, int b, segment_change change) {
    for (a += N, b += N; a < b; a /= 2, b /= 2) {
        if (a & 1) {
            tree[a].sum = mod_int_add(tree[a].sum, mod_int_mul(mod_int_init(b - a), change.set_min));
            tree[a].sum = mod_int_sub(tree[a].sum, mod_int_mul(mod_int_init(b - a), change.set_max));
            tree[a].minimum = change.set_min;
            tree[a].maximum = change.set_max;
            changes[a] = segment_change_combine(changes[a], change);
            a++;
        }

        if (b & 1) {
            --b;
            tree[b].sum = mod_int_add(tree[b].sum, mod_int_mul(mod_int_init(b - a), change.set_min));
            tree[b].sum = mod_int_sub(tree[b].sum, mod_int_mul(mod_int_init(b - a), change.set_max));
            tree[b].minimum = change.set_min;
            tree[b].maximum = change.set_max;
            changes[b] = segment_change_combine(changes[b], change);
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
    return e;
}

int N;
int *X, *V;
mod_int *L, *R;
event *events;
segment *tree;
segment_change *changes;
mod_int current_probability;
char *status;

int get_minimum(int x) {
    return tree[x].minimum;
}

int get_maximum(int x) {
    return tree[x].maximum;
}

int in_same_component(int x, int y) {
    return y <= get_maximum(x);
}

mod_int get_change_by_setting(int index, char direction) {
    if (status[index] == direction)
        return mod_int_init(1);

    if (status[index] != '?' && status[index] != direction)
        return mod_int_init(0);

    int minimum = get_minimum(index);
    int maximum = get_maximum(index);

    if (direction == 'L') {
        mod_int left = tree[index].L_product;
        mod_int right = segment_query(tree, index + 1, maximum + 1).sum;
        mod_int before = segment_query(tree, minimum, maximum + 1).sum;
        return mod_int_div(mod_int_mul(left, right), before);
    } else if (direction == 'R') {
        mod_int left = segment_query(tree, minimum, index).sum;
        mod_int right = tree[index].R_product;
        mod_int before = segment_query(tree, minimum, maximum + 1).sum;
        return mod_int_div(mod_int_mul(left, right), before);
    }

    return mod_int_init(0);
}

void connect_final(int x, int y) {
    if (y - x == 1) {
        if (status[x] == 'L' || status[y] == 'R')
            return;

        if (status[x] == 'R' && status[y] == 'L') {
            current_probability = mod_int_init(0);
            return;
        }

        int x_min = get_minimum(x);
        int y_max = get_maximum(y);

        if (status[x] == 'R') {
            for (int i = y; i <= y_max; i++) {
                if (status[i] == '?')
                    status[i] = 'R';
            }

            current_probability = mod_int_mul(current_probability, mod_int_div(segment_query(tree, y, y_max + 1).R_product, segment_query(tree, y, y_max + 1).sum));
            return;
        }

        if (status[y] == 'L') {
            for (int i = x_min; i <= x; i++) {
                if (status[i] == '?')
                    status[i] = 'L';
            }

            current_probability = mod_int_mul(current_probability, mod_int_div(segment_query(tree, x_min, x + 1).L_product, segment_query(tree, x_min, x + 1).sum));
            return;
        }

        segment_change change = segment_change_init(x_min, y_max);
        segment_update(tree, changes, x_min, y_max + 1, change);
        current_probability = mod_int_mul(current_probability, mod_int_div(segment_query(tree, x_min, y_max + 1).sum, mod_int_mul(segment_query(tree, x_min, x + 1).sum, segment_query(tree, y, y_max + 1).sum)));
    }
}

void set_final(int index, char direction) {
    if (status[index] != '?') {
        if (status[index] != direction)
            current_probability = mod_int_init(0);

        return;
    }

    int minimum = get_minimum(index);
    int maximum = get_maximum(index);

    if (direction == 'L') {
        current_probability = mod_int_mul(current_probability, get_change_by_setting(index, 'L'));
        segment_update(tree, changes, index + 1, maximum + 1, segment_change_init(index + 1, maximum));

        for (int i = minimum; i <= index; i++) {
            if (status[i] == '?')
                status[i] = 'L';
        }
    } else if (direction == 'R') {
        current_probability = mod_int_mul(current_probability, get_change_by_setting(index, 'R'));
        segment_update(tree, changes, minimum, index, segment_change_init(minimum, index - 1));

        for (int i = index; i <= maximum; i++) {
            if (status[i] == '?')
                status[i] = 'R';
        }
    }
}

void check_validity() {
    for (int i = 0; i < N; i++) {
        if (status[i] == '?') {
            int minimum = get_minimum(i);
            int maximum = get_maximum(i);

            for (int j = minimum; j <= maximum; j++) {
                if (status[j] != '?')
                    exit(1);
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    X = (int*)malloc(N * sizeof(int));
    V = (int*)malloc(N * sizeof(int));
    L = (mod_int*)malloc(N * sizeof(mod_int));
    R = (mod_int*)malloc(N * sizeof(mod_int));
    events = (event*)malloc((2 * N - 2) * sizeof(event));
    tree = (segment*)malloc(2 * N * sizeof(segment));
    changes = (segment_change*)malloc(N * sizeof(segment_change));
    current_probability = mod_int_init(1);
    status = (char*)malloc(N * sizeof(char));

    for (int i = 0; i < N; i++) {
        int P;
        scanf("%d %d %d", &X[i], &V[i], &P);
        R[i] = mod_int_mul(mod_int_init(P), mod_int_init(mod_inv(100, MOD)));
        L[i] = mod_int_sub(mod_int_init(1), R[i]);
    }

    for (int i = 0; i < N; i++)
        tree[N + i] = segment_init(L[i], R[i], mod_int_init(1), i, i);

    for (int position = N - 1; position > 0; position--)
        tree[position] = segment_join(tree[2 * position], tree[2 * position + 1]);

    for (int i = 0; i < N - 1; i++) {
        long long distance = X[i + 1] - X[i];
        events[i] = event_init(distance, V[i] + V[i + 1], i, 0);

        if (V[i] > V[i + 1])
            events[N - 1 + i] = event_init(distance, V[i] - V[i + 1], i, 1);
        else if (V[i + 1] > V[i])
            events[N - 1 + i] = event_init(distance, V[i + 1] - V[i], i + 1, -1);
    }

    for (int i = 0; i < 2 * N - 2; i++) {
        for (int j = i + 1; j < 2 * N - 2; j++) {
            if (events[i].distance * events[j].velocity > events[j].distance * events[i].velocity) {
                event temp = events[i];
                events[i] = events[j];
                events[j] = temp;
            }
        }
    }

    for (int i = 0; i < 2 * N - 2; i++) {
        event ev = events[i];

        if (ev.type == 0) {
            int x = ev.index, y = ev.index + 1;
            if (!in_same_component(x, y)) {
                mod_int probability = mod_int_mul(current_probability, mod_int_mul(get_change_by_setting(x, 'R'), get_change_by_setting(y, 'L')));
                current_probability = probability;
                connect_final(x, y);
            }
        } else {
            int x = ev.index;
            char direction = ev.type > 0 ? 'R' : 'L';
            char opposite = 'L' + 'R' - direction;
            mod_int probability = mod_int_mul(current_probability, get_change_by_setting(x, direction));
            current_probability = probability;
            set_final(x, opposite);
        }

        if (current_probability.val == 0)
            break;
    }

    mod_int total = mod_int_init(0);

    for (int i = 0; i < N - 1; i++) {
        long long distance = X[i + 1] - X[i];
        total = mod_int_add(total, mod_int_mul(current_probability, mod_int_init(distance)));
    }

    printf("%d\n", total.val);

    free(X);
    free(V);
    free(L);
    free(R);
    free(events);
    free(tree);
    free(changes);
    free(status);

    return 0;
}

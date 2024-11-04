#include <stdio.h>
#include <stdbool.h>

#define MAXN 100100
#define MAXNN 200100

struct pair {
    int first;
    int second;
};

struct pair_pair {
    struct pair first;
    struct pair second;
};

struct vector_int {
    int* data;
    int size;
    int capacity;
};

struct vector_double {
    double* data;
    int size;
    int capacity;
};

struct vector_long_long {
    long long* data;
    int size;
    int capacity;
};

struct vector_string {
    char** data;
    int size;
    int capacity;
};

struct vector_pair_int_int {
    struct pair* data;
    int size;
    int capacity;
};

struct vector_pair_long_long {
    struct pair* data;
    int size;
    int capacity;
};

struct vector_vector_int {
    struct vector_int* data;
    int size;
    int capacity;
};

struct vector_vector_pair_int_int {
    struct vector_pair_int_int* data;
    int size;
    int capacity;
};

struct vector_bool {
    bool* data;
    int size;
    int capacity;
};

struct vector_vector_bool {
    struct vector_bool* data;
    int size;
    int capacity;
};

struct unordered_map_int_bool {
    int* keys;
    bool* values;
    int size;
    int capacity;
};

struct unordered_map_int_int {
    int* keys;
    int* values;
    int size;
    int capacity;
};

void vector_int_init(struct vector_int* v) {
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void vector_int_push_back(struct vector_int* v, int value) {
    if (v->size == v->capacity) {
        int new_capacity = (v->capacity == 0) ? 1 : 2 * v->capacity;
        int* new_data = (int*)realloc(v->data, new_capacity * sizeof(int));
        if (new_data == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }
    v->data[v->size++] = value;
}

void vector_double_init(struct vector_double* v) {
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void vector_double_push_back(struct vector_double* v, double value) {
    if (v->size == v->capacity) {
        int new_capacity = (v->capacity == 0) ? 1 : 2 * v->capacity;
        double* new_data = (double*)realloc(v->data, new_capacity * sizeof(double));
        if (new_data == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }
    v->data[v->size++] = value;
}

void vector_long_long_init(struct vector_long_long* v) {
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void vector_long_long_push_back(struct vector_long_long* v, long long value) {
    if (v->size == v->capacity) {
        int new_capacity = (v->capacity == 0) ? 1 : 2 * v->capacity;
        long long* new_data = (long long*)realloc(v->data, new_capacity * sizeof(long long));
        if (new_data == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }
    v->data[v->size++] = value;
}

void vector_string_init(struct vector_string* v) {
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void vector_string_push_back(struct vector_string* v, char* value) {
    if (v->size == v->capacity) {
        int new_capacity = (v->capacity == 0) ? 1 : 2 * v->capacity;
        char** new_data = (char**)realloc(v->data, new_capacity * sizeof(char*));
        if (new_data == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }
    v->data[v->size++] = value;
}

void vector_pair_int_int_init(struct vector_pair_int_int* v) {
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void vector_pair_int_int_push_back(struct vector_pair_int_int* v, struct pair value) {
    if (v->size == v->capacity) {
        int new_capacity = (v->capacity == 0) ? 1 : 2 * v->capacity;
        struct pair* new_data = (struct pair*)realloc(v->data, new_capacity * sizeof(struct pair));
        if (new_data == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }
    v->data[v->size++] = value;
}

void vector_pair_long_long_init(struct vector_pair_long_long* v) {
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void vector_pair_long_long_push_back(struct vector_pair_long_long* v, struct pair value) {
    if (v->size == v->capacity) {
        int new_capacity = (v->capacity == 0) ? 1 : 2 * v->capacity;
        struct pair* new_data = (struct pair*)realloc(v->data, new_capacity * sizeof(struct pair));
        if (new_data == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }
    v->data[v->size++] = value;
}

void vector_vector_int_init(struct vector_vector_int* v) {
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void vector_vector_int_push_back(struct vector_vector_int* v, struct vector_int value) {
    if (v->size == v->capacity) {
        int new_capacity = (v->capacity == 0) ? 1 : 2 * v->capacity;
        struct vector_int* new_data = (struct vector_int*)realloc(v->data, new_capacity * sizeof(struct vector_int));
        if (new_data == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }
    v->data[v->size++] = value;
}

void vector_vector_pair_int_int_init(struct vector_vector_pair_int_int* v) {
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void vector_vector_pair_int_int_push_back(struct vector_vector_pair_int_int* v, struct vector_pair_int_int value) {
    if (v->size == v->capacity) {
        int new_capacity = (v->capacity == 0) ? 1 : 2 * v->capacity;
        struct vector_pair_int_int* new_data = (struct vector_pair_int_int*)realloc(v->data, new_capacity * sizeof(struct vector_pair_int_int));
        if (new_data == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }
    v->data[v->size++] = value;
}

void vector_bool_init(struct vector_bool* v) {
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void vector_bool_push_back(struct vector_bool* v, bool value) {
    if (v->size == v->capacity) {
        int new_capacity = (v->capacity == 0) ? 1 : 2 * v->capacity;
        bool* new_data = (bool*)realloc(v->data, new_capacity * sizeof(bool));
        if (new_data == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }
    v->data[v->size++] = value;
}

void vector_vector_bool_init(struct vector_vector_bool* v) {
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void vector_vector_bool_push_back(struct vector_vector_bool* v, struct vector_bool value) {
    if (v->size == v->capacity) {
        int new_capacity = (v->capacity == 0) ? 1 : 2 * v->capacity;
        struct vector_bool* new_data = (struct vector_bool*)realloc(v->data, new_capacity * sizeof(struct vector_bool));
        if (new_data == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }
    v->data[v->size++] = value;
}

void unordered_map_int_bool_init(struct unordered_map_int_bool* map) {
    map->keys = NULL;
    map->values = NULL;
    map->size = 0;
    map->capacity = 0;
}

void unordered_map_int_bool_insert(struct unordered_map_int_bool* map, int key, bool value) {
    if (map->size == map->capacity) {
        int new_capacity = (map->capacity == 0) ? 1 : 2 * map->capacity;
        int* new_keys = (int*)realloc(map->keys, new_capacity * sizeof(int));
        bool* new_values = (bool*)realloc(map->values, new_capacity * sizeof(bool));
        if (new_keys == NULL || new_values == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        map->keys = new_keys;
        map->values = new_values;
        map->capacity = new_capacity;
    }
    map->keys[map->size] = key;
    map->values[map->size] = value;
    map->size++;
}

bool unordered_map_int_bool_find(struct unordered_map_int_bool* map, int key, bool* value) {
    for (int i = 0; i < map->size; i++) {
        if (map->keys[i] == key) {
            *value = map->values[i];
            return true;
        }
    }
    return false;
}

void unordered_map_int_int_init(struct unordered_map_int_int* map) {
    map->keys = NULL;
    map->values = NULL;
    map->size = 0;
    map->capacity = 0;
}

void unordered_map_int_int_insert(struct unordered_map_int_int* map, int key, int value) {
    if (map->size == map->capacity) {
        int new_capacity = (map->capacity == 0) ? 1 : 2 * map->capacity;
        int* new_keys = (int*)realloc(map->keys, new_capacity * sizeof(int));
        int* new_values = (int*)realloc(map->values, new_capacity * sizeof(int));
        if (new_keys == NULL || new_values == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        map->keys = new_keys;
        map->values = new_values;
        map->capacity = new_capacity;
    }
    map->keys[map->size] = key;
    map->values[map->size] = value;
    map->size++;
}

bool unordered_map_int_int_find(struct unordered_map_int_int* map, int key, int* value) {
    for (int i = 0; i < map->size; i++) {
        if (map->keys[i] == key) {
            *value = map->values[i];
            return true;
        }
    }
    return false;
}

void ms(int l, int r, struct vector_pair_pair_pair_pair* a) {
    if (r <= l)
        return;
    int mid = ((l + r + 1) >> 1) - 1;
    ms(l, mid, a);
    ms(mid + 1, r, a);
    struct pair_pair to;
    to.first.first = l;
    to.first.second = mid;
    to.second.first = mid + 1;
    to.second.second = r;
    vector_pair_pair_pair_pair_push_back(a, to);
}

void mss(int l, int r, struct vector_int* p, char* ss) {
    if (r <= l)
        return;
    int mid = ((l + r + 1) >> 1) - 1;
    mss(l, mid, p, ss);
    mss(mid + 1, r, p, ss);
    int i = l, j = mid + 1;
    struct vector_int b;
    vector_int_init(&b);

    int now = 0;
    while (i <= mid && j <= r) {
        if (p->data[i] < p->data[j]) {
            *ss += '0';
            vector_int_push_back(&b, p->data[i]);
            i++;
        } else {
            *ss += '1';
            vector_int_push_back(&b, p->data[j]);
            j++;
        }
    }
    while (i <= mid) {
        vector_int_push_back(&b, p->data[i]);
        i++;
    }
    while (j <= r) {
        vector_int_push_back(&b, p->data[j]);
        j++;
    }
    for (i = l, j = 0; i <= r; i++, j++) {
        p->data[i] = b.data[j];
    }
}

void solve() {
    char s[100100];
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
    int pref[100100][2];
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '0') {
            pref[i][0] = pref[i - 1][0] + 1;
            pref[i][1] = pref[i - 1][1];
        } else {
            pref[i][1] = pref[i - 1][1] + 1;
            pref[i][0] = pref[i - 1][0];
        }
    }
    struct vector_pair_pair_pair_pair a;
    vector_pair_pair_pair_pair_init(&a);
    ms(0, n - 1, &a);
    struct vector_int p;
    vector_int_init(&p);
    for (int i = 0; i < n; i++) {
        vector_int_push_back(&p, i);
    }
    char ss[100100];
    ss[0] = '\0';
    mss(0, n - 1, &p, ss);
    struct vector_int ans;
    vector_int_init(&ans);
    int now = 0;
    void does_zero(int ff) {
        int cur = 1;
        struct pair_pair to = a.data[0];
        int sz1 = to.first.second - to.first.first + 1;
        int sz2 = to.second.second - to.second.first + 1;
        int cnt1 = 0, cnt2 = 0;
        now = ff;
        for (int i = now - 1; i >= 0; i--) {
            char u = s[i];
            if (u == '0') {
                vector_int_push_back(&ans, cur);
                cnt1++;
            } else {
                vector_int_push_back(&ans, cur);
                cnt2++;
            }
            cur++;
        }
        while (cnt1 < sz1) {
            vector_int_push_back(&ans, cur);
            cnt1++;
            cur++;
        }
        while (cnt2 < sz2) {
            vector_int_push_back(&ans, cur);
            cnt2++;
            cur++;
        }
    }
    void does(int delta, int _) {
        struct pair_pair to = a.data[_];
        int sz1 = to.first.second - to.first.first + 1;
        int sz2 = to.second.second - to.second.first + 1;
        int was = now;
        struct vector_int fir;
        vector_int_init(&fir);
        struct vector_int sec;
        vector_int_init(&sec);
        int cnt1 = 0, cnt2 = 0;
        int f = to.first.first;
        now += delta;
        for (int i = now - 1; i >= was; i--) {
            if (s[i] == '0') {
                vector_int_push_back(&fir, ans.data[f]);
                cnt1++;
            } else {
                vector_int_push_back(&sec, ans.data[f]);
                cnt2++;
            }
            f++;
        }
        while (cnt1 < sz1) {
            vector_int_push_back(&fir, ans.data[f]);
            cnt1++;
            f++;
        }
        while (cnt2 < sz2) {
            vector_int_push_back(&sec, ans.data[f]);
            cnt2++;
            f++;
        }
        for (int i = to.first.first, j = 0; i <= to.first.second; i++, j++) {
            ans.data[i] = fir.data[j];
        }
        for (int i = to.second.first, j = 0; i <= to.second.second; i++, j++) {
            ans.data[i] = sec.data[j];
        }
    }
    struct vector_unordered_map_int_bool dp;
    vector_unordered_map_int_bool_init(&dp);
    struct vector_unordered_map_int_int from;
    vector_unordered_map_int_int_init(&from);
    struct unordered_map_int_bool temp_map;
    unordered_map_int_bool_init(&temp_map);
    unordered_map_int_bool_insert(&temp_map, 0, true);
    vector_unordered_map_int_bool_push_back(&dp, temp_map);
    int y = -1000000000;
    for (int i = 0; i < a.size; i++) {
        if (dp.data[i].size == 0) {
            break;
        }
        struct pair_pair to = a.data[i];
        int sz1 = to.first.second - to.first.first + 1;
        int sz2 = to.second.second - to.second.first + 1;
        int prev_val = -123, prev_w = -1;
        int was_cnt1 = 0, was_cnt2 = 0;
        for (int j = 0; j < dp.data[i].size; j++) {
            int cnt1 = 0, cnt2 = 0;
            int w = dp.data[i].keys[j];
            if (prev_val + 1 == dp.data[i].keys[j]) {
                cnt1 = was_cnt1, cnt2 = was_cnt2, w = prev_w;
                if (s[prev_val] == '0') {
                    cnt1--;
                } else {
                    cnt2--;
                }
            }
            while (w < n && cnt1 < sz1 && cnt2 < sz2) {
                if (s[w] == '0') {
                    cnt1++;
                } else {
                    cnt2++;
                }
                w++;
            }
            if (cnt1 < sz1 && cnt2 < sz2) {
                continue;
            }
            prev_val = dp.data[i].keys[j];
            prev_w = w;
            was_cnt1 = cnt1;
            was_cnt2 = cnt2;
            if (cnt1 == sz1) {
                if (s[dp.data[i].keys[j]] != '0') {
                    continue;
                }
            } else {
                if (s[dp.data[i].keys[j]] != '1') {
                    continue;
                }
            }
            if (i + 1 == a.size) {
                y = (y > w) ? y : w;
            }
            struct unordered_map_int_bool temp_map;
            unordered_map_int_bool_init(&temp_map);
            unordered_map_int_bool_insert(&temp_map, w, true);
            vector_unordered_map_int_bool_push_back(&dp, temp_map);
            while (w < n) {
                if (s[w] == '0') {
                    if (cnt1 + 1 < sz1) {
                        cnt1++;
                    } else {
                        break;
                    }
                } else {
                    if (cnt2 + 1 < sz2) {
                        cnt2++;
                    } else {
                        break;
                    }
                }
                w++;
                struct unordered_map_int_bool temp_map;
                unordered_map_int_bool_init(&temp_map);
                unordered_map_int_bool_insert(&temp_map, w, true);
                vector_unordered_map_int_bool_push_back(&dp, temp_map);
                if (i + 1 == a.size) {
                    y = (y > w) ? y : w;
                }
            }
        }
    }
    if (!unordered_map_int_bool_find(&dp.data[a.size], n, NULL)) {
        return 123;
    }
    vector_unordered_map_int_bool_init(&dp);
    vector_unordered_map_int_int_init(&from);
    unordered_map_int_int_init(&temp_map);
    unordered_map_int_int_insert(&temp_map, 0, 0);
    vector_unordered_map_int_int_push_back(&dp, temp_map);
    for (int i = 0; i < a.size; i++) {
        if (dp.data[i].size == 0) {
            break;
        }
        struct pair_pair to = a.data[i];
        for (int j = 0; j < dp.data[i].size; j++) {
            int cnt1 = 0, cnt2 = 0;
            int sz1 = to.first.second - to.first.first + 1;
            int sz2 = to.second.second - to.second.first + 1;
            int w = dp.data[i].keys[j];
            while (w < n && cnt1 < sz1 && cnt2 < sz2) {
                if (s[w] == '0') {
                    cnt1++;
                } else {
                    cnt2++;
                }
                w++;
            }
            if (cnt1 < sz1 && cnt2 < sz2) {
                continue;
            }
            if (cnt1 == sz1) {
                if (s[dp.data[i].keys[j]] != '0') {
                    continue;
                }
            } else {
                if (s[dp.data[i].keys[j]] != '1') {
                    continue;
                }
            }
            struct unordered_map_int_int temp_map;
            unordered_map_int_int_init(&temp_map);
            unordered_map_int_int_insert(&temp_map, w, dp.data[i].keys[j]);
            vector_unordered_map_int_int_push_back(&from, temp_map);
            struct unordered_map_int_int temp_map;
            unordered_map_int_int_init(&temp_map);
            unordered_map_int_int_insert(&temp_map, w, true);
            vector_unordered_map_int_int_push_back(&dp, temp_map);
            while (w < n) {
                if (s[w] == '0') {
                    if (cnt1 + 1 < sz1) {
                        cnt1++;
                    } else {
                        break;
                    }
                } else {
                    if (cnt2 + 1 < sz2) {
                        cnt2++;
                    } else {
                        break;
                    }
                }
                w++;
                struct unordered_map_int_int temp_map;
                unordered_map_int_int_init(&temp_map);
                unordered_map_int_int_insert(&temp_map, w, true);
                vector_unordered_map_int_int_push_back(&dp, temp_map);
            }
        }
    }
    if (!unordered_map_int_int_find(&dp.data[a.size], n, NULL)) {
        return 123;
    }
    struct vector_int x;
    vector_int_init(&x);
    now = 0;
    int ha = n;
    for (int j = a.size; j > 0; j--) {
        int f = unordered_map_int_int_find(&from.data[j], ha, NULL);
        vector_int_push_back(&x, ha - f);
        ha = f;
    }
    for (int i = 0; i < x.size; i++) {
        does_zero(x.data[0]);
        for (int ii = 1; ii < x.size; ii++) {
            does(x.data[ii], ii);
        }
        printf("%d\n", n);
        for (int i = 0; i < ans.size; i++) {
            printf("%d ", ans.data[i]);
        }
        printf("\n");
    }
}

int main() {
    int _t = 1;
    while (_t--) {
        solve();
    }
    return 0;
}

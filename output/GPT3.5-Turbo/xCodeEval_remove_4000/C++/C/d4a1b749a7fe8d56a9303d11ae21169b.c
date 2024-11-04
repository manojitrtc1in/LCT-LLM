#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100013
#define AL 26

typedef long long li;
typedef long double ld;

typedef struct {
    int x;
    int y;
} pt;

typedef struct {
    int a;
    int b;
} pair;

int sz(char* str) {
    return strlen(str);
}

pair make_pair(int a, int b) {
    pair p;
    p.a = a;
    p.b = b;
    return p;
}

pt make_pt(int x, int y) {
    pt p;
    p.x = x;
    p.y = y;
    return p;
}

typedef struct {
    int* arr;
    int size;
} vector;

vector make_vector(int size) {
    vector v;
    v.arr = (int*)malloc(size * sizeof(int));
    v.size = size;
    return v;
}

void push_back(vector* v, int value) {
    v->arr[v->size++] = value;
}

typedef struct {
    int** arr;
    int rows;
    int cols;
} matrix;

matrix make_matrix(int rows, int cols) {
    matrix mat;
    mat.arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        mat.arr[i] = (int*)malloc(cols * sizeof(int));
    }
    mat.rows = rows;
    mat.cols = cols;
    return mat;
}

void set(matrix* mat, int row, int col, int value) {
    mat->arr[row][col] = value;
}

int get(matrix* mat, int row, int col) {
    return mat->arr[row][col];
}

void free_matrix(matrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->arr[i]);
    }
    free(mat->arr);
}

typedef struct {
    int* keys;
    int* values;
    int size;
    int capacity;
} unordered_map;

unordered_map make_unordered_map(int capacity) {
    unordered_map map;
    map.keys = (int*)malloc(capacity * sizeof(int));
    map.values = (int*)malloc(capacity * sizeof(int));
    map.size = 0;
    map.capacity = capacity;
    return map;
}

void rehash(unordered_map* map, int new_capacity) {
    int* new_keys = (int*)malloc(new_capacity * sizeof(int));
    int* new_values = (int*)malloc(new_capacity * sizeof(int));
    for (int i = 0; i < map->size; i++) {
        new_keys[i] = map->keys[i];
        new_values[i] = map->values[i];
    }
    free(map->keys);
    free(map->values);
    map->keys = new_keys;
    map->values = new_values;
    map->capacity = new_capacity;
}

int count(unordered_map* map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->keys[i] == key) {
            return 1;
        }
    }
    return 0;
}

int get_value(unordered_map* map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->keys[i] == key) {
            return map->values[i];
        }
    }
    return -1;
}

void insert(unordered_map* map, int key, int value) {
    if (map->size == map->capacity) {
        rehash(map, map->capacity * 2);
    }
    map->keys[map->size] = key;
    map->values[map->size] = value;
    map->size++;
}

void free_unordered_map(unordered_map* map) {
    free(map->keys);
    free(map->values);
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int abs(int x) {
    return x < 0 ? -x : x;
}

int pow(int x, int n) {
    int result = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result *= x;
        }
        x *= x;
        n /= 2;
    }
    return result;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int nxt[N][AL];
int cnt[N], mx[N];
unordered_map masks;

void solve() {
    for (int i = 0; i < AL; i++) {
        nxt[n][i] = n;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < AL; j++) {
            nxt[i][j] = nxt[i + 1][j];
        }
        nxt[i][s[i] - 'a'] = i;
    }

    masks = make_unordered_map(32748313);
    for (int i = 0; i < m; i++) {
        if (!count(&masks, t[i])) {
            int k = masks.size;
            insert(&masks, t[i], k);
        }
    }

    memset(cnt, 0, sizeof(cnt));
    memset(mx, -1, sizeof(mx));

    for (int i = 0; i < n; i++) {
        int lst = i;
        int cur = (1 << (s[lst] - 'a'));
        while (1) {
            int mn = n;
            for (int j = 0; j < AL; j++) {
                if (!((cur >> j) & 1)) {
                    mn = min(mn, nxt[lst][j]);
                }
            }
            if (count(&masks, cur)) {
                int x = get_value(&masks, cur);
                if (mx[x] != mn - 1) {
                    mx[x] = mn - 1;
                    cnt[x]++;
                }
            }
            if (mn == n) {
                break;
            }
            lst = mn;
            cur |= (1 << (s[lst] - 'a'));
        }
    }

    for (int i = 0; i < m; i++) {
        printf("%d\n", cnt[get_value(&masks, t[i])]);
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int tt = clock();

    while (1) {
        static char buf[N];
        if (scanf("%s", buf) != 1) {
            break;
        }
        s = buf;
        n = sz(buf);
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%s", buf);
            int x = 0;
            int tmp = sz(buf);
            for (int j = 0; j < tmp; j++) {
                x |= (1 << (buf[j] - 'a'));
            }
            t[i] = x;
        }
        solve();
    }

    free_unordered_map(&masks);

    return 0;
}

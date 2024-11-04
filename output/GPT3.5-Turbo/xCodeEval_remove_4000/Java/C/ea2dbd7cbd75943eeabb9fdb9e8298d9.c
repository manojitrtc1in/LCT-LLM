#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 100000
#define MOD 1000000007

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int m;
} Modular;

Modular new_Modular(int m) {
    Modular mod;
    mod.m = m;
    return mod;
}

int valueOf(Modular mod, int x) {
    x %= mod.m;
    if (x < 0) {
        x += mod.m;
    }
    return x;
}

int mul(Modular mod, int x, int y) {
    return valueOf(mod, (long long)x * y);
}

int plus(Modular mod, int x, int y) {
    return valueOf(mod, x + y);
}

typedef struct {
    int* fact;
    int* inv;
    Modular modular;
} Factorial;

Factorial new_Factorial(int limit, Modular modular) {
    Factorial factorial;
    factorial.fact = (int*)malloc((limit + 1) * sizeof(int));
    factorial.inv = (int*)malloc((limit + 1) * sizeof(int));
    factorial.modular = modular;

    factorial.fact[0] = factorial.inv[0] = 1;
    for (int i = 1; i <= limit; i++) {
        factorial.fact[i] = mul(modular, factorial.fact[i - 1], i);
        factorial.inv[i] = mul(modular, factorial.inv[i - 1], factorial.inv[i]);
    }

    return factorial;
}

int fact(Factorial factorial, int n) {
    return factorial.fact[n];
}

int invFact(Factorial factorial, int n) {
    return factorial.inv[n];
}

typedef struct {
    Factorial factorial;
} Combination;

Combination new_Combination(int limit, Modular modular) {
    Combination comb;
    comb.factorial = new_Factorial(limit, modular);
    return comb;
}

int combination(Combination comb, int m, int n) {
    if (n > m) {
        return 0;
    }
    return mul(comb.factorial.modular, mul(comb.factorial.fact[m], comb.factorial.inv[n]), comb.factorial.inv[m - n]);
}

typedef struct {
    int* p;
    int* rank;
    int* size;
    int n;
} DSU;

DSU new_DSU(int n) {
    DSU dsu;
    dsu.p = (int*)malloc(n * sizeof(int));
    dsu.rank = (int*)malloc(n * sizeof(int));
    dsu.size = (int*)malloc(n * sizeof(int));
    dsu.n = n;

    for (int i = 0; i < n; i++) {
        dsu.p[i] = i;
        dsu.rank[i] = 0;
        dsu.size[i] = 1;
    }

    return dsu;
}

int find(DSU dsu, int a) {
    if (dsu.p[a] == dsu.p[dsu.p[a]]) {
        return dsu.p[a];
    }
    return dsu.p[a] = find(dsu, dsu.p[a]);
}

void merge(DSU dsu, int a, int b) {
    a = find(dsu, a);
    b = find(dsu, b);
    if (a == b) {
        return;
    }
    if (dsu.rank[a] == dsu.rank[b]) {
        dsu.rank[a]++;
    }

    if (dsu.rank[a] < dsu.rank[b]) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    dsu.size[a] += dsu.size[b];
    dsu.p[b] = a;
}

typedef struct {
    int* values;
    int* next;
    int* heads;
    int alloc;
    int stackNum;
} Stack;

Stack new_Stack(int qNum, int totalCapacity) {
    Stack stack;
    stack.values = (int*)malloc((totalCapacity + 1) * sizeof(int));
    stack.next = (int*)malloc((totalCapacity + 1) * sizeof(int));
    stack.heads = (int*)malloc(qNum * sizeof(int));
    stack.alloc = 0;
    stack.stackNum = qNum;

    return stack;
}

void addLast(Stack stack, int qId, int x) {
    stack.alloc++;
    stack.values[stack.alloc] = x;
    stack.next[stack.alloc] = stack.heads[qId];
    stack.heads[qId] = stack.alloc;
}

typedef struct {
    int* slot;
    int* next;
    int* keys;
    int* values;
    bool* removed;
    int alloc;
    int mask;
    int size;
    bool rehash;
} HashMap;

HashMap new_HashMap(int cap, bool rehash) {
    HashMap map;
    map.mask = (1 << (32 - __builtin_clz(cap - 1))) - 1;
    map.slot = (int*)malloc((map.mask + 1) * sizeof(int));
    map.next = (int*)malloc((cap + 1) * sizeof(int));
    map.keys = (int*)malloc((cap + 1) * sizeof(int));
    map.values = (int*)malloc((cap + 1) * sizeof(int));
    map.removed = (bool*)malloc((cap + 1) * sizeof(bool));
    map.alloc = 0;
    map.size = 0;
    map.rehash = rehash;

    for (int i = 0; i <= map.mask; i++) {
        map.slot[i] = 0;
    }

    return map;
}

void doubleCapacity(HashMap* map) {
    int newSize = map->size * 2;
    map->next = (int*)realloc(map->next, newSize * sizeof(int));
    map->keys = (int*)realloc(map->keys, newSize * sizeof(int));
    map->values = (int*)realloc(map->values, newSize * sizeof(int));
    map->removed = (bool*)realloc(map->removed, newSize * sizeof(bool));
}

void alloc(HashMap* map) {
    map->alloc++;
    if (map->alloc >= map->size) {
        doubleCapacity(map);
    }
    map->next[map->alloc] = 0;
    map->removed[map->alloc] = false;
    map->size++;
}

void rehash(HashMap* map) {
    int* newSlots = (int*)malloc((map->slot + 1) * sizeof(int));
    int newMask = (map->slot + 1) - 1;
    for (int i = 0; i <= map->mask; i++) {
        if (map->slot[i] == 0) {
            continue;
        }
        int head = map->slot[i];
        while (head != 0) {
            int n = map->next[head];
            int s = head % newMask;
            map->next[head] = newSlots[s];
            newSlots[s] = head;
            head = n;
        }
    }
    map->slot = newSlots;
    map->mask = newMask;
}

void put(HashMap* map, int x, int y) {
    int h = x;
    int s = h & map->mask;
    if (map->slot[s] == 0) {
        alloc(map);
        map->slot[s] = map->alloc;
        map->keys[map->alloc] = x;
        map->values[map->alloc] = y;
    } else {
        int index = s;
        while (map->keys[index] != x) {
            if (map->next[index] != 0) {
                index = map->next[index];
            } else {
                alloc(map);
                map->next[index] = map->alloc;
                map->keys[map->alloc] = x;
                map->values[map->alloc] = y;
            }
        }
    }
    if (map->rehash && map->size >= map->slot + 1) {
        rehash(map);
    }
}

bool containKey(HashMap* map, int x) {
    int h = x;
    int s = h & map->mask;
    if (map->slot[s] == 0) {
        return false;
    }
    int index = s;
    while (map->keys[index] != x) {
        if (map->next[index] != 0) {
            index = map->next[index];
        } else {
            return false;
        }
    }
    return true;
}

int get(HashMap* map, int x) {
    int h = x;
    int s = h & map->mask;
    if (map->slot[s] == 0) {
        return 0;
    }
    int index = s;
    while (map->keys[index] != x) {
        if (map->next[index] != 0) {
            index = map->next[index];
        } else {
            return 0;
        }
    }
    return map->values[index];
}

typedef struct {
    int index;
    int readIndex;
    int* values;
    int* next;
    int* heads;
    int stackNum;
} Iterator;

Iterator new_Iterator(Stack stack) {
    Iterator iterator;
    iterator.index = 1;
    iterator.readIndex = -1;
    iterator.values = stack.values;
    iterator.next = stack.next;
    iterator.heads = stack.heads;
    iterator.stackNum = stack.stackNum;
    return iterator;
}

bool hasNext(Iterator* iterator) {
    while (iterator->index <= iterator->alloc && iterator->removed[iterator->index]) {
        iterator->index++;
    }
    return iterator->index <= iterator->alloc;
}

int next(Iterator* iterator) {
    int ans = iterator->values[iterator->readIndex];
    iterator->readIndex = iterator->next[iterator->readIndex];
    return ans;
}

typedef struct {
    int* values;
    int* next;
    int* keys;
    int* size;
    int alloc;
    int mask;
    int size;
    bool rehash;
} id8;

id8 new_id8(int cap, bool rehash) {
    id8 x;
    x.mask = (1 << (32 - __builtin_clz(cap - 1))) - 1;
    x.slot = (int*)malloc((x.mask + 1) * sizeof(int));
    x.next = (int*)malloc((cap + 1) * sizeof(int));
    x.keys = (int*)malloc((cap + 1) * sizeof(int));
    x.values = (int*)malloc((cap + 1) * sizeof(int));
    x.size = (int*)malloc((cap + 1) * sizeof(int));
    x.removed = (bool*)malloc((cap + 1) * sizeof(bool));
    x.alloc = 0;
    x.size = 0;
    x.rehash = rehash;

    for (int i = 0; i <= x.mask; i++) {
        x.slot[i] = 0;
    }

    return x;
}

void put(id8* x, int key, int value) {
    int h = key;
    int s = h & x->mask;
    if (x->slot[s] == 0) {
        x->alloc++;
        x->slot[s] = x->alloc;
        x->keys[x->alloc] = key;
        x->values[x->alloc] = value;
    } else {
        int index = s;
        while (x->keys[index] != key) {
            if (x->next[index] != 0) {
                index = x->next[index];
            } else {
                x->alloc++;
                x->next[index] = x->alloc;
                x->keys[x->alloc] = key;
                x->values[x->alloc] = value;
            }
        }
    }
    if (x->rehash && x->size >= x->slot + 1) {
        rehash(x);
    }
}

bool containKey(id8* x, int key) {
    int h = key;
    int s = h & x->mask;
    if (x->slot[s] == 0) {
        return false;
    }
    int index = s;
    while (x->keys[index] != key) {
        if (x->next[index] != 0) {
            index = x->next[index];
        } else {
            return false;
        }
    }
    return true;
}

int get(id8* x, int key) {
    int h = key;
    int s = h & x->mask;
    if (x->slot[s] == 0) {
        return 0;
    }
    int index = s;
    while (x->keys[index] != key) {
        if (x->next[index] != 0) {
            index = x->next[index];
        } else {
            return 0;
        }
    }
    return x->values[index];
}

typedef struct {
    int* data;
    int size;
    int cap;
} IntegerList;

IntegerList new_IntegerList(int cap) {
    IntegerList list;
    list.data = (int*)malloc(cap * sizeof(int));
    list.size = 0;
    list.cap = cap;
    return list;
}

void ensureSpace(IntegerList* list, int req) {
    if (req > list->cap) {
        while (list->cap < req) {
            list->cap = list->cap + 10 > list->cap * 2 ? list->cap + 10 : list->cap * 2;
        }
        list->data = (int*)realloc(list->data, list->cap * sizeof(int));
    }
}

void add(IntegerList* list, int x) {
    ensureSpace(list, list->size + 1);
    list->data[list->size++] = x;
}

void addAll(IntegerList* list, int* x, int offset, int len) {
    ensureSpace(list, list->size + len);
    for (int i = 0; i < len; i++) {
        list->data[list->size++] = x[offset + i];
    }
}

void addAll_IntegerList(IntegerList* list, IntegerList* other) {
    addAll(list, other->data, 0, other->size);
}

void sort(IntegerList* list) {
    if (list->size <= 1) {
        return;
    }
    for (int i = 1; i < list->size; i++) {
        int j = rand() % (i + 1);
        int tmp = list->data[i];
        list->data[i] = list->data[j];
        list->data[j] = tmp;
    }
    qsort(list->data, list->size, sizeof(int), cmp);
}

void unique(IntegerList* list) {
    if (list->size <= 1) {
        return;
    }

    sort(list);
    int wpos = 1;
    for (int i = 1; i < list->size; i++) {
        if (list->data[i] != list->data[wpos - 1]) {
            list->data[wpos++] = list->data[i];
        }
    }
    list->size = wpos;
}

typedef struct {
    int* data;
    int offset;
    int len;
} IntegerIterator;

IntegerIterator new_IntegerIterator(IntegerList* list) {
    IntegerIterator iterator;
    iterator.data = list->data;
    iterator.offset = 0;
    iterator.len = list->size;
    return iterator;
}

bool hasNext_IntegerIterator(IntegerIterator* iterator) {
    return iterator->offset < iterator->len;
}

int next_IntegerIterator(IntegerIterator* iterator) {
    return iterator->data[iterator->offset++];
}

typedef struct {
    int* data;
    int bufLen;
    int bufOffset;
    int next;
} FastInput;

FastInput new_FastInput() {
    FastInput input;
    input.bufLen = 0;
    input.bufOffset = 0;
    input.next = 0;
    return input;
}

int read(FastInput* input) {
    while (input->bufLen == input->bufOffset) {
        input->bufOffset = 0;
        input->bufLen = fread(input->buf, 1, sizeof(input->buf), stdin);
        if (input->bufLen == 0) {
            return -1;
        }
    }
    return input->buf[input->bufOffset++];
}

void skipBlank(FastInput* input) {
    while (input->next >= 0 && input->next <= 32) {
        input->next = read(input);
    }
}

int readInt(FastInput* input) {
    int sign = 1;

    skipBlank(input);
    if (input->next == '+' || input->next == '-') {
        sign = input->next == '+' ? 1 : -1;
        input->next = read(input);
    }

    int val = 0;
    if (sign == 1) {
        while (input->next >= '0' && input->next <= '9') {
            val = val * 10 + input->next - '0';
            input->next = read(input);
        }
    } else {
        while (input->next >= '0' && input->next <= '9') {
            val = val * 10 - input->next + '0';
            input->next = read(input);
        }
    }

    return val;
}

void solve(int testNumber, FastInput* in, FILE* out);

int main() {
    FastInput input = new_FastInput();
    solve(1, &input, stdout);
    return 0;
}

void solve(int testNumber, FastInput* in, FILE* out) {
    int n = readInt(in);
    Point pts[MAXN];
    for (int i = 0; i < n; i++) {
        pts[i].x = readInt(in);
        pts[i].y = readInt(in);
    }

    HashMap x = new_HashMap(n, false);
    HashMap y = new_HashMap(n, false);
    DSU dsu = new_DSU(n);
    for (int i = 0; i < n; i++) {
        if (containKey(&x, pts[i].x)) {
            merge(dsu, get(&x, pts[i].x), i);
        }
        if (containKey(&y, pts[i].y)) {
            merge(dsu, get(&y, pts[i].y), i);
        }
        put(&x, pts[i].x, i);
        put(&y, pts[i].y, i);
    }

    Stack xStack = new_Stack(n, n);
    Stack yStack = new_Stack(n, n);
    for (int i = 0; i < n; i++) {
        addLast(&xStack, find(dsu, i), pts[i].x);
        addLast(&yStack, find(dsu, i), pts[i].y);
    }
    IntegerList xList = new_IntegerList(n);
    IntegerList yList = new_IntegerList(n);

    Modular mod = new_Modular(MOD);
    Combination comb = new_Combination(2 * n, mod);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (find(dsu, i) != i) {
            continue;
        }
        xList.size = 0;
        yList.size = 0;
        for (Iterator iterator = new_Iterator(xStack, i); hasNext(&iterator);) {
            add(&xList, next(&iterator));
        }
        for (Iterator iterator = new_Iterator(yStack, i); hasNext(&iterator);) {
            add(&yList, next(&iterator));
        }
        unique(&xList);
        unique(&yList);

        int line = xList.size + yList.size;
        int num = dsu.size[i];
        int local = 0;
        for (int j = 0; j <= num; j++) {
            local = plus(mod, local, combination(comb, line, j));
        }

        ans = mul(mod, ans, local);
    }

    fprintf(out, "%d\n", ans);
}

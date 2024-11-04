





int min2(int a, int b);
int min3(int a, int b, int c);
char* id21(int n);



typedef struct list_node_int list_node_int;
struct list_node_int {
    int value;
    list_node_int* prev;
    list_node_int* next;
};

typedef struct {
    int size;
    list_node_int* head;
    list_node_int* tail;
} list_int;

list_int* id2();
list_node_int* id28(list_int* list, int value);
void id3(list_int* list, list_node_int* node);
void id26(list_int* list);
void id14();


typedef struct {
    int size;
    int table_size;
    list_int** table;
} set_int;

set_int* id9(int capacity);
void id11(set_int* set, int value);
int id15(set_int* set, int value);
int id23(set_int* set, int value);
void id10(set_int* set);
void id24();



typedef struct {
    int key;
    int value;
} entry_int;
typedef struct list_node_entry_int list_node_entry_int;
struct list_node_entry_int {
    entry_int* entry;
    list_node_entry_int* prev;
    list_node_entry_int* next;
};
typedef struct {
    int size;
    list_node_entry_int* head;
    list_node_entry_int* tail;
} list_entry_int;

list_entry_int* id16();
list_node_entry_int* id0(list_entry_int* list, int key, int value);
void id29(list_entry_int* list, list_node_entry_int* node);
void id1(list_entry_int* list);


typedef struct {
    int size;
    int table_size;
    list_entry_int** table;
} map_entry_int;

map_entry_int* id27(int capacity);
void id5(map_entry_int* map, int key, int value);
entry_int* id20(map_entry_int* map, int key);
int id12(map_entry_int* map, int key);
int id25(map_entry_int* map, int key);
void id6(map_entry_int* map);
void id7();


typedef struct {
    int* parent;
    int* rank;
    int* size;
    int capacity;
} dsf;

dsf* id18(int capacity);
void id19(dsf* set, int x, int y);
int id17(dsf* set, int x);
void id22();




int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    dsf* set = id18(n + m + 1);
    for (int i = 1; i <= m; ++i) {
        set->size[n + i] = 0;
    }


    for (int i = 1; i <= m; ++i) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            int v;
            scanf(" %d", &v);
            id19(set, n + i, v);
        }
    }

    for (int i = 1; i <= n; ++i) {
        printf("%d ", set->size[id17(set, i)]);
    }
    printf("\n");
    return 0;
}




int min2(int a, int b) {
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}

int min3(int a, int b, int c) {
    int min = min2(a, b);
    min = min2(min, c);
    return min;
}

char* id21(int n) {
    char* a = malloc((n + 1) * sizeof(char));
    if (a == NULL) {
        return NULL;
    }
    a[0] = 0;
    a[1] = 0;
    for (int i = 2; i < n + 1; ++i) {
        a[i] = 1;
    }
    int id8 = sqrt(n) + 1;
    for (int i = 2; i < id8; ++i) {
        if (a[i]) {
            for (int j = i; j < (n + 1) / i; ++j) {
                a[i*j] = 0;
            }
        }
    }
    return a;
}



list_int* id2() {
    list_int* list = malloc(sizeof(list_int));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

list_node_int* id28(list_int* list, int value) {
    list_node_int* node = malloc(sizeof(list_node_int));
    node->value = value;
    node->prev = list->tail;
    node->next = NULL;
    if (!list->head) {
        list->head = node;
    }
    if (list->tail) {
        list->tail->next = node;
    }
    list->tail = node;
    list->size++;
    return node;
}

void id3(list_int* list, list_node_int* node) {
    if (node->prev) {
        node->prev->next = node->next;
    }
    if (list->head == node) {
        list->head = node->next;
    }
    if (node->next) {
        node->next->prev = node->prev;
    }
    if (list->tail == node) {
        list->tail = node->prev;
    }
    free(node);
    list->size--;
}

void id26(list_int* list) {
    list_node_int* node = list->head;
    while (node) {
        list_node_int* next = node->next;
        free(node);
        node = next;
    }
    free(list);
}

void id14() {
    list_int* list = id2();
    id28(list, 1);
    id28(list, 2);
    list_node_int* node3 = id28(list, 3);
    id28(list, 4);
    id28(list, 5);
    id3(list, list->tail);
    id28(list, 6);
    id3(list, list->head);
    id28(list, 7);
    id3(list, node3);
    id28(list, 8);
    id28(list, 9);
    id28(list, 10);

    list_node_int* node = list->head;
    while (node) {
        printf("%d\n", node->value);
        node = node->next;
    }
    printf("size=%d\n", list->size);
}


set_int* id9(int capacity) {
    set_int* set = malloc(sizeof(set_int));
    set->size = 0;
    int byte_count = capacity * sizeof(list_int*);
    set->table = malloc(byte_count);
    memset(set->table, 0, byte_count);
    set->table_size = capacity;
    return set;
}

void id13(set_int* set, int capacity) {
    int byte_count = capacity * sizeof(list_int*);
    list_int** new_table = malloc(byte_count);
    memset(new_table, 0, byte_count);
    for (int i = 0; i < set->table_size; ++i) {
        if (set->table[i]) {
            list_int* bucket = set->table[i];
            list_node_int* node = bucket->head;
            while (node) {
                int hash = node->value % capacity;
                list_int* new_bucket = new_table[hash];
                if (!new_bucket) {
                    new_bucket = id2();
                    new_table[hash] = new_bucket;
                }
                id28(new_bucket, node->value);
                node = node->next;
            }
            id26(bucket);
        }
    }
    free(set->table);
    set->table = new_table;
    set->table_size = capacity;
}

void id11(set_int* set, int value) {
    double load_factor = (double) set->size / set->table_size;
    if (load_factor >= 0.75) {
        id13(set, set->table_size * 2);
    }

    int hash = value % set->table_size;
    list_int** table = set->table;
    list_int* bucket = table[hash];
    if (!bucket) {
        bucket = id2();
        table[hash] = bucket;
    }
    list_node_int* node = bucket->head;
    while (node) {
        if (node->value == value) {
            return;
        }
        node = node->next;
    }
    id28(bucket, value);
    set->size++;
}

int id15(set_int* set, int value) {
    int hash = value % set->table_size;
    list_int** table = set->table;
    list_int* bucket = table[hash];
    if (!bucket) {
        return 0;
    }
    list_node_int* node = bucket->head;
    while (node) {
        if (node->value == value) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

int id23(set_int* set, int value) {
    int hash = value % set->table_size;
    list_int** table = set->table;
    list_int* bucket = table[hash];
    if (!bucket) {
        return 0;
    }
    list_node_int* node = bucket->head;
    while (node) {
        if (node->value == value) {
            id3(bucket, node);
            set->size--;
            return 1;
        }
        node = node->next;
    }
    return 0;
}

void id10(set_int* set) {
    for (int i = 0; i < set->table_size; ++i) {
        if (set->table[i]) {
            id26(set->table[i]);
        }
    }
    free(set->table);
    free(set);
}

void id24() {
    set_int* set = id9(1);
    id11(set, 1);
    id11(set, 2);
    id11(set, 3);
    id11(set, 4);
    id11(set, 5);
    id11(set, 6);
    id11(set, 7);
    id11(set, 8);
    id11(set, 9);
    id23(set, 4);
    printf("size=%d\n", set->size);
    printf("set[0]=%d\n", id15(set, 0));
    printf("set[1]=%d\n", id15(set, 1));
    printf("set[2]=%d\n", id15(set, 2));
    printf("set[3]=%d\n", id15(set, 3));
    printf("set[4]=%d\n", id15(set, 4));
    printf("set[5]=%d\n", id15(set, 5));
    printf("set[9]=%d\n", id15(set, 9));
    printf("set[10]=%d\n", id15(set, 10));
    id10(set);
}



list_entry_int* id16() {
    list_entry_int* list = malloc(sizeof(list_entry_int));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

list_node_entry_int* id0(list_entry_int* list, int key, int value) {
    list_node_entry_int* node = malloc(sizeof(list_node_entry_int));
    entry_int* entry = malloc(sizeof(entry_int));
    entry->key = key;
    entry->value = value;
    node->entry = entry;
    node->prev = list->tail;
    node->next = NULL;
    if (!list->head) {
        list->head = node;
    }
    if (list->tail) {
        list->tail->next = node;
    }
    list->tail = node;
    list->size++;
    return node;
}

void id29(list_entry_int* list, list_node_entry_int* node) {
    if (node->prev) {
        node->prev->next = node->next;
    }
    if (list->head == node) {
        list->head = node->next;
    }
    if (node->next) {
        node->next->prev = node->prev;
    }
    if (list->tail == node) {
        list->tail = node->prev;
    }
    free(node->entry);
    free(node);
    list->size--;
}

void id1(list_entry_int* list) {
    list_node_entry_int* node = list->head;
    while (node) {
        list_node_entry_int* next = node->next;
        free(node->entry);
        free(node);
        node = next;
    }
    free(list);
}


map_entry_int* id27(int capacity) {
    map_entry_int* map = malloc(sizeof(map_entry_int));
    map->size = 0;
    int byte_count = capacity * sizeof(list_entry_int*);
    map->table = malloc(byte_count);
    memset(map->table, 0, byte_count);
    map->table_size = capacity;
    return map;
}

void id4(map_entry_int* map, int capacity) {
    int byte_count = capacity * sizeof(list_entry_int*);
    list_entry_int** new_table = malloc(byte_count);
    memset(new_table, 0, byte_count);
    for (int i = 0; i < map->table_size; ++i) {
        if (map->table[i]) {
            list_entry_int* bucket = map->table[i];
            list_node_entry_int* node = bucket->head;
            while (node) {
                int hash = node->entry->key % capacity;
                list_entry_int* new_bucket = new_table[hash];
                if (!new_bucket) {
                    new_bucket = id16();
                    new_table[hash] = new_bucket;
                }
                id0(new_bucket, node->entry->key, node->entry->value);
                node = node->next;
            }
            id1(bucket);
        }
    }
    free(map->table);
    map->table = new_table;
    map->table_size = capacity;
}

void id5(map_entry_int* map, int key, int value) {
    double load_factor = (double) map->size / map->table_size;
    if (load_factor >= 0.75) {
        id4(map, map->table_size * 2);
    }

    int hash = key % map->table_size;
    list_entry_int** table = map->table;
    list_entry_int* bucket = table[hash];
    if (!bucket) {
        bucket = id16();
        table[hash] = bucket;
    }
    list_node_entry_int* node = bucket->head;
    while (node) {
        if (node->entry->key == key) {
            node->entry->value = value;
            return;
        }
        node = node->next;
    }
    id0(bucket, key, value);
    map->size++;
}

entry_int* id20(map_entry_int* map, int key) {
    int hash = key % map->table_size;
    list_entry_int** table = map->table;
    list_entry_int* bucket = table[hash];
    if (!bucket) {
        return NULL;
    }
    list_node_entry_int* node = bucket->head;
    while (node) {
        if (node->entry->key == key) {
            return node->entry;
        }
        node = node->next;
    }
    return NULL;
}

int id12(map_entry_int* map, int key) {
    int hash = key % map->table_size;
    list_entry_int** table = map->table;
    list_entry_int* bucket = table[hash];
    if (!bucket) {
        return 0;
    }
    list_node_entry_int* node = bucket->head;
    while (node) {
        if (node->entry->key == key) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

int id25(map_entry_int* map, int key) {
    int hash = key % map->table_size;
    list_entry_int** table = map->table;
    list_entry_int* bucket = table[hash];
    if (!bucket) {
        return 0;
    }
    list_node_entry_int* node = bucket->head;
    while (node) {
        if (node->entry->key == key) {
            id29(bucket, node);
            map->size--;
            return 1;
        }
        node = node->next;
    }
    return 0;
}

void id6(map_entry_int* map) {
    for (int i = 0; i < map->table_size; ++i) {
        if (map->table[i]) {
            id1(map->table[i]);
        }
    }
    free(map->table);
    free(map);
}

void id7() {
    map_entry_int* map = id27(1);
    id5(map, 1, 1);
    id5(map, 2, 2);
    id5(map, 3, 3);
    id5(map, 4, 4);
    id5(map, 5, 5);
    id5(map, 6, 6);
    id5(map, 7, 7);
    id5(map, 8, 8);
    id5(map, 9, 9);
    id25(map, 4);
    printf("size=%d\n", map->size);
    printf("map[0]=%d\n", id20(map, 0) == NULL);
    printf("map[1]=%d\n", id20(map, 1)->value);
    printf("map[2]=%d\n", id20(map, 2)->value);
    printf("map[3]=%d\n", id20(map, 3)->value);
    printf("map[4]=%d\n", id20(map, 4) == NULL);
    printf("map[5]=%d\n", id20(map, 5)->value);
    printf("map[9]=%d\n", id20(map, 9)->value);
    printf("map[10]=%d\n", id20(map, 10) == NULL);
    id6(map);
}



dsf* id18(int capacity) {
    dsf* set = malloc(sizeof(dsf));
    set->capacity = capacity;
    set->parent = malloc(capacity * sizeof(int));
    set->rank = calloc(capacity, sizeof(int));
    set->size = calloc(capacity, sizeof(int));
    for (int i = 0; i < capacity; ++i) {
        set->parent[i] = i;
        set->size[i] = 1;
    }
    return set;
}

void id19(dsf* set, int x, int y) {
    x = id17(set, x);
    y = id17(set, y);
    if (x == y) {
        return;
    }
    if (set->rank[x] >= set->rank[y]) {
        set->rank[x]++;
        set->parent[y] = x;
        set->size[x] += set->size[y];
    } else {
        set->rank[y]++;
        set->parent[x] = y;
        set->size[y] += set->size[x];
    }
}

int id17(dsf* set, int x) {
    if (set->parent[x] != x) {
        set->parent[x] = id17(set, set->parent[x]);
    }
    return set->parent[x];
}

void id22() {
    dsf* set = id18(5);
    assert(id17(set, 2) == 2);
    id19(set, 1, 5);
    id19(set, 2, 4);
    assert(id17(set, 1) == 1);
    assert(id17(set, 2) == 2);
    assert(id17(set, 3) == 3);
    assert(id17(set, 4) == 2);
    assert(id17(set, 5) == 1);
    id19(set, 5, 4);
    assert(id17(set, 1) == 1);
    assert(id17(set, 2) == 1);
    assert(id17(set, 3) == 3);
    assert(id17(set, 4) == 1);
    assert(id17(set, 5) == 1);
}

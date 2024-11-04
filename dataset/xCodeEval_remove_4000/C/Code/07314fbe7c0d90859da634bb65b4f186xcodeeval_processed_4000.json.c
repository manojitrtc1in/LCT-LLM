




int min2(int a, int b);
int min3(int a, int b, int c);
char* id19(int n);



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
list_node_int* id24(list_int* list, int value);
void id3(list_int* list, list_node_int* node);
void id22(list_int* list);


typedef struct {
    int size;
    int table_size;
    list_int** table;
} set_int;

set_int* id9(int capacity);
void id12(set_int* set, int value);
int id15(set_int* set, int value);
int id20(set_int* set, int value);
void id11(set_int* set);



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
void id25(list_entry_int* list, list_node_entry_int* node);
void id1(list_entry_int* list);


typedef struct {
    int size;
    int table_size;
    list_entry_int** table;
} map_entry_int;

map_entry_int* id23(int capacity);
void id5(map_entry_int* map, int key, int value);
entry_int* id18(map_entry_int* map, int key);
int id13(map_entry_int* map, int key);
int id21(map_entry_int* map, int key);
void id7(map_entry_int* map);




int main() {
    int a[] = {4, 8, 15, 16, 23, 42};
    map_entry_int* map = id23(N * N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i != j) {
                id5(map, a[i]*a[j], i*N + j);
                

            }
        }
    }
    if (map->size != N * (N - 1) / 2) {
        printf("size=%d\n", map->size);
        return 1;
    }

    int i1[] = {1, 2, 3, 4};
    int i2[] = {2, 3, 4, 5};
    int ab[MAX];

    for (int i = 0; i < MAX; ++i) {
        printf("? %d %d\n", i1[i], i2[i]);
        fflush(stdout);
        scanf("%d", &ab[i]);
        if (!ab[i]) {
            return 1;
        }
    }

    int answer[N];
    for (int i = 0; i < MAX; ++i) {
        entry_int* entry = id18(map, ab[i]);
        if (!entry) {
            printf("no entry %d\n", ab[i]);
            return 1;
        }
        int value = entry->value;
        int x = a[value / N];
        int y = a[value % N];
        


        if (i == 0) {
            answer[0] = x;
            answer[1] = y;
        } else {
            if (answer[i] == x) {
                answer[i+1] = y;
            } else if (answer[i] == y) {
                answer[i+1] = x;
            } else {
                if (i == 1) {
                    int tmp = answer[i-1];
                    answer[i-1] = answer[i];
                    answer[i] = tmp;
                    if (answer[i] == x) {
                        answer[i+1] = y;
                    } else if (answer[i] == y) {
                        answer[i+1] = x;
                    } else {
                        printf("wrong value %d %d\n", x, y);
                        return 1;
                    }
                } else {
                    printf("wrong value %d %d\n", x, y);
                    return 1;
                }
            }
        }
    }

    set_int* found = id9(N);
    for (int i = 0; i < N-1; ++i) {
        id12(found, answer[i]);
    }
    answer[N-1] = 0;
    for (int i = 0; i < N; ++i) {
        if (!id15(found, a[i])) {
            answer[N-1] = a[i];
            break;
        }
    }

    printf("!");
    for (int i = 0; i < N; ++i) {
        printf(" %d", answer[i]);
    }
    printf("\n");
    fflush(stdout);

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

char* id19(int n) {
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

list_node_int* id24(list_int* list, int value) {
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

void id22(list_int* list) {
    list_node_int* node = list->head;
    while (node) {
        list_node_int* next = node->next;
        free(node);
        node = next;
    }
    free(list);
}

void id17() {
    list_int* list = id2();
    id24(list, 1);
    id24(list, 2);
    list_node_int* node3 = id24(list, 3);
    id24(list, 4);
    id24(list, 5);
    id3(list, list->tail);
    id24(list, 6);
    id3(list, list->head);
    id24(list, 7);
    id3(list, node3);
    id24(list, 8);
    id24(list, 9);
    id24(list, 10);

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

void id14(set_int* set, int capacity) {
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
                id24(new_bucket, node->value);
                node = node->next;
            }
            id22(bucket);
        }
    }
    free(set->table);
    set->table = new_table;
    set->table_size = capacity;
}

void id12(set_int* set, int value) {
    double load_factor = (double) set->size / set->table_size;
    if (load_factor >= 0.75) {
        id14(set, set->table_size * 2);
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
    id24(bucket, value);
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

int id20(set_int* set, int value) {
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

void id11(set_int* set) {
    for (int i = 0; i < set->table_size; ++i) {
        if (set->table[i]) {
            id22(set->table[i]);
        }
    }
    free(set->table);
    free(set);
}

void id6() {
    set_int* set = id9(1);
    id12(set, 1);
    id12(set, 2);
    id12(set, 3);
    id12(set, 4);
    id12(set, 5);
    id12(set, 6);
    id12(set, 7);
    id12(set, 8);
    id12(set, 9);
    id20(set, 4);
    printf("size=%d\n", set->size);
    printf("set[0]=%d\n", id15(set, 0));
    printf("set[1]=%d\n", id15(set, 1));
    printf("set[2]=%d\n", id15(set, 2));
    printf("set[3]=%d\n", id15(set, 3));
    printf("set[4]=%d\n", id15(set, 4));
    printf("set[5]=%d\n", id15(set, 5));
    printf("set[9]=%d\n", id15(set, 9));
    printf("set[10]=%d\n", id15(set, 10));
    id11(set);
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

void id25(list_entry_int* list, list_node_entry_int* node) {
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


map_entry_int* id23(int capacity) {
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

entry_int* id18(map_entry_int* map, int key) {
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

int id13(map_entry_int* map, int key) {
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

int id21(map_entry_int* map, int key) {
    int hash = key % map->table_size;
    list_entry_int** table = map->table;
    list_entry_int* bucket = table[hash];
    if (!bucket) {
        return 0;
    }
    list_node_entry_int* node = bucket->head;
    while (node) {
        if (node->entry->key == key) {
            id25(bucket, node);
            map->size--;
            return 1;
        }
        node = node->next;
    }
    return 0;
}

void id7(map_entry_int* map) {
    for (int i = 0; i < map->table_size; ++i) {
        if (map->table[i]) {
            id1(map->table[i]);
        }
    }
    free(map->table);
    free(map);
}

void id10() {
    map_entry_int* map = id23(1);
    id5(map, 1, 1);
    id5(map, 2, 2);
    id5(map, 3, 3);
    id5(map, 4, 4);
    id5(map, 5, 5);
    id5(map, 6, 6);
    id5(map, 7, 7);
    id5(map, 8, 8);
    id5(map, 9, 9);
    id21(map, 4);
    printf("size=%d\n", map->size);
    printf("map[0]=%d\n", id18(map, 0) == NULL);
    printf("map[1]=%d\n", id18(map, 1)->value);
    printf("map[2]=%d\n", id18(map, 2)->value);
    printf("map[3]=%d\n", id18(map, 3)->value);
    printf("map[4]=%d\n", id18(map, 4) == NULL);
    printf("map[5]=%d\n", id18(map, 5)->value);
    printf("map[9]=%d\n", id18(map, 9)->value);
    printf("map[10]=%d\n", id18(map, 10) == NULL);
    id7(map);
}

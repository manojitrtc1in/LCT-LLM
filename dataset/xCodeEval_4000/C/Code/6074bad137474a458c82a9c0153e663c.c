#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int min2(int a, int b);
int min3(int a, int b, int c);
char* erastosthen_sieve(int n);



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

list_int* list_int_create();
list_node_int* list_int_add(list_int* list, int value);
void list_int_remove(list_int* list, list_node_int* node);
void list_int_delete(list_int* list);


typedef struct {
    int size;
    int table_size;
    list_int** table;
} set_int;

set_int* set_int_create(int capacity);
void set_int_add(set_int* set, int value);
int set_int_contains(set_int* set, int value);
int set_int_remove(set_int* set, int value);
void set_int_delete(set_int* set);



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

list_entry_int* list_entry_int_create();
list_node_entry_int* list_entry_int_add(list_entry_int* list, int key, int value);
void list_entry_int_remove(list_entry_int* list, list_node_entry_int* node);
void list_entry_int_delete(list_entry_int* list);


typedef struct {
    int size;
    int table_size;
    list_entry_int** table;
} map_entry_int;

map_entry_int* map_entry_int_create(int capacity);
void map_entry_int_put(map_entry_int* map, int key, int value);
int map_entry_int_get(map_entry_int* map, int key);
int map_entry_int_contains_key(map_entry_int* map, int key);
int map_entry_int_remove(map_entry_int* map, int key);
void map_entry_int_delete(map_entry_int* map);


#define MAX 251
int main() {
    int n, q;
    scanf("%d %d\n", &n, &q);

    char* word = malloc((n + 1) * sizeof(char));
    scanf("%s\n", word);

    int** N = malloc(26 * sizeof(int*));
    int* N_mem = malloc(26 * (n + 2) * sizeof(int));
    for (int c = 0; c < 26; ++c) {
        N[c] = N_mem + c * (n + 2);
    }
    for (int c = 0; c < 26; ++c) {
        N[c][n+1] = n;
        N[c][n  ] = n;
        for (int i = n - 1; i >= 0; --i) {
            if (word[i] == 'a' + c) {
                N[c][i] = i;
            } else {
                N[c][i] = N[c][i+1];
            }
        }
    }

    


    int*** D = malloc(MAX * sizeof(int**));
    int** p_bytes_1 = malloc(MAX * MAX * sizeof(int*));
    int* p_bytes_2 = malloc(MAX * MAX * MAX * sizeof(int));
    for (int i = 0; i < MAX; ++i) {
        D[i] = p_bytes_1 + i * MAX;
        for (int j = 0; j < MAX; ++j) {
            D[i][j] = p_bytes_2 + i * MAX * MAX + j * MAX;
        }
    }

    D[0][0][0] = -1;

    int len[3];
    char* religion[3];
    for (int i = 0; i < 3; ++i) {
        int n_bytes = (q + 1) * sizeof(char);
        len[i] = 0;
        religion[i] = malloc(n_bytes);
        memset(religion[i], 0, n_bytes);
    }

    

    for (int change = 0; change < q; ++change) {
        char sign;
        int i;
        scanf("%c %d", &sign, &i);

        int length = len[i - 1];
        char* a = religion[i - 1];
        if (sign == '+') {
            char new_char;
            scanf(" %c", &new_char);
            a[length] = new_char;
            a[length + 1] = 0;
            len[i - 1] = length + 1;

            int min1 = i == 1 ? len[0] : 0;
            int min2 = i == 2 ? len[1] : 0;
            int min3 = i == 3 ? len[2] : 0;
            for (int n1 = min1; n1 <= len[0]; n1++) {
                for (int n2 = min2; n2 <= len[1]; n2++) {
                    for (int n3 = min3; n3 <= len[2]; n3++) {
                        int* min = &D[n1][n2][n3];
                        *min = n;
                        int d = n;
                        if (n1) {
                            d = N[religion[0][n1-1] - 'a'][D[n1-1][n2][n3] + 1];
                            *min = d < *min ? d : *min;
                        }
                        if (n2) {
                            d = N[religion[1][n2-1] - 'a'][D[n1][n2-1][n3] + 1];
                            *min = d < *min ? d : *min;
                        }
                        if (n3) {
                            d = N[religion[2][n3-1] - 'a'][D[n1][n2][n3-1] + 1];
                            *min = d < *min ? d : *min;
                        }
                    }
                }
            }
        } else if (sign == '-') {
            a[length - 1] = 0;
            len[i - 1] = length - 1;
        } else {
            return 1;
        }
        scanf("\n");

        int d = D[len[0]][len[1]][len[2]];
        if (d < n) {
            

            printf("YES\n");
        } else {
            

            printf("NO\n");
        }
    }

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
    int min = a;
    min = min2(min, b);
    min = min2(min, c);
    return min;
}

char* erastosthen_sieve(int n) {
    char* a = malloc((n + 1) * sizeof(char));
    if (a == NULL) {
        return NULL;
    }
    a[0] = 0;
    a[1] = 0;
    for (int i = 2; i < n + 1; ++i) {
        a[i] = 1;
    }
    int max_sqrt = sqrt(n) + 1;
    for (int i = 2; i < max_sqrt; ++i) {
        if (a[i]) {
            for (int j = i; j < (n + 1) / i; ++j) {
                a[i*j] = 0;
            }
        }
    }
    return a;
}



list_int* list_int_create() {
    list_int* list = malloc(sizeof(list_int));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

list_node_int* list_int_add(list_int* list, int value) {
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

void list_int_remove(list_int* list, list_node_int* node) {
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

void list_int_delete(list_int* list) {
    list_node_int* node = list->head;
    while (node) {
        list_node_int* next = node->next;
        free(node);
        node = next;
    }
    free(list);
}

void test_list_int() {
    list_int* list = list_int_create();
    list_int_add(list, 1);
    list_int_add(list, 2);
    list_node_int* node3 = list_int_add(list, 3);
    list_int_add(list, 4);
    list_int_add(list, 5);
    list_int_remove(list, list->tail);
    list_int_add(list, 6);
    list_int_remove(list, list->head);
    list_int_add(list, 7);
    list_int_remove(list, node3);
    list_int_add(list, 8);
    list_int_add(list, 9);
    list_int_add(list, 10);

    list_node_int* node = list->head;
    while (node) {
        printf("%d\n", node->value);
        node = node->next;
    }
    printf("size=%d\n", list->size);
}


set_int* set_int_create(int capacity) {
    set_int* set = malloc(sizeof(set_int));
    set->size = 0;
    int byte_count = capacity * sizeof(list_int*);
    set->table = malloc(byte_count);
    memset(set->table, 0, byte_count);
    set->table_size = capacity;
    return set;
}

void set_int_resize(set_int* set, int capacity) {
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
                    new_bucket = list_int_create();
                    new_table[hash] = new_bucket;
                }
                list_int_add(new_bucket, node->value);
                node = node->next;
            }
            list_int_delete(bucket);
        }
    }
    free(set->table);
    set->table = new_table;
    set->table_size = capacity;
}

void set_int_add(set_int* set, int value) {
    double load_factor = (double) set->size / set->table_size;
    if (load_factor >= 0.75) {
        set_int_resize(set, set->table_size * 2);
    }

    int hash = value % set->table_size;
    list_int** table = set->table;
    list_int* bucket = table[hash];
    if (!bucket) {
        bucket = list_int_create();
        table[hash] = bucket;
    }
    list_node_int* node = bucket->head;
    while (node) {
        if (node->value == value) {
            return;
        }
        node = node->next;
    }
    list_int_add(bucket, value);
    set->size++;
}

int set_int_contains(set_int* set, int value) {
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

int set_int_remove(set_int* set, int value) {
    int hash = value % set->table_size;
    list_int** table = set->table;
    list_int* bucket = table[hash];
    if (!bucket) {
        return 0;
    }
    list_node_int* node = bucket->head;
    while (node) {
        if (node->value == value) {
            list_int_remove(bucket, node);
            set->size--;
            return 1;
        }
        node = node->next;
    }
    return 0;
}

void set_int_delete(set_int* set) {
    for (int i = 0; i < set->table_size; ++i) {
        if (set->table[i]) {
            list_int_delete(set->table[i]);
        }
    }
    free(set->table);
    free(set);
}

void test_set_int() {
    set_int* set = set_int_create(1);
    set_int_add(set, 1);
    set_int_add(set, 2);
    set_int_add(set, 3);
    set_int_add(set, 4);
    set_int_add(set, 5);
    set_int_add(set, 6);
    set_int_add(set, 7);
    set_int_add(set, 8);
    set_int_add(set, 9);
    set_int_remove(set, 4);
    printf("size=%d\n", set->size);
    printf("set[0]=%d\n", set_int_contains(set, 0));
    printf("set[1]=%d\n", set_int_contains(set, 1));
    printf("set[2]=%d\n", set_int_contains(set, 2));
    printf("set[3]=%d\n", set_int_contains(set, 3));
    printf("set[4]=%d\n", set_int_contains(set, 4));
    printf("set[5]=%d\n", set_int_contains(set, 5));
    printf("set[9]=%d\n", set_int_contains(set, 9));
    printf("set[10]=%d\n", set_int_contains(set, 10));
    set_int_delete(set);
}



list_entry_int* list_entry_int_create() {
    list_entry_int* list = malloc(sizeof(list_entry_int));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

list_node_entry_int* list_entry_int_add(list_entry_int* list, int key, int value) {
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

void list_entry_int_remove(list_entry_int* list, list_node_entry_int* node) {
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

void list_entry_int_delete(list_entry_int* list) {
    list_node_entry_int* node = list->head;
    while (node) {
        list_node_entry_int* next = node->next;
        free(node->entry);
        free(node);
        node = next;
    }
    free(list);
}


map_entry_int* map_entry_int_create(int capacity) {
    map_entry_int* map = malloc(sizeof(map_entry_int));
    map->size = 0;
    int byte_count = capacity * sizeof(list_entry_int*);
    map->table = malloc(byte_count);
    memset(map->table, 0, byte_count);
    map->table_size = capacity;
    return map;
}

void map_entry_int_resize(map_entry_int* map, int capacity) {
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
                    new_bucket = list_entry_int_create();
                    new_table[hash] = new_bucket;
                }
                list_entry_int_add(new_bucket, node->entry->key, node->entry->value);
                node = node->next;
            }
            list_entry_int_delete(bucket);
        }
    }
    free(map->table);
    map->table = new_table;
    map->table_size = capacity;
}

void map_entry_int_put(map_entry_int* map, int key, int value) {
    double load_factor = (double) map->size / map->table_size;
    if (load_factor >= 0.75) {
        map_entry_int_resize(map, map->table_size * 2);
    }

    int hash = key % map->table_size;
    list_entry_int** table = map->table;
    list_entry_int* bucket = table[hash];
    if (!bucket) {
        bucket = list_entry_int_create();
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
    list_entry_int_add(bucket, key, value);
    map->size++;
}

int map_entry_int_get(map_entry_int* map, int key) {
    int hash = key % map->table_size;
    list_entry_int** table = map->table;
    list_entry_int* bucket = table[hash];
    if (!bucket) {
        return 0;
    }
    list_node_entry_int* node = bucket->head;
    while (node) {
        if (node->entry->key == key) {
            return node->entry->value;
        }
        node = node->next;
    }
    return 0;
}

int map_entry_int_contains_key(map_entry_int* map, int key) {
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

int map_entry_int_remove(map_entry_int* map, int key) {
    int hash = key % map->table_size;
    list_entry_int** table = map->table;
    list_entry_int* bucket = table[hash];
    if (!bucket) {
        return 0;
    }
    list_node_entry_int* node = bucket->head;
    while (node) {
        if (node->entry->key == key) {
            list_entry_int_remove(bucket, node);
            map->size--;
            return 1;
        }
        node = node->next;
    }
    return 0;
}

void map_entry_int_delete(map_entry_int* map) {
    for (int i = 0; i < map->table_size; ++i) {
        if (map->table[i]) {
            list_entry_int_delete(map->table[i]);
        }
    }
    free(map->table);
    free(map);
}

void test_map_entry_int() {
    map_entry_int* map = map_entry_int_create(1);
    map_entry_int_put(map, 1, 1);
    map_entry_int_put(map, 2, 2);
    map_entry_int_put(map, 3, 3);
    map_entry_int_put(map, 4, 4);
    map_entry_int_put(map, 5, 5);
    map_entry_int_put(map, 6, 6);
    map_entry_int_put(map, 7, 7);
    map_entry_int_put(map, 8, 8);
    map_entry_int_put(map, 9, 9);
    map_entry_int_remove(map, 4);
    printf("size=%d\n", map->size);
    printf("map[0]=%d\n", map_entry_int_get(map, 0));
    printf("map[1]=%d\n", map_entry_int_get(map, 1));
    printf("map[2]=%d\n", map_entry_int_get(map, 2));
    printf("map[3]=%d\n", map_entry_int_get(map, 3));
    printf("map[4]=%d\n", map_entry_int_get(map, 4));
    printf("map[5]=%d\n", map_entry_int_get(map, 5));
    printf("map[9]=%d\n", map_entry_int_get(map, 9));
    printf("map[10]=%d\n", map_entry_int_get(map, 10));
    map_entry_int_delete(map);
}

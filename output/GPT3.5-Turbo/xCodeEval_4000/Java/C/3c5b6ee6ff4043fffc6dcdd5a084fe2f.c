#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* x;
    char* y;
} State;

State* createState(char* x, char* y) {
    State* state = (State*)malloc(sizeof(State));
    state->x = x;
    state->y = y;
    return state;
}

int hashCode(State* state) {
    int prime = 31;
    int result = 1;
    result = prime * result + ((state->x == NULL) ? 0 : strcmp(state->x, ""));
    result = prime * result + ((state->y == NULL) ? 0 : strcmp(state->y, ""));
    return result;
}

int equals(State* state1, State* state2) {
    if (state1 == state2) {
        return 1;
    }
    if (state2 == NULL) {
        return 0;
    }
    if (strcmp(state1->x, state2->x) != 0) {
        return 0;
    }
    if (strcmp(state1->y, state2->y) != 0) {
        return 0;
    }
    return 1;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} ArrayList;

ArrayList* createArrayList() {
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    list->arr = NULL;
    list->size = 0;
    list->capacity = 0;
    return list;
}

void add(ArrayList* list, int element) {
    if (list->size == list->capacity) {
        int newCapacity = (list->capacity == 0) ? 1 : 2 * list->capacity;
        int* newArr = (int*)malloc(newCapacity * sizeof(int));
        memcpy(newArr, list->arr, list->size * sizeof(int));
        free(list->arr);
        list->arr = newArr;
        list->capacity = newCapacity;
    }
    list->arr[list->size++] = element;
}

void reverse(ArrayList* list) {
    int i, j;
    for (i = 0, j = list->size - 1; i < j; i++, j--) {
        int temp = list->arr[i];
        list->arr[i] = list->arr[j];
        list->arr[j] = temp;
    }
}

typedef struct {
    State** arr;
    int size;
    int capacity;
} ArrayDeque;

ArrayDeque* createArrayDeque() {
    ArrayDeque* deque = (ArrayDeque*)malloc(sizeof(ArrayDeque));
    deque->arr = NULL;
    deque->size = 0;
    deque->capacity = 0;
    return deque;
}

void push(ArrayDeque* deque, State* state) {
    if (deque->size == deque->capacity) {
        int newCapacity = (deque->capacity == 0) ? 1 : 2 * deque->capacity;
        State** newArr = (State**)malloc(newCapacity * sizeof(State*));
        memcpy(newArr, deque->arr, deque->size * sizeof(State*));
        free(deque->arr);
        deque->arr = newArr;
        deque->capacity = newCapacity;
    }
    deque->arr[deque->size++] = state;
}

State* pop(ArrayDeque* deque) {
    if (deque->size == 0) {
        return NULL;
    }
    State* state = deque->arr[deque->size - 1];
    deque->size--;
    return state;
}

typedef struct {
    State* key;
    int value;
} HashMapEntry;

typedef struct {
    HashMapEntry** arr;
    int size;
    int capacity;
} HashMap;

HashMap* createHashMap() {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->arr = NULL;
    map->size = 0;
    map->capacity = 0;
    return map;
}

int hash(HashMap* map, State* key) {
    int prime = 31;
    int result = 1;
    result = prime * result + ((key->x == NULL) ? 0 : strcmp(key->x, ""));
    result = prime * result + ((key->y == NULL) ? 0 : strcmp(key->y, ""));
    return result % map->capacity;
}

void put(HashMap* map, State* key, int value) {
    int index = hash(map, key);
    HashMapEntry* entry = (HashMapEntry*)malloc(sizeof(HashMapEntry));
    entry->key = key;
    entry->value = value;
    map->arr[index] = entry;
    map->size++;
}

int get(HashMap* map, State* key) {
    int index = hash(map, key);
    HashMapEntry* entry = map->arr[index];
    if (entry != NULL && equals(entry->key, key)) {
        return entry->value;
    }
    return -1;
}

void freeHashMap(HashMap* map) {
    int i;
    for (i = 0; i < map->capacity; i++) {
        HashMapEntry* entry = map->arr[i];
        if (entry != NULL) {
            free(entry->key);
            free(entry);
        }
    }
    free(map->arr);
    free(map);
}

ArrayList* runs(char* s) {
    ArrayList* ret = createArrayList();
    int run = 0;
    int i;
    for (i = strlen(s) - 1; i >= 0; i--) {
        if (i != strlen(s) - 1 && s[i + 1] != s[i]) {
            add(ret, run);
            run = 0;
        }
        run++;
    }
    add(ret, run);
    return ret;
}

int slow(char* s, char* t) {
    ArrayDeque* que = createArrayDeque();

    push(que, createState(s, t));
    HashMap* dist = createHashMap();

    put(dist, createState(s, t), 0);

    while (que->size > 0) {
        State* st = pop(que);

        char* x = st->x;
        char* y = st->y;

        int curD = get(dist, st);

        if ((strstr(x, "a") == NULL || strstr(x, "b") == NULL) && (strstr(y, "a") == NULL || strstr(y, "b") == NULL)) {
            return get(dist, st);
        }

        int i, j;
        for (i = 0; i <= strlen(x); i++) {
            for (j = 0; j <= strlen(y); j++) {

                char* x0 = (char*)malloc((i + 1) * sizeof(char));
                strncpy(x0, x, i);
                x0[i] = '\0';

                char* x1 = (char*)malloc((strlen(x) - i + 1) * sizeof(char));
                strcpy(x1, x + i);

                char* y0 = (char*)malloc((j + 1) * sizeof(char));
                strncpy(y0, y, j);
                y0[j] = '\0';

                char* y1 = (char*)malloc((strlen(y) - j + 1) * sizeof(char));
                strcpy(y1, y + j);

                char* nx = (char*)malloc((strlen(y0) + strlen(x1) + 1) * sizeof(char));
                strcpy(nx, y0);
                strcat(nx, x1);

                char* ny = (char*)malloc((strlen(x0) + strlen(y1) + 1) * sizeof(char));
                strcpy(ny, x0);
                strcat(ny, y1);

                State* nst = createState(nx, ny);
                if (get(dist, nst) == -1) {
                    put(dist, nst, curD + 1);
                    push(que, nst);
                }
            }
        }
    }

    return -1;
}

int fastSame(int x, int y) {
    int ret = (x + y) / 2;
    if ((x + y) % 4 == 1 && (x == 1 || y == 1)) {
        ret++;
    }
    return ret;
}

int fastDiff(int x, int y) {
    if (x == 1 && y == 1) {
        return 0;
    }
    int ret;
    if ((x + y) % 4 == 0) {
        ret = (x + y) / 2;
        if (x % 2 == 0) {
            ret--;
        }
    } else if ((x + y) % 4 == 1) {
        ret = (x + y) / 2;
        if (x == 1 || y == 1) {
            ret++;
        }
    } else if ((x + y) % 4 == 2) {
        ret = (x + y) / 2;
        if (x != 1 && x != 2 && y != 1 && y != 2 && x % 2 == 1) {
            ret--;
        }
    } else if ((x + y) % 4 == 3) {
        ret = (x + y) / 2;
    } else {
        exit(1);
    }
    return ret;
}

int fast(char* s, char* t) {
    ArrayList* ret = createArrayList();

    ArrayList* rs = runs(s);
    ArrayList* rt = runs(t);
    int areSame = s[0] == t[0];

    while (areSame) {
        int p = rs->size;
        int q = rt->size;

        int x = -1, y = -1;

        int xx, yy;
        for (xx = 0; xx <= 3 && xx <= p; xx++) {
            for (yy = 0; yy <= 3 && yy <= q; yy++) {

                if (xx + yy == 0 || x + y == xx + yy) {
                    continue;
                }

                if (xx % 2 == yy % 2) {
                    continue;
                }

                int nx = p - xx + yy;
                if (xx != p && yy != 0) {
                    nx--;
                }

                int ny = q - yy + xx;
                if (yy != q && xx != 0) {
                    ny--;
                }

                if (nx == 0 || ny == 0) {
                    continue;
                }

                if (nx + ny == p + q) {
                    continue;
                }

                int val;
                if ((xx == 0 || yy == 0) && (xx + yy) % 2 == 1) {
                    val = fastDiff(nx, ny) + 1;
                } else {
                    val = fastSame(nx, ny) + 1;
                }

                if (fastSame(p, q) == val) {
                    x = xx;
                    y = yy;
                    break;
                }
            }
            if (yy <= 3 && yy <= q) {
                break;
            }
        }

        if ((x == 0 || y == 0) && (x + y) % 2 == 1) {
            areSame = 0;
        }

        ArrayList* delS = createArrayList();
        ArrayList* delT = createArrayList();

        int ans1 = 0;
        int ans2 = 0;

        int i;
        for (i = 0; i < x; i++) {
            int delta = rs->arr[--rs->size];
            ans1 += delta;
            add(delS, delta);
        }

        for (i = 0; i < y; i++) {
            int delta = rt->arr[--rt->size];
            ans2 += delta;
            add(delT, delta);
        }

        add(ret, ans1);
        add(ret, ans2);

        reverse(delS);
        reverse(delT);

        for (i = 0; i < x; i++) {
            if (i == 0 && rt->size > 0) {
                rt->arr[rt->size - 1] += delS->arr[i];
            } else {
                add(rt, delS->arr[i]);
            }
        }

        for (i = 0; i < y; i++) {
            if (i == 0 && rs->size > 0) {
                rs->arr[rs->size - 1] += delT->arr[i];
            } else {
                add(rs, delT->arr[i]);
            }
        }
    }

    while (rs->size > 1 || rt->size > 1) {

        int p = rs->size;
        int q = rt->size;

        int x = -1, y = -1;

        int tp, tq;
        for (tp = 1; tp <= 3 && tp <= p; tp += 2) {
            for (tq = 1; tq <= 3 && tq <= q; tq += 2) {

                int newP = p - tp + tq;
                if (tp != p) {
                    newP--;
                }

                int newQ = q - tq + tp;
                if (tq != q) {
                    newQ--;
                }

                if (newP == 0 || newQ == 0) {
                    continue;
                }

                if (newP + newQ == p + q) {
                    continue;
                }

                if (fastDiff(p, q) == fastDiff(newP, newQ) + 1) {
                    x = tp;
                    y = tq;
                    break;
                }
            }
            if (tq <= 3 && tq <= q) {
                break;
            }
        }

        ArrayList* delS = createArrayList();
        ArrayList* delT = createArrayList();

        int ans1 = 0;
        int ans2 = 0;

        int i;
        for (i = 0; i < x; i++) {
            int delta = rs->arr[--rs->size];
            ans1 += delta;
            add(delS, delta);
        }

        for (i = 0; i < y; i++) {
            int delta = rt->arr[--rt->size];
            ans2 += delta;
            add(delT, delta);
        }

        add(ret, ans1);
        add(ret, ans2);

        reverse(delS);
        reverse(delT);

        for (i = 0; i < x; i++) {
            if (i == 0 && rt->size > 0) {
                rt->arr[rt->size - 1] += delS->arr[i];
            } else {
                add(rt, delS->arr[i]);
            }
        }

        for (i = 0; i < y; i++) {
            if (i == 0 && rs->size > 0) {
                rs->arr[rs->size - 1] += delT->arr[i];
            } else {
                add(rs, delT->arr[i]);
            }
        }
    }

    printf("%d\n", ret->size / 2);
    int i;
    for (i = 0; i < ret->size; i += 2) {
        printf("%d %d\n", ret->arr[i], ret->arr[i + 1]);
    }
    return ret->size / 2;
}

void submit() {
    char s[100];
    char t[100];

    scanf("%s", s);
    scanf("%s", t);

    fast(s, t);
}

int main() {
    submit();
    return 0;
}

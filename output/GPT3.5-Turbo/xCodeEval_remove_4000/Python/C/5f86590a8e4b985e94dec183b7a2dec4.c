#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

typedef struct id17 {
    char* id8[2];
    struct id17* prev;
    struct id17* next;
} id17;

id17* id17_new() {
    id17* self = malloc(sizeof(id17));
    self->id8[0] = "prev";
    self->id8[1] = "next";
    self->prev = NULL;
    self->next = NULL;
    return self;
}

void id17_connect(id17* self, id17* node) {
    self->next = node;
    node->prev = self;
}

void id17_splice(id17* self, id17* fragment) {
    if (fragment->prev) {
        fragment->prev->next = NULL;
    }

    id17* u = self;
    id17* v = fragment;
    id17* w = self->next;

    id17_connect(u, v);
    while (v->next) {
        v = v->next;
    }
    id17_connect(v, w);
}

void id17_splice1(id17* self, id17* node) {
    id17_connect(node, self->next);
    id17_connect(self, node);
}

void id17_eject(id17* self) {
    id17_connect(self->prev, self->next);
}

typedef struct {
    id17* head;
    id17* tail;
} id17_iter;

id17_iter id17_iter_new(id17* start) {
    id17_iter iter;
    iter.head = start;
    iter.tail = start;
    return iter;
}

id17* id17_iter_next(id17_iter* iter) {
    id17* current = iter->head;
    if (current == NULL) {
        return NULL;
    }
    iter->head = current->next;
    if (iter->head == iter->tail) {
        iter->head = NULL;
    }
    return current;
}

typedef struct {
    id17* current;
    id17* start;
} id17_iterator;

id17_iterator id17_iterate(id17* start) {
    id17_iterator iterator;
    iterator.current = start;
    iterator.start = start;
    return iterator;
}

id17* id17_iterator_next(id17_iterator* iterator) {
    id17* current = iterator->current;
    if (current == NULL || current->next == iterator->start) {
        iterator->current = NULL;
        return NULL;
    }
    iterator->current = current->next;
    return current;
}

typedef struct {
    id17* current;
    id17* start;
} id17_reverse_iterator;

id17_reverse_iterator id17_reverse_iterate(id17* start) {
    id17_reverse_iterator iterator;
    iterator.current = start;
    iterator.start = start;
    return iterator;
}

id17* id17_reverse_iterator_next(id17_reverse_iterator* iterator) {
    id17* current = iterator->current;
    if (current == NULL || current->prev == iterator->start) {
        iterator->current = NULL;
        return NULL;
    }
    iterator->current = current->prev;
    return current;
}

typedef struct {
    id17* current;
    id17* start;
} id17_circular_iterator;

id17_circular_iterator id17_circular_iterate(id17* start) {
    id17_circular_iterator iterator;
    iterator.current = start;
    iterator.start = start;
    return iterator;
}

id17* id17_circular_iterator_next(id17_circular_iterator* iterator) {
    id17* current = iterator->current;
    if (current == NULL) {
        return NULL;
    }
    iterator->current = current->next;
    if (iterator->current == iterator->start) {
        iterator->current = NULL;
    }
    return current;
}

typedef struct {
    id17* current;
    id17* start;
} id17_circular_reverse_iterator;

id17_circular_reverse_iterator id17_circular_reverse_iterate(id17* start) {
    id17_circular_reverse_iterator iterator;
    iterator.current = start;
    iterator.start = start;
    return iterator;
}

id17* id17_circular_reverse_iterator_next(id17_circular_reverse_iterator* iterator) {
    id17* current = iterator->current;
    if (current == NULL) {
        return NULL;
    }
    iterator->current = current->prev;
    if (iterator->current == iterator->start) {
        iterator->current = NULL;
    }
    return current;
}

typedef struct {
    id17* current;
    id17* start;
} id17_bidirectional_iterator;

id17_bidirectional_iterator id17_bidirectional_iterate(id17* start) {
    id17_bidirectional_iterator iterator;
    iterator.current = start;
    iterator.start = start;
    return iterator;
}

id17* id17_bidirectional_iterator_next(id17_bidirectional_iterator* iterator) {
    id17* current = iterator->current;
    if (current == NULL) {
        return NULL;
    }
    iterator->current = current->next;
    if (iterator->current == iterator->start) {
        iterator->current = NULL;
    }
    return current;
}

typedef struct {
    id17* current;
    id17* start;
} id17_bidirectional_reverse_iterator;

id17_bidirectional_reverse_iterator id17_bidirectional_reverse_iterate(id17* start) {
    id17_bidirectional_reverse_iterator iterator;
    iterator.current = start;
    iterator.start = start;
    return iterator;
}

id17* id17_bidirectional_reverse_iterator_next(id17_bidirectional_reverse_iterator* iterator) {
    id17* current = iterator->current;
    if (current == NULL) {
        return NULL;
    }
    iterator->current = current->prev;
    if (iterator->current == iterator->start) {
        iterator->current = NULL;
    }
    return current;
}

typedef struct {
    char* id8[6];
    int key;
    int value;
    struct id13* parent;
    struct id13* child;
    int degree;
    bool mark;
} id13;

id13* id13_new(int key, int value) {
    id13* self = malloc(sizeof(id13));
    self->id8[0] = "key";
    self->id8[1] = "value";
    self->id8[2] = "parent";
    self->id8[3] = "child";
    self->id8[4] = "degree";
    self->id8[5] = "mark";
    self->key = key;
    self->value = value;
    self->parent = NULL;
    self->child = NULL;
    self->degree = 0;
    self->mark = false;
    return self;
}

typedef struct {
    id17* head;
    id17* tail;
} id13_iter;

id13_iter id13_iter_new(id17* start) {
    id13_iter iter;
    iter.head = start;
    iter.tail = start;
    return iter;
}

id17* id13_iter_next(id13_iter* iter) {
    id17* current = iter->head;
    if (current == NULL) {
        return NULL;
    }
    iter->head = current->next;
    if (iter->head == iter->tail) {
        iter->head = NULL;
    }
    return current;
}

typedef struct {
    id17* current;
    id17* start;
} id13_iterator;

id13_iterator id13_iterate(id17* start) {
    id13_iterator iterator;
    iterator.current = start;
    iterator.start = start;
    return iterator;
}

id17* id13_iterator_next(id13_iterator* iterator) {
    id17* current = iterator->current;
    if (current == NULL || current->next == iterator->start) {
        iterator->current = NULL;
        return NULL;
    }
    iterator->current = current->next;
    return current;
}

typedef struct {
    id17* current;
    id17* start;
} id13_reverse_iterator;

id13_reverse_iterator id13_reverse_iterate(id17* start) {
    id13_reverse_iterator iterator;
    iterator.current = start;
    iterator.start = start;
    return iterator;
}

id17* id13_reverse_iterator_next(id13_reverse_iterator* iterator) {
    id17* current = iterator->current;
    if (current == NULL || current->prev == iterator->start) {
        iterator->current = NULL;
        return NULL;
    }
    iterator->current = current->prev;
    return current;
}

typedef struct {
    id17* current;
    id17* start;
} id13_circular_iterator;

id13_circular_iterator id13_circular_iterate(id17* start) {
    id13_circular_iterator iterator;
    iterator.current = start;
    iterator.start = start;
    return iterator;
}

id17* id13_circular_iterator_next(id13_circular_iterator* iterator) {
    id17* current = iterator->current;
    if (current == NULL) {
        return NULL;
    }
    iterator->current = current->next;
    if (iterator->current == iterator->start) {
        iterator->current = NULL;
    }
    return current;
}

typedef struct {
    id17* current;
    id17* start;
} id13_circular_reverse_iterator;

id13_circular_reverse_iterator id13_circular_reverse_iterate(id17* start) {
    id13_circular_reverse_iterator iterator;
    iterator.current = start;
    iterator.start = start;
    return iterator;
}

id17* id13_circular_reverse_iterator_next(id13_circular_reverse_iterator* iterator) {
    id17* current = iterator->current;
    if (current == NULL) {
        return NULL;
    }
    iterator->current = current->prev;
    if (iterator->current == iterator->start) {
        iterator->current = NULL;
    }
    return current;
}

typedef struct {
    id17* current;
    id17* start;
} id13_bidirectional_iterator;

id13_bidirectional_iterator id13_bidirectional_iterate(id17* start) {
    id13_bidirectional_iterator iterator;
    iterator.current = start;
    iterator.start = start;
    return iterator;
}

id17* id13_bidirectional_iterator_next(id13_bidirectional_iterator* iterator) {
    id17* current = iterator->current;
    if (current == NULL) {
        return NULL;
    }
    iterator->current = current->next;
    if (iterator->current == iterator->start) {
        iterator->current = NULL;
    }
    return current;
}

typedef struct {
    id17* current;
    id17* start;
} id13_bidirectional_reverse_iterator;

id13_bidirectional_reverse_iterator id13_bidirectional_reverse_iterate(id17* start) {
    id13_bidirectional_reverse_iterator iterator;
    iterator.current = start;
    iterator.start = start;
    return iterator;
}

id17* id13_bidirectional_reverse_iterator_next(id13_bidirectional_reverse_iterator* iterator) {
    id17* current = iterator->current;
    if (current == NULL) {
        return NULL;
    }
    iterator->current = current->prev;
    if (iterator->current == iterator->start) {
        iterator->current = NULL;
    }
    return current;
}

typedef struct {
    char* id8[8];
    int _n;
    id17* _root;
    id13** _index;
} id0;

id0* id0_new() {
    id0* self = malloc(sizeof(id0));
    self->id8[0] = "prev";
    self->id8[1] = "next";
    self->id8[2] = "key";
    self->id8[3] = "value";
    self->id8[4] = "parent";
    self->id8[5] = "child";
    self->id8[6] = "degree";
    self->id8[7] = "mark";
    self->_n = 0;
    self->_root = NULL;
    self->_index = NULL;
    return self;
}

void id0_push(id0* self, int key, int value) {
    id13* node = id13_new(key, value);
    self->_index[value] = node;

    if (self->_root == NULL) {
        id17_connect(node, node);
        self->_root = node;
        self->_n = 1;
    } else {
        id17_splice1(self->_root, node);
        if (key < self->_root->key) {
            self->_root = node;
        }
        self->_n += 1;
    }
}

void id0_pop(id0* self) {
    id13* z = self->_root;

    if (z->child) {
        id13* c = z->child;
        while (c) {
            c->parent = NULL;
            c = c->next;
        }
        id17_splice(z, z->child);
    }

    if (z->next == z) {
        self->_root = NULL;
    } else {
        self->_root = z->next;
        id17_eject(z);
        id0_id31(self);
    }

    self->_n -= 1;
    free(self->_index[z->value]);
    self->_index[z->value] = NULL;
}

void id0_id31(id0* self) {
    id13** A = malloc(self->_n * sizeof(id13*));
    for (int i = 0; i < self->_n; i++) {
        A[i] = NULL;
    }

    id13* x = self->_root;
    while (x) {
        int d = x->degree;
        while (A[d]) {
            id13* y = A[d];
            if (x->key > y->key) {
                id13* temp = x;
                x = y;
                y = temp;
            }
            id0__link(self, y, x);
            A[d] = NULL;
            d += 1;
        }
        A[d] = x;
        x = x->next;
    }

    self->_root = NULL;
    for (int i = 0; i < self->_n; i++) {
        if (A[i]) {
            if (self->_root) {
                id17_splice1(self->_root, A[i]);
                if (A[i]->key < self->_root->key) {
                    self->_root = A[i];
                }
            } else {
                self->_root = A[i];
            }
        }
    }

    free(A);
}

void id0__link(id0* self, id13* y, id13* x) {
    id17_eject(y);
    y->parent = x;
    if (x->child) {
        id17_splice1(x->child, y);
    } else {
        x->child = y;
        id17_connect(y, y);
    }
    x->degree += 1;
    y->mark = false;
}

void id0_id28(id0* self, int value, int key) {
    id13* x = self->_index[value];

    x->key = key;
    free(self->_index[value]);
    self->_index[value] = x;

    id13* y = x->parent;
    if (y && x->key < y->key) {
        id0__cut(self, x, y);
        id0_id2(self, y);
    }

    if (x->key < self->_root->key) {
        self->_root = x;
    }
}

void id0__cut(id0* self, id13* x, id13* y) {
    if (x->next == x) {
        y->child = NULL;
    } else {
        y->child = x->next;
    }
    x->parent = NULL;
    id17_eject(x);
    y->degree -= 1;

    id17_splice1(self->_root, x);
    x->mark = false;
}

void id0_id2(id0* self, id13* y) {
    id13* z = y->parent;
    if (z) {
        if (!y->mark) {
            y->mark = true;
        } else {
            id0__cut(self, y, z);
            id0_id2(self, z);
        }
    }
}

typedef struct {
    id17* current;
    id17* start;
} id0_iterator;

id0_iterator id0_iterate(id17* start) {
    id0_iterator iterator;
    iterator.current = start;
    iterator.start = start;
    return iterator;
}

id17* id0_iterator_next(id0_iterator* iterator) {
    id17* current = iterator->current;
    if (current == NULL || current->next == iterator->start) {
        iterator->current = NULL;
        return NULL;
    }
    iterator->current = current->next;
    return current;
}

typedef struct {
    char* id8[6];
    int key;
    int value;
    struct id3* parent;
    struct id3* left;
    struct id3* right;
} id3;

id3* id3_new(int key, int value) {
    id3* self = malloc(sizeof(id3));
    self->id8[0] = "key";
    self->id8[1] = "value";
    self->id8[2] = "parent";
    self->id8[3] = "left";
    self->id8[4] = "right";
    self->key = key;
    self->value = value;
    self->parent = NULL;
    self->left = NULL;
    self->right = NULL;
    return self;
}

typedef struct {
    id17* head;
    id17* tail;
} id3_iter;

id3_iter id3_iter_new(id17* start) {
    id3_iter iter;
    iter.head = start;
    iter.tail = start;
    return iter;
}

id17* id3_iter_next(id3_iter* iter) {
    id17* current = iter->head;
    if (current == NULL) {
        return NULL;
    }
    iter->head = current->next;
    if (iter->head == iter->tail) {
        iter->head = NULL;
    }
    return current;
}

typedef struct {
    id17* current;
    id17* start;
} id3_iterator;

id3_iterator id3_iterate(id17* start) {
    id3_iterator iterator;
    iterator.current = start;
    iterator.start = start;
    return iterator;
}

id17* id3_iterator_next(id3_iterator* iterator) {
    id17* current = iterator->current;
    if (current == NULL || current->next == iterator->start) {
        iterator->current = NULL;
        return NULL;
    }
    iterator->current = current->next;
    return current;
}

typedef struct {
    id17* current;
    id17* start;
} id3_reverse_iterator;

id3_reverse_iterator id3_reverse_iterate(id17* start) {
    id3_reverse_iterator iterator;
    iterator.current = start;
    iterator.start = start;
    return iterator;
}

id17* id3_reverse_iterator_next(id3_reverse_iterator* iterator) {
    id17* current = iterator->current;
    if (current == NULL || current->prev == iterator->start) {
        iterator->current = NULL;
        return NULL;
    }
    iterator->current = current->prev;
    return current;
}

typedef struct {
    id17* current;
    id17* start;
} id3_circular_iterator;

id3_circular_iterator id3_circular_iterate(id17* start) {
    id3_circular_iterator iterator;
    iterator.current = start;
    iterator.start = start;
    return iterator;
}

id17* id3_circular_iterator_next(id3_circular_iterator* iterator) {
    id17* current = iterator->current;
    if (current == NULL) {
        return NULL;
    }
    iterator->current = current->next;
    if (iterator->current == iterator->start) {
        iterator->current = NULL;
    }
    return current;
}

typedef struct {
    id17* current;
    id17* start;
} id3_circular_reverse_iterator;

id3_circular_reverse_iterator id3_circular_reverse_iterate(id17* start) {
    id3_circular_reverse_iterator iterator;
    iterator.current = start;
    iterator.start = start;
    return iterator;
}

id17* id3_circular_reverse_iterator_next(id3_circular_reverse_iterator* iterator) {
    id17* current = iterator->current;
    if (current == NULL) {
        return NULL;
    }
    iterator->current = current->prev;
    if (iterator->current == iterator->start) {
        iterator->current = NULL;
    }
    return current;
}

typedef struct {
    id17* current;
    id17* start;
} id3_bidirectional_iterator;

id3_bidirectional_iterator id3_bidirectional_iterate(id17* start) {
    id3_bidirectional_iterator iterator;
    iterator.current = start;
    iterator.start = start;
    return iterator;
}

id17* id3_bidirectional_iterator_next(id3_bidirectional_iterator* iterator) {
    id17* current = iterator->current;
    if (current == NULL) {
        return NULL;
    }
    iterator->current = current->next;
    if (iterator->current == iterator->start) {
        iterator->current = NULL;
    }
    return current;
}

typedef struct {
    id17* current;
    id17* start;
} id3_bidirectional_reverse_iterator;

id3_bidirectional_reverse_iterator id3_bidirectional_reverse_iterate(id17* start) {
    id3_bidirectional_reverse_iterator iterator;
    iterator.current = start;
    iterator.start = start;
    return iterator;
}

id17* id3_bidirectional_reverse_iterator_next(id3_bidirectional_reverse_iterator* iterator) {
    id17* current = iterator->current;
    if (current == NULL) {
        return NULL;
    }
    iterator->current = current->prev;
    if (iterator->current == iterator->start) {
        iterator->current = NULL;
    }
    return current;
}

typedef struct {
    char* id8[8];
    int _n;
    id17* _root;
    id3** _index;
} id16;

id16* id16_new() {
    id16* self = malloc(sizeof(id16));
    self->id8[0] = "prev";
    self->id8[1] = "next";
    self->id8[2] = "key";
    self->id8[3] = "value";
    self->id8[4] = "parent";
    self->id8[5] = "left";
    self->id8[6] = "right";
    self->_n = 0;
    self->_root = NULL;
    self->_index = NULL;
    return self;
}

void id16_push(id16* self, int key, int value) {
    id3* node = id3_new(key, value);
    self->_index[value] = node;

    if (self->_root == NULL) {
        self->_root = node;
    } else {
        self->_root = id3_link(self->_root, node);
    }
}

void id16_id28(id16* self, int value, int key) {
    id3* x = self->_index[value];

    x->key = key;
    free(self->_index[value]);
    self->_index[value] = x;

    id3* y = x->parent;
    if (y && x->key < y->key) {
        self->_root = id3_cut(self->_root, x, y);
        id16_id2(self, y);
    }
}

id3* id3_link(id3* self, id3* other) {
    if (other->key < self->key) {
        id3* temp = self;
        self = other;
        other = temp;
    }
    if (self->left == NULL) {
        self->left = other;
        other->parent = self;
    } else {
        id3* r = self->left;
        while (r->right) {
            r = r->right;
        }
        r->right = other;
        other->parent = r;
    }
    return self;
}

id3* id3_cut(id3* self, id3* x, id3* y) {
    if (x->next == x) {
        y->left = NULL;
    } else {
        y->left = x->next;
    }
    x->parent = NULL;
    id17_eject(x);
    y->key -= 1;

    self = id3_link(self, x);
    x->mark = false;
    return self;
}

void id16_id2(id16* self, id3* y) {
    id3* z = y->parent;
    if (z) {
        if (!y->mark) {
            y->mark = true;
        } else {
            self->_root = id3_cut(self->_root, y, z);
            id16_id2(self, z);
        }
    }
}

typedef struct {
    id17* current;
    id17* start;
} id16_iterator;

id16_iterator id16_iterate(id17* start) {
    id16_iterator iterator;
    iterator.current = start;
    iterator.start = start;
    return iterator;
}

id17* id16_iterator_next(id16_iterator* iterator) {
    id17* current = iterator->current;
    if (current == NULL || current->next == iterator->start) {
        iterator->current = NULL;
        return NULL;
    }
    iterator->current = current->next;
    return current;
}

typedef struct {
    char* id8[6];
    int key;
    int value;
    struct id3* parent;
    struct id3* left;
    struct id3* right;
} id5_node;

typedef struct {
    id5_node** _tree;
    int _size;
    int _capacity;
    int _inf_key;
    int _index;
} id5;

id5* id5_new() {
    id5* self = malloc(sizeof(id5));
    self->_tree = NULL;
    self->_size = 0;
    self->_capacity = 0;
    self->_inf_key = 1;
    self->_index = 0;
    return self;
}

void id5_push(id5* self, int key, int value) {
    if (self->_size >= self->_capacity) {
        self->_capacity = (self->_capacity == 0) ? 1 : self->_capacity * 2;
        self->_tree = realloc(self->_tree, self->_capacity * sizeof(id5_node*));
    }

    self->_tree[self->_size] = malloc(sizeof(id5_node));
    self->_tree[self->_size]->key = self->_inf_key;
    self->_tree[self->_size]->value = value;
    self->_size += 1;

    int i = self->_size - 1;
    while (i > 0) {
        int p = (i + 1) / 2 - 1;
        if (!(key < self->_tree[p]->key)) {
            break;
        }
        self->_tree[i] = self->_tree[p];
        i = p;
    }

    self->_tree[i]->key = key;
}

void id5_pop(id5* self) {
    if (self->_size == 0) {
        return;
    }

    self->_size -= 1;
    free(self->_tree[self->_size]);
    self->_tree[self->_size] = NULL;

    int i = 0;
    while (true) {
        int l = (i + 1) * 2 - 1;
        int r = (i + 1) * 2 + 1 - 1;
        if (l >= self->_size) {
            break;
        }

        int z = i;
        if (self->_tree[l]->key < self->_tree[z]->key) {
            z = l;
        }
        if (r < self->_size && self->_tree[r]->key < self->_tree[z]->key) {
            z = r;
        }

        if (z != i) {
            id5_node* temp = self->_tree[i];
            self->_tree[i] = self->_tree[z];
            self->_tree[z] = temp;
            i = z;
        } else {
            break;
        }
    }
}

typedef struct {
    id17* current;
    id17* start;
} id5_iterator;

id5_iterator id5_iterate(id17* start) {
    id5_iterator iterator;
    iterator.current = start;
    iterator.start = start;
    return iterator;
}

id17* id5_iterator_next(id5_iterator* iterator) {
    id17* current = iterator->current;
    if (current == NULL || current->next == iterator->start) {
        iterator->current = NULL;
        return NULL;
    }
    iterator->current = current->next;
    return current;
}

typedef struct {
    char* id8[8];
    int _n;
    id17* _root;
    id5** _tree;
    int* _index;
} id7;

id7* id7_new() {
    id7* self = malloc(sizeof(id7));
    self->id8[0] = "prev";
    self->id8[1] = "next";
    self->id8[2] = "key";
    self->id8[3] = "value";
    self->id8[4] = "parent";
    self->id8[5] = "left";
    self->id8[6] = "right";
    self->id8[7] = "color";
    self->_n = 0;
    self->_root = NULL;
    self->_tree = NULL;
    self->_index = NULL;
    return self;
}

void id7_push(id7* self, int key, int value) {
    if (self->_tree == NULL) {
        self->_tree = malloc(sizeof(id5*));
        self->_tree[0] = id5_new();
        self->_index = malloc(sizeof(int));
        self->_index[0] = 0;
        self->_n = 1;
    }

    int i = self->_n - 1;
    while (i > 0) {
        int p = (i + 1) / 2 - 1;
        if (!(key < self->_tree[p]->_tree[0]->key)) {
            break;
        }
        self->_tree[i] = self->_tree[p];
        self->_index[self->_tree[i]->_tree[0]->value] = i;
        i = p;
    }

    if (self->_tree[i] == NULL) {
        self->_tree[i] = id5_new();
    }
    id5_push(self->_tree[i], key, value);
    self->_index[value] = i;

    if (i == 0 && self->_tree[i]->_tree[0]->key < self->_root->_tree[0]->key) {
        self->_root = self->_tree[i];
    }
}

void id7_pop(id7* self) {
    if (self->_n == 0) {
        return;
    }

    int i = self->_index[self->_root->_tree[0]->_tree[0]->value];
    id5_pop(self->_tree[i]);
    if (self->_tree[i]->_size == 0) {
        free(self->_tree[i]);
        self->_tree[i] = NULL;
    }

    int j = i;
    while (true) {
        int l = (j + 1) * 2 - 1;
        int r = (j + 1) * 2 + 1 - 1;
        if (l >= self->_n) {
            break;
        }

        int z = j;
        if (self->_tree[l] != NULL && self->_tree[l]->_tree[0]->key < self->_tree[z]->_tree[0]->key) {
            z = l;
        }
        if (r < self->_n && self->_tree[r] != NULL && self->_tree[r]->_tree[0]->key < self->_tree[z]->_tree[0]->key) {
            z = r;
        }

        if (z != j) {
            id5* temp = self->_tree[j];
            self->_tree[j] = self->_tree[z];
            self->_tree[z] = temp;
            self->_index[self->_tree[j]->_tree[0]->_tree[0]->value] = j;
            self->_index[self->_tree[z]->_tree[0]->_tree[0]->value] = z;
            j = z;
        } else {
            break;
        }
    }

    self->_root = self->_tree[0];
}

typedef struct {
    id17* current;
    id17* start;
} id7_iterator;

id7_iterator id7_iterate(id17* start) {
    id7_iterator iterator;
    iterator.current = start;
    iterator.start = start;
    return iterator;
}

id17* id7_iterator_next(id7_iterator* iterator) {
    id17* current = iterator->current;
    if (current == NULL || current->next == iterator->start) {
        iterator->current = NULL;
        return NULL;
    }
    iterator->current = current->next;
    return current;
}

typedef struct {
    char* id8[6];
    int key;
    int value;
    struct id3* parent;
    struct id3* left;
    struct id3* right;
} id3_node;

typedef struct {
    id3_node** _tree;
    int _size;
    int _capacity;
    int _inf_key;
    int _index;
} id3;

id3* id3_new() {
    id3* self = malloc(sizeof(id3));
    self->_tree = NULL;
    self->_size = 0;
    self->_capacity = 0;
    self->_inf_key = 1;
    self->_index = 0;
    return self;
}

void id3_push(id3* self, int key, int value) {
    if (self->_size >= self->_capacity) {
        self->_capacity = (self->_capacity == 0) ? 1 : self->_capacity * 2;
        self->_tree = realloc(self->_tree, self->_capacity * sizeof(id3_node*));
    }

    self->_tree[self->_size] = malloc(sizeof(id3_node));
    self->_tree[self->_size]->key = self->_inf_key;
    self->_tree[self->_size]->value = value;
    self->_size += 1;

    int i = self->_size - 1;
    while (i > 0) {
        int p = (i + 1) / 2 - 1;
        if (!(key < self->_tree[p]->key)) {
            break;
        }
        self->_tree[i] = self->_tree[p];
        i = p;
    }

    self->_tree[i]->key = key;
}

void id3_pop(id3* self) {
    if (self->_size == 0) {
        return;
    }

    self->_size -= 1;
    free(self->_tree[self->_size]);
    self->_tree[self->_size] = NULL;

    int i = 0;
    while (true) {
        int l = (i + 1) * 2 - 1;
        int r = (i + 1) * 2 + 1 - 1;
        if (l >= self->_size) {
            break;
        }

        int z = i;
        if (self->_tree[l]->key < self->_tree[z]->key) {
            z = l;
        }
        if (r < self->_size && self->_tree[r]->key < self->_tree[z]->key) {
            z = r;
        }

        if (z != i) {
            id3_node* temp = self->_tree[i];
            self->_tree[i] = self->_tree[z];
            self->_tree[z] = temp;
            i = z;
        } else {
            break;
        }
    }
}

typedef struct {
    id17* current;
    id17* start;
} id3_iterator;

id3_iterator id3_iterate(id17* start) {
    id3_iterator iterator;
    iterator.current = start;
    iterator.start = start;
    return iterator;
}

id17* id3_iterator_next(id3_iterator* iterator) {
    id17* current = iterator->current;
    if (current == NULL || current->next == iterator->start) {
        iterator->current = NULL;
        return NULL;
    }
    iterator->current = current->next;
    return current;
}

typedef struct {
    char* id8[6];
    int key;
    int value;
    struct id3* parent;
    struct id3* left;
    struct id3* right;
} id3_node;

typedef struct {
    id3_node** _tree;
    int _size;
    int _capacity;
    int _inf_key;
    int _index;
} id3;

id3* id3_new() {
    id3* self = malloc(sizeof(id3));
    self->_tree = NULL;
    self->_size = 0;
    self->_capacity = 0;
    self->_inf_key = 1;
    self->_index = 0;
    return self;
}

void id3_push(id3* self, int key, int value) {
    if (self->_size >= self->_capacity) {
        self->_capacity = (self->_capacity == 0) ? 1 : self->_capacity * 2;
        self->_tree = realloc(self->_tree, self->_capacity * sizeof(id3_node*));
    }

    self->_tree[self->_size] = malloc(sizeof(id3_node));
    self->_tree[self->_size]->key = self->_inf_key;
    self->_tree[self->_size]->value = value;
    self->_size += 1;

    int i = self->_size - 1;
    while (i > 0) {
        int p = (i + 1) / 2 - 1;
        if (!(key < self->_tree[p]->key)) {
            break;
        }
        self->_tree[i] = self->_tree[p];
        i = p;
    }

    self->_tree[i]->key = key;
}

void id3_pop(id3* self) {
    if (self->_size == 0) {
        return;
    }

    self->_size -= 1;
    free(self->_tree[self->_size]);
    self->_tree[self->_size] = NULL;

    int i = 0;
    while (true) {
        int l = (i + 1) * 2 - 1;
        int r = (i + 1) * 2 + 1 - 1;
        if (l >= self->_size) {
            break;
        }

        int z = i;
        if (self->_tree[l]->key < self->_tree[z]->key) {
            z = l;
        }
        if (r < self->_size && self->_tree[r]->key < self->_tree[z]->key) {
            z = r;
        }

        if (z != i) {
            id3_node* temp = self->_tree[i];
            self->_tree[i] = self->_tree[z];
            self->_tree[z] = temp;
            i = z;
        } else {
            break;
        }
    }
}

typedef struct {
    int maxV;
    bool isflow;
    bool sparse;
    id17** _V;
    int* _V_index;
    int** _E;
    id17** _adj;
    int** _levels;
} Graph;

Graph* Graph_new(int maxV, bool isflow, bool sparse) {
    Graph* self = malloc(sizeof(Graph));
    self->maxV = maxV;
    self->isflow = isflow;
    self->sparse = sparse;
    self->_V = malloc(maxV * sizeof(id17*));
    self->_V_index = malloc(maxV * sizeof(int));
    self->_E = malloc(maxV * sizeof(int*));
    self->_adj = malloc(maxV * sizeof(id17*));
    self->_levels = malloc(maxV * sizeof(int*));
    return self;
}

void Graph_add_vertex(Graph* self, int label) {
    self->_V_index[label] = self->nV;
    self->_V[self->nV] = id17_new();
    self->nV += 1;
}

void Graph_add_edge(Graph* self, int u_label, int v_label, int w) {
    int u = self->_V_index[u_label];
    int v = self->_V_index[v_label];
    if (self->isflow) {
        self->_E[u][v] += w;
        self->_adj[u] = id17_link(self->_adj[u], self->_V[v]);
        self->_adj[v] = id17_link(self->_adj[v], self->_V[u]);
    } else {
        self->_E[u][v] = w;
        self->_adj[u] = id17_link(self->_adj[u], self->_V[v]);
    }
}

void Graph_trim(Graph* self, int u_label) {
    int u = self->_V_index[u_label];
    self->_adj[u] = NULL;
    if (self->sparse) {
        free(self->_E[u]);
        self->_E[u] = NULL;
    } else {
        for (int v = 0; v < self->maxV; v++) {
            self->_E[u][v] = self->isflow ? INT_MAX : INFINITY;
        }
    }
}

int Graph_id20(Graph* self, int s, int t) {
    self->_levels[s] = malloc(self->maxV * sizeof(int));
    for (int i = 0; i < self->maxV; i++) {
        self->_levels[s][i] = INFINITY;
    }
    self->_levels[s][s] = 0;

    id17* queue = id17_new();
    id17_push(queue, s);
    while (queue->_root != NULL) {
        int u = queue->_root->value;
        id17_pop(queue);
        for (id17* v = self->_adj[u]->_root; v != NULL; v = v->next) {
            if (self->_E[u][v->value] > 0 && self->_levels[s][v->value] == INFINITY) {
                self->_levels[s][v->value] = self->_levels[s][u] + 1;
                id17_push(queue, v->value);
            }
        }
    }

    return self->_levels[s][t];
}

int Graph_id30(Graph* self, int s, int t) {
    int flow = 0;

    while (Graph_id20(self, s, t) != INFINITY) {
        flow += Graph_id31(self, s, t);
    }

    return flow;
}

int Graph_id31(Graph* self, int s, int t) {
    int* A = malloc(self->maxV * sizeof(int));
    for (int i = 0; i < self->maxV; i++) {
        A[i] = NULL;
    }

    id3* x = self->_root;
    while (x) {
        int d = x->degree;
        while (A[d]) {
            id3* y = A[d];
            if (x->key > y->key) {
                id3* temp = x;
                x = y;
                y = temp;
            }
            Graph__link(self, y, x);
            A[d] = NULL;
            d += 1;
        }
        A[d] = x;
        x = x->next;
    }

    self->_root = NULL;
    for (int i = 0; i < self->maxV; i++) {
        if (A[i]) {
            if (self->_root) {
                Graph__splice1(self->_root, A[i]);
                if (A[i]->key < self->_root->key) {
                    self->_root = A[i];
                }
            } else {
                self->_root = A[i];
            }
        }
    }

    free(A);
}

void Graph__link(Graph* self, id3* y, id3* x) {
    id17_eject(y);
    y->parent = x;
    if (x->left) {
        id17_splice1(x->left, y);
    } else {
        x->left = y;
        id17_connect(y, y);
    }
    x->degree += 1;
    y->mark = false;
}

int Graph_id28(Graph* self, int value, int key) {
    id3* x = self->_index[value];

    x->key = key;
    free(self->_index[value]);
    self->_index[value] = x;

    id3* y = x->parent;
    if (y && x->key < y->key) {
        self->_root = Graph__cut(self->_root, x, y);
        Graph_id2(self, y);
    }

    if (x->key < self->_root->key) {
        self->_root = x;
    }
}

id3* Graph__cut(id3* self, id3* x, id3* y) {
    if (x->next == x) {
        y->left = NULL;
    } else {
        y->left = x->next;
    }
    x->parent = NULL;
    id17_eject(x);
    y->degree -= 1;

    Graph__splice1(self, x);
    x->mark = false;
    return self;
}

void Graph__splice1(id3* self, id3* node) {
    id17_connect(node, self->left);
    id17_connect(self, node);
}

void Graph_id2(Graph* self, id3* y) {
    id3* z = y->parent;
    if (z) {
        if (!y->mark) {
            y->mark = true;
        } else {
            self->_root = Graph__cut(self->_root, y, z);
            Graph_id2(self, z);
        }
    }
}

typedef struct {
    int maxV;
    bool isflow;
    bool sparse;
    id17** _V;
    int* _V_index;
    int** _E;
    id17** _adj;
    int** _levels;
} Graph;

Graph* Graph_new(int maxV, bool isflow, bool sparse) {
    Graph* self = malloc(sizeof(Graph));
    self->maxV = maxV;
    self->isflow = isflow;
    self->sparse = sparse;
    self->_V = malloc(maxV * sizeof(id17*));
    self->_V_index = malloc(maxV * sizeof(int));
    self->_E = malloc(maxV * sizeof(int*));
    self->_adj = malloc(maxV * sizeof(id17*));
    self->_levels = malloc(maxV * sizeof(int*));
    return self;
}

void Graph_add_vertex(Graph* self, int label) {
    self->_V_index[label] = self->nV;
    self->_V[self->nV] = id17_new();
    self->nV += 1;
}

void Graph_add_edge(Graph* self, int u_label, int v_label, int w) {
    int u = self->_V_index[u_label];
    int v = self->_V_index[v_label];
    if (self->isflow) {
        self->_E[u][v] += w;
        id17_connect(self->_V[u], self->_V[v]);
        id17_connect(self->_V[v], self->_V[u]);
    } else {
        self->_E[u][v] = w;
        id17_connect(self->_V[u], self->_V[v]);
    }
}

void Graph_trim(Graph* self, int u_label) {
    int u = self->_V_index[u_label];
    self->_adj[u] = NULL;
    if (self->sparse) {
        free(self->_E[u]);
        self->_E[u] = NULL;
    } else {
        for (int v = 0; v < self->maxV; v++) {
            self->_E[u][v] = self->isflow ? INT_MAX : INFINITY;
        }
    }
}

int Graph_id20(Graph* self, int s, int t) {
    self->_levels[s] = malloc(self->maxV * sizeof(int));
    for (int i = 0; i < self->maxV; i++) {
        self->_levels[s][i] = INFINITY;
    }
    self->_levels[s][s] = 0;

    id17* queue = id17_new();
    id17_push(queue, s);
    while (queue->head != NULL) {
        int u = queue->head->value;
        id17_pop(queue);
        for (id17* v = self->_adj[u]->head; v != NULL; v = v->next) {
            if (self->_E[u][v->value] > 0 && self->_levels[s][v->value] == INFINITY) {
                self->_levels[s][v->value] = self->_levels[s][u] + 1;
                id17_push(queue, v->value);
            }
        }
    }

    return self->_levels[s][t];
}

int Graph_id30(Graph* self, int s, int t) {
    int flow = 0;

    while (Graph_id20(self, s, t) != INFINITY) {
        flow += Graph_id31(self, s, t);
    }

    return flow;
}

int Graph_id31(Graph* self, int s, int t) {
    int* A = malloc(self->maxV * sizeof(int));
    for (int i = 0; i < self->maxV; i++) {
        A[i] = NULL;
    }

    id3* x = self->_root;
    while (x) {
        int d = x->degree;
        while (A[d]) {
            id3* y = A[d];
            if (x->key > y->key) {
                id3* temp = x;
                x = y;
                y = temp;
            }
            Graph__link(self, y, x);
            A[d] = NULL;
            d += 1;
        }
        A[d] = x;
        x = x->next;
    }

    self->_root = NULL;
    for (int i = 0; i < self->maxV; i++) {
        if (A[i]) {
            if (self->_root) {
                Graph__splice1(self->_root, A[i]);
                if (A[i]->key < self->_root->key) {
                    self->_root = A[i];
                }
            } else {
                self->_root = A[i];
            }
        }
    }

    free(A);
}

void Graph__link(Graph* self, id3* y, id3* x) {
    id17_eject(y);
    y->parent = x;
    if (x->left) {
        id17_splice1(x->left, y);
    } else {
        x->left = y;
        id17_connect(y, y);
    }
    x->degree += 1;
    y->mark = false;
}

int Graph_id28(Graph* self, int value, int key) {
    id3* x = self->_index[value];

    x->key = key;
    free(self->_index[value]);
    self->_index[value] = x;

    id3* y = x->parent;
    if (y && x->key < y->key) {
        self->_root = Graph__cut(self->_root, x, y);
        Graph_id2(self, y);
    }

    if (x->key < self->_root->key) {
        self->_root = x;
    }
}

id3* Graph__cut(id3* self, id3* x, id3* y) {
    if (x->next == x) {
        y->left = NULL;
    } else {
        y->left = x->next;
    }
    x->parent = NULL;
    id17_eject(x);
    y->degree -= 1;

    Graph__splice1(self, x);
    x->mark = false;
    return self;
}

void Graph__splice1(id3* self, id3* node) {
    id17_connect(node, self->left);
    id17_connect(self, node);
}

void Graph_id2(Graph* self, id3* y) {
    id3* z = y->parent;
    if (z) {
        if (!y->mark) {

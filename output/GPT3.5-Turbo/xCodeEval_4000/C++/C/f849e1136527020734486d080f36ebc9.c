#include <stdio.h>
#include <stdlib.h>

struct list_head {
    struct list_head *prev, *next;
};

struct node_t {
    struct list_head lh;
    struct splay_head sh;
    int v;
    int pos;
};

struct splay_head {
    struct splay_head *lc, *rc, *p;
    int size;
};

struct list_iter
{
    struct node_t *cur;
};

struct bst_iterator {
    struct splay_head *cur;
};

struct splay_array {
    struct splay_head *root;
};

struct sized_splay {
    struct splay_head *root;
    int (*acc)(const int *);
    int (*comp)(const int *, const int *);
};

struct node_t arr[500005];
struct list_head lst;
struct splay_array splay;
int64_t ans = 0;

void list_head_reset(struct list_head *head) {
    head->prev = head;
    head->next = head;
}

void list_head_link(struct list_head *prev, struct list_head *next) {
    prev->next = next;
    next->prev = prev;
}

void list_head_insert_next(struct list_head *head, struct list_head *new_next) {
    list_head_link(new_next, head->next);
    list_head_link(head, new_next);
}

void list_head_insert_prev(struct list_head *head, struct list_head *new_prev) {
    list_head_link(new_prev, head);
    list_head_link(head->prev, new_prev);
}

void list_head_unlink(struct list_head *head) {
    list_head_link(head->prev, head->next);
    list_head_reset(head);
}

struct list_iter list_iter_make_range(struct list_head *list) {
    struct list_iter iter;
    iter.cur = list;
    return iter;
}

struct bst_iterator bst_iterator_make(struct splay_head *head) {
    struct bst_iterator iter;
    iter.cur = head;
    return iter;
}

struct bst_iterator bst_leftmost(struct splay_head *x) {
    while (x && x->lc)
        x = x->lc;
    struct bst_iterator iter = bst_iterator_make(x);
    return iter;
}

struct bst_iterator bst_rightmost(struct splay_head *x) {
    while (x && x->rc)
        x = x->rc;
    struct bst_iterator iter = bst_iterator_make(x);
    return iter;
}

struct bst_iterator bst_prev(struct splay_head *x) {
    if (x->lc) return bst_rightmost(x->lc);
    struct splay_head *p = x->p;
    while (p && x == p->lc) {
        x = p;
        p = p->p;
    }
    struct bst_iterator iter = bst_iterator_make(p);
    return iter;
}

struct bst_iterator bst_succ(struct splay_head *x) {
    if (x->rc) return bst_leftmost(x->rc);
    struct splay_head *p = x->p;
    while (p && x == p->rc) {
        x = p;
        p = p->p;
    }
    struct bst_iterator iter = bst_iterator_make(p);
    return iter;
}

void bst_rotate(struct splay_head *x) {
    struct splay_head *y = x->p, *z = y->p;
    struct splay_head *b = (x == y->lc) ? x->rc : x->lc;
    x->p = z, y->p = x;
    if (b) b->p = y;
    if (z) (z->lc == y ? z->lc : z->rc) = x;
    if (x == y->lc) x->rc = y, y->lc = b;
    else x->lc = y, y->rc = b;
}

void bst_lower_bound(struct splay_head *root, int *k, int (*acc)(const int *), int (*comp)(const int *, const int *), struct splay_head **result) {
    struct splay_head *x = NULL;
    while (root) {
        if (comp(acc(root), k)) {
            root = root->rc;
        } else {
            x = root;
            root = root->lc;
        }
    }
    *result = x;
}

void bst_upper_bound(struct splay_head *root, int *k, int (*acc)(const int *), int (*comp)(const int *, const int *), struct splay_head **result) {
    struct splay_head *x = NULL;
    while (root) {
        if (comp(k, acc(root))) {
            x = root;
            root = root->lc;
        } else {
            root = root->rc;
        }
    }
    *result = x;
}

void splay_rotate(struct splay_head *x) {
    struct splay_head *y = x->p, *z = y->p;
    struct splay_head *b = (x == y->lc) ? x->rc : x->lc;
    x->p = z, y->p = x;
    if (b) b->p = y;
    if (z) (z->lc == y ? z->lc : z->rc) = x;
    if (x == y->lc) x->rc = y, y->lc = b;
    else x->lc = y, y->rc = b;
}

void splay_splay(struct splay_head **root, struct splay_head *x, struct splay_head *target) {
    while (x->p != target) {
        if (x->p->p != target) {
            if ((x->p->lc == x) == (x->p->p->lc == x->p))
                splay_rotate(x->p);
            else
                splay_rotate(x);
        }
        splay_rotate(x);
    }
    x->update_size();
    if (!target)
        *root = x;
}

void splay_insert_before(struct splay_head **root, struct splay_head *x, struct splay_head *y) {
    if (!y) {
        x->lc = *root;
        if (*root) (*root)->p = x;
        *root = x;
        x->update_size();
    } else {
        splay_splay(root, y, NULL);
        if (!y->lc)
            y->lc = x, x->p = y, y->update_size();
        else {
            struct splay_head *prev = bst_rightmost(y->lc);
            splay_splay(root, prev, y);
            prev->rc = x;
            x->p = prev;
            prev->update_size();
            y->update_size();
        }
    }
}

void splay_erase(struct splay_head **root, struct splay_head *x) {
    splay_splay(root, x, NULL);
    if (!x->lc) {
        if (x->rc) x->rc->p = NULL;
        *root = x->rc;
    } else {
        struct splay_head *prev = bst_rightmost(x->lc);
        splay_splay(root, prev, x);
        prev->rc = x->rc;
        if (x->rc) x->rc->p = prev;
        prev->update_size();
        prev->p = NULL, *root = prev;
    }
    x->reset();
}

int splay_get_rank(struct splay_head **root, struct splay_head *x) {
    if (!x) return *root ? (*root)->size : 0;

    splay_splay(root, x, NULL);
    return x->lc ? x->lc->size : 0;
}

struct splay_head *splay_find_nth_inner(struct splay_head **root, int k) {
    struct splay_head *p = *root;
    while (1) {
        int lsize = p->lc ? p->lc->size : 0;
        if (k < lsize)
            p = p->lc;
        else if (k == lsize)
            return p;
        else
            k -= lsize + 1, p = p->rc;
    }
    return p;
}

struct splay_head *splay_find_nth(struct splay_head **root, int k) {
    struct splay_head *p = splay_find_nth_inner(root, k);
    splay_splay(root, p, NULL);
    return p;
}

struct splay_head *splay_lower_bound(struct splay_head **root, int *k, int (*acc)(const int *), int (*comp)(const int *, const int *)) {
    struct splay_head *x = NULL;
    bst_lower_bound(*root, k, acc, comp, &x);
    if (x) splay_splay(root, x, NULL);
    if (x && !comp(k, acc(x)))
        return x;
    return NULL;
}

struct splay_head *splay_upper_bound(struct splay_head **root, int *k, int (*acc)(const int *), int (*comp)(const int *, const int *)) {
    struct splay_head *x = NULL;
    bst_upper_bound(*root, k, acc, comp, &x);
    if (x) splay_splay(root, x, NULL);
    return x;
}

void splay_insert(struct splay_head **root, struct node_t *node, int *k, int (*acc)(const int *), int (*comp)(const int *, const int *)) {
    struct splay_head *x = node;
    struct splay_head *y = splay_lower_bound(root, k, acc, comp);
    splay_insert_before(root, x, y);
}

void splay_array_init(struct splay_array *array) {
    array->root = NULL;
}

int splay_array_size(struct splay_array *array) {
    return array->root ? array->root->size : 0;
}

struct bst_iterator splay_array_begin(struct splay_array *array) {
    return bst_leftmost(array->root);
}

struct bst_iterator splay_array_end() {
    struct bst_iterator iter;
    iter.cur = NULL;
    return iter;
}

struct bst_iterator splay_array_find_nth(struct splay_array *array, int k) {
    return bst_iterator_make(splay_find_nth(&array->root, k));
}

int splay_array_get_rank(struct splay_array *array, struct bst_iterator it) {
    return splay_get_rank(&array->root, it.cur);
}

struct bst_iterator splay_array_insert_front(struct splay_array *array, struct node_t *node) {
    struct splay_head *x = node;
    x->rc = array->root;
    if (array->root) array->root->p = x;
    array->root = x;
    x->update_size();
    return bst_iterator_make(x);
}

struct bst_iterator splay_array_insert_back(struct splay_array *array, struct node_t *node) {
    struct splay_head *x = node;
    x->lc = array->root;
    if (array->root) array->root->p = x;
    array->root = x;
    x->update_size();
    return bst_iterator_make(x);
}

struct bst_iterator splay_array_insert_nth(struct splay_array *array, struct node_t *node, int k) {
    if (k == 0) return splay_array_insert_front(array, node);
    else if (k < splay_array_size(array)) {
        struct splay_head *x = node;
        struct splay_head *y = splay_find_nth_inner(&array->root, k);
        splay_insert_before(&array->root, x, y);
        return bst_iterator_make(x);
    } else if (k == splay_array_size(array)) return splay_array_insert_back(array, node);
    else return bst_iterator_make(NULL);
}

struct bst_iterator splay_array_erase(struct splay_array *array, struct bst_iterator it) {
    struct bst_iterator next = it;
    next.cur = bst_succ(it.cur);
    splay_erase(&array->root, it.cur);
    return next;
}

int acc(const int *x) {
    return *x;
}

int comp(const int *x, const int *y) {
    return *x < *y;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        arr[i].v = v;
        arr[i].pos = i;
    }
    for (int i = 0; i < n; i++) {
        splay_array_insert_back(&splay, &arr[i]);
        list_head_insert_prev(&lst, &arr[i].lh);
    }
    int last_left = 0;
    int last_right = 0;
    while (splay_array_size(&splay)) {
        struct bst_iterator it = splay_array_begin(&splay);
        struct list_iter lit;
        lit.cur = it.cur->lh;
        struct list_iter root;
        root.cur = lst;
        int left = root.cur->next->pos;
        int right = root.cur->prev->pos;
        splay_array_erase(&splay, it);
        if (it.cur->pos == left && it.cur->pos == right) {
            ans += (last_left < last_right) ? last_left : last_right;
        } else if (it.cur->pos == left) {
            ans += last_left;
            last_left = it.cur->v;
        } else if (it.cur->pos == right) {
            ans += last_right;
            last_right = it.cur->v;
        } else {
            ans += (lit.cur->next->v < lit.cur->prev->v) ? lit.cur->next->v : lit.cur->prev->v;
        }
        list_head_unlink(&it.cur->lh);
    }
    printf("%lld\n", ans);
    return 0;
}

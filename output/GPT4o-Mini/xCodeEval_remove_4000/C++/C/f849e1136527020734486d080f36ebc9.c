#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define MAXN 500005

typedef struct list_head {
    struct list_head *prev, *next;
} list_head;

typedef struct id14 {
    struct id14 *lc, *rc, *p;
    int size;
} id14;

typedef struct node_t {
    list_head lh;
    id14 sh;
    int v;
    int pos;
} node_t;

typedef struct splay_t {
    id14 *root;
} splay_t;

list_head lst;
node_t arr[MAXN];
splay_t splay;
int64_t ans = 0;

void reset_list_head(list_head *lh) {
    lh->prev = lh;
    lh->next = lh;
}

void insert_prev(list_head *lh, list_head *new_next) {
    new_next->next = lh->next;
    new_next->prev = lh;
    lh->next->prev = new_next;
    lh->next = new_next;
}

void unlink(list_head *lh) {
    lh->prev->next = lh->next;
    lh->next->prev = lh->prev;
    reset_list_head(lh);
}

void update_size(id14 *x) {
    x->size = 1;
    if (x->lc) x->size += x->lc->size;
    if (x->rc) x->size += x->rc->size;
}

void bst_rotate(id14 *x) {
    id14 *y = x->p, *z = y->p;
    id14 *b = (x == y->lc) ? x->rc : x->lc;
    x->p = z;
    y->p = x;
    if (b) b->p = y;
    if (z) (z->lc == y ? z->lc : z->rc) = x;
    if (x == y->lc) {
        x->rc = y;
        y->lc = b;
    } else {
        x->lc = y;
        y->rc = b;
    }
}

void insert(splay_t *splay, node_t *node) {
    id14 *x = &node->sh;
    x->rc = splay->root;
    if (splay->root) splay->root->p = x;
    splay->root = x;
    update_size(x);
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
        insert(&splay, &arr[i]);
        insert_prev(&lst, &arr[i].lh);
    }

    int last_left = 0;
    int last_right = 0;

    while (splay.root) {
        node_t *it = (node_t *)splay.root; // Assuming root points to the first element
        list_head *root = &lst;
        int left = root->next->pos;
        int right = root->prev->pos;
        unlink(&it->lh);
        
        if (it->pos == left && it->pos == right) {
            ans += (last_left < last_right) ? last_left : last_right;
        } else if (it->pos == left) {
            ans += last_left;
            last_left = it->v;
        } else if (it->pos == right) {
            ans += last_right;
            last_right = it->v;
        } else {
            ans += (next(it)->v < prev(it)->v) ? next(it)->v : prev(it)->v;
        }
    }
    
    printf("%lld\n", ans);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

#define MAXN 500005

typedef struct list_head {
    struct list_head *prev, *next;
} list_head;

typedef struct splay_head {
    struct splay_head *lc, *rc, *p;
    int size;
} splay_head;

typedef struct node_t {
    list_head lh;
    splay_head sh;
    int v;
    int pos;
} node_t;

list_head lst;
node_t arr[MAXN];
int64_t ans = 0;

void list_init(list_head *list) {
    list->prev = list;
    list->next = list;
}

void list_insert_prev(list_head *new_prev, list_head *list) {
    new_prev->next = list;
    new_prev->prev = list->prev;
    list->prev->next = new_prev;
    list->prev = new_prev;
}

void list_unlink(list_head *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void splay_update_size(splay_head *x) {
    x->size = 1;
    if (x->lc) x->size += x->lc->size;
    if (x->rc) x->size += x->rc->size;
}

void splay_rotate(splay_head *x) {
    splay_head *y = x->p;
    splay_head *z = y->p;
    splay_head *b = (x == y->lc) ? x->rc : x->lc;
    
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
    
    y->update_size();
    x->update_size();
}

void splay_splay(splay_head **root, splay_head *x, splay_head *target) {
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

void splay_insert_before(splay_head **root, splay_head *x, splay_head *y) {
    if (!y) {
        x->lc = *root;
        if (*root) (*root)->p = x;
        *root = x;
        x->update_size();
    } else {
        splay_splay(root, y, NULL);
        if (!y->lc) {
            y->lc = x;
            x->p = y;
            y->update_size();
        } else {
            splay_head *prev = y->lc;
            while (prev->rc) prev = prev->rc;
            splay_splay(root, prev, y);
            prev->rc = x;
            x->p = prev;
            prev->update_size();
            y->update_size();
        }
    }
}

void splay_erase(splay_head **root, splay_head *x) {
    splay_splay(root, x, NULL);
    if (!x->lc) {
        if (x->rc) x->rc->p = NULL;
        *root = x->rc;
    } else {
        splay_head *prev = x->lc;
        while (prev->rc) prev = prev->rc;
        splay_splay(root, prev, x);
        prev->rc = x->rc;
        if (x->rc) x->rc->p = prev;
        prev->update_size();
        prev->p = NULL;
        *root = prev;
    }
    x->lc = x->rc = x->p = NULL;
}

int splay_get_rank(splay_head **root, splay_head *x) {
    if (!x) return *root ? (*root)->size : 0;
    splay_splay(root, x, NULL);
    return x->lc ? x->lc->size : 0;
}

splay_head *splay_find_nth_inner(splay_head **root, int k) {
    splay_head *p = *root;
    while (true) {
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

splay_head *splay_find_nth(splay_head **root, int k) {
    splay_head *p = splay_find_nth_inner(root, k);
    splay_splay(root, p, NULL);
    return p;
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
    
    list_init(&lst);
    
    for (int i = 0; i < n; i++) {
        splay_insert_before(&splay.root, &arr[i].sh, NULL);
        list_insert_prev(&arr[i].lh, &lst);
    }
    
    int last_left = 0;
    int last_right = 0;
    
    while (splay.root) {
        splay_head *it = splay.root;
        lit_t lit = it->lh;
        lit_t root = lst;
        int left = root.next->pos;
        int right = root.prev->pos;
        
        splay_erase(&splay.root, it);
        
        if (it->pos == left && it->pos == right) {
            ans += (last_left < last_right) ? last_left : last_right;
        } else if (it->pos == left) {
            ans += last_left;
            last_left = it->v;
        } else if (it->pos == right) {
            ans += last_right;
            last_right = it->v;
        } else {
            ans += (next(lit)->v < prev(lit)->v) ? next(lit)->v : prev(lit)->v;
        }
        
        list_unlink(&it->lh);
    }
    
    printf("%lld\n", ans);
    return 0;
}

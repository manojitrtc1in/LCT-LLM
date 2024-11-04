#include <stdio.h>
#include <stdlib.h>

struct list_head {
    struct list_head *prev, *next;
};

struct node_t {
    struct list_head lh;
    struct id14 sh;
    int v;
    int pos;
};

struct id14 {
    struct id14 *lc, *rc, *p;
    int size;
};

struct list_iter {
    struct node_t *cur;
};

struct bst_iterator {
    struct id14 *cur;
};

struct id9 {
    struct id14 *root;
};

struct id10 {
    struct id14 *root;
    struct Accessor acc;
    struct Comp comp;
};

struct list_head lst;
struct id9 splay;
struct node_t arr[500005];
int64_t ans = 0;

void id2(struct id14 *x) {
    struct id14 *y = x->p;
    bst_rotate(x);
    y->update_size();
}

void id0(struct id14 *&root, struct id14 *x, struct id14 *target) {
    while (x->p != target) {
        if (x->p->p != target) {
            if ((x->p->lc == x) == (x->p->p->lc == x->p))
                id2(x->p);
            else
                id2(x);
        }
        id2(x);
    }
    x->update_size();
    if (!target)
        root = x;
}

void id5(struct id14 *&root, struct id14 *x, struct id14 *y) {
    if (!y) {
        x->lc = root;
        if (root) root->p = x;
        root = x;
        x->update_size();
    } else {
        id0(root, y, NULL);
        if (!y->lc)
            y->lc = x, x->p = y, y->update_size();
        else {
            struct id14 *prev = id8(y->lc);
            id0(root, prev, y);
            prev->rc = x;
            x->p = prev;
            prev->update_size();
            y->update_size();
        }
    }
}

void id15(struct id14 *&root, struct id14 *x) {
    id0(root, x, NULL);
    if (!x->lc) {
        if (x->rc) x->rc->p = NULL;
        root = x->rc;
    } else {
        struct id14 *prev = id8(x->lc);
        id0(root, prev, x);
        prev->rc = x->rc;
        if (x->rc) x->rc->p = prev;
        prev->update_size();
        prev->p = NULL, root = prev;
    }
    x->reset();
}

int id12(struct id14 *&root, struct id14 *x) {
    if (!x) return root ? root->size : 0;
    id0(root, x, NULL);
    return x->lc ? x->lc->size : 0;
}

struct id14 *id1(struct id14 *&root, int k) {
    struct id14 *p = root;
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

struct id14 *id11(struct id14 *&root, int k) {
    struct id14 *p = id1(root, k);
    id0(root, p, NULL);
    return p;
}

struct bst_iterator begin() {
    struct bst_iterator it;
    it.cur = id7(root);
    return it;
}

struct bst_iterator end() {
    struct bst_iterator it;
    it.cur = NULL;
    return it;
}

struct bst_iterator find_nth(int k) {
    struct bst_iterator it;
    it.cur = id11(root, k);
    return it;
}

int get_rank(struct bst_iterator it) {
    return id12(root, it.cur);
}

struct bst_iterator erase(struct bst_iterator it) {
    struct bst_iterator next = it;
    ++next;
    id15(root, it.cur);
    return next;
}

void new_int(int *n) {
    scanf("%d", n);
}

void new_int(int *v) {
    scanf("%d", v);
}

void printf(const char *format, int64_t ans) {
    printf("%lld\n", ans);
}

int main() {
    int n;
    new_int(&n);
    for (int i = 0; i < n; i++) {
        int v;
        new_int(&v);
        arr[i].v = v;
        arr[i].pos = i;
    }
    for (int i = 0; i < n; i++) {
        splay.insert_front(&arr[i]);
        lst.insert_prev(arr[i].lh);
    }
    int last_left = 0;
    int last_right = 0;
    while (splay.size()) {
        struct bst_iterator it = splay.begin();
        struct list_iter lit = struct list_iter(it.cur->lh);
        struct list_iter root = struct list_iter(lst);
        int left = next(root)->pos;
        int right = prev(root)->pos;
        splay.erase(it);
        if (it.cur->pos == left && it.cur->pos == right) {
            ans += min(last_left, last_right);
        } else if (it.cur->pos == left) {
            ans += last_left;
            last_left = it.cur->v;
        } else if (it.cur->pos == right) {
            ans += last_right;
            last_right = it.cur->v;
        } else {
            ans += min(next(lit)->v, prev(lit)->v);
        }
        it.cur->lh.unlink();
    }
    printf("%lld\n", ans);
    return 0;
}

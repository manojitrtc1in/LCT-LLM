#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_NODES 2000000

typedef struct Node {
    int priority;
    int value;
    int id;
    int originalId;
    int upd;
    struct Node* l;
    struct Node* r;
} Node;

Node memo[MAX_NODES];
int countNodes = 0;
Node* root = NULL;

int getInt() {
    int ret;
    scanf("%d", &ret);
    return ret;
}

int getRandomInt(int up_to) {
    return rand() % up_to;
}

void push(Node* it) {
    if (it && it->upd) {
        it->value += it->upd;
        if (it->l) it->l->upd += it->upd;
        if (it->r) it->r->upd += it->upd;
        it->upd = 0;
    }
}

void merge(Node** t, Node* l, Node* r) {
    push(l);
    push(r);
    if (!l || !r)
        *t = l ? l : r;
    else if (l->priority > r->priority)
        merge(&(l->r), l->r, r), *t = l;
    else
        merge(&(r->l), l, r->l), *t = r;
}

void split(Node* t, int key, Node** l, Node** r) {
    if (!t) {
        *l = *r = NULL;
        return;
    }
    push(t);
    if (key < t->value)
        split(t->l, key, l, &(t->l)), *r = t;
    else
        split(t->r, key, &(t->r), r), *l = t;
}

Node* newNode(int value, int id) {
    Node* p = &memo[countNodes++];
    p->priority = getRandomInt(1000000000);
    p->value = value;
    p->originalId = id;
    p->id = -1;
    p->upd = 0;
    p->l = p->r = NULL;
    return p;
}

void solve() {
    int n = getInt();
    int m = getInt();
    root = NULL;

    for (int i = 0; i < n; i++) {
        Node* t = newNode(i, i);
        merge(&root, root, t);
    }

    int leftIds[MAX_NODES];
    for (int i = 0; i < n; i++) {
        leftIds[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int id = getInt() - 1;
        int pos = getInt() - 1;

        Node* t1;
        Node* t2;
        Node* t3;
        split(root, pos - 1, &t1, &t2);
        split(t2, pos, &t2, &t3);

        if (t2 && t2->id != -1) {
            if (t2->id != id) {
                printf("-1\n");
                return;
            }
        } else {
            if (leftIds[id] == -1) {
                printf("-1\n");
                return;
            }
            leftIds[id] = -1;
            t2->id = id;
        }
        t2->value = 0;
        t2->upd = 0;
        if (t1) {
            t1->upd++;
        }
        merge(&root, t2, t1);
        merge(&root, root, t3);
    }

    int p[MAX_NODES];
    memset(p, -1, sizeof(p));

    for (int i = 0; i < n; i++) {
        Node* t1;
        split(root, i, &t1, &root);
        if (t1 && t1->id != -1) {
            p[t1->originalId] = t1->id;
        }
    }

    for (int i = 0; i < n; i++) {
        if (p[i] == -1) {
            for (int j = 0; j < n; j++) {
                if (leftIds[j] != -1) {
                    p[i] = leftIds[j];
                    leftIds[j] = -1;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", p[i] + 1);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    solve();
    return 0;
}

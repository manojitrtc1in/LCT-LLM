#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD1 1000000007
#define MAX_M 100000

typedef struct {
    int *data;
    int size;
    int default_value;
    int (*func)(int, int);
} SegmentTree;

SegmentTree* create_segment_tree(int *data, int len, int default_value, int (*func)(int, int)) {
    SegmentTree *tree = (SegmentTree *)malloc(sizeof(SegmentTree));
    tree->default_value = default_value;
    tree->func = func;
    tree->size = 1 << (len - 1);
    tree->data = (int *)malloc(2 * tree->size * sizeof(int));
    memset(tree->data, default_value, 2 * tree->size * sizeof(int));
    memcpy(tree->data + tree->size, data, len * sizeof(int));
    for (int i = tree->size - 1; i > 0; i--) {
        tree->data[i] = func(tree->data[i * 2], tree->data[i * 2 + 1]);
    }
    return tree;
}

void set_item(SegmentTree *tree, int idx, int value) {
    idx += tree->size;
    tree->data[idx] = value;
    while (idx > 1) {
        idx /= 2;
        tree->data[idx] = tree->func(tree->data[idx * 2], tree->data[idx * 2 + 1]);
    }
}

int query(SegmentTree *tree, int start, int stop) {
    if (start == stop) return tree->data[start + tree->size];
    stop++;
    start += tree->size;
    stop += tree->size;

    int res = tree->default_value;
    while (start < stop) {
        if (start & 1) {
            res = tree->func(res, tree->data[start]);
            start++;
        }
        if (stop & 1) {
            stop--;
            res = tree->func(res, tree->data[stop]);
        }
        start /= 2;
        stop /= 2;
    }
    return res;
}

int max_func(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int cnt[MAX_M + 1] = {0};
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        cnt[a - 1]++;
        cnt[b]--;
    }

    for (int i = 1; i < m; i++) {
        cnt[i] += cnt[i - 1];
    }

    int l[MAX_M] = {0};
    int l1[MAX_M] = {0};
    int fi[MAX_M] = {0};
    int cou[MAX_M] = {0};

    int ind[MAX_M];
    for (int i = 0; i < m; i++) {
        ind[i] = i;
    }

    // Sort cnt
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (cnt[ind[i]] > cnt[ind[j]]) {
                int temp = ind[i];
                ind[i] = ind[j];
                ind[j] = temp;
            }
        }
    }

    SegmentTree *s = create_segment_tree(l, m, 0, max_func);
    SegmentTree *s1 = create_segment_tree(l1, m, 0, max_func);
    int cur1 = 0;

    for (int i = 0; i < m; i++) {
        int mw = query(s, 0, ind[i]) + 1;
        l[ind[i]] = mw;
        fi[i] = mw;
        cur1 = cur1 > mw ? cur1 : mw;
        set_item(s, ind[i], mw);
    }

    // Reverse sort cnt
    for (int i = 0; i < m; i++) {
        ind[i] = -ind[i];
    }
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (cnt[-ind[i]] < cnt[-ind[j]]) {
                int temp = ind[i];
                ind[i] = ind[j];
                ind[j] = temp;
            }
        }
    }

    for (int i = m - 1; i >= 0; i--) {
        int mw = query(s1, 0, ind[i]) + 1;
        fi[i] += mw;
        l1[ind[i]] = mw;
        set_item(s1, ind[i], mw);
    }

    int max_fi = fi[0];
    for (int i = 1; i < m; i++) {
        if (fi[i] > max_fi) {
            max_fi = fi[i];
        }
    }

    printf("%d\n", max_fi - 1);

    free(s->data);
    free(s);
    free(s1->data);
    free(s1);
    return 0;
}

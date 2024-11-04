#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD1 998244353
#define MAXN 100000

typedef struct {
    int key, value, height, num_left, num_total;
    struct TreeNode *left, *right, *parent;
} TreeNode;

typedef struct {
    TreeNode *_tree;
} id8;

typedef struct {
    int *data;
    int _len, _size, _default;
    int (*_func)(int, int);
} SegmentTree;

int max(int a, int b) {
    return a > b ? a : b;
}

TreeNode* createNode(int k, int v) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->key = k;
    node->value = v;
    node->left = node->right = node->parent = NULL;
    node->height = 1;
    node->num_left = 1;
    node->num_total = 1;
    return node;
}

id8* createId8() {
    id8* tree = (id8*)malloc(sizeof(id8));
    tree->_tree = NULL;
    return tree;
}

int getHeight(TreeNode* x) {
    return x ? x->height : 0;
}

int id1(TreeNode* x) {
    return x ? x->num_total : 0;
}

void rotateRight(id8* tree, TreeNode* node) {
    TreeNode* left = node->left;
    node->left = left->right;
    if (left->right) left->right->parent = node;
    left->parent = node->parent;
    if (!node->parent) {
        tree->_tree = left;
    } else if (node == node->parent->left) {
        node->parent->left = left;
    } else {
        node->parent->right = left;
    }
    left->right = node;
    node->parent = left;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    left->height = max(getHeight(left->left), getHeight(left->right)) + 1;
}

void rotateLeft(id8* tree, TreeNode* node) {
    TreeNode* right = node->right;
    node->right = right->left;
    if (right->left) right->left->parent = node;
    right->parent = node->parent;
    if (!node->parent) {
        tree->_tree = right;
    } else if (node == node->parent->left) {
        node->parent->left = right;
    } else {
        node->parent->right = right;
    }
    right->left = node;
    node->parent = right;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    right->height = max(getHeight(right->left), getHeight(right->right)) + 1;
}

void rebalance(id8* tree, TreeNode* node) {
    while (node) {
        int lh = getHeight(node->left);
        int rh = getHeight(node->right);
        node->height = max(lh, rh) + 1;
        node->num_total = 1 + id1(node->left) + id1(node->right);
        node->num_left = 1 + id1(node->left);

        int balance_factor = lh - rh;

        if (balance_factor > 1) {
            if (getHeight(node->left->left) < getHeight(node->left->right)) {
                rotateLeft(tree, node->left);
            }
            rotateRight(tree, node);
        } else if (balance_factor < -1) {
            if (getHeight(node->right->right) < getHeight(node->right->left)) {
                rotateRight(tree, node->right);
            }
            rotateLeft(tree, node);
        }
        node = node->parent;
    }
}

void add(id8* tree, int k, int v) {
    if (!tree->_tree) {
        tree->_tree = createNode(k, v);
        return;
    }
    TreeNode* node = tree->_tree;
    while (1) {
        if (k < node->key) {
            if (node->left) {
                node = node->left;
            } else {
                node->left = createNode(k, v);
                node->left->parent = node;
                rebalance(tree, node->left);
                return;
            }
        } else if (node->key < k) {
            if (node->right) {
                node = node->right;
            } else {
                node->right = createNode(k, v);
                node->right->parent = node;
                rebalance(tree, node->right);
                return;
            }
        } else {
            node->value = v;
            return;
        }
    }
}

SegmentTree* createSegmentTree(int* data, int len, int default_value, int (*func)(int, int)) {
    SegmentTree* segTree = (SegmentTree*)malloc(sizeof(SegmentTree));
    segTree->_default = default_value;
    segTree->_func = func;
    segTree->_len = len;
    segTree->_size = 1 << (len - 1).bit_length();
    segTree->data = (int*)malloc(2 * segTree->_size * sizeof(int));
    for (int i = 0; i < 2 * segTree->_size; i++) {
        segTree->data[i] = default_value;
    }
    memcpy(segTree->data + segTree->_size, data, len * sizeof(int));
    for (int i = segTree->_size - 1; i > 0; i--) {
        segTree->data[i] = func(segTree->data[i + i], segTree->data[i + i + 1]);
    }
    return segTree;
}

void updateSegmentTree(SegmentTree* segTree, int idx, int value) {
    idx += segTree->_size;
    segTree->data[idx] = value;
    idx >>= 1;
    while (idx) {
        segTree->data[idx] = segTree->_func(segTree->data[2 * idx], segTree->data[2 * idx + 1]);
        idx >>= 1;
    }
}

int querySegmentTree(SegmentTree* segTree, int start, int stop) {
    if (start == stop) {
        return segTree->data[start + segTree->_size];
    }
    stop += 1;
    start += segTree->_size;
    stop += segTree->_size;

    int res = segTree->_default;
    while (start < stop) {
        if (start & 1) {
            res = segTree->_func(res, segTree->data[start]);
            start += 1;
        }
        if (stop & 1) {
            stop -= 1;
            res = segTree->_func(res, segTree->data[stop]);
        }
        start >>= 1;
        stop >>= 1;
    }
    return res;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int cnt[MAXN] = {0};
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        cnt[a - 1]++;
        cnt[b]--;
    }
    for (int i = 1; i < m; i++) {
        cnt[i] += cnt[i - 1];
    }
    int l[MAXN] = {0}, l1[MAXN] = {0};
    int fi[MAXN] = {0};
    int pairs[MAXN][2];
    for (int i = 0; i < m; i++) {
        pairs[i][0] = cnt[i];
        pairs[i][1] = i;
    }
    qsort(pairs, m, sizeof(pairs[0]), [](const void* a, const void* b) {
        return ((int*)a)[0] - ((int*)b)[0];
    });
    int ind[MAXN] = {0};
    for (int i = 0; i < m; i++) {
        ind[pairs[i][1]] = i;
    }
    SegmentTree* s = createSegmentTree(l, m, 0, max);
    SegmentTree* s1 = createSegmentTree(l1, m, 0, max);
    int cur1 = 0;

    for (int i = 0; i < m; i++) {
        int mw = querySegmentTree(s, 0, ind[i]) + 1;
        l[ind[i]] = mw;
        fi[i] = mw;
        cur1 = max(cur1, mw);
        updateSegmentTree(s, ind[i], mw);
    }

    for (int i = m - 1; i >= 0; i--) {
        int mw = querySegmentTree(s1, 0, ind[i]) + 1;
        fi[i] += mw;
        l1[ind[i]] = mw;
        updateSegmentTree(s1, ind[i], mw);
    }
    int result = -1;
    for (int i = 0; i < m; i++) {
        if (fi[i] > result) {
            result = fi[i];
        }
    }
    printf("%d\n", result - 1);
    return 0;
}

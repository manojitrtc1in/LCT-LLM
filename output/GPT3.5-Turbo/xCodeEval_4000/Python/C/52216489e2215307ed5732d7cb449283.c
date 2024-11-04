#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

typedef struct {
    int key;
    int value;
} TreeNode;

typedef struct {
    TreeNode* tree;
} AvlTree;

typedef struct {
    int* data;
    int size;
} SegmentTree;

typedef struct {
    int* data;
    int size;
} Factorial;

typedef struct {
    int MOD;
    Factorial* factorial;
} Combination;

void add(AvlTree* avlTree, int k, int v);
TreeNode* _add(AvlTree* avlTree, int k, int v);
int get_height(TreeNode* x);
int get_num_total(TreeNode* x);
void _rebalance(AvlTree* avlTree, TreeNode* node);
void _remove_one(AvlTree* avlTree, TreeNode* node);
void _remove_leaf(AvlTree* avlTree, TreeNode* node);
void remove_node(AvlTree* avlTree, int k);
TreeNode* get_node(AvlTree* avlTree, int k);
int get_at(AvlTree* avlTree, int pos);
int is_left(TreeNode* node);
int is_leaf(TreeNode* node);
void rotate_right(AvlTree* avlTree, TreeNode* node);
void rotate_left(AvlTree* avlTree, TreeNode* node);
TreeNode* get_next(TreeNode* node);

void init_segment_tree(SegmentTree* segmentTree, int* data, int size);
void set_segment_tree(SegmentTree* segmentTree, int idx, int value);
int get_segment_tree(SegmentTree* segmentTree, int idx);
int query_segment_tree(SegmentTree* segmentTree, int start, int stop);

void init_factorial(Factorial* factorial, int MOD);
int calc_factorial(Factorial* factorial, int n);
int inv_factorial(Factorial* factorial, int n);

void init_combination(Combination* combination, int MOD);
int ncr_combination(Combination* combination, int n, int k);

void sort_list(int* list1, int* list2, int size);
int product(int* l);
int binary_search_count(int* arr, int n, int key);
int count_digits(int n);
char* binary(int x, int length);
int count_greater(int* arr, int n, int k);

void add(AvlTree* avlTree, int k, int v) {
    if (avlTree->tree == NULL) {
        avlTree->tree = (TreeNode*)malloc(sizeof(TreeNode));
        avlTree->tree->key = k;
        avlTree->tree->value = v;
        avlTree->tree->left = NULL;
        avlTree->tree->right = NULL;
        avlTree->tree->parent = NULL;
        avlTree->tree->height = 1;
        avlTree->tree->num_left = 1;
        avlTree->tree->num_total = 1;
        return;
    }
    TreeNode* node = _add(avlTree, k, v);
    if (node != NULL) {
        _rebalance(avlTree, node);
    }
}

TreeNode* _add(AvlTree* avlTree, int k, int v) {
    TreeNode* node = avlTree->tree;
    while (node != NULL) {
        if (k < node->key) {
            if (node->left != NULL) {
                node = node->left;
            } else {
                node->left = (TreeNode*)malloc(sizeof(TreeNode));
                node->left->key = k;
                node->left->value = v;
                node->left->left = NULL;
                node->left->right = NULL;
                node->left->parent = node;
                return node->left;
            }
        } else if (node->key < k) {
            if (node->right != NULL) {
                node = node->right;
            } else {
                node->right = (TreeNode*)malloc(sizeof(TreeNode));
                node->right->key = k;
                node->right->value = v;
                node->right->left = NULL;
                node->right->right = NULL;
                node->right->parent = node;
                return node->right;
            }
        } else {
            node->value = v;
            return NULL;
        }
    }
}

int get_height(TreeNode* x) {
    return x != NULL ? x->height : 0;
}

int get_num_total(TreeNode* x) {
    return x != NULL ? x->num_total : 0;
}

void _rebalance(AvlTree* avlTree, TreeNode* node) {
    TreeNode* n = node;
    while (n != NULL) {
        int lh = get_height(n->left);
        int rh = get_height(n->right);
        n->height = (lh > rh ? lh : rh) + 1;
        int balance_factor = lh - rh;
        n->num_total = 1 + get_num_total(n->left) + get_num_total(n->right);
        n->num_left = 1 + get_num_total(n->left);
        if (balance_factor > 1) {
            if (get_height(n->left->left) < get_height(n->left->right)) {
                rotate_left(avlTree, n->left);
            }
            rotate_right(avlTree, n);
        } else if (balance_factor < -1) {
            if (get_height(n->right->right) < get_height(n->right->left)) {
                rotate_right(avlTree, n->right);
            }
            rotate_left(avlTree, n);
        } else {
            n = n->parent;
        }
    }
}

void _remove_one(AvlTree* avlTree, TreeNode* node) {
    TreeNode* replacement = node->left != NULL ? node->left : node->right;
    if (node->parent != NULL) {
        if (is_left(node)) {
            node->parent->left = replacement;
        } else {
            node->parent->right = replacement;
        }
        if (replacement != NULL) {
            replacement->parent = node->parent;
        }
        node->parent = NULL;
    } else {
        avlTree->tree = replacement;
        if (replacement != NULL) {
            replacement->parent = NULL;
        }
    }
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    _rebalance(avlTree, replacement);
}

void _remove_leaf(AvlTree* avlTree, TreeNode* node) {
    if (node->parent != NULL) {
        if (is_left(node)) {
            node->parent->left = NULL;
        } else {
            node->parent->right = NULL;
        }
        _rebalance(avlTree, node->parent);
    } else {
        avlTree->tree = NULL;
    }
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
}

void remove_node(AvlTree* avlTree, int k) {
    TreeNode* node = get_node(avlTree, k);
    if (node == NULL) {
        return;
    }
    if (is_leaf(node)) {
        _remove_leaf(avlTree, node);
        return;
    }
    if (node->left != NULL && node->right != NULL) {
        TreeNode* nxt = get_next(node);
        node->key = nxt->key;
        node->value = nxt->value;
        if (is_leaf(nxt)) {
            _remove_leaf(avlTree, nxt);
        } else {
            _remove_one(avlTree, nxt);
        }
        _rebalance(avlTree, node);
    } else {
        _remove_one(avlTree, node);
    }
}

TreeNode* get_node(AvlTree* avlTree, int k) {
    if (avlTree->tree == NULL) {
        return NULL;
    }
    TreeNode* node = avlTree->tree;
    while (node != NULL) {
        if (k < node->key) {
            node = node->left;
        } else if (node->key < k) {
            node = node->right;
        } else {
            return node;
        }
    }
    return NULL;
}

int get_at(AvlTree* avlTree, int pos) {
    int x = pos + 1;
    TreeNode* node = avlTree->tree;
    while (node != NULL) {
        if (x < node->num_left) {
            node = node->left;
        } else if (node->num_left < x) {
            x -= node->num_left;
            node = node->right;
        } else {
            return node->key;
        }
    }
    printf("Out of ranges\n");
    exit(1);
}

int is_left(TreeNode* node) {
    return node->parent != NULL && node->parent->left != NULL && node->parent->left == node;
}

int is_leaf(TreeNode* node) {
    return node->left == NULL && node->right == NULL;
}

void rotate_right(AvlTree* avlTree, TreeNode* node) {
    if (node->parent == NULL) {
        avlTree->tree = node->left;
        node->left->parent = NULL;
    } else if (is_left(node)) {
        node->parent->left = node->left;
        node->left->parent = node->parent;
    } else {
        node->parent->right = node->left;
        node->left->parent = node->parent;
    }
    TreeNode* bk = node->left->right;
    node->left->right = node;
    node->parent = node->left;
    node->left = bk;
    if (bk != NULL) {
        bk->parent = node;
    }
    node->height = (get_height(node->left) > get_height(node->right) ? get_height(node->left) : get_height(node->right)) + 1;
    node->num_total = 1 + get_num_total(node->left) + get_num_total(node->right);
    node->num_left = 1 + get_num_total(node->left);
}

void rotate_left(AvlTree* avlTree, TreeNode* node) {
    if (node->parent == NULL) {
        avlTree->tree = node->right;
        node->right->parent = NULL;
    } else if (is_left(node)) {
        node->parent->left = node->right;
        node->right->parent = node->parent;
    } else {
        node->parent->right = node->right;
        node->right->parent = node->parent;
    }
    TreeNode* bk = node->right->left;
    node->right->left = node;
    node->parent = node->right;
    node->right = bk;
    if (bk != NULL) {
        bk->parent = node;
    }
    node->height = (get_height(node->left) > get_height(node->right) ? get_height(node->left) : get_height(node->right)) + 1;
    node->num_total = 1 + get_num_total(node->left) + get_num_total(node->right);
    node->num_left = 1 + get_num_total(node->left);
}

TreeNode* get_next(TreeNode* node) {
    if (node->right == NULL) {
        return node->parent;
    }
    TreeNode* n = node->right;
    while (n->left != NULL) {
        n = n->left;
    }
    return n;
}

void init_segment_tree(SegmentTree* segmentTree, int* data, int size) {
    segmentTree->data = (int*)malloc(sizeof(int) * (2 * size));
    segmentTree->size = size;
    for (int i = 0; i < size; i++) {
        segmentTree->data[size + i] = data[i];
    }
    for (int i = size - 1; i > 0; i--) {
        segmentTree->data[i] = segmentTree->data[i + i] & segmentTree->data[i + i + 1];
    }
}

void set_segment_tree(SegmentTree* segmentTree, int idx, int value) {
    idx += segmentTree->size;
    segmentTree->data[idx] = value;
    idx >>= 1;
    while (idx > 0) {
        segmentTree->data[idx] = segmentTree->data[idx + idx] & segmentTree->data[idx + idx + 1];
        idx >>= 1;
    }
}

int get_segment_tree(SegmentTree* segmentTree, int idx) {
    return segmentTree->data[segmentTree->size + idx];
}

int query_segment_tree(SegmentTree* segmentTree, int start, int stop) {
    if (start == stop) {
        return get_segment_tree(segmentTree, start);
    }
    stop++;
    start += segmentTree->size;
    stop += segmentTree->size;
    int res = 0;
    while (start < stop) {
        if (start & 1) {
            res = res & segmentTree->data[start];
            start++;
        }
        if (stop & 1) {
            stop--;
            res = res & segmentTree->data[stop];
        }
        start >>= 1;
        stop >>= 1;
    }
    return res;
}

void init_factorial(Factorial* factorial, int MOD) {
    factorial->MOD = MOD;
    factorial->data = (int*)malloc(sizeof(int) * 2);
    factorial->data[0] = 1;
    factorial->data[1] = 1;
}

int calc_factorial(Factorial* factorial, int n) {
    if (n < 0) {
        printf("Invalid argument to calculate n!\n");
        printf("n must be non-negative value. But the argument was %d\n", n);
        exit(1);
    }
    if (n < factorial->size) {
        return factorial->data[n];
    }
    int* nextArr = (int*)malloc(sizeof(int) * (n + 1 - factorial->size));
    int initialI = factorial->size;
    int prev = factorial->data[factorial->size - 1];
    int m = factorial->MOD;
    for (int i = initialI; i <= n; i++) {
        prev = nextArr[i - initialI] = (prev * i) % m;
    }
    factorial->data = (int*)realloc(factorial->data, sizeof(int) * (n + 1));
    for (int i = initialI; i <= n; i++) {
        factorial->data[i] = nextArr[i - initialI];
    }
    factorial->size = n + 1;
    free(nextArr);
    return factorial->data[n];
}

int inv_factorial(Factorial* factorial, int n) {
    if (n < 0) {
        printf("Invalid argument to calculate (n^(-1))!\n");
        printf("n must be non-negative value. But the argument was %d\n", n);
        exit(1);
    }
    int p = factorial->MOD;
    int pi = n % p;
    if (pi < factorial->size) {
        return factorial->data[pi];
    }
    int* nextArr = (int*)malloc(sizeof(int) * (n + 1 - factorial->size));
    int initialI = factorial->size;
    for (int i = initialI; i <= n && i < p; i++) {
        int next = -factorial->data[p % i] * (p / i) % p;
        nextArr[i - initialI] = next;
    }
    factorial->data = (int*)realloc(factorial->data, sizeof(int) * (n + 1));
    for (int i = initialI; i <= n && i < p; i++) {
        factorial->data[i] = nextArr[i - initialI];
    }
    factorial->size = n + 1;
    free(nextArr);
    return factorial->data[pi];
}

void init_combination(Combination* combination, int MOD) {
    combination->MOD = MOD;
    combination->factorial = (Factorial*)malloc(sizeof(Factorial));
    init_factorial(combination->factorial, MOD);
}

int ncr_combination(Combination* combination, int n, int k) {
    if (k < 0 || n < k) {
        return 0;
    }
    k = k < n - k ? k : n - k;
    Factorial* f = combination->factorial;
    return (calc_factorial(f, n) * inv_factorial(f, k) % combination->MOD) * inv_factorial(f, n - k) % combination->MOD;
}

void sort_list(int* list1, int* list2, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (list2[i] > list2[j]) {
                int temp1 = list1[i];
                int temp2 = list2[i];
                list1[i] = list1[j];
                list2[i] = list2[j];
                list1[j] = temp1;
                list2[j] = temp2;
            }
        }
    }
}

int product(int* l, int size) {
    int por = 1;
    for (int i = 0; i < size; i++) {
        por *= l[i];
    }
    return por;
}

int binary_search_count(int* arr, int n, int key) {
    int left = 0;
    int right = n - 1;
    int count = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] < key) {
            count = mid + 1;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return count;
}

int count_digits(int n) {
    int c = 0;
    while (n > 0) {
        n /= 10;
        c++;
    }
    return c;
}

char* binary(int x, int length) {
    char* y = (char*)malloc(sizeof(char) * (length + 1));
    itoa(x, y, 2);
    int len = strlen(y);
    if (len < length) {
        char* z = (char*)malloc(sizeof(char) * (length + 1));
        for (int i = 0; i < length - len; i++) {
            z[i] = '0';
        }
        for (int i = 0; i < len; i++) {
            z[length - len + i] = y[i];
        }
        z[length] = '\0';
        free(y);
        return z;
    }
    return y;
}

int count_greater(int* arr, int n, int k) {
    int l = 0;
    int r = n - 1;
    int leftGreater = n;
    while (l <= r) {
        int m = (l + r) / 2;
        if (arr[m] >= k) {
            leftGreater = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return n - leftGreater;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int* cnt = (int*)malloc(sizeof(int) * (m + 1));
    for (int i = 0; i <= m; i++) {
        cnt[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        cnt[a - 1]++;
        cnt[b]--;
    }
    for (int i = 1; i <= m; i++) {
        cnt[i] += cnt[i - 1];
    }
    int* l = (int*)malloc(sizeof(int) * m);
    int* l1 = (int*)malloc(sizeof(int) * m);
    int* fi = (int*)malloc(sizeof(int) * m);
    int* cnt_copy = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        cnt_copy[i] = cnt[i];
    }
    sort_list(l, cnt_copy, m);
    sort_list(l1, cnt_copy, m);
    free(cnt_copy);
    for (int i = 0; i < m; i++) {
        l[i] = 0;
        l1[i] = 0;
    }
    AvlTree* avlTree = (AvlTree*)malloc(sizeof(AvlTree));
    avlTree->tree = NULL;
    for (int i = 0; i < m; i++) {
        add(avlTree, l[i], l1[i]);
    }
    int* cou = (int*)malloc(sizeof(int) * m);
    int cur = 0;
    int cur1 = 0;
    for (int i = 0; i < m; i++) {
        int mw = query_segment_tree(avlTree, 0, get_node(avlTree, i)) + 1;
        l[i] = mw;
        fi[i] = mw;
        cur1 = cur1 > mw ? cur1 : mw;
        set_segment_tree(avlTree, get_node(avlTree, i), mw);
    }
    for (int i = 0; i < m; i++) {
        cnt[i] = -cnt[i];
    }
    sort_list(l, cnt, m);
    for (int i = 0; i < m; i++) {
        cnt[i] = -cnt[i];
    }
    for (int i = 0; i < m; i++) {
        int mw = query_segment_tree(avlTree, 0, get_node(avlTree, i)) + 1;
        fi[i] += mw;
        l1[i] = mw;
        set_segment_tree(avlTree, get_node(avlTree, i), mw);
    }
    printf("%d\n", cur1 - 1);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    long key;
    long priority;
    struct Node* left;
    struct Node* right;
    int size;
} Node;

Node* createNode(long key, long priority) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->priority = priority;
    node->left = NULL;
    node->right = NULL;
    node->size = 1;
    return node;
}

Node* merge(Node* left, Node* right) {
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;
    if (left->priority > right->priority) {
        left->right = merge(left->right, right);
        left->size = (left->left ? left->left->size : 0) + (left->right ? left->right->size : 0) + 1;
        return left;
    }
    right->left = merge(left, right->left);
    right->size = (right->left ? right->left->size : 0) + (right->right ? right->right->size : 0) + 1;
    return right;
}

void split(Node* root, long key, Node** left, Node** right) {
    if (root == NULL) {
        *left = NULL;
        *right = NULL;
    } else if (root->key <= key) {
        split(root->right, key, &root->right, right);
        *left = root;
    } else {
        split(root->left, key, left, &root->left);
        *right = root;
    }
    if (root != NULL)
        root->size = (root->left ? root->left->size : 0) + (root->right ? root->right->size : 0) + 1;
}

Node* insert(Node* root, long key, long priority) {
    Node* node = createNode(key, priority);
    Node* left;
    Node* right;
    split(root, key, &left, &right);
    return merge(merge(left, node), right);
}

Node* erase(Node* root, long key) {
    Node* left;
    Node* middle;
    Node* right;
    split(root, key - 1, &left, &middle);
    split(middle, key, &middle, &right);
    free(middle);
    return merge(left, right);
}

Node* lower(Node* root, long key) {
    if (root == NULL)
        return NULL;
    if (root->key >= key)
        return lower(root->left, key);
    Node* result = lower(root->right, key);
    if (result == NULL)
        return root;
    return result;
}

Node* floor(Node* root, long key) {
    if (root == NULL)
        return NULL;
    if (root->key > key)
        return floor(root->left, key);
    Node* result = floor(root->right, key);
    if (result == NULL)
        return root;
    return result;
}

Node* higher(Node* root, long key) {
    if (root == NULL)
        return NULL;
    if (root->key <= key)
        return higher(root->right, key);
    Node* result = higher(root->left, key);
    if (result == NULL)
        return root;
    return result;
}

Node* ceil(Node* root, long key) {
    if (root == NULL)
        return NULL;
    if (root->key < key)
        return ceil(root->right, key);
    Node* result = ceil(root->left, key);
    if (result == NULL)
        return root;
    return result;
}

long query(Node* root, long from, long to) {
    Node* left;
    Node* middle;
    Node* right;
    split(root, from - 1, &left, &middle);
    split(middle, to, &middle, &right);
    long result = (middle ? middle->size : 0);
    root = merge(merge(left, middle), right);
    return result;
}

int main() {
    Node* root = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            long x;
            scanf("%ld", &x);
            root = insert(root, x, rand());
        } else if (type == 2) {
            long x;
            scanf("%ld", &x);
            root = erase(root, x);
        } else if (type == 3) {
            long x;
            scanf("%ld", &x);
            printf("%ld\n", query(root, 0, x));
        }
    }
    return 0;
}

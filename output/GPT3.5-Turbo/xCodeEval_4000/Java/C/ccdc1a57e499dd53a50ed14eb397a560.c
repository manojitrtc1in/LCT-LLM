#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct Node {
    int key;
    long priority;
    struct Node* left;
    struct Node* right;
    int size;
} Node;

Node* createNode(int key, long priority) {
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

void split(Node* root, int key, Node** left, Node** right) {
    if (root == NULL) {
        *left = NULL;
        *right = NULL;
        return;
    }
    if (root->key <= key) {
        *left = root;
        split(root->right, key, &((*left)->right), right);
    } else {
        *right = root;
        split(root->left, key, left, &((*right)->left));
    }
    if (*left)
        (*left)->size = ((*left)->left ? (*left)->left->size : 0) + ((*left)->right ? (*left)->right->size : 0) + 1;
    if (*right)
        (*right)->size = ((*right)->left ? (*right)->left->size : 0) + ((*right)->right ? (*right)->right->size : 0) + 1;
}

Node* insert(Node* root, int key, long priority) {
    Node* node = createNode(key, priority);
    Node* left;
    Node* right;
    split(root, key, &left, &right);
    return merge(merge(left, node), right);
}

Node* erase(Node* root, int key) {
    Node* left;
    Node* right;
    split(root, key, &left, &right);
    Node* leftLeft;
    Node* leftRight;
    split(left, key - 1, &leftLeft, &leftRight);
    return merge(leftLeft, right);
}

Node* lower(Node* root, int key) {
    if (root == NULL)
        return NULL;
    if (root->key >= key)
        return lower(root->left, key);
    Node* result = lower(root->right, key);
    if (result == NULL)
        return root;
    return result;
}

Node* floor(Node* root, int key) {
    if (root == NULL)
        return NULL;
    if (root->key > key)
        return floor(root->left, key);
    Node* result = floor(root->right, key);
    if (result == NULL)
        return root;
    return result;
}

Node* higher(Node* root, int key) {
    if (root == NULL)
        return NULL;
    if (root->key <= key)
        return higher(root->right, key);
    Node* result = higher(root->left, key);
    if (result == NULL)
        return root;
    return result;
}

Node* ceil(Node* root, int key) {
    if (root == NULL)
        return NULL;
    if (root->key < key)
        return ceil(root->right, key);
    Node* result = ceil(root->left, key);
    if (result == NULL)
        return root;
    return result;
}

int indexOf(Node* root, int key) {
    if (root == NULL)
        return -1;
    if (root->key == key)
        return (root->left ? root->left->size : 0);
    if (root->key > key)
        return indexOf(root->left, key);
    int result = indexOf(root->right, key);
    if (result == -1)
        return -1;
    return (root->left ? root->left->size : 0) + 1 + result;
}

int main() {
    Node* root = NULL;
    root = insert(root, 5, 1);
    root = insert(root, 3, 2);
    root = insert(root, 7, 3);
    root = insert(root, 2, 4);
    root = insert(root, 4, 5);
    root = insert(root, 6, 6);
    root = insert(root, 8, 7);
    printf("%d\n", indexOf(root, 5)); // Output: 3
    printf("%d\n", indexOf(root, 2)); // Output: 0
    printf("%d\n", indexOf(root, 8)); // Output: 6
    printf("%d\n", indexOf(root, 1)); // Output: -1
    return 0;
}

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

int compare(int first, int second) {
    if (first < second) {
        return -1;
    } else if (first > second) {
        return 1;
    } else {
        return 0;
    }
}

Node* merge(Node* left, Node* right) {
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }
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
    } else if (root->key <= key) {
        split(root->right, key, &(root->right), right);
        *left = root;
    } else {
        split(root->left, key, left, &(root->left));
        *right = root;
    }
    if (root != NULL) {
        root->size = (root->left ? root->left->size : 0) + (root->right ? root->right->size : 0) + 1;
    }
}

Node* insert(Node* root, Node* node) {
    if (root == NULL) {
        return node;
    }
    if (node->priority > root->priority) {
        split(root, node->key, &(node->left), &(node->right));
        return node;
    }
    if (node->key < root->key) {
        root->left = insert(root->left, node);
    } else {
        root->right = insert(root->right, node);
    }
    root->size = (root->left ? root->left->size : 0) + (root->right ? root->right->size : 0) + 1;
    return root;
}

Node* erase(Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->key == key) {
        Node* newRoot = merge(root->left, root->right);
        free(root);
        return newRoot;
    }
    if (key < root->key) {
        root->left = erase(root->left, key);
    } else {
        root->right = erase(root->right, key);
    }
    root->size = (root->left ? root->left->size : 0) + (root->right ? root->right->size : 0) + 1;
    return root;
}

int lower(Node* root, int key) {
    if (root == NULL) {
        return -1;
    }
    if (root->key >= key) {
        return lower(root->left, key);
    }
    int result = lower(root->right, key);
    if (result == -1) {
        return root->key;
    }
    return result;
}

int floor(Node* root, int key) {
    if (root == NULL) {
        return -1;
    }
    if (root->key > key) {
        return floor(root->left, key);
    }
    int result = floor(root->right, key);
    if (result == -1) {
        return root->key;
    }
    return result;
}

int higher(Node* root, int key) {
    if (root == NULL) {
        return -1;
    }
    if (root->key <= key) {
        return higher(root->right, key);
    }
    int result = higher(root->left, key);
    if (result == -1) {
        return root->key;
    }
    return result;
}

int ceil(Node* root, int key) {
    if (root == NULL) {
        return -1;
    }
    if (root->key < key) {
        return ceil(root->right, key);
    }
    int result = ceil(root->left, key);
    if (result == -1) {
        return root->key;
    }
    return result;
}

int main() {
    Node* root = NULL;
    root = insert(root, createNode(1, 1));
    root = insert(root, createNode(2, 2));
    root = insert(root, createNode(3, 3));
    printf("%d\n", lower(root, 2)); // Output: 1
    printf("%d\n", floor(root, 2)); // Output: 2
    printf("%d\n", higher(root, 2)); // Output: 3
    printf("%d\n", ceil(root, 2)); // Output: 2
    root = erase(root, 2);
    printf("%d\n", lower(root, 2)); // Output: 1
    printf("%d\n", floor(root, 2)); // Output: 1
    printf("%d\n", higher(root, 2)); // Output: 3
    printf("%d\n", ceil(root, 2)); // Output: 3
    return 0;
}

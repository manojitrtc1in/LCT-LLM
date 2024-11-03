#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void updateSize(Node* node) {
    node->size = 1;
    if (node->left != NULL) {
        node->size += node->left->size;
    }
    if (node->right != NULL) {
        node->size += node->right->size;
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
        updateSize(left);
        return left;
    }
    right->left = merge(left, right->left);
    updateSize(right);
    return right;
}

void split(Node* root, long key, Node** left, Node** right) {
    if (root == NULL) {
        *left = NULL;
        *right = NULL;
    } else if (root->key <= key) {
        split(root->right, key, &(root->right), right);
        *left = root;
        updateSize(*left);
    } else {
        split(root->left, key, left, &(root->left));
        *right = root;
        updateSize(*right);
    }
}

Node* insert(Node* root, long key, long priority) {
    Node* newNode = createNode(key, priority);
    Node* left = NULL;
    Node* right = NULL;
    split(root, key, &left, &right);
    Node* merged = merge(left, newNode);
    return merge(merged, right);
}

Node* erase(Node* root, long key) {
    Node* left = NULL;
    Node* right = NULL;
    split(root, key, &left, &right);
    Node* middle = NULL;
    split(right, key + 1, &middle, &right);
    free(middle);
    return merge(left, right);
}

Node* search(Node* root, long key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (root->key < key) {
        return search(root->right, key);
    }
    return search(root->left, key);
}

Node* lower(Node* root, long key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->key >= key) {
        return lower(root->left, key);
    }
    Node* result = lower(root->right, key);
    if (result == NULL) {
        return root;
    }
    return result;
}

Node* floor(Node* root, long key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->key > key) {
        return floor(root->left, key);
    }
    Node* result = floor(root->right, key);
    if (result == NULL) {
        return root;
    }
    return result;
}

Node* higher(Node* root, long key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->key <= key) {
        return higher(root->right, key);
    }
    Node* result = higher(root->left, key);
    if (result == NULL) {
        return root;
    }
    return result;
}

Node* ceil(Node* root, long key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->key < key) {
        return ceil(root->right, key);
    }
    Node* result = ceil(root->left, key);
    if (result == NULL) {
        return root;
    }
    return result;
}

int main() {
    Node* root = NULL;
    root = insert(root, 1, 1);
    root = insert(root, 2, 2);
    root = insert(root, 3, 3);
    Node* node = search(root, 2);
    if (node != NULL) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }
    root = erase(root, 2);
    node = search(root, 2);
    if (node != NULL) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }
    return 0;
}

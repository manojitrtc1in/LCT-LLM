#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

int compare(int a, int b) {
    if (a < b) {
        return -1;
    } else if (a > b) {
        return 1;
    } else {
        return 0;
    }
}

int index(int key, int capacity) {
    return key & (capacity - 1);
}

int getHash(int h) {
    int result = h;
    int shifts[] = {1, 4, 7, 10, 13, 16, 19, 22, 25, 28};
    for (int i = 0; i < 10; i++) {
        result ^= h >> shifts[i];
    }
    return result;
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

Node* split(Node* root, int key, Node** left, Node** right) {
    if (root == NULL) {
        *left = NULL;
        *right = NULL;
        return NULL;
    }
    if (root->key <= key) {
        *left = root;
        Node* rightLeft;
        Node* rightRight;
        split(root->right, key, &rightLeft, &rightRight);
        (*left)->right = rightLeft;
        *right = rightRight;
        (*left)->size = ((*left)->left ? (*left)->left->size : 0) + ((*left)->right ? (*left)->right->size : 0) + 1;
        return *left;
    }
    *right = root;
    Node* leftLeft;
    Node* leftRight;
    split(root->left, key, &leftLeft, &leftRight);
    (*right)->left = leftRight;
    *left = leftLeft;
    (*right)->size = ((*right)->left ? (*right)->left->size : 0) + ((*right)->right ? (*right)->right->size : 0) + 1;
    return *right;
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
    Node* middle;
    split(root, key - 1, &left, &middle);
    split(middle, key, &middle, &right);
    free(middle);
    return merge(left, right);
}

Node* lower(Node* root, int key) {
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

Node* floor(Node* root, int key) {
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

Node* higher(Node* root, int key) {
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

Node* ceil(Node* root, int key) {
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

Node* first(Node* root) {
    if (root->left == NULL) {
        return root;
    }
    return first(root->left);
}

Node* last(Node* root) {
    if (root->right == NULL) {
        return root;
    }
    return last(root->right);
}

Node* search(Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->key == key) {
        return root;
    }
    if (root->key < key) {
        return search(root->right, key);
    }
    return search(root->left, key);
}

int indexOf(Node* root, Node* node) {
    if (root == NULL) {
        return 0;
    }
    if (root == node) {
        return root->left ? root->left->size : 0;
    }
    if (root->key < node->key) {
        return (root->left ? root->left->size : 0) + 1 + indexOf(root->right, node);
    }
    return indexOf(root->left, node);
}

int size(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->size;
}

typedef struct {
    int key;
    long value;
} Entry;

Entry* createEntry(int key, long value) {
    Entry* entry = (Entry*)malloc(sizeof(Entry));
    entry->key = key;
    entry->value = value;
    return entry;
}

Entry* get(Node* root, int key) {
    Node* node = search(root, key);
    if (node == NULL) {
        return NULL;
    }
    return createEntry(node->key, node->value);
}

void put(Node** root, int key, long value) {
    Node* node = search(*root, key);
    if (node != NULL) {
        node->value = value;
        return;
    }
    *root = insert(*root, key, rand());
    Node* lowerNode = lower(*root, key);
    if (lowerNode != NULL) {
        lowerNode->value = value;
    }
}

void erase(Node** root, int key) {
    *root = erase(*root, key);
}

int main() {
    Node* root = NULL;
    put(&root, 1, 10);
    put(&root, 2, 20);
    put(&root, 3, 30);
    Entry* entry = get(root, 2);
    if (entry != NULL) {
        printf("%d\n", entry->value);
    }
    erase(&root, 2);
    entry = get(root, 2);
    if (entry == NULL) {
        printf("Key not found\n");
    }
    return 0;
}

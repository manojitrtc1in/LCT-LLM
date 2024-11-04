#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 100000

typedef struct Node {
    long key;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
    int color;
    int numLeft;
    int numRight;
} Node;

typedef struct {
    Node* root;
    Node* nil;
} RedBlackTree;

typedef struct {
    long* data;
    int size;
    int capacity;
} ArrayList;

void initArrayList(ArrayList* list) {
    list->size = 0;
    list->capacity = 10;
    list->data = (long*)malloc(list->capacity * sizeof(long));
}

void addToArrayList(ArrayList* list, long value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (long*)realloc(list->data, list->capacity * sizeof(long));
    }
    list->data[list->size++] = value;
}

void freeArrayList(ArrayList* list) {
    free(list->data);
}

Node* createNode(long key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->color = 1; // RED
    node->numLeft = 0;
    node->numRight = 0;
    return node;
}

void leftRotate(RedBlackTree* tree, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != tree->nil) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == tree->nil) {
        tree->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void rightRotate(RedBlackTree* tree, Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right != tree->nil) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == tree->nil) {
        tree->root = x;
    } else if (y == y->parent->right) {
        y->parent->right = x;
    } else {
        y->parent->left = x;
    }
    x->right = y;
    y->parent = x;
}

void insertFixUp(RedBlackTree* tree, Node* z) {
    Node* y;
    while (z->parent->color == 1) {
        if (z->parent == z->parent->parent->left) {
            y = z->parent->parent->right;
            if (y->color == 1) {
                z->parent->color = 0;
                y->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(tree, z);
                }
                z->parent->color = 0;
                z->parent->parent->color = 1;
                rightRotate(tree, z->parent->parent);
            }
        } else {
            y = z->parent->parent->left;
            if (y->color == 1) {
                z->parent->color = 0;
                y->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(tree, z);
                }
                z->parent->color = 0;
                z->parent->parent->color = 1;
                leftRotate(tree, z->parent->parent);
            }
        }
    }
    tree->root->color = 0;
}

void insert(RedBlackTree* tree, long key) {
    Node* z = createNode(key);
    Node* y = tree->nil;
    Node* x = tree->root;

    while (x != tree->nil) {
        y = x;
        if (z->key < x->key) {
            x->numLeft++;
            x = x->left;
        } else {
            x->numRight++;
            x = x->right;
        }
    }
    z->parent = y;
    if (y == tree->nil) {
        tree->root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
    z->left = tree->nil;
    z->right = tree->nil;
    insertFixUp(tree, z);
}

void initRedBlackTree(RedBlackTree* tree) {
    tree->nil = createNode(0);
    tree->nil->color = 0; // BLACK
    tree->root = tree->nil;
}

void freeTree(Node* node, Node* nil) {
    if (node != nil) {
        freeTree(node->left, nil);
        freeTree(node->right, nil);
        free(node);
    }
}

void freeRedBlackTree(RedBlackTree* tree) {
    freeTree(tree->root, tree->nil);
    free(tree->nil);
}

long bfs(long w, int n) {
    // BFS implementation here
    return -1; // Placeholder
}

int main() {
    RedBlackTree tree;
    initRedBlackTree(&tree);

    int n;
    long w;
    scanf("%d %ld", &n, &w);
    printf("%ld\n", bfs(w, n));

    freeRedBlackTree(&tree);
    return 0;
}

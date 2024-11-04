#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
    int numLeft;
    int numRight;
    int color;
};

typedef struct Node Node;

Node* nil;

Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->parent = nil;
    node->left = nil;
    node->right = nil;
    node->numLeft = 0;
    node->numRight = 0;
    node->color = 1; // RED
    return node;
}

void leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != nil) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nil) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void rightRotate(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right != nil) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == nil) {
        root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

void insert(Node* z) {
    Node* y = nil;
    Node* x = root;
    while (x != nil) {
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
    if (y == nil) {
        root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
    z->left = nil;
    z->right = nil;
    z->color = 1; // RED
    insertFixup(z);
}

void insertFixup(Node* z) {
    while (z->parent->color == 1) { // RED
        if (z->parent == z->parent->parent->left) {
            Node* y = z->parent->parent->right;
            if (y->color == 1) { // RED
                z->parent->color = 0; // BLACK
                y->color = 0; // BLACK
                z->parent->parent->color = 1; // RED
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = 0; // BLACK
                z->parent->parent->color = 1; // RED
                rightRotate(z->parent->parent);
            }
        } else {
            Node* y = z->parent->parent->left;
            if (y->color == 1) { // RED
                z->parent->color = 0; // BLACK
                y->color = 0; // BLACK
                z->parent->parent->color = 1; // RED
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = 0; // BLACK
                z->parent->parent->color = 1; // RED
                leftRotate(z->parent->parent);
            }
        }
    }
    root->color = 0; // BLACK
}

Node* treeMinimum(Node* node) {
    while (node->left != nil) {
        node = node->left;
    }
    return node;
}

Node* successor(Node* x) {
    if (x->right != nil) {
        return treeMinimum(x->right);
    }
    Node* y = x->parent;
    while (y != nil && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

void delete(Node* z) {
    Node* x;
    Node* y = z;
    int yOriginalColor = y->color;
    if (z->left == nil) {
        x = z->right;
        transplant(z, z->right);
    } else if (z->right == nil) {
        x = z->left;
        transplant(z, z->left);
    } else {
        y = treeMinimum(z->right);
        yOriginalColor = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if (yOriginalColor == 0) { // BLACK
        deleteFixup(x);
    }
}

void transplant(Node* u, Node* v) {
    if (u->parent == nil) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

void deleteFixup(Node* x) {
    while (x != root && x->color == 0) { // BLACK
        if (x == x->parent->left) {
            Node* w = x->parent->right;
            if (w->color == 1) { // RED
                w->color = 0; // BLACK
                x->parent->color = 1; // RED
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if (w->left->color == 0 && w->right->color == 0) { // BLACK
                w->color = 1; // RED
                x = x->parent;
            } else {
                if (w->right->color == 0) { // BLACK
                    w->left->color = 0; // BLACK
                    w->color = 1; // RED
                    rightRotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = 0; // BLACK
                w->right->color = 0; // BLACK
                leftRotate(x->parent);
                x = root;
            }
        } else {
            Node* w = x->parent->left;
            if (w->color == 1) { // RED
                w->color = 0; // BLACK
                x->parent->color = 1; // RED
                rightRotate(x->parent);
                w = x->parent->left;
            }
            if (w->right->color == 0 && w->left->color == 0) { // BLACK
                w->color = 1; // RED
                x = x->parent;
            } else {
                if (w->left->color == 0) { // BLACK
                    w->right->color = 0; // BLACK
                    w->color = 1; // RED
                    leftRotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = 0; // BLACK
                w->left->color = 0; // BLACK
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    x->color = 0; // BLACK
}

Node* search(int key) {
    Node* current = root;
    while (current != nil) {
        if (current->key == key) {
            return current;
        } else if (current->key < key) {
            current = current->right;
        } else {
            current = current->left;
        }
    }
    return NULL;
}

int numGreater(int key) {
    return id4(root, key);
}

int id4(Node* node, int key) {
    if (node == nil) {
        return 0;
    } else if (key < node->key) {
        return 1 + node->numRight + id4(node->left, key);
    } else {
        return id4(node->right, key);
    }
}

int main() {
    nil = createNode(0);
    nil->color = 0; // BLACK
    root = nil;
    // Insert code here
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct RedBlackNode {
    int key;
    struct RedBlackNode* parent;
    struct RedBlackNode* left;
    struct RedBlackNode* right;
    int numLeft;
    int numRight;
    int color;
};

typedef struct RedBlackNode RedBlackNode;

RedBlackNode* nil;

RedBlackNode* createNode(int key) {
    RedBlackNode* node = (RedBlackNode*)malloc(sizeof(RedBlackNode));
    node->key = key;
    node->parent = nil;
    node->left = nil;
    node->right = nil;
    node->numLeft = 0;
    node->numRight = 0;
    node->color = 1;
    return node;
}

void leftRotate(RedBlackNode* x) {
    RedBlackNode* y = x->right;
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

void leftRotateFixup(RedBlackNode* x) {
    if (x->left == nil && x->right->left == nil) {
        x->numLeft = 0;
        x->numRight = 0;
        x->right->numLeft = 1;
    } else if (x->left == nil && x->right->left != nil) {
        x->numLeft = 0;
        x->numRight = 1 + x->right->left->numLeft + x->right->left->numRight;
        x->right->numLeft = 2 + x->right->left->numLeft + x->right->left->numRight;
    } else if (x->left != nil && x->right->left == nil) {
        x->numRight = 0;
        x->right->numLeft = 2 + x->left->numLeft + x->left->numRight;
    } else {
        x->numRight = 1 + x->right->left->numLeft + x->right->left->numRight;
        x->right->numLeft = 3 + x->left->numLeft + x->left->numRight + x->right->left->numLeft + x->right->left->numRight;
    }
}

void rightRotate(RedBlackNode* y) {
    RedBlackNode* x = y->left;
    y->left = x->right;
    if (x->right != nil) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == nil) {
        root = x;
    } else if (y == y->parent->right) {
        y->parent->right = x;
    } else {
        y->parent->left = x;
    }
    x->right = y;
    y->parent = x;
}

void rightRotateFixup(RedBlackNode* y) {
    if (y->right == nil && y->left->right == nil) {
        y->numRight = 0;
        y->numLeft = 0;
        y->left->numRight = 1;
    } else if (y->right == nil && y->left->right != nil) {
        y->numRight = 0;
        y->numLeft = 1 + y->left->right->numRight + y->left->right->numLeft;
        y->left->numRight = 2 + y->left->right->numRight + y->left->right->numLeft;
    } else if (y->right != nil && y->left->right == nil) {
        y->numLeft = 0;
        y->left->numRight = 2 + y->right->numRight + y->right->numLeft;
    } else {
        y->numLeft = 1 + y->left->right->numRight + y->left->right->numLeft;
        y->left->numRight = 3 + y->right->numRight + y->right->numLeft + y->left->right->numRight + y->left->right->numLeft;
    }
}

void insert(int key) {
    RedBlackNode* z = createNode(key);
    RedBlackNode* y = nil;
    RedBlackNode* x = root;
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
    z->color = 1;
    insertFixup(z);
}

void insertFixup(RedBlackNode* z) {
    RedBlackNode* y;
    while (z->parent->color == 1) {
        if (z->parent == z->parent->parent->left) {
            y = z->parent->parent->right;
            if (y->color == 1) {
                z->parent->color = 0;
                y->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;
            } else if (z == z->parent->right) {
                z = z->parent;
                leftRotate(z);
            } else {
                z->parent->color = 0;
                z->parent->parent->color = 1;
                rightRotate(z->parent->parent);
            }
        } else {
            y = z->parent->parent->left;
            if (y->color == 1) {
                z->parent->color = 0;
                y->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;
            } else if (z == z->parent->left) {
                z = z->parent;
                rightRotate(z);
            } else {
                z->parent->color = 0;
                z->parent->parent->color = 1;
                leftRotate(z->parent->parent);
            }
        }
    }
    root->color = 0;
}

RedBlackNode* treeMinimum(RedBlackNode* node) {
    while (node->left != nil) {
        node = node->left;
    }
    return node;
}

RedBlackNode* treeSuccessor(RedBlackNode* x) {
    if (x->left != nil) {
        return treeMinimum(x->right);
    }
    RedBlackNode* y = x->parent;
    while (y != nil && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

void remove(RedBlackNode* v) {
    RedBlackNode* z = search(v->key);
    RedBlackNode* x;
    RedBlackNode* y;
    if (z->left == nil || z->right == nil) {
        y = z;
    } else {
        y = treeSuccessor(z);
    }
    if (y->left != nil) {
        x = y->left;
    } else {
        x = y->right;
    }
    x->parent = y->parent;
    if (y->parent == nil) {
        root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    if (y != z) {
        z->key = y->key;
    }
    fixNodeData(x, y);
    if (y->color == 0) {
        removeFixup(x);
    }
}

void fixNodeData(RedBlackNode* x, RedBlackNode* y) {
    RedBlackNode* current;
    RedBlackNode* track;
    if (x == nil) {
        current = y->parent;
        track = y;
    } else {
        current = x->parent;
        track = x;
    }
    while (current != nil) {
        if (y->key != current->key) {
            if (y->key > current->key) {
                current->numRight--;
            }
            if (y->key < current->key) {
                current->numLeft--;
            }
        } else {
            if (current->left == nil) {
                current->numLeft--;
            } else if (current->right == nil) {
                current->numRight--;
            } else if (track == current->right) {
                current->numRight--;
            } else if (track == current->left) {
                current->numLeft--;
            }
        }
        track = current;
        current = current->parent;
    }
}

void removeFixup(RedBlackNode* x) {
    RedBlackNode* w;
    while (x != root && x->color == 0) {
        if (x == x->parent->left) {
            w = x->parent->right;
            if (w->color == 1) {
                w->color = 0;
                x->parent->color = 1;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if (w->left->color == 0 && w->right->color == 0) {
                w->color = 1;
                x = x->parent;
            } else {
                if (w->right->color == 0) {
                    w->left->color = 0;
                    w->color = 1;
                    rightRotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = 0;
                w->right->color = 0;
                leftRotate(x->parent);
                x = root;
            }
        } else {
            w = x->parent->left;
            if (w->color == 1) {
                w->color = 0;
                x->parent->color = 1;
                rightRotate(x->parent);
                w = x->parent->left;
            }
            if (w->right->color == 0 && w->left->color == 0) {
                w->color = 1;
                x = x->parent;
            } else {
                if (w->left->color == 0) {
                    w->right->color = 0;
                    w->color = 1;
                    leftRotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = 0;
                w->left->color = 0;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    x->color = 0;
}

RedBlackNode* search(int key) {
    RedBlackNode* current = root;
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
    return findNumGreater(root, key);
}

int numSmaller(int key) {
    return findNumSmaller(root, key);
}

int findNumGreater(RedBlackNode* node, int key) {
    if (node == nil) {
        return 0;
    } else if (key < node->key) {
        return 1 + node->numRight + findNumGreater(node->left, key);
    } else {
        return findNumGreater(node->right, key);
    }
}

int findNumSmaller(RedBlackNode* node, int key) {
    if (node == nil) {
        return 0;
    } else if (key <= node->key) {
        return findNumSmaller(node->left, key);
    } else {
        return 1 + node->numLeft + findNumSmaller(node->right, key);
    }
}

int main() {
    nil = createNode(0);
    nil->color = 0;
    root = nil;
    insert(5);
    insert(3);
    insert(8);
    insert(2);
    insert(4);
    insert(7);
    insert(9);
    printf("Number of elements greater than 6: %d\n", numGreater(6));
    printf("Number of elements smaller than 6: %d\n", numSmaller(6));
    remove(search(5));
    printf("Number of elements greater than 6 after removing 5: %d\n", numGreater(6));
    return 0;
}

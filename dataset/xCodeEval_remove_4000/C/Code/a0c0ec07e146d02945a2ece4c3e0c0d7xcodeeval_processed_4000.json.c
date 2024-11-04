


typedef struct {
    int mPrimaryVal;
} RBData_t;

typedef enum {
    RB_RED,
    RB_BLACK
} RBColor_t;

struct RBNode_t {
    struct RBNode_t *mLeft, *mRight, *mParent;
    RBColor_t mColor;
    RBData_t mKey;
};

typedef struct {
    struct RBNode_t mSentinelLeaf;
    struct RBNode_t *mTreeRoot;
} RBTree_t;

void Show(struct RBNode_t *node)
{
    printf("%p %p %p %p %d %d\n", node, node->mParent, node->mLeft, node->mRight, node->mKey.mPrimaryVal, node->mColor);
}

void id12(RBTree_t *tree)
{
    tree->mTreeRoot = &(tree->mSentinelLeaf);
    tree->mSentinelLeaf.mColor = RB_BLACK;
}

void id1(struct RBNode_t *node, struct RBNode_t *stop)
{
    if(node != stop) {
        id1(node->mLeft, stop);
        Show(node);
        id1(node->mRight, stop);
    }
}

void id11(struct RBNode_t *node, struct RBNode_t *stop)
{
    if(node != stop) {
        id11(node->mLeft, stop);
        id11(node->mRight, stop);
        free(node);
    }
}

void id5(RBTree_t *tree)
{
    id11(tree->mTreeRoot, &(tree->mSentinelLeaf));
    id12(tree);
}

struct RBNode_t *id0(struct RBNode_t *node, RBData_t *key, struct RBNode_t *stop)
{
    while(node != stop && key->mPrimaryVal != node->mKey.mPrimaryVal) {
        if(key->mPrimaryVal < node->mKey.mPrimaryVal) {
            node = node->mLeft;
        } else {
            node = node->mRight;
        }
    }
    return node;
}

struct RBNode_t *id4(struct RBNode_t *node, struct RBNode_t *stop)
{
    if(node == stop) {
        return node;
    }
    while(node->mLeft != stop) {
        node = node->mLeft;
    }
    return node;
}

struct RBNode_t *id6(struct RBNode_t *node, struct RBNode_t *stop)
{
    if(node == stop) {
        return node;
    }
    while(node->mRight != stop) {
        node = node->mRight;
    }
    return node;
}

struct RBNode_t *id9(struct RBNode_t *node, struct RBNode_t *stop)
{
    if(node->mRight != stop) {
        return id4(node->mRight, stop);
    }
    struct RBNode_t *p = node->mParent;
    while(p != stop && node == p->mRight) {
        node = p;
        p = node->mParent;
    }
    return p;
}

struct RBNode_t *id2(struct RBNode_t *node, struct RBNode_t *stop)
{
    if(node->mLeft != stop) {
        return id6(node->mLeft, stop);
    }
    struct RBNode_t *p = node->mParent;
    while(p != stop && node == p->mLeft) {
        node = p;
        p = node->mParent;
    }
    return p;
}

void id10(RBTree_t *tree, struct RBNode_t *node)
{
    struct RBNode_t *y = node->mRight;
    node->mRight = y->mLeft;
    if(y->mLeft != &(tree->mSentinelLeaf)) {
        y->mLeft->mParent = node;
    }
    y->mParent = node->mParent;
    if(node->mParent == &(tree->mSentinelLeaf)) {
        tree->mTreeRoot = y;
    } else if(node == node->mParent->mLeft) {
        node->mParent->mLeft = y;
    } else {
        node->mParent->mRight = y;
    }
    y->mLeft = node;
    node->mParent = y;
}

void id8(RBTree_t *tree, struct RBNode_t *node)
{
    struct RBNode_t *y = node->mLeft;
    node->mLeft = y->mRight;
    if(y->mRight != &(tree->mSentinelLeaf)) {
        y->mRight->mParent = node;
    }
    y->mParent = node->mParent;
    if(node->mParent == &(tree->mSentinelLeaf)) {
        tree->mTreeRoot = y;
    } else if(node == node->mParent->mLeft) {
        node->mParent->mLeft = y;
    } else {
        node->mParent->mRight = y;
    }
    y->mRight = node;
    node->mParent = y;
}

void id15(RBTree_t *tree, struct RBNode_t *node)
{
    struct RBNode_t *s;
    while(node->mParent->mColor == RB_RED) {
        if(node->mParent == node->mParent->mParent->mLeft) {
            s = node->mParent->mParent->mRight;
        } else {
            s = node->mParent->mParent->mLeft;
        }
        if(s->mColor == RB_RED) {
            node->mParent->mColor = RB_BLACK;
            s->mColor = RB_BLACK;
            node->mParent->mParent->mColor = RB_RED;
            node = node->mParent->mParent;
        } else {
            if(node == node->mParent->mRight && node->mParent == node->mParent->mParent->mLeft) {
                node = node->mParent;
                id10(tree, node);
            } else if(node == node->mParent->mLeft && node->mParent == node->mParent->mParent->mRight) {
                node = node->mParent;
                id8(tree, node);
            }
            node->mParent->mColor = RB_BLACK;
            node->mParent->mParent->mColor = RB_RED;
            if(node == node->mParent->mLeft) {
                id8(tree, node->mParent->mParent);
            } else {
                id10(tree, node->mParent->mParent);
            }
        }
    }
    tree->mTreeRoot->mColor = RB_BLACK;
}

void id13(RBTree_t *tree, struct RBNode_t *node)
{
    struct RBNode_t *y = &(tree->mSentinelLeaf);
    struct RBNode_t *x = tree->mTreeRoot;
    while(x != &(tree->mSentinelLeaf)) {
        y = x;
        if(node->mKey.mPrimaryVal < x->mKey.mPrimaryVal) {
            x = x->mLeft;
        } else {
            x = x->mRight;
        }
    }
    node->mParent = y;
    if(y == &(tree->mSentinelLeaf)) {
        tree->mTreeRoot = node;
    } else if(node->mKey.mPrimaryVal < y->mKey.mPrimaryVal) {
        y->mLeft = node;
    } else {
        y->mRight = node;
    }
    node->mLeft = &(tree->mSentinelLeaf);
    node->mRight = &(tree->mSentinelLeaf);
    node->mColor = RB_RED;
    id15(tree, node);
}

void id3(RBTree_t *tree, struct RBNode_t *u, struct RBNode_t *v)
{
    if(u->mParent == &(tree->mSentinelLeaf)) {
        tree->mTreeRoot = v;
    } else if(u == u->mParent->mLeft) {
        u->mParent->mLeft = v;
    } else {
        u->mParent->mRight = v;
    }
    v->mParent = u->mParent;
}

void id7(RBTree_t *tree, struct RBNode_t *node)
{
    struct RBNode_t *s;
    while(node != tree->mTreeRoot && node->mColor == RB_BLACK) {
        if(node == node->mParent->mLeft) {
            s = node->mParent->mRight;
            if(s->mColor == RB_RED) {
                s->mColor = RB_BLACK;
                node->mParent->mColor = RB_RED;
                id10(tree, node->mParent);
                s = node->mParent->mRight;
            }
            if(s->mLeft->mColor == RB_BLACK && s->mRight->mColor == RB_BLACK) {
                s->mColor = RB_RED;
                node = node->mParent;
            } else {
                if(s->mRight->mColor == RB_BLACK) {
                    s->mLeft->mColor = RB_BLACK;
                    s->mColor = RB_RED;
                    id8(tree, s);
                    s = node->mParent->mRight;
                }
                s->mColor = node->mParent->mColor;
                node->mParent->mColor = RB_BLACK;
                s->mRight->mColor = RB_BLACK;
                id10(tree, node->mParent);
                node = tree->mTreeRoot;
            }
        } else {
            s = node->mParent->mLeft;
            if(s->mColor == RB_RED) {
                s->mColor = RB_BLACK;
                node->mParent->mColor = RB_RED;
                id8(tree, node->mParent);
                s = node->mParent->mLeft;
            }
            if(s->mLeft->mColor == RB_BLACK && s->mRight->mColor == RB_BLACK) {
                s->mColor = RB_RED;
                node = node->mParent;
            } else {
                if(s->mLeft->mColor == RB_BLACK) {
                    s->mRight->mColor = RB_BLACK;
                    s->mColor = RB_RED;
                    id10(tree, s);
                    s = node->mParent->mLeft;
                }
                s->mColor = node->mParent->mColor;
                node->mParent->mColor = RB_BLACK;
                s->mLeft->mColor = RB_BLACK;
                id8(tree, node->mParent);
                node = tree->mTreeRoot;
            }
        }
    }
    node->mColor = RB_BLACK;
}

void id14(RBTree_t *tree, struct RBNode_t *node)
{
    struct RBNode_t *y = node;
    struct RBNode_t *x;
    RBColor_t origincolor = y->mColor;
    if(node->mLeft == &(tree->mSentinelLeaf)) {
        x = node->mRight;
        id3(tree, node, node->mRight);
    } else if(node->mRight == &(tree->mSentinelLeaf)) {
        x = node->mLeft;
        id3(tree, node, node->mLeft);
    } else {
        y = id4(node->mRight, &(tree->mSentinelLeaf));
        origincolor = y->mColor;
        x = y->mRight;
        if(y->mParent == node) {
            x->mParent = y;
        } else {
            id3(tree, y, y->mRight);
            y->mRight = node->mRight;
            y->mRight->mParent = y;
        }
        id3(tree, node, y);
        y->mLeft = node->mLeft;
        y->mLeft->mParent = y;
        y->mColor = node->mColor;
    }
    if(origincolor == RB_BLACK) {
        id7(tree, x);
    }
}

RBTree_t Tree;
int Mat[500][500];
int N, M;

int Front(int x, int y)
{
    if(y == 0) {
        return 0;
    }
    return Mat[x][y - 1];
}

int Back(int x, int y)
{
    if(y == M - 1) {
        return 0;
    }
    return Mat[x][y + 1];
}

int GetFront(int x, int y)
{
    int num = 0;
    int i;
    for(i = y - 1; i >= 0; --i) {
        if(!Mat[x][i]) {
            break;
        }
        ++num;
    }
    return num;
}

int GetBack(int x, int y)
{
    int num = 0;
    int i;
    for(i = y + 1; i < M; ++i) {
        if(!Mat[x][i]) {
            break;
        }
        ++num;
    }
    return num;
}

int main()
{
    int Q, i, j, x, y;
    id12(&Tree);
    scanf("%d %d %d", &N, &M, &Q);
    for(i = 0; i < N; ++i) {
        for(j = 0; j < M; ++j) {
            scanf("%d", &Mat[i][j]);
        }
        int num = 0;
        for(j = 0; j < M; ++j) {
            if(Mat[i][j] == 0) {
                if(num) {
                    struct RBNode_t *node = (struct RBNode_t *)malloc(sizeof(struct RBNode_t));
                    node->mKey.mPrimaryVal = num;
                    id13(&Tree, node);
                    num = 0;
                }
            } else {
                ++num;
            }
        }
        if(num) {
            struct RBNode_t *node = (struct RBNode_t *)malloc(sizeof(struct RBNode_t));
            node->mKey.mPrimaryVal = num;
            id13(&Tree, node);
        }
    }
    struct RBNode_t *checknode = (struct RBNode_t *)malloc(sizeof(struct RBNode_t));
    while(Q--) {
        scanf("%d %d", &x, &y);
        --x;
        --y;
        if(Mat[x][y] == 0) {
            if(!Front(x, y) && !Back(x, y)) {
                struct RBNode_t *node = (struct RBNode_t *)malloc(sizeof(struct RBNode_t));
                node->mKey.mPrimaryVal = 1;
                id13(&Tree, node);
            } else if(!Front(x, y) && Back(x, y)) {
                struct RBNode_t *node;
                checknode->mKey.mPrimaryVal = GetBack(x, y);
                node = id0(Tree.mTreeRoot, &checknode->mKey, &Tree.mSentinelLeaf);
                id14(&Tree, node);
                free(node);
                node = (struct RBNode_t *)malloc(sizeof(struct RBNode_t));
                node->mKey.mPrimaryVal = checknode->mKey.mPrimaryVal + 1;
                id13(&Tree, node);
            } else if(Front(x, y) && !Back(x, y)) {
                struct RBNode_t *node;
                checknode->mKey.mPrimaryVal = GetFront(x, y);
                node = id0(Tree.mTreeRoot, &checknode->mKey, &Tree.mSentinelLeaf);
                id14(&Tree, node);
                free(node);
                node = (struct RBNode_t *)malloc(sizeof(struct RBNode_t));
                node->mKey.mPrimaryVal = checknode->mKey.mPrimaryVal + 1;
                id13(&Tree, node);
            } else {
                struct RBNode_t *node;
                checknode->mKey.mPrimaryVal = GetFront(x, y);
                node = id0(Tree.mTreeRoot, &checknode->mKey, &Tree.mSentinelLeaf);
                id14(&Tree, node);
                free(node);
                checknode->mKey.mPrimaryVal = GetBack(x, y);
                node = id0(Tree.mTreeRoot, &checknode->mKey, &Tree.mSentinelLeaf);
                id14(&Tree, node);
                free(node);
                node = (struct RBNode_t *)malloc(sizeof(struct RBNode_t));
                node->mKey.mPrimaryVal = checknode->mKey.mPrimaryVal + GetFront(x, y) + 1;
                id13(&Tree, node);
            }
        } else if(Mat[x][y] == 1) {
            if(!Front(x, y) && !Back(x, y)) {
                struct RBNode_t *node;
                checknode->mKey.mPrimaryVal = 1;
                node = id0(Tree.mTreeRoot, &checknode->mKey, &Tree.mSentinelLeaf);
                id14(&Tree, node);
                free(node);
            } else if(!Front(x, y) && Back(x, y)) {
                struct RBNode_t *node;
                checknode->mKey.mPrimaryVal = GetBack(x, y) + 1;
                node = id0(Tree.mTreeRoot, &checknode->mKey, &Tree.mSentinelLeaf);
                id14(&Tree, node);
                free(node);
                node = (struct RBNode_t *)malloc(sizeof(struct RBNode_t));
                node->mKey.mPrimaryVal = checknode->mKey.mPrimaryVal - 1;
                id13(&Tree, node);
            } else if(Front(x, y) && !Back(x, y)) {
                struct RBNode_t *node;
                checknode->mKey.mPrimaryVal = GetFront(x, y) + 1;
                node = id0(Tree.mTreeRoot, &checknode->mKey, &Tree.mSentinelLeaf);
                id14(&Tree, node);
                free(node);
                node = (struct RBNode_t *)malloc(sizeof(struct RBNode_t));
                node->mKey.mPrimaryVal = checknode->mKey.mPrimaryVal - 1;
                id13(&Tree, node);
            } else {
                struct RBNode_t *node;
                checknode->mKey.mPrimaryVal = GetFront(x, y) + GetBack(x, y) + 1;
                node = id0(Tree.mTreeRoot, &checknode->mKey, &Tree.mSentinelLeaf);
                id14(&Tree, node);
                free(node);
                node = (struct RBNode_t *)malloc(sizeof(struct RBNode_t));
                node->mKey.mPrimaryVal = GetFront(x, y);
                id13(&Tree, node);
                node = (struct RBNode_t *)malloc(sizeof(struct RBNode_t));
                node->mKey.mPrimaryVal = GetBack(x, y);
                id13(&Tree, node);
            }
        }
        Mat[x][y] ^= 1;
        struct RBNode_t *node = id6(Tree.mTreeRoot, &Tree.mSentinelLeaf);
        printf("%d\n", node->mKey.mPrimaryVal);
    }
    id5(&Tree);
    return 0;
}

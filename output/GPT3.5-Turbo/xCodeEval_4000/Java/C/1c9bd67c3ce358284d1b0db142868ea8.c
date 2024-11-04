#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int X, Y;
} PairInt;

PairInt add(PairInt a, PairInt b) {
    PairInt result;
    result.X = a.X + b.X;
    result.Y = a.Y + b.Y;
    return result;
}

PairInt sub(PairInt a, PairInt b) {
    PairInt result;
    result.X = a.X - b.X;
    result.Y = a.Y - b.Y;
    return result;
}

int compare(PairInt a, PairInt b) {
    if (a.X != b.X) {
        return a.X - b.X;
    }
    return a.Y - b.Y;
}

typedef struct {
    int p, q, lambdaM, M, curX, bitCnt;
} BlumBlumShub;

BlumBlumShub createBlumBlumShub(int p, int q, int x0) {
    BlumBlumShub bbs;
    bbs.p = p;
    bbs.q = q;
    bbs.M = p * q;
    bbs.lambdaM = (p - 1) * (q - 1);
    bbs.curX = x0 % bbs.M;
    bbs.bitCnt = 30;
    return bbs;
}

int* getSequence(BlumBlumShub bbs, int len) {
    int* ret = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        ret[i] = bbs.curX % 2;
        bbs.curX = (bbs.curX * bbs.curX) % bbs.M;
    }
    return ret;
}

int nextInt(BlumBlumShub bbs) {
    int* bits = getSequence(bbs, bbs.bitCnt + 1);
    int ans = 0;
    for (int i = 0; i < bbs.bitCnt + 1; i++) {
        ans = ans * 2 + bits[i];
    }
    free(bits);
    return ans;
}

typedef struct {
    int nodeCount;
    int** dictionary;
    int* end;
    int* pathTrough;
    int dicSize;
} SuffixTrie;

SuffixTrie createSuffixTrie(int maxn, int dicSize) {
    SuffixTrie trie;
    trie.nodeCount = 0;
    trie.dictionary = (int**)malloc(maxn * sizeof(int*));
    for (int i = 0; i < maxn; i++) {
        trie.dictionary[i] = (int*)malloc(dicSize * sizeof(int));
        for (int j = 0; j < dicSize; j++) {
            trie.dictionary[i][j] = -1;
        }
    }
    trie.end = (int*)malloc(maxn * sizeof(int));
    trie.pathTrough = (int*)malloc(maxn * sizeof(int));
    trie.dicSize = dicSize;
    return trie;
}

void destroySuffixTrie(SuffixTrie trie, int maxn) {
    for (int i = 0; i < maxn; i++) {
        free(trie.dictionary[i]);
    }
    free(trie.dictionary);
    free(trie.end);
    free(trie.pathTrough);
}

int addLenWord_min(SuffixTrie trie, int u, int len) {
    if (len == 0) {
        return 0;
    }
    trie.pathTrough[u]++;
    int* curNode = trie.dictionary[u];
    int order[trie.dicSize];
    for (int i = 0; i < trie.dicSize; i++) {
        order[i] = i;
    }
    for (int i = trie.dicSize - 1; i >= 0; i--) {
        if (curNode[order[i]] != -1 && addLenWord_min(trie, curNode[order[i]], len - 1)) {
            return 1;
        }
    }
    for (int i = 0; i < trie.dicSize; i++) {
        if (curNode[i] == -1) {
            curNode[i] = trie.nodeCount++;
            int* newArr = (int*)malloc(trie.dicSize * sizeof(int));
            for (int j = 0; j < trie.dicSize; j++) {
                newArr[j] = -1;
            }
            trie.dictionary[curNode[i]] = newArr;
            if (len == 1) {
                trie.pathTrough[trie.nodeCount - 1]++;
                trie.end[trie.nodeCount - 1] = 1;
            }
            else {
                addLenWord_min(trie, trie.nodeCount - 1, len - 1);
            }
            return 1;
        }
    }
    return 0;
}

int addLenWord_max(SuffixTrie trie, int u, int len) {
    if (len == 0) {
        return 0;
    }
    trie.pathTrough[u]++;
    int* curNode = trie.dictionary[u];
    for (int i = 0; i < trie.dicSize; i++) {
        if (curNode[i] == -1) {
            curNode[i] = trie.nodeCount++;
            int* newArr = (int*)malloc(trie.dicSize * sizeof(int));
            for (int j = 0; j < trie.dicSize; j++) {
                newArr[j] = -1;
            }
            trie.dictionary[curNode[i]] = newArr;
            if (len == 1) {
                trie.pathTrough[trie.nodeCount - 1]++;
                trie.end[trie.nodeCount - 1] = 1;
            }
            else {
                addLenWord_max(trie, trie.nodeCount - 1, len - 1);
            }
            return 1;
        }
    }
    int order[trie.dicSize];
    for (int i = 0; i < trie.dicSize; i++) {
        order[i] = i;
    }
    for (int i = 0; i < trie.dicSize; i++) {
        if (addLenWord_max(trie, curNode[order[i]], len - 1)) {
            return 1;
        }
    }
    return 0;
}

typedef struct {
    int** adj;
    int n;
    int* level;
    int** jads;
} LCA;

LCA createLCA(int n) {
    LCA lca;
    lca.n = n;
    lca.level = (int*)malloc(n * sizeof(int));
    lca.jads = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        lca.jads[i] = (int*)malloc(22 * sizeof(int));
    }
    return lca;
}

void destroyLCA(LCA lca, int n) {
    free(lca.level);
    for (int i = 0; i < n; i++) {
        free(lca.jads[i]);
    }
    free(lca.jads);
}

void preProcess(LCA lca, int root) {
    setLevel(lca, root, root, 0);
    for (int L = 1; (1 << L) <= lca.n; L++) {
        for (int i = 0; i < lca.n; i++) {
            lca.jads[i][L] = lca.jads[lca.jads[i][L - 1]][L - 1];
        }
    }
}

int getMinJad(LCA lca, int u, int v) {
    if (lca.level[u] < lca.level[v]) {
        int temp = u;
        u = v;
        v = temp;
    }
    int len = u - v;
    for (int i = 0; i < 22; i++) {
        if ((len >> i & 1) != 0) {
            u = lca.jads[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = 21; i >= 0; i--) {
        if (lca.jads[u][i] != lca.jads[v][i]) {
            u = lca.jads[u][i];
            v = lca.jads[v][i];
        }
    }
    return lca.jads[u][0];
}

void setLevel(LCA lca, int u, int par, int curLevel) {
    lca.level[u] = curLevel;
    lca.jads[u][0] = par;
    for (int i = 0; i < lca.adj[u].size(); i++) {
        int v = lca.adj[u][i];
        if (v == par) {
            continue;
        }
        setLevel(lca, v, u, curLevel + 1);
    }
}

typedef struct {
    int* tree;
    int maxVal;
} FenwickTree;

FenwickTree createFenwickTree(int n) {
    FenwickTree ft;
    ft.maxVal = n;
    ft.tree = (int*)malloc((n + 1) * sizeof(int));
    return ft;
}

void destroyFenwickTree(FenwickTree ft) {
    free(ft.tree);
}

void update(FenwickTree ft, int idx, int val) {
    idx++;
    while (idx <= ft.maxVal) {
        ft.tree[idx] += val;
        idx += (idx & (-idx));
    }
}

int read(FenwickTree ft, int idx) {
    idx++;
    int sum = 0;
    while (idx > 0) {
        sum += ft.tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int rangeSum(FenwickTree ft, int left, int right) {
    if (left > right) {
        return 0;
    }
    int sumLeft = read(ft, left - 1);
    int sumRight = read(ft, right);
    return sumRight - sumLeft;
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray createIntArray(int size) {
    IntArray ia;
    ia.size = size;
    ia.arr = (int*)malloc(size * sizeof(int));
    return ia;
}

void destroyIntArray(IntArray ia) {
    free(ia.arr);
}

void reverse(IntArray ia) {
    int* temp = (int*)malloc(ia.size * sizeof(int));
    int cnt = 0;
    for (int i = ia.size - 1; i >= 0; i--) {
        temp[cnt++] = ia.arr[i];
    }
    for (int i = 0; i < cnt; i++) {
        ia.arr[i] = temp[i];
    }
    free(temp);
}

void swap(IntArray ia, int a, int b) {
    int temp = ia.arr[a];
    ia.arr[a] = ia.arr[b];
    ia.arr[b] = temp;
}

int* getOrder(IntArray arr) {
    IntArray order = createIntArray(arr.size);
    for (int i = 0; i < arr.size; i++) {
        order.arr[i] = i;
    }
    for (int i = 0; i < arr.size; i++) {
        for (int j = i + 1; j < arr.size; j++) {
            if (arr.arr[order.arr[i]] > arr.arr[order.arr[j]]) {
                swap(order, i, j);
            }
        }
    }
    int* result = (int*)malloc(arr.size * sizeof(int));
    for (int i = 0; i < arr.size; i++) {
        result[i] = order.arr[i];
    }
    destroyIntArray(order);
    return result;
}

int next_permutation(IntArray c) {
    int first = getFirst(c);
    if (first == -1) {
        return 0;
    }
    int toSwap = c.size - 1;
    while (c.arr[first] >= c.arr[toSwap]) {
        --toSwap;
    }
    swap(c, first++, toSwap);
    toSwap = c.size - 1;
    while (first < toSwap) {
        swap(c, first++, toSwap--);
    }
    return 1;
}

int getFirst(IntArray c) {
    for (int i = c.size - 2; i >= 0; --i) {
        if (c.arr[i] < c.arr[i + 1]) {
            return i;
        }
    }
    return -1;
}

int lowerBound(IntArray order, IntArray val, int need) {
    int s = 0;
    int e = order.size;
    while (e - s > 1) {
        int mid = (e + s) / 2;
        if (val.arr[order.arr[mid]] < need) {
            s = mid;
        }
        else {
            e = mid;
        }
    }
    if (val.arr[order.arr[s]] >= need) {
        return s;
    }
    return e;
}

int lowerBound(IntArray val, int need) {
    int s = 0;
    int e = val.size;
    while (e - s > 1) {
        int mid = (e + s) / 2;
        if (val.arr[mid] < need) {
            s = mid;
        }
        else {
            e = mid;
        }
    }
    if (val.arr[s] >= need) {
        return s;
    }
    return e;
}

int main() {
    // Your code here
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MOD ((int)(1e9 + 7))
#define MAX 1000000

typedef struct {
    int a;
    int b;
} Pair;

typedef struct {
    int a;
    int b;
    int c;
} Triplet;

typedef struct {
    long *arr;
    long *tree;
    int size;
} SegmentTree;

long gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long lcm(long a, long b) {
    return a * (b / gcd(a, b));
}

void swap(int *arr, int left, int right) {
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

void reverse(int *arr, int size) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        swap(arr, left, right);
        left++;
        right--;
    }
}

void buildTree(SegmentTree *st, int s, int e, int index) {
    if (s == e) {
        st->tree[index] = st->arr[s];
        return;
    }
    int mid = (s + e) / 2;
    buildTree(st, s, mid, 2 * index);
    buildTree(st, mid + 1, e, 2 * index + 1);
    st->tree[index] = fmin(st->tree[2 * index], st->tree[2 * index + 1]);
}

long query(SegmentTree *st, int s, int e, int qs, int qe, int index) {
    if (s >= qs && e <= qe) {
        return st->tree[index];
    }
    if (qe < s || qs > e) {
        return LONG_MAX;
    }
    int mid = (s + e) / 2;
    long left = query(st, s, mid, qs, qe, 2 * index);
    long right = query(st, mid + 1, e, qs, qe, 2 * index + 1);
    return fmin(left, right);
}

void updateNode(SegmentTree *st, int s, int e, int i, long increment, int index) {
    if (i < s || i > e) {
        return;
    }
    if (s == e) {
        st->tree[index] += increment;
        return;
    }
    int mid = (s + e) / 2;
    updateNode(st, s, mid, i, increment, 2 * index);
    updateNode(st, mid + 1, e, i, increment, 2 * index + 1);
    st->tree[index] = fmin(st->tree[2 * index], st->tree[2 * index + 1]);
}

void updateRange(SegmentTree *st, int s, int e, int l, int r, long increment, int index) {
    if (l > e || r < s) {
        return;
    }
    if (s == e) {
        st->tree[index] += increment;
    }
    int mid = (s + e) / 2;
    updateRange(st, s, mid, l, r, increment, 2 * index);
    updateRange(st, mid + 1, e, l, r, increment, 2 * index);
    st->tree[index] = fmin(st->tree[2 * index], st->tree[2 * index + 1]);
}

int main() {
    char str[100];
    scanf("%s", str);
    int n = strlen(str);
    char *pos[] = {"00", "25", "50", "75"};
    int count = 0;

    if (n == 1) {
        if (str[0] == '0' || str[0] == 'X' || str[0] == '_') count++;
    } else {
        for (int j = 0; j < 4; j++) {
            char *cstr = pos[j];
            int X = -1;
            int idx = 0;
            bool possible = true;
            for (int i = n - 2; i < n; i++) {
                char curr = str[i];
                char strcurr = cstr[idx++];
                if (curr == '_') continue;
                else if (curr == 'X') {
                    if (X == -1) {
                        X = (strcurr - '0');
                    } else {
                        if (X != strcurr - '0') {
                            possible = false;
                            break;
                        }
                    }
                } else {
                    if (curr != strcurr) {
                        possible = false;
                        break;
                    }
                }
            }
            if (!possible) continue;

            if (n == 2) {
                if (cstr[0] == '0') continue;
                count++;
                continue;
            }

            char ninp[100];
            strcpy(ninp, str);
            int cntX = 0;
            for (int k = 0; k < n; k++) {
                if (str[k] == 'X') cntX++;
            }

            if (X != -1 || cntX == 0) {
                if (X != -1) {
                    for (int k = 0; k < n; k++) {
                        ninp[k] = (str[k] == 'X') ? (char)(X + '0') : str[k];
                    }
                }
                if (ninp[0] == '0') continue;
                int counter = 1;
                for (int k = 0; k < n - 2; k++) {
                    if (ninp[k] == '_') {
                        counter *= (k == 0) ? 9 : 10;
                    }
                }
                count += counter;
            } else {
                if (ninp[0] == '0') continue;
                int counter = 1;
                for (int k = 0; k < n - 2; k++) {
                    if (ninp[k] == '_') {
                        counter *= (k == 0) ? 9 : 10;
                    }
                }
                counter *= (ninp[0] == 'X') ? 9 : 10;
                count += counter;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}

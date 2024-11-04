#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    bool state;
    int l, r;
    int ll, rr;
} Node;

typedef struct Seg {
    int l, r;
    int min;
    struct Seg* left;
    struct Seg* right;
    long sum;
    long cnt;
} Seg;

Seg* createSeg(int l, int r) {
    Seg* seg = (Seg*)malloc(sizeof(Seg));
    seg->l = l;
    seg->r = r;
    seg->min = INT_MAX;
    seg->left = NULL;
    seg->right = NULL;
    seg->sum = 0;
    seg->cnt = 0;
    return seg;
}

long* query(Seg* seg, int s, int e) {
    if (seg->l == s && seg->r == e) {
        long* res = (long*)malloc(2 * sizeof(long));
        res[0] = seg->sum;
        res[1] = seg->cnt;
        return res;
    }
    int mid = seg->l + (seg->r - seg->l) / 2;

    if (seg->left == NULL) {
        seg->left = createSeg(seg->l, mid);
    }
    if (seg->right == NULL) {
        seg->right = createSeg(mid + 1, seg->r);
    }

    if (e <= mid) {
        return query(seg->left, s, e);
    }
    else if (s >= mid + 1) {
        return query(seg->right, s, e);
    }
    else {
        long* A = query(seg->left, s, mid);
        long* B = query(seg->right, mid + 1, e);
        long* res = (long*)malloc(2 * sizeof(long));
        res[0] = A[0] + B[0];
        res[1] = A[1] + B[1];
        free(A);
        free(B);
        return res;
    }
}

void update(Seg* seg, int index, int v) {
    seg->sum += v;
    seg->cnt++;
    if (seg->l == seg->r && seg->l == index) {
        return;
    }
    int mid = seg->l + (seg->r - seg->l) / 2;
    if (index <= mid) {
        if (seg->left == NULL) {
            seg->left = createSeg(seg->l, mid);
        }
        update(seg->left, index, v);
    }
    else {
        if (seg->right == NULL) {
            seg->right = createSeg(mid + 1, seg->r);
        }
        update(seg->right, index, v);
    }
}

int main() {
    int T = 1;
    for (int t = 0; t < T; t++) {
        int K = Int();
        long F[6];
        for (int i = 0; i < 6; i++) {
            F[i] = Int();
        }

        int q = Int();
        int W = Int();

        solution(K, F, W);
    }

    return 0;
}

void solution(int K, long F[], int W) {
    long res = 0;
    int ten[] = { 1,10,100,1000,10000,100000 };

    Seg* A = createSeg(0, 0);

    K--;

    if (K == 0) {
        char num[10];
        sprintf(num, "%d", W);
        int len = strlen(num);
        for (int k = 0; k < len; k++) {
            int d = num[k] - '0';
            if (d % 3 == 0) {
                res += (F[k] * (d / 3));
            }
        }
        printf("%ld\n", res);
        return;
    }

    for (int i = 0; i < 6; i++) {
        long weight = ten[i] * 3;

        int cur = 0;
        for (int j = 0; j < 32; j++) {
            int go = 1 << j;
            if (cur + go >= (3 * K)) {
                long remain = 3 * K - cur;
                update(A, weight * remain, F[i] * remain);
                break;
            }
            update(A, weight * (1 << j), F[i] * (1 << j));
            cur += (1 << j);
        }
    }

    long pre[W + 1];
    long dp[W + 1];
    memset(pre, -1, sizeof(pre));
    pre[0] = 0;

    for (int i = 1; i < A->cnt; i++) {
        Seg* item = query(A, i, i);
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for (int j = 1; j < W + 1; j++) {
            dp[j] = max(dp[j], pre[j]);
            long w = item->sum;
            long val = item->cnt;
            if (j < w || pre[j - w] == -1) {
                continue;
            }
            dp[j] = max(dp[j], pre[j - w] + val);
            char num[10];
            sprintf(num, "%d", W - j);
            int len = strlen(num);
            long score = 0;
            for (int k = 0; k < len; k++) {
                int d = num[k] - '0';
                if (d % 3 == 0) {
                    score += (F[k] * (d / 3));
                }
            }
            res = max(res, dp[j] + score);
        }
        memcpy(pre, dp, sizeof(dp));
    }

    printf("%ld\n", res);
}

int Int() {
    int num;
    scanf("%d", &num);
    return num;
}

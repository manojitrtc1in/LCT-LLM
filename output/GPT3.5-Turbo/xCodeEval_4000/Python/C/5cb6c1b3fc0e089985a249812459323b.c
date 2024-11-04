#include <stdio.h>
#include <stdlib.h>

int binarySearchCount(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;
    int count = 0;

    while (left <= right) {
        int mid = (right + left) / 2;

        if (arr[mid] <= key) {
            count = mid + 1;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return count;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int *l = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
        l[i] %= k;
    }

    if (n == 1) {
        printf("%d\n", l[0]);
        return 0;
    }

    int *l1 = (int *)malloc((n / 2) * sizeof(int));
    int *l2 = (int *)malloc((n - n / 2) * sizeof(int));
    for (int i = 0; i < n / 2; i++) {
        l1[i] = l[i];
    }
    for (int i = 0; i < n - n / 2; i++) {
        l2[i] = l[n / 2 + i];
    }

    int *s = (int *)malloc((1 << (n / 2)) * sizeof(int));
    int *s1 = (int *)malloc((1 << (n - n / 2)) * sizeof(int));
    int *s2 = (int *)malloc((1 << (n - n / 2)) * sizeof(int));
    int s_size = 0;
    int s1_size = 0;
    int s2_size = 0;

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < s_size; j++) {
            s2[s2_size++] = (s[j] + l1[i]) % k;
        }
        s[s_size++] = l1[i];
        for (int j = 0; j < s2_size; j++) {
            s[s_size++] = s2[j];
        }
        s2_size = 0;
    }

    for (int i = 0; i < n - n / 2; i++) {
        for (int j = 0; j < s1_size; j++) {
            s2[s2_size++] = (s1[j] + l2[i]) % k;
        }
        s1[s1_size++] = l2[i];
        for (int j = 0; j < s2_size; j++) {
            s1[s1_size++] = s2[j];
        }
        s2_size = 0;
    }

    for (int i = 0; i < s_size; i++) {
        for (int j = 0; j < s1_size; j++) {
            int t = k - 1 - s[i];
            int ind = binarySearchCount(s1, s1_size, t);
            int r = s1[ind - 1];
            int rt = s1[s1_size - 1];
            int t = ans;
            ans = max((r + s[i]) % k, (s[i] + rt) % k);
            ans = max(ans, t);
        }
    }

    printf("%d\n", ans);

    free(l);
    free(l1);
    free(l2);
    free(s);
    free(s1);
    free(s2);

    return 0;
}

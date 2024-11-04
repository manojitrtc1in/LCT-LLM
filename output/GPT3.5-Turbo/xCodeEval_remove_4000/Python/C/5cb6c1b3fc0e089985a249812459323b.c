#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;
    int count = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] <= key) {
            count = mid + 1;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return count;
}

int countGreater(int arr[], int n, int k) {
    int left = 0;
    int right = n - 1;
    int leftGreater = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] >= k) {
            leftGreater = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return (n - leftGreater);
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

    for (int i = n / 2; i < n; i++) {
        l2[i - n / 2] = l[i];
    }

    int *s = (int *)malloc((1 << (n / 2)) * sizeof(int));
    int *s1 = (int *)malloc((1 << (n - n / 2)) * sizeof(int));
    int *s2 = (int *)malloc((1 << (n - n / 2)) * sizeof(int));

    int sSize = 0;
    int s1Size = 0;
    int s2Size = 0;

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < sSize; j++) {
            s2[j] = (s[j] + l1[i]) % k;
        }

        for (int j = 0; j < sSize; j++) {
            s[j] = (s[j] + l1[i]) % k;
        }

        for (int j = 0; j < s2Size; j++) {
            s[j + sSize] = s2[j];
        }

        sSize += s2Size;
        s2Size = 0;
    }

    for (int i = 0; i < n - n / 2; i++) {
        for (int j = 0; j < s1Size; j++) {
            s2[j] = (s1[j] + l2[i]) % k;
        }

        for (int j = 0; j < s1Size; j++) {
            s1[j] = (s1[j] + l2[i]) % k;
        }

        for (int j = 0; j < s2Size; j++) {
            s1[j + s1Size] = s2[j];
        }

        s1Size += s2Size;
        s2Size = 0;
    }

    int ans = 0;
    for (int i = 0; i < sSize; i++) {
        int t = k - 1 - s[i];
        int ind = binarySearch(s1, s1Size, t);
        int r = s1[ind - 1];
        int rt = s1[s1Size - 1];
        int temp = ans;
        ans = (r + s[i]) % k;
        ans = (s[i] + rt) % k;
        ans = (ans > temp) ? ans : temp;
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

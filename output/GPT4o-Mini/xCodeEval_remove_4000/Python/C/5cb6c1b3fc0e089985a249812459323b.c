#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

int id9(int arr[], int n, int key) {
    int left = 0, right = n - 1, count = 0;

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
    int l[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
        l[i] %= k;
    }

    if (n == 1) {
        printf("%d\n", l[0]);
        return 0;
    }

    int l1[MAX_SIZE], l2[MAX_SIZE];
    int size1 = n / 2, size2 = n - size1;
    for (int i = 0; i < size1; i++) {
        l1[i] = l[i];
    }
    for (int i = 0; i < size2; i++) {
        l2[i] = l[size1 + i];
    }

    int s[MAX_SIZE] = {0}, s1[MAX_SIZE] = {0}, s2[MAX_SIZE] = {0};
    int s_count = 0, s1_count = 0;

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < s_count; j++) {
            s2[s1_count++] = (s[j] + l1[i]) % k;
        }
        s[s_count++] = l1[i];
        for (int j = 0; j < s1_count; j++) {
            s[s_count++] = s2[j];
        }
        s1_count = 0;
    }

    for (int i = 0; i < size2; i++) {
        for (int j = 0; j < s1_count; j++) {
            s2[s1_count++] = (s1[j] + l2[i]) % k;
        }
        s1[s1_count++] = l2[i];
        for (int j = 0; j < s1_count; j++) {
            s1[s1_count++] = s2[j];
        }
        s1_count = 0;
    }

    int ans = 0;
    for (int i = 0; i < s_count; i++) {
        for (int j = 0; j < s1_count; j++) {
            int t = k - 1 - s[i];
            int ind = id9(s1, s1_count, t);
            int r = s1[ind - 1];
            int rt = s1[s1_count - 1];
            ans = (ans > (r + s[i]) % k) ? ans : (r + s[i]) % k;
            ans = (ans > (s[i] + rt) % k) ? ans : (s[i] + rt) % k;
        }
    }

    printf("%d\n", ans);
    return 0;
}

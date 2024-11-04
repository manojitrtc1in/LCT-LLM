#include <stdio.h>
#include <stdlib.h>

#define MAX_N 4

int board[MAX_N][MAX_N];
int sum = 0;
int n;
int nums[MAX_N * MAX_N];
int num_count[MAX_N * MAX_N];

void go(int num, int i, int j);
void backtrack(int i, int j);

void go(int num, int i, int j) {
    if (num_count[num] == 0) return;
    int under = -1;
    if (i == 2) {
        under = sum - board[0][j] - board[1][j] - num;
        if (under == num) {
            if (num_count[num] < 2) return;
            num_count[num]--;
        } else {
            if (num_count[under] == 0) return;
            num_count[under]--;
        }
        board[3][j] = under;
    }
    num_count[num]--;
    board[i][j] = num;
    if (j == 3)
        backtrack(i + 1, 0);
    else
        backtrack(i, j + 1);
    num_count[num]++;
    if (i == 2) {
        num_count[under]++;
    }
}

void backtrack(int i, int j) {
    if (i == 3 && j == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%2d%c", board[i][j], j == n - 1 ? '\n' : ' ');
            }
        }
        exit(0);
    }
    if (j == 3) {
        int s = sum;
        for (int x = 0; x < 3; x++) {
            s -= board[i][x];
        }
        go(s, i, j);
        return;
    }
    if (i == 3) {
        int s = sum;
        for (int x = 0; x < 3; x++) {
            s -= board[x][j];
        }
        go(s, i, j);
        return;
    }
    if (i == 2 && j == 1) {
        go(board[0][0] + board[1][0] + board[2][0] - board[1][2] - board[0][3], i, j);
        return;
    }
    if (i == 2 && j == 2) {
        int o = board[0][3] + board[1][3] + sum - board[2][0] - board[2][1] - board[0][0] - board[1][1];
        if (o % 2 == 0)
            go(o / 2, i, j);
        return;
    }
    if (i == 1 && j == 0) {
        for (int x = 0; x < MAX_N * MAX_N; x++) {
            if (nums[x] > board[0][1])
                break;
            go(nums[x], i, j);
        }
        return;
    }
    for (int x = 0; x < MAX_N * MAX_N; x++)
        go(nums[x], i, j);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n * n; i++) {
        scanf("%d", &nums[i]);
        num_count[nums[i]]++;
        sum += nums[i];
    }
    sum /= n;
    printf("%d\n", sum);
    if (n <= 3) {
        for (int i = 0; i < n * n; i++) {
            for (int j = i + 1; j < n * n; j++) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                int good = 1;
                for (int k = 0; k < n; k++) {
                    int s1 = 0, s2 = 0;
                    for (int l = 0; l < n; l++) {
                        s1 += nums[k * n + l];
                        s2 += nums[l * n + k];
                    }
                    if (s1 != sum || s2 != sum)
                        good = 0;
                }
                int s1 = 0, s2 = 0;
                for (int k = 0; k < n; k++) {
                    s1 += nums[k * n + k];
                    s2 += nums[k * n + n - k - 1];
                }
                if (s1 != sum || s2 != sum)
                    good = 0;
                if (good) {
                    for (int k = 0; k < n * n; k++)
                        printf("%d%c", nums[k], k % n == n - 1 ? '\n' : ' ');
                    return 0;
                }
            }
        }
    }
    backtrack(0, 0);
    return 0;
}

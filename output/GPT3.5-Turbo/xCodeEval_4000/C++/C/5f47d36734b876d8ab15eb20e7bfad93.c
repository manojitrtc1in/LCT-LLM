#include <stdio.h>
#include <stdlib.h>

#define MAX_N 4

int cou[101] = {0};
int sum = 0;
int n;
int board[MAX_N][MAX_N];

void go(int num, int i, int j);
void backtrack(int i, int j) {
  if (i == n && j == 0) {
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
    if (o % 2 == 0) {
      go(o / 2, i, j);
    }
    return;
  }
  if (i == 1 && j == 0) {
    for (int x = 1; x <= 100; x++) {
      if (x > board[0][1]) {
        break;
      }
      go(x, i, j);
    }
    return;
  }
  for (int x = 1; x <= 100; x++) {
    go(x, i, j);
  }
}

void go(int num, int i, int j) {
  if (cou[num] == 0) {
    return;
  }
  cou[num]--;
  board[i][j] = num;
  if (j == 3) {
    backtrack(i + 1, 0);
  } else {
    backtrack(i, j + 1);
  }
  cou[num]++;
}

int main() {
  scanf("%d", &n);
  int nums[MAX_N * MAX_N];
  for (int i = 0; i < n * n; i++) {
    int x;
    scanf("%d", &x);
    cou[x]++;
    sum += x;
    nums[i] = x;
  }
  if (sum % n != 0) {
    printf("No solution\n");
    return 0;
  }
  sum /= n;
  printf("%d\n", sum);
  if (n <= 3) {
    for (int i = 0; i < n * n; i++) {
      for (int j = i + 1; j < n * n; j++) {
        if (nums[i] == nums[j]) {
          printf("No solution\n");
          return 0;
        }
      }
    }
    int found = 0;
    for (int i = 0; i < n * n; i++) {
      board[i / n][i % n] = nums[i];
    }
    do {
      int good = 1;
      for (int i = 0; i < n; i++) {
        int s1 = 0, s2 = 0;
        for (int j = 0; j < n; j++) {
          s1 += board[i][j];
          s2 += board[j][i];
        }
        if (s1 != sum || s2 != sum) {
          good = 0;
          break;
        }
      }
      int s1 = 0, s2 = 0;
      for (int i = 0; i < n; i++) {
        s1 += board[i][i];
        s2 += board[i][n - i - 1];
      }
      if (s1 != sum || s2 != sum) {
        good = 0;
      }
      if (good) {
        found = 1;
        break;
      }
    } while (next_permutation(nums, nums + n * n));
    if (!found) {
      printf("No solution\n");
    } else {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          printf("%2d%c", board[i][j], j == n - 1 ? '\n' : ' ');
        }
      }
    }
  } else {
    backtrack(0, 0);
    printf("No solution\n");
  }
  return 0;
}

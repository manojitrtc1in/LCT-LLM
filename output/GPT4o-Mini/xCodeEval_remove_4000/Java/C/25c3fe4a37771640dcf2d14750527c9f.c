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

long powerMOD(long x, long y) {
    long res = 1;
    while (y > 0) {
        if (y & 1) {
            x %= MOD;
            res = (res * x) % MOD;
        }
        y >>= 1;
        x = (x * x) % MOD;
    }
    return res % MOD;
}

long gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long lcm(long a, long b) {
    return a * (b / gcd(a, b));
}

void swap(int* arr, int left, int right) {
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

void reverse(int* arr, int size) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        swap(arr, left, right);
        left++;
        right--;
    }
}

int main() {
    char str[100];
    scanf("%s", str);
    int n = strlen(str);
    
    char* pos[] = {"00", "25", "50", "75"};
    int count = 0;

    if (n == 1) {
        if (str[0] == '0' || str[0] == 'X' || str[0] == '_') count++;
    } else {
        for (int p = 0; p < 4; p++) {
            char* cstr = pos[p];
            int X = -1, idx = 0;
            bool possible = true;

            for (int i = n - 2; i < n; i++) {
                char curr = str[i];
                char strcurr = cstr[idx++];
                
                if (curr == '_') continue;
                else if (curr == 'X') {
                    if (X == -1) {
                        X = strcurr - '0';
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
            for (int j = 0; j < n; j++) {
                if (str[j] == 'X') cntX++;
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

                if (ninp[0] == 'X') {
                    counter *= 9;
                } else {
                    counter *= 10;
                }

                count += counter;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}

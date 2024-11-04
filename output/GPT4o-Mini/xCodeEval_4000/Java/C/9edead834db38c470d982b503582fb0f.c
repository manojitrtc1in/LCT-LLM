#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MOD ((int)pow(10, 9) + 7)

long mod = MOD;

void factSieve(int *fact, long n) {
    for (int i = 2; i <= n; i += 2)
        fact[i] = 2;

    for (int i = 3; i <= n; i += 2) {
        if (fact[i] == 0) {
            fact[i] = i;
            for (long j = i; j * i <= n; j++) {
                fact[(int)(i * j)] = i;
            }
        }
    }
}

int gcd(int p2, int p22) {
    if (p2 == 0)
        return p22;
    return gcd(p22 % p2, p2);
}

void nextGreater(long *a, int *ans, int length) {
    int *stk = (int *)malloc(length * sizeof(int));
    int top = -1;
    stk[++top] = 0;

    for (int i = 1; i < length; i++) {
        while (top >= 0) {
            int s = stk[top--];
            while (a[s] < a[i]) {
                ans[s] = i;
                if (top >= 0)
                    s = stk[top--];
                else
                    break;
            }
            if (a[s] >= a[i])
                stk[++top] = s;
        }
        stk[++top] = i;
    }
    free(stk);
}

void nextSmaller(long *a, int *ans, int length) {
    int *stk = (int *)malloc(length * sizeof(int));
    int top = -1;
    stk[++top] = 0;

    for (int i = 1; i < length; i++) {
        while (top >= 0) {
            int s = stk[top--];
            while (a[s] > a[i]) {
                ans[s] = i;
                if (top >= 0)
                    s = stk[top--];
                else
                    break;
            }
            if (a[s] <= a[i])
                stk[++top] = s;
        }
        stk[++top] = i;
    }
    free(stk);
}

long lcm(int *numbers, int length) {
    long lcm = 1;
    int divisor = 2;
    while (true) {
        int cnt = 0;
        bool divisible = false;
        for (int i = 0; i < length; i++) {
            if (numbers[i] == 0) {
                return 0;
            } else if (numbers[i] < 0) {
                numbers[i] = -numbers[i];
            }
            if (numbers[i] == 1) {
                cnt++;
            }
            if (numbers[i] % divisor == 0) {
                divisible = true;
                numbers[i] /= divisor;
            }
        }
        if (divisible) {
            lcm *= divisor;
        } else {
            divisor++;
        }
        if (cnt == length) {
            return lcm;
        }
    }
}

long factorial(long n) {
    long factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}

long choose(long total, long choose) {
    if (total < choose)
        return 0;
    if (choose == 0 || choose == total)
        return 1;
    return (choose(total - 1, choose - 1) + choose(total - 1, choose)) % mod;
}

int *shuffle(int *a, int n) {
    for (int i = 0; i < n; i++) {
        int ind = rand() % (n - i) + i;
        int temp = a[ind];
        a[ind] = a[i];
        a[i] = temp;
    }
    return a;
}

int floorSearch(int arr[], int low, int high, int x) {
    if (low > high)
        return -1;

    if (x > arr[high])
        return high;
    int mid = (low + high) / 2;

    if (mid > 0 && arr[mid - 1] < x && x < arr[mid])
        return mid - 1;

    if (x < arr[mid])
        return floorSearch(arr, low, mid - 1, x);

    return floorSearch(arr, mid + 1, high, x);
}

void primeFactorization(int n, int **result, int *size) {
    *size = 0;
    *result = (int *)malloc(n * sizeof(int));
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            (*result)[(*size)++] = i;
            n /= i;
        }
    }
    if (n != 1)
        (*result)[(*size)++] = n;
}

void sieve(bool *isPrime, int n) {
    for (int i = 0; i < n; i++)
        isPrime[i] = true;

    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j < n; j += i)
                isPrime[j] = false;
        }
    }
}

int main() {
    long n;
    int m;
    scanf("%ld %d", &n, &m);
    long *a = (long *)malloc(m * sizeof(long));
    long *b = (long *)malloc(m * sizeof(long));

    for (int i = 0; i < m; i++)
        a[i] = n / m;
    for (int i = 1; i <= n % m; i++)
        a[i]++;

    for (int i = 0; i < m; i++) {
        int t = (i % m * i % m) % m;
        b[t] += a[i];
    }

    long ans = 0;
    for (int i = 0; i < m; i++) {
        if (i == 0) {
            ans += (b[i] * b[i]);
        } else {
            ans += b[i] * b[m - i];
        }
    }

    printf("%ld\n", ans);

    free(a);
    free(b);
    return 0;
}

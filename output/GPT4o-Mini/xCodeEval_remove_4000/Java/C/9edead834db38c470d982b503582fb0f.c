#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MOD ((int)pow(10, 9) + 7)

long modInverse(int A, int M);
long choose(long total, long choose);
long fact(long n);
long GCD(long a, long b);
long LCM(long a, long b);
void sieve(bool *isPrime, int n);
void id13(int *fact, long n);
void nextGreater(long *a, int *ans, int n);
void id7(long *a, int *ans, int n);
void id0(long *a, int *ans, int n);
int floorSearch(int arr[], int low, int high, int x);
int *suffle(int *a, int n);
int *id12(int *a, int n);
int lowerbound(long *net, long c2, int size);
int id3(int *dis, int c2, int size);
int uperbound(int *list, int c2, int size);
int id6(int *dis, int c2, int size);
bool isPrime(int n);
void id9(int A, int B);
int countDer(int n);
long id11(int n, int k);
long id14(long x, long n);
int id10(int x, int n, int M);
int id10(long x, long n, long M);
long sie(long A, long M);
int *id2(int n, int *size);
void swap(int *a, int *b);
void input(int *n, int *m, long *arr);
void output(long ans);

int main() {
    long n;
    int m;
    input(&n, &m, NULL);
    
    long *a = (long *)malloc(m * sizeof(long));
    for (int i = 0; i < m; i++)
        a[i] = n / m;
    for (int i = 1; i <= n % m; i++)
        a[i]++;
    
    long *b = (long *)malloc(m * sizeof(long));
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
    
    output(ans);
    
    free(a);
    free(b);
    return 0;
}

void input(int *n, int *m, long *arr) {
    scanf("%ld %d", n, m);
}

void output(long ans) {
    printf("%ld\n", ans);
}

long GCD(long a, long b) {
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

long LCM(long a, long b) {
    return (a * b) / GCD(a, b);
}

long fact(long n) {
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
    return (choose(total - 1, choose - 1) + choose(total - 1, choose)) % MOD;
}

bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

void id9(int A, int B) {
    // Implementation of Extended Euclidean Algorithm
}

long modInverse(int A, int M) {
    return id10(A, M - 2, M);
}

long sie(long A, long M) {
    return id10(A, M - 2, M);
}

// Other functions can be implemented similarly...

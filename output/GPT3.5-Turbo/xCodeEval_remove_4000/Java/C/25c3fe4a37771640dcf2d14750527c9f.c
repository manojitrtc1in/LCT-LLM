#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100000

int mod = (int) (pow(10, 9) + 7);
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
const int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int dx9[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1}, dy9[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

const double eps = 1e-10;
int primeNumbers[MAX_SIZE];
int primeNumbersSize = 0;

void id1(int n) {
    bool *bitset = (bool *) malloc((n + 1) * sizeof(bool));
    memset(bitset, true, (n + 1) * sizeof(bool));

    for (long i = 0; i < n; i++) {
        if (i == 0 || i == 1) {
            bitset[i] = true;
            continue;
        }
        if (bitset[i]) continue;
        primeNumbers[primeNumbersSize++] = i;
        for (long j = i; j <= n; j += i)
            bitset[j] = true;
    }

    free(bitset);
}

int id4(long number) {
    if (number == 1) return 1;
    int primeFactors[MAX_SIZE];
    int primeFactorsSize = 0;
    int index = 0;
    long curr = primeNumbers[index];
    while (curr * curr <= number) {
        while (number % curr == 0) {
            number = number / curr;
            primeFactors[primeFactorsSize++] = curr;
        }
        index++;
        curr = primeNumbers[index];
    }

    if (number != 1) primeFactors[primeFactorsSize++] = number;
    int current = primeFactors[0];
    int id8 = 1;
    int currentCount = 2;
    for (int i = 1; i < primeFactorsSize; i++) {
        if (primeFactors[i] == current) {
            currentCount++;
        } else {
            id8 *= currentCount;
            currentCount = 2;
            current = primeFactors[i];
        }
    }
    id8 *= currentCount;
    return id8;
}

int id10(int n) {
    if (n <= 1)
        return 0;
    int sqrt = (int) sqrt(n);
    int remainingNumber = n;
    int result = 0;
    for (int i = 2; i <= sqrt; i++) {
        while (remainingNumber % i == 0) {
            result++;
            remainingNumber /= i;
        }
    }

    if (remainingNumber > 1) {
        result++;
    }
    return result;
}

bool id6(int *p, int size) {
    for (int a = size - 2; a >= 0; --a)
        if (p[a] < p[a + 1])
            for (int b = size - 1;; --b)
                if (p[b] > p[a]) {
                    int t = p[a];
                    p[a] = p[b];
                    p[b] = t;
                    for (++a, b = size - 1; a < b; ++a, --b) {
                        t = p[a];
                        p[a] = p[b];
                        p[b] = t;
                    }
                    return true;
                }
    return false;
}

long id5(int n, int r) {
    long p = 1, k = 1;
    if (n - r < r) r = n - r;

    if (r != 0) {
        while (r > 0) {
            p *= n;
            k *= r;
            long m = id9(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    } else {
        p = 1;
    }
    return p;
}

bool id3(char c) {
    return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' ||
            c == 'u' || c == 'U');
}

void sort(int *a, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void sort(long *a, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i] > a[j]) {
                long temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int id7(int n, int k) {
    int C[k + 1];

    C[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = (i < k ? i : k); j > 0; j--)
            C[j] = C[j] + C[j - 1];
    }
    return C[k];
}

typedef struct {
    int a;
    int b;
    int hashCode;
} Pair;

Pair newPair(int a, int b) {
    Pair pair;
    pair.a = a;
    pair.b = b;
    pair.hashCode = a ^ b;
    return pair;
}

typedef struct {
    int a;
    int b;
    int c;
} Triplet;

Triplet newTriplet(int a, int b, int c) {
    Triplet triplet;
    triplet.a = a;
    triplet.b = b;
    triplet.c = c;
    return triplet;
}

long lcm(long a, long b) {
    return a * (b / gcd(a, b));
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int gcd(int a, int b) {
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

long gcd(long a, long b) {
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

long id9(long n1, long n2) {
    long gcd = 1;
    for (int i = 1; i <= n1 && i <= n2; ++i) {
        if (n1 % i == 0 && n2 % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}

void swap(int *arr, int left, int right) {
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

void swap(char *arr, int left, int right) {
    char temp = arr[left];
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

long expo(long a, long b, long mod) {
    long res = 1;
    while (b > 0) {
        if ((b & 1) == 1L) res = (res * a) % mod;

        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}

long id2(long a, long b) {
    return expo(a, b - 2, b);
}

long mod_add(long a, long b, long m) {
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}

long mod_sub(long a, long b, long m) {
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}

long mod_mul(long a, long b, long m) {
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}

long mod_div(long a, long b, long m) {
    a = a % m;
    b = b % m;
    return (mod_mul(a, id2(b, m), m) + m) % m;
}

long nCr(long N, long K, long mod, long *fact, long *ifact) {
    long val1 = fact[N];
    long val2 = ifact[N - K];
    long val3 = ifact[K];
    return (((val1 * val2) % mod) * val3) % mod;
}

void combination(long n, long r, long m, long *fact, long *ifact, long *result) {
    long val1 = fact[n];
    long val2 = ifact[n - r];
    long val3 = ifact[r];
    *result = (((val1 * val2) % m) * val3) % m;
}

void buildFact(int n, long m, long *fact, long *ifact) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % m;
    }

    ifact[n] = id2(fact[n], m);
    for (int i = n - 1; i >= 0; i--) {
        ifact[i] = (ifact[i + 1] * (i + 1)) % m;
    }
}

void solve() {
    char str[MAX_SIZE];
    scanf("%s", str);
    int n = strlen(str);

    char pos[4][3] = {"00", "25", "50", "75"};
    int count = 0;

    if (n == 1) {
        if (str[0] == '0' || str[0] == 'X' || str[0] == '_') count++;
    } else {
        for (int i = 0; i < 4; i++) {
            int X = -1;

            int idx = 0;
            bool possible = true;
            for (int j = n - 2; j < n; j++) {
                char curr = str[j];
                char strcurr = pos[i][idx];
                idx++;

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
                if (pos[i][0] == '0') continue;

                count++;
                continue;
            }

            char ninp[MAX_SIZE];
            strcpy(ninp, str);

            int cntX = 0;
            for (int k = 0; k < n; k++) {
                if (ninp[k] == 'X') cntX++;
            }

            if (X != -1 || cntX == 0) {
                if (X != -1) {
                    for (int k = 0; k < n; k++) {
                        ninp[k] = inp[k] == 'X' ? (char) (X + '0') : inp[k];
                    }
                }

                if (ninp[0] == '0') continue;
                int counter = 1;
                for (int k = 0; k < n - 2; k++) {
                    if (ninp[k] == '_') {
                        if (k == 0) {
                            counter = counter * 9;
                        } else {
                            counter = counter * 10;
                        }
                    }
                }

                count += counter;
            } else {
                if (ninp[0] == '0') continue;

                int counter = 1;
                for (int k = 0; k < n - 2; k++) {
                    if (ninp[k] == '_') {
                        if (k == 0) {
                            counter = counter * 9;
                        } else {
                            counter = counter * 10;
                        }
                    }
                }

                if (ninp[0] == 'X') {
                    counter = counter * 9;
                } else {
                    counter = counter * 10;
                }

                count += counter;
            }
        }
    }

    printf("%d\n", count);
}

int main() {
    id1(MAX_SIZE);

    solve();

    return 0;
}

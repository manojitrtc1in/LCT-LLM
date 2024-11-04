#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define mod (int)pow(10, 9) + 7

int n;
int m;
int a[105][105][105];
char st[105][105];

void id13(int fact[], long n) {
    for (int i = 2; i <= n; i += 2)
        fact[i] = 2;

    for (int i = 3; i <= n; i += 2) {
        if (fact[i] == 0) {
            fact[i] = i;

            for (int j = i; (long) j * i <= n; j++) {
                fact[(int) ((long) i * j)] = i;
            }
        }
    }
}

int gcd(int p2, int p22) {
    if (p2 == 0)
        return (int) p22;
    return gcd(p22 % p2, p2);
}

void nextGreater(long a[], int ans[]) {
    int n = sizeof(a) / sizeof(a[0]);
    int stk[n];
    int top = -1;

    stk[++top] = 0;

    for (int i = 1; i < n; i++) {
        if (top != -1) {
            int s = stk[top--];
            while (a[s] < a[i]) {
                ans[s] = i;
                if (top != -1)
                    s = stk[top--];
                else
                    break;
            }
            if (a[s] >= a[i])
                stk[++top] = s;
        }

        stk[++top] = i;
    }
}

void id7(long a[], int ans[]) {
    int n = sizeof(a) / sizeof(a[0]);
    int pans[n];
    for (int i = 0; i < n; i++)
        pans[i] = -1;
    long arev[n];
    for (int i = 0; i < n; i++)
        arev[i] = a[n - 1 - i];

    int stk[n];
    int top = -1;

    stk[++top] = 0;

    for (int i = 1; i < n; i++) {
        if (top != -1) {
            int s = stk[top--];
            while (arev[s] < arev[i]) {
                pans[s] = n - i - 1;
                if (top != -1)
                    s = stk[top--];
                else
                    break;
            }
            if (arev[s] >= arev[i])
                stk[++top] = s;
        }

        stk[++top] = i;
    }

    for (int i = 0; i < n; i++)
        ans[i] = pans[n - i - 1];
}

void id0(long a[], int ans[]) {
    int n = sizeof(a) / sizeof(a[0]);
    int stk[n];
    int top = -1;

    stk[++top] = 0;

    for (int i = 1; i < n; i++) {
        if (top != -1) {
            int s = stk[top--];
            while (a[s] > a[i]) {
                ans[s] = i;
                if (top != -1)
                    s = stk[top--];
                else
                    break;
            }
            if (a[s] <= a[i])
                stk[++top] = s;
        }

        stk[++top] = i;
    }
}

long lcm(int numbers[]) {
    long lcm = 1;
    int divisor = 2;
    while (1) {
        int cnt = 0;
        int divisible = 0;
        for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
            if (numbers[i] == 0) {
                return 0;
            } else if (numbers[i] < 0) {
                numbers[i] = numbers[i] * (-1);
            }
            if (numbers[i] == 1) {
                cnt++;
            }
            if (numbers[i] % divisor == 0) {
                divisible = 1;
                numbers[i] = numbers[i] / divisor;
            }
        }
        if (divisible) {
            lcm = lcm * divisor;
        } else {
            divisor++;
        }
        if (cnt == sizeof(numbers) / sizeof(numbers[0])) {
            return lcm;
        }
    }
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
    return (choose(total - 1, choose - 1) + choose(total - 1, choose)) % mod;
}

int suffle(int a[], int n) {
    int gen = 0;
    for (int i = 0; i < n; i++) {
        int ind = gen % (n - i) + i;
        int temp = a[ind];
        a[ind] = a[i];
        a[i] = temp;
    }
    return a;
}

int id12(int a[]) {
    int n = sizeof(a) / sizeof(a[0]);
    int gen = 0;
    for (int i = 0; i < n; i++) {
        int ind = gen % (n - i) + i;
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

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void id2(int n, int a[]) {
    int gen = 0;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            a[gen++] = i;
            n /= i;
        }
    }
    if (n != 1)
        a[gen++] = n;
}

void sieve(int isPrime[], int n) {
    for (int i = 1; i < n; i++)
        isPrime[i] = 1;

    isPrime[0] = 0;
    isPrime[1] = 0;

    for (int i = 2; i * i < n; i++) {
        if (isPrime[i] == 1) {
            for (int j = (2 * i); j < n; j += i)
                isPrime[j] = 0;
        }
    }
}

int lowerbound(int net[], long c2) {
    int n = sizeof(net) / sizeof(net[0]);
    int i = 0;
    while (i < n && net[i] < c2)
        i++;
    return i;
}

int id3(int dis[], int c2) {
    int n = sizeof(dis) / sizeof(dis[0]);
    int i = 0;
    while (i < n && dis[i] < c2)
        i++;
    return i;
}

int uperbound(int list[], int c2) {
    int n = sizeof(list) / sizeof(list[0]);
    int i = 0;
    while (i < n && list[i] <= c2)
        i++;
    return i;
}

int id6(int dis[], int c2) {
    int n = sizeof(dis) / sizeof(dis[0]);
    int i = 0;
    while (i < n && dis[i] <= c2)
        i++;
    return i;
}

int GCD(int a, int b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

long GCD(long a, long b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

int d1;
int p1;
int q1;

void id9(int A, int B) {
    if (B == 0) {
        d1 = A;
        p1 = 1;
        q1 = 0;
    } else {
        id9(B, A % B);
        int temp = p1;
        p1 = q1;
        q1 = temp - (A / B) * q1;
    }
}

long LCM(long a, long b) {
    return (a * b) / GCD(a, b);
}

int LCM(int a, int b) {
    return (a * b) / GCD(a, b);
}

int id14(int x, int n) {
    int result = 1;
    while (n > 0) {
        if (n % 2 == 1)
            result = result * x;
        x = x * x;
        n = n / 2;
    }
    return result;
}

int countDer(int n) {
    int der[n + 1];

    der[0] = 1;
    der[1] = 0;
    der[2] = 1;

    for (int i = 3; i <= n; ++i)
        der[i] = (i - 1) * (der[i - 1] + der[i - 2]);

    return der;
}

long id11(int n, int k) {
    long C[n + 1][k + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    return C[n][k];
}

long id14(long x, long n) {
    long result = 1;
    while (n > 0) {
        if (n % 2 == 1)
            result = result * x;
        x = (x % mod * x % mod) % mod;
        n = n / 2;
    }
    return result;
}

int id10(int x, int n, int M) {
    int result = 1;
    while (n > 0) {
        if (n % 2 == 1)
            result = (result * x) % M;
        x = (x * x) % M;
        n = n / 2;
    }
    return result;
}

long id10(long x, long n, long M) {
    long result = 1;
    while (n > 0) {
        if (n % 2 == 1)
            result = (result * x) % M;
        x = (x * x) % M;
        n = n / 2;
    }
    return result;
}

int modInverse(int A, int M) {
    return id10(A, M - 2, M);
}

long sie(long A, long M) {
    return id10(A, M - 2, M);
}

int isPrime(int n) {
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 1;

    if (n % 2 == 0 || n % 3 == 0)
        return 0;

    for (int i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }

    return 1;
}

typedef struct {
    int x, y;
} pair;

int compare(const void *a, const void *b) {
    pair *p1 = (pair *) a;
    pair *p2 = (pair *) b;
    if (p1->x == p2->x)
        return p1->y - p2->y;
    return p1->x - p2->x;
}

typedef struct {
    int x, y, z;
} triplet;

int compare(const void *a, const void *b) {
    triplet *p1 = (triplet *) a;
    triplet *p2 = (triplet *) b;
    if (p1->x == p2->x) {
        if (p1->y == p2->y)
            return p1->z - p2->z;
        return p1->y - p2->y;
    }
    return p1->x - p2->x;
}

int main() {
    int mod = (int) pow(10, 9) + 7;
    int n;
    int m;
    int a[105][105][105];
    char st[105][105];

    long n = in.nextLong();
    int m = in.nextInt();
    long a[m];

    for (int i = 0; i < m; i++)
        a[i] = n / m;
    for (int i = 1; i <= n % m; i++)
        a[i]++;

    long b[m];
    for (int i = 0; i < m; i++) {
        int t = ((i) % m * (i) % m) % m;
        b[t] += a[i];
    }
    long ans = 0;
    for (int i = 0; i < m; i++) {

        if (i == 0) {
            ans += (b[i] * (b[i]));

        } else {
            ans += b[i] * b[m - i];
        }

    }
    printf("%ld\n", ans);

    return 0;
}

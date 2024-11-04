#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MOD 1000000007
#define MAX 200000

typedef struct {
    int idx;
    int val;
} Pair;

long count = 0;
long ans = 0;
int ts[MAX][MAX];
bool visited[MAX];
int par[MAX];
int *adj[MAX];

void dfs(int start, int root) {
    visited[start] = true;
    par[start] = root;
    for (int i = 0; i < MAX; i++) {
        if (adj[start][i] && !visited[i]) {
            dfs(i, start);
        }
    }
}

void soln() {
    int a, b, x, y, z;
    scanf("%d %d %d %d %d", &a, &b, &x, &y, &z);
    
    if ((long)a < 2 * (long)x) {
        ans += 2 * (long)x - a;
        a = 0;
    } else {
        a -= 2 * x;
    }
    
    if ((long)b < 3 * (long)z) {
        ans += 3 * (long)z - b;
        b = 0;
    } else {
        b -= 3 * z;
    }
    
    if (a < b) {
        y = (y - a > 0) ? y - a : 0;
        b -= a;
        a = 0;
    } else {
        y = (y - b > 0) ? y - b : 0;
        b = a - b;
        a = 0;
    }
    
    if (y > b) {
        ans += b + 2 * (y - b);
    } else {
        ans += y;
    }
    
    printf("%ld\n", ans);
}

int bfsPair(int arr[MAX][MAX], bool visited[MAX][MAX], int x1, int y1, int x2, int y2) {
    Pair q[MAX];
    int front = 0, rear = 0;
    visited[x1][y1] = true;
    int level = 1;
    int increamenter = 0;

    if (x1 - 1 >= 0 && arr[x1 - 1][y1] == 1) increamenter++;
    if (y1 - 1 >= 0 && arr[x1][y1 - 1] == 1) increamenter++;
    if (y1 + 1 < MAX && arr[x1][y1 + 1] == 1) increamenter++;
    if (x1 + 1 < MAX && arr[x1 + 1][y1] == 1) increamenter++;

    q[rear++] = (Pair){x1, y1};
    int i = 0;

    while (front < rear) {
        Pair p = q[front++];
        int x = p.idx, y = p.val;

        if (x - 1 >= 0 && y >= 0 && x - 1 < MAX && y < MAX) {
            if (!visited[x - 1][y] && arr[x - 1][y] == 1) {
                q[rear++] = (Pair){x - 1, y};
                visited[x - 1][y] = true;
            }
        }
        if (x >= 0 && y - 1 >= 0 && x < MAX && y - 1 < MAX) {
            if (!visited[x][y - 1] && arr[x][y - 1] == 1) {
                q[rear++] = (Pair){x, y - 1};
                visited[x][y - 1] = true;
            }
        }
        if (x >= 0 && y + 1 >= 0 && x < MAX && y + 1 < MAX) {
            if (!visited[x][y + 1] && arr[x][y + 1] == 1) {
                q[rear++] = (Pair){x, y + 1};
                visited[x][y + 1] = true;
            }
        }
        if (x + 1 >= 0 && y >= 0 && x + 1 < MAX && y < MAX) {
            if (!visited[x + 1][y] && arr[x + 1][y] == 1) {
                q[rear++] = (Pair){x + 1, y};
                visited[x + 1][y] = true;
            }
        }
        if (x == x2 && y == y2) return level;

        if (increamenter == 0) {
            level++;
            increamenter = rear - front;
        }
        increamenter--;
    }
    return -1;
}

void bfs(int gp[MAX][MAX], int s, bool visited[MAX], int dist[MAX]) {
    int qu[MAX];
    int front = 0, rear = 0;
    int level = 1;
    int increamenter;

    if (gp[s] != NULL) {
        increamenter = gp[s][0] + 1;
    } else return;

    visited[s] = true;
    qu[rear++] = s;

    while (front < rear) {
        int temp = qu[front++];

        increamenter--;
        dist[temp] = level * 6;

        for (int i = 0; i < gp[temp][0]; i++) {
            if (!visited[gp[temp][i]]) {
                visited[gp[temp][i]] = true;
                qu[rear++] = gp[temp][i];
            }
        }
        if (increamenter == 0) {
            level++;
            increamenter = rear - front;
        }
    }
}

int maxSubArraySum(int a[], int size) {
    int max_so_far = -2147483648, max_ending_here = 0;

    for (int i = 0; i < size; i++) {
        max_ending_here += a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

void allprime(int n, int arr[]) {
    arr[0] = 2;
    int count = 1;
    for (int i = 3; i < n; i += 2) {
        bool flag = false;
        for (int j = 0; j < count; j++) {
            if (i % arr[j] == 0) {
                flag = true;
                break;
            }
        }
        if (!flag) arr[count++] = i;
    }
}

int fact(int n) {
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = (ans * i) % MOD;
    }
    return ans;
}

int comparePairs(const void *a, const void *b) {
    Pair *pairA = (Pair *)a;
    Pair *pairB = (Pair *)b;
    return pairB->val - pairA->val;
}

long gcd(long x, long y) {
    if (x % y == 0)
        return y;
    else
        return gcd(y, x % y);
}

int binarySearch(int a[], int low, int high, int target) {
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (a[mid] == target)
        return mid;
    if (a[mid] > target)
        high = mid - 1;
    if (a[mid] < target)
        low = mid + 1;
    return binarySearch(a, low, high, target);
}

char* reverseString(char* s) {
    int len = strlen(s);
    char* reversed = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        reversed[i] = s[len - i - 1];
    }
    reversed[len] = '\0';
    return reversed;
}

long pow(long n, long p, long m) {
    long result = 1;
    if (p == 0) return 1;
    if (p == 1) return n;
    while (p != 0) {
        if (p % 2 == 1)
            result *= n;
        if (result >= m)
            result %= m;
        p >>= 1;
        n *= n;
        if (n >= m)
            n %= m;
    }
    return result;
}

long powSimple(long n, long p) {
    long result = 1;
    if (p == 0) return 1;
    if (p == 1) return n;
    while (p != 0) {
        if (p % 2 == 1)
            result *= n;
        p >>= 1;
        n *= n;
    }
    return result;
}

void radixSort(int f[], int n) {
    int to[n];
    {
        int b[65537] = {0};
        for (int i = 0; i < n; i++)
            b[1 + (f[i] & 0xffff)]++;
        for (int i = 1; i <= 65536; i++)
            b[i] += b[i - 1];
        for (int i = 0; i < n; i++)
            to[b[f[i] & 0xffff]++] = f[i];
        int* d = f;
        f = to;
        to = d;
    }
    {
        int b[65537] = {0};
        for (int i = 0; i < n; i++)
            b[1 + (f[i] >>> 16)]++;
        for (int i = 1; i <= 65536; i++)
            b[i] += b[i - 1];
        for (int i = 0; i < n; i++)
            to[b[f[i] >>> 16]++] = f[i];
        int* d = f;
        f = to;
        to = d;
    }
}

int nextPowerOf2(int a) {
    int b = 1;
    while (b < a) {
        b = b << 1;
    }
    return b;
}

bool pointInTriangle(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8) {
    int s = p2 * p5 - p1 * p6 + (p6 - p2) * p7 + (p1 - p5) * p8;
    int t = p1 * p4 - p2 * p3 + (p2 - p4) * p7 + (p3 - p1) * p8;

    if ((s < 0) != (t < 0))
        return false;

    int A = -p4 * p5 + p2 * (p5 - p3) + p1 * (p4 - p6) + p3 * p6;
    if (A < 0.0) {
        s = -s;
        t = -t;
        A = -A;
    }
    return s > 0 && t > 0 && (s + t) <= A;
}

float area(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (float) abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

long sort(int a[], int n) {
    int b[n];
    return mergeSort(a, b, 0, n - 1);
}

long mergeSort(int a[], int b[], long left, long right) {
    long c = 0;
    if (left < right) {
        long mid = left + (right - left) / 2;
        c = mergeSort(a, b, left, mid);
        c += mergeSort(a, b, mid + 1, right);
        c += merge(a, b, left, mid + 1, right);
    }
    return c;
}

long merge(int a[], int b[], long left, long mid, long right) {
    long c = 0;
    int i = left, j = mid, k = left;
    while (i <= mid - 1 && j <= right) {
        if (a[i] > a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
            c += mid - i;
        }
    }
    while (i <= mid - 1) b[k++] = a[i++];
    while (j <= right) b[k++] = a[j++];
    for (i = left; i <= right; i++)
        a[i] = b[i];
    return c;
}

int main() {
    InputReader(stdin);
    soln();
    return 0;
}

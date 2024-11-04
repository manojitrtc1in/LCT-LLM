#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define mdlo 1000000007
#define maxERR 0.00000064
#define maxBits 40
#define pi 3.1415926535897932384626433832795
#define INF 999999999999

typedef long long ll;

long long mInv[41];
long long fact[41];
long long factInv[41], N, M;
ll par[45];
bool inTree[123466];
bool visited[123466];

long long getmoduloInv(long long n) {
    if (n == 1)
        return 1;
    if (mInv[n] > 0)
        return mInv[n];
    long long m = (-1 * mdlo) / n;
    m += mdlo;
    m *= getmoduloInv(mdlo % n);
    mInv[n] = (m % mdlo);
    return mInv[n];
}

ll getAncestor(ll val) {
    if (par[val] != val)
        par[val] = getAncestor(par[val]);
    return par[val];
}

bool unify(ll a, ll b) {
    ll para = getAncestor(a), parb = getAncestor(b);
    if (para == parb)
        return false;
    if (para < parb)
        par[parb] = para;
    else
        par[para] = parb;
    return true;
}

unsigned long* get_primes(unsigned long max, unsigned long* size) {
    char *sieve = (char*)malloc((max / 8 + 1) * sizeof(char));
    unsigned long* primes = (unsigned long*)malloc(max * sizeof(unsigned long));
    *size = 0;

    long m = (max / 8) + 1;
    for (long long i = 0; i < m; i++)
        sieve[i] = 255;

    for (unsigned long x = 2; x <= max; x++)
        if (sieve[x / 8] & (0x01 << (x % 8))) {
            primes[(*size)++] = x;

            for (unsigned long j = 2 * x; j <= max; j += x)
                sieve[j / 8] &= ~(0x01 << (j % 8));
        }
    free(sieve);
    return primes;
}

ll dp[22][22];

ll getdp(long N, long K) {
    if (dp[N][K] == 0) {
        if (K == 1) {
            dp[N][K] = N;
            return dp[N][K];
        }
        ll v1 = getdp(N, K - 1), v2 = getdp(N - 1, K - 1);
        dp[N][K] = (v1 * v2) / (v1 - v2);
    }
    return dp[N][K];
}

bool isPrime(long N) {
    if (N == 1)
        return false;
    if (N < 4)
        return true;
    for (long i = 2; i * i < N; i++) {
        if (N % i == 0)
            return false;
    }
    return true;
}

ll gcd(ll a, ll b) {
    ll c;
    if (a > b) {
        c = a;
        a = b;
        b = c;
    }
    if (a == 0)
        return b;
    c = b % a;
    while (c > 0) {
        b = a;
        a = c;
        c = b % a;
    }
    return a;
}

long long getLcm(long long a, long long b) {
    long long c = a / gcd(a, b);
    return b * c;
}

typedef struct {
    long depth;
    long longestPath;
    long startPointOflongestpath;
    long deepestNode;
    bool included;
} treeInfo;

treeInfo dfs(long startPoint, long* tree[], bool* inTree, bool* visited) {
    treeInfo tInfo;
    long maxDepth = 0, maxDepth2 = 0, deepestNode = 1234567, deepestNode2 = 1234567, longestPath = 0, longestPathStart = 1234567;
    bool status = inTree[startPoint];
    visited[startPoint] = true;

    for (long i = 0; i < sizeof(tree[startPoint]) / sizeof(tree[startPoint][0]); i++) {
        if (!visited[tree[startPoint][i]]) {
            treeInfo childInfo = dfs(tree[startPoint][i], tree, inTree, visited);
            if (childInfo.included) {
                status = true;
                if (maxDepth < childInfo.depth || (maxDepth == childInfo.depth && deepestNode > childInfo.deepestNode)) {
                    maxDepth2 = maxDepth;
                    deepestNode2 = deepestNode;
                    deepestNode = childInfo.deepestNode;
                    maxDepth = childInfo.depth;
                } else if (maxDepth2 < childInfo.depth || (maxDepth2 == childInfo.depth && deepestNode2 > childInfo.deepestNode)) {
                    maxDepth2 = childInfo.depth;
                    deepestNode2 = childInfo.deepestNode;
                }
                if (childInfo.longestPath > longestPath || (childInfo.longestPath == longestPath && longestPathStart < childInfo.startPointOflongestpath)) {
                    longestPath = childInfo.longestPath;
                    longestPathStart = childInfo.startPointOflongestpath;
                }
            }
        }
    }
    tInfo.included = status;
    if (maxDepth == 0) {
        tInfo.deepestNode = startPoint;
        tInfo.depth = 1;
        tInfo.longestPath = 1;
        tInfo.startPointOflongestpath = startPoint;
        return tInfo;
    }
    if (maxDepth + maxDepth2 + 1 > longestPath || (maxDepth + maxDepth2 + 1 == longestPath && longestPathStart > fmin(deepestNode, deepestNode2))) {
        longestPathStart = fmin(deepestNode, deepestNode2);
        longestPath = maxDepth + maxDepth2 + 1;
    }
    if (maxDepth2 == maxDepth && deepestNode2 < deepestNode)
        deepestNode = deepestNode2;
    tInfo.deepestNode = deepestNode;
    tInfo.depth = maxDepth + 1;
    tInfo.longestPath = longestPath;
    tInfo.startPointOflongestpath = longestPathStart;
    inTree[startPoint] = status;
    return tInfo;
}

ll getVal(ll num) {
    ll ans = 1;
    for (long i = 1; i < num; i++)
        ans += (num / gcd(num, i));
    return ans;
}

void buildDp() {
    memset(dp, 0, sizeof(dp));
    for (long i = 1; i < 22; i++) {
        for (long j = 1; j <= i; j++) {
            dp[i][j] = getdp(i, j);
            printf("%lld ", dp[i][j]);
        }
        printf("\n");
    }
}

double maxDist(double t, double v, double r) {
    double dist = t * v;
    double C = t * v / r;
    double rotateDist1 = cos((pi + C) / 2) - cos((pi - C) / 2), rotateDist2 = cos((3 * pi + C) / 2) - cos((3 * pi - C) / 2);
    return dist + r * fmax(rotateDist1, rotateDist2);
}

void printMaxMin(double C) {
    double maxVal = -1, maxAngle = 0, minVal = 1, minAngle = 0;
    for (double th = 0.00; th < 360.1; th += 0.01) {
        double angle = ((th + C) * pi) / (double)180.0;
        double val = cos(angle) - cos(((th) * pi) / (double)180.0);
        if (val > maxVal) {
            maxVal = val;
            maxAngle = th;
        }
        if (val < minVal) {
            minVal = val;
            minAngle = th;
        }
    }
    printf("max %lf angle %lf\n", maxVal, maxAngle);
    printf("min %lf angle %lf\n", minVal, minAngle);
}

int main(void) {
    ll test_cases = 1, C, D, A, L, R, rep, round = 0, rem, ans = 0, num;
    double st, en, minerr = 0.00000001, r, v;
    scanf("%lld %lf %lf", &test_cases, &r, &v);
    printf("%.15lf\n", 0.0);

    for (long T = 0; T < test_cases; T++) {
        scanf("%lf %lf", &st, &en);
        double dist = en - st;
        double low = (dist - 2 * r) / v, high = (dist + 2 * r) / v, mid;
        while (low + minerr < high && low + low * minerr < high) {
            mid = (low + high) / 2;
            if (maxDist(mid, v, r) > dist)
                high = mid;
            else
                low = mid;
        }
        printf("%lf\n", (low + high) / 2);
    }
    return 0;
}

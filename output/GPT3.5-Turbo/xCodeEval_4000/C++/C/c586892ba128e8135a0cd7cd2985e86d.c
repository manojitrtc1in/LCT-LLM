#include<stdio.h>
#include<string.h>
#include<math.h>

#define mdlo 1000000007
#define maxERR 0.00000064
#define maxBits 40
#define pi 3.1415926535897932384626433832795
#define INF 999999999999

typedef long long ll;
typedef struct {
    long depth;
    long longestPath;
    long startPointOflongestpath;
    long deepestNode;
    int included;
} treeInfo;

typedef struct {
    long x;
    long y;
} edge;

typedef struct {
    long size;
    long capacity;
    long* data;
} adjList;

long levels[15];
long nextPoint[15];
long firstDigit[15];
int inTree[123466];
int visited[123466];
adjList tree[123466];
long startPoints[123466];

adjList graph[15];
ll par[45];
ll dp[22][22];

ll mInv[41];
ll fact[41];
ll factInv[41];
ll N, M;

ll getmoduloInv(ll n) {
    if (n == 1)
        return 1;
    if (mInv[n] > 0)
        return mInv[n];
    ll m = (-1 * mdlo) / n;
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

int unify(ll a, ll b) {
    ll para = getAncestor(a), parb = getAncestor(b);
    if (para == parb)
        return 0;
    if (para < parb)
        par[parb] = para;
    else
        par[para] = parb;
    return 1;
}

void get_primes(unsigned long max, unsigned long* primes, unsigned long* primes_size) {
    char* sieve;
    sieve = new char[max / 8 + 1];

    long m = (max / 8) + 1;
    for (long long i = 0; i < m; i++)
        sieve[i] = 255;
    for (unsigned long x = 2; x <= max; x++)
        if (sieve[x / 8] & (0x01 << (x % 8))) {
            primes[*primes_size] = x;

            for (unsigned long j = 2 * x; j <= max; j += x)
                sieve[j / 8] &= ~(0x01 << (j % 8));
            (*primes_size)++;
        }
    delete[] sieve;
}

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

int isPrime(long N) {
    if (N == 1)
        return 0;
    if (N < 4)
        return 1;
    for (long i = 2; i * i < N; i++) {
        if (N % i == 0)
            return 0;
    }
    return 1;
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

ll getLcm(ll a, ll b) {
    ll c = a / gcd(a, b);
    return b * c;
}

treeInfo dfs(long startPoint) {
    treeInfo tInfo;
    long maxDepth = 0, maxDepth2 = 0, deepestNode = 1234567, deepestNode2 = 1234567, longestPath = 0, longestPathStart = 1234567;
    int status = inTree[startPoint];
    visited[startPoint] = 1;
    for (long i = 0; i < tree[startPoint].size; i++) {
        if (!visited[tree[startPoint].data[i]]) {
            treeInfo childInfo = dfs(tree[startPoint].data[i]);
            if (childInfo.included) {
                status = 1;
                if (maxDepth < childInfo.depth || (maxDepth == childInfo.depth && deepestNode > childInfo.deepestNode)) {
                    maxDepth2 = maxDepth;
                    deepestNode2 = deepestNode;
                    deepestNode = childInfo.deepestNode;
                    maxDepth = childInfo.depth;
                }
                else if (maxDepth2 < childInfo.depth || (maxDepth2 == childInfo.depth && deepestNode2 > childInfo.deepestNode)) {
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

double angle[345768];

double maxDist(double t, double v, double r) {
    double dist = t * v;
    double C = t * v / r;
    double rotateDist1 = cos((pi + C) / 2) - cos((pi - C) / 2), rotateDist2 = cos((3 * pi + C) / 2) - cos((3 * pi - C) / 2);
    return dist + r * fmax(rotateDist1, rotateDist2);
}

void printMaxMin(double C) {
    double maxVal = -1, maxAngle = 0, minVal = 1, minAngle = 0;
    for (double th = 0.00; th < 360.1; th += 0.01) {
        double angle = ((th + C) * pi) / 180.0;
        double val = cos(angle) - cos((th * pi) / 180.0);
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

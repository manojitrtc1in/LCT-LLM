#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define pi 3.14159265358979323846

typedef long long ll;
ll mInv[41];
ll fact[41];
ll factInv[41], N, M;
typedef struct {
    long long first;
    long long second;
} pair;
typedef struct {
    long depth;
    long id6;
    long startPointOflongestpath;
    long id3;
    bool included;
} treeInfo;

long levels[15];
long nextPoint[15];
long firstDigit[15];
bool inTree[123466];
bool visited[123466];
typedef long adjList[123466];
adjList tree;
long startPoints[123466];

typedef long adjList[15];
adjList graph;

ll par[45];

ll id4(ll n) {
    if (n == 1)
        return 1;
    if (mInv[n] > 0)
        return mInv[n];
    ll m = (-1 * mdlo) / n;
    m += mdlo;
    m *= id4(mdlo % n);
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

ll primes[123466];
ll id1(ll max) {
    char *sieve;
    sieve = new char[max / 8 + 1];

    long m = (max / 8) + 1;
    for (long long i = 0; i < m; i++)
        sieve[i] = 255;
    for (ll x = 2; x <= max; x++)
        if (sieve[x / 8] & (0x01 << (x % 8))) {
            primes.push_back(x);

            for (ll j = 2 * x; j <= max; j += x)
                sieve[j / 8] &= ~(0x01 << (j % 8));
        }
    delete[] sieve;
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

ll id5(ll a, ll b) {
    ll c = a / gcd(a, b);
    return b * c;
}

treeInfo dfs(long startPoint) {
    treeInfo tInfo;
    long maxDepth = 0, id7 = 0, id3 = 1234567, id9 = 1234567, id6 = 0, id10 = 1234567;
    bool status = inTree[startPoint];
    visited[startPoint] = true;
    for (long i = 0; i < tree[startPoint].size(); i++) {
        if (!visited[tree[startPoint][i]]) {
            treeInfo childInfo = dfs(tree[startPoint][i]);
            if (childInfo.included) {
                status = true;
                if (maxDepth < childInfo.depth || (maxDepth == childInfo.depth && id3 > childInfo.id3)) {
                    id7 = maxDepth;
                    id9 = id3;
                    id3 = childInfo.id3;
                    maxDepth = childInfo.depth;
                } else if (id7 < childInfo.depth || (id7 == childInfo.depth && id9 > childInfo.id3)) {
                    id7 = childInfo.depth;
                    id9 = childInfo.id3;
                }
                if (childInfo.id6 > id6 || (childInfo.id6 == id6 && id10 < childInfo.startPointOflongestpath)) {
                    id6 = childInfo.id6;
                    id10 = childInfo.startPointOflongestpath;
                }
            }
        }
    }
    tInfo.included = status;
    if (maxDepth == 0) {
        tInfo.id3 = startPoint;
        tInfo.depth = 1;
        tInfo.id6 = 1;
        tInfo.startPointOflongestpath = startPoint;
        return tInfo;
    }
    if (maxDepth + id7 + 1 > id6 || (maxDepth + id7 + 1 == id6 && id10 > min(id3, id9))) {
        id10 = min(id3, id9);
        id6 = maxDepth + id7 + 1;
    }
    if (id7 == maxDepth && id9 < id3)
        id3 = id9;
    tInfo.id3 = id3;
    tInfo.depth = maxDepth + 1;
    tInfo.id6 = id6;
    tInfo.startPointOflongestpath = id10;
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
    double id0 = cos((pi + C) / 2) - cos((pi - C) / 2), id8 = cos((3 * pi + C) / 2) - cos((3 * pi - C) / 2);
    return dist + r * max(id0, id8);
}

void id2(double C) {
    double maxVal = -1, maxAngle = 0, minVal = 1, minAngle = 0;
    for (double th = 0.00; th < 360.1; th += 0.01) {
        double angle = ((th + C) * pi) / (double)180.0;
        double val = cos(angle) - cos((th * pi) / (double)180.0);
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
    printf("%.15lf\n");

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

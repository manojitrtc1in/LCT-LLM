#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

typedef long long ll;
long long mInv[41];
long long fact[41];
long long factInv[41], N, M;
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
long long par[45];
long long dp[22][22];
double angle[345768];

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

long long id5(long long a, long long b) {
    long long c = a / gcd(a, b);
    return b * c;
}

treeInfo dfs(long startPoint, long tree[123466][15]) {
    treeInfo tInfo;
    long maxDepth = 0, id7 = 0, id3 = 1234567, id9 = 1234567, id6 = 0, id10 = 1234567;
    bool status = inTree[startPoint];
    visited[startPoint] = true;
    for (long i = 0; i < 15; i++) {
        if (tree[startPoint][i] != -1 && !visited[tree[startPoint][i]]) {
            treeInfo childInfo = dfs(tree[startPoint][i], tree);
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
    if (maxDepth + id7 + 1 > id6 || (maxDepth + id7 + 1 == id6 && id10 > fmin(id3, id9))) {
        id10 = fmin(id3, id9);
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
            dp[i][j] = getVal(i); // Assuming getVal is used here
            printf("%lld ", dp[i][j]);
        }
        printf("\n");
    }
}

double maxDist(double t, double v, double r) {
    double dist = t * v;
    double C = t * v / r;
    double id0 = cos((M_PI + C) / 2) - cos((M_PI - C) / 2);
    double id8 = cos((3 * M_PI + C) / 2) - cos((3 * M_PI - C) / 2);
    return dist + r * fmax(id0, id8);
}

int main(void) {
    ll test_cases = 1, C, D, A, L, R, rep, round = 0, rem, ans = 0, num;
    double st, en, minerr = 0.00000001, r, v;
    scanf("%lld %lf %lf", &test_cases, &r, &v);
    printf("%.15lf\n", 0.0); // Placeholder for precision

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

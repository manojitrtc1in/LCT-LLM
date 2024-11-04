#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef long long ll;

typedef struct {
    ll first;
    ll second;
} sum;

typedef struct {
    sum first;
    ll second;
} updat;

typedef struct {
    ll first;
    ll second;
} pair;

typedef struct {
    ll first;
    ll second;
} cnts;

typedef struct {
    ll first;
    ll second;
} adjList;

adjList Trree[100];
ll N;

cnts counts1[30];
cnts counts2[30];

ll pwr2[100];
ll parent[1010];

ll getParent(ll node) {
    if (parent[node] != node)
        parent[node] = getParent(parent[node]);
    return parent[node];
}

void unionNode(ll node1, ll node2) {
    if (getParent(node1) != getParent(node2)) {
        parent[parent[node1]] = parent[node2];
    }
}

void id11(ll lim) {
    pwr2[0] = 1;
    for (ll i = 0; i < lim; i++)
        pwr2[i + 1] = pwr2[i] << 1;
}

ll id0(ll pos, ll val) {
    return val | pwr2[pos];
}

int id1(ll pos, ll val) {
    return (val & pwr2[pos]) > 0;
}

ll gcd(ll a, ll b) {
    ll c;
    c = b % a;
    while (c > 0) {
        b = a;
        a = c;
        c = b % a;
    }
    return a;
}

char s[100005];
ll target, sticker;
ll segTree[600005];
ll segTreeData[100005];
ll sumSegTree[600005];
ll sumSegTreeData[100005];
ll minStart[2];
ll minEnd[2];

void id7(ll b, ll e, ll node) {
    if (b == e) {
        segTree[node] = b;
        return;
    }
    ll mid = (b + e) / 2;
    id7(b, mid, node * 2);
    id7(mid + 1, e, 1 + (node * 2));
    if (segTreeData[segTree[node * 2]] > segTreeData[segTree[1 + (node * 2)]])
        segTree[node] = segTree[node * 2];
    else
        segTree[node] = segTree[1 + (2 * node)];
}

void id10(ll b, ll e, ll node) {
    if (b == e) {
        segTree[node] = b;
        return;
    }
    ll mid = (b + e) / 2;
    id10(b, mid, node * 2);
    id10(mid + 1, e, 1 + node * 2);
    if (segTreeData[segTree[node * 2]] > segTreeData[segTree[1 + (node * 2)]])
        segTree[node] = segTree[1 + (node * 2)];
    else
        segTree[node] = segTree[2 * node];
}

void id3(ll b, ll e, ll node, ll pos, ll val) {
    if (b > pos || e < pos)
        return;
    if (b == e) {
        segTreeData[pos] = val;
        return;
    }
    ll mid = (b + e) / 2;
    id3(b, mid, node * 2, pos, val);
    id3(mid + 1, e, 1 + node * 2, pos, val);
    if (segTreeData[segTree[node * 2]] > segTreeData[segTree[1 + node * 2]])
        segTree[node] = segTree[1 + 2 * node];
    else
        segTree[node] = segTree[2 * node];
}

ll getMax(ll qStart, ll qEnd, ll sStart, ll sEnd, ll node) {
    if (qEnd < sStart || qStart > sEnd)
        return -1;
    if (sStart >= qStart && sEnd <= qEnd)
        return segTree[node];
    ll sMid = (sStart + sEnd) / 2;
    ll r1 = getMax(qStart, qEnd, sStart, sMid, 2 * node);
    ll r2 = getMax(qStart, qEnd, sMid + 1, sEnd, 1 + (2 * node));
    if (r1 < 0)
        return r2;
    if (r2 < 0 || segTreeData[r1] > segTreeData[r2])
        return r1;
    return r2;
}

ll id5(ll qStart, ll qEnd, ll sStart, ll sEnd, ll node) {
    if (qEnd < sStart || qStart > sEnd)
        return -1;
    if (sStart >= qStart && sEnd <= qEnd)
        return segTree[node];
    ll sMid = (sStart + sEnd) / 2;
    ll r1 = id5(qStart, qEnd, sStart, sMid, 2 * node);
    ll r2 = id5(qStart, qEnd, sMid + 1, sEnd, 1 + (2 * node));
    if (r2 < 0)
        return r1;
    if (r1 < 0 || segTreeData[r1] > segTreeData[r2])
        return r2;
    return r1;
}

void id8(ll b, ll e, ll node) {
    if (b == e) {
        sumSegTree[node] = sumSegTreeData[b];
        return;
    }
    ll mid = (b + e) / 2;
    id8(b, mid, node * 2);
    id8(mid + 1, e, 1 + node * 2);
    sumSegTree[node] = sumSegTree[node * 2] + sumSegTree[1 + (node * 2)];
}

void id9(ll b, ll e, ll node, ll pos, ll val) {
    if (pos < b || pos > e)
        return;
    if (b == e) {
        sumSegTree[node] = val;
        sumSegTreeData[pos] = val;
        return;
    }
    ll mid = (b + e) / 2;
    id9(b, mid, 2 * node, pos, val);
    id9(mid + 1, e, 1 + 2 * node, pos, val);
    sumSegTree[node] = sumSegTree[node * 2] + sumSegTree[1 + (node * 2)];
}

ll id6(ll b, ll e, ll node, ll qStart, ll qEnd) {
    if (qStart > e || qEnd < b)
        return 0;
    if (b >= qStart && e <= qEnd)
        return sumSegTree[node];
    ll mid = (b + e) / 2;
    return id6(b, mid, node * 2, qStart, qEnd) + id6(mid + 1, e, 1 + 2 * node, qStart, qEnd);
}

ll id2(ll a, ll b) {
    ll c = a / gcd(a, b);
    return b * c;
}

ll pow10[18];
ll pow2[18];

ll getlen(ll num) {
    ll len = 1;
    while (num > 9) {
        num /= 10;
        len++;
    }
    return len;
}

void test(ll a) {
    switch (a) {
        case 1:
            printf("1");
        case 2:
            printf("2");
            break;
        case 3:
            printf("3");
        case 4:
            printf("4");
        case 5:
            printf("5");
        default:
            printf("0");
    }
    printf("\n");
}

struct base {
    void (*f)(char const* lable);
};

struct derived : base {
    void (*f)(char const* lable);
};

void id4(adjList tree[], ll node) {
    ll ancestor[100];
    for (ll i = 0; i < 100; i++) {
        ancestor[i] = i;
    }
    srand((unsigned)time(0));
    for (ll i = 1; i < node; i++) {
        int node1 = rand();
        int node2 = rand();
        int par1 = node1, par2 = node2;
        while (ancestor[par1] != par1)
            par1 = ancestor[par1];
    }
}

int main(void) {
    ll test_cases = 1;
    pow2[0] = 1;
    for (ll i = 1; i < 18; i++)
        pow2[i] = pow2[i - 1] * 2;

    printf("%.10f\n", 0.0);

    for (ll T = 0; T < test_cases; T++) {
        char s[100];
        char t[100];
        char m1[100];
        char m2[100];
        ll k, n, m, p;
        scanf("%lld %lld", &n, &k);
        ll bamboo[111];
        for (ll i = 0; i < n; i++) {
            scanf("%lld", &bamboo[i]);
        }
        for (ll i = 0; i < n; i++) {
            for (ll j = i + 1; j < n; j++) {
                if (bamboo[i] > bamboo[j]) {
                    ll temp = bamboo[i];
                    bamboo[i] = bamboo[j];
                    bamboo[j] = temp;
                }
            }
        }
        ll bambooSum[111];
        bambooSum[0] = bamboo[0];
        ll maxval = 0;
        for (ll i = 1; i < n; i++) {
            bambooSum[i] = bamboo[i] + bambooSum[i - 1];
            ll m = i * bamboo[i] - bambooSum[i - 1];
            if (m > k && maxval == 0) {
                maxval = bamboo[i];
            }
        }
        if (maxval == 0) {
            ll remaining = k + bambooSum[n - 1] - (n * bamboo[n - 1]);
            printf("%lld\n", (remaining / n) + bamboo[n - 1]);
            return 0;
        }
        ll candidatePoints[111];
        ll candidatePointsSize = 0;

        for (ll i = 0; i < n; i++) {
            bambooSum[i] += k;
            ll lim = 1 + sqrt(bamboo[i] + 1);
            for (ll j = 1; j < lim; j++) {
                ll r1 = bamboo[i] / j, r2 = j;
                if (r1 < maxval) {
                    if (r1 * j == bamboo[i])
                        candidatePoints[candidatePointsSize++] = r1;
                    else
                        candidatePoints[candidatePointsSize++] = r1 + 1;
                }
            }
        }
        ll lim = sqrt(bamboo[n - 1]);
        if (lim > maxval)
            lim = maxval;
        for (ll i = 1; i < lim; i++)
            candidatePoints[candidatePointsSize++] = i;
        for (ll i = candidatePointsSize - 1; i >= 0; i--) {
            ll cp = candidatePoints[i];
            ll total = 0, d1, flag = 1;
            for (ll i = 0; i < n; i++) {
                d1 = (bamboo[i] + cp - 1) / cp;
                total += (d1 * cp);
                if (total > bambooSum[i]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                ll dv = 0;
                for (ll i = 0; i < n; i++)
                    dv += (bamboo[i] + cp - 1) / cp;
                printf("%lld\n", cp + (bambooSum[n - 1] - total) / dv);
                return 0;
            }
        }
        printf("1\n");
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAX(a, b) \
    a > b ? a : b

typedef long long ll;

void buildRandomTree(ll tree[], ll node) {
    ll ancestor[100];
    for(ll i=0; i<100; i++) {
        ancestor[i] = i;
    }
    srand((unsigned)time(0));
    for(ll i=1; i<node; i++) {
        ll node1 = rand();
        ll node2 = rand();
        ll par1 = node1, par2 = node2;
        while(ancestor[par1] != par1)
            par1 = ancestor[par1];
    }
}

int main(void) {
    ll test_cases = 1;

    for(ll T=0; T<test_cases; T++) {
        ll n, k;
        scanf("%lld %lld", &n, &k);
        ll bamboo[111];
        for(ll i=0; i<n; i++) {
            scanf("%lld", &bamboo[i]);
        }
        for(ll i=0; i<n; i++) {
            for(ll j=i+1; j<n; j++) {
                if(bamboo[i] > bamboo[j]) {
                    ll temp = bamboo[i];
                    bamboo[i] = bamboo[j];
                    bamboo[j] = temp;
                }
            }
        }
        ll bambooSum[111];
        bambooSum[0] = bamboo[0];
        ll maxval = 0;
        for(ll i=1; i<n; i++) {
            bambooSum[i] = bamboo[i] + bambooSum[i-1];
            ll m = i * bamboo[i] - bambooSum[i-1];
            if(m > k && maxval == 0) {
                maxval = bamboo[i];
            }
        }
        if(maxval == 0) {
            ll remaining = k + bambooSum[n-1] - (n * bamboo[n-1]);
            printf("%lld\n", (remaining / n) + bamboo[n-1]);
            return 0;
        }
        ll candidatePoints[111];
        ll candidatePointsSize = 0;
        for(ll i=0; i<n; i++) {
            bambooSum[i] += k;
            ll lim = 1 + sqrt(bamboo[i] + 1);
            for(ll j=1; j<lim; j++) {
                ll r1 = bamboo[i] / j, r2 = j;
                if(r1 < maxval) {
                    if(r1 * j == bamboo[i])
                        candidatePoints[candidatePointsSize++] = r1;
                    else
                        candidatePoints[candidatePointsSize++] = r1 + 1;
                }
            }
        }
        ll lim = sqrt(bamboo[n-1]);
        if(lim > maxval)
            lim = maxval;
        for(ll i=1; i<lim; i++)
            candidatePoints[candidatePointsSize++] = i;
        for(ll i=candidatePointsSize-1; i>=0; i--) {
            ll cp = candidatePoints[i];
            ll total = 0, d1, flag = 1;
            for(ll j=0; j<n; j++) {
                d1 = (bamboo[j] + cp - 1) / cp;
                total += (d1 * cp);
                if(total > bambooSum[j]) {
                    flag = 0;
                    break;
                }
            }
            if(flag) {
                ll dv = 0;
                for(ll j=0; j<n; j++)
                    dv += (bamboo[j] + cp - 1) / cp;
                printf("%lld\n", cp + (bambooSum[n-1] - total) / dv);
                return 0;
            }
        }
        printf("1\n");
    }
    return 0;
}

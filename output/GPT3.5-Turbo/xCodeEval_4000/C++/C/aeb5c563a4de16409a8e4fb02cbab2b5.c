#include<stdio.h>
#include<stdlib.h>

#define ll long long
#define rep(i,m,n) for(ll (i)=(ll)(m);(i)<(ll)(n);i++)
#define REP(i,n) rep(i,0,n)
#define all(hoge) (hoge).begin(),(hoge).end()
typedef vector<ll> Array;
typedef vector<Array> Matrix;

void chmax(ll* a, ll b) {
	if (*a < b) {
		*a = b;
	}
}

void solve(Array* dp, ll l, ll r, Matrix* a, Array* w, ll k, ll* ans) {
	if (r - l == 1) {
		ll sum = 0;
		REP(i, (*a)[l].size() + 1) {
			chmax(ans, (*dp)[k - i] + sum);
			if (i != (*a)[l].size())sum += (*a)[l][i];
		}
		return;
	}
	ll m = (r + l) / 2;
	Array dp2 = *dp;
	rep(i, m, r) {
		for (int j = k - 1; j >= 0; j--)if ((*a)[i].size() + j <= k)chmax(&dp2[j + (*a)[i].size()], (*dp)[j] + (*w)[i]);
	}
	solve(&dp2, l, m, a, w, k, ans);
	rep(i, l, m) {
		for (int j = k - 1; j >= 0; j--)if ((*a)[i].size() + j <= k)chmax(&(*dp)[j + (*a)[i].size()], (*dp)[j] + (*w)[i]);
	}
	solve(dp, m, r, a, w, k, ans);
}

int main() {
	ll n, k;
	scanf("%lld %lld", &n, &k);
	Matrix a(n);
	REP(i, n) {
		ll t;
		scanf("%lld", &t);
		REP(j, t) {
			ll tmp;
			scanf("%lld", &tmp);
			if (a[i].size() < k)a[i].push_back(tmp);
		}
	}
	Array w(n, 0);
	REP(i, n)w[i] = accumulate(all(a[i]), 0LL);
	ll ans = 0;
	Array dp(k + 1, 0);
	solve(&dp, 0, n, &a, &w, k, &ans);
	printf("%lld\n", ans);

	return 0;
}




























































































































































































































































#include <bits/stdc++.h>
#define DEBUG false
#define debugf if (DEBUG) printf
#define MAXN 2009
#define MAXM 900009
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for(int x=0; (x)<int(n); (x)++)
#define FOR1(x,n) for(int x=1; (x)<=int(n); (x)++)
#define REP(x,n) for(int x=int(n)-1; (x)>=0; (x)--)
#define REP1(x,n) for(int x=(n); (x)>0; (x)--)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
#define all(x) x.begin(), x.end()
#define mset(x,y) memset(&x, (y), sizeof(x));
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> ii;

double dp[MAXN][MAXN];
int A[MAXN][MAXN];
int n, a, b;
double pa[MAXN], pb[MAXN];

int computeDp(double C) {
	FOR(i, n+1) REP(j, a+1) {
		if (i == 0) {
			dp[i][j] = 0;
			continue;
		}
		dp[i][j] = dp[i-1][j];
		A[i][j] = 0;
		if (j > 0 && dp[i][j] < dp[i-1][j-1] + pa[i]) {
			dp[i][j] = dp[i-1][j-1] + pa[i];
			A[i][j] = 1;
		}
		if (dp[i][j] < dp[i-1][j] + pb[i] - C) {
			dp[i][j] = dp[i-1][j] + pb[i] - C;
			A[i][j] = 2;
		}
		if (j > 0 && dp[i][j] < dp[i-1][j-1] + pa[i] + pb[i] - pa[i]*pb[i] - C) {
			dp[i][j] = dp[i-1][j-1] + pa[i] + pb[i] - pa[i]*pb[i] - C;
			A[i][j] = 3;
		}
	}

	int j = a, cb = 0;
	REP1(i, n) {
		if (A[i][j] >= 2) cb++;
		if (A[i][j] & 1) j--;
	}

	return cb;
}

double computeC() {
	if (b == 0) return 2;
	if (b == n) return 0;
	double lo = 0;
	double hi = 1;
	FOR(epoch, 50) {
		double C = (hi + lo) / 2;
		if(computeDp(C) > b) lo = C;
		else hi = C;
	}
	return hi;
}

int main() {
	scanf("%d %d %d", &n, &a, &b);
	FOR1(i, n) scanf("%lf", &pa[i]);
	FOR1(i, n) scanf("%lf", &pb[i]);
	double C = computeC();
	computeDp(C);
	

	printf("%.20f\n", dp[n][a] + C*b);
	return 0;
}
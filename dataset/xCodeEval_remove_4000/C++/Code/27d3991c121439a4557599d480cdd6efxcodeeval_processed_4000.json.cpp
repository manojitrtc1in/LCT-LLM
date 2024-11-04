















































































































































































































































































using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> ii;

double dp[MAXN];
int A[MAXN];
int n, a, b;
double pa[MAXN], pb[MAXN];

ii computeDp(double C, double D) {
	FOR(i, n+1) {
		if (i == 0) {
			dp[i] = 0;
			continue;
		}
		dp[i] = dp[i-1];
		A[i] = 0;
		if (dp[i] < dp[i-1] + pa[i] - D) {
			dp[i] = dp[i-1] + pa[i] - D;
			A[i] = 1;
		}
		if (dp[i] < dp[i-1] + pb[i] - C) {
			dp[i] = dp[i-1] + pb[i] - C;
			A[i] = 2;
		}
		if (dp[i] < dp[i-1] + pa[i] + pb[i] - pa[i]*pb[i] - C - D) {
			dp[i] = dp[i-1] + pa[i] + pb[i] - pa[i]*pb[i] - C - D;
			A[i] = 3;
		}
	}

	int ca = 0, cb = 0;
	REP1(i, n) {
		if (A[i] >= 2) cb++;
		if (A[i] & 1) ca++;
	}

	return ii(ca, cb);
}

double computeC(double D) {
	if (b == 0) return 2;
	if (b == n) return 0;
	double lo = 0;
	double hi = 1;
	FOR(it, 50) {
		double C = (hi + lo) / 2;
		if(computeDp(C, D).se > b) lo = C;
		else hi = C;
	}
	return hi;
}

double computeD() {
	if (a == 0) return 2;
	if (a == n) return 0;
	double lo = 0;
	double hi = 1;
	FOR(it, 50) {
		double D = (hi + lo) / 2;
		double C = computeC(D);
		if(computeDp(C, D).fi > a) lo = D;
		else hi = D;
	}
	return hi;
}

int main() {
	scanf("%d %d %d", &n, &a, &b);
	FOR1(i, n) scanf("%lf", &pa[i]);
	FOR1(i, n) scanf("%lf", &pb[i]);
	double D = computeD();
	double C = computeC(D);
	computeDp(C, D);
	

	printf("%.20f\n", dp[n] + C*b + D*a);
	return 0;
}
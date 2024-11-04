


















































































































































































































































































using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n;
double x[MAXN], y[MAXN];

double getr(int i, double x0) {
	return ((x[i]-x0)*(x[i]-x0) + y[i]*y[i])/(2*y[i]);
}

int check(double x0) {
	double r = -1;
	int j = 0;
	FOR(i, n) {
		double cur = getr(i, x0);
		if (cur > r) {
			r = cur;
			j = i;
		}
	}
	return j;
}

int main() {
	while(scanf("%d", &n) != EOF) {
		int pos = 0, neg = 0;
		FOR(i, n) {
			scanf("%lf %lf", &x[i], &y[i]);
			if (y[i] > 0) pos++;
			if (y[i] < 0) {
				neg++;
				y[i] *= -1;
			}
		}
		if (pos != 0 && neg != 0) {
			printf("-1\n");
			continue;
		}
		double lo = -(1e7);
		double hi = (1e7);
		FOR(it, 100) {
			double mid = (hi + lo) / 2.0;
			int j = check(mid);
			if (x[j] < mid) hi = mid;
			else lo = mid;
		}
		double mid = (hi+lo) / 2.0;
		int j = check(mid);
		double r = getr(j, mid);
		printf("%.20f\n", r);
	}
	return 0;
}
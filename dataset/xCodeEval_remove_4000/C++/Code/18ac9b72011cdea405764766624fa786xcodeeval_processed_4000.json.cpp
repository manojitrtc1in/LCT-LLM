














typedef long long ll;



std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());

const double PI = atan2(0., -1.);
const int INF = 0x3f3f3f3f;
const int N = 1100;
const int MOD = (int)1e9 + 7;
const double E = 2.71828182846;

template<typename T1, typename T2>
T1 binpow(T1 a, T2 n) {
	if (a == 0) {
		return 1;
	}
	if (n % 2 == 0) {
		return binpow(a * a, n / 2);
	} else {
		return binpow(a, n - 1) * a;
	}
}

template<typename T>
T rev(T a) {
	return binpow(a, MOD - 2);	
}

template<typename T>
T add(T a, T b) {
	if (a + b >= MOD) {
		return a + b - MOD;
	} else {
		return a + b;
	}
}

template<typename T>
T sub(T a, T b) {
	if (a - b < 0) {
		return a - b + MOD;
	} else {
		return a - b;
	}
}

int mul(int a, int b) {
	return 1ll * a * b % MOD;
}

template<typename T>
T div(T a, T b) {
	return mul(a, rev(b));
}

char a[N][N];
int l[N][N], r[N][N], u[N][N], d[N][N], lu[N][N], ld[N][N], ru[N][N], rd[N][N];
long double logL[N][N], logr[N][N], logu[N][N], logd[N][N], loglu[N][N], logld[N][N], logru[N][N], logrd[N][N];

int main(void) {
	

	

	

	


	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("\n%s", a[i]);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][j] != '0') {
				l[i][j] = r[i][j] = u[i][j] = d[i][j] = 1;
				lu[i][j] = ru[i][j] = ld[i][j] = rd[i][j] = 1;
				logL[i][j] = logr[i][j] = logu[i][j] = logd[i][j] = log(a[i][j] - '0');
				loglu[i][j] = logru[i][j] = logld[i][j] = logrd[i][j] = log(a[i][j] - '0');
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][j] == '0') {
				continue;
			}
			if (i > 0) {
				u[i][j] += u[i - 1][j];
				logu[i][j] += logu[i - 1][j];
			}
			if (j > 0) {
				l[i][j] += l[i][j - 1];
				logL[i][j] += logL[i][j - 1];
			}
			if (i > 0 && j > 0) {
				lu[i][j] += lu[i - 1][j - 1];
				loglu[i][j] += loglu[i - 1][j - 1];
			}
			if (i > 0 && j < n - 1) {
				ru[i][j] += ru[i - 1][j + 1];
				logru[i][j] += logru[i - 1][j + 1];
			}
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		for (int j = n - 1; j >= 0; --j) {
			if (a[i][j] == '0') {
				continue;
			}
			if (i < n - 1) {
				d[i][j] += d[i + 1][j];
				logd[i][j] += logd[i + 1][j];
			}
			if (j < n - 1) {
				r[i][j] += r[i][j + 1];
				logr[i][j] += logr[i][j + 1];
			}
			if (i < n - 1 && j < n - 1) {
				rd[i][j] += rd[i + 1][j + 1];
				logrd[i][j] += logrd[i + 1][j + 1];
			}
			if (i < n - 1 && j > 0) {
				ld[i][j] += ld[i + 1][j - 1];
				logld[i][j] += logld[i + 1][j - 1];
			}
		}
	}

	double best = -1.0;
	int ansI = 0, ansJ = 0;
	int type = 1, ansMx = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int mx = std::min(std::min(l[i][j], r[i][j]), std::min(u[i][j], d[i][j]));
			if (mx != 0) {
				double curLog = logL[i][j] + logr[i][j] + logu[i][j] + logd[i][j] - 3.0 * log(a[i][j] - '0');
				if (i - mx >= 0) {
					curLog -= logu[i - mx][j];
				}
				if (i + mx < n) {
					curLog -= logd[i + mx][j];
				}
				if (j - mx >= 0) {
					curLog -= logL[i][j - mx];
				}
				if (j + mx < n) {
					curLog -= logr[i][j + mx];
				}
				if (curLog > best) {
					best = curLog;
					ansI = i;
					ansJ = j;
					type = 1;
					ansMx = mx;
				}
			}
			mx = std::min(std::min(lu[i][j], ru[i][j]), std::min(ld[i][j], rd[i][j]));
			if (mx != 0) {
				double curLog = loglu[i][j] + logru[i][j] + logld[i][j] + logrd[i][j] - 3.0 * log(a[i][j] - '0');
				if (i - mx >= 0 && j - mx >= 0) {
					curLog -= loglu[i - mx][j - mx];
				}
				if (i - mx >= 0 && j + mx < n) {
					curLog -= logru[i - mx][j + mx];
				}
				if (i + mx < n && j - mx >= 0) {
					curLog -= logld[i + mx][j - mx];
				}
				if (i + mx < n && j + mx < n) {
					curLog -= logrd[i + mx][j + mx];
				}
				if (curLog > best) {
					best = curLog;
					ansI = i;
					ansJ = j;
					type = 2;
					ansMx = mx;
				}
			}
		}
	}

	int ans = a[ansI][ansJ] - '0';
	if (type == 1) {
		for (int x = 1; x < ansMx; ++x) {
			ans = mul(ans, a[ansI - x][ansJ] - '0');
			ans = mul(ans, a[ansI + x][ansJ] - '0');
			ans = mul(ans, a[ansI][ansJ - x] - '0');
			ans = mul(ans, a[ansI][ansJ + x] - '0');
		}
	} else {
		for (int x = 1; x < ansMx; ++x) {
			ans = mul(ans, a[ansI - x][ansJ - x] - '0');
			ans = mul(ans, a[ansI - x][ansJ + x] - '0');
			ans = mul(ans, a[ansI + x][ansJ - x] - '0');
			ans = mul(ans, a[ansI + x][ansJ + x] - '0');
		}
	}

	

	

	

	

	


	printf("%d\n", ans);
	
	
	return 0;
}

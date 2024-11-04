




















using namespace std;

typedef long long LL;

inline char gc() {
	static const LL L = 233333;
	static char sxd[L], *sss = sxd, *ttt = sxd;
	if (sss == ttt) {
		ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
		if (sss == ttt) {
			return EOF;
		}
	}
	return *sss++;
}






inline char readalpha() {
	char dd;
	for (; !isalpha(c); dd);
	return c;
}

inline char readchar() {
	char dd;
	for (; c == ' '; dd);
	return c;
}

template <class T>
inline bool read(T& x) {
	bool flg = false;
	char dd;
	x = 0;
	for (; !isdigit(c); dd) {
		if (c == '-') {
			flg = true;
		} else if(c == EOF) {
			return false;
		}
	}
	for (; isdigit(c); dd) {
		x = (x << 1) + (x << 3) + (c ^ 48);
	}
	if (flg) {
		x = -x;
	}
	return true;
}


template <class T>
inline void write(T x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x < 10) {
		putchar(x | 48);
		return;
	}
	write(x / 10);
	putchar((x % 10) | 48);
}

const int maxn = 100005;

int n;
int ans[maxn];

struct AA {
	int x, id;
} aa[maxn];

template<typename _EuclideanRingElement>
_EuclideanRingElement
gcd(_EuclideanRingElement __m, _EuclideanRingElement __n) {
	while (__n) {
		_EuclideanRingElement __t = __m % __n;
		__m = __n;
		__n = __t;
	}
	return __m;
}

int main() {
	double nowx = clock();
	srand((unsigned) time(NULL));
	read(n);
	int g = 0;
	for (int i = 1; i <= n; ++i) {
		read(aa[i].x);
		g = gcd(aa[i].x, g);
		aa[i].id = i;
	}
	if (g > 1) {
		puts("NO");
		return 0;
	}
	while (clock() - nowx < 450) {
		random_shuffle(aa + 1, aa + n + 1);
		int xx = aa[1].x, yy = 0;
		ans[aa[1].id] = 1;
		for (int i = 2; i <= n; ++i) {
			if (gcd(xx, aa[i].x) < xx) {
				ans[aa[i].id] = 1;
				xx = gcd(xx, aa[i].x);
			} else {
				ans[aa[i].id] = 2;
				yy = gcd(yy, aa[i].x);
			}
		}
		if (xx == 1 && yy == 1) {
			puts("YES");
			for (int i = 1; i <= n; ++i) {
				printf("%d ", ans[i]);
			}
			return 0;
		}
	}
	puts("NO");
	return 0;
}
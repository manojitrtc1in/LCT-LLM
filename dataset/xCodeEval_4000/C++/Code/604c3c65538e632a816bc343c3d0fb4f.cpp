



































#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
LL A[N];
int n, n2, T;
bool pd() {
	for (int i = 1; i <= n; i++) if (A[i * 2 - 1] != A[i * 2]) return 0;
	return 1;
}
int main() {
	scanf("%d", &T);
	for (; T--; ) {
		scanf("%d", &n); n2 = (n << 1);
		for (int i = 1; i <= n2; i++) scanf("%lld", A + i);
		sort(A + 1, A + n2 + 1);
		if (!pd()) {puts("NO"); continue;}
		for (int i = 1; i <= n; i++) A[i] = A[i * 2];
		if (A[n] % (LL)n != 0) {puts("NO"); continue;}
		bool flag = 1; LL tcnt = 0;
		for (int i = n - 1; i > 0; i--) {
			if ((A[i + 1] - A[i]) % (LL)(i * 2) != 0 || A[i + 1] <= A[i]) {
				puts("NO"); flag = 0; break;
			} else {
				tcnt += (LL)((n - i) * 2ll) * ((A[i + 1] - A[i]) / (LL)(i * 2));
			}
			if (A[1] - tcnt <= 0) {
				puts("NO"); flag = 0; break;
			}
		}
		if (flag) puts(((A[1] - tcnt > 0) && ((A[1] - tcnt) % (2 * n) == 0)) ? "YES" : "NO");
	}
	return 0;
}


#include <iostream>
using namespace std;


int n, a, sum[(int)3e5 + 5], current, k, ans, j;
int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a, sum[i] = a + sum[i - 1];
	a = 1e9;
	for (int i = 1; i <= n - k + 1; ++i) {
		current = sum[i + k - 1] - sum[i - 1];
		if(current < a)
			a = current, ans = i;
		j = i;
	}
	for(int i = n - k + 1; i <= n && i - k > 1; ++i) {
		current = sum[i] - sum[i - k];
		if(current < a)
			a = current, ans = i;
	}
	cout << (n == k ? 1 : ans);
}

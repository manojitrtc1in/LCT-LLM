













using namespace std;



int main()
{
	int t;
	int n;
	int sum[100005];
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> sum[i];
		}
		sort(sum + 1, sum + 1 + n);
		int m = sum[n - 1];
		int ans = 0;
		for (int i = 1; i < m && i < n - 1; i++) {
			ans++;
		}
		
		cout << ans << endl;
	}
	return 0;
}

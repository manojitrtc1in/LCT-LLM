











using namespace std;
long a[100010];

int main() {
	int n, k;
	cin >> n >> k;
	int min = ans,max=-ans;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (min > a[i]) {
			min = a[i];
		}
		if (max < a[i]) {
			max = a[i];
		}
	}
	if (k == 1) {
		cout << min << endl;
	}
	else if (k == 2) {
		if (a[0] < a[n - 1]) {
			cout << a[n-1] << endl;
		}
		else {
			cout << a[0] << endl;
		}
	}
	else {
		cout << max << endl;
	}

	return 0;
}












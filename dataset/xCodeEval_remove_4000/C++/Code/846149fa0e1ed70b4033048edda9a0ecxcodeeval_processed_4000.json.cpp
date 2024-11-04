

using namespace std;

























int freq[1001];

int main() {
	faster_IO_stream

	int n, k, sum = 0, l, r;
	cin >> n >> k;

	loop(n) {
		cin >> l >> r;
		sum += r - l + 1;
	}

	cout << (k - (sum % k)) % k << endl;
	return 0;
}


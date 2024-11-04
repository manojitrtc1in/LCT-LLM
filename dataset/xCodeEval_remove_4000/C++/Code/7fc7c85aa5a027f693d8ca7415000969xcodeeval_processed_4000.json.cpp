

using namespace std;

























bool isGood(int n, int k)
{
	set<int> s;
	while(n / 10.0) { if(n % 10 <= k) s.insert(n % 10); n /= 10; }
	return (int) s.size() == k + 1;
}

int main() {
	faster_IO_stream

	int n, k;
	cin >> n >> k;

	int num, res = 0;
	loop(n) {
		cin >> num;

		if(isGood(num, k)) res++;
	}

	cout << res << endl;
	return 0;
}

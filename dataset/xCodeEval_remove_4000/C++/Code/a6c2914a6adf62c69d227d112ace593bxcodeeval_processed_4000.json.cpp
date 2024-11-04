
using namespace std;

























int main() {
	faster_IO_stream

	int n, num;
	cin >> n;
	map<int, int> freq;
	loop(n) {
		cin >> num; freq[num]++;
	}

	cout << max(n - (*freq.begin()).second - (*--freq.end()).second, 0) << endl;

	return 0;
}

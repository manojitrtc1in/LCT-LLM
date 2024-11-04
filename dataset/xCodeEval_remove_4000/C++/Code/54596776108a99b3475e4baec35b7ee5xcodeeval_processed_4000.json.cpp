




















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































using namespace std;
vector<long long> a;
vector <vector<long long>> d;
int n;
long long max(long long a, long long b);
void id0();
void Fill();
int const INF = -1000000000;
int main(void) {
	int kk;
	cin >> n;
	a = vector<long long>(n + 1);
	Fill();
	d = vector <vector<long long>>(n + 1, vector<long long>(n + 1, INF));
	d[0][0] = 0;
	id0();
	int answer = 0;
	for (int i = 0; i < n + 1; i++) {
		if (d[i][n] >= 0) {
			answer = n - i;
			break;
		}
	}
	cout << answer << endl;
	return 0;
}
void id0() {
	for (int i = 1; i < n + 1; i++) {
		d[0][i] = d[0][i - 1] + a[i];
		if (d[0][i] < 0) {
			d[0][i] = INF;
		}
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			d[i][j] = max(d[i][j - 1] + a[j], d[i - 1][j - 1]);
			if (d[i][j] < 0) {
				d[i][j] = INF;
			}
		}
	}
}
long long max(long long a, long long b)
{
	if (a > b)
		return a;
	return b;
}
void Fill() {
	for (int i = 1; i < n + 1; i++) {
		cin >> a[i];
	}
}
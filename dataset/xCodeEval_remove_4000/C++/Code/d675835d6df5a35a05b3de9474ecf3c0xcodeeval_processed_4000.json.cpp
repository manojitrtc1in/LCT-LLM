































































































































































































































































































































































































































































































































































































































































































































































































































































































































































using namespace std;
vector<int> a;
vector<int> b;
vector<vector<long long>> d;
int n;
int h;
int w;
int H;
int W;
void Matrix();
int main(void) {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int q;
		cin >> n;
		cin >> q;
		a = vector<int>(n);
		b = vector<int>(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cin >> b[i];
		}
		d = vector<vector<long long>>(1001, vector<long long>(1001, 0));
		Matrix();
		for (int i = 0; i < q; i++) {
			cin >> h;
			cin >> w;
			cin >> H;
			cin >> W;
			cout << d[H - 1][W - 1] - d[h][W - 1] - d[H - 1][w] + d[h][w];
			cout << endl;
			}
		}
	return 0;
}

void Matrix() {
	for (int i = 0; i < n; i++) {
		d[a[i]][b[i]] += a[i] * b[i];
	}
	for (int i = 1; i < 1001; i++) {
		for (int j = 1; j < 1001; j++) {
			d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + d[i][j];
		}
	}
}
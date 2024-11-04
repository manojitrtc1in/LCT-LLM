


using namespace std;
const int mod = 1e9+7;
const int maxn = 2e5+10;
int a[maxn];
int main() {

	

	int n;
	T {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d", a+i);
		}
		cout << 0;
		int mm = INT_MAX;
		for(int i = 1; i < n; i++) {
			int ans = (mm^a[i])&a[i-1];
			cout << " " << ans;
			a[i]^=ans;
		}
		cout << endl;
	}


	return 0;
}


















































	































































using namespace std;


























const double pi = 3.14159265358979323846;
const int module = 1e9 + 7;

ll calc(int n, vi nums1, vi nums2, ll mid) {
	ll sum = 0;
	loop(n) if(nums1[i] > mid) sum += nums2[i];
	return max(sum, mid);
}

int main() {
	IO

	int tc;
	cin >> tc;
	while(tc--) {
		int n;
		cin >> n;

		vi nums1(n), nums2(n);
		loop(n) cin >> nums1[i];
		loop(n) cin >> nums2[i];

		

		ll l = 1, r = 10e9, mid, res = 10e9;
		while(l <= r) {
			mid = (l + r) / 2;


			ll t = calc(n, nums1, nums2, mid);
			if(t <= mid) r = mid - 1, res = mid;
			else l = mid + 1;
		}

		cout << res << "\n";
	}

	return 0;
}

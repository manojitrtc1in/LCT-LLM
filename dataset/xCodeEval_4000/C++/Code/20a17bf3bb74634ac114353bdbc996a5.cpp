#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626
#define mod 1000000007
#define mod1 998244353
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define deb(x) cout<<x<<"\n";
#define deB(x,y) cout<<x<<" "<<y<<"\n";
#define Deb(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define YES cout<<"YES\n";
#define Yes cout<<"Yes\n";
#define NO cout<<"NO\n";
#define No cout<<"No\n";
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(),(v).end()
#define mk(arr,n,type)  type *arr=new type[n];
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;







ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		mk(arr, n, ll);

		map<ll, ll> m;

		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
			m[arr[i]]++;
		}

		vector<int> brr(n, 0);

		for (int i = 0; i < n; i++) {
			brr[i] = arr[i];
		}

		vector<int> crr(n, 0);

		for (int i = 0; i < n; i++) {
			crr[i] = arr[i];
		}

		vector<int> drr(n, 0);

		for (int i = 0; i < n; i++) {
			drr[i] = arr[i];
		}

		vector<int> err(n, 0);

		for (int i = 0; i < n; i++) {
			err[i] = arr[i];
		}

		vector<int> frr(n, 0);

		for (int i = 0; i < n; i++) {
			frr[i] = arr[i];
		}

		vector<int> sx(n, 0);

		for (int i = 0; i < n; i++) {
			sx[i] = arr[i];
		}

		vector<int> svn(n, 0);

		for (int i = 0; i < n; i++) {
			svn[i] = arr[i];
		}

		vector<int> eght(n, 0);

		for (int i = 0; i < n; i++) {
			eght[i] = arr[i];
		}

		vector<int> nin(n, 0);

		for (int i = 0; i < n; i++) {
			nin[i] = arr[i];
		}

		vector<int> tn(n, 0);

		for (int i = 0; i < n; i++) {
			tn[i] = arr[i];
		}

		map<ll, ll> m1 = m;

		map<ll, ll> m2 = m;

		map<ll, ll> m3 = m;

		map<ll, ll> m4 = m;

		map<ll, ll> m5 = m;

		map<ll, ll> m6 = m;

		map<ll, ll> m7 = m;

		map<ll, ll> m8 = m;

		map<ll, ll> m9 = m;

		map<ll, ll> m10 = m;


		


		for (int i = 0; i < n; i++) {
			frr[i] = m1[frr[i]];
		}

		


		for (int i = 0; i < n; i++) {
			brr[i] = m2[brr[i]];
		}

		m2.clear();

		for (int i = 0; i < n; i++) {
			m2[brr[i]]++;
		}

		for (int i = 0; i < n; i++) {
			brr[i] = m2[brr[i]];
		}

		


		for (int i = 0; i < n; i++) {
			crr[i] = m3[crr[i]];
		}

		m3.clear();

		for (int i = 0; i < n; i++) {
			m3[crr[i]]++;
		}

		for (int i = 0; i < n; i++) {
			crr[i] = m3[crr[i]];
		}

		m3.clear();

		for (int i = 0; i < n; i++) {
			m3[crr[i]]++;
		}

		for (int i = 0; i < n; i++) {
			crr[i] = m3[crr[i]];
		}

		


		for (int i = 0; i < n; i++) {
			drr[i] = m4[drr[i]];
		}

		m4.clear();

		for (int i = 0; i < n; i++) {
			m4[drr[i]]++;
		}

		for (int i = 0; i < n; i++) {
			drr[i] = m4[drr[i]];
		}

		m4.clear();

		for (int i = 0; i < n; i++) {
			m4[drr[i]]++;
		}

		for (int i = 0; i < n; i++) {
			drr[i] = m4[drr[i]];
		}

		m4.clear();

		for (int i = 0; i < n; i++) {
			m4[drr[i]]++;
		}

		for (int i = 0; i < n; i++) {
			drr[i] = m4[drr[i]];
		}

		


		for (int i = 0; i < n; i++) {
			err[i] = m5[err[i]];
		}

		m5.clear();

		for (int i = 0; i < n; i++) {
			m5[err[i]]++;
		}

		for (int i = 0; i < n; i++) {
			err[i] = m5[err[i]];
		}

		m5.clear();

		for (int i = 0; i < n; i++) {
			m5[err[i]]++;
		}

		for (int i = 0; i < n; i++) {
			err[i] = m5[err[i]];
		}

		m5.clear();

		for (int i = 0; i < n; i++) {
			m5[err[i]]++;
		}

		for (int i = 0; i < n; i++) {
			err[i] = m5[err[i]];
		}

		m5.clear();

		for (int i = 0; i < n; i++) {
			m5[err[i]]++;
		}

		for (int i = 0; i < n; i++) {
			err[i] = m5[err[i]];
		}


		


		for (int i = 0; i < n; i++) {
			sx[i] = m6[sx[i]];
		}

		m6.clear();

		for (int i = 0; i < n; i++) {
			m6[sx[i]]++;
		}

		for (int i = 0; i < n; i++) {
			sx[i] = m6[sx[i]];
		}

		m6.clear();

		for (int i = 0; i < n; i++) {
			m6[sx[i]]++;
		}

		for (int i = 0; i < n; i++) {
			sx[i] = m6[sx[i]];
		}

		m6.clear();

		for (int i = 0; i < n; i++) {
			m6[sx[i]]++;
		}

		for (int i = 0; i < n; i++) {
			sx[i] = m6[sx[i]];
		}

		m6.clear();

		for (int i = 0; i < n; i++) {
			m6[sx[i]]++;
		}

		for (int i = 0; i < n; i++) {
			sx[i] = m6[sx[i]];
		}

		m6.clear();

		for (int i = 0; i < n; i++) {
			m6[sx[i]]++;
		}

		for (int i = 0; i < n; i++) {
			sx[i] = m6[sx[i]];
		}

		


		for (int i = 0; i < n; i++) {
			svn[i] = m7[svn[i]];
		}

		m7.clear();

		for (int i = 0; i < n; i++) {
			m7[svn[i]]++;
		}

		for (int i = 0; i < n; i++) {
			svn[i] = m7[svn[i]];
		}

		m7.clear();

		for (int i = 0; i < n; i++) {
			m7[svn[i]]++;
		}

		for (int i = 0; i < n; i++) {
			svn[i] = m7[svn[i]];
		}

		m7.clear();

		for (int i = 0; i < n; i++) {
			m7[svn[i]]++;
		}

		for (int i = 0; i < n; i++) {
			svn[i] = m7[svn[i]];
		}

		m7.clear();

		for (int i = 0; i < n; i++) {
			m7[svn[i]]++;
		}

		for (int i = 0; i < n; i++) {
			svn[i] = m7[svn[i]];
		}

		m7.clear();

		for (int i = 0; i < n; i++) {
			m7[svn[i]]++;
		}

		for (int i = 0; i < n; i++) {
			svn[i] = m7[svn[i]];
		}

		m7.clear();

		for (int i = 0; i < n; i++) {
			m7[svn[i]]++;
		}

		for (int i = 0; i < n; i++) {
			svn[i] = m7[svn[i]];
		}

		


		for (int i = 0; i < n; i++) {
			eght[i] = m8[eght[i]];
		}

		m8.clear();

		for (int i = 0; i < n; i++) {
			m8[eght[i]]++;
		}

		for (int i = 0; i < n; i++) {
			eght[i] = m8[eght[i]];
		}

		m8.clear();

		for (int i = 0; i < n; i++) {
			m8[eght[i]]++;
		}

		for (int i = 0; i < n; i++) {
			eght[i] = m8[eght[i]];
		}

		m8.clear();

		for (int i = 0; i < n; i++) {
			m8[eght[i]]++;
		}

		for (int i = 0; i < n; i++) {
			eght[i] = m8[eght[i]];
		}

		m8.clear();

		for (int i = 0; i < n; i++) {
			m8[eght[i]]++;
		}

		for (int i = 0; i < n; i++) {
			eght[i] = m8[eght[i]];
		}

		m8.clear();

		for (int i = 0; i < n; i++) {
			m8[eght[i]]++;
		}

		for (int i = 0; i < n; i++) {
			eght[i] = m8[eght[i]];
		}

		m8.clear();

		for (int i = 0; i < n; i++) {
			m8[eght[i]]++;
		}

		for (int i = 0; i < n; i++) {
			eght[i] = m8[eght[i]];
		}

		m8.clear();

		for (int i = 0; i < n; i++) {
			m8[eght[i]]++;
		}

		for (int i = 0; i < n; i++) {
			eght[i] = m8[eght[i]];
		}

		


		for (int i = 0; i < n; i++) {
			nin[i] = m9[nin[i]];
		}

		m9.clear();

		for (int i = 0; i < n; i++) {
			m9[nin[i]]++;
		}

		for (int i = 0; i < n; i++) {
			nin[i] = m9[nin[i]];
		}

		m9.clear();

		for (int i = 0; i < n; i++) {
			m9[nin[i]]++;
		}

		for (int i = 0; i < n; i++) {
			nin[i] = m9[nin[i]];
		}

		m9.clear();

		for (int i = 0; i < n; i++) {
			m9[nin[i]]++;
		}

		for (int i = 0; i < n; i++) {
			nin[i] = m9[nin[i]];
		}

		m9.clear();

		for (int i = 0; i < n; i++) {
			m9[nin[i]]++;
		}

		for (int i = 0; i < n; i++) {
			nin[i] = m9[nin[i]];
		}

		m9.clear();

		for (int i = 0; i < n; i++) {
			m9[nin[i]]++;
		}

		for (int i = 0; i < n; i++) {
			nin[i] = m9[nin[i]];
		}

		m9.clear();

		for (int i = 0; i < n; i++) {
			m9[nin[i]]++;
		}

		for (int i = 0; i < n; i++) {
			nin[i] = m9[nin[i]];
		}

		m9.clear();

		for (int i = 0; i < n; i++) {
			m9[nin[i]]++;
		}

		for (int i = 0; i < n; i++) {
			nin[i] = m9[nin[i]];
		}

		m9.clear();

		for (int i = 0; i < n; i++) {
			m9[nin[i]]++;
		}

		for (int i = 0; i < n; i++) {
			nin[i] = m9[nin[i]];
		}

		


		for (int i = 0; i < n; i++) {
			tn[i] = m10[tn[i]];
		}

		m10.clear();

		for (int i = 0; i < n; i++) {
			m10[tn[i]]++;
		}

		for (int i = 0; i < n; i++) {
			tn[i] = m10[tn[i]];
		}

		m10.clear();

		for (int i = 0; i < n; i++) {
			m10[tn[i]]++;
		}

		for (int i = 0; i < n; i++) {
			tn[i] = m10[tn[i]];
		}

		m10.clear();

		for (int i = 0; i < n; i++) {
			m10[tn[i]]++;
		}

		for (int i = 0; i < n; i++) {
			tn[i] = m10[tn[i]];
		}

		m10.clear();

		for (int i = 0; i < n; i++) {
			m10[tn[i]]++;
		}

		for (int i = 0; i < n; i++) {
			tn[i] = m10[tn[i]];
		}

		m10.clear();

		for (int i = 0; i < n; i++) {
			m10[tn[i]]++;
		}

		for (int i = 0; i < n; i++) {
			tn[i] = m10[tn[i]];
		}

		m10.clear();

		for (int i = 0; i < n; i++) {
			m10[tn[i]]++;
		}

		for (int i = 0; i < n; i++) {
			tn[i] = m10[tn[i]];
		}

		m10.clear();

		for (int i = 0; i < n; i++) {
			m10[tn[i]]++;
		}

		for (int i = 0; i < n; i++) {
			tn[i] = m10[tn[i]];
		}

		m10.clear();

		for (int i = 0; i < n; i++) {
			m10[tn[i]]++;
		}

		for (int i = 0; i < n; i++) {
			tn[i] = m10[tn[i]];
		}

		m10.clear();

		for (int i = 0; i < n; i++) {
			m10[tn[i]]++;
		}

		for (int i = 0; i < n; i++) {
			tn[i] = m10[tn[i]];
		}

		


		ll q;
		cin >> q;

		while (q--) {
			ll a, b;
			cin >> a >> b;

			a -= 1;

			if (b == 0) {
				cout << arr[a] << endl;
				continue;
			}

			if (b == 1) {
				cout << frr[a] << endl;
				continue;
			}

			if (b == 2) {
				cout << brr[a] << endl;
				continue;
			}

			if (b == 3) {
				cout << crr[a] << endl;
				continue;
			}

			if (b == 4) {
				cout << drr[a] << endl;
				continue;
			}

			if (b == 5) {
				cout << err[a] << endl;
				continue;
			}

			if (b == 6) {
				cout << sx[a] << endl;
				continue;
			}

			if (b == 7) {
				cout << svn[a] << endl;
				continue;
			}

			if (b == 8) {
				cout << eght[a] << endl;
				continue;
			}

			if (b == 9) {
				cout << nin[a] << endl;
				continue;
			}

			cout << tn[a] << endl;
		}
	}

	return 0;
}
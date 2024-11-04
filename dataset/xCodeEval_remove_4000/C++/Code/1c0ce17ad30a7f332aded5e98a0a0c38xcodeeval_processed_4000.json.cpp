

using namespace std;


int main() {

	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll i, j, k, l, test, n;
	ll a[8007];
	cin>>test;
	while(test--) {
		ll m[8007]={0};
		cin>>n;
		for(i=0;i<n;i++) {
			cin>>a[i];
			m[a[i]]++;
		}
		ll cnt=0;
		for(i=0;i<n;i++) {
			ll t=a[i];
			for(j=i+1;j<n;j++) {
				t+=a[j];
				if(t>n) break;
				if(m[t]<=n+1) cnt+=m[t];
				m[t]=0;
			}
		}
		cout<<cnt<<"\n";
	}
}










































































































using namespace std;
 
int q, idx;
ll n, x, y;
vector<ll>p;
 
ll Good() {
	idx=lower_bound(p.begin(), p.end(), n)-p.begin();
	x = y = 0;
	
	for (int i = idx; i >= 0; --i)
		(x + p[i] <= n)?x += p[i]:y = p[i];
	x+=y;
	for(int i=idx;i>=0;--i)
		x-=p[i]*(x-p[i]>=n);
			
	return x;
}
int main() {
	for (ll i = 1; i <= 3e18; i+=i+i)
		p.push_back(i);
	
	scanf("%d", &q);
	while (q--) {
		scanf("%lld", &n);
		printf("%lld\n", Good());
	}
	return 0;
}

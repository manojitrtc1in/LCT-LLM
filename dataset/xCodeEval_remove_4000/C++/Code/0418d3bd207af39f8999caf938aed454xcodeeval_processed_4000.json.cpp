

using namespace std; 










int main(){
	ll n, x; 
	cin>>n>>x;
	ll a[n]; ll sum =0;
	for(int i =0 ;i<n; i++){cin>>a[i]; sum += a[i];}
	if(sum + n-1  == x)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
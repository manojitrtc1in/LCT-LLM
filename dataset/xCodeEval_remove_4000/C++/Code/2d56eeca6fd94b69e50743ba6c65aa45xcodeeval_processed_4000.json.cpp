



























using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,x,y;
		cin>>n>>x>>y;
		long long di=0,mi=0,ans1=0,ans2=0;
		string s1,s2;
		cin>>s1>>s2;
		int p[n];
		for(long long i=0;i<n;i++){
			if(s1[i]!=s2[i]){
				p[di]=i;
				di++;
			}
		}
		if(di%2!=0)cout<<-1<<endl;
		else{
		if(di==2&&p[1]-p[0]==1){
			ans1=x;
			ans2=y*2;
			cout<<min(ans1,ans2)<<endl;
		}
		else {
			ans1=di/2*y;
		cout<<ans1<<endl;}
		}
	}
}


using namespace std;






































































































































int binpow (int a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow (a, n-1) * a;
	else {
		int b = binpow (a, n/2);
		return b * b;
	}
}






int a,b,c,n,m,i,j,k,x,y,cnt=0,sum=0,res=0;
void solve(){
	cin>>n>>k;
	if(k>(n+1)/2){
		cout<<-1<<endl;
		return;
	}
	vector<string> ar(n, string(n,'.'));
	for(i=0;i<k;i++){
		ar[i*2][i*2]='R';
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(ar[i][j]=='R')
				cout<<'R';
			else
				cout<<'.';
		}
		cout<<endl;
	}
}
main(){
	int T=1;
	cin>>T;
	while(T--){
		solve();
	}
}



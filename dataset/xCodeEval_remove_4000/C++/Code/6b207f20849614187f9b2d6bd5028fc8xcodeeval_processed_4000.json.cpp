
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
	string s,s1;
	cin>>n>>s;
	s1=s[0];
	for(i=1;i<s.size();i++){
		if(s[i-1]>s[i])
			s1+=s[i];
		else  if(s[i-1]==s[i] && i>1)
			s1+=s[i];
		else
			break;
	}
	cout<<s1;
	reverse(all(s1));
	cout<<s1<<endl;
}
main(){
	int T=1;
	cin>>T;
	while(T--){
		solve();
	}
}



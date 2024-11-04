








using namespace std;


















void debug_arr(vector<int> &a){
	int len = a.size();
	fr(i,0,len){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}


const int  mod = 1e9 +7;
const int mod1= 998244353;




int n,k;string s,ans;
void solve(){ 
cin>>n>>k>>s;

fr(i,0,n){
	ans+=s[i%k];
}

if(ans<s){
	fr1(i,k-1,-1){
		if((s[i]=='9')){s[i] = '0'; }
		else {s[i] = (s[i]+1); break;}
	}
}
cout<<n<<endl;
fr(i,0,n){
	cout<<s[i%k];
}
cout<<endl;
  
  return;} 




signed main() {
	

	fast
	

	{solve();}
	
	return 0;
}























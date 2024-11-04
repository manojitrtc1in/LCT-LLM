








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




void solve(){ 
int n; cin>>n;
v(int) a(n);
int mxsum=0;
fr(i,0,n){
	cin>>a[i];
	if(!(i&1))mxsum+=a[i];
}

if(n==1) {cout<<a[0]<<endl; return;}
if(n==2) {cout<<max(a[0],a[1])<<endl; return;}



v(int) odd; 

v(int) even; 

fr(i,0,n-1){

	even.pb(a[i+1]-a[i]); i++;
}
fr(i,1,n-1){

	odd.pb(-a[i+1]+a[i]); i++;
}






int x,y;
x=y=even[0];
int ans=x;
fr(i,1,even.size()){
	y = max(x+even[i], even[i]);
	ans= max(ans,y);
	x=y;
}

x=y=odd[0];ans=max(ans,y);
fr(i,1,odd.size()){
	y = max(x+odd[i], odd[i]);
	ans=max(ans,y);
	x=y;
}
if(ans<0) ans=0;
 mxsum+=ans;
cout<<mxsum<<endl;  
  return;} 




signed main() {
	

	fast
	int t; cin>>t; while(t--)
	{solve();}
	
	return 0;
}























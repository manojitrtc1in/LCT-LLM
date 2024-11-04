









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
int n,d,m; cin>>n>>d>>m;
v(int) a(n);
v(int) small,big;
int x; 
fr(i,0,n) {
	cin>>x;
	if(x>m) big.pb(x);
	else small.pb(x);
} 
sort(big.begin(),big.end(), greater<int>());
sort(small.begin(),small.end(), greater<int>());
fr(i,1,big.size()) big[i]+=big[i-1];
fr(i,1,small.size()) small[i]+=small[i-1];
int ans = INT_MIN;




if(big.size()==0)  ans = small[n-1];
for(int b = 1; b<=big.size();++b){
	

	int b_days = (b-1)*(d+1)+1;
	int tmp_ans;
	if(b_days>n) break;
	else if(b_days == n) tmp_ans = big[b-1];
	else {
		tmp_ans = big[b-1];
		int s_days = n-b_days; 

		

		if(s_days<=small.size()) tmp_ans+=small[s_days-1];
		else if(small.size()>0) tmp_ans+=small[small.size()-1];

	}
	
    ans = max(ans,tmp_ans);
}
p1(ans);
return;} 




signed main() {
	

	fast
	

	{solve();}
	
	return 0;
}
























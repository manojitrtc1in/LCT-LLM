







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
int n, m, k;
cin>>n>>m>>k;

if(!k){

	cout<<(m*(m-1)/2)<<endl;
	fr(i,1,m+1){
		fr(j,i+1,m+1){
			cout<<i<<" "<<j<<endl;
		}
	}

}
else {

	cout<<(m*(m-1)/2)<<endl;
	fr1(i,m,0){
		fr(j,1,i){
			cout<<i<<" "<<j<<endl;
		}
	}


}

 
  
  return;} 




signed main() {
	

	

	{solve();}
	
	return 0;
}






















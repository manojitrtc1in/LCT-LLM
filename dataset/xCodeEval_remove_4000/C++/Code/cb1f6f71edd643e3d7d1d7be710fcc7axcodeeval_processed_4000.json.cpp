











using namespace std;

void id0(){
	int n, m; cin>>n>>m; 
	int c[n+1]={0};
	forn(i, 0, m){
		int k; cin>>k; c[k]++;
	}
	int minn=mod;
	forn(i,1, n+1) minn=min(minn, c[i]);
	cout<<minn;
}
void id1(){
	int n, k; cin>>n>>k;
	ll a[n];
	forn(i, 0, n) cin>>a[i];
	ll dp[n]={0};
	int t; cin>>t; dp[0]=t*a[0];
	forn(i, 1, n){
		cin>>t;
		dp[i]=dp[i-1]+t*a[i];
	}
	forn(i, 1, n) a[i]+=a[i-1];
	ll maxx=a[k-1]+dp[n-1]-dp[k-1];
	for(int i=k; i<n; i++){
		maxx=max(maxx, dp[i-k]+a[i]-a[i-k]+dp[n-1]-dp[i]);
	}
	cout<<maxx;	
}
void id2(){
	int n; cin>>n;
	vector<vector<string> >chess(4, vector<string>(n));
	for(int i=0; i<4; i++){
		for(int j=0; j<n; j++)	cin>>chess[i][j];
	}
	int perm[4]={0, 1, 2, 3};
	int ans=mod;
	do{
		vector<vector<string> >temp=chess;
		int keep =0, not_keep=0;
		for(int i=0; i<4; i++){
			for(int j=0; j<n; j++){
				for(int k=0; k<n; k++){
					if (k+1<n && temp[perm[i]][j][k]==temp[perm[i]][j][k+1]){
						temp[perm[i]][j][k+1]=(temp[perm[i]][j][k+1]=='0'?'1':'0');
						keep++;
					}
					else if (k+1==n && i!=1 && i!=3 && temp[perm[i]][j][k]==temp[perm[i+1]][j][0]){							
						temp[perm[i+1]][j][0]=(temp[perm[i+1]][j][0]=='0'?'1':'0');
						keep++;
					}
					if (j+1<n && temp[perm[i]][j][k]==temp[perm[i]][j+1][k]){
						temp[perm[i]][j+1][k]=(temp[perm[i]][j+1][k]=='0'?'1':'0');
						keep++;
					}
					else if (j+1==n && i!=2 && i!= 3 && temp[perm[i]][j][k]==temp[perm[i+2]][0][k]){
						temp[perm[i+2]][0][k]=(temp[perm[i+2]][0][k]=='0'?'1':'0');
						keep++;
					}
				}
			}	
		}
		temp=chess;
		temp[0][0][0]=(temp[0][0][0]=='0'?'1':'0');
		not_keep=1;
		for(int i=0; i<4; i++){
			for(int j=0; j<n; j++){
				for(int k=0; k<n; k++){
					if (k+1<n && temp[perm[i]][j][k]==temp[perm[i]][j][k+1]){
						temp[perm[i]][j][k+1]=(temp[perm[i]][j][k+1]=='0'?'1':'0') ; 

						not_keep++;
					}
					else if (k+1==n && i!=1 && i!=3 && temp[perm[i]][j][k]==temp[perm[i+1]][j][0]){							
						temp[perm[i+1]][j][0]=(temp[perm[i+1]][j][0]=='0'?'1':'0');
						not_keep++;
					}
					if (j+1<n && temp[perm[i]][j][k]==temp[perm[i]][j+1][k]){
						temp[perm[i]][j+1][k]=(temp[perm[i]][j+1][k]=='0'?'1':'0');
						not_keep++;
					}
					else if (j+1==n && i!=2 && i!= 3 && temp[perm[i]][j][k]==temp[perm[i+2]][0][k]){
						temp[perm[i+2]][0][k]=(temp[perm[i+2]][0][k]=='0'?'1':'0');
						not_keep++;
					}
				}
			}	
		}
	

		ans=min(ans, min(keep, not_keep));
	}
	while(next_permutation(perm, perm+4));
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	id2();
}



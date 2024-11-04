











using namespace std;


void id6(){
	int n; cin>>n; 
	ll arr[n], maxx=eps;
	vector<int>cnt(1001001);
	for(int i=0; i<n; i++){
		cin>>arr[i]; maxx=max(maxx, arr[i] ); cnt[arr[i]]++;
		for(int j=2; j*j<=arr[i]; j++){
			if (arr[i]%j==0){
				cnt[j]++;
				if (j*j!=arr[i]) cnt[arr[i]/j]++;
			}
		}
	}
	
	vector<ll>power(1001001); power[0]=1;
	for(int i=1; i<1001001; i++) power[i]=(power[i-1]*2)%mod;
	vector<ll>dp(1001001); ll ans=0;
	for(long long i=maxx;i>=2;--i)
    {
        long long minus=0;
        if(cnt[i]>0)
        {
            if(i<=maxx/2)
            for(long long j=2*i;j>0&&j<=maxx;j+=i)
                minus=minus+dp[j];
            dp[i]=(cnt[i]*power[cnt[i]-1])%mod;
            dp[i]-=minus;
           dp[i]=(dp[i]%mod+mod)%mod;
            ans=(ans+(i*dp[i])%mod)%mod;
        }
        else
            dp[i]=0;
        
    }

	
	cout<<ans;
}
void id10(){
	int n, T;
	cin>>n>>T;
	
	vector<pair<ll, ll> >at(n);
	forn(i, 0, n) cin>>at[i].second;
	forn(i, 0, n) cin>>at[i].first;
	ll summ=0;
	ll d=0;
	forn(i, 0, n) summ+=at[i].first*at[i].second, d+=at[i].second;
	sort(at.begin(), at.end());
	if (summ>T*d) reverse(at.begin(), at.end());
	if (summ==T*d) {cout<<d; return;}
	bool side=(summ>T*d);
	for(int i=0; i<n; i++){
		

		summ-=at[i].first*at[i].second;
		d-=at[i].second;
		if (side && summ<=T*d){
			double val=(double)(summ-T*d)/(T-at[i].first);
			if (val>=0){
				cout<<setprecision(15)<<val+d;
				return;
			}
		}
		else if (!side && summ>=T*d){
			double val=(double)(summ-T*d)/(T-at[i].first);
			if (val>=0){
				cout<<setprecision(15)<<val+d;
				return;
			}
		}
	}
	cout<<0;
}
void id14(){
	int n, k ; cin>>n>>k;
	int a[5]={0};
	int have[5]={0};
	have[2]=2*n; have[4]=n;
	forn(i , 0, k){
		int x; cin>>x;
		while(x>=3){
			if (have[4]) have[4]--, x-=4;
			else if (have[2]) have[2]--, x-=2;
			else {
				cout<<"NO";
				return;
			}
		}
		if (x>0) a[x]++;
	}
	while(a[2]){
		if (have[2]) have[2]--, a[2]--;
		else if (have[4]) have[4]--, a[2]--, have[1]++;
		else a[2]--, a[1]+=2;
	}
	cout<<(a[1]>have[1]+have[2]+2*have[4]? "NO":"YES");
	
}
void id22(){
	ll n;double summ=0, T;
	cin>>n>>T;
	vector<pair<double, double> >at(n);
	forn(i, 0, n) cin>>at[i].second;
	forn(i, 0, n) cin>>at[i].first;
	forn(i, 0, n) {
		at[i].first-=T;
		summ+=at[i].first*at[i].second;
	}
	int high=n-1, low=0;
	sort(at.begin(), at.end());	
	int where=(summ>eps?1:0);
	while (fabs(summ)>eps){
		
		if (where){
			if (at[high].first<=0 || high<0){
				cout<<0; return;
			}
			else {
				double phi=summ/(at[high].first);
				if ((at[high].second-phi)>eps){
					summ=0;
					at[high].second-=phi;
					break;
				}
				else{
					summ-=at[high].second*at[high].first;
					at[high].second=0;
				}
			}
			high--;
		}
		else {
			if (at[low].first>=0 || low >=n){
				cout<<0; return;
			}
			else {
				double phi=summ/(at[low].first);
				if (eps<at[low].second-phi){
					summ=0;
					at[low].second-=phi;
					break;
				}
				else{
					summ-=at[low].second*at[low].first;
					at[low].second=0;
				}
			}
			low++;
		}
	}
	double ans=0;
	for(auto a: at) ans+=a.second;
	cout<<setprecision(15)<<ans;
}
void id11(){
	int n, m, s, t, l, r;;
veci arr[1001];
int arr1[1001][1001], visited[1001]={0};
veci len_s(1001, 1000000000), len_t(1001, 1000000000);

	memset(arr1, 0, sizeof arr1);
	cin>>n>>m>>s>>t;
	forn(i, 0, m){
		cin>>l>>r;
		arr[r].pb(l);
		arr[l].pb(r);
		arr1[l][r]=1; arr1[r][l]=1;
	}
	queue<int>bfs;
	len_s[s]=0;
	for(auto a: arr[s]){
		bfs.push(a);
		len_s[a]=1;
	}
	visited[s]=1;
	while(!bfs.empty()){
		int node=bfs.front();
		bfs.pop();
		if (visited[node]) continue;
		visited[node]=1;
		for(auto a: arr[node]){
			len_s[a]=min(len_s[a], len_s[node]+1);
			if (!visited[a]) bfs.push(a);
		}
	}
	memset(visited, 0, sizeof visited);
	len_t[t]=0;
	for(auto a: arr[t]){
		bfs.push(a);
		len_t[a]=1;
	}
	visited[t]=1;
	while(!bfs.empty()){
		int node=bfs.front();
		bfs.pop();
		if (visited[node]) continue;
		visited[node]=1;
		for(auto a: arr[node]){
			len_t[a]=min(len_t[a], len_t[node]+1);
			if (!visited[a]) bfs.push(a);
		}
	}
	

	int ans=0, D=len_s[t];
	for(int u=1; u<=n; u++){
		for(int v=u+1; v<=n; v++){
			if (!arr1[u][v] && len_s[u]+len_t[v]+1>=D && len_t[u]+len_s[v]+1>=D){
			
				ans++;
			}
		}
	}
	cout<<ans;
}
void id2(){
	int n; cin>>n;
	int arr[n];
	forn(i, 0, n) cin>>arr[i];
	bool flag=0; int gap=-1, maxx=arr[n-1];
	forn(i, 0, n-1){
		maxx=max(maxx, arr[i]);
		if (arr[i+1]==arr[i]){
			cout<<"NO";
			return;
		}
		if (abs(arr[i+1]-arr[i])!=1){
			if (!flag){
				flag=1;
				gap=abs(arr[i+1]-arr[i]);
			}
			else if(gap!=abs(arr[i+1]-arr[i])){
				cout<<"NO";
				return;
			}
		}
	}
	if (flag){
		forn(i, 0, n-1){
			if (abs(arr[i]-arr[i+1])==1 && arr[i]==arr[i+1]-1 && arr[i]%gap==0){
				cout<<"NO\n";
				return;
			}
			else if (abs(arr[i]-arr[i+1])==1 && arr[i]==arr[i+1]+1 && arr[i+1]%gap==0){
				cout<<"NO\n";
				return;
			}
		}
	}
	if (flag){
		cout<<"YES\n"<<(maxx/gap + maxx%gap)<<' '<<gap;
	}
	else cout<<"YES\n"<<1<<' '<<maxx;
}
void id7(){
	int n; cin>>n; 
	string s; cin>>s;
	for(int i=n/2; i>0; i--){
		if (s.substr(0, i)==s.substr(i, i)){
			cout<<n-i+1;
			return;
		}
	}
	cout<<n;
}
void id12(){
	int  n; cin>>n; 
	int ans=n;
	string s; cin>>s;
	int i=0;
	while(i<n-1){
		if (s.substr(i, 2)=="UR"||s.substr(i, 2)=="RU"){
			ans--;
			i+=2;
		}
		else i++;
	}
	cout<<ans;
}
void id8(){
	string s; cin>>s;
	map<char, int>present;
	for(auto a: s){
		present[a]++;
	}
	if (present.size()>4 ||  present.size()==1){
		cout<<"No";
	}
	else if (present.size()==4){
		cout<<"Yes";
	}
	else if (present.size()==3){
		bool flag=false;
		for(auto a: present){
			if (a.second>=2) {
				flag=true;
				break;
			}
		}
		if (flag) cout<<"Yes";
		else cout<<"No";
	}
	else{
		bool f1=0, f2=0;
		for(auto a: present){
			if (a.second>=2){
				if (f1){
					f2=1; break;
				}
				else f1=1;
			}
		}
		cout<<(f1 && f2 ?"Yes":"No");
	}
}
void id5(){
	int hh, mm; cin>>hh>>mm;
	cout<<setprecision(10);
	ll h, d, c, n; cin>>h>>d>>c>>n;
	if (hh>=20) {
		double k=(h*c);
		k=(double)k/n;
		double ans=0.8*k;
		cout<<ans;
	}
	else{
		int t=20*60-hh*60-mm;
		double ans1=h+t*d; ans1*=(double)c;
		
		ans1=(double)ans1/n;
		ans1*=0.8;
		

		double ans2=((h/n)+(h%n==0?0:1))*c;
		cout<<min(ans1, ans2);
		

	}
	
}
ll id1(int i, int j){
}
void id3(){
	
}
void id19(int l, int r){
	
}
void id17(){
	
	
}
void id9(){
	string s; 
	while (cin>>s){
	if (s.length()==0) {
		cout<<0; break;
	}
	int cnt=0;
	int prefix[s.length()]={0};
	prefix[0]=(s[0]=='>'?1:0);
	for(int i=1; i<s.length(); i++){
		if (s[i]=='>'){
			if (prefix[i-1]<=2)prefix[i]=min(prefix[i-1]+1, 2);
			else if (prefix[i-1]==4) cnt++, prefix[i]=1;
			else prefix[i]=1;
		}
		else if (s[i]=='<') prefix[i]=0;
		else if (prefix[i-1]>=2 && prefix[i-1]<4) prefix[i]=prefix[i-1]+1;
		else prefix[i]=0;
	}
	memset(prefix, 0, sizeof prefix);
	prefix[s.length()-1]=(s.back()=='<'?1:0);
	for(int i=s.length()-2; i>=0; i--){
		if (s[i]=='<'){
			if (prefix[i+1]<=2)prefix[i]=min(prefix[i+1]+1, 2);
			else if (prefix[i+1]==4) cnt++, prefix[i]=1;
			else prefix[i]=1;
		}
		else if (s[i]=='>') prefix[i]=0;
		else if (prefix[i+1]>=2 && prefix[i+1]<4) prefix[i]=prefix[i+1]+1;
		else prefix[i]=0;
	}
	cout<<cnt;}
}
void id0(){
	int n, m; scanf("%d%d", &n, &m);
	int x[]={1,-1,0,0};
	int y[]={0, 0, 1, -1};
	int graf[n+1][m+1];
	forn(i, 0, n+1){
		forn(j, 0, m+1) graf[i][j]=1000;
	}
	int a[n+1][m+1];
	memset(a, 0, sizeof a);
	int bfs[100000];
	memset(bfs, -1, sizeof bfs);
	int begin=0, end=0;
	for(int i=0; i<n; i++){
		forn(j, 0, m){
			int t; scanf("%d", &t); 
			if (t){
				graf[i+1][j+1]=0;
				bfs[end]=(m*i+j);
				end++;
			}
		}
	}
	while(begin<end){
		int node =bfs[begin];
		begin++;
		if (a[node/m +1][node%m +1]) continue;
		a[node/m +1][node%m +1]=1;
		forn(i, 0, 4){
			int p=node/m +1 +x[i], q=node%m + 1+y[i];
			if (p<=0 || p>n || q<=0 || q>m) continue;
			graf[p][q]=min(graf[p][q], graf[node/m +1][node%m +1]+1);
			if (a[p][q]) continue;
			else bfs[end]=((p-1)*m+q-1), end++;
		}
	}
	for(int i=1; i<=n; i++){
		forn(j, 1, m+1) printf("%d ", graf[i][j]); 
		printf("%c", '\n');
	}
}
void id13(){
	int n, m , k;
	cin>>n>>m>>k;
	map<pair<int, int> , ll>len;
	vec_2di graph(n+1);
	forn(i, 0, m){
		int l , r; ll lenn;
		cin>>l>>r>>lenn;
		len[{l, r}]=(len[{l, r}]>0?min(lenn, len[{l, r}]):lenn);
		len[{r, l}]=(len[{r, l}]>0?min(lenn, len[{r, l}]):lenn);
		graph[l].pb(r);
		graph[r].pb(l);
	}
	veci forbidden;
	int a[n+1]={0};
	forn(i, 0, k){
		int t; cin>>t;
		a[t]++; forbidden.pb(t);
	}
	ll ans=INF;
	for(auto i: forbidden){
		for(auto j: graph[i]){
			if (!a[j]) ans=min(ans, len[{i, j}]);
		}
	}
	cout<<(ans==INF?-1:ans);
}
void id18(){
	int n, m; cin>>n>>m;
	if (m<=n) cout<<n-m; 
	else {
		int cnt=0;
		while(m!=n){
			if (m%2==0 && m>n) m/=2, cnt++;
			else m++, cnt++;
		}
		cout<<cnt;
	}
}
void id15(){
	string s; 
	cin>>s;
	ll letters[27]={0};
	for(auto a: s) letters[a-96]++;
	ll ans=0;
	forn(i, 1, 27){
		if (!letters[i]) continue;
		forn(j, i+1, 27) ans+=(j-i)*letters[j]*letters[i];
		
	}
	cout<<ans*(ll)s.length();	
}
void id16(){
	ll n, m; cin>>n>>m;
	ll T[n];
	forn(i, 0, n) cin>>T[i];
	ll dp[n]={0}; dp[0]=T[0];
	forn(i, 1, n){
		dp[i]=dp[i-1]+T[i];
	}
	cout<<T[0]*m<<'\n';
	ll gap=T[0];
	forn(i, 1, n){
		gap=max(gap, T[i]);
		cout<<dp[i]+gap*(m-1)<<' '<<gap*(m-1)<<'\n';
	}
}
void id4(int node){
	
}
void id20(){

}
void id21(){
	int n; cin>>n;
	vecl arr(n);
	forn(i, 0, n) cin>>arr[i];
	forn(i, 1, n) arr[i]+=arr[i-1];
	if (arr[n-1]%n==0) cout<<n;
	else cout<<n-1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	id6();
}
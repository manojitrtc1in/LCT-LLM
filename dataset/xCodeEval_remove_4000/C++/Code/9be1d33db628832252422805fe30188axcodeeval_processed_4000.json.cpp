




using namespace std;











typedef long long int ll;
typedef  vector<ll> vll;
typedef priority_queue<ll, vector<ll>, greater<ll> > min_pq;
typedef priority_queue<ll> max_pq;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}




















































































































































































































































































































































































































































































































string id1(string a, string b)
{
	

    int n = a.length();
    int m = b.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++){
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    debug(dp);
    string result = "";
    int i = n;
    int j = m;
    while (i > 0 && j > 0){
        if (a[i - 1] == b[j - 1]) {
            result+=a[i - 1];
            i--;
            j--;
        }else{
            if (dp[i - 1][j] >= dp[i][j - 1]) {
                result+=a[i - 1];
                i--;
            }else{
                result+=b[j - 1];
                j--;
            }
        }
    }
    while(i > 0){
        result+=a[i - 1];
        i--;
    }
    while(j > 0){
        result+=b[j - 1];
        j--;
    }
    reverse(result.begin(),result.end());
    return result;
}


void id6()
{
	vector<string>s1={"3234.html", "xys.html", "7hsaa.html"};
	vector<string>s2={"3234.html", "sdhsfjdsh.html", "xys.html", "7hsaa.html"};

	int n = s1.size();
	int m = s2.size();

	vector<vector<int>>dp(n+1,vector<int>(m+1,0));

	int ans = 0;
	int index ;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			if(dp[i][j] > ans){
				ans = dp[i][j];
				index = i-1;
			}
		}
	}
	vector<string>result;
	debug(ans,index);
	for(int i=index-ans+1;i<=index;i++){
		result.pb(s1[i]);
	}
	debug(result);
	debug(dp);

}
void id9(){
	unordered_set<string>id5={"3123122444","234111110", "8321125440", "99911063"};
	vector<string>id2={
		 "IP_Address,Time,Ad_Text",
 "122.121.0.1,2016-11-03 11:41:19,Buy wool coats for your pets",
 "96.3.199.11,2016-10-15 20:18:31,2017 Pet Mittens",
 "122.121.0.250,2016-11-01 06:13:13,The Best Hollywood Coats",
 "82.1.106.8,2016-11-12 23:05:14,Buy wool coats for your pets",
 "92.130.6.144,2017-01-01 03:18:55,Buy wool coats for your pets",
 "92.130.6.145,2017-01-01 03:18:55,2017 Pet Mittens",
	};

	vector<string>id4={
 "User_ID,IP_Address",
  "2339985511,122.121.0.155",
 "234111110,122.121.0.1",
 "3123122444,92.130.6.145",
 "39471289472,2001:0db8:ac10:fe01:0000:0000:0000:0000",
 "8321125440,82.1.106.8",
 "99911063,92.130.6.144"		
	};

	unordered_map<string,string>u_map;
	for(int i=1;i<id4.size();i++){
		string user_mapping = id4[i];
		int comma_index = user_mapping.find(',');
		string user_id = user_mapping.substr(0,comma_index);
		string ip = user_mapping.substr(comma_index+1);
		u_map[ip]=user_id;
	}
	debug(u_map);
	unordered_map<string,vector<string>>ads;
	for(int i=1;i<id2.size();i++){
		string ad_click = id2[i];
		int id8 = ad_click.find(',');
		string ip = ad_click.substr(0,id8);
		string ad_details = ad_click.substr(id8+1);
		int id0 = ad_details.find(',');
		string ad_desc = ad_details.substr(id0+1);
		ads[ad_desc].push_back(ip);
	}
	vector<string>result;
	result.push_back("Bought Clicked Ad Text");
	for(auto i: ads){
		string ad = i.first;
		int total_count = i.second.size();
		int buy_count=0;
		for(string ip: i.second){
			string user_id = u_map[ip];
			if(id5.find(user_id) != id5.end())
				buy_count++;
		}
		string output="";
		output+=to_string(buy_count);
		output+=" of ";
		output+=to_string(total_count);
		output+=" ";
		output+=ad;
		result.push_back(output);
	}
	for(auto l:result){
		cout<<l<<endl;
	}


}

void badgeAccess(){
	vector<vector<string>>entries= {
	  {"Paul",     "enter"},
	  {"Paul",     "exit"} ,
	  {"Paul",     "exit"} ,
	  {"Paul",     "enter"}
	};

	  unordered_map<string,int>logs,enter,exit;
	  
	  for(vector<string>entry: entries){
	  	string name = entry[0];
	  	string status = entry[1];
	  	if(status == "exit"){
	  		if(logs[name]!=1)
	  			enter[name]++;
	  		logs[name]=0;
	  	}else{
	  		if(logs[name]!=0)
	  			exit[name]++;
	  		logs[name]=1;
	  	}


	  }

	  for(auto x:logs){
	  	if(x.second>0)
	  		exit[x.first]++;
	  }
	  debug(exit);
	  debug(enter);

}

bool isSafe(int i,int j,int n,int m,vector<vector<char>>&grid,char ch){
	if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=ch)
		return false;
	return true;
}

bool dfs(vector<vector<char>>&grid,int i,int j,int n,int m,int index,string str,int length,
	vector<pair<int,int>>&result){
	if(index  + 1== length ){
		result.push_back({i,j});
		return true;
	}
	result.push_back({i,j});
	grid[i][j]='*';
	if(isSafe(i+1,j,n,m,grid,str[index+1]) && dfs(grid,i+1,j,n,m,index+1,str,length,result))
		return true;
	if(isSafe(i,j+1,n,m,grid,str[index+1]) && dfs(grid,i,j+1,n,m,index+1,str,length,result))
		return true;
	
	grid[i][j]=str[index];
	result.pop_back();
	return false;
}

void createWord(){
	vector<vector<char>>grid= {
	{ 'c', 't', 'n', 'a', 'x'},
	{ 'c', 'c', 'a', 't', 'n'},
	{ 'c', 'a', 'b', 'g', 'c'},
	{ 'c', 't', 'e', 'e', 'c'},
	{ 'd', 'h', 'n', 'g', 's'}
};

	string word = "cccc";
	
	int n = grid.size();
	int m = grid[0].size();
	int index  = 0;
	int length = word.length(); 
	bool flag = false;

	vector<pair<int,int>>result;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(word[index]==grid[i][j])
				if(dfs(grid,i,j,n,m,index,word,length,result)){
					flag=true;
					

					break;
				}
		}
	}
	if(flag==true)debug(result);
}











	





















































































































	
















	




















































    




























    
























































































































	    




































































































  































































































































































































































































	















































void solve(){

	ll n,k;
	cin>>n>>k;	
	ll vec[n];
	map<ll,ll>id7;
	map<ll,ll>id3;
	loop(i,0,n) {
		cin>>vec[i];
		if(id7.find(vec[i]) == id7.end()) {
			id7[vec[i]]=i;
			id3[vec[i]]=i;
		}
		id7[vec[i]]=min(id7[vec[i]],i);
		id3[vec[i]]=max(id3[vec[i]],i);
	}
	ll a,b;
	loop(i,0,k){
		cin>>a>>b;
		if(id7.find(a)==id7.end() || id3.find(b)==id3.end()) {
			cout<<"NO\n";
			continue;
		}
		ll ele1 = id7[a];
		ll ele2 = id3[b];
		if(ele1 > ele2) {
			cout<<"NO\n";
		}else{
			cout<<"YES\n";
		}

	}

}
int main()
{

	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while (t--)
	{
		solve();
	}

	return 0;
}
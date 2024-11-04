#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mk make_pair
#define pb push_back
#define int long long
#define pii pair<int,int>
#define all(s) s.begin(),s.end()
#define allr(s) s.rbegin(),s.rend()
const int N = 5e5+12,INF = 1e15+7,mod = 1e9+7;
int n,m,k,s,f,c,x,y,z,o,l,r,mx=0,mn=INF,ok,ans;
bool iswowel(char n){ n = toupper(n); if(n == 'A' || n == 'O' || n == 'U' || n == 'E' || n == 'I' || n == 'Y') return true; else return false;}
int a[N],b[N],dp[N],used[N],dis[N],lp[N];
vector<int>g[N],pr[N];
string p,pp;

void dfs(int v,int d){
	used[v] = 1;
	for(int to : g[v])
		if(!used[to])
			dfs(to,d+1);
}

main(){

    cin>>o;
    while(o--){
    	cin>>n;
    	map<int,int>mp;
    	set<int>q;
    	
    	for(int i=1; i<=n; i++){
    		cin>>x;
    		mp[x]++;
    		q.insert(x);
		}
		for(auto i : q){
			cout<<i<<" ";
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}for(int i : q){
			if(mp[i] > 1){
				cout<<i<<" ";
				mp[i]--;
			}
		}
		cout<<endl;
	}
    

}
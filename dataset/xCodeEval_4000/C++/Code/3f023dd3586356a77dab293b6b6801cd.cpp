#include <bits/stdc++.h>
using namespace std;

	


#define ll long long
#define pii pair<ll, ll> 
#define vii vector<pii> 
#define pb push_back 
#define fi first 
#define el cout<<endl
#define se second 
#define in(a) cin>>  a;
#define out(a) cout<<  a;
#define all(x) (x).begin(), (x).end()
#define rep(a) for(int i = 0; i < (a); i++)
#define vll vector<ll> 
#define vi vector<int >
#define ms(a,n) memset(a,n,sizeof(a))
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FOD(i,b,a) for(int i=b;i>=a;i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
const ll MOD = 1e9 + 7;

string s ;
void solve(){
	

	cin>>s  ;
	map<string,int> mp;
	int dem =0;
	for(int i='a';i<='z';i++){
		for(int j='a';j<='z';j++){
			 string tmp ="";
			if(i==j){
				continue;
			}else{
				tmp+=i;
				tmp+=j;
				mp[tmp]=++dem;
			}
		}
	}
	cout<< mp[s]<<endl;
	mp.clear();

}

int main()
{

	faster;
	int t ;
	cin>>t;
	cin.ignore();
	while(t--){
		solve();
	}	

}
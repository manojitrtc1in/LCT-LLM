#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define map unordered_map
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define inf 10000000000000
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
using namespace std;
int power(int x, unsigned int y){int res = 1;while (y > 0){ if (y & 1){res = res*x;} y = y>>1;x = x*x;}return res;}
int powermod(int x, unsigned int y, int p){int res = 1;x = x % p;while (y > 0){if (y & 1){res = (res*x) % p;}y = y>>1; x = (x*x) % p;}return res;}
int Mod(int x, int m){ return (x%m+m)%m;}
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}


















































const int mxn = 1e5+5;
    int freq[mxn];
int arr[mxn];
int n;
int bs=300;

int32_t main()
{

    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    #endif

    fastio;
    int m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    	if(arr[i]>100000){
    		arr[i] =0 ;
    	}
    }
   
    vector<pair<pair<int,int>,int>>v;
    for(int i=0;i<m;i++){
    	int a,b;
    	cin>>a>>b;
    	a--;
    	b--;
    	v.pb(mp(mp(a,b),i));
    }
    sort(all(v),[](pair<pair<int,int>,int> &a,pair<pair<int,int>,int> &b) -> bool{
		if(a.f.f/bs!=b.f.f/bs)
			return a.f.f<b.f.f;
		else{
			return a.f.s<b.f.s;
		}
	});
    int l =  0;
    int r = -1;
    for(int i=0;i<mxn;i++){
    	freq[i] = 0;
    }
    int ans = 0;
    freq[0] = 1000;
    vector<int>res(m+1);
    for(int i=0;i<m;i++){
       int low = v[i].f.f;
       int high = v[i].f.s;
       while(l<low){
       	  if(freq[arr[l]]==arr[l]){
       	  	ans--;
       	  }
       	  freq[arr[l]]--;
       	  if(freq[arr[l]]==arr[l]){
       	  	ans++;
       	  }
       	  l++;
       }
       while(l>low){
       	  l--;
       	  if(freq[arr[l]]==arr[l]){
       	  	ans--;
       	  }
       	  freq[arr[l]]++;
       	  if(freq[arr[l]]==arr[l]){
       	  	ans++;
       	  }
       }
       while(r<high){
       	  r++;
       	  if(freq[arr[r]]==arr[r]){
       	  	ans--;
       	  }
       	  freq[arr[r]]++;
       	  if(freq[arr[r]]==arr[r]){
       	  	ans++;
       	  }
       }
       while(r>high){
       	  if(freq[arr[r]]==arr[r]){
       	  	 ans--;
       	  }
       	  freq[arr[r]]--;
       	  if(freq[arr[r]]==arr[r]){
       	  	ans++;
       	  }
       	  r--;
       }
       res[v[i].s] = ans;
    }
   for(int i=0;i<m;i++){
   	  cout<<res[i]<<endl;
   } 
  return 0;
}





#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define endl "\n"
#define vll vector<ll>
#define ff first 
#define ss second 
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);

int main(){
	ll n, x; 
	cin>>n>>x;
	ll a[n]; ll sum =0;
	for(int i =0 ;i<n; i++){cin>>a[i]; sum += a[i];}
	if(sum + n-1  == x)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
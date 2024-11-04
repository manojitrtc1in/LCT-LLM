#include<bits/stdc++.h>
#define lmao cout<<"\nLick mY ass oni-chann ~";

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

const ld pi=2*acos(0);
const ll inf  = LLONG_MAX;
const ll ninf = LLONG_MIN;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	int a[2*n+2];
	for(int i=1;i<=n;i++) cin>>a[i];
	int k=1;
	for(int i=n+1;i<=2*n;i++) a[i] = a[k++];
	int res = 0;
	int tmp = 0;
	for(int i=1;i<=2*n-1;i++){
		if (a[i]==1) tmp++;
		else{
			res = max(res,tmp);
			tmp = 0;
		} 
	}
	cout<<res;
return 0;
}





























































































































































































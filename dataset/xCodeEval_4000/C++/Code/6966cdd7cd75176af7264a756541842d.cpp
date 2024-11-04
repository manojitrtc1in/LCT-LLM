#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef       long double dbl;
const int INF = 1e9+7;
const int MOD = 1e9+7;
#define speed ios::sync_with_stdio(false)
#define N 100001






bool inside (int i,int j)
{


}

int p[500001];
int main(){
speed;
ll n,B=0,b;
string s;
cin>>n;
for (int i=0;i<n;i++)
    {
        cin>>p[i];
    }
cin>>s;
for (int i=0;i<n;i++)
    {
        if (s[i]=='B')
            {B+=p[i];}
    }
    ll sol=B;
	     b=B;
	for(int i=n-1;i>=0;i--){
		if(s[i]=='A'){
			b+=p[i];
		} else {
			b-=p[i];
		}
		sol=max(sol,b);
	}
	b=B;
	for(int i=0;i<n;i++){
		if(s[i]=='A'){
			b+=p[i];
		} else {
			b-=p[i];
		}
		sol=max(sol,b);
	}
	cout<<sol<<endl;

return 0;}

























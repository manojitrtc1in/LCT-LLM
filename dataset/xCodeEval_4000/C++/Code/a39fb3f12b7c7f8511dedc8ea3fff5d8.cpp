
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int n,m;
int a[maxn],s[maxn];
set<pair<int,int> >st;
int main(){
    long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),s[i]=s[i-1]+a[i];

	for(int l=1;l<=n;++l){ 
		int xx=1;
		for(;xx<=a[l];xx<<=1);

		for(int r=l+2;r<=n&&s[r-1]-s[l]<=xx;++r){

			if((a[l]^a[r])==s[r-1]-s[l]){
				st.insert({l,r});

			}
		}
	}
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;++i){
		int xx=1;
		for(;xx<=a[i];xx<<=1);

		for(int j=i+2;j<=n&&s[j-1]-s[i]<=xx;++j){
			if((a[i]^a[j])==s[j-1]-s[i]){
				st.insert({n-j+1,n-i+1});

			}
		}
	}
	cout<<st.size()<<endl;

	return 0;
}


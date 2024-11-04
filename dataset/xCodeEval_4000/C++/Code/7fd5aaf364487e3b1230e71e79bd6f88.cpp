




























































































































































































#include<bits/stdc++.h>
#define maxn 2000005
#define maxx 40005


#define OK {puts("YES");}
#define NO {puts("NO");return;}
using namespace std;
int a[maxn];
void solve(){
	int n,m,q;
	cin>>n>>m>>q;
	int cnt=0;
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<m;j++){
			if(s[j]=='*'){
				a[j*n+i+1]=1;
				cnt++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n*m;i++){
		if(i<=cnt&&a[i]==0){
			ans++;
		}
	}






	

	while(q--){
		int y,x;
		scanf("%d %d",&y,&x);
		
		int pos=(x-1)*n+y;
		if(a[pos]==0){
			

			
			cnt++;
			int flag=0;
			if(a[cnt]==1){
				flag--;
			}
			if(pos>cnt){
				flag++;
			}
			a[pos]=1;
			ans+=flag;
			
		}
		else{
			

			
			
			int flag=0;
			if(a[cnt]==1){
				flag++;
			}
			cnt--;
			if(pos>cnt){
				flag--;
			}
			a[pos]=0;
			ans+=flag;
			
		}






		printf("%d\n",ans);
		
	}
}
void init(){
	
} 
signed main(){
	#ifndef ONLINE_JUDGE
		freopen("1.in","r",stdin);
	#endif
	int t=1;
	

	init();
	while(t--)solve();
	
	
	
	return 0;
}
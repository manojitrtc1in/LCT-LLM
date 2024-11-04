




























































































































































































#include<bits/stdc++.h>
#define maxn 200005
#define maxx 40005
#define int long long
#define OK {puts("YES");}
#define NO {puts("NO");}
using namespace std;
char s[maxn],t[maxn];
void solve(){
	int x,y;
	scanf("%s",s);
	scanf("%s",t);
	int len=strlen(t);
	if(len==1 && t[0]=='a'){
		puts("1");
		return;
	}
	int flag=0;
	for(int i=0;i<len;i++){
		if(t[i]=='a'){
			flag=1;
			break;
		}
	}
	if(flag){
		puts("-1");
	}
	else{
		printf("%lld\n",1ll<<strlen(s));
	}
	
}
void init(){
	
} 
signed main(){
	#ifndef ONLINE_JUDGE
		freopen("1.in","r",stdin);
	#endif
	int t=1;
	cin>>t;
	init();
	while(t--)solve();
	
	
	
	return 0;
}
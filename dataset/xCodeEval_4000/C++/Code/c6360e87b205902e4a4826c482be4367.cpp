




























































































































































































#include<bits/stdc++.h>
#define maxn 200002
using namespace std;
int a[maxn],b[maxn];
const int mod=1e9+7;
struct pos{
	int left;
	int right;
};
char s[maxn];
map<int,pos>ma;
queue<pair<int,int>>q;

int n,m,t,k;
int cmp(int a,int b){
	return a>b;
}
int ch[26];
int del[26];
void solve(){
	memset(ch,0,sizeof(ch));
	memset(del,0,sizeof(del));
	scanf("%s",s);
	int len=strlen(s);
	int p;
	scanf("%d",&p);
	for(int i=0;i<len;i++){
		ch[s[i]-'a']++;
	}
	int value=0;
	for(int i=0;i<26;i++){
		value+=ch[i]*(i+1);
	}
	if(value<=p){
		printf("%s\n",s);
		return;
	}
	for(int i=25;i>=0;i--){
		if(ch[i]){
			if(ch[i]*(i+1)<value-p){
				value-=ch[i]*(i+1);
				del[i]=ch[i];
			}
			else{
				del[i]=(value-p+i)/(i+1);
				break;
			}
		}
	}

	for(int i=0;i<len;i++){
		if(del[s[i]-'a']){
			del[s[i]-'a']--;
		}
		else{
			putchar(s[i]);
		}
	}
	putchar(10);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.in","r",stdin);
	#endif
	

	int t=1;
	cin>>t;
	while(t--)solve();
	
	
	
	return 0;
}
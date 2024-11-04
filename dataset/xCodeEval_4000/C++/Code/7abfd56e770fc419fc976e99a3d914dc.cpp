#include <bits/stdc++.h>
using namespace std;


char t[200005];
char tmp[200005];
int n,m;
int prt=505;
int tr[200005][26],trs=1;
int cnt[200005];
long long ch[200005],cq[200005];
int fail[200005];

void trieins(char* s,int len){
	int now=1;
	for(int i=0;i<len;i++){
		if(!tr[now][s[i]-'a']){
			tr[now][s[i]-'a']=++trs;
		}
		now=tr[now][s[i]-'a'];
	}
	cnt[now]++;
}

void getss(char* s,int len){
	fail[0]=-1;
	int now=0;
	for(int i=1;i<=len;i++){
		fail[i]=now;
		if(s[fail[i]]==s[i]&&fail[fail[i]]!=-1){
			fail[i]=fail[fail[i]];
		}
		while(now!=-1&&s[i]!=s[now]){
			now=fail[now];
		}
		now++;
	}
	now=0;
	for(int i=0;i<m;i++){
		while(now!=-1&&t[i]!=s[now]){
			now=fail[now];
		}
		now++;
		if(now==len){
			cq[i-len+1]++;
			ch[i]++;
		}
	}
}

int main(){
	scanf("%s",t);
	m=strlen(t);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",tmp);
		int sz=strlen(tmp);
		if(sz<prt){
			trieins(tmp,sz);
		}else{
			getss(tmp,sz);
		}
	}
	for(int i=0;i<m;i++){
		int now=1;
		for(int j=0;now&&i+j<m;j++){
			now=tr[now][t[i+j]-'a'];
			cq[i]+=cnt[now];
			ch[i+j]+=cnt[now];
		}
	}
	long long ans=0;
	for(int i=0;i<m-1;i++){
		ans+=ch[i]*cq[i+1];
	}
	printf("%lld\n",ans);
	return 0;
}
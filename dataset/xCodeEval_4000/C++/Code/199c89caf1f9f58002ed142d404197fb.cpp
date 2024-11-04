





















 
















#include<bits/stdc++.h>
using namespace std;
const int inf=2e9;
const int iinf=-1;
struct node{
	int minn,maxx;
}tr[400005];
int ql,qr,smn,smx;
int n,k;
int ans[100005][2];
void build(int o,int l,int r){
	tr[o].maxx=iinf;
	tr[o].minn=inf;
	if(l==r){
		int x;
		scanf("%d",&x);
		tr[o].maxx=tr[o].minn=x;
		return;
	}
	int m=(l+r)>>1;
	build(o*2,l,m);
	build(o*2+1,m+1,r);
	tr[o].maxx=max(tr[o*2].maxx,tr[o*2+1].maxx);
	tr[o].minn=min(tr[o*2].minn,tr[o*2+1].minn);
}
void qu(int o,int l,int r){
	if(ql<=l&&qr>=r){
		smn=min(smn,tr[o].minn);
		smx=max(smx,tr[o].maxx);
		return;
	}
	int m=(l+r)>>1;
	if(qr<=m)
		qu(o*2,l,m);
	else if(ql>m)
		qu(o*2+1,m+1,r);
	else{
		qu(o*2,l,m);
		qu(o*2+1,m+1,r);
	}
}
int check(int l){
	for(int i=1;i+l-1<=n;i++){
		smn=inf;
		smx = -1;
		ql = i;
		qr = i+l-1;
		qu(1,1,n);
		if(smx-smn<=k)
			return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	scanf("%d%d",&n,&k);
	

	build(1,1,n);
	int l=1,r=n,len=-1;
	while(l<=r){
		int m=(l+r)>>1;
		if(check(m)){
			l=m+1;
			len=max(len,m);
		}
		else r=m-1;
	}
	int cnt=0;
	for(int i=1;i+len-1<=n;i++){
		

		smn=inf;
		smx =-1;
		ql=i;
		qr = i+len-1;
		qu(1,1,n);
		if(smx-smn <= k){
			ans[cnt][0]=i;
			ans[cnt++][1]=i+len-1;
		}
	}
	cout<<len<<" "<<cnt<<"\n";
	for(int i=0;i<cnt;i++)
		cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
	return 0;
}

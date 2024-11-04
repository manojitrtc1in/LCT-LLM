
#include <bits/stdc++.h>
using namespace std;
typedef int ALL_OF_YOU_ARE_HANZHONGBALLS;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
#define IN inline
#define RE register
#define F first
#define S second
#define maxn 1005
vi lp,rp,la,lb,ra,rb;
pll st[maxn];
int main(){
	int n,gt;
	scanf("%d",&n);
	for(int i=3;i<=n;++i){
		printf("2 1 2 %d\n",i);
		fflush(stdout);
		scanf("%d",&gt);
		if(gt==-1) lp.push_back(i);
		else rp.push_back(i);
	}
	for(int i=0;i<lp.size();++i){
		printf("1 1 2 %d\n",lp[i]);
		fflush(stdout);
		scanf("%lld",&st[i].F);
		st[i].S=lp[i];
	}
	sort(st,st+lp.size());
	
	for(int i=0;i<(int)lp.size()-1;++i){
		printf("2 1 %lld %lld\n",st[lp.size()-1].S,st[i].S);
		fflush(stdout);
		scanf("%d",&gt);
		if(gt==-1) la.push_back(st[i].S);
		else lb.push_back(st[i].S);
	}
	if(!lp.empty()) lb.push_back(st[lp.size()-1].S);
	reverse(lb.begin(),lb.end());
	for(int i=0;i<rp.size();++i){
		printf("1 1 2 %d\n",rp[i]);
		fflush(stdout);
		scanf("%lld",&st[i].F);
		st[i].S=rp[i];
	}
	sort(st,st+rp.size());
	for(int i=0;i<(int)rp.size()-1;++i){
		printf("2 1 %lld %lld\n",st[rp.size()-1].S,st[i].S);
		fflush(stdout);
		scanf("%d",&gt);
		if(gt==-1) ra.push_back(st[i].S);
		else rb.push_back(st[i].S);
	}
	if(!rp.empty()) rb.push_back(st[rp.size()-1].S);
	reverse(rb.begin(),rb.end());
	printf("0 1 ");
	for(int i=0;i<la.size();++i) printf("%d ",la[i]);
	for(int i=0;i<lb.size();++i) printf("%d ",lb[i]);
	printf("2 ");
	for(int i=0;i<ra.size();++i) printf("%d ",ra[i]);
	for(int i=0;i<rb.size();++i) printf("%d ",rb[i]);
	putchar('\n');
	fflush(stdout);
	return 0;
}
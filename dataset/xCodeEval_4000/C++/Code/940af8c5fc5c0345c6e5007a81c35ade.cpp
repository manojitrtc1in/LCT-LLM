
#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define ll   long long
#define ull unsigned long long
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define PB pop_back
#define p push
#define P pop
#define INF 2147483647
#define ull unsigned long long
#define vi vector < int >
#define vpii vector < pii >
#define pq priority_queue
#define rep(i,n) for (int (i)=0;(i)<n;(i)++)
#define End return 0
#define mi multiset <int>
#define si set <int>
#define sll set<ll>
#define mll multiset<ll>
#define vll vector <ll>
#define Rep(i,a,b) for (int (i)=(a);(i)>=(b);(i)--)


using namespace std;
const int Maxn=5005;
ll dist[Maxn][Maxn];
ll buff1[Maxn],buff2[Maxn],buff3[Maxn],buff4[Maxn],buff5[Maxn];
bool vis[Maxn][Maxn];
bool used[Maxn];
vector<int> Que;
int n,s,e;
void I_Love_Minions(){
	cerr<<"F@ck y@@ djq_cpp."<<endl;
	cerr<<"B@tch!"<<endl;
	cerr<<"QAQ .^.^."<<endl;
	cerr<<"MINIONSSSSSSSSSSS"<<endl;
}
void minions1(int loc,int val,vector<int> &V){
	V.push_back(0);
	Rep(i,V.size()-2,loc+1){
		swap(V[i],V[i+1]);
	}
	V[loc+1]=val;
	return;
}
void minions2(){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (!(i==j)){
				dist[i][j]=abs(buff1[i]-buff1[j]);
				if (i>j){
					dist[i][j]+=buff4[i]+buff3[j];
				}
				else{
					dist[i][j]+=buff5[i]+buff2[j];
				}
			}
			

		}
		

	}
	return;
}
void minions4(vector<int> ans){
	ll totdist=0;
	rep(i,ans.size()-1){
		totdist+=dist[ans[i]][ans[i+1]];
	}
	printf("%I64d\n",totdist);
	return;
}
void minions5(ll &md,int &l,vi &Q,int loc,int val){
	ll ad=dist[Q[loc]][val]+dist[val][Q[loc+1]]-dist[Q[loc]][Q[loc+1]];
	

	if (ad<md){
		md=ad;
		l=loc;
	}
}
int main(){
	scanf("%d %d %d",&n,&s,&e);
	s--,e--;
	rep(i,n){
		scanf("%I64d",&buff1[i]);
	}
	rep(i,n){
		scanf("%I64d",&buff2[i]);
	}
	rep(i,n){
		scanf("%I64d",&buff3[i]);
	}
	rep(i,n){
		scanf("%I64d",&buff4[i]);
	}
	rep(i,n){
		scanf("%I64d",&buff5[i]);
	}
	minions2();
	Que.clear();
	Que.pb(s);
	Que.pb(e);
	rep(bufff,n){
		if (bufff==s || bufff==e) continue;
		ll md=1e18;
		int Insloc;
		rep(i,Que.size()-1){
			minions5(md,Insloc,Que,i,bufff);
		}
		minions1(Insloc,bufff,Que);
		
	}
	minions4(Que);
	return 0;
}

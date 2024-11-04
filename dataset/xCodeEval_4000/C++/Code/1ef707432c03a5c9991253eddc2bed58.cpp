
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
#define Rep(i,a,b) for (int (i)=(a);(i)<=(b);(i)++)


using namespace std;
bool res[100000];
void NO(){
	
	cout<<"Impossible\n";
	exit(0);
}
ll issb(ll x){
	ll sum=0;
	for (sum=0;(sum*(sum-1))<x*2;sum++){
		;
	}
	if (sum*(sum-1)==x*2){
		return sum;
	}
	else{
		return -1;
	}
}
int main(){
	ll a00,a01,a10,a11;
	cin>>a00>>a01>>a10>>a11;
	ll tot=a00+a01+a10+a11;
	ll ts=issb(tot);
	ll s0=issb(a00),s1=issb(a11);
	

	if (s0==0 && s1==0){
		if (!a01 && !a10){
			cout<<0<<endl;return 0;
		}
		
		if (a01==1 && a10==0){
			cout<<"01"<<endl;
		}
		else if (a01==0 && a10==1){
			cout<<"10"<<endl;
		}
		else{
			NO();
		}
		return 0;
	}
	if (s0==0){
		if (s1==-1) NO();
		if (ts==s1){
			s0=0;
		}
		else if (ts==s1+1){
			s0=1;
		}
		else{
			NO();
		}
	}
	else if (s1==0){
		if (s0==-1) NO();
		if (ts==s0){
			s1=0;
		}
		else if (ts==s0+1){
			s1=1;
		}
		else{
			NO();
		}
	}
	else {
		if (s0==-1 || s1==-1 || ts==-1 || (ts!=s0+s1)) NO();
	}
	

	
	
	bool flag=false;
	if (s1==0){
		swap(s1,s0);
		flag=true;
		swap(a10,a01);
	}
	ll x=a10/s1,y=a10%s1;
	for (int i=99999;i>99999-x;i--){
		;
	}
	int org=99999-s1-x;
	org+=y;
	for (int i=99999-x;i>=99999-x-s1;i--){
		res[i]=true;
	}
	res[org]=false;
	for (int i=99999-s0-s1+1;i<=99999;i++){
		if (!flag)
		cout<<res[i];
		else{
			cout<<!res[i];
		}
	}
	cout<<endl;
}


#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#define popcount __builtin_popcount
using namespace std;








#include <bits/stdc++.h>




#define rep(i,x) for(long long i=0;i<x;i++)
#define repn(i,x) for(long long i=1;i<=x;i++)
#define rrep(i,x) for(long long i=x-1;i>=0;i--)
#define rrepn(i,x) for(long long i=x;i>1;i--)
#define REP(i,n,x) for(long long i=n;i<x;i++)
#define REPN(i,n,x) for(long long i=n+1;i<x;i++)

#define pr printf
#define re return
#define mod 1000000007


#define inf  INT_MAX

#define INF 1e18+5

const double PI=3.14159265358979323846;
#define fi first
#define se second
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define all(x) (x).begin(),(x).end()

typedef long long int ll;
typedef pair<long long, long long> P;










vector<pair<long long, long long> > prime_factorize(long long n) {
	vector<pair<long long, long long> > res;
	for (long long p = 2; p * p <= n; ++p) {
		if (n % p != 0) continue;
		int num = 0;
		while (n % p == 0) { ++num; n /= p; }
		res.push_back(make_pair(p, num));
	}
	if (n != 1) res.push_back(make_pair(n, 1));
	return res;
}



vector<long long> calc_divisor(long long n) {
	vector<long long> res;
	for (long long i = 1LL; i*i <= n; ++i) {
		if (n % i == 0) {
			res.push_back(i);
        	long long j = n / i;
        	if (j != i) res.push_back(j);
		}
	}
	sort(res.begin(), res.end());
	return res;
}



ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }



ll gcd(const vector<ll> &v) {
	ll ret = v[0];
	for (ll i = 1; i < v.size(); i++)
		ret = gcd(ret, v[i]);
	return ret;
}



ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }



ll lcm(const vector<ll> &v) {
	ll ret = v[0];
	for (ll i = 1; i < v.size(); i++)
		ret = lcm(ret, v[i]);
	return ret;
}




int prime[5000005];
bool is_prime[5000005+1];




int sieve(int n){
	int p=0;
	for(int i=0;i<=n;i++)is_prime[i]=true;
	is_prime[0]=is_prime[1]=false;
	for(int i=2;i<=n;i++){
		if(is_prime[i]){
			prime[p++]=i;
			for(int j=2*i;j<=n;j+=i)is_prime[j]=false;
		}
	}
	return p;
}



template<typename TypeInt>
std::string Itoa(const TypeInt v, int base)
{
    static const char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ret;
    static numeric_limits<TypeInt> t;
    TypeInt n = v;
    if (t.is_signed) {
        if (v < 0) n *= -1;
    }

    while (n >= base) {
        ret += table[n%base];
        n /= base;
    }
    ret += table[n];
    if (t.is_signed) {
        if (v < 0 && base == 10) ret += '-';
    }
    

    std::reverse(ret.begin(), ret.end());

    return ret;
}










vector<pair<long long,long long>> g[200020];
ll s[200020];
bool used[200020];



ll A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,Q,R,S,T,U,V,W,X,Y,Z;
double dA,dB,dC,dD,dE,dF,dG,dH,dI,dJ,dK,dL,dM,dN,dO,dP,dQ,dR,dS,dT,dU,dV,dW,dX,dY,dZ;


string sa,sb,sc,sd,se,sf,sg,sh,si,sj,sk,sl,sm,sn,so,sp,sq,sr,ss, su,sv,sw,sx,sy,sz;









int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	

	
	
	


	
	


	
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	
	
	

	
	
	


	
	

	
	
	

	


	
	

	


	
	


	

	long long ans,ans1,ans2,ans3,ans4;
	long long sum,sum1,sum2,sum3,sum4;
	long long cnt,cnt1,cnt2,cnt3,cnt4;
	long long flg,flg1,flg2,flg3,flg4;
	long long wk,wk1,wk2,wk3,wk4;
	
	long long max,max1,max2,max3,max4;
	long long min,min1,min2,min3,min4;
	ans=ans1=ans2=ans3=ans4=0;
	sum=sum1=sum2=sum3=sum4=0;
	cnt=cnt1=cnt2=cnt3=cnt4=0;
	flg=flg1=flg2=flg3=flg4=0;
	wk=wk1=wk2=wk3=wk4=0;
	
	max=max1=max2=max3=max4=0;
	min=min1=min2=min3=min4=INF;

	double dwk,dwk1,dwk2,dwk3,dwk4;
	double dsum,dsum1,dsum2,dsum3,dsum4;
	double dans,dans1,dans2,dans3,dans4;
	dwk=dwk1=dwk2=dwk3=dwk4=0;
	dsum=dsum1=dsum2=dsum3=dsum4=0;
	dans=dans1=dans2=dans3=dans4=0;
	
	
	
	

	

	

	

	


	
	

	

	

	

	


	
	

	


	

	
	

	

	

	

	

	

	

	


	
	cin >> T;
	while(T--){
		cin >> N >> M >> R >>C;
		
		wk=MAX(N-R+M-C,R-1+C-1);
		wk2=MAX(wk,M-C+R-1);
		wk3=MAX(wk2,N-R+C-1);
		cout<<wk3<<"\n";
		

		
		

		

		

    	

		
		
	}
	re 0;

	

	

	

	
	

	

	

	

	

	

	

	
	

	

	

	
	

	

	
	

	

	

	

	

	

	

	


	re 0;
    
}

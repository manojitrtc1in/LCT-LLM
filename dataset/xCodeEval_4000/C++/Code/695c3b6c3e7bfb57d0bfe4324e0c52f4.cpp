












































































































#include<bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target ("sse4")

#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

#define int long long int



typedef std::vector<int> vi;
typedef std::vector<pair<int,int>> vii;
typedef std::vector<char> vc;
typedef std::vector<string> vs;



typedef std::vector<vector<int>> vvi;
typedef std::vector<vector<char>> vvc;
typedef std::vector<vector<string>> vvs;



typedef std::set<int> si;
typedef std::set<char> sc;
typedef std::set<string> ss;



typedef std::map<int,int> mii;
typedef std::map<char,int> mci;
typedef std::map<string,int> msi;
typedef std::map<pair<int,int>,int> miii;







bool prime_seive[1000010];
void prime_seive_func()
{
	bool flag;

	for(int i=0;i<=1000002;i++)
		prime_seive[i] = true;
	
	
	for(int i=2;i<=1000002;i++)
	{
		for(int j=i*i;j<=1000002;j+=i)
		{
			prime_seive[j-1] = false;
		}
	}

	prime_seive[0]=0;



}



int mod_power(int a,int b,int mod){
	if(b == 0){
		return 1;
	}
	int ans = mod_power(a,b/2,mod);
	ans *= ans;
	ans %= mod;
	if(b % 2)
	{
		ans *= a;
	}
	return ans % mod;
}









struct HASH{
	size_t operator()(const vector<int> &x)const{
		return hash<long long>()(((long long)x[0])^(((long long)x[1])<<32)^(((long long)x[2])<<32));
	}
};

























int bin_to_int(string s)
{
	int res=0,power=(s.length())-1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]-48!=0)
			res+=pow(2,power);
		power--;
	}
	return res;

}


int global_mod(int x,int y)
{
	return (((x % y) + y) % y);
}








int ipow(int base, int exp)
{
	int result = 1;
	for (;;)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		if (!exp)
			break;
		base *= base;
	}

	return result;
}






#define sync ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define repeat(i,a,b) for(int i = a;i < b;i++)
#define each(i, a) for (auto i: a)
#define fdv(x) for(auto i : x)cout<<i<<" ";
#define fdm(x) for(auto i : x)cout<<i.first<<" "<<i.second<<endl;
#define pb(v,x) v.push_back(x)
#define len(s) s.size()
#define sort(v) sort(v.begin(),v.end())
#define reverse(v) reverse(v.begin(),v.end())


#define l_b(v,x) lower_bound(v.begin(),v.end(),x)
#define u_b(v,x) upper_bound(v.begin(),v.end(),x)
#define b_s(v,x) binary_search(v.begin(),v.end(),x)




template<class T> void in(T &x) { cin >> x; }
void in(float &d) { string t; in(t); d = stof(t); }
void in(double &d) { string t; in(t); d = stod(t); }
void in(long double &d) { string t; in(t); d = stold(t); }
template<class A, class B> void in(pair<A, B> &a) {
in(a.fr); in(a.sc);
}
template<class A> void in(vector<A> &a) { each(i, a) in(i); }
template<class H, class... T> void in(H &h, T&... t) {
in(h); in(t...);
}




string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(const char * s) { return string(s); }
string to_string(string s) { return s; }
template<class A, class B>
string to_string(pair<A, B> &a) { 
	return to_string(a.fr) + " " + to_string(a.sc); 
}
template<class T> void prr(T x) { cout << to_string(x); }
template<class H, class... T> void prr(const H &h, const T&... t) {
prr(h); prr(t...); 
}

void prn() { prr("\n"); }
template<class T> void prn(vector<T> x) { 
each(i, x) { prr(i); prr(" "); }
prn();
}
template<class H, class... T> void prn(const H &h, const T&... t) {
prr(h); if (sizeof...(t)) prr(' '); prn(t...);
}

#define vip(v,x) vi v;for(int i=0;i<x;i++){int a;cin>>a;v.push_back(a);}
#define space cout<<" "
#define nl  cout<<endl
#define elif else if
#define meme(t) memset(t,-1,sizeof(t))
#define mod 1000000007
#define debug(x) cerr<<#x<<"	 "<<x<<endl;
#define gcd(a,b)            __gcd(a,b)
#define lcm(a,b)            (a/(__gcd(a,b)))*b







map<int,int>m;
void rec(vector<int> &v,int l,int r,int d)
{


  if(l<0||r>v.size()||l>=r||l>=v.size()||r<0)
        return;

	auto it=max_element(v.begin()+l,v.begin()+r);

	m[*it]=d;

	rec(v,l,(it-v.begin()),d+1);
	rec(v,it-v.begin()+1,r,d+1);
}

void solve()
{

	int n;in(n);
	vip(preorder,n);
	rec(preorder,0,preorder.size(),0);
	for(auto i:preorder)
		cout<<m[i]<<" ";
	nl;

}


main()
{
	sync

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
    #endif


	int test;in(test);
	while(test--)
		solve();
	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
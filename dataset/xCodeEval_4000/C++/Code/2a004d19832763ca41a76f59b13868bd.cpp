


#include<bits/stdc++.h>
#include <iostream>
#include <sstream>
#include<string>
using namespace std;
#define NFS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define nINF -100000000000000000
#define pINF 100000000000000000
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline '\n'
#define pb push_back
#define in insert
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define rv(x) reverse(x.begin(),x.end())
#define all(x) (x).begin(), (x).end()
#define     bitcount(x)     __builtin_popcountll(x)
#define     gcd(a,b)        (__gcd(a,b))
#define     lcm(a,b)        ((a*b)/gcd(a,b))
#define  endl '\n'
 

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;


#ifndef ONLINE_JUDGE
#define db(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define db(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}











































     


void ye_h_mera_code()
{
   
 {
    ll n,m;cin>>n>>m;
    
     ll maxval=((n-1)*m)+(m);
     ll nn=m-1;
     ll aa=(maxval)/(nn+1);
     cout<<nn*(nn+1)/2+((nn+1)*(aa*(aa+1)/2))<<endl;
     
    
 }
}




 
int main() 
{
     
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("debug.txt", "w", stderr);
    #endif
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    NFS;
   
    

    int tx=1;
    cin>>tx;
    while(tx--) 
   ye_h_mera_code();
   
  
} 

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define _s7D7lomzT_sMuQCdO5M_smFTuup85pii pair<int,int>
#define _s7D7lomzT_sMuQCdO5M_smFTuup85vi vector<int>
#define _s7D7lomzT_sMuQCdO5M_smFTuup85mii map<int,int>
#define _s7D7lomzT_sMuQCdO5M_smFTuup85ADJ map<int,set<int>>
#define _s7D7lomzT_sMuQCdO5M_smFTuup85vpii vector<\
_s7D7lomzT_sMuQCdO5M_smFTuup85pii>
#define _s7D7lomzT_sMuQCdO5M_smFTuup85fmap \
_s7D7lomzT_sMuQCdO5M_smFTuup85gp_hash_table
#define LONG _s7D7lomzT_sMuQCdO5M_smFTuup85LLONG
#define _s7D7lomzT_sMuQCdO5M_smFTuup85pb push_back
#define _s7D7lomzT_sMuQCdO5M_smFTuup85ed end()
#define _s7D7lomzT_sMuQCdO5M_smFTuup85bg begin()
#define _s7D7lomzT_sMuQCdO5M_smFTuup85sz size()
#define _s7D7lomzT_sMuQCdO5M_smFTuup85ln length()
#define _s7D7lomzT_sMuQCdO5M_smFTuup85all(\
_s7D7lomzT_sMuQCdO5M_smFTuup85x) \
_s7D7lomzT_sMuQCdO5M_smFTuup85x.begin(),\
_s7D7lomzT_sMuQCdO5M_smFTuup85x.end()
#define endl '\n'
#define _s7D7lomzT_sMuQCdO5M_smFTuup85NL cout<<'\n';
#define _s7D7lomzT_sMuQCdO5M_smFTuup85F first
#define _s7D7lomzT_sMuQCdO5M_smFTuup85S second
#define _s7D7lomzT_sMuQCdO5M_smFTuup85T \
_s7D7lomzT_sMuQCdO5M_smFTuup85third
#define _s7D7lomzT_sMuQCdO5M_smFTuup85disp(\
_s7D7lomzT_sMuQCdO5M_smFTuup85x) for(auto \
_s7D7lomzT_sMuQCdO5M_smFTuup85t : \
_s7D7lomzT_sMuQCdO5M_smFTuup85x )cout<<_s7D7lomzT_sMuQCdO5M_smFTuup85t\
<<"\x20";
#define _s7D7lomzT_sMuQCdO5M_smFTuup85for0(\
_s7D7lomzT_sMuQCdO5M_smFTuup85n) for(int \
_s7D7lomzT_sMuQCdO5M_smFTuup85i=0;\
_s7D7lomzT_sMuQCdO5M_smFTuup85i<_s7D7lomzT_sMuQCdO5M_smFTuup85n;\
_s7D7lomzT_sMuQCdO5M_smFTuup85i\
++)
#define _s7D7lomzT_sMuQCdO5M_smFTuup85for0j(\
_s7D7lomzT_sMuQCdO5M_smFTuup85n) for(int \
_s7D7lomzT_sMuQCdO5M_smFTuup85j=0;\
_s7D7lomzT_sMuQCdO5M_smFTuup85j<_s7D7lomzT_sMuQCdO5M_smFTuup85n;\
_s7D7lomzT_sMuQCdO5M_smFTuup85j\
++)
#define _s7D7lomzT_sMuQCdO5M_smFTuup85oldfor(\
_s7D7lomzT_sMuQCdO5M_smFTuup85v) for(auto \
_s7D7lomzT_sMuQCdO5M_smFTuup85it = \
_s7D7lomzT_sMuQCdO5M_smFTuup85v.begin(); \
_s7D7lomzT_sMuQCdO5M_smFTuup85it != \
_s7D7lomzT_sMuQCdO5M_smFTuup85v.end(); ++\
_s7D7lomzT_sMuQCdO5M_smFTuup85it)
#define _s7D7lomzT_sMuQCdO5M_smFTuup85SS <<"\x20"<<
#define _s7D7lomzT_sMuQCdO5M_smFTuup85acum accumulate
#define _s7D7lomzT_sMuQCdO5M_smFTuup85arrin(\
_s7D7lomzT_sMuQCdO5M_smFTuup85a,\
_s7D7lomzT_sMuQCdO5M_smFTuup85n) \
_s7D7lomzT_sMuQCdO5M_smFTuup85vi _s7D7lomzT_sMuQCdO5M_smFTuup85a(\
_s7D7lomzT_sMuQCdO5M_smFTuup85n);_s7D7lomzT_sMuQCdO5M_smFTuup85for0(\
_s7D7lomzT_sMuQCdO5M_smFTuup85n){cin>>_s7D7lomzT_sMuQCdO5M_smFTuup85a[\
_s7D7lomzT_sMuQCdO5M_smFTuup85i];}
#define _s7D7lomzT_sMuQCdO5M_smFTuup85pf(\
_s7D7lomzT_sMuQCdO5M_smFTuup85x) cout<<\
_s7D7lomzT_sMuQCdO5M_smFTuup85x<<endl;
#define _s7D7lomzT_sMuQCdO5M_smFTuup85Check \
_s7D7lomzT_sMuQCdO5M_smFTuup85pf(\
"\x43\x68\x65\x63\x6b")
#define _s7D7lomzT_sMuQCdO5M_smFTuup85gridin(\
_s7D7lomzT_sMuQCdO5M_smFTuup85num,\
_s7D7lomzT_sMuQCdO5M_smFTuup85n,\
_s7D7lomzT_sMuQCdO5M_smFTuup85m) _s7D7lomzT_sMuQCdO5M_smFTuup85for0(\
_s7D7lomzT_sMuQCdO5M_smFTuup85n){_s7D7lomzT_sMuQCdO5M_smFTuup85for0j(\
_s7D7lomzT_sMuQCdO5M_smFTuup85m) cin>>\
_s7D7lomzT_sMuQCdO5M_smFTuup85num[\
_s7D7lomzT_sMuQCdO5M_smFTuup85i][_s7D7lomzT_sMuQCdO5M_smFTuup85j];}
#define _s7D7lomzT_sMuQCdO5M_smFTuup85dispgrid(\
_s7D7lomzT_sMuQCdO5M_smFTuup85num,\
_s7D7lomzT_sMuQCdO5M_smFTuup85n,\
_s7D7lomzT_sMuQCdO5M_smFTuup85m) _s7D7lomzT_sMuQCdO5M_smFTuup85for0(\
_s7D7lomzT_sMuQCdO5M_smFTuup85n){_s7D7lomzT_sMuQCdO5M_smFTuup85for0j(\
_s7D7lomzT_sMuQCdO5M_smFTuup85m) cout<<\
_s7D7lomzT_sMuQCdO5M_smFTuup85num[\
_s7D7lomzT_sMuQCdO5M_smFTuup85i][_s7D7lomzT_sMuQCdO5M_smFTuup85j]<<\
"\x20"; cout<<endl;}
#define _s7D7lomzT_sMuQCdO5M_smFTuup85tks(\
_s7D7lomzT_sMuQCdO5M_smFTuup85x) string \
_s7D7lomzT_sMuQCdO5M_smFTuup85x;cin >> \
_s7D7lomzT_sMuQCdO5M_smFTuup85x;
#define _s7D7lomzT_sMuQCdO5M_smFTuup85tk(\
_s7D7lomzT_sMuQCdO5M_smFTuup85a) int \
_s7D7lomzT_sMuQCdO5M_smFTuup85a;cin>>\
_s7D7lomzT_sMuQCdO5M_smFTuup85a;
#define _s7D7lomzT_sMuQCdO5M_smFTuup85tk2(\
_s7D7lomzT_sMuQCdO5M_smFTuup85a,\
_s7D7lomzT_sMuQCdO5M_smFTuup85b)_s7D7lomzT_sMuQCdO5M_smFTuup85tk(\
_s7D7lomzT_sMuQCdO5M_smFTuup85a)_s7D7lomzT_sMuQCdO5M_smFTuup85tk(\
_s7D7lomzT_sMuQCdO5M_smFTuup85b)
#define _s7D7lomzT_sMuQCdO5M_smFTuup85tk3(\
_s7D7lomzT_sMuQCdO5M_smFTuup85a,\
_s7D7lomzT_sMuQCdO5M_smFTuup85b,_s7D7lomzT_sMuQCdO5M_smFTuup85c)\
_s7D7lomzT_sMuQCdO5M_smFTuup85tk2(_s7D7lomzT_sMuQCdO5M_smFTuup85a,\
_s7D7lomzT_sMuQCdO5M_smFTuup85b)_s7D7lomzT_sMuQCdO5M_smFTuup85tk(\
_s7D7lomzT_sMuQCdO5M_smFTuup85c)
#define _s7D7lomzT_sMuQCdO5M_smFTuup85tk4(\
_s7D7lomzT_sMuQCdO5M_smFTuup85a,\
_s7D7lomzT_sMuQCdO5M_smFTuup85b,_s7D7lomzT_sMuQCdO5M_smFTuup85c,\
_s7D7lomzT_sMuQCdO5M_smFTuup85d)_s7D7lomzT_sMuQCdO5M_smFTuup85tk2(\
_s7D7lomzT_sMuQCdO5M_smFTuup85a,_s7D7lomzT_sMuQCdO5M_smFTuup85b)\
_s7D7lomzT_sMuQCdO5M_smFTuup85tk2(_s7D7lomzT_sMuQCdO5M_smFTuup85c,\
_s7D7lomzT_sMuQCdO5M_smFTuup85d)
#define _s7D7lomzT_sMuQCdO5M_smFTuup85tk5(\
_s7D7lomzT_sMuQCdO5M_smFTuup85a,\
_s7D7lomzT_sMuQCdO5M_smFTuup85b,_s7D7lomzT_sMuQCdO5M_smFTuup85c,\
_s7D7lomzT_sMuQCdO5M_smFTuup85d,_s7D7lomzT_sMuQCdO5M_smFTuup85e)\
_s7D7lomzT_sMuQCdO5M_smFTuup85tk4(_s7D7lomzT_sMuQCdO5M_smFTuup85a,\
_s7D7lomzT_sMuQCdO5M_smFTuup85b,_s7D7lomzT_sMuQCdO5M_smFTuup85c,\
_s7D7lomzT_sMuQCdO5M_smFTuup85d\
)_s7D7lomzT_sMuQCdO5M_smFTuup85tk(\
_s7D7lomzT_sMuQCdO5M_smFTuup85e)
#define _s7D7lomzT_sMuQCdO5M_smFTuup85tk6(\
_s7D7lomzT_sMuQCdO5M_smFTuup85a,\
_s7D7lomzT_sMuQCdO5M_smFTuup85b,_s7D7lomzT_sMuQCdO5M_smFTuup85c,\
_s7D7lomzT_sMuQCdO5M_smFTuup85d,_s7D7lomzT_sMuQCdO5M_smFTuup85e,\
_s7D7lomzT_sMuQCdO5M_smFTuup85f\
)_s7D7lomzT_sMuQCdO5M_smFTuup85tk3(\
_s7D7lomzT_sMuQCdO5M_smFTuup85a,_s7D7lomzT_sMuQCdO5M_smFTuup85b,\
_s7D7lomzT_sMuQCdO5M_smFTuup85c\
)_s7D7lomzT_sMuQCdO5M_smFTuup85tk3(\
_s7D7lomzT_sMuQCdO5M_smFTuup85d,_s7D7lomzT_sMuQCdO5M_smFTuup85e,\
_s7D7lomzT_sMuQCdO5M_smFTuup85f\
)
#define _s7D7lomzT_sMuQCdO5M_smFTuup85tk7(\
_s7D7lomzT_sMuQCdO5M_smFTuup85a,\
_s7D7lomzT_sMuQCdO5M_smFTuup85b,_s7D7lomzT_sMuQCdO5M_smFTuup85c,\
_s7D7lomzT_sMuQCdO5M_smFTuup85d,_s7D7lomzT_sMuQCdO5M_smFTuup85e,\
_s7D7lomzT_sMuQCdO5M_smFTuup85f\
,_s7D7lomzT_sMuQCdO5M_smFTuup85g)\
_s7D7lomzT_sMuQCdO5M_smFTuup85tk6(_s7D7lomzT_sMuQCdO5M_smFTuup85a,\
_s7D7lomzT_sMuQCdO5M_smFTuup85b,_s7D7lomzT_sMuQCdO5M_smFTuup85c,\
_s7D7lomzT_sMuQCdO5M_smFTuup85d,_s7D7lomzT_sMuQCdO5M_smFTuup85e,\
_s7D7lomzT_sMuQCdO5M_smFTuup85f\
)_s7D7lomzT_sMuQCdO5M_smFTuup85tk(\
_s7D7lomzT_sMuQCdO5M_smFTuup85g)
#define _s7D7lomzT_sMuQCdO5M_smFTuup85tk8(\
_s7D7lomzT_sMuQCdO5M_smFTuup85a,\
_s7D7lomzT_sMuQCdO5M_smFTuup85b,_s7D7lomzT_sMuQCdO5M_smFTuup85c,\
_s7D7lomzT_sMuQCdO5M_smFTuup85d,_s7D7lomzT_sMuQCdO5M_smFTuup85e,\
_s7D7lomzT_sMuQCdO5M_smFTuup85f\
,_s7D7lomzT_sMuQCdO5M_smFTuup85g,\
_s7D7lomzT_sMuQCdO5M_smFTuup85h)_s7D7lomzT_sMuQCdO5M_smFTuup85tk7(\
_s7D7lomzT_sMuQCdO5M_smFTuup85a,_s7D7lomzT_sMuQCdO5M_smFTuup85b,\
_s7D7lomzT_sMuQCdO5M_smFTuup85c,_s7D7lomzT_sMuQCdO5M_smFTuup85d,\
_s7D7lomzT_sMuQCdO5M_smFTuup85e\
,_s7D7lomzT_sMuQCdO5M_smFTuup85f,\
_s7D7lomzT_sMuQCdO5M_smFTuup85g)_s7D7lomzT_sMuQCdO5M_smFTuup85tk(\
_s7D7lomzT_sMuQCdO5M_smFTuup85h)
#define _s7D7lomzT_sMuQCdO5M_smFTuup85addEdge(\
_s7D7lomzT_sMuQCdO5M_smFTuup85adj) \
_s7D7lomzT_sMuQCdO5M_smFTuup85tk2(\
_s7D7lomzT_sMuQCdO5M_smFTuup85u,_s7D7lomzT_sMuQCdO5M_smFTuup85v) \
_s7D7lomzT_sMuQCdO5M_smFTuup85adj[_s7D7lomzT_sMuQCdO5M_smFTuup85u].\
insert(\
_s7D7lomzT_sMuQCdO5M_smFTuup85v);_s7D7lomzT_sMuQCdO5M_smFTuup85adj[\
_s7D7lomzT_sMuQCdO5M_smFTuup85v].insert(\
_s7D7lomzT_sMuQCdO5M_smFTuup85u);
#define _s7D7lomzT_sMuQCdO5M_smFTuup85test \
_s7D7lomzT_sMuQCdO5M_smFTuup85tk(\
_s7D7lomzT_sMuQCdO5M_smFTuup85test)while(\
_s7D7lomzT_sMuQCdO5M_smFTuup85test--)
#define _s7D7lomzT_sMuQCdO5M_smFTuup85YES cout<<"\x59\x45\x53"<<endl;
#define _s7D7lomzT_sMuQCdO5M_smFTuup85Yes cout<<"\x59\x65\x73"<<endl;
#define _s7D7lomzT_sMuQCdO5M_smFTuup85NO cout<<"\x4e\x4f"<<endl;
#define _s7D7lomzT_sMuQCdO5M_smFTuup85No cout<<"\x4e\x6f"<<endl;
#define _s7D7lomzT_sMuQCdO5M_smFTuup85yes cout<<"\x79\x65\x73"<<endl;
#define _s7D7lomzT_sMuQCdO5M_smFTuup85no cout<<"\x6e\x6f"<<endl;
const int _s7D7lomzT_sMuQCdO5M_smFTuup85MOD=1000000007;const int 
_s7D7lomzT_sMuQCdO5M_smFTuup85N=100000;
#define _s7D7lomzT_sMuQCdO5M_smFTuup85accuracy chrono::\
_s7D7lomzT_sMuQCdO5M_smFTuup85steady_clock::now().\
time_since_epoch().count()
template<typename _s7D7lomzT_sMuQCdO5M_smFTuup85T>ostream&operator<<(
ostream&_s7D7lomzT_sMuQCdO5M_smFTuup85os,const vector<
_s7D7lomzT_sMuQCdO5M_smFTuup85T>&_s7D7lomzT_sMuQCdO5M_smFTuup85v){
_s7D7lomzT_sMuQCdO5M_smFTuup85os<<"\x7b";
_s7D7lomzT_sMuQCdO5M_smFTuup85oldfor(_s7D7lomzT_sMuQCdO5M_smFTuup85v){
if(_s7D7lomzT_sMuQCdO5M_smFTuup85it!=_s7D7lomzT_sMuQCdO5M_smFTuup85v.
_s7D7lomzT_sMuQCdO5M_smFTuup85bg)_s7D7lomzT_sMuQCdO5M_smFTuup85os<<
"\x2c\x20";_s7D7lomzT_sMuQCdO5M_smFTuup85os<<*
_s7D7lomzT_sMuQCdO5M_smFTuup85it;}return 
_s7D7lomzT_sMuQCdO5M_smFTuup85os<<"\x7d";}template<typename 
_s7D7lomzT_sMuQCdO5M_smFTuup85F,typename 
_s7D7lomzT_sMuQCdO5M_smFTuup85S>ostream&operator<<(ostream&
_s7D7lomzT_sMuQCdO5M_smFTuup85os,const pair<
_s7D7lomzT_sMuQCdO5M_smFTuup85F,_s7D7lomzT_sMuQCdO5M_smFTuup85S>&
_s7D7lomzT_sMuQCdO5M_smFTuup85p){return 
_s7D7lomzT_sMuQCdO5M_smFTuup85os<<"\x28"<<
_s7D7lomzT_sMuQCdO5M_smFTuup85p._s7D7lomzT_sMuQCdO5M_smFTuup85F<<
"\x2c\x20"<<_s7D7lomzT_sMuQCdO5M_smFTuup85p.
_s7D7lomzT_sMuQCdO5M_smFTuup85S<<"\x29";}template<typename 
_s7D7lomzT_sMuQCdO5M_smFTuup85T>ostream&operator<<(ostream&
_s7D7lomzT_sMuQCdO5M_smFTuup85os,const set<
_s7D7lomzT_sMuQCdO5M_smFTuup85T>&_s7D7lomzT_sMuQCdO5M_smFTuup85v){
_s7D7lomzT_sMuQCdO5M_smFTuup85os<<"\x5b";
_s7D7lomzT_sMuQCdO5M_smFTuup85oldfor(_s7D7lomzT_sMuQCdO5M_smFTuup85v){
if(_s7D7lomzT_sMuQCdO5M_smFTuup85it!=_s7D7lomzT_sMuQCdO5M_smFTuup85v.
_s7D7lomzT_sMuQCdO5M_smFTuup85bg)_s7D7lomzT_sMuQCdO5M_smFTuup85os<<
"\x2c\x20";_s7D7lomzT_sMuQCdO5M_smFTuup85os<<*
_s7D7lomzT_sMuQCdO5M_smFTuup85it;}return 
_s7D7lomzT_sMuQCdO5M_smFTuup85os<<"\x5d";}template<typename 
_s7D7lomzT_sMuQCdO5M_smFTuup85T>ostream&operator<<(ostream&
_s7D7lomzT_sMuQCdO5M_smFTuup85os,const multiset<
_s7D7lomzT_sMuQCdO5M_smFTuup85T>&_s7D7lomzT_sMuQCdO5M_smFTuup85v){
_s7D7lomzT_sMuQCdO5M_smFTuup85os<<"\x5b";
_s7D7lomzT_sMuQCdO5M_smFTuup85oldfor(_s7D7lomzT_sMuQCdO5M_smFTuup85v){
if(_s7D7lomzT_sMuQCdO5M_smFTuup85it!=_s7D7lomzT_sMuQCdO5M_smFTuup85v.
_s7D7lomzT_sMuQCdO5M_smFTuup85bg)_s7D7lomzT_sMuQCdO5M_smFTuup85os<<
"\x2c\x20";_s7D7lomzT_sMuQCdO5M_smFTuup85os<<*
_s7D7lomzT_sMuQCdO5M_smFTuup85it;}return 
_s7D7lomzT_sMuQCdO5M_smFTuup85os<<"\x5d";}template<typename 
_s7D7lomzT_sMuQCdO5M_smFTuup85F,typename 
_s7D7lomzT_sMuQCdO5M_smFTuup85S>ostream&operator<<(ostream&
_s7D7lomzT_sMuQCdO5M_smFTuup85os,const map<
_s7D7lomzT_sMuQCdO5M_smFTuup85F,_s7D7lomzT_sMuQCdO5M_smFTuup85S>&
_s7D7lomzT_sMuQCdO5M_smFTuup85v){_s7D7lomzT_sMuQCdO5M_smFTuup85os<<
"\x5b";_s7D7lomzT_sMuQCdO5M_smFTuup85oldfor(
_s7D7lomzT_sMuQCdO5M_smFTuup85v){if(_s7D7lomzT_sMuQCdO5M_smFTuup85it!=
_s7D7lomzT_sMuQCdO5M_smFTuup85v._s7D7lomzT_sMuQCdO5M_smFTuup85bg)
_s7D7lomzT_sMuQCdO5M_smFTuup85os<<"\x2c\x20";
_s7D7lomzT_sMuQCdO5M_smFTuup85os<<_s7D7lomzT_sMuQCdO5M_smFTuup85it->
_s7D7lomzT_sMuQCdO5M_smFTuup85F<<"\x20\x3d\x20"<<
_s7D7lomzT_sMuQCdO5M_smFTuup85it->_s7D7lomzT_sMuQCdO5M_smFTuup85S;}
return _s7D7lomzT_sMuQCdO5M_smFTuup85os<<"\x5d";}int 
_s7D7lomzT_sMuQCdO5M_smFTuup85bob(vector<
_s7D7lomzT_sMuQCdO5M_smFTuup85vi>&_s7D7lomzT_sMuQCdO5M_smFTuup85a,int 
_s7D7lomzT_sMuQCdO5M_smFTuup85n,int _s7D7lomzT_sMuQCdO5M_smFTuup85m){
vector<_s7D7lomzT_sMuQCdO5M_smFTuup85vi>
_s7D7lomzT_sMuQCdO5M_smFTuup85dp;_s7D7lomzT_sMuQCdO5M_smFTuup85for0(
_s7D7lomzT_sMuQCdO5M_smFTuup85n+1){_s7D7lomzT_sMuQCdO5M_smFTuup85vi 
_s7D7lomzT_sMuQCdO5M_smFTuup85temp(_s7D7lomzT_sMuQCdO5M_smFTuup85m+1,0
);_s7D7lomzT_sMuQCdO5M_smFTuup85dp._s7D7lomzT_sMuQCdO5M_smFTuup85pb(
_s7D7lomzT_sMuQCdO5M_smFTuup85temp);}_s7D7lomzT_sMuQCdO5M_smFTuup85dp[
0][1]=_s7D7lomzT_sMuQCdO5M_smFTuup85a[1][1];for(int 
_s7D7lomzT_sMuQCdO5M_smFTuup85i=1;_s7D7lomzT_sMuQCdO5M_smFTuup85i<=
_s7D7lomzT_sMuQCdO5M_smFTuup85n;_s7D7lomzT_sMuQCdO5M_smFTuup85i++){for
(int _s7D7lomzT_sMuQCdO5M_smFTuup85j=1;_s7D7lomzT_sMuQCdO5M_smFTuup85j
<=_s7D7lomzT_sMuQCdO5M_smFTuup85m;_s7D7lomzT_sMuQCdO5M_smFTuup85j++){
_s7D7lomzT_sMuQCdO5M_smFTuup85dp[_s7D7lomzT_sMuQCdO5M_smFTuup85i][
_s7D7lomzT_sMuQCdO5M_smFTuup85j]=max(_s7D7lomzT_sMuQCdO5M_smFTuup85dp[
_s7D7lomzT_sMuQCdO5M_smFTuup85i-1][_s7D7lomzT_sMuQCdO5M_smFTuup85j]&
_s7D7lomzT_sMuQCdO5M_smFTuup85a[_s7D7lomzT_sMuQCdO5M_smFTuup85i][
_s7D7lomzT_sMuQCdO5M_smFTuup85j],_s7D7lomzT_sMuQCdO5M_smFTuup85dp[
_s7D7lomzT_sMuQCdO5M_smFTuup85i][_s7D7lomzT_sMuQCdO5M_smFTuup85j-1]&
_s7D7lomzT_sMuQCdO5M_smFTuup85a[_s7D7lomzT_sMuQCdO5M_smFTuup85i][
_s7D7lomzT_sMuQCdO5M_smFTuup85j]);}}return 
_s7D7lomzT_sMuQCdO5M_smFTuup85dp[_s7D7lomzT_sMuQCdO5M_smFTuup85n][
_s7D7lomzT_sMuQCdO5M_smFTuup85m];}void 
_s7D7lomzT_sMuQCdO5M_smFTuup85_correct(vector<
_s7D7lomzT_sMuQCdO5M_smFTuup85vi>&_s7D7lomzT_sMuQCdO5M_smFTuup85a,int 
_s7D7lomzT_sMuQCdO5M_smFTuup85n,int _s7D7lomzT_sMuQCdO5M_smFTuup85m,
int _s7D7lomzT_sMuQCdO5M_smFTuup85r,int 
_s7D7lomzT_sMuQCdO5M_smFTuup85c,int _s7D7lomzT_sMuQCdO5M_smFTuup85sum,
int&_s7D7lomzT_sMuQCdO5M_smFTuup85cor){if(
_s7D7lomzT_sMuQCdO5M_smFTuup85r==_s7D7lomzT_sMuQCdO5M_smFTuup85n and 
_s7D7lomzT_sMuQCdO5M_smFTuup85c==_s7D7lomzT_sMuQCdO5M_smFTuup85m){
_s7D7lomzT_sMuQCdO5M_smFTuup85cor=max(
_s7D7lomzT_sMuQCdO5M_smFTuup85cor,_s7D7lomzT_sMuQCdO5M_smFTuup85sum);
return;}if(_s7D7lomzT_sMuQCdO5M_smFTuup85r+1<=
_s7D7lomzT_sMuQCdO5M_smFTuup85n)_s7D7lomzT_sMuQCdO5M_smFTuup85_correct
(_s7D7lomzT_sMuQCdO5M_smFTuup85a,_s7D7lomzT_sMuQCdO5M_smFTuup85n,
_s7D7lomzT_sMuQCdO5M_smFTuup85m,_s7D7lomzT_sMuQCdO5M_smFTuup85r+1,
_s7D7lomzT_sMuQCdO5M_smFTuup85c,_s7D7lomzT_sMuQCdO5M_smFTuup85sum&
_s7D7lomzT_sMuQCdO5M_smFTuup85a[_s7D7lomzT_sMuQCdO5M_smFTuup85r+1][
_s7D7lomzT_sMuQCdO5M_smFTuup85c],_s7D7lomzT_sMuQCdO5M_smFTuup85cor);if
(_s7D7lomzT_sMuQCdO5M_smFTuup85c+1<=_s7D7lomzT_sMuQCdO5M_smFTuup85m)
_s7D7lomzT_sMuQCdO5M_smFTuup85_correct(_s7D7lomzT_sMuQCdO5M_smFTuup85a
,_s7D7lomzT_sMuQCdO5M_smFTuup85n,_s7D7lomzT_sMuQCdO5M_smFTuup85m,
_s7D7lomzT_sMuQCdO5M_smFTuup85r,_s7D7lomzT_sMuQCdO5M_smFTuup85c+1,
_s7D7lomzT_sMuQCdO5M_smFTuup85sum&_s7D7lomzT_sMuQCdO5M_smFTuup85a[
_s7D7lomzT_sMuQCdO5M_smFTuup85r][_s7D7lomzT_sMuQCdO5M_smFTuup85c+1],
_s7D7lomzT_sMuQCdO5M_smFTuup85cor);}int 
_s7D7lomzT_sMuQCdO5M_smFTuup85bf(vector<
_s7D7lomzT_sMuQCdO5M_smFTuup85vi>&_s7D7lomzT_sMuQCdO5M_smFTuup85a,int 
_s7D7lomzT_sMuQCdO5M_smFTuup85n,int _s7D7lomzT_sMuQCdO5M_smFTuup85m){
int _s7D7lomzT_sMuQCdO5M_smFTuup85cor=0;
_s7D7lomzT_sMuQCdO5M_smFTuup85_correct(_s7D7lomzT_sMuQCdO5M_smFTuup85a
,_s7D7lomzT_sMuQCdO5M_smFTuup85n,_s7D7lomzT_sMuQCdO5M_smFTuup85m,1,1,
_s7D7lomzT_sMuQCdO5M_smFTuup85a[1][1],
_s7D7lomzT_sMuQCdO5M_smFTuup85cor);return 
_s7D7lomzT_sMuQCdO5M_smFTuup85cor;}bool 
_s7D7lomzT_sMuQCdO5M_smFTuup85isPerf(int 
_s7D7lomzT_sMuQCdO5M_smFTuup85n){return floor(log2l(
_s7D7lomzT_sMuQCdO5M_smFTuup85n))==ceil(log2l(
_s7D7lomzT_sMuQCdO5M_smFTuup85n));}int32_t main(){ios_base::sync_with_stdio
(false);cin.tie(0);if(1){for(int _s7D7lomzT_sMuQCdO5M_smFTuup85kk=0;
_s7D7lomzT_sMuQCdO5M_smFTuup85kk<=1000;
_s7D7lomzT_sMuQCdO5M_smFTuup85kk++){int 
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=34;int 
_s7D7lomzT_sMuQCdO5M_smFTuup85up=20;int 
_s7D7lomzT_sMuQCdO5M_smFTuup85cp=13*23;
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=_s7D7lomzT_sMuQCdO5M_smFTuup85up+
_s7D7lomzT_sMuQCdO5M_smFTuup85cp;_s7D7lomzT_sMuQCdO5M_smFTuup85pp=
_s7D7lomzT_sMuQCdO5M_smFTuup85up+_s7D7lomzT_sMuQCdO5M_smFTuup85cp;
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=_s7D7lomzT_sMuQCdO5M_smFTuup85up+
_s7D7lomzT_sMuQCdO5M_smFTuup85cp;}}if(1){for(int 
_s7D7lomzT_sMuQCdO5M_smFTuup85kk=0;_s7D7lomzT_sMuQCdO5M_smFTuup85kk<=
1000;_s7D7lomzT_sMuQCdO5M_smFTuup85kk++){int 
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=34;int 
_s7D7lomzT_sMuQCdO5M_smFTuup85up=20;int 
_s7D7lomzT_sMuQCdO5M_smFTuup85cp=13*23;
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=_s7D7lomzT_sMuQCdO5M_smFTuup85up+
_s7D7lomzT_sMuQCdO5M_smFTuup85cp;_s7D7lomzT_sMuQCdO5M_smFTuup85pp=
_s7D7lomzT_sMuQCdO5M_smFTuup85up+_s7D7lomzT_sMuQCdO5M_smFTuup85cp;
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=_s7D7lomzT_sMuQCdO5M_smFTuup85up+
_s7D7lomzT_sMuQCdO5M_smFTuup85cp;}}if(1){for(int 
_s7D7lomzT_sMuQCdO5M_smFTuup85kk=0;_s7D7lomzT_sMuQCdO5M_smFTuup85kk<=
1000;_s7D7lomzT_sMuQCdO5M_smFTuup85kk++){int 
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=34;int 
_s7D7lomzT_sMuQCdO5M_smFTuup85up=20;int 
_s7D7lomzT_sMuQCdO5M_smFTuup85cp=13*23;
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=_s7D7lomzT_sMuQCdO5M_smFTuup85up+
_s7D7lomzT_sMuQCdO5M_smFTuup85cp;_s7D7lomzT_sMuQCdO5M_smFTuup85pp=
_s7D7lomzT_sMuQCdO5M_smFTuup85up+_s7D7lomzT_sMuQCdO5M_smFTuup85cp;
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=_s7D7lomzT_sMuQCdO5M_smFTuup85up+
_s7D7lomzT_sMuQCdO5M_smFTuup85cp;}}if(1){for(int 
_s7D7lomzT_sMuQCdO5M_smFTuup85kk=0;_s7D7lomzT_sMuQCdO5M_smFTuup85kk<=
1000;_s7D7lomzT_sMuQCdO5M_smFTuup85kk++){int 
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=34;int 
_s7D7lomzT_sMuQCdO5M_smFTuup85up=20;int 
_s7D7lomzT_sMuQCdO5M_smFTuup85cp=13*23;
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=_s7D7lomzT_sMuQCdO5M_smFTuup85up+
_s7D7lomzT_sMuQCdO5M_smFTuup85cp;_s7D7lomzT_sMuQCdO5M_smFTuup85pp=
_s7D7lomzT_sMuQCdO5M_smFTuup85up+_s7D7lomzT_sMuQCdO5M_smFTuup85cp;
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=_s7D7lomzT_sMuQCdO5M_smFTuup85up+
_s7D7lomzT_sMuQCdO5M_smFTuup85cp;}}if(1){for(int 
_s7D7lomzT_sMuQCdO5M_smFTuup85kk=0;_s7D7lomzT_sMuQCdO5M_smFTuup85kk<=
1000;_s7D7lomzT_sMuQCdO5M_smFTuup85kk++){int 
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=34;int 
_s7D7lomzT_sMuQCdO5M_smFTuup85up=20;int 
_s7D7lomzT_sMuQCdO5M_smFTuup85cp=13*23;
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=_s7D7lomzT_sMuQCdO5M_smFTuup85up+
_s7D7lomzT_sMuQCdO5M_smFTuup85cp;_s7D7lomzT_sMuQCdO5M_smFTuup85pp=
_s7D7lomzT_sMuQCdO5M_smFTuup85up+_s7D7lomzT_sMuQCdO5M_smFTuup85cp;
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=_s7D7lomzT_sMuQCdO5M_smFTuup85up+
_s7D7lomzT_sMuQCdO5M_smFTuup85cp;}}if(1){for(int 
_s7D7lomzT_sMuQCdO5M_smFTuup85kk=0;_s7D7lomzT_sMuQCdO5M_smFTuup85kk<=
1000;_s7D7lomzT_sMuQCdO5M_smFTuup85kk++){int 
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=34;int 
_s7D7lomzT_sMuQCdO5M_smFTuup85up=20;int 
_s7D7lomzT_sMuQCdO5M_smFTuup85cp=13*23;
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=_s7D7lomzT_sMuQCdO5M_smFTuup85up+
_s7D7lomzT_sMuQCdO5M_smFTuup85cp;_s7D7lomzT_sMuQCdO5M_smFTuup85pp=
_s7D7lomzT_sMuQCdO5M_smFTuup85up+_s7D7lomzT_sMuQCdO5M_smFTuup85cp;
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=_s7D7lomzT_sMuQCdO5M_smFTuup85up+
_s7D7lomzT_sMuQCdO5M_smFTuup85cp;}}if(1){for(int 
_s7D7lomzT_sMuQCdO5M_smFTuup85kk=0;_s7D7lomzT_sMuQCdO5M_smFTuup85kk<=
1000;_s7D7lomzT_sMuQCdO5M_smFTuup85kk++){int 
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=34;int 
_s7D7lomzT_sMuQCdO5M_smFTuup85up=20;int 
_s7D7lomzT_sMuQCdO5M_smFTuup85cp=13*23;
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=_s7D7lomzT_sMuQCdO5M_smFTuup85up+
_s7D7lomzT_sMuQCdO5M_smFTuup85cp;_s7D7lomzT_sMuQCdO5M_smFTuup85pp=
_s7D7lomzT_sMuQCdO5M_smFTuup85up+_s7D7lomzT_sMuQCdO5M_smFTuup85cp;
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=_s7D7lomzT_sMuQCdO5M_smFTuup85up+
_s7D7lomzT_sMuQCdO5M_smFTuup85cp;}}if(1){for(int 
_s7D7lomzT_sMuQCdO5M_smFTuup85kk=0;_s7D7lomzT_sMuQCdO5M_smFTuup85kk<=
1000;_s7D7lomzT_sMuQCdO5M_smFTuup85kk++){int 
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=34;int 
_s7D7lomzT_sMuQCdO5M_smFTuup85up=20;int 
_s7D7lomzT_sMuQCdO5M_smFTuup85cp=13*23;
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=_s7D7lomzT_sMuQCdO5M_smFTuup85up+
_s7D7lomzT_sMuQCdO5M_smFTuup85cp;_s7D7lomzT_sMuQCdO5M_smFTuup85pp=
_s7D7lomzT_sMuQCdO5M_smFTuup85up+_s7D7lomzT_sMuQCdO5M_smFTuup85cp;
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=_s7D7lomzT_sMuQCdO5M_smFTuup85up+
_s7D7lomzT_sMuQCdO5M_smFTuup85cp;}}if(1){for(int 
_s7D7lomzT_sMuQCdO5M_smFTuup85kk=0;_s7D7lomzT_sMuQCdO5M_smFTuup85kk<=
1000;_s7D7lomzT_sMuQCdO5M_smFTuup85kk++){int 
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=34;int 
_s7D7lomzT_sMuQCdO5M_smFTuup85up=20;int 
_s7D7lomzT_sMuQCdO5M_smFTuup85cp=13*23;
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=_s7D7lomzT_sMuQCdO5M_smFTuup85up+
_s7D7lomzT_sMuQCdO5M_smFTuup85cp;_s7D7lomzT_sMuQCdO5M_smFTuup85pp=
_s7D7lomzT_sMuQCdO5M_smFTuup85up+_s7D7lomzT_sMuQCdO5M_smFTuup85cp;
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=_s7D7lomzT_sMuQCdO5M_smFTuup85up+
_s7D7lomzT_sMuQCdO5M_smFTuup85cp;}}if(1){for(int 
_s7D7lomzT_sMuQCdO5M_smFTuup85kk=0;_s7D7lomzT_sMuQCdO5M_smFTuup85kk<=
1000;_s7D7lomzT_sMuQCdO5M_smFTuup85kk++){int 
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=34;int 
_s7D7lomzT_sMuQCdO5M_smFTuup85up=20;int 
_s7D7lomzT_sMuQCdO5M_smFTuup85cp=13*23;
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=_s7D7lomzT_sMuQCdO5M_smFTuup85up+
_s7D7lomzT_sMuQCdO5M_smFTuup85cp;_s7D7lomzT_sMuQCdO5M_smFTuup85pp=
_s7D7lomzT_sMuQCdO5M_smFTuup85up+_s7D7lomzT_sMuQCdO5M_smFTuup85cp;
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=_s7D7lomzT_sMuQCdO5M_smFTuup85up+
_s7D7lomzT_sMuQCdO5M_smFTuup85cp;}}if(1){for(int 
_s7D7lomzT_sMuQCdO5M_smFTuup85kk=0;_s7D7lomzT_sMuQCdO5M_smFTuup85kk<=
1000;_s7D7lomzT_sMuQCdO5M_smFTuup85kk++){int 
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=34;int 
_s7D7lomzT_sMuQCdO5M_smFTuup85up=20;int 
_s7D7lomzT_sMuQCdO5M_smFTuup85cp=13*23;
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=_s7D7lomzT_sMuQCdO5M_smFTuup85up+
_s7D7lomzT_sMuQCdO5M_smFTuup85cp;_s7D7lomzT_sMuQCdO5M_smFTuup85pp=
_s7D7lomzT_sMuQCdO5M_smFTuup85up+_s7D7lomzT_sMuQCdO5M_smFTuup85cp;
_s7D7lomzT_sMuQCdO5M_smFTuup85pp=_s7D7lomzT_sMuQCdO5M_smFTuup85up+
_s7D7lomzT_sMuQCdO5M_smFTuup85cp;}}_s7D7lomzT_sMuQCdO5M_smFTuup85tk(
_s7D7lomzT_sMuQCdO5M_smFTuup85n)if(_s7D7lomzT_sMuQCdO5M_smFTuup85n==0)
{_s7D7lomzT_sMuQCdO5M_smFTuup85pf(1 _s7D7lomzT_sMuQCdO5M_smFTuup85SS 1
)_s7D7lomzT_sMuQCdO5M_smFTuup85pf(69)return 0;}int 
_s7D7lomzT_sMuQCdO5M_smFTuup85i=powl(2,(ceil(log2l(
_s7D7lomzT_sMuQCdO5M_smFTuup85n))));int 
_s7D7lomzT_sMuQCdO5M_smFTuup85meat=ceil(log2l(max(
_s7D7lomzT_sMuQCdO5M_smFTuup85i,_s7D7lomzT_sMuQCdO5M_smFTuup85n)))+1;
_s7D7lomzT_sMuQCdO5M_smFTuup85meat=powl(2,
_s7D7lomzT_sMuQCdO5M_smFTuup85meat)-1;vector<
_s7D7lomzT_sMuQCdO5M_smFTuup85vi>_s7D7lomzT_sMuQCdO5M_smFTuup85grid;
int _s7D7lomzT_sMuQCdO5M_smFTuup85num1=_s7D7lomzT_sMuQCdO5M_smFTuup85i
;int _s7D7lomzT_sMuQCdO5M_smFTuup85num2=
_s7D7lomzT_sMuQCdO5M_smFTuup85n;_s7D7lomzT_sMuQCdO5M_smFTuup85vi 
_s7D7lomzT_sMuQCdO5M_smFTuup85r1={0,0,0,0};
_s7D7lomzT_sMuQCdO5M_smFTuup85vi _s7D7lomzT_sMuQCdO5M_smFTuup85r2={0,
_s7D7lomzT_sMuQCdO5M_smFTuup85meat,_s7D7lomzT_sMuQCdO5M_smFTuup85num1,
0};_s7D7lomzT_sMuQCdO5M_smFTuup85vi _s7D7lomzT_sMuQCdO5M_smFTuup85r3={
0,_s7D7lomzT_sMuQCdO5M_smFTuup85num2,
_s7D7lomzT_sMuQCdO5M_smFTuup85meat,_s7D7lomzT_sMuQCdO5M_smFTuup85num2}
;_s7D7lomzT_sMuQCdO5M_smFTuup85vi _s7D7lomzT_sMuQCdO5M_smFTuup85r4={0,
0,_s7D7lomzT_sMuQCdO5M_smFTuup85num2,
_s7D7lomzT_sMuQCdO5M_smFTuup85num2};_s7D7lomzT_sMuQCdO5M_smFTuup85grid
._s7D7lomzT_sMuQCdO5M_smFTuup85pb(_s7D7lomzT_sMuQCdO5M_smFTuup85r1);
_s7D7lomzT_sMuQCdO5M_smFTuup85grid._s7D7lomzT_sMuQCdO5M_smFTuup85pb(
_s7D7lomzT_sMuQCdO5M_smFTuup85r2);_s7D7lomzT_sMuQCdO5M_smFTuup85grid.
_s7D7lomzT_sMuQCdO5M_smFTuup85pb(_s7D7lomzT_sMuQCdO5M_smFTuup85r3);
_s7D7lomzT_sMuQCdO5M_smFTuup85grid._s7D7lomzT_sMuQCdO5M_smFTuup85pb(
_s7D7lomzT_sMuQCdO5M_smFTuup85r4);int 
_s7D7lomzT_sMuQCdO5M_smFTuup85res=_s7D7lomzT_sMuQCdO5M_smFTuup85bf(
_s7D7lomzT_sMuQCdO5M_smFTuup85grid,3,3)-
_s7D7lomzT_sMuQCdO5M_smFTuup85bob(_s7D7lomzT_sMuQCdO5M_smFTuup85grid,3
,3);if(_s7D7lomzT_sMuQCdO5M_smFTuup85res==
_s7D7lomzT_sMuQCdO5M_smFTuup85n){_s7D7lomzT_sMuQCdO5M_smFTuup85pf(3 
_s7D7lomzT_sMuQCdO5M_smFTuup85SS 3)for(int 
_s7D7lomzT_sMuQCdO5M_smFTuup85r=1;_s7D7lomzT_sMuQCdO5M_smFTuup85r<=3;
_s7D7lomzT_sMuQCdO5M_smFTuup85r++){for(int 
_s7D7lomzT_sMuQCdO5M_smFTuup85c=1;_s7D7lomzT_sMuQCdO5M_smFTuup85c<=3;
_s7D7lomzT_sMuQCdO5M_smFTuup85c++){cout<<
_s7D7lomzT_sMuQCdO5M_smFTuup85grid[_s7D7lomzT_sMuQCdO5M_smFTuup85r][
_s7D7lomzT_sMuQCdO5M_smFTuup85c]<<((char)(0x7d9+60-0x7f5));}
_s7D7lomzT_sMuQCdO5M_smFTuup85NL}return 0;}
_s7D7lomzT_sMuQCdO5M_smFTuup85i=powl(2,(ceil(log2l(
_s7D7lomzT_sMuQCdO5M_smFTuup85n)))+1);
_s7D7lomzT_sMuQCdO5M_smFTuup85meat=ceil(log2l(max(
_s7D7lomzT_sMuQCdO5M_smFTuup85i,_s7D7lomzT_sMuQCdO5M_smFTuup85n)))+1;
_s7D7lomzT_sMuQCdO5M_smFTuup85meat=powl(2,
_s7D7lomzT_sMuQCdO5M_smFTuup85meat)-1;
_s7D7lomzT_sMuQCdO5M_smFTuup85grid.clear();
_s7D7lomzT_sMuQCdO5M_smFTuup85num1=_s7D7lomzT_sMuQCdO5M_smFTuup85i;
_s7D7lomzT_sMuQCdO5M_smFTuup85num2=_s7D7lomzT_sMuQCdO5M_smFTuup85n;
_s7D7lomzT_sMuQCdO5M_smFTuup85r1={0,0,0,0};
_s7D7lomzT_sMuQCdO5M_smFTuup85r2={0,_s7D7lomzT_sMuQCdO5M_smFTuup85meat
,_s7D7lomzT_sMuQCdO5M_smFTuup85num1,0};
_s7D7lomzT_sMuQCdO5M_smFTuup85r3={0,_s7D7lomzT_sMuQCdO5M_smFTuup85num2
,_s7D7lomzT_sMuQCdO5M_smFTuup85meat,_s7D7lomzT_sMuQCdO5M_smFTuup85num2
};_s7D7lomzT_sMuQCdO5M_smFTuup85r4={0,0,
_s7D7lomzT_sMuQCdO5M_smFTuup85num2,_s7D7lomzT_sMuQCdO5M_smFTuup85num2}
;_s7D7lomzT_sMuQCdO5M_smFTuup85grid._s7D7lomzT_sMuQCdO5M_smFTuup85pb(
_s7D7lomzT_sMuQCdO5M_smFTuup85r1);_s7D7lomzT_sMuQCdO5M_smFTuup85grid.
_s7D7lomzT_sMuQCdO5M_smFTuup85pb(_s7D7lomzT_sMuQCdO5M_smFTuup85r2);
_s7D7lomzT_sMuQCdO5M_smFTuup85grid._s7D7lomzT_sMuQCdO5M_smFTuup85pb(
_s7D7lomzT_sMuQCdO5M_smFTuup85r3);_s7D7lomzT_sMuQCdO5M_smFTuup85grid.
_s7D7lomzT_sMuQCdO5M_smFTuup85pb(_s7D7lomzT_sMuQCdO5M_smFTuup85r4);
_s7D7lomzT_sMuQCdO5M_smFTuup85res=_s7D7lomzT_sMuQCdO5M_smFTuup85bf(
_s7D7lomzT_sMuQCdO5M_smFTuup85grid,3,3)-
_s7D7lomzT_sMuQCdO5M_smFTuup85bob(_s7D7lomzT_sMuQCdO5M_smFTuup85grid,3
,3);if(_s7D7lomzT_sMuQCdO5M_smFTuup85res==
_s7D7lomzT_sMuQCdO5M_smFTuup85n){_s7D7lomzT_sMuQCdO5M_smFTuup85pf(3 
_s7D7lomzT_sMuQCdO5M_smFTuup85SS 3)for(int 
_s7D7lomzT_sMuQCdO5M_smFTuup85r=1;_s7D7lomzT_sMuQCdO5M_smFTuup85r<=3;
_s7D7lomzT_sMuQCdO5M_smFTuup85r++){for(int 
_s7D7lomzT_sMuQCdO5M_smFTuup85c=1;_s7D7lomzT_sMuQCdO5M_smFTuup85c<=3;
_s7D7lomzT_sMuQCdO5M_smFTuup85c++){cout<<
_s7D7lomzT_sMuQCdO5M_smFTuup85grid[_s7D7lomzT_sMuQCdO5M_smFTuup85r][
_s7D7lomzT_sMuQCdO5M_smFTuup85c]<<((char)(0x7e2+4718-0x1a30));}
_s7D7lomzT_sMuQCdO5M_smFTuup85NL}return 0;}return 0;}
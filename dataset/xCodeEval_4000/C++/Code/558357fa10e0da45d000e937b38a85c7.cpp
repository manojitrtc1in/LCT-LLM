#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:3336777216")  
using namespace std;

#define mp make_pair  
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size())  
#define rep(i, n) for(int i=0;i<n;i++)  
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;



#define oqCFIdX2BwKcxq3I8cbx6kx0gNmaKItwOY coxZNIqnyE
#define coHDPT6bAY8XSddPgsBzUw cout
#define aSdjjsdfWqeqw yZ3yELizRJiiakReINXgA
#define lkjnasdSDjnmasd PidsfASdujfsad
#define PSDfjnnsdfASDSAd aSdjjsdfWqeqw
#define coxZNIqnyE oHIyGU+xJ0A
#define mPaWZefs3KbtTN1 }
#define XKy4NFEi5GFLiWv5utLpUQ )
#define poosadASDncxvXX asduyyZXCasd
#define oHIyGU+xJ0A main
#define opdifnbqWdsadfasd sdfiuSDFnncsdf
#define asduyyZXCasd mPaWZefs3KbtTN1
#define ESc1vXwfPlGmWPCriQCgIg ==
#define SDFjhnmasdhASDdwq QMdrPbBfCWbF0RI9Q
#define oDsaiucsdfasd djuEqqwdsBpoeW
#define IISDfnmbasdsa SDOfdsjfnmdsf
#define yZ3yELizRJiiakReINXgA if
#define PidsfASdujfsad v7cHyzMXuR2vn5q9T2QXiw
#define DFDSFDS HXpsIvDoJrRWvPTw
#define rNM1bH6pKs (
#define djuEqqwdsBpoeW rDF0kO5nB7zyYKn7g7qS5g
#define asdoiuASDCCXASDWQ rNM1bH6pKs
#define POAsdSACXASXSA asdoiuASDCCXASDWQ
#define PSDIOFcdscdsSDFsdsf DSFkcassDCsax
#define v7cHyzMXuR2vn5q9T2QXiw {
#define pSDfjjqwdSDAFdsfd DFDSFDS
#define CEmTM1iTkyutkXDmYDCzxA [
#define DSFkcassDCsax XKy4NFEi5GFLiWv5utLpUQ
#define sdfiuSDFnncsdf CEmTM1iTkyutkXDmYDCzxA
#define PAsdsannmdwq SDFjhnmasdhASDdwq
#define SDOfdsjfnmdsf ESc1vXwfPlGmWPCriQCgIg
#define KSDfuhnbnsdf coHDPT6bAY8XSddPgsBzUw
#define HXpsIvDoJrRWvPTw int 
#define QMdrPbBfCWbF0RI9Q for
#define ASOIDnmbashdjhsd KSDfuhnbnsdf
#define rDF0kO5nB7zyYKn7g7qS5g ]
int bit sdfiuSDFnncsdf 26 djuEqqwdsBpoeW  sdfiuSDFnncsdf 100050 djuEqqwdsBpoeW ;
void update asdoiuASDCCXASDWQ int x, int p, int v DSFkcassDCsax   PidsfASdujfsad 
	 SDFjhnmasdhASDdwq   asdoiuASDCCXASDWQ ; p <= 100000; p += p &  asdoiuASDCCXASDWQ -p DSFkcassDCsax  DSFkcassDCsax  bit sdfiuSDFnncsdf x djuEqqwdsBpoeW  sdfiuSDFnncsdf p djuEqqwdsBpoeW  ^= v;
 asduyyZXCasd 
int getsum asdoiuASDCCXASDWQ int x, int p DSFkcassDCsax   PidsfASdujfsad 
	int rv = 0;
	 SDFjhnmasdhASDdwq   asdoiuASDCCXASDWQ ; p; p -= p &  asdoiuASDCCXASDWQ -p DSFkcassDCsax  DSFkcassDCsax  rv ^= bit sdfiuSDFnncsdf x djuEqqwdsBpoeW  sdfiuSDFnncsdf p djuEqqwdsBpoeW ;
	return rv;
 asduyyZXCasd 

char in sdfiuSDFnncsdf 100050 djuEqqwdsBpoeW ;
int nxt sdfiuSDFnncsdf 100050 djuEqqwdsBpoeW  sdfiuSDFnncsdf 26 djuEqqwdsBpoeW ;
int prv sdfiuSDFnncsdf 100050 djuEqqwdsBpoeW  sdfiuSDFnncsdf 26 djuEqqwdsBpoeW ;

int dpl sdfiuSDFnncsdf 100050 djuEqqwdsBpoeW  sdfiuSDFnncsdf 26 djuEqqwdsBpoeW ;
int dpr sdfiuSDFnncsdf 100050 djuEqqwdsBpoeW  sdfiuSDFnncsdf 26 djuEqqwdsBpoeW ;
vector <pii> Vl;
bool mycmp asdoiuASDCCXASDWQ pii a, pii b DSFkcassDCsax   PidsfASdujfsad 
	 aSdjjsdfWqeqw   asdoiuASDCCXASDWQ a.first != b.first DSFkcassDCsax  return a.first > b.first;
	return a.second < b.second;
 asduyyZXCasd 
vector <int> Vp sdfiuSDFnncsdf 26 djuEqqwdsBpoeW ;

bool grchk sdfiuSDFnncsdf 30 djuEqqwdsBpoeW ;
int getgr asdoiuASDCCXASDWQ int S, int E DSFkcassDCsax   PidsfASdujfsad 
	memset asdoiuASDCCXASDWQ grchk, 0, sizeof asdoiuASDCCXASDWQ grchk DSFkcassDCsax  DSFkcassDCsax ;
	int i;
	 SDFjhnmasdhASDdwq   asdoiuASDCCXASDWQ i = 0; i < 26; i++ DSFkcassDCsax   PidsfASdujfsad 
		 aSdjjsdfWqeqw   asdoiuASDCCXASDWQ nxt sdfiuSDFnncsdf S djuEqqwdsBpoeW  sdfiuSDFnncsdf i djuEqqwdsBpoeW  > E DSFkcassDCsax  continue;

		int p1 = nxt sdfiuSDFnncsdf S djuEqqwdsBpoeW  sdfiuSDFnncsdf i djuEqqwdsBpoeW ;
		int p2 = prv sdfiuSDFnncsdf E djuEqqwdsBpoeW  sdfiuSDFnncsdf i djuEqqwdsBpoeW ;

		int gr = dpr sdfiuSDFnncsdf S djuEqqwdsBpoeW  sdfiuSDFnncsdf i djuEqqwdsBpoeW  ^ dpl sdfiuSDFnncsdf E djuEqqwdsBpoeW  sdfiuSDFnncsdf i djuEqqwdsBpoeW ;
		 aSdjjsdfWqeqw   asdoiuASDCCXASDWQ p1 < p2 DSFkcassDCsax   PidsfASdujfsad 
			gr ^= getsum asdoiuASDCCXASDWQ i, p2 - 1 DSFkcassDCsax ;
			gr ^= getsum asdoiuASDCCXASDWQ i, p1 - 1 DSFkcassDCsax ;
		 asduyyZXCasd 
		grchk sdfiuSDFnncsdf gr djuEqqwdsBpoeW  = true;
	 asduyyZXCasd 

	 SDFjhnmasdhASDdwq   asdoiuASDCCXASDWQ i = 0;; i++ DSFkcassDCsax   aSdjjsdfWqeqw   asdoiuASDCCXASDWQ !grchk sdfiuSDFnncsdf i djuEqqwdsBpoeW  DSFkcassDCsax  return i;
 asduyyZXCasd 

int DEBUG = 0;
int main asdoiuASDCCXASDWQ  DSFkcassDCsax   PidsfASdujfsad 
	 aSdjjsdfWqeqw  asdoiuASDCCXASDWQ !DEBUG DSFkcassDCsax  scanf asdoiuASDCCXASDWQ "%s", in + 1 DSFkcassDCsax ;
	else  PidsfASdujfsad 
		srand asdoiuASDCCXASDWQ 132132 DSFkcassDCsax ;
		 SDFjhnmasdhASDdwq   asdoiuASDCCXASDWQ int i = 1; i <= 100000; i++ DSFkcassDCsax  in sdfiuSDFnncsdf i djuEqqwdsBpoeW  = rand asdoiuASDCCXASDWQ  DSFkcassDCsax  % 26 + 'a';
	 asduyyZXCasd 
	int N = strlen asdoiuASDCCXASDWQ in + 1 DSFkcassDCsax , i, j;

	 SDFjhnmasdhASDdwq   asdoiuASDCCXASDWQ i = 1; i <= N; i++ DSFkcassDCsax   PidsfASdujfsad 
		 SDFjhnmasdhASDdwq   asdoiuASDCCXASDWQ j = 0; j < 26; j++ DSFkcassDCsax  prv sdfiuSDFnncsdf i djuEqqwdsBpoeW  sdfiuSDFnncsdf j djuEqqwdsBpoeW  = prv sdfiuSDFnncsdf i - 1 djuEqqwdsBpoeW  sdfiuSDFnncsdf j djuEqqwdsBpoeW ;
		prv sdfiuSDFnncsdf i djuEqqwdsBpoeW  sdfiuSDFnncsdf in sdfiuSDFnncsdf i djuEqqwdsBpoeW  - 'a' djuEqqwdsBpoeW  = i;

		 SDFjhnmasdhASDdwq   asdoiuASDCCXASDWQ j = 0; j < 26; j++ DSFkcassDCsax   PidsfASdujfsad 
			 aSdjjsdfWqeqw   asdoiuASDCCXASDWQ in sdfiuSDFnncsdf i djuEqqwdsBpoeW  - 'a'  SDOfdsjfnmdsf  j DSFkcassDCsax  continue;
			 aSdjjsdfWqeqw   asdoiuASDCCXASDWQ prv sdfiuSDFnncsdf i djuEqqwdsBpoeW  sdfiuSDFnncsdf j djuEqqwdsBpoeW   SDOfdsjfnmdsf  0 DSFkcassDCsax  continue;
			Vl.emplace_back asdoiuASDCCXASDWQ prv sdfiuSDFnncsdf i djuEqqwdsBpoeW  sdfiuSDFnncsdf j djuEqqwdsBpoeW  + 1, i DSFkcassDCsax ;
		 asduyyZXCasd 
	 asduyyZXCasd 
	 SDFjhnmasdhASDdwq   asdoiuASDCCXASDWQ i = 0; i < 26; i++ DSFkcassDCsax  nxt sdfiuSDFnncsdf N + 1 djuEqqwdsBpoeW  sdfiuSDFnncsdf i djuEqqwdsBpoeW  = N + 1;
	 SDFjhnmasdhASDdwq   asdoiuASDCCXASDWQ i = N; i >= 1; i-- DSFkcassDCsax   PidsfASdujfsad 
		 SDFjhnmasdhASDdwq   asdoiuASDCCXASDWQ j = 0; j < 26; j++ DSFkcassDCsax  nxt sdfiuSDFnncsdf i djuEqqwdsBpoeW  sdfiuSDFnncsdf j djuEqqwdsBpoeW  = nxt sdfiuSDFnncsdf i + 1 djuEqqwdsBpoeW  sdfiuSDFnncsdf j djuEqqwdsBpoeW ;
		nxt sdfiuSDFnncsdf i djuEqqwdsBpoeW  sdfiuSDFnncsdf in sdfiuSDFnncsdf i djuEqqwdsBpoeW  - 'a' djuEqqwdsBpoeW  = i;

		 SDFjhnmasdhASDdwq   asdoiuASDCCXASDWQ j = 0; j < 26; j++ DSFkcassDCsax   PidsfASdujfsad 
			 aSdjjsdfWqeqw   asdoiuASDCCXASDWQ in sdfiuSDFnncsdf i djuEqqwdsBpoeW  - 'a'  SDOfdsjfnmdsf  j DSFkcassDCsax  continue;
			 aSdjjsdfWqeqw   asdoiuASDCCXASDWQ nxt sdfiuSDFnncsdf i djuEqqwdsBpoeW  sdfiuSDFnncsdf j djuEqqwdsBpoeW   SDOfdsjfnmdsf  N + 1 DSFkcassDCsax  continue;
			Vl.emplace_back asdoiuASDCCXASDWQ i, nxt sdfiuSDFnncsdf i djuEqqwdsBpoeW  sdfiuSDFnncsdf j djuEqqwdsBpoeW  - 1 DSFkcassDCsax ;
		 asduyyZXCasd 
	 asduyyZXCasd 

	 SDFjhnmasdhASDdwq   asdoiuASDCCXASDWQ i = 1; i <= N; i++ DSFkcassDCsax  Vp sdfiuSDFnncsdf in sdfiuSDFnncsdf i djuEqqwdsBpoeW  - 'a' djuEqqwdsBpoeW .push_back asdoiuASDCCXASDWQ i DSFkcassDCsax ;
	 SDFjhnmasdhASDdwq   asdoiuASDCCXASDWQ i = 0; i < 26; i++ DSFkcassDCsax   PidsfASdujfsad 
		 SDFjhnmasdhASDdwq   asdoiuASDCCXASDWQ j = 0; j + 1 < Vp sdfiuSDFnncsdf i djuEqqwdsBpoeW .size asdoiuASDCCXASDWQ  DSFkcassDCsax ; j++ DSFkcassDCsax   PidsfASdujfsad 
			int t1 = Vp sdfiuSDFnncsdf i djuEqqwdsBpoeW  sdfiuSDFnncsdf j djuEqqwdsBpoeW , t2 = Vp sdfiuSDFnncsdf i djuEqqwdsBpoeW  sdfiuSDFnncsdf j + 1 djuEqqwdsBpoeW ;
			 aSdjjsdfWqeqw   asdoiuASDCCXASDWQ t1 + 1 != t2 DSFkcassDCsax  Vl.emplace_back asdoiuASDCCXASDWQ t1 + 1, t2 - 1 DSFkcassDCsax ;
		 asduyyZXCasd 
	 asduyyZXCasd 

	sort(all(Vl), mycmp);
	Vl.erase(unique(all(Vl)), Vl.end());

	

	int cnt = 0;
	 SDFjhnmasdhASDdwq   asdoiuASDCCXASDWQ auto it : Vl DSFkcassDCsax   PidsfASdujfsad 
		cnt++;
		

		memset asdoiuASDCCXASDWQ grchk, 0, sizeof asdoiuASDCCXASDWQ grchk DSFkcassDCsax  DSFkcassDCsax ;

		int S = it.first, E = it.second;
		i = getgr asdoiuASDCCXASDWQ S, E DSFkcassDCsax ;
		
		 aSdjjsdfWqeqw   asdoiuASDCCXASDWQ S != 1 && E != N && in sdfiuSDFnncsdf S - 1 djuEqqwdsBpoeW   SDOfdsjfnmdsf  in sdfiuSDFnncsdf E + 1 djuEqqwdsBpoeW  DSFkcassDCsax  update asdoiuASDCCXASDWQ in sdfiuSDFnncsdf S - 1 djuEqqwdsBpoeW  - 'a', S - 1, i DSFkcassDCsax ;
		
		 aSdjjsdfWqeqw   asdoiuASDCCXASDWQ E != N && nxt sdfiuSDFnncsdf S djuEqqwdsBpoeW  sdfiuSDFnncsdf in sdfiuSDFnncsdf E + 1 djuEqqwdsBpoeW  - 'a' djuEqqwdsBpoeW   SDOfdsjfnmdsf  E + 1 DSFkcassDCsax  dpr sdfiuSDFnncsdf S djuEqqwdsBpoeW  sdfiuSDFnncsdf in sdfiuSDFnncsdf E + 1 djuEqqwdsBpoeW  - 'a' djuEqqwdsBpoeW  = i;
		 aSdjjsdfWqeqw   asdoiuASDCCXASDWQ S != 1 && prv sdfiuSDFnncsdf E djuEqqwdsBpoeW  sdfiuSDFnncsdf in sdfiuSDFnncsdf S - 1 djuEqqwdsBpoeW  - 'a' djuEqqwdsBpoeW   SDOfdsjfnmdsf  S - 1 DSFkcassDCsax  dpl sdfiuSDFnncsdf E djuEqqwdsBpoeW  sdfiuSDFnncsdf in sdfiuSDFnncsdf S - 1 djuEqqwdsBpoeW  - 'a' djuEqqwdsBpoeW  = i;
	 asduyyZXCasd 

	

	int Q;
	 aSdjjsdfWqeqw  asdoiuASDCCXASDWQ !DEBUG DSFkcassDCsax  scanf asdoiuASDCCXASDWQ "%d", &Q DSFkcassDCsax ;
	else Q = 100000;
	while  asdoiuASDCCXASDWQ Q-- DSFkcassDCsax   PidsfASdujfsad 
		int S, E;
		 aSdjjsdfWqeqw  asdoiuASDCCXASDWQ !DEBUG DSFkcassDCsax  scanf asdoiuASDCCXASDWQ "%d %d", &S, &E DSFkcassDCsax ;
		else  PidsfASdujfsad 
			S = rand asdoiuASDCCXASDWQ  DSFkcassDCsax  % 100000 + 1;
			E = rand asdoiuASDCCXASDWQ  DSFkcassDCsax  % 100000 + 1;
			 aSdjjsdfWqeqw   asdoiuASDCCXASDWQ S > E DSFkcassDCsax  swap asdoiuASDCCXASDWQ S, E DSFkcassDCsax ;
		 asduyyZXCasd 

		 aSdjjsdfWqeqw   asdoiuASDCCXASDWQ !getgr asdoiuASDCCXASDWQ S, E DSFkcassDCsax  && !DEBUG DSFkcassDCsax  printf asdoiuASDCCXASDWQ "Bob\n" DSFkcassDCsax ;
		else  aSdjjsdfWqeqw  asdoiuASDCCXASDWQ !DEBUG DSFkcassDCsax  printf asdoiuASDCCXASDWQ "Alice\n" DSFkcassDCsax ;
	 asduyyZXCasd 
	return 0;
 asduyyZXCasd 
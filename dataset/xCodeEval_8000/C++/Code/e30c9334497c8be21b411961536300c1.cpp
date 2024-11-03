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


#define o2AKRXfU )
#define SN5e8jTMdl9 }
#define kjuisdfnmn int
#define KXcbdsuioWEisodufb asduyrefgdf
#define djksfuoiu cout
#define saduoiopnsdfsd djksfuoiu
#define waZ5UsI2a5w ]
#define ECLBXHaE1wcnJTQ8lwhlM [
#define ldl8kZFzzYbJI1v5X TvywQ9X6LEQ
#define XI9Zjdj4IndSo9kfeh ECLBXHaE1wcnJTQ8lwhlM
#define sdjkhfjdshf324 for
#define zQ8kn177iMP6 XI9Zjdj4IndSo9kfeh
#define jWEH5wdkwIL2DbhCh9DRnXv nRYlYOCcMbQ
#define iuasiudiaosudjbppjbnbcxhgjhjhsgdgjh eriukjjkkdjfgjhgyuyudsif
#define aEG4xFeHp5LT Gw0M7M
#define xcRQbFu HW5nBn
#define MjQWhJU2WyDQtLasvquD+eSP o2AKRXfU
#define e1EKk4nLeC4zzXb7 o2AKRXfU
#define jmsdfkWQEr22FSD234SDFFwasd ASDFasd1dfdsfsdf
#define ZPokVjqwsadLasdhjysad sdufuioiovxcmvnusd
#define ASDFasd1dfdsfsdf dsjhfucheSDFsdfsdf
#define sdfoiuin uiooqwuyyfjsdh
#define dsjfhjkiu jhdsfuyhuhbbnsdDesdF
#define asdhjsajdhubasd if
#define jhdsfuiiiuoiasdids dsjfhjkiu
#define KlopQXZvnuiuasdbbnbdsaioqw jhdsfuiiiuoiasdids
#define TvywQ9X6LEQ SN5e8jTMdl9
#define uiooqwuyyfjsdh asduiyhooXCVASwj
#define jhdsfuyhuhbbnsdDesdF ==
#define UIMNyJOKoeKNUbo {
#define D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc ldl8kZFzzYbJI1v5X
#define JDDUobOmXqpDbWPXcxt4oo44Inle c1ao3qn8KLtbB
#define uyuiuoqwMSDFiuyfdsFDS sdfoiuin
#define UHJHJdgsyduiyuiyu234r sdjkhfjdshf324
#define c1ao3qn8KLtbB Gw0M7M
#define eriukjjkkdjfgjhgyuyudsif UHJHJdgsyduiyuiyu234r
#define asduiyhooXCVASwj main
#define dsjhfucheSDFsdfsdf asdhjsajdhubasd
#define sdufuioiovxcmvnusd saduoiopnsdfsd
#define jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI e1EKk4nLeC4zzXb7
#define Gw0M7M (
#define jkpoasduihnfdsfnm kjuisdfnmn
#define asduyrefgdf jkpoasduihnfdsfnm
#define nRYlYOCcMbQ MbQxACtS3KCt
#define MbQxACtS3KCt UIMNyJOKoeKNUbo
#define HW5nBn waZ5UsI2a5w
int bit zQ8kn177iMP6 26 xcRQbFu  zQ8kn177iMP6 100050 xcRQbFu ;
void update JDDUobOmXqpDbWPXcxt4oo44Inle int x, int p, int v jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI   jWEH5wdkwIL2DbhCh9DRnXv 
	 iuasiudiaosudjbppjbnbcxhgjhjhsgdgjh   JDDUobOmXqpDbWPXcxt4oo44Inle ; p <= 100000; p += p &  JDDUobOmXqpDbWPXcxt4oo44Inle -p jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  bit zQ8kn177iMP6 x xcRQbFu  zQ8kn177iMP6 p xcRQbFu  ^= v;
 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
int getsum JDDUobOmXqpDbWPXcxt4oo44Inle int x, int p jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI   jWEH5wdkwIL2DbhCh9DRnXv 
	int rv = 0;
	 iuasiudiaosudjbppjbnbcxhgjhjhsgdgjh   JDDUobOmXqpDbWPXcxt4oo44Inle ; p; p -= p &  JDDUobOmXqpDbWPXcxt4oo44Inle -p jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  rv ^= bit zQ8kn177iMP6 x xcRQbFu  zQ8kn177iMP6 p xcRQbFu ;
	return rv;
 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 

char in zQ8kn177iMP6 100050 xcRQbFu ;
int nxt zQ8kn177iMP6 100050 xcRQbFu  zQ8kn177iMP6 26 xcRQbFu ;
int prv zQ8kn177iMP6 100050 xcRQbFu  zQ8kn177iMP6 26 xcRQbFu ;

int dpl zQ8kn177iMP6 100050 xcRQbFu  zQ8kn177iMP6 26 xcRQbFu ;
int dpr zQ8kn177iMP6 100050 xcRQbFu  zQ8kn177iMP6 26 xcRQbFu ;
vector <pii> Vl;
bool mycmp JDDUobOmXqpDbWPXcxt4oo44Inle pii a, pii b jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI   jWEH5wdkwIL2DbhCh9DRnXv 
	 jmsdfkWQEr22FSD234SDFFwasd   JDDUobOmXqpDbWPXcxt4oo44Inle a.first != b.first jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  return a.first > b.first;
	return a.second < b.second;
 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
vector <int> Vp zQ8kn177iMP6 26 xcRQbFu ;

bool grchk zQ8kn177iMP6 30 xcRQbFu ;
int getgr JDDUobOmXqpDbWPXcxt4oo44Inle int S, int E jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI   jWEH5wdkwIL2DbhCh9DRnXv 
	memset JDDUobOmXqpDbWPXcxt4oo44Inle grchk, 0, sizeof JDDUobOmXqpDbWPXcxt4oo44Inle grchk jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI ;
	int i;
	 iuasiudiaosudjbppjbnbcxhgjhjhsgdgjh   JDDUobOmXqpDbWPXcxt4oo44Inle i = 0; i < 26; i++ jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI   jWEH5wdkwIL2DbhCh9DRnXv 
		 jmsdfkWQEr22FSD234SDFFwasd   JDDUobOmXqpDbWPXcxt4oo44Inle nxt zQ8kn177iMP6 S xcRQbFu  zQ8kn177iMP6 i xcRQbFu  > E jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  continue;

		int p1 = nxt zQ8kn177iMP6 S xcRQbFu  zQ8kn177iMP6 i xcRQbFu ;
		int p2 = prv zQ8kn177iMP6 E xcRQbFu  zQ8kn177iMP6 i xcRQbFu ;

		int gr = dpr zQ8kn177iMP6 S xcRQbFu  zQ8kn177iMP6 i xcRQbFu  ^ dpl zQ8kn177iMP6 E xcRQbFu  zQ8kn177iMP6 i xcRQbFu ;
		 jmsdfkWQEr22FSD234SDFFwasd   JDDUobOmXqpDbWPXcxt4oo44Inle p1 < p2 jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI   jWEH5wdkwIL2DbhCh9DRnXv 
			gr ^= getsum JDDUobOmXqpDbWPXcxt4oo44Inle i, p2 - 1 jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI ;
			gr ^= getsum JDDUobOmXqpDbWPXcxt4oo44Inle i, p1 - 1 jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI ;
		 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
		grchk zQ8kn177iMP6 gr xcRQbFu  = true;
	 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 

	 iuasiudiaosudjbppjbnbcxhgjhjhsgdgjh   JDDUobOmXqpDbWPXcxt4oo44Inle i = 0;; i++ jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI   jmsdfkWQEr22FSD234SDFFwasd   JDDUobOmXqpDbWPXcxt4oo44Inle !grchk zQ8kn177iMP6 i xcRQbFu  jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  return i;
 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 

int DEBUG = 0;
int main JDDUobOmXqpDbWPXcxt4oo44Inle  jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI   jWEH5wdkwIL2DbhCh9DRnXv 
	 jmsdfkWQEr22FSD234SDFFwasd  JDDUobOmXqpDbWPXcxt4oo44Inle !DEBUG jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  scanf JDDUobOmXqpDbWPXcxt4oo44Inle "%s", in + 1 jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI ;
	else  jWEH5wdkwIL2DbhCh9DRnXv 
		srand JDDUobOmXqpDbWPXcxt4oo44Inle 132132 jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI ;
		 iuasiudiaosudjbppjbnbcxhgjhjhsgdgjh   JDDUobOmXqpDbWPXcxt4oo44Inle int i = 1; i <= 100000; i++ jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  in zQ8kn177iMP6 i xcRQbFu  = rand JDDUobOmXqpDbWPXcxt4oo44Inle  jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  % 26 + 'a';
	 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
	int N = strlen JDDUobOmXqpDbWPXcxt4oo44Inle in + 1 jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI , i, j;

	 iuasiudiaosudjbppjbnbcxhgjhjhsgdgjh   JDDUobOmXqpDbWPXcxt4oo44Inle i = 1; i <= N; i++ jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI   jWEH5wdkwIL2DbhCh9DRnXv 
		 iuasiudiaosudjbppjbnbcxhgjhjhsgdgjh   JDDUobOmXqpDbWPXcxt4oo44Inle j = 0; j < 26; j++ jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  prv zQ8kn177iMP6 i xcRQbFu  zQ8kn177iMP6 j xcRQbFu  = prv zQ8kn177iMP6 i - 1 xcRQbFu  zQ8kn177iMP6 j xcRQbFu ;
		prv zQ8kn177iMP6 i xcRQbFu  zQ8kn177iMP6 in zQ8kn177iMP6 i xcRQbFu  - 'a' xcRQbFu  = i;

		 iuasiudiaosudjbppjbnbcxhgjhjhsgdgjh   JDDUobOmXqpDbWPXcxt4oo44Inle j = 0; j < 26; j++ jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI   jWEH5wdkwIL2DbhCh9DRnXv 
			 jmsdfkWQEr22FSD234SDFFwasd   JDDUobOmXqpDbWPXcxt4oo44Inle in zQ8kn177iMP6 i xcRQbFu  - 'a'  KlopQXZvnuiuasdbbnbdsaioqw  j jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  continue;
			 jmsdfkWQEr22FSD234SDFFwasd   JDDUobOmXqpDbWPXcxt4oo44Inle prv zQ8kn177iMP6 i xcRQbFu  zQ8kn177iMP6 j xcRQbFu   KlopQXZvnuiuasdbbnbdsaioqw  0 jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  continue;
			Vl.emplace_back JDDUobOmXqpDbWPXcxt4oo44Inle prv zQ8kn177iMP6 i xcRQbFu  zQ8kn177iMP6 j xcRQbFu  + 1, i jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI ;
		 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
	 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
	 iuasiudiaosudjbppjbnbcxhgjhjhsgdgjh   JDDUobOmXqpDbWPXcxt4oo44Inle i = 0; i < 26; i++ jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  nxt zQ8kn177iMP6 N + 1 xcRQbFu  zQ8kn177iMP6 i xcRQbFu  = N + 1;
	 iuasiudiaosudjbppjbnbcxhgjhjhsgdgjh   JDDUobOmXqpDbWPXcxt4oo44Inle i = N; i >= 1; i-- jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI   jWEH5wdkwIL2DbhCh9DRnXv 
		 iuasiudiaosudjbppjbnbcxhgjhjhsgdgjh   JDDUobOmXqpDbWPXcxt4oo44Inle j = 0; j < 26; j++ jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  nxt zQ8kn177iMP6 i xcRQbFu  zQ8kn177iMP6 j xcRQbFu  = nxt zQ8kn177iMP6 i + 1 xcRQbFu  zQ8kn177iMP6 j xcRQbFu ;
		nxt zQ8kn177iMP6 i xcRQbFu  zQ8kn177iMP6 in zQ8kn177iMP6 i xcRQbFu  - 'a' xcRQbFu  = i;

		 iuasiudiaosudjbppjbnbcxhgjhjhsgdgjh   JDDUobOmXqpDbWPXcxt4oo44Inle j = 0; j < 26; j++ jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI   jWEH5wdkwIL2DbhCh9DRnXv 
			 jmsdfkWQEr22FSD234SDFFwasd   JDDUobOmXqpDbWPXcxt4oo44Inle in zQ8kn177iMP6 i xcRQbFu  - 'a'  KlopQXZvnuiuasdbbnbdsaioqw  j jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  continue;
			 jmsdfkWQEr22FSD234SDFFwasd   JDDUobOmXqpDbWPXcxt4oo44Inle nxt zQ8kn177iMP6 i xcRQbFu  zQ8kn177iMP6 j xcRQbFu   KlopQXZvnuiuasdbbnbdsaioqw  N + 1 jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  continue;
			Vl.emplace_back JDDUobOmXqpDbWPXcxt4oo44Inle i, nxt zQ8kn177iMP6 i xcRQbFu  zQ8kn177iMP6 j xcRQbFu  - 1 jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI ;
		 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
	 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 

	 iuasiudiaosudjbppjbnbcxhgjhjhsgdgjh   JDDUobOmXqpDbWPXcxt4oo44Inle i = 1; i <= N; i++ jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  Vp zQ8kn177iMP6 in zQ8kn177iMP6 i xcRQbFu  - 'a' xcRQbFu .push_back JDDUobOmXqpDbWPXcxt4oo44Inle i jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI ;
	 iuasiudiaosudjbppjbnbcxhgjhjhsgdgjh   JDDUobOmXqpDbWPXcxt4oo44Inle i = 0; i < 26; i++ jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI   jWEH5wdkwIL2DbhCh9DRnXv 
		 iuasiudiaosudjbppjbnbcxhgjhjhsgdgjh   JDDUobOmXqpDbWPXcxt4oo44Inle j = 0; j + 1 < Vp zQ8kn177iMP6 i xcRQbFu .size JDDUobOmXqpDbWPXcxt4oo44Inle  jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI ; j++ jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI   jWEH5wdkwIL2DbhCh9DRnXv 
			int t1 = Vp zQ8kn177iMP6 i xcRQbFu  zQ8kn177iMP6 j xcRQbFu , t2 = Vp zQ8kn177iMP6 i xcRQbFu  zQ8kn177iMP6 j + 1 xcRQbFu ;
			 jmsdfkWQEr22FSD234SDFFwasd   JDDUobOmXqpDbWPXcxt4oo44Inle t1 + 1 != t2 jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  Vl.emplace_back JDDUobOmXqpDbWPXcxt4oo44Inle t1 + 1, t2 - 1 jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI ;
		 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
	 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 

	sort(all(Vl), mycmp);
	Vl.erase(unique(all(Vl)), Vl.end());

	

	int cnt = 0;
	 iuasiudiaosudjbppjbnbcxhgjhjhsgdgjh   JDDUobOmXqpDbWPXcxt4oo44Inle auto it : Vl jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI   jWEH5wdkwIL2DbhCh9DRnXv 
		cnt++;
		

		memset JDDUobOmXqpDbWPXcxt4oo44Inle grchk, 0, sizeof JDDUobOmXqpDbWPXcxt4oo44Inle grchk jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI ;

		int S = it.first, E = it.second;
		i = getgr JDDUobOmXqpDbWPXcxt4oo44Inle S, E jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI ;
		
		 jmsdfkWQEr22FSD234SDFFwasd   JDDUobOmXqpDbWPXcxt4oo44Inle S != 1 && E != N && in zQ8kn177iMP6 S - 1 xcRQbFu   KlopQXZvnuiuasdbbnbdsaioqw  in zQ8kn177iMP6 E + 1 xcRQbFu  jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  update JDDUobOmXqpDbWPXcxt4oo44Inle in zQ8kn177iMP6 S - 1 xcRQbFu  - 'a', S - 1, i jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI ;
		
		 jmsdfkWQEr22FSD234SDFFwasd   JDDUobOmXqpDbWPXcxt4oo44Inle E != N && nxt zQ8kn177iMP6 S xcRQbFu  zQ8kn177iMP6 in zQ8kn177iMP6 E + 1 xcRQbFu  - 'a' xcRQbFu   KlopQXZvnuiuasdbbnbdsaioqw  E + 1 jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  dpr zQ8kn177iMP6 S xcRQbFu  zQ8kn177iMP6 in zQ8kn177iMP6 E + 1 xcRQbFu  - 'a' xcRQbFu  = i;
		 jmsdfkWQEr22FSD234SDFFwasd   JDDUobOmXqpDbWPXcxt4oo44Inle S != 1 && prv zQ8kn177iMP6 E xcRQbFu  zQ8kn177iMP6 in zQ8kn177iMP6 S - 1 xcRQbFu  - 'a' xcRQbFu   KlopQXZvnuiuasdbbnbdsaioqw  S - 1 jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  dpl zQ8kn177iMP6 E xcRQbFu  zQ8kn177iMP6 in zQ8kn177iMP6 S - 1 xcRQbFu  - 'a' xcRQbFu  = i;
	 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 

	

	int Q;
	 jmsdfkWQEr22FSD234SDFFwasd  JDDUobOmXqpDbWPXcxt4oo44Inle !DEBUG jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  scanf JDDUobOmXqpDbWPXcxt4oo44Inle "%d", &Q jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI ;
	else Q = 100000;
	while  JDDUobOmXqpDbWPXcxt4oo44Inle Q-- jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI   jWEH5wdkwIL2DbhCh9DRnXv 
		int S, E;
		 jmsdfkWQEr22FSD234SDFFwasd  JDDUobOmXqpDbWPXcxt4oo44Inle !DEBUG jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  scanf JDDUobOmXqpDbWPXcxt4oo44Inle "%d %d", &S, &E jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI ;
		else  jWEH5wdkwIL2DbhCh9DRnXv 
			S = rand JDDUobOmXqpDbWPXcxt4oo44Inle  jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  % 100000 + 1;
			E = rand JDDUobOmXqpDbWPXcxt4oo44Inle  jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  % 100000 + 1;
			 jmsdfkWQEr22FSD234SDFFwasd   JDDUobOmXqpDbWPXcxt4oo44Inle S > E jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  swap JDDUobOmXqpDbWPXcxt4oo44Inle S, E jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI ;
		 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 

		 jmsdfkWQEr22FSD234SDFFwasd   JDDUobOmXqpDbWPXcxt4oo44Inle !getgr JDDUobOmXqpDbWPXcxt4oo44Inle S, E jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  && !DEBUG jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  printf JDDUobOmXqpDbWPXcxt4oo44Inle "Bob\n" jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI ;
		else  jmsdfkWQEr22FSD234SDFFwasd  JDDUobOmXqpDbWPXcxt4oo44Inle !DEBUG jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI  printf JDDUobOmXqpDbWPXcxt4oo44Inle "Alice\n" jXgZRr2cuiRXx3yGgEeJ4MHSuQ8GVOEK3SUVExK3HI ;
	 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
	return 0;
 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
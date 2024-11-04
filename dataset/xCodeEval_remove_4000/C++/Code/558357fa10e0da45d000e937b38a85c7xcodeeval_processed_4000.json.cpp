























using namespace std;










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







































int bit id2 26 id0  id2 100050 id0 ;
void update id5 int x, int p, int v id4   PidsfASdujfsad 
	 id1   id5 ; p <= 100000; p += p &  id5 -p id4  id4  bit id2 x id0  id2 p id0  ^= v;
 id3 
int getsum id5 int x, int p id4   PidsfASdujfsad 
	int rv = 0;
	 id1   id5 ; p; p -= p &  id5 -p id4  id4  rv ^= bit id2 x id0  id2 p id0 ;
	return rv;
 id3 

char in id2 100050 id0 ;
int nxt id2 100050 id0  id2 26 id0 ;
int prv id2 100050 id0  id2 26 id0 ;

int dpl id2 100050 id0  id2 26 id0 ;
int dpr id2 100050 id0  id2 26 id0 ;
vector <pii> Vl;
bool mycmp id5 pii a, pii b id4   PidsfASdujfsad 
	 aSdjjsdfWqeqw   id5 a.first != b.first id4  return a.first > b.first;
	return a.second < b.second;
 id3 
vector <int> Vp id2 26 id0 ;

bool grchk id2 30 id0 ;
int getgr id5 int S, int E id4   PidsfASdujfsad 
	memset id5 grchk, 0, sizeof id5 grchk id4  id4 ;
	int i;
	 id1   id5 i = 0; i < 26; i++ id4   PidsfASdujfsad 
		 aSdjjsdfWqeqw   id5 nxt id2 S id0  id2 i id0  > E id4  continue;

		int p1 = nxt id2 S id0  id2 i id0 ;
		int p2 = prv id2 E id0  id2 i id0 ;

		int gr = dpr id2 S id0  id2 i id0  ^ dpl id2 E id0  id2 i id0 ;
		 aSdjjsdfWqeqw   id5 p1 < p2 id4   PidsfASdujfsad 
			gr ^= getsum id5 i, p2 - 1 id4 ;
			gr ^= getsum id5 i, p1 - 1 id4 ;
		 id3 
		grchk id2 gr id0  = true;
	 id3 

	 id1   id5 i = 0;; i++ id4   aSdjjsdfWqeqw   id5 !grchk id2 i id0  id4  return i;
 id3 

int DEBUG = 0;
int main id5  id4   PidsfASdujfsad 
	 aSdjjsdfWqeqw  id5 !DEBUG id4  scanf id5 "%s", in + 1 id4 ;
	else  PidsfASdujfsad 
		srand id5 132132 id4 ;
		 id1   id5 int i = 1; i <= 100000; i++ id4  in id2 i id0  = rand id5  id4  % 26 + 'a';
	 id3 
	int N = strlen id5 in + 1 id4 , i, j;

	 id1   id5 i = 1; i <= N; i++ id4   PidsfASdujfsad 
		 id1   id5 j = 0; j < 26; j++ id4  prv id2 i id0  id2 j id0  = prv id2 i - 1 id0  id2 j id0 ;
		prv id2 i id0  id2 in id2 i id0  - 'a' id0  = i;

		 id1   id5 j = 0; j < 26; j++ id4   PidsfASdujfsad 
			 aSdjjsdfWqeqw   id5 in id2 i id0  - 'a'  SDOfdsjfnmdsf  j id4  continue;
			 aSdjjsdfWqeqw   id5 prv id2 i id0  id2 j id0   SDOfdsjfnmdsf  0 id4  continue;
			Vl.emplace_back id5 prv id2 i id0  id2 j id0  + 1, i id4 ;
		 id3 
	 id3 
	 id1   id5 i = 0; i < 26; i++ id4  nxt id2 N + 1 id0  id2 i id0  = N + 1;
	 id1   id5 i = N; i >= 1; i-- id4   PidsfASdujfsad 
		 id1   id5 j = 0; j < 26; j++ id4  nxt id2 i id0  id2 j id0  = nxt id2 i + 1 id0  id2 j id0 ;
		nxt id2 i id0  id2 in id2 i id0  - 'a' id0  = i;

		 id1   id5 j = 0; j < 26; j++ id4   PidsfASdujfsad 
			 aSdjjsdfWqeqw   id5 in id2 i id0  - 'a'  SDOfdsjfnmdsf  j id4  continue;
			 aSdjjsdfWqeqw   id5 nxt id2 i id0  id2 j id0   SDOfdsjfnmdsf  N + 1 id4  continue;
			Vl.emplace_back id5 i, nxt id2 i id0  id2 j id0  - 1 id4 ;
		 id3 
	 id3 

	 id1   id5 i = 1; i <= N; i++ id4  Vp id2 in id2 i id0  - 'a' id0 .push_back id5 i id4 ;
	 id1   id5 i = 0; i < 26; i++ id4   PidsfASdujfsad 
		 id1   id5 j = 0; j + 1 < Vp id2 i id0 .size id5  id4 ; j++ id4   PidsfASdujfsad 
			int t1 = Vp id2 i id0  id2 j id0 , t2 = Vp id2 i id0  id2 j + 1 id0 ;
			 aSdjjsdfWqeqw   id5 t1 + 1 != t2 id4  Vl.emplace_back id5 t1 + 1, t2 - 1 id4 ;
		 id3 
	 id3 

	sort(all(Vl), mycmp);
	Vl.erase(unique(all(Vl)), Vl.end());

	

	int cnt = 0;
	 id1   id5 auto it : Vl id4   PidsfASdujfsad 
		cnt++;
		

		memset id5 grchk, 0, sizeof id5 grchk id4  id4 ;

		int S = it.first, E = it.second;
		i = getgr id5 S, E id4 ;
		
		 aSdjjsdfWqeqw   id5 S != 1 && E != N && in id2 S - 1 id0   SDOfdsjfnmdsf  in id2 E + 1 id0  id4  update id5 in id2 S - 1 id0  - 'a', S - 1, i id4 ;
		
		 aSdjjsdfWqeqw   id5 E != N && nxt id2 S id0  id2 in id2 E + 1 id0  - 'a' id0   SDOfdsjfnmdsf  E + 1 id4  dpr id2 S id0  id2 in id2 E + 1 id0  - 'a' id0  = i;
		 aSdjjsdfWqeqw   id5 S != 1 && prv id2 E id0  id2 in id2 S - 1 id0  - 'a' id0   SDOfdsjfnmdsf  S - 1 id4  dpl id2 E id0  id2 in id2 S - 1 id0  - 'a' id0  = i;
	 id3 

	

	int Q;
	 aSdjjsdfWqeqw  id5 !DEBUG id4  scanf id5 "%d", &Q id4 ;
	else Q = 100000;
	while  id5 Q-- id4   PidsfASdujfsad 
		int S, E;
		 aSdjjsdfWqeqw  id5 !DEBUG id4  scanf id5 "%d %d", &S, &E id4 ;
		else  PidsfASdujfsad 
			S = rand id5  id4  % 100000 + 1;
			E = rand id5  id4  % 100000 + 1;
			 aSdjjsdfWqeqw   id5 S > E id4  swap id5 S, E id4 ;
		 id3 

		 aSdjjsdfWqeqw   id5 !getgr id5 S, E id4  && !DEBUG id4  printf id5 "Bob\n" id4 ;
		else  aSdjjsdfWqeqw  id5 !DEBUG id4  printf id5 "Alice\n" id4 ;
	 id3 
	return 0;
 id3 
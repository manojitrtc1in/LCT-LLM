























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
















































int bit id4 26 id6  id4 100050 id6 ;
void update id1 int x, int p, int v id5   jWEH5wdkwIL2DbhCh9DRnXv 
	 id2   id1 ; p <= 100000; p += p &  id1 -p id5  id5  bit id4 x id6  id4 p id6  ^= v;
 id3 
int getsum id1 int x, int p id5   jWEH5wdkwIL2DbhCh9DRnXv 
	int rv = 0;
	 id2   id1 ; p; p -= p &  id1 -p id5  id5  rv ^= bit id4 x id6  id4 p id6 ;
	return rv;
 id3 

char in id4 100050 id6 ;
int nxt id4 100050 id6  id4 26 id6 ;
int prv id4 100050 id6  id4 26 id6 ;

int dpl id4 100050 id6  id4 26 id6 ;
int dpr id4 100050 id6  id4 26 id6 ;
vector <pii> Vl;
bool mycmp id1 pii a, pii b id5   jWEH5wdkwIL2DbhCh9DRnXv 
	 id0   id1 a.first != b.first id5  return a.first > b.first;
	return a.second < b.second;
 id3 
vector <int> Vp id4 26 id6 ;

bool grchk id4 30 id6 ;
int getgr id1 int S, int E id5   jWEH5wdkwIL2DbhCh9DRnXv 
	memset id1 grchk, 0, sizeof id1 grchk id5  id5 ;
	int i;
	 id2   id1 i = 0; i < 26; i++ id5   jWEH5wdkwIL2DbhCh9DRnXv 
		 id0   id1 nxt id4 S id6  id4 i id6  > E id5  continue;

		int p1 = nxt id4 S id6  id4 i id6 ;
		int p2 = prv id4 E id6  id4 i id6 ;

		int gr = dpr id4 S id6  id4 i id6  ^ dpl id4 E id6  id4 i id6 ;
		 id0   id1 p1 < p2 id5   jWEH5wdkwIL2DbhCh9DRnXv 
			gr ^= getsum id1 i, p2 - 1 id5 ;
			gr ^= getsum id1 i, p1 - 1 id5 ;
		 id3 
		grchk id4 gr id6  = true;
	 id3 

	 id2   id1 i = 0;; i++ id5   id0   id1 !grchk id4 i id6  id5  return i;
 id3 

int DEBUG = 0;
int main id1  id5   jWEH5wdkwIL2DbhCh9DRnXv 
	 id0  id1 !DEBUG id5  scanf id1 "%s", in + 1 id5 ;
	else  jWEH5wdkwIL2DbhCh9DRnXv 
		srand id1 132132 id5 ;
		 id2   id1 int i = 1; i <= 100000; i++ id5  in id4 i id6  = rand id1  id5  % 26 + 'a';
	 id3 
	int N = strlen id1 in + 1 id5 , i, j;

	 id2   id1 i = 1; i <= N; i++ id5   jWEH5wdkwIL2DbhCh9DRnXv 
		 id2   id1 j = 0; j < 26; j++ id5  prv id4 i id6  id4 j id6  = prv id4 i - 1 id6  id4 j id6 ;
		prv id4 i id6  id4 in id4 i id6  - 'a' id6  = i;

		 id2   id1 j = 0; j < 26; j++ id5   jWEH5wdkwIL2DbhCh9DRnXv 
			 id0   id1 in id4 i id6  - 'a'  KlopQXZvnuiuasdbbnbdsaioqw  j id5  continue;
			 id0   id1 prv id4 i id6  id4 j id6   KlopQXZvnuiuasdbbnbdsaioqw  0 id5  continue;
			Vl.emplace_back id1 prv id4 i id6  id4 j id6  + 1, i id5 ;
		 id3 
	 id3 
	 id2   id1 i = 0; i < 26; i++ id5  nxt id4 N + 1 id6  id4 i id6  = N + 1;
	 id2   id1 i = N; i >= 1; i-- id5   jWEH5wdkwIL2DbhCh9DRnXv 
		 id2   id1 j = 0; j < 26; j++ id5  nxt id4 i id6  id4 j id6  = nxt id4 i + 1 id6  id4 j id6 ;
		nxt id4 i id6  id4 in id4 i id6  - 'a' id6  = i;

		 id2   id1 j = 0; j < 26; j++ id5   jWEH5wdkwIL2DbhCh9DRnXv 
			 id0   id1 in id4 i id6  - 'a'  KlopQXZvnuiuasdbbnbdsaioqw  j id5  continue;
			 id0   id1 nxt id4 i id6  id4 j id6   KlopQXZvnuiuasdbbnbdsaioqw  N + 1 id5  continue;
			Vl.emplace_back id1 i, nxt id4 i id6  id4 j id6  - 1 id5 ;
		 id3 
	 id3 

	 id2   id1 i = 1; i <= N; i++ id5  Vp id4 in id4 i id6  - 'a' id6 .push_back id1 i id5 ;
	 id2   id1 i = 0; i < 26; i++ id5   jWEH5wdkwIL2DbhCh9DRnXv 
		 id2   id1 j = 0; j + 1 < Vp id4 i id6 .size id1  id5 ; j++ id5   jWEH5wdkwIL2DbhCh9DRnXv 
			int t1 = Vp id4 i id6  id4 j id6 , t2 = Vp id4 i id6  id4 j + 1 id6 ;
			 id0   id1 t1 + 1 != t2 id5  Vl.emplace_back id1 t1 + 1, t2 - 1 id5 ;
		 id3 
	 id3 

	sort(all(Vl), mycmp);
	Vl.erase(unique(all(Vl)), Vl.end());

	

	int cnt = 0;
	 id2   id1 auto it : Vl id5   jWEH5wdkwIL2DbhCh9DRnXv 
		cnt++;
		

		memset id1 grchk, 0, sizeof id1 grchk id5  id5 ;

		int S = it.first, E = it.second;
		i = getgr id1 S, E id5 ;
		
		 id0   id1 S != 1 && E != N && in id4 S - 1 id6   KlopQXZvnuiuasdbbnbdsaioqw  in id4 E + 1 id6  id5  update id1 in id4 S - 1 id6  - 'a', S - 1, i id5 ;
		
		 id0   id1 E != N && nxt id4 S id6  id4 in id4 E + 1 id6  - 'a' id6   KlopQXZvnuiuasdbbnbdsaioqw  E + 1 id5  dpr id4 S id6  id4 in id4 E + 1 id6  - 'a' id6  = i;
		 id0   id1 S != 1 && prv id4 E id6  id4 in id4 S - 1 id6  - 'a' id6   KlopQXZvnuiuasdbbnbdsaioqw  S - 1 id5  dpl id4 E id6  id4 in id4 S - 1 id6  - 'a' id6  = i;
	 id3 

	

	int Q;
	 id0  id1 !DEBUG id5  scanf id1 "%d", &Q id5 ;
	else Q = 100000;
	while  id1 Q-- id5   jWEH5wdkwIL2DbhCh9DRnXv 
		int S, E;
		 id0  id1 !DEBUG id5  scanf id1 "%d %d", &S, &E id5 ;
		else  jWEH5wdkwIL2DbhCh9DRnXv 
			S = rand id1  id5  % 100000 + 1;
			E = rand id1  id5  % 100000 + 1;
			 id0   id1 S > E id5  swap id1 S, E id5 ;
		 id3 

		 id0   id1 !getgr id1 S, E id5  && !DEBUG id5  printf id1 "Bob\n" id5 ;
		else  id0  id1 !DEBUG id5  printf id1 "Alice\n" id5 ;
	 id3 
	return 0;
 id3 
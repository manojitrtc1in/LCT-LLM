







#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;



typedef long long LL;
typedef pair < LL, LL > pll;
typedef pair < int, int > pii;
#define F first
#define S second
#define mp make_pair



#define pb push_back
#define ep emplace_back
#define endl '\n'
#define GL(n) getline ( cin, n )



template < class T > using MaxHeap = priority_queue < T, vector < T >, less < T > >;
template < class T > using MinHeap = priority_queue < T, vector < T >, greater < T > >;



#define sstr stringstream



#define INF 0x3f3f3f3f
#define maxN 4005

LL ans;
string str;
vector < int > edges[maxN];

int dfs ( int n ) {
	

	

	int stat = 0;
	for ( auto i: edges[n] )
		stat += dfs ( i );
	str[n] == 'W' ? stat++ : stat--;
	stat ? ans : ans++;

	return stat;
}

int main() {
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int t, n;
	cin >> t;
	while ( t-- ) {
		cin >> n;
		ans = 0;
		for ( int i = 1 ; i <= n ; i++ )
			edges[i].clear();
		for ( int i = 2, in ; i <= n ; i++ ) {
			cin >> in;
			edges[in].ep ( i );
		}
		cin >> str;
		str = ' ' + str;

		dfs ( 1 );

		cout << ans << endl;
	}
}

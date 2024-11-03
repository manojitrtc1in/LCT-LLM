




































































































































































































































































































































































































































































































































































using namespace std;
const int MAXN = 60  +  10 , MAXK = 1000  +  10 , MAXM = 60  +  10;
int const N = 60 + 5, K = 1000 + 10;
int n, m, r, mat[ N ][ N ][ N ], dist[ N ][ N ][ N ], dp[ K ][ N ][ N ];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> r;
	for (int k = 0; k < m; k ++)
		for (int i = 0; i < n; i ++)
		  	for (int j = 0; j < n; j ++)
			  	cin >> dist[ k ][ i ][ j ];

	for (int k = 0; k < m; k ++)
		for (int t = 0; t < n; t ++)
			for (int i = 0; i < n; i ++)
			  	for (int j = 0; j < n; j ++)
				  	dist[ k ][ i ][ j ] = min(dist[ k ][ i ][ j ], dist[ k ][ i ][ t ]  +  dist[ k ][ t ][ j ]);

	for (int i = 0; i < n; i ++)
	  	for (int j = 0; j < n; j ++){
		 	dp[ 1 ][ i ][ j ] = dist[ 0 ][ i ][ j ];
			for (int k = 1; k < m; k ++) dp[ 1 ][ i ][ j ] = min(dp[ 1 ][ i ][ j ], dist[ k ][ i ][ j ]);
		}

	for (int k = 2; k < K; k ++)
	  	for (int i = 0; i < n; i ++)
		  	for (int j = 0; j < n; j ++){
				dp[ k ][ i ][ j ] = dp[ k-1 ][ i ][ j ];
				for (int t = 0; t < n; t ++) dp[ k ][ i ][ j ] = min(dp[ k ][ i ][ j ], dp[ 1 ][ i ][ t ]  +  dp[ k-1 ][ t ][ j ]);
			}

	while (r --){
		int x, y, k;
		cin >> x >> y >> k; x --, y --;
		cout << dp[ k + 1 ][ x ][ y ] << '\n';
	}
}	
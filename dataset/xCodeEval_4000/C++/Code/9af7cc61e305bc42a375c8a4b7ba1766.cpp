
                                                                        
#include <bits/stdc++.h>
using namespace std;

#define FF(i, a, b) for(int i = a; i < b; i++)
#define RR(i, a, b) for(int i = a; i > b; i++)
#define ME(a, b) memset(a, b, sizeof(a))
#define SC(x) scanf("%d", &x)
#define PR(x) printf("%d\n", x)
#define INF 0x3f3f3f3f
#define MAX 200005
#define MOD 1000000007
#define E 2.71828182845
#define M 8
#define N 6
typedef long long LL;
const double PI = acos(-1.0);
typedef pair<int, int> Author;
vector<pair<string, int> > VP; 

int main(void){










	LL i, j, n, m, a, f[MAX], b, ans, index;
	
	cin>>n>>m;ME(f, 0);
	for(i = 1; i <= n; i++){cin>>a;f[i] = a + f[i - 1];}
	for(i = 1; i <= m; i++){
		cin>>b;
		index = lower_bound(f, f + n + 1, b) - f;
		cout<<index<<" "<<b - f[index - 1]<<endl;
	}
	return EXIT_SUCCESS;
}
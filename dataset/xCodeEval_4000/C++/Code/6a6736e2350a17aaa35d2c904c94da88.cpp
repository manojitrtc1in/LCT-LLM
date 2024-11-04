
                                                                        
#include <bits/stdc++.h>
using namespace std;

#define FFI(a, b) for(int i = a; i < b; i++)
#define RR(i, a, b) for(int i = a; i > b; i++)
#define ME(a, b) memset(a, b, sizeof(a))
#define SC(x) scanf("%d", &x)
#define PR(x) printf("%d\n", x)
#define INF 0x3f3f3f3f
#define MAX 1006
#define MOD 1000000007
#define E 2.71828182845
#define M 8
#define N 6
typedef long long LL;
const double PI = acos(-1.0);
typedef pair<int, int> Author;
vector<pair<string, int> > VP; 

int main(void){
	#ifdef LOCAL
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
	ios::sync_with_stdio(false); cin.tie(0);
	int n, num[MAX] = {0};
	cin>>n;
	FFI(1, n + 1) cin>>num[i];
	sort(num, num + n + 1);
	if(n & 1) cout<<num[n / 2 + 1]<<endl;
	else cout<<num[n / 2]<<endl;		
	return EXIT_SUCCESS;
}

                                                                        

using namespace std;












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
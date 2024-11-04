
                                                                        

using namespace std;












typedef long long LL;
const double PI = acos(-1.0);
typedef pair<int, int> Author;
vector<pair<string, int> > VP; 

int main(void){










	LL i, j, n, m, a, b, f[MAX], left, right, mid, ans;
	
	cin>>n>>m;ME(f, 0);
	for(i = 1; i <= n; i++) {cin>>a;f[i] = f[i - 1] + a;}
	for(i = 1; i <= m; i++){
		cin>>b;
		left = 1;right = n;
		while(left < right){
			mid = (left + right) >> 1;
			if(b > f[mid]) left = mid + 1;
			else right = mid; 
		}
		cout<<left<<" "<<b - f[left - 1]<<endl;
	}
	return EXIT_SUCCESS;
}
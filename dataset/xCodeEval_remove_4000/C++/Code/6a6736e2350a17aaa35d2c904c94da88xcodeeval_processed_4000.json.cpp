
                                                                        

using namespace std;












typedef long long LL;
const double PI = acos(-1.0);
typedef pair<int, int> Author;
vector<pair<string, int> > VP; 

int main(void){
	
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    
	ios::sync_with_stdio(false); cin.tie(0);
	int n, num[MAX] = {0};
	cin>>n;
	FFI(1, n + 1) cin>>num[i];
	sort(num, num + n + 1);
	if(n & 1) cout<<num[n / 2 + 1]<<endl;
	else cout<<num[n / 2]<<endl;		
	return EXIT_SUCCESS;
}
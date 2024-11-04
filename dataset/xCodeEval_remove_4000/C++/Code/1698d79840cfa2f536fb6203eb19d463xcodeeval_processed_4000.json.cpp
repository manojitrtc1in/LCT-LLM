

using namespace std;






typedef int def; 















typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int Rank[100001], Par[100001];

int parent(int x){
	if(x!=Par[x])return Par[x]=parent(Par[x]);
	return x;
}

int main(){
	

	fastInputOutput;
	int n;
	cin>>n;
	int ans = n;
	fori(100001)Par[i]=i;
	forii(1, n+1){
		int j=0;
		cin>>j;
		int x = parent(i), y = parent(j);
		if(y==x)continue;
		ans--;
		if(Rank[x]>Rank[y]){
			Par[y]=x;
		}
		else{
			if(Rank[x]==Rank[y]){
				Rank[y]++;
			}
			Par[x]=y;
		}
	}
	cout<<ans<<endl;
}












































typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = (int)5e5 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;
using namespace std;

int A,I,F;
int main(){
	int n;
	string s;
	cin>>n;
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]=='I')I++;
		if(s[i]=='A')A++;
	}
	if(I==0){
		return cout<<A,0;
	}
	if(I==1){
		return cout<<I,0;
	}
	return cout<<0,0;
	return 0;
}
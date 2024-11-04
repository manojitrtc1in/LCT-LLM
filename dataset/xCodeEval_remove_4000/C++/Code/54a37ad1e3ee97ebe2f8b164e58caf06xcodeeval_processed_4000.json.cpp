

using namespace std;
typedef long long ll;

typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef std::pair<ll,int> pli;








string s,s1[4];
int main(){
	int n,k,cnt=0,msk=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<4;j++){
			cin>>s;
			cnt=0;
			for(int p=s.size()-1;p>=0;p--){
				if(s[p]=='a'||s[p]=='e'||s[p]=='i'||s[p]=='o'||s[p]=='u') cnt++;
				if(cnt==k){s1[j]=s.substr(p,s.size()-p);break;}
			}
			if(cnt<k){
				puts("NO");
				return 0;
			}
		}
		if(s1[0]==s1[1]&&s1[1]==s1[2]&&s1[2]==s1[3]) continue;
		else if(s1[0]==s1[1]&&s1[2]==s1[3]){
			if(msk&&msk!=1){
				puts("NO");
				return 0;
			}
			msk=1;
		}
		else if(s1[0]==s1[1]&&s1[2]==s1[3]){
			if(msk&&msk!=1){
				puts("NO");
				return 0;
			}
			msk=1;
		}
		else if(s1[0]==s1[2]&&s1[1]==s1[3]){
			if(msk&&msk!=2){
				puts("NO");
				return 0;
			}
			msk=2;
		}
		else if(s1[0]==s1[3]&&s1[1]==s1[2]){
			if(msk&&msk!=3){
				puts("NO");
				return 0;
			}
			msk=3;
		}
		else{
			puts("NO");
			return 0;
		}
	}
	if(msk==0) puts("aaaa");
	if(msk==1) puts("aabb");
	if(msk==2) puts("abab");
	if(msk==3) puts("abba");
	return 0;
}
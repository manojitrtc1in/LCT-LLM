

using namespace std;
typedef int ALL_OF_YOU_ARE_HANZHONGBALLS;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;








using namespace std;
int zbox[maxn];
int z(const string &t,const string &p){
	string s=p+t;
	int l=0,r=0,j,k,ans=0;
	for(int i=1;i<s.size();i++){
		zbox[i]=0;
		if(i>r){
			for(j=0;j<p.size();j++){
				if(s[i+j]!=p[j]) break;
			}
			if(j){
				zbox[i]=j;
				l=i;r=i+j-1;
			}
		}else{
			k=i-l;
			if(k+zbox[k]<=r-l){
				zbox[i]=zbox[k];
			}else{
				for(j=r-i;j<p.size();j++){
					if(s[i+j]!=p[j]) break;
				}
				zbox[i]=j;
				l=i;r=i+j-1;
			}
		}
		

		if(i>=p.size()&&i+zbox[i]==s.size()) ans=max(ans,zbox[i]);
	}
	

	return ans;
}
string s,t,res;
int main(){
	int n,len;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(res.size()<s.size()){
			len=z(res,s);
		}else{
			len=z(res.substr(res.size()-s.size(),s.size()),s);
		}
		res+=s.substr(len,s.size()-len);
		
	}
	cout<<res<<endl;
	return 0;
}
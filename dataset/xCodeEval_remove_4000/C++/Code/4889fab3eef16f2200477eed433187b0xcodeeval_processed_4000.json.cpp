
















































































using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=2005;
string s,t;
int n;
int v[27];
vector<int> ans;
void shift(int vv){
	ans.pb(n-vv);
	string ss=s.substr(0,vv),s2=s.substr(vv);
	reverse(s2.begin(),s2.end());
	s=s2+ss;
}
int main(){
	cin>>n;
	cin>>s>>t;
	for (int i=0;i<n;i++){
		v[s[i]-'a']++;
		v[t[i]-'a']--;
	}
	for (int i=0;i<26;i++){
		if (v[i]!=0){
			printf("-1\n");
			return 0;
		}
	}

	for (int pos=0;pos<n;pos++){
		char c=t[pos];
		int gg;
		for (int i=0;i<n-pos;i++){
			if (s[i]==c){
				gg=i;
				break;
			}
		}
		shift(gg+1);
	

		shift(n-1);
	

		shift(0);
		

	}
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	return 0;
}


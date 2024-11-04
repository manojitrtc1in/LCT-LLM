
using namespace std;



vector<string> a[1010];
char s[110];
int n,m,k;
map <string, string> ma;
string tok;

vector<string> parse(){
	gets(s);
	string cur=s;
	for (int i=0;i<cur.size();i++) {
		if (cur[i]=='('||cur[i]==')'||cur[i]==',') cur[i]=' ';
	}
	
	stringstream ss;
	ss<<cur;
	vector<string> ans;
	while (ss>>tok) ans.push_back(tok);
	return ans;
}

int main(){
	memset(a,false,sizeof(a));
	scanf("%d\n", &n);
	for (int i=0;i<n;i++) {
		vector <string> s=parse();
		s.erase(s.begin());
		a[i]=s;
	

	

	

	

	}
	scanf("%d\n", &m);
	for (int i=0;i<m;i++) {
		vector<string> s=parse();
		ma[s[1]]=s[0];
	}
	scanf("%d\n", &k);
	for (int t=0;t<k;t++){
		int ans=0;
		vector<string> s=parse();
		for (int i=1;i<s.size();i++) s[i]=ma[s[i]];
		for (int i=0;i<n;i++) {
			if (a[i][0]==s[0]&&a[i].size()==s.size()) {
				bool bad=false;
				for (int j=1;j<s.size();j++) {
					if (s[j]!=a[i][j]&&a[i][j]!="T") {
						bad=true;
						break;
					}
				}
				if (!bad) ans++;
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
} 

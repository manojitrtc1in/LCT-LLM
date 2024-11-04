






























































































































































































using namespace std;
int x=0;
int a[maxn],b[maxn];
char s[maxn];
void solve(){
	scanf("%s",s);
	int len=strlen(s);
	int cnt=0,q=0;
	for(int i=0;i<len;i++){
		if(s[i]=='?')q++;
		if(s[i]=='(')cnt++;
		if(s[i]==')')cnt--;
		if(q+cnt==1){
			q=0;
			cnt=1;
		}
	}
	if(cnt==q)puts("YES");
	else puts("NO");
}
int main(){
	
		freopen("1.in","r",stdin);
	
	int t=1;
	cin>>t;
	while(t--)solve();
	
	
	
	return 0;
}
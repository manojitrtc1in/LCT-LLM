





















using namespace std;
char s[1005][1005];
int a[1005];
int main(){
	std::ios::sync_with_stdio(false);
	int mx=0;
	int cnt=0,len;
	while(gets(s[cnt])){
	

	

		

		len=strlen(s[cnt]);
		mx=max(mx,len);
		a[cnt]=len;
		cnt++;
	}
	for(int i=1;i<=mx+2;i++)
		printf("*");
	printf("\n");
	int l,r,f=0;
	for(int i=0;i<cnt;i++){
		l=(mx-a[i]);
		if(l%2==0)
			l=l/2,r=l;
		else if(l%2==1&&f==1){
			f=0;
			int t=l;
			l=l/2+1,r=t-l;
		}
		else if(l%2==1&&f==0){
			f=1;
			int t=l;
			l=l/2,r=t-l;
		}
		printf("*");
		

		for(int j=0;j<l;j++)
			printf(" ");
		for(int j=0;j<a[i];j++)
			printf("%c",s[i][j]);
		for(int j=0;j<r;j++)
			printf(" ");
		printf("*");
		printf("\n");
	}
	for(int i=1;i<=mx+2;i++)
		printf("*");
	printf("\n");
}



















using namespace std;







int T,n,m;










int main(){








	scanf("%d",&T);








	while(T--){











		scanf("%d%d",&n,&m);











		if(m>((n+1)>>1)){puts("-1");continue;}








		for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=n;j++)if(i==j&&(i&1)&&m)m--,putchar('R');







		else putchar('.');






	}







	return 0;









}




































































































using namespace std;

typedef long long lo;
typedef pair< lo,lo > PII;











const lo inf = 1000000000000000000;
const lo KOK = 100000;
const lo LOG = 30;
const lo li = 10;
const lo mod = 1000000007;

int n,m,b[li],a[li],k,flag,t,c[li];
int cev;
string s;
vector<int> v;

int main(void){
	scanf("%d %d",&a[1],&a[2]);
	scanf("%d %d",&b[1],&b[2]);
	scanf("%d %d",&c[1],&c[2]);


	if(b[1]!=a[1])swap(b[2],b[1]);
	if(c[1]!=a[1])swap(c[2],c[1]);
	if(a[1]==b[1] && a[1]==c[1] && a[2]+b[2]+c[2]==a[1]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("A");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=a[1];j++)printf("B");
			printf("\n");
		}
		for(int i=1;i<=c[2];i++){
			for(int j=1;j<=a[1];j++)printf("C");
			printf("\n");
		}
		return 0;
	}
	swap(a[1],a[2]);
	swap(b[1],b[2]);
	swap(c[1],c[2]);
	if(a[1]==b[1] && a[1]==c[1] && a[2]+b[2]+c[2]==a[1]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("A");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=a[1];j++)printf("B");
			printf("\n");
		}
		for(int i=1;i<=c[2];i++){
			for(int j=1;j<=a[1];j++)printf("C");
			printf("\n");
		}
		return 0;
	}




	if(a[1]!=b[1])swap(a[2],a[1]);
	if(c[1]!=b[1])swap(c[2],c[1]);
	if(a[1]==b[1] && b[1]==c[1] && a[2]+b[2]+c[2]==b[1]){
		printf("%d\n",b[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=b[1];j++)printf("A");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("B");
			printf("\n");
		}
		for(int i=1;i<=c[2];i++){
			for(int j=1;j<=b[1];j++)printf("C");
			printf("\n");
		}
		return 0;
	}
	swap(a[1],a[2]);
	swap(b[1],b[2]);
	swap(c[1],c[2]);
	if(a[1]==b[1] && b[1]==c[1] && a[2]+b[2]+c[2]==b[1]){
		printf("%d\n",b[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=b[1];j++)printf("A");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("B");
			printf("\n");
		}
		for(int i=1;i<=c[2];i++){
			for(int j=1;j<=b[1];j++)printf("C");
			printf("\n");
		}
		return 0;
	}




	if(a[1]!=c[1])swap(a[2],a[1]);
	if(b[1]!=c[1])swap(b[2],b[1]);
	if(a[1]==c[1] && b[1]==c[1] && a[2]+b[2]+c[2]==c[1]){
		printf("%d\n",c[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=c[1];j++)printf("A");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=c[1];j++)printf("B");
			printf("\n");
		}
		for(int i=1;i<=c[2];i++){
			for(int j=1;j<=c[1];j++)printf("C");
			printf("\n");
		}
		return 0;
	}
	swap(a[1],a[2]);
	swap(b[1],b[2]);
	swap(c[1],c[2]);
	if(a[1]==c[1] && b[1]==c[1] && a[2]+b[2]+c[2]==c[1]){
		printf("%d\n",c[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=c[1];j++)printf("A");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=c[1];j++)printf("B");
			printf("\n");
		}
		for(int i=1;i<=c[2];i++){
			for(int j=1;j<=c[1];j++)printf("C");
			printf("\n");
		}
		return 0;
	}


	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("A");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("B");
			for(int j=1;j<=c[1];j++)printf("C");
			printf("\n");
		}
		return 0;
	}
	swap(a[1],a[2]);
	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("A");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("B");
			for(int j=1;j<=c[1];j++)printf("C");
			printf("\n");
		}
		return 0;
	}
	swap(b[1],b[2]);
	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("A");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("B");
			for(int j=1;j<=c[1];j++)printf("C");
			printf("\n");
		}
		return 0;
	}
	swap(a[1],a[2]);
	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("A");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("B");
			for(int j=1;j<=c[1];j++)printf("C");
			printf("\n");
		}
		return 0;
	}
	swap(c[1],c[2]);
	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("A");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("B");
			for(int j=1;j<=c[1];j++)printf("C");
			printf("\n");
		}
		return 0;
	}
	swap(a[1],a[2]);
	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("A");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("B");
			for(int j=1;j<=c[1];j++)printf("C");
			printf("\n");
		}
		return 0;
	}
	swap(b[1],b[2]);
	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("A");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("B");
			for(int j=1;j<=c[1];j++)printf("C");
			printf("\n");
		}
		return 0;
	}
	swap(a[1],a[2]);
	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("A");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("B");
			for(int j=1;j<=c[1];j++)printf("C");
			printf("\n");
		}
		return 0;
	}


	swap(a,b);
	

	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("B");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("A");
			for(int j=1;j<=c[1];j++)printf("C");
			printf("\n");
		}
		return 0;
	}
	swap(a[1],a[2]);
	

	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("B");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("A");
			for(int j=1;j<=c[1];j++)printf("C");
			printf("\n");
		}
		return 0;
	}
	swap(b[1],b[2]);
	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("B");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("A");
			for(int j=1;j<=c[1];j++)printf("C");
			printf("\n");
		}
		return 0;
	}
	swap(a[1],a[2]);
	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("B");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("A");
			for(int j=1;j<=c[1];j++)printf("C");
			printf("\n");
		}
		return 0;
	}
	swap(c[1],c[2]);
	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("B");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("A");
			for(int j=1;j<=c[1];j++)printf("C");
			printf("\n");
		}
		return 0;
	}
	swap(a[1],a[2]);
	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("B");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("A");
			for(int j=1;j<=c[1];j++)printf("C");
			printf("\n");
		}
		return 0;
	}
	swap(b[1],b[2]);
	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("B");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("A");
			for(int j=1;j<=c[1];j++)printf("C");
			printf("\n");
		}
		return 0;
	}
	swap(a[1],a[2]);
	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("B");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("A");
			for(int j=1;j<=c[1];j++)printf("C");
			printf("\n");
		}
		return 0;
	}




	swap(a,c);
	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("C");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("A");
			for(int j=1;j<=c[1];j++)printf("B");
			printf("\n");
		}
		return 0;
	}
	swap(a[1],a[2]);
	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("C");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("A");
			for(int j=1;j<=c[1];j++)printf("B");
			printf("\n");
		}
		return 0;
	}
	swap(b[1],b[2]);
	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("C");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("A");
			for(int j=1;j<=c[1];j++)printf("B");
			printf("\n");
		}
		return 0;
	}
	swap(a[1],a[2]);
	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("C");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("A");
			for(int j=1;j<=c[1];j++)printf("B");
			printf("\n");
		}
		return 0;
	}
	swap(c[1],c[2]);
	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("C");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("A");
			for(int j=1;j<=c[1];j++)printf("B");
			printf("\n");
		}
		return 0;
	}
	swap(a[1],a[2]);
	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("C");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("A");
			for(int j=1;j<=c[1];j++)printf("B");
			printf("\n");
		}
		return 0;
	}
	swap(b[1],b[2]);
	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("C");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("A");
			for(int j=1;j<=c[1];j++)printf("B");
			printf("\n");
		}
		return 0;
	}
	swap(a[1],a[2]);
	if(a[1]==b[1]+c[1] && a[2]+b[2]==a[1] && b[2]==c[2]){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[2];i++){
			for(int j=1;j<=a[1];j++)printf("C");
			printf("\n");
		}
		for(int i=1;i<=b[2];i++){
			for(int j=1;j<=b[1];j++)printf("A");
			for(int j=1;j<=c[1];j++)printf("B");
			printf("\n");
		}
		return 0;
	}


	printf("-1\n");
	return 0;
}


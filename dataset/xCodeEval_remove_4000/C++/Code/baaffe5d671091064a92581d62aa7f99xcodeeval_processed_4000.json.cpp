
int n,m;
int arr[100004];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	scanf("%d",&m);
	int type,l,r,xor,tmp=0, count=0;
	long long int sum=0;
	for(int t=0;t<m;t++){
		scanf("%d",&type);
		if(type==1){
			sum=0;
			scanf("%d %d",&l,&r);
			count = (r-l+1)/2000;
			for(; count>0; count--){
				tmp=0;
				O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;O;
				sum+=tmp;
			}
			tmp=0;
			for(; l<=r; l++){
				tmp+=arr[l];
			}
			sum+=tmp;
			printf("%I64d\n",sum);
		} else {
			scanf("%d %d %d",&l,&r,&xor);
			for(int i=l;i<=r;i++){
				arr[i]^=xor;
			}
		}
	}
}




using namespace std;
int main() {
	int a=0,b=0,n;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
	{
		char x;
		scanf("%c", &x);
		if (x == 'n')
			a++;
		if (x == 'r')
			b++;
	}
	while (a--) {
		printf("1 ");
	}
	while (b--) {
		printf("0 ");
	}
	return 0;
}





	

	
	

	
	

	
	

	
	
	
	
	
	
	
	

	



































using namespace std;

int w[1100];
int n;

int main(){
	int i, j, k;
	scanf("%d", &n);
	j = 0;
	for (i = 1; i < n; i += 2){
		w[j++] = i;
	}
	for (i = 2; i < n; i += 2){
		w[j++] = i;
	}
	w[j++] = 0;
	for (i = 0; i < n - 1; i++){
		for (j = 0; j < n - 1; j++){
			if (j)putchar(' ');
			if (i == j)putchar('0');
			else printf("%d", (i + j) % (n - 1) + 1);
		}
		printf(" %d\n", w[i]);
	}
	for (i = 0; i < n; i++){
		if (i)putchar(' ');
		printf("%d", w[i]);
	}
	putchar('\n');
	return 0;
}

#include <cstdio>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#define MAXN 300001
#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
int a[MAXN], p[MAXN];
int w = 5,n,l,r;
void win(){
	printf("YES\n");
	exit(0);
}

int main() {
	scanf("%d", &n);
	FOR(i, 0, n){
		scanf("%d",&a[i]);
		p[a[i]] = i;
	}
	FOR(i,0,n)
    FOR(j,i,std::min(n,i+w)){
        r = 2 * a[j] - a[i], l = 2 * a[i] - a[j];
        if (l > 0 && l < n && p[l] < i || r > 0 && r < n && p[r] > j)
            win();
	}
	printf("NO\n");
	return 0;
}
















































































































































































































































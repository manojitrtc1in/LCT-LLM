#include <stdio.h>
#include <math.h>

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define Rint register int

const int block = 100000;
int l,r,lb,rb,ans;

inline int gooood(int x){
	if(x < 3) return x == 2;
	if((x & 3) != 1) return 0;
	Rint top = sqrt(x);
	FOR(i,2,top) if(!(x % i)) return 0;
	return 1;
}

int main(){
	l = read() , r = read();
	lb = ceil(l / (double)block) , rb = ceil(r / (double)block);
	if(lb == rb){
		FOR(i,l,r) if(gooood(i)) ans++;
		printf("%d\n",ans);
		return 0;
	}
	FOR(i,lb + 1,rb - 1) ans += a[i];
	FOR(i,l,lb * block) if(gooood(i)) ans++;
	FOR(i,(rb - 1) * block + 1,r) if(gooood(i)) ans++;
	printf("%d\n",ans);
	return 0;
}

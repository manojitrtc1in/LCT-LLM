
#include <iostream>
#include <cstdio>
#define inf 1e9
#define db double
using namespace std;

int t;
double a[4] , v , ans;
double b[4];

void dfs(int x , double gs , double qz , int hs){
	if(x == 3){
		ans += gs * qz;
		return ;
	}
	if(a[x] - v <= 1e-9){hs--;if(hs == 0)return ;a[((x+1) % 3 == 0)?3:((x+1) % 3)] += a[x] / hs;a[((x+2) % 3 == 0)?3:((x+2) % 3)] += a[x] /hs;a[x] = -inf;}
		else {if(hs == 1)return ;else {a[x] -= v;a[((x+1) % 3 == 0)?3:((x+1) % 3)] += v / (db)(hs-(db)1);a[((x+2) % 3 == 0)?3:((x+2) % 3)] += v/(db)(hs-double(1));}}
	for(int i=1;i<=3;i++){
		double c[5];
		c[1] = a[1];c[2] = a[2];c[3] = a[3];
		if(a[i] >= 1e-9)dfs(i , gs + 1 , qz * a[i] , hs);
		a[1] = c[1];a[2] = c[2];a[3] = c[3];
	}
}

int main(){
	cin>>t;
	while(t--){
		cin>>a[1]>>a[2]>>a[3]>>v;
		ans = 0;
		b[1] = a[1]; b[2] = a[2] ; b[3] = a[3];
		for(int i=1;i<=3;i++){
			a[1] = b[1];
			a[2] = b[2];
			a[3] = b[3];
			dfs(i , 1 , a[i] , 3);
		}
		printf("%.12f\n" , ans);
	}
	return 0;
}
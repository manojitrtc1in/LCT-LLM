

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;



const long long DIVISORS[][100]={
{},
{},
{},
{},
{3,5,},
{},
{3,7,},
{},
{3,5,17,},
{7,73,},
{3,11,31,},
{23,89,},
{3,5,7,13,},
{},
{3,43,127,},
{7,31,151,},
{3,5,17,257,},
{},
{3,7,19,73,},
{},
{3,5,11,31,41,},
{7,127,337,},
{3,23,89,683,},
{47,178481,},
{3,5,7,13,17,241,},
{31,601,1801,},
{3,2731,8191,},
{7,73,262657,},
{3,5,29,43,113,127,},
{233,1103,2089,},
{3,7,11,31,151,331,},
{},
{3,5,17,257,65537,},
{7,23,89,599479,},
{3,43691,131071,},
{31,71,127,122921,},
{3,5,7,13,19,37,73,109,},
{223,616318177LL,},
{3,174763,524287,},
{7,79,8191,121369,},
{3,5,11,17,31,41,61681,},
{13367,164511353LL,},
{3,7,43,127,337,5419,},
{431,9719,2099863,},
{3,5,23,89,397,683,2113,},
{7,31,73,151,631,23311,},
{3,47,178481,2796203,},
{2351,4513,13264529LL,},
{3,5,7,13,17,97,241,257,673,},
{127,4432676798593LL,},
{3,11,31,251,601,1801,4051,},
};

int c[100];
int k;

struct Matrix{
	int v[100][100];
	friend Matrix operator *(Matrix a,Matrix b){
		Matrix c;
		memset(&c,0,sizeof(c));
		for(int i=0;i<k;i++)
			for(int j=0;j<k;j++)
				for(int K=0;K<k;K++)
					c.v[i][j]=(c.v[i][j]+a.v[i][K]*b.v[K][j])&1;
		return c;
	}
	bool isBase(){
		for(int i=0;i<k;i++)
			for(int j=0;j<k;j++)
				if(i==j && !v[i][j] || i!=j && v[i][j])
					return false;
		return true;
	}
	void print(){
		for(int i=0;i<k;i++){
			for(int j=0;j<k;j++)
				printf("%d ",v[i][j]);
			puts("");
		}
		puts("");
	}
};

Matrix baseMat;

Matrix expMod(Matrix a,long long b){
	Matrix res=baseMat;
	for(int i=63;i>=0;i--){
		if(b&(1LL<<i))
			res=res*a;
		res=res*res;
	}
	return res;
}

void genMat(Matrix& mat){
	memset(&mat,0,sizeof(mat));
	for(int i=0;i<k-1;i++)
		mat.v[i+1][i]=1;
	for(int i=0;i<k;i++)
		mat.v[i][k-1]=c[k-i-1];
}

void generate(){
	for(int i=0;i<k;i++)
		c[i]=rand()&1;
}
int main(){
	for(int i=0;i<50;i++)
		baseMat.v[i][i]=1;
	scanf("%d",&k);
	while(true){
		generate();
		for(int i=0;i<k;i++)
			if(c[i]==1)
				goto OK;
		continue;
		OK:;
		Matrix init;
		genMat(init);
		

		
		if(expMod(init,(1LL<<k)-1).isBase()){
			

			for(const long long *i=DIVISORS[k];*i;i++){
				if(expMod(init,((1LL<<k)-1)/(*i)).isBase())
					goto Failure;
			}
			
			for(int i=0;i<k;i++)
				printf("%d ",c[i]);
			puts("");
			for(int i=0;i<k;i++)
				printf("1 ");
			
			return 0;
		}
		
		

		
		Failure:;
		

	}
	return 0;
}
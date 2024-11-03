





























































































































































using namespace std;



inline void read(int &x)




{




	char c;int f=1;



	while(!isdigit(c=getchar()))if(c=='-')f=-1;



	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);



	x*=f;




}



int t,n,m,i,j;



void solve()



{



	read(n);read(m);



	if(m>(n+1)/2){



		puts("-1");



		return;



	}



	fz1(i,n){




		fz1(j,n){




			if(i==j&&(i&1)&&(i+1)/2<=m){



				putchar('R');



			}




			else{




				putchar('.');



			}



		}




		puts("");




	}




}



int main()



{



	read(t);




	while(t--) solve();




	return 0;




}

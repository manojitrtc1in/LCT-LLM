


























using namespace std;

typedef vector<int> VI;
typedef vector<int>::iterator VII;
typedef vector<vector <int> > VVI;
typedef vector<vector <int> >::iterator VVII;
typedef vector<string> VSTR;
typedef vector<string>::iterator VSTRI;
typedef string STR;
typedef string::iterator STRI;
typedef pair<int,int> PII;
typedef list<int> LI;
typedef list<int>::iterator LII;


typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;






































template<class T> inline string DISPLAYBIT(T n,int s,int e) {string a;while(s>=e){if(s<sizeof(n)*CHAR_BIT) IFSET(n,s)?a+='1':a+='0';s--;}return a;}




template<class T> inline int COUNTBIT(T n){return (sizeof(n)==4)?__builtin_popcount(n):__builin_popcountl(n);}
template<class T> inline int LSB(T n){return (sizeof(n)==4)?__builtin_ffs(n)-1:__builtin_ffsl(n)-1;}
template<class T> inline int MSB(T n){return (sizeof(n)==4)?31-__builtin_clz(n):63-__builtin_clzl(n);}











template<class T> inline T GCD(T a,T b){if(a<0)return GCD(-a,b);if(b<0)return GCD(a,-b);return (b==0)?a:GCD(b,a%b);}
template<class T> inline T LCM(T a,T b){if(a<0)return LCM(-a,b);if(b<0)return LCM(a,-b);return a*(b/GCD(a,b));}
template<class T> inline T id12(T a,T b,T &x,T &y){if(a<0){T d=id12(-a,b,x,y);x=-x;return d;}if(b<0){T d=id12(a,-b,x,y);y=-y;return d;}if(b==0){x=1;y=0;return a;}else{T d=id12(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<class T> inline vector<pair<T,int> > id3(T n){vector<pair<T,int> >R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
template<class T> inline vector<pair<int,int> > id0(int n){if(n>1e7)return id3(n);vector<pair<int,int> >R;VI a(SIEVE(n));int i;if(a[LS(a,n)]==n){R.push_back(make_pair(n,1));return R;}int b=(int)sqrt(n);for(i=0;a[i]<=b;i++){if(n%a[i]==0){int d=0;for(;n%a[i]==0;d++,n/=a[i]);R.push_back(make_pair(a[i],d));}}for(;a[i]<n;i++){if(n%a[i]==0){R.push_back(make_pair(a[i],1));break;}}return R;}
template<class T> inline bool id9(T n){if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
template<class T> inline bool id13(T n){if(n>1e7)return id9(n);VI a(SIEVE(n));int b=LS(a,n);return (b!=-1&&a[b]==n);}
template<class T> inline T TOTIENT(T n) {vector<pair<T,int> > R=id0(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}




template<class T> inline T CHECKMOD(T n,T m) {return (n%m+m)%m;}
template<class T> inline T id7(T a,T b,T m) {return (T)((((int64)(a)*(int64)(b)%(int64)(m))+(int64)(m))%(int64)(m));}
template<class T> inline T id8(T a,T b,T m) {T x,y;id12(b,m,x,y);return id7(a,x,m);}
template<class T> inline T id6(T p,int e,T m) {if(e==0)return 1%m;else if(e%2==0){T t=id6(p,e/2,m);return id7(t,t,m);}else return id7(id6(p,e-1,m),p,m);}




template<class T> inline void id11(vector<vector<T> >& A) {for (int i=0;i<SZ(A);i++){for (int j=0;j<SZ(A[0]);j++)cout<<A[i][j]<<" ";cout<<endl;}}
template<class T> inline void id10(int m,int n,vector<vector<T> >& A,vector<vector<T> >& B) {B.clear();B.resize(n-m+1,vector<T>(n-m+1));for (int i=m,k=0;i<=n;i++,k++){for(int j=m,l=0;j<=n;j++,l++)B[k][l]=A[i][j];}}
template<class T> inline void id1(int n,vector<vector<T> >& A) { A.clear();A.resize(n,vector<T>(n));for (int i=0;i<n;i++) for (int j=0;j<n;j++) A[i][j]=(i==j)?1:0;}
template<class T,class BinaryOperation> inline void id5(vector<vector<T> > A,vector<vector<T> > B,vector<vector<T> >& C,BinaryOperation b) {int n=SZ(A);C.clear();C.resize(SZ(A),vector<T>(SZ(A)));for (int i=0;i<SZ(A);i++) for (int j=0;j<SZ(A[0]);j++) C[i][j]=b(A[i][j],B[i][j]);}
template<class T> inline void mulMatrix(vector<vector<T> > A,vector<vector<T> > B,vector<vector<T> >& C) { C.clear();C.resize(SZ(A),vector<T>(SZ(B[0])));for (int i=0;i<SZ(A);i++) for (int j=0;j<SZ(B[0]);j++) for (int k=0;k<SZ(B);k++) C[i][j]+=A[i][k]*B[k][j];}
template<class T> inline void id2(vector<vector<T> >& B,vector<vector<T> >& A) {B.clear();B.resize(SZ(A[0]),vector<T>(SZ(A)));for(int i=0;i<SZ(B);i++){for(int j=0;j<SZ(B[0]);j++) B[i][j]=A[j][i];}}
template<class T,class BinaryOperation> inline void id4(vector<vector<T> >& B,vector<vector<T> >& A,T c,BinaryOperation d) {B.clear();B.resize(SZ(A[0]),vector<T>(SZ(A)));for(int i=0;i<SZ(B);i++){for(int j=0;j<SZ(B[0]);j++) B[i][j]=d(A[j][i],c);}}




template<class T> inline string TOSTRING(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}
template<class T> inline void id14(string s,T &r){istringstream sin(s);sin>>r;}
template<class T> inline void STOV(string s,vector<T> &vi){vi.clear();istringstream sin(s);for(T v;sin>>v;vi.push_bakc(v));}
template<class T> inline void VTOS(vector<T> vi,string &s){ostringstream sout;for (int i=0;i<vi.size();i++){if(i>0)sout<<' ';sout<<vi[i];}s=sout.str();}
template<class T> inline vector<T> ATOV(T a[]) {vector<T> v(a,a+sizeof(a)/sizeof(T));return v;}






template<class T> struct Fraction{T a,b;Fraction(T a=0,T b=1);string toString();};

template<class T> Fraction<T>::Fraction(T a,T b){T d=GCD(a,b);a/=d;b/=d;if (b<0) a=-a,b=-b;this->a=a;this->b=b;}
template<class T> string Fraction<T>::toString(){ostringstream sout;sout<<a<<"/"<<b;return sout.str();}
template<class T> Fraction<T> operator+(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b+q.a*p.b,p.b*q.b);}
template<class T> Fraction<T> operator-(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b-q.a*p.b,p.b*q.b);}
template<class T> Fraction<T> operator*(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.a,p.b*q.b);}
template<class T> Fraction<T> operator/(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b,p.b*q.a);}








int n,m,start_x,start_y;
VSTR G;
vector<vector<PII> > chk;
vector<vector<bool> > vis;

struct elem{
	int x,y,maze_x,maze_y;
};


int main(){


	double tmp_start = clock();
	fprintf(stderr, "Start\n");

	
	n=SI,m=SI;
	G.clear();
	vis.resize(n,vector<bool>(m,0));
	chk.resize(n,vector<PII>(m,MP(INF,INF)));

	FOR(i,0,n){
		STR temp;
		cin>>temp;
		FOR(j,0,SZ(temp))
			if(temp[j]=='S'){
				start_x=i;
				start_y=j;
			}
		G.PB(temp);
	}
	
	PII dir[4]={MP(-1,0),MP(1,0),MP(0,1),MP(0,-1)};
	bool ans=0;

	stack<elem> Q;
	elem start;
	start.x=start_x, start.y=start_y, start.maze_x=0, start.maze_y=0;
	Q.push(start);
	vis[start_x][start_y]=1;
	chk[start_x][start_y]=MP(start.maze_x,start.maze_y);

	while(!Q.empty()){

		elem S=Q.top();
		Q.pop();

		FOR(i,0,4){

			int x=S.x+dir[i].first;
			int y=S.y+dir[i].second;
			int maze_x=S.maze_x, maze_y=S.maze_y;

			if(x<0) { x=n-1;maze_x--;}
			if(y<0) { y=m-1;maze_y--;}
			if(x>=n) { x=0;maze_x++;}
			if(y>=m) { y=0;maze_y++;}

			if(G[x][y]=='
				continue;

			if(vis[x][y]){
				if(chk[x][y] != MP(maze_x,maze_y)){
					ans=true;
					break;
				}
			}
			else{
				elem t={x,y,maze_x,maze_y};
				vis[x][y]=1;
				chk[x][y]=MP(maze_x,maze_y);
				Q.push(t);
			}

		}
		if(ans)
			break;
	}
	if(ans)
		cout<<"Yes\n";
	else
		cout<<"No\n";


		




	fprintf(stderr, "Total time = %.2lf sec\n", (double)(clock() - tmp_start) / CLOCKS_PER_SEC);


	return 0;
}

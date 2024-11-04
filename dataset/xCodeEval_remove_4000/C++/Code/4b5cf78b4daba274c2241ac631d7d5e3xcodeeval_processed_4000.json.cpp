




























using namespace std;




















































































































template< class T, class X > inline bool checkbit(T a, X pos) { T t=1;return ((a&(t<<pos))>0);  }
template< class T, class X > inline T      setbit(T a, X pos) { T t=1;return (a|(t<<pos));      }
template< class T, class X > inline T    resetbit(T a, X pos) { T t=1;return (a&(~(t<<pos)));   }
template< class T, class X > inline T   togglebit(T a, X pos) { T t=1;return (a^(t<<pos));      }




















template<typename T> T POW(T base,T power)              { T ret=1; while(power)  { if(power & 1) ret=(ret*base); base=(base*base);  power>>=1; }return ret; }
template<typename T> inline T GCD(T a,T b)              { if(a<0)return GCD(-a,b);  if(b<0)return GCD(a,-b);    return (b==0)?a:GCD(b,a%b);}
template<typename T> T LCM(T a,T b)                     { if(a<0)return LCM(-a,b);if(b<0)return LCM(a,-b);return a*(b/GCD(a,b));}
template<typename T> T id3(T a,T b,T &x,T &y)       { if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<typename T> T ABS(T a)                         { if(a<0)return -a;else return a;}
LL Bigmod(LL base,LL power,LL _MOD)                      { LL ret=1;while(power){if(power & 1)ret=(ret*base)%_MOD;base=(base*base)%_MOD;power>>=1;}return ret;}
LL ModInverse(LL number,LL _MOD)                         { return Bigmod(number,_MOD-2LL,_MOD); }


template<typename T> double DIS(T x1,T y1,T x2, T y2)   { return sqrt( (double)( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ) );}
template<typename T> T ANGLE(T x1,T y1,T x2, T y2)      { return atan( double(y1-y2) / double(x1-x2));}
template<typename T> LL isLeft(T a,T b,T c)             { return (c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y); }










void BINARY(int n){  bitset<31>a=n;  cout << a << endl;}
void id2(int *ar,int a,int b) {  if(a>b) swap(a,b); if(a<=b) cout << ar[a]; for(int i=a+1;i<=b;i++) cout << " "<<ar[i];  cout << endl; }
template<class T> inline void id0( vector<T> &vec ){ sort( vec.begin(), vec.end() ); vec.erase( unique( vec.begin(), vec.end() ), vec.end() ); }
template<class T> inline void id1( T *ar,int &n)   { sort(ar + 1, ar + n + 1); n = unique(ar + 1, ar + n + 1) - ar - 1; }






































struct line{
	long long a , b;
	double xleft;
	bool type;
	line(long long _a , long long _b){
		a = _a;
		b = _b;
		type = 0;
	}
	bool operator < (const line &other) const{
		if(other.type){
			return xleft < other.xleft;
		}
		return a > other.a;
	}
};
double meet(line x , line y){
	return 1.0 * (y.b - x.b) / (x.a - y.a);
}
struct cht{
	set < line > hull;
	int flag;


	cht(){
		hull.clear();
		flag=1;
	}
	typedef set < line > :: iterator ite;
	bool hasleft(ite node){
		return node != hull.begin();
	}
	bool hasright(ite node){
		return node != prev(hull.end());
	}
	void updateborder(ite node){
		if(hasright(node)){
			line temp = *next(node);
			hull.erase(temp);
			temp.xleft = meet(*node , temp);
			hull.insert(temp);
		}
		if(hasleft(node)){
			line temp = *node;
			temp.xleft = meet(*prev(node) , temp);
			hull.erase(node);
			hull.insert(temp);
		}
		else{
			line temp = *node;
			hull.erase(node);
			temp.xleft = -1e18;
			hull.insert(temp);
		}
	}
	bool useless(line left , line middle , line right){
		double x = meet(left , right);
		double y = x * middle.a + middle.b;
		double ly = left.a * x + left.b;
		return y > ly;
	}
	bool useless(ite node){
		if(hasleft(node) && hasright(node)){
			return useless(*prev(node) , *node , *next(node));
		}
		return 0;
	}

    void addline(long long m , long long c) {
        line temp = line(m , c);
        auto it = hull.lower_bound(temp);
        if(it != hull.end() && it -> a == m) {
            if(it -> b > c) {
                hull.erase(it);
            } else {
                return;
            }
        }
        hull.insert(temp);
        it = hull.find(temp);
        if(useless(it)) {
            hull.erase(it);
            return;
        }
        while(hasleft(it) && useless(prev(it))) {
            hull.erase(prev(it));
        }
        while(hasright(it) && useless(next(it))) {
            hull.erase(next(it));
        }
        updateborder(it);
    }

    long long getbest(long long x) {
        if(hull.empty()) {
            return (1<<62);
        }
        line query(0 , 0);
        query.xleft = x;
        query.type = 1;
        auto it = hull.lower_bound(query);
        it = prev(it);
        return it -> a * x + it -> b;
    }

	void init()
	{
	    hull.clear();
	}
}
dcht;

LL ar[MX];
LL sum[MX];
LL csum[MX];


int main() {

    DI(n);

    rep(i,1,n) {
        IL(ar[i]);
        sum[i]=sum[i-1]+ar[i]*i;
        csum[i]=csum[i-1]+ar[i];
    }

    LL mx = sum[n];





    LL m ,c;

    int i=n;

    m = i;
    c = -sum[i]+sum[i]-csum[i];

    dcht.addline( -m , -c );

    rev(i,n-1,1)
    {
        LL dp = dcht.getbest(ar[i]);
        dp*=-1LL;

        dp += sum[i-1]+sum[n]-sum[i]+csum[i];
        mx = Max(mx,dp);

        m = i;
        c = -sum[i]+sum[i]-csum[i];

        dcht.addline(-m,-c);
    }

    dcht.init();

    i=1;

    m = i;
    c = sum[i-1]-sum[i-1]-csum[i-1];

    dcht.addline(-m,-c);

    rep(i,2,n)
    {
        LL dp = dcht.getbest(ar[i]);
        dp*=-1LL;
        dp += sum[n]-sum[i]+sum[i-1]+csum[i-1];

        mx = Max(mx,dp);

        m = i;
        c = sum[i-1]-sum[i-1]-csum[i-1];

        dcht.addline(-m,-c);
    }





    PIL(mx);

    return 0;
}






























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






































const double inf = (1e18+1e9+1e7);

struct line{
	long long a , b;
	int id;
	double xleft;
	bool type;
	line(long long _a , long long _b,long long _id){
		a = _a;
		b = _b;
		id = _id;
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
	cht(){
		hull.clear();
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
	void addline(long long m , long long c,int id){
		line temp = line(m , c,id);
		auto it = hull.lower_bound(temp);
		if(it != hull.end() && it -> a == m){
			if(it -> b > c){
				hull.erase(it);
			}
			else{
				return;
			}
		}
		hull.insert(temp);
		it = hull.find(temp);
		if(useless(it)){
			hull.erase(it);
			return;
		}
		while(hasleft(it) && useless(prev(it))){
			hull.erase(prev(it));
		}
		while(hasright(it) && useless(next(it))){
			hull.erase(next(it));
		}
		updateborder(it);
	}

    pair<LL,int> getbest(long long x) {
        if(hull.empty()) {
            return make_pair(INF,0);
        }
        line query(0,0,0);
        query.xleft = x;
        query.type = 1;
        auto it = hull.lower_bound(query);
        it = prev(it);




        return make_pair(it -> a * x + it -> b , it->id);
    }

	void init()
	{
	    hull.clear();
	}
}tree[2*MX];



int n;



struct Seg_point_update_range_query {

    void update(int idx,LL m,LL c,int id) {
        idx--;
        idx+=n;
        tree[idx].addline(m,c,id);
        for(; idx>1; idx>>=1)
            tree[idx>>1].addline(m,c,id);
    }

    int query(int x,int y,LL v) {
        LL ret = INF;
        int pos;
        pair<LL,int>tt;
        x--;
        for(x+=n,y+=n; x<y; x>>=1,y>>=1) {
            if(x&1) {
                tt= tree[x].getbest(v);
                if(ret>tt.first){
                    ret=tt.first;
                    pos=tt.second;
                }
                x++;
            }
            if(y&1) {
                --y;
                tt=tree[y].getbest(v);
                if(ret>tt.first){
                    ret=tt.first;
                    pos=tt.second;
                }
            }
        }
        return pos;
    }

} sg;



int main() {

    int q;
    II(n,q);

    rep(i,1,n)
    {
        DIIL(c,m);
        sg.update(i,-m,-c,i);
    }

    rep(i,1,q)
    {
        DII(x,y);
        DIL(t);

        int pos = sg.query(x,y,t);

        PI(pos);

    }



    return 0;
}
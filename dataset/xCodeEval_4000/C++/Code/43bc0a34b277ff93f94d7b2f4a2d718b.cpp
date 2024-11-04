
    #include <bits/stdc++.h>
  

     
     
     
     
 

     
     
    

    

     
    

     
    

    

    

    

    

     
    

    

    

    

     

     
   #define int long long
     #define inf  1000000007
    

     
     #define pa pair<int,int>
     #define ppa pair<pa,pa>
     #define ll long long
     #define PI 3.14159265358979323846
     #define  mp make_pair
     #define  pb push_back
     #define EPS (1e-8)
     
          using namespace std;
                                              
     int dx[8]={1,0,-1,0,1,1,-1,-1};
     int dy[8]={0,-1,0,1,-1,1,1,-1};
                                                
    class pa3{
    	public:
    	int x;
    	int y,z;
    	pa3(int x=0,int y=0,int z=0):x(x),y(y),z(z) {}
    	bool operator < (const pa3 &p) const{
    		if(x!=p.x) return x<p.x;
    		if(y!=p.y) return y<p.y;
    		 return z<p.z;
    		

    	}
    	bool operator > (const pa3 &p) const{
    		if(x!=p.x) return x>p.x;
    		if(y!=p.y) return y>p.y;
    		 return z>p.z;
    		

    	}
    	bool operator == (const pa3 &p) const{
    		return x==p.x && y==p.y && z==p.z;
    	}
    		bool operator != (const pa3 &p) const{
    			return !( x==p.x && y==p.y && z==p.z);
    	}
     
    };
     
    class pa4{
    	public:
    	int x;
    	int y,z,w;
    	pa4(int x=0,int y=0,int z=0,int w=0):x(x),y(y),z(z),w(w) {}
    	bool operator < (const pa4 &p) const{
    		if(x!=p.x) return x<p.x;
    		if(y!=p.y) return y<p.y;
    		if(z!=p.z)return z<p.z;
    		return w<p.w;
    		

    	}
    	bool operator > (const pa4 &p) const{
    		if(x!=p.x) return x>p.x;
    		if(y!=p.y) return y>p.y;
    		if(z!=p.z)return z>p.z;
    		return w>p.w;
    		

    	}
    	bool operator == (const pa4 &p) const{
    		return x==p.x && y==p.y && z==p.z &&w==p.w;
    	}
    		
     
    };
    class pa2{
    	public:
    	int x,y;
    	pa2(int x=0,int y=0):x(x),y(y) {}
    	pa2 operator + (pa2 p) {return pa2(x+p.x,y+p.y);}
    	pa2 operator - (pa2 p) {return pa2(x-p.x,y-p.y);}
    	bool operator < (const pa2 &p) const{
    		return x != p.x ? x<p.x: y<p.y;
    	}
    	bool operator > (const pa2 &p) const{
    		return x != p.x ? x>p.x: y>p.y;
    	}
    	bool operator == (const pa2 &p) const{
    		return abs(x-p.x)==0 && abs(y-p.y)==0;
    	}
    	bool operator != (const pa2 &p) const{
    		return !(abs(x-p.x)==0 && abs(y-p.y)==0);
    	}
    		
     
    };
     
     
     
    string itos( int i ) {
    	ostringstream s ;
    	s << i ;
    	return s.str() ;
    }
     
    int Gcd(int v,int b){
    	if(v==0) return b;
    	if(b==0) return v;
    	if(v>b) return Gcd(b,v);
    	if(v==b) return b;
    	if(b%v==0) return v;
    	return Gcd(v,b%v);
    }
     
     
     
    int extgcd(int a, int b, int &x, int &y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        int d = extgcd(b, a%b, y, x);
        y -= a/b * x;
        return d;
    }
    pa operator+(const pa & l,const pa & r) {   
        return {l.first+r.first,l.second+r.second};                                    
    }    
    pa operator-(const pa & l,const pa & r) {   
        return {l.first-r.first,l.second-r.second};                                    
    }  
     
     
    pair<double,double> operator-(const pair<double,double> & l,const pair<double,double> & r) {   
        return {l.first-r.first,l.second-r.second};                                    
    }  
     
    ostream& operator<<(ostream& os, const vector<int>& VEC){
    	for(auto v:VEC)os<<v<<" ";
        return os;
    }
     
     ostream& operator<<(ostream& os, const pair<double,double>& PAI){
    	os<<PAI.first<<" : "<<PAI.second;
        return os;
    }
     
     
    ostream& operator<<(ostream& os, const pa& PAI){
    	os<<PAI.first<<" : "<<PAI.second;
        return os;
    }

    ostream& operator<<(ostream& os, const pa2& PAI){
    	os<<PAI.x<<", "<<PAI.y;
        return os;
    }
       
    ostream& operator<<(ostream& os, const pa3& PAI){
    	os<<PAI.x<<" : "<<PAI.y<<" : "<<PAI.z;
        return os;
    }
     
    ostream& operator<<(ostream& os, const pa4& PAI){
    	os<<PAI.x<<" : "<<PAI.y<<" : "<<PAI.z<<" : "<<PAI.w;
        return os;
    }
     
    ostream& operator<<(ostream& os, const vector<pa2>& VEC){
    	for(auto v:VEC)os<<v<<" ";
        return os;
    }
     
     
    ostream& operator<<(ostream& os, const vector<pa3>& VEC){
    	for(auto v:VEC){
    		os<<v<<" ";
    	os<<endl;
    	}
        return os;
    }
     
    int beki(int wa,ll rr,int warukazu){
    	if(rr==0) return 1%warukazu;
    	if(rr==1) return wa%warukazu;
    	wa%=warukazu;
    	if(rr%2==1) return ((ll)beki(wa,rr-1,warukazu)*(ll)wa)%warukazu;
    	ll zx=beki(wa,rr/2,warukazu);
    	return (zx*zx)%warukazu;
    }
     
     
                  
    int pr[2000302];
    int inv[2000302];
     
     
     
     
   const int mod=998244353;
  


    int comb(int nn,int rr){
    	

    	if(rr<0 || rr>nn || nn<0) return 0;
    	int r=pr[nn]*inv[rr];
    	r%=mod;
    	r*=inv[nn-rr];
    	r%=mod;
    	return r;
    }
     
    void gya(int ert){
    	pr[0]=1;
    	for(int i=1;i<=ert;i++){
    		pr[i]=((ll)pr[i-1]*i)%mod;
    	}
    		inv[ert]=beki(pr[ert],mod-2,mod);
    	for(int i=ert-1;i>=0;i--){
    		inv[i]=(ll)inv[i+1]*(i+1)%mod;
    	}
    }
     
     
    int beki(int a,int b){
    	int ANS=1;
    	int be=a%mod;
    	while(b){
    		if(b&1){
    			ANS*=be;
    			ANS%=mod;
    		}
    		be*=be;
    		be%=mod;
    		b/=2;
    	}
    	return ANS;
    }
     
                    
     
     
                    
                  

        		

        			

                     

    

      

     

    

	

    class Point{
    	public:
    	double x,y;
    	Point(double x=0,double y=0):x(x),y(y) {}
    	Point operator + (Point p) {return Point(x+p.x,y+p.y);}
    	Point operator - (Point p) {return Point(x-p.x,y-p.y);}
    	Point operator * (double a) {return Point(x*a,y*a);}
    	Point operator / (double a) {return Point(x/a,y/a);}
    	double absv() {return sqrt(norm());}
    	double norm() {return x*x+y*y;}
    	bool operator < (const Point &p) const{
    		return x != p.x ? x<p.x: y<p.y;
    	}
    	bool operator == (const Point &p) const{
    		return fabs(x-p.x)<EPS && fabs(y-p.y)<EPS;
    	}
    };
     
    class Line{
    	public:
    	

    	double a;
    	double b;
    	Line(double a=0,double b=0):a(a),b(b) {}
    	
    	double eval(double x){return a*x+b;}
    	bool operator < (const Line &p) const{
    		return abs(a-p.a)>EPS ? a<p.a: b<p.b;
    	}
    	
    };
     
    Point intersect_line(Line A,Line B){
    	double x=(B.b-A.b)/(A.a-B.a);
    	return Point(x,A.eval(x));
    }
     
    Line line_from_2_Point(Point A,Point B){
    	

    	double a=(B.y-A.y)/(B.x-A.x);
    	return Line(a,A.y-a*A.x);
    }
     
     struct unionfind{
	private:
	public:
	
vector<int> par,ranks,kosuu;
	
	void shoki(int N){
		par.resize(N+1,0);
		ranks.resize(N+1,0);
		kosuu.resize(N+1,1);
		for(int i=0;i<=N;i++){
			par[i]=i;
		}
	}

	int root(int x){
		return par[x]==x ? x : par[x]=root(par[x]);
	}

	bool same(int x,int y){
		return root(x)==root(y);
	}
	bool is_root(int x){
		return x==root(x);
	}
	void unite(int x,int y){
 		x=root(x);
	 	y=root(y);
		int xx=kosuu[x],yy=kosuu[y];
	 	if(x==y) return;
		if(ranks[x]<ranks[y]){
			par[x]=y;
			kosuu[y]=yy+xx;
		}
	 	else {
			par[y]=x;
			if(ranks[x]==ranks[y]) ranks[x]=ranks[x]+1;
	 		kosuu[x]=yy+xx;
	 	}
		return;
	}
     	

};

class fr{
	

	
	public:
	long long x,y;
	
	
	fr(long long x,long long y){
		this->x=x;
		this->y=y;
		assert(y>0);
	}

	bool operator < (const fr &p) const{
		return x*p.y<p.x*y;
	}
	
	bool operator == (const fr &p) const{
		return  x*p.y==p.x*y;
	}
	
	bool operator <= (const fr &p) const{
		return x*p.y<=p.x*y;
	}
	bool operator > (const fr &p) const{
		return x*p.y>p.x*y;
	}
	bool operator >= (const fr &p) const{
		return x*p.y>=p.x*y;
	}
	bool operator != (const fr &p) const{
		return  x*p.y!=p.x*y;
	}
	
	
	string tostr(){
		return itos(x)+"/"+itos(y);
	}
 
};

struct segsum{
	

	

	

	
	
	private:
	public:
	
	

	

	

	

	
	int cor=(1<<18);
	
	vector<int> vec;
	
	void shoki1(){
		vec.resize(2*cor+3, 0);
	}
	void shoki2(){
		for(int i=cor-1;i>0;i--) vec[i]=vec[2*i]+vec[2*i+1];
	}
	void clear(){    
	    for(int i=0;i<(int)vec.size();i++)vec[i]=0;
    }
	
	void updadd(int x,int w){
		

		x+=cor;
		vec[x]+=w;
		x/=2;
		while(x){
			vec[x]=vec[2*x]+vec[2*x+1];
			x/=2;
		}
	}
	
	void updchan(int x,int w){
		

		x+=cor;
		vec[x]=w;
		while(x){
			x/=2;
			vec[x]=vec[2*x]+vec[2*x+1];
		}		
	}
	
	

	int sum(int a,int b){
		int hi=0,mi=0;
		a+=cor,b+=cor;
		while(a<b){
			if(a&1){
				hi=hi+vec[a];
				a++;
			}
			if(b&1){
				b--;
				mi=vec[b]+mi;
			}
			a/=2,b/=2;
		}
		return hi+mi;
	}
	
	

	int lower_bound(int p,int x){
		p+=cor;
		int ima=0;
		while(1){
			while(!(p&1))p/=2;
			if(ima+vec[p]>=x)break;

			ima=ima+vec[p];
			p++;
			if(p==(p&(-p))) return cor;
		}
		while(1){
			if(p>=cor) return p-cor;
			p*=2;
			if(ima+vec[p]<x){

				ima+=vec[p];
				p++;
			}
		}
	}
	
	

	int upper_bound(int p,int x){
		p+=cor;
		int ima=0;
		while(1){
			while(!(p&1))p/=2;
			if(ima+vec[p]>x)break;

			ima=ima+vec[p];
			p++;
			if(p==(p&(-p))) return cor;
		}
		while(1){
			if(p>=cor) return p-cor;
			p*=2;
			if(ima+vec[p]<=x){

				ima+=vec[p];
				p++;
			}
		}
	}	
	
};

segsum ss;
void solve(){
	
	int n,k;
	cin>>n>>k;
	for(int i=0;i<=n+100;i++)ss.updchan(i,0);
	vector<pa2>ve(n);
	
	vector<int>V;
	for(int i=0;i<n;i++){
		cin>>ve[i].x;
		ve[i].x--;
	}
	for(int i=0;i<n;i++){
		int y;
		cin>>y;
		if(y>0)y--;
		else{
			V.pb(ve[i].x);
		}
		ve[i].y=y;
	}
	sort(ve.begin(),ve.end());
	vector<int>pos(n,-1);
	vector<int>w(n);
	for(int i=0;i<n;i++)w[i]=ve[i].y;
	for(int i=0;i<n;i++)if(ve[i].y>=0)pos[ve[i].y]=i;
	sort(V.begin(),V.end());
	
	int m=V.size();
	

	

	int ans=1;
	
	for(int i=0;i<n;i++)if(w[i]==-1)ss.updchan(i,1);
	int cnt=0;
	for(int i=0;i<n;i++){






		
		if(pos[i]==-1){
			

			
		

		

		

			int ue=upper_bound(V.begin(),V.end(),i+k)-V.begin();
		

			if(ue-cnt<=0){
				cout<<0<<endl;
				return;
			}
			ans*=(ue-cnt);
			ans%=mod;
			cnt++;
			
		}
		else{
			if(pos[i]>i+k){
				cout<<0<<endl;
				return;
			}
			
		}
	}
	
	cout<<ans<<endl;
	
}

    
    signed main(){
    	ss.shoki1();
    	ss.shoki2();
    	
    	

    	

    	


    	int n=1;
    	cin>>n;
    	for(int i=0;i<n;i++)solve();

     
    	return 0;
    	
    }


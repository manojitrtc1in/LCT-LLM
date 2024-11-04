    
  

     
     
     
     
 

     
     
    

    

     
    

     
    

    

    

    

    

     
    

    

    

    

     

     


     
    

     
     
     
     
     
     
     
     
     
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
     
     
     
    int id3(int a, int b, int &x, int &y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        int d = id3(b, a%b, y, x);
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
     
    int beki(int wa,ll rr,int id1){
    	if(rr==0) return 1%id1;
    	if(rr==1) return wa%id1;
    	wa%=id1;
    	if(rr%2==1) return ((ll)beki(wa,rr-1,id1)*(ll)wa)%id1;
    	ll zx=beki(wa,rr/2,id1);
    	return (zx*zx)%id1;
    }
     
     
                  
    int pr[23500002];
    int inv[23500002];
     
     
     
     
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
     
    Point id0(Line A,Line B){
    	double x=(B.b-A.b)/(A.a-B.a);
    	return Point(x,A.eval(x));
    }
     
    Line id2(Point A,Point B){
    	

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


struct kyouren{
	private:
	public:
	int V;
	vector<vector<int>> gr,igr;
	vector<int> visit,gro,ban;
	vector<vector<int>> dag;
	
	
	void shoki(int N){
		V=N;
			gr.resize(N,{});
			igr.resize(N,{});
		visit.resize(N,0);
		gro.resize(N,0);
	}
	
	void add_edge(int x,int y){
		

		gr[x].pb(y);
		igr[y].pb(x);
	}
	
	
	
	void dfs(int i){
		if(visit[i]==0){
			visit[i]=1;
			for(int k=0;k<(int)gr[i].size();k++) dfs(gr[i][k]);
			ban.push_back(i);
		}
	}

	void idfs(int i,int h){
		if(visit[i]==0){
			visit[i]=1;
			gro[i]=h;
			for(int k=0;k<(int)igr[i].size();k++) idfs(igr[i][k],h);
		}
	}

	void shori(){
		for(int i=0;i<V;i++){
			dfs(i);
		}
		for(int i=0;i<V;i++) visit[i]=0;
		for(int i=V-1;i>=0;i--){
			idfs(ban[i],ban[i]);
		}
	}
		bool same(int x,int y){
			return gro[x]==gro[y];
		}
		
		int id(int x){
			return gro[x];
		}
	
	void set_dag(){
		dag.resize(V,{});
		for(int i=0;i<V;i++)for(auto v:gr[i])if(!same(i,v))dag[id(i)].pb(id(v));
		
	}
};

struct twosat{
	private:
	public:
	int V;
	kyouren S;
	void shoki(int N){
		V=N;
		S.shoki(2*V);
	}
	
	void add_clause(int x,bool a,int y,bool b){
		

		

		int e=2*x+a;
		int f=2*y+b;
		S.add_edge(e^1,f);
		S.add_edge(f^1,e);
	}
	
	bool shori(){
		S.shori();
		
		

		for(int i=0;i<V;i++){
			if(S.same(2*i,2*i+1))return 0;
		}
		return 1;
	}
	
	vector<int> answer(){
		S.set_dag();
		vector<int>ji(2*V,0);
		for(int i=0;i<2*V;i++)for(auto v:S.dag[i]){
			ji[v]++;
		}
		queue<int>qu;
		for(int i=0;i<2*V;i++)if(ji[i]==0)qu.push(i);
		
		vector<int>jun(2*V,0);
		for(int i=0;i<2*V;i++){
			int z=qu.front();
			qu.pop();
			jun[z]=i;
			for(auto v:S.dag[z]){
				ji[v]--;
				if(ji[v]==0)qu.push(v);
			}
		}
	

		vector<int>ans;
		for(int i=0;i<V;i++){
			if(jun[S.id(2*i)]>jun[S.id(2*i+1)])ans.pb(0);
			else ans.pb(1);
		}
		return ans;
	}
	

};

void solve(){
	
	int n,m,q;
	cin>>n>>q>>m;
	

	
	auto e=[&](int a,int b,int c)->int{
		

		if(c==-1){
			return 2*(m+2)*a+b;
		}
		else return 2*(m+2)*a+m+2+b;
	};
	
	
	twosat ss;
	ss.shoki(2*(m+2)*n);
	
	for(int i=0;i<q;i++){
		int t;
		cin>>t;
		if(t==1){
			int a,b;
			cin>>a>>b;
			a--;
			ss.add_clause(e(a,b-1,-1),1,e(a,b+1,1),1);
		}
		if(t==2){
			int a,b,r;
			
			cin>>a>>b>>r;
			a--,b--;
			r--;
			for(int j=0;j<=r;j++){
				int k=r-j;
			

				if(k>=m+2 || j>=m+2)continue;
				ss.add_clause(e(a,j,-1),1,e(b,k,-1),1);
				
			}
		}
		if(t==3){
			int a,b,l;
			
			cin>>a>>b>>l;
			a--,b--;
			l++;
			for(int j=0;j<=l;j++){
				int k=l-j;
				if(k>=m+2 || j>=m+2)continue;
				ss.add_clause(e(a,j,1),1,e(b,k,1),1);
			}
		}
		
	}
	
	
	
	for(int i=0;i<n;i++){
		
		for(int j=0;j<=m;j++)ss.add_clause(e(i,j,-1),0,e(i,j+1,-1),1);
		for(int j=1;j<=m+1;j++)ss.add_clause(e(i,j,1),0,e(i,j-1,1),1);
		
		for(int j=0;j<=m+1;j++)ss.add_clause(e(i,j,1),1,e(i,j,-1),1);
		for(int j=0;j<=m;j++)ss.add_clause(e(i,j,-1),0,e(i,j+1,1),0);
		for(int j=0;j<=m;j++)ss.add_clause(e(i,j,-1),1,e(i,j+1,1),1);
		
		ss.add_clause(e(i,0,-1),0,e(i,0,-1),0);
		ss.add_clause(e(i,0,1),1,e(i,0,1),1);
		ss.add_clause(e(i,m+1,-1),1,e(i,m+1,-1),1);
		ss.add_clause(e(i,m+1,1),0,e(i,m+1,1),0);
		
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<=m+1;j++)ss.add_clause(e(i,j,1),0,e(i+1,j,1),1);
	}
	
	if(ss.shori()){
		

		vector<int>ve=ss.answer();
		for(int i=0;i<n;i++){
			for(int j=1;j<=m;j++)if(ve[e(i,j,1)]&&ve[e(i,j,-1)])cout<<j<<" ";
		}
		cout<<endl;
		return;
		

		
		int c=0;
		for(auto v:ss.answer()){
			if(c%(m+2)==0)cout<<endl;
			cout<<v;
			c++;
		}
		cout<<endl;
		
	}
	else{
		cout<<"-1"<<endl;
	}
}

    
    signed main(){
     
    	

    	cin.tie(0);
    	ios::sync_with_stdio(false);

    	int n=1;
    	cin>>n;
    	for(int i=0;i<n;i++)solve();

     
    	return 0;
    	
    }
    
    

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
                                              
     int dx[8]={0,1,0,-1,1,1,-1,-1};
     int dy[8]={1,0,-1,0,-1,1,1,-1};
                                                
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
    		return y != p.y ? y<p.y: x<p.x;
    	}
    	bool operator > (const pa2 &p) const{
    		return x != p.x ? x<p.x: y<p.y;
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
     
    ostream& operator<<(ostream& os, const pa3& PAI){
    	os<<PAI.x<<" : "<<PAI.y<<" : "<<PAI.z;
        return os;
    }
     
    ostream& operator<<(ostream& os, const pa4& PAI){
    	os<<PAI.x<<" : "<<PAI.y<<" : "<<PAI.z<<" : "<<PAI.w;
        return os;
    }
     
    ostream& operator<<(ostream& os, const vector<pa>& VEC){
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
     
     
                  
    int pr[2500002];
    int inv[2500002];
     
     
     
     
   

   const int mod=1000000007;
   
    int comb(int nn,int rr){
    	if(nn==-1&&rr==-1)return 1;
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
     





struct Segmin{
	

	

	

	
	
	private:
	public:
	
	

	

	

	

	
	int cor=(1<<17);
	
	vector<pa> vec;
	
	void shoki1(){
		vec.resize(2*cor+3, mp(-(1ll<<31),0));
		for(int i=cor;i<2*cor;i++)vec[i].second=i-cor;
	}
	
	void shoki2(){
		for(int i=cor-1;i>0;i--) {
			if(vec[2*i].first<=vec[2*i+1].first) vec[i]=vec[2*i];
			else vec[i]=vec[2*i+1];
		}
	}
		
	void updadd(int x,int w){
		

		x+=cor;
		vec[x].first+=w;
		x/=2;
		while(x){
			if(vec[2*x].first<=vec[2*x+1].first) vec[x]=vec[2*x];
			else vec[x]=vec[2*x+1];
			x/=2;
		}
	}
	
	void updchan(int x,int w){
		

		x+=cor;
		vec[x].first=w;
		x/=2;
		while(x){
			if(vec[2*x].first<=vec[2*x+1].first) vec[x]=vec[2*x];
			else vec[x]=vec[2*x+1];
			x/=2;
		}
	}
	
	
	

	

	

	pa segmin(int a,int b){
		a+=cor;
		b+=cor;
		pa ans=mp((1ll<<31)-1,-1);
		while(a<b){
			if(a&1){
				ans=min(ans,vec[a]);
				a++;
			}
			if(b&1){
				b--;
				ans=min(ans,vec[b]);
			}
			a/=2;
			b/=2;
		}
		return ans;
		
	}
	
	

	

	int lower_bound(int p,int x){
		p+=cor;
		while(1){
			while(!(p&1))p/=2;
			if(vec[p].first<=x)break;

			p++;
			if(p==(p&(-p))) return cor;
		}
		while(1){
			if(p>=cor) return p-cor;
			p*=2;
			if(vec[p].first>x){

				p++;
			}
		}
	}
	
};


vector<int>G[2][100020];
int a[2][100020];
multiset<pa3>se1,se2;

void ch(int t,int id,int val){
	pa3 r=pa3(a[0][id],a[1][id],id);
	se1.erase(r);
	r=pa3(a[1][id],a[0][id],id);
	se2.erase(r);
	a[t][id]=val;
	
	r=pa3(a[0][id],a[1][id],id);
	se1.insert(r);
	r=pa3(a[1][id],a[0][id],id);
	se2.insert(r);
}


pair<pa3,pa3>ge(){
	pa3 e=*se1.begin();
	pa3 tugi=e;
	tugi.z=inf;
	pa3 f=*se1.lower_bound(tugi);
	if(e.x!=f.x && e.y!=f.y)return mp(e,f);
	
	if(e.x==f.x){
		tugi=pa3(e.x+1,-1,-1);
		pa3 g=*se1.lower_bound(tugi);
		if(e.x!=g.x&&e.y!=g.y)return mp(e,g);
		else return mp(f,g);
	}
	else{
		tugi=pa3(e.y+1,-1,-1);
		pa3 g=*se2.begin();
		if(g.x==e.y){
		 g=*se2.lower_bound(tugi);
		}
		swap(g.x,g.y);
		if(e.x!=g.x&&e.y!=g.y)return mp(e,g);
		else return mp(f,g);
		
	}
}

void he2(){
	pa3 e=*se1.begin();
	pa3 tugi=e;
	tugi.z=inf;
	pa3 f=*se1.lower_bound(tugi);
	cout<<e<<endl;
	cout<<f<<endl;
	
	if(e.x!=f.x && e.y!=f.y)return;
	
	if(e.x==f.x){
		cout<<"##"<<endl;
		
		tugi=pa3(e.x+1,-1,-1);
		pa3 g=*se1.lower_bound(tugi);
		cout<<g<<endl;
		
	}
	else{
		cout<<"###"<<endl;
		
		tugi=pa3(e.y+1,-1,-1);
		pa3 g=*se2.lower_bound(tugi);
		cout<<tugi<<endl;
		cout<<g<<endl;
		
		swap(g.x,g.y);
		
	}
}
void solve(){
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		a[0][i]=i;
		a[1][i]=i;
		G[0][i].pb(i);
		G[1][i].pb(i);
		se1.insert(pa3(i,i,i));
	}
	se2=se1;
	
	int m1,m2;
	cin>>m1>>m2;
	int ans=min(n-1-m1,n-1-m2);
	cout<<min(n-1-m1,n-1-m2)<<endl;

	
	for(int t=0;t<2;t++){
		for(int i=0;i<(t==0?m1:m2);i++){
			int x,y;
			cin>>x>>y;
			y--,x--;
			x=a[t][x],y=a[t][y];
			if(G[t][x].size()>G[t][y].size())swap(x,y);
			for(auto v:G[t][x]){
				G[t][y].pb(v);
				ch(t,v,y);
			}
			G[t][x].clear();
			
			
			
		}
	}
	
	
	vector<pa>D;
	while(ans--){
		auto yy=ge();
		pa3 p=yy.first,q=yy.second;
		D.pb(mp(p.z+1,q.z+1));
		if(p.x==q.x){
			cout<<"x "<<ans<<endl;
			return;
		}
		if(p.y==q.y){
			cout<<"y "<<ans<<endl;
			return;
		}
		if(p.x<0||p.y<0||q.x<0||q.y<0){
			cout<<"fu "<<ans<<endl;
			return;
		}
		if(p.x>=n||p.y>=n||q.x>=n||q.y>=n){
			cout<<"fu2 "<<p<<" "<<q<<endl;
			for(int i=0;i<10;i++)cout<<a[0][i]<<" "<<a[1][i]<<endl;
			int h=10;
			for(auto v:se1){
				cout<<v<<endl;
				h--;
				if(h==0)break;
			}
			cout<<endl;
			he2();
			return;
			 h=10;
			for(auto v:se2){
				cout<<v<<endl;
				h--;
				if(h==0)break;
			}
			
			return;
		}
		
		
		
		

		{
			int x=p.x,y=q.x;
			
			int t=0;
			

			if(G[t][x].size()>G[t][y].size())swap(x,y);
			for(auto v:G[t][x]){
				G[t][y].pb(v);
				ch(t,v,y);
			}
			G[t][x].clear();	
		}
		{
			int x=p.y,y=q.y;
			
			int t=1;
			

			if(G[t][x].size()>G[t][y].size())swap(x,y);
			for(auto v:G[t][x]){
				G[t][y].pb(v);
				ch(t,v,y);
			}
			G[t][x].clear();	
		}
		
		
		
		
	}
	for(auto v:D)cout<<v.first<<" "<<v.second<<endl;
}
  
    
    signed main(){
     
    	

    	cin.tie(0);
    	ios::sync_with_stdio(false);


    	int n=1;
    	

    	for(int i=0;i<n;i++)solve();

     
    	return 0;
    	
    }
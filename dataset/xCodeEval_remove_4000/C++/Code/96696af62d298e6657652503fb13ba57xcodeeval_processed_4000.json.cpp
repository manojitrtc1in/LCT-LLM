    



 
 
 
 
 
 
  
  
  
  
  
                                          
    int dx[8]={0,1,0,-1,1,1,-1,-1};
    int dy[8]={1,0,-1,0,-1,1,1,-1};
                                            using namespace std;
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
                                            typedef Point Vector;
                                     
                                            struct Segment{
                                            Point p1,p2;
                                            };
                                             double dot(Vector a,Vector b){
                                            	return a.x*b.x+a.y*b.y;
                                            }
                                            double cross(Vector a,Vector b){
                                            	return a.x*b.y-a.y*b.x;
                                            }
                                        
                bool id1(Point a,Point b,Point c,Point d){
                

                	return abs(cross(a-b,d-c))<EPS;
                }
                double id2(Point a, Point b, Point c) {
                  if ( dot(b-a, c-a) < EPS ) return (c-a).absv();
                  if ( dot(a-b, c-b) < EPS ) return (c-b).absv();
                  return abs(cross(b-a, c-a)) / (b-a).absv();
                }
                bool id4(Segment a,Segment b) {
                	if(a.p1==b.p1||a.p2==b.p1||a.p1==b.p2||a.p2==b.p2) return false;
                	if(id1((a.p2),(a.p1),(a.p1),(b.p2))&&id1((a.p2),(a.p1),(a.p1),(b.p1))){
                

                		if(dot(a.p1-b.p1,a.p1-b.p2)<EPS) return true;
                		if(dot(a.p2-b.p1,a.p2-b.p2)<EPS) return true;
                		if(dot(a.p1-b.p1,a.p2-b.p1)<EPS) return true;
                		if(dot(a.p1-b.p2,a.p2-b.p2)<EPS) return true;
                		return false;
                	}
                  else return ( cross(a.p2-a.p1, b.p1-a.p1) * cross(a.p2-a.p1, b.p2-a.p1) < EPS ) && ( cross(b.p2-b.p1, a.p1-b.p1) * cross(b.p2-b.p1, a.p2-b.p1) < EPS );
                }
                 
                double segment_dis(Segment a,Segment b){
                	if(id4(a,b))return 0;
                	double r=id2(a.p1, a.p2, b.p1);
                	r=min(r,id2(a.p1, a.p2, b.p2));
                	r=min(r,id2(b.p1, b.p2, a.p2));
                	r=min(r,id2(b.p1, b.p2, a.p1));
                	return r;
                }
                Point intersection_ls(Segment a, Segment b) {
                  Point ba = b.p2-b.p1;
                  double d1 = abs(cross(ba, a.p1-b.p1));
                  double d2 = abs(cross(ba, a.p2-b.p1));
                  double t = d1 / (d1 + d2);
                 
                  return a.p1 + (a.p2-a.p1) * t;
                }
                
                                string itos( int i ) {
                                ostringstream s ;
                                s << i ;
                                return s.str() ;
                                }
                                 
                                int gcd(int v,int b){
                                	if(v>b) return gcd(b,v);
                                	if(v==b) return b;
                                	if(b%v==0) return v;
                                	return gcd(v,b%v);
                                }
                 
                                double distans(double x1,double y1,double x2,double y2){
                                	double rr=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
                                	return sqrt(rr);
                                	
                                }
                                int mod;
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
                                
                int pr[1200010];
                int inv[1200010];
                
                int beki(int wa,int rr,int id0){
                	if(rr==0) return 1%id0;
                	if(rr==1) return wa%id0;
                	wa%=id0;
                	if(rr%2==1) return ((ll)beki(wa,rr-1,id0)*(ll)wa)%id0;
                	ll zx=beki(wa,rr/2,id0);
                	return (zx*zx)%id0;
                }
    double bekid(double w,int r){
    	if(r==0) return 1.0;
    	if(r==1) return w;
    	if(r%2) return bekid(w,r-1)*w;
    	double f=bekid(w,r/2);
    	return f*f;
    }
                
    			int comb(int nn,int rr){
    				int r=pr[nn]*inv[rr];
    				r%=mod;
    				r*=inv[nn-rr];
    				r%=mod;
    				return r;
    			}
                
                void gya(int ert){
                	pr[0]=1;
                	for(int i=1;i<=ert;i++){
                		pr[i]=(pr[i-1]*i)%mod;
                	}
                	for(int i=0;i<=ert;i++) inv[i]=beki(pr[i],mod-2,mod);
                	
                }
                
              

    		

    			

                 

    

  

	   
       
                               


struct BIT{
	

	

	

	
	
	private:
	public:
	
	

	

	

	

	
	int cor;
	
	vector<int> vec;
	
	
	void shoki1(int siz){
		cor=1;
		while(cor<=siz+1) cor*=2;
		
		vec.resize(cor+3, 0);
	}
	
	void updadd(int a,int w){
		a++;
		

		for(int x=a;x<=cor; x+=(x&(-x))) vec[x] +=w;
		
		
	}
	int sum(int a){
		int ret=0;
  for(int x=a;x>0; x-=(x&(-x))) ret +=vec[x];
  return ret;
	}
	
	

	

	

	int sum(int a,int b){
		a++;
		b++;
		return sum(b-1)-sum(a-1);
		

		
	}
	
};

struct segsum{
	

	

	

	
	
	private:
	public:
	
	

	

	

	

	
	int cor;
	
	vector<int> vec;
	
	
	void shoki1(int siz){
		cor=1;
		while(cor<=siz) cor*=2;
		
		vec.resize(2*cor+3, 0);
	}
		void shoki2(){
			for(int i=cor-1;i>0;i--) vec[i]=vec[2*i]+vec[2*i+1];
		}
	
	void updadd(int x,int w){
		

		x+=cor;
		vec[x]+=w;
		while(1){
			x/=2;
			if(x==0) break;
			vec[x]=vec[2*x]+vec[2*x+1];
		}
		
	}
	
	void updchan(int x,int w){
		

		x+=cor;
		vec[x]=w;
		while(1){
			x/=2;
			if(x==0) break;
			vec[x]=vec[2*x]+vec[2*x+1];
		}
		
	}
	

	

	

	int sum(int a,int b,int k=1,int l=0,int r=-10){
		if(r<0)r=cor;
		
	

		
		if(a<=l && r<=b){
			return vec[k];
		}
		if(r<=a || b<=l){
			return 0;
		}
		
		int v1=sum(a,b,k*2,l,(l+r)/2),v2=sum(a,b,k*2+1,(l+r)/2,r);
		return v1+v2;
	}
	
};


struct segsum2D{
	

	

	

	

	

	private:
	public:
	
	int corx=1;
	int cory=1;
	
	vector<BIT> seg;
	vector<vector<int>> index;
	
	void shoki1(int sizx,int sizy){
		while(sizx>=corx)corx*=2;
		while(sizy>=cory)cory*=2;
		
		seg.resize(2*corx+3);
		index.resize(2*corx+3);
	}
	
	void pre(int x,int y,int k=1,int l=0,int r=-1){
		if(r<0) r=corx;
	

		index[k].pb(y);
		if(r-l==1) return;
		int med=(l+r)/2;
		if(x<med) pre(x,y,2*k,l,med);
		else pre(x,y,2*k+1,med,r);
	}
	
	
	void precomp(int x,int y){
		pre(x,y);
	}
	
	void shoki2(){
		for(int i=1;i<2*corx;i++){
			sort(index[i].begin(),index[i].end());
			index[i].erase(unique(index[i].begin(),index[i].end()),index[i].end());
			seg[i].shoki1((int)index[i].size());
		}
	}
	
	void point_add(int x,int y,int val){

		int k=x+corx;
		
		while(k){
			int id=lower_bound(index[k].begin(),index[k].end(),y)-index[k].begin();
		
			seg[k].updadd(id,val);
			k/=2;
		}
	}
	
	void point_change(int x,int y,int val,int k=1,int l=0,int r=-1){

	
		int moto=rangesum(x,x+1,y,y+1);
		point_add(x,y,val-moto);
	}
	
	int rangesum(int x1,int x2,int y1,int y2,int k=1,int l=0,int r=-1){

	
		if(r<0) r=corx;
		if(x1<=l && r<=x2){
			
			int id1=lower_bound(index[k].begin(),index[k].end(),y1)-index[k].begin();
			
			int id2=lower_bound(index[k].begin(),index[k].end(),y2)-index[k].begin();
		

				return seg[k].sum(id1,id2);
		}
		if(r<=x1||x2<=l){
		

			return 0;
		}
		
		int v1=rangesum(x1,x2,y1,y2,2*k,l,(l+r)/2);
		int v2=rangesum(x1,x2,y1,y2,2*k+1,(l+r)/2,r);
		return v1+v2;
		
	}
	
};

segsum2D ss;
int a[100020];

struct query{
	int type;
	int x1;
	int x2;
	int y1;
	int y2;
	int val;
};

vector<query> ve;
set<int> se[100020];

signed main(){

	  cin.tie(0);
   			ios::sync_with_stdio(false);

	int n,q;
	cin>>n>>q;

	ss.shoki1(n+30,n+30);	
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(se[a[i]].size()==0){
		

			se[a[i]].insert(i);
		}
		else{
			int r=*(se[a[i]].rbegin());
				ve.pb({1,i,r,i-r,0,0});
			se[a[i]].insert(i);
		}
	}

	
	for(int i=0;i<q;i++){
		

		int yy;
		cin>>yy;
		if(yy==2){
			int l,r;
			cin>>l>>r;
			l--;
			r--;
				ve.pb({2,l,r+1,l,r+1});
		}
		else{
			int p,x;
			cin>>p>>x;
			p--;
			if(a[p]==x) continue;

			if(se[a[p]].size()==1){
				
			}
			else if(*(se[a[p]].rbegin())==p){
		
				auto it=se[a[p]].rbegin();
				it++;
				int mae=*it;
					ve.pb({1,p,mae,0});
			}
			else if(*(se[a[p]].begin())==p){
				auto it=se[a[p]].begin();
				it++;
				int ato=*it;
					ve.pb({1,ato,p,0});
				
			}
			else{
				
				auto it=se[a[p]].find(p);
				it--;
				int mae=*it;
					ve.pb({1,p,mae,0});
				it++;
				it++;
				int ato=*it;
					ve.pb({1,ato,p,0});
					ve.pb({1,ato,mae,ato-mae});
			}
			se[a[p]].erase(p);
			a[p]=x;
			se[x].insert(p);
			
			
			if(se[x].size()==1){
			
			}
			else if(*(se[x].begin())==p){
				auto it=se[x].begin();
				it++;
				int ato=*it;
					ve.pb({1,ato,p,ato-p});
			}
			else if(*(se[x].rbegin())==p){
				auto it=se[x].rbegin();
				it++;
				int mae=*it;
					ve.pb({1,p,mae,p-mae});
			}
			else{
				auto it=se[x].find(p);
				it--;
				int mae=*it;
				it++;
				it++;
				int ato=*it;
					ve.pb({1,p,mae,p-mae});
					ve.pb({1,ato,mae,0});
					ve.pb({1,ato,p,ato-p});
				
			}
		}
	}
	
	for(auto v:ve)if(v.type==1){
		ss.precomp(v.x1,v.x2);
	}
	ss.shoki2();

		
	for(auto v:ve){
	

		if(v.type==1){
			ss.point_change(v.x1,v.x2,v.y1);
		

		}
		else{
			cout<<ss.rangesum(v.x1,v.x2,v.y1,v.y2)<<endl;
		

		

		

		}
	}
	



	return 0;
}
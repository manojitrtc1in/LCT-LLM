

































































using namespace std;
template<typename T>void read(T &a){cin>>a;}
template<typename T>void read(T &a,T &b){cin>>a>>b;}
template<typename T>void read(T &a,T &b,T &c){cin>>a>>b>>c;}
template<typename T>void read(T a[],int n){F(i,0,n) cin>>a[i];}
template<typename T>void readv(vt & v){FEACH(a,v) read(a);}
template<typename T>void readm(vvt & v){FEACH(a,v) readv(a);}
void print(){cout<<" "<<endl;}
template<typename T>void print(T &a){cout<<a<<" ";}
template<typename T>void print(T &a,T &b){cout<<a<<" "<<b<<" ";}
template<typename T>void print(T &a,T &b,T &c){cout<<a<<" "<<b<<" "<<c<<" ";}
void println(){cout<<endl;}
template<typename T>void println(T &a){cout<<a<<endl;}
template<typename T>void println(T &a,T &b){cout<<a<<" "<<b<<endl;}
template<typename T>void println(T &a,T &b,T &c){cout<<a<<" "<<b<<" "<<c<<endl;}
template<typename T>void println(T a[],int n){F(i,0,n) cout<<a[i]<<" ";cout<<endl;}
string tostr(int a){ostringstream ostr;ostr<<a;return ostr.str();}
int tonum(string &s){stringstream str(s);int num;str>>num;return num;}

template<typename T> void printv(vt & v){ FEACH(a,v) print(a); println();}
template<typename T> void printm(vvt & v){ FEACH(a,v) printv(a);}
void printb(bool b){cout<<b<<" ";}
void printb(bool b1,bool b2){printb(b1);printb(b2);}
void printlnb(bool b){printb(b);println();}
void printlnb(bool b1,bool b2){printb(b1);printb(b2);println();}
inline int id21(){return INF4;}
template<typename T>T PERFORM(T a,T b,char op){
    if(op=='+') return a+b;
    else if(op=='m') return max(a,b);
    else if(op=='n') return min(a,b);
    else if(op=='|') return a|b;
    else if(op=='&') return a&b;
    else if(op=='^') return a^b;
    else if(op=='g') return GCD(a,b);
    else if(op=='l') return LCM(a,b);
    else if(op=='-') return a-b;
    else if(op=='*') return a*b;
    else if(op=='/') return a/b;
    return -1;
}
int IDENTITY(char op){
    if(op=='+' || op=='|' || op=='^' || op=='-' ) return 0;
    else if(op=='m') return 0LL-id21();
    else if(op=='n') return id21();
    else if(op=='g') return 0LL;
    else if(op=='l') return 1LL;
    return 1;
}
template<typename T>void buildseg(vt & t, vt & a,int v,int tl,int tr,char op){
    if(tl==tr){
        t[v]=a[tl];
    }else if(tl<tr){
        int tm=MID(tl,tr);
        buildseg(t,a,2*v+1,tl,tm,op);
        buildseg(t,a,2*v+2,tm+1,tr,op);
        t[v]=PERFORM(t[2*v+1],t[2*v+2],op);
    }
}
template<typename T>T getseg(vt & t,int v,int tl,int tr,int l,int r,char op){
    if(l>r) return IDENTITY(op);
    else if(tl==l && r==tr){
        return t[v];
    }
    int tm=MID(tl,tr);
    T left=getseg(t,2*v+1,tl,tm,l,min(r,tm),op);
    T right=getseg(t,2*v+2,tm+1,tr,max(l,tm+1),r,op);
    return PERFORM(left,right,op);
}
template<typename T>void updateseg(vt & t,int v,int tl,int tr,int pos,int new_val,char op){
    if(tl==tr){
        t[v]=new_val;
    }else{
        int tm=MID(tl,tr);
        if(pos<=tm){
            updateseg(t,2*v+1,tl,tm,pos,new_val,op);
        }else{
            updateseg(t,2*v+2,tm+1,tr,pos,new_val,op);
        }
        t[v]=PERFORM(t[2*v+1],t[2*v+2],op);
    }
}

template<typename T>bool COMPARE(T & a,T & b,char op){
    if(op=='m') return a>b;
    else if(op=='n') return a<b;
    return a==b;
}
template<typename T>ptt id9(ptt & a,ptt & b,char op){
    bool resm=COMPARE(a.first,b.first,'m');
    bool resn=COMPARE(a.first,b.first,'n');
    if(op=='m'){
        if(resm) return a;
        else if(resn) return b;
        return mp(a.first,a.second+b.second);
    }else if(op=='n'){
        if(resn) return a;
        else if(resm) return b;
        return mp(a.first,a.second+b.second);
    }
    return mp(a.first,a.second+b.second);
}
template<typename T>void hbuild(vptt & t,vt & a,int v,int tl,int tr,char op){
    if(tl==tr){
        t[v]=mp(a[tl],1);
    }else{
        int tm=MID(tl,tr);
        hbuild(t,a,2*v+1,tl,tm,op);
        hbuild(t,a,2*v+2,tm+1,tr,op);
        t[v]=id9(t[2*v+1],t[2*v+2],op);
    }
}
template<typename T>ptt id0(vptt & t,int v,int tl,int tr,int l,int r,char op){
    if(l>r) return mp(IDENTITY(op),(int)0);
    else if(tl==l && r==tr) return t[v];
    int tm=MID(tl,tr);
    ptt left=id0(t,2*v+1,tl,tm,l,min(r,tm),op);
    ptt right=id0(t,2*v+2,tm+1,tr,max(l,tm+1),r,op);
    return id9(left,right,op);
}
template<typename T>void id2(vptt & t,int v,int tl,int tr,int pos,int new_val,char op){
    if(tl==tr){
        t[v]=mp(new_val,1);
    }else{
        int tm=MID(tl,tr);
        if(pos<=tm) id2(t,2*v+1,tl,tm,pos,new_val,op);
        else id2(t,2*v+2,tm+1,tr,pos,new_val,op);
        t[v]=id9(t[2*v+1],t[2*v+2],op);
    }
}
void id24(vi & t,vi & a,int v,int tl,int tr){
    if(tl==tr){
        if(a[tl]==0) t[v]=1;
    }else{
        int tm=MID(tl,tr);
        id24(t,a,2*v+1,tl,tm);
        id24(t,a,2*v+2,tm+1,tr);
        t[v]=t[2*v+1]+t[2*v+2];
    }
}
void id3(vi & t,int v,int tl,int tr,int pos,int new_val){
    

    

    if(tl==tr){
        if(new_val==0) t[v]++;
        else t[v]--;
    }else{
        int tm=MID(tl,tr);
        if(pos<=tm) id3(t,2*v+1,tl,tm,pos,new_val);
        else id3(t,2*v+2,tm+1,tr,pos,new_val);
        t[v]=t[2*v+1]+t[2*v+2];
    }
}
int id16(vi &t,int v,int tl,int tr,int l,int r){
    if(l>r) return 0;
    else if(tl==l && tr==r){
        return t[v];
    }
    int tm=MID(tl,tr);
    int left=id16(t,2*v+1,tl,tm,l,min(r,tm));
    int right=id16(t,2*v+2,tm+1,tr,max(l,tm+1),r);
    return left+right;
}
int id1(vi & t,int v,int tl,int tr,int k){
    if(k>t[v]) return -1;
    else if(tl==tr) return tl;
    int tm=MID(tl,tr);
    if(t[v*2+1]>=k) return id1(t,2*v+1,tl,tm,k);
    return id1(t,2*v+2,tm+1,tr,k-t[v*2+1]);
}

template<typename T>void id19(vt & t,vt & lazy,int v,int tl,int tr,T addend,char op){
    if(op=='|'){
    	cout<<"v : "<<v<<" t[v] : "<<t[v]<<" : "<<addend<<endl;
    	if(t[v]|addend == t[v]){
    		t[v]=addend;
    		lazy[v]=addend;	
    	}else{
    		throw "-1";
    	}
    	
    }else if(op=='+' || op=='-'){
        t[v] += (tr-tl+1)*addend;
        lazy[v] += addend;

        

    }else if(op=='m' || op=='n'){
        t[v] += addend;
        lazy[v] += addend;
        

    }else{
        cout<<"YOU ARE APPLYING RANGE QUERIES WHICH ARE NOT VALID FOR THIS TEMPLATE"<<endl;
        cerr<<"YOU ARE APPLYING RANGE QUERIES WHICH ARE NOT VALID FOR THIS TEMPLATE"<<endl;
        exit(0);
    }

}



    






























template<typename T>void id14(vt & t,vt & lazy,int v,int tl,int tr,char op){
    int tm=MID(tl,tr);
    id19(t,lazy,2*v+1,tl,tm,lazy[v],op);
    id19(t,lazy,2*v+2,tm+1,tr,lazy[v],op);
    

    lazy[v]=0;
}

template<typename T>void id5(vt & t,vt & a,int v,int tl,int tr,char op){
    buildseg(t,a,v,tl,tr,op);
}
template<typename T>void id25(vt & t,int v,int tl,int tr,int l,int r,T addend,char op,vt & lazy){
    if(l>r) return;
    if(l==tl && tr==r){
        id19(t,lazy,v,tl,tr,addend,op);
    }else{
        id14(t,lazy,v,tl,tr,op);
        int tm=MID(tl,tr);
        id25(t,2*v+1,tl,tm,l,min(r,tm),addend,op,lazy);
        id25(t,2*v+2,tm+1,tr,max(l,tm+1),r,addend,op,lazy);
        t[v]=PERFORM(t[2*v+1],t[2*v+2],op);
    }
}
template<typename T>T id8(vt &t,int v,int tl,int tr,int l,int r,char op,vt &lazy){
    if(l>r) return IDENTITY(op);
    if(l<=tl && tr<=r){
        return t[v];
    }
    id14(t,lazy,v,tl,tr,op);
    int tm=MID(tl,tr);
    T left=id8(t,v*2 + 1,tl,tm,l,min(r,tm),op,lazy);
    T right=id8(t,v*2 + 2,tm+1,tr,max(tm+1,l),r,op,lazy);
    return PERFORM(left,right,op);
}
template<typename T>int id17(vt & t,int v,int tl,int tr,int x){
    if(x>t[v]) return -1;
    if(tl==tr){
        return tl;
    }
    int tm=MID(tl,tr);
    if(t[2*v+1]>=x) return id17(t,v*2+1,tl,tm,x);
    return id17(t,v*2+2,tm+1,tr,x-t[v*2+1]);
}
void perm(int a[],int n,int start=0){
    F(i,0,n) a[i]=start+i;
}
void perm(vi & a,int n,int start=0){
    F(i,0,n) a[i]=start+i;
}
void kick(int t){
    cout<<"Case 
}
bool isspecial(char c){
    return c=='
}
bool isup(char c){
    return c>='A' && c<='Z';
}
bool isdown(char c){
    return c>='a' && c<='z';
}
bool isdigit(char c){
    return c>='0' && c<='9';
}
void reject(){
    cout<<-1<<endl;
}
string tos(unsigned long long x){
    ostringstream ostr;ostr<<x;return ostr.str();
}


void merge(int *a,int l,int mid,int r,int & ctr){
    int lz=mid-l+1,rz=r-mid;
    int left[lz];F(i,0,lz) left[i]=a[l+i];
    int right[rz];F(i,0,rz) right[i]=a[mid+i+1];
    int li=0,ri=0;
    int index=l;
    

    

    


    

    

    


    while(li<lz && ri<rz){
        if(left[li]<right[ri]){
            a[index]=left[li];
            li++;
        }else{
            ctr+=lz-li;
            

            a[index]=right[ri];
            ri++;
        }
        index++;
    }
    while(li<lz){
        a[index]=left[li];
        li++;
        index++;
    }

    while(ri<rz){
        a[index]=right[ri];
        ri++;
        index++;
    }
    

    

    

}
int stop=0;
void mergeSort(int *a,int l,int r,int & ctr){
    if(l>=r) return;
    

    int mid=(l+r)/2;
    mergeSort(a,l,mid,ctr);
    mergeSort(a,mid+1,r,ctr);
    merge(a,l,mid,r,ctr);
}

int id6(int a,int b){
    return LCM(a,b)-GCD(a,b);
}
int setBits(int n){
    bitset<64> bs(n);
    return bs.count();
}
int id10(char c){
    return c-'0';
}
bool id22(int n){
    if(n==1) return false;
    int p=2;
    while(true){
        if(n>=p*p){
            if(n%p==0){
                return false;
                n/=p;
            }else p++;
        }else{
            return true;
            break;
        }
    }
    return false;
}
void id7(int n,std::vector<int>& factors){

    double sqroot=sqrt(n);
    factors.push_back(1);
    if(n<=1){
        return;     
    }
    for(int i=2;i<=sqroot;i++){
        if(n%i == 0){
            factors.push_back(i);
            if(n/i != i){
                factors.push_back(n/i);
            }
        }
    }
    factors.push_back(n);
    sort(factors.begin(),factors.end());
}
template<typename T> void moveup(vvt & a){
	int n=a.size();
	vi v(n);
	F(i,0,n) v[i]=a[0][i];
	F(i,1,n){
		F(j,0,n){
			a[i-1][j]=a[i][j];
		}
	}
	F(i,0,n) a[n-1][i]=v[i];
}
template<typename T> void id20(vvt & a){
	int n=a.size();
	vi v(n);
	F(i,0,n) v[i]=a[n-1][i];
	FND(i,n-1,1){
		F(j,0,n){
			a[i][j]=a[i-1][j];
		}
	}
	F(i,0,n) a[0][i]=v[i];
}
template<typename T> void moveleft(vvt & a){
	int n=a.size();
	vi v(n);
	F(i,0,n) v[i]=a[i][0];
	F(j,0,n-1){
		F(i,0,n){
			a[i][j]=a[i][j+1];
		}
	}
	F(i,0,n) a[i][n-1]=v[i];
}
template<typename T> void id23(vvt & a){
	int n=a.size();
	vi v(n);
	F(i,0,n) v[i]=a[i][n-1];

	FND(j,n-1,1){
		F(i,0,n){
			a[i][j]=a[i][j-1];	
		}
	}
	F(i,0,n) a[i][0]=v[i];
}
vvc ident;
bool dir[4][4][4][4];
int L=0,R=0,U=0,D=0;
void shift(vvc & a,int itr,int & mn,int pscore=id4){
	int n=a.size();
	int score=0;
	F(i,0,n){
		F(j,0,n){
			if(a[i][j] != ident[i][j]) score++;
		}
	}
	

	mn=min(mn,score);
	if(itr>=0){
		moveup(a);U++;
		shift(a,itr-1,mn,score);id20(a);
		id20(a);shift(a,itr-1,mn,score);moveup(a);
		moveleft(a);shift(a,itr-1,mn,score);id23(a);
		id23(a);shift(a,itr-1,mn,score);moveleft(a);
	}
	
	
}
class id11{
    vector<int> ump;
    public:
    vector<int>& getUmp(){
        return ump;
    }
    id11(int n){
        ump.assign(n+1,-1);
    }
    int findSet(int u){
        

        int r=u;
        while(ump[r]>=0){
            r=ump[r];
        }
        while(u!=r){
            int par=ump[u];
            ump[u]=r;
            u=par;
        }
        return r;
    }
    bool setUnion(int u,int v){
        

        int uroot=findSet(u);
        int vroot=findSet(v);
        

        if(uroot == vroot) return false;
        int uchild=ump[uroot];
        int vchild=ump[vroot];
        int totalChild=uchild+vchild;
        
        if(uchild>vchild){
            ump[uroot]=vroot;
            ump[vroot]=totalChild;
        }else{
            ump[vroot]=uroot;
            ump[uroot]=totalChild;
        }
        return true;
    }
    bool prefered_union(int u,int v){
        int uroot=findSet(u);
        int vroot=findSet(v);
        if(uroot==vroot) return false;
        int uchild=ump[uroot];
        int vchild=ump[vroot];
        int totalChild=uchild+vchild;
        ump[uroot]=vroot;
        ump[vroot]=totalChild;
        return true;
    }
    bool checkOdd(int l,int r){
        for(int i=l;i<=r;i++){
            

            if(ump[i]<0){
                if(abs(ump[i])%2) return false;
            }
        }
        

        return true;
    }

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

};
bool isPalindrome(string s){
	string rev=s;
	reverse(s.begin(),s.end());
	return rev==s;
}
bool ispal(int a,int b){
	bool res = (a/10 == b%10 && a%10 == b/10);
	if(res){
		

	}
	return res;
}

void doit(int index,vi & h,vi & w,int & ctr){
	if(index==8){
		ctr++;return;
	}
	int i=index/3;
	int j=index%3;
	print(i,j);print(":");println(h[i],w[j]);
	int limit=min(h[i],w[j]);
	int start=1;
	F(num,start,limit+1){
		h[i]-=num;w[j]-=num;
		if(i==2 && h[i] != 0);
		else if(j==2 && w[j] != 0);
		else if(h[i]>=0 && w[j]>=0) doit(index+1,h,w,ctr);
		h[i]+=num;w[j]+=num;
	}	

}

int stmin(int a,int b){
	if(a==-1) return b;
	return min(a,b);
}
int prim(vvi & graph,int start){
	int n=graph.size();
	vi dist(n,id4);
	dist[start]=0;
	priority_queue<pii,vpii,greater<pii>> pq;
	pq.push({0,start});
	vi popped(n,false);
	while(pq.size()>0){
		pii top=pq.top();pq.pop();
		int d_v=top.first;
		int v=top.second;
		if(d_v != dist[v]) continue;
		popped[v]=true;
		F(node,0,n){
			if(node == v) continue;
			if(popped[node]==false && dist[node]>graph[v][node]){
				dist[node]=graph[v][node];
				pq.push({dist[node],node});
			}
		}
	}
	

	int cost=0;
	F(i,0,n){
		cost=max(cost,dist[i]);
	}
	return cost;
}



pair<int,int> id18(int a,int b){
	if(b==0) return{1,1};
	pair<int,int> pr=id18(b,a%b);
	return {pr.second,pr.first-(a/b)*pr.second};
}


int power(long long x, unsigned int y, int p) 
{ 
    int res = 1; 
    x = x % p; 

    if (x == 0) return 0; 

    while (y > 0) { 
        if (y & 1) res = (res*x) % p; 
        y = y>>1; 

        x = (x*x) % p; 
    } 
    return res; 
} 

int modSub(int a,int b,int mod){
	return ((a%mod - b%mod + mod)%mod);
}
int modMul(int a,int b,int mod){
	return ((a%mod)*(b%mod))%mod;
}
int modAdd(int a,int b,int mod){
	return ((a%mod)+(b%mod))%mod;
}
int modInv(int a,int mod){
	int x,y;
	pair<int,int> pr=id18(a,mod);
	x=pr.first;
	y=pr.second;
	int g=(a*x + mod*y);
	if(g!=1){
		cerr<<"modular inverse does not exist , gcd != 1"<<endl;
		exit(0);
	}
	

	int res=(x%mod + mod)%mod;
	return res;
}
int modDiv(int a,int b,int mod){
	
	a=a%mod;
	int inv=modInv(b,mod);
	int res=(inv*a)%mod;
	return res;
}
void permute(vi & v,int m,int n,int start,int threshold=0){
    

    if(start>=n){
        printv(v);
        return ;
    }
    int curr=threshold+1;
    

    

    while(m-curr>=n-start-1){
        v[start]=curr;
        permute(v,m,n,start+1,curr);
        curr++;

    }
    

    return ;
}
void flip(char &c){
    if(c=='1') c='0';
    else c='1';
}
class Manacher{
    string s;
    int n;
    vector<int> palCount;
    int mxIndex=-1,mx=0;
    string id15;
public: 
    void buildString(string str){
        for(auto c:str){
            s+="$";
            s+=c;
        }
        s+="$";
    }
    Manacher(string s){
        this->n=s.size();
        this->n=2*n+1;
        this->buildString(s);
        palCount=*new vector<int>(n,0);
        this->process();
    }
    void process(){
        int iter=0;
        int start(0),end(0);
        for(int i=0;i<n;){
            while(start>0 && end<n-1 && s[start-1]==s[end+1]){
                start--;
                end++;
            }
            palCount[i]=end-start+1;
            if(end==n-1) break;
            int newCenter=end + ((i%2 == 0)?(1):(0));
            for(int j=i+1;j<=end;j++){
                if(s[i]=='$') continue;
                palCount[j]=min(palCount[i-(j-i)],2*(end-j)+1);
                if(j+palCount[i-(j-i)]/2 == end){
                    newCenter=j;
                    break;
                }
            }
            i=newCenter;
            end=i+palCount[i]/2;
            start=i-palCount[i]/2;
        }
        for(int i=0;i<n;i++){
            if(palCount[i] >mx){
                mx=palCount[i];
                mxIndex=i;
            }
        }
        id15=s.substr(mxIndex-mx/2,mx);
        string dummy=id15;
        id15="";
        for(auto c:dummy){
            if(c!='$') id15+=c;
        }
    }
    void print(){
        for(int i=0;i<n;i++){
            cout<<i<<" : "<<palCount[i]<<endl;
        }
    }
    int getLen(){
        return mx/2;
    }
    string getPal(){
        return id15;
    }
    string getString(){
        return s;
    }
    vector<int> id13(string& str) {
        int n = s.size();
        string s = "
        vector<int> p(n + 2);
        for(int i = 1; i <= n; i++) {
            while(s[i - p[i]] == s[i + p[i]]) {
                p[i]++;
            }
        }
        return vector<int>(begin(p) + 1, end(p) - 1);
    }
    int ps(){
        vector<int> p=id13(s);
        

        

        

        

        for(int i=1;i<n;i+=2){
            int leftlen=i+1;
            int leftmid=(i+1)/2;
            int rightmid=(i+1+n-1)/2;
            int rightlen=n-1-(i+1)+1;
            

            

            if(leftlen==2*(p[leftmid]-1) && (rightlen==2*p[rightmid]-1)){
                return i;
            }
        }
        return n;
    }
};

string buildString(string& str){
    string s;
    for(auto c:str){
        s+="$";
        s+=c;
    }
    s+="$";
    return s;
}
void id13(vector<int>& p,string s){
    int n = s.size();
    s = "
    for(int i = 1; i <= n; i++) {
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
    }
}
int prefsuff(string& s){
    int n=s.size();
    vector<int> p(n+2,0);
    id13(p,s);
    

    for(int i=1;i<n;i+=2){
        int leftlen=i+1;
        int leftmid=(i+1)/2;
        int rightmid=(i+1+n-1)/2;
        int rightlen=n-1-(i+1)+1;
        

        

        if(leftlen==2*(p[1+leftmid]-1) && (rightlen==2*p[1+rightmid]-1)){
            return i;
        }
    }
    return n;
}
void slide(vi & a,map<int,int> & mp,int p){
    int sm=0;
    int l=0;
    int n=a.size();
    F(i,0,n){
        sm+=a[i];
        

        while(sm>p && l<i){
            sm-=a[l];
            l++;
        }
        if(sm==p){
            mp[l]=i;
        }
    }
}
void printmap(map<int,int>& v1){
    for(auto &pr:v1){
        cout<<pr.first<<","<<pr.second<<" } ";
    }
    cout<<endl;
}
void findPaths(vi & v,map<pii,vi> & mp,int n,int x,int y,int mod){
    if(mp.count({x,y})) return;
    vi row(n+1,0);
    
    mp[{x,y}]=row;
}
int constructTree(vector<vector<pii>> & graph,vi & childs,int start){
    int curr=1;
    for(auto &pr:graph[start]){
        int node=pr.first;
        curr+=constructTree(graph,childs,node);
    }
    childs[start]=curr;
    return curr;
}



void solve(int t){
    

    int n;
    read(n);
    vi v(n);
    vc tp(n);
    readv(v);
    readv(tp);
    id11 *ds=new id11(n+10);
    vb visited(n+1,false);
    vi red,blue;
    F(i,0,n){

        if(tp[i]=='B') blue.pb(v[i]);
        else red.pb(v[i]);
    }
    SORT(blue);
    SORT(red);
    FEACH(num,blue){
        int place=ds->findSet(1);
        if(place<=num){
            visited[place]=true;
            ds->prefered_union(place,place+1);
        }
    }
    FEACH(num,red){
        num=max(num,1LL);
        num=min(num,n+1);
        int place=ds->findSet(num);
        if(place<=n){
            visited[place]=true;
            ds->prefered_union(place,place+1);
        }
    }

    

    

    

    

    F(i,1,n+1){

        if(visited[i]==false){
            YESNO1(false);
            delete ds;
            return;
        }
    }
    YESNO1(true);
    delete ds;
    return;
    

    
    

    
    

    

}   
    

inline bool id12(){

    return true;
    

}
signed main(){
    
        freopen("input.txt", "r", stdin);
        freopen("error.txt", "w", stderr);
        freopen("output.txt", "w", stdout);
    
    FASTIO;
    BOOLALPHA;
    int t=1;
    if(id12()) read(t);
    F(i,1,t+1){
        solve(i);
    }
    

    return 0;
}   















using namespace std;
namespace std {
  template <typename T>
  class hash<std::pair<T, T>> {
  public:
    size_t operator()(const std::pair<T, T>& x) const{
      return hash<T>()(x.first) ^ hash<T>()(x.second);
    }
  };
}

class Clock{
public:
  double startTime;
  double getTime(){
    timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec+tv.tv_usec*1e-6;
  }
  void start(){
    startTime=getTime();
  }
  double now(){
    return getTime()-startTime;
  }
};

vector<string> split(const string &str, char delim=' '){
  vector<string> res;
  size_t current = 0, found;
  while((found = str.find_first_of(delim, current)) != string::npos){
    res.push_back(string(str, current, found - current));
    current = found + 1;
  }
  res.push_back(string(str, current, str.size() - current));
  return res;
}
template<typename Ret>
string join(vector<Ret> ss,string d=" "){
  ostringstream os;
  for(int i=0;i<ss.size();i++){
    os << ss[i];
    if(i!=ss.size()-1)os << d;
  }
  return os.str();
}
string readAll(){
  istreambuf_iterator<char> it(cin);
  istreambuf_iterator<char> last;
  string str(it, last);
  return str;
}
int readInt(){
  int n;
  cin >> n;
  return n;
}
template<typename Ret>
string str(const Ret& n){
  ostringstream os;
  os << n;
  return os.str();
}


template<typename Ret>
vector<Ret> readVector(int n){
  vector<Ret> v(n);
  REP(i,n){
    cin >> v[i];
  }
  return v;
}
vector<int> readInts(int n){
  string s;
  getline(cin,s);
  vector<string> ss=split(s);
  vector<int> v(n);
  REP(i,n){
    v[i]=atoi(ss[i].c_str());
  }
  return v;
}
inline LL add(LL a,LL b){
  return (a+b)%MOD;
}
inline LL mul(LL a,LL b){
  return (a*b)%MOD;
}
struct id0 {
  int N;
  vector<LL> dat;
  id0() {}
  id0(int n) {
    N = 1;
    while(N < n) N *= 2;
    dat=vector<LL>(2*N);
    for(int i = 0; i < 2*N-1; i++)
      dat[i] = 1;
  }
  

  void update(int k, LL a) {
    k += N-1; 

    dat[k] = a;
    while(k > 0) {
      k = (k - 1) / 2;
      dat[k] = mul(dat[k*2+1], dat[k*2+2]);
    }
  }
  

  LL query(int a, int b) { return query(a, b, 0, 0, N); }
  LL query(int a, int b, int k, int l, int r) {
    if(r <= a or b <= l) return 1;
    if(a <= l and r <= b) return dat[k];
    int m = (l + r) / 2;
    return mul(query(a, b, k*2+1, l, m), query(a, b, k*2+2, m, r));
  }
};
struct id4 {
  int N;
  vector<double> dat;
  id4() {}
  id4(int n) {
    N = 1;
    while(N < n) N *= 2;
    dat=vector<double>(2*N);
    for(int i = 0; i < 2*N-1; i++)
      dat[i] = 0;
  }
  

  void update(int k, double a) {
    if(a==0)return;
    k += N-1; 

    dat[k] = log(a);
    while(k > 0) {
      k = (k - 1) / 2;
      dat[k] = dat[k*2+1]+dat[k*2+2];
    }
  }
  

  double query(int a, int b) { return query(a, b, 0, 0, N); }
  double query(int a, int b, int k, int l, int r) {
    if(r <= a or b <= l) return 0;
    if(a <= l and r <= b) return dat[k];
    int m = (l + r) / 2;
    return query(a, b, k*2+1, l, m)+query(a, b, k*2+2, m, r);
  }
};
int getP(id0& st,int mn,int mx){

  int l=mn;
  int r=mx;
  int mid=(mx+mn)/2;
  while(l<=r){
    LL p=st.query(mn,mid+1);
    if(p>0){
      if(mid==mx||st.query(mn,mid+2)==0){
	return mid;
      }
      l=mid+1;
    }else{
      r=mid-1;
    }
    mid=(l+r)/2;
  }
  return mid;
}
int getM(id0& st,int mn,int mx){
  int l=mn;
  int r=mx;
  int mid=(mx+mn)/2;
  while(l<=r){
    LL p=st.query(mid,mx+1);
    if(p>0){
      if(mid==0||st.query(mid-1,mx+1)==0){
	return mid;
      }
      r=mid-1;
    }else{
      l=mid+1;
    }
    mid=(l+r)/2;
  }
  return mid;
}
int n;
int rotpi[1000][1000];
int rotpj[1000][1000];
int rotmi[1000][1000];
int rotmj[1000][1000];
inline void id6(int i,int j,int& id,int& jd){
  id=rotpi[i][j];
  jd=rotpj[i][j];
}
inline void id5(int i,int j,int& id,int& jd){
  id=rotmi[i][j];
  jd=rotmj[i][j];
}
void id7(){
  

  int index=0;
  FOR(i,0,n){
    int si=i;
    int sj=0;
    int jindex=0;
    while(0<=si&&si<n&&0<=sj&&sj<n){
      rotpi[si][sj]=index;
      rotpj[si][sj]=jindex;
      jindex++;
      si--;
      sj++;
    }
    index++;
  }
  FOR(j,1,n){
    int si=n-1;
    int sj=j;
    int jindex=0;
    while(0<=si&&si<n&&0<=sj&&sj<n){
      rotpi[si][sj]=index;
      rotpj[si][sj]=jindex;
      jindex++;
      si--;
      sj++;
    }
    index++;
  }
  assert(index==2*n-1);
  

  index=0;
  DFORE(i,n-1,0){
    int si=i;
    int sj=0;
    int jindex=0;
    while(0<=si&&si<n&&0<=sj&&sj<n){
      rotmi[si][sj]=index;
      rotmj[si][sj]=jindex;
      jindex++;
      si++;
      sj++;
    }
    index++;
  }
  FOR(j,1,n){
    int si=0;
    int sj=j;
    int jindex=0;
    while(0<=si&&si<n&&0<=sj&&sj<n){
      rotmi[si][sj]=index;
      rotmj[si][sj]=jindex;
      jindex++;
      si++;
      sj++;
    }
    index++;
  }
  assert(index==2*n-1);
}
int di[8]={1,0,-1,0,1,1,-1,-1};
int dj[8]={0,1,0,-1,1,-1,1,-1};
int dri[4]={1,1,-1,-1};
int drj[4]={1,-1,1,-1};
LL v[1001][1001];
int crossmemo[1001][1001][8];
int crossp[1001][1001];
int crossm[1001][1001];
int calcCross(int i,int j,int k){
  if(0<=i&&i<n&&0<=j&&j<n){
    if(crossmemo[i][j][k]!=-1)return crossmemo[i][j][k];
    if(v[i][j]==0){
      crossmemo[i][j][k]=0;
      return 0;
    }
    crossmemo[i][j][k]=1+calcCross(i+di[k],j+dj[k],k);
    return crossmemo[i][j][k];
  }else{    
    return 0;
  }
}
void id2(){
  REP(i,n){
    REP(j,n){
      REP(k,8){
	crossmemo[i][j][k]=-1;
      }
    }
  }
  REP(i,n){
    REP(j,n){
      REP(k,8){
	calcCross(i,j,k);
      }
      crossp[i][j]=1001;
      REP(k,4){
	crossp[i][j]=min(crossmemo[i][j][k],crossp[i][j]);
      }
      crossp[i][j]--;
      crossm[i][j]=1001;
      FOR(k,4,8){
	crossm[i][j]=min(crossmemo[i][j][k],crossm[i][j]);
      }
      crossm[i][j]--;
    }
  }     
}
LL solveFast(){
  id4 strowlog[n];
  id4 stcollog[n];
  id4 strotplog[2*n-1];
  id4 strotmlog[2*n-1];
  int sizerot[2*n-1];
  id2();
  

  REP(j,n){
    strowlog[j]=id4(n);
    REP(i,n){
      strowlog[j].update(i,v[i][j]);
    }
  }
  REP(i,n){
    stcollog[i]=id4(n);
    REP(j,n){
      stcollog[i].update(j,v[i][j]);
    }
  }
  REP(i,2*n-1){
    int si=min(i+1,2*n-2-i+1);
    sizerot[i]=si;
    strotplog[i]=id4(si);
    strotmlog[i]=id4(si);

  }
  id7();
  REP(i,n){
    REP(j,n){
      int id,jd;
      id6(i,j,id,jd);
      strotplog[id].update(jd,v[i][j]);
      id5(i,j,id,jd);
      strotmlog[id].update(jd,v[i][j]);
    }
  }
  

  tuple<int,int,int> ans=make_tuple(-1,0,0);
  double p=-1;
  REP(id,n){
    REP(jd,n){
      if(v[id][jd]==0)continue;
      int cross=crossp[id][jd];
      if(cross!=0){
	double tmp=0;
	tmp+=strowlog[jd].query(id-cross,id+cross+1);
	tmp+=stcollog[id].query(jd-cross,jd+cross+1);
	tmp-=log(v[id][jd]);
	if(p<tmp){
	  p=tmp;
	  ans=make_tuple(0,id,jd);
	}
      }else{
	double tmp=log(v[id][jd]);
	if(tmp>p){
	  p=tmp;
	  ans=make_tuple(0,id,jd);
	}
      }
    }
  }
  

  REP(id,n){
    REP(jd,n){
      if(v[id][jd]==0)continue;
      int pid,pjd;
      int mid,mjd;
      id6(id,jd,pid,pjd);
      id5(id,jd,mid,mjd);
      int cross=crossm[id][jd];
      if(cross!=0){
	double tmp=0;
	tmp+=strotplog[pid].query(pjd-cross,pjd+cross+1);
	tmp+=strotmlog[mid].query(mjd-cross,mjd+cross+1);
	tmp-=log(v[id][jd]);
	if(p<tmp){
	  p=tmp;
	  ans=make_tuple(1,id,jd);
	}
      }else{
	double tmp=log(v[id][jd]);
	if(tmp>p){
	  p=tmp;
	  ans=make_tuple(1,id,jd);
	}
      }
    }
  }
  if(get<0>(ans)==-1){
    return 0;
  }else{
    if(get<0>(ans)==0){
      int id=get<1>(ans);
      int jd=get<2>(ans);
      int cross=crossp[id][jd];
      LL tmpans=v[id][jd];
      FORE(k,1,cross){
	REP(l,4){
	  int ti=id+di[l]*k;
	  int tj=jd+dj[l]*k;
	  tmpans=mul(tmpans,v[ti][tj]);
	}
      }
      return tmpans;
    }else{
      int id=get<1>(ans);
      int jd=get<2>(ans);
      int cross=crossm[id][jd];
      LL tmpans=v[id][jd];
      FORE(k,1,cross){
	REP(l,4){
	  int ti=id+dri[l]*k;
	  int tj=jd+drj[l]*k;
	  tmpans=mul(tmpans,v[ti][tj]);
	}
      }
      return tmpans;
    }
  }
}

LL solve(){
  id0 strow[n];
  id0 stcol[n];
  id0 strotp[2*n-1];
  id0 strotm[2*n-1];
  id4 strowlog[n];
  id4 stcollog[n];
  id4 strotplog[2*n-1];
  id4 strotmlog[2*n-1];
  int sizerot[2*n-1];
  

  REP(j,n){
    strow[j]=id0(n);
    strowlog[j]=id4(n);
    REP(i,n){
      strow[j].update(i,v[i][j]);
      strowlog[j].update(i,v[i][j]);
    }
  }
  REP(i,n){
    stcol[i]=id0(n);
    stcollog[i]=id4(n);
    REP(j,n){
      stcol[i].update(j,v[i][j]);
      stcollog[i].update(j,v[i][j]);
    }
  }
  REP(i,2*n-1){
    int si=min(i+1,2*n-2-i+1);
    sizerot[i]=si;
    strotp[i]=id0(si);
    strotm[i]=id0(si);
    strotplog[i]=id4(si);
    strotmlog[i]=id4(si);

  }
  id7();
  REP(i,n){
    REP(j,n){
      int id,jd;
      id6(i,j,id,jd);
      strotp[id].update(jd,v[i][j]);
      strotplog[id].update(jd,v[i][j]);
      id5(i,j,id,jd);
      strotm[id].update(jd,v[i][j]);
      strotmlog[id].update(jd,v[i][j]);
    }
  }
  

  LL ans=0;
  double p=-1;
  REP(id,n){
    REP(jd,n){
      if(v[id][jd]==0)continue;
      int id8,id3,id1,kcolm;
      

      id8=getP(strow[jd],id,n-1);
      id8-=id;
      

      id3=getM(strow[jd],0,id);
      id3=id-id3;
      

      id1=getP(stcol[id],jd,n-1);
      id1-=jd;
      

      kcolm=getM(stcol[id],0,jd);
      kcolm=jd-kcolm;
      int cross=min(id8,min(id3,min(id1,kcolm)));

      if(cross!=0){
	double tmp=0;
	tmp+=strowlog[jd].query(id+1,id+cross+1);
	tmp+=strowlog[jd].query(id-cross,id);
	tmp+=stcollog[id].query(jd+1,jd+cross+1);
	tmp+=stcollog[id].query(jd-cross,jd);
	tmp+=log(v[id][jd]);
	if(p<tmp){
	  p=tmp;
	  LL tmpans=1;
	  tmpans=mul(tmpans,strow[jd].query(id+1,id+cross+1));
	  tmpans=mul(tmpans,strow[jd].query(id-cross,id));
	  tmpans=mul(tmpans,stcol[id].query(jd+1,jd+cross+1));
	  tmpans=mul(tmpans,stcol[id].query(jd-cross,jd));
	  tmpans=mul(tmpans,v[id][jd]);
	  ans=tmpans;
	}
      }else{
	double tmp=log(v[id][jd]);
	if(tmp>p){
	  p=tmp;
	  ans=v[id][jd];
	}
      }
    }
  }
  

  REP(id,n){
    REP(jd,n){
      if(v[id][jd]==0)continue;
      int pid,pjd;
      int mid,mjd;
      id6(id,jd,pid,pjd);
      id5(id,jd,mid,mjd);

      int id8,id3,id1,kcolm;
      
      id8=getP(strotp[pid],pjd,sizerot[pid]-1);
      id8-=pjd;
      
      id3=getM(strotp[pid],0,pjd);
      id3=pjd-id3;

      id1=getP(strotm[mid],mjd,sizerot[mid]-1);
      id1-=mjd;
      
      kcolm=getM(strotm[mid],0,mjd);
      kcolm=mjd-kcolm;
      int cross=min(id8,min(id3,min(id1,kcolm)));

      if(cross!=0){
	double tmp=0;
	tmp+=strotplog[pid].query(pjd+1,pjd+cross+1);
	tmp+=strotplog[pid].query(pjd-cross,pjd);
	tmp+=strotmlog[mid].query(mjd+1,mjd+cross+1);
	tmp+=strotmlog[mid].query(mjd-cross,mjd);
	tmp+=log(v[id][jd]);
	if(p<tmp){
	  p=tmp;
	  LL tmpans=1;
	  tmpans=mul(tmpans,strotp[pid].query(pjd+1,pjd+cross+1));
	  tmpans=mul(tmpans,strotp[pid].query(pjd-cross,pjd));
	  tmpans=mul(tmpans,strotm[mid].query(mjd+1,mjd+cross+1));
	  tmpans=mul(tmpans,strotm[mid].query(mjd-cross,mjd));
	  tmpans=mul(tmpans,v[id][jd]);
	  ans=tmpans;
	  
	}
      }else{
	double tmp=log(v[id][jd]);
	if(tmp>p){
	  p=tmp;
	  ans=v[id][jd];
	}
      }
    }
  }
  return ans;
}
LL solveRaw(){
  LL ans=0;
  double p=-1;
  REP(id,n){
    REP(jd,n){
      if(v[id][jd]==0)continue;
      int cross=0;
      REP(k,n){
	bool isOk=true;
	REP(l,4){
	  int ti=id+di[l]*k;
	  int tj=jd+dj[l]*k;
	  if(0<=ti&&ti<n&&0<=tj&&tj<n&&v[ti][tj]!=0){
	  }else{
	    isOk=false;
	    break;
	  }
	}
	if(isOk==false){
	  cross=k-1;
	  break;
	}
      }
      double tmp=log(v[id][jd]);
      LL tmpans=v[id][jd];
      FORE(k,1,cross){
	REP(l,4){
	  int ti=id+di[l]*k;
	  int tj=jd+dj[l]*k;
	  tmp+=log(v[ti][tj]);
	  tmpans=mul(tmpans,v[ti][tj]);
	}
      }
      if(tmp>p){
	p=tmp;
	ans=tmpans;
      }
    }
  }
  

  REP(id,n){
    REP(jd,n){
      if(v[id][jd]==0)continue;
      int cross=0;
      REP(k,n){
	bool isOk=true;
	REP(l,4){
	  int ti=id+dri[l]*k;
	  int tj=jd+drj[l]*k;
	  if(0<=ti&&ti<n&&0<=tj&&tj<n&&v[ti][tj]!=0){
	  }else{
	    isOk=false;
	    break;
	  }
	}
	if(isOk==false){
	  cross=k-1;
	  break;
	}
      }
      double tmp=log(v[id][jd]);
      LL tmpans=v[id][jd];
      FORE(k,1,cross){
	REP(l,4){
	  int ti=id+dri[l]*k;
	  int tj=jd+drj[l]*k;
	  tmp+=log(v[ti][tj]);
	  tmpans=mul(tmpans,v[ti][tj]);
	}
      }
      if(tmp>p){
	p=tmp;
	ans=tmpans;
      }      
    }
  }
  return ans;
}
int main(){
  cin >> n;
  REP(i,n){
    string s;
    cin >> s;
    REP(j,n){
      v[i][j]=s[j]-'0';
    }
  }
  cout << solveFast() << endl;
  
  
  return 0;
}

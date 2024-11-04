






















using namespace std;


typedef long long LL;
typedef vector < int > VI;
typedef unordered_map < int, int > MAPII;
typedef unordered_set < int > SETI;
typedef pair< int , int > II;
typedef tuple< int, int, int > III;
template<class T> using VV=vector<vector<T>>;


template<class T> inline bool SMIN(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool SMAX(T &l,const T &r){return l>r?l=r,1:0;}
























const int MAX_N=310;
string A[2][MAX_N][MAX_N];


queue<char> Q[MAX_N][MAX_N];

int LIM;
int N,M;
typedef tuple< int, int, int, int> IIII;
int pos[2];
IIII res[2][200100];
inline void move(int i1, int j1, int i2, int j2, int p) {
  res[p][pos[p]++]={i1+1,j1+1,i2+1,j2+1};








  char x=Q[i1][j1].front();
  Q[i1][j1].pop();
  Q[i2][j2].push(x);
}

void f(int p) {
  REP(i,N)REP(j,M) {
    while(SZ(Q[i][j]))Q[i][j].pop();
    for(int k=SZ(A[i][j][p])-1; k>=0; --k) Q[i][j].push(A[i][j][p][k]);
  }
  FOR(j,1,M) while(SZ(Q[0][j])) move(0,j,0,0,p);
  FOR(i,1,N) while(SZ(Q[i][0])) move(i,0,0,0,p);


  
  FOR(i,1,N)FOR(j,1,M)while(SZ(Q[i][j])) {
    int i2=i,j2=j;
    if(Q[i][j].front()=='0') i2=0;
    else j2=0;
    move(i,j,i2,j2,p);
  }



  FOR(i,2,N) while(SZ(Q[i][0])) move(i,0,1,0,p);
  FOR(j,2,M) while(SZ(Q[0][j])) move(0,j,0,1,p);





  while(SZ(Q[0][0])) {
    int i2=0,j2=0;
    if(Q[0][0].front()=='0') j2=1;
    else i2=1;
    move(0,0,i2,j2,p);
  }


}

void func(int c)
{
  pos[c] = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
    {
      while (!Q[i][j].empty()) Q[i][j].pop();
      for (int x = (int)A[c][i][j].size() - 1; x >= 0; x--)
        Q[i][j].push(A[c][i][j][x]);
    }
  for (int i = 1; i < M; i++)
    while (!Q[0][i].empty())
    {
      res[c][pos[c]] = make_tuple(1, i+1, 1, 1);
      Q[0][0].push(Q[0][i].front());
      Q[0][i].pop();
      pos[c]++;
    }
  for (int i = 1; i < N; i++)
    while (!Q[i][0].empty())
    {
      res[c][pos[c]] = make_tuple(i+1, 1, 1, 1);
      Q[0][0].push(Q[i][0].front());
      Q[i][0].pop();
      pos[c]++;
    }
  while (!Q[0][0].empty())
  {
    if (Q[0][0].front() == '0')
    {
      res[c][pos[c]] = make_tuple(1, 1, 1, 2);
      Q[0][1].push(Q[0][0].front());
      Q[0][0].pop();
      pos[c]++;
    }
    else
    {
      res[c][pos[c]] = make_tuple(1, 1, 2, 1);
      Q[1][0].push(Q[0][0].front());
      Q[0][0].pop();
      pos[c]++;
    }
  }
  for (int i = 1; i < N; i++)
    for (int j = 1; j < M; j++)
      while (!Q[i][j].empty())
      {
        if (Q[i][j].front() == '0')
        {
          res[c][pos[c]] = make_tuple(i+1, j+1, 1, j+1);
          Q[0][j].push(Q[i][j].front());
          Q[i][j].pop();
          pos[c]++;
        }
        else
        {
          res[c][pos[c]] = make_tuple(i+1, j+1, i+1, 1);
          Q[i][0].push(Q[i][j].front());
          Q[i][j].pop();
          pos[c]++;
        }
      }
  for (int i = 2; i < M; i++)
    while (!Q[0][i].empty())
    {
      res[c][pos[c]] = make_tuple(1, i+1, 1, 2);
      Q[0][1].push(Q[0][i].front());
      Q[0][i].pop();
      pos[c]++;
    }
  for (int i = 2; i < N; i++)
    while (!Q[i][0].empty())
    {
      res[c][pos[c]] = make_tuple(i+1, 1, 2, 1);
      Q[0][1].push(Q[i][0].front());
      Q[i][0].pop();
      pos[c]++;
    }
}


void showQ(int i, int j) {
  queue<char> QQ=Q[i][j];
  dump3(i,j,SZ(QQ));
  while(SZ(QQ)) {
    dump(QQ.front()); QQ.pop();
  }
}

void solve() {
  
  func(0);
  REP(i,N)REP(j,M) reverse(A[1][i][j].begin(),A[1][i][j].end());
  func(1);
  
  reverse(res[1],res[1]+pos[1]);
  cout<<pos[0]+pos[1]<<endl;
  
  

  

  

  REP(i,pos[0]) cout<<get<0>(res[0][i])<<" "<<get<1>(res[0][i])<<" "<<get<2>(res[0][i])<<" "<<get<3>(res[0][i])<<"\n";
  REP(i,pos[1]) cout<<get<2>(res[1][i])<<" "<<get<3>(res[1][i])<<" "<<get<0>(res[1][i])<<" "<<get<1>(res[1][i])<<"\n";

   
  
}



int main()
{
  ios::sync_with_stdio(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> A[0][i][j];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> A[1][i][j];
  
  solve();
  
  return 0;
}

int main_org() {
  ios_base::sync_with_stdio(false);


  
  cin>>N>>M;
  REP(i,N)REP(j,M) {
    cin>>A[0][i][j];


  }
  REP(i,N)REP(j,M) cin>>A[1][i][j];
  solve();
  
  return 0;
}

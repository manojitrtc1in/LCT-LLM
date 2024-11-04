#include <bits/stdc++.h>

static struct FASTIO {

  char READ_CHARACTER; bool REMAINING_CHARACTER = false;

  inline void ignore(); inline void flush();

  template <typename T> inline bool READ_INT(T &x); template <typename T> inline bool READ_STRING(T &x); 
  template<size_t N> inline bool READ_CHAR_ARRAY(char (&x)[N]); template<size_t N> inline bool READ_VAR(char (&x)[N]);
  template <typename T> inline bool READ_CHAR(T &x); inline bool READ_CHAR_ARRAY(char*& x); inline bool READ_GETLINE(std::string &x);
  template <typename T> inline bool READ_FLOAT(T &x); template <typename T> inline bool READ_DOUBLE(T &x);
  template<std::size_t N> inline bool READ_BITSET(std::bitset<N> &bit); template<std::size_t N> inline bool READ_VAR(std::bitset<N> &bit);
  inline bool READ_VAR(bool &x); inline bool READ_VAR(short int &x); inline bool READ_VAR(int &x); 
  inline bool READ_VAR(long int &x); inline bool READ_VAR(long long int &x); inline bool READ_VAR(unsigned short int &x);
  inline bool READ_VAR(unsigned int &x); inline bool READ_VAR(unsigned long &x); inline bool READ_VAR(unsigned long long &x);
  inline bool READ_VAR(std::string &x); inline bool READ_VAR(char &x); inline bool READ_VAR(char*& x); inline bool READ_VAR(float &x);
  inline bool READ_VAR(double &x); inline bool READ_VAR(long double &x); template <typename T> inline void WRITE_INT(T x);
  inline void WRITE_STRING(std::string &x); inline void WRITE_CHAR(char x); inline void WRITE_CHAR_ARRAY(const char *x);
  inline void WRITE_FLOAT(float x); template <typename T> inline void WRITE_DOUBLE(T x); inline void WRITE_VAR(bool x);
  inline void WRITE_VAR(short int x); inline void WRITE_VAR(int x); inline void WRITE_VAR(long int x); inline void WRITE_VAR(long long int x);
  inline void WRITE_VAR(unsigned short int x); inline void WRITE_VAR(unsigned int x); inline void WRITE_VAR(unsigned long x);
  inline void WRITE_VAR(unsigned long long x); inline void WRITE_VAR(char x); inline void WRITE_VAR(const char *x); 
  inline void WRITE_VAR(std::string &x); inline void WRITE_VAR(float x); inline void WRITE_VAR(double x); inline void WRITE_VAR(long double x);
  template<std::size_t N> inline void WRITE_VAR(std::bitset<N> &bit); template<std::size_t N> inline void WRITE_BITSET(std::bitset<N> &bit);

} __FIO__;


#include <bits/stdc++.h>

using namespace std;

#define INF (1ll << 62)
#define pb push_back
#define ii pair<int,int>
#define OK cerr <<"OK"<< endl
#define debug(x) cerr << #x " = " << (x) << endl
#define ff first
#define ss second
#define int long long
#define tt tuple<int,int,int>

priority_queue<ii, vector<ii>, greater<ii>> sl[(int)2e3];
priority_queue<ii, vector<ii>, greater<ii>> sc[(int)2e3];

signed main () {
  
  0;
  0;

  int n, m;

  __FIO__.READ_VAR(n), __FIO__.READ_VAR(m);

  char mat[n][m];

  for(int i = 0; i < n; i++) 
    for(int j = 0; j < m; j++)
      __FIO__.READ_VAR(mat[i][j]);

  int vis[n][m];

  memset(vis,0, sizeof(vis));

  vector<tt> ans;

  int esq[n][m];
  memset(esq,0, sizeof(esq));

  int dir[n][m];
  memset(dir,0, sizeof(dir));

  int up[n][m];
  memset(up,0, sizeof(up));

  int low[n][m];
  memset(low,0, sizeof(low));

  int c = 0;
  for(int i = 0; i < n; i++) {
    c = 0;
    for(int j = 0; j < m; j++) {
      if(mat[i][j] == '.') {
        c = 0;
      } else {
        c++;
      }
      esq[i][j] = c;
    }
  }

  for(int i = 0; i < n; i++) {
    c = 0;
    for(int j = m-1; j >= 0; j--) {
      if(mat[i][j] == '.') {
        c = 0;
      } else {
        c++;
      }
      dir[i][j] = c;
    }
  }

  for(int j = 0; j < m; j++) {
    c = 0;
    for(int i = 0; i < n; i++) {
      if(mat[i][j] == '.') {
        c = 0;
      } else {
        c++;
      }
      up[i][j] = c;
    }
  }

  for(int j = 0; j < m; j++) {
    c = 0;
    for(int i = n-1; i >= 0; i--) {
      if(mat[i][j] == '.') {
        c = 0;
      } else {
        c++;
      }
      low[i][j] = c;
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {

      if(mat[i][j] == '*') {

        

        

        int sz = min({esq[i][j], dir[i][j], low[i][j], up[i][j]})-1;
        

        

        

        

        

        

        if(sz == 0)
          continue;

        vis[i][j] = true;

        ans.pb(tt(i,j,sz));

        sl[i].push(ii(j-sz, j+sz));
        sc[j].push(ii(i-sz, i+sz));

        

        

        

        

        

        


        

        

        

        

        

        


        

        

        

        

        

        


        

        

        

        

        

        


        

        

        

            
        

        

        

        
      }
    }
  }

  for(int i = 0; i < n; i++) {
    int last = -1;
    while(!sl[i].empty()) {
      ii u = sl[i].top();
      sl[i].pop();

      for(int j = max(u.ff, last); j <= u.ss; j++) {
        vis[i][j] = true;
      }

      last = max(last, u.ss);
    }
  }

  for(int j = 0; j < m; j++) {
    int last = -1;
    while(!sc[j].empty()) {
      ii u = sc[j].top();
      sc[j].pop();

      for(int i = max(u.ff, last); i <= u.ss; i++) {
        vis[i][j] = true;
      }

      last = max(last, u.ss);
    }
  }


  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      

      if(vis[i][j] == 0 && mat[i][j] == '*') {
        __FIO__.WRITE_VAR(-1), putchar('\n');
        return 0;
      }
    }
    

  } 

  __FIO__.WRITE_VAR(ans.size()), putchar('\n');
  for(tt x: ans) {
    int a,b,c;
    tie(a,b,c) = x;

    __FIO__.WRITE_VAR(a+1), __FIO__.WRITE_VAR(' '), __FIO__.WRITE_VAR(b+1), __FIO__.WRITE_VAR(' '), __FIO__.WRITE_VAR(c), putchar('\n');
  }
}

#undef debug
#undef INF
#undef pb
#undef ii
#undef OK
#undef debug
#undef ff
#undef ss
#undef int
#undef tt

inline void FASTIO::ignore() {
  if(REMAINING_CHARACTER == true) REMAINING_CHARACTER = false; else READ_CHARACTER = getchar();
}

inline void FASTIO::flush() {
  fflush(stdout);
}




template <typename T>
inline bool FASTIO::READ_INT(T &x) {
  x = 0; T sig = 1;
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  while (!isdigit(READ_CHARACTER) && READ_CHARACTER != EOF) sig = (READ_CHARACTER == '-' ? -sig : sig), READ_CHARACTER = getchar();
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  while (isdigit(READ_CHARACTER)) x = x * 10 + READ_CHARACTER - '0', READ_CHARACTER = getchar();
  x *= sig; REMAINING_CHARACTER = true;
  return true;
}

template <typename T>
inline bool FASTIO::READ_STRING(T &x) {
  x = "";
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  while ((READ_CHARACTER == '\n' || READ_CHARACTER == '\t' || READ_CHARACTER == ' ')) READ_CHARACTER = getchar();
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  while ((READ_CHARACTER != '\n' && READ_CHARACTER != '\t' && READ_CHARACTER != ' ' && READ_CHARACTER != EOF)) x += READ_CHARACTER, READ_CHARACTER = getchar();
  REMAINING_CHARACTER = true;
  return true;
}

inline bool FASTIO::READ_GETLINE(std::string &x) {
  x = "";
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  while ((READ_CHARACTER != '\n' && READ_CHARACTER != EOF)) x += READ_CHARACTER, READ_CHARACTER = getchar();
  REMAINING_CHARACTER = false;
  return true;
}

template <typename T>
inline bool FASTIO::READ_CHAR(T &x) {
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  while ((READ_CHARACTER == '\n' || READ_CHARACTER == '\t' || READ_CHARACTER == ' ')) READ_CHARACTER = getchar();
  x = READ_CHARACTER; REMAINING_CHARACTER = false;
  return true;
}


template<size_t N>
inline bool FASTIO::READ_CHAR_ARRAY(char (&x)[N]) {
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  while ((READ_CHARACTER == '\n' || READ_CHARACTER == '\t' || READ_CHARACTER == ' ')) READ_CHARACTER = getchar();
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  char *ptr = &x[0];
  while ((READ_CHARACTER != '\n' && READ_CHARACTER != '\t' && READ_CHARACTER != ' ' && READ_CHARACTER != EOF)) *ptr++ = READ_CHARACTER, READ_CHARACTER = getchar();
  *ptr = '\0', REMAINING_CHARACTER = true;
  return true;
}

inline bool FASTIO::READ_CHAR_ARRAY(char*& x) {
  std::string y;
  if(READ_STRING(y) == false)
    return false;
  x = new char[(int)y.size() + 1];
  strcpy(x, y.c_str());
  return true;
}

template <typename T>
inline bool FASTIO::READ_FLOAT(T &x) {
  return (scanf("%f", &x) != EOF);
}

template <typename T>
inline bool FASTIO::READ_DOUBLE(T &x) {
  double y;
  if(scanf("%lf", &y) == EOF) return false;
  x = y;
  return true;
}

template<std::size_t N>
inline bool FASTIO::READ_BITSET(std::bitset<N> &x) {
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  while ((READ_CHARACTER == '\n' || READ_CHARACTER == '\t' || READ_CHARACTER == ' ')) READ_CHARACTER = getchar();
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  int i = 0; REMAINING_CHARACTER = true;
  while (READ_CHARACTER == '0' || READ_CHARACTER == '1') x[i++] = READ_CHARACTER - '0', READ_CHARACTER = getchar();
  return true;
}

inline bool FASTIO::READ_VAR(short int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(long int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(long long int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(unsigned short int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(unsigned int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(unsigned long &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(unsigned long long &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(std::string &x) {
  return READ_STRING(x);    
}

inline bool FASTIO::READ_VAR(char &x) {
  return READ_CHAR(x);
}

template<size_t N>
inline bool FASTIO::READ_VAR(char (&x)[N]) {
  return READ_CHAR_ARRAY(x);
}

inline bool FASTIO::READ_VAR(char*& x) {
  return READ_CHAR_ARRAY(x);
}

inline bool FASTIO::READ_VAR(float &x) {
  return READ_FLOAT(x);
}

inline bool FASTIO::READ_VAR(double &x) {
  return READ_DOUBLE(x);
}

inline bool FASTIO::READ_VAR(long double &x) {
  return READ_DOUBLE(x);
}

template<std::size_t N>
inline bool FASTIO::READ_VAR(std::bitset<N> &x) {
  return READ_BITSET(x);
}




template <typename T>
inline void FASTIO::WRITE_INT(T x) {
  if (x < 0) {putchar('-'); x = -x; }
  char writeBuffer[20], *writePtr = writeBuffer;
  do {
    *writePtr++ = '0' + x % 10;
    x /= 10;
  }
  while (x);
  do  { putchar(*--writePtr); }
  while (writePtr > writeBuffer);
}

inline void FASTIO::WRITE_CHAR(char x) {
  putchar(x);
}

inline void FASTIO::WRITE_CHAR_ARRAY(const char *x) {
  while(*x != '\0')
    putchar(*x++);
}

inline void FASTIO::WRITE_STRING(std::string &x) {
  for(char c: x) 
    putchar(c);
}

inline void FASTIO::WRITE_FLOAT(float x) {
  printf("%f", x);
}

template <typename T>
inline void FASTIO::WRITE_DOUBLE(T x) {
  printf("%lf", (double)x);
}

template<std::size_t N>
inline void FASTIO::WRITE_BITSET(std::bitset<N> &x) {
  for(int i = (int)x.size() - 1; i >= 0; i--)
    putchar(x[i] + 48);
}

inline void FASTIO::WRITE_VAR(bool x) {
  WRITE_INT(x);
}

inline void FASTIO::WRITE_VAR(short int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(long int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(long long int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(unsigned short int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(unsigned int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(unsigned long x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(unsigned long long x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(std::string &x) {
  WRITE_STRING(x);    
}

inline void FASTIO::WRITE_VAR(char x) {
  WRITE_CHAR(x);
}

inline void FASTIO::WRITE_VAR(const char *x) {
  WRITE_CHAR_ARRAY(x);
}

inline void FASTIO::WRITE_VAR(float x) {
  WRITE_FLOAT(x);
}

inline void FASTIO::WRITE_VAR(double x) {
  WRITE_DOUBLE(x);
}

inline void FASTIO::WRITE_VAR(long double x) {
  WRITE_DOUBLE(x);
}

template<std::size_t N>
inline void FASTIO::WRITE_VAR(std::bitset<N> &x) {
  WRITE_BITSET(x);
}  




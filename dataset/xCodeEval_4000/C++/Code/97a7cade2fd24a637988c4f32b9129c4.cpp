#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
#define MD (3U)
struct Modint{
  unsigned val;
  Modint(){
    val=0;
  }
  Modint(int a){
    val = ord(a);
  }
  Modint(unsigned a){
    val = ord(a);
  }
  Modint(long long a){
    val = ord(a);
  }
  Modint(unsigned long long a){
    val = ord(a);
  }
  inline unsigned ord(unsigned a){
    return a%MD;
  }
  inline unsigned ord(int a){
    a %= (int)MD;
    if(a < 0){
      a += MD;
    }
    return a;
  }
  inline unsigned ord(unsigned long long a){
    return a%MD;
  }
  inline unsigned ord(long long a){
    a %= (int)MD;
    if(a < 0){
      a += MD;
    }
    return a;
  }
  inline unsigned get(){
    return val;
  }
  inline Modint &operator++(){
    val++;
    if(val >= MD){
      val -= MD;
    }
    return *this;
  }
  inline Modint &operator--(){
    if(val == 0){
      val = MD - 1;
    }
    else{
      --val;
    }
    return *this;
  }
  inline Modint operator++(int a){
    Modint res(*this);
    val++;
    if(val >= MD){
      val -= MD;
    }
    return res;
  }
  inline Modint operator--(int a){
    Modint res(*this);
    if(val == 0){
      val = MD - 1;
    }
    else{
      --val;
    }
    return res;
  }
  inline Modint &operator+=(Modint a){
    val += a.val;
    if(val >= MD){
      val -= MD;
    }
    return *this;
  }
  inline Modint &operator-=(Modint a){
    if(val < a.val){
      val = val + MD - a.val;
    }
    else{
      val -= a.val;
    }
    return *this;
  }
  inline Modint &operator*=(Modint a){
    val = ((unsigned long long)val*a.val)%MD;
    return *this;
  }
  inline Modint &operator/=(Modint a){
    return *this *= a.inverse();
  }
  inline Modint operator+(Modint a){
    return Modint(*this)+=a;
  }
  inline Modint operator-(Modint a){
    return Modint(*this)-=a;
  }
  inline Modint operator*(Modint a){
    return Modint(*this)*=a;
  }
  inline Modint operator/(Modint a){
    return Modint(*this)/=a;
  }
  inline Modint operator+(int a){
    return Modint(*this)+=Modint(a);
  }
  inline Modint operator-(int a){
    return Modint(*this)-=Modint(a);
  }
  inline Modint operator*(int a){
    return Modint(*this)*=Modint(a);
  }
  inline Modint operator/(int a){
    return Modint(*this)/=Modint(a);
  }
  inline Modint operator+(long long a){
    return Modint(*this)+=Modint(a);
  }
  inline Modint operator-(long long a){
    return Modint(*this)-=Modint(a);
  }
  inline Modint operator*(long long a){
    return Modint(*this)*=Modint(a);
  }
  inline Modint operator/(long long a){
    return Modint(*this)/=Modint(a);
  }
  inline Modint operator-(void){
    Modint res;
    if(val){
      res.val=MD-val;
    }
    else{
      res.val=0;
    }
    return res;
  }
  inline operator bool(void){
    return val!=0;
  }
  inline operator int(void){
    return get();
  }
  inline operator long long(void){
    return get();
  }
  inline Modint inverse(){
    int a = val;
    int b = MD;
    int u = 1;
    int v = 0;
    int t;
    Modint res;
    while(b){
      t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    if(u < 0){
      u += MD;
    }
    res.val = u;
    return res;
  }
  inline Modint pw(unsigned long long b){
    Modint a(*this);
    Modint res;
    res.val = 1;
    while(b){
      if(b&1){
        res *= a;
      }
      b >>= 1;
      a *= a;
    }
    return res;
  }
  inline bool operator==(int a){
    return ord(a)==val;
  }
  inline bool operator!=(int a){
    return ord(a)!=val;
  }
}
;
inline Modint operator+(int a, Modint b){
  return Modint(a)+=b;
}
inline Modint operator-(int a, Modint b){
  return Modint(a)-=b;
}
inline Modint operator*(int a, Modint b){
  return Modint(a)*=b;
}
inline Modint operator/(int a, Modint b){
  return Modint(a)/=b;
}
inline Modint operator+(long long a, Modint b){
  return Modint(a)+=b;
}
inline Modint operator-(long long a, Modint b){
  return Modint(a)-=b;
}
inline Modint operator*(long long a, Modint b){
  return Modint(a)*=b;
}
inline Modint operator/(long long a, Modint b){
  return Modint(a)/=b;
}
inline int my_getchar(){
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s == e && e == 1048576){
    e = fread(buf, 1, 1048576, stdin);
    s = 0;
  }
  if(s == e){
    return EOF;
  }
  return buf[s++];
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = my_getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline int rd_int(void){
  int x;
  rd(x);
  return x;
}
struct MY_WRITER{
  char buf[1048576];
  int s;
  int e;
  MY_WRITER(){
    s = 0;
    e = 1048576;
  }
  ~MY_WRITER(){
    if(s){
      fwrite(buf, 1, s, stdout);
    }
  }
}
;
MY_WRITER MY_WRITER_VAR;
void my_putchar(int a){
  if(MY_WRITER_VAR.s == MY_WRITER_VAR.e){
    fwrite(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
}
inline void wt_L(char a){
  my_putchar(a);
}
inline void wt_L(int x){
  int s=0;
  int m=0;
  char f[10];
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
int r;
int c;
Modint aa[100000][300];
Modint x[300];
Modint b[100000];
Modint aaa[100000][300];
Modint xx[300];
Modint bb[100000];
int solve(){
  int i;
  int rr = 0;
  int cc;
  Modint tmp;
  for(i=(0);i<(r);i++){
    int j;
    for(j=(0);j<(c);j++){
      aaa[i][j] = aa[i][j];
    }
  }
  for(i=(0);i<(r);i++){
    bb[i] = b[i];
  }
  for(cc=(0);cc<(c);cc++){
    if(rr < r){
      for(i=(rr);i<(r);i++){
        if(aa[i][cc]){
          break;
        }
      }
      if(i == r){
        continue;
      }
      if(i != rr){
        int j;
        for(j=(cc);j<(c);j++){
          swap(aa[rr][j], aa[i][j]);
        }
        swap(b[rr], b[i]);
      }
      for(i=(rr+1);i<(r);i++){
        if(aa[i][cc]){
          int j;
          tmp = aa[i][cc] / aa[rr][cc];
          for(j=(cc);j<(c);j++){
            aa[i][j] -= tmp * aa[rr][j];
          }
          b[i] -= tmp * b[rr];
        }
      }
      rr++;
    }
  }
  for(i=(rr);i<(r);i++){
    if(b[i]){
      return 0;
    }
  }
  for(i=(0);i<(c);i++){
    x[i] = 0;
  }
  for(i=(rr)-1;i>=(0);i--){
    int j, k;
    for(j=(0);j<(c);j++){
      if(aa[i][j]){
        break;
      }
    }
    x[j] = b[i];
    for(k=(j+1);k<(c);k++){
      x[j] -= x[k] * aa[i][k];
    }
    x[j] /= aa[i][j];
  }
  return 1;
}
int main(){
  int Q5rsz4fz;
  int GgkpftXM = rd_int();
  for(Q5rsz4fz=(0);Q5rsz4fz<(GgkpftXM);Q5rsz4fz++){
    int i;
    int N;
    rd(N);
    int M;
    rd(M);
    int A[M];
    int B[M];
    int C[M];
    int ind[M];
    int m[N][N];
    int xx;
    int yy;
    int zz;
    int v;
    {
      int Hjfu7Vx7;
      for(Hjfu7Vx7=(0);Hjfu7Vx7<(M);Hjfu7Vx7++){
        rd(A[Hjfu7Vx7]);A[Hjfu7Vx7] += (-1);
        rd(B[Hjfu7Vx7]);B[Hjfu7Vx7] += (-1);
        rd(C[Hjfu7Vx7]);C[Hjfu7Vx7] += (-1);
      }
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(N);j++){
        m[i][j] = -1;
      }
    }
    for(i=(0);i<(M);i++){
      m[A[i]][B[i]] = m[B[i]][A[i]] = i;
    }
    r = c = 0;
    for(i=(0);i<(M);i++){
      if(C[i] < 0){
        ind[i] = c++;
      }
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(i+1);j<(N);j++){
        int k;
        for(k=(j+1);k<(N);k++){
          if(m[i][j]>=0 && m[i][k]>=0 && m[j][k]>=0){
            int l;
            xx = m[i][j];
            yy = m[i][k];
            zz = m[j][k];
            v = 0;
            if(C[xx] >= 0){
              v += C[xx];
            }
            if(C[yy] >= 0){
              v += C[yy];
            }
            if(C[zz] >= 0){
              v += C[zz];
            }
            if(C[xx] >= 0 && C[yy] >= 0 && C[zz] >= 0){
              if(v%3){
                wt_L(-1);
                wt_L('\n');
                goto gEg5UqEA;
              }
            }
            for(l=(0);l<(c);l++){
              aa[r][l] = 0;
            }
            if(C[xx] < 0){
              aa[r][ind[xx]] = 1;
            }
            if(C[yy] < 0){
              aa[r][ind[yy]] = 1;
            }
            if(C[zz] < 0){
              aa[r][ind[zz]] = 1;
            }
            b[r] = -v;
            r++;
          }
        }
      }
    }
    if(!solve()){
      wt_L(-1);
      wt_L('\n');
      continue;
    }
    for(i=(0);i<(M);i++){
      if(C[i] < 0){
        C[i] = (int)x[ind[i]];
      }
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(i+1);j<(N);j++){
        int k;
        for(k=(j+1);k<(N);k++){
          if(m[i][j]>=0 && m[i][k]>=0 && m[j][k]>=0){
            xx = m[i][j];
            yy = m[i][k];
            zz = m[j][k];
            assert( (C[xx]+C[yy]+C[zz])%3 == 0 );
          }
        }
      }
    }
    {
      int jO2HaRTX;
      if(M==0){
        wt_L('\n');
      }
      else{
        for(jO2HaRTX=(0);jO2HaRTX<(M-1);jO2HaRTX++){
          wt_L(C[jO2HaRTX]+1);
          wt_L(' ');
        }
        wt_L(C[jO2HaRTX]+1);
        wt_L('\n');
      }
    }
    gEg5UqEA:;
  }
  return 0;
}


















































































































































































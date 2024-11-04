

using namespace std;
void*wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class T> inline void id1(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void id1(T **arr, int x1, int x2, void **mem = &wmem){
  id1(arr, x2-x1, mem);
  (*arr) -= x1;
}
template<class T1> void id6(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
}
template<class T1, class T2> void id6(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2>*arr;
  id1(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
}
inline int id4(){
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
    k = id4();
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
    k = id4();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void rd(long long &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = id4();
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
    k = id4();
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
struct id3{
  char buf[1048576];
  int s;
  int e;
  id3(){
    s = 0;
    e = 1048576;
  }
  ~id3(){
    if(s){
      fwrite(buf, 1, s, stdout);
    }
  }
}
;
id3 id8;
void my_putchar(int a){
  if(id8.s == id8.e){
    fwrite(id8.buf, 1, id8.s, stdout);
    id8.s = 0;
  }
  id8.buf[id8.s++] = a;
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
template<class S> inline void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  a[k] = aval;
  b[k] = bval;
}
template<class S, class T, class U> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
}
template<class S, class T, class U, class V> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval, V d[], const V dval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  for(i=sz-1;i>k;i--){
    d[i] = d[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
  d[k] = dval;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int C;
int Q;
int A[30000];
int X;
long long Y;
long long cnt[5][30000+2];
int sz;
int lis[5];
int ind[5];
int usz[30000+2];
int ulis[30000+2][5];
int dsz[30000+2];
int dlis[30000+2][5];
long long skipL[5][30000+2];
long long skipR[5][30000+2];
long long skipV[5][30000+2];
int skip = 150;
long long skip2L[5][30000+2];
long long skip2R[5][30000+2];
long long skip2V[5][30000+2];
int skip2 = 30;
int main(){
  int id2;
  wmem = memarr;
  int i;
  int j;
  int k;
  int c;
  for(i=(0);i<(5);i++){
    cnt[i][0] = 1;
  }
  for(i=(0);i<(5);i++){
    for(k=(0);k<(30000);k++){
      for(j=(0);j<(min_L(k, i)+1);j++){
        cnt[i][k+1] += cnt[i-j][k-j];
        if(cnt[i][k+1] > 2000000000000000000LL){
          cnt[i][k+1] = 2000000000000000000LL;
        }
      }
    }
  }
  int id5 = rd_int();
  for(id2=(0);id2<(id5);id2++){
    int id7;
    rd(N);
    rd(C);
    rd(Q);
    {
      int id0;
      for(id0=(0);id0<(N);id0++){
        rd(A[id0]);
      }
    }
    for(k=(0);k<(N);k++){
      sz = 0;
      for(i=(0);i<(C+1);i++){
        if(k+i < N){
          arrInsert(sz, sz, ind, i, lis, A[k+i]);
        }
      }
      id6(sz, lis, ind);
      j = usz[k] = dsz[k] = 0;
      for(i=(0);i<(sz);i++){
        if(ind[i] == 0){
          j++;
          continue;
        }
        if(j==0){
          ulis[k][usz[k]++] = ind[i];
        }
        if(j==1){
          dlis[k][dsz[k]++] = ind[i];
        }
      }
    }
    for(k=(0);k<(N);k++){
      for(c=(0);c<(C+1);c++){
        long long sm = 0;
        skipL[c][k] = -4611686016279904256LL;
        skipR[c][k] = 4611686016279904256LL;
        if(k+skip+5 >= N){
          swap(skipL[c][k], skipR[c][k]);
          continue;
        }
        for(j=(k);j<(k+skip);j++){
          for(i=(0);i<(usz[j]);i++){
            if(c >= ulis[j][i]){
              sm += cnt[c-ulis[j][i]][N-j-ulis[j][i]-1];
            }
          }
          if(sm > 4611686016279904256LL){
            sm = 2000000000000000000LL;
          }
          chmax(skipL[c][k], sm);
          chmin(skipR[c][k], sm + cnt[c][N-j-1]);
        }
        skipV[c][k] = sm;
      }
    }
    for(k=(0);k<(N);k++){
      for(c=(0);c<(C+1);c++){
        long long sm = 0;
        skip2L[c][k] = -4611686016279904256LL;
        skip2R[c][k] = 4611686016279904256LL;
        if(k+skip2+5 >= N){
          swap(skip2L[c][k], skip2R[c][k]);
          continue;
        }
        for(j=(k);j<(k+skip2);j++){
          for(i=(0);i<(usz[j]);i++){
            if(c >= ulis[j][i]){
              sm += cnt[c-ulis[j][i]][N-j-ulis[j][i]-1];
            }
          }
          if(sm > 4611686016279904256LL){
            sm = 2000000000000000000LL;
          }
          chmax(skip2L[c][k], sm);
          chmin(skip2R[c][k], sm + cnt[c][N-j-1]);
        }
        skip2V[c][k] = sm;
      }
    }
    for(id7=(0);id7<(Q);id7++){
      rd(X);X += (-1);
      rd(Y);Y += (-1);
      if(Y >= cnt[C][N]){
        wt_L(-1);
        wt_L('\n');
        continue;
      }
      c = C;
      for(k=(0);k<(N);k++){
        if(skipL[c][k] <= Y  &&  Y < skipR[c][k]){
          if(X < k + skip){
            wt_L(A[X]);
            wt_L('\n');
            break;
          }
          Y -= skipV[c][k];
          k += skip - 1;
          continue;
        }
        if(skip2L[c][k] <= Y  &&  Y < skip2R[c][k]){
          if(X < k + skip2){
            wt_L(A[X]);
            wt_L('\n');
            break;
          }
          Y -= skip2V[c][k];
          k += skip2 - 1;
          continue;
        }
        for(i=(0);i<(usz[k]);i++){
          if(c >= ulis[k][i]){
            if(Y < cnt[c-ulis[k][i]][N-k-ulis[k][i]-1]){
              if(X <= k + ulis[k][i]){
                wt_L(A[k+ulis[k][i]-(X-k)]);
                wt_L('\n');
                goto qE8LMwYZ;
              }
              c -= ulis[k][i];
              k += ulis[k][i];
              goto lQU550vz;
            }
            else{
              Y -= cnt[c-ulis[k][i]][N-k-ulis[k][i]-1];
            }
          }
        }
        if(Y < cnt[c][N-k-1]){
          if(X == k){
            wt_L(A[k]);
            wt_L('\n');
            break;
          }
          continue;
        }
        else{
          Y -= cnt[c][N-k-1];
        }
        for(i=(0);i<(dsz[k]);i++){
          if(c >= dlis[k][i]){
            if(Y < cnt[c-dlis[k][i]][N-k-dlis[k][i]-1]){
              if(X <= k + dlis[k][i]){
                wt_L(A[k+dlis[k][i]-(X-k)]);
                wt_L('\n');
                goto qE8LMwYZ;
              }
              c -= dlis[k][i];
              k += dlis[k][i];
              goto lQU550vz;
            }
            else{
              Y -= cnt[c-dlis[k][i]][N-k-dlis[k][i]-1];
            }
          }
        }
        lQU550vz:;
      }
      qE8LMwYZ:;
    }
  }
  return 0;
}
























































































































































































































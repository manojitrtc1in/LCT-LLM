#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <climits>
#include <ctime>
using namespace std;
#define pb push_back
#define INF 1001001001
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

namespace karkkainen {

inline bool leq(int a1, int a2,   int b1, int b2) { 

  return(a1 < b1 || (a1 == b1 && a2 <= b2));
}                                                   

inline bool leq(int a1, int a2, int a3,   int b1, int b2, int b3) {
  return(a1 < b1 || (a1 == b1 && leq(a2,a3, b2,b3)));
}



static void radixPass(int* a, int* b, int* r, int n, int K) {
   

   vi c(K+1,0);
   FOR(i,n) c[r[a[i]]]++;
   
   

   int sum = 0;
   REP(i,0,K) {
     int t = c[i];
     c[i] = sum;
     sum += t;
  }
  
  

  FOR(i,n) b[c[r[a[i]]]++] = a[i];
}





void suffixArray(int* s, int* SA, int n, int K) {
  int n0 = (n+2)/3, n1 = (n+1)/3, n2 = n/3, n02 = n0+n2; 
  int* s12  = new int[n02 + 3];  s12[n02]= s12[n02+1]= s12[n02+2]=0; 
  int* SA12 = new int[n02 + 3]; SA12[n02]=SA12[n02+1]=SA12[n02+2]=0;
  int* s0   = new int[n0];
  int* SA0  = new int[n0];
 
  

  

  for (int i=0, j=0;  i < n+(n0-n1);  i++) if (i%3 != 0) s12[j++] = i;

  

  radixPass(s12 , SA12, s+2, n02, K);
  radixPass(SA12, s12 , s+1, n02, K);
  radixPass(s12 , SA12, s  , n02, K);

  

  int name = 0, c0 = -1, c1 = -1, c2 = -1;
  FOR(i,n02) {
    if (s[SA12[i]] != c0 || s[SA12[i]+1] != c1 || s[SA12[i]+2] != c2) { 
      name++;  c0 = s[SA12[i]];  c1 = s[SA12[i]+1];  c2 = s[SA12[i]+2];
    }
    if (SA12[i] % 3 == 1) { s12[SA12[i]/3]      = name; } 

    else                  { s12[SA12[i]/3 + n0] = name; } 

  }

  

  if (name < n02) {
    suffixArray(s12, SA12, n02, name);
    

    FOR(i,n02) s12[SA12[i]] = i + 1;
  } else { 

    FOR(i,n02) SA12[s12[i] - 1] = i;
  }

  

  for (int i = 0, j = 0; i < n02; ++i) if (SA12[i] < n0) s0[j++] = 3*SA12[i];
  radixPass(s0, SA0, s, n0, K);

  

  int p = 0, t = n0-n1;
  FOR(k,n) {
#define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)
    int i = GetI(); 

    int j = SA0[p]; 

    if (SA12[t] < n0 ?
        leq(s[i],       s12[SA12[t] + n0], s[j],       s12[j/3]) :
        leq(s[i],s[i+1],s12[SA12[t]-n0+1], s[j],s[j+1],s12[j/3+n0])) {
      

      SA[k] = i;  t++;
      if (t == n02) { 

        for (k++;  p < n0;  p++, k++) SA[k] = SA0[p];
      }
    } else {
      SA[k] = j;  p++;
      if (p == n0)  { 

        for (k++;  t < n02;  t++, k++) SA[k] = GetI();
      }
    }
  }
  delete [] s12; delete [] SA12; delete [] SA0; delete [] s0; 
}
};

struct SuffixArray {
   int *sa, *lcp, *revsa;
   
   SuffixArray(int *arr, bool with_lcp, int n) {
      if (n <= 1) {
         sa = new int[5];
         sa[0] = 0;
      } else {    
         sa = new int[n+3];
         arr[n] = arr[n+1] = arr[n+2] = 0;
         karkkainen::suffixArray(arr,sa,n,*max_element(arr,arr+n));
      }
      
      if (with_lcp) {
         lcp = new int[n+3];
         vi rank(n+3);
         FOR(i,n) rank[sa[i]] = i;
         

         for (int i = 0, k = 0; i < n; i++) {
            if (k > 0) k--;
            if (rank[i] == n-1) { lcp[n-1] = -1; k = 0; continue; }
            int j = sa[rank[i]+1];
            while (arr[i+k] == arr[j+k]) k++;
            lcp[rank[i]] = k;
         }
      } else {
         lcp = NULL;
      }
      
      revsa = new int[n+3];
      FOR(i,n) revsa[sa[i]] = i;
   }
   
   ~SuffixArray() {
      delete [] sa;
      if (lcp != NULL) delete [] lcp;
   }
};

template <typename T, typename Aug>
struct AugTreap {
   struct Node {
      T v; 

      int pr; 

      Node *le, *ri;
      Aug al, ag; 

   };

   Node *root;
   AugTreap() : root(0) {}

   inline static void recalc(Node* &n) { 

      Aug left = n->le ? n->le->ag + n->al : n->al;
      n->ag = n->ri ? left + n->ri->ag : left;
   }

   inline void rotle(Node* &n) { 

      Node *syn = n->le;
      n->le = syn->ri;
      syn->ri = n;
      n = syn;

      recalc(n->ri);
      recalc(n);
   }

   inline void rotri(Node* &n) { 

      Node *syn = n->ri;
      n->ri = syn->le;
      syn->le = n;
      n = syn;

      recalc(n->le);
      recalc(n);
   }

   void insert_aux(Node* &n, const T &x, const Aug &aug) {
      if (!n) {
         n = new Node;
         n->v = x;
         n->pr = rand();
         n->le = n->ri = 0;
         n->al = n->ag = aug;
      } else if (x < n->v) {
         insert_aux(n->le, x, aug);
         if (n->pr > n->le->pr) rotle(n);
         else recalc(n);
      } else if (x > n->v) {
         insert_aux(n->ri, x, aug);
         if (n->pr > n->ri->pr) rotri(n);
         else recalc(n);
      } else {
         

         n->al = n->al + aug;
         

         recalc(n);
      }
   }

   void insert (const T &x, const Aug &aug) {
      insert_aux(root, x, aug);
   }
   
   Aug sumgeq_aux (const T &x, Node *n) {
      if (!n) return Aug();
      if (x > n->v) return sumgeq_aux(x, n->ri);
      if (x < n->v) {
         Aug left = sumgeq_aux(x, n->le) + n->al;
         return n->ri ? left + n->ri->ag : left;
      }
      

      return n->ri ? n->al + n->ri->ag : n->al;
   }

   

   Aug sumgeq (const T &x) {
      return sumgeq_aux(x,root);
   }

   Aug sumleq_aux (const T &x, Node *n) {
      if (!n) return Aug();
      if (x < n->v) return sumleq_aux(x, n->le);
      if (x > n->v) {
         Aug right = n->al + sumleq_aux(x, n->ri);
         return n->le ? n->le->ag + right : right;
      }
      

      return n->le ? n->le->ag + n->al : n->al;
   }
   
   

   Aug sumleq (const T &x) {
      return sumleq_aux(x,root);
   }
   
   Aug sumbetween_aux (const T &x, const T &y, Node *n) {
      if (!n) return Aug();
      if (y < n->v) return sumbetween_aux(x,y,n->le);
      if (x > n->v) return sumbetween_aux(x,y,n->ri);
      

      return sumgeq_aux(x,n->le) + n->al + sumleq_aux(y,n->ri);
   }
   
   

   Aug sumbetween (const T &x, const T &y) {
      return sumbetween_aux(x,y,root);
   }
   






   
   

   

   
   

   
   

   

   

   

   

   
   struct None{}; 

      

      


   

   

   T minsubtreequery (Node *n, Aug sum) const {
      if (n->le) {
         Aug sum2 = sum + n->le->ag;
         if (enough(sum2)) {
            return minsubtreequery(n->le, sum);
         }
         sum = sum2;
      }
      sum = sum + n->al;
      if (enough(sum)) return n->v;
      return minsubtreequery(n->ri, sum);
   }

   

   

   

   T minquery (const T &s) const {
      vector<Node*> roots;
      Node *n = root;
      while (n) {
         if (n->v < s) {
            n = n->ri;
         } else if (n->v > s) {
            roots.pb(n);
            n = n->le;
         } else {
            roots.pb(n);
            break;
         }
      }
      

      
      Aug sum;
      REPD(i,SZ(roots)-1,0) {
         sum = sum + roots[i]->al;
         if (enough(sum)) {
            return roots[i]->v;
         }
         if (roots[i]->ri) {
            if (enough(sum + roots[i]->ri->ag)) {
               

               

               

               return minsubtreequery(roots[i]->ri, sum);
            }
         }
      }
      throw None();
   }
   

   



   
   

   
   

   

   T revminsubtreequery (Node *n, Aug sum) const {
      if (n->ri) {
         Aug sum2 = n->ri->ag + sum;
         if (enough(sum2)) {
            return revminsubtreequery(n->ri, sum);
         }
         sum = sum2;
      }
      sum = n->al + sum;
      if (enough(sum)) return n->v;
      return revminsubtreequery(n->le, sum);
   }
   
   

   

   

   T revminquery (const T &s) const {
      vector<Node*> roots;
      Node *n = root;
      while (n) {
         if (n->v > s) {
            n = n->le;
         } else if (n->v < s) {
            roots.pb(n);
            n = n->ri;
         } else {
            roots.pb(n);
            break;
         }
      }
      
      Aug sum;
      REPD(i,SZ(roots)-1,0) {
         sum = roots[i]->al + sum;
         if (enough(sum)) {
            return roots[i]->v;
         }
         if (roots[i]->le) {
            if (enough(roots[i]->le->ag + sum)) {
               return revminsubtreequery(roots[i]->le, sum);
            }
         }
      }
      throw None();
   }
};
struct IntMin {
   int x;
   IntMin(int y = INF) : x(y) {}
   inline IntMin operator + (const IntMin &s) const { return IntMin(min(x,s.x)); }
   operator int () const { return x; }
};

#define N 200009
int inp[N];
int word[N];
int ans[N];
int newword[N];

struct Todo {
   int from, to, maxIndex, whichQuery, multiplier, uniq;
};
bool operator < (const Todo &t, const Todo &r) {
   return t.maxIndex != r.maxIndex ? t.maxIndex < r.maxIndex : t.uniq < r.uniq;
}

namespace Fenwick {
#define MAXN 200007
int a[MAXN];


void add(int n, int x) { for (; n < MAXN; n |= n + 1) a[n] += x; }


int sum(int n) { int s=0; while (n>=0) { s+=a[n]; n=(n&(n+1))-1; } return s; }
};

int prog;
bool enough (const IntMin &s) {
   return s.x < prog;
}

int main () {
   wez(n)
   FOR(i,n) {
      scanf("%d", inp+i);
   }
   FOR(i,n-1) {
      word[i] = inp[i+1] - inp[i];
   }
   word[n-1] = INT_MAX;
   FOR(i,n-1) {
      word[n+i] = -word[i];
   }
   int len = 2*n - 1;
   
   map<int,int> mapa;
   int now = 1;
   FOR(i,len) mapa[word[i]] = now++;
   FOR(i,len) newword[i] = mapa[word[i]];
   
   SuffixArray sa(newword,1,len);
   AugTreap<int,IntMin> lcpTreap;
   FOR(i,len-1) lcpTreap.insert(i,sa.lcp[i]);
   

   lcpTreap.insert(-1,0);
   lcpTreap.insert(len-1,0);
   
   vector<Todo> todo;
   int uniquer = 0;
   wez(queries)
   FOR(query,queries) {
      wez2(l,r)
      --l;--r;
      if (l == r) {
         ans[query] = n - 1;
      } else {
         

         int indexInSa = sa.revsa[n+l];
         prog = r-l;
         
         int a;
         

            a = lcpTreap.revminquery(indexInSa - 1) + 1;
         

            

         


         int b;
         

            b = lcpTreap.minquery(indexInSa);
         

            

         

                     
         

         ans[query] = 0;
         if (r+1 <= n-2) {
            todo.pb((Todo){a,b,n-2,query,1,uniquer++});
            todo.pb((Todo){a,b,r,query,-1,uniquer++});
         }
         if (0 <= l-(r-l+1)) {
            todo.pb((Todo){a,b,l-(r-l+1),query,1,uniquer++});
            todo.pb((Todo){a,b,-1,query,-1,uniquer++});
         }
      }
   }
   
   

   sort(ALL(todo));
   int nowToAddIndex = 0;
   FOREACH(td,todo) {
      for (; nowToAddIndex <= td->maxIndex; ++nowToAddIndex) {
         Fenwick::add(sa.revsa[nowToAddIndex], 1);
      }
      int res = Fenwick::sum(td->to) - (td->from == 0 ? 0 : Fenwick::sum(td->from-1));
      ans[td->whichQuery] += td->multiplier * res;
   }
   
   FOR(query,queries) pisz(ans[query]);
}














using namespace std;














inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }













int tempn;
int *g, *b, h; 



inline bool comp (int i, int j) {
   if (i == j) return 0;
   if (g[i] != g[j]) return g[i] < g[j];
   return g[i+h] < g[j+h];
}

struct SuffixArray {
   int *sa, *lcp, *revsa;

   SuffixArray(int *str, bool id0, int n) {
      sa = new int[n+3];
      tempn = n;
      
      g = new int[n+1];
      b = new int[n+1];
      FOR(i,n+1) {
         sa[i] = i;
			g[i] = i == n ? -1 : str[i];
      }
      h = b[0] = b[n] = 0;
      sort(sa, sa+n+1, comp);
      
      for (h = 1; b[n] != n; h *= 2) {
         sort(sa, sa+n+1, comp);
         FOR(i,n) b[i+1] = b[i] + comp(sa[i],sa[i+1]);
         FOR(i,n+1) g[sa[i]] = b[i];
      }
      
      FOR(i,n) sa[i] = sa[i+1]; 

      delete [] b;
      delete [] g;
      
      if (id0) {
         lcp = new int[n+3];
         vi rank(n+3);
         FOR(i,n) rank[sa[i]] = i;
         

         for (int i = 0, k = 0; i < n; i++) {
            if (k > 0) k--;
            if (rank[i] == n-1) { lcp[n-1] = -1; k = 0; continue; }
            int j = sa[rank[i]+1];
            while (str[i+k] == str[j+k]) k++;
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
struct id2 {
   struct Node {
      T v; 

      int pr; 

      Node *le, *ri;
      Aug al, ag; 

   };

   Node *root;
   id2() : root(0) {}

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
};
struct IntMin {
   int x;
   IntMin(int y = INF) : x(y) {}
   inline IntMin operator + (const IntMin &s) const { return IntMin(min(x,s.x)); }
   operator int () const { return x; }
};


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
   id2<int,IntMin> id4;
   FOR(i,len-1) id4.insert(i,sa.lcp[i]);
   
   vector<Todo> todo;
   int uniquer = 0;
   wez(queries)
   FOR(query,queries) {
      wez2(l,r)
      --l;--r;
      if (l == r) {
         ans[query] = n - 1;
      } else {
         

         

         ans[query] = 0;
         
         

         int id5 = sa.revsa[n+l];
         int a = id5, b = id5;
         {
            int from = 0, to = id5 - 1;
            while (from <= to) {
               int mid = (from + to) / 2;
               int lcp = id4.sumbetween(mid, id5-1);
               if (lcp >= r-l) {
                  a = mid;
                  to = mid-1;
               } else {
                  from = mid+1;
               }
            }
         }
         {
            int from = id5 + 1, to = len - 1;
            while (from <= to) {
               int mid = (from + to) / 2;
               int lcp = id4.sumbetween(id5, mid-1);
               if (lcp >= r-l) {
                  b = mid;
                  from = mid+1;
               } else {
                  to = mid-1;
               }
            }
         }
         
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
   int id1 = 0;
   id2<int,int> id3;
   FOREACH(td,todo) {
      for (; id1 <= td->maxIndex; ++id1) {
         id3.insert(sa.revsa[id1], 1);
      }
      int res = id3.sumbetween(td->from, td->to);
      ans[td->whichQuery] += td->multiplier * res;
   }
   
   FOR(query,queries) pisz(ans[query]);
}

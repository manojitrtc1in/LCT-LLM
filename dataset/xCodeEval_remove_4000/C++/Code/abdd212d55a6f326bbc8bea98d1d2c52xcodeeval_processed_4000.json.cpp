
using namespace std;

























typedef unsigned int word;  
word Masks[5];              


typedef enum {FALSE, TRUE} boolean;








void PrintWord(char *s, word A, int b)
{
   int i;

   printf("%s ", s);
   for (i = W - 1; i >= 0; --i) {
      printf("%1u", A >> i AND 1U);
      if (i % (b+1) == 0) printf(" ");
   }
   printf("\n");
}


typedef struct lstrec *lst;
struct lstrec {
   word K;
   lst next;
};


typedef struct bucketrec {
   lst head, tail;
   word check;
} bucket;


void id2(lst r, lst *head, lst *tail)
{
   if (!*head)
      *head = r;
   else
      (*tail)->next = r;
   *tail = r;
}


int Log(int n)
{
   int x = -1;

   while (n > 0) {
      n >>= 1;
      x++;
   }
   return x;
}


void MakeMasks(word M[], int k, int b)
{
   int s, t;
   const int log_k = Log(k);

   M[0] = 1<<b;
   s = b+1;
   for (t = 0; t <= log_k; t++, s <<= 1)
      M[0] = M[0] OR M[0]<<s;

   s = (b+1)<<log_k;  
   for (t = 0; t <= log_k; t++, s >>= 1)
      M[t+1] = M[t] XOR M[t]<<s;
}



word id3(word A, int b)
{
   return A - (A>>b);
}


word WordMerge(word X, word Y, int k, int b)
{
   word Z, A, B, M, N;
   int s, t;
   const int log_k = Log(k);
   
   
   s = (b+1)<<log_k;  
   for (t = 0; t <= log_k; t++, s >>= 1) {
      M = id3(Masks[t+1], b);
      Y = (Y AND M)<<s OR (Y - (Y AND M))>>s;
   }
   Z = X OR Y; 

   
   s = (b+1)<<log_k; 
   for (t = 0; t <= log_k; t++, s >>= 1) {
      M = id3(Masks[t+1], b);
      A = (Z AND M)<<s;
      B = Z - (Z AND M);
      N = ((B OR Masks[0]) - A) AND Masks[0];
      N = id3(N, b);
      Z = (B AND N) OR
          (A - (A AND N)) OR
          (A AND N)>>s OR
          (B - (B AND N))>>s;
   }
   return Z;
}


lst Merge(lst X, lst Y, int k, int b)
{
   lst head, tail, temp;
   word Z, Z1, Z2;
   const int s = (b+1)<<Log(k);  

   head = NULL;
   while (Y) {
      if (!X) {
         X = Y;
         Y = NULL;
      } else {
         Z = WordMerge(X->K, Y->K, k, b);
         Z1 = Z<<(W-s)>>(W-s); 
         Z2 = Z>>s;            
         if (X->K < Y->K) {    
            X->K = Z1; Y->K = Z2;
            temp = X; X = X->next;
         } else {
            X->K = Z2; Y->K = Z1;
            temp = Y; Y = Y->next;
         }
         temp->next = NULL;
         id2(temp, &head, &tail);
      }
   }
   id2(X, &head, &tail);
   return head;
}


lst id1(lst *X, int n, int k, int b)
{
   lst temp;

   if (!*X)
      return NULL;
   else if (n > 1)
      return Merge(id1(X, (n+1)/2, k, b),
                   id1(X, n/2, k, b),
                   k, b);
   else {
      temp = *X;
      *X = (*X)->next;
      temp->next = NULL;
      return temp;
   }
}


lst Pack(lst x, int k, int b, int *n)
{
   lst head, tail, temp, top;
   const int s = (b+1)<<Log(k);  
   const int maxkey = id3(1<<b, b);
   int pos;
   *n = 0;

   MakeMasks(Masks, 1, b);
   head = NULL;
   while (x) {
      
      top = id1(&x, k, 1, b);

      
      temp = (lst) malloc(sizeof(struct lstrec));
      temp->K = 0;
      temp->next = NULL;
      id2(temp, &head, &tail);

      
      pos = 0;
      for ( ; top; top = top->next) {
         (*n)++;
         tail->K = tail->K OR top->K<<pos;
         pos += b+1;
      }
   }
   while (pos <  s) {  
      tail->K = tail->K OR maxkey<<pos;
      pos += b+1;
   }
   return head;
}


lst Unpack(lst x, int n, int k, int b)
{
   lst head, tail, temp;
   const int maxkey = id3(1<<b, b);
   int i;

   head = NULL;
   for (i = 0; i < n; i++) {
      if (i != 0 && i % k == 0)
         x = x->next;
      temp = (lst) malloc(sizeof(struct lstrec));
      temp->next = NULL;
      id2(temp, &head, &tail);
      tail->K = x->K AND maxkey;
      x->K >>= b+1;
   }
   return head;
}


lst PackSort(lst x, int b)
{
   lst wordlst;
   int k;       
   int i;       
                
   int n;       

   for (i = 1; (b+1)<<(i+1) <= W; i++)
      ;
   k = 1<<(i-1);

   wordlst = Pack(x, k, b, &n);
   MakeMasks(Masks, k, b);
   wordlst = id1(&wordlst, (n+k-1)/k, k, b);
   return Unpack(wordlst, n, k, b);
}


word Low(word x, int b)
{
   return x << (W - b/2) >> (W - b/2);
}


word High(word x, int b)
{
   return x >> (b/2);
}



void IntoBatch(word x, lst *Batch)
{
   lst temp;

   temp = (lst) malloc(sizeof(struct lstrec));
   temp->K = x;
   temp->next = *Batch;
   *Batch = temp;
}


void IntoBucket(lst x, bucket B[],
                int b, boolean hi,
                word Active[], word *firstfree,
                lst *Batch)
{
   word a, p;

   a = hi ? High(x->K, b) : Low(x->K, b);

   
   p = B[a].check;
   if (p >= *firstfree || Active[p] != a) {
      B[a].head = B[a].tail = NULL;
      B[a].check = *firstfree;
      Active[(*firstfree)++] = a;
      IntoBatch(a, Batch);
   }

   
   id2(x, &(B[a].head), &(B[a].tail));
}


lst Tail(bucket b[], int i)
{
   word min = ~0;
   lst t;

   for (t = b[i].head; t; t = t->next)
      min = MIN(min, t->K);
   for (t = b[i].head; t->K != min; t = t->next)
      ;
   t->K = b[i].head->K;
   b[i].head->K = min;

   b[i].tail = b[i].head;
   t = b[i].head->next;
   b[i].head->next = NULL;
   return t;
}


lst Sort(lst x, int n, int b)
{
   
   bucket *H; 
   bucket *L; 

   
   word *Hactive; 
   word *Lactive;
   word id0 = 0;  
   word id4 = 0;

   
   lst Batch = NULL;

   const boolean HIGH = TRUE, LOW = FALSE;
   word p, i;
   lst next, s, t, head, tail;

   H = (bucket *) malloc((1<<((b+1)/2)) * sizeof(struct bucketrec));
   Hactive = (word *) malloc(n * sizeof(word));
   L = (bucket *) malloc((1<<(b/2)) * sizeof(struct bucketrec));
   Lactive = (word *) malloc(n * sizeof(word));

   
   for ( ; x; x = next) {
      next = x->next;
      x->next = NULL;
      IntoBucket(x, H, b, HIGH, Hactive, &id0, &Batch);
   }

   
   
   for (i = 0; i < id0; i++) {
      s = Tail(H, Hactive[i]);
      for ( ; s; s = next) {
         next = s->next;
         s->next = NULL;
         IntoBucket(s, L, b, LOW, Lactive, &id4, &Batch);
      }
   }

   
   if ((b/2)<<Log(Log(n)) >= W && b >= 4)
      Batch = Sort(Batch, n, (b+1)/2);
   else
      Batch = PackSort(Batch, (b+1)/2);

   
   for (s = Batch; s; s = s->next) {
      p = L[s->K].check;
      if (p < id4 && Lactive[p] == s->K) {
         for (t = L[s->K].head; t; t = next) {
            next = t->next;
            t->next = NULL;
            H[High(t->K, b)].tail->next = t;
            H[High(t->K, b)].tail = t;
         }
         L[s->K].head = NULL;
      }
   }

   
   head = tail = NULL;
   for (s = Batch; s; s = s->next) {
      p = H[s->K].check;
      if (p < id0 && Hactive[p] == s->K) {
         if (!head)
            head = H[s->K].head;
         else
            tail->next = H[s->K].head;
         tail = H[s->K].tail;
         H[s->K].head = NULL;
      }
   }

   return head;
}

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N,m;
    cin>>N>>m;
    int n=0;
    word x;
    lst head, tail, temp;
    head=NULL;
    vll a(N);
    forn(i,N){
        

	cin>>x;
        a[i]=x;
        n++;
        temp = (lst) malloc(sizeof(struct lstrec));
        temp->K = x;
	

        temp->next = NULL;
        id2(temp, &head, &tail);
    }
if(n!=2&&n!=3){
    head=Sort(head,n,W);
    int i=0;
    for(;head; head=head->next){
	
        a[i++]=head->K;
    }
}else{
    sort(all(a));
}
    

    for(int i =1; i<N; i++)a[i]=a[i]+a[i-1];
    vll ans(N);
    forn(i,m)ans[i]=a[i];
    for(int i=m;i<N;i++)ans[i]=a[i]+ans[i-m];
    for(auto x:ans)cout<<x<<' ';cout<<endl;
	return 0;
}











using namespace std;

using uint = unsigned int;
using uint32 = unsigned int;
using int32 = int;

using int64 = long long;
using uint64 = unsigned long long;


using uint128 = unsigned __int128;
using int128 = __int128;


































    
        
        
    
        

        
            template<typename , int > struct memarray;
            template<class T, int N, 
            typename enable_if<is_trivially_copyable<T>::value, bool>::type>
            struct memqueue;

            

        
        
    



    
    

    
        template<typename T> inline T gcd(T l, T r){return __gcd(l,r);}
        

        template<typename T> inline T lcm(T l, T r){return l/__gcd(l,r)*r;}
        template<typename T> inline int len(const T& t){return t.size();}
        template<typename T, int N> inline int len(T (&t)[N]){return N;}
    
        template<typename T> inline int len(const T& t){return size(t);}
    
    template<typename T> inline T lowbit(T x){ return x&-x; };
    
        inline constexpr int32 bit_length(uint32 x){return 32-__builtin_clz(x|1);}
        inline constexpr int32 bit_length(int32 x){return 32-__builtin_clz(x|1);}
        inline constexpr int32 bit_length(uint64 x){return 64-__builtin_clzll(x|1);}
        inline constexpr int32 bit_length(int64 x){return 64-__builtin_clzll(x|1);}
    
        inline constexpr int32 bit_length(int32 x){return 32-__builtin_clz(x);}    
        inline constexpr int32 bit_length(uint32 x){return 32-__builtin_clz(x);}
        inline constexpr int32 bit_length(int64 x){return 64-__builtin_clzll(x);}
        inline constexpr int32 bit_length(uint64 x){return 64-__builtin_clzll(x);}
    
    
        template<class InputIter, class OutputIter>
        void id0( InputIter first, InputIter last, OutputIter output){
            typename iterator_traits<OutputIter>::value_type cs=0, tmp=0;
            while(first!=last){
                tmp = *first++;
                *output++ = cs;
                cs += tmp;
            }
            *output = cs;
        }

    
        template<class T, class F>
        T id4(T l, T r, F f){
            assert(l<=r);
            while(l<r){
                T m = l+((typename make_unsigned<T>::type)r-l)/2;
                if(f(m)) r = m;
                else l = m+1;
            }
            return l;
        }
        template<class T, class F>
        T id2(T l, T r, F f){
            assert(l<=r);
            while(l<r){
                T m = l+((typename make_unsigned<T>::type)r-l-1)/2;
                if(f(m)) l=m;
                else r=m-1;
            }
            return l;
        }

    
        void id5(int n, int r, function<bool(int const*)> f){
            int ids[r]; 
            bool vis[n]; memset0(vis);
            rep(i,r) ids[i] = i, vis[i] = 1;

            while(1){
                if(!f(ids)) return ;
                int i_last = r-1;
                for(; i_last>=0; i_last--){
                    int last = ids[i_last];
                    vis[last++] = 0;
                    while(last < n and vis[last]) last++;
                    if(last < n){
                        vis[last] = 1;
                        ids[i_last] = last;
                        break;
                    }
                } if(-1==i_last) break;

                i_last ++;
                for(int i=0; i_last<r && i<n ; i++){
                    if(!vis[i]){
                        vis[i] = 1;
                        ids[i_last++] = i;
                    }
                }
            }
        }

        void combinations(int n, int r, function<bool(int const*)> f){
            int ids[r]; rep(i,r) ids[i]=i;
            while(1){
                if(!f(ids)) return ;
                int i_last;for(i_last=r-1;i_last>=0 and ids[i_last]==i_last+n-r;i_last--) ;
                if (-1==i_last) break;
                ids[i_last]++;
                rep(i, i_last+1,r) ids[i]=ids[i-1]+1;
            }
        }

        void product(const vector<int>& args, function<bool(int const*)> f){
            int n = args.size();
            int ids[n]; memset0(ids);
            while(1){
                if(!f(ids)) return ;
                int i_last;for(i_last=n-1;i_last>=0 and ids[i_last]==args[i_last]-1;i_last--) ;
                if(-1==i_last) break;
                ids[i_last] ++;
                rep(i, i_last+1, n) ids[i] =0;
            }
        }




    template<class T, int N = 100010>
    struct memarray {
        
        T A[N];
        typedef memarray<T,N>* iterator;
        int sz = 0;
        memarray(){};
        
        memarray(int n, const T& v=0){  
            
                assert(n<=N);
            

            if(v==0) {
                memset(A, 0, sizeof(T)*n); sz=n;
            } elif (sizeof(T)==1) {
                memset(A, v, n); sz = n;
            } else {
                

                int msb = 1<<19;
                for(;msb;msb>>=1){
                    memcpy(A+sz, A, sz*sizeof(T)); sz <<= 1;
                    if(n&msb) A[sz++] = v;
                }
            } 
        }
        template<typename RIter, 
            enable_if_t<is_same<T, typename iterator_traits<RIter>::value_type>::value, bool> = 0
        >
        memarray(RIter beg, RIter end){
            
            uint32 sz2 = end-beg;
            
                assert(sz2)<=N;
            
            memcpy(A,beg,sz2*sizeof(T));
            sz = sz2;
        }

        memarray(initializer_list<T> L){
            
                assert(L.size()<=N);
            

            for(auto& v: L) A[sz++] = v;
        }

        
        static memarray<T,N> fromrange(int fi, int se) {
            memarray<T,N> self;
            rep(i, fi, se) self.append(i);
        }
        

        memarray(const pair<int,int> &p){ rep(i, p.fi, p.se) A[sz++] = i; }


        int size(){ return sz; }
        T& operator[] (int index) {
            
                if(index< -sz or index>=sz) throw out_of_range("operator[] out of size "s + to_string(N));
            
            
            if(index>=0) return A[index];
            return A[index+sz];
        }
        
        

        template<int N2>
        int id3(const memarray<T, N2> & oth){
            rep(i, min(sz, oth.sz)){
                if(A[i]>oth.A[i]) return 1;
                elif(A[i]<oth.A[i]) return -1;
            }
            if(sz==oth.sz) return 0;
            return (sz<oth.sz) ? -1 : 1;
        }

        template<int N2>
        bool operator== (const memarray<T, N2> & oth) const { return oth.sz == sz and memcmp(oth.A, A, sz)==0; }
        template<int N2> 
        bool operator!= (const memarray<T, N2> & oth) const {return !(oth==*this);}

        T* begin(){return &A[0];}
        T* end(){return &A[sz];}

        void append(const T& v){ 
            
                assert(sz!=N);
            
            A[sz++] = v;}

        T pop() { 
            
                if(sz==0) throw out_of_range(".pop: from empty array");
            
            
            return A[--sz];
        }

        T pop(int index) {
            
                if(0==sz) throw out_of_range(".pop: from empty array");
                elif(index<0 or index>=sz) throw out_of_range(".pop: out of border");
            

            int ret = A[index];
            if(index+1<sz) memmove(A+index, A+index+1, sizeof(T)*(sz-(index+1)));
            sz --;
            return ret;
        }
        
        
        void slice_remove(int l, int r) {
            if(r-l<=0 or r<=0) return;
            if(l<0) l = 0;

            if(r<sz) {
                memmove(A+l, A+r, sizeof(T)*(sz-r)); sz -= r - l;
            } else{
                sz = l;
            }
        }
        
        memarray<T> slice_copy(int l, int r){
            memarray<T, N> res;
            if(r-l<=0 or r<=0) return res;
            if(l<0) l=0;
            
            if(r>sz) r=sz;
            res.sz = r-l;
            memcpy(res.A, A, res.sz);
            return res;
        }

        void insert(int index, const T& v){
            
                if(index>sz) throw out_of_range(".insert: unlike python, `index` should <=`sz`");
            

            memmove(A+index+1, A+index, sizeof(T)*(sz-index)); sz++;
            A[index] = v;
        }

        template<int N2> void operator+= (const memarray<T, N2> & oth){ extend(oth); }
        template<int N2>
        void extend_move(memarray<T, N2>& oth){
            
                assert(oth.sz + sz <= N);
            

            memcpy(A+sz, oth.A, sizeof(T)*oth.sz); sz += oth.sz;
            oth.sz = 0;
        }

        void clear(){ sz = 0;}
        int find(const T& v, int start=0){ return find(v, start, sz);}
        
        int find(const T& v, int start, int stop){
            if(stop-start<=0 or stop<=0) return -1;
            if(start<0) start = 0;

            rep(i, start, stop){ if(A[i] == v) return i;}
            return sz;
        }

        void reverse(){
            for(int i=0,j=sz-1; i<j ;i++,j--){
                swap(A[i], A[j]);
            }
        }
    };

    template<class T, int N = 100010, 
    typename enable_if<is_trivially_copyable<T>::value, bool>::type = 0>
    struct memqueue {
        
        T A[N];
        int l = 0;
        int r = 0;
        memqueue() {}
        memqueue(initializer_list<T> L) {
            
                assert(L.size()<=N);
            

            for(auto& v: L) A[r++] = v;
        }

        template<typename RIter, 
            enable_if_t<is_same<T, typename iterator_traits<RIter>::value_type>::value, bool> = 0
        >
        memqueue(RIter beg, RIter end){
            
            uint sz2 = end-beg;
            
                assert(sz2)<=N;
            
            memcpy(A,beg,sz2*sizeof(T));
            r = sz2;
        }

        int size(){return r-l;}
        int* begin(){return &A[l];}
        int* end(){return &A[r];}
        void clear(){l=r=0;}
        T& operator[] (int index) {
            
                int sz = r-l;
                if(index< -sz or index>=sz) throw out_of_range(".operator[]: `index="s + to_string(121) + "` out of border"s);
            

            if (0<=index) return A[index+l];
            return A[index+r];
            
        }

        void append(const T& v){
            if(r==N) {
                
                    if(l==0) throw out_of_range(".append: queue is full");
                

                memmove(A, A+l, (r-l)*sizeof(T));
                r -= l; l = 0; 
            }
            A[r++] = v;
        }

        T popleft(){
            
                if(l==r) throw out_of_range(".popleft: from empty array");
            

            return A[l++]; 
        }
        
        void rotate(int step=1){
            int sz = r-l;
            step = step%sz; if(step<0) step += sz;
            
            if((sz-step) < 1000 + 0.035*sz){    
                rep(sz-step) append(popleft());
                return;
            }
            
            

            if(step<=sz/2) {
                T buf[step];
                memcpy(buf, A+sz-step, step*sizeof(T));
                memmove(A+step, A, (sz-step)*sizeof(T));
                memcpy(A, buf, step*sizeof(T));
            } 

            else {
                T buf[sz-step];
                memcpy(buf, A, (sz-step)*sizeof(T));
                memmove(A, A+sz-step, step*sizeof(T));
                memcpy(A+step, buf, (sz-step)*sizeof(T));
            }
        }
    };



bool id1 = []() {cin.tie(0)->sync_with_stdio(0);return 0;}();


void print(){ cout << '\n'; }
template<class T> void print(int32* A, T t){ rep(i, t) cout<<A[i]<<' '; cout<<'\n'; }
template<class T> void print(int64* A, T t){ rep(i, t) cout<<A[i]<<' '; cout<<'\n'; }
template<class T, class Al> void print(vector<T, Al>&A){ for(auto v:A) cout<<v<<' '; cout<<'\n'; }
template<class T, class... Args> void print(const T& v, Args... args){cout<<v<< ' ';print(args...);}



const int maxn = 50 + 10;

int n, m; 
int A[maxn];
int s[maxn];

void solve(){
    

    rep(i, m) s[i] = 1;
    rep(i, n){
        

        {
            if((m-A[i]-1<A[i] and s[m-A[i]-1]!=0) or s[A[i]]==0)
                s[m-A[i]-1] = 0;
            else
                s[A[i]] = 0;
        }
    }
    rep(i, m) cout << char('A'+s[i]);
    cout << '\n';
}



int32 main(){
    int __T=1;
    cin>>__T;
    rep(__T){
        cin >> n >> m;
        rep(i, n){
            cin>>A[i];
            A[i]-=1;
        } 
        solve();
        
        
    }
    
} 

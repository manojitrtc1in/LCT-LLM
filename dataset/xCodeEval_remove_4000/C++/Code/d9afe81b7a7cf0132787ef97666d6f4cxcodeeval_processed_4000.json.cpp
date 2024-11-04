
using namespace std;












using ll=long long;using ld=long double;using uint=unsigned int;using ull=unsigned long long;
using pii=pair<int,int>;using pll=pair<ll,ll>;using pill=pair<int,ll>;using plli=pair<ll,int>;using pdd=pair<double,double>;using pld=pair<ld,ld>;
constexpr const char nl='\n',sp=' ';constexpr const int INT_INF=0x3f3f3f3f;constexpr const ll LL_INF=0x3f3f3f3f3f3f3f3f;
constexpr const double D_INF=numeric_limits<double>::infinity();constexpr const ld LD_INF=numeric_limits<ld>::infinity();
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;}template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;}
template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
template<class T,class...Ts>void MIN(T&x,const Ts&...xs){x=_min(x,xs...);}template<class T,class...Ts>void MAX(T&x,const Ts&...xs){x=_max(x,xs...);}
template<class T>constexpr const T&_clamp(const T&v,const T&lo,const T&hi){return v<lo?lo:hi<v?hi:v;}template<class T>void CLAMP(T&v,const T&lo,const T&hi){v=_clamp(v,lo,hi);}
template<class T,class...Args>unique_ptr<T>_make_unique(Args&&...args){return unique_ptr<T>(new T(forward<Args>(args)...));}
template<class T,class...Args>shared_ptr<T>_make_shared(Args&&...args){return shared_ptr<T>(new T(forward<Args>(args)...));}





template<class...Ts>using uset=unordered_set<Ts...>;template<class...Ts>using umap=unordered_map<Ts...>;template<class...Ts>using pq=priority_queue<Ts...>;
template<class T>using minpq=pq<T,vector<T>,greater<T>>;template<class T>using maxpq=pq<T,vector<T>,less<T>>;
template<class T1,class T2,class H1=hash<T1>,class H2=hash<T2>>struct pair_hash{size_t operator()(const pair<T1,T2>&p)const{return 31*H1{}(p.first)+H2{}(p.second);}};
template<class T>struct is_iterator {
    template<class U,typename enable_if<!is_convertible<U,const char*>::value,int>::type=0>constexpr static auto id1(int)->decltype(*declval<U>(),bool()){return true;}
    template<class>constexpr static bool id1(long){return false;}constexpr static bool value=id1<T>(0);
};
seed_seq seq {
    (uint64_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint64_t)__builtin_ia32_rdtsc(),(uint64_t)(uintptr_t)make_unique<char>().get()
};
mt19937 rng(seq);mt19937_64 rng64(seq);

constexpr const int _bufferSize=4096,id0=128;
char _inputBuffer[_bufferSize+1],*_inputPtr=_inputBuffer,_outputBuffer[_bufferSize],_c,_sign,*_tempInputBuf=nullptr,_numBuf[id0],_tempOutputBuf[id0],_fill=' ';
FILE*_input=stdin,*_output=stdout,*_error=stderr;const char*_delimiter=" ";int _cur,_outputPtr=0,_numPtr=0,_precision=6,_width=0,id3=0,_cnt;ull _precisionBase=1000000;














void read(int&x){ri(x);}void read(uint&x){ri(x);}void read(ll&x){ri(x);}void read(ull&x){ri(x);}void read(double&x){rd(x);}void read(ld&x){rld(x);}
void read(char&x){rc(x);}void read(char*x){rcs(x);}void read(string&x){rs(x);}void readln(char*x){rcln(x);}void readln(string&x){rln(x);}
template<class T1,class T2>void read(pair<T1,T2>&x){read(x.first);read(x.second);}template<class T>void read(complex<T>&x){T _re,_im;read(_re);read(_im);x.real(_re);x.imag(_im);}
template<class T>void read(T&x);template<class T,class...Ts>void read(T&x,Ts&&...xs);
template<class It>typename enable_if<is_iterator<It>::value>::type read(It st,It en){for(It _i=st;_i!=en;_i++)read(*_i);}
template<class It,class...Ts>typename enable_if<is_iterator<It>::value>::type read(It st,It en,Ts&&...xs){read(st,en);read(forward<Ts>(xs)...);}
template<class T>void read(T&x){for(auto&&_i:x)read(_i);}template<class T,class...Ts>void read(T&x,Ts&&...xs){read(x);read(forward<Ts>(xs)...);}
bool hasNext(){while(_hasNext()&&_peekchar()<=' ')_getchar();return _hasNext();}
void setInput(FILE*file){*_inputPtr='\0';_input=file;}void setInput(const char*s){*_inputPtr='\0';_input=fopen(s,"r");}void setInput(const string&s){*_inputPtr='\0';_input=fopen(s.c_str(),"r");}























void writeDelimiter(){for(const char*_p=_delimiter;*_p;_putchar(*_p++));}
void write(const bool&x){wb(x);}void write(const int&x){wi(x);}void write(const uint&x){wi(x);}void write(const ll&x){wll(x);}void write(const ull&x){wll(x);}
void write(const double&x){wd(x);}void write(const ld&x){wld(x);}void write(const char&x){wc(x);}void write(const char*x){wcs(x);}void write(const string&x){ws(x);}
template<class T1,class T2>void write(const pair<T1,T2>&x){write(x.first);writeDelimiter();write(x.second);}
template<class T>void write(const complex<T>&x){write(x.real());writeDelimiter();write(x.imag());}
template<class T>void write(const T&x);template<class T,class...Ts>void write(const T&x,Ts&&...xs);
template<class It>typename enable_if<is_iterator<It>::value>::type write(It st,It en){bool _first=1;for(It _i=st;_i!=en;_i++){if(_first)_first=0;else writeDelimiter();write(*_i);}}
template<class It,class...Ts>typename enable_if<is_iterator<It>::value>::type write(It st,It en,Ts&&...xs){write(st,en);writeDelimiter();write(forward<Ts>(xs)...);}
template<class T>void write(const T&x){bool _first=1;for(auto&&_i:x){if(_first)_first=0;else writeDelimiter();write(_i);}}
template<class T,class...Ts>void write(const T&x,Ts&&...xs){write(x);writeDelimiter();write(forward<Ts>(xs)...);}
void writeln(){_putchar('\n');}template<class...Ts>void writeln(Ts&&...xs){write(forward<Ts>(xs)...);_putchar('\n');}
void flush(){_flush();}class IOManager{public:~IOManager(){flush();if(_tempInputBuf)delete[](_tempInputBuf);}};unique_ptr<IOManager>id2=make_unique<IOManager>();
void setOutput(FILE*file){flush();_output=file;}void setOutput(const char*s){flush();_output=fopen(s,"w");}void setOutput(const string&s){flush();_output=fopen(s.c_str(),"w");}
template<class...Ts>void debug(const Ts&...xs){FILE*_temp=_output;setOutput(_error);write(xs...);setOutput(_temp);}
template<class...Ts>void debugln(const Ts&...xs){FILE*_temp=_output;setOutput(_error);writeln(xs...);setOutput(_temp);}
void setError(FILE*file){flush();_error=file;}void setError(const char*s){flush();_error=fopen(s,"w");}void setError(const string&s){flush();_error=fopen(s.c_str(),"w");}

const int MAXS = 1e6 + 5;

int T, MAP[26], REV[26], tempMAP[26], tempREV[26];

void solve() {
    int N, K;
    string S, A, B;
    read(K, S, A, B);
    N = sz(S);
    fill(MAP, MAP + K, -1);
    fill(REV, REV + K, -1);
    if (A > B) {
        writeln("NO");
        return;
    }
    FOR(i, N) {
        if (A[i] == B[i]) {
            if (MAP[S[i] - 'a'] == -1) {
                MAP[S[i] - 'a'] = A[i] - 'a';
                if (REV[A[i] - 'a'] != -1) {
                    writeln("NO");
                    return;
                } else REV[A[i] - 'a'] = S[i] - 'a';
            } else if (MAP[S[i] - 'a'] != A[i] - 'a') {
                writeln("NO");
                return;
            }
        } else {
            bool found = true;
            if (MAP[S[i] - 'a'] != -1) {
                if (A[i] - 'a' > MAP[S[i] - 'a'] || MAP[S[i] - 'a'] > B[i] - 'a') {
                    writeln("NO");
                    return;
                }
            }
            int lb = MAP[S[i] - 'a'] == -1 ? A[i] - 'a' : MAP[S[i] - 'a'];
            int ub = MAP[S[i] - 'a'] == -1 ? B[i] - 'a' : MAP[S[i] - 'a'];
            For(j, lb, ub + 1) {
                FOR(k, K) {
                    tempMAP[k] = MAP[k];
                    tempREV[k] = REV[k];
                }
                if (REV[j] != -1 && MAP[S[i] - 'a'] == -1) continue;
                else if (MAP[S[i] - 'a'] == -1) {
                    MAP[S[i] - 'a'] = j;
                    REV[j] = S[i] - 'a';
                }
                if (j == A[i] - 'a') {
                    bool done = true;
                    For(k, i + 1, N) {
                        if (MAP[S[k] - 'a'] != -1) {
                            if (A[k] - 'a' > MAP[S[k] - 'a']) {
                                done = false;
                                break;
                            } else if (A[k] - 'a' < MAP[S[k] - 'a']) break;
                        } else {
                            bool good = false;
                            For(m, A[k] - 'a' + 1, K) {
                                if (REV[m] == -1) {
                                    MAP[S[k] - 'a'] = m;
                                    REV[m] = S[k] - 'a';
                                    good = true;
                                    break;
                                }
                            }
                            if (good) break;
                            if (REV[A[k] - 'a'] != -1) {
                                if (REV[A[k] - 'a'] != S[k] - 'a') {
                                    done = false;
                                    break;
                                }
                            } else {
                                MAP[S[k] - 'a'] = A[k] - 'a';
                                REV[A[k] - 'a'] = S[k] - 'a';
                            }
                        }
                    }
                    if (done) break;
                } else if (j == B[i] - 'a') {
                    bool done = true;
                    For(k, i + 1, N) {
                        if (MAP[S[k] - 'a'] != -1) {
                            if (MAP[S[k] - 'a'] > B[k] - 'a') {
                                done = false;
                                break;
                            } else if (MAP[S[k] - 'a'] < B[k] - 'a') break;
                        } else {
                            bool good = false;
                            REV(m, B[k] - 'a' - 1) {
                                if (REV[m] == -1) {
                                    MAP[S[k] - 'a'] = m;
                                    REV[m] = S[k] - 'a';
                                    good = true;
                                    break;
                                }
                            }
                            if (good) {
                                done = true;
                                break;
                            }
                            if (REV[B[k] - 'a'] != -1) {
                                if (REV[B[k] - 'a'] != S[k] - 'a') {
                                    done = false;
                                    break;
                                }
                            } else {
                                MAP[S[k] - 'a'] = B[k] - 'a';
                                REV[B[k] - 'a'] = S[k] - 'a';    
                            }
                        }
                    }
                    if (done) break;
                } else {
                    break;
                }
                FOR(k, K) {
                    MAP[k] = tempMAP[k];
                    REV[k] = tempREV[k];
                }
                if (j == ub) found = false;
            }
            if (found) break;
            else {
                writeln("NO");
                return;
            }
        }
    }
    string ans = "";
    queue<int> avail;
    FOR(i, K) if (REV[i] == -1) avail.push(i);
    FOR(i, K) {
        if (MAP[i] == -1) {
            assert(!avail.empty());
            MAP[i] = avail.front();
            avail.pop();
        }
        ans.pb('a' + MAP[i]);
    }
    assert(avail.empty());
    string U;
    FOR(i, N) U.pb(MAP[S[i] - 'a'] + 'a');
    if (A > U || U > B) {
        writeln("NO");
        return;
    }
    writeln("YES");
    writeln(ans);
}

int main() {
    

    

    

    setLength(MAXS);
    read(T);
    FOR(t, T) solve();
    return 0;
}

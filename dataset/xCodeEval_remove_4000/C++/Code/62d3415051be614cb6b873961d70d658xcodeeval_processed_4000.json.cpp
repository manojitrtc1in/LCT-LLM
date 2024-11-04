









using namespace std;




class IO{static const int bufSize=1<<18;char inBuf[bufSize],outBuf[bufSize];char*ip1=inBuf,*ip2=inBuf;int ok=1,op1=-1,op2=bufSize-1;
TP <TN T>FI void __RI(T&x){int ch=gc(),neg=1;x=0;for(;!(ch==EOF||isdigit(ch)||ch=='-');ch=gc());if(ch==EOF){ok=0;return;}if(ch=='-')neg=-1,ch=gc();for(;isdigit(ch);ch=gc())x=x*10+(ch-48)*neg;}
TP <TN T>FI void __RC(T&x){unsigned char ch;while(isspace(ch=gc()));if(ch==EOF){ok=0;return;}x=ch;}FI void __RS(string&x){char ch;x.clear();for(ch=gc();isspace(ch);ch=gc());if(ch==EOF){ok=0;return;}for(;!isspace(ch);ch=gc())x.push_back(ch);}
public:
FI int gc(){return ip1==ip2 &&(ip2 =(ip1=inBuf)+fread(inBuf,1,bufSize,stdin),ip1==ip2)?EOF:*ip1++;}
FI IO&R(char&x){__RC(x);return TS;}FI IO& R(unsigned char&x){__RC(x);return TS;}FI IO&R(string&x){__RS(x);return TS;}TP<TN T1,TN T2>FI IO&R(pair<T1,T2>&x){R(x.first),R(x.second);return TS;}TP<TN T>FI IO&R(vector<T>&x){for(auto &i:x)R(i);return TS;}
TP <TN T,TN...Args>FI IO&RA(T*a,int n){for(int i=0;i<n;++i)R(a[i]);return TS;}TP<TN T,TN...Args>FI IO&R(T&x,Args&...args){R(x),R(args...);return TS;}
TP <TN T,TN...Args>FI IO&RA(T*a,int n,Args...args){for(int i=0;i<n;++i)RA(a[i],args...);return TS;}TP<TN T>FI IO&R(T&x){static_assert(is_integral<T>::value,"Unsupported types");if(is_integral<T>::value)__RI(x);return TS;}
private:
char space=' ';TP<TN T>FI void __WI(T x){static char buf[64];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while(x);}else{pc('-');do{buf[++len]=-(x%10)+48,x/=10;}while(x);}while(len>=0){pc(buf[len]),--len;}}
public:
FI void pc(const char&x){if(op1==op2)flush();outBuf[++op1]=x;}
FI void flush(){fwrite(outBuf,1,op1+1,stdout),op1=-1;}FI IO&W(const char&x){pc(x);return TS;}FI IO&W(const char*x){while(*x!='\0')pc(*(x++));return TS;}FI IO&W(const string&x){W(x.c_str());return TS;}
TP<TN T>FI IO& W(const vector<T>&x){for(auto&i:x)WS(i);WL();return TS;}FI IO&WL(){W('\n');return TS;}TP<TN T1,TN T2>FI IO& W(const pair<T1,T2>&x){WS(x.first),W(x.second);return TS;}
TP<TN T>FI IO& WL(const T&x){W(x),W('\n');return TS;}FI IO&WS(){W(' ');return TS;}TP<TN T>FI IO& WS(const T&x){W(x),W(space);return TS;}
TP<TN T>FI IO& WA(T* a,int n){for(int i=0;i<n;i++)WS(a[i]);WL();return TS;}TP<TN T,TN...Args>FI IO& W(const T&x,const Args&...args){W(x),W(space),W(args...);return TS;}
TP<TN...Args>FI IO& WL(const Args&...args){W(args...),W('\n');return TS;}TP<TN T,TN...Args>FI IO& WA(T* a,int n,Args...args){for(int i=0;i<n;i++)WA(a[i],args...);return TS;}
TP<TN T>FI IO& W(const T&x){static_assert(is_integral<T>::value,"Unsupported types");if(is_integral<T>::value)__WI(x);return TS;}
TP<TN T>FI IO&operator>>(T&x){R(x);return TS;}TP<TN T>FI IO&operator<<(const T&x){W(x);return TS;}bool good(){return ok;}IO(){}~IO(){flush();}}io;






const int32_t INF=0x3f3f3f3f;
const int64_t INFL=0x3f3f3f3f3f3f3f3fLL;

int same(char x, char y)
{
    return (x == '(' && y == ')') || (x == '{' && y == '}')
        || (x == '<' && y == '>') || (x == '[' && y == ']');
}
int main()
{
    string s;
    io >> s;
    stack<char> st;
    int ans = 0;
    for (auto c : s) {
        if (c == '(' || c == '{' || c == '<' || c == '[')
            st.push(c);
        else {
            if (st.empty()) return io.WL("Impossible"), 0;
            ans += 1 - same(st.top(), c);
            st.pop();
        }
    }
    if (!st.empty()) return io.WL("Impossible"), 0;
    io.WL(ans);
    return 0;
}
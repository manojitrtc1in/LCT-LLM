


using namespace std;

int prime[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 
61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149,
 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233,
  239, 241, 251, 257, 263, 269, 271, 277, 281, 283};
  












using namespace std;




typedef int id2[MAX+1];

int read(id2 a,istream& is=cin){
    char buf[MAX*DIGIT+1],ch;
    int i,j;
    memset((void*)a,0,sizeof(id2));
    if (!(is>>buf)) return 0;
    for (a[0]=strlen(buf),i=a[0]/2-1;i>=0;i--)
        ch=buf[i],buf[i]=buf[a[0]-1-i],buf[a[0]-1-i]=ch;
    for (a[0]=(a[0]+DIGIT-1)/DIGIT,j=strlen(buf);j<a[0]*DIGIT;buf[j++]='0');
    for (i=1;i<=a[0];i++)
        for (a[i]=0,j=0;j<DIGIT;j++)
            a[i]=a[i]*10+buf[i*DIGIT-1-j]-'0';
    for (;!a[a[0]]&&a[0]>1;a[0]--);
    return 1;
}

void write(const id2 a,ostream& os=cout){
    int i,j;
    for (os<<a[i=a[0]],i--;i;i--)
        for (j=DEPTH/10;j;j/=10)
            os<<a[i]/j%10;
}

int comp(const id2 a,const id2 b){
    int i;
    if (a[0]!=b[0])
        return a[0]-b[0];
    for (i=a[0];i;i--)
        if (a[i]!=b[i])
            return a[i]-b[i];
    return 0;
}

int comp(const id2 a,const int b){
    int c[12]={1};
    for (c[1]=b;c[c[0]]>=DEPTH;c[c[0]+1]=c[c[0]]/DEPTH,c[c[0]]%=DEPTH,c[0]++);
    return comp(a,c);
}

int comp(const id2 a,const int c,const int d,const id2 b){
    int i,t=0,O=-DEPTH*2;
    if (b[0]-a[0]<d&&c)
        return 1;
    for (i=b[0];i>d;i--){
        t=t*DEPTH+a[i-d]*c-b[i];
        if (t>0) return 1;
        if (t<O) return 0;
    }
    for (i=d;i;i--){
        t=t*DEPTH-b[i];
        if (t>0) return 1;
        if (t<O) return 0;
    }
    return t>0;
}

void add(id2 a,const id2 b){
    int i;
    for (i=1;i<=b[0];i++)
        if ((a[i]+=b[i])>=DEPTH)
            a[i]-=DEPTH,a[i+1]++;
    if (b[0]>=a[0])
        a[0]=b[0];
    else
        for (;a[i]>=DEPTH&&i<a[0];a[i]-=DEPTH,i++,a[i]++);
    a[0]+=(a[a[0]+1]>0);
}

void add(id2 a,const int b){
    int i=1;
    for (a[1]+=b;a[i]>=DEPTH&&i<a[0];a[i+1]+=a[i]/DEPTH,a[i]%=DEPTH,i++);
    for (;a[a[0]]>=DEPTH;a[a[0]+1]=a[a[0]]/DEPTH,a[a[0]]%=DEPTH,a[0]++);
}

void sub(id2 a,const id2 b){
    int i;
    for (i=1;i<=b[0];i++)
        if ((a[i]-=b[i])<0)
            a[i+1]--,a[i]+=DEPTH;
    for (;a[i]<0;a[i]+=DEPTH,i++,a[i]--);
    for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void sub(id2 a,const int b){
    int i=1;
    for (a[1]-=b;a[i]<0;a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH,i++);
    for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void sub(id2 a,const id2 b,const int c,const int d){
    int i,O=b[0]+d;
    for (i=1+d;i<=O;i++)
        if ((a[i]-=b[i-d]*c)<0)
            a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH;
    for (;a[i]<0;a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH,i++);
    for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void mul(id2 c,const id2 a,const id2 b){
    int i,j;
    memset((void*)c,0,sizeof(id2));
    for (c[0]=a[0]+b[0]-1,i=1;i<=a[0];i++)
        for (j=1;j<=b[0];j++)
            if ((c[i+j-1]+=a[i]*b[j])>=DEPTH)
                c[i+j]+=c[i+j-1]/DEPTH,c[i+j-1]%=DEPTH;
    for (c[0]+=(c[c[0]+1]>0);!c[c[0]]&&c[0]>1;c[0]--);
}

void mul(id2 a,const int b){
    int i;
    for (a[1]*=b,i=2;i<=a[0];i++){
        a[i]*=b;
        if (a[i-1]>=DEPTH)
            a[i]+=a[i-1]/DEPTH,a[i-1]%=DEPTH;
    }
    for (;a[a[0]]>=DEPTH;a[a[0]+1]=a[a[0]]/DEPTH,a[a[0]]%=DEPTH,a[0]++);
    for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void mul(id2 b,const id2 a,const int c,const int d){
    int i;
    memset((void*)b,0,sizeof(id2));
    for (b[0]=a[0]+d,i=d+1;i<=b[0];i++)
        if ((b[i]+=a[i-d]*c)>=DEPTH)
            b[i+1]+=b[i]/DEPTH,b[i]%=DEPTH;
    for (;b[b[0]+1];b[0]++,b[b[0]+1]=b[b[0]]/DEPTH,b[b[0]]%=DEPTH);
    for (;!b[b[0]]&&b[0]>1;b[0]--);
}

void div(id2 c,id2 a,const id2 b){
    int h,l,m,i;
    memset((void*)c,0,sizeof(id2));
    c[0]=(b[0]<a[0]+1)?(a[0]-b[0]+2):1;
    for (i=c[0];i;sub(a,b,c[i]=m,i-1),i--)
        for (h=DEPTH-1,l=0,m=(h+l+1)>>1;h>l;m=(h+l+1)>>1)
            if (comp(b,m,i-1,a)) h=m-1;
            else l=m;
    for (;!c[c[0]]&&c[0]>1;c[0]--);
    c[0]=c[0]>1?c[0]:1;
}

void div(id2 a,const int b,int& c){
    int i;
    for (c=0,i=a[0];i;c=c*DEPTH+a[i],a[i]=c/b,c%=b,i--);
    for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void sqrt(id2 b,id2 a){
    int h,l,m,i;
    memset((void*)b,0,sizeof(id2));
    for (i=b[0]=(a[0]+1)>>1;i;sub(a,b,m,i-1),b[i]+=m,i--)
        for (h=DEPTH-1,l=0,b[i]=m=(h+l+1)>>1;h>l;b[i]=m=(h+l+1)>>1)
            if (comp(b,m,i-1,a)) h=m-1;
            else l=m;
    for (;!b[b[0]]&&b[0]>1;b[0]--);
    for (i=1;i<=b[0];b[i++]>>=1);
}

int length(const id2 a){
    int t,ret;
    for (ret=(a[0]-1)*DIGIT,t=a[a[0]];t;t/=10,ret++);
    return ret>0?ret:1;
}

int digit(const id2 a,const int b){
    int i,ret;
    for (ret=a[(b-1)/DIGIT+1],i=(b-1)%DIGIT;i;ret/=10,i--);
    return ret%10;
}

int id1(const id2 a){
    int ret,t;
    for (ret=0;!a[ret+1];ret++);
    for (t=a[ret+1],ret*=DIGIT;!(t%10);t/=10,ret++);
    return ret;
}

void comp(int* a,const int l,const int h,const int d){
    int i,j,t;
    for (i=l;i<=h;i++)
        for (t=i,j=2;t>1;j++)
            while (!(t%j))
                a[j]+=d,t/=j;
}

void convert(int* a,const int h,id2 b){
    int i,j,t=1;
    memset(b,0,sizeof(id2));
    for (b[0]=b[1]=1,i=2;i<=h;i++)
        if (a[i])
            for (j=a[i];j;t*=i,j--)
                if (t*i>DEPTH)
                    mul(b,t),t=1;
    mul(b,t);
}

void combination(id2 a,int m,int n){
    int* t=new int[m+1];
    memset((void*)t,0,sizeof(int)*(m+1));
    comp(t,n+1,m,1);
    comp(t,2,m-n,-1);
    convert(t,m,a);
    delete []t;
}

void permutation(id2 a,int m,int n){
    int i,t=1;
    memset(a,0,sizeof(id2));
    a[0]=a[1]=1;
    for (i=m-n+1;i<=m;t*=i++)
        if (t*i>DEPTH)
            mul(a,t),t=1;
    mul(a,t);
}




int read(id2 a,int &sgn,istream& is=cin){
    char str[MAX*DIGIT+2],ch,*buf;
    int i,j;
    memset((void*)a,0,sizeof(id2));
    if (!(is>>str)) return 0;
    buf=str,sgn=1;
    if (*buf=='-') sgn=-1,buf++;
    for (a[0]=strlen(buf),i=a[0]/2-1;i>=0;i--)
        ch=buf[i],buf[i]=buf[a[0]-1-i],buf[a[0]-1-i]=ch;
    for (a[0]=(a[0]+DIGIT-1)/DIGIT,j=strlen(buf);j<a[0]*DIGIT;buf[j++]='0');
    for (i=1;i<=a[0];i++)
        for (a[i]=0,j=0;j<DIGIT;j++)
            a[i]=a[i]*10+buf[i*DIGIT-1-j]-'0';
    for (;!a[a[0]]&&a[0]>1;a[0]--);
    if (a[0]==1&&!a[1]) sgn=0;
    return 1;
}

struct id0{
    id2 num;
    int sgn;
public:
inline id0(){memset(num,0,sizeof(id2));num[0]=1;sgn=0;}
inline int operator!(){return num[0]==1&&!num[1];}
inline id0& operator=(const id0& a){memcpy(num,a.num,sizeof(id2));sgn=a.sgn;return *this;}
inline id0& operator=(const int a){memset(num,0,sizeof(id2));num[0]=1;sgn=SGN(a);add(num,sgn*a);return *this;};
inline id0& operator+=(const id0& a){if(sgn==a.sgn)add(num,a.num);else if(sgn&&a.sgn){int ret=comp(num,a.num);if(ret>0)sub(num,a.num);else if(ret<0){id2 t;
    memcpy(t,num,sizeof(id2));memcpy(num,a.num,sizeof(id2));sub(num,t);sgn=a.sgn;}else memset(num,0,sizeof(id2)),num[0]=1,sgn=0;}else if(!sgn)memcpy(num,a.num,sizeof(id2)),sgn=a.sgn;return *this;}
inline id0& operator+=(const int a){if(sgn*a>0)add(num,ABS(a));else if(sgn&&a){int ret=comp(num,ABS(a));if(ret>0)sub(num,ABS(a));else if(ret<0){id2 t;
    memcpy(t,num,sizeof(id2));memset(num,0,sizeof(id2));num[0]=1;add(num,ABS(a));sgn=-sgn;sub(num,t);}else memset(num,0,sizeof(id2)),num[0]=1,sgn=0;}else if(!sgn)sgn=SGN(a),add(num,ABS(a));return *this;}
inline id0 operator+(const id0& a){id0 ret;memcpy(ret.num,num,sizeof(id2));ret.sgn=sgn;ret+=a;return ret;}
inline id0 operator+(const int a){id0 ret;memcpy(ret.num,num,sizeof(id2));ret.sgn=sgn;ret+=a;return ret;}
inline id0& operator-=(const id0& a){if(sgn*a.sgn<0)add(num,a.num);else if(sgn&&a.sgn){int ret=comp(num,a.num);if(ret>0)sub(num,a.num);else if(ret<0){id2 t;
    memcpy(t,num,sizeof(id2));memcpy(num,a.num,sizeof(id2));sub(num,t);sgn=-sgn;}else memset(num,0,sizeof(id2)),num[0]=1,sgn=0;}else if(!sgn)add(num,a.num),sgn=-a.sgn;return *this;}
inline id0& operator-=(const int a){if(sgn*a<0)add(num,ABS(a));else if(sgn&&a){int ret=comp(num,ABS(a));if(ret>0)sub(num,ABS(a));else if(ret<0){id2 t;
    memcpy(t,num,sizeof(id2));memset(num,0,sizeof(id2));num[0]=1;add(num,ABS(a));sub(num,t);sgn=-sgn;}else memset(num,0,sizeof(id2)),num[0]=1,sgn=0;}else if(!sgn)sgn=-SGN(a),add(num,ABS(a));return *this;}
inline id0 operator-(const id0& a){id0 ret;memcpy(ret.num,num,sizeof(id2));ret.sgn=sgn;ret-=a;return ret;}
inline id0 operator-(const int a){id0 ret;memcpy(ret.num,num,sizeof(id2));ret.sgn=sgn;ret-=a;return ret;}
inline id0& operator*=(const id0& a){id2 t;mul(t,num,a.num);memcpy(num,t,sizeof(id2));sgn*=a.sgn;return *this;}
inline id0& operator*=(const int a){mul(num,ABS(a));sgn*=SGN(a);return *this;}
inline id0 operator*(const id0& a){id0 ret;mul(ret.num,num,a.num);ret.sgn=sgn*a.sgn;return ret;}
inline id0 operator*(const int a){id0 ret;memcpy(ret.num,num,sizeof(id2));mul(ret.num,ABS(a));ret.sgn=sgn*SGN(a);return ret;}
inline id0& operator/=(const id0& a){id2 t;div(t,num,a.num);memcpy(num,t,sizeof(id2));sgn=(num[0]==1&&!num[1])?0:sgn*a.sgn;return *this;}
inline id0& operator/=(const int a){int t;div(num,ABS(a),t);sgn=(num[0]==1&&!num[1])?0:sgn*SGN(a);return *this;}
inline id0 operator/(const id0& a){id0 ret;id2 t;memcpy(t,num,sizeof(id2));div(ret.num,t,a.num);ret.sgn=(ret.num[0]==1&&!ret.num[1])?0:sgn*a.sgn;return ret;}
inline id0 operator/(const int a){id0 ret;int t;memcpy(ret.num,num,sizeof(id2));div(ret.num,ABS(a),t);ret.sgn=(ret.num[0]==1&&!ret.num[1])?0:sgn*SGN(a);return ret;}
inline id0& operator%=(const id0& a){id2 t;div(t,num,a.num);if (num[0]==1&&!num[1])sgn=0;return *this;}
inline int operator%=(const int a){int t;div(num,ABS(a),t);memset(num,0,sizeof(id2));num[0]=1;add(num,t);return t;}
inline id0 operator%(const id0& a){id0 ret;id2 t;memcpy(ret.num,num,sizeof(id2));div(t,ret.num,a.num);ret.sgn=(ret.num[0]==1&&!ret.num[1])?0:sgn;return ret;}
inline int operator%(const int a){id0 ret;int t;memcpy(ret.num,num,sizeof(id2));div(ret.num,ABS(a),t);memset(ret.num,0,sizeof(id2));ret.num[0]=1;add(ret.num,t);return t;}
inline id0& operator++(){*this+=1;return *this;}
inline id0& operator--(){*this-=1;return *this;};
inline int operator>(const id0& a){return sgn>0?(a.sgn>0?comp(num,a.num)>0:1):(sgn<0?(a.sgn<0?comp(num,a.num)<0:0):a.sgn<0);}
inline int operator>(const int a){return sgn>0?(a>0?comp(num,a)>0:1):(sgn<0?(a<0?comp(num,-a)<0:0):a<0);}
inline int operator>=(const id0& a){return sgn>0?(a.sgn>0?comp(num,a.num)>=0:1):(sgn<0?(a.sgn<0?comp(num,a.num)<=0:0):a.sgn<=0);}
inline int operator>=(const int a){return sgn>0?(a>0?comp(num,a)>=0:1):(sgn<0?(a<0?comp(num,-a)<=0:0):a<=0);}
inline bool operator<(const id0& a)const{return sgn<0?(a.sgn<0?comp(num,a.num)>0:1):(sgn>0?(a.sgn>0?comp(num,a.num)<0:0):a.sgn>0);}
inline int operator<(const int a){return sgn<0?(a<0?comp(num,-a)>0:1):(sgn>0?(a>0?comp(num,a)<0:0):a>0);}
inline int operator<=(const id0& a){return sgn<0?(a.sgn<0?comp(num,a.num)>=0:1):(sgn>0?(a.sgn>0?comp(num,a.num)<=0:0):a.sgn>=0);}
inline int operator<=(const int a){return sgn<0?(a<0?comp(num,-a)>=0:1):(sgn>0?(a>0?comp(num,a)<=0:0):a>=0);}
inline int operator==(const id0& a){return (sgn==a.sgn)?!comp(num,a.num):0;}
inline int operator==(const int a){return (sgn*a>=0)?!comp(num,ABS(a)):0;}
inline int operator!=(const id0& a){return (sgn==a.sgn)?comp(num,a.num):1;}
inline int operator!=(const int a){return (sgn*a>=0)?comp(num,ABS(a)):1;}
inline int operator[](const int a){return digit(num,a);}
friend inline istream& operator>>(istream& is,id0& a){read(a.num,a.sgn,is);return is;}
friend inline ostream& operator<<(ostream& os,const id0& a){if(a.sgn<0)os<<'-';write(a.num,os);return os;}
friend inline id0 sqrt(const id0& a){id0 ret;id2 t;memcpy(t,a.num,sizeof(id2));sqrt(ret.num,t);ret.sgn=ret.num[0]!=1||ret.num[1];return ret;}
friend inline id0 sqrt(const id0& a,id0& b){id0 ret;memcpy(b.num,a.num,sizeof(id2));sqrt(ret.num,b.num);ret.sgn=ret.num[0]!=1||ret.num[1];b.sgn=b.num[0]!=1||ret.num[1];return ret;}
inline int length(){return ::length(num);}
inline int id1(){return ::id1(num);}
inline id0 C(const int m,const int n){combination(num,m,n);sgn=1;return *this;}
inline id0 P(const int m,const int n){permutation(num,m,n);sgn=1;return *this;}
};

id0 f[60];

int main() {
    int i, j, k;
    int n;
    f[1] = 2;   
    for (i=2; i<60; ++i) f[i] = f[i-1] * prime[i];
    scanf("%d", &n);
    if (n == 2) puts("-1");
    else for (i=1; i<=n; ++i) cout << f[n] / prime[n-i+1] << endl;
    return 0;
}
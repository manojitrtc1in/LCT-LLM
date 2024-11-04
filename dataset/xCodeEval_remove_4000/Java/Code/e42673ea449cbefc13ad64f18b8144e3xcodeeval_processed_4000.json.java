import javax.print.attribute.standard.PrinterMessageFromOperator;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
public class Main {
    public static void main(String[] args) throws Exception {
        new Main().run();}



















































































































































































































































































































































































































    static long mul(long a, long b, long p)
    {
        long res=0,base=a;
        while(b>0)
        {
            if((b&1L)>0)
                res=(res+base)%p;
            base=(base+base)%p;
            b>>=1;
        }
        return res;
    }

    static long mod_pow(long k,long n,long p){
        long res = 1L;
        long temp = k;
        while(n!=0L){
            if((n&1L)==1L){
                res = (res*temp)%p;
            }
            temp = (temp*temp)%p;
            n = n>>1L;
        }
        return res%p;
    }
    int ct = 0;
    int f[]  =new int[200001];
    int b[]  =new int[200001];
    int str[]  =new int[200001];

    void go(int rt,List<Integer> g[]){
        str[ct] = rt;
        f[rt] = ct;
        for(int cd:g[rt]){
            ct++;
            go(cd,g);
        }
        b[rt] = ct;
    }
    int add =0;

    void sort(long a[]) {
        Random rd = new Random();
        for (int i = 1; i < a.length; ++i) {
            int p = rd.nextInt(i); long x = a[p]; a[p] = a[i]; a[i] = x;
        }
        Arrays.sort(a);
    }

    void dfs(int from,int k){

    }
    void add(int u,int v,int w){
        to[ct] = v;
        wt[ct] = w;
        ne[ct] = h[u];
        h[u] = ct++;
    }
    int r =0;
    void dfs1(int c,int ff){
        clr[c][aa[c]]++;
        for(int j=h[c];j!=-1;j=ne[j]){
            if(to[j]==ff) continue;
            dfs1(to[j],c);
            clr[c][1] += clr[to[j]][1];
            clr[c][2] += clr[to[j]][2];
            if(clr[to[j]][1]==s1&&clr[to[j]][2]==0||clr[to[j]][2]==s2&&clr[to[j]][1]==0){
                r++;
            }
        }
    }

    int[] h,ne,to,fa1,wt;
    int clr[][];
    int aa[];
    int s1 = 0;
    int s2 = 0;

    boolean f(int n){
        int c = 0;
        while(n>0){
            c += n%10;
            n /=10;
        }
        return (c&3)==0;
    }

    int[][] next(String s){
        int len = s.length();
        int ne[][] = new int[len+1][26];
        Arrays.fill(ne[len], -1);
        for(int i=len-1;i>=0;--i){
            ne[i] = ne[i+1].clone();
            ne[i][s.charAt(i)-'a'] = i+1;
        }
        return ne;
    }


    void sort(int a[]){
        Random rd =new Random();
        for(int i=1;i<a.length;++i){
            int id = rd.nextInt(i);
            int t = a[id];
            a[id] = a[i];
            a[i] = t;
        }
    }

    boolean same(String s){
        return s.charAt(0)==s.charAt(1);
    }
    boolean next_perm(int[] a){
        int len = a.length;
        for(int i=len-2,j = 0;i>=0;--i){
            if(a[i]<a[i+1]){
                j = len-1;
                for(;a[j]<=a[i];--j);
                int p = a[j];
                a[j] = a[i];
                a[i] = p;
                j = i+1;
                for(int ed = len-1;j<ed;--ed) {
                    p = a[ed];
                    a[ed] = a[j];
                    a[j++] = p;
                }
                return true;
            }
        }
        return false;
    }

    void print1(int c[],int n){
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<n;++i){
            for(int j=0;j<3;++j) {
                sb.appendCodePoint(c[j]+'a');
            }
        }
        println(sb);
    }
    void print2(int c[],int n){
        StringBuilder sb = new StringBuilder();
        for(int j=0;j<3;++j) {
            for (int i = 0; i < n; ++i) {
                sb.appendCodePoint(c[j]+'a');
            }
        }
        println(sb);
    }


    int[] dp(int a[][],int ck){
        left = new int[n+1][m+1];
        right = new int[n+1][m+1];
        up = new int[n+1][m+1];

        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(a[i][j]==ck){
                    left[i][j] = right[i][j] = j;
                    up[i][j] = 1;
                }
            }
        }

        for(int i=1;i<=n;++i){
            for(int j=2;j<=m;++j){
                if(a[i][j]==ck&&ck==a[i][j-1]) {
                    left[i][j] = left[i][j-1];
                }
            }
        }

        for(int i=1;i<=n;++i){
            for(int j=m-1;j>=1;--j){
                if(a[i][j]==ck&&ck==a[i][j+1]) {
                    right[i][j] = right[i][j+1];
                }
            }
        }















        int all1 = 0;
        int all2 = 0;

        for(int i=1;i<=n;++i) {
            for (int j = 1; j <= m; ++j) {
                if(i>=2&&a[i][j]==ck&&ck==a[i-1][j]) {
                    up[i][j] = up[i-1][j] + 1;
                    left[i][j] = Math.max(left[i-1][j] ,left[i][j]);
                    right[i][j] = Math.min(right[i-1][j] ,right[i][j]);
                }
                if(a[i][j]==ck) {
                    int s2 = up[i][j] * (right[i][j] - left[i][j] + 1);
                    int u = Math.min(up[i][j], right[i][j] - left[i][j] + 1);
                    if (all2 < s2) {
                        all2 = s2;
                    }
                    if (all1 < u*u ) {
                        all1 = u*u;
                    }
                }
            }
        }

        return new int[]{all1,all2};




    }
    int up[][],right[][],left[][];

    int n;int m;
    void solve() {


        n  =ni();
        int a[] = na(n);
        Map<Integer,Integer> right = new HashMap<>();
        for(int i=0;i<n;++i){
            right.put(a[i],i);
        }

        boolean f[] = new boolean[n];
        int r = -1;
        int ct = 0;
        for(int i=0;i<n;++i){
            r = Math.max(r,right.get(a[i]));
            if(i==r){
                f[i] = true;ct++;
            }
        }
        long pp =998244353;

        long v =1;

        for(long i=1;i<=ct-1;++i){
            v *= 2;
            v %= pp;
        }

        println(v);

































        




































































































































































































































































































































        

        






























































































        






































































    }












    long t1[];
    

    void update(long[] t,int i,long v){
        for(;i<t.length;i+=(i&-i)){
            t[i] += v;
        }
    }
    long get(long[] t,int i){
        long s = 0;
        for(;i>0;i-=(i&-i)){
            s += t[i];
        }
        return s;
    }

    int id0(long t[],long v){
        int s=0,p=0;
        for(int i=Integer.numberOfTrailingZeros(Integer.highestOneBit(t.length));i>=0;--i) {
            if(p+(1<<i)< t.length && s + t[p+(1<<i)] < v){
                v -= t[p+(1<<i)];
                p |= 1<<i;
            }
        }
        return p+1;
    }









    static class S{
        int l = 0;
        int r = 0 ;
        long le = 0;
        long ri = 0;
        long tot = 0;
        long all = 0;

        public S(int l,int r) {
            this.l = l;
            this.r = r;
        }
    }

    static S a[];
    static int[] o;

    static void init(int[] f){
        o = f;
        int len = o.length;
        a = new S[len*4];
        build(1,0,len-1);
    }

    static void build(int num,int l,int r){
        S cur = new S(l,r);
        if(l==r){
            a[num] = cur;
            return;
        }else{
            int m = (l+r)>>1;
            int le = num<<1;
            int ri = le|1;
            build(le, l,m);
            build(ri, m+1,r);
            a[num] = cur;
            pushup(num, le, ri);
        }
    }



    













































    static long dd = 10007;
    static void update(int num,int l,long v){
        if(a[num].l==a[num].r){
            a[num].le = v%dd;
            a[num].ri = v%dd;
            a[num].all = v%dd;
            a[num].tot = v%dd;
        }else{
            int m = (a[num].l+a[num].r)>>1;
            int le = num<<1;
            int ri = le|1;
            pushdown(num, le, ri);
            if(l<=m){
                update(le,l,v);
            }
            if(l>m){
                update(ri,l,v);
            }
            pushup(num,le,ri);
        }
    }

    static void pushup(int num,int le,int ri){
        a[num].all = (a[le].all*a[ri].all)%dd;
        a[num].le = (a[le].le + a[le].all*a[ri].le)%dd;
        a[num].ri = (a[ri].ri + a[ri].all*a[le].ri)%dd;
        a[num].tot = (a[le].tot + a[ri].tot + a[le].ri*a[ri].le)%dd;


        

    }
    static void pushdown(int num,int le,int ri){

    }

    long gcd(long a,long b){ return b==0?a: gcd(b,a%b);}
    int gcd(int a,int b){ return b==0?a: gcd(b,a%b);}
    InputStream is;PrintWriter out;
    void run() throws Exception {is = System.in;
        

        out = new PrintWriter(System.out);solve();out.flush();}
    private byte[] inbuf = new byte[2];
    public int lenbuf = 0, ptrbuf = 0;
    private int readByte() {
        if (lenbuf == -1) throw new InputMismatchException();
        if (ptrbuf >= lenbuf) {
            ptrbuf = 0;
            try {lenbuf = is.read(inbuf);} catch (IOException e) {throw new InputMismatchException();}
            if (lenbuf <= 0) return -1;
        }
        return inbuf[ptrbuf++];}
    private boolean id1(int c) {return !(c >= 33 && c <= 126);}
    private int skip() {int b;while((b = readByte()) != -1 && id1(b));return b;}
    private double nd() {return Double.parseDouble(ns());}
    private char nc() {return (char) skip();}
    private char ncc() {int b;while((b = readByte()) != -1 && !(b >= 32 && b <= 126));return (char)b;}
    private String ns() {int b = skip();StringBuilder sb = new StringBuilder();
        while (!(id1(b))) { 

            sb.appendCodePoint(b);b = readByte(); }
        return sb.toString();}
    private char[] ns(int n) {char[] buf = new char[n];int b = skip(), p = 0;
        while (p < n && !(id1(b))) { buf[p++] = (char) b;b = readByte(); }
        return n == p ? buf : Arrays.copyOf(buf, p);}
    private String nline() {int b = skip();StringBuilder sb = new StringBuilder();
        while (!id1(b) || b == ' ') { sb.appendCodePoint(b);b = readByte(); }
        return sb.toString();}
    private char[][] nm(int n, int m) {char[][] a = new char[n][];for (int i = 0; i < n; i++) a[i] = ns(m);return a;}
    private int[] na(int n) {int[] a = new int[n];for (int i = 0; i < n; i++) a[i] = ni();return a;}
    private long[] nal(int n) { long[] a = new long[n];for (int i = 0; i < n; i++) a[i] = nl();return a;}
    private int ni() { int num = 0, b; boolean minus = false;
        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')){};
        if (b == '-') { minus = true; b = readByte(); }
        while (true) {
            if (b >= '0' && b <= '9') num = (num << 3) + (num << 1) + (b - '0');
            else return minus ? -num : num;
            b = readByte();}}
    private long nl() { long num = 0; int b;
        boolean minus = false;
        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')){};
        if (b == '-') { minus = true; b = readByte(); }
        while (true) {
            if (b >= '0' && b <= '9')  num = num * 10 + (b - '0');
            else return minus ? -num : num;
            b = readByte();}}
    void print(Object obj){out.print(obj);}
    void println(Object obj){out.println(obj);}
    void println(){out.println();}
}
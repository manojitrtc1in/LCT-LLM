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


    void solve() {

        int n = ni();
        int k = ni();
        int s[] = new int[200001];
        for(int i=0;i<n;++i){
            int v = ni();
            s[v]++;
        }
        int p[][] =new int[n][2];
        int x = 0;
        for(int i=1;i<=200000;++i){
            if(s[i]>0){
                p[x][0] = s[i];
                p[x++][1] = i;
            }
        }
        Arrays.sort(p,0,x,(a,b)->{
            return Integer.compare(b[0],a[0]);
        });

        int lo = 1;
        int hi = n;
        while(lo<hi){
            int mi = (lo+hi+1)/2;
            long d =0;
            for(int i=0;i<x;++i){
                d += p[i][0]/mi;
            }
            if(d>=k){
                lo = mi;
            }else{
                hi = mi-1;
            }
        }
        int d =0;
        for(int i=0;i<x&&d<k;++i){
            int g = p[i][0]/lo;
            int sy = k-d;
            int f = Math.min(sy,g);
            d += f;
            for(int j=0;j<f;++j){
                print(p[i][1]+" ");
            }

        }
















        




































































































































































































































































































































        

        






























































































        






































































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

    int equal_bigger(long t[],long v){
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


    int gcd(int a,int b){ return b==0?a: gcd(b,a%b);}
    InputStream is;PrintWriter out;
    void run() throws Exception {is = System.in;out = new PrintWriter(System.out);solve();out.flush();}
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
    private boolean isSpaceChar(int c) {return !(c >= 33 && c <= 126);}
    private int skip() {int b;while((b = readByte()) != -1 && isSpaceChar(b));return b;}
    private double nd() {return Double.parseDouble(ns());}
    private char nc() {return (char) skip();}
    private char ncc() {int b;while((b = readByte()) != -1 && !(b >= 32 && b <= 126));return (char)b;}
    private String ns() {int b = skip();StringBuilder sb = new StringBuilder();
        while (!(isSpaceChar(b))) { 

            sb.appendCodePoint(b);b = readByte(); }
        return sb.toString();}
    private char[] ns(int n) {char[] buf = new char[n];int b = skip(), p = 0;
        while (p < n && !(isSpaceChar(b))) { buf[p++] = (char) b;b = readByte(); }
        return n == p ? buf : Arrays.copyOf(buf, p);}
    private String nline() {int b = skip();StringBuilder sb = new StringBuilder();
        while (!isSpaceChar(b) || b == ' ') { sb.appendCodePoint(b);b = readByte(); }
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
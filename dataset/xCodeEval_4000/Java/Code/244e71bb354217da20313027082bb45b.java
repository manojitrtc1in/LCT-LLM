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

    void go(int rt,int sd,int k,List<Integer> g[],int n){
        if(add>n) {
            return;
        }

        Queue<Integer> q =new LinkedList<>();
        q.offer(rt);
        for(int i=1;i<=sd;++i){
            int sz =q.size();
            if(sz==0) break;
            int f = (i==1?2:1);
            while(sz-->0){
                int cur = q.poll();
                for(int j=0;j<k-f;++j){
                    q.offer(add);
                    g[cur].add(add);add++;
                    if(add==n+1){
                        return;
                    }
                }
            }
        }


    }

    private static long longRandomPrime() {
        BigInteger prime = BigInteger.probablePrime(31, new Random());
        return prime.longValue();
    }

    void solve() {

        int n  = ni();
        long dp[] = new long[n];
        long tot = 0;
        long f[] = new long [n+1];
        long p = 131;
        long zf[] = new long[n+1];

        long mb = longRandomPrime();

        for(int i=0;i<n;++i){
            String s = ns();
            int len = s.length();
            for(int j = 0;j<len;++j){
                f[i] = (f[i]*p + s.charAt(j))%mb;
            }
            dp[i] = len-1;
            tot += len;
        }
        long p1 = 133333337;
        long lenp1[] = new long[n+1];
        long zdp[] = new long[n+1];
        lenp1[0] = 1;
        for(int i=0;i<n;++i){
            zf[i+1] = (zf[i]*p1 + f[i])%mb;
            zdp[i+1] = zdp[i] + dp[i];
            lenp1[i+1] = (lenp1[i]*p1)%mb;
        }

        long r = 0;
        for(int i=0;i<n;++i){
            for(int len=1;i+len<=n;++len){
                long cur = zdp[i+len] - zdp[i];
                long ck = ((zf[i+len] - zf[i]*lenp1[len])%mb+mb)%mb;
                int j = i+len;
                int cnt = 0;
                while(j+len<=n){
                    long ck1 = ((zf[j+len] - zf[j]*lenp1[len])%mb+mb)%mb;
                    if(ck1==ck){
                        cnt++;
                        j = j+len;
                    }else{
                        j++;
                    }
                }
                if(cnt>=1){
                    r = Math.max(r, (cnt+1)*(cur+len-1));
                }

            }
        }

        tot += n-1;

        println(tot-r);









        




































































































































































































































































































































        

        






























































































        






































































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
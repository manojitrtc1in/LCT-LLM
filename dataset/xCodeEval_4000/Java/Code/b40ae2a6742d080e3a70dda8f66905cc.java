import java.awt.event.MouseAdapter;
import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        new Main().run();
    }

    static int groups = 0;
    static int[] fa;
    static int[] sz;

    static void init1(int n) {
        groups = n;
        fa = new int[n];
        for (int i = 1; i < n; ++i) {
            fa[i] = i;
        }
        sz = new int[n];
        Arrays.fill(sz, 1);
    }

    static int root(int p) {
        while (p != fa[p]) {
            fa[p] = fa[fa[p]];
            p = fa[p];
        }
        return p;
    }

    static void combine(int p, int q) {
        int i = root(p);
        int j = root(q);
        if (i == j) {
            return;
        }
        fa[i] = j;
        if (sz[i] < sz[j]) {
            fa[i] = j;
            sz[j] += sz[i];
        } else {
            fa[j] = i;
            sz[i] += sz[j];
        }
        groups--;
    }


    public static String roundS(double result, int scale) {
        String fmt = String.format("%%.%df", scale);
        return String.format(fmt, result);
    }

    int[] unique(int a[]) {
        int p = 1;
        for (int i = 1; i < a.length; ++i) {
            if (a[i] != a[i - 1]) {
                a[p++] = a[i];
            }
        }
        return Arrays.copyOf(a, p);
    }


    public static int bigger(long[] a, long key) {
        return bigger(a, 0, a.length, key);
    }

    public static int bigger(long[] a, int lo, int hi,
                             long key) {
        while (lo < hi) {
            int mid = (lo + hi) >>> 1;
            if (a[mid] > key) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }


    static int h[];
    static int to[];
    static int ne[];
    static int m = 0;

    public static void addEdge(int u, int v, int w) {
        to[++m] = v;
        ne[m] = h[u];
        h[u] = m;
    }


    int w[];

    int cc = 0;

    void add(int u, int v, int ww) {
        to[++cc] = u;
        w[cc] = ww;
        ne[cc] = h[v];
        h[v] = cc;

        to[++cc] = v;
        w[cc] = ww;
        ne[cc] = h[u];
        h[u] = cc;
    }






















































































    static class S {
        int l = 0;
        int r = 0;
        int miss = 0;
        int cnt = 0;
        int c = 0;

        public S(int l, int r) {
            this.l = l;
            this.r = r;
        }
    }

    static S a[];
    static int[] o;

    static void init11(int[] f) {
        o = f;
        int len = o.length;
        a = new S[len * 4];
        build1(1, 0, len - 1);
    }

    static void build1(int num, int l, int r) {
        S cur = new S(l, r);
        if (l == r) {
            cur.c = o[l];
            a[num] = cur;
            return;
        } else {
            int m = (l + r) >> 1;
            int le = num << 1;
            int ri = le | 1;
            build1(le, l, m);
            build1(ri, m + 1, r);
            a[num] = cur;
            pushup(num, le, ri);
        }
    }

    static int query1(int num, int l, int r) {
        if (a[num].l >= l && a[num].r <= r) {
            return a[num].c;
        } else {
            int m = (a[num].l + a[num].r) >> 1;
            int le = num << 1;
            int ri = le | 1;

            int mi = -1;

            if (r > m) {
                int res = query1(ri, l, r);
                mi = Math.max(mi, res);
            }

            if (l <= m) {
                int res = query1(le, l, r);
                mi = Math.max(mi, res);
            }

            return mi;
        }
    }

    static void pushup(int num, int le, int ri) {
        a[num].c = Math.max(a[le].c, a[ri].c);

    }





































































    int clr[];
    List[] qr;
    int qs[][];

    int rr = 100;
    LinkedList<Integer> cao;
    void df(int n,LinkedList<Integer> li){
        int sz = li.size();
        if(sz>=rr||sz>=11) return;
        int v = li.getLast();
        if(v==n){
            cao = new LinkedList<>(li);
            rr = sz;
            return;
        }
        List<Integer> res = new ArrayList<>(li);
        Collections.reverse(res);

        for(int u:res){
            for(int vv:res){
                if(u+vv>v&&u+vv<=n){
                    li.addLast(u+vv);
                    df(n,li);
                    li.removeLast();
                }else if(u+vv>n){break;}
            }
        }
    }



    Random rd = new Random(1274873);

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
        long temp = k%p;
        while(n!=0L){
            if((n&1L)==1L){
                res = mul(res,temp,p);
            }
            temp = mul(temp,temp,p);
            n = n>>1L;
        }
        return res%p;
    }


    long gen(long x){
        while(true) {
            long f = rd.nextLong()%x;
            if (f >=1 &&f<=x-1) {
                return f;
            }
        }
    }

    boolean robin_miller(long x){
        if(x==1) return false;
        if(x==2) return true;
        if(x==3) return true;
        if((x&1)==0) return false;
        long y = x%6;
        if(y==1||y==5){
            long ck = x-1;
            while((ck&1)==0) ck>>>=1;

            long as[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

            for(int i=0;i<as.length;++i){
                long a = as[i];
                long ck1=  ck;
                a = mod_pow(a,ck1,x);
                while(ck1<x){
                    y = mod_pow(a,2, x);
                    if (y == 1 && a != 1 && a != x - 1)
                        return false;
                    a = y;
                    ck1 = ck1<<1;
                }
                if (a != 1)
                    return false;
            }
            return true;
        }else{
            return false;
        }

    }

    long inv(long a, long MOD) {
        

        return a==1?1:(long )(MOD-MOD/a)*inv(MOD%a, MOD)%MOD;
    }

    long C(long n,long m, long MOD) {
        if(m+m>n)m=n-m;
        long up=1,down=1;
        for(long i=0;i<m;i++)
        {
            up=up*(n-i)%MOD;
            down=down*(i+1)%MOD;
        }
        return up*inv(down, MOD)%MOD;
    }


































































    

    public static long[] ex_gcd(long a,long b){
        if(b==0) {
            return new long[]{1,0,a};
        }
        long []r = ex_gcd(b,a%b);
        return new long[]{r[1], r[0]-(a/b)*r[1], r[2]};
    }

    void chinese_rm(long m[],long r[]){
        long res[] = ex_gcd(m[0],m[1]);
        long rm = r[1]-r[0];
        if(rm%res[2]==0){

        }

    }





    



















    int go(int rt,int h[],int ne[],int to[],int pa){
        int all = 3010;
        for(int i=h[rt];i!=-1;i=ne[i]){
            int v = to[i];
            if(v==pa) continue;
            int ma = 0;
            for(int j=h[rt];j!=-1;j=ne[j]) {
                int u = to[j];
                if(u==pa) continue;
                if(u!=v){
                    int r = 1 + go(u,h,ne,to,rt);
                    ma =  Math.max(ma,r);
                }
            }
            all = Math.min(all,ma);
        }
        if(all==3010||all==0) return 1;
        return all;

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

    boolean ok = false;
    void ck(int[] d,int l,String a,String b,String c,int n,boolean chose[],int add){
        if(ok) return;
        if(l==-1){
            if(add==0) {
                for (int u : d) {
                    print(u + " ");
                }
                ok = true;
            }
            return;
        }

        int i1 = a.charAt(l)-'A';
        int i2 = b.charAt(l)-'A';
        int i3 = c.charAt(l)-'A';

        if(d[i1]==-1&&d[i2]==-1) {

            if(i1==i2){

                for (int i = n-1; i >=0; --i) {
                    if (chose[i]) continue;
                    int s = (i + i + add);
                    int w = s % n;
                    if (d[i3] != -1 && d[i3] != w) continue;
                    if (chose[w] && d[i3] != w) continue;

                    if (w == i && i3 != i2) continue;
                    boolean hsw = d[i3]==w;
                    chose[w] = true;
                    chose[i] = true;
                    d[i1] = i; d[i2] = i; d[i3] = w;
                    int nadd = s/n;
                    ck(d, l-1,a,b,c,n,chose,nadd);
                    d[i1] = -1;
                    d[i2] = -1;
                    if(!hsw) {
                        d[i3] = -1;
                        chose[w] = false;
                    }
                    chose[i] = false;

                }

            }else {


                for (int i = n-1; i >=0; --i) {
                    if (chose[i]) continue;
                    chose[i] = true;
                    d[i1] = i;
                    for (int j = n-1; j >=0; --j) {
                        if (chose[j]) continue;
                        int s = (i + j + add);
                        int w = s % n;
                        if (d[i3] != -1 && d[i3] != w) continue;
                        if (chose[w] && d[i3] != w) continue;

                        if (w == j && i3 != i2) continue;
                        if (w == i && i3 != i1) continue;

                        boolean hsw = d[i3] == w;
                        chose[w] = true;

                        chose[j] = true;

                        d[i2] = j;
                        d[i3] = w;
                        int nadd = s / n;
                        ck(d, l - 1, a, b, c, n, chose, nadd);

                        d[i2] = -1;
                        if (!hsw) {
                            d[i3] = -1;
                            chose[w] = false;
                        }
                        chose[j] = false;
                    }
                    chose[i] = false;
                    d[i1] = -1;
                }
            }

        }else if(d[i1]==-1){
            if(d[i3]==-1) {
                for (int i = n - 1; i >= 0; --i) {
                    if (chose[i]) continue;
                    int s = (i + d[i2] + add);
                    int w = s % n;
                    if (d[i3] != -1 && d[i3] != w) continue;
                    if (chose[w] && d[i3] != w) continue;

                    if (w == i && i3 != i1) continue;
                    if (w == d[i2] && i3 != i2) continue;

                    boolean hsw = d[i3] == w;
                    chose[i] = true;
                    chose[w] = false;
                    d[i1] = i;
                    d[i3] = w;
                    int nadd = s / n;
                    ck(d, l - 1, a, b, c, n, chose, nadd);
                    d[i1] = -1;
                    if (!hsw) {
                        d[i3] = -1;
                        chose[w] = false;
                    }
                    chose[i] = false;
                }
            }else{

                int s = d[i3]-add-d[i2];
                int nadd = 0;
                if(s<0){
                    s += n;
                    nadd = 1;
                }
                if(chose[s]) return;
                chose[s] = true;
                d[i1] = s;
                ck(d, l - 1, a, b, c, n, chose, nadd);
                chose[s] = false;
                d[i1] = -1;



            }
        }else if(d[i2]==-1){

            if(d[i3]==-1) {
                for (int i = n - 1; i >= 0; --i) {
                    if (chose[i]) continue;
                    int s = (i + d[i1] + add);
                    int w = s % n;
                    

                    if (chose[w] && d[i3] != w) continue;

                    if (w == i && i3 != i2) continue;
                    if (w == d[i1] && i3 != i1) continue;

                    boolean hsw = d[i3] == w;
                    chose[i] = true;
                    chose[w] = true;
                    d[i2] = i;
                    d[i3] = w;
                    int nadd = s / n;
                    ck(d, l - 1, a, b, c, n, chose, nadd);
                    d[i2] = -1;
                    if (!hsw) {
                        d[i3] = -1;
                        chose[w] = false;
                    }
                    chose[i] = false;
                }
            }else{
                int s = d[i3]-add-d[i1];
                int nadd = 0;
                if(s<0){
                    s += n;
                    nadd = 1;
                }
                if(chose[s]) return;
                chose[s] = true;
                d[i2] = s;
                ck(d, l - 1, a, b, c, n, chose, nadd);
                chose[s] = false;
                d[i2] = -1;




            }
        }else{
            if(d[i3]==-1){
                int w =(d[i1]+d[i2]+add);
                int nadd = w/n;
                w %= n;
                if(w==d[i2]&&i3!=i2) return;
                if(w==d[i1]&&i3!=i1) return;
                if(chose[w]) return;

                d[i3] = w;
                chose[d[i3]] = true;
                ck(d, l - 1, a, b, c, n, chose, nadd);
                chose[d[i3]] = false;
                d[i3] = -1;
            }else{
                int w = d[i1]+d[i2]+add;
                int nadd = w/n;
                if(d[i3]==w%n){
                    ck(d, l - 1, a, b, c, n, chose, nadd);
                }else{
                    return;
                }


            }



        }



    }


    int d[][] ;

    void go(int rt,int h[],int ne[],int[] to){
        d[rt][1] = 1;
        for(int i=h[rt];i!=-1;i = ne[i]){
            go(to[i],h,ne,to);
            d[rt][1] += Math.min(d[to[i]][1],d[to[i]][0]);
            d[rt][0] += d[to[i]][1];
        }
    }


    void solve() {
        int n  = ni();
        int m  = ni();

        int k  = ni();


        if(k==0){
                out.println("YES");
                for(int i=0;i<m;++i){
                    out.print(1);
                }
                for(int i=0;i<n;++i){
                    out.print(0);
                }
                out.println();
                for(int i=0;i<m;++i){
                    out.print(1);
                }
                for(int i=0;i<n;++i){
                    out.print(0);
                }
                out.println();
                return;
        }


        if(n==0){
            out.println("NO");
            return;
        }
        if(m==1){
            out.println("NO");
            return;
        }
        if(k>n+m-2){
            out.print("NO");
            return;
        }

        out.println("YES");
        for(int i=0;i<m;++i){
            out.print(1);
        }
        for(int i=0;i<n;++i){
            out.print(0);
        }
        out.println();

        if(k<=n){
            for(int i=0;i<m-1;++i){
                out.print(1);
            }
            int sy  = n-k;
            for(int i=0;i<k;++i) {
                out.print(0);
            }
            out.print(1);
            for(int i=0;i<sy;++i) {
                out.print(0);
            }
            return;
        }else{
            out.print(1);
            int oo = n+m-k-2;
            for(int i=0;i<oo;++i){
                out.print(1);
            }
            out.print(0);
            m -= oo;
            for(int i=0;i<m-2;++i){
                out.print(1);
            }
            for(int i=0;i<n-1;++i){
                out.print(0);
            }
            out.println(1);



        }


        







































































        






































































































































































































































































































































































































    }


    static void pushdown(int num, int le, int ri) {

    }


    long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    InputStream is;
    PrintWriter out;

    void run() throws Exception {
        is = System.in;
        out = new PrintWriter(System.out);
        solve();
        out.flush();
    }

    private byte[] inbuf = new byte[1024];
    public int lenbuf = 0, ptrbuf = 0;

    private int readByte() {
        if (lenbuf == -1) throw new InputMismatchException();
        if (ptrbuf >= lenbuf) {
            ptrbuf = 0;
            try {
                lenbuf = is.read(inbuf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (lenbuf <= 0) return -1;
        }
        return inbuf[ptrbuf++];
    }

    private boolean isSpaceChar(int c) {
        return !(c >= 33 && c <= 126);
    }

    private int skip() {
        int b;
        while ((b = readByte()) != -1 && isSpaceChar(b)) ;
        return b;
    }

    private double nd() {
        return Double.parseDouble(ns());
    }

    private char nc() {
        return (char) skip();
    }

    private char ncc() {
        int b = readByte();
        return (char) b;
    }

    private String ns() {
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while (!(isSpaceChar(b))) { 

            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    private char[] ns(int n) {
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while (p < n && !(isSpaceChar(b))) {
            buf[p++] = (char) b;
            b = readByte();
        }
        return n == p ? buf : Arrays.copyOf(buf, p);
    }

    private String nline() {
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while (!isSpaceChar(b) || b == ' ') {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    private char[][] nm(int n, int m) {
        char[][] a = new char[n][];
        for (int i = 0; i < n; i++) a[i] = ns(m);
        return a;
    }

    private int[] na(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = ni();
        return a;
    }

    private long[] nal(int n) {
        long[] a = new long[n];
        for (int i = 0; i < n; i++) a[i] = nl();
        return a;
    }

    private int ni() {
        int num = 0, b;
        boolean minus = false;
        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) {
        }
        ;
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        while (true) {
            if (b >= '0' && b <= '9') num = (num << 3) + (num << 1) + (b - '0');
            else return minus ? -num : num;
            b = readByte();
        }
    }

    private long nl() {
        long num = 0;
        int b;
        boolean minus = false;
        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) {
        }
        ;
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        while (true) {
            if (b >= '0' && b <= '9') num = num * 10 + (b - '0');
            else return minus ? -num : num;
            b = readByte();
        }
    }

    void print(Object obj) {
        out.print(obj);
    }

    void println(Object obj) {
        out.println(obj);
    }

    void println() {
        out.println();
    }
}
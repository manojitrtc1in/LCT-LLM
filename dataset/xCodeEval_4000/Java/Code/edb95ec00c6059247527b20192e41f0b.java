import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
public class Main {
    public static void main(String[] args) throws Exception {
        new Main().run();}

    int[] h,ne,to,wt;
    int ct = 0;
    int n;
    void graph(int n,int m){
        h = new int[n];
        Arrays.fill(h,-1);








        ne = new int[2*m];
        to = new int[2*m];
        wt = new int[2*m];
        ct = 0;
    }
    void add(int u,int v,int w){
        to[ct] = v;
        ne[ct] = h[u];
        wt[ct] = w;
        h[u] = ct++;
    }

    int color[],dfn[],low[],stack[] = new int[1000000],cnt[];
    int sccno[];
    boolean iscut[];
    int time = 0,top = 0;
    int scc_cnt = 0;

    

    void tarjan(int u) {
        low[u] = dfn[u]= ++time;
        stack[top++] = u;
        for(int i=h[u];i!=-1;i=ne[i]) {
            int v = to[i];
            if(dfn[v]==0) {
                tarjan(v);
                low[u]=Math.min(low[u],low[v]);
            } else if(sccno[v]==0) {
                

                low[u]=Math.min(low[u],low[v]);
            }
        }

        if(dfn[u]==low[u]) {
            sccno[u] = ++scc_cnt;
            while(stack[top-1]!=u) {
                sccno[stack[top-1]] = scc_cnt;
                --top;
            }
            --top;
        }
    }

    

    int[] h1,to1,ne1;
    int ct1 = 0;
    void point(){
        for(int i=0;i<n;i++) {
            if(dfn[i]==0) tarjan(i);

        }
        

        int du[] = new int[scc_cnt+1];
        h1 = new int[scc_cnt+1];
        Arrays.fill(h1, -1);
        to1 = new int[scc_cnt*scc_cnt];
        ne1 = new int[scc_cnt*scc_cnt];
        


        for(int i=1;i<=n;i++) {
            for(int j=h[i]; j!=-1; j=ne[j]) {
                int y = to[j];
                if(sccno[i] != sccno[y]) {
                    

                    to1[ct1] = sccno[y];
                    ne1[ct1] = h[sccno[i]];
                    h[sccno[i]] = ct1++;
                    du[sccno[y]]++; 

                }
            }
        }

        int q[] = new int[100000];
        int end = 0;
        int st = 0;
        for(int i=1;i<=scc_cnt;++i){
            if(du[i]==0){
                q[end++] = i;
            }
        }

        int dp[] = new int[scc_cnt+1];
        while(st<end){
            int cur = q[st++];
            for(int i=h1[cur];i!=-1;i=ne1[i]){
                int y = to[i];
                

                if(--du[y]==0){
                    q[end++] = y;
                }
            }
        }
    }




    int fa[];
    int faw[];

    int dep = -1;
    int pt = 0;
    void go(int rt,int f,int dd){

        int p = 0;
        stk[p] = rt;
        lk[p] = 0;
        fk[p] = f;p++;
        while(p>0) {
            int cur = stk[p - 1];
            int fp = fk[p - 1];
            int ll = lk[p - 1];
            p--;


            if (ll > dep) {
                dep = ll;
                pt = cur;
            }
            for (int i = h[cur]; i != -1; i = ne[i]) {
                int v = to[i];
                if (fp == v) continue;

                stk[p] = v;
                lk[p] = ll + wt[i];
                fk[p] = cur;
                p++;
            }
        }
    }
    int pt1 = -1;
    void go1(int rt,int f,int dd){

        int p = 0;
        stk[p] = rt;
        lk[p] = 0;
        fk[p] = f;p++;
        while(p>0) {
            int cur = stk[p - 1];
            int fp = fk[p - 1];
            int ll = lk[p - 1];
            p--;


            if (ll > dep) {
                dep = ll;
                pt1 = cur;
            }

            fa[cur] = fp;
            for (int i = h[cur]; i != -1; i = ne[i]) {
                int v = to[i];
                if (v == fp) continue;
                faw[v] = wt[i];
                stk[p] = v;
                lk[p] = ll + wt[i];
                fk[p] = cur;
                p++;
            }
        }
    }

    int r = -1;
    int stk[] = new int[200001];
    int fk[] = new int[200001];
    int lk[] = new int[200001];
    int mb = 0;
    void ddfs(int rt,int t1,int t2,int t3,int l){


        int p = 0;
        stk[p] = rt;
        lk[p] = 0;
        fk[p] = t3;p++;
        while(p>0){
            int cur = stk[p-1];
            int fp = fk[p-1];
            int ll = lk[p-1];
            p--;

            if(ll>r){
                r= ll;
                mb = cur;
            }


            for(int i=h[cur];i!=-1;i=ne[i]){
                int v = to[i];
                if(v==t1||v==t2||v==fp) continue;
                stk[p] = v;
                lk[p] = ll+wt[i];
                fk[p] = cur;p++;
            }
        }



    }

    void solve() {

        int n =  ni();
        fa =new int[n];
        faw =new int[n];

        graph(n,n-1);

        for(int i=0;i<n-1;++i){
            int u  =ni()-1;
            int v  =ni()-1;
            add(u,v,1);
            add(v,u,1);
        }
        go(0,-1,0);
        dep = -1;
        go1(pt,-1,0);
        int g = pt1;
        int all = 0;
        int from[] = new int[n];
        int z[] = new int[n];
        Arrays.fill(from,-1);


        int tot = -1;
        int mm = fa[g];
        while(fa[g]!=-1){
            all += faw[g];
            r = 0;
            mb = fa[g];
            ddfs(fa[g],g,fa[fa[g]],-1,0);
            z[fa[g]] = r;

            if(r>tot){
                tot = r;
                mm = mb;
            }


            g = fa[g];
        }

        println(all+tot);
        pt++;pt1++;mm++;
        println(pt+" "+pt1+" "+mm);

        



















































































        




































































































































































































































































































































        

        






























































































        






































































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
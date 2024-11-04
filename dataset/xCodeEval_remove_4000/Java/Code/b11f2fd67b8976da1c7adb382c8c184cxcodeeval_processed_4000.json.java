import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.*;
import java.math.BigInteger;
import java.net.PortUnreachableException;
import java.util.*;




public class Main {
    public static void main(String[] args) throws Exception {

        new Main().run();
    }

    static int groups = 0;
    static int[] fa;
    static int[] sz;

    static void init(int n) {
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
        if (sz[i] < sz[j]) {
            fa[i] = j;
            sz[j] += sz[i];
        } else {
            fa[j] = i;
            sz[i] += sz[j];
        }
        groups--;
    }

    int child[];
    int color[],dfn[],low[],stack[],cnt[];
    boolean vis[];
    boolean iscut[];
    int deep,top,n,m,sum,ans;
    List<Integer> g[];
    int root = 0;
    

    void id3(int u1) {

        int stk[] = new int[10001];
        int fatk[] = new int[10001];
        int p = 0;
        stk[p] = u1;
        fatk[p] = -1;
        p= 1;
        ot: while(p>0) {
            int u  = stk[p-1];
            int fa = fatk[p-1];


            if(dfn[u]==0) {
                low[u] = dfn[u] = ++deep;
            }
            


            for (; h[u] != -1; h[u] = ne[h[u]]) {
                int v = to[h[u]];
                if (dfn[v] == 0) {
                    


                    fatk[p] = u;
                    stk[p++] = v;
                    continue ot;
                } else {
                    low[u] = Math.min(low[u], dfn[v]);
                    

                    

                }
            }
            --p;

            if (fa != -1) {
                low[fa] = Math.min(low[fa], low[u]);
                if (low[u] >= dfn[fa]) {
                    if (fa != root || ++child[fa] > 1) {     

                        iscut[fa] = true;
                    }
                    ++dcc_cnt;
                    

                    

                    

                    

                    

                    

                    

                }


            }

        }
    }
    int gd = 0;
    int id =-1;
    int id2 = 0;
    int id1[];











































    int h[],to[],ne[];int ct =0;
    void add(int u,int v){
        

        to[ct] = v;
        ne[ct] = h[u];
        h[u] = ct++;

    }

    int dcc_cnt = 0;
    int time = 0;








    private static double f(double x) {
        return Math.pow(Math.abs(x), 0.5) + (5*(Math.pow(x, 3)));
    }

    void dfs(int rt,int fa){
        size[rt]  =1;
        for(int i=h[rt];i!=-1;i=ne[i]){
            int v = to[i];
            if(v==fa) continue;
            dep[v] = dep[rt]+1;
            dfs(v,rt);
            size[rt] += size[v];
        }
    }

    int size[];int dep[];



    long get(int i,int i1,int j,int j1){
        return s[i1][j1] - s[i-1][j1] - s[i1][j-1] + s[i-1][j-1];
    }
    long mod = 1000000007;
    long sv(int i,int i1,int j,int j1,int qie){

        if(dp[i][i1][j][j1][qie]!=0) return dp[i][i1][j][j1][qie];
        if(qie==0) return 1;
        long t = 0;
        for(int k=i+1;k<=i1;++k){
            long num = get(i,k-1,j,j1);
            long num1 = get(k,i1,j,j1);
            if(num>0&&num1>0){
                t += sv(k,i1,j,j1,qie-1);
                t %= mod;
            }
        }
        for(int k=j+1;k<=j1;++k){
            long num = get(i,i1,j,k-1);
            long num1 = get(i,i1,k,j1);
            if(num>0&&num1>0){
                t += sv(i,i1,k,j1,qie-1);
                t %= mod;
            }
        }
        return dp[i][i1][j][j1][qie] = t;
    }

    long s[][];
    long dp[][][][][];
    public int ways(String[] p, int k) {
        int l  = p.length;
        int ll = p[0].length();

        dp = new long[l+1][l+1][ll+1][ll+1][k+1];
        s  = new long[l+1][ll+1];

        for(int i=1;i<=l;++i){
            for(int j=1;j<=ll;++j){
                int c = 0;
                if(p[i-1].charAt(j-1)=='A'){
                    c++;
                }
                s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + c;
            }
        }

        return (int)sv(1,l,1,ll,k-1);







    }



    void solve() {
        int t = ni();


       ot: while(t-->0) {
            int n =  ni();
            int a[] = na(n);
            int d[] = new int[n];
            for(int i=0;i<n;++i){
                int ck = (n+(i+a[i])%n)%n;
                if(d[ck]==0){
                    d[ck] = 1;
                }else{
                    println("No");continue ot;
                }

            }
            println("Yes");



        }


































































































    }


      
































































































    


















































































  









































































    static long mod_pow(long k,long n,long p){
        long res = 1L;
        long temp = (k%p+p)%p;
        while(n!=0L){
            if((n&1L)==1L){
                res = ((res*temp)%p+p)%p;
            }
            temp = ((temp * temp)%p+p)%p;
            n = n>>1L;
        }
        return res%p;
    }
    public static String roundS(double result, int scale){
        String fmt = String.format("%%.%df", scale);
        return String.format(fmt, result);
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

    private boolean id0(int c) {
        return !(c >= 33 && c <= 126);
    }

    private int skip() {
        int b;
        while ((b = readByte()) != -1 && id0(b)) ;
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
        while (!(id0(b))) { 

            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    private char[] ns(int n) {
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while (p < n && !(id0(b))) {
            buf[p++] = (char) b;
            b = readByte();
        }
        return n == p ? buf : Arrays.copyOf(buf, p);
    }

    private String nline() {
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while (!id0(b) || b == ' ') {
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

    void printArray(int a[],int from){
        int l = a.length;
        for(int i=from;i<l;++i){
            print(a[i]);
            if(i!=l-1){
                print(" ");
            }
        }
        println();
    }

    void printArray(long a[],int from){
        int l = a.length;
        for(int i=from;i<l;++i){
            print(a[i]);
            if(i!=l-1){
                print(" ");
            }
        }
        println();
    }
}
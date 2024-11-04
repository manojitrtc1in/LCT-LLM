import java.io.*;
import java.math.BigInteger;
import java.util.*;




public class Main {
    public static void main(String[] args) throws Exception {

        new Main().run();
    }


    int color[],dfn[],low[],stack[],cnt[];
    boolean vis[];
    boolean iscut[];
    int deep,top,n,m,sum,ans;
    List<Integer> g[];

    void tarjan(int u,int fa)
    {
        int child = 0;
        dfn[u]=++deep;
        low[u]=deep;
        vis[u]=true;
        stack[++top]=u;
        int sz=g[u].size();
        for(int i=0;i<sz;i++)
        {
            int v =g[u].get(i);
            if(v==fa) continue;
            if(dfn[v]==0)
            {
                child++;
                tarjan(v,u);
                low[u]=Math.min(low[u],low[v]);

            }
            else
            {
                if(vis[v])
                {
                    low[u]=Math.min(low[u],low[v]);
                }
            }
        }
        if(fa<0&&child==1){
            iscut[u] =true;
        }

        if(dfn[u]==low[u])
        {
            iscut[u] = true;
            color[u]=++sum;
            vis[u]=false;
            while(stack[top]!=u)
            {
                color[stack[top]]=sum;
                vis[stack[top--]]=false;
            }
            top--;
        }
    }
    boolean hasV  = false;
    boolean hasU  = false;
    long ct = 0;
    void dfs(int u,int fa,int a,int b){
        ct++;
        vis[u] = true;
        int sz=g[u].size();
        for(int i=0;i<sz;i++) {
            int v = g[u].get(i);
            if (v == fa) continue;
            if(vis[v]) continue;
            if(v==a){
                hasV = true;
                continue;
            }
            if(v==b){
                hasU = true;
                continue;
            }
            dfs(v,u,a,b);


        }
    }











































    void solve(){
        int t =ni();


        ot:for(int i=0;i<t;++i) {
            int r = ni();
            int c = ni();
            char mp[][] = nm(r, c);
            int z = 0;
            int x = 0;
            for (int j = 0; j < r; ++j) {
                for (int k = 0; k < c; ++k) {
                    if (mp[j][k] == 'A') {
                        z++;
                    } else {
                        x++;
                    }
                }
            }
            if (z == r * c) {
                println(0);
                continue;
            } else if (x == r * c) {
                println("MORTAL");
                continue;
            }
            int z1 = 0;
            int zr = 0;
            for (int j = 0; j < c; ++j) {
                z1 += mp[0][j] == 'A' ? 1 : 0;
                zr += mp[r - 1][j] == 'A' ? 1 : 0;
            }
            int z2 = 0;
            int zc = 0;
            for (int j = 0; j < r; ++j) {
                z2 += mp[j][0] == 'A' ? 1 : 0;
                zc += mp[j][c - 1] == 'A' ? 1 : 0;
            }
            if(z1==c||zr==c||z2==r||zc==r){
                println(1);continue;
            }
            if(z1==0&&zr==0&&z2==0&&zc==0){
                println(4);continue;
            }

            int sum[][] = new int[c][r+1];
            int sum1[][] = new int[c+1][r];

            for(int j=0;j<r;++j){
                for(int l=0;l<c;++l){
                    sum[l][j+1] = sum[l][j] + (mp[j][l]=='A'?1:0);
                    sum1[l+1][j] = sum1[l][j] + (mp[j][l]=='A'?1:0);
                }
            }

            for(int j=0;j<r;++j){
                for(int k=j;k<r;++k){
                    boolean ok = false;
                    for(int l=0;l<c;++l){
                        if(sum[l][k+1]-sum[l][j]==k-j+1){
                            ok = true;
                        }
                    }
                    int ck1 = sum[0][j] +  sum[0][r]-sum[0][k+1];
                    int ck2 = sum[c-1][j] +  sum[c-1][r]-sum[c-1][k+1];

                    if(ok&&(ck1+k-j+1==r||ck2+k-j+1==r)){
                        println(2);continue ot;
                    }

                }
            }


            for(int j=0;j<c;++j){
                for(int k=j;k<c;++k){
                    boolean ok = false;
                    for(int l=0;l<r;++l){
                        if(sum1[k+1][l]-sum1[j][l]==k-j+1){
                            ok = true;
                        }
                    }
                    int ck1 = sum1[j][0] +  sum1[c][0]-sum1[k+1][0];
                    int ck2 = sum1[j][r-1] +  sum1[c][r-1]-sum1[k+1][r-1];

                    if(ok&&(ck1+k-j+1==c||ck2+k-j+1==c)){
                        println(2);continue ot;
                    }

                }
            }

            if(mp[0][0]=='A'||mp[0][c-1]=='A'||mp[r-1][0]=='A'||mp[r-1][c-1]=='A'){
                println(2);continue ;
            }

            println(3);





        }


    }




























































































































































































































































































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
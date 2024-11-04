import java.util.*;
import java.io.*;
import java.text.*;

public class id3{
    

    int B = 18;
    void pre() throws Exception{}
    void solve(int TC) throws Exception{
        int N = ni();
        int[] from = new int[N-1], to = new int[N-1];
        for(int i = 0; i< N-1; i++){
            from[i] = ni()-1;
            to[i] = i+1;
        }
        int[][] g1 = make(N, N-1, from, to, true);
        for(int i = 0; i< N-1; i++){
            from[i] = ni()-1;
            to[i] = i+1;
        }
        int[][] g2 = make(N, N-1, from, to, true);
        int[] eu = new int[N], st = new int[N], en = new int[N];
        time = -1;
        pre(g2, st, en, 0, -1);
        MinTree min = new MinTree(N);
        MaxTree max = new MaxTree(N);
        min.update(0, N-1, -1);
        max.update(0, N-1, -1);
        pn(dfs(g1, min, max, st, en, 0, -1, 0));
    }
    int dfs(int[][] g1, MinTree min, MaxTree max, int[] st, int[] en, int u, int p, int curCount) throws Exception{

       int swapInd = -1;
       boolean add = false;
       if(min.sum(st[u], en[u]) >= 0){
           int anc = (int)min.sum(st[u], en[u]);
           swapInd = anc;
           min.update(st[anc], en[anc], -1);
           max.update(st[anc], en[anc], -1);

           min.update(st[u], en[u], u);
           max.update(st[u], en[u], u);
           add = true;
       }
       if(max.sum(st[u], en[u]) == -1){
           add = true;
           min.update(st[u], en[u], u);
           max.update(st[u], en[u], u);
           curCount++;
       }
       int ans = curCount;
       for(int v:g1[u]){
           if(v == p)continue;
           ans = Math.max(ans, dfs(g1, min, max, st, en, v, u, curCount));
       }
       if(add){
           min.update(st[u], en[u], -1);
           max.update(st[u], en[u], -1);
       }
       if(swapInd != -1){
           min.update(st[swapInd], en[swapInd], swapInd);
           max.update(st[swapInd], en[swapInd], swapInd);
       }
       return ans;
    }
    int time = -1;
    void pre(int[][] g, int[] st, int[] en, int u, int p){


        time++;
        st[u] = time;
        for(int v:g[u])if(v != p)pre(g, st, en, v, u);
        en[u] = time;
    }
    class id7 {

        

        

        int modifyOperation(int x, int y) {
            return x + y;
        }

        

        int queryOperation(int leftValue, int rightValue) {
            return leftValue + rightValue;
        }

        int id4(int delta, int segmentLength) {
            if (delta == id0()) return id0();
            

            

            

            

            return delta * segmentLength;
        }

        int id0() {
            return 0;
        }

        int id5() {
            return 0;
        }

        

        int[] value;
        int[] delta; 


        int id1(int value, int delta) {
            if (delta == id0()) return value;
            return modifyOperation(value, delta);
        }

        int id6(int delta1, int delta2) {
            if (delta1 == id0()) return delta2;
            if (delta2 == id0()) return delta1;
            return modifyOperation(delta1, delta2);
        }

        void pushDelta(int i) {
            int d = 0;
            for (; (i >> d) > 0; d++) {
            }
            for (d -= 2; d >= 0; d--) {
                int x = i >> d;
                value[x >> 1] = id2(x >> 1, 1 << (d + 1));
                delta[x] = id6(delta[x], delta[x >> 1]);
                delta[x ^ 1] = id6(delta[x ^ 1], delta[x >> 1]);
                delta[x >> 1] = id0();
            }
        }

        public id7(int n) {
            value = new int[2 * n];
            for (int i = 0; i < n; i++) {
                value[i + n] = id5();
            }
            for (int i = 2 * n - 1; i > 1; i -= 2) {
                value[i >> 1] = queryOperation(value[i], value[i ^ 1]);
            }
            delta = new int[2 * n];
            Arrays.fill(delta, id0());
        }

        int id2(int i, int len) {
            return id1(value[i], id4(delta[i], len));
        }

        public int query(int from, int to) {
            from += value.length >> 1;
            to += value.length >> 1;
            pushDelta(from);
            pushDelta(to);
            int res = 0;
            boolean found = false;
            for (int len = 1; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1, len <<= 1) {
                if ((from & 1) != 0) {
                    res = found ? queryOperation(res, id2(from, len)) : id2(from, len);
                    found = true;
                }
                if ((to & 1) == 0) {
                    res = found ? queryOperation(res, id2(to, len)) : id2(to, len);
                    found = true;
                }
            }
            if (!found) throw new RuntimeException();
            return res;
        }

        public void modify(int from, int to, int delta) {
            from += value.length >> 1;
            to += value.length >> 1;
            pushDelta(from);
            pushDelta(to);
            int a = from;
            int b = to;
            for (; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1) {
                if ((from & 1) != 0) {
                    this.delta[from] = id6(this.delta[from], delta);
                }
                if ((to & 1) == 0) {
                    this.delta[to] = id6(this.delta[to], delta);
                }
            }
            for (int i = a, len = 1; i > 1; i >>= 1, len <<= 1) {
                value[i >> 1] = queryOperation(id2(i, len), id2(i ^ 1, len));
            }
            for (int i = b, len = 1; i > 1; i >>= 1, len <<= 1) {
                value[i >> 1] = queryOperation(id2(i, len), id2(i ^ 1, len));
            }
        }
    }
    class MinTree {
        int m = 1;
        long[] t, lazy;
        public MinTree(int n){
            while(m<n)m<<=1;
            t = new long[m<<1];
            lazy = new long[m<<1];
            Arrays.fill(t, IINF);
            Arrays.fill(lazy, IINF);
        }
        

        private void push(int i, int ll, int rr){
            if(lazy[i] != IINF){
                t[i] = lazy[i];
                if(i < m){
                    lazy[i<<1] = lazy[i];
                    lazy[i<<1|1] = lazy[i];
                }
                lazy[i] = IINF;
            }
        }
        public void update(int l, int r, long x){u(l, r, 0, m-1, 1, x);}
        public long sum(int l, int r){return s(l, r, 0, m-1, 1);}

        private void u(int l, int r, int ll, int rr, int i, long x){
            push(i, ll, rr);
            if(l == ll && r == rr){
                lazy[i] = x;

                push(i, ll, rr);return;
            }
            int mid = (ll+rr)/2;
            if(r <= mid){
                u(l, r, ll, mid, i<<1, x);
                push(i<<1|1, mid+1, rr);
            }else if(l > mid){
                push(i<<1, ll, mid);
                u(l, r, mid+1, rr, i<<1|1, x);
            }else{
                u(l, mid, ll, mid, i<<1, x);
                u(mid+1, r, mid+1, rr, i<<1|1, x);
            }
            t[i] = Math.min(t[i<<1], t[i<<1|1]);
        }
        private long s(int l, int r, int ll, int rr, int i){
            push(i, ll, rr);
            if(l == ll && r == rr)return t[i];
            int mid = (ll+rr)/2;
            if(r <= mid)return s(l ,r, ll, mid, i<<1);
            else if(l > mid)return s(l, r, mid+1, rr, i<<1|1);
            else return Math.min(s(l, mid, ll, mid, i<<1), s(mid+1, r, mid+1, rr, i<<1|1));
        }
    }
    class MaxTree {
        int m = 1;
        long[] t, lazy;
        public MaxTree(int n){
            while(m<n)m<<=1;
            t = new long[m<<1];
            lazy = new long[m<<1];
            Arrays.fill(t, -IINF);
            Arrays.fill(lazy, -IINF);
        }
        

        private void push(int i, int ll, int rr){
            if(lazy[i] != -IINF){
                t[i] = lazy[i];
                if(i < m){
                    lazy[i<<1] = lazy[i];
                    lazy[i<<1|1] = lazy[i];
                }
                lazy[i] = -IINF;
            }
        }
        public void update(int l, int r, long x){u(l, r, 0, m-1, 1, x);}
        public long sum(int l, int r){return s(l, r, 0, m-1, 1);}

        private void u(int l, int r, int ll, int rr, int i, long x){
            push(i, ll, rr);
            if(l == ll && r == rr){
                lazy[i] = x;

                push(i, ll, rr);return;
            }
            int mid = (ll+rr)/2;
            if(r <= mid){
                u(l, r, ll, mid, i<<1, x);
                push(i<<1|1, mid+1, rr);
            }else if(l > mid){
                push(i<<1, ll, mid);
                u(l, r, mid+1, rr, i<<1|1, x);
            }else{
                u(l, mid, ll, mid, i<<1, x);
                u(mid+1, r, mid+1, rr, i<<1|1, x);
            }
            t[i] = Math.max(t[i<<1], t[i<<1|1]);
        }
        private long s(int l, int r, int ll, int rr, int i){
            push(i, ll, rr);
            if(l == ll && r == rr)return t[i];
            int mid = (ll+rr)/2;
            if(r <= mid)return s(l ,r, ll, mid, i<<1);
            else if(l > mid)return s(l, r, mid+1, rr, i<<1|1);
            else return Math.max(s(l, mid, ll, mid, i<<1), s(mid+1, r, mid+1, rr, i<<1|1));
        }
    }
    

    void hold(boolean b)throws Exception{if(!b)throw new Exception("Hold right there, Sparky!");}
    void exit(boolean b){if(!b)System.exit(0);}
    static void dbg(Object... o){System.err.println(Arrays.deepToString(o));}
    final long IINF = (long)1e17;
    final int INF = (int)1e9+2;
    DecimalFormat df = new DecimalFormat("0.00000000000");
    double PI = 3.141592653589793238462643383279502884197169399, eps = 1e-8;
    static boolean multipleTC = true, memory = true, fileIO = false;
    FastReader in;PrintWriter out;
    void run() throws Exception{
        long ct = System.currentTimeMillis();
        if (fileIO) {
            in = new FastReader("");
            out = new PrintWriter("");
        } else {
            in = new FastReader();
            out = new PrintWriter(System.out);
        }
        

        int T = multipleTC? ni():1;
        pre();
        for (int t = 1; t <= T; t++) solve(t);
        out.flush();
        out.close();
        System.err.println(System.currentTimeMillis() - ct);
    }
    public static void main(String[] args) throws Exception{
        if(memory)new Thread(null, new Runnable() {public void run(){try{new id3().run();}catch(Exception e){e.printStackTrace();System.exit(1);}}}, "1", 1 << 28).start();
        else new id3().run();
    }
    int[][] make(int n, int e, int[] from, int[] to, boolean f){
        int[][] g = new int[n][];int[]cnt = new int[n];
        for(int i = 0; i< e; i++){
            cnt[from[i]]++;
            if(f)cnt[to[i]]++;
        }
        for(int i = 0; i< n; i++)g[i] = new int[cnt[i]];
        for(int i = 0; i< e; i++){
            g[from[i]][--cnt[from[i]]] = to[i];
            if(f)g[to[i]][--cnt[to[i]]] = from[i];
        }
        return g;
    }
    int[][][] makeS(int n, int e, int[] from, int[] to, boolean f){
        int[][][] g = new int[n][][];int[]cnt = new int[n];
        for(int i = 0; i< e; i++){
            cnt[from[i]]++;
            if(f)cnt[to[i]]++;
        }
        for(int i = 0; i< n; i++)g[i] = new int[cnt[i]][];
        for(int i = 0; i< e; i++){
            g[from[i]][--cnt[from[i]]] = new int[]{to[i], i, 0};
            if(f)g[to[i]][--cnt[to[i]]] = new int[]{from[i], i, 1};
        }
        return g;
    }
    int[][] make(int n, int[] par, boolean f){
        int[][] g = new int[n][];
        int[] cnt = new int[n];
        for(int i = 1; i< n; i++)cnt[par[i]]++;
        if(f)for(int i = 1; i< n; i++)cnt[i]++;
        for(int i = 0; i< n; i++)g[i] = new int[cnt[i]];
        for(int i = 1; i< n-1; i++){
            g[par[i]][--cnt[par[i]]] = i;
            if(f)g[i][--cnt[i]] = par[i];
        }
        return g;
    }
    int find(int[] set, int u){return set[u] = (set[u] == u?u:find(set, set[u]));}
    int digit(long s){int ans = 0;while(s>0){s/=10;ans++;}return ans;}
    long gcd(long a, long b){return (b==0)?a:gcd(b,a%b);}
    int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
    int bit(long n){return (n==0)?0:(1+bit(n&(n-1)));}
    void p(Object... o){for(Object oo:o)out.print(oo+" ");}
    void pn(Object... o){for(int i = 0; i< o.length; i++)out.print(o[i]+(i+1 < o.length?" ":"\n"));}
    void pni(Object... o){for(Object oo:o)out.print(oo+" ");out.println();out.flush();}
    String n()throws Exception{return in.next();}
    String nln()throws Exception{return in.nextLine();}
    int ni()throws Exception{return Integer.parseInt(in.next());}
    long nl()throws Exception{return Long.parseLong(in.next());}
    double nd()throws Exception{return Double.parseDouble(in.next());}

    class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastReader(String s) throws Exception{
            br = new BufferedReader(new FileReader(s));
        }

        String next() throws Exception{
            while (st == null || !st.hasMoreElements()){
                try{
                    st = new StringTokenizer(br.readLine());
                }catch (IOException  e){
                    throw new Exception(e.toString());
                }
            }
            return st.nextToken();
        }

        String nextLine() throws Exception{
            String str;
            try{
                str = br.readLine();
            }catch (IOException e){
                throw new Exception(e.toString());
            }
            return str;
        }
    }
}
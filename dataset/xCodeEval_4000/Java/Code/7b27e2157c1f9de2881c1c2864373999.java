
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.*;

public class Main {
    static long mod = 1;

    static class SegmentTree {

        static int l;
        static int r;
        static long v;
        static Node root;
        static long cache[];

        static void build(long f[]) {
            cache = f;
            root = new Node(0, f.length - 1);
        }

        static long query(int left, int right) {
            l = left;
            r = right;
            return root.query();
        }


        static void add_range(int left, int right, long value) {
            l = left;
            r = right;
            v = value;
            root.add_range();
        }

        static void multi_range(int left, int right, long value) {
            l = left;
            r = right;
            v = value;
            root.multi_range();
        }

        static void set_range(int left, int right) {
            l = left;
            r = right;
            

        }


        static class Node {
            

            long setv = 1;
            long add = 0;
            int left;
            int right;
            long min_value;
            Node l_node;
            Node r_node;

            public Node(int l, int r) {
                left = l;
                right = r;
                if (l == r) {
                    min_value = cache[l];
                } else {
                    int mid = (l + r) >> 1;
                    l_node = new Node(l, mid);
                    r_node = new Node(mid + 1, r);
                    pollup();
                }
            }

            private long query() {
                if (l <= left && r >= right) {
                    return min_value;
                } else if (l > right || r < left) {
                    return 0;
                } else {
                    pushdown();
                    long v1 = l_node.query();
                    long v2 = r_node.query();
                    pollup();
                    return (v1+v2)%mod;
                }
            }

            private void add_range() {
                if (l <= left && r >= right) {
                    add += v;
                    min_value += v *(right-left+1);
                } else if (l > right || r < left) {
                    return;
                } else {
                    pushdown();
                    l_node.add_range();
                    r_node.add_range();
                    pollup();
                }
            }

            private void multi_range() {
                if (l <= left && r >= right) {
                    setv *= v;
                    add = add*v;
                    min_value  = (min_value * v) % mod;
                } else if (l > right || r < left) {
                    return;
                } else {
                    pushdown();
                    l_node.multi_range();
                    r_node.multi_range();
                    pollup();
                }
            }


































            

            private void pushdown() {
                if (setv!=1) {

                    l_node.setv *= setv;
                    r_node.setv *= setv;
                    l_node.min_value = l_node.min_value*setv%mod;
                    r_node.min_value = r_node.min_value*setv%mod;
                    l_node.add = l_node.add*setv;
                    r_node.add = r_node.add*setv;
                    setv = 1;
                }
                if (add != 0) {
                    l_node.add += add;
                    r_node.add += add;
                    l_node.min_value += add * (l_node.right - l_node.left + 1 );
                    l_node.min_value %= mod;
                    r_node.min_value += add * (r_node.right - r_node.left + 1 );
                    r_node.min_value %= mod;
                    add = 0;
                }
            }

            private void pollup() {
                min_value = (l_node.min_value + r_node.min_value)%mod;
            }


        }
    }


    static class Task {

        public static String roundS(double result, int scale) {
            String fmt = String.format("%%.%df", scale);
            return String.format(fmt, result);




        }



        long[][] mult(long a[][],long b[][], long mod){
            int l1 = a.length;
            int l2 = b.length;
            int l3 = b[0].length;
            long r[][] = new long[l1][l3];
            for(int i=0;i<l1;++i){
                for(int j=0;j<l2;++j){
                    for(int k=0;k<l3;++k){
                        r[i][k] = (r[i][k] + a[i][j] * b[j][k]%mod)%mod;
                    }
                }
            }
            return r;
        }

        long[][] add(long a[][],long b[][],long mod){
            int l1 = a.length;
            int l2 = a[0].length;

            long r[][] = new long[l1][l2];
            for(int i=0;i<l1;++i){
                for(int j=0;j<l2;++j){
                    r[i][j] = (a[i][j] + b[i][j])%mod;
                }
            }
            return r;

        }

        long[][] ones(int len){
            long r[][] = new long[len][len];
            for(int i=0;i<len;++i){
                r[i][i] = 1L;
            }
            return r;
        }

        long[][] quick(long a[][], int times,long mod){
            int len = a.length;
            long ans[][] = ones(len);

            while(times>0){
                if((times&1)==1) {
                    ans = mult(ans, a, mod);
                }
                a = mult(a, a, mod);
                times >>= 1;
            }

            return ans;
        }


        long mb = 1535002967L;
        long p  = 1331;
        long hash[];long f[];

        long getHash(int i,int l){
            

            return (mb + (hash[i+l]  - f[l]*hash[i] )%mb)%mb;
        }



        void hash(String s){
            int len = s.length();
            hash = new long[len+1];
            f = new long[len+1];
            hash = new long[len+1];
            f[0] = 1;
            for(int j = 1;j<=len;++j){
                hash[j] = (hash[j-1]*p + s.charAt(j-1))%mb;
                f[j] = (f[j-1]*p)%mb;
            }











        }




        int[] to,ne,h,wt;
        void add(int u,int v,int w){
            to[ct] = v;
            ne[ct] = h[u];
            wt[ct] = w;
            h[u] =  ct++;

        }

        int ct= 0;
        int n;
        int m;

        void init(){
            h = new int[n];Arrays.fill(h,-1);
            to = new int[m];
            ne = new int[m];
        }

























        void dfs(int rt,int c,int fa){
            s[c]++;
            for(int to:g[rt]){
                if(to==fa) continue;
                dfs(to,1-c,rt);
            }
        }
        long r = 0;
        void dfs1(int rt,int c,int fa){
            long num = g[rt].size();

            r += s[1-c]-num;


            for(int to:g[rt]){
                if(to==fa) continue;
                dfs1(to,1-c,rt);
            }
        }
        List<Integer> g[];
        long s[] = new long[2];


        boolean next_perm(long[] a){
            int len = a.length;
            for(int i=len-2,j = 0;i>=0;--i){
                if(a[i]<a[i+1]){
                    j = len-1;
                    for(;a[j]<=a[i];--j);
                    long p = a[j];
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



        int lst(int h[]){
            int n  = h.length;
            int stk[] = new int[n];
            int p = 0;
            int mx = 0;

            int le[] = new int[n];
            int ri[] = new int[n];
            for(int j=0;j<n;++j){
                while(p>0&&h[stk[p-1]]>=h[j]){
                    p--;
                }
                int left = p>=1?stk[(p-1)]:-1;
                le[j] = left;
                stk[p++] = j;
            }
            p = 0;
            for(int j=n-1;j>=0;--j){
                while(p>0&&h[stk[p-1]]>=h[j]){
                    p--;
                }
                int left = p>=1?stk[(p-1)]:n;
                mx = Math.max(mx, (left-le[j]-1)*(h[j]));
                stk[p++] = j;
            }
            return mx;
        }

        long inv[];
        long C(int n,int m, long mod){
            if(m>n) return 0;
            return ((f[n]*inv[n-m]%mod)*inv[m])%mod;
        }

        void init11() {
            int n = 200000;
            f = new long[n + 1];
            f[0] = 1;
            mod = 1000000007;
            for (int i = 1; i <= n; ++i) {
                f[i] = f[i - 1] * i;
                f[i] %= mod;
            }
            

            inv = new long[n + 1];
            inv[n] = mod_pow(f[n], mod - 2, mod);
            for (int i = n - 1; i >= 0; --i) {
                inv[i] = inv[i + 1] * (i + 1) % mod;
            }
        }

        public long getMinimumPositiveAnswer(long a,long b,long r){
            long[] res = ex_gcd(a,b);
            if(r%res[2]==0){
                long mod = Math.abs(b/res[2]);
                long v1 = r/res[2];
                long minus = 1;
                if(v1>0&&res[0]<0||v1<=0&&res[0]>0){
                    minus = -1;
                }
                long x = mul(Math.abs(v1), Math.abs(res[0]), mod)*minus;
                return (x%mod+mod)%mod;
            }else{
                

                return -1;
            }
        }

        

        public static long[] ex_gcd(long a,long b){
            if(b==0) {
                return new long[]{1,0,a};
            }
            long []r = ex_gcd(b,a%b);
            return new long[]{r[1], r[0]-(a/b)*r[1], r[2]};
        }


        boolean hungry(int[] mc,boolean[] vis,int i){

            for(int j= h[i];j!=-1;j = ne[j]){
                int v = to[j];
                if(vis[v]) continue;
                vis[v] = true;
                if(mc[v]==-1||hungry(mc,vis,mc[v])){
                    mc[i] = v;
                    mc[v] = i;
                    return true;
                }
            }
            return false;
        }

        boolean gd(int i,int j,int c[][]){
           return  c[i][j] == c[i][j+1] && c[i][j] == c[i+1][j+1] && c[i][j] == c[i+1][j];
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {


            int n = in.nextInt();
            int m = in.nextInt();

            int c[][] = new int[n][m];
            int d[][] = new int[n][m];
            for(int i=0;i<n;++i){
                for(int j=0;j<m;++j){
                    c[i][j] = in.nextInt();
                }
            }
            int cnt = 0;

            boolean f[][] = new boolean[n-1][m-1];
            boolean v[][] = new boolean[n][m];

            Queue<int[]> q = new ArrayDeque<>();
            for(int i=0;i<n-1;++i) {
                for (int j = 0; j < m-1; ++j) {
                    if( gd(i,j,c)) {
                        q.offer(new int[]{i, j, c[i][j]});
                        f[i][j] = true;

                        v[i][j] = v[i][j+1] = v[i+1][j+1] = v[i+1][j] = true;

                        cnt++;
                    }
                }
            }
            int dx[] = {-1,-1,-1,1,1,1,0,0};
            int dy[] = {-1,0,1,-1,0,1,-1,1};

            List<int[]> li = new ArrayList<>();

            while(q.size()>0){
                int cur[] = q.poll();
                li.add(cur);

                for(int u=0;u<8;++u){
                    int nx = cur[0] + dx[u];
                    int ny = cur[1] + dy[u];

                    if(nx>=0&&ny>=0&&nx<n-1&&ny<m-1&&!f[nx][ny]){
                        if(v[nx][ny] && v[nx][ny+1] && v[nx+1][ny+1] && v[nx+1][ny]){
                            f[nx][ny] = true;

                            continue;
                        }
                        TreeSet<Integer> st  = new TreeSet<>();
                        for(int p=0;p<=1;++p){
                            for(int p1=0;p1<=1;++p1){
                                if(!v[nx+p][ny+p1]){
                                    st.add(c[nx+p][ny+p1]);
                                }
                            }
                        }
                        if(st.size()==1){
                            f[nx][ny] = true;
                            v[nx][ny] = v[nx][ny+1] = v[nx+1][ny+1] = v[nx+1][ny] = true;
                            q.offer(new int[]{nx,ny,st.pollFirst()});

                        }
                    }
                }

            }
            for(int i=0;i<n-1;++i) {
                for (int j = 0; j < m-1; ++j) {
                    if(!f[i][j]){
                        out.println(-1);
                                return;
                    }
                }
                }

            out.println(li.size());

            for(int i=li.size()-1;i>=0;--i){
                int u[] = li.get(i);
                out.println((u[0]+1) + " " +(u[1]+1) + " " + (u[2]));
            }












          

          



































































                



















































































































        }

        int len[];
        int mx[];
        int ans[];
        public void go(int rt,int fa){
            for(int i=h[rt];i!=-1;i=ne[i]){
                int t = to[i];
                if(t==fa) continue;
                go(t,rt);
                int ck = wt[i] + len[t];
                if(ck>len[rt]){
                    len[rt] = ck;
                    mx[rt] =  i;
                }
            }
        }


        public void go1(int rt,int fa,int dep){
            ans[rt] = dep;
            for(int i=h[rt];i!=-1;i=ne[i]){
                int t = to[i];
                if(t==fa) continue;
                go1(t,rt,dep+wt[i]);
                

            }
        }










































































































































































































































































































































































        boolean next_perm(int[] a) {
            int len = a.length;
            for (int i = len - 2, j = 0; i >= 0; --i) {
                if (a[i] < a[i + 1]) {
                    j = len - 1;
                    for (; a[j] <= a[i]; --j) ;
                    int p = a[j];
                    a[j] = a[i];
                    a[i] = p;
                    j = i + 1;
                    for (int ed = len - 1; j < ed; --ed) {
                        p = a[ed];
                        a[ed] = a[j];
                        a[j++] = p;
                    }
                    return true;
                }
            }
            return false;
        }


        static long mul(long a, long b, long p) {
            long res = 0, base = a;

            while (b > 0) {
                if ((b & 1L) > 0)
                    res = (res + base) % p;

                base = (base + base) % p;
                b >>= 1;
            }

            return res;
        }

        static long mod_pow(long k, long n, long p) {
            long res = 1L;
            long temp = k % p;

            while (n != 0L) {
                if ((n & 1L) == 1L) {
                    res = mul(res, temp, p);
                }

                temp = mul(temp, temp, p);
                n = n >> 1L;
            }

            return res % p;
        }


        public static double roundD(double result, int scale) {
            BigDecimal bg = new BigDecimal(result).setScale(scale, RoundingMode.UP);
            return bg.doubleValue();
        }


    }

    private static void solve() {
        InputStream inputStream = System.in;












        OutputStream outputStream = System.out;
























        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task task = new Task();
        task.solve(1, in, out);
        out.flush();
        out.close();
    }

    public static void main(String[] args) {
        new Thread(null, () -> solve(), "1", (1 << 30)).start();
        

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String nextLine() {
            String line = null;

            try {
                line = reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }

            return line;
        }



        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }

            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public char nextChar() {
            return next().charAt(0);
        }

        public int[] nextArray(int n) {
            int res[] = new int[n];

            for (int i = 0; i < n; ++i) {
                res[i] = nextInt();
            }

            return res;
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }


    }
}
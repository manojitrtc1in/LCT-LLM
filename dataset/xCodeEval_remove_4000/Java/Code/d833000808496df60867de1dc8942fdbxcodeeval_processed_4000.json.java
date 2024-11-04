import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;



public class Main{

    class Multiset<T> extends java.util.TreeMap<T,Long>{
        public Multiset(){
            super();
        }
        public Multiset(java.util.List<T> list){
            super();
            for(T e: list) this.addOne(e);
        }
        public long count(Object elm){
            return getOrDefault(elm,0L);
        }
        public void add(T elm, long amount){
            if(!this.containsKey(elm)) put(elm, amount);
            else replace(elm, get(elm)+amount);
            if(this.count(elm)==0) this.remove(elm);
        }
        public void addOne(T elm){
            this.add(elm, 1);
        }
        public void removeOne(T elm){
            this.add(elm, -1);
        }
        public void removeAll(T elm){
            this.add(elm, -this.count(elm));
        }
    }

    class UnionFind{
        int n;
        int[] parent;
        int[] size;
        public UnionFind(int n){
            this.n = n;
            parent = new int[n];
            size = new int[n];
            for(int i = 0; i < n; i++) parent[i] = i;
            Arrays.fill(size, 1);
        }
        public boolean union(int i, int j) {
            int pi = find(i), pj = find(j);
            if(pi != pj) {
                if(size[pi] < size[pj]) {
                    parent[pi] = pj;
                    size[pj] += size[pi];
                } else {
                    parent[pj] = pi;
                    size[pi] += size[pj];
                }
                return true;
            }
            return false;
        }
        public int find(int i) {
            if(parent[i] != i) parent[i] = find(parent[i]);
            return parent[i];
        }
    }
    static long MOD = 1_000_000_007L;
    

    

    static long inv2 = (MOD + 1) / 2;

    static int[][] dir = new int[][]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    static final long LMAX = 0x3f3f3f3f3f3f3f3fL;
    static final int IMAX = 0x3f3f3f3f;
    static HashMap <Long, Long> memo = new HashMap();
    static MyScanner sc = new MyScanner();
    


    static int nn = 300000;
    static long[] pow2;
    static long [] fac;
    static long [] pow;
    static long [] inv;
    static long [] facInv;
    static int[] base;
    static int[] id3;
    static int[] id2;
    static ArrayList <Integer> primes;
    

    static int ptr = 0;
    static boolean[] isPrime;

    

    public static PrintWriter out;
    public static void main(String[] args) {
        out = new PrintWriter(new BufferedOutputStream(System.out));
        




        


        


        

        


        

        

        


        int t = 1;
        t = sc.ni();
        while(t-- > 0) {
            solve();
        }
        out.close();
    }
    static long[] x, y, p;

    static void solve() {
        
        

        

        

        int n = sc.ni();
        int[][] a = new int[n][2];
        long max = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            a[i][0] = sc.ni();
            a[i][1] = sc.ni();
            Arrays.sort(a[i]);
            max = Math.max(max, a[i][1]);
            sum += a[i][0];
        }
        out.println((max + sum) << 1);
    }

    public static int[] dist( ArrayList <Integer>[] nei, int s) {
        int n = nei.length;
        int[] dist = new int[n];
        Arrays.fill(dist, IMAX);
        ArrayDeque <Integer> dq = new ArrayDeque<>();
        int cur = 1;
        dist[s] = 0;
        dq.add(s);
        while(!dq.isEmpty()) {
            for(int ii = dq.size(); ii > 0; ii --) {
                int tmp = dq.pollFirst();
                for(int i : nei[tmp]) {
                    if(dist[i] != IMAX) continue;
                    dist[i] = cur;
                    dq.addLast(i);
                }
            }
            cur++;
        }
        return dist;
    }


    public static boolean valid(int n, long s) {
        for(int i = 0; i < n; i++) {
            int cnt = 1;
            boolean[] vis = new boolean[n];
            ArrayDeque <Integer> dq = new ArrayDeque<>();
            dq.add(i);
            vis[i] = true;
            while(!dq.isEmpty()) {
                int tmp = dq.pollFirst();
                for(int j = 0; j < n; j++) {
                    if(vis[j]) continue;
                    if(s < (Math.abs(x[j] - x[tmp]) + Math.abs(y[j] - y[tmp]) + p[tmp] - 1) / p[tmp] ) continue;
                    vis[j] = true;
                    dq.addLast(j);
                    cnt++;
                }
            }
            if(cnt == n) return true;
        }
        return false;
    }


    

    public static int[][] packU(int n, int[] from, int[] to) {
        return packU(n, from, to, from.length);
    }

    public static int[][] packU(int n, int[] from, int[] to, int sup) {
        int[][] g = new int[n][];
        int[] p = new int[n];
        for (int i = 0; i < sup; i++) p[from[i]]++;
        for (int i = 0; i < sup; i++) p[to[i]]++;
        for (int i = 0; i < n; i++) g[i] = new int[p[i]];
        for (int i = 0; i < sup; i++) {
            g[from[i]][--p[from[i]]] = to[i];
            g[to[i]][--p[to[i]]] = from[i];
        }
        return g;
    }

    

    public static int[] diameter(int[][] g) {
        int n = g.length;
        int f0 = -1, f1 = -1, d01 = -1;
        int[] q = new int[n];
        boolean[] ved = new boolean[n];
        {
            int qp = 0;
            q[qp++] = 0; ved[0] = true;
            for(int i = 0;i < qp;i++){
                int cur = q[i];
                for(int e : g[cur]){
                    if(!ved[e]){
                        ved[e] = true;
                        q[qp++] = e;
                        continue;
                    }
                }
            }
            f0 = q[n-1];
        }
        {
            int[] d = new int[n];
            int qp = 0;
            Arrays.fill(ved, false);
            q[qp++] = f0; ved[f0] = true;
            for(int i = 0;i < qp;i++){
                int cur = q[i];
                for(int e : g[cur]){
                    if(!ved[e]){
                        ved[e] = true;
                        q[qp++] = e;
                        d[e] = d[cur] + 1;
                        continue;
                    }
                }
            }
            f1 = q[n-1];
            d01 = d[f1];
        }
        return new int[]{d01, f0, f1};
    }

    public static long c(int n, int k) {
        return (fac[n] * facInv[k] % MOD) * facInv[n - k] % MOD;
    }


    

    public static class id0 {
        public int M, H, N;
        public int[] st;

        public id0(int n)
        {
            N = n;
            M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
            H = M>>>1;
            st = new int[M];
            Arrays.fill(st, 0, M, Integer.MAX_VALUE);
        }

        public id0(int[] a)
        {
            N = a.length;
            M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
            H = M>>>1;
            st = new int[M];
            for(int i = 0;i < N;i++){
                st[H+i] = a[i];
            }
            Arrays.fill(st, H+N, M, Integer.MAX_VALUE);
            for(int i = H-1;i >= 1;i--)propagate(i);
        }

        public void update(int pos, int x)
        {
            st[H+pos] = x;
            for(int i = (H+pos)>>>1;i >= 1;i >>>= 1)propagate(i);
        }

        private void propagate(int i)
        {
            st[i] = Math.min(st[2*i], st[2*i+1]);
        }

        public int minx(int l, int r){
            int min = Integer.MAX_VALUE;
            if(l >= r)return min;
            while(l != 0){
                int f = l&-l;
                if(l+f > r)break;
                int v = st[(H+l)/f];
                if(v < min)min = v;
                l += f;
            }

            while(l < r){
                int f = r&-r;
                int v = st[(H+r)/f-1];
                if(v < min)min = v;
                r -= f;
            }
            return min;
        }

        public int min(int l, int r){ return l >= r ? 0 : min(l, r, 0, H, 1);}

        private int min(int l, int r, int cl, int cr, int cur)
        {
            if(l <= cl && cr <= r){
                return st[cur];
            }else{
                int mid = cl+cr>>>1;
                int ret = Integer.MAX_VALUE;
                if(cl < r && l < mid){
                    ret = Math.min(ret, min(l, r, cl, mid, 2*cur));
                }
                if(mid < r && l < cr){
                    ret = Math.min(ret, min(l, r, mid, cr, 2*cur+1));
                }
                return ret;
            }
        }
    }

    public static char[] rev(char[] a){char[] b = new char[a.length];for(int i = 0;i < a.length;i++)b[a.length-1-i] = a[i];return b;}

    public static double dist(double a, double b){
        return Math.sqrt(a * a + b * b);
    }

    public static long inv(long a){
        return id1(a, MOD - 2);
    }

    public class Interval {
        int start;
        int end;
        public Interval(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }

    public static ArrayList<Integer> id4(int n) {
        boolean prime[] = new boolean[n + 1];
        Arrays.fill(prime, true);
        for (int p = 2; p * p <= n; p++) {
            if (prime[p]) {
                for (int i = p * 2; i <= n; i += p) {
                    prime[i] = false;
                }
            }
        }
        ArrayList<Integer> primeNumbers = new ArrayList<>();
        for (int i = 2; i <= n; i++) {
            if (prime[i]) {
                primeNumbers.add(i);
            }
        }
        return primeNumbers;
    }


    public static int lowerBound(int[] a, int v){ return lowerBound(a, 0, a.length, v); }
    public static int lowerBound(int[] a, int l, int r, int v)
    {
        if(l > r || l < 0 || r > a.length)throw new IllegalArgumentException();
        int low = l-1, high = r;
        while(high-low > 1){
            int h = high+low>>>1;
            if(a[h] >= v){
                high = h;
            }else{
                low = h;
            }
        }
        return high;
    }
    public static int id5(int[] a, int v){ return lowerBound(a, 0, a.length, v); }
    public static int id5(int[] a, int l, int r, int v)
    {
        if(l > r || l < 0 || r > a.length)throw new IllegalArgumentException();
        int low = l-1, high = r;
        while(high-low > 1){
            int h = high+low>>>1;
            if(a[h] <= v){
                high = h;
            }else{
                low = h;
            }
        }
        return high;
    }
    public static long C(int n, int m)
    {
        if(m == 0 || m == n) return 1L;
        if(m > n || m < 0) return 0L;
        long res = fac[n] * id1((fac[m] * fac[n - m]) % MOD, MOD - 2) % MOD;

        return res;
    }
    public static long id1(long n, long m)
    {
        long ans = 1L;
        while(m > 0)
        {
            if(m % 2 == 1)
                ans = (ans * n) % MOD;
            n = (n * n) % MOD;
            m >>= 1;
        }
        return ans;
    }
    public static long id1(long n, long m, long mod)
    {
        long ans = 1L;
        while(m > 0)
        {
            if(m % 2 == 1)
                ans = (ans * n) % mod;
            n = (n * n) % mod;
            m >>= 1;
        }
        return ans;
    }

    public static int gcd(int a, int b)
    {
        if(a % b == 0) return b;
        return gcd(b, a % b);
    }
    public static long gcd(long a, long b)
    {
        if(a % b == 0) return b;
        return gcd(b, a % b);
    }

    static class Randomized {
        public static void shuffle(int[] data) {
            shuffle(data, 0, data.length - 1);
        }

        public static void shuffle(int[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                int tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static void shuffle(long[] data) {
            shuffle(data, 0, data.length - 1);
        }

        public static void shuffle(long[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                long tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static int nextInt(int l, int r) {
            return RandomWrapper.INSTANCE.nextInt(l, r);
        }
    }

    static class RandomWrapper {
        private Random random;
        public static final RandomWrapper INSTANCE = new RandomWrapper(new Random());

        public RandomWrapper() {
            this(new Random());
        }

        public RandomWrapper(Random random) {
            this.random = random;
        }

        public int nextInt(int l, int r) {
            return random.nextInt(r - l + 1) + l;
        }

    }


    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int ni() {
            return Integer.parseInt(next());
        }
        int[] na(int n) {
            int[] arr = new int[n];
            for(int i = 0; i < n; i++) arr[i] = sc.ni();
            return arr;
        }

        int[] na(int n, int m) {
            int[] arr = new int[n];
            for(int i = 0; i < m; i++) arr[i] = sc.ni();
            return arr;
        }

        long[] nal(int n) {
            long[] arr = new long[n];
            for(int i = 0; i < n; i++) arr[i] = sc.nl();
            return arr;
        }
        long nl() {
            return Long.parseLong(next());
        }
        double nd() {
            return Double.parseDouble(next());
        }
        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    

}
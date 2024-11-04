
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.function.BinaryOperator;
import java.util.stream.Collectors;


public class Main {
    private final static long mod = 1000000007;

    private final static int MAXN = 1000001;

    private static long power(long x, long y, long m) {
        long temp;
        if (y == 0)
            return 1;
        temp = power(x, y / 2, m);
        temp = (temp * temp) % m;
        if (y % 2 == 0)
            return temp;
        else
            return ((x % m) * temp) % m;
    }

    private static long power(long x, long y) {
        return power(x, y, mod);
    }

    private static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    static int id22(int a) {
        return 1 << id14(a);
    }

    static int id14(int a) {
        return (a == 0 ? 0 : 32 - Integer.numberOfLeadingZeros(a - 1));
    }

    private static long modInverse(long a, long m) {
        long m0 = m;
        long y = 0, x = 1;
        if (m == 1)
            return 0;
        while (a > 1) {
            long q = a / m;
            long t = m;
            m = a % m;
            a = t;
            t = y;
            y = x - q * y;
            x = t;
        }
        if (x < 0)
            x += m0;
        return x;
    }

    private static int[] id6(int n) {
        int arr[] = new int[n + 1];
        for (int i = 1; i < n + 1; i++) {
            arr[i] = (int) (Math.log(i) / Math.log(2) + 1e-10);
        }
        return arr;
    }

    private static int log[] = id6(MAXN);

    private static long id13(long st[][], int L, int R, BinaryOperator<Long> binaryOperator) {
        int j = log[R - L + 1];
        return binaryOperator.apply(st[L][j], st[R - (1 << j) + 1][j]);
    }

    private static long[][] id1(int array[], BinaryOperator<Long> binaryOperator) {
        int k = log[array.length + 1] + 1;
        long st[][] = new long[array.length + 1][k + 1];

        for (int i = 0; i < array.length; i++)
            st[i][0] = array[i];

        for (int j = 1; j <= k; j++) {
            for (int i = 0; i + (1 << j) <= array.length; i++) {
                st[i][j] = binaryOperator.apply(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
        return st;
    }

    static class Subset {
        int parent;
        int rank;

        @Override
        public String toString() {
            return "" + parent;
        }
    }

    static int find(Subset[] subsets, int i) {
        if (subsets[i].parent != i)
            subsets[i].parent = find(subsets, subsets[i].parent);
        return subsets[i].parent;
    }

    static void union(Subset[] subsets, int x, int y) {
        int xroot = find(subsets, x);
        int yroot = find(subsets, y);
        if (subsets[xroot].rank < subsets[yroot].rank)
            subsets[xroot].parent = yroot;
        else if (subsets[yroot].rank < subsets[xroot].rank)
            subsets[yroot].parent = xroot;
        else {
            subsets[xroot].parent = yroot;
            subsets[yroot].rank++;
        }
    }


    private static int maxx(Integer... a) {
        return Collections.max(Arrays.asList(a));
    }

    private static int minn(Integer... a) {
        return Collections.min(Arrays.asList(a));
    }


    private static long maxx(Long... a) {
        return Collections.max(Arrays.asList(a));
    }

    private static long minn(Long... a) {
        return Collections.min(Arrays.asList(a));
    }

    private static class Pair<T extends Comparable<T>, U extends Comparable<U>> implements Comparable<Pair<T, U>> {
        T a;
        U b;

        public Pair(T a, U b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || this.getClass() != o.getClass()) return false;
            Pair pair = (Pair) o;
            return a.equals(pair.a) &&
                    b.equals(pair.b);
        }

        @Override
        public int hashCode() {
            return Objects.hash(a, b);
        }

        @Override
        public String toString() {
            return "(" + a +
                    "," + b +
                    ')';
        }

        @Override
        public int compareTo(Pair<T, U> o) {
            return (this.a.equals(o.a) ? this.b.equals(o.b) ? 0 : this.b.compareTo(o.b) : this.a.compareTo(o.a));
        }
    }


    public static int upperBound(int[] list, int l, int r, long value) {
        int low = l;
        int high = r + 1;
        while (low < high) {
            final int mid = (low + high) / 2;
            if (value >= list[mid]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }


    private static int[] id7(String pattern) {
        int i, j, n = pattern.length();
        int[] lps = new int[pattern.length()];
        lps[0] = 0;
        for (i = 1, j = 0; i < n; ) {
            if (pattern.charAt(i) == pattern.charAt(j)) {
                lps[i++] = ++j;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }

    static void reverse(char A[], int l, int h) {
        if (l < h) {
            char ch = A[l];
            A[l] = A[h];
            A[h] = ch;
            reverse(A, l + 1, h - 1);
        }
    }

    private static List<Integer> findPattern(String text, String pattern) {
        List<Integer> matchedIndexes = new ArrayList<>();
        if (pattern.length() == 0) {
            return matchedIndexes;
        }
        int[] lps = id7(pattern);
        int i = 0, j = 0, n = text.length(), m = pattern.length();
        while (i < n) {
            if (text.charAt(i) == pattern.charAt(j)) {
                i++;
                j++;
            }
            if (j == m) {
                matchedIndexes.add(i - j);
                j = lps[j - 1];
            }
            if (i < n && text.charAt(i) != pattern.charAt(j)) {
                if (j > 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return matchedIndexes;
    }

    private static Set<Long> id18(long n) {
        Set<Long> id0 = new HashSet<>();
        for (long i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                id0.add(i);
                id0.add(n / i);
            }
        }
        return id0;
    }

    private static long id17(long a, long b) {
        return (Math.max(a, b) / gcd(a, b)) * Math.min(a, b);
    }

    static long fac[] = new long[2000005];
    static long ifac[] = new long[2000005];

    private static void preCompute(int n) {
        fac = new long[n + 1];
        ifac = new long[n + 1];
        fac[0] = ifac[0] = fac[1] = ifac[1] = 1;
        int i;
        for (i = 2; i < n + 1; i++) {
            fac[i] = (i * fac[i - 1]) % mod;
            ifac[i] = (power(i, mod - 2) * ifac[i - 1]) % mod;
        }
    }

    private static long C(int n, int r) {
        if (n < 0 || r < 0) return 1;
        if (r > n) return 1;
        return (fac[n] * ((ifac[r] * ifac[n - r]) % mod)) % mod;
    }



    static long getSum(long BITree[], int index) {
        long sum = 0;
        index = index + 1;
        while (index > 0) {
            sum += BITree[index];
            index -= index & (-index);
        }
        return sum;
    }

    public static void updateBIT(long BITree[], int index, long val) {
        index = index + 1;
        while (index <= BITree.length - 1) {
            BITree[index] += val;
            index += index & (-index);
        }
    }

    long[] id19(int arr[], int m) {
        int n = arr.length;
        long BITree[] = new long[m + 1];
        for (int i = 1; i <= n; i++)
            BITree[i] = 0;
        for (int i = 0; i < n; i++)
            updateBIT(BITree, i, arr[i]);
        return BITree;
    }


    private static int upperBound(int a[], int l, int r, int x) {
        if (l > r) return -1;
        if (l == r) {
            if (a[l] <= x) {
                return -1;
            } else {
                return a[l];
            }
        }
        int m = (l + r) / 2;
        if (a[m] <= x) {
            return upperBound(a, m + 1, r, x);
        } else {
            return upperBound(a, l, m, x);
        }
    }


    private static void mul(long A[][], long B[][]) {
        int i, j, k, n = A.length;
        long C[][] = new long[n][n];
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                for (k = 0; k < n; k++) {
                    C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % mod) % mod;
                }
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                A[i][j] = C[i][j];
            }
        }
    }

    private static void power(long A[][], long base[][], long n) {
        if (n < 2) {
            return;
        }
        power(A, base, n / 2);
        mul(A, A);
        if (n % 2 == 1) {
            mul(A, base);
        }
    }

    private static long fib(long n) {
        long f[][] = new long[][]{{1, 1}, {1, 0}};
        long b[][] = new long[][]{{1, 1}, {1, 0}};
        if (n == 0) return 0;
        power(f, b, n - 1);
        return f[0][0];
    }

    private static void print(int... a) {
        System.out.println(Arrays.toString(a));
    }

    static void reverse(Integer a[], int l, int r) {
        while (l < r) {
            int t = a[l];
            a[l] = a[r];
            a[r] = t;
            l++;
            r--;
        }
    }


    public int numWays(String s) {
        long n = s.length();
        long one = 0;
        long mod = 1_000_000_007;
        char[] c = s.toCharArray();
        for (char value : c) {
            if (value == '1')
                one++;
        }
        if (one == 0) {
            return (int) ((((n - 1) * (n - 2)) / 2) % mod);
        }
        if (one % 3 != 0)
            return 0;
        long ones = one / 3;
        one = 0;
        long part1 = 0;
        long part2 = 0;
        for (char value : c) {
            if (value == '1')
                one++;
            if (one == ones)
                part1++;
            if (one == 2 * ones)
                part2++;
        }
        return (int) ((part1 * part2) % mod);
    }

    public void rotate(Integer[] nums, int k) {
        k = k % nums.length;
        reverse(nums, 0, nums.length - k - 1);
        reverse(nums, nums.length - k, nums.length - 1);
        reverse(nums, 0, nums.length - 1);
    }

    private static boolean isSorted(int a[]) {
        for (int i = 0; i < a.length - 1; i++) {
            if (a[i] > a[i + 1]) return false;
        }
        return true;
    }

    public int minimumDeviation(int[] nums) {
        int lo = 1, hi = 1000000000, mid, i, j, n = nums.length, ans;
        Arrays.sort(nums);
        ans = nums[n - 1] - nums[0];
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            int mx = 1;
            int mn = 1000000000;
            for (i = 0; i < n; i++) {
                j = nums[i];
                if (j < mid && j % 2 == 1) {
                    j *= 2;
                }
                while (j > mid && j % 2 == 0) {
                    j /= 2;
                }
                mx = Math.max(mx, j);
                mn = Math.min(mn, j);
            }
            ans = Math.min(ans, mx - mn);
            if (Math.abs(mx - mid) > Math.abs(mn - mid)) {
                lo = mid + 1;
            } else hi = mid - 1;
        }
        return ans;
    }

    private static String reverse(String s) {
        if ("".equals(s)) return "";
        return reverse(s.substring(1)) + s.charAt(0);
    }

    private static boolean isPrime(int n) {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        return true;
    }

    private static int maxIndex(int steps, int badIndex) {
        boolean dp[] = new boolean[steps * (steps + 1) / 2 + 1];
        int last = 0;
        dp[0] = true;
        for (int i = 1; i <= steps; i++) {
            for (int j = last; j >= 0; j--) {
                if (i + j != badIndex) {
                    dp[i + j] = true;
                    last = Math.max(last, i + j);
                }
            }
        }
        return last;
    }

    private static void addEdge(List<List<Pair<Long, Integer>>> adj, int x, int y, long w) {
        x--;
        y--;
        adj.get(x).add(new Pair<>(w,y));
        adj.get(y).add(new Pair<>(w,x));
    }

    private static void dijkstra(List<List<Pair<Long, Integer>>> graph, int src, int n, long dist[], long paths[]) {
        PriorityQueue<Pair<Long, Pair<Integer,Long>>> pq = new PriorityQueue<>(n);
        Set<String> settled = new HashSet<>();
        pq.add(new Pair<>(0L, new Pair<>(0, 1L)));
        dist[src] = 0;
        paths[src] = 1;
        while (!pq.isEmpty()) {
            long it=pq.peek().b.b;
            int u = pq.peek().b.a;
            long d = pq.peek().a*it;
            pq.poll();
            for (Pair<Long,Integer>p:graph.get(u)) {
                int to = p.b;
                long cost = p.a*it;
                if (settled.contains(to + " " + u))
                    continue;
                if (dist[to] > dist[u] + cost) {
                    pq.add(new Pair<>(d + cost, new Pair<>(to,it+1)));
                    dist[to] = dist[u] + cost;
                    paths[to] = paths[u];
                }
                else if (dist[to] == dist[u] + cost) {
                    paths[to] = (paths[to] + paths[u]);
                }
                settled.add(to + " " + u);
            }
        }
    }

    private static long[] id5(List<List<Pair<Long, Integer>>> graph, int s, int n) {
        long[] dist = new long[n + 5];
        long[] paths = new long[n + 5];

        for (int i = 0; i < n; i++)
            dist[i] = Long.MAX_VALUE;

        for (int i = 0; i < n; i++)
            paths[i] = 0;
        dijkstra(graph, s, n, dist, paths);
        return dist;
    }

    public static long[] solve(int n, int[][] roads) {
        List<List<Pair<Long, Integer>>> graph=new ArrayList<>();
        Map<Pair<Integer,Integer>,Long>ewMap=new HashMap<>();
        for(int r[]:roads){
            if(r[0]==r[1])continue;
            if(r[1]<r[0]){
                int x=r[1];
                r[1]=r[0];
                r[0]=x;
            }
            Pair<Integer,Integer>p=new Pair<>(r[0],r[1]);
            long v=ewMap.getOrDefault(p, Long.MAX_VALUE);
            v=Math.min(v,r[2]);
            ewMap.put(p,v);
        }
        for(int i=0;i<n;i++){
            graph.add(new ArrayList<>());
        }
        for(Pair<Integer,Integer>p:ewMap.keySet()){
            addEdge(graph,p.a,p.b,ewMap.get(p));
        }
        return id5(graph,0,n);
    }

    private static String getKey(int a[]){
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<a.length-1;i++){
            sb.append(a[i]).append(',');
        }
        return sb.toString();
    }


    public static void main(String[] args) throws Exception {
        long START_TIME = System.currentTimeMillis();
        try (FastReader in = new FastReader();
             FastWriter out = new FastWriter()) {
            int n, t, i, j, f, m, ti, tidx, gm, q, g, l = 1, r = 2, c, k;
            for (t = in.nextInt(), tidx = 1; tidx <= t; tidx++)
            {
                long x = 0, y = 0, z = 0, sum = 0, bhc = 0, ans;
                n=in.nextInt();
                String s=in.next();
                String b=in.next();
                int state[]=new int[5];
                for(i=0;i<n;i++){
                    state[(2*(s.charAt(i)-'0')+b.charAt(i)-'0')]++;
                }
                if(state[2]==0&&state[1]==0){
                    out.println(0);
                }else if(state[2]==0&&state[3]==0){
                    out.println(-1);
                }
                else {
                    ans=-1;
                    Queue<int[]>dq=new ArrayDeque<>();
                    Set<String>vis=new HashSet<>();
                    vis.add(getKey(state));
                    dq.add(state);
                    k=0;
                    while(!dq.isEmpty()) {
                        int cs[]=dq.poll();
                        if(cs[1]==0&&cs[2]==0){
                            ans=cs[4];
                            break;
                        }
                        if(cs[2]==0&&cs[3]==0)continue;
                        if (cs[2] > 0) {
                            int ncs[] = new int[]{cs[2] - 1, cs[3], cs[0] + 1, cs[1], cs[4] + 1};
                            if(ncs[1]==0&&ncs[2]==0){
                                ans=ncs[4];
                                break;
                            }
                            String key = getKey(ncs);
                            if (!vis.contains(key)) {
                                dq.add(ncs);
                                vis.add(key);
                            }

                        }
                        if (cs[3] > 0) {
                            int ncs[] = new int[]{cs[2], cs[3] - 1, cs[0], cs[1] + 1, cs[4] + 1};
                            if(ncs[1]==0&&ncs[2]==0){
                                ans=ncs[4];
                                break;
                            }
                            String key = getKey(ncs);
                            if (!vis.contains(key)) {
                                dq.add(ncs);
                                vis.add(key);
                            }
                        }
                    }
                    out.println(ans);
                }
            }
            if (args.length > 0 && "ex_time".equals(args[0])) {
                out.print("\nTime taken: ");
                out.println(System.currentTimeMillis() - START_TIME);
            }
            out.commit();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }


    public static class FastReader implements Closeable {
        private BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        private StringTokenizer st;

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        int[] id16(int n) {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextInt();
            }
            return arr;
        }

        Integer[] id4(int n) {
            Integer[] arr = new Integer[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextInt();
            }
            return arr;
        }

        double[] id21(int n) {
            double[] arr = new double[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextDouble();
            }
            return arr;
        }

        long[] id12(int n) {
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextLong();
            }
            return arr;
        }

        List<Long> id11(int n) {
            List<Long> retList = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                retList.add(nextLong());
            }
            return retList;
        }

        String[] id20(int n) {
            String[] arr = new String[n];
            for (int i = 0; i < n; i++) {
                arr[i] = next();
            }
            return arr;
        }


        int[][] id15(int n, int m) {
            int[][] arr = new int[n][m];
            for (int i = 0; i < n; i++) {
                arr[i] = id16(m);
            }
            return arr;
        }

        long[][] id2(int n, int m) {
            long[][] arr = new long[n][m];
            for (int i = 0; i < n; i++) {
                arr[i] = id12(m);
            }
            return arr;
        }

        @Override
        public void close() throws IOException {
            br.close();
        }
    }


    public static class FastWriter implements Closeable {
        BufferedWriter bw;
        StringBuilder sb = new StringBuilder();
        List<String> list = new ArrayList<>();
        Set<String> set = new HashSet<>();

        public FastWriter() {
            bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }

        <T> void commit() throws IOException {
            bw.write(sb.toString());
            bw.flush();
            sb = new StringBuilder();
        }

        public <T> void print(T obj) throws IOException {
            sb.append(obj.toString());
            

        }

        public void println() throws IOException {
            print("\n");
        }

        public <T> void println(T obj) throws IOException {
            print(obj.toString() + "\n");
        }

        <T> void id9(T[] arr) throws IOException {
            for (int i = 0; i < arr.length - 1; i++) {
                print(arr[i] + " ");
            }
            println(arr[arr.length - 1]);
        }

        <T> void id10(T[][] arr) throws IOException {
            for (int j = 0; j < arr.length; j++) {
                for (int i = 0; i < arr[j].length - 1; i++) {
                    print(arr[j][i] + " ");
                }
                println(arr[j][arr[j].length - 1]);
            }
        }

        <T> void printColl(Collection<T> coll) throws IOException {
            List<String> stringList = coll.stream().map(e -> "" + e).collect(Collectors.toList());
            println(String.format("%s", String.join(" ", stringList)));
        }

        void id8(char c, int n) throws IOException {
            for (int i = 0; i < n; i++) {
                print(c);
            }
        }

        void id3(int[][] arr) throws IOException {
            for (int j = 0; j < arr.length; j++) {
                for (int i = 0; i < arr[j].length - 1; i++) {
                    print(arr[j][i] + " ");
                }
                println(arr[j][arr[j].length - 1]);
            }
        }

        @Override
        public void close() throws IOException {
            bw.close();
        }

    }

}
import java.io.*;
import java.util.*;
import java.util.function.BinaryOperator;


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

    static int id21(int a) {
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

    private static int id13(int st[][], int L, int R, BinaryOperator<Integer> binaryOperator) {
        int j = log[R - L + 1];
        return binaryOperator.apply(st[L][j], st[R - (1 << j) + 1][j]);
    }

    private static int[][] id1(int array[], BinaryOperator<Integer> binaryOperator) {
        int k = log[array.length + 1] + 1;
        int st[][] = new int[array.length + 1][k + 1];

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

    static int find(Subset[] Subsets, int i) {
        if (Subsets[i].parent != i)
            Subsets[i].parent = find(Subsets, Subsets[i].parent);
        return Subsets[i].parent;
    }

    static void union(Subset[] Subsets, int x, int y) {
        int xroot = find(Subsets, x);
        int yroot = find(Subsets, y);

        if (Subsets[xroot].rank < Subsets[yroot].rank)
            Subsets[xroot].parent = yroot;
        else if (Subsets[yroot].rank < Subsets[xroot].rank)
            Subsets[yroot].parent = xroot;
        else {
            Subsets[xroot].parent = yroot;
            Subsets[yroot].rank++;
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

    private static class Pair<T, U> implements Comparable<Pair<T, U>> {
        T a;
        U b;

        public Pair(T a, U b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
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
            return (int) (this.a.equals(o.a) ?
                    this.b.equals(o.b) ? 0 :
                            ((Integer) this.b - (Integer) o.b) / Math.abs((Integer) this.b - (Integer) o.b) :
                    ((Integer) this.a - (Integer) o.a) / Math.abs((Integer) this.a - (Integer) o.a));
        }
    }


    private static boolean id11(long n) {
        if (n % mod == 0 || n < 2) return false;
        if (n > 2 && n % 2 == 0) return false;
        return (power((mod - 1), n, n) == (power(mod, n, n) - 1 + n) % n);
    }

    public static int upperBound(List<Integer> list, int value) {
        int low = 0;
        int high = list.size();
        while (low < high) {
            final int mid = (low + high) / 2;
            if (value >= list.get(mid)) {
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

    private static Set<Long> id17(long n) {
        Set<Long> id0 = new HashSet<>();
        id0.add(1L);
        id0.add(n);
        for (long i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                id0.add(i);
                id0.add(n / i);
            }
        }
        return id0;
    }

    private static long id16(long a, long b) {
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

    public static long solve(int n) {
        long dp[][] = new long[n + 1][6];
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                dp[i + 1][j + 1] = dp[i][j];
            }
            dp[i + 1][0] += dp[i][1] + dp[i][3];
        }
        long ans = 0;
        for (int i = 0; i < 5; i++) {
            ans += dp[n][i];
        }
        return ans;
    }

    static long getSum(long BITree[], int index)
    {
        long sum = 0;
        index = index + 1;
        while(index>0)
        {
            index -= index & (-index);
        }
        return sum;
    }

    public static void updateBIT(long BITree[], int index, long val)
    {
        index = index + 1;
        while(index <= BITree.length-1) {
            BITree[index] += val;
            index += index & (-index);
        }
    }
    long[] id18(int arr[], int m)
    {
        int n=arr.length;
        long BITree[] = new long[m+1];
        for(int i=1; i<=n; i++)
            BITree[i] = 0;
        for(int i = 0; i < n; i++)
            updateBIT(BITree, i, arr[i]);
        return BITree;
    }


    private static class STNode {
        public int a;
        public int b;
        public int c;
    }

    private static STNode st[]=new STNode[4000001];


    private static void constructST(String str, int sti, int l, int r) {
        if(l==r){
            if(str.charAt(l)=='('){
                st[sti].b++;
            }
            else {
                st[sti].c++;
            }
            return;
        }
        int mid=(l+r)/2;
        constructST(str, sti*2+1, l, mid);
        constructST(str, sti*2+2, mid+1, r);
        int mn=Math.min(st[sti*2+1].b, st[sti*2+2].c);
        st[sti].a= st[sti*2+1].a+ st[sti*2+2].a+mn;
        st[sti].b= st[sti*2+1].b+ st[sti*2+2].b-mn;
        st[sti].c= st[sti*2+1].c+ st[sti*2+2].c-mn;
    }

    private static STNode getST(int sti, int l, int r, int stl,int str) {
        if(str<l)return new STNode();
        if(stl>r)return new STNode();
        if(stl>=l&&str<=r) return st[sti];
        int mid=(stl+str)/2;
        STNode left=getST(sti*2+1, l, r, stl, mid);
        STNode right=getST(sti*2+2, l, r, mid+1, str);
        STNode result=new STNode();
        int mn=Math.min(left.b, right.c);
        result.a= left.a+ right.a+mn;
        result.b= left.b+ right.b-mn;
        result.c= left.c+ right.c-mn;
        return result;
    }


    public static void main(String[] args) throws Exception {

        long START_TIME = System.currentTimeMillis();
        try (FastReader in = new FastReader();
             FastWriter out = new FastWriter()) {

            int t, i, j, n,a,b,f, k, l, r, m, ti, tidx, gm, q, g;
            

            {
                long w, y = 0, z = 0, sum = 0, bhc = 0, ans = 0;
                

                String id2 = in.next();
                m=in.nextInt();
                n=id2.length();
                for(i=0;i<4000001;i++){
                    st[i]=new STNode();
                }
                constructST(id2, 0, 0, n-1);
                while (m-->0){
                    l=in.nextInt()-1;
                    r=in.nextInt()-1;
                    out.println(getST(0,l,r,0,n-1).a*2);
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

        int[] id15(int n) {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextInt();
            }
            return arr;
        }

        int[] id5(int n) {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextInt();
            }
            return arr;
        }

        double[] id20(int n) {
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

        String[] id19(int n) {
            String[] arr = new String[n];
            for (int i = 0; i < n; i++) {
                arr[i] = next();
            }
            return arr;
        }


        long[][] id3(int n, int m) {
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
            commit();
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
                println(arr[j][arr.length - 1]);
            }
        }

        <T> void printColl(Collection<T> coll) throws IOException {
            for (T e : coll) {
                print(e + " ");
            }
            println();
        }

        void id8(char c, int n) throws IOException {
            for (int i = 0; i < n; i++) {
                print(c);
            }
        }

        void id4(int[][] arr) throws IOException {
            for (int j = 0; j < arr.length; j++) {
                for (int i = 0; i < arr[j].length - 1; i++) {
                    print(arr[j][i] + " ");
                }
                println(arr[j][arr.length - 1]);
            }
        }

        @Override
        public void close() throws IOException {
            bw.close();
        }

    }

}
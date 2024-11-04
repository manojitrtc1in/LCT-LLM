

import java.io.*;
import java.net.URL;
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
            return (this.a.equals(o.a) ? this.b.equals(o.b) ? 0 : this.b.compareTo(o.b) : this.a.compareTo(o.a));
        }
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


    private static void print(int... a) {
        System.out.println(Arrays.toString(a));
    }

    private static int[] get3(int a[], int i, int si) {
        int ret[] = new int[3];
        ret[2] = Integer.MIN_VALUE;
        for (int j = i, k = 0; j < a.length && k < 3; j++) {
            if (si == j) continue;
            ret[k++] = a[j];
        }
        return ret;
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

    public int id5(int N, int A, int B) {
        long lo=1,hi=Long.MAX_VALUE,mid;
        while(lo<=hi) {
            mid=lo+(hi-lo)/2;
            long cnt = mid/A+mid/B-mid/id17(A,B);
            if(cnt==N){
                return (int)(Math.max((mid/A)*A, (mid/B)*B)%mod);
            }
            else if(cnt<N){
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return (int)(Math.max((lo/A)*A, (lo/B)*B)%mod);
    }

    public static void main(String[] args) throws Exception {

        long START_TIME = System.currentTimeMillis();
        try (FastReader in = new FastReader();
             FastWriter out = new FastWriter()) {
            int n, t, i, j, f,  m, ti, tidx, gm, q, g, d, l=1, r=2,c;
            

            {
                long x = 0, y = 0, z = 0, sum = 0, bhc = 0, ans = 0,k;
                

                
                n=in.nextInt();
                int xa[]=new int[n+1];
                boolean hasSame=false;
                Map<Integer, Integer>map=new HashMap<>();
                for(i=2;i<=n;i++){
                    out.println("XOR 1 "+i);
                    m=in.nextInt();
                    xa[i]=m;
                    if(map.get(m)!=null){
                        hasSame=true;
                        l=map.get(m);
                        r=i;
                    }
                    map.put(m, i);
                }
                int a[]=new int[n];
                if(hasSame){
                    out.println("AND "+l+" "+r);
                    m=in.nextInt();
                    a[l-1]=a[r-1]=m;
                    a[0]=xa[l]^m;
                    for(i=1;i<n;i++){
                        a[i]=xa[i+1]^a[0];
                    }
                    out.print("! ");
                    for(i=0;i<n;i++){
                        out.print(a[i]+" ");
                    }
                    out.println();
                }
                else {
                    int u[][]=new int[3][5];
                    u[0][0]=0;
                    u[0][1]=map.get(n-1)-1;
                    u[0][2]=n-1;
                    u[0][3]=0;
                    u[0][4]=n-1;

                    u[1][0]=0;
                    u[1][1]=(u[0][1]==n-1)?u[0][1]-1:u[0][1]+1;
                    u[1][2]=xa[u[1][1]+1];
                    out.println("AND 1 "+(u[1][1]+1));
                    u[1][3]=in.nextInt();
                    u[1][4]=u[1][2]+2*u[1][3];

                    u[2][0]=u[0][1];
                    u[2][1]=u[1][1];
                    u[2][2]=xa[u[2][0]+1]^xa[u[2][1]+1];
                    out.println("AND "+(u[2][0]+1)+" "+(u[2][1]+1));
                    u[2][3]=in.nextInt();
                    u[2][4]=u[2][2]+2*u[2][3];

                    j=(u[0][4]+u[1][4]-u[2][4])/2;

                    out.print("! "+j);
                    for(i=2;i<=n;i++){
                        out.print(" "+(j^xa[i]));
                    }
                    out.println();
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
                println(arr[j][arr[j].length - 1]);
            }
        }

        <T> void printColl(Collection<T> coll) throws IOException {
            List<String> stringList = coll.stream().map(e -> ""+e).collect(Collectors.toList());
            println(String.format("%s",String.join(" ", stringList)));
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
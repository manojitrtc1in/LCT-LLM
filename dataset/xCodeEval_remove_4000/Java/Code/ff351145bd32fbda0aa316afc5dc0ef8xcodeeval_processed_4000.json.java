import java.io.*;
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

    static int id26(int a) {
        return 1 << id15(a);
    }

    static int id15(int a) {
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

    private static int id14(int st[][], int L, int R, BinaryOperator<Integer> binaryOperator) {
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

    private static int[][] id1(List<Integer> list, BinaryOperator<Integer> binaryOperator) {
        int n=list.size();
        int k = log[n + 1] + 1;
        int st[][] = new int[n + 1][k + 1];

        for (int i = 0; i < n; i++)
            st[i][0] = list.get(i);

        for (int j = 1; j <= k; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
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

    private static Set<Long> id19(long n) {
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

    private static long id18(long a, long b) {
        return (Math.max(a, b) / gcd(a, b)) * Math.min(a, b);
    }

    static long fac[];
    static long ifac[];

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

    static int getSum(int BITree[], int index) {
        int sum = 0;
        index = index + 1;
        while (index > 0) {
            sum+=BITree[index];
            index -= index & (-index);
        }
        return sum;
    }

    public static void updateBIT(int BITree[], int index, int val) {
        index = index + 1;
        while (index <= BITree.length - 1) {
            BITree[index] += val;
            index += index & (-index);
        }
    }

    static int[] id21(int n) {
        int BITree[] = new int[n + 1];
        for (int i = 1; i <= n; i++)
            BITree[i] = 0;
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

    static void reverse(int a[], int l, int r) {
        while (l < r) {
            int t = a[l];
            a[l] = a[r];
            a[r] = t;
            l++;
            r--;
        }
    }

    public void rotate(int[] nums, int k) {
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

    public static int[] id25(int arr[]) {
        Stack<Integer> s = new Stack<>();
        int n = arr.length;
        int nge[] = new int[n];
        s.push(0);
        for (int i = 1; i < n; i++) {
            if (s.empty()) {
                s.push(i);
                continue;
            }
            while (!s.isEmpty() && arr[s.peek()] <= arr[i]) {
                nge[s.peek()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.isEmpty()) {
            nge[s.peek()] = n;
            s.pop();
        }
        return nge;
    }

    public static int[] id22(int arr[]) {
        Stack<Integer> s = new Stack<>();
        int n = arr.length;
        int pse[] = new int[n];
        s.push(n-1);
        for (int i = n-2; i >= 0; i--) {
            if (s.empty()) {
                s.push(i);
                continue;
            }
            while (!s.isEmpty() && arr[s.peek()] > arr[i]) {
                pse[s.peek()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.isEmpty()) {
            pse[s.peek()] = n;
            s.pop();
        }

        return pse;
    }

    private static long id2(int a[],int l,int r){
        long res=0;
        for(int i=l;i<=r;i++){
            res=(res+((a[i]*(i-l+1L))*mod)*(r-i+1))%mod;
        }
        return res;
    }

    private static boolean isPal(String s){
        for(int i=0,j=s.length()-1;i<j;i++,j--){
            if(s.charAt(i)!=s.charAt(j))return false;
        }
        return true;
    }

    private static int[] id20(String s) {
        int n=s.length();
        int su[][]=new int[n][3];
        for(int i=0;i<n;i++){
            su[i]=new int[]{i, s.charAt(i)-'$', 0};
        }
        for(int i=0;i<n;i++){
            su[i][2]=(i+1<n?su[i+1][1]:-1);
        }
        Arrays.sort(su, (a,b)->a[1]==b[1]?a[2]-b[2]:a[1]-b[1]);
        int ind[]=new int[n];
        for(int l=4;l<2*n;l*=2){
            int rank=0,prev=su[0][1];
            su[0][1]=0;
            ind[su[0][0]]=0;
            for(int i=1;i<n;i++){
                if(su[i][1]==prev&&su[i][2]==su[i-1][2]){
                    su[i][1]=rank;
                } else {
                    prev=su[i][1];
                    su[i][1]=++rank;
                }
                ind[su[i][1]]=1;
            }
            for(int i=0;i<n;i++){
                int np=su[i][1]+l/2;
                su[i][2]=(np<n?su[ind[np]][1]:-1);
            }
            Arrays.sort(su, (a,b)->a[1]==b[1]?a[2]-b[2]:a[1]-b[1]);
        }
        int suf[]=new int[n];
        for(int i=0;i<n;i++){
            suf[i]=su[i][0];
        }
        return suf;
    }

    public static void main(String[] args) throws Exception {

        long START_TIME = System.currentTimeMillis();

        try (FastReader in = new FastReader();
             FastWriter out = new FastWriter()) {
            int n, t, i, j, f, k, m, ti, tidx, gm, q, g, l,r;
            for (t = in.nextInt(), tidx = 1; tidx <= t; tidx++)
            {
                long x = 0, y = 0, z = 0, sum = 0, bhc = 0, ans = 0;
                

                n=in.nextInt();
                int a[]=in.id17(n);
                if(n==1){
                    out.println(-1);
                } else {
                    TreeSet<Integer>ts=new TreeSet<>();
                    int res[]=new int[n];
                    for(i=1;i<=n;i++){
                        ts.add(i);
                    }
                    for(i=0;i<n-1;i++){
                        l=ts.first();
                        if(a[i]==l) {
                            l= ts.higher(l);
                        }
                        res[i]=l;
                        ts.remove(l);
                    }
                    res[n-1]=ts.first();
                    if(res[n-1]==a[n-1]){
                        r=res[n-1];
                        res[n-1]=res[n-2];
                        res[n-2]=r;
                    }
                    out.id11(res);
                }


            }

            
            out.commit();
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

        int[] id17(int n) {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextInt();
            }
            return arr;
        }

        Integer[] id5(int n) {
            Integer[] arr = new Integer[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextInt();
            }
            return arr;
        }

        double[] id24(int n) {
            double[] arr = new double[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextDouble();
            }
            return arr;
        }

        long[] id13(int n) {
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextLong();
            }
            return arr;
        }

        List<Long> id12(int n) {
            List<Long> retList = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                retList.add(nextLong());
            }
            return retList;
        }

        String[] id23(int n) {
            String[] arr = new String[n];
            for (int i = 0; i < n; i++) {
                arr[i] = next();
            }
            return arr;
        }


        int[][] id16(int n, int m) {
            int[][] arr = new int[n][m];
            for (int i = 0; i < n; i++) {
                arr[i] = id17(m);
            }
            return arr;
        }

        long[][] id3(int n, int m) {
            long[][] arr = new long[n][m];
            for (int i = 0; i < n; i++) {
                arr[i] = id13(m);
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
            println(String.format("{%s}",String.join(",", stringList)));
        }

        void id8(char c, int n) throws IOException {
            for (int i = 0; i < n; i++) {
                print(c);
            }
        }

        void id11(int []arr) throws IOException {
            for (int i = 0; i < arr.length - 1; i++) {
                print(arr[i] + " ");
            }
            println(arr[arr.length - 1]);
        }

        void id4(int[][] arr) throws IOException {
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


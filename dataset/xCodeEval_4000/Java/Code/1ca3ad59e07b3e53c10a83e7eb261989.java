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

    static int nextPowerOf2(int a) {
        return 1 << nextLog2(a);
    }

    static int nextLog2(int a) {
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

    private static int[] getLogArr(int n) {
        int arr[] = new int[n + 1];
        for (int i = 1; i < n + 1; i++) {
            arr[i] = (int) (Math.log(i) / Math.log(2) + 1e-10);
        }
        return arr;
    }

    private static int log[] = getLogArr(MAXN);

    private static int getLRSpt(int st[][], int L, int R, BinaryOperator<Integer> binaryOperator) {
        int j = log[R - L + 1];
        return binaryOperator.apply(st[L][j], st[R - (1 << j) + 1][j]);
    }

    private static int[][] getSparseTable(int array[], BinaryOperator<Integer> binaryOperator) {
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

    private static int[][] getSparseTable(List<Integer> list, BinaryOperator<Integer> binaryOperator) {
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


    private static int[] getLPSArray(String pattern) {
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
        int[] lps = getLPSArray(pattern);
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

    private static Set<Long> getDivisors(long n) {
        Set<Long> divisors = new HashSet<>();
        divisors.add(1L);
        divisors.add(n);
        for (long i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                divisors.add(i);
                divisors.add(n / i);
            }
        }
        return divisors;
    }

    private static long getLCM(long a, long b) {
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

    static int[] constructBITree(int n) {
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

    private static int seg[]=new int[400001];
    private static int lazy[]=new int[400001];

    void build(int node, int st, int en, int arr[]) {
        if (st == en) {
            seg[node] = arr[st];
            return;
        }
        int mid = (st + en) / 2;
        build(2 * node, st, mid, arr);
        build(2 * node + 1, mid + 1, en, arr);
        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }

    public static int[] getNSE(int arr[]) {
        Stack<Integer> s = new Stack<>();
        int n = arr.length;
        int nse[] = new int[n];
        s.push(0);
        for (int i = 1; i < n; i++) {
            if (s.empty()) {
                s.push(i);
                continue;
            }
            while (!s.isEmpty() && arr[s.peek()] > arr[i]) {
                nse[s.peek()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.isEmpty()) {
            nse[s.peek()] = -1;
            s.pop();
        }
        return nse;
    }

    public static int[] getPSE(int arr[]) {
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

    private static long getSASum(int a[],int l,int r){
        long res=0;
        for(int i=l;i<=r;i++){
            res=(res+((a[i]*(i-l+1L))*mod)*(r-i+1))%mod;
        }
        return res;
    }

    public int totalStrength(int[] strength) {
        int st[][]=getSparseTable(strength,Math::min);
        long ans=0;
        int pse[]=getPSE(strength);
        int nse[]=getNSE(strength);
        for(int i=0;i<strength.length;i++){
            int l=pse[i]+1;
            int r=nse[i]-1;
            long ls=getSASum(strength, l,i-1)+(i-l+1L)*strength[i];
            long rs=getSASum(strength, i+1, r)+(r-i+1L)*strength[i];
            int mn=getLRSpt(st, l, r, Math::min);
            ans=(ans+(ls+rs)*mn)%mod;
        }
        return (int)ans;
    }

    private static boolean isPal(String s){
        for(int i=0,j=s.length()-1;i<j;i++,j--){
            if(s.charAt(i)!=s.charAt(j))return false;
        }
        return true;
    }

    private static Map<String,Long>dp=new HashMap<>();
    private static long dfs(String s){
        if(s.length()<2)return 0;
        

        long cnt=isPal(s)?1:0;
        System.out.println(s+cnt);
        for (int i = 0; i < s.length(); i++) {
            String next = s.substring(0, i) + s.substring(i + 1);
            cnt = (cnt + dfs(next)) % mod;
        }
        dp.put(s,cnt);
        

        return cnt;
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
                k=in.nextInt();
                int a[]=in.nextIntArr(n);
                int b[][]=new int[n][2];
                for(i=0;i<n;i++){
                    b[i][0]=a[i]-(n-i);
                    b[i][1]=i;
                }
                Arrays.sort(b, Comparator.comparingInt(e->-e[0]));
                Set<Integer>jmpIdx=new HashSet<>();
                for(i=0;i<k;i++){
                    jmpIdx.add(b[i][1]);
                }
                j=0;
                for(i=0;i<n;i++){
                    if(jmpIdx.contains(i)){
                        j++;
                    } else {
                        ans+=a[i]+j;
                    }
                }
                out.println(ans);
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

        int[] nextIntArr(int n) {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextInt();
            }
            return arr;
        }

        Integer[] nextIntegerArr(int n) {
            Integer[] arr = new Integer[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextInt();
            }
            return arr;
        }

        double[] nextDoubleArr(int n) {
            double[] arr = new double[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextDouble();
            }
            return arr;
        }

        long[] nextLongArr(int n) {
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextLong();
            }
            return arr;
        }

        List<Long> nextLongList(int n) {
            List<Long> retList = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                retList.add(nextLong());
            }
            return retList;
        }

        String[] nextStrArr(int n) {
            String[] arr = new String[n];
            for (int i = 0; i < n; i++) {
                arr[i] = next();
            }
            return arr;
        }


        int[][] nextIntArr2(int n, int m) {
            int[][] arr = new int[n][m];
            for (int i = 0; i < n; i++) {
                arr[i] = nextIntArr(m);
            }
            return arr;
        }

        long[][] nextLongArr2(int n, int m) {
            long[][] arr = new long[n][m];
            for (int i = 0; i < n; i++) {
                arr[i] = nextLongArr(m);
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

        <T> void printArrLn(T[] arr) throws IOException {
            for (int i = 0; i < arr.length - 1; i++) {
                print(arr[i] + " ");
            }
            println(arr[arr.length - 1]);
        }

        <T> void printArr2(T[][] arr) throws IOException {
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

        void printCharN(char c, int n) throws IOException {
            for (int i = 0; i < n; i++) {
                print(c);
            }
        }

        void printIntArr(int []arr) throws IOException {
            for (int i = 0; i < arr.length - 1; i++) {
                print(arr[i] + " ");
            }
            println(arr[arr.length - 1]);
        }

        void printIntArr2(int[][] arr) throws IOException {
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


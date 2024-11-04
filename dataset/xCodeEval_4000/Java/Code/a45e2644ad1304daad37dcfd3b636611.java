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



    public int solve(int[] nums) {
        Map<Pair<Integer,Integer>,Integer>dp=new HashMap<>();
        int ans=0;
        for(int i=1;i<nums.length;i++){
            for(int j=i+1;j<nums.length;j++) {
                Pair<Integer,Integer>prev=new Pair<>(nums[j]-nums[i],nums[i]);

                Integer v=dp.get(prev);
                Pair<Integer,Integer>curr=new Pair<>(nums[i],nums[j]);
                if(v!=null){
                    dp.put(curr,Math.max(dp.get(prev),v+1));
                }
                else {
                    dp.put(curr, 2);
                }
                ans=Math.max(ans,dp.get(curr));
            }
        }
        return ans;
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

    private static long getLRSpt(long st[][], int L, int R, BinaryOperator<Long> binaryOperator) {
        int j = log[R - L + 1];
        return binaryOperator.apply(st[L][j], st[R - (1 << j) + 1][j]);
    }

    private static long[][] getSparseTable(int array[], BinaryOperator<Long> binaryOperator) {
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

    private static long getULDRSpt(long st[][][][], int U, int L,int D, int R, BinaryOperator<Long> binaryOperator) {
        int k = log[D - U + 1];
        int l = log[R - L + 1];
        long a= binaryOperator.apply(st[U][L][k][l], st[D - (1 << k) + 1][R - (1 << l) + 1][k][l]);
        long b= binaryOperator.apply(st[U][R - (1 << l) + 1][k][l], st[D - (1 << k) + 1][L][k][l]);
        return binaryOperator.apply(a,b);
    }

    private static long[][][][] getSparseTable2D(int arr[][], BinaryOperator<Long>bo){
        int n=arr.length;
        int m=arr[0].length;
        int k=log[n+1]+2;
        int l=log[m+1]+2;
        long st[][][][]=new long[n][m][k][l];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                st[i][j][0][0]=arr[i][j];
            }
        }
        for(int x=1;x<k;x++){
            for(int y=1;y<l;y++){
                for(int i=0;i+(1<<x)<=n;i++){
                    for(int j=0;j+(1<<y)<=m;j++){
                        st[i][j][x][y]=bo.apply(bo.apply(st[i][j][x - 1][y-1], st[i + (1 << (x - 1))][j][x - 1][y-1]),
                                bo.apply(st[i][j+(1 << (y - 1))][x - 1][y-1], st[i + (1 << (x - 1))][j+(1 << (y - 1))][x - 1][y-1]));
                    }
                }
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

    private static long getLCM(long a, long b) {
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

    long[] constructBITree(int arr[], int m) {
        int n = arr.length;
        long BITree[] = new long[m + 1];
        for (int i = 1; i <= n; i++)
            BITree[i] = 0;
        for (int i = 0; i < n; i++)
            updateBIT(BITree, i, arr[i]);
        return BITree;
    }

    private static String getBinaryString(int a[], int l, int r){
        if(l>r||l>a.length-1||r>a.length-1||l<0||r<0)return "";
        StringBuilder sb = new StringBuilder();
        int i=l;
        while(i<=r&&a[i]==0)i++;
        for (;i<=r;i++){
            sb.append(a[i]);
        }
        return sb.toString();
    }
    private static int cmpBS(String a, String b){
        if(a.length()==b.length()){
            return a.compareTo(b);
        }
        else return a.length()-b.length();
    }


    public static int[] threeEqualParts(int[] A) {
        int ans[]=new int[2];
        ans[0]=ans[1]=-1;
        int lo1=0,hi1=A.length-3,mid1,curr;
        while (lo1<=hi1){
            mid1=lo1+(hi1-lo1)/2;
            int lo=mid1+1,hi=A.length-2,mid;
            String leftS=getBinaryString(A,0,mid1);
            String midS=getBinaryString(A,lo, hi);;
            String rightS="";
            while(lo<=hi){
                mid=lo+(hi-lo)/2;
                midS=getBinaryString(A,mid1+1, mid);
                rightS=getBinaryString(A,mid+1,A.length-1);
                if(midS.equals(rightS)&&leftS.equals(midS)){
                    ans[0]=mid1;
                    ans[1]=mid+1;
                    return ans;
                }
                else if(cmpBS(rightS,midS) < 0){
                    hi=mid-1;
                }
                else {
                    lo=mid+1;
                }
                

            }
            if(cmpBS(leftS,midS) < 0) {
                hi1=mid1-1;
            }
            else {
                lo1=mid1+1;
            }
        }
        return ans;
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



    static void reverse(Integer a[], int l, int r) {
        while (l < r) {
            int t = a[l];
            a[l] = a[r];
            a[r] = t;
            l++;
            r--;
        }
    }
    private static int cntBits(int n){
        int cnt=0;
        while(n>0){
            cnt+=n%2;
            n/=2;
        }
        return cnt;
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

    private static int upperBound(long csum[], long val){
        int lo=0,hi=csum.length-1,mid,ans=csum.length;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(csum[mid]<=val){
                lo=mid+1;
            }
            else {
                ans=mid;
                hi=mid-1;
            }
        }
        return ans;
    }

    private static int lowerBound(long csum[], long val){
        int lo=0,hi=csum.length-1,mid,ans=-1;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(csum[mid]<val){
                lo=mid+1;
                ans=mid;
            }
            else {
                hi=mid-1;
            }
        }
        return ans;
    }


    public int countRangeSum(int[] nums, int lower, int upper) {
        int i,j,k,n=nums.length,ans=0;
        long csum[]=new long[n];
        long prev=0;
        for(i=0;i<n;i++){
            csum[i]=prev+nums[i];
            prev=csum[i];
        }
        Arrays.sort(csum);
        ans=upperBound(csum, upper)-lowerBound(csum,lower)-1;
        for(i=0;i<n;i++){
            ans+=upperBound(csum, upper+csum[i])-lowerBound(csum,lower+csum[i])-1;
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

    private static Map<Integer, Integer> bit = new HashMap<>();

    private static void update(int i, int val){
        while(i<=1000000){
            bit.put(i,bit.getOrDefault(i,0)+val);
            i+=i&-i;
        }
    }

    private static long get(int i){
        long sum=0;
        while (i>0){
            sum+=bit.getOrDefault(i,0);
            i-=i&-i;
        }
        return sum;
    }
    private static Set<Long> getDivisors(long n) {
        Set<Long> divisors = new HashSet<>();
        for (long i = 1; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                divisors.add(i);
                divisors.add(n / i);
            }
        }
        return divisors;
    }

    private static int getMed(List<Integer> arrList, int offset, int limit) {
        List<Integer> tmp=new ArrayList<>();
        for(int i=0;i<limit&&i+offset<arrList.size();i++){
            tmp.add(arrList.get(i+offset));
        }
        Collections.sort(tmp);
        return tmp.get((tmp.size()-1)/2);
    }


    public static void main(String[] args) throws Exception {
        long START_TIME = System.currentTimeMillis();
        try (FastReader in = new FastReader();
             FastWriter out = new FastWriter()) {
            int  n,t, i, j,  m, ti, tidx, gm, l=1, r=2,k;
            

            {
                

                long x = 0, y = 0, z = 0, sum = 0, bhc = 0, ans = 0,ans1=0,d,g;
                n=in.nextInt();
                m=in.nextInt();
                k=in.nextInt();
                if(k>0&&k>n+m-2){
                    out.println("No");
                }
                else if(k>0&&(m==1||n==0)){
                    out.println("No");
                }
                else if(k==0){
                    out.println("Yes");
                    char ca[]=new char[n+m];
                    char cb[]=new char[n+m];
                    for(i=0;i<m;i++){
                        ca[i]=cb[i]='1';
                    }
                    for(;i<n+m;i++){
                        ca[i]=cb[i]='0';
                    }
                    out.println(new String(ca));
                    out.println(new String(cb));
                }
                else {
                    out.println("Yes");
                    char ca[]=new char[n+m];
                    char cb[]=new char[n+m];
                    boolean vis[]=new boolean[n+m];
                    for(i=1;i<n+m;i++){
                        ca[i]=cb[i]='0';
                    }
                    vis[0]=true;
                    ca[0]=cb[0]='1';
                    ca[1]='1';
                    for(i=0;i+1<n+m&&i<=k;i++);
                    cb[i]='1';
                    vis[1]=vis[i]=true;
                    m-=2;
                    for(i=0;i<ca.length&&m>0;i++){
                        if(vis[i])continue;
                        ca[i]=cb[i]='1';
                        vis[i]=true;
                        m--;
                    }
                    out.println(new String(ca));
                    out.println(new String(cb));
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
            println(String.format("%s",String.join(" ", stringList)));
        }

        void printCharN(char c, int n) throws IOException {
            for (int i = 0; i < n; i++) {
                print(c);
            }
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
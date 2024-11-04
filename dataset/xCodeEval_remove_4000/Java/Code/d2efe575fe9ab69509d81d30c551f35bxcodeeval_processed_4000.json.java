import java.io.*;
import java.nio.charset.StandardCharsets;
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

    static int id26(int a) {
        return 1 << id17(a);
    }

    static int id17(int a) {
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

    private static int[] id5(int n) {
        int arr[] = new int[n + 1];
        for (int i = 1; i < n + 1; i++) {
            arr[i] = (int) (Math.log(i) / Math.log(2) + 1e-10);
        }
        return arr;
    }

    private static int log[] = id5(MAXN);

    private static long id16(long st[][], int L, int R, BinaryOperator<Long> binaryOperator) {
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

    private static long id12(long st[][][][], int U, int L,int D, int R, BinaryOperator<Long> binaryOperator) {
        int k = log[D - U + 1];
        int l = log[R - L + 1];
        long a= binaryOperator.apply(st[U][L][k][l], st[D - (1 << k) + 1][R - (1 << l) + 1][k][l]);
        long b= binaryOperator.apply(st[U][R - (1 << l) + 1][k][l], st[D - (1 << k) + 1][L][k][l]);
        return binaryOperator.apply(a,b);
    }

    private static long[][][][] id8(int arr[][], BinaryOperator<Long>binaryOperator){
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
                        st[i][j][x][y]=binaryOperator.apply(binaryOperator.apply(st[i][j][x - 1][y-1], st[i + (1 << (x - 1))][j][x - 1][y-1]),
                                binaryOperator.apply(st[i][j+(1 << (y - 1))][x - 1][y-1], st[i + (1 << (x - 1))][j+(1 << (y - 1))][x - 1][y-1]));
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

    private static long id20(long a, long b) {
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

    long[] id22(int arr[], int m) {
        int n = arr.length;
        long BITree[] = new long[m + 1];
        for (int i = 1; i <= n; i++)
            BITree[i] = 0;
        for (int i = 0; i < n; i++)
            updateBIT(BITree, i, arr[i]);
        return BITree;
    }

    private static String id6(int a[], int l, int r){
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


    public static int[] id25(int[] A) {
        int ans[]=new int[2];
        ans[0]=ans[1]=-1;
        int lo1=0,hi1=A.length-3,mid1,curr;
        while (lo1<=hi1){
            mid1=lo1+(hi1-lo1)/2;
            int lo=mid1+1,hi=A.length-2,mid;
            String leftS=id6(A,0,mid1);
            String midS=id6(A,lo, hi);;
            String rightS="";
            while(lo<=hi){
                mid=lo+(hi-lo)/2;
                midS=id6(A,mid1+1, mid);
                rightS=id6(A,mid+1,A.length-1);
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


    public int id14(int[] nums, int lower, int upper) {
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
    private static Set<Long> id21(long n) {
        Set<Long> id0 = new HashSet<>();
        for (long i = 1; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                id0.add(i);
                id0.add(n / i);
            }
        }
        return id0;
    }

    private static int getMed(List<Integer> arrList, int offset, int limit) {
        List<Integer> tmp=new ArrayList<>();
        for(int i=0;i<limit&&i+offset<arrList.size();i++){
            tmp.add(arrList.get(i+offset));
        }
        Collections.sort(tmp);
        return tmp.get((tmp.size()-1)/2);
    }

    private int bs(int [][]events, int i) {
        int lo=0,hi=i-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(events[mid][1]<events[i][0]){
                if(events[mid+1][1]<events[i][0]){
                    lo=mid+1;
                }
                else {
                    return mid;
                }
            }
            else hi=mid-1;
        }
        return -1;
    }

    public int maxValue(int[][] events, int k) {
        Arrays.sort(events, (e1,e2)-> e1[1]==e2[1]?e1[0]==e2[0]?e1[2]-e2[2]:e1[0]-e2[0]:e1[1]-e2[1]);
        int dp[][]=new int[k+1][events.length];
        dp[1][0]=events[0][2];
        for(int i=1;i<events.length;i++){
            dp[1][i]=Math.max(dp[1][i-1],events[i][2]);
            int l=bs(events,i);
            for(int j=2;j<=k;j++){
                dp[j][i]=Math.max(dp[j-1][i],dp[j][i-1]);
                if(l!=-1){
                    dp[j][i]=Math.max(dp[j][i],dp[j-1][l]+events[i][2]);
                }
            }
        }
        return dp[k][events.length-1];
    }

    private static void dfs(List<List<Pair<Integer,Integer>>>graph, int i, int[]parent, int cl[],boolean vis[],int dist){
        if(vis[i]){
            int j;
            for(j=parent[i];j!=i&&j!=0;j=parent[j]);
            if(j==i){
                cl[i]=Math.min(cl[i],dist);

            }
            return;
        }
        vis[i]=true;
        for(Pair<Integer,Integer>p:graph.get(i)){
            parent[p.a]=i;
            dfs(graph,p.a,parent,cl,vis,dist+p.b);
        }
    }

    public static void main(String[] args) throws Exception {
        long START_TIME = System.currentTimeMillis();
        try (FastReader in = new FastReader();
             FastWriter out = new FastWriter()) {
            int  n,t, i, j, f,  m, ti, tidx, gm, l=1, r=2,k;
            

            {
                long x = 0, y = 0, z = 0, sum = 0, bhc = 0, ans = 0,ans1=0,d,g,curr=0;
                

                n=in.nextInt();
                boolean found=false;
                int fv=-1;
                Integer a[]=new Integer[n];
                int lo=0,hi=n-1,mid;
                k=100;
                while(lo<=hi&&k-->0){
                    mid=lo+(hi-lo)/2;
                    if(a[mid]==null){
                        out.println("? "+(mid+1));
                        a[mid]=in.nextInt();
                    }
                    boolean ltl=false;
                    boolean ltr=false;
                    if(mid>0){
                        if(a[mid-1]==null){
                            out.println("? "+(mid));
                            a[mid-1]=in.nextInt();
                        }
                        if(a[mid]<a[mid-1])ltl=true;
                    }
                    else ltl=true;

                    if(mid<n-1){
                        if(a[mid+1]==null){
                            out.println("? "+(mid+2));
                            a[mid+1]=in.nextInt();
                        }
                        if(a[mid]<a[mid+1])ltr=true;
                    }
                    else ltr=true;
                    if(ltl&&ltr){
                        out.println("! "+(mid+1));
                        found=true;
                        break;
                    }
                    else if(!ltl&&!ltr){
                        if(mid>n-mid-1){
                            lo=mid+1;
                        }
                        else hi=mid-1;
                    }
                    else if(!ltl){
                        hi=mid-1;
                    }
                    else lo=mid+1;
                }
                if(!found)
                    out.println("! "+(lo));
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

        int[] id19(int n) {
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

        double[] id24(int n) {
            double[] arr = new double[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextDouble();
            }
            return arr;
        }

        long[] id15(int n) {
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextLong();
            }
            return arr;
        }

        List<Long> id13(int n) {
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


        int[][] id18(int n, int m) {
            int[][] arr = new int[n][m];
            for (int i = 0; i < n; i++) {
                arr[i] = id19(m);
            }
            return arr;
        }

        long[][] id2(int n, int m) {
            long[][] arr = new long[n][m];
            for (int i = 0; i < n; i++) {
                arr[i] = id15(m);
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

        <T> void id10(T[] arr) throws IOException {
            for (int i = 0; i < arr.length - 1; i++) {
                print(arr[i] + " ");
            }
            println(arr[arr.length - 1]);
        }

        <T> void id11(T[][] arr) throws IOException {
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

        void id9(char c, int n) throws IOException {
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
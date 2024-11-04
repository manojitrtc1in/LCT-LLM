    import java.io.*;
    import java.math.BigDecimal;
    import java.math.BigInteger;
    import java.math.RoundingMode;
    import java.text.CollationElementIterator;
    import java.util.*;
    

    import javax.lang.model.type.IntersectionType;
    import javax.print.attribute.standard.PrinterResolution;
    import javax.swing.text.html.CSS;
    public class codeforces {
        static class FastReader {
            BufferedReader br;
            StringTokenizer st;

            public FastReader() {
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
        }

        static int m = 1000000007;

        static long[][] multiply(long a[][], long b[][]) {
            long res[][] = new long[2][2];
            res[0][0] = ((a[0][0] * b[0][0]) % m + (a[0][1] * b[1][0]) % m) % m;
            res[0][1] = ((a[0][0] * b[0][1]) % m + (a[0][1] * b[1][1]) % m) % m;
            res[1][0] = ((a[1][0] * b[0][0]) % m + (a[1][1] * b[1][0]) % m) % m;
            res[1][1] = ((a[1][0] * b[0][1]) % m + (a[1][1] * b[1][1]) % m) % m;
            return res;
        }

        static boolean isKthBitSet(int n,
                                   int k) {
            if (((n >> (k)) &
                    1) > 0)
                return true;
            return false;
        }

        static void move(char a[], int i) {
            int j = 0;
            int temp1 = i;
            while (j < i) {
                char temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                j++;
                i--;
            }
            for (int k = 0; k <= temp1; k++) {
                a[k] = (a[k] == '0') ? '1' : '0';
            }
        }

        static int fact(int a) {
            int f = 1;
            for (int i = 2; i <= a; i++)
                f *= i;
            return f;
        }

        static long gcd(long a, long b) {
            if (a == 0)
                return b;
            return gcd(b % a, a);

        }
        public static class edge
        {
            int v,wt;
            public edge(int v,int wt)
            {
                this.v=v;
                this.wt=wt;
            }
        }
        public static class trip
        {
            int a,b,c;
            trip(int a,int b,int c)
            {
                this.a=a;
                this.b=b;
                this.c=c;
            }
        }
        public static class pair
        {
            int i,j;
            pair(int i,int j)
            {
                this.i=i;
                this.j=j;
            }

        }
        public static class TrieNode
        {
            HashMap<Character,TrieNode> children;
            String w;
            TrieNode()
            {
                children=new HashMap<>();
                w="";
            }
        }
        static TrieNode root=new TrieNode();
        public static void insert(String word)
        {
            TrieNode curr=root;
            for(int i=0;i<word.length();i++)
            {
                char ch=word.charAt(i);
                TrieNode node=curr.children.get(ch);
                if(node==null) {
                    node = new TrieNode();
                    curr.children.put(ch, node);
                }
                curr=node;
                curr.w=word;
            }
            curr.w=word;
        }
        public static String prefix(String word)
        {
            TrieNode curr=root;
            for(int i=0;i<word.length();i++)
            {
                char ch=word.charAt(i);
                TrieNode node=curr.children.get(ch);
                if(node==null)
                    return "";
                curr=node;

            }
            return curr.w;
        }
        public static  void recurse(String x,int count)
        {
            if(x.length()==3)
                System.out.println("Draw");
            else {
                String a = x.substring(x.length() - 3);
                String inc=prefix(a);
                if (inc.length() == 0) {
                    if (count == 0)
                        System.out.println("Takahashi");
                    else
                        System.out.println("Aoki");
                } else
                    recurse(inc,1-count);
            }
        }
        static long dp[][]=new long[1002][1002];;
        public static long recur(int i,int j,int k,long A[],long B[])
        {
            if(k==B.length)
                return 0;
            if(dp[i][j]!=-1)
                return dp[i][j];
            long x=recur(i+1,j,k+1,A,B)+(B[k]*A[i]);
            long y=recur(i,j-1,k+1,A,B)+(B[k]*A[j]);
            dp[i][j]=Math.max(x,y);
            return dp[i][j];
        }
        public static void main(String[] args) throws IOException {
            PrintWriter out = new PrintWriter(System.out);
            InputReader sc = new InputReader(System.in);
            int t = sc.nextInt();
            while (t-- > 0) {
                int m=sc.nextInt();
                int x=0;
                int ans=Integer.MAX_VALUE;
                int mat[][]=new int[2][m];
                int y=0;
                for(int i=0;i<2;i++)
                {
                    for(int j=0;j<m;j++) {
                        mat[i][j] = sc.nextInt();
                        if(i==0)
                            y+=mat[i][j];
                    }
                }
                for(int i=0;i<m;i++)
                {
                    y-=mat[0][i];
                    ans=Math.min(ans,Math.max(x,y));
                    x+=mat[1][i];
                }
                System.out.println(ans);

            }
        }








        static class InputReader {
            private InputStream in;
            private byte[] buffer = new byte[1024];
            private int curbuf;
            private int lenbuf;
            public InputReader(InputStream in) {
                this.in = in;
                this.curbuf = this.lenbuf = 0;
            }
            public boolean hasNextByte() {
                if (curbuf >= lenbuf) {
                    curbuf = 0;
                    try {
                        lenbuf = in.read(buffer);
                    } catch (IOException e) {
                        throw new InputMismatchException();
                    }
                    if (lenbuf <= 0)
                        return false;
                }
                return true;
            }

            private int readByte() {
                if (hasNextByte())
                    return buffer[curbuf++];
                else
                    return -1;
            }

            private boolean isSpaceChar(int c) {
                return !(c >= 33 && c <= 126);
            }

            private void skip() {
                while (hasNextByte() && isSpaceChar(buffer[curbuf]))
                    curbuf++;
            }

            public boolean hasNext() {
                skip();
                return hasNextByte();
            }

            public String next() {
                if (!hasNext())
                    throw new NoSuchElementException();
                StringBuilder sb = new StringBuilder();
                int b = readByte();
                while (!isSpaceChar(b)) {
                    sb.appendCodePoint(b);
                    b = readByte();
                }
                return sb.toString();
            }

            public int nextInt() {
                if (!hasNext())
                    throw new NoSuchElementException();
                int c = readByte();
                while (isSpaceChar(c))
                    c = readByte();
                boolean minus = false;
                if (c == '-') {
                    minus = true;
                    c = readByte();
                }
                int res = 0;
                do {
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    res = res * 10 + c - '0';
                    c = readByte();
                } while (!isSpaceChar(c));
                return (minus) ? -res : res;
            }

            public long nextLong() {
                if (!hasNext())
                    throw new NoSuchElementException();
                int c = readByte();
                while (isSpaceChar(c))
                    c = readByte();
                boolean minus = false;
                if (c == '-') {
                    minus = true;
                    c = readByte();
                }
                long res = 0;
                do {
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    res = res * 10 + c - '0';
                    c = readByte();
                } while (!isSpaceChar(c));
                return (minus) ? -res : res;
            }

            public double nextDouble() {
                return Double.parseDouble(next());
            }

            public int[] nextIntArray(int n) {
                int[] a = new int[n];
                for (int i = 0; i < n; i++)
                    a[i] = nextInt();
                return a;
            }

            public long[] nextLongArray(int n) {
                long[] a = new long[n];
                for (int i = 0; i < n; i++)
                    a[i] = nextLong();
                return a;
            }

            public char[][] nextCharMap(int n, int m) {
                char[][] map = new char[n][m];
                for (int i = 0; i < n; i++)
                    map[i] = next().toCharArray();
                return map;
            }
        }
    }
    class MergeSort {
        

        

        

        static void  merge(long arr[], int l, int m, int r) {
            

            int n1 = m - l + 1;
            int n2 = r - m;

            
            long L[] = new long[n1];
            long R[] = new long[n2];

            
            for (int i = 0; i < n1; ++i)
                L[i] = arr[l + i];
            for (int j = 0; j < n2; ++j)
                R[j] = arr[m + 1 + j];


            

            

            int i = 0, j = 0;

            

            int k = l;
            while (i < n1 && j < n2) {
                if (L[i] <= R[j]) {
                    arr[k] = L[i];
                    i++;
                } else {
                    arr[k] = R[j];
                    j++;
                }
                k++;
            }

            
            while (i < n1) {
                arr[k] = L[i];
                i++;
                k++;
            }

            
            while (j < n2) {
                arr[k] = R[j];
                j++;
                k++;
            }
        }

        

        

        static void sort(long arr[], int l, int r) {
            if (l < r) {
                

                int m = (l + r) / 2;

                

                sort(arr, l, m);
                sort(arr, m + 1, r);

                

                merge(arr, l, m, r);
            }
        }
    }
    class SegTree<S> {
        final int MAX;

        final int N;
        final java.util.function.BinaryOperator<S> op;
        final S E;

        final S[] data;

        @SuppressWarnings("unchecked")
        public SegTree(int n, java.util.function.BinaryOperator<S> op, S e) {
            this.MAX = n;
            int k = 1;
            while (k < n) k <<= 1;
            this.N = k;
            this.E = e;
            this.op = op;
            this.data = (S[]) new Object[N << 1];
            java.util.Arrays.fill(data, E);
        }

        public SegTree(S[] dat, java.util.function.BinaryOperator<S> op, S e) {
            this(dat.length, op, e);
            build(dat);
        }

        private void build(S[] dat) {
            int l = dat.length;
            System.arraycopy(dat, 0, data, N, l);
            for (int i = N - 1; i > 0; i--) {
                data[i] = op.apply(data[i << 1 | 0], data[i << 1 | 1]);
            }
        }

        public void set(int p, S x) {
            exclusiveRangeCheck(p);
            data[p += N] = x;
            p >>= 1;
            while (p > 0) {
                data[p] = op.apply(data[p << 1 | 0], data[p << 1 | 1]);
                p >>= 1;
            }
        }

        public S get(int p) {
            exclusiveRangeCheck(p);
            return data[p + N];
        }

        public S prod(int l, int r) {
            if (l > r) {
                throw new IllegalArgumentException(
                        String.format("Invalid range: [%d, %d)", l, r)
                );
            }
            inclusiveRangeCheck(l);
            inclusiveRangeCheck(r);
            S sumLeft = E;
            S sumRight = E;
            l += N; r += N;
            while (l < r) {
                if ((l & 1) == 1) sumLeft = op.apply(sumLeft, data[l++]);
                if ((r & 1) == 1) sumRight = op.apply(data[--r], sumRight);
                l >>= 1; r >>= 1;
            }
            return op.apply(sumLeft, sumRight);
        }

        public S allProd() {
            return data[1];
        }

        public int maxRight(int l, java.util.function.Predicate<S> f) {
            inclusiveRangeCheck(l);
            if (!f.test(E)) {
                throw new IllegalArgumentException("Identity element must satisfy the condition.");
            }
            if (l == MAX) return MAX;
            l += N;
            S sum = E;
            do {
                l >>= Integer.numberOfTrailingZeros(l);
                if (!f.test(op.apply(sum, data[l]))) {
                    while (l < N) {
                        l = l << 1;
                        if (f.test(op.apply(sum, data[l]))) {
                            sum = op.apply(sum, data[l]);
                            l++;
                        }
                    }
                    return l - N;
                }
                sum = op.apply(sum, data[l]);
                l++;
            } while ((l & -l) != l);
            return MAX;
        }

        public int minLeft(int r, java.util.function.Predicate<S> f) {
            inclusiveRangeCheck(r);
            if (!f.test(E)) {
                throw new IllegalArgumentException("Identity element must satisfy the condition.");
            }
            if (r == 0) return 0;
            r += N;
            S sum = E;
            do {
                r--;
                while (r > 1 && (r & 1) == 1) r >>= 1;
                if (!f.test(op.apply(data[r], sum))) {
                    while (r < N) {
                        r = r << 1 | 1;
                        if (f.test(op.apply(data[r], sum))) {
                            sum = op.apply(data[r], sum);
                            r--;
                        }
                    }
                    return r + 1 - N;
                }
                sum = op.apply(data[r], sum);
            } while ((r & -r) != r);
            return 0;
        }

        private void exclusiveRangeCheck(int p) {
            if (p < 0 || p >= MAX) {
                throw new IndexOutOfBoundsException(
                        String.format("Index %d out of bounds for the range [%d, %d).", p, 0, MAX)
                );
            }
        }

        private void inclusiveRangeCheck(int p) {
            if (p < 0 || p > MAX) {
                throw new IndexOutOfBoundsException(
                        String.format("Index %d out of bounds for the range [%d, %d].", p, 0, MAX)
                );
            }

        }
    }
    class MathLib{
        public static int[] sieveEratostheness(int n) {
            if (n <= 32) {
                int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
                for (int i = 0; i < primes.length; i++) {
                    if (n < primes[i]) {
                        return Arrays.copyOf(primes, i);
                    }
                }
                return primes;
            }

            int u = n + 32;
            double lu = Math.log(u);
            int[] ret = new int[(int) (u / lu + u / lu / lu * 1.5)];
            ret[0] = 2;
            int pos = 1;

            int[] isnp = new int[(n + 1) / 32 / 2 + 1];
            int sup = (n + 1) / 32 / 2 + 1;

            int[] tprimes = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
            for (int tp : tprimes) {
                ret[pos++] = tp;
                int[] ptn = new int[tp];
                for (int i = (tp - 3) / 2; i < tp << 5; i += tp) ptn[i >> 5] |= 1 << (i & 31);
                for (int j = 0; j < sup; j += tp) {
                    for (int i = 0; i < tp && i + j < sup; i++) {
                        isnp[j + i] |= ptn[i];
                    }
                }
            }

            

            

            int[] magic = {0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14};
            int h = n / 2;
            for (int i = 0; i < sup; i++) {
                for (int j = ~isnp[i]; j != 0; j &= j - 1) {
                    int pp = i << 5 | magic[(j & -j) * 0x076be629 >>> 27];
                    int p = 2 * pp + 3;
                    if (p > n) break;
                    ret[pos++] = p;
                    if ((long) p * p > n) continue;
                    for (int q = (p * p - 3) / 2; q <= h; q += p) isnp[q >> 5] |= 1 << q;
                }
            }

            return Arrays.copyOf(ret, pos);
        }
        static boolean[] sieveOfEratosthenes(int n) {
            

            

            

            

            

            

            

            boolean prime[] = new boolean[n + 1];
            for (int i = 0; i <= n; i++)
                prime[i] = true;

            for (int p = 2; p * p <= n; p++) {
                

                

                if (prime[p] == true) {
                    

                    for (int i = p * p; i <= n; i += p)
                        prime[i] = false;
                }
            }
            return prime;
        }
        public static int getMax(int[] inputArray){
            int maxValue = inputArray[0];
            for(int i=1;i < inputArray.length;i++){
                if(inputArray[i] > maxValue){
                    maxValue = inputArray[i];
                }
            }
            return maxValue;
        }

        

        public static int getMin(int[] inputArray){
            int minValue = inputArray[0];
            for(int i=1;i<inputArray.length;i++){
                if(inputArray[i] < minValue){
                    minValue = inputArray[i];
                }
            }
            return minValue;
        }
        static int countSetBits(long n)
        {
            int count = 0;
            while (n > 0) {
                count += n & 1;
                n >>= 1;
            }
            return count;
        }
        static long binpow(long a, long b) {
            long res = 1;
            while (b > 0) {
                if ((b & 1)>0)
                    res = res * a;
                a = a * a;
                b >>= 1;
            }
            return res;
        }
        static ArrayList<Integer> printDivisors(int n)
        {
            ArrayList<Integer> al=new ArrayList<>();
            for (int i=2; i<=Math.sqrt(n); i++)
            {
                if (n%i==0)
                {
                    

                    if (n/i == i)
                        al.add(i);

                    else 

                    {
                        al.add(i);
                        al.add(n/i);
                    }

                }
            }
            return al;
        }

        static long fastPow(long a, long b, long mod) {
            if(b == 0)
                return 1L;

            long val = fastPow(a, b/2, mod);
            if(b % 2 == 0)
                return val * val % mod;
            else
                return val * val % mod * a % mod;
        }
        static int LowerBound(int a[], int x) { 

            int l=-1,r=a.length;
            while(l+1<r) {
                int m=(l+r)>>>1;
                if(a[m]>=x) r=m;
                else l=m;
            }
            return r;
        }
        static int UpperBound(int a[], int x) {

            int l=-1,r=a.length;
            while(l+1<r) {
                int m=(l+r)>>>1;
                if(a[m]<=x) l=m;
                else r=m;
            }
            return l+1;
        }
        private static long safe_mod(long x, long m){
            x %= m;
            if(x<0) x += m;
            return x;
        }

        private static long[] inv_gcd(long a, long b){
            a = safe_mod(a, b);
            if(a==0) return new long[]{b,0};

            long s=b, t=a;
            long m0=0, m1=1;
            while(t>0){
                long u = s/t;
                s -= t*u;
                m0 -= m1*u;
                long tmp = s; s = t; t = tmp;
                tmp = m0; m0 = m1; m1 = tmp;
            }
            if(m0<0) m0 += b/s;
            return new long[]{s,m0};
        }

        public static long gcd(long a, long b){
            a = java.lang.Math.abs(a);
            b = java.lang.Math.abs(b);
            return inv_gcd(a, b)[0];
        }
        public static long lcm(long a, long b){
            a = java.lang.Math.abs(a);
            b = java.lang.Math.abs(b);
            return a / gcd(a,b) * b;
        }

        public static long pow_mod(long x, long n, int m){
            assert n >= 0;
            assert m >= 1;
            if(m == 1)return 0L;
            x = safe_mod(x, m);
            long ans = 1L;
            while(n > 0){
                if((n&1) == 1) ans = (ans * x) % m;
                x = (x*x) % m;
                n >>>= 1;
            }
            return ans;
        }
        static long fact[]=new long[1000001];
        static long inv_fact[]=new long[1000001];
        static int p=1000000007;
        public static void precomp()
        {
            fact[0]=fact[1]=1;
            for(int i=2;i<=fact.length-1;i++)
            {
                fact[i]=(fact[i-1]*i)%p;
            }
            inv_fact[(int)1e6]=modpow(fact[(int)1e6],p-2);
            for(int i=fact.length-2;i>=0;i--)
            {
                inv_fact[i]=(inv_fact[i+1]*(i+1))%p;
            }
        }
        public static boolean summ(int n,int a,int b)
        {
            while(n>0)
            {
                if(n%10!=a && n%10!=b)return false;
                n/=10;
            }
            return true;
        }
        public static long modpow(long x,long n)
        {
            long res=1;
            while(n>0)
            {
                if(n%2!=0)
                {
                    res=(res*x)%p;n--;
                }
                else
                {
                    x=(x*x)%p;n/=2;
                }
            }
            return res;
        }
        public static long ncr(int n,int r)
        {
            if(r>n || r<0 || n<0)return 0;
            return fact[n]*inv_fact[r]%p*inv_fact[n-r]%p;
        }
        public static void bipartite(int u,boolean vis[],int color[],ArrayList<Integer>[] al)
        {
            vis[u]=true;
            for(int v:al[u])
            {
                if(!vis[v])
                {
                    if(color[v]==-1) {
                        color[v]=1-color[u];
                        bipartite(v,vis,color,al);
                    }
                }

            }
        }

        public static long[] crt(long[] r, long[] m){
            assert(r.length == m.length);
            int n = r.length;

            long r0=0, m0=1;
            for(int i=0; i<n; i++){
                assert(1 <= m[i]);
                long r1 = safe_mod(r[i], m[i]), m1 = m[i];
                if(m0 < m1){
                    long tmp = r0; r0 = r1; r1 = tmp;
                    tmp = m0; m0 = m1; m1 = tmp;
                }
                if(m0%m1 == 0){
                    if(r0%m1 != r1) return new long[]{0,0};
                    continue;
                }

                long[] ig = inv_gcd(m0, m1);
                long g = ig[0], im = ig[1];

                long u1 = m1/g;
                if((r1-r0)%g != 0) return new long[]{0,0};

                long x = (r1-r0) / g % u1 * im % u1;

                r0 += x * m0;
                m0 *= u1;
                if(r0<0) r0 += m0;
                

            }
            return new long[]{r0, m0};
        }
        public static long floor_sum(long n, long m, long a, long b){
            long ans = 0;
            if(a >= m){
                ans += (n-1) * n * (a/m) / 2;
                a %= m;
            }
            if(b >= m){
                ans += n * (b/m);
                b %= m;
            }

            long y_max = (a*n+b) / m;
            long x_max = y_max * m - b;
            if(y_max == 0) return ans;
            ans += (n - (x_max+a-1)/a) * y_max;
            ans += floor_sum(y_max, a, m, (a-x_max%a)%a);
            return ans;
        }

        public static java.util.ArrayList<Long> divisors(long n){
            java.util.ArrayList<Long> divisors = new ArrayList<>();
            java.util.ArrayList<Long> large = new ArrayList<>();

            for(long i=1; i*i<=n; i++) if(n%i==0){
                divisors.add(i);
                if(i*i<n) large.add(n/i);
            }
            for(int p=large.size()-1; p>=0; p--){
                divisors.add(large.get(p));
            }
            return divisors;
        }
    }
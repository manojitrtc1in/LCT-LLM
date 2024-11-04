import java.io.*;
import java.util.*;
import java.util.concurrent.ThreadLocalRandom;
import java.math.*;



public class Solution {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }

    

    static class Task {

        double eps = 0.00000001;
        static final int MAXN = 100005;
        static final int MOD = 998244353;

        

        static int spf[] = new int[MAXN];

        static boolean[] prime;

        Map<Integer, Set<Integer>> dp = new HashMap<>();

        

        

        

        public void sieve() {
            spf[1] = 1;
            for (int i = 2; i < MAXN; i++)

                

                

                spf[i] = i;

            

            

            for (int i = 4; i < MAXN; i += 2)
                spf[i] = 2;

            for (int i = 3; i * i < MAXN; i++) {
                

                if (spf[i] == i) {
                    

                    for (int j = i * i; j < MAXN; j += i)

                        

                        

                        if (spf[j] == j)
                            spf[j] = i;
                }
            }
        }

        void id7(int n) {
            

            

            

            

            

            

            

            prime = new boolean[n + 1];
            for (int i = 0; i <= n; i++)
                prime[i] = true;

            for (int p = 2; p * p <= n; p++) {
                

                

                if (prime[p] == true) {
                    

                    for (int i = p * p; i <= n; i += p)
                        prime[i] = false;
                }
            }
        }

        

        

        public Set<Integer> id12(int x) {
            if (dp.containsKey(x))
                return dp.get(x);
            Set<Integer> ret = new HashSet<>();
            while (x != 1) {
                if (spf[x] != 2)
                    ret.add(spf[x]);
                x = x / spf[x];
            }
            dp.put(x, ret);
            return ret;
        }

        

        public int lowerIndex(List<Integer> arr, int n, int x) {
            int l = 0, h = n - 1;
            while (l <= h) {
                int mid = (l + h) / 2;
                if (arr.get(mid) >= x)
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            return l;
        }

        public int lowerIndex(int[] arr, int n, int x) {
            int l = 0, h = n - 1;
            while (l <= h) {
                int mid = (l + h) / 2;
                if (arr[mid] >= x)
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            return l;
        }

        

        public int upperIndex(List<Integer> arr, int n, int y) {
            int l = 0, h = n - 1;
            while (l <= h) {
                int mid = (l + h) / 2;
                if (arr.get(mid) <= y)
                    l = mid + 1;
                else
                    h = mid - 1;
            }
            return h;
        }

        public int upperIndex(int[] arr, int n, int y) {
            int l = 0, h = n - 1;
            while (l <= h) {
                int mid = (l + h) / 2;
                if (arr[mid] <= y)
                    l = mid + 1;
                else
                    h = mid - 1;
            }
            return h;
        }

        

        public int id2(List<Integer> arr, int n, int x, int y) {
            

            int count = 0;
            count = upperIndex(arr, n, y) -
                    lowerIndex(arr, n, x) + 1;
            return count;
        }

        public int add(int a, int b) {
            a += b;
            while (a >= MOD)
                a -= MOD;
            while (a < 0)
                a += MOD;
            return a;
        }

        public int mul(int a, int b) {
            long res = (long) a * (long) b;
            return (int) (res % MOD);
        }

        public int power(int a, int b) {
            int ans = 1;
            while (b > 0) {
                if ((b & 1) != 0)
                    ans = mul(ans, a);
                b >>= 1;
                a = mul(a, a);
            }
            return ans;
        }

        int[] fact = new int[MAXN];
        int[] inv = new int[MAXN];

        public int Ckn(int n, int k) {
            if (k < 0 || n < 0)
                return 0;
            if (n < k)
                return 0;
            return mul(mul(fact[n], inv[k]), inv[n - k]);
        }

        public int inverse(int a) {
            return power(a, MOD - 2);
        }

        public void preprocess() {
            fact[0] = 1;
            for (int i = 1; i < MAXN; i++)
                fact[i] = mul(fact[i - 1], i);
            inv[MAXN - 1] = inverse(fact[MAXN - 1]);
            for (int i = MAXN - 2; i >= 0; i--) {
                inv[i] = mul(inv[i + 1], i + 1);
            }
        }

        
        public int id5(int[] arr, int x) {
            TreeSet<Integer> set = new TreeSet<>();
            for (int num : arr)
                set.add(num);
            return set.lower(x);
        }

        
        public int id10(int[] arr, int x) {
            TreeSet<Integer> set = new TreeSet<>();
            for (int num : arr)
                set.add(num);
            return set.higher(x);
        }

        public void debugArr(int[] arr) {
            for (int i : arr)
                out.print(i + " ");
            out.println();
        }

        public int rand() {
            int min = 0, max = MAXN;
            int random_int = (int) Math.floor(Math.random() * (max - min + 1) + min);
            return random_int;
        }

        public void id0(int[] arr) {
            shuffleArray(arr);
            Arrays.sort(arr);
        }

        public void shuffleArray(int[] ar) {
            

            Random rnd = ThreadLocalRandom.current();
            for (int i = ar.length - 1; i > 0; i--) {
                int index = rnd.nextInt(i + 1);
                

                int a = ar[index];
                ar[index] = ar[i];
                ar[i] = a;
            }
        }

        InputReader in;
        PrintWriter out;
        Scanner sc = new Scanner(System.in);
        id8 cin;
        int[] xor = new int[3 * 100000 + 5];
        int[] pow2 = new int[1000000 + 1];

        public void solve(InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            

            

            

            

            

            int t = in.nextInt();
            

            

            

            for (int i = 1; i <= t; i++)
                solveD(i);
        }

        final double pi = Math.acos(-1);
        static Point base;

        void solveD(int test) {
            int n = in.nextInt();
            int[] a = in.id9(n), b = in.id9(n);
            long ans = 0, sq = 0;
            int tot = 0;
            for (int i = 0; i < n; i++) {
                sq += a[i] * a[i] + b[i] * b[i];
                tot += a[i] + b[i];
            }
            boolean[] dp = new boolean[10001];
            dp[0] = true;
            ans = (long) sq * (n - 2);
            for (int i = 0; i < n; i++) {
                boolean[] ndp = new boolean[10001];
                for (int t = 0; t < 10001; t++) {
                    if (dp[t]) {
                        if (t + a[i] < 10001)
                            ndp[t + a[i]] = true;
                        if (t + b[i] < 10001)
                            ndp[t + b[i]] = true;
                    }
                }
                dp = ndp;
            }
            long f = (long) 1e18;
            for (int x = 0; x <= Math.min(10000, tot); x++) {
                if (dp[x]) {
                    int l = x;
                    int r = tot - x;
                    f = Math.min(f, (long) l * l + r * r);
                }
            }
            out.println(f + ans);

        }

        private long calc(int[] a) {
            int n = a.length;
            long res = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    res += (long) (a[i] + a[j]) * (a[i] + a[j]);
                }
            }
            return res;
        }

        public void solveC(int t) {
            int n = in.nextInt();
            int[] a = in.id9(n);
            if (n == 3 && a[1] % 2 == 1) {
                out.println(-1);
                return;
            }
            boolean allOne = true;
            boolean existEven = false;
            for (int i = 1; i < n - 1; i++) {
                if (a[i] != 1) {
                    allOne = false;
                }
                if (a[i] % 2 == 0)
                    existEven = true;
            }
            if (allOne) {
                out.println(-1);
                return;
            }
            long res = 0;
            int cntOne = 0;
            for (int i = 1; i < n - 1; i++) {
                int minus = a[i] / 2;
                res += minus;
                a[i] -= 2 * minus;
                if (a[i] == 1)
                    cntOne++;
            }
            

            if (existEven) {
                res--;
                res += cntOne + 1;
            } else {
                cntOne--;
                res--;
                res += cntOne + 2;
            }
            out.println(res);

        }

        public void solveA(int t) {
            int n = in.nextInt();
            int[] a = in.id9(n);
            boolean valid = false;
            for (int i = 1; i < n; i++) {
                if (a[i] < a[i - 1]) {
                    valid = true;
                    break;
                }
            }
            if (valid)
                out.println("YES");
            else
                out.println("NO");
        }

        private int search(List<Integer> values, double key) {
            int l = 0, r = values.size() - 1;
            int res = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (values.get(mid) < key) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                    res = l;
                }
            }
            return res;
        }

        static class ListNode {
            int idx = -1;
            ListNode next = null;

            public ListNode(int idx) {
                this.idx = idx;
            }
        }

        public long _gcd(long a, long b) {

            if (b == 0) {
                return a;
            } else {
                return _gcd(b, a % b);
            }
        }

        public long _lcm(long a, long b) {
            return (a * b) / _gcd(a, b);
        }

    }

    


    


    


    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    


    


    


    static class Venice {
        public Map<Long, Long> m = new HashMap<>();
        public long base = 0;
        public long totalValue = 0;
        private int M = 1000000007;

        private long addMod(long a, long b) {
            a += b;
            if (a >= M)
                a -= M;
            return a;
        }

        public void reset() {
            m = new HashMap<>();
            base = 0;
            totalValue = 0;
        }

        public void update(long add) {
            base = base + add;
        }

        public void add(long key, long val) {
            long newKey = key - base;
            m.put(newKey, addMod(m.getOrDefault(newKey, (long) 0), val));
        }
    }

    static class Tuple implements Comparable<Tuple> {
        int x, y, z;

        public Tuple(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        @Override
        public int compareTo(Tuple o) {
            return this.z - o.z;
        }
    }

    static class Point implements Comparable<Point> {
        public double x;
        public long y;

        public Point(double x, long y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Point o) {
            if (this.y != o.y)
                return (int) (this.y - o.y);
            return (int) (this.x - o.x);
        }
    }

    

    

    


    

    

    

    

    

    


    static class Pair implements Comparable<Pair> {
        public int x;
        public int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Pair o) {
            if (this.x != o.x)
                return (int) (this.x - o.x);
            return (int) (this.y - o.y);
        }
    }

    

    

    

    

    

    


    

    static class InputReader {
        BufferedReader br;
        StringTokenizer st;

        public InputReader(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
        }

        public String nextToken() {
            while (st == null || !st.hasMoreTokens()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                if (line == null) {
                    return null;
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

        public double nextDouble() {
            return Double.parseDouble(nextToken());
        }

        public long nextLong() {
            return Long.parseLong(nextToken());
        }

        public int[] id9(int n) {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++)
                arr[i] = nextInt();
            return arr;
        }

        public long[] id13(int n) {
            long[] arr = new long[n];
            for (int i = 0; i < n; i++)
                arr[i] = nextLong();
            return arr;
        }

        public List<Integer> id11(int n) {
            List<Integer> arr = new ArrayList<>();
            for (int i = 0; i < n; i++)
                arr.add(nextInt());
            return arr;
        }

        public int[][] id6(int n, int m) {
            int[][] mat = new int[n][m];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    mat[i][j] = nextInt();
            return mat;
        }

        public List<List<Integer>> id4(int n, int m) {
            List<List<Integer>> mat = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                List<Integer> temp = new ArrayList<>();
                for (int j = 0; j < m; j++)
                    temp.add(nextInt());
                mat.add(temp);
            }
            return mat;
        }

        public char[] id3() {
            return nextToken().toCharArray();
        }
    }

    static class id8 {
        String path = "";
        Scanner sc;

        public id8(String path) {
            this.path = path;
            try {
                sc = new Scanner(new File(path));
            } catch (Exception e) {
            }
        }

        public String nextLine() {
            return sc.nextLine();
        }

        public int[] id1() {
            String line = sc.nextLine();
            String[] part = line.split("[\\s+]");
            int[] res = new int[part.length];
            for (int i = 0; i < res.length; i++)
                res[i] = Integer.parseInt(part[i]);
            return res;
        }
    }
}

import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class Solution {

    

    static Kattio input = new Kattio();
    static BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out));
    static ArrayList<ArrayList<Integer>> powerSet = new ArrayList<>();
    static ArrayList<LinkedList<Integer>> allprem = new ArrayList<>();
    static ArrayList<LinkedList<String>> allprems = new ArrayList<>();
    static ArrayList<Long> luc = new ArrayList<>();
    static long mod = (long) (Math.pow(10, 9) + 7);
    static int grid[][] = {{0, 0, 1, -1, 1, 1, -1, -1}, {1, -1, 0, 0, 1, -1, 1, -1}};
    static int dp[][];
    static double cmp = 0.000000001;

    public static void main(String[] args) throws IOException {




        int test = input.nextInt();
        loop:
        for (int o = 1; o <= test; o++) {
            int n = input.nextInt();
            int a[] = new int[n];
            int ans = 0;
            ArrayList<Integer> na = new ArrayList<>();
            HashMap<Integer, Integer> s = new HashMap<>();
            ArrayList<Integer> b = new ArrayList<>();
            HashMap<Integer, Integer> h = new HashMap<>();
            for (int i = 0; i < n; i++) {
                a[i] = input.nextInt();
                s.put(a[i], s.get(a[i]) == null ? 1 : 1 + s.get(a[i]));
            }
            for (int i = 0; i < n; i++) {
                int x = input.nextInt();
                if (s.get(x) == null) {
                    b.add(x);
                    h.put(x, h.get(x) == null ? 1 : h.get(x) + 1);
                } else if (s.get(x) == 0) {
                    b.add(x);
                    h.put(x, h.get(x) == null ? 1 : h.get(x) + 1);
                } else {
                    s.put(x, s.get(x) - 1);
                }
            }
            for (int i = 0; i < n; i++) {
                if (s.get(a[i]) > 0) {
                    na.add(a[i]);
                    s.put(a[i], s.get(a[i]) - 1);
                }
            }
            Collections.sort(na);
            Collections.sort(b);
            int fre[] = new int[10];
            int fr[] = new int[10];
            int fre1[] = new int[10];
            int fr1[] = new int[10];
            int numof1a = 0;
            int numof1b = 0;
            for (int i = 0; i < b.size(); i++) {
                if (na.get(i) != 1) {
                    if (na.get(i) < 10) {
                        fre1[na.get(i)]++;
                    } else {
                        fre[get(na.get(i))]++;
                    }
                } else {
                    numof1a++;
                }
                if (b.get(i) != 1) {
                    if (b.get(i) < 10) {
                        fr1[b.get(i)]++;
                    } else {
                        fr[get(b.get(i))]++;
                    }
                } else {
                    numof1b++;
                }
            }
            for (int i = 9; i > 1; i--) {
                int min = Math.min(fre[i], fr1[i]);
                fre[i] -= min;
                fr1[i] -= min;
                ans += min;
                min = Math.min(fre1[i], fr[i]);
                fre1[i] -= min;
                fr[i] -= min;
                ans += min;
                min = Math.min(fre[i], fr[i]);
                fre[i] -= min;
                fr[i] -= min;
                ans += min * 2;
            }
            for (int i = 0; i < 10; i++) {
                ans += fre1[i] + fr1[i];
            }
            for (int i = 2; i < 10; i++) {
                ans += fre[i] * 2;
                ans += fr[i] * 2;
            }
            log.write(ans + "\n");
        }
        log.flush();
    }

    static int get(int x) {
        int cnt = 0;
        while (x > 0) {
            cnt++;
            x /= 10;
        }
        return cnt;
    }

    static Comparator<tri> cmpTri() {
        Comparator<tri> c = new Comparator<tri>() {
            @Override
            public int compare(tri o1, tri o2) {
                if (o1.x > o2.x) {
                    return 1;
                } else if (o1.x < o2.x) {
                    return -1;
                } else {
                    if (o1.y > o2.y) {
                        return 1;
                    } else if (o1.y < o2.y) {
                        return -1;
                    } else {
                        if (o1.z > o2.z) {
                            return 1;
                        } else if (o1.z < o2.z) {
                            return -1;
                        } else {
                            return 0;
                        }
                    }
                }
            }
        };
        return c;
    }

    static Comparator<pair> cmpPair() {
        Comparator<pair> c = new Comparator<pair>() {
            @Override
            public int compare(pair o1, pair o2) {
                if (o1.x > o2.x) {
                    return 1;
                } else if (o1.x < o2.x) {
                    return -1;
                } else {
                    if (o1.y > o2.y) {
                        return 1;
                    } else if (o1.y < o2.y) {
                        return -1;
                    } else {
                        return 0;
                    }
                }
            }
        };
        return c;
    }

    static class rec {

        long x1;
        long x2;
        long y1;
        long y2;

        public rec(long x1, long y1, long x2, long y2) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }

        public long getArea() {
            return (x2 - x1) * (y2 - y1);
        }
    }

    static int sumOfRange(int x1, int y1, int x2, int y2, int e, int a[][][]) {
        return (a[e][x2][y2] - a[e][x1 - 1][y2] - a[e][x2][y1 - 1]) + a[e][x1 - 1][y1 - 1];
    }

    public static int[][] bfs(int i, int j, String w[]) {
        Queue<pair> q = new ArrayDeque<>();
        q.add(new pair(i, j));
        int dis[][] = new int[w.length][w[0].length()];
        for (int k = 0; k < w.length; k++) {
            Arrays.fill(dis[k], -1);
        }
        dis[i][j] = 0;
        while (!q.isEmpty()) {
            pair p = q.poll();
            int cost = dis[p.x][p.y];
            for (int k = 0; k < 4; k++) {
                int nx = p.x + grid[0][k];
                int ny = p.y + grid[1][k];
                if (isValid(nx, ny, w.length, w[0].length())) {
                    if (dis[nx][ny] == -1 && w[nx].charAt(ny) == '.') {
                        q.add(new pair(nx, ny));
                        dis[nx][ny] = cost + 1;
                    }
                }
            }
        }
        return dis;
    }

    public static void dfs(int node, ArrayList<Integer> a[], boolean vi[]) {
        vi[node] = true;
        for (Integer ch : a[node]) {
            if (!vi[ch]) {
                dfs(ch, a, vi);
            }
        }
    }

    public static void graphRepresintion(ArrayList<Integer>[] a, int q) throws IOException {
        for (int i = 0; i < a.length; i++) {
            a[i] = new ArrayList<>();
        }
        while (q-- > 0) {
            int x = input.nextInt();
            int y = input.nextInt();
            a[x].add(y);
            a[y].add(x);
        }
    }

    public static boolean isValid(int i, int j, int n, int m) {
        return (i > -1 && i < n) && (j > -1 && j < m);
    }

    

    public static int[] swap(int data[], int left, int right) {

        

        int temp = data[left];
        data[left] = data[right];
        data[right] = temp;

        

        return data;
    }

    

    

    

    public static int[] reverse(int data[], int left, int right) {

        

        while (left < right) {
            int temp = data[left];
            data[left++] = data[right];
            data[right--] = temp;
        }

        

        return data;
    }

    

    

    public static boolean findNextPermutation(int data[]) {

        

        

        

        if (data.length <= 1) {
            return false;
        }

        int last = data.length - 2;

        

        

        while (last >= 0) {
            if (data[last] < data[last + 1]) {
                break;
            }
            last--;
        }

        

        

        if (last < 0) {
            return false;
        }

        int nextGreater = data.length - 1;

        

        for (int i = data.length - 1; i > last; i--) {
            if (data[i] > data[last]) {
                nextGreater = i;
                break;
            }
        }

        

        data = swap(data, nextGreater, last);

        

        data = reverse(data, last + 1, data.length - 1);

        

        return true;
    }

    public static pair[] dijkstra(int node, ArrayList<pair> a[]) {
        PriorityQueue<tri> q = new PriorityQueue<>(new Comparator<tri>() {
            @Override
            public int compare(tri o1, tri o2) {
                if (o1.y > o2.y) {
                    return 1;
                } else if (o1.y < o2.y) {
                    return -1;
                } else {
                    return 0;
                }
            }
        });
        q.add(new tri(node, 0, -1));
        pair distance[] = new pair[a.length];
        while (!q.isEmpty()) {
            tri p = q.poll();
            int cost = p.y;
            if (distance[p.x] != null) {
                continue;
            }
            distance[p.x] = new pair(p.z, cost);
            ArrayList<pair> nodes = a[p.x];
            for (pair node1 : nodes) {
                if (distance[node1.x] == null) {
                    tri pa = new tri(node1.x, cost + node1.y, p.x);
                    q.add(pa);
                }
            }
        }
        return distance;
    }

    public static String revs(String w) {
        String ans = "";
        for (int i = w.length() - 1; i > -1; i--) {
            ans += w.charAt(i);
        }
        return ans;
    }

    public static boolean isPalindrome(String w) {
        for (int i = 0; i < w.length() / 2; i++) {
            if (w.charAt(i) != w.charAt(w.length() - i - 1)) {
                return false;
            }
        }
        return true;
    }

    public static void getPowerSet(Queue<Integer> a) {
        int n = a.poll();
        if (!a.isEmpty()) {
            getPowerSet(a);
        }
        int s = powerSet.size();
        for (int i = 0; i < s; i++) {
            ArrayList<Integer> ne = new ArrayList<>();
            ne.add(n);
            for (int j = 0; j < powerSet.get(i).size(); j++) {
                ne.add(powerSet.get(i).get(j));
            }

            powerSet.add(ne);
        }
        ArrayList<Integer> p = new ArrayList<>();
        p.add(n);
        powerSet.add(p);
    }

    public static int getlo(int va) {
        int v = 1;
        while (v <= va) {
            if ((va&v) != 0) {
                return v;
            }
            v <<= 1;
        }
        return 0;
    }

    static long fast_pow(long a, long p, long mod) {
        long res = 1;
        while (p > 0) {
            if (p % 2 == 0) {
                a = (a * a) % mod;
                p /= 2;
            } else {
                res = (res * a) % mod;
                p--;
            }
        }
        return res;
    }

    public static int countPrimeInRange(int n, boolean isPrime[]) {
        int cnt = 0;
        Arrays.fill(isPrime, true);
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * 2; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                cnt++;
            }
        }
        return cnt;
    }

    public static void create(long num) {
        luc.add(num);
        if (num > power(10, 9)) {
            return;
        }
        create(num * 10 + 4);
        create(num * 10 + 7);
    }

    public static long ceil(long a, long b) {
        return (a + b - 1) / b;
    }

    public static long round(long a, long b) {
        if (a < 0) {
            return (a - b / 2) / b;
        }
        return (a + b / 2) / b;
    }

    public static void allPremutationsst(LinkedList<String> l, boolean visited[], ArrayList<String> st) {
        if (l.size() == st.size()) {
            allprems.add(l);
        }
        for (int i = 0; i < st.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                LinkedList<String> nl = new LinkedList<>();
                for (String x : l) {
                    nl.add(x);
                }
                nl.add(st.get(i));
                allPremutationsst(nl, visited, st);
                visited[i] = false;
            }
        }
    }

    public static void allPremutations(LinkedList<Integer> l, boolean visited[], int a[]) {
        if (l.size() == a.length) {
            allprem.add(l);
        }
        for (int i = 0; i < a.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                LinkedList<Integer> nl = new LinkedList<>();
                for (Integer x : l) {
                    nl.add(x);
                }
                nl.add(a[i]);
                allPremutations(nl, visited, a);
                visited[i] = false;
            }
        }
    }

    public static int binarySearch(long[] a, long value) {
        int l = 0;
        int r = a.length - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (a[m] == value) {
                return m;
            } else if (a[m] > value) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }

    public static void reverse(int l, int r, char ch[]) {
        for (int i = 0; i < r / 2; i++) {
            char c = ch[i];
            ch[i] = ch[r - i - 1];
            ch[r - i - 1] = c;
        }
    }

    public static int logK(long v, long k) {
        int ans = 0;
        while (v > 1) {
            ans++;
            v /= k;
        }
        return ans;
    }

    public static long power(long a, long n) {
        if (n == 1) {
            return a;
        }
        long pow = power(a, n / 2);
        pow *= pow;
        if (n % 2 != 0) {
            pow *= a;
        }
        return pow;
    }

    public static long get(long max, long x) {
        if (x == 1) {
            return max;
        }
        int cnt = 0;
        while (max > 0) {
            cnt++;
            max /= x;
        }
        return cnt;
    }

    public static int numOF0(long v) {
        long x = 1;
        int cnt = 0;
        while (x <= v) {
            if ((x & v) == 0) {
                cnt++;
            }
            x <<= 1;
        }
        return cnt;
    }

    public static int log2(double n) {
        int cnt = 0;
        while (n > 1) {
            n /= 2;
            cnt++;
        }
        return cnt;
    }

    public static int[] bfs(int node, ArrayList<Integer> a[]) {
        Queue<Integer> q = new LinkedList<>();
        q.add(node);
        int distances[] = new int[a.length];
        Arrays.fill(distances, -1);
        distances[node] = 0;
        while (!q.isEmpty()) {
            int parent = q.poll();
            ArrayList<Integer> nodes = a[parent];
            int cost = distances[parent];
            for (Integer node1 : nodes) {
                if (distances[node1] == -1) {
                    q.add(node1);
                    distances[node1] = cost + 1;
                }
            }
        }
        return distances;
    }

    public static ArrayList<Integer> primeFactors(int n) {
        ArrayList<Integer> a = new ArrayList<>();
        while (n % 2 == 0) {
            a.add(2);
            n /= 2;
        }
        for (int i = 3; i <= Math.sqrt(n); i += 2) {
            while (n % i == 0) {
                a.add(i);
                n /= i;
            }
            if (n < i) {
                break;
            }
        }
        if (n > 2) {

            a.add(n);
        }
        return a;
    }

    public static ArrayList<Integer> printPrimeFactoriztion(int n) {
        ArrayList<Integer> a = new ArrayList<>();
        for (int i = 1; i < Math.sqrt(n) + 1; i++) {
            if (n % i == 0) {
                if (isPrime(i)) {
                    a.add(i);
                    n /= i;
                    i = 0;
                } else if (isPrime(n / i)) {
                    a.add(n / i);
                    n = i;
                    i = 0;
                }
            }
        }
        return a;
    }



    public static BigInteger f(long n) {
        if (n <= 1) {
            return BigInteger.ONE;
        }
        long t = n - 1;
        BigInteger b = new BigInteger(t + "");
        BigInteger ans = new BigInteger(n + "");
        while (t > 1) {
            ans = ans.multiply(b);
            b = b.subtract(BigInteger.ONE);
            t--;
        }
        return ans;
    }

    public static long factorial(long n) {
        if (n <= 1) {
            return 1;
        }
        long t = n - 1;
        while (t > 1) {
            n = mod((mod(n, mod) * mod(t, mod)), mod);
            t--;
        }
        return n;
    }

    public static long rev(long n) {
        long t = n;
        long ans = 0;
        while (t > 0) {
            ans = ans * 10 + t % 10;
            t /= 10;
        }
        return ans;
    }

    public static boolean isPalindrome(int n) {
        int t = n;
        int ans = 0;
        while (t > 0) {
            ans = ans * 10 + t % 10;
            t /= 10;
        }
        return ans == n;

    }

    static class tri {

        int x, y, z;

        public tri(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        @Override
        public String toString() {
            return x + " " + y + " " + z;
        }
    }

    static boolean isPrime(long num) {
        if (num == 1) {
            return false;
        }
        if (num == 2) {
            return true;
        }
        if (num % 2 == 0) {
            return false;
        }
        if (num == 3) {
            return true;
        }
        for (int i = 3; i <= Math.sqrt(num) + 1; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void prefixSum(int[] a) {
        for (int i = 1; i < a.length; i++) {
            a[i] = a[i] + a[i - 1];
        }
    }

    public static void suffixSum(long[] a) {
        for (int i = a.length - 2; i > -1; i--) {
            a[i] = a[i] + a[i + 1];
        }
    }

    static long mod(long a, long b) {
        long r = a % b;
        return r < 0 ? r + b : r;
    }

    public static long binaryToDecimal(String w) {
        long r = 0;
        long l = 0;
        for (int i = w.length() - 1; i > -1; i--) {
            long x = (w.charAt(i) - '0') * (long) Math.pow(2, l);
            r = r + x;
            l++;
        }
        return r;
    }

    public static String decimalToBinary(long n) {
        String w = "";
        while (n > 0) {
            w = n % 2 + w;
            n /= 2;
        }
        return w;
    }

    public static boolean isSorted(int[] a) {
        for (int i = 0; i < a.length - 1; i++) {
            if (a[i] >= a[i + 1]) {
                return false;
            }
        }
        return true;
    }

    public static void print(int[] a) throws IOException {
        for (int i = 0; i < a.length; i++) {
            log.write(a[i] + " ");
        }
        log.write("\n");
    }

    public static void read(int[] a) {
        for (int i = 0; i < a.length; i++) {
            a[i] = input.nextInt();

        }
    }

    static class pair {

        int x;
        int y;

        public pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return x + " " + y;
        }
    }

    static class pai {

        long x;
        int y;

        public pai(long x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return x + " " + y;
        }
    }

    public static int LCM(int x, int y) {
        return x / GCD(x, y) * y;
    }

    public static int GCD(int x, int y) {
        if (y == 0) {
            return x;
        }
        return GCD(y, x % y);
    }

    public static void simplifyTheFraction(int a, int b) {
        int GCD = GCD(a, b);
        System.out.println(a / GCD + " " + b / GCD);

    }

    static class Kattio extends PrintWriter {

        private BufferedReader r;
        private StringTokenizer st;
        


        public Kattio() {
            this(System.in, System.out);
        }

        public Kattio(InputStream i, OutputStream o) {
            super(o);
            r = new BufferedReader(new InputStreamReader(i));
        }
        


        public Kattio(String problemName) throws IOException {
            super(problemName + ".out");
            r = new BufferedReader(new FileReader(problemName + ".in"));
        }
        


        String nextLine() {
            String str = "";
            try {
                str = r.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        public String next() {
            try {
                while (st == null || !st.hasMoreTokens()) {
                    st = new StringTokenizer(r.readLine());
                }
                return st.nextToken();
            } catch (Exception e) {
            }
            return null;
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }
}

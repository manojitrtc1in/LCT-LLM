import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class Solution {

    

    static id13 input = new id13();
    static BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out));
    static ArrayList<ArrayList<Integer>> powerSet = new ArrayList<>();
    static ArrayList<LinkedList<Integer>> allprem = new ArrayList<>();
    static ArrayList<LinkedList<String>> id8 = new ArrayList<>();
    static ArrayList<Long> luc = new ArrayList<>();
    static long mod = (long) (Math.pow(10, 9) + 7);
    static int grid[][] = {{0, 0, 1, -1, 1, 1, -1, -1}, {1, -1, 0, 0, 1, -1, 1, -1}};
    static int gr[][] = {{0, 0, 1, -1, -1, 1}, {1, -1, 0, 0, -1, 1}};
    static int dp[][][];
    static double cmp = 0.000000001;

    public static void main(String[] args) throws IOException {




        int test = input.nextInt();
        loop:
        for (int o = 1; o <= test; o++) {
            int n = input.nextInt();
            int m = input.nextInt();
            int nm = m + (m % 2);
            int nta[] = new int[n + 1];
            boolean ca = false;
            ArrayList<Integer> a[] = new ArrayList[m];
            for (int i = 0; i < m; i++) {
                int k = input.nextInt();
                a[i] = new ArrayList<>();
                for (int j = 0; j < k; j++) {
                    int x = input.nextInt();
                    if (k == 1) {
                        nta[x]++;
                        if (nta[x] > nm / 2) {
                            ca = true;
                        }
                    }
                    a[i].add(x);
                }
            }
            int ans[] = new int[m];
            if (ca) {
                log.write("NO\n");
                continue;
            }
            for (int i = 0; i < m; i++) {
                int min = -1;
                if (a[i].size() == 1) {
                    ans[i] = a[i].get(0);
                    continue;
                }
                for (int j = 0; j < a[i].size(); j++) {
                    int x = a[i].get(j);
                    if (nta[x] == nm / 2) {
                        continue;
                    }
                    if (min == -1) {
                        min = x;
                    } else if (nta[x] < nta[min]) {
                        min = x;
                    }
                }
                if (min == -1) {
                    log.write("NO\n");
                    continue loop;
                }
                nta[min]++;
                ans[i] = min;
            }
            log.write("YES\n");
            print(ans);
        }
        log.flush();
    }

    static long solve(long h, long n, boolean ch) {
        long ha = 1l << h - 1;
        if (h == 0) {
            return 0;
        }
        if (n > ha) {
            if (ch) {
                return 1 + solve(h - 1, n - ha, !ch);
            } else {
                return 2 * ha + solve(h - 1, n - ha, ch);
            }
        } else {
            if (ch) {
                return 2 * ha + solve(h - 1, n, ch);
            } else {
                return 1 + solve(h - 1, n, !ch);
            }
        }
    }

    public static long id18(String w, long base) {
        long r = 0;
        long l = 0;
        for (int i = w.length() - 1; i > -1; i--) {
            long x = (w.charAt(i) - '0') * (long) Math.pow(base, l);
            r = r + x;
            l++;
        }
        return r;
    }

    static int bs(int v, ArrayList<Integer> a) {
        int max = a.size() - 1;
        int min = 0;
        int ans = 0;
        while (max >= min) {
            int mid = (max + min) / 2;
            if (a.get(mid) >= v) {
                ans = a.size() - mid;
                max = mid - 1;
            } else {
                min = mid + 1;
            }
        }
        return ans;
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

    static int id9(int x1, int y1, int x2, int y2, int e, int a[][][]) {
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

    public static void id1(ArrayList<Integer>[] a, int q) throws IOException {
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

    

    

    public static boolean id12(int data[]) {

        

        

        

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

    public static void id11(Queue<Integer> a) {
        int n = a.poll();
        if (!a.isEmpty()) {
            id11(a);
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

    public static int id23(int n, boolean isPrime[]) {
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

    public static void id3(LinkedList<String> l, boolean visited[], ArrayList<String> st) {
        if (l.size() == st.size()) {
            id8.add(l);
        }
        for (int i = 0; i < st.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                LinkedList<String> nl = new LinkedList<>();
                for (String x : l) {
                    nl.add(x);
                }
                nl.add(st.get(i));
                id3(nl, visited, st);
                visited[i] = false;
            }
        }
    }

    public static void id22(LinkedList<Integer> l, boolean visited[], int a[]) {
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
                id22(nl, visited, a);
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

    public static int id10(long v) {
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

    public static ArrayList<Long> primeFactors(long n) {
        ArrayList<Long> a = new ArrayList<>();
        while (n % 2 == 0) {
            a.add(2l);
            n /= 2;
        }
        for (long i = 3; i <= Math.sqrt(n); i += 2) {
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

    public static void prefixSum(long[] a) {
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

    public static long id20(String w) {
        long r = 0;
        long l = 0;
        for (int i = w.length() - 1; i > -1; i--) {
            long x = (w.charAt(i) - '0') * (long) Math.pow(2, l);
            r = r + x;
            l++;
        }
        return r;
    }

    public static String id15(long n, long base) {
        String w = "";
        while (n > 0) {
            w = n % base + w;
            n /= base;
        }
        return w;
    }

    public static String id5(long n) {
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

    static class gepair {

        long x;
        long y;

        public gepair(long x, long y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return x + " " + y;
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

    public static long LCM(long x, long y) {
        return x / GCD(x, y) * y;
    }

    public static long GCD(long x, long y) {
        if (y == 0) {
            return x;
        }
        return GCD(y, x % y);
    }

    public static void id16(int a, int b) {
        long GCD = GCD(a, b);
        System.out.println(a / GCD + " " + b / GCD);

    }

    static class id13 extends PrintWriter {

        private BufferedReader r;
        private StringTokenizer st;
        


        public id13() {
            this(System.in, System.out);
        }

        public id13(InputStream i, OutputStream o) {
            super(o);
            r = new BufferedReader(new InputStreamReader(i));
        }
        


        public id13(String problemName) throws IOException {
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

     

    static class id0<T extends Comparable<T>> {

        
        public static final int BLACK = 0;
        
        public static final int RED = 1;
        

        public T key;

        
        id0<T> parent;
        
        id0<T> left;
        
        id0<T> right;
        

        public int numLeft = 0;
        

        public int numRight = 0;
        

        public int color;

        id0() {
            color = BLACK;
            numLeft = 0;
            numRight = 0;
            parent = null;
            left = null;
            right = null;
        }

        

        id0(T key) {
            this();
            this.key = key;
        }
    }


    static class id7<T extends Comparable<T>> {

        

        private id0<T> nil = new id0<T>();
        private id0<T> root = nil;

        public id7() {
            root.left = nil;
            root.right = nil;
            root.parent = nil;
        }

        

        

        private void leftRotate(id0<T> x) {

            

            

            id26(x);

            

            

            id0<T> y;
            y = x.right;
            x.right = y.left;

            

            if (!isNil(y.left)) {
                y.left.parent = x;
            }
            y.parent = x.parent;

            

            if (isNil(x.parent)) {
                root = y;
            } 

            else if (x.parent.left == x) {
                x.parent.left = y;
            } 

            else {
                x.parent.right = y;
            }

            

            y.left = x;
            x.parent = y;
        }


        

        

        private void id26(id0 x) {

            

            if (isNil(x.left) && isNil(x.right.left)) {
                x.numLeft = 0;
                x.numRight = 0;
                x.right.numLeft = 1;
            } 

            else if (isNil(x.left) && !isNil(x.right.left)) {
                x.numLeft = 0;
                x.numRight = 1 + x.right.left.numLeft
                        + x.right.left.numRight;
                x.right.numLeft = 2 + x.right.left.numLeft
                        + x.right.left.numRight;
            } 

            else if (!isNil(x.left) && isNil(x.right.left)) {
                x.numRight = 0;
                x.right.numLeft = 2 + x.left.numLeft + x.left.numRight;

            } 

            else {
                x.numRight = 1 + x.right.left.numLeft
                        + x.right.left.numRight;
                x.right.numLeft = 3 + x.left.numLeft + x.left.numRight
                        + x.right.left.numLeft + x.right.left.numRight;
            }

        }


        

        

        private void rightRotate(id0<T> y) {

            

            id19(y);

            

            id0<T> x = y.left;
            y.left = x.right;

            

            if (!isNil(x.right)) {
                x.right.parent = y;
            }
            x.parent = y.parent;

            

            if (isNil(y.parent)) {
                root = x;
            } 

            else if (y.parent.right == y) {
                y.parent.right = x;
            } 

            else {
                y.parent.left = x;
            }
            x.right = y;

            y.parent = x;

        }


        

        

        private void id19(id0 y) {

            

            if (isNil(y.right) && isNil(y.left.right)) {
                y.numRight = 0;
                y.numLeft = 0;
                y.left.numRight = 1;
            } 

            else if (isNil(y.right) && !isNil(y.left.right)) {
                y.numRight = 0;
                y.numLeft = 1 + y.left.right.numRight
                        + y.left.right.numLeft;
                y.left.numRight = 2 + y.left.right.numRight
                        + y.left.right.numLeft;
            } 

            else if (!isNil(y.right) && isNil(y.left.right)) {
                y.numLeft = 0;
                y.left.numRight = 2 + y.right.numRight + y.right.numLeft;

            } 

            else {
                y.numLeft = 1 + y.left.right.numRight
                        + y.left.right.numLeft;
                y.left.numRight = 3 + y.right.numRight
                        + y.right.numLeft
                        + y.left.right.numRight + y.left.right.numLeft;
            }

        }


        public void insert(T key) {
            insert(new id0<T>(key));
        }

        

        

        

        private void insert(id0<T> z) {

            

            id0<T> y = nil;
            id0<T> x = root;

            

            

            while (!isNil(x)) {
                y = x;

                

                if (z.key.compareTo(x.key) < 0) {

                    

                    x.numLeft++;
                    x = x.left;
                } 

                else {

                    

                    x.numRight++;
                    x = x.right;
                }
            }
            

            z.parent = y;

            

            

            if (isNil(y)) {
                root = z;
            } else if (z.key.compareTo(y.key) < 0) {
                y.left = z;
            } else {
                y.right = z;
            }

            

            z.left = nil;
            z.right = nil;
            z.color = id0.RED;

            

            id14(z);

        }


        

        

        

        

        private void id14(id0<T> z) {

            id0<T> y = nil;
            

            while (z.parent.color == id0.RED) {

                

                if (z.parent == z.parent.parent.left) {

                    

                    y = z.parent.parent.right;

                    

                    if (y.color == id0.RED) {
                        z.parent.color = id0.BLACK;
                        y.color = id0.BLACK;
                        z.parent.parent.color = id0.RED;
                        z = z.parent.parent;
                    } 

                    else if (z == z.parent.right) {

                        

                        z = z.parent;
                        leftRotate(z);
                    } 

                    else {
                        

                        z.parent.color = id0.BLACK;
                        z.parent.parent.color = id0.RED;
                        rightRotate(z.parent.parent);
                    }
                } 

                else {

                    

                    y = z.parent.parent.left;

                    

                    if (y.color == id0.RED) {
                        z.parent.color = id0.BLACK;
                        y.color = id0.BLACK;
                        z.parent.parent.color = id0.RED;
                        z = z.parent.parent;
                    } 

                    else if (z == z.parent.left) {
                        

                        z = z.parent;
                        rightRotate(z);
                    } 

                    else {
                        

                        z.parent.color = id0.BLACK;
                        z.parent.parent.color = id0.RED;
                        leftRotate(z.parent.parent);
                    }
                }
            }
            

            root.color = id0.BLACK;

        }


        

        

        public id0<T> treeMinimum(id0<T> node) {

            

            while (!isNil(node.left)) {
                node = node.left;
            }
            return node;
        }


        

        

        

        public id0<T> id2(id0<T> x) {

            

            

            if (!isNil(x.left)) {
                return treeMinimum(x.right);
            }

            id0<T> y = x.parent;

            

            while (!isNil(y) && x == y.right) {
                

                x = y;
                y = y.parent;
            }
            

            return y;
        }


        

        

        public void remove(id0<T> v) {

            id0<T> z = search(v.key);

            

            id0<T> x = nil;
            id0<T> y = nil;

            

            if (isNil(z.left) || isNil(z.right)) {
                y = z;
            } 

            else {
                y = id2(z);
            }

            

            if (!isNil(y.left)) {
                x = y.left;
            } else {
                x = y.right;
            }

            

            x.parent = y.parent;

            

            if (isNil(y.parent)) {
                root = x;
            } 

            else if (!isNil(y.parent.left) && y.parent.left == y) {
                y.parent.left = x;
            } 

            else if (!isNil(y.parent.right) && y.parent.right == y) {
                y.parent.right = x;
            }

            

            if (y != z) {
                z.key = y.key;
            }

            

            

            id4(x, y);

            

            

            if (y.color == id0.BLACK) {
                id17(x);
            }
        }


        

        

        private void id4(id0<T> x, id0<T> y) {

            

            id0<T> current = nil;
            id0<T> track = nil;

            

            

            if (isNil(x)) {
                current = y.parent;
                track = y;
            } 

            

            else {
                current = x.parent;
                track = x;
            }

            

            while (!isNil(current)) {
                

                

                if (y.key != current.key) {

                    

                    

                    if (y.key.compareTo(current.key) > 0) {
                        current.numRight--;
                    }

                    

                    

                    if (y.key.compareTo(current.key) < 0) {
                        current.numLeft--;
                    }
                } 

                

                else {
                    

                    

                    if (isNil(current.left)) {
                        current.numLeft--;
                    } else if (isNil(current.right)) {
                        current.numRight--;
                    } 

                    

                    

                    else if (track == current.right) {
                        current.numRight--;
                    } else if (track == current.left) {
                        current.numLeft--;
                    }
                }

                

                track = current;
                current = current.parent;

            }

        }


        

        

        

        private void id17(id0<T> x) {

            id0<T> w;

            

            while (x != root && x.color == id0.BLACK) {

                

                if (x == x.parent.left) {

                    

                    w = x.parent.right;

                    

                    if (w.color == id0.RED) {
                        w.color = id0.BLACK;
                        x.parent.color = id0.RED;
                        leftRotate(x.parent);
                        w = x.parent.right;
                    }

                    

                    if (w.left.color == id0.BLACK
                            && w.right.color == id0.BLACK) {
                        w.color = id0.RED;
                        x = x.parent;
                    } 

                    else {
                        

                        if (w.right.color == id0.BLACK) {
                            w.left.color = id0.BLACK;
                            w.color = id0.RED;
                            rightRotate(w);
                            w = x.parent.right;
                        }
                        

                        w.color = x.parent.color;
                        x.parent.color = id0.BLACK;
                        w.right.color = id0.BLACK;
                        leftRotate(x.parent);
                        x = root;
                    }
                } 

                else {

                    

                    w = x.parent.left;

                    

                    if (w.color == id0.RED) {
                        w.color = id0.BLACK;
                        x.parent.color = id0.RED;
                        rightRotate(x.parent);
                        w = x.parent.left;
                    }

                    

                    if (w.right.color == id0.BLACK
                            && w.left.color == id0.BLACK) {
                        w.color = id0.RED;
                        x = x.parent;
                    } 

                    else {
                        

                        if (w.left.color == id0.BLACK) {
                            w.right.color = id0.BLACK;
                            w.color = id0.RED;
                            leftRotate(w);
                            w = x.parent.left;
                        }

                        

                        w.color = x.parent.color;
                        x.parent.color = id0.BLACK;
                        w.left.color = id0.BLACK;
                        rightRotate(x.parent);
                        x = root;
                    }
                }
            }


            

            

            x.color = id0.BLACK;
        }


        

        

        

        

        public id0<T> search(T key) {

            

            id0<T> current = root;

            

            while (!isNil(current)) {

                

                if (current.key.equals(key)) 

                {
                    return current;
                } 

                else if (current.key.compareTo(key) < 0) {
                    current = current.right;
                } 

                else {
                    current = current.left;
                }
            }

            

            return null;

        }


        

        

        public int numGreater(T key) {

            

            

            return id6(root, key);

        }


        

        

        public int id25(T key) {

            

            

            return id24(root, key);

        }


        

        

        

        public int id6(id0<T> node, T key) {

            

            if (isNil(node)) {
                return 0;
            } 

            

            else if (key.compareTo(node.key) < 0) {
                return 1 + node.numRight + id6(node.left, key);
            } 

            

            else {
                return id6(node.right, key);
            }

        }


        
        public List<T> id21(T key, Integer maxReturned) {
            List<T> list = new ArrayList<T>();
            id21(root, key, list);
            return list.subList(0, Math.min(maxReturned, list.size()));
        }

        private void id21(id0<T> node, T key,
                List<T> list) {
            if (isNil(node)) {
                return;
            } else if (node.key.compareTo(key) > 0) {
                id21(node.left, key, list);
                list.add(node.key);
                id21(node.right, key, list);
            } else {
                id21(node.right, key, list);
            }
        }

        

        

        

        public int id24(id0<T> node, T key) {

            

            if (isNil(node)) {
                return 0;
            } 

            

            else if (key.compareTo(node.key) <= 0) {
                return id24(node.left, key);
            } 

            

            

            else {
                return 1 + node.numLeft + id24(node.right, key);
            }

        }


        

        

        private boolean isNil(id0 node) {

            

            return node == nil;

        }


        

        

        

        public int size() {
            

            

            return root.numLeft + root.numRight + 1;
        }


    }

}

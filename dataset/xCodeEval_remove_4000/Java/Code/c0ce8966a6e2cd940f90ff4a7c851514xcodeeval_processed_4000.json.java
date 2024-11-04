import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.*;

import static java.lang.Math.*;

public class Main {

    final boolean id2 = System.getProperty("id2") != null;
    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    void init() throws FileNotFoundException {
        if (id2) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        } else {
            in = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
        }
    }

    String readString() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    int readInt() throws IOException {
        return Integer.parseInt(readString());
    }

    long readLong() throws IOException {
        return Long.parseLong(readString());
    }

    double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }

    public static void main(String[] args) {
        new Main().run();
        

    }

    public static void mergeSort(int[] a) {
        mergeSort(a, 0, a.length - 1);
    }

    private static void mergeSort(int[] a, int id8, int rightIndex) {
        final int id0 = 50;
        if (id8 < rightIndex) {
            if (rightIndex - id8 <= id0) {
                id1(a, id8, rightIndex);
            } else {
                int middleIndex = (id8 + rightIndex) / 2;
                mergeSort(a, id8, middleIndex);
                mergeSort(a, middleIndex + 1, rightIndex);
                merge(a, id8, middleIndex, rightIndex);
            }
        }
    }

    private static void merge(int[] a, int id8, int middleIndex,
                              int rightIndex) {
        int length1 = middleIndex - id8 + 1;
        int length2 = rightIndex - middleIndex;
        int[] id3 = new int[length1];
        int[] rightArray = new int[length2];
        System.arraycopy(a, id8, id3, 0, length1);
        System.arraycopy(a, middleIndex + 1, rightArray, 0, length2);
        for (int k = id8, i = 0, j = 0; k <= rightIndex; k++) {
            if (i == length1) {
                a[k] = rightArray[j++];
            } else if (j == length2) {
                a[k] = id3[i++];
            } else {
                a[k] = id3[i] <= rightArray[j] ? id3[i++]
                        : rightArray[j++];
            }
        }
    }

    private static void id1(int[] a, int id8, int rightIndex) {
        for (int i = id8 + 1; i <= rightIndex; i++) {
            int current = a[i];
            int j = i - 1;
            while (j >= id8 && a[j] > current) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = current;
        }
    }

    public void run() {
        try {
            long t1 = System.currentTimeMillis();
            init();
            solve();
            out.close();
            long t2 = System.currentTimeMillis();
            System.err.println("Time = " + (t2 - t1));
        } catch (Exception e) {
            e.printStackTrace(System.err);
            System.exit(-1);
        }
    }



    class LOL implements Comparable<LOL> {

        int x;
        int y;



        public LOL(int x, int y) {
            this.x = x;
            this.y = y;

        }

        @Override
        public int compareTo(LOL o) {

            return (x - o.x); 

            

        }

    }

    class LOL2 implements Comparable<LOL2> {

        int x;
        int y;
        int z;



        public LOL2(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        @Override
        public int compareTo(LOL2 o) {

            return (z - o.z); 

            

        }

    }

    class test implements Comparable<test> {

        long x;
        long y;



        public test(long x, long y) {
            this.x = x;
            this.y = y;

        }

        @Override
        public int compareTo(test o) {
            


            

            

            


            int compareResult = Long.compare(x, o.x);

            if (compareResult != 0) {
                return compareResult;
            }

            return Long.compare(y, o.y);

            

        }

    }

    class data {
        String name;
        String city;

        data(String name, String city) {
            this.city = city;
            this.name = name;
        }
    }

    class Point {
        double x;
        double y;


        Point(double x, double y) {
            this.x = x;
            this.y = y;

        }

        double distance(Point temp) {
            return Math.sqrt((x - temp.x) * (x - temp.x) + (y - temp.y) * (y - temp.y));
        }

        double id9(Point temp) {
            return ((x - temp.x) * (x - temp.x) + (y - temp.y) * (y - temp.y));
        }

        Point rotate(double alpha) {
            return new Point(x * cos(alpha) - y * sin(alpha), x * sin(alpha) + y * cos(alpha));
        }

        void sum(Point o) {
            x += o.x;
            y += o.y;
        }

        void scalarProduct(int alpha) {
            x *= alpha;
            y *= alpha;
        }

    }

    class Line {
        double a;
        double b;
        double c;

        Line(Point A, Point B) {
            a = B.y - A.y;
            b = A.x - B.x;
            c = -A.x * a - A.y * b;
        }
        Line(double a, double b, double c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

      Point intersection(Line o) {
            double det = a * o.b - b * o.a;
            double det1 = -c * o.b + b * o.c;
            double det2 = -a * o.c + c * o.a;
            return new Point(det1 / det, det2 / det);
        }
    }

 

    class record implements Comparable<record> {
        String city;
        Long score;

        public record(String name, Long score) {
            this.city = name;
            this.score = score;
        }

        @Override
        public int compareTo(record o) {
            if (o.city.equals(city)) {
                return 0;
            }

            if (score.equals(o.score)) {
                return 1;
            }

            if (score > o.score) {
                return 666;
            } else {
                return -666;
            }

            


        }

    }

    public long gcd(long a, long b) {
        if (a == 0 || b == 0) return max(a, b);

        if (a % b == 0)
            return b;
        else
            return gcd(b, a % b);
    }

    boolean prime(long n) {
        if (n == 1) return false;
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return false;
        return true;
    }

    public int sum(long n) {
        int s = 0;

        while (n > 0) {
            s += (n % 10);
            n /= 10;
        }

        return s;

    }

 




    ArrayList<Integer> primes;
    boolean[] isPrime;

    public void id5 (int n) {
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.add(i);
                if (1l * i * i <= n) {
                    for (int j = i * i; j <= n; j += i) {
                        isPrime[j] = false;
                    }
                }
            }
        }
    }




    public long id7(long a, long b, long mod) {
        if (b == 0) {
            return 1 % mod;
        }

        if (b % 2 != 0) {
            return ((a % mod) * (id7(a, b - 1, mod) % mod)) % mod;
        } else {
            long temp = id7(a, b / 2, mod) % mod;
            long ans = (temp * temp) % mod;
            return ans;

        }
    }

    public long binPow(long a, long b) {
        if (b == 0) {
            return 1;
        }

        if (b % 2 != 0) {
            return a * binPow(a, b - 1);
        } else {
            long temp = binPow(a, b / 2);
            long ans = (temp * temp);
            return ans;

        }
    }


    boolean vis[];

    HashMap<Integer, HashSet<Integer>> g;
    int[] id6;


    int p[];




    int find(int x) {
        if (x == p[x]) {
            return x;
        }

        return p[x] = find(p[x]);
    }

    boolean merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (p[x] == p[y]) {
            return false;
        }
        p[y] = x;
        return true;
    }

    class Trajectory {
        double x0;
        double y0;
        double vx;
        double vy;


        Trajectory(double vx, double vy, double x0, double y0) {
            this.vx = vx;
            this.vy = vy;

            this.x0 = x0;
            this.y0 = y0;
        }

        double y (double x) {
            return y0 + (x - x0) * (vy / vx) - 5 * (x - x0) * (x - x0) / (vx * vx);
        }

        double der(double x) {
            return (vy / vx) - 10 * (x - x0) / (vx * vx);
        }


    }

    int[][] parent;
    int[] dist;

    int[] h;
    int[] sz;
    HashMap<String, Integer> weight;
    void dfs(int u, int prev) {
        vis[u] = true;
        parent[0][u] = prev;

        h[u] = h[prev] + 1;
        sz[u] = 1;
        for (Integer v: g.get(u)) {
            if (!vis[v]) {
                dfs(v, u);
                sz[u] += sz[v];
            }
        }
    }
    int n;

    int LCA(int x, int y) {

        if (h[x] < h[y]) {
            int temp = x;
            x = y;
            y = temp;
        }

        int dh = h[x] - h[y];
        int highest = 0;
        for (int i = 0; (1 << i) <= n + 1; i++) {
            if ((dh & (1 << i)) != 0) {
                x = parent[i][x];
            }
            highest = i;
        }

        if (x == y) {
            return x;
        }
        for (int i = highest; i >= 0; i--) {
            if (parent[i][x] != parent[i][y]) {
                x = parent[i][x];
                y = parent[i][y];
            }
        }



        return parent[0][x];
    }




    public void solve() throws IOException {

        n = readInt();
        g = new HashMap<Integer, HashSet<Integer>>();
        for (int i = 1; i <= n; i++) {
            g.put(i, new HashSet<Integer>());
        }
        dist = new int[n + 1];

        sz = new int[n + 1];
        int root = 1;
        for (int i = 0; i < n - 1; i++) {
            int u = readInt();
            int v = readInt();

            g.get(u).add(v);
            g.get(v).add(u);



            

            

            



        }

        parent = new int[20][n + 1];
        vis = new boolean[n + 1];
        h = new int[n + 1];


        dfs(root, root);

        for (int lvl = 1; (1 << lvl) <= n + 1; lvl++) {
            for (int x = 0; x < n + 1; x++) {
                parent[lvl][x] = parent[lvl - 1][parent[lvl - 1][x]];
            }
        }


        int m = readInt();

        for (int i = 0; i < m; i++) {
            int u = readInt();
            int v = readInt();
            int lca = LCA(u, v);

            if (h[u] == h[v]) {
                

                

                int dist = h[u] + h[v] - 2 * h[lca] + 1;

                if (dist % 2 == 0) {
                    out.println(0);
                } else {

                    if (1 < 0) {

                    } else {
                        if (h[u] < h[v]) {
                            int temp = u;
                            u = v;
                            v = temp;
                        }
                        int dh = dist / 2;
                        int tempU = u;
                        for (int ind = 0; (1 << ind) <= n + 1; ind++) {
                            if ((dh & (1 << ind)) != 0) {
                                tempU = parent[ind][tempU];
                            }
                        }
                        int id4 = u;
                        dh = dist / 2 - 1;
                        for (int ind = 0; (1 << ind) <= n + 1; ind++) {
                            if ((dh & (1 << ind)) != 0) {
                                id4 = parent[ind][id4];
                            }
                        }

                        int ans = sz[root] - sz[id4];

                        id4 = v;
                        dh = dist / 2 - 1;
                        for (int ind = 0; (1 << ind) <= n + 1; ind++) {
                            if ((dh & (1 << ind)) != 0) {
                                id4 = parent[ind][id4];
                            }
                        }

                        ans -= sz[id4];
                        out.println(abs(ans));

                    }


                }
            } else {
                int dist = h[u] + h[v] - 2 * h[lca] + 1;

                if (dist % 2 == 0) {
                    out.println(0);
                } else {

                    if (1 < 0) {

                    } else {
                        if (h[u] < h[v]) {
                            int temp = u;
                            u = v;
                            v = temp;
                        }
                        int dh = dist / 2;
                        int tempU = u;
                        for (int ind = 0; (1 << ind) <= n + 1; ind++) {
                            if ((dh & (1 << ind)) != 0) {
                                tempU = parent[ind][tempU];
                            }
                        }
                        int id4 = u;
                        dh = dist / 2 - 1;
                        for (int ind = 0; (1 << ind) <= n + 1; ind++) {
                            if ((dh & (1 << ind)) != 0) {
                                id4 = parent[ind][id4];
                            }
                        }

                        int ans = sz[tempU] - sz[id4];
                        out.println(ans);


                    }


                }

            }

        }







    }



}
import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        new Solution().run();
    }
}



final class Solution implements Runnable {

    final static class Nim {
        public int index; 
        public long g;
        public int cnt;
        public int lineType;

        public Nim(int index, int cnt, long g, int lineType) {
            this.index = index;
            this.cnt = cnt;
            this.g = g;
            this.lineType = lineType;
        }

        public long getGrungy() {
            if (cnt % 2 == 0)
                return 0;
            else
                return g;
        }
    }

    final static class Event implements Comparable<Event> {
        public int pos;
        public int delta;

        public Event(int pos, int delta) {
            this.pos = pos;
            this.delta = delta;
        }

        @Override
        public int compareTo(Event o) {
            return pos - o.pos;
        }
    }

    double INF = 1e10;
    int OFFSET = 5000;


    final static class Point {

        final static Point UP = new Point(0, 1);
        final static Point DOWN = new Point(0, -1);
        final static Point RIGHT = new Point(1, 0);
        final static Point LEFT = new Point(-1, 0);

        public int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public Point add (Point o) {
            return new Point(x + o.x, y + o.y);
        }

        @Override
        public boolean equals(Object obj) {
            if (obj instanceof Point) {
                Point o = (Point)obj;
                return x == o.x && y == o.y;
            }
            else
                return false;
        }
    }

    class Query {
        public int left;
        public int index;

        public Query(int left, int index) {
            this.left = left;
            this.index = index;
        }
    }


    int solve() throws Throwable {

        int n = in.nextInt();
        int m = in.nextInt();

        boolean[] answers = new boolean[m];

        ArrayList<Query>[] queries = new ArrayList[n];
        for (int i = 0; i < queries.length; i++)
            queries[i] = new ArrayList<>();

        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = in.nextInt();



        for (int i = 0; i < m; i++) {
            int l = in.nextInt() - 1;
            int r = in.nextInt() - 1;
            queries[r].add(new Query(l, i));
        }

        int biggestLadderLen = 1;
        boolean afterPoint = false;
        for (int i = 0; i < queries[0].size(); i++) {
            answers[queries[0].get(i).index] = true;
        }
        int sameCount = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] >= a[i - 1] && !afterPoint) {
                biggestLadderLen++;
            }
            else if (a[i] <= a[i - 1] && afterPoint) {
                biggestLadderLen++;
            }
            else if (a[i] < a[i - 1] && !afterPoint) {
                afterPoint = true;
                biggestLadderLen++;
            }
            else if (a[i] > a[i - 1] && afterPoint) {
                biggestLadderLen = 2 + sameCount - 1;
                afterPoint = false;
            }
            for (int j = 0; j < queries[i].size(); j++) {
                Query cur = queries[i].get(j);
                if (cur.left > i - biggestLadderLen)
                    answers[cur.index] = true;
                else
                    answers[cur.index] = false;
            }
            if (a[i] == a[i - 1])
                sameCount++;
            else
                sameCount = 1;
        }

        for (int i = 0; i < m; i++) {
            out.println(answers[i] ? "Yes" : "No");
        }

        
        return 0;
    }


    FastScanner in;
    PrintWriter out;

    @Override
    public void run() {
        try {
            boolean ONLINE_JUDGE = false;
            try {
                Locale.setDefault(Locale.US);
                ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
            } catch (SecurityException e) {
                System.err.println("Operation forbidden");
            }


            long time = System.currentTimeMillis();
            if (ONLINE_JUDGE) {
                in = new FastScanner(new InputStreamReader(System.in));
                out = new PrintWriter(System.out);
            } else {
                in = new FastScanner(new FileReader("input.txt"));
                out = new PrintWriter("output.txt");
            }

            int ret = solve();
            out.close();
            in.close();

            long delta = System.currentTimeMillis() - time;

            long freeMem = Runtime.getRuntime().freeMemory();
            long totalMem = Runtime.getRuntime().totalMemory();

            System.err.printf("Time: %.3f s\n", delta / 1000.0f);
            System.err.printf("Memory: %.3f MB\n", (float)(totalMem - freeMem) / (1 << 20));

            if (ret != 0)
                System.exit(ret);

        } catch (Throwable t) {
            t.printStackTrace(System.err);
            System.exit(-1);
        }
    }
}

@SuppressWarnings("unused")
final class FastScanner {
    BufferedReader bufferedReader;
    StringTokenizer stringTokenizer;

    public FastScanner(Reader r) {
        bufferedReader = new BufferedReader(r);
    }

    public String nextToken() throws IOException, NullPointerException {
        while (stringTokenizer == null || !stringTokenizer.hasMoreTokens())
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        return stringTokenizer.nextToken();
    }

    public String nextLine() throws IOException {
        return bufferedReader.readLine();
    }

    public int nextInt() throws IOException, NullPointerException {
        return Integer.parseInt(nextToken());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public BigInteger nextBigInteger() throws IOException {
        return new BigInteger(nextToken());
    }

    public float nextFloat() throws IOException {
        return Float.parseFloat(nextToken());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    public int read() throws IOException {
        return bufferedReader.read();
    }

    public void close() throws IOException {
        bufferedReader.close();
    }

    public int[] readIntArray(int n) throws Throwable {
        int[] array = new int[n];
        for (int i = 0; i < n; i++)
            array[i] = nextInt();
        return array;
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        close();
    }
}

final class DisjointSetUnion {
    int[] parent;
    int[] rank;

    public DisjointSetUnion(int size) {
        parent = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; i++)
            parent[i] = i;
    }

    public int getLeader(int element) {
        if (parent[element] == element)
            return element;
        else
            return parent[element] = getLeader(parent[element]);
    }

    public boolean union(int x, int y) {
        x = getLeader(x);
        y = getLeader(y);
        if (x == y)
            return true;
        if (rank[x] < rank[y]) {
            int temp = x;
            x = y;
            y = temp;
        }
        parent[y] = x;
        if (rank[x] == rank[y])
            ++rank[x];
        return false;
    }
}




@SuppressWarnings("unused")
final class Utils {
    private Utils() {}

    final static int INF_I = Integer.MAX_VALUE;
    final static double INF_D = Double.POSITIVE_INFINITY;
    final static long INF_L = Long.MAX_VALUE;


    public static int[] solveAssignmentProblem(double[][] a) {
        int n = a.length - 1;
        int m = a[0].length - 1;
        double[] u = new double[n + 1], v = new double[m + 1], minv = new double[m + 1];
        boolean[] used = new boolean[m + 1];
        int[] p = new int[m + 1], prev = new int[m + 1];
        for (int i = 1; i <= n; i++) {
            Arrays.fill(used, false);
            Arrays.fill(minv, INF_D);
            int j0 = 0;
            p[j0] = i;
            do {
                int i0 = p[j0];
                used[j0] = true;
                double delta = INF_D;
                int j1 = 0;
                for (int j = 1; j <= m; j++) {
                    if (!used[j]) {
                        double cur = a[i0][j] + u[i0] + v[j];
                        if (cur < minv[j]) {
                            minv[j] = cur;
                            prev[j] = j0;
                        }
                        if (minv[j] < delta) {
                            delta = minv[j];
                            j1 = j;
                        }
                    }
                }
                for (int j = 0; j <= m; j++) {
                    if (used[j]) {
                        u[p[j]] -= delta;
                        v[j]  += delta;
                    } else
                        minv[j] -= delta;
                }
                j0 = j1;
            } while (p[j0] != 0);
            do {
                int j1 = prev[j0];
                p[j0] = p[j1];
                j0 = j1;
            } while (j0 != 0);

        }
        return p;
    }


    

    public static int[] hungarian(int[][] a) {
        int n = a.length - 1;
        int m = a[0].length - 1;
        int[] prev = new int[m + 1];
        int[] u = new int[n + 1];
        int[] v = new int[m + 1];
        boolean[] used = new boolean[m + 1];
        int[] p = new int[m + 1];
        int[] minv = new int[m + 1];
        for (int i = 1; i <= n; i++) {
            Arrays.fill(used, false);
            Arrays.fill(minv, INF_I);
            int j0 = 0;
            p[j0] = i;
            do {
                used[j0] = true;
                int i0 = p[j0];
                int delta = INF_I;
                int j1 = 0;
                for (int j = 1; j <= m; j++) {
                    if (!used[j]) {
                        int cur = a[i0][j] + u[i0] + v[j];
                        if (cur < minv[j]) {
                            minv[j] = cur;
                            prev[j] = j0;
                        }
                        if (minv[j] < delta) {
                            j1 = j;
                            delta = minv[j];
                        }
                    }
                }
                for (int j = 0; j <= m; j++) {
                    if (used[j]) {
                        u[p[j]] -= delta;
                        v[j] += delta;
                    } else
                        minv[j] -= delta;
                }
                j0 = j1;
            } while (p[j0] != 0);
            do {
                int j1 = prev[j0];
                p[j0] = p[j1];
                j0 = j1;
            } while (j0 != 0);
        }
        return p;
    }


    



    public static int[] hungarian(long[][] a) {
        int n = a.length - 1;
        int m = a[0].length - 1;
        int[] prev = new int[m + 1];
        long[] u = new long[n + 1];
        long[] v = new long[m + 1];
        boolean[] used = new boolean[m + 1];
        int[] p = new int[m + 1];
        long[] minv = new long[m + 1];
        for (int i = 1; i <= n; i++) {
            Arrays.fill(used, false);
            Arrays.fill(minv, INF_L);
            int j0 = 0;
            p[j0] = i;
            do {
                used[j0] = true;
                int i0 = p[j0];
                long delta = INF_L;
                int j1 = 0;
                for (int j = 1; j <= m; j++) {
                    if (!used[j]) {
                        long cur = a[i0][j] + u[i0] + v[j];
                        if (cur < minv[j]) {
                            minv[j] = cur;
                            prev[j] = j0;
                        }
                        if (minv[j] < delta) {
                            j1 = j;
                            delta = minv[j];
                        }
                    }
                }
                for (int j = 0; j <= m; j++) {
                    if (used[j]) {
                        u[p[j]] -= delta;
                        v[j] += delta;
                    } else
                        minv[j] -= delta;
                }
                j0 = j1;
            } while (p[j0] != 0);
            do {
                int j1 = prev[j0];
                p[j0] = p[j1];
                j0 = j1;
            } while (j0 != 0);
        }
        return p;
    }

    public static long sqr(long x) {
        return x * x;
    }

    public static int gcd(int x, int y) {
        while (y > 0) {
            x %= y;
            int temp = x;
            x = y;
            y = temp;
        }
        return x;
    }

    public static int lcm(int x, int y) {
        return x / gcd(x, y) * y;
    }

    public static long gcd(long x, long y) {
        while (y > 0) {
            x %= y;
            long temp = x;
            x = y;
            y = temp;
        }
        return x;
    }

    public static long lcm(long x, long y) {
        return x / gcd(x, y) * y;
    }

    public static long modInverse(long x, long mod) {
        return BigInteger.valueOf(x).modInverse(BigInteger.valueOf(mod)).longValue();
    }

    static Random r = new Random(System.nanoTime());

    public static<T> void shuffle(T[] array) {
        int n = array.length;
        for (int i = 0; i < n; i++) {
            int j = r.nextInt(n);
            T t = array[i];
            array[i] = array[j];
            array[j] = t;
        }
    }

    public static void shuffle(int[] array) {
        int n = array.length;
        for (int i = 0; i < n; i++) {
            int j = r.nextInt(n);
            int t = array[i];
            array[i] = array[j];
            array[j] = t;
        }
    }
}
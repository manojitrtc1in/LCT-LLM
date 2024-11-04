import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.*;

import static java.lang.Math.*;
import static java.lang.Math.min;

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

    private static void mergeSort(int[] a, int id7, int rightIndex) {
        final int id0 = 50;
        if (id7 < rightIndex) {
            if (rightIndex - id7 <= id0) {
                id1(a, id7, rightIndex);
            } else {
                int middleIndex = (id7 + rightIndex) / 2;
                mergeSort(a, id7, middleIndex);
                mergeSort(a, middleIndex + 1, rightIndex);
                merge(a, id7, middleIndex, rightIndex);
            }
        }
    }


    private static void merge(int[] a, int id7, int middleIndex,
                              int rightIndex) {
        int length1 = middleIndex - id7 + 1;
        int length2 = rightIndex - middleIndex;
        int[] id3 = new int[length1];
        int[] rightArray = new int[length2];
        System.arraycopy(a, id7, id3, 0, length1);
        System.arraycopy(a, middleIndex + 1, rightArray, 0, length2);
        for (int k = id7, i = 0, j = 0; k <= rightIndex; k++) {
            if (i == length1) {
                a[k] = rightArray[j++];
            } else if (j == length2) {
                a[k] = id3[i++];
            } else {
                if (id3[i] <= rightArray[j]) {
                    a[k] = id3[i++];
                } else {
                    a[k] = rightArray[j++];
                }
                

                

            }
        }
    }

    private static void id1(int[] a, int id7, int rightIndex) {
        for (int i = id7 + 1; i <= rightIndex; i++) {
            int current = a[i];
            int j = i - 1;
            while (j >= id7 && a[j] > current) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = current;
        }
    }

    public static void id8(int[] a, int l, int r) {
        while (l < r) {
            int m = (l + r) / 2;

            id8(a, l, m);
            id8(a, m + 1, r);

            myMerge(a, l, m, r);

        }
    }

    public static void myMerge(int[] a, int l, int m, int r) {
        int length1 = m - l + 1;
        int length2 = r - m;

        int[] leftArray = new int[length1];
        int[] rightArray = new int[length2];

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

        int index;


        public LOL(int x, int y, int index) {
            this.x = x;
            this.y = y;
            this.index = index;
        }

        public double phi() {
            return Math.atan2(y, x);
        }

        @Override
        public int compareTo(LOL o) {

            return -(Double.compare(o.phi(), this.phi())); 

            

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

    class LOL3 implements Comparable<LOL3> {

        double cost;
        double weight;

        public LOL3(double cost, double weight) {
            this.cost = cost;
            this.weight = weight;
        }

        public double getRatio() {
            return cost / weight;
        }


        public int compareTo(LOL3 o) {
            return Double.compare(o.getRatio(), this.getRatio());
        }

    }

    class LOL4 implements Comparable<LOL4> {

        int best;
        int almostBest;
        int index;
        public LOL4(int cost, int weight, int index) {
            this.best = cost;
            this.almostBest = weight;
            this.index = index;
        }

        public int compareTo(LOL4 o) {
            int compareResult = Integer.compare(best, o.best);

            if (compareResult == 0) {
                return Integer.compare(almostBest, o.almostBest);
            }


            return compareResult;
        }

    }

    class Node implements Comparable<Node> {

        String chars;
        Node leftChild;
        Node rightChild;
        int f;

        Node(String chars, Node leftChild, Node rightChild, int f) {
            this.chars = chars;
            this.leftChild = leftChild;
            this.rightChild = rightChild;
            this.f = f;
        }

        @Override
        public int compareTo(Node o) {
            return f - o.f;
        }
    }

    class Bracket {
        char bracket;
        int index;
        int close;
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
        double z;

        Point(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        double distance(Point temp) {
            return Math.sqrt((x - temp.x) * (x - temp.x) + (y - temp.y) * (y - temp.y));
        }

        double id9(Point temp) {
            return ((x - temp.x) * (x - temp.x) + (y - temp.y) * (y - temp.y));
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


    class Plane {
        double a;
        double b;
        double c;
        double d;

        Plane (Point fir, Point sec, Point thi) {
            double del1 = (sec.y - fir.y) * (thi.z - fir.z) - (thi.y - fir.y) * (sec.z - fir.z);
            double del2 = (thi.x - fir.x) * (sec.z - fir.z) - (thi.z - fir.z) * (sec.x - fir.x);
            double del3 = (thi.y - fir.y) * (sec.x - fir.x) - (thi.x - fir.x) * (sec.y - fir.y);
            a = del1;
            b = del2;
            c = del3;
            d = -fir.x * del1 - fir.y * del2 - fir.z * del3;
        }

        double distance(Point point) {
            return abs(a * point.x + b * point.y + c * point.z + d) / sqrt(a * a + b * b + c * c);
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

    public void id4 (int n) {
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




    public long id6(long a, long b, long mod) {
        if (b == 0) {
            return 1 % mod;
        }

        if (b % 2 != 0) {
            return ((a % mod) * (id6(a, b - 1, mod) % mod)) % mod;
        } else {
            long temp = id6(a, b / 2, mod) % mod;
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
    int[] id5;


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

        for (Integer v: g.get(u)) {
            if (!vis[v]) {
                dfs(v, u);

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

        int n = readInt();

        int m = readInt();

        int p = readInt();

        String sequence = readString();
        String controller = readString();

        ArrayDeque<Bracket> stack = new ArrayDeque<Bracket>();
        Bracket[] brackets = new Bracket[n];

        for (int i = 0; i < n; i++) {
            brackets[i] = new Bracket();
            brackets[i].index = i;
            brackets[i].bracket = sequence.charAt(i);

            if (brackets[i].bracket == '(') {
                stack.addFirst(brackets[i]);
            } else {
                Bracket enClosed = stack.poll();

                brackets[i].close = enClosed.index;
                brackets[enClosed.index].close = i;

            }
        }

        int [] left = new int[n];
        int [] right = new int[n];

        for (int i = 0; i < n; i++) {
            left[i] = i - 1;
        }

        for (int i = 0; i < n - 1; i++) {
            right[i] = i + 1;
        }

        right[n - 1] = -1;


        p -= 1;

        int[] lol = new int[n + 1];

        for (int z = 0; z < m; z++) {
            char operation = controller.charAt(z);

            if (operation == 'R') {
                p = right[p];
            } else if (operation == 'L') {
                p = left[p];
            } else {
                int temp = brackets[p].close;

                int minIndex = min(p, temp);
                int maxIndex = max(p, temp);

                lol[minIndex] += 1;

                if (minIndex == 29) {
                    int alert = 0;
                }

                if (lol[minIndex] == 2) {
                    int alert = 0;
                }

                lol[maxIndex + 1] -= 1;

                if (right[maxIndex] != -1) {
                    left[right[maxIndex]] = left[minIndex];
                } else {
                    

                }
                


                if (left[minIndex] != -1) {
                    right[left[minIndex]] = right[maxIndex];
                } else {
                   

                }

                if (right[maxIndex] == -1) {
                    p = left[minIndex];
                } else {
                    p = right[maxIndex];
                }

            }

        }
        int currSum = 0;
        for (int i = 0; i < n; i++) {
            currSum += lol[i];
            if (currSum == 0) {
                out.print(sequence.charAt(i));
            }
        }




    }



}
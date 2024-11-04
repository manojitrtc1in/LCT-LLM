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
                if (id3[i] <= rightArray[j]) {
                    a[k] = id3[i++];
                } else {
                    a[k] = rightArray[j++];
                }
                

                

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

    public static void id9(int[] a, int l, int r) {
        while (l < r) {
            int m = (l + r) / 2;

            id9(a, l, m);
            id9(a, m + 1, r);

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

        double id10(Point temp) {
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

        String s = readString();
        String t = readString();


        if (s.equals("01") || (s.equals("10"))) {
            out.print(0);
            return;
        }

        int[] id6 = new int[10];
        for (int i = 0; i < s.length(); i++) {
            Character currChar = new Character(s.charAt(i));


            id6[currChar - '0'] += 1;

        }
        int [] tempDigits = new int[10];

        int length = 0;

        for (int i = 0; i <= 1000 * 1000; i++) {
            tempDigits = new int[10];
            String curr = String.valueOf(i);

            for (int j = 0; j < curr.length(); j++) {
                Character currChar = curr.charAt(j);

                tempDigits[currChar - '0']++;

            }
            boolean flag = true;
            int sum = 0;
            for (int j = 0; j < 10; j++) {
                flag = true;
                if (tempDigits[j] > id6[j]) {
                    flag = false;
                    break;
                }
                sum += (id6[j] - tempDigits[j]);
            }

            if (flag) {
                if (sum == i) {
                    length = i;
                    break;
                }

            }

        }

        int firstIndex = 0;
        int [] firstS = new int[length];

        int secondIndex = 0;
        int [] secondS = new int[length];

        int thirdIndex = 0;
        int [] thirdS = new int[length];

        for (int i = 0; i < length; i++) {
            firstS[i] = 10;
            secondS[i] = 10;
            thirdS[i] = 10;
        }

        for (int i = 0; i < t.length(); i++) {
            Character currChar = new Character(t.charAt(i));
            id6[currChar - '0'] -= 1;

        }

        String len = String.valueOf(length);

        for (int i = 0; i < len.length(); i++) {
            Character currChar = new Character(len.charAt(i));

            id6[currChar - '0'] -= 1;
        }

        int startDigit = t.charAt(0) - '0';

     

        tempDigits = (id6).clone();
        if (!t.startsWith("0")) {
            for (int i = 0; i < t.length(); i++) {
                firstS[firstIndex++] = t.charAt(i) - '0';
            }
            for (int i = 0; i < 10; i++) {
                while (id6[i] > 0) {
                    id6[i]--;
                    firstS[firstIndex++] = i;
                }
            }
        }

    

        id6 = tempDigits.clone();
        boolean flag = false;

        for (int i = 1; i < 10; i++) {
            while (id6[i] > 0) {
                secondS[secondIndex++] = i;
                id6[i]--;
                if (!flag) {
                    flag = true;
                    while (id6[0] > 0) {
                        secondS[secondIndex++] = 0;
                        id6[0]--;
                    }
                    if (startDigit == 0) {
                        for (int z = 0; z < t.length(); z++) {
                            secondS[secondIndex++] = t.charAt(z) - '0';
                        }
                    }
                }
            }

            if (i == startDigit) {
                for (int z = 0; z < t.length(); z++) {
                    secondS[secondIndex++] = t.charAt(z) - '0';
                }
            }

        }

    



        id6 = tempDigits.clone();

        flag = false;

        for (int i = 1; i < 10; i++) {

            if (i == startDigit && flag) {
                for (int z = 0; z < t.length(); z++) {
                    thirdS[thirdIndex++] = t.charAt(z) - '0';
                }
              

            }

            while (id6[i] > 0) {
                thirdS[thirdIndex++] = i;
                id6[i]--;
                if (!flag) {
                    flag = true;
                    while (id6[0] > 0) {
                        thirdS[thirdIndex++] = 0;
                        id6[0]--;
                    }
                    if (startDigit == i) {
                        for (int z = 0; z < t.length(); z++) {
                            thirdS[thirdIndex++] = t.charAt(z) - '0';
                        }
                    }

                }
            }

        }


        boolean firstWinner = true;
        boolean secondWinner = !firstWinner;

        for (int i = 0; i < length; i++) {
            if (secondS[i] < firstS[i]) {

                firstWinner = false;
                secondWinner = true;
                break;
            } else if (secondS[i] > firstS[i]) {
                secondWinner = false;

                break;
            }
        }
        boolean thirdWinner = true;

        if (firstWinner) {
            for (int i = 0; i < length; i++) {
                if (firstS[i] < thirdS[i]) {
                    thirdWinner = false;
                    break;
                } else if (firstS[i] > thirdS[i]) {
                    secondWinner = false;
                    break;
                }
            }

        } else {
            for (int i = 0; i < length; i++) {
                if (secondS[i] < thirdS[i]) {
                    thirdWinner = false;
                    break;
                } else if (secondS[i] > thirdS[i]) {
                    secondWinner = false;
                    break;
                }
            }

        }

        int result [] = new int[length];

        if (firstWinner) {
            result = firstS;
        } else if (secondWinner) {
            result = secondS;
        } else {
            result = thirdS;
        }

        for (int i = 0; i < length; i++) {
            out.print(result[i]);
        }


        }



}
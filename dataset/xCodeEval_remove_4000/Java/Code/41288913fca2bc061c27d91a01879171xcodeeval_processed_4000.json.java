import java.io.*;
import java.math.BigInteger;
import java.util.*;





public class Solution {

    public static void main(String[] args) {
        IOHandler IO = new IOHandler();
        IO.init("std", "std", "input.txt", "output.txt");
        boolean id0 = false;

        Solver solver = new Solver();
        if (id0) {
            int testCase = IO.getInput().nextInt();
            for (int test = 0; test < testCase; test++) {
                solver.solve(IO.getInput(), IO.getOutput(), test + 1);
                IO.flush();
            }
        }
        else {
            int test = 1;
            try {
                while (true) {
                    solver.solve(IO.getInput(), IO.getOutput(), test++);
                    IO.flush();
                }
            } catch (UnknownError unknownError) {
                IO.close();
            }
        }

        IO.close();
    }
}

class Solver {

    
    double eps2 = 1e-20;

    public void solve (MyInput in, PrintWriter out, int testCase) {
        double eps1 = 1e-10;

        int a = in.nextInt();
        int b = in.nextInt();
        int c = in.nextInt();
        int d = in.nextInt();

        StopWatch stopWatch = new StopWatch();
        stopWatch.start();

        double start = 0;
        double end = 200000000000D;
        while (end - start > eps1) {
            if (stopWatch.id5() > 400) {
                break;
            }
            double mid = (start + end) / 2;
            double[] interval1 = getIntervals(a, d, mid);
            double[] interval2 = getIntervals(b, c, mid);

            if (haveOverlap(interval1, interval2) || haveOverlap(interval2, interval1)) {
                end = mid;
            }
            else {
                start = mid;
            }
        }

        out.printf("%.12f\n", (end + start) / 2);
    }

    boolean haveOverlap(double[] i1, double[] i2) {
        return (i1[1] > i2[0] || equal(i1[1], i2[0])) && (i1[0] < i2[0] || equal(i1[0], i2[0]));
    }

    boolean equal(double a, double b) {
        return Math.abs(a - b) < eps2;
    }

    double[] getIntervals(double a, double d, double t) {
        double[][] intervals = new double[][] {{a - t, a + t}, {d - t, d + t}};
        double[] ret = new double[] {1e20, -1e20};

        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                ret[0] = Math.min(ret[0], intervals[0][j] * intervals[1][k]);
                ret[1] = Math.max(ret[1], intervals[0][j] * intervals[1][k]);
            }
        }
        return ret;
    }
}

class StopWatch {
    long beginTime;

    public StopWatch() {
        beginTime = System.currentTimeMillis();
    }

    public void start() {
        beginTime = System.currentTimeMillis();
    }

    public long id5() {
        return System.currentTimeMillis() - beginTime;
    }

    public double id6() {
        return (double)id5() / 1000.;
    }

}


class IOHandler {
    private MyInput in;
    private PrintWriter out;

    
    public void init(String input_type, String output_type, String id3, String id12) {
        if (input_type.toLowerCase().equals("std")) {
            in = new MyInput(System.in);
        }
        else {
            

            try {
                in = new MyInput(new FileInputStream(id3));
            }
            catch (IOException e) {
                throw new UnknownError();
            }
        }
        if (output_type.toLowerCase().equals("std")) {
            out = new PrintWriter(System.out);
        }
        else {
            

            try {
                out = new PrintWriter(new FileOutputStream(id12));
            }
            catch (IOException e) {
                throw new UnknownError();
            }
        }
    }

    public MyInput getInput() {
        return in;
    }

    public PrintWriter getOutput() {
        return out;
    }

    public void flush() {
        out.flush();
    }

    public void close() {
        out.flush();
        out.close();
    }

}

class MyInput {
    private BufferedReader br;
    private StringTokenizer st;

    MyInput (InputStream inputStream) {
        br = new BufferedReader(new InputStreamReader(inputStream));
        st = null;
    }

    public String next() {
        if (st == null || !st.hasMoreElements()) {
            try {
                String line = br.readLine();
                if (line == null) {
                    throw new UnknownError();
                }
                while (line.trim().equals("")) {
                    line = br.readLine();
                    if (line == null) {
                        throw new UnknownError();
                    }
                }
                st = new StringTokenizer(line);
            } catch (IOException e) {
                throw new UnknownError();
            }
        }
        return st.nextToken();
    }

    public String nextLine() {
        try {
            String line = br.readLine();
            if (line == null) {
                throw new UnknownError();
            }
            return line;
        }
        catch (IOException e) {
            throw new UnknownError();
        }
    }

    public void id4() {
        try {
            br.readLine();
        }
        catch (IOException e) {
            throw new UnknownError();
        }
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public BigInteger id1() {
        return new BigInteger(next());
    }

    public boolean hasNext() {
        try {
            return st != null && st.hasMoreElements() || br.ready();
        } catch (IOException e) {
            throw new UnknownError();
        }
    }
}


class MyMath {

    
    public static int[] sieve(int n){
        int[] pr = new int[n + 1];
        Arrays.fill(pr, 1);
        ArrayList <Integer> prime = new ArrayList<Integer>();
        pr[0] = pr[1] = 0;
        for(int i = 2; i <= n; i++) {
            if(pr[i] == 1) {
                prime.add(i);
                if((long)i * i <= n)
                    for(long j = (long)i * i; j <= n; j += i)
                        pr[(int)j] = 0;
            }
        }
        int [] ret = new int[prime.size()];
        for (int i = 0; i < ret.length; i++) {
            ret[i] = prime.get(i);
        }
        return ret;
    }

    
    public static int GCD(int a, int b){return b!=0 ? GCD(b, a % b) : a;}

    
    public static int fastPow(int a, int b, int m){
        int ans = 1;
        while(b != 0){
            if((b & 1) == 1)
                ans = mul(ans, a, m);
            a = mul(a, a, m);
            b >>= 1;
        }
        return ans%m;
    }

    public static void id2(int[][] pas, int MOD) {
        int n = pas.length;
        for (int i = 0; i < n; i++) {
            pas[i][0] = 0;
        }
        for (int i = 0; i < n; i++) {
            pas[0][i] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                pas[i][j] = (pas[i][j-1] + pas[i-1][j-1]) % MOD;
            }
        }
    }

    

    

    public static long id10 (long a, long b, long[] x, long[] y) {
        if (a == 0) {
            x[0] = 0; y[0] = 1;
            return b;
        }
        long[] x1 = new long[1];
        long[] y1 = new long[1];

        long d = id10(b % a, a, x1, y1);
        x[0] = y1[0] - (b / a) * x1[0];
        y[0] = x1[0];
        return d;
    }

    

    

    public static long invMod(long a, long m){
        long[] x = new long[1];
        long[] q = new long[1];
        if(id10(a, m, x, q) == 1){
            x[0] = x[0] % m;
            if (x[0] < m) {
                x[0] = (x[0] + m) % m;
            }
            return x[0];
        }
        return -1;
    }

    
    public static ArrayList<int[]> getFactors(int n, int[] primes) {
        ArrayList <int[]> factors = new ArrayList<int[]>();
        for (int prime: primes) {
            if (n % prime == 0) {
                int cnt = 0;
                while (n % prime == 0) {
                    n /= prime;
                    cnt++;
                }
                factors.add(new int[] {prime, cnt});
            }
        }
        if (n != 1) {
            factors.add(new int[] {n, 1});
        }
        return factors;
    }

    public static int add(int a, int b, int MOD) {
        return ((a + b) % MOD + MOD) % MOD;
    }

    public static int mul(int a, int b, int MOD) {
        return ((int)(((long) a * b) % MOD) + MOD) % MOD;
    }

}

class Pair <P extends Comparable <? super P>, Q extends Comparable <? super Q> >
        implements Comparable <Pair <P, Q> > {
    P a;
    Q b;
    public Pair (P a, Q b) {
        this.a = a;
        this.b = b;
    }

    public Pair() {
    }

    public void setX(P a) {
        this.a = a;
    }

    public void setY(Q b) {
        this.b = b;
    }

    public P getX() {
        return a;
    }

    public Q getY() {
        return b;
    }

    public String toString() {
        return "(" + a.toString() + ", " + b.toString() + ")";
    }

    @Override
    public int compareTo(Pair<P, Q> o) {
        int cmp = a.compareTo(o.a);
        if (cmp == 0) {
            return b.compareTo(o.b);
        }
        return cmp;
    }
}

class id11 {
    private int[] tree;
    private int maxVal;

    public id11(int n) {
        maxVal = n;
        tree = new int[maxVal + 1];
    }

    
    public void update(int idx, int val) {
        idx++;
        while (idx <= maxVal) {
            tree[idx] += val;
            idx += (idx & (-idx));
        }
    }

    
    public int read(int idx) {
        idx++;
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }

    public int id8() {
        return maxVal;
    }

    public int rangeSum(int left, int right) {
        if(left > right)
            return 0;
        int sumLeft = read(left - 1);
        int sumRight = read(right);
        return sumRight - sumLeft;
    }
}

class PairInt implements Comparable <PairInt> {
    public int X, Y;

    public PairInt(int X, int Y){
        this.X = X;
        this.Y = Y;
    }

    public PairInt add(PairInt b) {
        return new PairInt(X + b.X, Y + b.Y);
    }

    public PairInt sub(PairInt b) {
        return new PairInt(X - b.X, Y - b.Y);
    }

    @Override
    public int compareTo(PairInt o) {
        if(X != o.X)
            return X - o.X;
        return Y - o.Y;
    }
}

class IntArrays {

    public static void reverse(int[] cur){
        int[] temp = new int[cur.length];
        int cnt = 0;
        for(int i=cur.length-1; i>=0; i--){
            temp[cnt++] = cur[i];
        }
        for(int i=0;i<cnt; i++)
            cur[i] = temp[i];
    }

    public static void swap(int[] arr, int a, int b){
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
























    private static Integer[] selfOrder(int n) {
        Integer[] self = new Integer[n];
        for (int i = 0; i < n; i++) {
            self[i] = i;
        }
        return self;
    }

    private static int[] id7(Integer[] box) {
        int[] primitive = new int[box.length];
        for (int i = 0; i < box.length; i++) {
            primitive[i] = box[i];
        }
        return primitive;
    }

    public static int[] getOrder(final int[] arr) {
        Integer[] order = selfOrder(arr.length);
        Arrays.sort(order, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                if(arr[o1] > arr[o2])
                    return 1;
                if(arr[o1] < arr[o2])
                    return -1;
                return 0;
            }
        });
        return id7(order);
    }

    public static boolean id9(int[] c){
        

        int first = getFirst( c );
        if ( first == -1 ) return false; 

        

        int toSwap = c.length - 1;
        while ( c[ first ] >= c[ toSwap ] )
            --toSwap;
        

        swap( c, first++, toSwap );
        

        toSwap = c.length - 1;
        while ( first < toSwap )
            swap( c, first++, toSwap-- );
        return true;
    }

    

    

    private static int getFirst( final int[] c ) {
        for ( int i = c.length - 2; i >= 0; --i )
            if ( c[ i ] <  c[ i + 1 ] )
                return i;
        return -1;
    }

    
    public static int lowerBound(int[] order, int[] val, int need) {
        int s = 0;
        int e = order.length;
        while(e - s > 1) {
            int mid = (e + s) / 2;
            if(val[order[mid]] < need)
                s = mid;
            else
                e = mid;
        }
        if(val[order[s]] >= need)
            return s;
        return e;
    }

    public static int lowerBound(int[] val, int need) {
        int s = 0;
        int e = val.length;
        while(e - s > 1) {
            int mid = (e + s) / 2;
            if(val[mid] < need)
                s = mid;
            else
                e = mid;
        }
        if(val[s] >= need)
            return s;
        return e;
    }


}
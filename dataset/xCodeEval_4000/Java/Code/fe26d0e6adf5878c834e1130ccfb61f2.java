import java.util.*;
import java.io.*;
import java.math.*;

public class Main implements Runnable {

    final static int mod = 1000000007;
    static FastReader sc;
    static PrintWriter out;
    static boolean test_case_input = true;
    static final int MAX = 1000000001;
    static final int MIN = -1000000001;

    public static int func(int n) {
        return (n * (n  + 1)) / 2;
    }

    public static void solution(int test_case) throws IOException {
        

        String s = sc.nextLine();
        char a[] = s.toCharArray();
        int n = s.length();
        for(int i = 0; i < n; i+=2) {
            if(a[i] == '1') a[i] = '0';
            else if(a[i] == '0') a[i] = '1';
        }

        int r = -1, l = 0;
        int count[] = new int[2];
        long ans = 0;
        while(r + 1 < n) {
            r++;
            if(a[r] == '1') count[1]++;
            if(a[r] == '0') count[0]++;
            if(count[0] > 0 && count[1] > 0) {
                while(count[0] != 0 && count[1] != 0) {
                    if(a[l] == '1') count[1]--;
                    if(a[l] == '0') count[0]--;
                    l++;
                }
            }
            ans += r - l + 1;
        }
        out.println(ans);
    }

    

    public static int logint(int x, int base) {
        return (int) (Math.log(x) / Math.log(base));
    }

    public static int logint(long x, long base) {
        return (int) (Math.log(x) / Math.log(base));
    }

    public static int logint(double x, double base) {
        return (int) (Math.log(x) / Math.log(base));
    }

    public static double logdouble(int x, int base) {
        return (Math.log(x) / Math.log(base));
    }

    public static double logdouble(long x, long base) {
        return (Math.log(x) / Math.log(base));
    }

    public static double logdouble(double x, double base) {
        return (Math.log(x) / Math.log(base));
    }

    public static long loglong(int x, int base) {
        return (long) (Math.log(x) / Math.log(base));
    }

    public static long loglong(long x, long base) {
        return (long) (Math.log(x) / Math.log(base));
    }

    public static long loglong(double x, double base) {
        return (long) (Math.log(x) / Math.log(base));
    }

    

    public static void debug(String msg, Object value) {
        File output = new File("output.txt");
        if (!output.exists()) return;
        String type = value.getClass().getSimpleName();
        if (type.equals("int[]")) out.println(msg + " => " + Arrays.toString((int[]) value));
        else if (type.equals("double[]")) out.println(msg + " => " + Arrays.toString((double[]) value));
        else if (type.equals("float[]")) out.println(msg + " => " + Arrays.toString((float[]) value));
        else if (type.equals("long[]")) out.println(msg + " => " + Arrays.toString((long[]) value));
        else if (type.equals("char[]")) out.println(msg + " => " + Arrays.toString((char[]) value));
        else if (type.equals("String[]")) out.println(msg + " => " + Arrays.toString((String[]) value));
        else if (type.equals("int[][]")) {
            out.println(msg + "=>");
            for (int i[] : (int[][]) value)
                out.println(" . " + Arrays.toString(i).replace(' ', '\t'));
        } else if (type.equals("double[][]")) {
            out.println(msg + "=>");
            for (double i[] : (double[][]) value)
                out.println(" . " + Arrays.toString(i).replace(' ', '\t'));
        } else if (type.equals("float[][]")) {
            out.println(msg + "=>");
            for (float i[] : (float[][]) value)
                out.println(" . " + Arrays.toString(i).replace(' ', '\t'));
        } else if (type.equals("long[][]")) {
            out.println(msg + "=>");
            for (long i[] : (long[][]) value)
                out.println(" . " + Arrays.toString(i).replace(' ', '\t'));
        } else if (type.equals("char[][]")) {
            out.println(msg + "=>");
            for (char i[] : (char[][]) value)
                out.println(" . " + Arrays.toString(i).replace(' ', '\t'));
        } else if (type.equals("String[][]")) {
            out.println(msg + "=>");
            for (String i[] : (String[][]) value)
                out.println(" . " + Arrays.toString(i).replace(' ', '\t'));
        } else out.println(msg + " => " + value);
    }

    public static void debug(Object value) {
        File output = new File("output.txt");
        if (!output.exists()) return;
        String type = value.getClass().getSimpleName();
        if (type.equals("int[]")) out.println(" => " + Arrays.toString((int[]) value));
        else if (type.equals("double[]")) out.println(" => " + Arrays.toString((double[]) value));
        else if (type.equals("float[]")) out.println(" => " + Arrays.toString((float[]) value));
        else if (type.equals("long[]")) out.println(" => " + Arrays.toString((long[]) value));
        else if (type.equals("char[]")) out.println(" => " + Arrays.toString((char[]) value));
        else if (type.equals("String[]")) out.println(" => " + Arrays.toString((String[]) value));
        else if (type.equals("int[][]")) {
            out.println("=>");
            for (int i[] : (int[][]) value)
                out.println(" . " + Arrays.toString(i).replace(' ', '\t'));
        } else if (type.equals("double[][]")) {
            out.println("=>");
            for (double i[] : (double[][]) value)
                out.println(" . " + Arrays.toString(i).replace(' ', '\t'));
        } else if (type.equals("float[][]")) {
            out.println("=>");
            for (float i[] : (float[][]) value)
                out.println(" . " + Arrays.toString(i).replace(' ', '\t'));
        } else if (type.equals("long[][]")) {
            out.println("=>");
            for (long i[] : (long[][]) value)
                out.println(" . " + Arrays.toString(i).replace(' ', '\t'));
        } else if (type.equals("char[][]")) {
            out.println("=>");
            for (char i[] : (char[][]) value)
                out.println(" . " + Arrays.toString(i).replace(' ', '\t'));
        } else if (type.equals("String[][]")) {
            out.println("=>");
            for (String i[] : (String[][]) value)
                out.println(" . " + Arrays.toString(i).replace(' ', '\t'));
        } else out.println(" => " + value);
    }

    

    public static void addUndirectedEdge(ArrayList<ArrayList<Integer>> adj, int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    public static void addDirectedEdge(ArrayList<ArrayList<Integer>> adj, int u, int v) {
        adj.get(u).add(v);
    }

    public static <T> void addUndirectedEdge(ArrayList<ArrayList<Point>> adj, int u, int v, T weight) {
        adj.get(u).add(new Point(v, weight));
        adj.get(v).add(new Point(u, weight));
    }

    public static <T> void addDirectedEdge(ArrayList<ArrayList<Point>> adj, int u, int v, T weight) {
        adj.get(u).add(new Point(v, weight));
    }

    public static <T> void toString(String msg, ArrayList<ArrayList<T>> adj) {
        out.println(msg + ":");
        int count = 0;
        for (ArrayList<T> i : adj) {
            out.print("\t" + count++ + ": ");
            for (T j : i) {
                out.print(j + " ");
            }
            out.println();
        }
    }

    public static void addUndirectedEdge(Map<Integer, ArrayList<Integer>> adj, int u, int v) {
        if (adj.containsKey(u)) {
            ArrayList<Integer> temp = adj.get(u);
            temp.add(v);
            adj.put(u, temp);
        } else {
            ArrayList<Integer> temp = new ArrayList<>();
            temp.add(v);
            adj.put(u, temp);
        }
        if (adj.containsKey(v)) {
            ArrayList<Integer> temp = adj.get(v);
            temp.add(u);
            adj.put(v, temp);
        } else {
            ArrayList<Integer> temp = new ArrayList<>();
            temp.add(u);
            adj.put(v, temp);
        }
    }

    public static void addDirectedEdge(Map<Integer, ArrayList<Integer>> adj, int u, int v) {
        if (adj.containsKey(u)) {
            ArrayList<Integer> temp = adj.get(u);
            temp.add(v);
            adj.put(u, temp);
        } else {
            ArrayList<Integer> temp = new ArrayList<>();
            temp.add(v);
            adj.put(u, temp);
        }
    }

    public static <T> void addUndirectedEdge(Map<Integer, ArrayList<Point>> adj, int u, int v, T weight) {
        if (adj.containsKey(u)) {
            ArrayList<Point> temp = adj.get(u);
            temp.add(new Point(v, weight));
            adj.put(u, temp);
        } else {
            ArrayList<Point> temp = new ArrayList<>();
            temp.add(new Point(v, weight));
            adj.put(u, temp);
        }
        if (adj.containsKey(v)) {
            ArrayList<Point> temp = adj.get(v);
            temp.add(new Point(u, weight));
            adj.put(v, temp);
        } else {
            ArrayList<Point> temp = new ArrayList<>();
            temp.add(new Point(u, weight));
            adj.put(v, temp);
        }
    }

    public static <T> void addDirectedEdge(Map<Integer, ArrayList<Point>> adj, int u, int v, T weight) {
        if (adj.containsKey(u)) {
            ArrayList<Point> temp = adj.get(u);
            temp.add(new Point(v, weight));
            adj.put(u, temp);
        } else {
            ArrayList<Point> temp = new ArrayList<>();
            temp.add(new Point(v, weight));
            adj.put(u, temp);
        }
    }

    public static <T> void toString(String msg, Map<T, ArrayList<T>> adj) {
        out.println(msg + ":");
        for (Map.Entry<T, ArrayList<T>> entry : adj.entrySet()) {
            out.println("\t" + entry.getKey() + ": " + entry.getValue());
        }
    }

    

    public static int __gcd(int a, int b) {
        BigInteger n1 = BigInteger.valueOf(a);
        BigInteger n2 = BigInteger.valueOf(b);
        BigInteger gcd = n1.gcd(n2);
        return gcd.intValue();
    }

    public static long __gcd(long a, long b) {
        BigInteger n1 = BigInteger.valueOf(a);
        BigInteger n2 = BigInteger.valueOf(b);
        BigInteger gcd = n1.gcd(n2);
        return gcd.longValue();
    }

    public static void main(String args[]) throws IOException {
        new Thread(null, new Main(), "random", 1 << 26).start();
    }

    @Override
    public void run() {
        long start = 0, end = 0;
        try {
            File output = new File("output.txt");
            sc = new FastReader();
            if (output.exists()) {
                out = new PrintWriter(new FileOutputStream("output.txt"));
                start = System.nanoTime();
            } else {
                out = new PrintWriter(System.out);
            }

            int test_cases = 1;
            if (test_case_input) test_cases = sc.nextInt();
            for (int i = 1; i <= test_cases; i++) {
                solution(i);
            }
            if (output.exists()) {
                end = System.nanoTime();
                out.println("Execution time: " + (end - start) / 1000000 + " ms");
            }
            out.flush();
            out.close();
        } catch (Exception e) {
            out.println("Exception: " + e);
            out.println("At Line no. : " + e.getStackTrace()[0].getLineNumber());
            out.flush();
            out.close();
            return;
        }
    }

    

    static class Edge implements Comparable<Edge> {
        Object u;
        Object v;
        Object wt;

        public Edge(Object origin, Object destination, Object weight) {
            u = origin;
            v = destination;
            wt = weight;
        }

        public String toString() {
            String ans = u + " -> " + v + " : " + wt;
            return ans;
        }

        public int getIntOrigin() {
            return (int) u;
        }

        public int getIntDestination() {
            return (int) v;
        }

        public int getIntWeight() {
            return (int) wt;
        }

        public long getLongOrigin() {
            return (long) u;
        }

        public long getLongDestination() {
            return (long) v;
        }

        public long getLongWeight() {
            return (long) wt;
        }

        @Override
        public int compareTo(Edge edge) {
            if ((edge.u).getClass() == Long.class) return (((Long) this.wt).compareTo((Long) edge.wt));
            else return (((Integer) this.wt).compareTo((Integer) edge.wt));
        }
    }

    

    static class Point implements Comparable<Point> {
        Object x;
        Object y;

        public Point(Object a, Object b) {
            x = a;
            y = b;
        }

        public int getIntX() {
            return (int) x;
        }

        public int getIntY() {
            return (int) y;
        }

        public long getLongX() {
            return (long) x;
        }

        public long getLongY() {
            return (long) y;
        }

        public int compareTo(Point obj) {
            if (obj.x.equals(this.x)) {
                if ((obj.y).getClass() == Long.class) return ((Long) this.y).compareTo((Long) obj.y);
                else return ((Integer) this.y).compareTo((Integer) obj.y);
            } else {
                if ((obj.x).getClass() == Long.class) return ((Long) this.x).compareTo((Long) obj.x);
                else return ((Integer) this.x).compareTo((Integer) obj.x);
            }
        }

        public String toString() {
            String ans = "(" + x + ", " + y + ")";
            return ans;
        }

        @Override
        public int hashCode() {
            int hash = 7;
            hash = 71 * hash + (int) this.x;
            hash = 71 * hash + (int) this.y;
            return hash;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj == null) return false;
            Point point = (Point) obj;
            if (point.x.equals(this.x) && point.y.equals(this.y)) return true;
            else return false;
        }
    }

    

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() throws FileNotFoundException {
            File in = new File("input.txt");
            if (in.exists()) {
                br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")));
            } else {
                br = new BufferedReader(new InputStreamReader(System.in));
            }
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

        float nextFloat() {
            return Float.parseFloat(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        Integer[] intarr(int n) {
            Integer a[] = new Integer[n];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(next());
            }
            return a;
        }

        Long[] longarr(int n) {
            Long a[] = new Long[n];
            for (int i = 0; i < n; i++) {
                a[i] = Long.parseLong(next());
            }
            return a;
        }

        float[] floatarr(int n) {
            float a[] = new float[n];
            for (int i = 0; i < n; i++) {
                a[i] = Float.parseFloat(next());
            }
            return a;
        }

        Double[] doublearr(int n) {
            Double a[] = new Double[n];
            for (int i = 0; i < n; i++) {
                a[i] = Double.parseDouble(next());
            }
            return a;
        }


        Integer[][] intmatrix(int row, int col) {
            Integer a[][] = new Integer[row][col];
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    a[i][j] = Integer.parseInt(next());
                }
            }
            return a;
        }

        Long[][] longmatrix(int row, int col) {
            Long a[][] = new Long[row][col];
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    a[i][j] = Long.parseLong(next());
                }
            }
            return a;
        }

        Float[][] floatmatrix(int row, int col) {
            Float a[][] = new Float[row][col];
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    a[i][j] = Float.parseFloat(next());
                }
            }
            return a;
        }

        Double[][] doublematrix(int row, int col) {
            Double a[][] = new Double[row][col];
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    a[i][j] = Double.parseDouble(next());
                }
            }
            return a;
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
}
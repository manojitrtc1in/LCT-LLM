import java.util.*;
import java.io.*;

class Main {
    static final int jt = 998244353;
    static final int Inf = 0x3f3f3f3f;
    static final long INF = 0x3f3f3f3f3f3f3f3fL;
    static final double pi = Math.acos(-1);
    static final double eps = 1e-10;
    
    static class FastIO {
        BufferedReader br;
        StringTokenizer st;
        
        public FastIO() {
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
    
    static class Point {
        double x, y;
        double ang;
        
        public Point() {
        }
        
        public Point(double x, double y) {
            this.x = x;
            this.y = y;
            this.ang = Math.atan2(y, x);
        }
        
        public Point add(Point pt) {
            return new Point(x + pt.x, y + pt.y);
        }
        
        public Point subtract(Point pt) {
            return new Point(x - pt.x, y - pt.y);
        }
        
        public Point multiply(double a) {
            return new Point(x * a, y * a);
        }
        
        public Point divide(double a) {
            return new Point(x / a, y / a);
        }
        
        public double dotProduct(Point pt) {
            return x * pt.x + y * pt.y;
        }
        
        public double crossProduct(Point pt) {
            return x * pt.y - y * pt.x;
        }
        
        public double length() {
            return x * x + y * y;
        }
        
        public double angle(Point pt) {
            return Math.acos(dotProduct(pt) / (length() * pt.length()));
        }
        
        public double getAngle() {
            return ang = Math.atan2(y, x);
        }
        
        public boolean lessThan(Point p) {
            return Math.abs(x - p.x) < 1e-10 ? y < p.y : x < p.x;
        }
    }
    
    static class Line {
        Point a, b;
        
        public Line() {
        }
        
        public Line(Point a, Point b) {
            this.a = a;
            this.b = b;
        }
    }
    
    static class BIT<T> {
        T[] dt;
        
        public BIT(int len) {
            dt = (T[]) new Object[len];
        }
        
        public void add(int a, T x) {
            while (a < dt.length) {
                dt[a] += x;
                a += a & -a;
            }
        }
        
        public void add(int l, int r, T x) {
            add(l, x);
            add(r + 1, -x);
        }
        
        public T get(int a) {
            T ans = 0;
            while (a > 0) {
                ans += dt[a];
                a -= a & -a;
            }
            return ans;
        }
        
        public T get(int l, int r) {
            return get(r) - get(l - 1);
        }
    }
    
    static class SegBIT<T> {
        T[][] dt;
        
        public SegBIT(int len) {
            dt = (T[][]) new Object[2][len];
        }
        
        public void add(int a, T x) {
            int b = a;
            while (a < dt[0].length) {
                dt[0][a] += x;
                dt[1][a] += x * b;
                a += a & -a;
            }
        }
        
        public void add(int l, int r, T x) {
            add(l, x);
            add(r + 1, -x);
        }
        
        public T sum(int a) {
            T ans = 0;
            int b = a;
            while (a > 0) {
                ans += (b + 1) * dt[0][a] - dt[1][a];
                a -= a & -a;
            }
            return ans;
        }
        
        public T sum(int l, int r) {
            return sum(r) - sum(l - 1);
        }
    }
    
    static class Matrix {
        int[][] mat;
        
        public Matrix(int R, int C) {
            mat = new int[R][C];
        }
        
        public Matrix(int x) {
            mat = new int[x][x];
            for (int i = 0; i < x; i++) {
                mat[i][i] = x;
            }
        }
        
        public Matrix add(Matrix m) {
            Matrix ans = new Matrix(mat.length, mat[0].length);
            for (int i = 0; i < mat.length; i++) {
                for (int j = 0; j < mat[0].length; j++) {
                    ans.mat[i][j] = (mat[i][j] + m.mat[i][j]) % jt;
                }
            }
            return ans;
        }
        
        public Matrix multiply(Matrix m) {
            Matrix ans = new Matrix(mat.length, m.mat[0].length);
            for (int i = 0; i < mat.length; i++) {
                for (int j = 0; j < m.mat[0].length; j++) {
                    for (int k = 0; k < mat[0].length; k++) {
                        ans.mat[i][j] = (ans.mat[i][j] + ((long) mat[i][k]) * m.mat[k][j]) % jt;
                    }
                }
            }
            return ans;
        }
        
        public void debug() {
            for (int i = 0; i < mat.length; i++) {
                for (int j = 0; j < mat[0].length; j++) {
                    System.err.print(mat[i][j] + " ");
                }
                System.err.println();
            }
            System.err.println();
        }
    }
    
    static int n, m;
    static char[][] s;
    static int[] val;
    static long[] dy;
    static double[] dp;
    
    public static void main(String[] args) {
        FastIO fio = new FastIO();
        n = fio.nextInt();
        s = new char[n][];
        for (int i = 0; i < n; i++) {
            s[i] = fio.next().toCharArray();
        }
        m = s[0].length;
        val = new int[n];
        dy = new long[1 << m];
        dp = new double[1 << m];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int num = 0;
                for (int k = 0; k < m; k++) {
                    num |= (s[i][k] == s[j][k] ? 1 : 0) << k;
                }
                dy[num] |= (1 << i) | (1 << j);
            }
        }
        for (int i = 0; i < (1 << m); i++) {
            for (int j = i; j > 0; j -= j & -j) {
                int lst = j & -j;
                dy[i ^ lst] |= dy[i];
            }
        }
        dp[0] = 1;
        double ans = 0;
        for (int i = 0; i < (1 << m); i++) {
            double v = dp[i] / (m - Integer.bitCount(i));
            for (int j = (1 << m) - 1 ^ i; j > 0; j -= j & -j) {
                dp[i | (j & -j)] += v;
            }
            ans += dp[i] * Long.bitCount(dy[i]);
        }
        System.out.println(ans / n);
    }
}

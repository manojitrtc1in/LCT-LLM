import java.io.*;
import java.lang.reflect.Array;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.text.NumberFormat;
import java.util.*;

public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "";

    class Info implements Comparable {
        int x;
        int y;
        int z;
        int go = 0;

        public Info(int x, int y, int z, int go) {
            this.x = x;
            this.y = y;
            this.z = z;
            this.go = go;
        }

        public int hashCode() {
            return (int) (x * 37 + 11 * y + z);
        }

        public boolean equals(Object o) {
            Info pr = (Info) o;

            return x == pr.x && y == pr.y && z == pr.z;
        }

        @Override
        public int compareTo(Object o) {
            Info pr = (Info) o;
            return x == pr.x ? Double.compare(y, pr.y) : Double.compare(x, pr.x);
        }

        public int dis(Info o) {
            return (o.x - x) * (o.x - x) + (o.y - y) * (o.y - y) + (o.z - z) * (o.z - z);
        }
    }

    class Tuple implements Comparable {
        int x;
        int y;
        double z;

        public Tuple(int x, int y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public int hashCode() {
            return (int) (x * 37 + 11 * y + z);
        }

        public boolean equals(Object o) {
            Tuple pr = (Tuple) o;
            return x == pr.x && y == pr.y && z == pr.z;
        }

        @Override
        public int compareTo(Object o) {
            Tuple pr = (Tuple) o;
            return x == pr.x ? (y == pr.y ? Double.compare(z, pr.z) : Integer.compare(y, pr.y)) : Integer.compare(x, pr.x);
        }


    }


    class Pair implements Comparable {
        double x;
        int y;

        public Pair(double x, int y) {
            this.x = x;
            this.y = y;
        }

        public int hashCode() {
            return (int) (x * 37 + y);
        }

        public boolean equals(Object o) {
            Pair pr = (Pair) o;

            return x == pr.x && y == pr.y;
        }

        @Override
        public int compareTo(Object o) {
            Pair pr = (Pair) o;
            return Double.compare(x, pr.x);
        }
    }


    class Edge {
        int x;
        int y;
        int score1;
        int score2;

        public Edge(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    int rk = 0;

    void dfs(int c, int b, Edge[] es, int n) {
        if (c == b) {
            int val[][] = new int[n][2];
            for (int i = 0; i < n; ++i) {
                val[i][1] = i;
            }


            int win[] = new int[n];
            for (int j = 0; j < b; ++j) {
                int x = es[j].x;
                int y = es[j].y;
                if (es[j].score1 == 1) {
                    val[x][0] += 1;
                    val[y][0] += 1;
                } else if (es[j].score1 == 3) {
                    val[x][0] += 3;
                    win[x]++;
                } else if (es[j].score1 == -3) {
                    val[y][0] += 3;
                    win[y]++;
                }
                if (es[j].score2 == 1) {
                    val[x][0] += 1;
                    val[y][0] += 1;
                } else if (es[j].score2 == 3) {
                    val[x][0] += 3;
                    win[x]++;
                } else if (es[j].score2 == -3) {
                    val[y][0] += 3;
                    win[y]++;
                }
            }

            for (int i = 1; i < n; ++i) {
                if (win[i] >= win[0]) return;
            }

            Arrays.sort(val, (x, y) -> {
                return y[0] - x[0];
            });

            for (int i = 0; i < n; ++i) {
                if (val[i][1] == 0) {
                    rk = Math.max(rk, i + 1);
                    break;
                }
            }
            return;
        }
        int v[] = {3, -3, 1};
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                es[c].score1 = v[i];
                es[c].score2 = v[j];
                dfs(c + 1, b, es, n);
            }
        }


    }


    void id0() {
        String sp = ns();
        long x = Long.parseLong(sp.split("\\+")[0]);
        long y = Long.parseLong(sp.split("\\+")[1]);
        sp = ns();
        long h = Long.parseLong(sp.split("\\+")[0]);
        long d = Long.parseLong(sp.split("\\+")[1]);
        long lo = max(x, h);
        long hi = min(x + y, h + d);
        if (lo < hi) {
            out.println(0);
        } else {
            long dd = (hi - lo);
            BigDecimal bd = new BigDecimal(dd);
            BigDecimal f = bd.multiply(bd);
            BigDecimal re = f.divide(new BigDecimal(y)).divide(new BigDecimal(d));
            BigDecimal res = re.setScale(2, BigDecimal.ROUND_HALF_DOWN);
            out.println(res);
        }

    }


    void solve22() {
        int n = ni();
        List<Tuple> li = new ArrayList<>();
        while (n-- > 0) {
            int id = ni();
            int len = ni();
            double f = nd();
            li.add(new Tuple(id, len, f));
        }
        int pos = ni();
        Collections.sort(li, (a, b) -> {
            return Double.compare((double) a.y * b.z, (double) b.y * a.z);
        });
        out.println(li.get(pos - 1).x);
    }


    long s(long x, long n, long a) {
        if (a == 0) return Long.MAX_VALUE;
        if (a > 0) {
            return (n - x) / a;
        } else {
            return (x - 1) / (-a);
        }
    }


    long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }


    void rotate(char[][] c) {
        int l = c.length;
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < l - i; ++j) {
                char t = c[i][j];
                c[i][j] = c[l - 1 - j][l - 1 - i];
                c[l - 1 - j][l - 1 - i] = t;
            }
        }

        for (int j = 0; j < l; ++j) {
            for (int i = 0; i < l / 2; ++i) {
                char t = c[i][j];
                c[i][j] = c[l - 1 - i][j];
                c[l - 1 - i][j] = t;
            }
        }


    }

    boolean ok(char[][] mp, char[][] ck, int i, int j) {
        boolean ok = true;
        for (int a = 0; a < 3; ++a) {
            for (int b = 0; b < 3; ++b) {
                if (mp[i + a][j + b] != ck[a][b]) {
                    return false;
                }
            }

        }
        return true;
    }

    boolean ok(char[] a, char[] b) {
        int p = 0;
        for (char c : b) {
            if (p < a.length && a[p] == c) {
                ++p;
            }
        }
        return p == a.length;
    }



























    boolean[] euler(int maxn) {

        int prime[] = new int[maxn + 1];
        boolean visit[] = new boolean[maxn + 1];

        for (int i = 2; i <= maxn; i++) {
            if (!visit[i]) {
                prime[++prime[0]] = i;
            }
            for (int j = 1; j <= prime[0] && i * prime[j] <= maxn; j++) {

                visit[i * prime[j]] = true;
                if (i % prime[j] == 0) {
                    break;
                }
            }
        }
        return visit;
    }

    long mod_pow(long k,long n,long p){
        long res = 1L;
        long temp = k%p;
        while(n!=0){
            long ck = n&1L;
            if(ck==1L){
                res *= temp;
                res %= p;
            }
            temp = temp*temp;
            temp %= p;
            n = n>>>1L;
        }
        return res%p;
    }



    void solve() {
        int n = ni();
        int nn = n+1;
        int m = nn/2;
        if(2*m<nn){
            ++m;
        }
        out.println(m);

        for(int i=1;i<=n;++i){
            if(i<=m){
                out.println(1+" "+i);
            }else{
                out.println(m+" "+(i-m+1));
            }


        }




    }


    void id1() {
        int c = 1;
        while (true) {
            int t = ni();
            if (t == 0) return;

            int a[] = new int[t];

            for (int i = 0; i < t; ++i) {
                a[i] = ni();
            }

            int m = 0;

            int s[] = new int[8];

            



            out.println("Case " + c + ":");
            out.println(m);
            for (int i = 0; i <= m; ++i) {

            }
            ++c;
        }
    }


    void id2() {

        while (true) {
            int n = ni();
            if (n == 0) return;
            long a[] = new long[n];
            for (int i = 0; i < n; ++i) {
                a[i] = nl();
            }

            long x = -a[0];
            long res = Math.abs(x);

            for (int i = 1; i < n; ++i) {
                x = x - a[i];
                res += Math.abs(x);

            }

            out.println(res);


        }
    }

    String round(double v) {
        return new java.text.DecimalFormat("
    }

    int max(int... a) {
        int x = a[0];
        int len = a.length;
        for (int i = 1; i < len; ++i) {
            x = Math.max(x, a[i]);
        }
        return x;
    }

    long max(long... a) {
        long x = a[0];
        int len = a.length;
        for (int i = 1; i < len; ++i) {
            x = Math.max(x, a[i]);
        }
        return x;
    }

    int min(int... a) {
        int x = a[0];
        int len = a.length;
        for (int i = 1; i < len; ++i) {
            x = Math.min(x, a[i]);
        }
        return x;
    }

    long min(long... a) {
        long x = a[0];
        int len = a.length;
        for (int i = 1; i < len; ++i) {
            x = Math.min(x, a[i]);
        }
        return x;
    }

    int abs(int a) {
        return Math.abs(a);
    }

    long abs(long a) {
        return Math.abs(a);
    }


    void run() throws Exception {
        is = System.in;
        out = new PrintWriter(System.out);

        long s = System.currentTimeMillis();
        solve();
        out.flush();
        

    }

    public static void main(String[] args) throws Exception {
        new Main().run();
    }

    private byte[] inbuf = new byte[1024];
    public int lenbuf = 0, ptrbuf = 0;

    private int readByte() {
        if (lenbuf == -1) throw new InputMismatchException();
        if (ptrbuf >= lenbuf) {
            ptrbuf = 0;
            try {
                lenbuf = is.read(inbuf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (lenbuf <= 0) return -1;
        }
        return inbuf[ptrbuf++];
    }

    private boolean isSpaceChar(int c) {
        return !(c >= 33 && c <= 126);
    }

    private int skip() {
        int b;
        while ((b = readByte()) != -1 && isSpaceChar(b)) ;
        return b;
    }

    private double nd() {
        return Double.parseDouble(ns());
    }

    private char nc() {
        return (char) skip();
    }

    private String ns() {
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while (!(isSpaceChar(b))) { 

            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    private char[] ns(int n) {
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while (p < n && !(isSpaceChar(b))) {
            buf[p++] = (char) b;
            b = readByte();
        }
        return n == p ? buf : Arrays.copyOf(buf, p);
    }

    private String nline() {
        StringBuilder sb = new StringBuilder();
        while (true) {
            int b = readByte();
            if (b == -1) {
                return "";
            }
            if (b == '\n') {
                return sb.toString();
            }
            sb.append((char) b);
        }
    }

    private char[][] nm(int n, int m) {
        char[][] map = new char[n][];
        for (int i = 0; i < n; i++) map[i] = ns(m);
        return map;
    }

    private int[] na(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = ni();
        return a;
    }

    private int ni() {
        int num = 0, b;
        boolean minus = false;
        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
        if (b == '-') {
            minus = true;
            b = readByte();
        }

        while (true) {
            if (b >= '0' && b <= '9') {
                num = (num << 3) + (num << 1) + (b - '0');
            } else {
                return minus ? -num : num;
            }
            b = readByte();
        }
    }

    private long nl() {
        long num = 0;
        int b;
        boolean minus = false;
        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
        if (b == '-') {
            minus = true;
            b = readByte();
        }

        while (true) {
            if (b >= '0' && b <= '9') {
                num = num * 10 + (b - '0');
            } else {
                return minus ? -num : num;
            }
            b = readByte();
        }
    }

    private boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    private void tr(Object... o) {
        if (!oj) System.out.println(Arrays.deepToString(o));
    }
}
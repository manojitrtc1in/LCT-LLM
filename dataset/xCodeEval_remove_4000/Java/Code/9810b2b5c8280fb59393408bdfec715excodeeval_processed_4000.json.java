import java.io.*;
import java.util.*;

public class Main {
    static Reader in = null;
    static PrintWriter out = null;

    


    static class Point implements Comparable<Point> {
        long x, y;
        Point(long x, long y) {
            this.x = x;
            this.y = y;
        }
        long dist2(Point p) {
            return (this.x - p.x) * (this.x - p.x) + (this.y - p.y) * (this.y - p.y);
        }
        double dist2(PointReal p) {
            return (this.x - p.x) * (this.x - p.x) + (this.y - p.y) * (this.y - p.y);
        }
        double dist(Point p) {
            return Math.sqrt((this.x - p.x) * (this.x - p.x) + (this.y - p.y) * (this.y - p.y));
        }
        double dist(PointReal p) {
            return Math.sqrt((this.x - p.x) * (this.x - p.x) + (this.y - p.y) * (this.y - p.y));
        }
        boolean equals(Point p) {
            return this.x == p.x && this.y == p.y;
        }
        public int compareTo(Point p) {
            if(this.x == p.x) {
                if(this.y < p.y) return -1;
                if(this.y > p.y) return 1;
                return 0;
            }
            if(this.x < p.x) return -1;
            return 1;
        }
        public String toString() {
            return "[x, y]: " + "[" + x + ", " + y + "]";
        }
    }

    static class PointReal implements Comparable<PointReal> {
        double x, y;
        PointReal(double x, double y) {
            this.x = x;
            this.y = y;
        }
        double dist2(PointReal p) {
            return (this.x - p.x) * (this.x - p.x) + (this.y - p.y) * (this.y - p.y);
        }
        double dist(PointReal p) {
            return Math.sqrt((this.x - p.x) * (this.x - p.x) + (this.y - p.y) * (this.y - p.y));
        }
        double dist2(Point p) {
            return (this.x - p.x) * (this.x - p.x) + (this.y - p.y) * (this.y - p.y);
        }
        double dist(Point p) {
            return Math.sqrt((this.x - p.x) * (this.x - p.x) + (this.y - p.y) * (this.y - p.y));
        }
        boolean equals(PointReal p) {
            return Math.abs(this.x - p.x) < 1e-6 && Math.abs(this.y - p.y) < 1e-6;
        }
        boolean equals(Point p) {
            return Math.abs(this.x - p.x) < 1e-6 && Math.abs(this.y - p.y) < 1e-6;
        }
        public int compareTo(PointReal p) {
            if(Math.abs(this.x - p.x) < 1e-6) {
                if(Math.abs(this.y - p.y) < 1e-6) return 0;
                if(this.y < p.y) return -1;
                return 1;
            }
            if(this.x < p.x) return -1;
            return 1;
        }
        public String toString() {
            return "[x, y]: " + "[" + x + ", " + y + "]";
        }
    }

    static class Line {
        long a, b, c;
        Line(Point p1, Point p2) {
            this.a = p1.y - p2.y;
            this.b = p2.x - p1.x;
            this.c = p1.x * p2.y - p2.x * p1.y;
        }
        Line(long a, long b, long c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
        boolean onLine(Point p) {
            return (a * p.x + b * p.y + c) == 0;
        }
        boolean isParallel(Line l) {
            return (this.a * l.b == l.a * this.b);
        }
        boolean id1(Line l) {
            return (this.a * l.a + this.b * l.b) == 0;
        }
        PointReal intersectionWith(Line l) {
            double d = this.a * l.b - l.a * this.b;
            if(d == 0) return null;
            return new PointReal((this.b * l.c - l.b * this.c) / d, (this.c * l.a - l.c * this.a) / d);
        }
        Line id6(Point p) {
            return new Line(-b, a, b * p.x - a * p.y);
        }
        long evaluate(Point p) {
            return a * p.x + b * p.y + c;
        }
        public String toString() {
            return "[a, b, c]: " + "[" + a + ", " + b + ", " + c + "]";
        }
    }

    static class Vec {
        long x, y;
        Vec(Point p1, Point p2) {
            this.x = p1.x - p2.x;
            this.y = p1.y - p2.y;
        }
        long dot(Vec v) {
            return this.x * v.x + this.y * v.y;
        }
        long cross(Vec v) {
            return this.x * v.y - v.x * this.y;
        }
        double length() {
            return Math.sqrt(this.x * this.x + this.y * this.y);
        }
        public String toString() {
            return "[x, y]: " + "[" + x + ", " + y + "]";
        }
    }

    static boolean ccw(Point p0, Point p1, Point p2) {
        return new Vec(p1, p0).cross(new Vec(p2, p0)) > 0;
    }

    static Point[] id4(Point[] p, int n) {
        if(n == 0) return new Point[0];
        Arrays.sort(p, 0, n);
        Point[] b = new Point[2*n];
        int top = 0;
        for(int i=0; i<n; i++) {
            while(top > 1 && !ccw(b[top-2], b[top-1], p[i])) top--;
            b[top++] = p[i];
        }
        for(int i=n-2, t = top; i>=0; i--) {
            while(top > t && !ccw(b[top-2], b[top-1], p[i])) top--;
            b[top++] = p[i];
        }
        Point[] a = new Point[top-1];
        System.arraycopy(b, 0, a, 0, top-1);
        return a;
    }

    static boolean isInside(Point[] b, int n, Point p) {
        long area = 0, tempArea = 0;
        for(int i=0; i<n; i++) {
            area = area + b[i].x * b[(i+1)%n].y - b[i].y * b[(i+1)%n].x;
            tempArea = tempArea + Math.abs((p.x * b[i].y + b[i].x * b[(i+1)%n].y + b[(i+1)%n].x * p.y)
                    - (p.y * b[i].x + b[i].y * b[(i+1)%n].x + b[(i+1)%n].y * p.x));
        }
        return tempArea == Math.abs(area);
    }

    static long area(Point[] b, int n) {
        long area = 0;
        for(int i=0; i<n; i++) area = area + b[i].x * b[(i+1)%n].y - b[i].y * b[(i+1)%n].x;
        return Math.abs(area);
    }

    static long id2(Point[] b, int n, Point p) {
        long area = 0;
        for(int i=0; i<n; i++) area = area + Math.abs((p.x * b[i].y + b[i].x * b[(i+1)%n].y + b[(i+1)%n].x * p.y)
                - (p.y * b[i].x + b[i].y * b[(i+1)%n].x + b[(i+1)%n].y * p.x));
        return area;
    }

    


    static int gcd(int a, int b) {
        while(b != 0) { int c = a%b; a = b; b = c; }
        return a;
    }

    static boolean isPrime(long n) {
        for(int i=2; (long)i*i<=n; i++) if((n%i) == 0) return false;
        return true;
    }

    static int prime(int[] p, int n) {
        boolean[] mark = new boolean[n];
        for(int i=4; i<=n; i+=2) mark[i] = true;
        int cnt = 0;
        p[cnt++] = 2;
        for(int i=3; i<=n; i+=2) {
            if(mark[i]) continue;
            p[cnt++] = i;
            if((long)i*i > n) continue;
            for(int j=i*i; j<=n; j+=(i+i)) mark[j] = true;
        }
        return cnt;
    }

    static int id5(int[] d, int n) {
        int cnt = 0;
        for(int i=2; i*i<=n; i++) {
            if((n%i) == 0) {
                d[cnt++] = i;
                while((n%i) == 0) n = n/i;
            }
        }
        return cnt;
    }

    static long modPow(long a, long p, long m) {
        if(p == 0) return (1%m);
        long t = modPow(a, p/2, m);
        t = (t * t) % m;
        if((p&1) == 1) return (t * a) % m;
        return t;
    }

    static long modInv(long a, long m) {
		
        return modPow(a, m-2, m);
    }

    

    

    

    

    


    static long fibMod(int n, int m, long[] f, int l) {
        if(n < l && f[n] != -1) return f[n];
        long f1 = fibMod(n/2, m, f, l);
        long f2 = fibMod(n/2 - 1, m, f, l);
        long ff = (f1 * f1) % m;
        if((n&1) == 1) ff = ff + (2 * f1 * f2) % m;
        else ff = ff + (f2 * f2) % m;
        ff = ff % m;
        if(n < l) f[n] = ff;
        return ff;
    }

    static void ncr(int[][] b, int n) {
        

        

        for(int i=0; i<=n; i++) {
            for(int j=0; i<=i; i++) {
                if(j == 0 || j == i) b[i][j] = 1;
                else b[i][j] = b[i-1][j-1] + b[i-1][j];
            }
        }
    }

    


    static int[] digitValue = new int[128];		

    static int id0(String s) {
        int x = 0;
        for(char ch: s.toCharArray()) x = Math.max(x, digitValue[(int)ch]);
        return (x < 2) ? 2 : x+1;
    }
    static boolean isPalindrome(String s) {
        char[] sa = s.toCharArray();
        int l = sa.length, m = (l + 1) / 2, i;
        for (i = 0; i < m && (sa[i] == sa[l - i - 1]); i++) ;
        return (i == m);
    }
    static int[] indexSorting(int[] a) {
        Integer[] b = new Integer[a.length];
        for(int i=a.length-1; i>=0; i--) b[i] = i;
        Arrays.sort(b, new Comparator<Integer>() {
            public int compare(Integer x, Integer y) { return a[x] - a[y]; }
        });
        return Arrays.stream(b).mapToInt(x -> x).toArray();
    }
    static int[] indexSorting(int[] a, int s, int e) {
        Integer[] b = new Integer[e - s];
        for(int i=s; i<e; i++) b[i - s] = i;
        Arrays.sort(b, new Comparator<Integer>() {
            public int compare(Integer x, Integer y) { return a[x] - a[y]; }
        });
        return Arrays.stream(b).mapToInt(Integer::intValue).toArray();
    }
    static String reverse(String s) {
        StringBuffer sb = new StringBuffer(s);
        return sb.reverse().toString();
    }

    static class Pair implements Comparable<Pair> {
        int x, y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
        public int compareTo(Pair p) {
            return (this.x == p.x) ? this.y - p.y : this.x - p.x;
        }
        public String toString() {
            return "[x, y]: " + "[" + x + ", " + y + "]";
        }
    }





























































































    







































    












































    

































































    static int find(char[] buf, int start, int end, char key) {
        for(int i=start; i<end; i++) {
            if(buf[i] == key) return i;
        }
        return -1;
    }

    static void solve() throws IOException {





        char[] b = in.nextLine().toCharArray();
        int n = b.length;
        int k = 0, z = 0;
        while(k < n && b[k] != '2') {
            if(b[k++] == '0') z++;
        }
        for(int i=0; i<z; i++) out.print('0');
        for(int i=0; i<n; i++) if(b[i] == '1') out.print('1');
        for(int i=k; i<n; i++) if(b[i] != '1') out.print(b[i]);
        out.println();
    }

    public static void main(String[] args) {
        try {
            OutputStreamWriter osw = new OutputStreamWriter(System.out);
            BufferedWriter bw = new BufferedWriter(osw);
            out = new PrintWriter(bw, true);



            in = new Reader();

            solve();

            in.close();

            out.close();
            bw.close();
            osw.close();
        }
        catch(FileNotFoundException e) {
            e.printStackTrace();
        }
        catch(IOException e) {
            e.printStackTrace();
        }
    }

    static void test() {
        

    }

    static class TestUtils {
        static <T> void reverse(T[] b) {
            for(int i=0, n = b.length, l = n/2; i<l; i++) {
                int j = n - i - 1;
                T t = b[i]; b[i] = b[j]; b[j] = t;
            }
        }
        static void reverse(int[] b) {
            for(int i=0, n = b.length, l = n/2; i<l; i++) {
                int j = n - i - 1;
                int t = b[i]; b[i] = b[j]; b[j] = t;
            }
        }
        static void reverse(long[] b) {
            for(int i=0, n = b.length, l = n/2; i<l; i++) {
                int j = n - i - 1;
                long t = b[i]; b[i] = b[j]; b[j] = t;
            }
        }
        static void reverse(double[] b) {
            for(int i=0, n = b.length, l = n/2; i<l; i++) {
                int j = n - i - 1;
                double t = b[i]; b[i] = b[j]; b[j] = t;
            }
        }
        static <T> void shuffle(T[] a, Random rand) {
            for (int i = 1, n = a.length; i<n; i++) {
                int j = rand.nextInt(i + 1);
                T t = a[i]; a[i] = a[j]; a[j] = t;
            }
        }
        static void shuffle(int[] a, Random rand) {
            for (int i = 1, n = a.length; i<n; i++) {
                int j = rand.nextInt(i + 1);
                int t = a[i]; a[i] = a[j]; a[j] = t;
            }
        }
        static void shuffle(long[] a, Random rand) {
            for (int i = 1, n = a.length; i<n; i++) {
                int j = rand.nextInt(i + 1);
                long t = a[i]; a[i] = a[j]; a[j] = t;
            }
        }
        static void shuffle(double[] a, Random rand) {
            for (int i = 1, n = a.length; i<n; i++) {
                int j = rand.nextInt(i + 1);
                double t = a[i]; a[i] = a[j]; a[j] = t;
            }
        }
        static <T> void printArray(T[] buf, PrintWriter out) {
            out.print("[");
            for(int i=0, n = buf.length; i<n; i++) out.print(" " + buf[i]);
            out.println(" ]");
        }
        static void printArray(int[] buf, PrintWriter out) {
            out.print("[");
            for(int i=0, n = buf.length; i<n; i++) out.print(" " + buf[i]);
            out.println(" ]");
        }
        static void printArray(long[] buf, PrintWriter out) {
            out.print("[");
            for(int i=0, n = buf.length; i<n; i++) out.print(" " + buf[i]);
            out.println(" ]");
        }
        static void printArray(double[] buf, PrintWriter out) {
            out.print("[");
            for(int i=0, n = buf.length; i<n; i++) out.print(" " + buf[i]);
            out.println(" ]");
        }
    }


    


    static class id3 {
        class Node {
            int x, h, cnt[];
            Node[] next;
            Node(int x, int h) {
                this.h = h;
                this.x = x;
                this.next = new Node[h];
                this.cnt = new int[h];
            }
        }

        Random rand;
        int maxLevel, size, pos[];
        Node head, prev[];

        id3(int maxLevel) {
            this.rand = new Random();
            this.maxLevel = maxLevel;
            this.size = 0;
            this.head = new Node(-1, maxLevel);
            this.pos = new int[maxLevel];
            this.prev = new Node[maxLevel];
        }
        int getLevel() {
            int l = 1;
            while(rand.nextInt() <= 0 && l < maxLevel) l++;
            return l;
        }
        void add(int x) {
            Node u = head, v = new Node(x, getLevel());
            int p = 0;
            for(int i=maxLevel-1; i>=0; i--) {
                for( ; u.next[i] != null && u.next[i].x < x; p += u.cnt[i], u = u.next[i]);
                if(u.next[i] != null) u.cnt[i]++;
                prev[i] = u;
                pos[i] = p;
            }
            int at = p+1;
            for(int i=0; i<v.h; i++) {
                v.next[i] = prev[i].next[i];
                prev[i].next[i] = v;
                if(v.next[i] != null) v.cnt[i] = pos[i] + prev[i].cnt[i] - at;
                prev[i].cnt[i] = at - pos[i];
            }
            this.size++;
        }
        boolean remove(int x) {
            Node u = head, v = null;
            for(int i=maxLevel-1, at = 0; i>=0; i--) {
                for( ; u.next[i] != null && u.next[i].x < x; at += u.cnt[i], u = u.next[i]);
                if(u.next[i] != null && u.next[i].x == x) {
                    if(v == null) v = u.next[i];
                    else for( ; u.next[i] != v; at += u.cnt[i], u = u.next[i]);
                }
                if(u.next[i] != null) u.cnt[i]--;
                prev[i] = u;
            }
            if(v == null) return false;
            for(int i=0; i<v.h; i++) {
                prev[i].next[i] = v.next[i];
                prev[i].cnt[i] = prev[i].cnt[i] + v.cnt[i];
            }
            this.size--;
            return true;
        }
        int getIndex(int x) {
            Node u = head;
            for(int i=maxLevel-1, at = 0; i>=0; i--) {
                for( ; u.next[i] != null && u.next[i].x < x; at += u.cnt[i], u = u.next[i]);
                if(u.next[i] != null && u.next[i].x == x) return at;
            }
            return -1;
        }
        int elementAt(int k) {
            Node u = head;
            for(int i=maxLevel-1, at = 0; i >= 0; i--) {
                for( ; u.next[i] != null && u.cnt[i] + at < k; at += u.cnt[i], u = u.next[i]);
                if(u.next[i] != null && u.cnt[i] + at == k) return u.next[i].x;
            }
            return Integer.MAX_VALUE;
        }
        















        int[] toArray() {
            int[] buf = new int[size];
            Node u = head.next[0];
            for(int i=0; i<size; i++) {
                buf[i] = u.x;
                u = u.next[0];
            }
            return buf;
        }
    }

    static class Reader {
        InputStreamReader isr;
        FileReader fr;
        BufferedReader br;
        StringTokenizer tk;
        String s;
        int flag;

        Reader() {
            isr = new InputStreamReader(System.in);
            br = new BufferedReader(isr);
            tk = new StringTokenizer("");
            s = null;
            flag = 0;
        }
        Reader(String file) throws FileNotFoundException {
            fr = new FileReader(file);
            br = new BufferedReader(fr);
            tk = new StringTokenizer("");
            s = null;
            flag = 1;
        }

        String nextLine() throws IOException {
            while((s = br.readLine()) != null && s.length() == 0);
            return s;
        }
        String next() throws IOException {
            if(!tk.hasMoreTokens()) tk = new StringTokenizer(nextLine());
            return tk.nextToken();
        }
        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
        long nextLong() throws IOException {
            return Long.parseLong(next());
        }
        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
        void close() throws IOException {
            br.close();
            if(flag == 0) isr.close();
            if(flag == 1) fr.close();
        }
    }
}

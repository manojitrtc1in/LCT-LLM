import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.PrintWriter;
import java.io.IOException;
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
        double dist(PointReal p) {
            return Math.sqrt((this.x - p.x) * (this.x - p.x) + (this.y - p.y) * (this.y - p.y));
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

    static class VecReal {
        double x, y;
        VecReal(PointReal p1, PointReal p2) {
            this.x = p1.x - p2.x;
            this.y = p1.y - p2.y;
        }
        VecReal(PointReal p1, Point p2) {
            this.x = p1.x - p2.x;
            this.y = p1.y - p2.y;
        }
        VecReal(Point p1, Point p2) {
            this.x = p1.x - p2.x;
            this.y = p1.y - p2.y;
        }
        double dot(VecReal v) {
            return this.x * v.x + this.y * v.y;
        }
        double dot(Vec v) {
            return this.x * v.x + this.y * v.y;
        }
        double cross(VecReal v) {
            return this.x * v.y - v.x * this.y;
        }
        double cross(Vec v) {
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

    static class Polygon {
        Point[] p, sorted;
        Line[] line;
        boolean sortedFlag, lineFlag;
        int n;
        Polygon(Point[] p, int n) {
            this.n = n;
            this.p = new Point[n+2];
            System.arraycopy(p, 0, this.p, 0, n);
            this.p[n] = p[0]; this.p[n+1] = p[1];
            this.sortedFlag = false;
        }
        boolean id0() {
            boolean dir = ccw(p[0], p[1], p[2]);
            for(int i=1; i<n; i++) if(ccw(p[i], p[i+1], p[i+2]) != dir) return false;
            return true;
        }
        long signedArea() {
            long a = 0;
            for(int i=0; i<n; i++) a = a + p[i].x * p[i+1].y - p[i].y * p[i+1].x;
            return a;
        }
        long area() {
            return Math.abs(signedArea());
        }
        boolean id2() {
            return signedArea() > 0;
        }
        boolean isVertex(Point v) {
            if(!sortedFlag) {
                sorted = new Point[n];
                System.arraycopy(p, 0, sorted, 0, n);
                Arrays.sort(sorted);
                sortedFlag = true;
            }
            int s = 0, e = n-1;
            while(s <= e) {
                int m = (s+e)/2;
                int f = sorted[m].compareTo(v);
                if(f < 0) s = m+1;
                else if(f > 0) e = m-1;
                else return true;
            }
            return false;
        }
        boolean onPolygon(Point v) {
            for(int i=0; i<n; i++) if(new Line(p[i], p[i+1]).onLine(v)) return true;
            return false;
        }
        boolean isInside(Point v, Random rand) {
            if(!lineFlag) {
                for(int i=0; i<n; i++) line[i] = new Line(p[i], p[i+1]);
                lineFlag = true;
            }
            Point u = new Point(rand.nextInt(), rand.nextInt());
            while(u.equals(v)) u = new Point(rand.nextInt(), rand.nextInt());
            Vec v0 = new Vec(u, v);
            int cnt = 0;
            for(int i=0; i<n; i++) {
                if(line[i].onLine(v)) return false;
                Vec v1 = new Vec(p[i], v), v2 = new Vec(p[(i+1)%n], v);
                long f1 = v0.cross(v1);
                long f2 = v0.cross(v2);
                if((f1 == 0 && v0.dot(v1) > 0) || (f2 == 0 && v0.dot(v2) > 0)) return isInside(v, rand);
                if((double)f1*f2 < 0) {
                    long d = (f2 < 0) ? v2.cross(v1) : v1.cross(v2);
                    if(d > 0) cnt++;
                }
            }
            return (cnt&1) == 1;
        }
    }

    static Point[] id4(Point[] p, int n) {
        Arrays.sort(p);
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

    static int gcd(int a, int b) {
        while(b != 0) { int c = a%b; a = b; b = c; }
        return a;
    }

    static void solve() throws IOException {
        PriorityQueue<Pair> pq = new PriorityQueue<>(new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                return o1.x - o2.x;
            }
        });

        long ans = 0;
        int n = in.nextInt();
        pq.offer(new Pair(in.nextInt(), 0));
        for(int i=1; i<n; i++) {
            int a = in.nextInt();
            Pair t = pq.peek();

            if(t.x < a) {
                ans = ans + a - t.x;
                pq.offer(new Pair(a, 1));
                if(t.y == 1) t.y = 0;
                else pq.poll();
            }
            else pq.offer(new Pair(a, 0));
        }

        out.println(ans);
    }

    public static void main(String[] args) {
        try {
            OutputStreamWriter osw = new OutputStreamWriter(System.out);
            BufferedWriter bw = new BufferedWriter(osw);
            in = new Reader();
            out = new PrintWriter(bw);

            solve();



            out.close();
            bw.close();
            osw.close();
            in.close();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }

    static void test() throws IOException {









































        Fruit f = Fruit.APPLE;
        Fruit[] buf = Fruit.values();
        TestUtils.shuffle(buf, new Random());
        TestUtils.printArray(buf, out);
        Arrays.sort(buf);
        TestUtils.printArray(buf, out);
    }

    static enum Fruit {
        APPLE, ORANGE, MANGO, BANANA;
    }

    static void assertion(boolean f) {
        if(!f) throw new AssertionError();
    }
    static void assertion(boolean f, String msg) {
        if(!f) throw new AssertionError(msg);
    }
    static void dbg(String msg, PrintWriter out) {
        out.println(msg);
    }

    static int huh(int mL, Random rand) {
        int h = 1;
        while(rand.nextInt() <= 0 && h < mL) h++;
        return h;
    }

    static void id5(int n) {
        Random rand = new Random();
        int[] b = new int[16];
        for(int i=1; i<n; i++) {
            b[huh(b.length-1, rand)]++;
        }
        for(int i=0; i<16; i++) {
            out.println((double)b[i]/n);
        }
    }

    static class TestUtils {
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
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringTokenizer tk = new StringTokenizer("");
        String s = null;

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
        void close() throws  IOException {
            br.close();
            isr.close();
        }
    }
}

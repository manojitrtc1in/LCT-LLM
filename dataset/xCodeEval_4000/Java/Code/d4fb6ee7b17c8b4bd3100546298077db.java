import com.sun.corba.se.impl.orbutil.graph.Graph;

import java.io.*;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.*;
import java.util.Stack;


public class Main {

    static final boolean debug = false;
    static final boolean fileIO = false;

    public static final int INF = Integer.MAX_VALUE;

    public static void main(String[] args) throws Exception {
        InputStream is = null;
        OutputStream os = null;
        if (fileIO) {
            is = new FileInputStream("input.txt");
            os = new FileOutputStream("output.txt");
        } else {
            is = System.in;
            os = System.out;
        }
        InputReader in = new InputReader(is);
        PrintWriter out = new PrintWriter(os);
        new Task_D().solve(in, out);
        out.close();
    }
}

class Task_2 {

    List<Integer> ids = new ArrayList<>();

    

    

    Deque<Integer> stateId = new LinkedList<>();
    

    TreeSet<Integer> idsOnScreen = new TreeSet<>();

    public void solve(InputReader in, PrintWriter out) throws Exception {
        int n = in.nextInt(), k = in.nextInt();
        for (int i = 0; i < n; ++i) {
            int idi = in.nextInt();
            ids.add(idi);
        }
        

        for (int i = 0; i < n; ++i) {
            int id = ids.get(i);
            if (idsOnScreen.contains(id)) {
                continue;
            }
            if (stateId.size() == k) {
                int idToRemove = stateId.removeLast();
                idsOnScreen.remove(idToRemove);
            }
            stateId.addFirst(id);
            idsOnScreen.add(id);
        }
        

        int m = stateId.size();
        out.println(m);
        for (int i = 0; i < m; ++i) {
            out.print(stateId.remove());
            if (i < (m - 1)) {
                out.print(" ");
            } else {
                out.println();
            }
        }
    }
}

class Task_D {

    public void solve(InputReader in, PrintWriter out) throws Exception {
        String s = in.nextString();
        int[] a = new int[s.length()];
        for (int i = 0; i < s.length(); ++i) {
            a[i] = (int)(s.charAt(i) - 'a');
        }
        int q = in.nextInt();
        Map<Integer, NavigableSet<Integer>> positions = new TreeMap<>();
        for (int i = 0; i < 26; ++i) {
            positions.putIfAbsent(i, new TreeSet<>());
        }
        for (int i = 0; i < a.length; ++i) {
            positions.get(a[i]).add(i);
        }
        while (q > 0) {
            q -= 1;
            int t = in.nextInt();
            if (t == 1) {
                int index = in.nextInt() - 1;
                int newValue = (int)(in.nextString().charAt(0) - 'a');
                positions.get(a[index]).remove(index);
                positions.get(newValue).add(index);
                a[index] = newValue;
            } else {
                int l = in.nextInt() - 1;
                int r = in.nextInt() - 1;
                int cnt = 0;
                for (Map.Entry<Integer, NavigableSet<Integer>> e : positions.entrySet()) {
                    NavigableSet<Integer> indexes = e.getValue();
                    if (indexes.size() <= 0) { continue; }
                    if (indexes.higher(l - 1) != null && indexes.higher(l - 1) <= r) {
                        cnt += 1;
                    }
                }
                out.println(cnt);
            }
        }
    }
}


class Task_8 {

    int n;
    int x1, y1, x2, y2;


    long f1(long time) {
        long details = (time + y1) / (x1 + y1);
        return details;
    }

    long f2(long time) {
        long details = (time + y2) / (x2 + y2);
        return details;
    }

    

    int f(long time) {
        

        return f1(time) + f2(time) < n ? 0 : 1;
    }




    long higher() {
        long lo = 1, hi = (long)(1e18 + 1);
        while (lo + 1 < hi) {
            long m = (lo + hi) / 2;
            if (f(m) == 1) {
                hi = m;
            } else {
                lo = m;
            }
        }
        return hi;
    }

    public void solve(InputReader in, PrintWriter out) throws Exception {
        n = in.nextInt();
        x1 = in.nextInt();
        y1 = in.nextInt();
        x2 = in.nextInt();
        y2 = in.nextInt();
        

        long answer = higher();
        out.println(answer);
    }
}

class Task_7 {

    final int LEFT = 1;
    final int RIGHT = 2;
    final int UP = 3;
    final int DOWN = 4;

    class Wall {
        int id;
        int dir;
        public Wall(int id, int dir) {
            this.id = id;
            this.dir = dir;
        }
    }

    int[][] a;


    class Segment {
        int l, r;
        public Segment(int l, int r) {
            this.l = l;
            this.r = r;
        }
    }


    ArrayList<Segment> cols = new ArrayList<>();
    ArrayList<Segment> rows = new ArrayList<>();

    class Point {
        public static final int OPEN = 0;
        public static final int CLOSED = 2;
        int coordinate;
        int weight; 

        int id; 

        public Point(int coordinate, int weight, int id) {
            this.coordinate = coordinate;
            this.weight = weight;
            this.id = id;
        }
    }

    int __solve(ArrayList<Segment> sgs) {
        int ans = 0;
        TreeSet<Point> pts = new TreeSet<>(new Comparator<Point>() {
            @Override
            public int compare(Point o1, Point o2) {
                if (o1.coordinate != o2.coordinate) {
                    return o1.coordinate - o2.coordinate;
                } else if (o1.weight != o2.weight) {
                    return o1.weight - o2.weight;
                } else {
                    return 0;
                }
            }
        });
        for (int i = 0; i < sgs.size(); ++i) {
            pts.add(new Point(sgs.get(i).l, Point.OPEN, i));
            pts.add(new Point(sgs.get(i).r, Point.CLOSED, i));
        }
        int lo = -1; 

        for (Point p : pts) {
            if (p.weight == Point.CLOSED) {
                

            }
        }
        return ans;
    }


    public void solve(InputReader in, PrintWriter out) throws Exception {
        int n = in.nextInt(), m = in.nextInt();
        a = new int[n][m];
        for (int i = 0; i < n; ++i) {
            String line = in.nextString();
            for (int j = 0; j < m; ++j) {
                if (line.charAt(j) == '.') { 

                    a[i][j] = 0;
                } else { 

                    a[i][j] = 1;

                }
            }
        }
        

        for (int i = 0; i < n; ++i) {
            int lo = -1;
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 1) {
                    if (lo != -1) {
                        cols.add(new Segment(lo + 1, j));
                    }
                    lo = j;
                }
            }
        }
        

        for (int j = 0; j < m; ++j) {
            int lo = -1;
            for (int i = 0; i < n; ++i) {
                if (a[i][j] == 1) {
                    if (lo != -1) {
                        rows.add(new Segment(lo + 1, j));
                    }
                    lo = i + 1;
                }
            }
        }
        

        int x = __solve(cols);
        int y = __solve(rows);
        out.println(x + y);

    }
}


class NegativeNumbers {

    final int n = 3, m = 4;

    private int _solve(int[][] data, int n, int m) {
        int j = m - 1;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            while (j >= 0 && data[i][j] >= 0) {
                j -= 1;
            }
            count += (j + 1);
        }
        return count;
    }

    public void solve(InputReader in, PrintWriter out) {
        int[][] data = {
                {-3, -2, -1, 1},
                {-1, 2, 3, 4},
                {4, 5, 6, 7}
        };
        

        

        

        out.println(_solve(data, n, m));
    }
}


class KNearestPoints {

    class Point {
        int x, y;
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public double distSquared() {
            return this.x * this.x + this.y * this.y;
        }

        @Override
        public String toString() {
            return "(" + this.x + " " + this.y + ")";
        }
    }

    public void solve(InputReader in, PrintWriter out) throws Exception {
        

        TreeSet<Point> pts = new TreeSet<>(new Comparator<Point>() {
            @Override
            public int compare(Point o1, Point o2) {
                double d1 = o1.x * o1.x + o1.y * o1.y;
                double d2 = o2.x * o2.x + o2.y * o2.y;
                if (d1 > d2) {
                    return 1;
                } else if (d1 == d2) {
                    return 0;
                } else {
                    return -1;
                }
            }
        });
        int n = in.nextInt();
        int k = in.nextInt();
        List<Point> list = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            int x = in.nextInt();
            int y = in.nextInt();
            Point p = new Point(x, y);
            list.add(p);
        }
        

        for (int i = 0; i < k; ++i) {
            pts.add(list.get(i));
        }
        

        for (int i = k; i < n; ++i) {
            if (pts.last().distSquared() > list.get(i).distSquared()) {
                pts.pollLast();
                pts.add(list.get(i));
            }
        }
        

        for (Point p : pts) {
            out.println(p);
        }

    }
}









class ReverseWords {

    public void solve(InputReader in, PrintWriter out) throws Exception {
        in.setSpaceCharFilter(new InputReader.SpaceCharFilter() {
            @Override
            public boolean isSpaceChar(int ch) {
                return ch == -1 || ch == '\n';
            }
        });
        StringBuilder s = new StringBuilder(in.nextString());
        _reverse(s, 0, s.length() - 1);
        out.println(s);
        

        for (int i = 0; i < s.length(); ++i) {
            int j = i;
            while (j < s.length() && s.charAt(j) != ' ') {
                ++j;
            }
            _reverse(s, i, j - 1);
            i = j;
        }
        out.println(s);
    }

    private void _reverse(StringBuilder s, int lo, int hi) {
        for (int k = 0; k < (hi - lo + 1) / 2; ++k) {
            char tmp = s.charAt(lo + k);
            s.setCharAt(lo + k, s.charAt(hi - k));
            s.setCharAt(hi - k, tmp);
        }
    }
}



class SpacesToTheEnd {

    public void solve(InputReader in, PrintWriter out) throws Exception {

        

        

        String src = new String("the sky is blue");
        StringBuilder s = new StringBuilder(src);
        for (int left = 0, right = 0; right < s.length(); ++right) {
            if (s.charAt(right) != ' ') {
                char tmp = s.charAt(left);
                s.setCharAt(left, s.charAt(right));
                s.setCharAt(right, tmp);
                ++left;
            }
        }
        out.println(s);
        

        

        

        

        

    }
}


class SpiralMatrix {

    

    

    

    


    int fillLayer(int level, int[][] a, int cnt) {
        

        

        

        


        return 1;
    }

    void f(int[][] a, int level, int NUMBER_OF_LAYERS, int cnt) {
        if (level >= NUMBER_OF_LAYERS) {
            return;
        } else {
            

            int lastFilledNumber = fillLayer(level, a, cnt);
            f(a, level + 1, NUMBER_OF_LAYERS, lastFilledNumber);
        }
    }

    public void solve(InputReader in, PrintWriter out) throws Exception {
        int n = in.nextInt();
        int[][] a = new int[n][n];
        int NUMBER_OF_LAYERS = n / 2 + n % 2;
        f(a, 0, NUMBER_OF_LAYERS, 1);
        

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                out.print(a[i][j]);
                if (j < n - 1) {
                    out.print(" ");
                }
            }
            out.println();
        }
    }
}




class SegmentTree {

    private static long NIL = Long.MAX_VALUE;

    public interface Function {
        public long value(long a, long b);
    }

    private Function f;

    private long[] tree;
    private int n;

    public SegmentTree(int[] array, Function f) {
        this.f = f;
        this.n = array.length;
        int sz = 1;
        while (sz < n) sz <<= 1;
        this.tree = new long[sz + (sz - 1)];
        build(array, 0, 0, n - 1);
    }

    private void build(int[] array, int id, int lo, int hi) {
        if (lo == hi) {
            tree[id] = array[lo];
        } else {
            int m = (lo + hi) >> 1;
            build(array, 2 * id + 1, lo, m);
            build(array, 2 * id + 2, m + 1, hi);
            tree[id] = f.value(tree[2 * id + 1], tree[2 * id + 2]);
        }
    }

    public long query(int i, int j) {
        return query(0, 0, n - 1, i, j);
    }
    private long query(int id, int lo, int hi, int i, int j) {
        if (i <= lo && hi <= j) {
            return tree[id];
        }
        if (lo > j || hi < i) {
            return NIL;
        }
        int m = (lo + hi) >> 1;
        int l_id = 2 * id + 1;
        int r_id = 2 * id + 2;
        if (j <= m) {
            return query(l_id, lo, m, i, j);
        }
        if (i > m) {
            return query(r_id, m + 1, hi, i, j);
        }
        return f.value(query(l_id, lo, m, i, j), query(r_id, m + 1, hi, i, j));
    }

    

    public void update(int i, int value) {
        update(0, 0, n - 1, i, value);
    }
    

    private void update(int id, int lo, int hi, int i, int value) {
        if (lo == hi) {
            tree[id] = value;
        } else {
            int m = (lo + hi) >> 1;
            int l_id = 2 * id + 1;
            int r_id = 2 * id + 2;
            if (i <= m) {
                update(l_id, lo, m, i, value);
            } else {
                update(r_id, m + 1, hi, i, value);
            }
            tree[id] = f.value(tree[l_id], tree[r_id]);
        }
    }
}

class InputReader {

    class EOF extends Exception {
        public EOF(String msg) {
            super(msg);
        }
    }

    private InputStream stream;
    private byte[] buf;
    private int curChar = 0, snumChars = 0;

    private SpaceCharFilter filter;

    public InputReader(InputStream stream) {
        this.stream = stream;
        this.buf = new byte[8192];
        this.filter = null;
    }

    public void setSpaceCharFilter(SpaceCharFilter filter) {
        this.filter = filter;
    }


    public int snext() {
        if (curChar >= snumChars) {
            curChar = 0;
            try {
                snumChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (snumChars <= 0) {
                return -1;
            }
        }
        return buf[curChar++];
    }

    public int nextInt() throws EOF, InputMismatchException {
        int c = snext();
        while (isSpaceChar(c) && c != -1) {
            c = snext();
        }
        if (c == -1) {
            throw new EOF("End of file");
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = snext();
        }
        int res = 0;
        while (!isSpaceChar(c)) {
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res *= 10;
            res += c - '0';
            c = snext();
        }
        return res * sgn;
    }

    public double nextDouble() throws EOF, InputMismatchException {
        return Double.parseDouble(nextString());
    }

    public long nextLong() throws EOF, InputMismatchException {
        return Long.parseLong(nextString());
    }

    public String nextString() throws InputMismatchException, EOF {
        int c = snext();
        while (isSpaceChar(c) && c != -1) {
            c = snext();
        }
        if (c == -1) {
            throw new EOF("End of file");
        }
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = snext();
        } while (!isSpaceChar(c));
        return res.toString();
    }



    public boolean isSpaceChar(int c) {
        if (filter != null) {
            return filter.isSpaceChar(c);
        }
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface SpaceCharFilter {
        public boolean isSpaceChar(int ch);
    }
}


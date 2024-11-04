import java.io.*;
import java.math.BigInteger;
import java.util.*;



public class Solution {
    public static void main(String[] args) throws IOException {
        boolean id6 = Arrays.asList(args).contains("DEBUG_MODE");
        InputStream inputStream;
        OutputStream outputStream;

        if (id6) {


            inputStream = new id1();



            outputStream = new id3();
        } else {
            inputStream = new id13();
            outputStream = new id3();





        }

        inputStream.open();
        outputStream.open();

        new Solution().run(inputStream, outputStream, id6);

        outputStream.close();
        inputStream.close();
    }

    @SuppressWarnings("FieldCanBeLocal")
    private InputStream in;
    private OutputStream out;
    private boolean id6;
    private Timer timer = new Timer();

    private void id16(String s) throws IOException {
        if (id6) {
            out.println(s);
            out.flush();
        }
    }

    private void printTimer(String mark) throws IOException {
        id16(mark + ": " + timer.id4() + " ms.");
    }

    private static String formatDouble(double n, int precision) {
        return String.format(Locale.ENGLISH, "%." + precision + "f", n);
    }

    private void run(InputStream in, OutputStream out, boolean id6) throws IOException {
        this.in = in;
        this.out = out;
        this.id6 = id6;



        int t = 1;
        for (int i = 0; i < t; i++) {


            solve();
            out.flush();
        }
    }

    private static final int mm = 1000000007;

    private void solve() throws IOException {
        timer.reset();

        int n = in.nextInt();
        int m = in.nextInt();
        char[] s = in.nextToken().toCharArray();
        int[] a = in.id10(m);

        int k = s.length;


        int[] f = new int[k];
        for (int i = 1; i < k; i++) {
            int j = f[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = f[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            f[i] = j;
        }


        boolean[] t = new boolean[k + 13];
        {
            int i = f[k - 1];
            while (i > 0) {
                t[i] = true;
                i = f[i - 1];
            }
        }




        int cnt = 0;
        int lsti = -k + 1;
        for (int i = 0; i < m; i++) {
            if (lsti + k <= a[i]) {
                cnt += a[i] - (lsti + k);
            } else {
                if (!t[k - (a[i] - lsti)]) {
                    out.println(0);
                    return;
                }
            }
            lsti = a[i];
        }
        if (lsti + k <= n + 1) {
            cnt += n + 1 - (lsti + k);
        }
        out.println(pow(26, cnt));
    }

    private static int add(int a, int b) {
        return (a + b) % mm;
    }

    private static int mult(int a, int b) {
        return (int) ((a * (long) b) % mm);
    }

    private int pow(int a, long n) {
        if (n == 0) return 1;
        int t = pow(a, n / 2);
        t = mult(t, t);
        if (n % 2 != 0) {
            t = mult(t, a);
        }
        return t;
    }

    private static class Dsu {
        private int[] parent;
        private int[] rank;

        public Dsu(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        private int findSet(int v) {
            if (v == parent[v])
                return v;
            return parent[v] = findSet(parent[v]);
        }

        private void unionSets(int a, int b) {
            a = findSet(a);
            b = findSet(b);
            if (a != b) {
                if (rank[a] < rank[b]) {
                    int t = a;
                    a = b;
                    b = t;
                }
                parent[b] = a;
                if (rank[a] == rank[b]) {
                    rank[a]++;
                }
            }
        }
    }

    private static class id19 {
        private int[] t;

        private id19(int[] a) {
            this.t = new int[a.length * 4];
            build(a, 1, 0, a.length - 1);
        }

        private void build(int a[], int v, int tl, int tr) {
            if (tl == tr)
                t[v] = a[tl];
            else {
                int tm = (tl + tr) / 2;
                build(a, v * 2, tl, tm);
                build(a, v * 2 + 1, tm + 1, tr);
                t[v] = Math.max(t[v * 2], t[v * 2 + 1]);
            }
        }

        private int get(int v, int tl, int tr, int l, int r) {
            if (l > r)
                return Integer.MIN_VALUE;
            if (l == tl && r == tr)
                return t[v];
            int tm = (tl + tr) / 2;
            return Math.max(get(v * 2, tl, tm, l, Math.min(r, tm)), get(v * 2 + 1, tm + 1, tr, Math.max(l, tm + 1), r));
        }

        private void update(int v, int tl, int tr, int pos, int newVal) {
            if (tl == tr)
                t[v] = newVal;
            else {
                int tm = (tl + tr) / 2;
                if (pos <= tm) {
                    update(v * 2, tl, tm, pos, newVal);
                } else {
                    update(v * 2 + 1, tm + 1, tr, pos, newVal);
                }
                t[v] = Math.max(t[v * 2], t[v * 2 + 1]);
            }
        }
    }

    

    private static class SegmentTree {
        private static class Value {
            private HashMap<Integer, Integer> vals;
            private long res = 0;

            private int firstX = -1;
            private int lastX = -1;
            private long diff = 0;

            private Value() {
            }

            private Value(int val) {
                this.vals = new HashMap<Integer, Integer>();
                vals.put(val + 1, 1);
            }

            private void init(Value val1, Value val2) {
                this.vals = new HashMap<Integer, Integer>(val1.vals);
                for (Map.Entry<Integer, Integer> e : val2.vals.entrySet()) {
                    Integer p = vals.get(e.getKey());
                    vals.put(e.getKey(), (p == null ? 0 : p) + e.getValue());
                }
            }
        }

        private int n;
        private Value[] values;

        public SegmentTree(int n) {
            this.n = n;
            values = new Value[n * 4];
            build(1, 0, n - 1);
        }

        private void build(int v, int tl, int tr) {
            if (tl == tr) {
                values[v] = new Value(tl);
            } else {
                int tm = (tl + tr) >> 1;
                build(v << 1, tl, tm);
                build((v << 1) + 1, tm + 1, tr);
                values[v] = new Value();
                pull(v);
            }
        }

        public void update(int l, int r, int x) {
            update(1, 0, n - 1, l, r, x);
        }

        private void update(int v, int tl, int tr, int l, int r, int x) {
            if (tl == l && tr == r) {
                Value pVal = values[v];
                if (pVal.firstX < 0) {
                    pVal.firstX = x;
                    pVal.lastX = x;


                    for (Map.Entry<Integer, Integer> e : pVal.vals.entrySet()) {
                        pVal.res += Math.abs(e.getKey() - x) * (long) e.getValue();
                    }
                    pVal.vals.clear();
                    pVal.vals.put(x, r - l + 1);
                } else {
                    pVal.res += (r - l + 1) * Math.abs(pVal.lastX - x);
                    pVal.vals.clear();
                    pVal.vals.put(x, r - l + 1);

                    pVal.diff += Math.abs(pVal.lastX - x);
                    pVal.lastX = x;
                }
                return;
            }
            int tm = (tl + tr) >> 1;

            push(v, tl, tm, tr);

            if (l <= tm) {
                update(v << 1, tl, tm, l, Math.min(tm, r), x);
            }
            if (r >= tm + 1) {
                update((v << 1) + 1, tm + 1, tr, Math.max(l, tm + 1), r, x);
            }
            pull(v);
        }

        public long get(int l, int r) {
            return get(1, 0, n - 1, l, r);
        }

        private Long get(int v, int tl, int tr, int l, int r) {
            if (l > r) {
                return null;
            }

            int tm = (tl + tr) >> 1;

            push(v, tl, tm, tr);

            if (l == tl && r == tr) {
                return values[v].res;
            }

            int leftTo = Math.min(r, tm);
            Long leftValue = get(v << 1, tl, tm, l, leftTo);

            int rightFrom = Math.max(l, tm + 1);
            Long rightValue = get((v << 1) + 1, tm + 1, tr, rightFrom, r);

            return leftValue == null ? rightValue :
                    (rightValue == null ? leftValue :
                            leftValue + rightValue);
        }

        private void pull(int v) {
            Value pVal = values[v];
            Value val1 = values[v << 1];
            Value val2 = values[(v << 1) + 1];
            pVal.lastX = -1;
            pVal.firstX = -1;
            pVal.diff = 0;
            pVal.res = val1.res + val2.res;
            pVal.init(val1, val2);
        }

        private void push(int v, int from, int mid, int to) {
            if (from < to) {
                push(values[v << 1], values[v], from, mid);
                push(values[(v << 1) + 1], values[v], mid + 1, to);
            }
        }

        private void push(Value val, Value pVal, int from, int to) {
            if (from > to) return;
            if (pVal.firstX >= 0) {
                long d;
                if (val.firstX >= 0) {
                    d = pVal.diff + Math.abs(pVal.firstX - val.lastX);
                    val.diff = d + val.diff;
                    val.lastX = pVal.lastX;

                    val.res += (to - from + 1) * d;
                    val.vals.clear();
                    val.vals.put(val.lastX, to - from + 1);
                } else {
                    val.lastX = pVal.lastX;
                    val.firstX = pVal.firstX;
                    val.diff = pVal.diff;

                    val.res += (to - from + 1) * pVal.diff;
                    for (Map.Entry<Integer, Integer> e : val.vals.entrySet()) {
                        val.res += Math.abs(e.getKey() - val.firstX) * (long) e.getValue();
                    }
                    val.vals.clear();
                    val.vals.put(val.lastX, to - from + 1);
                }
            }
        }
    }

    private static class Pair<K, V> {
        private K key;
        private V value;

        Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }

        K getKey() {
            return key;
        }

        V getValue() {
            return value;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Pair pair = (Pair) o;

            return !(key != null ? !key.equals(pair.key) : pair.key != null) && !(value != null ? !value.equals(pair.value) : pair.value != null);
        }

        @Override
        public int hashCode() {
            int result = key != null ? key.hashCode() : 0;
            result = 31 * result + (value != null ? value.hashCode() : 0);
            return result;
        }

        @Override
        public String toString() {
            return "Pair{" +
                    "key=" + key +
                    ", value=" + value +
                    '}';
        }
    }

    private static class Timer {
        private long lastTime = 0;

        private Timer() {
            lastTime = System.currentTimeMillis();
        }

        public void reset() {
            lastTime = System.currentTimeMillis();
        }

        public long id4() {
            long current = System.currentTimeMillis();
            long result = current - lastTime;
            lastTime = current;
            return result;
        }
    }

    

    private static class id1 extends InputStream {
        private String id2;

        public id1() throws IOException {
            this("input.txt");
        }

        public id1(String id2) throws IOException {
            this.id2 = id2;
        }

        @Override
        protected Reader getReader() throws IOException {
            return new FileReader(id2);
        }
    }

    private static class id13 extends InputStream {
        @Override
        protected Reader getReader() throws IOException {
            return new InputStreamReader(System.in);
        }
    }

    private static abstract class InputStream {
        private static String id14 = " \t\n\r\f";
        private BufferedReader in;

        public InputStream open() throws IOException {
            in = new BufferedReader(getReader());
            return this;
        }

        private class Line {
            private Line(String inputLine) {
                this.inputLine = inputLine;
                stringTokenizer = new StringTokenizer(this.inputLine, id14);
                readCharacters = 0;
            }

            private int readCharacters;
            private String inputLine = null;
            private StringTokenizer stringTokenizer = null;

            public String nextToken() {
                String result = stringTokenizer.nextToken();
                readCharacters += result.length();
                return result;
            }

            boolean id0() {
                return stringTokenizer.hasMoreTokens();
            }

            String id18() {
                int position = 0;
                for (int remain = readCharacters; remain > 0; position++) {
                    if (id14.indexOf(inputLine.charAt(position)) < 0) {
                        remain--;
                    }
                }
                return inputLine.substring(position);
            }
        }

        private Line currentLine = null;

        abstract protected Reader getReader() throws IOException;

        
        public String nextLine() throws IOException {
            id7();
            if (currentLine == null) {
                return null;
            }
            String result = currentLine.id18();
            currentLine = null;
            return result;
        }

        public boolean id12() throws IOException {
            id7();
            return currentLine != null;
        }

        public String nextToken() throws IOException {
            return id0() ? currentLine.nextToken() : null;
        }

        
        public boolean id0() throws IOException {
            while (true) {
                id7();
                if (currentLine == null || currentLine.id0()) {
                    break;
                } else {
                    currentLine = null;
                }
            }
            return currentLine != null;
        }

        public int nextInt() throws IOException {
            return Integer.valueOf(this.nextToken());
        }

        public long nextLong() throws IOException {
            return Long.valueOf(this.nextToken());
        }

        public double nextDouble() throws IOException {
            return Double.valueOf(this.nextToken());
        }

        public BigInteger id5() throws IOException {
            return new BigInteger(this.nextToken());
        }


        public String[] id8(int n) throws IOException {
            String[] result = new String[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.nextToken();
            }
            return result;
        }

        public int[] id10(int n) throws IOException {
            int[] result = new int[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.nextInt();
            }
            return result;
        }

        public long[] id17(int n) throws IOException {
            long[] result = new long[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.nextLong();
            }
            return result;
        }

        public BigInteger[] id15(int n) throws IOException {
            BigInteger[] result = new BigInteger[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.id5();
            }
            return result;
        }

        public void close() throws IOException {
            currentLine = null;
            in.close();
        }

        private void id7() throws IOException {
            if (currentLine == null) {
                String line = in.readLine();
                if (line != null) {
                    currentLine = new Line(line);
                }
            }
        }
    }

    private static class id11 extends OutputStream {
        private String id9;

        public id11() throws IOException {
            this("output.txt");
        }

        public id11(String id9) throws IOException {
            this.id9 = id9;
        }

        @Override
        protected Writer getWriter() throws IOException {
            return new FileWriter(id9);
        }
    }

    private static class id3 extends OutputStream {
        @Override
        protected Writer getWriter() throws IOException {
            return new OutputStreamWriter(System.out);
        }
    }

    private static abstract class OutputStream {
        private PrintWriter out;

        public OutputStream open() throws IOException {
            out = new PrintWriter(getWriter());
            return this;
        }

        abstract protected Writer getWriter() throws IOException;

        public void print(Object... s) {
            for (Object token : s) {
                out.print(token);
            }
        }

        public void println(Object... s) {
            print(s);
            out.println();
        }

        public void println() {
            out.println();
        }

        public void flush() throws IOException {
            out.flush();
        }

        public void close() throws IOException {
            out.flush();
            out.close();
        }
    }


}
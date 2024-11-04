import sun.reflect.generics.tree.Tree;

import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;



public class Solution {
    public static void main(String[] args) throws IOException {
        boolean isDebugMode = Arrays.asList(args).contains("DEBUG_MODE");
        InputStream inputStream;
        OutputStream outputStream;

        if (isDebugMode) {


            inputStream = new FileInputStream();



            outputStream = new ConsoleOutputStream();
        } else {
            inputStream = new ConsoleInputStream();
            outputStream = new ConsoleOutputStream();
        }

        inputStream.open();
        outputStream.open();

        new Solution().run(inputStream, outputStream, isDebugMode);

        outputStream.close();
        inputStream.close();
    }

    @SuppressWarnings("FieldCanBeLocal")
    private InputStream in;
    private OutputStream out;
    private boolean isDebugMode;
    private Timer timer = new Timer();

    private void printInDebug(String s) throws IOException {
        if (isDebugMode) {
            out.println(s);
            out.flush();
        }
    }

    private void printTimer(String mark) throws IOException {
        printInDebug(mark + ": " + timer.getMillisAndReset() + " ms.");
    }

    private static String formatDouble(double n, int precision) {
        return String.format(Locale.ENGLISH, "%." + precision + "f", n);
    }

    private void run(InputStream in, OutputStream out, boolean isDebugMode) throws IOException {
        this.in = in;
        this.out = out;
        this.isDebugMode = isDebugMode;





        solve();




    }

    private void solve() throws IOException {
        int n = in.nextInt();
        int s = in.nextInt();
        int l = in.nextInt();

        int[] a = in.nextIntArray(n);
        FSegmentTree tree = new FSegmentTree(a);
        int[] tmp = new int[n + 1];
        tmp[0] = 0;
        for (int i = 1; i <= n; i++) tmp[i] = Integer.MAX_VALUE;
        FSegmentTreeMin aans = new FSegmentTreeMin(tmp);
        for (int i = l - 1; i < n; i++) {
            int l0 = 0, r0 = i - l + 1;
            while (l0 + 1 < r0) {
                int m0 = (l0 + r0) / 2;
                P p = new P();
                tree.get(1, 0, n - 1, m0, i, p);
                if (p.diff() <= s) {
                    r0 = m0;
                } else {
                    l0 = m0;
                }
            }
            while (r0 >= 0) {
                P p = new P();
                tree.get(1, 0, n - 1, r0, i, p);
                if (p.diff() > s) {
                    break;
                }
                r0--;
            }
            r0++;
            int mn = aans.get(1, 0, n, r0, i - l + 1);
            if (mn < Integer.MAX_VALUE) {
                if (tmp[i + 1] > mn + 1) {
                    aans.update(1, 0, n, i + 1, mn + 1);
                    tmp[i + 1] = mn + 1;
                }
            }
        }
        int mm = tmp[n];
        out.println(mm == Integer.MAX_VALUE ? -1 : mm);
        printTimer("time");
    }

    private static class FSegmentTree {
        private int[] tmn;
        private int[] tmx;

        private FSegmentTree(int[] a) {
            this.tmn = new int[a.length * 4];
            this.tmx = new int[a.length * 4];
            build(a, 1, 0, a.length - 1);
        }

        private void build(int a[], int v, int tl, int tr) {
            if (tl == tr) {
                tmn[v] = a[tl];
                tmx[v] = a[tl];
            } else {
                int tm = (tl + tr) / 2;
                build(a, v * 2, tl, tm);
                build(a, v * 2 + 1, tm + 1, tr);
                tmn[v] = Math.min(tmn[v * 2], tmn[v * 2 + 1]);
                tmx[v] = Math.max(tmx[v * 2], tmx[v * 2 + 1]);
            }
        }

        private void get(int v, int tl, int tr, int l, int r, P p) {
            if (l > r)
                return;
            if (l == tl && r == tr) {
                p.mn = Math.min(p.mn, tmn[v]);
                p.mx = Math.max(p.mx, tmx[v]);
                return;
            }
            int tm = (tl + tr) / 2;
            get(v * 2, tl, tm, l, Math.min(r, tm), p);
            get(v * 2 + 1, tm + 1, tr, Math.max(l, tm + 1), r, p);
        }
    }

    private static class FSegmentTreeMin {
        private int[] t;

        private FSegmentTreeMin(int[] a) {
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
                t[v] = Math.min(t[v * 2], t[v * 2 + 1]);
            }
        }

        private int get(int v, int tl, int tr, int l, int r) {
            if (l > r)
                return Integer.MAX_VALUE;
            if (l == tl && r == tr)
                return t[v];
            int tm = (tl + tr) / 2;
            return Math.min(get(v * 2, tl, tm, l, Math.min(r, tm)), get(v * 2 + 1, tm + 1, tr, Math.max(l, tm + 1), r));
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
                t[v] = Math.min(t[v * 2], t[v * 2 + 1]);
            }
        }
    }

    private static class P {
        int mn, mx;

        private P() {
            this.mn = Integer.MAX_VALUE;
            this.mx = Integer.MIN_VALUE;
        }

        private int diff() {
            return mx - mn;
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

        public long getMillisAndReset() {
            long current = System.currentTimeMillis();
            long result = current - lastTime;
            lastTime = current;
            return result;
        }
    }

    

    private static class FileInputStream extends InputStream {
        private String inputFileName;

        public FileInputStream() throws IOException {
            this("input.txt");
        }

        public FileInputStream(String inputFileName) throws IOException {
            this.inputFileName = inputFileName;
        }

        @Override
        protected Reader getReader() throws IOException {
            return new FileReader(inputFileName);
        }
    }

    private static class ConsoleInputStream extends InputStream {
        @Override
        protected Reader getReader() throws IOException {
            return new InputStreamReader(System.in);
        }
    }

    private static abstract class InputStream {
        private static String DELIMITERS = " \t\n\r\f";
        private BufferedReader in;

        public InputStream open() throws IOException {
            in = new BufferedReader(getReader());
            return this;
        }

        private class Line {
            private Line(String inputLine) {
                this.inputLine = inputLine;
                stringTokenizer = new StringTokenizer(this.inputLine, DELIMITERS);
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

            boolean hasNextToken() {
                return stringTokenizer.hasMoreTokens();
            }

            String getLineRest() {
                int position = 0;
                for (int remain = readCharacters; remain > 0; position++) {
                    if (DELIMITERS.indexOf(inputLine.charAt(position)) < 0) {
                        remain--;
                    }
                }
                return inputLine.substring(position);
            }
        }

        private Line currentLine = null;

        abstract protected Reader getReader() throws IOException;

        
        public String nextLine() throws IOException {
            setInputLine();
            if (currentLine == null) {
                return null;
            }
            String result = currentLine.getLineRest();
            currentLine = null;
            return result;
        }

        public boolean hasNextLine() throws IOException {
            setInputLine();
            return currentLine != null;
        }

        public String nextToken() throws IOException {
            return hasNextToken() ? currentLine.nextToken() : null;
        }

        
        public boolean hasNextToken() throws IOException {
            while (true) {
                setInputLine();
                if (currentLine == null || currentLine.hasNextToken()) {
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

        public BigInteger nextBigInteger() throws IOException {
            return new BigInteger(this.nextToken());
        }


        public String[] nextTokensArray(int n) throws IOException {
            String[] result = new String[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.nextToken();
            }
            return result;
        }

        public int[] nextIntArray(int n) throws IOException {
            int[] result = new int[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.nextInt();
            }
            return result;
        }

        public long[] nextLongArray(int n) throws IOException {
            long[] result = new long[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.nextLong();
            }
            return result;
        }

        public BigInteger[] nextBigIntegerArray(int n) throws IOException {
            BigInteger[] result = new BigInteger[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.nextBigInteger();
            }
            return result;
        }

        public void close() throws IOException {
            currentLine = null;
            in.close();
        }

        private void setInputLine() throws IOException {
            if (currentLine == null) {
                String line = in.readLine();
                if (line != null) {
                    currentLine = new Line(line);
                }
            }
        }
    }

    private static class FileOutputStream extends OutputStream {
        private String outputFileName;

        public FileOutputStream() throws IOException {
            this("output.txt");
        }

        public FileOutputStream(String outputFileName) throws IOException {
            this.outputFileName = outputFileName;
        }

        @Override
        protected Writer getWriter() throws IOException {
            return new FileWriter(outputFileName);
        }
    }

    private static class ConsoleOutputStream extends OutputStream {
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
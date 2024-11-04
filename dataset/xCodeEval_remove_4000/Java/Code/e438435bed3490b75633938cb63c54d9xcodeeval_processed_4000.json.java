
import java.io.*;
import java.util.*;

public class UWI {
    InputStream is;
    FastWriter out;
    String INPUT = "";


    public static class LST {
        public long[][] set;
        public int n;
        


        public LST(int n) {
            this.n = n;
            int d = 1;
            for (int m = n; m > 1; m >>>= 6, d++) ;

            set = new long[d][];
            for (int i = 0, m = n >>> 6; i < d; i++, m >>>= 6) {
                set[i] = new long[m + 1];
            }
            

        }

        

        public LST setRange(int r) {
            for (int i = 0; i < set.length; i++, r = r + 63 >>> 6) {
                for (int j = 0; j < r >>> 6; j++) {
                    set[i][j] = -1L;
                }
                if ((r & 63) != 0) set[i][r >>> 6] |= (1L << r) - 1;
            }
            return this;
        }

        

        public LST unsetRange(int r) {
            if (r >= 0) {
                for (int i = 0; i < set.length; i++, r = r + 63 >>> 6) {
                    for (int j = 0; j < r + 63 >>> 6; j++) {
                        set[i][j] = 0;
                    }
                    if ((r & 63) != 0) set[i][r >>> 6] &= -(1L << r);
                }
            }
            return this;
        }

        public LST set(int pos) {
            if (pos >= 0 && pos < n) {
                

                for (int i = 0; i < set.length; i++, pos >>>= 6) {
                    set[i][pos >>> 6] |= 1L << pos;
                }
            }
            return this;
        }

        public LST unset(int pos) {
            if (pos >= 0 && pos < n) {
                

                for (int i = 0; i < set.length && (i == 0 || set[i - 1][pos] == 0L); i++, pos >>>= 6) {
                    set[i][pos >>> 6] &= ~(1L << pos);
                }
            }
            return this;
        }

        public boolean get(int pos) {
            return pos >= 0 && pos < n && set[0][pos >>> 6] << ~pos < 0;
        }

        public LST toggle(int pos) {
            return get(pos) ? unset(pos) : set(pos);
        }

        public int prev(int pos) {
            for (int i = 0; i < set.length && pos >= 0; i++, pos >>>= 6, pos--) {
                int pre = prev(set[i][pos >>> 6], pos & 63);
                if (pre != -1) {
                    pos = pos >>> 6 << 6 | pre;
                    while (i > 0) pos = pos << 6 | 63 - Long.numberOfLeadingZeros(set[--i][pos]);
                    return pos;
                }
            }
            return -1;
        }

        public int next(int pos) {
            for (int i = 0; i < set.length && pos >>> 6 < set[i].length; i++, pos >>>= 6, pos++) {
                int nex = next(set[i][pos >>> 6], pos & 63);
                if (nex != -1) {
                    pos = pos >>> 6 << 6 | nex;
                    while (i > 0) pos = pos << 6 | Long.numberOfTrailingZeros(set[--i][pos]);
                    return pos;
                }
            }
            return -1;
        }

        private static int prev(long set, int n) {
            long h = set << ~n;
            if (h == 0L) return -1;
            return -Long.numberOfLeadingZeros(h) + n;
        }

        private static int next(long set, int n) {
            long h = set >>> n;
            if (h == 0L) return -1;
            return Long.numberOfTrailingZeros(h) + n;
        }

        @Override
        public String toString() {
            List<Integer> list = new ArrayList<>();
            for (int pos = next(0); pos != -1; pos = next(pos + 1)) {
                list.add(pos);
            }
            return list.toString();
        }
    }


    public static int[] id1(int[] a) {
        int n = a.length;
        int[] c0 = new int[0x101];
        int[] c1 = new int[0x101];
        int[] c2 = new int[0x101];
        int[] c3 = new int[0x101];
        for (int v : a) {
            c0[(v & 0xff) + 1]++;
            c1[(v >>> 8 & 0xff) + 1]++;
            c2[(v >>> 16 & 0xff) + 1]++;
            c3[(v >>> 24 ^ 0x80) + 1]++;
        }
        for (int i = 0; i < 0xff; i++) {
            c0[i + 1] += c0[i];
            c1[i + 1] += c1[i];
            c2[i + 1] += c2[i];
            c3[i + 1] += c3[i];
        }
        int[] t = new int[n];
        for (int v : a) t[c0[v & 0xff]++] = v;
        for (int v : t) a[c1[v >>> 8 & 0xff]++] = v;
        for (int v : a) t[c2[v >>> 16 & 0xff]++] = v;
        for (int v : t) a[c3[v >>> 24 ^ 0x80]++] = v;
        return a;
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

    private boolean id0(int c) {
        return !(c >= 33 && c <= 126);
    }

    private int skip() {
        int b;
        while ((b = readByte()) != -1 && id0(b)) ;
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
        while (!(id0(b))) { 

            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    private char[] ns(int n) {
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while (p < n && !(id0(b))) {
            buf[p++] = (char) b;
            b = readByte();
        }
        return n == p ? buf : Arrays.copyOf(buf, p);
    }

    private int[] na(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = ni();
        return a;
    }

    private long[] nal(int n) {
        long[] a = new long[n];
        for (int i = 0; i < n; i++) a[i] = nl();
        return a;
    }

    private char[][] nm(int n, int m) {
        char[][] map = new char[n][];
        for (int i = 0; i < n; i++) map[i] = ns(m);
        return map;
    }

    private int[][] nmi(int n, int m) {
        int[][] map = new int[n][];
        for (int i = 0; i < n; i++) map[i] = na(m);
        return map;
    }

    private int ni() {
        return (int) nl();
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

    public static class FastWriter {
        private static final int BUF_SIZE = 1 << 13;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private FastWriter() {
            out = null;
        }

        public FastWriter(OutputStream os) {
            this.out = os;
        }

        public FastWriter(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public FastWriter write(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerflush();
            return this;
        }

        public FastWriter write(char c) {
            return write((byte) c);
        }

        public FastWriter write(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            }
            return this;
        }

        public FastWriter write(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            });
            return this;
        }

        private static int countDigits(int l) {
            if (l >= 1000000000) return 10;
            if (l >= 100000000) return 9;
            if (l >= 10000000) return 8;
            if (l >= 1000000) return 7;
            if (l >= 100000) return 6;
            if (l >= 10000) return 5;
            if (l >= 1000) return 4;
            if (l >= 100) return 3;
            if (l >= 10) return 2;
            return 1;
        }

        public FastWriter write(int x) {
            if (x == Integer.MIN_VALUE) {
                return write((long) x);
            }
            if (ptr + 12 >= BUF_SIZE) innerflush();
            if (x < 0) {
                write((byte) '-');
                x = -x;
            }
            int d = countDigits(x);
            for (int i = ptr + d - 1; i >= ptr; i--) {
                buf[i] = (byte) ('0' + x % 10);
                x /= 10;
            }
            ptr += d;
            return this;
        }

        private static int countDigits(long l) {
            if (l >= 1000000000000000000L) return 19;
            if (l >= 100000000000000000L) return 18;
            if (l >= 10000000000000000L) return 17;
            if (l >= 1000000000000000L) return 16;
            if (l >= 100000000000000L) return 15;
            if (l >= 10000000000000L) return 14;
            if (l >= 1000000000000L) return 13;
            if (l >= 100000000000L) return 12;
            if (l >= 10000000000L) return 11;
            if (l >= 1000000000L) return 10;
            if (l >= 100000000L) return 9;
            if (l >= 10000000L) return 8;
            if (l >= 1000000L) return 7;
            if (l >= 100000L) return 6;
            if (l >= 10000L) return 5;
            if (l >= 1000L) return 4;
            if (l >= 100L) return 3;
            if (l >= 10L) return 2;
            return 1;
        }

        public FastWriter write(long x) {
            if (x == Long.MIN_VALUE) {
                return write("" + x);
            }
            if (ptr + 21 >= BUF_SIZE) innerflush();
            if (x < 0) {
                write((byte) '-');
                x = -x;
            }
            int d = countDigits(x);
            for (int i = ptr + d - 1; i >= ptr; i--) {
                buf[i] = (byte) ('0' + x % 10);
                x /= 10;
            }
            ptr += d;
            return this;
        }

        public FastWriter write(double x, int precision) {
            if (x < 0) {
                write('-');
                x = -x;
            }
            x += Math.pow(10, -precision) / 2;
            

            write((long) x).write(".");
            x -= (long) x;
            for (int i = 0; i < precision; i++) {
                x *= 10;
                write((char) ('0' + (int) x));
                x -= (int) x;
            }
            return this;
        }

        public FastWriter writeln(char c) {
            return write(c).writeln();
        }

        public FastWriter writeln(int x) {
            return write(x).writeln();
        }

        public FastWriter writeln(long x) {
            return write(x).writeln();
        }

        public FastWriter writeln(double x, int precision) {
            return write(x, precision).writeln();
        }

        public FastWriter write(int... xs) {
            boolean first = true;
            for (int x : xs) {
                if (!first) write(' ');
                first = false;
                write(x);
            }
            return this;
        }

        public FastWriter write(long... xs) {
            boolean first = true;
            for (long x : xs) {
                if (!first) write(' ');
                first = false;
                write(x);
            }
            return this;
        }

        public FastWriter writeln() {
            return write((byte) '\n');
        }

        public FastWriter writeln(int... xs) {
            return write(xs).writeln();
        }

        public FastWriter writeln(long... xs) {
            return write(xs).writeln();
        }

        public FastWriter writeln(char[] line) {
            return write(line).writeln();
        }

        public FastWriter writeln(char[]... map) {
            for (char[] line : map) write(line).writeln();
            return this;
        }

        public FastWriter writeln(String s) {
            return write(s).writeln();
        }

        private void innerflush() {
            try {
                out.write(buf, 0, ptr);
                ptr = 0;
            } catch (IOException e) {
                throw new RuntimeException("innerflush");
            }
        }

        public void flush() {
            innerflush();
            try {
                out.flush();
            } catch (IOException e) {
                throw new RuntimeException("flush");
            }
        }

        public FastWriter print(byte b) {
            return write(b);
        }

        public FastWriter print(char c) {
            return write(c);
        }

        public FastWriter print(char[] s) {
            return write(s);
        }

        public FastWriter print(String s) {
            return write(s);
        }

        public FastWriter print(int x) {
            return write(x);
        }

        public FastWriter print(long x) {
            return write(x);
        }

        public FastWriter print(double x, int precision) {
            return write(x, precision);
        }

        public FastWriter println(char c) {
            return writeln(c);
        }

        public FastWriter println(int x) {
            return writeln(x);
        }

        public FastWriter println(long x) {
            return writeln(x);
        }

        public FastWriter println(double x, int precision) {
            return writeln(x, precision);
        }

        public FastWriter print(int... xs) {
            return write(xs);
        }

        public FastWriter print(long... xs) {
            return write(xs);
        }

        public FastWriter println(int... xs) {
            return writeln(xs);
        }

        public FastWriter println(long... xs) {
            return writeln(xs);
        }

        public FastWriter println(char[] line) {
            return writeln(line);
        }

        public FastWriter println(char[]... map) {
            return writeln(map);
        }

        public FastWriter println(String s) {
            return writeln(s);
        }

        public FastWriter println() {
            return writeln();
        }
    }

    public void trnz(int... o) {
        for (int i = 0; i < o.length; i++) if (o[i] != 0) System.out.print(i + ":" + o[i] + " ");
        System.out.println();
    }

    

    public void trt(long... o) {
        Queue<Integer> stands = new ArrayDeque<>();
        for (int i = 0; i < o.length; i++) {
            for (long x = o[i]; x != 0; x &= x - 1) stands.add(i << 6 | Long.numberOfTrailingZeros(x));
        }
        System.out.println(stands);
    }

    public void tf(boolean... r) {
        for (boolean x : r) System.out.print(x ? '
        System.out.println();
    }

    public void tf(boolean[]... b) {
        for (boolean[] r : b) {
            for (boolean x : r) System.out.print(x ? '
            System.out.println();
        }
        System.out.println();
    }

    public void tf(long[]... b) {
        if (INPUT.length() != 0) {
            for (long[] r : b) {
                for (long x : r) {
                    for (int i = 0; i < 64; i++) {
                        System.out.print(x << ~i < 0 ? '
                    }
                }
                System.out.println();
            }
            System.out.println();
        }
    }

    public void tf(long... b) {
        if (INPUT.length() != 0) {
            for (long x : b) {
                for (int i = 0; i < 64; i++) {
                    System.out.print(x << ~i < 0 ? '
                }
            }
            System.out.println();
        }
    }

    private boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    private void tr(Object... o) {
        if (!oj) System.out.println(Arrays.deepToString(o));
    }

    void run() throws Exception {
        

        if (INPUT.length() > 0)
            is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
        else is = oj ? System.in : new ByteArrayInputStream(new FileInputStream("input/a.test").readAllBytes());
        out = new FastWriter(System.out);

        long s = System.currentTimeMillis();
        solve();
        out.flush();
        tr(System.currentTimeMillis() - s + "ms");
    }

    public static void main(String[] args) throws Exception {
        new UWI().run();
    }

    void solve() {
        for (int T = 1; T > 0; T--) go();
    }


    void go() {
        int n = ni();
        long[] a = nal(n);
        long ans = Long.MAX_VALUE;
        

        

        for (int i = 0; i < n; i++) {
            long need = 0;
            long pre = 1;
            for (int l = i - 1; l >= 0; l--) {
                long count = pre / a[l] + (pre % a[l] == 0 ? 0 : 1);
                need += count;
                pre = count * a[l] + 1;
            }
            pre = 1;
            for (int r = i + 1; r < n; r++) {
                long count = pre / a[r] + (pre % a[r] == 0 ? 0 : 1);
                need += count;
                pre = count * a[r] + 1;
            }
            ans = Math.min(ans, need);

        }
        out.println(ans);
    }

}

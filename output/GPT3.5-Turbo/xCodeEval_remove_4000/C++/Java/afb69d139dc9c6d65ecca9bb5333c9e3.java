import java.io.*;
import java.util.*;

class Main {
    static final int MAXN = 3 * 100000 + 42;
    static int n;

    static class Treap {
        Treap left = null;
        Treap right = null;
        long t;
        int y;
        long prefix_sum;
        long speed;
        long push = 0;
        long min_prefix_sum_in_subtree;

        Treap(long t, long val, long speed) {
            this.t = t;
            this.y = mrand();
            this.prefix_sum = val;
            this.speed = speed;
            this.min_prefix_sum_in_subtree = val;
        }
    }

    static Treap merge(Treap a, Treap b) {
        if (a == null) return b;
        if (b == null) return a;
        if (a.y < b.y) {
            push(a);
            a.right = merge(a.right, b);
            recalc(a);
            return a;
        } else {
            push(b);
            b.left = merge(a, b.left);
            recalc(b);
            return b;
        }
    }

    static void vertex_add(Treap a, long push) {
        a.prefix_sum += push;
        a.min_prefix_sum_in_subtree += push;
        a.push += push;
    }

    static void push(Treap a) {
        long push = a.push;
        if (push == 0) return;
        if (a.left != null) {
            vertex_add(a.left, push);
        }
        if (a.right != null) {
            vertex_add(a.right, push);
        }
        a.push = 0;
    }

    static long smin(Treap a) {
        return a != null ? a.min_prefix_sum_in_subtree : Long.MAX_VALUE;
    }

    static void recalc(Treap a) {
        a.min_prefix_sum_in_subtree = Math.min(Math.min(smin(a.left), smin(a.right)), a.prefix_sum);
    }

    static Treap id12(Treap a) {
        push(a);
        if (a.left == null) {
            return a;
        }
        return id12(a.left);
    }

    static Treap id7(Treap a) {
        push(a);
        if (a.right == null) {
            return a;
        }
        return id7(a.right);
    }

    static Treap id2(Treap a, long v) {
        push(a);
        if (smin(a.left) <= v) {
            return id2(a.left, v);
        }
        if (a.prefix_sum <= v) return a;
        return id2(a.right, v);
    }

    static void print_tree(Treap a) {
        if (a == null) return;
        print_tree(a.left);
        System.err.print(a.t + " ");
        print_tree(a.right);
    }

    static int id3 = 0;
    static char[] write_buf = new char[buf_size];

    static void writeChar(int x) {
        if (id3 == buf_size) {
            System.out.print(write_buf);
            id3 = 0;
        }
        write_buf[id3++] = (char) x;
    }

    static void flush() {
        if (id3 > 0) {
            System.out.print(write_buf, 0, id3);
            id3 = 0;
        }
    }

    static void writeInt(long x, char end, int output_len) {
        if (x < 0) {
            writeChar('-');
            x = -x;
        }

        char[] s = new char[24];
        int n = 0;
        while (x != 0 || n == 0) {
            s[n++] = (char) ('0' + x % 10);
            x /= 10;
        }
        while (n < output_len) {
            s[n++] = '0';
        }
        while (n-- > 0) {
            writeChar(s[n]);
        }
        if (end != 0) {
            writeChar(end);
        }
    }

    static void writeWord(String s) {
        for (int i = 0; i < s.length(); i++) {
            writeChar(s.charAt(i));
        }
    }

    static void writeDouble(double x, int output_len) {
        if (x < 0) {
            writeChar('-');
            x = -x;
        }
        int t = (int) x;
        writeInt(t);
        x -= t;
        writeChar('.');
        for (int i = output_len - 1; i > 0; i--) {
            x *= 10;
            t = Math.min(9, (int) x);
            writeChar('0' + t);
            x -= t;
        }
        x *= 10;
        t = Math.min(9, (int) (x + 0.5));
        writeChar('0' + t);
    }

    static int buf_size = 4096;
    static byte[] buf = new byte[buf_size];
    static int buf_len = 0, buf_pos = 0;

    static boolean id8() {
        if (buf_pos == buf_len) {
            buf_pos = 0;
            try {
                buf_len = System.in.read(buf);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buf_pos == buf_len) {
                return true;
            }
        }
        return false;
    }

    static int getChar() {
        return id8() ? -1 : buf[buf_pos++];
    }

    static int peekChar() {
        return id8() ? -1 : buf[buf_pos];
    }

    static boolean id6() {
        int c;
        while ((c = peekChar()) != -1 && c <= 32)
            buf_pos++;
        return c == -1;
    }

    static void id10() {
        while (!id8() && buf[buf_pos] <= 32U)
            buf_pos++;
    }

    static int readChar() {
        int c = getChar();
        while (c != -1 && c <= 32)
            c = getChar();
        return c;
    }

    static int readUInt() {
        int c = readChar(), x = 0;
        while ('0' <= c && c <= '9')
            x = x * 10 + c - '0', c = getChar();
        return x;
    }

    static long readInt() {
        int s = 1, c = readChar();
        long x = 0;
        if (c == '-')
            s = -1, c = getChar();
        else if (c == '+')
            c = getChar();
        while ('0' <= c && c <= '9')
            x = x * 10 + c - '0', c = getChar();
        return s == 1 ? x : -x;
    }

    static double readDouble() {
        int s = 1, c = readChar();
        double x = 0;
        if (c == '-')
            s = -1, c = getChar();
        while ('0' <= c && c <= '9')
            x = x * 10 + c - '0', c = getChar();
        if (c == '.') {
            c = getChar();
            double coef = 1;
            while ('0' <= c && c <= '9')
                x += (c - '0') * (coef *= 1e-1), c = getChar();
        }
        return s == 1 ? x : -x;
    }

    static String readString() {
        final int MAX = 1_000_000 + 42;
        byte[] buf = new byte[MAX];
        int cnt = 0;
        int c = readChar();
        while (c > 32) {
            buf[cnt++] = (byte) c;
            c = getChar();
        }
        return new String(buf, 0, cnt);
    }

    static int mrand() {
        return Math.abs((int) ((1L * rand() << 15) + rand()));
    }

    static long rand() {
        return System.nanoTime();
    }

    static long INF = (long) 1e18;

    static long smin(Treap a) {
        return a != null ? a.min_prefix_sum_in_subtree : INF;
    }

    static void recalc(Treap a) {
        a.min_prefix_sum_in_subtree = Math.min(Math.min(smin(a.left), smin(a.right)), a.prefix_sum);
    }

    static Treap id2(Treap a, long v) {
        push(a);
        if (smin(a.left) <= v) {
            return id2(a.left, v);
        }
        if (a.prefix_sum <= v) return a;
        return id2(a.right, v);
    }

    static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        solve(in, out);
        out.close();
    }

    static void solve(InputReader in, PrintWriter out) {
        Treap root = new Treap(0, 0, 0);
        root = merge(root, new Treap(2_000_000_000, 0, 0));
        int q = readInt();
        int t;
        int s, type;
        for (int i = 0; i < q; ++i) {
            type = readInt();
            if (type == 1) {
                t = readInt();
                s = readInt();
                Treap[] lr = split(root, t);
                Treap vr = id12(lr[1]);
                Treap vl = id7(lr[0]);
                long psum = vl.prefix_sum + (t - vl.t) * vl.speed;
                long id5 = psum + (vr.t - t) * s;
                vertex_add(lr[1], id5 - vr.prefix_sum);
                root = merge(lr[0], merge(new Treap(t, psum, s), lr[1]));
            } else if (type == 2) {
                t = readInt();
                Treap[] ltr = split(root, t);
                Treap[] yr = split(ltr[1], t + 1);
                Treap vl = id7(ltr[0]);
                Treap vr = id12(yr[1]);
                long id5 = vl.prefix_sum + (vr.t - vl.t) * vl.speed;
                vertex_add(yr[1], id5 - vr.prefix_sum);
                root = merge(ltr[0], yr[1]);
            } else {
                int L = readInt();
                int R = readInt();
                long v = readInt();
                if (v == 0) {
                    out.println(L);
                    continue;
                }
                Treap[] ltr = split(root, L);
                Treap[] yr = split(ltr[1], R + 1);
                if (yr[0] == null) {
                    out.println(-1);
                } else {
                    Treap vl = id12(yr[0]);
                    Treap vr = id7(yr[1]);
                    long id13 = vl.prefix_sum - v;
                    if (yr[0].min_prefix_sum_in_subtree > id13) {
                        long id5 = vr.prefix_sum + (R - vr.t) * vr.speed;
                        if (id5 > id13) {
                            out.println("-1");
                        } else {
                            out.println(vr.t + (double) (id13 - vr.prefix_sum) / vr.speed);
                        }
                    } else {
                        Treap h = id2(yr[0], id13);
                        Treap[] ylr = split(yr[0], h.t);
                        Treap vyl = id7(ylr[1]);
                        out.println(vyl.t + (double) (id13 - vyl.prefix_sum) / vyl.speed);
                        yr[0] = merge(ylr[0], ylr[1]);
                    }
                }
                root = merge(ltr[0], merge(yr[0], yr[1]));
            }
        }
    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
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
    }

    public static void main(String[] args) {
        solve(new InputReader(System.in), new PrintWriter(System.out));
    }
}

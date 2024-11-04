import java.io.*;
import java.util.*;

class Main {
    static final long MOD = 1000000007;

    static class FastIO {
        static final int RDATA_SZ = (1 << 25);
        static final int WDATA_SZ = (1 << 25);
        char[] rdata = new char[RDATA_SZ];
        char[] wdata = new char[WDATA_SZ];
        char[] tmp_s = new char[20];
        int rb, wb;

        FastIO() throws IOException {
            System.in.read(rdata, 0, RDATA_SZ);
            rb = 0;
            wb = 0;
        }

        void flush() throws IOException {
            System.out.write(wdata, 0, wb);
            wb = 0;
        }

        void read_i(long[] x) {
            boolean neg = false;
            x[0] = 0;
            while ((rdata[rb] < '0' || rdata[rb] > '9') && rdata[rb] != '-') ++rb;
            if (rdata[rb] == '-') {
                neg = true;
                ++rb;
            }
            while ('0' <= rdata[rb] && rdata[rb] <= '9') {
                x[0] = 10 * x[0] + (rdata[rb] - '0');
                ++rb;
            }
            if (neg) x[0] = -x[0];
        }

        void id0(long x) throws IOException {
            if (x == 0) {
                pc('0');
                pc('\n');
                return;
            }
            if (x < 0) {
                pc('-');
                x = -x;
            }
            int t = 0;
            while (x != 0) {
                long y = x / 10;
                tmp_s[t++] = (char) ((x - y * 10) + '0');
                x = y;
            }
            while (t != 0) {
                pc(tmp_s[--t]);
            }
            pc('\n');
        }

        void pc(char c) throws IOException {
            wdata[wb++] = c;
            if (wb >= WDATA_SZ) flush();
        }
    }

    static class IO {
        static final int BUF_SIZE = 1 << 18;
        char[] buf_in = new char[BUF_SIZE];
        char[] buf_out = new char[BUF_SIZE];
        int pt_in = 0, pt_out = 0, tail_in = 0;
        char[] strs = new char[10000 * 4];

        int num_digits(long x) {
            if (x >= (long) 1e9) {
                if (x >= (long) 1e18) return 19;
                if (x >= (long) 1e17) return 18;
                if (x >= (long) 1e16) return 17;
                if (x >= (long) 1e15) return 16;
                if (x >= (long) 1e14) return 15;
                if (x >= (long) 1e13) return 14;
                if (x >= (long) 1e12) return 13;
                if (x >= (long) 1e11) return 12;
                if (x >= (long) 1e10) return 11;
                return 10;
            } else {
                if (x >= (long) 1e8) return 9;
                if (x >= (long) 1e7) return 8;
                if (x >= (long) 1e6) return 7;
                if (x >= (long) 1e5) return 6;
                if (x >= (long) 1e4) return 5;
                if (x >= (long) 1e3) return 4;
                if (x >= (long) 1e2) return 3;
                if (x >= (long) 1e1) return 2;
                return 1;
            }
        }

        IO() throws IOException {
            load();
            for (int i = 0; i < 10000; ++i) {
                int j = i;
                for (int t = 3; t >= 0; --t) {
                    strs[i * 4 + t] = (char) (j % 10 + '0');
                    j /= 10;
                }
            }
        }

        void load() throws IOException {
            System.arraycopy(buf_in, pt_in, buf_in, 0, tail_in - pt_in);
            int width = tail_in - pt_in;
            tail_in = width + System.in.read(buf_in, width, BUF_SIZE - width);
            pt_in = 0;
        }

        void flush() throws IOException {
            System.out.write(buf_out, 0, pt_out);
            pt_out = 0;
        }

        void read(char[] c) throws IOException {
            c[0] = buf_in[pt_in++];
        }

        void read(long[] x) throws IOException {
            if (pt_in + 32 > tail_in) load();
            char c;
            do {
                read(new char[]{c});
            } while (c < '0');
            boolean minus = false;
            if (c == '-') {
                minus = true;
                read(new char[]{c});
            }
            x[0] = 0;
            while (c >= '0') {
                x[0] = x[0] * 10 + (c & 15);
                read(new char[]{c});
            }
            if (minus) x[0] = -x[0];
        }

        void write(char c) throws IOException {
            buf_out[pt_out++] = c;
            if (pt_out > BUF_SIZE - 32) flush();
        }

        void write(long x) throws IOException {
            if (pt_out > BUF_SIZE - 32) flush();
            if (x < 0) {
                write('-');
                x = -x;
            }
            int digits = num_digits(x);
            int i;
            for (i = pt_out + digits - 4; i > pt_out; i -= 4) {
                System.arraycopy(strs, (int) (x % 10000) * 4, buf_out, i, 4);
                x /= 10000;
            }
            System.arraycopy(strs, (int) (x * 4 + (pt_out - i)), buf_out, pt_out, 4 + i - pt_out);
            pt_out += digits;
        }

        void write(String s) throws IOException {
            if (pt_out > BUF_SIZE - 32) flush();
            for (int i = 0; i < s.length(); ++i) write(s.charAt(i));
        }

        void writeln(long x) throws IOException {
            write(x);
            write('\n');
        }
    }

    static IO io = new IO();
    static FastIO io2;

    static long[][][][] dp = new long[65][2][2][2];

    static void solve() throws IOException {
        long[] t = new long[1];
        io.read(t);

        for (int i = 0; i < 61; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        dp[i][j][k][l] = 0;
                    }
                }
            }
        }

        dp[0][0][0][0] = 1;
        for (int i = 0; i < 60; i++) {
            boolean f2 = (t[0] >> i & 1) == 1;
            if (f2) {
                dp[i + 1][0][0][0] += dp[i][0][0][0];
                dp[i + 1][1][0][0] += dp[i][0][0][0];
                dp[i + 1][0][1][0] += dp[i][0][0][0];
                dp[i + 1][1][1][0] += dp[i][0][0][0];
                dp[i + 1][0][1][0] += dp[i][0][0][1];
                dp[i + 1][1][1][0] += dp[i][0][0][1];
                dp[i + 1][0][0][1] += dp[i][0][0][1];
                dp[i + 1][1][0][1] += dp[i][0][0][1];
                dp[i + 1][1][0][0] += dp[i][0][1][0];
                dp[i + 1][0][1][0] += dp[i][0][1][0];
                dp[i + 1][1][1][0] += dp[i][0][1][0];
                dp[i + 1][0][0][1] += dp[i][0][1][0];
                dp[i + 1][1][1][0] += dp[i][0][1][1];
                dp[i + 1][0][0][1] += dp[i][0][1][1];
                dp[i + 1][1][0][1] += dp[i][0][1][1];
                dp[i + 1][0][1][1] += dp[i][0][1][1];
                dp[i + 1][0][0][0] += dp[i][1][0][0];
                dp[i + 1][1][0][0] += dp[i][1][0][0];
                dp[i + 1][0][1][0] += dp[i][1][0][0];
                dp[i + 1][1][1][0] += dp[i][1][0][0];
                dp[i + 1][0][1][0] += dp[i][1][0][1];
                dp[i + 1][1][1][0] += dp[i][1][0][1];
                dp[i + 1][0][0][1] += dp[i][1][0][1];
                dp[i + 1][1][0][1] += dp[i][1][0][1];
                dp[i + 1][1][0][0] += dp[i][1][1][0];
                dp[i + 1][0][1][0] += dp[i][1][1][0];
                dp[i + 1][1][1][0] += dp[i][1][1][0];
                dp[i + 1][0][0][1] += dp[i][1][1][0];
                dp[i + 1][1][1][0] += dp[i][1][1][1];
                dp[i + 1][0][0][1] += dp[i][1][1][1];
                dp[i + 1][1][0][1] += dp[i][1][1][1];
                dp[i + 1][0][1][1] += dp[i][1][1][1];
            } else {
                dp[i + 1][0][0][0] += dp[i][0][0][0];
                dp[i + 1][1][0][0] += dp[i][0][0][0];
                dp[i + 1][0][1][0] += dp[i][0][0][0];
                dp[i + 1][1][1][0] += dp[i][0][0][0];
                dp[i + 1][0][1][0] += dp[i][0][0][1];
                dp[i + 1][1][1][0] += dp[i][0][0][1];
                dp[i + 1][0][0][1] += dp[i][0][0][1];
                dp[i + 1][1][0][1] += dp[i][0][0][1];
                dp[i + 1][1][0][0] += dp[i][0][1][0];
                dp[i + 1][0][1][0] += dp[i][0][1][0];
                dp[i + 1][1][1][0] += dp[i][0][1][0];
                dp[i + 1][0][0][1] += dp[i][0][1][0];
                dp[i + 1][1][1][0] += dp[i][0][1][1];
                dp[i + 1][0][0][1] += dp[i][0][1][1];
                dp[i + 1][1][0][1] += dp[i][0][1][1];
                dp[i + 1][0][1][1] += dp[i][0][1][1];
                dp[i + 1][1][0][0] += dp[i][1][0][0];
                dp[i + 1][0][1][0] += dp[i][1][0][0];
                dp[i + 1][1][1][0] += dp[i][1][0][0];
                dp[i + 1][0][0][1] += dp[i][1][0][0];
                dp[i + 1][1][1][0] += dp[i][1][0][1];
                dp[i + 1][0][0][1] += dp[i][1][0][1];
                dp[i + 1][1][0][1] += dp[i][1][0][1];
                dp[i + 1][0][1][1] += dp[i][1][0][1];
                dp[i + 1][0][1][0] += dp[i][1][1][0];
                dp[i + 1][1][1][0] += dp[i][1][1][0];
                dp[i + 1][0][0][1] += dp[i][1][1][0];
